#ifndef INSTALLATION_ECS_PUISSANCE_ECHANGEURVIEW_HPP
#define INSTALLATION_ECS_PUISSANCE_ECHANGEURVIEW_HPP

#include <gui_generated/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurViewBase.hpp>
#include <gui/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurPresenter.hpp>

class Installation_ecs_puissance_echangeurView : public Installation_ecs_puissance_echangeurViewBase
{
public:
    Installation_ecs_puissance_echangeurView();
    virtual ~Installation_ecs_puissance_echangeurView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider();
    void bouton_gauche_puissance();
    void bouton_droit_puissance();
    void update_PW_echangeur();

    virtual void changeDate(S_DATE *sDate);
 	virtual void changeErreur(uint16_t u16Erreur);
 	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
 	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	unsigned char u2PW_Echangeur :2;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
   };

#endif // INSTALLATION_ECS_PUISSANCE_ECHANGEURVIEW_HPP
