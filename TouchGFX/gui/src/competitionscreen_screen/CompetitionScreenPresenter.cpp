#include <gui/competitionscreen_screen/CompetitionScreenView.hpp>
#include <gui/competitionscreen_screen/CompetitionScreenPresenter.hpp>

CompetitionScreenPresenter::CompetitionScreenPresenter(CompetitionScreenView& v)
    : view(v)
{

}

void CompetitionScreenPresenter::activate()
{
	missionChanged();
}

void CompetitionScreenPresenter::deactivate()
{

}

void CompetitionScreenPresenter::missionChanged() {
	view.setMission(model->getMission());
}
