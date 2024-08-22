#include <gui/accueil_screen/AccueilView.hpp>

AccueilView::AccueilView():
        swipeCallback(this, &AccueilView::swipeCallbackHandler)
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM));
	memset(&sStatut_Primaire_old, 0, sizeof(sStatut_Primaire));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC));
	memset(&sStatut_ECS_old, 0, sizeof(sStatut_ECS));
	memset(&sStatut_Piscine_old, 0, sizeof(sStatut_Piscine));
	memset(&sStatut_Zx_old, 0, sizeof(sStatut_Zx));
	memset(&sStatut_RegulExt_old, 0, sizeof(sStatut_RegulExt_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	u8Zone1 = 0xff;
	u8Zone2 = 0xff;
	u8NbZones = 0;
	bConnexionDistance = false;
	changeStatutPAC(&sStatut_PAC);
	changeDate(&sDate);
	changeConfig(&sConfig_IHM);
	changeErreur(u16ErreurEncours);
	changeStatutPrimaire(&sStatut_Primaire);
    changeStatutEther(&sCycEther);
    changeStatutECS(&sStatut_ECS);
    changeStatutPiscine(&sStatut_Piscine);
    changeStatutRegulExt(&sStatut_RegulExt);
    changeStatutCyclFrigo(&sCyclRegFrigo[0]);
    changeStatutZx(0, &sStatut_Zx[0]);
    changeStatutZx(1, &sStatut_Zx[1]);
    changeStatutZx(2, &sStatut_Zx[2]);
    changeStatutZx(3, &sStatut_Zx[3]);
    changeStatutZx(4, &sStatut_Zx[4]);
    changeStatutZx(5, &sStatut_Zx[5]);
    changeStatutZx(6, &sStatut_Zx[6]);
    changeStatutZx(7, &sStatut_Zx[7]);
	barre_titre.sansAccueil();
	barre_titre.sansRetour();
    swipeDetectContainerConfigurationScreen.setAction(swipeCallback);
}

void AccueilView::setupScreen()
{
    AccueilViewBase::setupScreen();
}

void AccueilView::tearDownScreen()
{
    AccueilViewBase::tearDownScreen();
}

void AccueilView::swipeCallbackHandler(int16_t velocity)
{
    if(velocity < 0)
    {
		application().gotoConfigurationScreenSlideTransitionEast();
    }
}

void AccueilView::Timer_500ms()
{
	uint16_t u16TmpBuffer[11];
	//
	if(sStatut_PAC_old.Mode_Secours != 0 || sStatut_PAC_old.Test != 0 || sDemandeFrigo.bShuntTempo != 0 || sStatut_PAC_old.sFonctInxTor.bTorEJP != 0 || sStatut_PAC_old.bDerogationPression != 0 || sStatut_PAC_old.bDerogationPressionBP != 0)
	{
		// Texte à afficher
		if(sStatut_PAC_old.Mode_Secours != 0)
		{
		    textArea_alerte.setTypedText(touchgfx::TypedText(T_TEXT_SECOURS_PAC_CENTRE_DEFAUT));
		}
		else if (sStatut_PAC_old.Test != 0)
		{
		    textArea_alerte.setTypedText(touchgfx::TypedText(T_TEXT_TEST_PAC_CENTRE_DEFAUT));
		}
		else if (sDemandeFrigo.bShuntTempo != 0)
		{
		    textArea_alerte.setTypedText(touchgfx::TypedText(T_TEXT_SHUNT_TEMPO_CENTRE_DEFAUT));
		}
		else if (sStatut_PAC_old.sFonctInxTor.bTorEJP != 0)
		{
		    textArea_alerte.setTypedText(touchgfx::TypedText(T_TEXT_EJP_CENTRE_DEFAUT));
		}
		else if (sStatut_PAC_old.bDerogationPression != 0)
		{
		    textArea_alerte.setTypedText(touchgfx::TypedText(T_TEXT_DEROG_PRESSION_CENTRE_DEFAUT));
		}
		else if (sStatut_PAC_old.bDerogationPressionBP != 0)
		{
		    textArea_alerte.setTypedText(touchgfx::TypedText(T_TEXT_DEROG_PRESSION_BP_CENTRE_DEFAUT));
		}
		// Clignottement du logo et de la zone de texte
		if(textArea_alerte.isVisible())
		{
			textArea_alerte.setVisible(false);
			textArea_alerte.invalidate();
			changeLogo(false);
		}
		else
		{
			textArea_alerte.setVisible(true);
			textArea_alerte.invalidate();
			changeLogo(true);
		}
	}
	else
	{
		textArea_alerte.setVisible(false);
		textArea_alerte.invalidate();
		changeLogo(true);
	}
	// Si multizones
	if(u8NbZones > 2)
	{
		// Zone suivante
		for(int i = (u8Zone1 + 1); i < ((u8Zone1 + 1) + NB_ZONE); i++)
		{
			if((i % NB_ZONE) == 0 && sConfig_IHM_old.sOption_PAC.sZone.bZone1)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 1 && sConfig_IHM_old.sOption_PAC.sZone.bZone2)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 2 && sConfig_IHM_old.sOption_PAC.sZone.bZone3)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 3 && sConfig_IHM_old.sOption_PAC.sZone.bZone4)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 4 && sConfig_IHM_old.sOption_PAC.sZone.bZone5)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 5 && sConfig_IHM_old.sOption_PAC.sZone.bZone6)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 6 && sConfig_IHM_old.sOption_PAC.sZone.bZone7)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
			else if((i % NB_ZONE) == 7 && sConfig_IHM_old.sOption_PAC.sZone.bZone8)
			{
				u8Zone1 = (i % NB_ZONE);
				break;
			}
		}
		// Modification de l'affichage
		// Nom de la zone
		for(int i = 0; i < 10; i++)
		{
			u16TmpBuffer[i] = sConfig_IHM_old.sParam_Zx[u8Zone1].u8NomZone[i];
		}
		Unicode::snprintf(textAreaBuffer_Zone_1, 11, "%s", u16TmpBuffer);
		textArea_zone_1.setWildcard(textAreaBuffer_Zone_1);
		textArea_zone_1.invalidate();
		//
		switch(sConfig_IHM_old.sParam_Zx[u8Zone1].u2RattachementGroupe)
		{
			case AUTONOME:
				button_marron_zone_1.setVisible(false);
				button_violet_zone_1.setVisible(false);
				break;
			case GROUPE_A:
				button_marron_zone_1.setVisible(false);
				button_violet_zone_1.setVisible(true);
				break;
			case GROUPE_B:
				button_marron_zone_1.setVisible(true);
				button_violet_zone_1.setVisible(false);
				break;
		}
		button_marron_zone_1.invalidate();
		button_violet_zone_1.invalidate();
		// Couleur de la demande et mode// Mode et demande de la zone
		switch(sStatut_Zx_old[u8Zone1].Mode)
		{
			case ARRET:
				circle_mode_zone_1Painter.setColor(BLANC);
				circle_demande_zone_1Painter.setColor(BLANC);
				break;
			case MARCHE_CHAUD:
			case AUTO_CHAUD:
			case HORS_GEL:
				circle_mode_zone_1Painter.setColor(ROUGE_CHAUD);
				if(sStatut_Zx_old[u8Zone1].i16ConsigneTeau != 0)
				{
					circle_demande_zone_1Painter.setColor(ROUGE_CHAUD);
				}
				else circle_demande_zone_1Painter.setColor(BLANC);
				break;
			case MARCHE_FROID:
			case AUTO_FROID:
				circle_mode_zone_1Painter.setColor(BLEU_FROID);
				if(sStatut_Zx_old[u8Zone1].i16ConsigneTeau != 0)
				{
					circle_demande_zone_1Painter.setColor(BLEU_FROID);
				}
				else circle_demande_zone_1Painter.setColor(BLANC);
				break;
		}
		circle_mode_zone_1.setPainter(circle_mode_zone_1Painter);
		circle_demande_zone_1.setPainter(circle_demande_zone_1Painter);
		circle_mode_zone_1.invalidate();
		circle_demande_zone_1.invalidate();
		//
		Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_1, 7, "%.1f", ((float) sStatut_Zx_old[u8Zone1].i16Tint) / 10);
		textArea_temp_zone_1.setWildcard(textAreaBuffer_Temp_Zone_1);
		textArea_temp_zone_1.invalidate();
	}
}

void AccueilView::changeLogo(bool bVisible)
{
	//
	Image_arkteos.setVisible(false);
	Image_alppac.setVisible(false);
//	Image_ces.setVisible(false);
//	Image_cfd.setVisible(false);
//	Image_enelia.setVisible(false);
//	Image_etienne_energies.setVisible(false);
//	Image_qualiclim.setVisible(false);
	//
	if(bVisible)
	{
		if(memcmp(sConfig_IHM.sInstall_PAC.CodeLogoClient, "CLIMDIFF3597", 12) == 0)
		{
			Image_alppac.setVisible(true);
		}
	//	else if(strcmp(sConfig_IHM.sInstall_PAC.CodeLogoClient, "CFD2366"))
	//	{
	//		Image_cfd.setVisible(true);
	//	}
	//	else
	//	if(strcmp(sConfig_IHM.sInstall_PAC.CodeLogoClient, "CES1718"))
	//	{
	//		Image_ces.setVisible(true);
	//	}
	//	else if(strcmp(sConfig_IHM.sInstall_PAC.CodeLogoClient, "ENELIA5664"))
	//	{
	//		Image_enelia.setVisible(true);
	//	}
	//	else if(strcmp(sConfig_IHM.sInstall_PAC.CodeLogoClient, "ETIENNE5796"))
	//	{
	//		Image_etienne_energies.setVisible(true);
	//	}
	//	else if(memcmp(sConfig_IHM.sInstall_PAC.CodeLogoClient, "QUALICLIM5129", ))
	//	{
	//		Image_qualiclim.setVisible(true);
	//	}
		else Image_arkteos.setVisible(true);
	}
	Image_arkteos.invalidate();
	Image_alppac.invalidate();
//	Image_ces.invalidate();
//	Image_cfd.invalidate();
//	Image_enelia.invalidate();
//	Image_etienne_energies.invalidate();
//	Image_qualiclim.invalidate();
}

void AccueilView::bouton_marche_arret()
{
	if(container_marche.isVisible())
	{
		eOuiNon = OUI_NON_ARRET_GENERAL;
	}
	else eOuiNon = OUI_NON_MARCHE_GENERAL;
	application().gotoPage_oui_nonScreenNoTransition();
}

void AccueilView::bouton_zone_1()
{
	if(u8NbZones > 2 && sConfig_IHM_old.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE)
	{
		application().gotoMultizonesScreenNoTransition();
	}
	else application().gotoZoneScreenNoTransition();
}

void AccueilView::changeModePac(bool marche)
{
//  container_marche.setVisible(marche);
//  container_marche.invalidate();
}

void AccueilView::changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire)
{
	if(sStatut_Primaire_old.u16In_Pression_Eau != sStatut_Primaire->u16In_Pression_Eau)
	{
	    Unicode::snprintfFloat(textAreaBuffer_Pression, 7, "%.1f", ((float) sStatut_Primaire->u16In_Pression_Eau) / 10);
	    textArea_pression.setWildcard(textAreaBuffer_Pression);
	    textArea_pression.invalidate();
	    textArea_pression_chauf.setWildcard(textAreaBuffer_Pression);
	    textArea_pression_chauf.invalidate();
	}

	//
	if(sConfig_IHM_old.sParam_PAC.TypeRegul >= REGUL_EXTERNE && sStatut_Primaire_old.i16TeauBallonTampon != sStatut_Primaire->i16TeauBallonTampon)
	{
		Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_1, 7, "%.1f", ((float) sStatut_Primaire->i16TeauBallonTampon) / 10);
		textArea_temp_zone_1.setWildcard(textAreaBuffer_Temp_Zone_1);
		textArea_temp_zone_1.invalidate();
	}
	memcpy(&sStatut_Primaire_old, sStatut_Primaire, sizeof(S_STATUT_PRIMAIRE));
}

void AccueilView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	// Icone état appoint
	if(sStatut_PAC_old.Appoint != sStatut_PAC->Appoint)
	{
		switch(sStatut_PAC->Appoint)
		{
			case RELEVE_CHAUDIERE:
			case APPOINT_CHAUDIERE:
				scalableImage_appoint.setVisible(false);
				scalableImage_chaudiere.setVisible(true);
				break;
			case ELEC:
				scalableImage_appoint.setVisible(true);
				scalableImage_chaudiere.setVisible(false);
				break;
			default:
				scalableImage_appoint.setVisible(false);
				scalableImage_chaudiere.setVisible(false);
				break;
		}
		scalableImage_appoint.invalidate();
		scalableImage_chaudiere.invalidate();
	}
	// Icone état exception
	if(sStatut_PAC_old.Exception != sStatut_PAC->Exception)
	{
		switch(sStatut_PAC->Exception)
		{
			case S_VACANCES:
				scalableImage_vacances.setVisible(true);
				scalableImage_legionel.setVisible(false);
				scalableImage_sablier.setVisible(false);
				scalableImage_dalle.setVisible(false);
				break;
			case S_DALLE:
				scalableImage_vacances.setVisible(false);
				scalableImage_legionel.setVisible(false);
				scalableImage_sablier.setVisible(false);
				scalableImage_dalle.setVisible(true);
				break;
			case S_LEGIONEL:
				scalableImage_vacances.setVisible(false);
				scalableImage_legionel.setVisible(true);
				scalableImage_sablier.setVisible(false);
				scalableImage_dalle.setVisible(false);
				break;
			case S_SABLIER:
				scalableImage_vacances.setVisible(false);
				scalableImage_legionel.setVisible(false);
				scalableImage_sablier.setVisible(true);
				scalableImage_dalle.setVisible(false);
				break;
			default:
				scalableImage_vacances.setVisible(false);
				scalableImage_legionel.setVisible(false);
				scalableImage_sablier.setVisible(false);
				scalableImage_dalle.setVisible(false);
				break;
		}
		scalableImage_vacances.invalidate();
		scalableImage_legionel.invalidate();
		scalableImage_sablier.invalidate();
		scalableImage_dalle.invalidate();
	}
	// Icone état
	if(sStatut_PAC_old.S_Mode != sStatut_PAC->S_Mode)
	{
		switch(sStatut_PAC->S_Mode)
		{
			case S_ARRET:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					scalableImage_ecs.setVisible(true);
					scalableImage_piscine.setVisible(true);
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					scalableImage_ecs.setVisible(true);
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					scalableImage_piscine.setVisible(true);
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
			case S_ATTENTE:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					scalableImage_ecs.setVisible(true);
					scalableImage_piscine.setVisible(true);
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					scalableImage_ecs.setVisible(true);
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					scalableImage_piscine.setVisible(true);
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
			case S_CHAUD:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					scalableImage_maison_etat.setPosition(211, 417, 67, 58);
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Simu_ECS_Pisc");
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Chauffe_Eau");
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Piscine");
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
			case S_FROID:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Simu_ECS_Pisc");
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Chauffe_Eau");
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Piscine");
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
			case S_HORS_GEL:
//				// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Regul_Ajtech_Hors_Gel");
				break;
			case S_EXT_CHAUD:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Simu_ECS_Pisc");
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Chauffe_Eau");
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Piscine");
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
			case S_EXT_FROID:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Simu_ECS_Pisc");
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Chauffe_Eau");
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Piscine");
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
			case S_CHAUD_FROID:
				if((sStatut_PAC->S_Mode & S_ECS) && (sStatut_PAC->S_Mode & S_PISCINE) == S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Simu_ECS_Pisc");
				}
				else if(sStatut_PAC->S_Mode & S_ECS)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Chauffe_Eau");
				}
				else if(sStatut_PAC->S_Mode & S_PISCINE)
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Piscine");
				}
				else
				{
					// secondColumnLeftWidget = getBackground("Picto_Etat_L55xh39_Arret");
				}
				break;
		}
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void AccueilView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void AccueilView::changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine)
{
	if(sStatut_Piscine_old.i16TeauPiscine != sStatut_Piscine->i16TeauPiscine)
	{
		Unicode::snprintfFloat(textAreaBuffer_Piscine, 7, "%.1f", ((float) sStatut_Piscine->i16TeauPiscine) / 10);
		textArea_temp_piscine.setWildcard(textAreaBuffer_Piscine);
		textArea_temp_piscine.invalidate();
	}
	memcpy(&sStatut_Piscine_old, sStatut_Piscine, sizeof(S_STATUT_PISCINE));
}

void AccueilView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	// Température extérieure
	if(sCyclRegFrigo_old.commun.i16Text != sCyclRegFrigo->commun.i16Text)
	{
	    Unicode::snprintfFloat(textAreaBuffer_Temp_Ext, 7, "%.1f", ((float) sCyclRegFrigo->commun.i16Text) / 10);
	    textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
	    textArea_temp_ext.invalidate();
	}
	// Pression capteur
	if(sConfig_IHM_old.sModele_PAC.u8ModelePAC == GEOTWIN_IV && sCyclRegFrigo_old.pac.geotwin.InPress.i16Pression_EauCaptage != sCyclRegFrigo->pac.geotwin.InPress.i16Pression_EauCaptage)
	{
	    Unicode::snprintfFloat(textAreaBuffer_Pression_Capt, 7, "%.1f", ((float) sCyclRegFrigo->pac.geotwin.InPress.i16Pression_EauCaptage) / 10);
	    textArea_pression_capt.setWildcard(textAreaBuffer_Pression_Capt);
	    textArea_pression_capt.invalidate();
	}
	else if(sConfig_IHM_old.sModele_PAC.u8ModelePAC == INVERTERRA && sCyclRegFrigo_old.pac.geoinverter.sInAnaGeoinv.i16Press_EauCapteur != sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_EauCapteur)
	{
	    Unicode::snprintfFloat(textAreaBuffer_Pression_Capt, 7, "%.1f", ((float) sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_EauCapteur) / 10);
	    textArea_pression_capt.setWildcard(textAreaBuffer_Pression_Capt);
	    textArea_pression_capt.invalidate();
	}
	// Mémorisation de l'état précédent
	memcpy(&sCyclRegFrigo_old, sCyclRegFrigo, sizeof(S_CYCL_REG_FRI));
}

void AccueilView::changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx)
{
	if(sConfig_IHM_old.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_MULTI_ZONE)
	{
		if(u8Zone == u8Zone1)
		{
			// Mode et demande de la zone
			if((sStatut_Zx_old[u8Zone].Mode != sStatut_Zx->Mode) || (sStatut_Zx_old[u8Zone].Exception != sStatut_Zx->Exception))
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						circle_mode_zone_1Painter.setColor(BLANC);
						circle_demande_zone_1Painter.setColor(BLANC);
						break;
					case MARCHE_CHAUD:
					case AUTO_CHAUD:
					case HORS_GEL:
						circle_mode_zone_1Painter.setColor(ROUGE_CHAUD);
						if(sStatut_Zx->i16ConsigneTeau != 0)
						{
							circle_demande_zone_1Painter.setColor(ROUGE_CHAUD);
						}
						else circle_demande_zone_1Painter.setColor(BLANC);
						break;
					case MARCHE_FROID:
					case AUTO_FROID:
						circle_mode_zone_1Painter.setColor(BLEU_FROID);
						if(sStatut_Zx->i16ConsigneTeau != 0)
						{
							circle_demande_zone_1Painter.setColor(BLEU_FROID);
						}
						else circle_demande_zone_1Painter.setColor(BLANC);
						break;
				}
				circle_mode_zone_1.setPainter(circle_mode_zone_1Painter);
				circle_demande_zone_1.setPainter(circle_demande_zone_1Painter);
				circle_mode_zone_1.invalidate();
				circle_demande_zone_1.invalidate();
			}
			//
			if(sStatut_Zx_old[u8Zone].i16Tint != sStatut_Zx->i16Tint)
			{
				Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_1, 7, "%.1f", ((float) sStatut_Zx->i16Tint) / 10);
				textArea_temp_zone_1.setWildcard(textAreaBuffer_Temp_Zone_1);
				textArea_temp_zone_1.invalidate();
			}
		}
		else if(u8Zone == u8Zone2)
		{
			// Mode et demande de la zone
			if((sStatut_Zx_old[u8Zone].Mode != sStatut_Zx->Mode) || (sStatut_Zx_old[u8Zone].Exception != sStatut_Zx->Exception))
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						circle_mode_zone_2Painter.setColor(BLANC);
						circle_demande_zone_2Painter.setColor(BLANC);
						break;
					case MARCHE_CHAUD:
					case AUTO_CHAUD:
					case HORS_GEL:
						circle_mode_zone_2Painter.setColor(ROUGE_CHAUD);
						if(sStatut_Zx->i16ConsigneTeau != 0)
						{
							circle_demande_zone_2Painter.setColor(ROUGE_CHAUD);
						}
						else circle_demande_zone_2Painter.setColor(BLANC);
						break;
					case MARCHE_FROID:
					case AUTO_FROID:
						circle_mode_zone_2Painter.setColor(BLEU_FROID);
						if(sStatut_Zx->i16ConsigneTeau != 0)
						{
							circle_demande_zone_2Painter.setColor(BLEU_FROID);
						}
						else circle_demande_zone_2Painter.setColor(BLANC);
						break;
				}
				circle_mode_zone_2.setPainter(circle_mode_zone_2Painter);
				circle_demande_zone_2.setPainter(circle_demande_zone_2Painter);
				circle_mode_zone_2.invalidate();
				circle_demande_zone_2.invalidate();
			}
			//
			if(sStatut_Zx_old[u8Zone].i16Tint != sStatut_Zx->i16Tint)
			{
				Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_2, 7, "%.1f", ((float) sStatut_Zx->i16Tint) / 10);
				textArea_temp_zone_2.setWildcard(textAreaBuffer_Temp_Zone_2);
				textArea_temp_zone_2.invalidate();
			}
		}
	}
	// Mémorisation de l'état précédent
	memcpy(&sStatut_Zx_old[u8Zone], sStatut_Zx, sizeof(S_STATUT_ZX));
}

void AccueilView::changeStatutRegulExt(S_STATUT_REG_EXT *sStatut_RegulExt)
{
	if(sConfig_IHM_old.sParam_PAC.TypeRegul >= REGUL_EXTERNE)
	{
		// Mode et demande de la zone
		if((sStatut_RegulExt_old.Mode != sStatut_Zx->Mode) || (sStatut_RegulExt_old.Exception != sStatut_Zx->Exception))
		{
			switch(sStatut_RegulExt->Mode)
			{
				case ARRET:
					circle_mode_zone_1Painter.setColor(BLANC);
					circle_demande_zone_1Painter.setColor(BLANC);
					break;
				case MARCHE_CHAUD:
				case AUTO_CHAUD:
				case HORS_GEL:
					circle_mode_zone_1Painter.setColor(ROUGE_CHAUD);
					if(sStatut_RegulExt->i16ConsigneTeau != 0)
					{
						circle_demande_zone_1Painter.setColor(ROUGE_CHAUD);
					}
					else circle_demande_zone_1Painter.setColor(BLANC);
					break;
				case MARCHE_FROID:
				case AUTO_FROID:
					circle_mode_zone_1Painter.setColor(BLEU_FROID);
					if(sStatut_RegulExt->i16ConsigneTeau != 0)
					{
						circle_demande_zone_1Painter.setColor(BLEU_FROID);
					}
					else circle_demande_zone_1Painter.setColor(BLANC);
					break;
			}
			circle_mode_zone_1.setPainter(circle_mode_zone_1Painter);
			circle_demande_zone_1.setPainter(circle_demande_zone_1Painter);
			circle_mode_zone_1.invalidate();
			circle_demande_zone_1.invalidate();
		}
	}
	// Mémorisation de l'état précédent
	memcpy(&sStatut_RegulExt_old, sStatut_RegulExt, sizeof(S_STATUT_ZX));
}

void AccueilView::changeStatutECS(S_STATUT_ECS *sStatut_ECS)
{
	if(sStatut_ECS_old.bOutTor_Spare1 != sStatut_ECS->bOutTor_Spare1)
	{
		if(sStatut_ECS->bOutTor_Spare1)
		{
			Image_bouclage_ecs.setVisible(true);
		}
		else Image_bouclage_ecs.setVisible(false);
		Image_bouclage_ecs.invalidate();
	}
	if(sStatut_ECS_old.i16TeauMilieu != sStatut_ECS->i16TeauMilieu)
	{
		Unicode::snprintfFloat(textAreaBuffer_ECS_Milieu, 7, "%.1f", ((float) sStatut_ECS->i16TeauMilieu) / 10);
		textArea_temp_ecs.setWildcard(textAreaBuffer_ECS_Milieu);
		textArea_temp_ecs.invalidate();
		textArea_ecs_milieu.setWildcard(textAreaBuffer_ECS_Milieu);
		textArea_ecs_milieu.invalidate();
	}
	if(sStatut_ECS_old.i16TeauBas != sStatut_ECS->i16TeauBas)
	{
		Unicode::snprintfFloat(textAreaBuffer_ECS_Bas, 7, "%.1f", ((float) sStatut_ECS->i16TeauBas) / 10);
		textArea_ecs_bas.setWildcard(textAreaBuffer_ECS_Bas);
		textArea_ecs_bas.invalidate();
	}
	memcpy(&sStatut_ECS_old, sStatut_ECS, sizeof(S_STATUT_ECS));
}

void AccueilView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void AccueilView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	uint16_t u16TmpBuffer[11];
	if(sConfig_IHM->sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_MULTI_ZONE)
	{
		// Bouton zones
		if(memcmp(&sConfig_IHM_old.sOption_PAC.sZone, &sConfig_IHM->sOption_PAC.sZone, sizeof(S_ZONE)) || sConfig_IHM_old.sParam_PAC.TypeRegul != sConfig_IHM->sParam_PAC.TypeRegul)
		{
			u8NbZones = sConfig_IHM->sOption_PAC.sZone.bZone1 +
						sConfig_IHM->sOption_PAC.sZone.bZone2 +
						sConfig_IHM->sOption_PAC.sZone.bZone3 +
						sConfig_IHM->sOption_PAC.sZone.bZone4 +
						sConfig_IHM->sOption_PAC.sZone.bZone5 +
						sConfig_IHM->sOption_PAC.sZone.bZone6 +
						sConfig_IHM->sOption_PAC.sZone.bZone7 +
						sConfig_IHM->sOption_PAC.sZone.bZone8;
			// Zone 1
			if((u8NbZones == 1 && sConfig_IHM->sOption_PAC.sZone.bZone2 == 0) || u8NbZones >= 2)
			{
				Image_maison_zone_1.setVisible(true);
				container_zone_1.setVisible(true);
			}
			else container_zone_1.setVisible(false);
			container_zone_1.invalidate();
			// Zone 2
			if(u8NbZones == 2 || (u8NbZones == 1 && sConfig_IHM->sOption_PAC.sZone.bZone2))
			{
				container_zone_2.setVisible(true);
			}
			else container_zone_2.setVisible(false);
			container_zone_2.invalidate();
			// Définition de la zone
			if(u8NbZones <= 2)
			{
				if(sConfig_IHM->sOption_PAC.sZone.bZone1)
				{
					u8Zone1 = 0;
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone2)
				{
					if(u8NbZones == 1)
					{
						u8Zone2 = 1;
					}
					else if(u8Zone1 == 0xff)
					{
						u8Zone1 = 1;
					}
					else
					{
						u8Zone2 = 1;
					}
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone3)
				{
					if(u8Zone1 == 0xff)
					{
						u8Zone1 = 2;
					}
					else
					{
						u8Zone2 = 2;
					}
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone4)
				{
					if(u8Zone1 == 0xff)
					{
						u8Zone1 = 3;
					}
					else
					{
						u8Zone2 = 3;
					}
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone5)
				{
					if(u8Zone1 == 0xff)
					{
						u8Zone1 = 4;
					}
					else
					{
						u8Zone2 = 4;
					}
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone6)
				{
					if(u8Zone1 == 0xff)
					{
						u8Zone1 = 5;
					}
					else
					{
						u8Zone2 = 5;
					}
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone7)
				{
					if(u8Zone1 == 0xff)
					{
						u8Zone1 = 6;
					}
					else
					{
						u8Zone2 = 6;
					}
				}
				if(sConfig_IHM->sOption_PAC.sZone.bZone8)
				{
					if(u8Zone1 == 0xff)
					{
						u8Zone1 = 7;
					}
					else
					{
						u8Zone2 = 7;
					}
				}
			}
			else if(u8Zone1 == 0xff)
			{
				u8Zone1 = 0;
			}
		}
		// Affichage de la zone 1
		if(memcmp(&sConfig_IHM_old.sParam_Zx[u8Zone1], &sConfig_IHM->sParam_Zx[u8Zone1], sizeof(S_PARAM_ZX)))
		{
			// Nom de la zone
			for(int i = 0; i < 10; i++)
			{
				u16TmpBuffer[i] = sConfig_IHM->sParam_Zx[u8Zone1].u8NomZone[i];
			}
			Unicode::snprintf(textAreaBuffer_Zone_1, 11, "%s", u16TmpBuffer);
			textArea_zone_1.setWildcard(textAreaBuffer_Zone_1);
			textArea_zone_1.invalidate();
			//
			switch(sConfig_IHM->sParam_Zx[u8Zone1].u2RattachementGroupe)
			{
				case AUTONOME:
					button_marron_zone_1.setVisible(false);
					button_violet_zone_1.setVisible(false);
					break;
				case GROUPE_A:
					button_marron_zone_1.setVisible(false);
					button_violet_zone_1.setVisible(true);
					break;
				case GROUPE_B:
					button_marron_zone_1.setVisible(true);
					button_violet_zone_1.setVisible(false);
					break;
			}
			button_marron_zone_1.invalidate();
			button_violet_zone_1.invalidate();
			// Mode et demande de la zone
			if((sStatut_Zx_old[u8Zone1].Mode != sStatut_Zx->Mode) || (sStatut_Zx_old[u8Zone1].Exception != sStatut_Zx->Exception))
			{
				switch(sStatut_Zx_old[u8Zone1].Mode)
				{
					case ARRET:
						circle_mode_zone_1Painter.setColor(BLANC);
						circle_demande_zone_1Painter.setColor(BLANC);
						break;
					case MARCHE_CHAUD:
					case AUTO_CHAUD:
					case HORS_GEL:
						circle_mode_zone_1Painter.setColor(ROUGE_CHAUD);
						if(sStatut_Zx_old[u8Zone1].i16ConsigneTeau != 0)
						{
							circle_demande_zone_1Painter.setColor(ROUGE_CHAUD);
						}
						else circle_demande_zone_1Painter.setColor(BLANC);
						break;
					case MARCHE_FROID:
					case AUTO_FROID:
						circle_mode_zone_1Painter.setColor(BLEU_FROID);
						if(sStatut_Zx_old[u8Zone1].i16ConsigneTeau != 0)
						{
							circle_demande_zone_1Painter.setColor(BLEU_FROID);
						}
						else circle_demande_zone_1Painter.setColor(BLANC);
						break;
				}
				circle_mode_zone_1.setPainter(circle_mode_zone_1Painter);
				circle_demande_zone_1.setPainter(circle_demande_zone_1Painter);
				circle_mode_zone_1.invalidate();
				circle_demande_zone_1.invalidate();
			}
			Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_1, 7, "%.1f", ((float) sStatut_Zx_old[u8Zone1].i16Tint) / 10);
			textArea_temp_zone_1.setWildcard(textAreaBuffer_Temp_Zone_1);
			textArea_temp_zone_1.invalidate();
		}
		// Affichage de la zone 2
		if(memcmp(&sConfig_IHM_old.sParam_Zx[u8Zone2], &sConfig_IHM->sParam_Zx[u8Zone2], sizeof(S_PARAM_ZX)))
		{
			for(int i = 0; i < 10; i++)
			{
				u16TmpBuffer[i] = sConfig_IHM->sParam_Zx[u8Zone2].u8NomZone[i];
			}
			Unicode::snprintf(textAreaBuffer_Zone_2, 11, "%s", u16TmpBuffer);
			textArea_zone_2.setWildcard(textAreaBuffer_Zone_2);
			textArea_zone_2.invalidate();
			//
			switch(sConfig_IHM->sParam_Zx[u8Zone2].u2RattachementGroupe)
			{
				case AUTONOME:
					button_marron_zone_2.setVisible(false);
					button_violet_zone_2.setVisible(false);
					break;
				case GROUPE_A:
					button_marron_zone_2.setVisible(false);
					button_violet_zone_2.setVisible(true);
					break;
				case GROUPE_B:
					button_marron_zone_2.setVisible(true);
					button_violet_zone_2.setVisible(false);
					break;
			}
			button_marron_zone_2.invalidate();
			button_violet_zone_2.invalidate();
			// Mode et demande de la zone
			switch(sStatut_Zx_old[u8Zone2].Mode)
			{
				case ARRET:
					circle_mode_zone_2Painter.setColor(BLANC);
					circle_demande_zone_2Painter.setColor(BLANC);
					break;
				case MARCHE_CHAUD:
				case AUTO_CHAUD:
				case HORS_GEL:
					circle_mode_zone_2Painter.setColor(ROUGE_CHAUD);
					if(sStatut_Zx_old[u8Zone2].i16ConsigneTeau != 0)
					{
						circle_demande_zone_2Painter.setColor(ROUGE_CHAUD);
					}
					else circle_demande_zone_2Painter.setColor(BLANC);
					break;
				case MARCHE_FROID:
				case AUTO_FROID:
					circle_mode_zone_2Painter.setColor(BLEU_FROID);
					if(sStatut_Zx_old[u8Zone2].i16ConsigneTeau != 0)
					{
						circle_demande_zone_2Painter.setColor(BLEU_FROID);
					}
					else circle_demande_zone_2Painter.setColor(BLANC);
					break;
			}
			circle_mode_zone_2.setPainter(circle_mode_zone_2Painter);
			circle_demande_zone_2.setPainter(circle_demande_zone_2Painter);
			circle_mode_zone_2.invalidate();
			circle_demande_zone_2.invalidate();
			Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_2, 7, "%.1f", ((float) sStatut_Zx_old[u8Zone2].i16Tint) / 10);
			textArea_temp_zone_2.setWildcard(textAreaBuffer_Temp_Zone_2);
			textArea_temp_zone_2.invalidate();
		}
	}
	else
	{
		if(sConfig_IHM_old.sParam_PAC.TypeRegul != sConfig_IHM->sParam_PAC.TypeRegul)
		{
			u8Zone1 = u8Zone2 = 0xff;
			// Affichage du texte adapté
			Unicode::snprintf(textAreaBuffer_Zone_1, 11, touchgfx::TypedText(T_TEXT_TEMP_BALLON_EXTERNE_CENTRE_DEFAUT).getText());
			textArea_zone_1.setWildcard(textAreaBuffer_Zone_1);
			textArea_zone_1.invalidate();
			Unicode::snprintfFloat(textAreaBuffer_Temp_Zone_1, 7, "%.1f", ((float) sStatut_Primaire_old.i16TeauBallonTampon) / 10);
			textArea_temp_zone_1.setWildcard(textAreaBuffer_Temp_Zone_1);
			textArea_temp_zone_1.invalidate();
			// Affichage d'une zone uniquement
			Image_maison_zone_1.setVisible(false);
			button_marron_zone_1.setVisible(false);
			button_violet_zone_1.setVisible(false);
			container_zone_1.setVisible(true);
			container_zone_1.invalidate();
			container_zone_2.setVisible(false);
			container_zone_2.invalidate();
			// Mode et demande de la zone
			if((sStatut_RegulExt_old.Mode != sStatut_Zx->Mode) || (sStatut_RegulExt_old.Exception != sStatut_Zx->Exception))
			{
				switch(sStatut_RegulExt_old.Mode)
				{
					case ARRET:
						circle_mode_zone_1Painter.setColor(BLANC);
						circle_demande_zone_1Painter.setColor(BLANC);
						break;
					case MARCHE_CHAUD:
					case AUTO_CHAUD:
					case HORS_GEL:
						circle_mode_zone_1Painter.setColor(ROUGE_CHAUD);
						if(sStatut_RegulExt_old.i16ConsigneTeau != 0)
						{
							circle_demande_zone_1Painter.setColor(ROUGE_CHAUD);
						}
						else circle_demande_zone_1Painter.setColor(BLANC);
						break;
					case MARCHE_FROID:
					case AUTO_FROID:
						circle_mode_zone_1Painter.setColor(BLEU_FROID);
						if(sStatut_RegulExt_old.i16ConsigneTeau != 0)
						{
							circle_demande_zone_1Painter.setColor(BLEU_FROID);
						}
						else circle_demande_zone_1Painter.setColor(BLANC);
						break;
				}
				circle_mode_zone_1.setPainter(circle_mode_zone_1Painter);
				circle_demande_zone_1.setPainter(circle_demande_zone_1Painter);
				circle_mode_zone_1.invalidate();
				circle_demande_zone_1.invalidate();
			}
		}
	}
	// Bouton ECS
	if(sConfig_IHM_old.sOption_PAC.ECS != sConfig_IHM->sOption_PAC.ECS)
	{
		if(sConfig_IHM->sOption_PAC.ECS != 0)
		{
			container_ecs.setVisible(true);
			container_statut_ecs.setVisible(true);
		}
		else
		{
			container_ecs.setVisible(false);
			container_statut_ecs.setVisible(false);
		}
		container_ecs.invalidate();
		container_statut_ecs.invalidate();
	}
	// Bouton piscine
	if(sConfig_IHM_old.sOption_PAC.Piscine != sConfig_IHM->sOption_PAC.Piscine)
	{
		if(sConfig_IHM->sOption_PAC.Piscine != 0)
		{
			container_piscine.setVisible(true);
		}
		else container_piscine.setVisible(false);
		container_piscine.invalidate();
	}
	// Bouton marche
	if(sConfig_IHM_old.sMode_PAC.bEtatPAC != sConfig_IHM->sMode_PAC.bEtatPAC)
	{
		if(sConfig_IHM->sMode_PAC.bEtatPAC != 0)
		{
			container_marche.setVisible(true);
		}
		else container_marche.setVisible(false);
		container_marche.invalidate();
	}
	// Logo pression eau
	if(sConfig_IHM_old.sModele_PAC.u8ModelePAC != sConfig_IHM->sModele_PAC.u8ModelePAC)
	{
		switch(sConfig_IHM->sModele_PAC.u8ModelePAC)
		{
			case GEOTWIN_IV:
			case INVERTERRA:
				container_pression_geo.setVisible(true);
				container_pression_aero.setVisible(false);
				break;
			default:
				container_pression_geo.setVisible(false);
				container_pression_aero.setVisible(true);
				break;
		}
		container_pression_geo.invalidate();
		container_pression_aero.invalidate();
	}
	// Gestion logo
	if(memcmp(sConfig_IHM_old.sInstall_PAC.CodeLogoClient, sConfig_IHM->sInstall_PAC.CodeLogoClient, sizeof(sConfig_IHM_old.sInstall_PAC.CodeLogoClient)))
	{
		changeLogo(true);
	}
	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void AccueilView::changeDate(S_DATE *sDate)
{
	uint32_t u32Mois, u32Jour;

	if(sDate_old.Date != sDate->Date)
	{
		// Affichage de la date
	    Unicode::snprintf(textAreaBuffer_Date, 9, "%02d/%02d/%02d", sDate->Date, sDate->Month, sDate->Year);
	    barre_titre.date(textAreaBuffer_Date);
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
		// Affichage du titre
	    switch(sDate->WeekDay)
		{
			default:
				u32Jour = T_TEXT_LUNDI_CENTRE_LARGE;
				break;
			case 1:
				u32Jour = T_TEXT_MARDI_CENTRE_LARGE;
				break;
			case 2:
				u32Jour = T_TEXT_MERCREDI_CENTRE_LARGE;
				break;
			case 3:
				u32Jour = T_TEXT_JEUDI_CENTRE_LARGE;
				break;
			case 4:
				u32Jour = T_TEXT_VENDREDI_CENTRE_LARGE;
				break;
			case 5:
				u32Jour = T_TEXT_SAMEDI_CENTRE_LARGE;
				break;
			case 6:
				u32Jour = T_TEXT_DIMANCHE_CENTRE_LARGE;
				break;
		}
	    switch(sDate->Month)
		{
			default:
				u32Mois = T_TEXT_MOIS_JANVIER_CENTRE_LARGE;
				break;
			case 2:
				u32Mois = T_TEXT_MOIS_FEVRIER_CENTRE_LARGE;
				break;
			case 3:
				u32Mois = T_TEXT_MOIS_MARS_CENTRE_LARGE;
				break;
			case 4:
				u32Mois = T_TEXT_MOIS_AVRIL_CENTRE_LARGE;
				break;
			case 5:
				u32Mois = T_TEXT_MOIS_MAI_CENTRE_LARGE;
				break;
			case 6:
				u32Mois = T_TEXT_MOIS_JUIN_CENTRE_LARGE;
				break;
			case 7:
				u32Mois = T_TEXT_MOIS_JUILLET_CENTRE_LARGE;
				break;
			case 8:
				u32Mois = T_TEXT_MOIS_AOUT_CENTRE_LARGE;
				break;
			case 9:
				u32Mois = T_TEXT_MOIS_SEPTEMBRE_CENTRE_LARGE;
				break;
			case 10:
				u32Mois = T_TEXT_MOIS_OCTOBRE_CENTRE_LARGE;
				break;
			case 11:
				u32Mois = T_TEXT_MOIS_NOVEMBRE_CENTRE_LARGE;
				break;
			case 12:
				u32Mois = T_TEXT_MOIS_DECEMBRE_CENTRE_LARGE;
				break;
		}
	    Unicode::snprintf(textAreaBuffer_Titre, 30, "%s %d %s 20%02d", touchgfx::TypedText(u32Jour).getText(), sDate->Date, touchgfx::TypedText(u32Mois).getText(), sDate->Year);
	    barre_titre.titre(textAreaBuffer_Titre);
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
