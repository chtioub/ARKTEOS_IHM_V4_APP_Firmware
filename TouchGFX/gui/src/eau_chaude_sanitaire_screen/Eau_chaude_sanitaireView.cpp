#include <gui/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Eau_chaude_sanitaireView::Eau_chaude_sanitaireView()
{
	uint8_t u8Prog_empty[7][24];
	memset(u8Prog_empty, 0, sizeof(u8Prog_empty));
	// Init des variables
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	//
	if(memcmp(au8Prog_Options, u8Prog_empty, sizeof(au8Prog_Options)))
	{
		button_bouclage_ecs_on.setVisible(true);
	}
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_ACCUEIL_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	// Récupération des progs
#ifndef SIMULATOR
	presenter->c_prog_ecs(false);
//	presenter->c_prog_option(false);
#endif
}

void Eau_chaude_sanitaireView::setupScreen()
{
    Eau_chaude_sanitaireViewBase::setupScreen();
}

void Eau_chaude_sanitaireView::tearDownScreen()
{
	// En cas de changement de page on vérifie si les consignes ont été changées
	if(sConfig_IHM.sMode_ECS.i16Consigne_ECS_Normal != u16Consigne || sConfig_IHM.sMode_ECS.i16Consigne_ECS_Relance != u16Relance)
	{
		sConfig_IHM.sMode_ECS.i16Consigne_ECS_Normal = u16Consigne;
		sConfig_IHM.sMode_ECS.i16Consigne_ECS_Relance = u16Relance;
		presenter->c_user_ecs();
	}

    Eau_chaude_sanitaireViewBase::tearDownScreen();
}

void Eau_chaude_sanitaireView::slider_consigne(int sliderValue)
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	if(sliderValue < (u16Relance + 50))
	{
		u16Consigne = u16Relance + 50;
		slider_rose.setValue((int) u16Consigne);
		sliderValue = u16Consigne;
	}
	else u16Consigne = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", ((float) u16Consigne) / 10.0);
    textArea_rose.setWildcard(textAreaBuffer_consigne);
    textArea_rose.moveTo((int)((float) slider_rose.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_rose.getWidth()/2  + ((float)sliderValue - (float)400) * (float)1.98),51);
    textArea_rose.invalidate();
}

void Eau_chaude_sanitaireView::slider_relance(int sliderValue)
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	if(sliderValue > (u16Consigne - 50))
	{
		u16Relance = u16Consigne - 50;
		slider_gris.setValue((int) u16Relance);
		sliderValue = u16Relance;
	}
	else u16Relance = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_relance, 5, "%.1f", ((float) u16Relance) / 10.0);
    textArea_gris.setWildcard(textAreaBuffer_relance);
    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)sliderValue - (float)400) * (float)1.98),51);
    textArea_gris.invalidate();
}

void Eau_chaude_sanitaireView::bouton_plus_relance()
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16Relance == (u16Consigne - 50)) return;

	u16Relance += 1;
	if(u16Relance > (u16Consigne - 50))
	{
		u16Relance = u16Consigne - 50;
	}
	slider_gris.setValue((int)u16Relance);
    Unicode::snprintfFloat(textAreaBuffer_relance, 5, "%.1f", ((float) u16Relance) / 10.0);
    textArea_gris.setWildcard(textAreaBuffer_relance);
    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)u16Relance - (float)400) * (float)1.98),51);
    textArea_gris.invalidate();
}

void Eau_chaude_sanitaireView::bouton_moins_relance()
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16Relance == 400) return;

	u16Relance -= 1;
	if(u16Relance < 400)
	{
		u16Relance = 400;
	}
	slider_gris.setValue((int)u16Relance);
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", ((float) u16Relance) / 10.0);
    textArea_gris.setWildcard(textAreaBuffer_relance);
    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)u16Relance - (float)400) * (float)1.98),51);
    textArea_gris.invalidate();
}

void Eau_chaude_sanitaireView::bouton_plus_consigne()
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16Consigne == 650) return;

	u16Consigne += 1;
	if(u16Consigne > 650)
	{
		u16Consigne = 650;
	}
	//
	slider_rose.setValue(u16Consigne);
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", ((float) u16Consigne) / 10.0);
    textArea_rose.setWildcard(textAreaBuffer_consigne);
    textArea_rose.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)u16Consigne - (float)400) * (float)1.98),51);
    textArea_rose.invalidate();
}

void Eau_chaude_sanitaireView::bouton_moins_consigne()
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16Consigne == (u16Relance + 50)) return;

	u16Consigne -= 1;
	if(u16Consigne < (u16Relance + 50))
	{
		u16Consigne = u16Relance + 50;
	}
	slider_rose.setValue((int)u16Consigne);
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", ((float) u16Consigne) / 10.0);
    textArea_rose.setWildcard(textAreaBuffer_consigne);
    textArea_rose.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)u16Consigne - (float)400) * (float)1.98),51);
    textArea_rose.invalidate();
}

void Eau_chaude_sanitaireView::bouton_appoint()
{
	sConfig_IHM.sMode_ECS.bUserAppointECS = toggleButton_appoint_ecs.getState();
	presenter->c_user_ecs();
}

void Eau_chaude_sanitaireView::bouton_arret()
{
	if(toggleButton_arret_ecs.getState())
	{
		button_marche_ecs_on.setVisible(false);
		button_marche_ecs_on.invalidate();
		toggleButton_arret_ecs.forceState(true);
		toggleButton_arret_ecs.setTouchable(false);
		toggleButton_arret_ecs.invalidate();
	}
	//
	if(sConfig_IHM.sMode_ECS.Mode != ARRET)
	{
		sConfig_IHM.sMode_ECS.Mode = ARRET;
		presenter->c_user_ecs();
	}
}

void Eau_chaude_sanitaireView::bouton_marche_ecs()
{
	if(sConfig_IHM.sMode_ECS.Mode != AUTO_CHAUD)
	{
		sConfig_IHM.sMode_ECS.Mode = AUTO_CHAUD;
		presenter->c_user_ecs();
	}
	// Vers page programmation
	memcpy(u8Prog, au8Prog_ECS, sizeof(u8Prog));
	eProg = PRO_ECS;
	application().gotoProgrammationScreenNoTransition();
}

void Eau_chaude_sanitaireView::timer_100ms()
{
	if(u16TempoEnvoiConsigne)
	{
		u16TempoEnvoiConsigne--;
		if(u16TempoEnvoiConsigne == 0)
		{
			if(sConfig_IHM.sMode_ECS.i16Consigne_ECS_Normal != u16Consigne || sConfig_IHM.sMode_ECS.i16Consigne_ECS_Relance != u16Relance)
			{
				sConfig_IHM.sMode_ECS.i16Consigne_ECS_Normal = u16Consigne;
				sConfig_IHM.sMode_ECS.i16Consigne_ECS_Relance = u16Relance;
				presenter->c_user_ecs();
			}
		}
	}
}

void Eau_chaude_sanitaireView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	if(sConfig_IHM_old.sMode_ECS.Mode != sConfig_IHM->sMode_ECS.Mode)
	{
		if(sConfig_IHM->sMode_ECS.Mode == AUTO_CHAUD)
		{
			button_marche_ecs_on.setVisible(true);
			toggleButton_arret_ecs.forceState(false);
			toggleButton_arret_ecs.setTouchable(true);
		}
		else
		{
			button_marche_ecs_on.setVisible(false);
			toggleButton_arret_ecs.forceState(true);
			toggleButton_arret_ecs.setTouchable(false);
		}
		button_marche_ecs_on.invalidate();
		toggleButton_arret_ecs.invalidate();
	}

	if(sConfig_IHM_old.sMode_ECS.bUserAppointECS != sConfig_IHM->sMode_ECS.bUserAppointECS)
	{
		if(sConfig_IHM->sMode_ECS.bUserAppointECS == 1)
		{
			toggleButton_appoint_ecs.forceState(true);
		}
		else toggleButton_appoint_ecs.forceState(false);
		toggleButton_appoint_ecs.invalidate();
	}

	if(sConfig_IHM_old.sMode_ECS.Exception != sConfig_IHM->sMode_ECS.Exception)
	{
		if(sConfig_IHM->sMode_ECS.Exception == S_SABLIER)
		{
			button_derog_ecs_on.setVisible(true);
		}
		else button_derog_ecs_on.setVisible(false);
		button_derog_ecs_on.invalidate();
	}

	if(sConfig_IHM_old.sMode_ECS.i16Consigne_ECS_Normal != sConfig_IHM->sMode_ECS.i16Consigne_ECS_Normal || sConfig_IHM_old.sMode_ECS.i16Consigne_ECS_Relance != sConfig_IHM->sMode_ECS.i16Consigne_ECS_Relance)
	{
		u16Consigne = sConfig_IHM->sMode_ECS.i16Consigne_ECS_Normal;
		u16Relance = sConfig_IHM->sMode_ECS.i16Consigne_ECS_Relance;
		//
		slider_rose.setValue((int) u16Consigne);
	    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", ((float) u16Consigne) / 10.0);
	    textArea_rose.setWildcard(textAreaBuffer_consigne);
	    textArea_rose.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)u16Consigne - (float)400) * (float)1.98),51);
	    textArea_rose.invalidate();
		//
		slider_gris.setValue((int) u16Relance);
	    Unicode::snprintfFloat(textAreaBuffer_relance, 5, "%.1f", ((float) u16Relance) / 10.0);
	    textArea_gris.setWildcard(textAreaBuffer_relance);
	    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)u16Relance - (float)400) * (float)1.98),51);
	    textArea_gris.invalidate();
	}

	if(sConfig_IHM_old.sParam_ECS.bBouclageECS != sConfig_IHM->sParam_ECS.bBouclageECS)
	{
		if(sConfig_IHM->sParam_ECS.bBouclageECS != 0)
		{
			container_bouclage_ecs.setVisible(true);
		}
		else container_bouclage_ecs.setVisible(false);
		container_bouclage_ecs.invalidate();
	}

	if(sConfig_IHM_old.sMode_ECS.u8Time_Bouclage_ECS != sConfig_IHM->sMode_ECS.u8Time_Bouclage_ECS)
	{
		if(sConfig_IHM->sMode_ECS.u8Time_Bouclage_ECS != 0)
		{
			button_bouclage_ecs_on.setVisible(true);
		}
		else button_bouclage_ecs_on.setVisible(false);
		button_bouclage_ecs_on.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void Eau_chaude_sanitaireView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Eau_chaude_sanitaireView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Eau_chaude_sanitaireView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Eau_chaude_sanitaireView::changeDate(S_DATE *sDate)
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
