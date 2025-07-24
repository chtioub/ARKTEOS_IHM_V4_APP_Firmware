#include <gui/multizones_screen/MultizonesView.hpp>

MultizonesView::MultizonesView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	memset(&sStatut_Zx_old, 0, sizeof(sStatut_Zx));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, "");
	barre_titre.titre(textAreaBuffer_Titre);
}

void MultizonesView::setupScreen()
{
    MultizonesViewBase::setupScreen();
}

void MultizonesView::tearDownScreen()
{
    MultizonesViewBase::tearDownScreen();
}

void MultizonesView::bouton_zone_1()
{
	u8ZoneSelect = u8ZoneCorrespondante[0];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_2()
{
	u8ZoneSelect = u8ZoneCorrespondante[1];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_3()
{
	u8ZoneSelect = u8ZoneCorrespondante[2];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_4()
{
	u8ZoneSelect = u8ZoneCorrespondante[3];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_5()
{
	u8ZoneSelect = u8ZoneCorrespondante[4];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_6()
{
	u8ZoneSelect = u8ZoneCorrespondante[5];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_7()
{
	u8ZoneSelect = u8ZoneCorrespondante[6];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::bouton_zone_8()
{
	u8ZoneSelect = u8ZoneCorrespondante[7];
	application().gotoZoneScreenNoTransition();
}

void MultizonesView::changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx)
{
	if(u8Zone == u8ZoneCorrespondante[0])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[0]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[0], &sStatut_Zx[u8ZoneCorrespondante[0]], &circle_demande_zone_1, &circle_demande_zone_1Painter, &circle_mode_zone_1, &circle_mode_zone_1Painter, &textArea_temp_zone_1, textAreaBuffer_Temp_Zone_1);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[1])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[1]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[1], &sStatut_Zx[u8ZoneCorrespondante[1]], &circle_demande_zone_2, &circle_demande_zone_2Painter, &circle_mode_zone_2, &circle_mode_zone_2Painter, &textArea_temp_zone_2, textAreaBuffer_Temp_Zone_2);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[2])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[2]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[2], &sStatut_Zx[u8ZoneCorrespondante[2]], &circle_demande_zone_3, &circle_demande_zone_3Painter, &circle_mode_zone_3, &circle_mode_zone_3Painter, &textArea_temp_zone_3, textAreaBuffer_Temp_Zone_3);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[3])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[3]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[3], &sStatut_Zx[u8ZoneCorrespondante[3]], &circle_demande_zone_4, &circle_demande_zone_4Painter, &circle_mode_zone_4, &circle_mode_zone_4Painter, &textArea_temp_zone_4, textAreaBuffer_Temp_Zone_4);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[4])
	{
		// Affichage de la zone 2
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[4]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[4], &sStatut_Zx[u8ZoneCorrespondante[4]], &circle_demande_zone_5, &circle_demande_zone_5Painter, &circle_mode_zone_5, &circle_mode_zone_5Painter, &textArea_temp_zone_5, textAreaBuffer_Temp_Zone_5);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[5])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[5]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[5], &sStatut_Zx[u8ZoneCorrespondante[5]], &circle_demande_zone_6, &circle_demande_zone_6Painter, &circle_mode_zone_6, &circle_mode_zone_6Painter, &textArea_temp_zone_6, textAreaBuffer_Temp_Zone_6);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[6])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[6]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[6], &sStatut_Zx[u8ZoneCorrespondante[6]], &circle_demande_zone_7, &circle_demande_zone_7Painter, &circle_mode_zone_7, &circle_mode_zone_7Painter, &textArea_temp_zone_7, textAreaBuffer_Temp_Zone_7);
		}
	}
	else if(u8Zone == u8ZoneCorrespondante[7])
	{
		if(memcmp(&sStatut_Zx_old[u8ZoneCorrespondante[7]], sStatut_Zx, sizeof(S_STATUT_ZX)))
		{
			changeZx(u8ZoneCorrespondante[7], &sStatut_Zx[u8ZoneCorrespondante[7]], &circle_demande_zone_8, &circle_demande_zone_8Painter, &circle_mode_zone_8, &circle_mode_zone_8Painter, &textArea_temp_zone_8, textAreaBuffer_Temp_Zone_8);
		}
	}
	// Mémorisation de l'état précédent
	memcpy(&sStatut_Zx_old[u8Zone], sStatut_Zx, sizeof(S_STATUT_ZX));
}

void MultizonesView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	uint8_t u8NbZones, u8Tmp = 0;
	// Bouton zones
	if(memcmp(&sConfig_IHM_old.sOption_PAC.sZone, &sConfig_IHM->sOption_PAC.sZone, sizeof(S_ZONE)))
	{
		u8NbZones = sConfig_IHM->sOption_PAC.sZone.zone.bZone1 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone2 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone3 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone4 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone5 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone6 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone7 +
					sConfig_IHM->sOption_PAC.sZone.zone.bZone8;
		//
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone1)
		{
			u8ZoneCorrespondante[u8Tmp++] = 0;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone2)
		{
			u8ZoneCorrespondante[u8Tmp++] = 1;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone3)
		{
			u8ZoneCorrespondante[u8Tmp++] = 2;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone4)
		{
			u8ZoneCorrespondante[u8Tmp++] = 3;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone5)
		{
			u8ZoneCorrespondante[u8Tmp++] = 4;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone6)
		{
			u8ZoneCorrespondante[u8Tmp++] = 5;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone7)
		{
			u8ZoneCorrespondante[u8Tmp++] = 6;
		}
		if(sConfig_IHM->sOption_PAC.sZone.zone.bZone8)
		{
			u8ZoneCorrespondante[u8Tmp++] = 7;
		}
		// Zone 1
		if(u8NbZones >= 1)
		{
			container_zone_1.setVisible(true);
		}
		else container_zone_1.setVisible(false);
		container_zone_1.invalidate();
		// Zone 2
		if(u8NbZones >= 2)
		{
			container_zone_2.setVisible(true);
		}
		else container_zone_2.setVisible(false);
		container_zone_2.invalidate();
		// Zone 3
		if(u8NbZones >= 3)
		{
			container_zone_3.setVisible(true);
		}
		else container_zone_3.setVisible(false);
		container_zone_3.invalidate();
		// Zone 4
		if(u8NbZones >= 4)
		{
			container_zone_4.setVisible(true);
		}
		else container_zone_4.setVisible(false);
		container_zone_4.invalidate();
		// Zone 1
		if(u8NbZones >= 5)
		{
			container_zone_5.setVisible(true);
		}
		else container_zone_5.setVisible(false);
		container_zone_5.invalidate();
		// Zone 1
		if(u8NbZones >= 6)
		{
			container_zone_6.setVisible(true);
		}
		else container_zone_6.setVisible(false);
		container_zone_6.invalidate();
		// Zone 7
		if(u8NbZones >= 7)
		{
			container_zone_7.setVisible(true);
		}
		else container_zone_7.setVisible(false);
		container_zone_7.invalidate();
		// Zone 8
		if(u8NbZones >= 8)
		{
			container_zone_8.setVisible(true);
		}
		else container_zone_8.setVisible(false);
		container_zone_8.invalidate();
	}
	// Affichage de la zone 1
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[0]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[0]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[0], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[0]], &button_orange_zone_1, &button_marron_zone_1, &button_violet_zone_1, &textArea_zone_1, textAreaBuffer_Zone_1);
		changeZx(u8ZoneCorrespondante[0], &sStatut_Zx[u8ZoneCorrespondante[0]], &circle_demande_zone_1, &circle_demande_zone_1Painter, &circle_mode_zone_1, &circle_mode_zone_1Painter, &textArea_temp_zone_1, textAreaBuffer_Temp_Zone_1);
	}
	// Affichage de la zone 2
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[1]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[1]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[1], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[1]], &button_orange_zone_2, &button_marron_zone_2, &button_violet_zone_2, &textArea_zone_2, textAreaBuffer_Zone_2);
		changeZx(u8ZoneCorrespondante[1], &sStatut_Zx[u8ZoneCorrespondante[1]], &circle_demande_zone_2, &circle_demande_zone_2Painter, &circle_mode_zone_2, &circle_mode_zone_2Painter, &textArea_temp_zone_2, textAreaBuffer_Temp_Zone_2);
	}
	// Affichage de la zone 3
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[2]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[2]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[2], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[2]], &button_orange_zone_3, &button_marron_zone_3, &button_violet_zone_3, &textArea_zone_3, textAreaBuffer_Zone_3);
		changeZx(u8ZoneCorrespondante[2], &sStatut_Zx[u8ZoneCorrespondante[2]], &circle_demande_zone_3, &circle_demande_zone_3Painter, &circle_mode_zone_3, &circle_mode_zone_3Painter, &textArea_temp_zone_3, textAreaBuffer_Temp_Zone_3);
	}
	// Affichage de la zone 4
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[3]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[3]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[3], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[3]], &button_orange_zone_4, &button_marron_zone_4, &button_violet_zone_4, &textArea_zone_4, textAreaBuffer_Zone_4);
		changeZx(u8ZoneCorrespondante[3], &sStatut_Zx[u8ZoneCorrespondante[3]], &circle_demande_zone_4, &circle_demande_zone_4Painter, &circle_mode_zone_4, &circle_mode_zone_4Painter, &textArea_temp_zone_4, textAreaBuffer_Temp_Zone_4);
	}
	// Affichage de la zone 5
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[4]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[4]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[4], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[4]], &button_orange_zone_5, &button_marron_zone_5, &button_violet_zone_5, &textArea_zone_5, textAreaBuffer_Zone_5);
		changeZx(u8ZoneCorrespondante[4], &sStatut_Zx[u8ZoneCorrespondante[4]], &circle_demande_zone_5, &circle_demande_zone_5Painter, &circle_mode_zone_5, &circle_mode_zone_5Painter, &textArea_temp_zone_5, textAreaBuffer_Temp_Zone_5);
	}
	// Affichage de la zone 6
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[5]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[5]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[5], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[5]], &button_orange_zone_6, &button_marron_zone_6, &button_violet_zone_6, &textArea_zone_6, textAreaBuffer_Zone_6);
		changeZx(u8ZoneCorrespondante[5], &sStatut_Zx[u8ZoneCorrespondante[5]], &circle_demande_zone_6, &circle_demande_zone_6Painter, &circle_mode_zone_6, &circle_mode_zone_6Painter, &textArea_temp_zone_6, textAreaBuffer_Temp_Zone_6);
	}
	// Affichage de la zone 7
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[6]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[6]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[6], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[6]], &button_orange_zone_7, &button_marron_zone_7, &button_violet_zone_7, &textArea_zone_7, textAreaBuffer_Zone_7);
		changeZx(u8ZoneCorrespondante[6], &sStatut_Zx[u8ZoneCorrespondante[6]], &circle_demande_zone_7, &circle_demande_zone_7Painter, &circle_mode_zone_7, &circle_mode_zone_7Painter, &textArea_temp_zone_7, textAreaBuffer_Temp_Zone_7);
	}
	// Affichage de la zone 8
	if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneCorrespondante[7]], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[7]], sizeof(S_PARAM_ZX)))
	{
		changeConfigZx(u8ZoneCorrespondante[7], &sConfig_IHM->sParam_Zx[u8ZoneCorrespondante[7]], &button_orange_zone_8, &button_marron_zone_8, &button_violet_zone_8, &textArea_zone_8, textAreaBuffer_Zone_8);
		changeZx(u8ZoneCorrespondante[7], &sStatut_Zx[u8ZoneCorrespondante[7]], &circle_demande_zone_8, &circle_demande_zone_8Painter, &circle_mode_zone_8, &circle_mode_zone_8Painter, &textArea_temp_zone_8, textAreaBuffer_Temp_Zone_8);
	}
	//
	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void MultizonesView::changeConfigZx(uint8_t u8Zone, S_PARAM_ZX *sParam_Zx, touchgfx::Button *button_orange_zone, touchgfx::Button *button_marron_zone, touchgfx::Button *button_violet_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_Zone)
{
	uint16_t u16TmpBuffer[11];

	for(int i = 0; i < 10; i++)
	{
		u16TmpBuffer[i] = sParam_Zx->u8NomZone[i];
	}
	Unicode::snprintf(textAreaBuffer_Zone, 11, "%s", u16TmpBuffer);
	textArea_zone->setWildcard(textAreaBuffer_Zone);
	textArea_zone->invalidate();
	//
	switch(sParam_Zx->u2RattachementGroupe)
	{
		case AUTONOME:
			button_marron_zone->setVisible(false);
			button_violet_zone->setVisible(false);
			break;
		case GROUPE_A:
			button_marron_zone->setVisible(false);
			button_violet_zone->setVisible(true);
			break;
		case GROUPE_B:
			button_marron_zone->setVisible(true);
			button_violet_zone->setVisible(false);
			break;
	}
	button_marron_zone->invalidate();
	button_violet_zone->invalidate();
}

void MultizonesView::changeZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx, touchgfx::Circle *circle_demande_zone, touchgfx::PainterRGB565 *circle_demande_zonePainter, touchgfx::Circle *circle_mode_zone, touchgfx::PainterRGB565 *circle_mode_zonePainter, touchgfx::TextAreaWithOneWildcard *textArea_temp_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_Temp_Zone)
{
	// Mode et demande de la zone
	switch(sStatut_Zx->Mode)
	{
		case ARRET:
			circle_mode_zonePainter->setColor(BLANC);
			circle_demande_zonePainter->setColor(BLANC);
			break;
		case MARCHE_CHAUD:
		case AUTO_CHAUD:
		case HORS_GEL:
			circle_mode_zonePainter->setColor(ROUGE_CHAUD);
			if(sStatut_Zx->i16ConsigneTeau != 0)
			{
				circle_demande_zonePainter->setColor(ROUGE_CHAUD);
			}
			else circle_demande_zonePainter->setColor(BLANC);
			break;
		case MARCHE_FROID:
		case AUTO_FROID:
			circle_mode_zonePainter->setColor(BLEU_FROID);
			if(sStatut_Zx->i16ConsigneTeau != 0)
			{
				circle_demande_zonePainter->setColor(BLEU_FROID);
			}
			else circle_demande_zonePainter->setColor(BLANC);
			break;
	}
	circle_mode_zone->setPainter(*circle_mode_zonePainter);
	circle_demande_zone->setPainter(*circle_demande_zonePainter);
	circle_mode_zone->invalidate();
	circle_demande_zone->invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_Temp_Zone, 7, "%.1f", ((float) sStatut_Zx->i16Tint) / 10);
	textArea_temp_zone->setWildcard(textAreaBuffer_Temp_Zone);
	textArea_temp_zone->invalidate();
}

void MultizonesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void MultizonesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void MultizonesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void MultizonesView::changeDate(S_DATE *sDate)
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
