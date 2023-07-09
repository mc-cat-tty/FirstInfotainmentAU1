#ifndef COMPETITIONSCREENVIEW_HPP
#define COMPETITIONSCREENVIEW_HPP

#include <gui_generated/competitionscreen_screen/CompetitionScreenViewBase.hpp>
#include <gui/competitionscreen_screen/CompetitionScreenPresenter.hpp>

class CompetitionScreenView : public CompetitionScreenViewBase
{
public:
    CompetitionScreenView();
    virtual ~CompetitionScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setMission(const char *mission);
protected:
};

#endif // COMPETITIONSCREENVIEW_HPP
