#ifndef INSTALLATION_ECS_SOLAIREVIEW_HPP
#define INSTALLATION_ECS_SOLAIREVIEW_HPP

#include <gui_generated/installation_ecs_solaire_screen/Installation_ecs_solaireViewBase.hpp>
#include <gui/installation_ecs_solaire_screen/Installation_ecs_solairePresenter.hpp>

class Installation_ecs_solaireView : public Installation_ecs_solaireViewBase
{
public:
    Installation_ecs_solaireView();
    virtual ~Installation_ecs_solaireView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_oui_solaire();
	void bouton_non_solaire();
	void bouton_gauche_contact();
	void bouton_droite_contact();
	void update_contact();
	void bouton_valider();

	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	unsigned char bSolaire, bContact;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Contact[7];
   };

#endif // INSTALLATION_ECS_SOLAIREVIEW_HPP
