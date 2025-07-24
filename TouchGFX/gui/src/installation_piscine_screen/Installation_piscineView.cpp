#include <gui/installation_piscine_screen/Installation_piscineView.hpp>

Installation_piscineView::Installation_piscineView()
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
	if(sConfig_Piscine_temp.bPiscine == 0)
	{
		toggleButton_oui_oui_non_piscine.forceState(false);
		toggleButton_oui_oui_non_piscine.setTouchable(true);
		toggleButton_non_oui_non_piscine.forceState(true);
		toggleButton_non_oui_non_piscine.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_piscine.forceState(true);
		toggleButton_oui_oui_non_piscine.setTouchable(false);
		toggleButton_non_oui_non_piscine.forceState(false);
		toggleButton_non_oui_non_piscine.setTouchable(true);
	}
	toggleButton_non_oui_non_piscine.invalidate();
	toggleButton_oui_oui_non_piscine.invalidate();
	//
	if(sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine == PRIORITE_PISCINE)
	{
		toggleButton_piscine_option_relance_piscine.forceState(true);
	}
	else if(sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine == PRIORITE_CHAUD)
	{
		toggleButton_maison_option_relance_piscine.forceState(true);
	}
	else toggleButton_piscine_maison_option_relance_piscine.forceState(true);
	bouton_piscine();
	bouton_maison();
	bouton_50_50();
	//
	u16ConsignePiscine = sConfig_Piscine_temp.sParam_Piscine.i16ConsigneDepartEauPiscine;
    Unicode::snprintfFloat(textAreaBuffer_Temp, 5, "%.1f", ((float) u16ConsignePiscine) / 10);
    textArea_valeur_consigne_eau_piscine.setWildcard(textAreaBuffer_Temp);
	//
	if(sConfig_Piscine_temp.sParam_Piscine.bGestionSimultanee)
	{
		buttonWithLabel_on_simultane_piscine.setVisible(true);
	}
	else buttonWithLabel_on_simultane_piscine.setVisible(false);
	// Titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);
}

void Installation_piscineView::setupScreen()
{
    Installation_piscineViewBase::setupScreen();
}

void Installation_piscineView::tearDownScreen()
{
    Installation_piscineViewBase::tearDownScreen();
}

void Installation_piscineView::bouton_piscine_non()
{
	if(toggleButton_non_oui_non_piscine.getState())
	{
		toggleButton_oui_oui_non_piscine.forceState(false);
		toggleButton_oui_oui_non_piscine.setTouchable(true);
		toggleButton_oui_oui_non_piscine.invalidate();
		toggleButton_non_oui_non_piscine.setTouchable(false);
		toggleButton_non_oui_non_piscine.invalidate();
	}
}

void Installation_piscineView::bouton_piscine_oui()
{
	if(toggleButton_oui_oui_non_piscine.getState())
	{
		toggleButton_non_oui_non_piscine.forceState(false);
		toggleButton_non_oui_non_piscine.setTouchable(true);
		toggleButton_non_oui_non_piscine.invalidate();
		toggleButton_oui_oui_non_piscine.setTouchable(false);
		toggleButton_oui_oui_non_piscine.invalidate();
	}
}

void Installation_piscineView::bouton_piscine()
{
	if(toggleButton_piscine_option_relance_piscine.getState())
	{
		toggleButton_maison_option_relance_piscine.forceState(false);
		toggleButton_maison_option_relance_piscine.setTouchable(true);
		toggleButton_maison_option_relance_piscine.invalidate();
		toggleButton_piscine_maison_option_relance_piscine.forceState(false);
		toggleButton_piscine_maison_option_relance_piscine.setTouchable(true);
		toggleButton_piscine_maison_option_relance_piscine.invalidate();
		toggleButton_piscine_option_relance_piscine.setTouchable(false);
		toggleButton_piscine_option_relance_piscine.invalidate();
	}
}

void Installation_piscineView::bouton_maison()
{
	if(toggleButton_maison_option_relance_piscine.getState())
	{
		toggleButton_piscine_option_relance_piscine.forceState(false);
		toggleButton_piscine_option_relance_piscine.setTouchable(true);
		toggleButton_piscine_option_relance_piscine.invalidate();
		toggleButton_piscine_maison_option_relance_piscine.forceState(false);
		toggleButton_piscine_maison_option_relance_piscine.setTouchable(true);
		toggleButton_piscine_maison_option_relance_piscine.invalidate();
		toggleButton_maison_option_relance_piscine.setTouchable(false);
		toggleButton_maison_option_relance_piscine.invalidate();
	}
}

void Installation_piscineView::bouton_50_50()
{
	if(toggleButton_piscine_maison_option_relance_piscine.getState())
	{
		toggleButton_piscine_option_relance_piscine.forceState(false);
		toggleButton_piscine_option_relance_piscine.setTouchable(true);
		toggleButton_piscine_option_relance_piscine.invalidate();
		toggleButton_maison_option_relance_piscine.forceState(false);
		toggleButton_maison_option_relance_piscine.setTouchable(true);
		toggleButton_maison_option_relance_piscine.invalidate();
		toggleButton_piscine_maison_option_relance_piscine.setTouchable(false);
		toggleButton_piscine_maison_option_relance_piscine.invalidate();
	}
}

void Installation_piscineView::bouton_consigne_moins()
{
	if(u16ConsignePiscine <= 300) return;
	//
	u16ConsignePiscine--;
	//
    Unicode::snprintfFloat(textAreaBuffer_Temp, 5, "%.1f", ((float) u16ConsignePiscine) / 10);
    textArea_valeur_consigne_eau_piscine.setWildcard(textAreaBuffer_Temp);
    textArea_valeur_consigne_eau_piscine.invalidate();
}

void Installation_piscineView::bouton_consigne_plus()
{
	if(u16ConsignePiscine >= (sConfig_IHM.sModele_PAC.u8ThermoMaxPac * 10)) return;
	//
	u16ConsignePiscine++;
	//
    Unicode::snprintfFloat(textAreaBuffer_Temp, 5, "%.1f", ((float) u16ConsignePiscine) / 10);
    textArea_valeur_consigne_eau_piscine.setWildcard(textAreaBuffer_Temp);
    textArea_valeur_consigne_eau_piscine.invalidate();
}

void Installation_piscineView::bouton_mem_config_piscine()
{
	//
	if(toggleButton_oui_oui_non_piscine.getState())
	{
		sConfig_Piscine_temp.bPiscine = 1;
	}
	else sConfig_Piscine_temp.bPiscine = 0;
	//
	if(toggleButton_piscine_option_relance_piscine.getState())
	{
		sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine = PRIORITE_PISCINE;
	}
	else if(toggleButton_maison_option_relance_piscine.getState())
	{
		sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine = PRIORITE_CHAUD;
	}
	else sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine = PRIORITE_EGAL;
	//
	sConfig_Piscine_temp.sParam_Piscine.i16ConsigneDepartEauPiscine = u16ConsignePiscine;
}

void Installation_piscineView::bouton_simultane()
{
	eOuiNon = OUI_NON_SIMULTANE_PISCINE;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Installation_piscineView::bouton_hysteresis()
{
	eHysteresis = HYST_PISC;
	application().gotoInstallation_hysteresisScreenNoTransition();
}

void Installation_piscineView::bouton_valider()
{
	//
	if(toggleButton_oui_oui_non_piscine.getState())
	{
		sConfig_Piscine_temp.bPiscine = 1;
	}
	else sConfig_Piscine_temp.bPiscine = 0;
	//
	if(toggleButton_piscine_option_relance_piscine.getState())
	{
		sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine = PRIORITE_PISCINE;
	}
	else if(toggleButton_maison_option_relance_piscine.getState())
	{
		sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine = PRIORITE_CHAUD;
	}
	else sConfig_Piscine_temp.sParam_Piscine.PrioritePiscine = PRIORITE_EGAL;
	//
	sConfig_Piscine_temp.sParam_Piscine.i16ConsigneDepartEauPiscine = u16ConsignePiscine;
	// Mémorisation
	sConfig_IHM.sOption_PAC.Piscine = sConfig_Piscine_temp.bPiscine;
	//Car sinon l'hystérésis précédemment entré était écrasé
	sConfig_Piscine_temp.sParam_Piscine.i8HysteresisEauPlus = sConfig_IHM.sParam_Piscine.i8HysteresisEauPlus;
	sConfig_Piscine_temp.sParam_Piscine.i8HysteresisEauMoins = sConfig_IHM.sParam_Piscine.i8HysteresisEauMoins;

	memcpy(&sConfig_IHM.sParam_Piscine, &sConfig_Piscine_temp.sParam_Piscine, sizeof(S_PARAM_PISCINE));
	// Multiple trame
	presenter->c_install_param();
	presenter->c_install_piscine();
	application().gotoInstallationScreenNoTransition();
}

void Installation_piscineView::timer_10ms()
{
	//
	if(button_gauche_consigne_eau_piscine.getPressedState())
	{
		if(u8PressionLongue_gauche < 15)
		{
			u8PressionLongue_gauche++;
		}
		else bouton_consigne_moins();
	}
	else u8PressionLongue_gauche = 0;
	//
	if(button_droite_consigne_eau_piscine.getPressedState())
	{
		if(u8PressionLongue_droite < 15)
		{
			u8PressionLongue_droite++;
		}
		else bouton_consigne_plus();
	}
	else u8PressionLongue_droite = 0;
}

void Installation_piscineView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_piscineView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_piscineView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_piscineView::changeDate(S_DATE *sDate)
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
