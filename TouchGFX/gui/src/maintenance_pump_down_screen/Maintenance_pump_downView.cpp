#include <gui/maintenance_pump_down_screen/Maintenance_pump_downView.hpp>

Maintenance_pump_downView::Maintenance_pump_downView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeStatutCyclFrigo(&sCyclRegFrigo[0]);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_FONCTION_MAINTENANCE_AVANCEE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	//Lieu récupération charge
	toggleButton_lieu_charge_UE.forceState(true);
	toggleButton_lieu_charge_UE.setTouchable(false);
	toggleButton_lieu_charge_UI.forceState(false);
	toggleButton_lieu_charge_UI.setTouchable(true);
	toggleButton_lieu_charge_UE.invalidate();
	toggleButton_lieu_charge_UI.invalidate();

	//Lancement procédure
	toggleButton_non_oui_non_pump_down.forceState(true);
	toggleButton_non_oui_non_pump_down.setTouchable(false);
	toggleButton_oui_oui_non_pump_down.forceState(false);
	toggleButton_oui_oui_non_pump_down.setTouchable(true);
	toggleButton_non_oui_non_pump_down.invalidate();
	toggleButton_oui_oui_non_pump_down.invalidate();

	textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE));
	textArea_info_recup.invalidate();
	eEtape_PumpDown = ETAPE_0;

	progress_bar.setValue(sCyclRegFrigo[0].pac.ajpac.sInPressFrigo.i16In_Pression_BP410 + 3);
	progress_bar.invalidate();
}

void Maintenance_pump_downView::bouton_unite_exterieure()
{
	toggleButton_lieu_charge_UE.forceState(true);
	toggleButton_lieu_charge_UE.setTouchable(false);
	toggleButton_lieu_charge_UI.forceState(false);
	toggleButton_lieu_charge_UI.setTouchable(true);
	toggleButton_lieu_charge_UE.invalidate();
	toggleButton_lieu_charge_UI.invalidate();
	textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE));
	textArea_info_recup.invalidate();
}

void Maintenance_pump_downView::bouton_unite_interieure()
{
	toggleButton_lieu_charge_UI.forceState(true);
	toggleButton_lieu_charge_UI.setTouchable(false);
	toggleButton_lieu_charge_UE.forceState(false);
	toggleButton_lieu_charge_UE.setTouchable(true);
	toggleButton_lieu_charge_UE.invalidate();
	toggleButton_lieu_charge_UI.invalidate();
	textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UI));
	textArea_info_recup.invalidate();
}

void Maintenance_pump_downView::bouton_oui()
{
	toggleButton_oui_oui_non_pump_down.forceState(true);
	toggleButton_oui_oui_non_pump_down.setTouchable(false);
	toggleButton_non_oui_non_pump_down.forceState(false);
	toggleButton_non_oui_non_pump_down.setTouchable(true);
	toggleButton_oui_oui_non_pump_down.invalidate();
	toggleButton_non_oui_non_pump_down.invalidate();

	if (toggleButton_lieu_charge_UE.getState() == 1)
	{
		presenter->c_sav_mode_pump_down_recup_ue();
	}
	else
	{
		presenter->c_sav_mode_pump_down_recup_ui();
	}
	eEtape_PumpDown = ETAPE_1;
}

void Maintenance_pump_downView::bouton_non()
{
	toggleButton_non_oui_non_pump_down.forceState(true);
	toggleButton_non_oui_non_pump_down.setTouchable(false);
	toggleButton_oui_oui_non_pump_down.forceState(false);
	toggleButton_oui_oui_non_pump_down.setTouchable(true);
	toggleButton_non_oui_non_pump_down.invalidate();
	toggleButton_oui_oui_non_pump_down.invalidate();

	presenter->c_sav_mode_pump_down_stop();
	eEtape_PumpDown = ETAPE_0;
}

void Maintenance_pump_downView::Timer_500ms()
{
	if(eEtape_PumpDown == ETAPE_0)
	{
		if (toggleButton_lieu_charge_UE.getState() == 1)
		{
			textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE));
		}
		else textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UI));
	}
	else if(eEtape_PumpDown == ETAPE_1)
	{
		if (toggleButton_lieu_charge_UE.getState() == 1)
		{
			textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE_1));
		}
		else textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UI_1));

		if (sCyclRegFrigo[0].pac.ajpac.sInPressFrigo.i16In_Pression_BP410 < -3)
		{
			eEtape_PumpDown = ETAPE_2;
		}
	}
	else if (eEtape_PumpDown == ETAPE_2)
	{
		if (toggleButton_lieu_charge_UE.getState() == 1)
		{
			textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE_2));
		}
		else textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UI_2));

		if (sCyclRegFrigo[0].pac.ajpac.sDemandePW.PalierCompresseur1 == 0)
		{
			if (sCyclRegFrigo[0].pac.ajpac.sInPressFrigo.i16In_Pression_BP410 > 10)
			{
				eEtape_PumpDown = ETAPE_4;
			}
			else eEtape_PumpDown = ETAPE_3;
		}
		presenter->c_sav_mode_pump_down_stop();
	}
	else if (eEtape_PumpDown == ETAPE_3)
	{
		if (sCyclRegFrigo[0].pac.ajpac.sInPressFrigo.i16In_Pression_BP410 > 10)
		{
			eEtape_PumpDown = ETAPE_4;
		}
		if (toggleButton_lieu_charge_UE.getState() == 1)
		{
			textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE_3));
		}
		else textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UI_3));
	}
	else if (eEtape_PumpDown == ETAPE_4)
	{
		if (toggleButton_lieu_charge_UE.getState() == 1)
		{
			textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UE_4));
		}
		else textArea_info_recup.setTypedText(touchgfx::TypedText(T_TEXT_RECUP_CHARGE_UI_4));
	}
	textArea_info_recup.invalidate();

	progress_bar.setValue(sCyclRegFrigo[0].pac.ajpac.sInPressFrigo.i16In_Pression_BP410 + 3);
	progress_bar.invalidate();
}

void Maintenance_pump_downView::bouton_valider()
{
	presenter->c_sav_mode_pump_down_stop();
	application().gotoMaintenance_fct_avancesScreenNoTransition();
}

void Maintenance_pump_downView::setupScreen()
{
    Maintenance_pump_downViewBase::setupScreen();
}

void Maintenance_pump_downView::tearDownScreen()
{
    Maintenance_pump_downViewBase::tearDownScreen();
}

void Maintenance_pump_downView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	Unicode::snprintfFloat(textAreaBuffer_Pression_HP, 6, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410/10));
	Unicode::snprintfFloat(textAreaBuffer_Pression_BP, 6, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410/10));
	textArea_val_pression_hp.setWildcard(textAreaBuffer_Pression_HP);
	textArea_val_pression_bp.setWildcard(textAreaBuffer_Pression_BP);
	textArea_val_pression_hp.invalidate();
	textArea_val_pression_bp.invalidate();
}

void Maintenance_pump_downView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Maintenance_pump_downView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Maintenance_pump_downView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Maintenance_pump_downView::changeDate(S_DATE *sDate)
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

