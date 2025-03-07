#ifndef INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEVIEW_HPP
#define INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEVIEW_HPP

#include <gui_generated/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupeViewBase.hpp>
#include <gui/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupePresenter.hpp>

class Installation_MZ_param_complementaires_groupeView : public Installation_MZ_param_complementaires_groupeViewBase
{
public:
    Installation_MZ_param_complementaires_groupeView();
    virtual ~Installation_MZ_param_complementaires_groupeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_vitesse_droite();
    void bouton_vitesse_gauche();
    void bouton_oui_marche_forcee();
    void bouton_non_marche_forcee();
    void vitesseVentilateur();
    void renommer_groupe();
    void bouton_valider();

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	uint8_t u7VitesseVentilateur:7;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[50], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Vitesse_Ventil[5];
};

#endif // INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEVIEW_HPP
