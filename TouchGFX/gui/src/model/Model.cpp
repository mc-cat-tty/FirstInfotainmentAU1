#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <string.h>

displayInfo info;

Model::Model() : modelListener(0)
{
	dbgMessage = nullptr;
	strncpy(mission, "None", MAX_MISSION_LEN);
}


#ifdef SIMULATOR

static int t = 0;

void Model::tick() {
  // Some random data
  setRpm((t * 60) % 12000); 
  setThrottle_perc((t + 50) % 100);
  setFrontBrakePerc(t % 100);
  setRearBrakePerc(100 - (t % 100));
  setOrinTemperature(t % 100);
  setVoltage24v(25.0f);
  setBattery_v(13.0f);
  setLap(t % 20);
  setP_Fuel((float)(t % 999) / 100);
  setP_oil((float)(t % 999) / 100);
  setT_oil(t % 200);
  setT_water(t % 300);
  setGear(t % 6);
  setSpeed(t % 150);
  setRES(t % 4);
  setLC(true);
  setCLT(true);

  t++;
  modelListener->infoChanged();
  modelListener->gearChanged();
}

#else

#include "cmsis_os.h"
#include "main.h"

extern osMessageQueueId_t dbgMsgQueue;
extern osMessageQueueId_t guiToMainMsgQueue;
extern osMessageQueueId_t mainToGuiMsgQueue;

void Model::tick()
{
	osStatus_t status;
	
	status = osMessageQueueGet(mainToGuiMsgQueue, &info, NULL, 0);
	if (status == osOK)
	{
		setGear(info.gear);
		setSpeed(info.speed);
		setRpm(info.rpm);

		setT_water(info.T_water);
		setT_oil(info.T_oil);
		setP_oil(info.P_oil);

		setThrottle_perc(info.throttle_perc);

		setRES(info.RES);
		setLC(info.LC);
		setCLT(info.CLT);

		setBattery_v(info.battery_v);

		setOrinTemperature(info.orinTemperature);
		setVoltage24v(info.voltage24v);

		setRearBrakePerc(info.brakePressureRear * (100.0 / 160.0));
		setFrontBrakePerc(info.brakePressureFront * (100.0 / 160.0));
		setLap(info.lap);
		setP_Fuel(info.P_fuel);

		/* TODO: String variables */

		modelListener->infoChanged();
	}

	status = osMessageQueueGet(dbgMsgQueue, &dbgMessage, NULL, 0);
	if (status == osOK)
		modelListener->debugMessageChanged();

}
#endif


#ifdef SIMULATOR
#include <stdio.h>

void Model::requestMission(MmrMission missionType) {
  static char buf[32];
  snprintf(buf, 32, "Mission requested: %d", missionType);
  dbgMessage = buf;
  modelListener->debugMessageChanged();
  commonAfterRequestMission(missionType);
}

void Model::requestChassisReset() {
	static char buf[32];
  snprintf(buf, 32, "Chassis reset requested.");
  dbgMessage = buf;
  modelListener->debugMessageChanged();
}

#else

void Model::requestMission(MmrMission missionType) {
  guiToMainMsg msg;
	msg.type = GUI_TO_MAIN_MSG_MISSIONSELECT;
	msg.content.selectedMission = missionType;

  osMessageQueuePut(guiToMainMsgQueue, &msg, 0, 0);
  commonAfterRequestMission(missionType);
}

void Model::requestChassisReset() {
  guiToMainMsg msg {
		.type = GUI_TO_MAIN_MSG_CHASSISRESET
	};

	osMessageQueuePut(guiToMainMsgQueue, &msg, 0, 0);
}


#endif

void Model::commonAfterRequestMission(MmrMission missionType) {
	strncpy(mission, missionTranslation[missionType], MAX_MISSION_LEN),
	modelListener->missionChanged();
}
