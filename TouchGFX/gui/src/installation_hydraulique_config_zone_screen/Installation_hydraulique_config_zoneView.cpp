#include <gui/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zoneView.hpp>
#include <images/BitmapDatabase.hpp>

Installation_hydraulique_config_zoneView::Installation_hydraulique_config_zoneView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	memset(&sStatut_RF_old, 0, sizeof(sStatut_RF_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutRF(&sStatut_RF[0]);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	//
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_PARAMETRES_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2 && sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE)
	{
		if(sConfig_Hydrau_temp.u8NumZone == 1)
		{
			container_type_emetteur.setVisible(false);
			buttonWithLabel_courbe_loi_eau.setVisible(false);
		}
		else if(sConfig_Hydrau_temp.u8NumZone == 0)
		{
			sConfig_Hydrau_temp.sParamZx.TypeEmmetteur = PLANCHER;
			button_droite_type_emetteur.setVisible(false);
			button_gauche_type_emetteur.setVisible(false);
		}
		buttonWithLabel_gestion_circulateur.setVisible(false);
	}
	else if(sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2 && sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_2_ZONES)
	{
		if(sConfig_Hydrau_temp.u8NumZone == 1)
		{
//			container_type_emetteur.setVisible(false);
//			buttonWithLabel_courbe_loi_eau.setVisible(false);
			if (sConfig_IHM.sParam_Zx[0].TypeEmmetteur == PLANCHER)
			{
				sConfig_Hydrau_temp.sParamZx.TypeEmmetteur = PLANCHER;
				button_droite_type_emetteur.setVisible(false);
				button_gauche_type_emetteur.setVisible(false);
			}
		}
	}
	else buttonWithLabel_gestion_circulateur.setVisible(true);
	//
	affichage_type_emetteur();
	affichage_type_sonde();
}

void Installation_hydraulique_config_zoneView::setupScreen()
{
    Installation_hydraulique_config_zoneViewBase::setupScreen();
}

void Installation_hydraulique_config_zoneView::tearDownScreen()
{
	Installation_hydraulique_config_zoneViewBase::tearDownScreen();
}

void Installation_hydraulique_config_zoneView::bouton_droite_type_emetteur()
{
	if(++sConfig_Hydrau_temp.sParamZx.TypeEmmetteur > RADIATEUR)
	{
		sConfig_Hydrau_temp.sParamZx.TypeEmmetteur = PLANCHER;
	}
	// Loi d'eau par défaut
	switch(sConfig_Hydrau_temp.sParamZx.TypeEmmetteur)
	{
		case RADIATEUR:
			memcpy(&sConfig_Hydrau_temp.sParamZx.u8LoiDeau, &u8Loideau_Radiateur, sizeof(u8Loideau_Plancher));
			break;
		case VENTILO:
			memcpy(&sConfig_Hydrau_temp.sParamZx.u8LoiDeau, &u8Loideau_Ventilo, sizeof(u8Loideau_Plancher));
			break;
		case PLANCHER:
			memcpy(&sConfig_Hydrau_temp.sParamZx.u8LoiDeau, &u8Loideau_Plancher, sizeof(u8Loideau_Plancher));
			break;
	}
	//
	affichage_type_emetteur();
}

void Installation_hydraulique_config_zoneView::bouton_gauche_type_emetteur()
{
	if(sConfig_Hydrau_temp.sParamZx.TypeEmmetteur == PLANCHER)
	{
		sConfig_Hydrau_temp.sParamZx.TypeEmmetteur = RADIATEUR;
	}
	else sConfig_Hydrau_temp.sParamZx.TypeEmmetteur--;
	// Loi d'eau par défaut
	switch(sConfig_Hydrau_temp.sParamZx.TypeEmmetteur)
	{
		case RADIATEUR:
			memcpy(&sConfig_Hydrau_temp.sParamZx.u8LoiDeau, &u8Loideau_Radiateur, sizeof(u8Loideau_Plancher));
			break;
		case VENTILO:
			memcpy(&sConfig_Hydrau_temp.sParamZx.u8LoiDeau, &u8Loideau_Ventilo, sizeof(u8Loideau_Plancher));
			break;
		case PLANCHER:
			memcpy(&sConfig_Hydrau_temp.sParamZx.u8LoiDeau, &u8Loideau_Plancher, sizeof(u8Loideau_Plancher));
			break;
	}
	//
	affichage_type_emetteur();
}

void Installation_hydraulique_config_zoneView::affichage_type_emetteur()
{
	//
	switch(sConfig_Hydrau_temp.sParamZx.TypeEmmetteur)
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
	}
	textArea_valeur_type_emetteur.invalidate();
}

void Installation_hydraulique_config_zoneView::bouton_droite_type_sonde()
{
	if(++sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat > TH_CONTACT)
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat = TH_RF;
	}
	affichage_type_sonde();
}

void Installation_hydraulique_config_zoneView::bouton_gauche_type_sonde()
{
	if(sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat == TH_RF)
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat = TH_CONTACT;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat--;
	affichage_type_sonde();
}

void Installation_hydraulique_config_zoneView::affichage_type_sonde()
{
	container_sonde_rf.setVisible(false);
	buttonWithLabel_sonde_modbus.setVisible(false);
	//
	switch(sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat)
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
}

void Installation_hydraulique_config_zoneView:: renommer_zone()
{
	eTypeClavierAlpha = RENOMMER_ZONE_GROUPE;
}


void Installation_hydraulique_config_zoneView::bouton_valider()
{
	memcpy(&sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone], &sConfig_Hydrau_temp.sParamZx, sizeof(S_PARAM_ZX));
	presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
	application().gotoInstallation_hydrauliqueScreenNoTransition();
}

void Installation_hydraulique_config_zoneView::changeStatutRF(S_STATUT_RF *sStatut_RF)
{
	if(memcmp(&sStatut_RF[sConfig_Hydrau_temp.u8NumZone], &sStatut_RF_old, sizeof(sStatut_RF_old)))
	{
		//
		if(sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Valid_Zx != 0)
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

void Installation_hydraulique_config_zoneView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_config_zoneView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_config_zoneView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_config_zoneView::changeDate(S_DATE *sDate)
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
