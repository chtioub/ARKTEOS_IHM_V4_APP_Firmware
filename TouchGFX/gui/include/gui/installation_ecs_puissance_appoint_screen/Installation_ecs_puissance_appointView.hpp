#ifndef INSTALLATION_ECS_PUISSANCE_APPOINTVIEW_HPP
#define INSTALLATION_ECS_PUISSANCE_APPOINTVIEW_HPP

#include <gui_generated/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointViewBase.hpp>
#include <gui/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointPresenter.hpp>

class Installation_ecs_puissance_appointView : public Installation_ecs_puissance_appointViewBase
{
public:
    Installation_ecs_puissance_appointView();
    virtual ~Installation_ecs_puissance_appointView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider();
    void bouton_gauche_puissance();
    void bouton_droit_puissance();
    void update_PW_appoint();

    virtual void changeDate(S_DATE *sDate);
 	virtual void changeErreur(uint16_t u16Erreur);
 	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
 	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	unsigned char u6PW_Brin :6;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_PWAppoint[5];
   };

#endif // INSTALLATION_ECS_PUISSANCE_APPOINTVIEW_HPP
