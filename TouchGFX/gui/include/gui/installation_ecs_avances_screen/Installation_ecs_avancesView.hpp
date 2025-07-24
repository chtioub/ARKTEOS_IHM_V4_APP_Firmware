#ifndef INSTALLATION_ECS_AVANCESVIEW_HPP
#define INSTALLATION_ECS_AVANCESVIEW_HPP

#include <gui_generated/installation_ecs_avances_screen/Installation_ecs_avancesViewBase.hpp>
#include <gui/installation_ecs_avances_screen/Installation_ecs_avancesPresenter.hpp>

class Installation_ecs_avancesView : public Installation_ecs_avancesViewBase
{
public:
    Installation_ecs_avancesView();
    virtual ~Installation_ecs_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	void update_temps_rotation_vanne();
   	void update_type_appoint();
   	void update_type_echangeur();

    void bouton_gauche_type_appoint();
    void bouton_droit_type_appoint();
    void bouton_gauche_type_echangeur();
    void bouton_droit_type_echangeur();
    void bouton_gauche_temps_vanne_ecs();
    void bouton_droit_temps_vanne_ecs();
    void bouton_bouclage_ecs();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	uint8_t Time_Bascul_V3V_ECS;
	unsigned char bTypeAppointECS, u2TypeEchangeur, bSolaire, bCouplageEJP, bBouclageECS;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_TypeAppoint[19], textAreaBuffer_TypeEchangeur[11], textAreaBuffer_TempsV3V[13], textAreaBuffer_BouclageECS[4], textAreaBuffer_CouplageEJP[4];
   };

#endif // INSTALLATION_ECS_AVANCESVIEW_HPP
