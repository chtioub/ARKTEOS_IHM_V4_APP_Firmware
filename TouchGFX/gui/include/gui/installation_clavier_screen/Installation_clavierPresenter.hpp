#ifndef INSTALLATION_CLAVIERPRESENTER_HPP
#define INSTALLATION_CLAVIERPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_clavierView;

class Installation_clavierPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_clavierPresenter(Installation_clavierView& v);

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

    virtual ~Installation_clavierPresenter() {}

private:
    Installation_clavierPresenter();

    Installation_clavierView& view;
};

#endif // INSTALLATION_CLAVIERPRESENTER_HPP
