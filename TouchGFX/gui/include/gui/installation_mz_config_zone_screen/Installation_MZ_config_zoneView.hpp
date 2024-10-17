#ifndef INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP
#define INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP

#include <gui_generated/installation_mz_config_zone_screen/Installation_MZ_config_zoneViewBase.hpp>
#include <gui/installation_mz_config_zone_screen/Installation_MZ_config_zonePresenter.hpp>

class Installation_MZ_config_zoneView : public Installation_MZ_config_zoneViewBase
{
public:
    Installation_MZ_config_zoneView();
    virtual ~Installation_MZ_config_zoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP
