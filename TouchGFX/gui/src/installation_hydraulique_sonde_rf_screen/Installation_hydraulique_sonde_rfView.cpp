#include <gui/installation_hydraulique_sonde_rf_screen/Installation_hydraulique_sonde_rfView.hpp>
#include <images/BitmapDatabase.hpp>

Installation_hydraulique_sonde_rfView::Installation_hydraulique_sonde_rfView()
{
	memset(&sStatut_RF_old, 0, sizeof(sStatut_RF_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeStatutRF(&sStatut_RF[0]);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SONDE_RADIO_TITRE_CENTRE_DEFAUT).getText());
	Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Valid_Zx != 0)
	{
		toggleButton_associer.forceState(true);
		toggleButton_associer.setTouchable(false);
		toggleButton_dissocer.forceState(false);
		toggleButton_dissocer.setTouchable(true);
	}
	else
	{
		toggleButton_associer.forceState(false);
		toggleButton_associer.setTouchable(true);
		toggleButton_dissocer.forceState(true);
		toggleButton_dissocer.setTouchable(false);
	}
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
	//
	Unicode::snprintf(textAreaBuffer_num_sonde, 2, "%d", sConfig_Hydrau_temp.sParamZx.type_zone.zone.NumSonde + 1);
	textArea_numero_sonde.setWildcard(textAreaBuffer_num_sonde);
}

void Installation_hydraulique_sonde_rfView::setupScreen()
{
    Installation_hydraulique_sonde_rfViewBase::setupScreen();
}

void Installation_hydraulique_sonde_rfView::tearDownScreen()
{
    Installation_hydraulique_sonde_rfViewBase::tearDownScreen();
}

void Installation_hydraulique_sonde_rfView::bouton_mem_config()
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
}

void Installation_hydraulique_sonde_rfView::bouton_retour()
{
	sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne = sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bVerouillageConsigne;
	sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde = sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bArretZoneDefautSonde;
	//
	if(sConfig_Hydrau_temp.u8TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
	{
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_hydraulique_sonde_rfView::bouton_associer()
{
	if(toggleButton_associer.getState())
	{
		toggleButton_associer.setTouchable(false);
		toggleButton_associer.invalidate();
		toggleButton_dissocer.forceState(false);
		toggleButton_dissocer.setTouchable(true);
		toggleButton_dissocer.invalidate();
		//
		presenter->c_install_th_association(sConfig_Hydrau_temp.u8NumZone);
	}
}

void Installation_hydraulique_sonde_rfView::bouton_dissocier()
{
	if(toggleButton_dissocer.getState())
	{
		toggleButton_dissocer.setTouchable(false);
		toggleButton_dissocer.invalidate();
		toggleButton_associer.forceState(false);
		toggleButton_associer.setTouchable(true);
		toggleButton_associer.invalidate();
		//
		presenter->c_install_th_dissociation(sConfig_Hydrau_temp.u8NumZone);
	}
}

void Installation_hydraulique_sonde_rfView::bouton_verrouillage_consigne()
{
	if(toggleButton_verrouillage_consigne.getState())
	{
		textArea_on_off_verrouillage_consigne.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_verrouillage_consigne.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_verrouillage_consigne.invalidate();
}

void Installation_hydraulique_sonde_rfView::bouton_arret_defaut()
{
	if(toggleButton_arret_defaut.getState())
	{
		textArea_on_off_arret_defaut.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_arret_defaut.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_arret_defaut.invalidate();
}

void Installation_hydraulique_sonde_rfView::bouton_hysteresis()
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

void Installation_hydraulique_sonde_rfView::bouton_resistance_terminaison()
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

void Installation_hydraulique_sonde_rfView::bouton_valider()
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
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bVerouillageConsigne = sConfig_Hydrau_temp.sParamZx.type_zone.zone.bVerouillageConsigne;
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.bArretZoneDefautSonde = sConfig_Hydrau_temp.sParamZx.type_zone.zone.bArretZoneDefautSonde;
	//
	presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
	application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydraulique_sonde_rfView::changeStatutRF(S_STATUT_RF *sStatut_RF)
{
	if(memcmp(&sStatut_RF[sConfig_Hydrau_temp.u8NumZone], &sStatut_RF_old, sizeof(sStatut_RF_old)))
	{
		//
		if(sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Valid_Zx != 0)
		{
			container_qualite_signal.setVisible(true);
			textArea_signal.setTypedText(touchgfx::TypedText(T_TEXT_QUALITE_SIGNAL_CENTRE_DEFAUT));
			//
			if(sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception > -70)
			{
				image_qualite_signal.setBitmap(touchgfx::Bitmap(BITMAP_ETAT_RECEPTION_RF_EXCELLENTE_L184XH71_ID));
			}
			else if(sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception <= -70 && sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception > -80)
			{
				image_qualite_signal.setBitmap(touchgfx::Bitmap(BITMAP_ETAT_RECEPTION_RF_BONNE_L184XH71_ID));
			}
			else if (sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception <= -80 && sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception > -90)
			{
				image_qualite_signal.setBitmap(touchgfx::Bitmap(BITMAP_ETAT_RECEPTION_RF_MOYENNE_L184XH71_ID));
			}
			else if (sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception <= -90 && sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Niveau_Reception > -95)
			{
				image_qualite_signal.setBitmap(touchgfx::Bitmap(BITMAP_ETAT_RECEPTION_RF_FAIBLE_L184XH71_ID));
			}
			else image_qualite_signal.setBitmap(touchgfx::Bitmap(BITMAP_ETAT_RECEPTION_RF_MAUVAISE_L184XH71_ID));
			image_qualite_signal.invalidate();
		}
		else
		{
			//
			container_qualite_signal.setVisible(false);
			//
			if(sStatut_RF[sConfig_Hydrau_temp.u8NumZone].Init_Zx != 0)
			{
				textArea_signal.setTypedText(touchgfx::TypedText(T_TEXT_ASSOCIATION_EN_COURS_CENTRE_DEFAUT));
			}
			else
			{
				textArea_signal.setTypedText(touchgfx::TypedText(T_TEXT_AUCUNE_SONDE_CENTRE_DEFAUT));
			}
		}
		toggleButton_associer.invalidate();
		toggleButton_dissocer.invalidate();
		container_qualite_signal.invalidate();
		textArea_signal.invalidate();
	}
}

void Installation_hydraulique_sonde_rfView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_sonde_rfView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_sonde_rfView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_sonde_rfView::changeDate(S_DATE *sDate)
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
