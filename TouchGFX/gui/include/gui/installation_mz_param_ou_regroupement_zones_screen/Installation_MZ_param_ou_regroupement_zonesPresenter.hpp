#ifndef INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESPRESENTER_HPP
#define INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_MZ_param_ou_regroupement_zonesView;

class Installation_MZ_param_ou_regroupement_zonesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_MZ_param_ou_regroupement_zonesPresenter(Installation_MZ_param_ou_regroupement_zonesView& v);

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

    virtual ~Installation_MZ_param_ou_regroupement_zonesPresenter() {}

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);

private:
    Installation_MZ_param_ou_regroupement_zonesPresenter();

    Installation_MZ_param_ou_regroupement_zonesView& view;
};

#endif // INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESPRESENTER_HPP
