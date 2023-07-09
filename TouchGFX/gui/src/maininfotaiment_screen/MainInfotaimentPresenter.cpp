#include <gui/maininfotaiment_screen/MainInfotaimentView.hpp>
#include <gui/maininfotaiment_screen/MainInfotaimentPresenter.hpp>

MainInfotaimentPresenter::MainInfotaimentPresenter(MainInfotaimentView& v)
    : view(v)
{

}

void MainInfotaimentPresenter::TESTFUNCTION()
{
	view.setRES(3);
}

void MainInfotaimentPresenter::activate()
{
	infoChanged();
	debugMessageChanged();
}

void MainInfotaimentPresenter::deactivate()
{
	
}

void MainInfotaimentPresenter::gearChanged()
{
	view.setGear(model->getGear());
}

void MainInfotaimentPresenter::infoChanged()
{
	view.setGear(model->getGear());
	view.setSpeed(model->getSpeed());
	view.setRpm(model->getRpm());

	view.setT_Water(model->getT_water());
	view.setT_Oil(model->getT_oil());
	view.setP_Oil(model->getP_oil());
	view.setP_Fuel(model->getP_fuel());

	view.setThrottle_Perc(model->getThrottle_perc());

	view.setFrontBrake_Perc(model->getFrontBrakePerc());
	view.setRearBrake_Perc(model->getRearBrakePerc());

	view.setRES(model->getRES());
	view.setLC(model->getLC());
	view.setCLT(model->getCLT());

	view.setBattery_V(model->getBattery_v());

	view.setOrinTemperature(model->getOrinTemperature());
	view.setVoltage24v(model->getVoltage24v());
	view.setLap(model->getLap());

	/* TODO: String variables */
}


void MainInfotaimentPresenter::debugMessageChanged() {
	view.setDebugMessage(model->getDebugMessage());
}
