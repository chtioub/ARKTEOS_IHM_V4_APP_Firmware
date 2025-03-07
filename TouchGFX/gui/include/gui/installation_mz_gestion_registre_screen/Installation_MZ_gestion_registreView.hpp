#ifndef INSTALLATION_MZ_GESTION_REGISTREVIEW_HPP
#define INSTALLATION_MZ_GESTION_REGISTREVIEW_HPP

#include <gui_generated/installation_mz_gestion_registre_screen/Installation_MZ_gestion_registreViewBase.hpp>
#include <gui/installation_mz_gestion_registre_screen/Installation_MZ_gestion_registrePresenter.hpp>

class Installation_MZ_gestion_registreView : public Installation_MZ_gestion_registreViewBase
{
public:
    Installation_MZ_gestion_registreView();
    virtual ~Installation_MZ_gestion_registreView() {}
    virtual void setupScreen();
	virtual void tearDownScreen();

    void bouton_valider();
    void bouton_non();
    void bouton_oui();
    void bouton_droite_consigne();
    void bouton_gauche_consigne();


	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
 	uint8_t u8NumZone, u8GestionRegistre;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	S_STATUT_RF sStatut_RF_old;
	unsigned char   bRegistreForce : 1;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_ValeurRegistre[4];
};

#endif // INSTALLATION_MZ_GESTION_REGISTREVIEW_HPP
