#ifndef INSTALLATION_MZ_REGLAGE_DEBIT_AIRVIEW_HPP
#define INSTALLATION_MZ_REGLAGE_DEBIT_AIRVIEW_HPP

#include <gui_generated/installation_mz_reglage_debit_air_screen/Installation_MZ_reglage_debit_airViewBase.hpp>
#include <gui/installation_mz_reglage_debit_air_screen/Installation_MZ_reglage_debit_airPresenter.hpp>

class Installation_MZ_reglage_debit_airView : public Installation_MZ_reglage_debit_airViewBase
{
public:
    Installation_MZ_reglage_debit_airView();
    virtual ~Installation_MZ_reglage_debit_airView() {}
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
	uint8_t u8NumZone, u8VitesseVentil;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	unsigned char bActivationCorrection : 1;
	unsigned char CorrectionDebitAir;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_ValeurVitesseVentil[4];
};

#endif // INSTALLATION_MZ_REGLAGE_DEBIT_AIRVIEW_HPP
