#include <gui/installation_mz_config_groupe_screen/Installation_MZ_config_groupeView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_MZ_config_groupeView::Installation_MZ_config_groupeView()
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

//	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_INSTALLATION_CENTRE_DEFAUT).getText());
//	barre_titre.titre(textAreaBuffer_Titre);

	//sParamZxMZtemp[] sConfig_Hydrau_temp.

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_PARAMETRES_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	//Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", (sConfig_Hydrau_temp.u8NumZone == 8) ? 'A' : 'B');
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
	barre_titre.titre(textAreaBuffer_Titre);

	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, textAreaBuffer_Question, 10);
	textArea_question_oui_non.setWildcard(textAreaBuffer_Question);
	textArea_question_oui_non.invalidate();


	// Groupe actif oui_non
	if(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.bGroupeActif == 0)
	{
		toggleButton_oui_oui_non.forceState(false);
		toggleButton_oui_oui_non.setTouchable(true);
		toggleButton_non_oui_non.forceState(true);
		toggleButton_non_oui_non.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non.forceState(true);
		toggleButton_oui_oui_non.setTouchable(false);
		toggleButton_non_oui_non.forceState(false);
		toggleButton_non_oui_non.setTouchable(true);
	}

	// Groupe Chaud actif
	if(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].bModeChaud == 0)
	{
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.setTouchable(true);
	}
	else
	{
		toggleButton_chaud.forceState(true);
		toggleButton_chaud.setTouchable(true);
	}

	// Groupe Froid actif
	if(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].bModeFroid == 0)
	{
		toggleButton_froid.forceState(false);
		toggleButton_froid.setTouchable(true);
	}
	else
	{
		toggleButton_froid.forceState(true);
		toggleButton_froid.setTouchable(true);
	}

	toggleButton_oui_oui_non.invalidate();
	toggleButton_non_oui_non.invalidate();
	toggleButton_chaud.invalidate();
	toggleButton_froid.invalidate();

	affichage_type_emetteur();

//	sConfig_Hydrau_temp.u8NumZone = 8;
//	sParamZxMZtemp
}


void Installation_MZ_config_groupeView::bouton_droite_type_emetteur()
{
	switch(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur)
	{
		case PLANCHER:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = VENTILO;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Ventilo, sizeof(u8Loideau_Ventilo));
			break;
		case VENTILO:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = RADIATEUR;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Radiateur, sizeof(u8Loideau_Radiateur));
			break;
		case RADIATEUR:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = GAINABLE;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Gainable, sizeof(u8Loideau_Gainable));
			break;
		case GAINABLE:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = SOUS_STATION;
			break;
		case SOUS_STATION:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = PLANCHER;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Plancher, sizeof(u8Loideau_Plancher));
			break;
		default:
			break;
	}
	//
	affichage_type_emetteur();
}

void Installation_MZ_config_groupeView::bouton_gauche_type_emetteur()
{
	switch(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur)
	{
		case PLANCHER:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = SOUS_STATION;
			//memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Ventilo, sizeof(u8Loideau_Ventilo));
			break;
		case VENTILO:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = PLANCHER;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Plancher, sizeof(u8Loideau_Plancher));
			break;
		case RADIATEUR:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = VENTILO;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Ventilo, sizeof(u8Loideau_Ventilo));
			break;
		case GAINABLE:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = RADIATEUR;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Radiateur,  sizeof(u8Loideau_Radiateur));
			break;
		case SOUS_STATION:
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur = GAINABLE;
			memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], &u8Loideau_Radiateur, sizeof(u8Loideau_Gainable));
			break;
		default:
			break;
	}
	//
	affichage_type_emetteur();
}

void Installation_MZ_config_groupeView::affichage_type_emetteur()
{
//	//textArea_type_emet_dans_groupe.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
//
	switch(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur)
	{
		case RADIATEUR:
			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
			break;
		case VENTILO:
			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT));
			break;
		case PLANCHER:
			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT));
			break;
		case GAINABLE:
			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_GAINABLE_CENTRE_DEFAUT));
			break;
		case SOUS_STATION:
			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_SOUS_STATION_CENTRE_DEFAUT));
			break;
		default:
			break;
	}
	if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur == SOUS_STATION)
	{
		container_oui_non_activer_mode.setVisible(false);
		buttonWithLabel_courbe_loi_eau.setVisible(false);
		buttonWithLabel_param_comp.setVisible(false);
		buttonWithLabel_gestion_circ.setVisible(true);
		buttonWithLabel_renommer_groupe.setVisible(true);
	}
	else
	{
		container_oui_non_activer_mode.setVisible(true);
		buttonWithLabel_courbe_loi_eau.setVisible(true);
		buttonWithLabel_param_comp.setVisible(true);
		buttonWithLabel_gestion_circ.setVisible(false);
		buttonWithLabel_renommer_groupe.setVisible(false);
	}
	container_oui_non_activer_mode.invalidate();
	textArea_valeur_type_emetteur.invalidate();
	buttonWithLabel_courbe_loi_eau.invalidate();
	buttonWithLabel_param_comp.invalidate();
	buttonWithLabel_gestion_circ.invalidate();
	buttonWithLabel_renommer_groupe.invalidate();
}



void Installation_MZ_config_groupeView::bouton_non()
{
//	sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.bGroupeActif = 0;
//	updatetogglebutton_nonoui();
	if(toggleButton_non_oui_non.getState())
	{
		toggleButton_oui_oui_non.forceState(false);
		toggleButton_oui_oui_non.setTouchable(true);
		toggleButton_oui_oui_non.invalidate();
		toggleButton_non_oui_non.setTouchable(false);
		toggleButton_non_oui_non.invalidate();
	}
}

void Installation_MZ_config_groupeView::bouton_oui()
{
	if(toggleButton_oui_oui_non.getState())
	{
		toggleButton_non_oui_non.forceState(false);
		toggleButton_non_oui_non.setTouchable(true);
		toggleButton_non_oui_non.invalidate();
		toggleButton_oui_oui_non.setTouchable(false);
		toggleButton_oui_oui_non.invalidate();
	}
}

//void Installation_MZ_config_groupeView::bouton_chaud()
//{
////	sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.bGroupeActif = 0;
////	updatetogglebutton_nonoui();
//
//	// init : toggleButton_si_defaut_pac.forceState(true);
////	if(toggleButton_si_defaut_pac.getState())
////		{
////			textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
////		}
////		else textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
////		textArea_on_off_si_defaut_pac.invalidate();
//	if(toggleButton_chaud.getState())
////	{
////		textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
////	}
////	else textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
//	textArea_on_off_si_defaut_pac.invalidate();
//}

void Installation_MZ_config_groupeView::setupScreen()
{
    Installation_MZ_config_groupeViewBase::setupScreen();
}

void Installation_MZ_config_groupeView::tearDownScreen()
{
    Installation_MZ_config_groupeViewBase::tearDownScreen();
}


void Installation_MZ_config_groupeView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_config_groupeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_config_groupeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_config_groupeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_config_groupeView::changeDate(S_DATE *sDate)
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

