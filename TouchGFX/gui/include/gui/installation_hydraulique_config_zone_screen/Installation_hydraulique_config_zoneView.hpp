#ifndef INSTALLATION_HYDRAULIQUE_CONFIG_ZONEVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_CONFIG_ZONEVIEW_HPP

#include <gui_generated/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zoneViewBase.hpp>
#include <gui/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zonePresenter.hpp>

class Installation_hydraulique_config_zoneView : public Installation_hydraulique_config_zoneViewBase
{
public:
    Installation_hydraulique_config_zoneView();
    virtual ~Installation_hydraulique_config_zoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_HYDRAULIQUE_CONFIG_ZONEVIEW_HPP
