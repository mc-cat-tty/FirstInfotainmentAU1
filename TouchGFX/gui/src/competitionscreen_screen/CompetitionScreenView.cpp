#include <gui/competitionscreen_screen/CompetitionScreenView.hpp>

CompetitionScreenView::CompetitionScreenView() { }

void CompetitionScreenView::setupScreen()
{
    CompetitionScreenViewBase::setupScreen();
}

void CompetitionScreenView::tearDownScreen()
{
    CompetitionScreenViewBase::tearDownScreen();
}

void CompetitionScreenView::setMission(const char *mission) {
	Unicode::strncpy(txtMissionBuffer, mission, TXTMISSION_SIZE);
	txtMission.invalidate();
}
