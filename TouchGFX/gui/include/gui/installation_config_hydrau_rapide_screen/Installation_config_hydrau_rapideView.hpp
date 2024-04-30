#ifndef INSTALLATION_CONFIG_HYDRAU_RAPIDEVIEW_HPP
#define INSTALLATION_CONFIG_HYDRAU_RAPIDEVIEW_HPP

#include <gui_generated/installation_config_hydrau_rapide_screen/Installation_config_hydrau_rapideViewBase.hpp>
#include <gui/installation_config_hydrau_rapide_screen/Installation_config_hydrau_rapidePresenter.hpp>

class Installation_config_hydrau_rapideView : public Installation_config_hydrau_rapideViewBase
{
public:
    Installation_config_hydrau_rapideView();
    virtual ~Installation_config_hydrau_rapideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_CONFIG_HYDRAU_RAPIDEVIEW_HPP
