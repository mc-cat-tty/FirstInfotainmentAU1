#ifndef DRIVERSCREENPRESENTER_HPP
#define DRIVERSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DriverScreenView;

class DriverScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DriverScreenPresenter(DriverScreenView& v);

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

    virtual void gearChanged();
    virtual void infoChanged();

    virtual ~DriverScreenPresenter() {}

private:
    DriverScreenPresenter();

    DriverScreenView& view;
};

#endif // DRIVERSCREENPRESENTER_HPP
