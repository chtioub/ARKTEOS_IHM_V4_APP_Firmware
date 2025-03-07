#ifndef INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDVIEW_HPP
#define INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDVIEW_HPP

#include <gui_generated/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidViewBase.hpp>
#include <gui/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidPresenter.hpp>

class Installation_MZ_param_complementaires_froidView : public Installation_MZ_param_complementaires_froidViewBase
{
public:
    Installation_MZ_param_complementaires_froidView();
    virtual ~Installation_MZ_param_complementaires_froidView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_valider();
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	void bouton_droite_consigne();
	void bouton_gauche_consigne();
	void bouton_oui();
	void bouton_non();
	void bouton_retour();
protected:
		bool bConnexionDistance, bModeFroid;
		uint16_t u16ErreurAffichee, u16ConsigneFroid;
		S_DATE sDate_old;
		S_CONFIG_IHM sConfig_IHM_old;
		S_STATUT_PAC sStatut_PAC_old;
		touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[50], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Consigne[3];
};

#endif // INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDVIEW_HPP
