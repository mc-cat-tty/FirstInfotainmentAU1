/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/startup_screen/StartupViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

StartupViewBase::StartupViewBase() :
    fromStartupToInfotaimentCounter(0)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backgroundStartup.setXY(0, 0);
    backgroundStartup.setBitmap(touchgfx::Bitmap(BITMAP_MMRD_LOGO_NUOVO_800X480_ID));
    add(backgroundStartup);
}

StartupViewBase::~StartupViewBase()
{

}

void StartupViewBase::setupScreen()
{

}

void StartupViewBase::afterTransition()
{
    //fromStartupToInfotaiment
    //When screen transition ends delay
    //Delay for 2400 ms (144 Ticks)
    fromStartupToInfotaimentCounter = FROMSTARTUPTOINFOTAIMENT_DURATION;
}

void StartupViewBase::handleTickEvent()
{
    if (fromStartupToInfotaimentCounter > 0)
    {
        fromStartupToInfotaimentCounter--;
        if (fromStartupToInfotaimentCounter == 0)
        {
                //changeScreen
                //When fromStartupToInfotaiment completed change screen to MainInfotaiment
                //Go to MainInfotaiment with screen transition towards East
                application().gotoMainInfotaimentScreenWipeTransitionEast();
        }
    }
}
