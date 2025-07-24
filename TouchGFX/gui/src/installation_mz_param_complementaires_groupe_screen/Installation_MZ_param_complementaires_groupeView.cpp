#include <gui/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupeView.hpp>

Installation_MZ_param_complementaires_groupeView::Installation_MZ_param_complementaires_groupeView()
{
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

	Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_PARAM_COMPLEMENTAIRE_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
	//Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", (sConfig_Hydrau_temp.u8NumZone == 8) ? 'A' : 'B');
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
	barre_titre.titre(textAreaBuffer_Titre);

	if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur == GAINABLE)
	{
		u7VitesseVentilateur = sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.u7VitesseMaxVentilateur;
		vitesseVentilateur();
		// Marche forcée
		if(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.bFanForce == 0)
		{
			toggleButton_oui_oui_non_marche_forcee.forceState(false);
			toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
			toggleButton_non_oui_non_marche_forcee.forceState(true);
			toggleButton_non_oui_non_marche_forcee.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_marche_forcee.forceState(true);
			toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
			toggleButton_non_oui_non_marche_forcee.forceState(false);
			toggleButton_non_oui_non_marche_forcee.setTouchable(true);
		}
		container_oui_non_ventil_forcee.setVisible(true);
		container_vitesse_max_ventil.setVisible(true);
	}
	else
	{
		container_oui_non_ventil_forcee.setVisible(false);
		container_vitesse_max_ventil.setVisible(false);
	}
	container_oui_non_ventil_forcee.invalidate();
	container_vitesse_max_ventil.invalidate();
}

void Installation_MZ_param_complementaires_groupeView::vitesseVentilateur()
{
    // MAJ de la valeur
     Unicode::snprintf(textAreaBuffer_Vitesse_Ventil, 5, "%d", u7VitesseVentilateur);
     textArea_valeur_vitesse_ventilateur.setWildcard(textAreaBuffer_Vitesse_Ventil);
     textArea_valeur_vitesse_ventilateur.invalidate();

     if (u7VitesseVentilateur > 70)
     {
		 textArea_vitesse_ventilateur.setTypedText(touchgfx::TypedText(T_TEXT_VITESSE_MAX_VENTILATEUR_ATTENTION));
     }
     else
     {
    	 textArea_vitesse_ventilateur.setTypedText(touchgfx::TypedText(T_TEXT_VITESSE_MAX_VENTILATEUR));
     }
     textArea_vitesse_ventilateur.invalidate();
}

void Installation_MZ_param_complementaires_groupeView::bouton_vitesse_gauche()
{
	if(u7VitesseVentilateur > 0)
	{
		u7VitesseVentilateur--;
	}
	vitesseVentilateur();
}

void Installation_MZ_param_complementaires_groupeView::bouton_vitesse_droite()
{
	if(u7VitesseVentilateur < 100)
	{
		u7VitesseVentilateur++;
	}
	vitesseVentilateur();
}

void Installation_MZ_param_complementaires_groupeView::bouton_non_marche_forcee()
{
	if(toggleButton_non_oui_non_marche_forcee.getState())
	{
		toggleButton_oui_oui_non_marche_forcee.forceState(false);
		toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
		toggleButton_oui_oui_non_marche_forcee.invalidate();
		toggleButton_non_oui_non_marche_forcee.setTouchable(false);
		toggleButton_non_oui_non_marche_forcee.invalidate();
	}
}

void Installation_MZ_param_complementaires_groupeView::bouton_oui_marche_forcee()
{
	if(toggleButton_oui_oui_non_marche_forcee.getState())
	{
		toggleButton_non_oui_non_marche_forcee.forceState(false);
		toggleButton_non_oui_non_marche_forcee.setTouchable(true);
		toggleButton_non_oui_non_marche_forcee.invalidate();
		toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
		toggleButton_oui_oui_non_marche_forcee.invalidate();
	}
}

void Installation_MZ_param_complementaires_groupeView::bouton_hysteresis()
{
	//u7VitesseVentilateur = sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.u7VitesseMaxVentilateur;
//	if(toggleButton_oui_oui_non_marche_forcee.getState())
//	{
//		toggleButton_non_oui_non_marche_forcee.forceState(false);
//		toggleButton_non_oui_non_marche_forcee.setTouchable(true);
//		toggleButton_non_oui_non_marche_forcee.invalidate();
//		toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
//		toggleButton_oui_oui_non_marche_forcee.invalidate();
//	}
	eHysteresis = HYST_TEAU;
}

void Installation_MZ_param_complementaires_groupeView:: renommer_groupe()
{
	eTypeClavierAlpha = RENOMMER_ZONE_GROUPE;
}


void Installation_MZ_param_complementaires_groupeView::bouton_valider()
{
	if(toggleButton_oui_oui_non_marche_forcee.getState())
	{
		sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.bFanForce = 1;
	}
	else sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.bFanForce = 0;
	sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.u7VitesseMaxVentilateur = u7VitesseVentilateur;
}

void Installation_MZ_param_complementaires_groupeView::setupScreen()
{
    Installation_MZ_param_complementaires_groupeViewBase::setupScreen();
}

void Installation_MZ_param_complementaires_groupeView::tearDownScreen()
{
    Installation_MZ_param_complementaires_groupeViewBase::tearDownScreen();
}


void Installation_MZ_param_complementaires_groupeView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_param_complementaires_groupeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_param_complementaires_groupeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_complementaires_groupeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_complementaires_groupeView::changeDate(S_DATE *sDate)
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
