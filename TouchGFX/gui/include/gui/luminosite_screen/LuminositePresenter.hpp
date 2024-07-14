#ifndef LUMINOSITEPRESENTER_HPP
#define LUMINOSITEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LuminositeView;

class LuminositePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LuminositePresenter(LuminositeView& v);

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

    virtual ~LuminositePresenter() {}

private:
    LuminositePresenter();

    LuminositeView& view;
};

#endif // LUMINOSITEPRESENTER_HPP
