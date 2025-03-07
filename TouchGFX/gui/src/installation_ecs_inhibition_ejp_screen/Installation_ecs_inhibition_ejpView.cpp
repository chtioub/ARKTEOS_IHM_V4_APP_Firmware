#include <gui/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecs_inhibition_ejpView::Installation_ecs_inhibition_ejpView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);

	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PUISSANCE_APPOINT_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

//	u6PW_Brin = sParam_ECS_temp.u6PW_Brin; //Valeur de puissance / 100
//	update_PW_appoint();
	bCouplageEJP = sParam_ECS_temp.bCouplageEJP;

	//ECS Oui/Non
    if(bCouplageEJP == 0)
	{
    	toggleButton_oui_oui_non_inhibition_ejp_ecs.forceState(false);
    	toggleButton_oui_oui_non_inhibition_ejp_ecs.setTouchable(true);
    	toggleButton_non_oui_non_inhibition_ejp_ecs.forceState(true);
    	toggleButton_non_oui_non_inhibition_ejp_ecs.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_inhibition_ejp_ecs.forceState(true);
		toggleButton_oui_oui_non_inhibition_ejp_ecs.setTouchable(false);
		toggleButton_non_oui_non_inhibition_ejp_ecs.forceState(false);
		toggleButton_non_oui_non_inhibition_ejp_ecs.setTouchable(true);
	}
    toggleButton_oui_oui_non_inhibition_ejp_ecs.invalidate();
    toggleButton_non_oui_non_inhibition_ejp_ecs.invalidate();
}


void Installation_ecs_inhibition_ejpView::bouton_oui()
{
	if(toggleButton_oui_oui_non_inhibition_ejp_ecs.getState())
	{
		toggleButton_non_oui_non_inhibition_ejp_ecs.forceState(false);
		toggleButton_non_oui_non_inhibition_ejp_ecs.setTouchable(true);
		toggleButton_non_oui_non_inhibition_ejp_ecs.invalidate();
		toggleButton_oui_oui_non_inhibition_ejp_ecs.setTouchable(false);
		toggleButton_oui_oui_non_inhibition_ejp_ecs.invalidate();
	}
	bCouplageEJP = 1;
}

void Installation_ecs_inhibition_ejpView::bouton_non()
{
	if(toggleButton_non_oui_non_inhibition_ejp_ecs.getState())
	{
		toggleButton_oui_oui_non_inhibition_ejp_ecs.forceState(false);
		toggleButton_oui_oui_non_inhibition_ejp_ecs.setTouchable(true);
		toggleButton_oui_oui_non_inhibition_ejp_ecs.invalidate();
		toggleButton_non_oui_non_inhibition_ejp_ecs.setTouchable(false);
		toggleButton_non_oui_non_inhibition_ejp_ecs.invalidate();
	}
	bCouplageEJP = 0;
}

void Installation_ecs_inhibition_ejpView::bouton_valider()
{
	sParam_ECS_temp.bCouplageEJP = bCouplageEJP & 1;
	sConfig_IHM.sParam_ECS.bCouplageEJP = bCouplageEJP & 1;
	presenter->c_install_ecs();
}

void Installation_ecs_inhibition_ejpView::setupScreen()
{
    Installation_ecs_inhibition_ejpViewBase::setupScreen();
}

void Installation_ecs_inhibition_ejpView::tearDownScreen()
{
    Installation_ecs_inhibition_ejpViewBase::tearDownScreen();
}


void Installation_ecs_inhibition_ejpView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_inhibition_ejpView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_inhibition_ejpView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_inhibition_ejpView::changeDate(S_DATE *sDate)
{
	if(sDate_old.Date != sDate->Date)
	{
		// Affichage de la date
	    Unicode::snprintf(textAreaBuffer_Date, 9, "%02d/%02d/%02d", sDate->Date, sDate->Month, sDate->Year);
	    barre_titre.date(textAreaBuffer_Date);
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
	else if(sDate_old.Minutes != sDate->Minutes)
	{
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
    barre_titre.invalidate();
	memcpy(&sDate_old, sDate, sizeof(S_DATE));
}


