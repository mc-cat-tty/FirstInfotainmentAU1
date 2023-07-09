#ifndef MODEL_HPP
#define MODEL_HPP

#include "gui_shared_defs.h"

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void setGear(int recvGear) { gear = recvGear; }
    int getGear() { return gear; }
    void setSpeed(int recvSpeed) { speed = recvSpeed; }
    int getSpeed() { return speed; }
    void setRpm(int recvRpm) { rpm = recvRpm; }
    int getRpm() { return rpm; }

    void setT_water(int recvT_water) { T_water = recvT_water; }
    int getT_water() { return T_water; }
    void setT_oil(int recvT_oil) { T_oil= recvT_oil; }
    int getT_oil() { return T_oil; }
    void setP_oil(float recvP_oil) { P_oil= recvP_oil; }
    float getP_oil() { return P_oil; }
    void setP_Fuel(float recvP_fuel) { P_fuel = recvP_fuel; }
    float getP_fuel() { return P_fuel; }

    void setOrinTemperature(float recvOrinTemperature) { orinTemperature = recvOrinTemperature; }
    float getOrinTemperature() { return orinTemperature; }

    void setVoltage24v(float recvVoltage24v) { voltage24v = recvVoltage24v; }
    float getVoltage24v() { return voltage24v; }

    void setThrottle_perc(int recvThrottle_perc) { throttle_perc= recvThrottle_perc; }
    int getThrottle_perc() { return throttle_perc; }

    void setRearBrakePerc(int recvBrake_perc) { rearBrakePerc = recvBrake_perc; }
    int getRearBrakePerc() { return rearBrakePerc; }

    void setFrontBrakePerc(int recvBrake_perc) { frontBrakePerc = recvBrake_perc; }
    int getFrontBrakePerc() { return frontBrakePerc; }

    void setLap(int lap_recv) { lap = lap_recv; }
    int getLap() { return lap; }

    void setRES(int recvRES) { RES = recvRES; }
    int getRES() { return RES; }
    void setLC(bool recvLC) { LC= recvLC; }
    bool getLC() { return LC; }
    void setCLT(bool recvCLT) { CLT= recvCLT; }
    bool getCLT() { return CLT; }

    void setBattery_v(float recvBattery_v) { battery_v = recvBattery_v; }
    float getBattery_v() { return battery_v; }

    void requestChassisReset();

    void requestMission(MmrMission missionType);
    void commonAfterRequestMission(MmrMission missionType);

    const char* getMission() { return mission; }

    const char* getDebugMessage() { return dbgMessage; }

    /* TODO: string variables */

protected:
    ModelListener *modelListener;

    const char *dbgMessage;
    char mission[15];
    constexpr static const int MAX_MISSION_LEN = 15;
    const char missionTranslation[9][MAX_MISSION_LEN] = {
    	"Idle",
		"Acceleration",
		"Skidpad",
		"Autocross",
		"Trackdrive",
		"EBS Test",
		"Inspection",
		"Manual",
		"Debug"
    };

    int gear, speed, rpm, T_water, T_oil, throttle_perc;
    int frontBrakePerc, rearBrakePerc;

    int lap;

    float orinTemperature;

    float P_oil, P_fuel;

    int RES;
    bool LC, CLT;

    float battery_v, voltage24v;

    char DS[40], AS[40], AMI[40], EBS[10];
};

#endif // MODEL_HPP
