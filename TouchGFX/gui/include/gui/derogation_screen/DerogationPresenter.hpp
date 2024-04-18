#ifndef DEROGATIONPRESENTER_HPP
#define DEROGATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DerogationView;

class DerogationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DerogationPresenter(DerogationView& v);

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

    virtual ~DerogationPresenter() {}

private:
    DerogationPresenter();

    DerogationView& view;
};

#endif // DEROGATIONPRESENTER_HPP
