#ifndef MISSIONSELECTVIEW_HPP
#define MISSIONSELECTVIEW_HPP

#include <gui_generated/missionselect_screen/MissionSelectViewBase.hpp>
#include <gui/containers/missionBtnContainer.hpp>
#include <gui/missionselect_screen/MissionSelectPresenter.hpp>
#include <touchgfx/Callback.hpp>

class MissionSelectView : public MissionSelectViewBase
{
public:
    MissionSelectView();
    
    virtual ~MissionSelectView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    
    virtual void onChassisResetClicked();

    virtual void onIdleBtnClicked();
    virtual void onAccelerationBtnClicked();
    virtual void onSkidpadBtnClicked();
    virtual void onAutocrossBtnClicked();
    virtual void onTrackdriveBtnClicked();
    virtual void onEbsTestBtnClicked();
    virtual void onInspectionBtnClicked();
    virtual void onManualBtnClicked();
    virtual void onDebugBtnClicked();
};

#endif // MISSIONSELECTVIEW_HPP
