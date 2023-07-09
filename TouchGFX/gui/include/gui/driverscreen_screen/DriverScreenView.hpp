#ifndef DRIVERSCREENVIEW_HPP
#define DRIVERSCREENVIEW_HPP

#include <gui_generated/driverscreen_screen/DriverScreenViewBase.hpp>
#include <gui/driverscreen_screen/DriverScreenPresenter.hpp>

class DriverScreenView : public DriverScreenViewBase
{
public:
    DriverScreenView();
    virtual ~DriverScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setGear(int gear);

	void setRpm(int rpm);
	void setLap(int lap);
	void setSpeed(int speed);

	void setRES(int resVal);
	void setLC(bool isLcOn);
	void setCLT(bool isCltPulled);

	void setTmot(int motTemp);
	void setToil(int oilTemp);
	void setTorin(int orinTemp);

	void setPoil(float oilPressure);
	void setPfuel(float fuelPressure);
	void setPbrake(int brakePressure);

	void setTPS(int tpsPercentage);  // between 1 an 100

	void setBat12(float voltage);
	void setBat24(float voltage);


protected:
};

#endif // DRIVERSCREENVIEW_HPP
