#ifndef INSTALLATION_ECSPRESENTER_HPP
#define INSTALLATION_ECSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_ecsView;

class Installation_ecsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_ecsPresenter(Installation_ecsView& v);

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

    virtual ~Installation_ecsPresenter() {}

private:
    Installation_ecsPresenter();

    Installation_ecsView& view;
};

#endif // INSTALLATION_ECSPRESENTER_HPP
