#ifndef INSTALLATION_MODE_SILENCIEUXVIEW_HPP
#define INSTALLATION_MODE_SILENCIEUXVIEW_HPP

#include <gui_generated/installation_mode_silencieux_screen/Installation_mode_silencieuxViewBase.hpp>
#include <gui/installation_mode_silencieux_screen/Installation_mode_silencieuxPresenter.hpp>

class Installation_mode_silencieuxView : public Installation_mode_silencieuxViewBase
{
public:
    Installation_mode_silencieuxView();
    virtual ~Installation_mode_silencieuxView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	void bouton_arret();
	void bouton_marche_prog();
	void bouton_valider();
	void bouton_gauche_limitation_pw();
	void bouton_droit_limitation_pw();
	void update_val_limitation_PW();
	void update_toggle_boutons();


	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	unsigned char Type_Degivrage  :1;
	unsigned char u2NiveauSilence :2;
	uint8_t bModeSilencieux:1;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_LimitationPW[3];
};
#endif // INSTALLATION_MODE_SILENCIEUXVIEW_HPP
