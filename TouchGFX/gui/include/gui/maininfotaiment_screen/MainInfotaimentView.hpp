#ifndef MAININFOTAIMENTVIEW_HPP
#define MAININFOTAIMENTVIEW_HPP

/* Costanti che memorizzano i valori BUONI dei diversi componenti dell'auto */
#define WATER_TEMP_OK_VAL 94
#define OIL_TEMP_OK_VAL 104
#define OIL_PRESS_OK_VAL 6.5
#define BATTERY_V_OK_VAL 14.4
#define VOLTAGE_24V_OK_VAL 27.0
#define ORIN_T_OK_VAL 70.0

/* Costanti che memorizzano i valori TROPPO BASSI dei diversi componenti dell'auto */
#define WATER_TEMP_LOW_VAL 50
#define OIL_TEMP_LOW_VAL 50
#define OIL_PRESS_LOW_VAL 1.5
#define BATTERY_V_LOW_VAL 11.5
#define VOLTAGE_24V_LOW_VAL 23.5

#include <gui_generated/maininfotaiment_screen/MainInfotaimentViewBase.hpp>
#include <gui/maininfotaiment_screen/MainInfotaimentPresenter.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

class MainInfotaimentView : public MainInfotaimentViewBase
{
public:
    MainInfotaimentView();
    virtual ~MainInfotaimentView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setGear(int gear);
    void setRpm(int rpm);
    void setSpeed(int speed);

    void setT_Water(int t_water);
    void setT_Oil(int t_oil);
    void setP_Oil(float p_oil);
    void setP_Fuel(float p_fuel);

    void setThrottle_Perc(int throttle_perc);
    void setFrontBrake_Perc(int brake_perc);
    void setRearBrake_Perc(int brake_perc);

    void setOrinTemperature(float orinTemperature);
    void setVoltage24v(float voltage24v);

    void setRES(int RES);
    void setLC(bool LC);
    void setCLT(bool CLT);

    void setBattery_V(float battery_v);

    void setDebugMessage(const char* msg);

    void setLap(int lap);

    /* TODO: String variables */

protected:
};

#endif // MAININFOTAIMENTVIEW_HPP
