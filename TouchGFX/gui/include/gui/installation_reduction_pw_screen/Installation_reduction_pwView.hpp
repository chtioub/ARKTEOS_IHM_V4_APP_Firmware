#ifndef INSTALLATION_REDUCTION_PWVIEW_HPP
#define INSTALLATION_REDUCTION_PWVIEW_HPP

#include <gui_generated/installation_reduction_pw_screen/Installation_reduction_pwViewBase.hpp>
#include <gui/installation_reduction_pw_screen/Installation_reduction_pwPresenter.hpp>

class Installation_reduction_pwView : public Installation_reduction_pwViewBase
{
public:
    Installation_reduction_pwView();
    virtual ~Installation_reduction_pwView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	void bouton_valider();
	void bouton_gauche();
	void bouton_droit();
	void update_val_reduc_pw();

	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	unsigned char Reduc_PW        :3;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_ReductionPW[20];
};

#endif // INSTALLATION_REDUCTION_PWVIEW_HPP
