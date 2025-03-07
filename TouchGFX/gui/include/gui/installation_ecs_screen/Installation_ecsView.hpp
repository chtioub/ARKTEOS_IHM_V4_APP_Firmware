#ifndef INSTALLATION_ECSVIEW_HPP
#define INSTALLATION_ECSVIEW_HPP

#include <gui_generated/installation_ecs_screen/Installation_ecsViewBase.hpp>
#include <gui/installation_ecs_screen/Installation_ecsPresenter.hpp>

class Installation_ecsView : public Installation_ecsViewBase
{
public:
    Installation_ecsView();
    virtual ~Installation_ecsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_hysteresis_ECS();
    void bouton_demande_forcee();
    void update_time_ECS_thermo();
    void update_simultane();
    void update_demande_forcee();
    void bouton_gauche_duree_cycle();
    void bouton_droite_duree_cycle();
    void bouton_oui_ecs();
    void bouton_non_ecs();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	unsigned char bOptionECS : 1;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Time_Thermo_Max[8], textAreaBuffer_DemandeForcee[4];
};

#endif // INSTALLATION_ECSVIEW_HPP
