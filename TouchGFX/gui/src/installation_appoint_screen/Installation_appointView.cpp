#include <gui/installation_appoint_screen/Installation_appointView.hpp>

Installation_appointView::Installation_appointView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_APPOINT_CHAUFF_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	u8TypeAppoint = sConfig_IHM.sOption_PAC.TypeAppoint;
	if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE && u8TypeAppoint > ELEC)
	{
		u8TypeAppoint = NO_APPOINT;
	}
	affichage_type_appoint();
	//
	if(sConfig_IHM.sParam_PAC.bModeSecoursDefautPAC)
	{
		toggleButton_si_defaut_pac.forceState(true);
		textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	//
	i8TempExt = sConfig_IHM.sParam_PAC.i8Text_Ref_Appoint;
	Unicode::snprintfFloat(textAreaBuffer_TempExt, 6, "%.1f", (float) i8TempExt);
	textArea_valeur_temp_ext_equilibre.setWildcard(textAreaBuffer_TempExt);

	ePageHystExt = HYST_EXT_APPOINT;
}

void Installation_appointView::setupScreen()
{
    Installation_appointViewBase::setupScreen();
}

void Installation_appointView::tearDownScreen()
{
    Installation_appointViewBase::tearDownScreen();
}

void Installation_appointView::bouton_type_appoint_droite()
{
	if(u8TypeAppoint >= RELEVE_CHAUDIERE || (u8TypeAppoint == ELEC && sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE))
	{
		u8TypeAppoint = NO_APPOINT;
	}
	else u8TypeAppoint++;
	affichage_type_appoint();
}

void Installation_appointView::bouton_type_appoint_gauche()
{
	if(u8TypeAppoint == NO_APPOINT)
	{
		if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE)
		{
			u8TypeAppoint = ELEC;
		}
		else u8TypeAppoint = RELEVE_CHAUDIERE;
	}
	else if(u8TypeAppoint == RELEVE_CHAUDIERE || u8TypeAppoint == APPOINT_CHAUDIERE)
	{
		u8TypeAppoint = ELEC;
	}
	else u8TypeAppoint--;
	affichage_type_appoint();
}

void Installation_appointView::affichage_type_appoint()
{
	switch(u8TypeAppoint)
	{
		default:
			textArea_valeur_type_appoint.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			container_gestion_chaudiere.setVisible(false);
			container_si_defaut_pac.setVisible(false);
			buttonWithLabel_hysteresis_ext.setVisible(false);
			container_temp_ext_equilibre.setVisible(false);
			break;
		case ELEC:
			textArea_valeur_type_appoint.setTypedText(touchgfx::TypedText(T_TEXT_ELECTRIQUE_CENTRE_DEFAUT));
			container_gestion_chaudiere.setVisible(false);
			container_si_defaut_pac.setVisible(true);
			buttonWithLabel_hysteresis_ext.setVisible(true);
			container_temp_ext_equilibre.setVisible(true);
			break;
		case RELEVE_CHAUDIERE:
			textArea_valeur_gestion_chaudiere.setTypedText(touchgfx::TypedText(T_TEXT_RELEVE_CENTRE_DEFAUT));
			textArea_valeur_type_appoint.setTypedText(touchgfx::TypedText(T_TEXT_CHAUDIERE_CENTRE_DEFAUT));
			container_gestion_chaudiere.setVisible(true);
			container_si_defaut_pac.setVisible(true);
			buttonWithLabel_hysteresis_ext.setVisible(true);
			container_temp_ext_equilibre.setVisible(true);
			break;
		case APPOINT_CHAUDIERE:
			textArea_valeur_gestion_chaudiere.setTypedText(touchgfx::TypedText(T_TEXT_APPOINT_CENTRE_DEFAUT));
			textArea_valeur_type_appoint.setTypedText(touchgfx::TypedText(T_TEXT_CHAUDIERE_CENTRE_DEFAUT));
			container_gestion_chaudiere.setVisible(true);
			container_si_defaut_pac.setVisible(true);
			buttonWithLabel_hysteresis_ext.setVisible(true);
			container_temp_ext_equilibre.setVisible(true);
			break;
	}
	textArea_valeur_gestion_chaudiere.invalidate();
	textArea_valeur_type_appoint.invalidate();
	container_gestion_chaudiere.invalidate();
	container_si_defaut_pac.invalidate();
	buttonWithLabel_hysteresis_ext.invalidate();
	container_temp_ext_equilibre.invalidate();
}

void Installation_appointView::bouton_temp_equilibre_plus()
{
	if(i8TempExt < 40)
	{
		i8TempExt++;
		Unicode::snprintfFloat(textAreaBuffer_TempExt, 6, "%.1f", (float) i8TempExt);
		textArea_valeur_temp_ext_equilibre.setWildcard(textAreaBuffer_TempExt);
		textArea_valeur_temp_ext_equilibre.invalidate();
	}
}

void Installation_appointView::bouton_temp_equilibre_moins()
{
	if(i8TempExt > -20)
	{
		i8TempExt--;
		Unicode::snprintfFloat(textAreaBuffer_TempExt, 6, "%.1f", (float) i8TempExt);
		textArea_valeur_temp_ext_equilibre.setWildcard(textAreaBuffer_TempExt);
		textArea_valeur_temp_ext_equilibre.invalidate();
	}
}

void Installation_appointView::bouton_appoint_on_off()
{
	if(toggleButton_si_defaut_pac.getState())
	{
		textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_si_defaut_pac.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_si_defaut_pac.invalidate();
}

void Installation_appointView::bouton_hysteresis_ext()
{
	// Hysteresis
	eHysteresis = HYST_EXT;
	application().gotoInstallation_hysteresisScreenNoTransition();
}

void Installation_appointView::bouton_chaudiere()
{
	if(textArea_valeur_gestion_chaudiere.getTypedText().getId() == touchgfx::TypedText(T_TEXT_RELEVE_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_gestion_chaudiere.setTypedText(touchgfx::TypedText(T_TEXT_CHAUDIERE_CENTRE_DEFAUT));
		u8TypeAppoint = 4;
	}
	else
	{
		textArea_valeur_gestion_chaudiere.setTypedText(touchgfx::TypedText(T_TEXT_RELEVE_CENTRE_DEFAUT));
		u8TypeAppoint = 3;
	}
	textArea_valeur_gestion_chaudiere.invalidate();
}

void Installation_appointView::bouton_valider()
{
	sConfig_IHM.sOption_PAC.TypeAppoint = u8TypeAppoint;
	//
	if(toggleButton_si_defaut_pac.getState())
	{
		sConfig_IHM.sParam_PAC.bModeSecoursDefautPAC = 1;
	}
	else sConfig_IHM.sParam_PAC.bModeSecoursDefautPAC = 0;
	//
	sConfig_IHM.sParam_PAC.i8Text_Ref_Appoint = i8TempExt;
	//
	if(sConfig_IHM.sOption_PAC.TypeAppoint != ELEC)
	{
		sConfig_IHM.sParam_ECS.bTypeAppointECS = 0;
	}
	// Multiple trames
	presenter->c_install_param();
	presenter->c_install_ecs();
	application().gotoInstallation_hydrauliqueScreenNoTransition();
}

void Installation_appointView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_appointView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_appointView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_appointView::changeDate(S_DATE *sDate)
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
