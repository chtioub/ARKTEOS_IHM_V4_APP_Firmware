#ifndef INSTALLATION_ECS_CYCLE_LEGIONELVIEW_HPP
#define INSTALLATION_ECS_CYCLE_LEGIONELVIEW_HPP

#include <gui_generated/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelViewBase.hpp>
#include <gui/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelPresenter.hpp>

class Installation_ecs_cycle_legionelView : public Installation_ecs_cycle_legionelViewBase
{
public:
    Installation_ecs_cycle_legionelView();
    virtual ~Installation_ecs_cycle_legionelView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void update_heure_antilegionellose();
    void update_jour_antilegionellose();
    void bouton_valider();
    void bouton_oui_legionelle();
    void bouton_non_legionelle();
    void bouton_gauche_jour();
    void bouton_droit_jour();
    void bouton_gauche_heure();
    void bouton_droit_heure();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	 bool bConnexionDistance;
//	    uint8_t u8PressionLongue_droite, u8PressionLongue_gauche;
	    uint16_t u16ErreurAffichee;
	    unsigned char bAntiLegionnel, Jour_Legionel, Heure_Legionel;
	    S_DATE sDate_old;
	    S_CONFIG_IHM sConfig_IHM_old;
	    S_STATUT_PAC sStatut_PAC_old;
	    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_HeureLegionelle[8], textAreaBuffer_JourLegionelle[9];
};

#endif // INSTALLATION_ECS_CYCLE_LEGIONELVIEW_HPP
