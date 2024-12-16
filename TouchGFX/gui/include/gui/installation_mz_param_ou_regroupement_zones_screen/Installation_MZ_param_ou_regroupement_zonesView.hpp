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

    void bouton_retour();

	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP
