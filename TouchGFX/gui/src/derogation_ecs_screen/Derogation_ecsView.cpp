#include <gui/derogation_ecs_screen/Derogation_ecsView.hpp>

Derogation_ecsView::Derogation_ecsView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	changeConfig(&sConfig_IHM);
	// Statut initial du bouton derogation
	if(sConfig_IHM.sMode_ECS.Exception == S_SABLIER)
	{
		toggleButton_non_oui_non_derog_ecs.forceState(false);
		toggleButton_non_oui_non_derog_ecs.setTouchable(true);
		toggleButton_oui_oui_non_derog_ecs.forceState(true);
		toggleButton_oui_oui_non_derog_ecs.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_derog_ecs.forceState(false);
		toggleButton_oui_oui_non_derog_ecs.setTouchable(true);
		toggleButton_non_oui_non_derog_ecs.forceState(true);
		toggleButton_non_oui_non_derog_ecs.setTouchable(false);
	}
	// Statut initial du bouton legionel
	if(sConfig_IHM.sMode_ECS.bUserLegionnel == true)
	{
		toggleButton_non_oui_non_legionel.forceState(false);
		toggleButton_non_oui_non_legionel.setTouchable(true);
		toggleButton_oui_oui_non_legionel.forceState(true);
		toggleButton_oui_oui_non_legionel.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_legionel.forceState(false);
		toggleButton_oui_oui_non_legionel.setTouchable(true);
		toggleButton_non_oui_non_legionel.forceState(true);
		toggleButton_non_oui_non_legionel.setTouchable(false);
	}
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_ECS_DEROG_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void Derogation_ecsView::setupScreen()
{
    Derogation_ecsViewBase::setupScreen();
}

void Derogation_ecsView::tearDownScreen()
{
    Derogation_ecsViewBase::tearDownScreen();
}

void Derogation_ecsView::bouton_legionel_non()
{
	if(toggleButton_non_oui_non_legionel.getState())
	{
		toggleButton_oui_oui_non_legionel.forceState(false);
		toggleButton_oui_oui_non_legionel.setTouchable(true);
		toggleButton_oui_oui_non_legionel.invalidate();
		toggleButton_non_oui_non_legionel.setTouchable(false);
		toggleButton_non_oui_non_legionel.invalidate();
	}
}

void Derogation_ecsView::bouton_legionel_oui()
{
	if(toggleButton_oui_oui_non_legionel.getState())
	{
		toggleButton_non_oui_non_legionel.forceState(false);
		toggleButton_non_oui_non_legionel.setTouchable(true);
		toggleButton_non_oui_non_legionel.invalidate();
		toggleButton_oui_oui_non_legionel.setTouchable(false);
		toggleButton_oui_oui_non_legionel.invalidate();
	}
}

void Derogation_ecsView::bouton_non_derog_ecs()
{
	if(toggleButton_non_oui_non_derog_ecs.getState())
	{
		toggleButton_oui_oui_non_derog_ecs.forceState(false);
		toggleButton_oui_oui_non_derog_ecs.setTouchable(true);
		toggleButton_oui_oui_non_derog_ecs.invalidate();
		toggleButton_non_oui_non_derog_ecs.setTouchable(false);
		toggleButton_non_oui_non_derog_ecs.invalidate();
	}
}

void Derogation_ecsView::bouton_oui_derog_ecs()
{
	if(toggleButton_oui_oui_non_derog_ecs.getState())
	{
		toggleButton_non_oui_non_derog_ecs.forceState(false);
		toggleButton_non_oui_non_derog_ecs.setTouchable(true);
		toggleButton_non_oui_non_derog_ecs.invalidate();
		toggleButton_oui_oui_non_derog_ecs.setTouchable(false);
		toggleButton_oui_oui_non_derog_ecs.invalidate();
	}
}

void Derogation_ecsView::bouton_valider()
{
	if(sConfig_IHM.sMode_ECS.Exception != (toggleButton_oui_oui_non_derog_ecs.getState() * 2) || sConfig_IHM.sMode_ECS.bUserLegionnel != toggleButton_oui_oui_non_legionel.getState())
	{
		sConfig_IHM.sMode_ECS.Exception = (toggleButton_oui_oui_non_derog_ecs.getState() * 2);
		sConfig_IHM.sMode_ECS.bUserLegionnel = toggleButton_oui_oui_non_legionel.getState();
		presenter->c_user_ecs();
	}
	// Retour page ECS
	application().gotoEau_chaude_sanitaireScreenNoTransition();
}

void Derogation_ecsView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	// Affichage ou non de l'antilegionel
	if(sConfig_IHM->sParam_ECS.bAntiLegionnel != sConfig_IHM_old.sParam_ECS.bAntiLegionnel)
	{
		if(sConfig_IHM->sParam_ECS.bAntiLegionnel == true)
		{
			container_oui_non_legionnel.setVisible(true);
		}
		else container_oui_non_legionnel.setVisible(false);
		container_oui_non_legionnel.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void Derogation_ecsView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Derogation_ecsView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Derogation_ecsView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Derogation_ecsView::changeDate(S_DATE *sDate)
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
