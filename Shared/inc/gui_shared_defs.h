#ifndef GUI_SHARED_DEFS_H
#define GUI_SHARED_DEFS_H

#include <stdint.h>
#include <missions.h>

typedef struct {
	uint8_t speed;
	uint8_t gear;
	uint16_t rpm;
	uint8_t T_water;
	uint8_t T_oil;
	uint8_t throttle_perc;
	uint8_t brake_perc;
	float P_oil;
	int RES;
	bool LC;
	bool CLT;
	float battery_v;
	float brakePressureFront;
	float brakePressureRear;
	float voltage24v;
	float orinTemperature;
	float P_fuel;
	int lap;
	/* TODO: String variables */
} displayInfo;

typedef enum {
  GUI_TO_MAIN_MSG_MISSIONSELECT,
  GUI_TO_MAIN_MSG_SETRESOPMODE,
  GUI_TO_MAIN_MSG_CHASSISRESET
} GuiToMainMsgType;

typedef struct {
  GuiToMainMsgType type;
  union {
  	MmrMission selectedMission;
  } content;
} guiToMainMsg;

#endif // GUI_SHARED_DEFS_H
