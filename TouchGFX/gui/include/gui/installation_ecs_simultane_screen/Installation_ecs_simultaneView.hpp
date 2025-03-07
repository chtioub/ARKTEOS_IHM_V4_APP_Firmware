#ifndef INSTALLATION_ECS_SIMULTANEVIEW_HPP
#define INSTALLATION_ECS_SIMULTANEVIEW_HPP

#include <gui_generated/installation_ecs_simultane_screen/Installation_ecs_simultaneViewBase.hpp>
#include <gui/installation_ecs_simultane_screen/Installation_ecs_simultanePresenter.hpp>

class Installation_ecs_simultaneView : public Installation_ecs_simultaneViewBase
{
public:
    Installation_ecs_simultaneView();
    virtual ~Installation_ecs_simultaneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeDate(S_DATE *sDate);
   	virtual void changeErreur(uint16_t u16Erreur);
   	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
   	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

   	void update_reduction_loi_deau();
   	void update_temps_max();
   	void update_percent_vanne();
   	void bouton_valider();
   	void bouton_gauche_temps_simultane();
	void bouton_droit_temps_simultane();
	void bouton_gauche_temp_loi_deau();
	void bouton_droit_temp_loi_deau();
	void bouton_gauche_ouverture_vanne();
	void bouton_droit_ouverture_vanne();
	void bouton_oui();
	void bouton_non();

protected:
    bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	unsigned char bGestionSimultanee, u4DeltaLoiDeauSimultanee, u3MiniOuvertureVanne, u2TpsFinSimu;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Temps_Fin_Simu[24], textAreaBuffer_ReducLoiDeau[6], textAreaBuffer_PercentV3V[18];
   };

#endif // INSTALLATION_ECS_SIMULTANEVIEW_HPP
