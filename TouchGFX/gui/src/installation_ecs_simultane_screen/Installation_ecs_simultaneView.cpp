#include <gui/installation_ecs_simultane_screen/Installation_ecs_simultaneView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecs_simultaneView::Installation_ecs_simultaneView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);

	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_MODE_SIMULTANE_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	bGestionSimultanee = sParam_ECS_temp.bGestionSimultanee;
	u4DeltaLoiDeauSimultanee = sParam_ECS_temp.u4DeltaLoiDeauSimultanee;
	u3MiniOuvertureVanne = sParam_ECS_temp.u3MiniOuvertureVanne;
	u2TpsFinSimu = sParam_ECS_temp.u2TpsFinSimu;

	//Legionel ON/Off
	if(bGestionSimultanee == 0)
	{
		toggleButton_oui_oui_non_simultane_ecs.forceState(false);
		toggleButton_oui_oui_non_simultane_ecs.setTouchable(true);
		toggleButton_non_oui_non_simultane_ecs.forceState(true);
		toggleButton_non_oui_non_simultane_ecs.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_simultane_ecs.forceState(true);
		toggleButton_oui_oui_non_simultane_ecs.setTouchable(false);
		toggleButton_non_oui_non_simultane_ecs.forceState(false);
		toggleButton_non_oui_non_simultane_ecs.setTouchable(true);
	}
	toggleButton_oui_oui_non_simultane_ecs.invalidate();
	toggleButton_non_oui_non_simultane_ecs.invalidate();


	//Réduc loi d'eau
	update_reduction_loi_deau();
	//Temps max en simu ECS
	update_temps_max();
	//Pourcentage V3V
	update_percent_vanne();
}

void  Installation_ecs_simultaneView::update_reduction_loi_deau()
{
	Unicode::snprintf(textAreaBuffer_ReducLoiDeau, 5, "%d", u4DeltaLoiDeauSimultanee);
	textArea_valeur_reduc_temp_consigne_eau_ecs.setWildcard(textAreaBuffer_ReducLoiDeau);
	textArea_valeur_reduc_temp_consigne_eau_ecs.invalidate();
}

void  Installation_ecs_simultaneView::update_temps_max()
{
	switch (u2TpsFinSimu)
	{
		case 0:
			Unicode::snprintf(textAreaBuffer_Temps_Fin_Simu, 24,touchgfx::TypedText(T_TEXT_1H).getText());
			break;
		case 1:
			Unicode::snprintf(textAreaBuffer_Temps_Fin_Simu, 24,touchgfx::TypedText(T_TEXT_2H).getText());
			break;
		case 2:
			Unicode::snprintf(textAreaBuffer_Temps_Fin_Simu, 24,touchgfx::TypedText(T_TEXT_3H).getText());
			break;
		case 3:
			Unicode::snprintf(textAreaBuffer_Temps_Fin_Simu, 24,touchgfx::TypedText(T_TEXT_PAS_DE_LIMITATION).getText());
			break;
	}

	textArea_valeur_temps_max_simultane.setWildcard(textAreaBuffer_Temps_Fin_Simu);
	textArea_valeur_temps_max_simultane.invalidate();
}

void  Installation_ecs_simultaneView::update_percent_vanne()
{
	switch (u3MiniOuvertureVanne)
	{
		case 0:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_PAS_DE_LIMITATION).getText());
			break;
		case 1:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_30).getText());
			break;
		case 2:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_40).getText());
			break;
		case 3:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_50).getText());
			break;
		case 4:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_60).getText());
			break;
		case 5:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_70).getText());
			break;
		case 6:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_80).getText());
			break;
		case 7:
			Unicode::snprintf(textAreaBuffer_PercentV3V, 18,touchgfx::TypedText(T_TEXT_MIN_V3V_ECS_90).getText());
			break;
	}

	textArea_valeur_ouverture_min_vanne_ecs.setWildcard(textAreaBuffer_PercentV3V);
	textArea_valeur_ouverture_min_vanne_ecs.invalidate();
}

void Installation_ecs_simultaneView::bouton_gauche_temps_simultane()
{
	if (u2TpsFinSimu > 0) u2TpsFinSimu--;
	else u2TpsFinSimu = 3;
	update_temps_max();
}

void Installation_ecs_simultaneView::bouton_droit_temps_simultane()
{
	if (u2TpsFinSimu < 3) u2TpsFinSimu++;
	else u2TpsFinSimu = 0;
	update_temps_max();
}

void Installation_ecs_simultaneView::bouton_gauche_temp_loi_deau()
{
	if (u4DeltaLoiDeauSimultanee > 0) u4DeltaLoiDeauSimultanee--;
	else u4DeltaLoiDeauSimultanee = 15;
	update_reduction_loi_deau();
}

void Installation_ecs_simultaneView::bouton_droit_temp_loi_deau()
{
	if (u4DeltaLoiDeauSimultanee < 15) u4DeltaLoiDeauSimultanee++;
	else u4DeltaLoiDeauSimultanee = 0;
	update_reduction_loi_deau();
}

void Installation_ecs_simultaneView::bouton_gauche_ouverture_vanne()
{
	if (u3MiniOuvertureVanne > 0) u3MiniOuvertureVanne--;
	else u3MiniOuvertureVanne = 7;
	update_percent_vanne();
}

void Installation_ecs_simultaneView::bouton_droit_ouverture_vanne()
{
	if (u3MiniOuvertureVanne < 7) u3MiniOuvertureVanne++;
	else u3MiniOuvertureVanne = 0;
	update_percent_vanne();
}

void Installation_ecs_simultaneView::bouton_oui()
{
	if(toggleButton_oui_oui_non_simultane_ecs.getState())
	{
		toggleButton_non_oui_non_simultane_ecs.forceState(false);
		toggleButton_non_oui_non_simultane_ecs.setTouchable(true);
		toggleButton_non_oui_non_simultane_ecs.invalidate();
		toggleButton_oui_oui_non_simultane_ecs.setTouchable(false);
		toggleButton_oui_oui_non_simultane_ecs.invalidate();
	}
	bGestionSimultanee = 1;
}

void Installation_ecs_simultaneView::bouton_non()
{
	if(toggleButton_non_oui_non_simultane_ecs.getState())
	{
		toggleButton_oui_oui_non_simultane_ecs.forceState(false);
		toggleButton_oui_oui_non_simultane_ecs.setTouchable(true);
		toggleButton_oui_oui_non_simultane_ecs.invalidate();
		toggleButton_non_oui_non_simultane_ecs.setTouchable(false);
		toggleButton_non_oui_non_simultane_ecs.invalidate();
	}
	bGestionSimultanee = 0;
}

void Installation_ecs_simultaneView::bouton_valider()
{

	sParam_ECS_temp.bGestionSimultanee = bGestionSimultanee & 1;
	sParam_ECS_temp.u4DeltaLoiDeauSimultanee = u4DeltaLoiDeauSimultanee & 0b1111;
	sParam_ECS_temp.u3MiniOuvertureVanne = u3MiniOuvertureVanne & 0b111;
	sParam_ECS_temp.u2TpsFinSimu = u2TpsFinSimu & 0b11;

	sConfig_IHM.sParam_ECS.bGestionSimultanee = bGestionSimultanee & 1;
	sConfig_IHM.sParam_ECS.u4DeltaLoiDeauSimultanee = u4DeltaLoiDeauSimultanee & 0b1111;
	sConfig_IHM.sParam_ECS.u3MiniOuvertureVanne = u3MiniOuvertureVanne & 0b111;
	sConfig_IHM.sParam_ECS.u2TpsFinSimu = u2TpsFinSimu & 0b11;

	presenter->c_install_ecs();
}


void Installation_ecs_simultaneView::setupScreen()
{
    Installation_ecs_simultaneViewBase::setupScreen();
}

void Installation_ecs_simultaneView::tearDownScreen()
{
    Installation_ecs_simultaneViewBase::tearDownScreen();
}

void Installation_ecs_simultaneView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_simultaneView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_simultaneView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_simultaneView::changeDate(S_DATE *sDate)
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
