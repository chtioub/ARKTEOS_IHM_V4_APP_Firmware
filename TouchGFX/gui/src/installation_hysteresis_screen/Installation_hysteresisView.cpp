#include <gui/installation_hysteresis_screen/Installation_hysteresisView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
//#include <math.h>

Installation_hysteresisView::Installation_hysteresisView()
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

	bMoveSliderPlus = false;
	bMoveSliderMoins = false;

	//u7VitesseVentilateur = sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.GroupeEau.u7VitesseMaxVentilateur;
//	Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_PARAM_COMPLEMENTAIRE_CENTRE_DEFAUT).getText());
//	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
//	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
//	//Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", (sConfig_Hydrau_temp.u8NumZone == 8) ? 'A' : 'B');
//	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
//	barre_titre.titre(textAreaBuffer_Titre);
//

	switch (eHysteresis)
	{
		case HYST_TINT ://-2/2
			Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_HYSTERESIS_SONDE_CENTRE_DEFAUT).getText());
			slider_hyst_plus.setValue(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisPlus * 20);
			slider_hyst_moins.setValue(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisMoins * 20);
			Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 4, " - ");
			Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
			Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)",sConfig_Hydrau_temp.u8NumZone + 1 );
			break;
		case HYST_TEAU ://-4/4
			Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_HYSTERESIS_SONDE_EAU).getText());
			//Groupe
			if (sConfig_Hydrau_temp.u8NumZone >= 8)
			{
				Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 2, " ");
				Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
				Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
				slider_hyst_plus.setValue(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisPlus * 10);
				slider_hyst_moins.setValue(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisMoins * 10);
			}
			else
			{
				slider_hyst_plus.setValue(sConfig_IHM.sParam_PAC.i8HysteresisEauPlus * 10);
				slider_hyst_moins.setValue(sConfig_IHM.sParam_PAC.i8HysteresisEauMoins * 10);
			}
			break;
		case HYST_ECS ://-4/4
			Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_HYSTERESIS_ECS_CENTRE_DEFAUT).getText());
			slider_hyst_plus.setValue(sConfig_IHM.sParam_ECS.i8HysteresisECSPlus * 10);
			slider_hyst_moins.setValue(sConfig_IHM.sParam_ECS.i8HysteresisECSMoins * 10);
			break;
		case HYST_EXT ://-4/4
			Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_HYSTERESIS_EXT_CENTRE_DEFAUT).getText());
			slider_hyst_plus.setValue(sConfig_IHM.sParam_PAC.i8HysteresisTextPlus * 10);
			slider_hyst_moins.setValue(sConfig_IHM.sParam_PAC.i8HysteresisTextMoins * 10);
			break;
		case HYST_PISC ://-4/4
			Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_HYSTERESIS_PISCINE_CENTRE_DEFAUT).getText());
			slider_hyst_plus.setValue(sConfig_IHM.sParam_Piscine.i8HysteresisEauPlus * 10);
			slider_hyst_moins.setValue(sConfig_IHM.sParam_Piscine.i8HysteresisEauMoins * 10);
			break;
		case HYST_PRIM ://-4/4
			Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_HYSTERESIS_PRIMAIRE_CENTRE_DEFAUT).getText());
			slider_hyst_plus.setValue(sConfig_IHM.sConfig_PAC.CommunAllConfig.i8Hysteresis_Primaire_Plus * 10);
			slider_hyst_moins.setValue(sConfig_IHM.sConfig_PAC.CommunAllConfig.i8Hysteresis_Primaire_Moins * 10);
			break;
		default:
			break;
	}

	switch (eHysteresis)
	{
		case HYST_TINT ://-2/2
			Unicode::snprintfFloat(textAreaBuffer_hyst_plus, 5, "%.1f", ((float)(slider_hyst_plus.getValue()))/200);
			Unicode::snprintfFloat(textAreaBuffer_hyst_moins, 5, "%.1f", ((float)(slider_hyst_moins.getValue()))/200);
			break;
		case HYST_TEAU :
		case HYST_ECS :
		case HYST_EXT :
		case HYST_PISC :
		case HYST_PRIM :
		default:
			Unicode::snprintfFloat(textAreaBuffer_hyst_plus, 5, "%.1f", ((float)(slider_hyst_plus.getValue()))/100);
			Unicode::snprintfFloat(textAreaBuffer_hyst_moins, 5, "%.1f", ((float)(slider_hyst_moins.getValue()))/100);
			break;
	}
	//Unicode::snprintfFloat(textAreaBuffer_hyst_plus, 5, "%.1f", ((float)(slider_hyst_plus.getValue()))/100);
	textArea_hyst_plus.setWildcard(textAreaBuffer_hyst_plus);
	textArea_hyst_plus.setX(slider_hyst_plus.getValue() + 435);
	fleche_droite.setX(slider_hyst_plus.getValue() + 395);
	//Unicode::snprintfFloat(textAreaBuffer_hyst_moins, 5, "%.1f", ((float)(slider_hyst_moins.getValue()))/100);
	textArea_hyst_moins.setWildcard(textAreaBuffer_hyst_moins);
	textArea_hyst_moins.setX(slider_hyst_moins.getValue() + 430);
	fleche_gauche.setX(slider_hyst_moins.getValue() + 395);

	slider_hyst_plus.invalidate();
	slider_hyst_moins.invalidate();
	textArea_hyst_plus.setVisible(true);
	fleche_droite.setVisible(true);
	textArea_hyst_plus.invalidate();
	fleche_droite.invalidate();
	textArea_hyst_moins.setVisible(true);
	fleche_gauche.setVisible(true);
	textArea_hyst_moins.invalidate();
	fleche_gauche.invalidate();

	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();
}

void Installation_hysteresisView::setupScreen()
{
    Installation_hysteresisViewBase::setupScreen();
}

void Installation_hysteresisView::tearDownScreen()
{
    Installation_hysteresisViewBase::tearDownScreen();
}

void Installation_hysteresisView::Slider_Plus(int valSlid)
{
	bMoveSliderPlus = true;
	GestionSliderPlus();
	bMoveSliderPlus = false;
}


void Installation_hysteresisView::Slider_Moins(int valSlid)
{
	bMoveSliderMoins = true;
	GestionSliderMoins();
	bMoveSliderMoins = false;
}

void Installation_hysteresisView::GestionSliderPlus()
{
	if (slider_hyst_plus.getValue() < slider_hyst_moins.getMinValue())
	{
		slider_hyst_moins.setValue(slider_hyst_moins.getMinValue());
		slider_hyst_plus.setValue(slider_hyst_moins.getMinValue() + DELTA_MIN_HYST_PLUS_MOINS);
		slider_hyst_moins.invalidate();
		slider_hyst_plus.invalidate();
	}

	if (slider_hyst_moins.getValue() > (/*valSlid*/ slider_hyst_plus.getValue() - DELTA_MIN_HYST_PLUS_MOINS))
	{
		slider_hyst_moins.setValue(/*valSlid*/slider_hyst_plus.getValue() - DELTA_MIN_HYST_PLUS_MOINS);
	}

	lineV_hyst_plus.setVisible(false);
	lineV_hyst_plus.invalidate();
	lineV_hyst_plus.setStart((slider_hyst_plus.getValue() + 403), 0);
	lineV_hyst_plus.setEnd((slider_hyst_plus.getValue() + 403), 190);
	lineV_hyst_plus.setVisible(true);
	lineV_hyst_plus.invalidate();

	lineH_hyst_haute.setVisible(false);
	lineH_hyst_basse.setVisible(false);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	int xval = 0;
	int yval = 0;
	lineV_hyst_moins.getStart(xval,yval);
	lineH_hyst_haute.setStart(xval, 3);
	lineH_hyst_haute.setEnd((slider_hyst_plus.getValue() + 403), 3);
	lineH_hyst_basse.setStart(xval, 3);
	lineH_hyst_basse.setEnd((slider_hyst_plus.getValue() + 403), 3);

	lineH_hyst_haute.setVisible(true);
	lineH_hyst_basse.setVisible(true);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	textArea_hyst_plus.setVisible(false);
	fleche_droite.setVisible(false);
	textArea_hyst_plus.invalidate();
	fleche_droite.invalidate();


	switch (eHysteresis)
	{
		case HYST_TINT ://-2/2
			Unicode::snprintfFloat(textAreaBuffer_hyst_plus, 5, "%.1f", ((float)(slider_hyst_plus.getValue()))/200);
			break;
		case HYST_TEAU :
		case HYST_ECS :
		case HYST_EXT :
		case HYST_PISC :
		case HYST_PRIM :
		default:
			Unicode::snprintfFloat(textAreaBuffer_hyst_plus, 5, "%.1f", ((float)(slider_hyst_plus.getValue()))/100);
			break;
	}

	textArea_hyst_plus.setWildcard(textAreaBuffer_hyst_plus);
	textArea_hyst_plus.setX(slider_hyst_plus.getValue() + 435);
	fleche_droite.setX(slider_hyst_plus.getValue() + 395);

	textArea_hyst_plus.setVisible(true);
	fleche_droite.setVisible(true);
	textArea_hyst_plus.invalidate();
	fleche_droite.invalidate();
}

void Installation_hysteresisView::GestionSliderMoins()
{
	if (slider_hyst_moins.getValue() > slider_hyst_plus.getMaxValue())
	{
		slider_hyst_plus.setValue(slider_hyst_plus.getMaxValue());
		slider_hyst_moins.setValue(slider_hyst_plus.getMaxValue() - DELTA_MIN_HYST_PLUS_MOINS);
		slider_hyst_moins.invalidate();
		slider_hyst_plus.invalidate();
	}

	if (slider_hyst_plus.getValue() < (/*valSlid*/slider_hyst_moins.getValue() + DELTA_MIN_HYST_PLUS_MOINS))
	{
		slider_hyst_plus.setValue(/*valSlid*/ slider_hyst_moins.getValue() + DELTA_MIN_HYST_PLUS_MOINS);
	}

	lineV_hyst_moins.setVisible(false);
	lineV_hyst_moins.invalidate();
	lineV_hyst_moins.setStart((slider_hyst_moins.getValue() + 403), 0);
	lineV_hyst_moins.setEnd((slider_hyst_moins.getValue() + 403), 190);
	lineV_hyst_moins.setVisible(true);
	lineV_hyst_moins.invalidate();

	lineH_hyst_haute.setVisible(false);
	lineH_hyst_basse.setVisible(false);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	int xval = 0;
	int yval = 0;
	lineV_hyst_plus.getStart(xval,yval);

	lineH_hyst_haute.setEnd(xval, 3);
	lineH_hyst_haute.setStart((slider_hyst_moins.getValue() + 403), 3);
	lineH_hyst_basse.setEnd(xval, 3);
	lineH_hyst_basse.setStart((slider_hyst_moins.getValue() + 403), 3);

	lineH_hyst_haute.setVisible(true);
	lineH_hyst_basse.setVisible(true);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	textArea_hyst_moins.setVisible(false);
	fleche_gauche.setVisible(false);
	textArea_hyst_moins.invalidate();
	fleche_gauche.invalidate();


	switch (eHysteresis)
	{
		case HYST_TINT ://-2/2
			Unicode::snprintfFloat(textAreaBuffer_hyst_moins, 5, "%.1f", ((float)(slider_hyst_moins.getValue()))/200);
			break;
		case HYST_TEAU ://-2/2
		case HYST_ECS :
		case HYST_EXT :
		case HYST_PISC :
		case HYST_PRIM :
		default:
			Unicode::snprintfFloat(textAreaBuffer_hyst_moins, 5, "%.1f", ((float)(slider_hyst_moins.getValue()))/100);
			break;
	}

	textArea_hyst_moins.setWildcard(textAreaBuffer_hyst_moins);
	textArea_hyst_moins.setX(slider_hyst_moins.getValue() + 430);
	fleche_gauche.setX(slider_hyst_moins.getValue() + 395);

	textArea_hyst_moins.setVisible(true);
	fleche_gauche.setVisible(true);
	textArea_hyst_moins.invalidate();
	fleche_gauche.invalidate();
}

void Installation_hysteresisView::Timer_100ms()
{
	//Fonction pour s'assurer qu'on est bien par pas de 0,2°C
	int valtemp;
	int newval;
	if (!bMoveSliderMoins)
	{
		valtemp = slider_hyst_moins.getValue()/10;

		if ((valtemp & 1) == 1)
		{
			newval = (slider_hyst_moins.getValue() - 10);
			slider_hyst_moins.setValue(newval);
			slider_hyst_moins.invalidate();
		}
		else
		{
			newval = (valtemp * 10);
			slider_hyst_moins.setValue(newval);
			slider_hyst_moins.invalidate();
		}
		GestionSliderMoins();
	}

	if (!bMoveSliderPlus)
	{
		valtemp = slider_hyst_plus.getValue()/10;

		if ((valtemp & 1) == 1)
		{
			newval = (slider_hyst_plus.getValue() + 10);
			slider_hyst_plus.setValue(newval);
			slider_hyst_plus.invalidate();
		}
		else
		{
			newval = (valtemp * 10);
			slider_hyst_plus.setValue(newval);
			slider_hyst_plus.invalidate();
		}

		GestionSliderPlus();
	}
}


void Installation_hysteresisView::bouton_valider()
{
	switch (eHysteresis)
	{
		case HYST_TINT :
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisPlus = (slider_hyst_plus.getValue()/20);
			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisMoins = (slider_hyst_moins.getValue()/20);
			memcpy(&sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone], &sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], sizeof(S_PARAM_ZX));
			presenter->c_install_param_zx();
			//RF
			if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.TypeThermostat == TH_RF)
			{
				application().gotoInstallation_hydraulique_sonde_rfScreenNoTransition();
			}
			else //Modbus
			{
				application().gotoInstallation_hydraulique_sonde_modbusScreenNoTransition();
			}
			break;
		case HYST_TEAU :
			if (sConfig_Hydrau_temp.u8NumZone >= 8)
			{
				sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisPlus = (slider_hyst_plus.getValue()/10);
				sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisMoins = (slider_hyst_moins.getValue()/10);
				application().gotoInstallation_MZ_param_complementaires_groupeScreenNoTransition();
			}
			else
			{
				sConfig_IHM.sParam_PAC.i8HysteresisEauPlus = (slider_hyst_plus.getValue()/10);
				sConfig_IHM.sParam_PAC.i8HysteresisEauMoins = (slider_hyst_moins.getValue()/10);
				presenter->c_install_param();
				application().gotoInstallation_hydrauliqueScreenNoTransition();
			}
			break;
		case HYST_ECS :
			sConfig_IHM.sParam_ECS.i8HysteresisECSPlus = (slider_hyst_plus.getValue()/10);
			sConfig_IHM.sParam_ECS.i8HysteresisECSMoins = (slider_hyst_moins.getValue()/10);
			presenter->c_install_ecs();
			application().gotoInstallation_ecsScreenNoTransition();
			break;
		case HYST_EXT :
			sConfig_IHM.sParam_PAC.i8HysteresisTextPlus = (slider_hyst_plus.getValue()/10);
			sConfig_IHM.sParam_PAC.i8HysteresisTextMoins = (slider_hyst_moins.getValue()/10);
			presenter->c_install_param();
			if (ePageHystExt == HYST_EXT_APPOINT)
			{
				application().gotoInstallation_appointScreenNoTransition();
			}
			else
			{
				application().gotoInstallation_regulation_avanceeScreenNoTransition();
			}
			break;
		case HYST_PISC :
			sConfig_IHM.sParam_Piscine.i8HysteresisEauPlus = (slider_hyst_plus.getValue()/10);
			sConfig_IHM.sParam_Piscine.i8HysteresisEauMoins = (slider_hyst_moins.getValue()/10);
			presenter->c_install_piscine();
			application().gotoInstallation_piscineScreenNoTransition();
			break;
		case HYST_PRIM :
			//Page théoriquement plus utilisée ou accessible (valable anciennement que pour Géotwin)
//			sConfig_IHM.sConfig_PAC.CommunAllConfig.i8Hysteresis_Primaire_Plus = (slider_hyst_plus.getValue()/10);
//			sConfig_IHM.sConfig_PAC.CommunAllConfig.i8Hysteresis_Primaire_Moins = (slider_hyst_moins.getValue()/10);
//			presenter->c_install_config_pac();
//			application().gotoInstallation_piscineScreenNoTransition();
			break;
		default:
			break;
	}
}

void Installation_hysteresisView::bouton_retour()
{
	switch (eHysteresis)
	{
		case HYST_TINT :
//			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisPlus = (slider_hyst_plus.getValue()/20);
//			sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].i8HysteresisMoins = (slider_hyst_moins.getValue()/20);
//			memcpy(&sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone], &sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], sizeof(S_PARAM_ZX));
//			presenter->c_install_param_zx();
			//RF
			if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].type_zone.zone.TypeThermostat == TH_RF)
			{
				application().gotoInstallation_hydraulique_sonde_rfScreenNoTransition();
			}
			else //Modbus
			{
				application().gotoInstallation_hydraulique_sonde_modbusScreenNoTransition();
			}
			break;
		case HYST_TEAU :
//			sConfig_IHM.sParam_PAC.i8HysteresisEauPlus = (slider_hyst_plus.getValue()/10);
//			sConfig_IHM.sParam_PAC.i8HysteresisEauMoins = (slider_hyst_moins.getValue()/10);
//			presenter->c_install_param();
			if (sConfig_Hydrau_temp.u8NumZone >= 8)
			{
				application().gotoInstallation_MZ_param_complementaires_groupeScreenNoTransition();
			}
			else application().gotoInstallation_hydrauliqueScreenNoTransition();
			break;
		case HYST_ECS :
//			sConfig_IHM.sParam_ECS.i8HysteresisECSPlus = (slider_hyst_plus.getValue()/10);
//			sConfig_IHM.sParam_ECS.i8HysteresisECSMoins = (slider_hyst_moins.getValue()/10);
//			presenter->c_install_ecs();
			application().gotoInstallation_ecsScreenNoTransition();
			break;
		case HYST_EXT :
//			sConfig_IHM.sParam_PAC.i8HysteresisTextPlus = (slider_hyst_plus.getValue()/10);
//			sConfig_IHM.sParam_PAC.i8HysteresisTextMoins = (slider_hyst_moins.getValue()/10);
//			presenter->c_install_param();
			if (ePageHystExt == HYST_EXT_APPOINT)
			{
				application().gotoInstallation_appointScreenNoTransition();
			}
			else
			{
				application().gotoInstallation_regulation_avanceeScreenNoTransition();
			}
			break;
		case HYST_PISC :
//			sConfig_IHM.sParam_Piscine.i8HysteresisEauPlus = (slider_hyst_plus.getValue()/10);
//			sConfig_IHM.sParam_Piscine.i8HysteresisEauMoins = (slider_hyst_moins.getValue()/10);
//			presenter->c_install_piscine();
			application().gotoInstallation_piscineScreenNoTransition();
			break;
		case HYST_PRIM :
			//Page théoriquement plus utilisée ou accessible (valable anciennement que pour Géotwin)
//			sConfig_IHM.sConfig_PAC.CommunAllConfig.i8Hysteresis_Primaire_Plus = (slider_hyst_plus.getValue()/10);
//			sConfig_IHM.sConfig_PAC.CommunAllConfig.i8Hysteresis_Primaire_Moins = (slider_hyst_moins.getValue()/10);
//			presenter->c_install_config_pac();
//			application().gotoInstallation_piscineScreenNoTransition();
			break;
		default:
			break;
	}
}


void Installation_hysteresisView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_hysteresisView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hysteresisView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hysteresisView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hysteresisView::changeDate(S_DATE *sDate)
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



