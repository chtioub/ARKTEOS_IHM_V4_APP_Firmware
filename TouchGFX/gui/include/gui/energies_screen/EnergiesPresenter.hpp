#ifndef ENERGIESPRESENTER_HPP
#define ENERGIESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EnergiesView;

class EnergiesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    EnergiesPresenter(EnergiesView& v);

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

    virtual ~EnergiesPresenter() {}

private:
    EnergiesPresenter();

    EnergiesView& view;
};

#endif // ENERGIESPRESENTER_HPP
