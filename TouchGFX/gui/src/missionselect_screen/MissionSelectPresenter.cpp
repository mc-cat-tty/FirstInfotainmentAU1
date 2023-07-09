#include <gui/missionselect_screen/MissionSelectView.hpp>
#include <gui/missionselect_screen/MissionSelectPresenter.hpp>

MissionSelectPresenter::MissionSelectPresenter(MissionSelectView& v)
    : view(v)
{

}


void MissionSelectPresenter::activate()
{

}

void MissionSelectPresenter::deactivate()
{

}

void MissionSelectPresenter::requestMission(MmrMission missionType)
{
    model->requestMission(missionType);
}

void MissionSelectPresenter::requestChassisReset() {
    model->requestChassisReset();
}
