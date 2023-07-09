#include <gui/maininfotaiment_screen/MainInfotaimentView.hpp>


MainInfotaimentView::MainInfotaimentView()
{

}

void MainInfotaimentView::setupScreen()
{
  MainInfotaimentViewBase::setupScreen();
}

void MainInfotaimentView::tearDownScreen()
{
  MainInfotaimentViewBase::tearDownScreen();
}

void MainInfotaimentView::setGear(int gear)
{
	//update text area

	if (!gear)
		Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%c", 'N');
	else
		Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%d", gear);
	Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%3d", 150);
	Unicode::snprintf(txtRpmBuffer, TXTRPM_SIZE, "%4d", 4200);

  txtGear.invalidate();
}

void MainInfotaimentView::setSpeed(int speed)
{
	//update text area

	Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%3.3d", speed);

  txtSpeed.invalidate();
}

void MainInfotaimentView::setRpm(int rpm)
{
	//update text area

	Unicode::snprintf(txtRpmBuffer, TXTRPM_SIZE, "%5.5d", rpm);
	if (rpm < 4500)
	{
		progressRpmLow.setValue(0);
		progressRpmMed.setValue(0);
		progressRpmHigh.setValue(0);
	} else if ((rpm >= 4500) && (rpm < 6000))
	{
		progressRpmLow.setValue(100);
		progressRpmMed.setValue(0);
		progressRpmHigh.setValue(0);
	} else if ((rpm >= 6000) && (rpm < 9000))
	{
		progressRpmLow.setValue(100);
		progressRpmMed.setValue(100);
		progressRpmHigh.setValue(0);
	} else if ((rpm >= 9000) && (rpm < 10500))
	{
		progressRpmLow.setValue(100);
		progressRpmMed.setValue(100);
		progressRpmHigh.setValue(100);
	} else
	{
		if (progressRpmLow.getValue() == 100)
		{
			progressRpmLow.setValue(0);
			progressRpmMed.setValue(0);
			progressRpmHigh.setValue(0);
		} else
		{
			progressRpmLow.setValue(100);
			progressRpmMed.setValue(100);
			progressRpmHigh.setValue(100);
		}
	}
  txtRpm.invalidate();
}

void MainInfotaimentView::setT_Water(int t_water)
{
	/* Update T_WATER img */
	if (t_water <= WATER_TEMP_LOW_VAL )
		imgWaterTemp.setBitmap(touchgfx::Bitmap(BITMAP_WATER_LOW_ID));
	else if (t_water <= WATER_TEMP_OK_VAL )
		imgWaterTemp.setBitmap(touchgfx::Bitmap(BITMAP_WATER_OK_ID));
	else
		imgWaterTemp.setBitmap(touchgfx::Bitmap(BITMAP_WATER_HIGH_ID));

	/* Update T_WATER text */
	Unicode::snprintf(txtTWaterBuffer, TXTTWATER_SIZE, "%3.3d", t_water);

	txtTWater.invalidate();
	imgWaterTemp.invalidate();
}

void MainInfotaimentView::setT_Oil(int t_oil)
{
	/* Update T_OIL img */
	if (t_oil <= OIL_TEMP_LOW_VAL )
    imgOilTemp.setBitmap(touchgfx::Bitmap(BITMAP_OIL_TEMP_LOW_ID));
	else if (t_oil <= OIL_TEMP_OK_VAL )
    imgOilTemp.setBitmap(touchgfx::Bitmap(BITMAP_OIL_TEMP_OK_ID));
	else
    imgOilTemp.setBitmap(touchgfx::Bitmap(BITMAP_OIL_TEMP_HIGH_ID));

	/* Update T_OIL text */
	Unicode::snprintf(txtTOilBuffer, TXTTOIL_SIZE, "%3.3d", t_oil);

	txtTOil.invalidate();
	imgOilTemp.invalidate();
}

void MainInfotaimentView::setP_Oil(float p_oil)
{
	/* Update P_OIL img */
	if (p_oil <= OIL_PRESS_LOW_VAL )
    	imgOilPres.setBitmap(touchgfx::Bitmap(BITMAP_OIL_PRES_LOW_ID));
	else if (p_oil <= OIL_PRESS_OK_VAL )
		imgOilPres.setBitmap(touchgfx::Bitmap(BITMAP_OIL_PRES_OK_ID));
	else
		imgOilPres.setBitmap(touchgfx::Bitmap(BITMAP_OIL_PRES_HIGH_ID));

	/* Update P_OIL text */
	Unicode::snprintfFloat(txtPOilBuffer, TXTPOIL_SIZE, "%.2f", p_oil);

	txtPOil.invalidate();
	imgOilPres.invalidate();
}

void MainInfotaimentView::setP_Fuel(float p_fuel) {
	Unicode::snprintfFloat(txtPFuelBuffer, TXTPFUEL_SIZE, "%.2f", p_fuel);
	txtPFuel.invalidate();
}

void MainInfotaimentView::setThrottle_Perc(int throttle_perc)
{
	progressThrottle.setValue(throttle_perc);
}

void MainInfotaimentView::setFrontBrake_Perc(int brake_perc)
{
	progressBrakeFront.setValue(brake_perc);
}

void MainInfotaimentView::setRearBrake_Perc(int brake_perc)
{
	progressBrakeRear.setValue(brake_perc);
}

void MainInfotaimentView::setOrinTemperature(float orinTemperature) {
  if (orinTemperature <= ORIN_T_OK_VAL)
    imgTOrin.setBitmap(touchgfx::Bitmap(BITMAP_ORIN_T_OK_ID));
  else
    imgTOrin.setBitmap(touchgfx::Bitmap(BITMAP_ORIN_T_HIGH_ID));

  Unicode::snprintfFloat(txtTOrinBuffer, TXTTORIN_SIZE, "%.f", orinTemperature);

  imgTOrin.invalidate();
  txtTOrin.invalidate();
}

#define BITMAP_24V_OK_ID BITMAP_BATTERY_OK_ID
#define BITMAP_24V_LOW_ID BITMAP_BATTERY_LOW_ID
#define BITMAP_24V_HIGH_ID BITMAP_BATTERY_HIGH_ID

void MainInfotaimentView::setVoltage24v(float voltage24v) {
  if (voltage24v <= VOLTAGE_24V_LOW_VAL)
		img24v.setBitmap(touchgfx::Bitmap(BITMAP_24V_LOW_ID));
  else if (voltage24v <= VOLTAGE_24V_OK_VAL)  
    img24v.setBitmap(touchgfx::Bitmap(BITMAP_24V_OK_ID));
  else
    img24v.setBitmap(touchgfx::Bitmap(BITMAP_24V_HIGH_ID));

  Unicode::snprintfFloat(txt24vBuffer, TXT24V_SIZE, "%2.1f", voltage24v);
  img24v.invalidate();
  txt24v.invalidate();
}

void MainInfotaimentView::setRES(int RES)
{
	if(!RES)
	{
		/* Turn RES EMERGENCY MODE box */
		boxRES.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		labelRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	} else if(RES == 1)
	{
		/* Turn RES IDLE MODE box */
		boxRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
		labelRES.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	} else if(RES == 3)
	{
		/* Turn RES GO MODE box */
		boxRES.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		labelRES.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	}

	boxRES.invalidate();
	labelRES.invalidate();
}

void MainInfotaimentView::setLC(bool LC)
{
	if(!LC)
	{
		/* Turn off LC box */
    boxLC.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelLC.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	} else
	{
		/* Turn on LC box */
    boxLC.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    labelLC.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	}

	boxLC.invalidate();
	labelLC.invalidate();
}

void MainInfotaimentView::setCLT(bool CLT)
{
	if(!CLT)
	{
		/* Turn off CLT box */
    boxClutch.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    labelClutch.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	} else
	{
		/* Turn on CLT box */
    boxClutch.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    labelClutch.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	}

	boxClutch.invalidate();
	labelClutch.invalidate();
}

void MainInfotaimentView::setBattery_V(float battery_v)
{
	/* Update BATTERY_V img */
	if (battery_v <= BATTERY_V_LOW_VAL )
    imgBatteryV.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_LOW_ID));
	else if (battery_v <= BATTERY_V_OK_VAL )
    imgBatteryV.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_OK_ID));
	else
    imgBatteryV.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_HIGH_ID));

	/* Update BATTERY_V text */
	Unicode::snprintfFloat(txtBattery_VBuffer, TXTBATTERY_V_SIZE, "%2.1f", battery_v);

	txtBattery_V.invalidate();
	imgBatteryV.invalidate();
}

void MainInfotaimentView::setLap(int lap) {
	Unicode::snprintf(txtLapBuffer, TXTLAP_SIZE, "%d", lap);

  txtLap.invalidate();
}

/* TODO: String variables */


void MainInfotaimentView::setDebugMessage(const char* msg) {
	if (msg == nullptr) {
		Unicode::strncpy(dbgTextAreaBuffer, "", DBGTEXTAREA_SIZE);
	} else {
		Unicode::strncpy(dbgTextAreaBuffer, msg, DBGTEXTAREA_SIZE);
	}

	dbgTextArea.invalidate();
}