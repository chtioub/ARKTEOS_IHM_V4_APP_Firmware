#include <gui/bouclage_ecs_screen/Bouclage_ecsView.hpp>

Bouclage_ecsView::Bouclage_ecsView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	//
	u8Time_Bouclage_ECS = sConfig_IHM.sMode_ECS.u8Time_Bouclage_ECS;
	if(u8Time_Bouclage_ECS != 0)
	{
		Unicode::snprintf(textAreaBuffer_Tps_Bouclage, 6, "%02dh%02d", u8Time_Bouclage_ECS / 60, u8Time_Bouclage_ECS % 60);
	}
	else Unicode::snprintf(textAreaBuffer_Tps_Bouclage, 6, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	textArea_valeur_duree_bouclage_ecs.setWildcard(textAreaBuffer_Tps_Bouclage);
	//
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_BOUCLAGE_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	// Récupération des progs
#ifndef SIMULATOR
	presenter->c_prog_option(false);
#endif
}

void Bouclage_ecsView::setupScreen()
{
    Bouclage_ecsViewBase::setupScreen();
}

void Bouclage_ecsView::tearDownScreen()
{
    Bouclage_ecsViewBase::tearDownScreen();
}

void Bouclage_ecsView::bouton_prog()
{
	// Vers page programmation
	memcpy(u8Prog, au8Prog_Options, sizeof(u8Prog));
	eProg = PRO_OPTION;
	application().gotoProgrammationScreenNoTransition();
}

void Bouclage_ecsView::bouton_valider()
{
	if(sConfig_IHM.sMode_ECS.u8Time_Bouclage_ECS != u8Time_Bouclage_ECS)
	{
		sConfig_IHM.sMode_ECS.u8Time_Bouclage_ECS = u8Time_Bouclage_ECS;
		presenter->c_user_ecs();
	}
	application().gotoEau_chaude_sanitaireScreenNoTransition();
}

void Bouclage_ecsView::bouton_moins_bouclage_ecs()
{
	if(u8Time_Bouclage_ECS != 0)
	{
		u8Time_Bouclage_ECS--;
	}
	else u8Time_Bouclage_ECS = 240;

	if(u8Time_Bouclage_ECS != 0)
	{
		Unicode::snprintf(textAreaBuffer_Tps_Bouclage, 6, "%02dh%02d", u8Time_Bouclage_ECS / 60, u8Time_Bouclage_ECS % 60);
	}
	else Unicode::snprintf(textAreaBuffer_Tps_Bouclage, 6, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	textArea_valeur_duree_bouclage_ecs.setWildcard(textAreaBuffer_Tps_Bouclage);
	textArea_valeur_duree_bouclage_ecs.invalidate();
}

void Bouclage_ecsView::bouton_plus_bouclage_ecs()
{
	if(++u8Time_Bouclage_ECS > 240)
	{
		u8Time_Bouclage_ECS = 0;
	}

	if(u8Time_Bouclage_ECS != 0)
	{
		Unicode::snprintf(textAreaBuffer_Tps_Bouclage, 6, "%02dh%02d", u8Time_Bouclage_ECS / 60, u8Time_Bouclage_ECS % 60);
	}
	else Unicode::snprintf(textAreaBuffer_Tps_Bouclage, 6, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	textArea_valeur_duree_bouclage_ecs.setWildcard(textAreaBuffer_Tps_Bouclage);
	textArea_valeur_duree_bouclage_ecs.invalidate();
}

void Bouclage_ecsView::timer_10ms()
{
	//
	if(button_gauche_duree_bouclage_ecs.getPressedState())
	{
		if(u8PressionLongue_gauche < 15)
		{
			u8PressionLongue_gauche++;
		}
		else bouton_moins_bouclage_ecs();
	}
	else u8PressionLongue_gauche = 0;
	//
	if(button_droite_duree_bouclage_ecs.getPressedState())
	{
		if(u8PressionLongue_droite < 15)
		{
			u8PressionLongue_droite++;
		}
		else bouton_plus_bouclage_ecs();
	}
	else u8PressionLongue_droite = 0;
}

void Bouclage_ecsView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Bouclage_ecsView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Bouclage_ecsView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Bouclage_ecsView::changeDate(S_DATE *sDate)
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
