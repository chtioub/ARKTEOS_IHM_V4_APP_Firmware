#ifndef INSTALLATION_MZ_CONFIG_GROUPEVIEW_HPP
#define INSTALLATION_MZ_CONFIG_GROUPEVIEW_HPP

#include <gui_generated/installation_mz_config_groupe_screen/Installation_MZ_config_groupeViewBase.hpp>
#include <gui/installation_mz_config_groupe_screen/Installation_MZ_config_groupePresenter.hpp>

class Installation_MZ_config_groupeView : public Installation_MZ_config_groupeViewBase
{
public:
    Installation_MZ_config_groupeView();
    virtual ~Installation_MZ_config_groupeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_MZ_CONFIG_GROUPEVIEW_HPP
