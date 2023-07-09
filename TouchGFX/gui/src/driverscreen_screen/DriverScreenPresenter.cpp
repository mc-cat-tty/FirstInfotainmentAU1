#include <gui/driverscreen_screen/DriverScreenView.hpp>
#include <gui/driverscreen_screen/DriverScreenPresenter.hpp>

DriverScreenPresenter::DriverScreenPresenter(DriverScreenView& v)
    : view(v)
{

}

void DriverScreenPresenter::activate()
{
	infoChanged();
	gearChanged();
}

void DriverScreenPresenter::deactivate()
{

}

void DriverScreenPresenter::gearChanged() {
	view.setGear(model->getGear());
}

void DriverScreenPresenter::infoChanged() {
	view.setGear(model->getGear());

	view.setRpm(model->getRpm());
	view.setLap(model->getLap());
	view.setSpeed(model->getSpeed());

	view.setRES(model->getRES());
	view.setLC(model->getLC());
	view.setCLT(model->getCLT());

	view.setTmot(model->getT_water());
	view.setToil(model->getT_oil());
	view.setTorin(model->getOrinTemperature());

	view.setPoil(model->getP_oil());
	view.setPfuel(model->getP_fuel());
	view.setPbrake(model->getFrontBrakePerc());

	view.setTPS(model->getThrottle_perc());

	view.setBat12(model->getBattery_v());
	view.setBat24(model->getVoltage24v());
}
