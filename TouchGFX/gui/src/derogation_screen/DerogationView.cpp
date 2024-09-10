#include <gui/derogation_screen/DerogationView.hpp>

DerogationView::DerogationView()
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
	// Statut initial du bouton derogation
	if(u8ZoneSelect == 0xff)
	{
		u16ValMin = 70;
		u16ValMax = sConfig_IHM.sModele_PAC.u8ThermoMaxPac * 10;
		textArea_question_consigne_derog.setTypedText(touchgfx::TypedText(T_TEXT_CONSIGNE_DEROG_EXT_CENTRE_DEFAUT));
		if(sConfig_IHM.sMode_RegulExt.Exception == S_SABLIER)
		{
			toggleButton_non_oui_non_derog.forceState(false);
			toggleButton_non_oui_non_derog.setTouchable(true);
			toggleButton_oui_oui_non_derog.forceState(true);
			toggleButton_oui_oui_non_derog.setTouchable(false);
			u16Time_Derogation = sStatut_RegulExt.u16CTime_Sablier / 60;
		}
		else
		{
			toggleButton_oui_oui_non_derog.forceState(false);
			toggleButton_oui_oui_non_derog.setTouchable(true);
			toggleButton_non_oui_non_derog.forceState(true);
			toggleButton_non_oui_non_derog.setTouchable(false);
			u16Time_Derogation = sConfig_IHM.sMode_RegulExt.u16Time_RegExt_Sablier;
		}
	}
	else
	{
		u16ValMin = 120;
		u16ValMax = 300;
	    textArea_question_consigne_derog.setTypedText(touchgfx::TypedText(T_TEXT_CONSIGNE_DEROG_CENTRE_DEFAUT));
		if(sConfig_IHM.sMode_Zx[u8ZoneSelect].Exception == S_SABLIER)
		{
			toggleButton_non_oui_non_derog.forceState(false);
			toggleButton_non_oui_non_derog.setTouchable(true);
			toggleButton_oui_oui_non_derog.forceState(true);
			toggleButton_oui_oui_non_derog.setTouchable(false);
			u16Time_Derogation = sStatut_Zx[u8ZoneSelect].u16CTime_Sablier / 60;
		}
		else
		{
			toggleButton_oui_oui_non_derog.forceState(false);
			toggleButton_oui_oui_non_derog.setTouchable(true);
			toggleButton_non_oui_non_derog.forceState(true);
			toggleButton_non_oui_non_derog.setTouchable(false);
			u16Time_Derogation = sConfig_IHM.sMode_Zx[u8ZoneSelect].u16Time_Sablier;
		}
	}
	// Durée de la dérogation
	if(u16Time_Derogation != 0)
	{
		Unicode::snprintf(textAreaBuffer_Derogation, 6, "%02dh%02d", u16Time_Derogation / 60, u16Time_Derogation % 60);
	}
	else Unicode::snprintf(textAreaBuffer_Derogation, 6, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	textArea_valeur_duree_derog.setWildcard(textAreaBuffer_Derogation);
	// Température de consigne dérogation
	if(u8ZoneSelect == 0xff)
	{
		u16Consigne_Derogation = sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Sablier;
		Unicode::snprintfFloat(textAreaBuffer_Consigne, 6, "%.1f", ((float) u16Consigne_Derogation) / 10);
	}
	else
	{
		u16Consigne_Derogation = sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Sablier;
		Unicode::snprintfFloat(textAreaBuffer_Consigne, 6, "%.1f", ((float) u16Consigne_Derogation) / 10);
	}
	textArea_valeur_consigne_derog.setWildcard(textAreaBuffer_Consigne);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_ZONE_DEROGATION_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void DerogationView::bouton_oui_derog()
{
	if(toggleButton_oui_oui_non_derog.getState())
	{
		toggleButton_non_oui_non_derog.forceState(false);
		toggleButton_non_oui_non_derog.setTouchable(true);
		toggleButton_non_oui_non_derog.invalidate();
		toggleButton_oui_oui_non_derog.setTouchable(false);
		toggleButton_oui_oui_non_derog.invalidate();
	}
}

void DerogationView::bouton_non_derog()
{
	if(toggleButton_non_oui_non_derog.getState())
	{
		toggleButton_oui_oui_non_derog.forceState(false);
		toggleButton_oui_oui_non_derog.setTouchable(true);
		toggleButton_oui_oui_non_derog.invalidate();
		toggleButton_non_oui_non_derog.setTouchable(false);
		toggleButton_non_oui_non_derog.invalidate();
	}
}

void DerogationView::bouton_moins_derog()
{
	if(u16Time_Derogation != 0)
	{
		if(u16Time_Derogation == 30)
		{
			u16Time_Derogation = 0;
		}
		else u16Time_Derogation--;
	}
	else u16Time_Derogation = 720;

	if(u16Time_Derogation != 0)
	{
		Unicode::snprintf(textAreaBuffer_Derogation, 6, "%02dh%02d", u16Time_Derogation / 60, u16Time_Derogation % 60);
	}
	else Unicode::snprintf(textAreaBuffer_Derogation, 6, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	textArea_valeur_duree_derog.setWildcard(textAreaBuffer_Derogation);
	textArea_valeur_duree_derog.invalidate();
}

void DerogationView::bouton_plus_derog()
{
	if(u16Time_Derogation == 0)
	{
		u16Time_Derogation = 30;
	}
	else if(++u16Time_Derogation > 720)
	{
		u16Time_Derogation = 0;
	}

	if(u16Time_Derogation != 0)
	{
		Unicode::snprintf(textAreaBuffer_Derogation, 6, "%02dh%02d", u16Time_Derogation / 60, u16Time_Derogation % 60);
	}
	else Unicode::snprintf(textAreaBuffer_Derogation, 6, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	textArea_valeur_duree_derog.setWildcard(textAreaBuffer_Derogation);
	textArea_valeur_duree_derog.invalidate();
}

void DerogationView::bouton_plus_consigne()
{
	// Température de consigne dérogation
	if(u16Consigne_Derogation < u16ValMax)
	{
		u16Consigne_Derogation++;
	}
	Unicode::snprintfFloat(textAreaBuffer_Consigne, 6, "%.1f", ((float) u16Consigne_Derogation) / 10);
	textArea_valeur_consigne_derog.setWildcard(textAreaBuffer_Consigne);
	textArea_valeur_consigne_derog.invalidate();
}

void DerogationView::bouton_moins_consigne()
{
	// Température de consigne dérogation
	if(u16Consigne_Derogation > u16ValMin)
	{
		u16Consigne_Derogation--;
	}
	Unicode::snprintfFloat(textAreaBuffer_Consigne, 6, "%.1f", ((float) u16Consigne_Derogation) / 10);
	textArea_valeur_consigne_derog.setWildcard(textAreaBuffer_Consigne);
	textArea_valeur_consigne_derog.invalidate();
}

void DerogationView::timer_10ms()
{
	//
	if(button_gauche_duree_derog.getPressedState())
	{
		if(u8PressionLongue_gauche < 15)
		{
			u8PressionLongue_gauche++;
		}
		else bouton_moins_derog();
	}
	else u8PressionLongue_gauche = 0;
	//
	if(button_droite_duree_derog.getPressedState())
	{
		if(u8PressionLongue_droite < 15)
		{
			u8PressionLongue_droite++;
		}
		else bouton_plus_derog();
	}
	else u8PressionLongue_droite = 0;
	//
	if(button_gauche_consigne_derog.getPressedState())
	{
		if(u8PressionLongue_gauche_consigne < 15)
		{
			u8PressionLongue_gauche_consigne++;
		}
		else bouton_moins_consigne();
	}
	else u8PressionLongue_gauche_consigne = 0;
	//
	if(button_droite_consigne_derog.getPressedState())
	{
		if(u8PressionLongue_droite_consigne < 15)
		{
			u8PressionLongue_droite_consigne++;
		}
		else bouton_plus_consigne();
	}
	else u8PressionLongue_droite_consigne = 0;
}

void DerogationView::bouton_valider()
{
	if(u8ZoneSelect == 0xff)
	{
		if(sConfig_IHM.sMode_RegulExt.Exception != (toggleButton_oui_oui_non_derog.getState() * 2))
		{
			sConfig_IHM.sMode_RegulExt.Exception = toggleButton_oui_oui_non_derog.getState() * 2;
			sConfig_IHM.sMode_RegulExt.u16Time_RegExt_Sablier = u16Time_Derogation;
			sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Sablier = u16Consigne_Derogation;
			presenter->c_user_reg_ext();
		}
		else if(sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Sablier != u16Consigne_Derogation)
		{
			sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Sablier = u16Consigne_Derogation;
			presenter->c_user_reg_ext();
		}
	}
	else
	{
		if(sConfig_IHM.sMode_Zx[u8ZoneSelect].Exception != (toggleButton_oui_oui_non_derog.getState() * 2))
		{
			sConfig_IHM.sMode_Zx[u8ZoneSelect].Exception = toggleButton_oui_oui_non_derog.getState() * 2;
			sConfig_IHM.sMode_Zx[u8ZoneSelect].u16Time_Sablier = u16Time_Derogation;
			sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Sablier = u16Consigne_Derogation;
			presenter->c_user_zx(u8ZoneSelect);
		}
		else if(sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Sablier != u16Consigne_Derogation)
		{
			sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Sablier = u16Consigne_Derogation;
			presenter->c_user_zx(u8ZoneSelect);
		}
	}

	application().gotoZoneScreenNoTransition();
}

void DerogationView::setupScreen()
{
    DerogationViewBase::setupScreen();
}

void DerogationView::tearDownScreen()
{
    DerogationViewBase::tearDownScreen();
}

void DerogationView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void DerogationView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void DerogationView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void DerogationView::changeDate(S_DATE *sDate)
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
