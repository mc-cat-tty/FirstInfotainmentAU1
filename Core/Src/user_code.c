#include "main.h"
#include "gui_shared_defs.h"
#include "cmsis_os.h"

#include <pin.h>
#include <button.h>
#include <led.h>
#include <spi.h>
#include <mcp2515.h>
#include <spi0.h>
#include <stm_pin.h>
#include <timing.h>
#include <delay.h>
#include <net.h>
#include <util.h>
#include <buffer.h>


extern osMessageQueueId_t dbgMsgQueue;
extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t mainToGuiMsgQueue;
extern SPI_HandleTypeDef hspi2;

displayInfo msgDisplayInfo;
int gear_six_count = 0, gear_mem = 0;

MmrPin mcp2515csPin;
MmrPin* spiSlavePins[] = { &mcp2515csPin };

MmrLaunchControlState lcState = MMR_LAUNCH_CONTROL_UNKNOWN;

#include <string.h>
void userMessage(const char* msg) {
  osMessageQueuePut(dbgMsgQueue, &msg, 0U, 0U);
  osThreadYield();
}

void userError(const char* msg) {
	userMessage(msg);
	while (true) {
		osDelay(1000);
	}
}


// STEERING WHEEL BUTTONS

typedef struct SteeringButton {
  MmrPin mmr_pin;
  MmrButton mmr_button;
} SteeringButton;


typedef struct DashboardLed {
  MmrPin mmr_pin;
  MmrLed mmr_led;
} DashboardLed;

SteeringButton rightPaddleBtn;
SteeringButton leftPaddleBtn;
SteeringButton greenBtn;
SteeringButton leftRedBtn;
SteeringButton rightRedBtn;
DashboardLed neutralLed;
// SteeringButton blackButton;

// Mappings
#define SHIFT_UP_BTN rightPaddleBtn
#define SHIFT_DOWN_BTN leftPaddleBtn
#define SHIFT_NTRL_BTN greenBtn
#define MISSION_MANUAL_BTN leftRedBtn
#define SET_LAUNCHCTRL_BTN rightRedBtn

void init_button(SteeringButton* btn, GPIO_TypeDef* port, uint16_t pin, bool hasInvertedLogic) {
	btn->mmr_pin = MMR_Pin(port, pin, hasInvertedLogic);
	btn->mmr_button = MMR_Button(&btn->mmr_pin);
}

void init_led(DashboardLed* led, GPIO_TypeDef* port, uint16_t pin, bool hasInvertedLogic) {
	led->mmr_pin = MMR_Pin(port, pin, hasInvertedLogic);
	led->mmr_led = MMR_Led(&led->mmr_pin);
}

void initialize_steering_buttons() {
	init_button(&leftPaddleBtn,  STEERING_LEFT_PADDLE_BUTTON_GPIO_Port,	 STEERING_LEFT_PADDLE_BUTTON_Pin,	false);
	init_button(&rightPaddleBtn, STEERING_RIGHT_PADDLE_BUTTON_GPIO_Port, STEERING_RIGHT_PADDLE_BUTTON_Pin, 	false);
	init_button(&greenBtn,	     STEERING_GREEN_BUTTON_GPIO_Port,	     STEERING_GREEN_BUTTON_Pin,			false);
	init_button(&leftRedBtn,	 STEERING_LEFT_RED_BUTTON_GPIO_Port,     STEERING_LEFT_RED_BUTTON_Pin,  	false);
	init_button(&rightRedBtn, 	 STEERING_RIGHT_RED_BUTTON_GPIO_Port,    STEERING_RIGHT_RED_BUTTON_Pin, 	false);
	// init_led(&neutralLed,		 DASHBOARD_NETURAL_LED_Port,			 DASHBOARD_NEUTRAL_LED_Pin,			false);
	// blackButton = init_button(STEERING_BLACK_BUTTON_GPIO_Port, STEERING_BLACK_BUTTON_Pin, true);
}

typedef enum EcuTask {
	ECU_Task_None,
	ECU_Task_ShiftingUp,
	ECU_Task_ShiftingDown,
	ECU_Task_ShiftingNtrl,
	ECU_Task_SetLaunchCtrl,
	ECU_Task_UnsetLaunchCtrl
} EcuTask;

int ecu_task_requests = 0;
EcuTask runningEcuTask = ECU_Task_None;
bool ecu_task_request(EcuTask task) {
  ++ecu_task_requests;

  if (runningEcuTask == ECU_Task_None) {
    runningEcuTask = task;
    return true;
  }
  return false;
}


void msgOnTask(MmrTaskResult result, const char* completed, const char* error) {
  if (result == MMR_TASK_COMPLETED)
    userMessage(completed);
  else if (result == MMR_TASK_ERROR)
	userMessage(error);
}

void task_run_ecu_tasks() {
	MmrTaskResult taskResult = MMR_TASK_COMPLETED;
	switch (runningEcuTask) {
		case ECU_Task_None:
			return;

		case ECU_Task_ShiftingUp:
			taskResult = MMR_NET_ShiftUpAsync(gear_mem);
			msgOnTask(taskResult, "INFO: Shifted up.", "WARN: Failed to shift up.");
			break;

		case ECU_Task_ShiftingDown:
			taskResult = MMR_NET_ShiftDownAsync(gear_mem);
			msgOnTask(taskResult, "INFO: Shifted down.", "WARN: Failed to shift down.");
			break;

		case ECU_Task_ShiftingNtrl:
			taskResult = MMR_NET_ShiftToNeutralAsync(gear_mem);
			msgOnTask(taskResult, "INFO: Shifted to neutral.", "WARN: Failed to shift to neutral.");
			break;

		case ECU_Task_SetLaunchCtrl:
		case ECU_Task_UnsetLaunchCtrl: {
			if (runningEcuTask == ECU_Task_SetLaunchCtrl)
				taskResult = MMR_NET_CoerceLaunchControlAsync(lcState, MMR_LAUNCH_CONTROL_SET);
			else
				taskResult = MMR_NET_CoerceLaunchControlAsync(lcState, MMR_LAUNCH_CONTROL_NOT_SET);

			msgOnTask(taskResult, "INFO: Launch control toggled.", "WARN: Failed to toggle launch control.");
			break;
		}
	}

	if (taskResult != MMR_TASK_PENDING)
		runningEcuTask = ECU_Task_None;
}



// Helpers for CAN
typedef struct {
  bool (*action)();
  MmrDelay interval;
  int repetitions;

  // State
  int __currentRepetition;
} RepeatAsyncParams;

MmrTaskResult RepeatAsync(RepeatAsyncParams* params) {
  if (params->__currentRepetition >= params->repetitions) {
    params->__currentRepetition = 0;
    return MMR_TASK_COMPLETED;
  }

  if (MMR_DELAY_WaitAsync(&params->interval)) {
    if (!params->action()) {
      params->__currentRepetition = 0;
      return MMR_TASK_ERROR;
    }
    ++params->__currentRepetition;
  }
  return MMR_TASK_PENDING;
}

bool sendCanMessage(MmrCanMessageId id, uint8_t* buf, uint8_t length) {
  MmrCanMessage txMsg;
  MMR_CAN_MESSAGE_SetId(&txMsg, id);
  MMR_CAN_MESSAGE_SetStandardId(&txMsg, true);
  MMR_CAN_MESSAGE_SetPayload(&txMsg, buf, length);
  return MMR_CAN_Send(&mcp2515, &txMsg);
}


// Mission request
int mission_requests = 0;
bool isSwitchingMission = false;
MmrMission selectedMission;

void mission_request(MmrMission mission) {
  if (!isSwitchingMission) {
	  selectedMission = mission;
	  isSwitchingMission = true;
	  ++mission_requests;
  }
}

bool sendMissionRequest() {
  return sendCanMessage(MMR_CAN_MESSAGE_ID_M_MISSION_SELECTED, &selectedMission, 1);
}

RepeatAsyncParams sendMissionRequestRepeatAsync = {
  .action = sendMissionRequest,
  .interval = (MmrDelay) { .ms = 50 },
  .repetitions = 5
};


// RES operational mode
bool isSendingResOpMode;

bool sendResOpMode() {
  static uint8_t buf[1] = { 0x01 };
  return sendCanMessage(MMR_CAN_MESSAGE_ID_RES_NMT, buf, sizeof(buf));
}

RepeatAsyncParams sendResOpModeRepeatAsync = {
  .action = sendResOpMode,
  .interval = (MmrDelay) { .ms = 50 },
  .repetitions = 5
};


// Chassis reset
bool isResettingChassis;

// Main logic
void process_single_gui_message(guiToMainMsg* msg) {
  switch (msg->type) {
    case GUI_TO_MAIN_MSG_MISSIONSELECT:
      mission_request(msg->content.selectedMission);
      break;
    case GUI_TO_MAIN_MSG_SETRESOPMODE:
      isSendingResOpMode = true;
      break;
    case GUI_TO_MAIN_MSG_CHASSISRESET:
      isResettingChassis = true;
  }
}

void task_process_gui_messages_rx() {
  int pendingGuiMsgs = osMessageQueueGetCount(guiToMainMsgQueue);
  for (int i = 0; i < pendingGuiMsgs; ++i)
  {
    guiToMainMsg msg;
    osMessageQueueGet(guiToMainMsgQueue, &msg, NULL, 0);
    process_single_gui_message(&msg);
  }
}

void process_single_can_message(MmrCanMessage* msg) {
  if (!msg->isStandardId)
    return;

  switch (msg->id) {
    /* RES */
    case MMR_CAN_MESSAGE_ID_RES:
      msgDisplayInfo.RES = msg->payload[0];  /* 0 = emergency, 1 = GO */
      break;

    /* RPM, SPEED, GEAR, ATH */
    case MMR_CAN_MESSAGE_ID_ECU_ENGINE_FN1:
      msgDisplayInfo.rpm = (msg->payload[1] << 8) | msg->payload[0];

      uint16_t speed = (msg->payload[3] << 8) | msg->payload[2];
      msgDisplayInfo.speed = (unsigned char)(speed / 100);

      uint8_t gear = msg->payload[4]; /* No need to read msg->payload[5] since it will ALWAYS be 0! */
      gear_mem = gear;
      if (gear == 6)
      {
        gear_six_count++;
        if (gear_six_count == 3)
          msgDisplayInfo.gear = gear;
      }
      else
      {
        gear_six_count = 0;
        msgDisplayInfo.gear = gear;
      }

      if (gear == 0) {
    	  // MMR_LED_Set(&neutralLed, MMR_LED_ON);
    	  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, 1);
      }
      else {
    	  // MMR_LED_Set(&neutralLed, MMR_LED_OFF);
    	  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, 0);
      }

      uint16_t throttle = (msg->payload[7] << 8) | msg->payload[6];
      msgDisplayInfo.throttle_perc = (unsigned char)(throttle / 100);
      break;

    /* TOIL, TWATER */
    case 0x701:
      msgDisplayInfo.T_oil = (msg->payload[0] - 40);/* No need to read RxData[1] since it will ALWAYS be 0! */
      msgDisplayInfo.T_water = (msg->payload[2] - 40); /* No need to read RxData[3] since it will ALWAYS be 0! */
      break;

    /* POIL */
    case 0x703: {
      short p_oil = (msg->payload[1] << 8) | msg->payload[0];
      msgDisplayInfo.P_oil = (float)p_oil / 20;

      float p_fuel = (float)MMR_BUFFER_ReadInt16(msg->payload, 2, MMR_ENCODING_LITTLE_ENDIAN) / 100.0f;
      msgDisplayInfo.P_fuel = p_fuel;
      break;
    }

    /* Brake pressure */
    case MMR_CAN_MESSAGE_ID_ECU_BRAKE_PRESSURES:
      msgDisplayInfo.brakePressureFront = (0.005f) * MMR_BUFFER_ReadUint16(msg->payload, 2, MMR_ENCODING_LITTLE_ENDIAN);
      msgDisplayInfo.brakePressureRear = (0.005f) * MMR_BUFFER_ReadUint16(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN);
      break;


    /* battery_V * 1000 */
    case 0x704: {
      short bat = (msg->payload[1] << 8) | msg->payload[0];
      msgDisplayInfo.battery_v = (float)bat / 1000;
      break;
    }

    /* LAUNCH CONTROL ACTIVE */
    case 0x70C: {
      bool lc = msg->payload[0] & 0x1;
      msgDisplayInfo.LC = lc;
      lcState = lc? MMR_LAUNCH_CONTROL_SET : MMR_LAUNCH_CONTROL_NOT_SET;
      break;
    }

    /* CLUTCH PULL OK */
    case MMR_CAN_MESSAGE_ID_CS_CLUTCH_PULL_OK:
      msgDisplayInfo.CLT = true; /* No need to read RxData[7] since it will ALWAYS be 0! */
      break;

    /* ORIN TEMPERATURE */
    case MMR_CAN_MESSAGE_ID_ORIN_TEMPERATURE:
      msgDisplayInfo.orinTemperature = MMR_BUFFER_ReadFloat(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN);
      break;

    /* 24V */
    case MMR_CAN_MESSAGE_ID_24v:
      msgDisplayInfo.voltage24v = MMR_BUFFER_ReadFloat(msg->payload, 0, MMR_ENCODING_LITTLE_ENDIAN);
      break;

    case MMR_CAN_MESSAGE_ID_D_LAP_COUNTER:
      msgDisplayInfo.lap = MMR_BUFFER_ReadByte(msg->payload, 0);
      break;

    /* CLUTCH RELEASE OK */
    case MMR_CAN_MESSAGE_ID_CS_CLUTCH_RELEASE_OK:
      msgDisplayInfo.CLT = false; /* No need to read RxData[7] since it will ALWAYS be 0! */
      break;

    default:
      return;
  }

  // If no case matched (only the default case did), this is not reached.
  // Send a message containing the updated data to the display thread.
  osMessageQueuePut(mainToGuiMsgQueue, &msgDisplayInfo, 0U, 0U);
}

void task_process_can_rx() {
  static uint8_t rxBuf[8];

  MmrCanMessage rxMsg;
  MMR_CAN_MESSAGE_SetPayload(&rxMsg, rxBuf, 8);

  int pendingCanMsgs = MMR_CAN_GetPendingMessages(&mcp2515);

  for (int i = 0; i < pendingCanMsgs; ++i) {
    if (MMR_CAN_Receive(&mcp2515, &rxMsg))
      process_single_can_message(&rxMsg);
    else
      userMessage("WARN: Message reception failed.");
  }
}

void task_process_buttons() {
#define IS_JUST_PRESSED(x) MMR_BUTTON_Read(&x.mmr_button) == MMR_BUTTON_JUST_PRESSED

  if (IS_JUST_PRESSED(SHIFT_UP_BTN)) {
    ecu_task_request(ECU_Task_ShiftingUp);
  }
  if (IS_JUST_PRESSED(SHIFT_DOWN_BTN)) {
    ecu_task_request(ECU_Task_ShiftingDown);
  }
  if (IS_JUST_PRESSED(SHIFT_NTRL_BTN)) {
    ecu_task_request(ECU_Task_ShiftingNtrl);
  }
  if (IS_JUST_PRESSED(SET_LAUNCHCTRL_BTN)) {
    ecu_task_request(msgDisplayInfo.LC? ECU_Task_UnsetLaunchCtrl : ECU_Task_SetLaunchCtrl);
  }
  if (IS_JUST_PRESSED(MISSION_MANUAL_BTN)) {
    mission_request(MMR_MISSION_MANUAL);
    sendResOpMode();
  }
}

void task_send_missionrequest() {
  if (isSwitchingMission) {
    MmrTaskResult result = RepeatAsync(&sendMissionRequestRepeatAsync);
    if (result != MMR_TASK_PENDING) {
      isSwitchingMission = false;
      msgOnTask(result, "INFO: Mission switched.", "WARN: Mission switch failed.");
    }
  }
}

void task_send_resopmode() {
  if (isSendingResOpMode) {
    MmrTaskResult result = RepeatAsync(&sendResOpModeRepeatAsync);
    if (result != MMR_TASK_PENDING) {
      isSendingResOpMode = false;
      msgOnTask(result, "INFO: Sent res operational mode.", "WARN: RES operational mode transmission failed.");
    }
  }
}

void task_resetchassis() {
  if (isResettingChassis) {
	MmrTaskResult result = MMR_NET_ChassisResetAsync();
	if (result != MMR_TASK_PENDING) {
	  isResettingChassis = false;
	  msgOnTask(result, "INFO: Reset chassis sensors.", "WARN: Chassis reset failed.");
	}
  }
}

void configuration() {
  // Initialize the MMR libraries
  userMessage("INFO: Initialization...");

  MMR_SetTickProvider(HAL_GetTick);

  initialize_steering_buttons();

  mcp2515csPin = MMR_Pin(MCP2515_CS_GPIO_Port, MCP2515_CS_Pin, true);
  if (!MMR_SPI0_Init(&hspi2, spiSlavePins, 1))
	  userError("ERROR: MMR SPI0 Init failed.");

  MMR_MCP2515_Init(&spi0, 0);

  MMR_NET_ECU_BUTTONS_Init(&mcp2515);

  userMessage("INFO: Resetting MCP2515...");
  while (!MMR_MCP2515_ResetAsync(10)) {
	  if (MMR_MCP2515_GetLastError() != MMR_MCP2515_ERROR_OK)
		  userError("ERROR: MCP2515 reset failed.");

	  osDelay(200);
  }

  userMessage("INFO: Configuring MCP2515 timings...");
  // MCP2515 setup
  if (!MMR_MCP2515_ConfigureCANTiming(MMR_MCP2515_TIMING_8MHz_1000kBPS))
	  userError("ERROR: MCP2515 Timings configuration failed.");


  userMessage("INFO: Configuring MCP2515 filter...");
  MmrCanFilter fil = MMR_CAN_Filter(0, 0, false);
  if (!MMR_CAN_SetFilter(&mcp2515, &fil))
	  userError("ERROR: MCP2515 Filter configuration failed.");


  userMessage("INFO: Switching MCP2515 mode...");
  while (!MMR_MCP2515_SwitchModeAsync(MMR_MCP2515_MODE_NORMAL, 10)) {
    if (MMR_MCP2515_GetLastError() != MMR_MCP2515_ERROR_OK)
      userError("ERROR: MCP2515 mode switch failed.");

    osDelay(200);
  }
}


void userDefaultTask() {

  configuration();

  userMessage("INFO: Running.");

  while (true) {
    task_process_can_rx();
    task_process_gui_messages_rx();
    task_process_buttons();

    task_run_ecu_tasks();
    task_send_missionrequest();
    task_send_resopmode();
    task_resetchassis();
  }
}
