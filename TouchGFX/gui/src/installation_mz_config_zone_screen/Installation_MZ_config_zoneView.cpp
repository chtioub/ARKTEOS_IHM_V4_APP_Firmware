#include <gui/installation_mz_config_zone_screen/Installation_MZ_config_zoneView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_MZ_config_zoneView::Installation_MZ_config_zoneView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));//De CPA
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	memset(&sStatut_RF_old, 0, sizeof(sStatut_RF_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;

	//A garder avant tous les "change....."
	u8NumZone = sConfig_Hydrau_temp.u8NumZone;

	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutRF(&sStatut_RF[0]);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeConfig(&sConfig_IHM);

	container.setXY(u8PositionX, u8PositionY);
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);

	bZoneActive = false;
//	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
//	barre_titre.titre(textAreaBuffer_Titre);

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_PARAMETRES_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sParamZxMZtemp[u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", u8NumZone + 1);
	barre_titre.titre(textAreaBuffer_Titre);

	Unicode::snprintf(textAreaBuffer_MessTitre, 40, touchgfx::TypedText(T_TEXT_MESSAGE_INFORMATION_TITRE).getText());
	message_information.titre(textAreaBuffer_MessTitre);
	modalWindow_information.hide();
	modalWindow_information.invalidate();

	TypeEmetteur = sParamZxMZtemp[u8NumZone].TypeEmmetteur;
	TypeThermostat = sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat;
	i8PertesDeCharges = sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges;
	VolumePiece = sParamZxMZtemp[u8NumZone].u7VolumePiece * 5;
	bActivationCorrection = sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bActivationCorrection;
	bModeChaud = sParamZxMZtemp[u8NumZone].bModeChaud;
	bModeFroid = sParamZxMZtemp[u8NumZone].bModeFroid;
	memcpy(&u8NomZone, &sParamZxMZtemp[u8NumZone].u8NomZone, sizeof(sParamZxMZtemp[u8NumZone].u8NomZone));

	ViewHideButtonContainer();
	InitContainer();
}

void Installation_MZ_config_zoneView::ViewHideButtonContainer()
{
	bool bRattachement = false;
	//Si rattaché à un groupe du type gainable
	if ((sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_A && sParamZxMZtemp[8].TypeEmmetteur == GAINABLE)
			|| (sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_B && sParamZxMZtemp[9].TypeEmmetteur == GAINABLE))
	{
		bRattachement = true;
		TypeEmetteur = GAINABLE;
	}
	else if ((sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_A && sParamZxMZtemp[8].TypeEmmetteur == PLANCHER)
			|| (sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_B && sParamZxMZtemp[9].TypeEmmetteur == PLANCHER))
	{
		bRattachement = true;
		TypeEmetteur = PLANCHER;
	}
	else if ((sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_A && sParamZxMZtemp[8].TypeEmmetteur == VENTILO)
			|| (sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_B && sParamZxMZtemp[9].TypeEmmetteur == VENTILO))
	{
		bRattachement = true;
		TypeEmetteur = VENTILO;
	}
	else if((sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_A && sParamZxMZtemp[8].TypeEmmetteur == RADIATEUR)
			|| (sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_B && sParamZxMZtemp[9].TypeEmmetteur == RADIATEUR))
	{
		bRattachement = true;
		TypeEmetteur = RADIATEUR;
	}

	if (bRattachement)
	{
		button_gauche_type_emetteur.setVisible(false);
		button_droite_type_emetteur.setVisible(false);
		container_oui_non_activer_zone.setY(532);
		buttonWithLabel_gestion_circulateur.setVisible(true);
		buttonWithLabel_courbe_loi_eau.setVisible(false);
		container_oui_non_activer_mode.setY(304);
		buttonWithLabel_renommer.setY(456);

		if (TypeEmetteur == GAINABLE)
		{
			buttonWithLabel_gestion_registre.setVisible(true);
			container_volume_zone.setVisible(true);
			container_correction_debit_air.setVisible(true);
			container_pertes_charges_gaines.setVisible(true);
			buttonWithLabel_gestion_circulateur.setVisible(false);
		}
	}
	else
	{
		//Zone autonome
		if (sParamZxMZtemp[u8NumZone].u2RattachementGroupe == AUTONOME )
		{
			button_gauche_type_emetteur.setVisible(true);
			button_droite_type_emetteur.setVisible(true);
			buttonWithLabel_courbe_loi_eau.setVisible(true);
			container_oui_non_activer_mode.setY(228);
			buttonWithLabel_renommer.setY(380);
		}
		else//Rattaché à un groupe mais autre que Gainable
		{
			button_gauche_type_emetteur.setVisible(false);
			button_droite_type_emetteur.setVisible(false);
			buttonWithLabel_courbe_loi_eau.setVisible(false);
			container_oui_non_activer_mode.setY(152);
			buttonWithLabel_renommer.setY(304);
		}
		container_oui_non_activer_zone.setY(456);
		buttonWithLabel_gestion_registre.setVisible(false);
		buttonWithLabel_gestion_circulateur.setVisible(true);
		container_volume_zone.setVisible(false);
		container_correction_debit_air.setVisible(false);
		container_pertes_charges_gaines.setVisible(false);
	}
	container_oui_non_activer_zone.invalidate();
	buttonWithLabel_gestion_registre.invalidate();
	buttonWithLabel_gestion_circulateur.invalidate();
	buttonWithLabel_courbe_loi_eau.invalidate();
	container_oui_non_activer_mode.invalidate();
	container_volume_zone.invalidate();
	container_correction_debit_air.invalidate();
	buttonWithLabel_renommer.invalidate();
	container_pertes_charges_gaines.invalidate();
	scrollableContainer.invalidate();

	button_gauche_type_emetteur.invalidate();
	button_droite_type_emetteur.invalidate();
}

void Installation_MZ_config_zoneView::InitContainer()
{
	MAJBoutonActiverZone();
	MAJBoutonActiverChaud();
	MAJBoutonActiverFroid();
	MAJEmetteur();
	MAJTypeSonde();
	MAJPertesDeCharges();
	MAJVolumePiece();
	MAJActivationCorrectionDebitAir();
}

void Installation_MZ_config_zoneView::MAJBoutonActiverZone()
{
	if (u8NumZone == 0 && sConfig_Hydrau_temp.sZones.zone.bZone1) 		bZoneActive = true;
	else if (u8NumZone == 0 && !sConfig_Hydrau_temp.sZones.zone.bZone1) 	bZoneActive = false;
	else if (u8NumZone == 1 && sConfig_Hydrau_temp.sZones.zone.bZone2) 	bZoneActive = true;
	else if (u8NumZone == 1 && !sConfig_Hydrau_temp.sZones.zone.bZone2) 	bZoneActive = false;
	else if (u8NumZone == 2 && sConfig_Hydrau_temp.sZones.zone.bZone3) 	bZoneActive = true;
	else if (u8NumZone == 2 && !sConfig_Hydrau_temp.sZones.zone.bZone3) 	bZoneActive = false;
	else if (u8NumZone == 3 && sConfig_Hydrau_temp.sZones.zone.bZone4) 	bZoneActive = true;
	else if (u8NumZone == 3 && !sConfig_Hydrau_temp.sZones.zone.bZone4) 	bZoneActive = false;
	else if (u8NumZone == 4 && sConfig_Hydrau_temp.sZones.zone.bZone5) 	bZoneActive = true;
	else if (u8NumZone == 4 && !sConfig_Hydrau_temp.sZones.zone.bZone5) 	bZoneActive = false;
	else if (u8NumZone == 5 && sConfig_Hydrau_temp.sZones.zone.bZone6) 	bZoneActive = true;
	else if (u8NumZone == 5 && !sConfig_Hydrau_temp.sZones.zone.bZone6) 	bZoneActive = false;
	else if (u8NumZone == 6 && sConfig_Hydrau_temp.sZones.zone.bZone7) 	bZoneActive = true;
	else if (u8NumZone == 6 && !sConfig_Hydrau_temp.sZones.zone.bZone7) 	bZoneActive = false;
	else if (u8NumZone == 7 && sConfig_Hydrau_temp.sZones.zone.bZone8) 	bZoneActive = true;
	else if (u8NumZone == 7 && !sConfig_Hydrau_temp.sZones.zone.bZone8) 	bZoneActive = false;

	if (bZoneActive)
	{
		toggleButton_oui_activer_zone.forceState(true);
		toggleButton_oui_activer_zone.setTouchable(false);
		toggleButton_non_activer_zone.forceState(false);
		toggleButton_non_activer_zone.setTouchable(true);
	}
	else
	{
		toggleButton_oui_activer_zone.forceState(false);
		toggleButton_oui_activer_zone.setTouchable(true);
		toggleButton_non_activer_zone.forceState(true);
		toggleButton_non_activer_zone.setTouchable(false);
	}
	container_oui_non_activer_zone.invalidate();
}

void Installation_MZ_config_zoneView::MAJBoutonActiverChaud()
{
	if (sParamZxMZtemp[u8NumZone].bModeChaud == 1)
	{
		toggleButton_chaud.forceState(true);
		toggleButton_chaud.setTouchable(true);
	}
	else
	{
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.setTouchable(true);
	}
	toggleButton_chaud.invalidate();
	//sParamZxMZtemp[u8NumZone].bModeChaud = bModeChaud;
}

void Installation_MZ_config_zoneView::MAJBoutonActiverFroid()
{
	if (sParamZxMZtemp[u8NumZone].bModeFroid == 1)
	{
		toggleButton_froid.forceState(true);
		toggleButton_froid.setTouchable(true);
	}
	else
	{
		toggleButton_froid.forceState(false);
		toggleButton_froid.setTouchable(true);
	}
	toggleButton_froid.invalidate();
	//sParamZxMZtemp[u8NumZone].bModeFroid = bModeFroid;
}

void Installation_MZ_config_zoneView::bouton_non()
{
	//sConfig_Hydrau_temp.sZones.zone.bZone1 = 0;
	bZoneActive = false;
	if(toggleButton_non_activer_zone.getState())
	{
		toggleButton_oui_activer_zone.forceState(false);
		toggleButton_oui_activer_zone.setTouchable(true);
		toggleButton_oui_activer_zone.invalidate();
		toggleButton_non_activer_zone.setTouchable(false);
		toggleButton_non_activer_zone.invalidate();
	}
	record_zone_active_oui_non();
}

void Installation_MZ_config_zoneView::bouton_oui()
{
	//sConfig_Hydrau_temp.sZones.zone.bZone1 = 1;
	bZoneActive = true;
	if(toggleButton_oui_activer_zone.getState())
	{
		toggleButton_non_activer_zone.forceState(false);
		toggleButton_non_activer_zone.setTouchable(true);
		toggleButton_non_activer_zone.invalidate();
		toggleButton_oui_activer_zone.setTouchable(false);
		toggleButton_oui_activer_zone.invalidate();
	}
	record_zone_active_oui_non();
}

void Installation_MZ_config_zoneView::record_zone_active_oui_non()
{
	switch (u8NumZone)
	{
		case 0:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone1 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone1 = 0;
			break;
		case 1:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone2 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone2 = 0;
			break;
		case 2:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone3 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone3 = 0;
			break;
		case 3:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone4 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone4 = 0;
			break;
		case 4:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone5 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone5 = 0;
			break;
		case 5:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone6 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone6 = 0;
			break;
		case 6:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone7 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone7 = 0;
			break;
		case 7:
			if (bZoneActive == true)	sConfig_Hydrau_temp.sZones.zone.bZone8 = 1;
			else sConfig_Hydrau_temp.sZones.zone.bZone8 = 0;
			break;
		default:
			break;
	}
}

void Installation_MZ_config_zoneView::bouton_froid()
{
	if(TypeEmetteur == RADIATEUR || sConfig_IHM.sModele_PAC.bReversible == false ||
			(sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_A && sParamZxMZtemp[8].bModeFroid == 0 ) ||
			(sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_B && sParamZxMZtemp[9].bModeFroid == 0 ) )
	{
		sParamZxMZtemp[u8NumZone].bModeFroid = 0;
		MAJBoutonActiverFroid();
		affichage_froid_non_autorise();
	}
	else
	{
		if (sParamZxMZtemp[u8NumZone].u2RattachementGroupe == AUTONOME )
		{
			application().gotoInstallation_MZ_param_complementaires_froidScreenNoTransition();
		}
		else
		{
			if (sParamZxMZtemp[u8NumZone].bModeFroid == 1)
			{
				sParamZxMZtemp[u8NumZone].bModeFroid = 0;
			}
			else sParamZxMZtemp[u8NumZone].bModeFroid = 1;

			MAJBoutonActiverFroid();
		}
	}
}

void Installation_MZ_config_zoneView::bouton_chaud()
{
	if((sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_A && sParamZxMZtemp[8].bModeChaud == 0 ) ||
		(sParamZxMZtemp[u8NumZone].u2RattachementGroupe == GROUPE_B && sParamZxMZtemp[9].bModeChaud == 0 ) )
	{
		sParamZxMZtemp[u8NumZone].bModeChaud = 0;
		MAJBoutonActiverChaud();
		affichage_chaud_non_autorise();
	}
	else
	{
		if(sParamZxMZtemp[u8NumZone].bModeChaud == 1)
		{
			sParamZxMZtemp[u8NumZone].bModeChaud = 0;
		}
		else sParamZxMZtemp[u8NumZone].bModeChaud = 1;

		MAJBoutonActiverChaud();
	}
}

void Installation_MZ_config_zoneView:: affichage_chaud_non_autorise()
{
	Unicode::snprintf(textAreaBuffer_MessMess, 500, touchgfx::TypedText(T_TEXT_MESSAGE_MODE_CHAUD_PAS_AUTORISE).getText());
	message_information.message(textAreaBuffer_MessMess);
	modalWindow_information.show();
	modalWindow_information.invalidate();
}

void Installation_MZ_config_zoneView:: affichage_froid_non_autorise()
{
	Unicode::snprintf(textAreaBuffer_MessMess, 500, touchgfx::TypedText(T_TEXT_MESSAGE_MODE_FROID_PAS_AUTORISE).getText());
	message_information.message(textAreaBuffer_MessMess);
	modalWindow_information.show();
	modalWindow_information.invalidate();
}

void Installation_MZ_config_zoneView:: bouton_valider_information()
{
	modalWindow_information.hide();
	modalWindow_information.invalidate();
}

void Installation_MZ_config_zoneView::MAJEmetteur()
{
//	//textArea_type_emet_dans_groupe.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
//
	switch(TypeEmetteur)
	{
		case RADIATEUR:
			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
			bModeFroid = 0;
			toggleButton_froid.forceState(false);
			toggleButton_froid.invalidate();
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
//		case SOUS_STATION:
//			textArea_valeur_type_emetteur.setTypedText(touchgfx::TypedText(T_TEXT_SOUS_STATION_CENTRE_DEFAUT));
//			break;
		default:
			break;
	}
	textArea_valeur_type_emetteur.invalidate();
	sParamZxMZtemp[u8NumZone].TypeEmmetteur = TypeEmetteur;
}

//void Installation_MZ_config_zoneView::bouton_droite_type_emetteur()
//{
//	if (TypeEmetteur < RADIATEUR) TypeEmetteur++;
//	else TypeEmetteur = PLANCHER;
//	MAJEmetteur();
//}
//
//void Installation_MZ_config_zoneView::bouton_gauche_type_emetteur()
//{
//	if (TypeEmetteur > PLANCHER) TypeEmetteur--;
//	else TypeEmetteur = RADIATEUR;
//	MAJEmetteur();
//}
void Installation_MZ_config_zoneView::bouton_droite_type_emetteur()
{
	if (TypeEmetteur == RADIATEUR)
	{
		TypeEmetteur = PLANCHER;
	}
	else
	{
		TypeEmetteur++;
	}

	switch(TypeEmetteur)
	{
		case PLANCHER:
			memcpy(&sParamZxMZtemp[u8NumZone].u8LoiDeau, &u8Loideau_Plancher, sizeof(u8Loideau_Plancher));
			break;
		case VENTILO:
			memcpy(&sParamZxMZtemp[u8NumZone].u8LoiDeau, &u8Loideau_Ventilo, sizeof(u8Loideau_Ventilo));
			break;
		case RADIATEUR:
			memcpy(&sParamZxMZtemp[u8NumZone].u8LoiDeau, &u8Loideau_Radiateur,  sizeof(u8Loideau_Radiateur));
			break;
		default:
			break;
	}

	MAJEmetteur();
}

void Installation_MZ_config_zoneView::bouton_gauche_type_emetteur()
{
	if(TypeEmetteur == PLANCHER)
	{
		TypeEmetteur = RADIATEUR;
	}
	else
	{
		TypeEmetteur--;
	}

	switch(TypeEmetteur)
	{
		case PLANCHER:
			memcpy(&sParamZxMZtemp[u8NumZone].u8LoiDeau, &u8Loideau_Plancher, sizeof(u8Loideau_Plancher));
			break;
		case VENTILO:
			memcpy(&sParamZxMZtemp[u8NumZone].u8LoiDeau, &u8Loideau_Ventilo, sizeof(u8Loideau_Ventilo));
			break;
		case RADIATEUR:
			memcpy(&sParamZxMZtemp[u8NumZone].u8LoiDeau, &u8Loideau_Radiateur,  sizeof(u8Loideau_Radiateur));
			break;
		default:
			break;
	}

	MAJEmetteur();
}

void Installation_MZ_config_zoneView::bouton_droite_type_sonde()
{
	if(sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat < TH_CONTACT) sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat++;
	else sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat = TH_RF;
	MAJTypeSonde();
}

void Installation_MZ_config_zoneView::bouton_gauche_type_sonde()
{
	if(sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat > TH_RF) sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat--;
	else sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat = TH_CONTACT;
	MAJTypeSonde();
}

void Installation_MZ_config_zoneView::MAJTypeSonde()
{
	container_sonde_rf.setVisible(false);
	buttonWithLabel_sonde_modbus.setVisible(false);

	switch(sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat)
	{
		case TH_RF:
			container_sonde_rf.setVisible(true);
			textArea_valeur_type_sonde.setTypedText(touchgfx::TypedText(T_TEXT_SONDE_RADIO_CENTRE_DEFAUT));
			break;
		case TH_MODBUS:
			buttonWithLabel_sonde_modbus.setVisible(true);
			textArea_valeur_type_sonde.setTypedText(touchgfx::TypedText(T_TEXT_SONDE_MODBUS_CENTRE_DEFAUT));
			break;
		case TH_CONTACT:
			textArea_valeur_type_sonde.setTypedText(touchgfx::TypedText(T_TEXT_SONDE_CONTACT_CENTRE_DEFAUT));
			break;
	}
	textArea_valeur_type_sonde.invalidate();
	container_sonde_rf.invalidate();
	buttonWithLabel_sonde_modbus.invalidate();
//	sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat = TypeThermostat;
}

void Installation_MZ_config_zoneView::MAJPertesDeCharges()
{
	Unicode::snprintf(textAreaBuffer_PertesDeCharges, 4, "%d", sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges);
	textArea_valeur_pertes_charges_gaines.setWildcard(textAreaBuffer_PertesDeCharges);
	textArea_valeur_pertes_charges_gaines.invalidate();
	//sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges = i8PertesDeCharges;
}

void Installation_MZ_config_zoneView::MAJVolumePiece()
{
	Unicode::snprintf(textAreaBuffer_VolumeZone, 4, "%d", (sParamZxMZtemp[u8NumZone].u7VolumePiece*5));
	textArea_valeur_volume_zone.setWildcard(textAreaBuffer_VolumeZone);
	textArea_valeur_volume_zone.invalidate();
	//sParamZxMZtemp[u8NumZone].u7VolumePiece = (VolumePiece / 5) & 0x7F;
}

void Installation_MZ_config_zoneView::MAJActivationCorrectionDebitAir()
{
	if(bActivationCorrection != 0)
	{
		image_on_off_correction_debit_air.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_correction_debit_air.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else
	{
		image_on_off_correction_debit_air.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
		textArea_on_off_correction_debit_air.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	}

	image_on_off_correction_debit_air.invalidate();
	textArea_on_off_correction_debit_air.invalidate();
}

void Installation_MZ_config_zoneView::bouton_droite_pdc_gaines()
{
	if (sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges < 90) sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges++;
	MAJPertesDeCharges();
}

void Installation_MZ_config_zoneView::bouton_gauche_pdc_gaines()
{
	if (sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges > -90) sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges--;
	MAJPertesDeCharges();
}

void Installation_MZ_config_zoneView::bouton_droite_volume_zone()
{
	if ((sParamZxMZtemp[u8NumZone].u7VolumePiece * 5) < 200) sParamZxMZtemp[u8NumZone].u7VolumePiece = sParamZxMZtemp[u8NumZone].u7VolumePiece+1;
	MAJVolumePiece();
}

void Installation_MZ_config_zoneView::bouton_gauche_volume_zone()
{
	if ((sParamZxMZtemp[u8NumZone].u7VolumePiece *5) > 0) sParamZxMZtemp[u8NumZone].u7VolumePiece = sParamZxMZtemp[u8NumZone].u7VolumePiece-1;
	MAJVolumePiece();
}

void Installation_MZ_config_zoneView:: renommer_zone()
{
	eTypeClavierAlpha = RENOMMER_ZONE_GROUPE;
}

void Installation_MZ_config_zoneView::bouton_valider()
{
//Cas des zones
	if (u8NumZone < 8)
	{
		application().gotoInstallation_MZ_param_ou_regroupement_zonesScreenNoTransition();
	}
	else //Cas des groupes
	{
		if (bRegroupementZoneTemp)
		{
			application().gotoInstallation_MZ_param_ou_regroupement_zonesScreenNoTransition();
		}
		else
		{
			application().gotoInstallation_hydrauliqueScreenNoTransition();
		}
	}
	sParamZxMZtemp[u8NumZone].TypeEmmetteur = TypeEmetteur;
}

void Installation_MZ_config_zoneView::bouton_retour()
{
	sParamZxMZtemp[u8NumZone].bModeChaud = bModeChaud;
	sParamZxMZtemp[u8NumZone].bModeFroid = bModeFroid;
	sParamZxMZtemp[u8NumZone].type_zone.zone.TypeThermostat = TypeThermostat;
	sParamZxMZtemp[u8NumZone].TypeEmmetteur = TypeEmetteur;
	sParamZxMZtemp[u8NumZone].u7VolumePiece =  (VolumePiece / 5) & 0x7F;
	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.i8PertesDeCharges = i8PertesDeCharges;
//	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bRegistreForce = bRegistreForce;
//	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.u4GestionRegistre = u4GestionRegistre;
	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bActivationCorrection = bActivationCorrection;
	//sParamZxMZtemp[u8NumZone].type_emetteur.gainable.CorrectionDebitAir = CorrectionDebitAir;

	memcpy(&sParamZxMZtemp[u8NumZone].u8NomZone, &u8NomZone, sizeof(u8NomZone));

	//Cas des zones
	if (u8NumZone < 8)
	{
		application().gotoInstallation_MZ_param_ou_regroupement_zonesScreenNoTransition();
	}
	else //Cas des groupes
	{
		application().gotoInstallation_MZ_parametrage_groupesScreenNoTransition();
	}
}

void Installation_MZ_config_zoneView::setupScreen()
{
    Installation_MZ_config_zoneViewBase::setupScreen();
}

void Installation_MZ_config_zoneView::tearDownScreen()
{
    Installation_MZ_config_zoneViewBase::tearDownScreen();
}


void Installation_MZ_config_zoneView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_config_zoneView::changeStatutRF(S_STATUT_RF *sStatut_RF)
{
	if(memcmp(&sStatut_RF[u8NumZone], &sStatut_RF_old, sizeof(sStatut_RF_old)))
	{
		//
		if(sStatut_RF[u8NumZone].Valid_Zx != 0)
		{
		    image_on_off_sonde_rf.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
			textArea_on_off_sonde_rf.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		}
		else
		{
		    image_on_off_sonde_rf.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
			textArea_on_off_sonde_rf.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		}
		image_on_off_sonde_rf.invalidate();
		textArea_on_off_sonde_rf.invalidate();
	}
}

void Installation_MZ_config_zoneView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_config_zoneView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_config_zoneView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_config_zoneView::changeDate(S_DATE *sDate)
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
