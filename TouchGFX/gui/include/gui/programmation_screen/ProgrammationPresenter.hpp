#ifndef PROGRAMMATIONPRESENTER_HPP
#define PROGRAMMATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ProgrammationView;

class ProgrammationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ProgrammationPresenter(ProgrammationView& v);

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

    virtual ~ProgrammationPresenter() {}

private:
    ProgrammationPresenter();

    ProgrammationView& view;
};

#endif // PROGRAMMATIONPRESENTER_HPP
