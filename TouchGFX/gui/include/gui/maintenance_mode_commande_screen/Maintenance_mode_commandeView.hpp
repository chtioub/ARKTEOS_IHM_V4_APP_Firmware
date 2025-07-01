#ifndef MAINTENANCE_MODE_COMMANDEVIEW_HPP
#define MAINTENANCE_MODE_COMMANDEVIEW_HPP

#include <gui_generated/maintenance_mode_commande_screen/Maintenance_mode_commandeViewBase.hpp>
#include <gui/maintenance_mode_commande_screen/Maintenance_mode_commandePresenter.hpp>

class Maintenance_mode_commandeView : public Maintenance_mode_commandeViewBase
{
public:
    Maintenance_mode_commandeView();
    virtual ~Maintenance_mode_commandeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);

	void bouton_gauche();
	void bouton_droite();
	void bouton_oui();
   	void bouton_non();
   	void update_code_commande();

protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Valeur[60], textAreaBuffer_ValCodeCde[4];
};

#endif // MAINTENANCE_MODE_COMMANDEVIEW_HPP
