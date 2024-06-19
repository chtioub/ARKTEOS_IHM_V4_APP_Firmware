#ifndef INSTALLATION_APPOINTPRESENTER_HPP
#define INSTALLATION_APPOINTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_appointView;

class Installation_appointPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_appointPresenter(Installation_appointView& v);

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

    virtual ~Installation_appointPresenter() {}

private:
    Installation_appointPresenter();

    Installation_appointView& view;
};

#endif // INSTALLATION_APPOINTPRESENTER_HPP
