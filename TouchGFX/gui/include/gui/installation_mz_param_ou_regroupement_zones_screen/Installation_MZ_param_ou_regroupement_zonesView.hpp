#ifndef INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP
#define INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP

#include <gui_generated/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesViewBase.hpp>
#include <gui/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesPresenter.hpp>

class Installation_MZ_param_ou_regroupement_zonesView : public Installation_MZ_param_ou_regroupement_zonesViewBase
{
public:
    Installation_MZ_param_ou_regroupement_zonesView();
    virtual ~Installation_MZ_param_ou_regroupement_zonesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP
