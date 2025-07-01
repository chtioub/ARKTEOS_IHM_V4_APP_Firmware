#include <gui/installation_hydraulique_param_comp_screen/Installation_hydraulique_param_compView.hpp>

Installation_hydraulique_param_compView::Installation_hydraulique_param_compView()
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
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		textArea_question_oui_non_chauffage.setTypedText(touchgfx::TypedText(T_TEXT_CHAUFFAGE_CENTRE_DEFAUT));
		textArea_question_oui_non_rafraichissement.setTypedText(touchgfx::TypedText(T_TEXT_RAFRAICHISSEMENT_CENTRE_DEFAUT));
		Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_COMPLEMENTAIRE_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_COMPLEMENTAIRE_CENTRE_DEFAUT).getText());
	    Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
		Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	    Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	}
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		//
		if(sConfig_IHM.sParam_RegulExt.bModeChaud == 0)
		{
			toggleButton_oui_oui_non_chauffage.forceState(false);
			toggleButton_oui_oui_non_chauffage.setTouchable(true);
			toggleButton_non_oui_non_chauffage.forceState(true);
			toggleButton_non_oui_non_chauffage.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_chauffage.forceState(true);
			toggleButton_oui_oui_non_chauffage.setTouchable(false);
			toggleButton_non_oui_non_chauffage.forceState(false);
			toggleButton_non_oui_non_chauffage.setTouchable(true);
		}
		//
		if(sConfig_IHM.sParam_RegulExt.bModeFroid == 0)
		{
			toggleButton_oui_oui_non_rafraichissement.forceState(false);
			toggleButton_oui_oui_non_rafraichissement.setTouchable(true);
			toggleButton_non_oui_non_rafraichissement.forceState(true);
			toggleButton_non_oui_non_rafraichissement.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_rafraichissement.forceState(true);
			toggleButton_oui_oui_non_rafraichissement.setTouchable(false);
			toggleButton_non_oui_non_rafraichissement.forceState(false);
			toggleButton_non_oui_non_rafraichissement.setTouchable(true);
		}
		// Temp depart eau
		u8TempDepartEau = sConfig_IHM.sParam_RegulExt.u4ConsigneEauFroid + 7;
	}
	else
	{
		//
		if(sConfig_Hydrau_temp.sParamZx.bModeChaud == 0)
		{
			toggleButton_oui_oui_non_chauffage.forceState(false);
			toggleButton_oui_oui_non_chauffage.setTouchable(true);
			toggleButton_non_oui_non_chauffage.forceState(true);
			toggleButton_non_oui_non_chauffage.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_chauffage.forceState(true);
			toggleButton_oui_oui_non_chauffage.setTouchable(false);
			toggleButton_non_oui_non_chauffage.forceState(false);
			toggleButton_non_oui_non_chauffage.setTouchable(true);
		}
		//
		if(sConfig_Hydrau_temp.sParamZx.bModeFroid == 0)
		{
			toggleButton_oui_oui_non_rafraichissement.forceState(false);
			toggleButton_oui_oui_non_rafraichissement.setTouchable(true);
			toggleButton_non_oui_non_rafraichissement.forceState(true);
			toggleButton_non_oui_non_rafraichissement.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_rafraichissement.forceState(true);
			toggleButton_oui_oui_non_rafraichissement.setTouchable(false);
			toggleButton_non_oui_non_rafraichissement.forceState(false);
			toggleButton_non_oui_non_rafraichissement.setTouchable(true);
		}
		// Temp depart eau
		u8TempDepartEau = sConfig_Hydrau_temp.sParamZx.u4ConsigneTeauFroid + 7;
	}
	// Oui non rafraichissement
	if(sConfig_IHM.sModele_PAC.bReversible != 0 || (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV && (sConfig_IHM.sConfig_PAC.ConfigGeo.bFreecooling || sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid)) || (sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA && (sConfig_IHM.sConfig_PAC.ConfigGeoInverter.bFreecooling || sConfig_IHM.sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid)))
	{
		if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE || sConfig_Hydrau_temp.sParamZx.TypeEmmetteur < RADIATEUR)
		{
			container_oui_non_rafraichissement.setVisible(true);
		}
	}
	// Bouton consigne eau
	if(container_oui_non_rafraichissement.isVisible() && toggleButton_oui_oui_non_rafraichissement.getState() && sConfig_Hydrau_temp.u8TypeRegul != REGUL_ESCLAVE && (sConfig_Hydrau_temp.u8TypeRegul != REGUL_DIRECTE || sConfig_Hydrau_temp.u8NumZone == 0 || sConfig_Hydrau_temp.sZones.bZone1 == 0 || sConfig_Hydrau_temp.sZones.bZone2 == 0 || sConfig_IHM.sParam_Zx[0].bModeFroid == 0))
	{
		container_temp_depart_eau_raf.setVisible(true);
		container_temp_depart_eau_raf.invalidate();
	}
	//
	if(sConfig_Hydrau_temp.u8TypeRegul < REGUL_EXTERNE && container_oui_non_rafraichissement.isVisible() && toggleButton_oui_oui_non_rafraichissement.getState() && sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		container_change_over.setVisible(true);
		container_change_over.invalidate();
	}
	if(sConfig_IHM.sParam_PAC.bThermostatContactModeFroid)
	{
		toggleButton_change_over.forceState(true);
		textArea_on_off_change_over.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	// Temperature minimum eau
	if(sConfig_Hydrau_temp.u8TypeRegul < REGUL_EXTERNE && sConfig_Hydrau_temp.sParamZx.TypeEmmetteur == PLANCHER)
	{
		u8TempDepartEau_MIN = 17;
	}
	else u8TempDepartEau_MIN = 7;
	// Temperature max eau
	if((sConfig_Hydrau_temp.u8TypeRegul == REGUL_BCP_INTERNE || sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_2_ZONES) && sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2 && sConfig_Hydrau_temp.u8NumZone == 1)
	{
		if(u8TempDepartEau_MIN < (sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid + 7))
		{
			u8TempDepartEau_MIN = sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid + 7;
		}
	}
	// Temperature max eau
	if((sConfig_Hydrau_temp.u8TypeRegul == REGUL_BCP_INTERNE || sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_2_ZONES) && sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2 && sConfig_Hydrau_temp.u8NumZone == 0)
	{
		u8TempDepartEau_MAX = sConfig_IHM.sParam_Zx[1].u4ConsigneTeauFroid + 7;
	}
	else u8TempDepartEau_MAX = 22;
	//
	if(u8TempDepartEau > u8TempDepartEau_MAX)
	{
		u8TempDepartEau = u8TempDepartEau_MAX;
	}
	//
	if(u8TempDepartEau < u8TempDepartEau_MIN)
	{
		u8TempDepartEau = u8TempDepartEau_MIN;
	}
	// Temp depart eau
	Unicode::snprintfFloat(textAreaBuffer_TempDepartEau, 6, "%.1f", (float) u8TempDepartEau);
	textArea_valeur_temp_depart_eau_raf.setWildcard(textAreaBuffer_TempDepartEau);
}

void Installation_hydraulique_param_compView::setupScreen()
{
    Installation_hydraulique_param_compViewBase::setupScreen();
}

void Installation_hydraulique_param_compView::tearDownScreen()
{
    Installation_hydraulique_param_compViewBase::tearDownScreen();
}

void Installation_hydraulique_param_compView::bouton_dep_eau_moins()
{
	if(u8TempDepartEau > u8TempDepartEau_MIN)
	{
		u8TempDepartEau--;
		Unicode::snprintfFloat(textAreaBuffer_TempDepartEau, 6, "%.1f", (float) u8TempDepartEau);
		textArea_valeur_temp_depart_eau_raf.setWildcard(textAreaBuffer_TempDepartEau);
		textArea_valeur_temp_depart_eau_raf.invalidate();
	}
}

void Installation_hydraulique_param_compView::bouton_dep_eau_plus()
{
	if(u8TempDepartEau < u8TempDepartEau_MAX)
	{
		u8TempDepartEau++;
		Unicode::snprintfFloat(textAreaBuffer_TempDepartEau, 6, "%.1f", (float) u8TempDepartEau);
		textArea_valeur_temp_depart_eau_raf.setWildcard(textAreaBuffer_TempDepartEau);
		textArea_valeur_temp_depart_eau_raf.invalidate();
	}
}

void Installation_hydraulique_param_compView::bouton_oui_chauffage()
{
	if(toggleButton_oui_oui_non_chauffage.getState())
	{
		toggleButton_non_oui_non_chauffage.forceState(false);
		toggleButton_non_oui_non_chauffage.setTouchable(true);
		toggleButton_non_oui_non_chauffage.invalidate();
		toggleButton_oui_oui_non_chauffage.setTouchable(false);
		toggleButton_oui_oui_non_chauffage.invalidate();
	}
}

void Installation_hydraulique_param_compView::bouton_non_chauffage()
{
	if(toggleButton_non_oui_non_chauffage.getState())
	{
		toggleButton_oui_oui_non_chauffage.forceState(false);
		toggleButton_oui_oui_non_chauffage.setTouchable(true);
		toggleButton_oui_oui_non_chauffage.invalidate();
		toggleButton_non_oui_non_chauffage.setTouchable(false);
		toggleButton_non_oui_non_chauffage.invalidate();
	}
}

void Installation_hydraulique_param_compView::bouton_oui_rafraichissement()
{
	if(toggleButton_oui_oui_non_rafraichissement.getState())
	{
		toggleButton_non_oui_non_rafraichissement.forceState(false);
		toggleButton_non_oui_non_rafraichissement.setTouchable(true);
		toggleButton_non_oui_non_rafraichissement.invalidate();
		toggleButton_oui_oui_non_rafraichissement.setTouchable(false);
		toggleButton_oui_oui_non_rafraichissement.invalidate();
		//
		if(sConfig_Hydrau_temp.u8TypeRegul != REGUL_ESCLAVE && (sConfig_Hydrau_temp.u8TypeRegul != REGUL_DIRECTE || sConfig_Hydrau_temp.u8NumZone == 0 || sConfig_Hydrau_temp.sZones.bZone1 == 0 || sConfig_Hydrau_temp.sZones.bZone2 == 0 || sConfig_IHM.sParam_Zx[0].bModeFroid == 0))
		{
			container_temp_depart_eau_raf.setVisible(true);
			container_temp_depart_eau_raf.invalidate();
		}
		//
		if(sConfig_Hydrau_temp.u8TypeRegul < REGUL_EXTERNE && sConfig_Hydrau_temp.sParamZx.type_zone.zone.TypeThermostat == TH_CONTACT)
		{
			container_change_over.setVisible(true);
			container_change_over.invalidate();
		}
	}
}

void Installation_hydraulique_param_compView::bouton_non_rafraichissement()
{
	if(toggleButton_non_oui_non_rafraichissement.getState())
	{
		toggleButton_oui_oui_non_rafraichissement.forceState(false);
		toggleButton_oui_oui_non_rafraichissement.setTouchable(true);
		toggleButton_oui_oui_non_rafraichissement.invalidate();
		toggleButton_non_oui_non_rafraichissement.setTouchable(false);
		toggleButton_non_oui_non_rafraichissement.invalidate();
		container_temp_depart_eau_raf.setVisible(false);
		container_temp_depart_eau_raf.invalidate();
		container_change_over.setVisible(false);
		container_change_over.invalidate();
	}
}

void Installation_hydraulique_param_compView::bouton_retour()
{
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
	else application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydraulique_param_compView::bouton_change_over()
{
	if(toggleButton_change_over.getState())
	{
		textArea_on_off_change_over.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_change_over.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_change_over.invalidate();
}


void Installation_hydraulique_param_compView::bouton_valider()
{
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		//
		if(toggleButton_oui_oui_non_chauffage.getState())
		{
			sConfig_IHM.sParam_RegulExt.bModeChaud = 1;
		}
		else sConfig_IHM.sParam_RegulExt.bModeChaud = 0;
		//
		if(toggleButton_oui_oui_non_rafraichissement.getState())
		{
			sConfig_IHM.sParam_RegulExt.bModeFroid = 1;
		}
		else sConfig_IHM.sParam_RegulExt.bModeFroid = 0;
		// Temp depart eau
		sConfig_IHM.sParam_RegulExt.u4ConsigneEauFroid = u8TempDepartEau - 7;
		//
		presenter->c_install_reg_ext();//c_install_param();
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
	else
	{
		//
		if(toggleButton_oui_oui_non_chauffage.getState())
		{
			sConfig_Hydrau_temp.sParamZx.bModeChaud = 1;
		}
		else sConfig_Hydrau_temp.sParamZx.bModeChaud = 0;
		//
		if(container_oui_non_rafraichissement.isVisible() && toggleButton_oui_oui_non_rafraichissement.getState())
		{
			sConfig_Hydrau_temp.sParamZx.bModeFroid = 1;
		}
		else sConfig_Hydrau_temp.sParamZx.bModeFroid = 0;
		// Temp depart eau
		sConfig_Hydrau_temp.sParamZx.u4ConsigneTeauFroid = u8TempDepartEau - 7;
		//
		sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].bModeChaud = sConfig_Hydrau_temp.sParamZx.bModeChaud;
		sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].bModeFroid = sConfig_Hydrau_temp.sParamZx.bModeFroid;
		sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid = sConfig_Hydrau_temp.sParamZx.u4ConsigneTeauFroid;
		//
		if(sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2)
		{
			//
			if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE && container_temp_depart_eau_raf.isVisible())
			{
				if(sConfig_Hydrau_temp.u8NumZone == 0)
				{
					sConfig_IHM.sParam_Zx[1].u4ConsigneTeauFroid = u8TempDepartEau - 7;
					presenter->c_install_zx(1);
				}
				else
				{
					sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid = u8TempDepartEau - 7;
					presenter->c_install_zx(0);
				}
			}
			//
			if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_BCP_INTERNE || sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_2_ZONES)
			{
				//
				if(sConfig_Hydrau_temp.u8NumZone == 0 && sConfig_IHM.sParam_Zx[1].u4ConsigneTeauFroid < sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid)
				{
					sConfig_IHM.sParam_Zx[1].u4ConsigneTeauFroid = sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid;
					presenter->c_install_zx(1);
				}
				//
				if(sConfig_Hydrau_temp.u8NumZone == 1 && sConfig_IHM.sParam_Zx[1].u4ConsigneTeauFroid < sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid)
				{
					sConfig_IHM.sParam_Zx[0].u4ConsigneTeauFroid = sConfig_IHM.sParam_Zx[1].u4ConsigneTeauFroid;
					presenter->c_install_zx(0);
				}
			}
		}
		//
		if(sConfig_IHM.sParam_PAC.bThermostatContactModeFroid != toggleButton_change_over.getState())
		{
			sConfig_IHM.sParam_PAC.bThermostatContactModeFroid = toggleButton_change_over.getState();
			presenter->c_install_param();
		}
		//
		presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_hydraulique_param_compView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_param_compView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_param_compView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_param_compView::changeDate(S_DATE *sDate)
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
