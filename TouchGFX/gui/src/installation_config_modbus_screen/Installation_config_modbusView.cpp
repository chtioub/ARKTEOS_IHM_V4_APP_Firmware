#include <gui/installation_config_modbus_screen/Installation_config_modbusView.hpp>

Installation_config_modbusView::Installation_config_modbusView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_MODBUS_TITRE_CENTRE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	bConfigThermostats120R = sConfig_IHM.sParam_PAC.bConfigThermostats120R;
	bGestionTimeOut = sConfig_IHM.sParamModbus.bGestionTimeOut;
	adresse = sConfig_IHM.sParamModbus.adresse;
	speed = sConfig_IHM.sParamModbus.speed;
	u1NbStopBit = sConfig_IHM.sParamModbus.u1NbStopBit;
	u2Parite = sConfig_IHM.sParamModbus.u2Parite;
	bThermostatModbusExterne = sConfig_IHM.sParam_PAC.bThermostatModbusExterne;
	if (adresse == 0) adresse = 1;

	if (bThermostatModbusExterne) toggleButton_temp_zones_modbus.forceState(true);
	else toggleButton_temp_zones_modbus.forceState(false);
	toggleButton_temp_zones_modbus.invalidate();

	if (bConfigThermostats120R == 1)
	{
		toggleButton_activer_resistance_oui.forceState(true);
		toggleButton_activer_resistance_oui.setTouchable(false);
		toggleButton_activer_resistance_non.forceState(false);
		toggleButton_activer_resistance_non.setTouchable(true);
	}
	else
	{
		toggleButton_activer_resistance_oui.forceState(false);
		toggleButton_activer_resistance_oui.setTouchable(true);
		toggleButton_activer_resistance_non.forceState(true);
		toggleButton_activer_resistance_non.setTouchable(false);
	}
	toggleButton_activer_resistance_non.invalidate();
	toggleButton_activer_resistance_oui.invalidate();

	if (bGestionTimeOut == 1)
	{
		toggleButton_arret_pac_oui.forceState(true);
		toggleButton_arret_pac_oui.setTouchable(false);
		toggleButton_arret_pac_non.forceState(false);
		toggleButton_arret_pac_non.setTouchable(true);
	}
	else
	{
		toggleButton_arret_pac_oui.forceState(false);
		toggleButton_arret_pac_oui.setTouchable(true);
		toggleButton_arret_pac_non.forceState(true);
		toggleButton_arret_pac_non.setTouchable(false);
	}
	toggleButton_arret_pac_non.invalidate();
	toggleButton_arret_pac_oui.invalidate();

	update_temp_zones();
	update_parite();
	update_stopbit();
	update_vitesse();
	update_adresse();
}

void Installation_config_modbusView::update_temp_zones()
{
	if (bThermostatModbusExterne == 1)
	{
		textArea_on_off_temp_zones_modbus.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else
	{
		textArea_on_off_temp_zones_modbus.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	}
	textArea_on_off_temp_zones_modbus.invalidate();
}

void Installation_config_modbusView::bouton_temp_zones()
{
	if(toggleButton_temp_zones_modbus.getState()) bThermostatModbusExterne = 1;
	else bThermostatModbusExterne = 0;

	update_temp_zones();
}

void Installation_config_modbusView::bouton_activer_resistance_oui()
{
	if (toggleButton_activer_resistance_oui.getState())
	{
		toggleButton_activer_resistance_oui.forceState(true);
		toggleButton_activer_resistance_oui.setTouchable(false);
		toggleButton_activer_resistance_non.forceState(false);
		toggleButton_activer_resistance_non.setTouchable(true);
	}
	toggleButton_activer_resistance_non.invalidate();
	toggleButton_activer_resistance_oui.invalidate();

	bConfigThermostats120R = 1;
}

void Installation_config_modbusView::bouton_activer_resistance_non()
{
	if (toggleButton_activer_resistance_non.getState())
	{
		toggleButton_activer_resistance_oui.forceState(false);
		toggleButton_activer_resistance_oui.setTouchable(true);
		toggleButton_activer_resistance_non.forceState(true);
		toggleButton_activer_resistance_non.setTouchable(false);
	}
	toggleButton_activer_resistance_non.invalidate();
	toggleButton_activer_resistance_oui.invalidate();

	bConfigThermostats120R = 0;
}

void Installation_config_modbusView::bouton_arret_pac_oui()
{
	if (toggleButton_arret_pac_oui.getState())
	{
		toggleButton_arret_pac_oui.forceState(true);
		toggleButton_arret_pac_oui.setTouchable(false);
		toggleButton_arret_pac_non.forceState(false);
		toggleButton_arret_pac_non.setTouchable(true);
	}
	toggleButton_arret_pac_non.invalidate();
	toggleButton_arret_pac_oui.invalidate();

	bGestionTimeOut = 1;
}

void Installation_config_modbusView::bouton_arret_pac_non()
{
	if (toggleButton_arret_pac_non.getState())
	{
		toggleButton_arret_pac_oui.forceState(false);
		toggleButton_arret_pac_oui.setTouchable(true);
		toggleButton_arret_pac_non.forceState(true);
		toggleButton_arret_pac_non.setTouchable(false);
	}
	toggleButton_arret_pac_non.invalidate();
	toggleButton_arret_pac_oui.invalidate();

	bGestionTimeOut = 0;
}

void Installation_config_modbusView::bouton_gauche_parite()
{
	if (u2Parite == 0) u2Parite = 2;
	else u2Parite--;
	update_parite();
}

void Installation_config_modbusView::bouton_droite_parite()
{
	if (u2Parite == 2) u2Parite = 0;
	else u2Parite++;
	update_parite();
}

void Installation_config_modbusView::update_parite()
{
	switch(u2Parite)
	{
		default:
		case 0:
			Unicode::snprintf(textAreaBuffer_Parite,5, "None");
			break;
		case 1:
			Unicode::snprintf(textAreaBuffer_Parite,5, "Even");
			break;
		case 2:
			Unicode::snprintf(textAreaBuffer_Parite,5, "Odd");
			break;
	}
	textArea_valeur_choix_parite.setWildcard(textAreaBuffer_Parite);
	textArea_valeur_choix_parite.invalidate();
}

void Installation_config_modbusView::bouton_gauche_nb()
{
	if (u1NbStopBit == 0) u1NbStopBit = 1;
	else u1NbStopBit = 0;
	update_stopbit();
}

void Installation_config_modbusView::bouton_droite_nb()
{
	if (u1NbStopBit == 0) u1NbStopBit = 1;
	else u1NbStopBit = 0;
	update_stopbit();
}

void Installation_config_modbusView::update_stopbit()
{
	Unicode::snprintf(textAreaBuffer_StopBit, 2, "%d", (u1NbStopBit + 1));
	textArea_valeur_choix_nb_stopbit.setWildcard(textAreaBuffer_StopBit);
	textArea_valeur_choix_nb_stopbit.invalidate();
}

void Installation_config_modbusView::bouton_gauche_vitesse()
{
	if (speed == 0) speed = 3;
	else speed--;
	update_vitesse();
}

void Installation_config_modbusView::bouton_droite_vitesse()
{
	if (speed == 3) speed = 0;
	else speed++;
	update_vitesse();
}

void Installation_config_modbusView::update_vitesse()
{
	switch(speed)
	{
		case 0:
			Unicode::snprintf(textAreaBuffer_Speed,6, "4800");
			break;
		case 1:
			Unicode::snprintf(textAreaBuffer_Speed,6, "9600");
			break;
		case 2:
			Unicode::snprintf(textAreaBuffer_Speed,6, "19200");
			break;
		case 3:
			Unicode::snprintf(textAreaBuffer_Speed,6, "38400");
			break;
	}
	textArea_valeur_choix_vitesse.setWildcard(textAreaBuffer_Speed);
	textArea_valeur_choix_vitesse.invalidate();
}

void Installation_config_modbusView::bouton_gauche_adresse()
{
	if (adresse == 1) adresse = 1;
	else adresse--;
	update_adresse();
}

void Installation_config_modbusView::bouton_droite_adresse()
{
	if (adresse == 63) adresse = 63;
	else adresse++;
	update_adresse();
}

void Installation_config_modbusView::update_adresse()
{
	Unicode::snprintf(textAreaBuffer_Adresse, 3, "%d", adresse);
	textArea_valeur_choix_adresse.setWildcard(textAreaBuffer_Adresse);
	textArea_valeur_choix_adresse.invalidate();
}


void Installation_config_modbusView::bouton_valider()
{
	sConfig_IHM.sParam_PAC.bConfigThermostats120R = bConfigThermostats120R & 1;
	sConfig_IHM.sParamModbus.bGestionTimeOut = bGestionTimeOut & 1;
	sConfig_IHM.sParamModbus.u7TimeOut = 60 & 0x7F;
	sConfig_IHM.sParamModbus.adresse = adresse;
	sConfig_IHM.sParamModbus.speed = speed;
	sConfig_IHM.sParamModbus.u1NbStopBit = u1NbStopBit & 1;
	sConfig_IHM.sParamModbus.u2Parite = u2Parite & 0b11;
	sConfig_IHM.sParam_PAC.bThermostatModbusExterne = bThermostatModbusExterne & 1;
	presenter->c_install_param();
	presenter->c_install_modbus();
}

void Installation_config_modbusView::setupScreen()
{
    Installation_config_modbusViewBase::setupScreen();
}

void Installation_config_modbusView::tearDownScreen()
{
    Installation_config_modbusViewBase::tearDownScreen();
}

void Installation_config_modbusView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_config_modbusView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_config_modbusView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_config_modbusView::changeDate(S_DATE *sDate)
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
