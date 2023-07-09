#ifndef MAININFOTAIMENTPRESENTER_HPP
#define MAININFOTAIMENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainInfotaimentView;

class MainInfotaimentPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainInfotaimentPresenter(MainInfotaimentView& v);

    void TESTFUNCTION();

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainInfotaimentPresenter() {};

    //from model
    virtual void gearChanged();
    virtual void infoChanged();
    virtual void debugMessageChanged();

private:
    MainInfotaimentPresenter();

    MainInfotaimentView& view;
};

#endif // MAININFOTAIMENTPRESENTER_HPP
