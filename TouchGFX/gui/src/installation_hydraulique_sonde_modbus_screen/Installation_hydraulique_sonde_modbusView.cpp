#include <gui/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusView.hpp>
#include <images/BitmapDatabase.hpp>

Installation_hydraulique_sonde_modbusView::Installation_hydraulique_sonde_modbusView()
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
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SONDE_MODBUS_TITRE_CENTRE_DEFAUT).getText());
	Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne)
	{
		toggleButton_verrouillage_consigne.forceState(true);
		textArea_on_off_verrouillage_consigne.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	//
	if(sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde)
	{
		toggleButton_arret_defaut.forceState(true);
		textArea_on_off_arret_defaut.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	//
	if(sConfig_IHM.sParam_PAC.bConfigThermostats120R)
	{
		image_on_off_resistance_terminaison.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_resistance_terminaison.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	// Numéro de sonde
	u8NumSonde = sConfig_Hydrau_temp.sParamZx.type_zone.zone.NumSonde;
	Unicode::snprintf(textAreaBuffer_num_sonde, 2, "%d", u8NumSonde + 1);
	textArea_valeur_num_sonde.setWildcard(textAreaBuffer_num_sonde);
	textArea_adresse.setWildcard(textAreaBuffer_num_sonde);

	bAttentionClicked = false;
	Unicode::snprintf(textAreaBuffer_MessTitre, 40, touchgfx::TypedText(T_TEXT_MESSAGE_ATTENTION_TITRE).getText());
	message_attention.titre(textAreaBuffer_MessTitre);
}

void Installation_hydraulique_sonde_modbusView::setupScreen()
{
    Installation_hydraulique_sonde_modbusViewBase::setupScreen();
}

void Installation_hydraulique_sonde_modbusView::tearDownScreen()
{
    Installation_hydraulique_sonde_modbusViewBase::tearDownScreen();
}

void Installation_hydraulique_sonde_modbusView::bouton_moins_numero_sonde()
{
	if(u8NumSonde > 0)
	{
		u8NumSonde--;
		Unicode::snprintf(textAreaBuffer_num_sonde, 2, "%d", u8NumSonde + 1);
		textArea_valeur_num_sonde.setWildcard(textAreaBuffer_num_sonde);
		textArea_adresse.setWildcard(textAreaBuffer_num_sonde);
		textArea_valeur_num_sonde.invalidate();
		textArea_adresse.invalidate();
	}
}

void Installation_hydraulique_sonde_modbusView::bouton_plus_numero_sonde()
{
	if(u8NumSonde < 7)
	{
		u8NumSonde++;
		Unicode::snprintf(textAreaBuffer_num_sonde, 2, "%d", u8NumSonde + 1);
		textArea_valeur_num_sonde.setWildcard(textAreaBuffer_num_sonde);
		textArea_adresse.setWildcard(textAreaBuffer_num_sonde);
		textArea_valeur_num_sonde.invalidate();
		textArea_adresse.invalidate();
	}
}

void Installation_hydraulique_sonde_modbusView::bouton_retour()
{
	sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bVerouillageConsigne;
	sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bArretZoneDefautSonde;
	//
	if(sConfig_Hydrau_temp.u8TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
	{
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_hydraulique_sonde_modbusView::bouton_verrouillage_consigne()
{
	if(toggleButton_verrouillage_consigne.getState())
	{
		textArea_on_off_verrouillage_consigne.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_verrouillage_consigne.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_verrouillage_consigne.invalidate();
}

void Installation_hydraulique_sonde_modbusView::bouton_arret_defaut()
{
	if(toggleButton_arret_defaut.getState())
	{
		textArea_on_off_arret_defaut.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_arret_defaut.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_arret_defaut.invalidate();
}

void Installation_hydraulique_sonde_modbusView::bouton_hysteresis()
{
	//
	if(toggleButton_verrouillage_consigne.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 0;
	//
	if(toggleButton_arret_defaut.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 0;
	//
	eHysteresis = HYST_TINT;
	application().gotoInstallation_hysteresisScreenNoTransition();
}

void Installation_hydraulique_sonde_modbusView::bouton_resistance_terminaison()
{
	//
	if(toggleButton_verrouillage_consigne.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 0;
	//
	if(toggleButton_arret_defaut.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 0;
	//
	eOuiNon = OUI_NON_RESIST_TERM_SONDE;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Installation_hydraulique_sonde_modbusView:: affichage_attention()
{
	Unicode::snprintf(textAreaBuffer_MessMess, 500, touchgfx::TypedText(T_TEXT_MESSAGE_MEME_NUMERO_SONDE).getText());
	message_attention.message(textAreaBuffer_MessMess);

	modalWindow_attention.show();
	modalWindow_attention.invalidate();
}

void Installation_hydraulique_sonde_modbusView::bouton_valider_attention()
{
	//
	if(toggleButton_verrouillage_consigne.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 0;
	//
	if(toggleButton_arret_defaut.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 0;
	//
	sConfig_Hydrau_temp.sParamZx.type_zone.zone.NumSonde = u8NumSonde;
	//
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.NumSonde = u8NumSonde;
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bVerouillageConsigne = sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne;
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bArretZoneDefautSonde = sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde;
	//
	presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
	application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydraulique_sonde_modbusView::bouton_valider()
{
	bool bFlagSonde = false;
	//Affichage message qu'une autre sonde porte le même numéro
	for (int i = 0;i<NB_ZONE; i++)
	{
		if ((((sConfig_IHM.sOption_PAC.sZone.u8val >> i) & 0b01) ==1) && sParamZxMZtemp[i].type_zone.zone.TypeThermostat == TH_RF && i !=sConfig_Hydrau_temp.u8NumZone)
		{
			if (sParamZxMZtemp[i].type_zone.zone.NumSonde == u8NumSonde)
			{
//				if (bAttentionClicked == false)
//				{
//					bAttentionClicked = true;
					affichage_attention();
					bFlagSonde = true;
//				}
			}
		}
	}
	if (bFlagSonde == false)
	{
		//
		if(toggleButton_verrouillage_consigne.getState())
		{
			sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 1;
		}
		else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = 0;
		//
		if(toggleButton_arret_defaut.getState())
		{
			sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 1;
		}
		else sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = 0;
		//
		sConfig_Hydrau_temp.sParamZx.type_zone.zone.NumSonde = u8NumSonde;
		//
		sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.NumSonde = u8NumSonde;
		sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bVerouillageConsigne = sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne;
		sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bArretZoneDefautSonde = sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde;
		//
		presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_hydraulique_sonde_modbusView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_sonde_modbusView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_sonde_modbusView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_sonde_modbusView::changeDate(S_DATE *sDate)
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
