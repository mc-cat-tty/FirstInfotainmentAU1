#include <gui/missionselect_screen/MissionSelectView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "gui_shared_defs.h"

void MissionSelectView::setupScreen()
{
    MissionSelectViewBase::setupScreen();
}

void MissionSelectView::onChassisResetClicked() {
    presenter->requestChassisReset();
}

void MissionSelectView::onIdleBtnClicked() {
	presenter->requestMission(MMR_MISSION_IDLE);
}

void MissionSelectView::onAccelerationBtnClicked() {
	presenter->requestMission(MMR_MISSION_ACCELERATION);
}

void MissionSelectView::onSkidpadBtnClicked() {
	presenter->requestMission(MMR_MISSION_SKIDPAD);
}

void MissionSelectView::onAutocrossBtnClicked() {
	presenter->requestMission(MMR_MISSION_AUTOCROSS);
}

void MissionSelectView::onTrackdriveBtnClicked() {
	presenter->requestMission(MMR_MISSION_TRACKDRIVE);
}

void MissionSelectView::onEbsTestBtnClicked() {
	presenter->requestMission(MMR_MISSION_EBS_TEST);
}

void MissionSelectView::onInspectionBtnClicked() {
	presenter->requestMission(MMR_MISSION_INSPECTION);
}

void MissionSelectView::onManualBtnClicked() {
	presenter->requestMission(MMR_MISSION_MANUAL);
}

void MissionSelectView::onDebugBtnClicked() {
	presenter->requestMission(MMR_MISSION_DEBUG);
}

MissionSelectView::MissionSelectView() {

}

void MissionSelectView::tearDownScreen() {
    MissionSelectViewBase::tearDownScreen();
}
