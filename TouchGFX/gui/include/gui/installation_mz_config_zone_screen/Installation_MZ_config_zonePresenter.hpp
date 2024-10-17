#ifndef INSTALLATION_MZ_CONFIG_ZONEPRESENTER_HPP
#define INSTALLATION_MZ_CONFIG_ZONEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_MZ_config_zoneView;

class Installation_MZ_config_zonePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_MZ_config_zonePresenter(Installation_MZ_config_zoneView& v);

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

    virtual ~Installation_MZ_config_zonePresenter() {}

private:
    Installation_MZ_config_zonePresenter();

    Installation_MZ_config_zoneView& view;
};

#endif // INSTALLATION_MZ_CONFIG_ZONEPRESENTER_HPP
