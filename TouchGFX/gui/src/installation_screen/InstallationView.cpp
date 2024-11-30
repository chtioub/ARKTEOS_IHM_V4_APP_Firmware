#include <gui/installation_screen/InstallationView.hpp>

InstallationView::InstallationView()
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

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_INSTALLATION_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void InstallationView::setupScreen()
{
    InstallationViewBase::setupScreen();
}

void InstallationView::tearDownScreen()
{
    InstallationViewBase::tearDownScreen();
}

void InstallationView::bouton_mem_config()
{
    sConfig_Hydrau_temp.u8TypeRegul = sConfig_IHM.sParam_PAC.TypeRegul;
	sConfig_Hydrau_temp.sZones = sConfig_IHM.sOption_PAC.sZone;
}

void InstallationView::bouton_mem_config_piscine()
{
	sConfig_Piscine_temp.bPiscine = sConfig_IHM.sOption_PAC.Piscine;
    memcpy(&sConfig_Piscine_temp.sParam_Piscine, &sConfig_IHM.sParam_Piscine, sizeof(S_PARAM_PISCINE));
}

void InstallationView::bouton_mem_config_ecs()
{
    memcpy(&sParam_ECS_temp, &sConfig_IHM.sParam_ECS, sizeof(S_PARAM_ECS));
}

void InstallationView::bouton_modif_code()
{
	eCode = MODIF_CODE_INSTALL;
	application().gotoCode_numeriqueScreenNoTransition();
}

void InstallationView::bouton_retour()
{
	if(bMaintenanceDepuisUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else application().gotoConfigurationScreenNoTransition();
}

void InstallationView::bouton_raz_config()
{
	eOuiNon = OUI_NON_RAZ_CONF_INSTALL;
	application().gotoPage_oui_nonScreenNoTransition();
}

void InstallationView::bouton_freecooling()
{
	eOuiNon = OUI_NON_FREECOOLING;
	application().gotoPage_oui_nonScreenNoTransition();
}

void InstallationView::bouton_dalle()
{
	eOuiNon = OUI_NON_CHAUFFE_DALLE;
	application().gotoPage_oui_nonScreenNoTransition();
}

void InstallationView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	// Bouton freecooling
	if((sConfig_IHM->sModele_PAC.u8ModelePAC != sConfig_IHM_old.sModele_PAC.u8ModelePAC) || (sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV && sConfig_IHM->sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid != sConfig_IHM_old.sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid) || (sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA && sConfig_IHM->sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid != sConfig_IHM_old.sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid))
	{
		if(sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV && sConfig_IHM->sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid == 0)
		{
			container_freecooling.setVisible(true);
		}
		else if(sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA && sConfig_IHM->sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid == 0)
		{
			container_freecooling.setVisible(true);
		}
		else container_freecooling.setVisible(false);
		container_freecooling.invalidate();
	}
	// bouton cicuit captage
	if(sConfig_IHM->sModele_PAC.u8ModelePAC != sConfig_IHM_old.sModele_PAC.u8ModelePAC)
	{
		if(sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV || sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA|| sConfig_IHM->sModele_PAC.u8ModelePAC == ARKTEA)
		{
			container_param_circuit_captage.setVisible(true);
		}
		else container_param_circuit_captage.setVisible(false);
		container_param_circuit_captage.invalidate();
	}
	// bouton mise en chauffe dalle
	if(sConfig_IHM->sParam_PAC.TypeRegul != sConfig_IHM_old.sParam_PAC.TypeRegul)
	{
		if(sConfig_IHM->sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_MULTI_ZONE)
		{
			container_mise_chauffe_dalle.setVisible(true);
		}
		else container_mise_chauffe_dalle.setVisible(false);
		container_mise_chauffe_dalle.invalidate();
	}
	// ECS
	if(sConfig_IHM->sOption_PAC.ECS != sConfig_IHM_old.sOption_PAC.ECS)
	{
		if(sConfig_IHM->sOption_PAC.ECS)
		{
			buttonWithLabel_mode_ecs_on.setVisible(true);
		}
		else buttonWithLabel_mode_ecs_on.setVisible(false);
		buttonWithLabel_mode_ecs_on.invalidate();
	}
	// Piscine
	if(sConfig_IHM->sOption_PAC.Piscine != sConfig_IHM_old.sOption_PAC.Piscine)
	{
		if(sConfig_IHM->sOption_PAC.Piscine)
		{
			buttonWithLabel_mode_piscine_on.setVisible(true);
		}
		else buttonWithLabel_mode_piscine_on.setVisible(false);
		buttonWithLabel_mode_piscine_on.invalidate();
	}
	// Freecooling
	if((sConfig_IHM->sConfig_PAC.ConfigGeo.bFreecooling != sConfig_IHM_old.sConfig_PAC.ConfigGeo.bFreecooling) || (sConfig_IHM->sConfig_PAC.ConfigGeoInverter.bFreecooling != sConfig_IHM_old.sConfig_PAC.ConfigGeoInverter.bFreecooling))
	{
		if(sConfig_IHM->sConfig_PAC.ConfigGeo.bFreecooling && sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV)
		{
			buttonWithLabel_param_freecooling_on.setVisible(true);
		}
		else if(sConfig_IHM->sConfig_PAC.ConfigGeoInverter.bFreecooling && sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA)
		{
			buttonWithLabel_param_freecooling_on.setVisible(true);
		}
		else buttonWithLabel_param_freecooling_on.setVisible(false);
		buttonWithLabel_param_freecooling_on.invalidate();
	}
	// Circulateur primaire
	if((sConfig_IHM->sParam_PAC.bCirculateurPrimaireForce != sConfig_IHM_old.sParam_PAC.bCirculateurPrimaireForce) || (sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce != sConfig_IHM_old.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce))
	{
		if(sConfig_IHM->sParam_PAC.bCirculateurPrimaireForce && sConfig_IHM->sModele_PAC.u8ModelePAC <= GEOTWIN_IV)
		{
			buttonWithLabel_param_circ_prim_on.setVisible(true);
		}
		else if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce && sConfig_IHM->sModele_PAC.u8ModelePAC > GEOTWIN_IV)
		{
			buttonWithLabel_param_circ_prim_on.setVisible(true);
		}
		else buttonWithLabel_param_circ_prim_on.setVisible(false);
		buttonWithLabel_param_circ_prim_on.invalidate();
	}
	// Circualateur capteur
	if((sConfig_IHM->sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce != sConfig_IHM_old.sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce) || (sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce != sConfig_IHM_old.sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce))
	{
		if(sConfig_IHM->sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce && sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV)
		{
			buttonWithLabel_param_circ_capt_on.setVisible(true);
		}
		else if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce && sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA)
		{
			buttonWithLabel_param_circ_capt_on.setVisible(true);
		}
		else buttonWithLabel_param_circ_capt_on.setVisible(false);
		buttonWithLabel_param_circ_capt_on.invalidate();
	}
	// Wattmetre
	if(sConfig_IHM->sOption_PAC.CoeffComptagePW != sConfig_IHM_old.sOption_PAC.CoeffComptagePW)
	{
		if(sConfig_IHM->sOption_PAC.CoeffComptagePW)
		{
			buttonWithLabel_config_wattmetre_on.setVisible(true);
		}
		else buttonWithLabel_config_wattmetre_on.setVisible(false);
		buttonWithLabel_config_wattmetre_on.invalidate();
	}
	// Chauffe dalle
	if(sConfig_IHM->sParam_PAC.u8CTime_Sablier_Dalle_Jour != sConfig_IHM_old.sParam_PAC.u8CTime_Sablier_Dalle_Jour)
	{
		if(sConfig_IHM->sParam_PAC.u8CTime_Sablier_Dalle_Jour != 0)
		{
			buttonWithLabel_mise_chauffe_dalle_on.setVisible(true);
		}
		else buttonWithLabel_mise_chauffe_dalle_on.setVisible(false);
		buttonWithLabel_mise_chauffe_dalle_on.invalidate();
	}
	//
	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void InstallationView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void InstallationView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void InstallationView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void InstallationView::changeDate(S_DATE *sDate)
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
