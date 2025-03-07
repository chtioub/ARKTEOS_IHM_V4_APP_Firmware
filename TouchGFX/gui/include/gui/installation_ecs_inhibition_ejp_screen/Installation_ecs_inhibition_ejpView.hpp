#ifndef INSTALLATION_ECS_INHIBITION_EJPVIEW_HPP
#define INSTALLATION_ECS_INHIBITION_EJPVIEW_HPP

#include <gui_generated/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpViewBase.hpp>
#include <gui/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpPresenter.hpp>

class Installation_ecs_inhibition_ejpView : public Installation_ecs_inhibition_ejpViewBase
{
public:
    Installation_ecs_inhibition_ejpView();
    virtual ~Installation_ecs_inhibition_ejpView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider();
    void bouton_oui();
    void bouton_non();

    virtual void changeDate(S_DATE *sDate);
 	virtual void changeErreur(uint16_t u16Erreur);
 	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
 	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	unsigned char bCouplageEJP  : 1;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
   };

#endif // INSTALLATION_ECS_INHIBITION_EJPVIEW_HPP
