#ifndef INSTALLATION_CONFIG_IN_OUTPRESENTER_HPP
#define INSTALLATION_CONFIG_IN_OUTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_config_in_outView;

class Installation_config_in_outPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_config_in_outPresenter(Installation_config_in_outView& v);

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

    virtual ~Installation_config_in_outPresenter() {}

private:
    Installation_config_in_outPresenter();

    Installation_config_in_outView& view;
};

#endif // INSTALLATION_CONFIG_IN_OUTPRESENTER_HPP
