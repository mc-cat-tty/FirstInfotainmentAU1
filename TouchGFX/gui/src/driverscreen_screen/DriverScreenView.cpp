#include <gui/driverscreen_screen/DriverScreenView.hpp>
#include <touchgfx/Color.hpp>

DriverScreenView::DriverScreenView() {}

void DriverScreenView::setupScreen() {
    DriverScreenViewBase::setupScreen();
}

void DriverScreenView::tearDownScreen() {
    DriverScreenViewBase::tearDownScreen();
}

void DriverScreenView::setGear(int gear) {
	if (gear == 0) {
		Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%c", 'N');
	}
	else {
		Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%d", gear);
	}

	txtGear.invalidate();
}

void DriverScreenView::setRpm(int rpm) {
    Unicode::snprintf(txtRpmBuffer, TXTRPM_SIZE, "%d", rpm);
    txtRpm.invalidate();
}

void DriverScreenView::setLap(int lap) {
    Unicode::snprintf(txtLapBuffer, TXTLAP_SIZE, "%d", lap);
    txtLap.invalidate();
}

void DriverScreenView::setSpeed(int speed) {
    Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%d", speed);
    txtSpeed.invalidate();
}

void DriverScreenView::setRES(int resVal) {
	switch (resVal) {
		case 0:  // Emergency
		boxRES.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		labelRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		break;

		case 1:  // Idle
		boxRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		labelRES.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;

		case 3:  // Go
		boxRES.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		labelRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		break;
	}

	boxRES.invalidate();
	labelRES.invalidate();
}

void DriverScreenView::setLC(bool isLcOn) {
	if (isLcOn) {
		boxLC.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		labelLC.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	}
	else {
		boxLC.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		labelLC.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	}

	boxLC.invalidate();
	labelLC.invalidate();
}

void DriverScreenView::setCLT(bool isCltPulled) {
	if (isCltPulled) {
		boxCLT.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		labelCLT.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	}
	else {
		boxCLT.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		labelCLT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	}

	boxCLT.invalidate();
	labelCLT.invalidate();
}


void DriverScreenView::setTmot(int motTemp) {
    Unicode::snprintf(txtTmotBuffer, TXTTMOT_SIZE, "%d", motTemp);
    txtTmot.invalidate();
}

void DriverScreenView::setToil(int oilTemp) {
    Unicode::snprintf(txtToilBuffer, TXTTOIL_SIZE, "%d", oilTemp);
    txtToil.invalidate();
}

void DriverScreenView::setTorin(int orinTemp) {
    Unicode::snprintf(txtTorinBuffer, TXTTORIN_SIZE, "%d", orinTemp);
    txtTorin.invalidate();
}

void DriverScreenView::setPoil(float oilPressure) {
    Unicode::snprintfFloat(txtPoilBuffer, TXTPOIL_SIZE, "%.2f", oilPressure);
    txtPoil.invalidate();
}

void DriverScreenView::setPfuel(float fuelPressure) {
    Unicode::snprintfFloat(txtPfuelBuffer, TXTPFUEL_SIZE, "%.1f", fuelPressure);
    txtPfuel.invalidate();
}

void DriverScreenView::setPbrake(int brakePressure) {
    Unicode::snprintf(txtPbrakeBuffer, TXTPBRAKE_SIZE, "%d", brakePressure);
    txtPbrake.invalidate();
}

void DriverScreenView::setTPS(int tpsPercentage) {
    Unicode::snprintf(txtTPSBuffer, TXTTPS_SIZE, "%d", tpsPercentage);
    txtTPS.invalidate();
}

void DriverScreenView::setBat12(float voltage) {
    Unicode::snprintfFloat(txtBat12Buffer, TXTBAT12_SIZE, "%.1f", voltage);
    txtBat12.invalidate();
}

void DriverScreenView::setBat24(float voltage) {
    Unicode::snprintfFloat(txtBat24Buffer, TXTBAT24_SIZE, "%.1f", voltage);
    txtBat24.invalidate();
}
