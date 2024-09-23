#include <gui/installation_hydraulique_gestion_circulateur_screen/Installation_hydraulique_gestion_circulateurView.hpp>

Installation_hydraulique_gestion_circulateurView::Installation_hydraulique_gestion_circulateurView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_GESTION_CIRCULATEUR_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);

	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_GRUNDFOS)
	{
		textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
	}
	else
	{
		container_vitesse_circulateur.setVisible(false);
		textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
	}
	//
	u8VitesseCirculateur = sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.GestionCirculateur;
	vitesseCirculateur();
	// Marche forcée
	if(sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bCirculateurForce == 0)
	{
		toggleButton_oui_oui_non_marche_forcee.forceState(false);
		toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
		toggleButton_non_oui_non_marche_forcee.forceState(true);
		toggleButton_non_oui_non_marche_forcee.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_marche_forcee.forceState(true);
		toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
		toggleButton_non_oui_non_marche_forcee.forceState(false);
		toggleButton_non_oui_non_marche_forcee.setTouchable(true);
	}
}

void Installation_hydraulique_gestion_circulateurView::setupScreen()
{
    Installation_hydraulique_gestion_circulateurViewBase::setupScreen();
}

void Installation_hydraulique_gestion_circulateurView::tearDownScreen()
{
    Installation_hydraulique_gestion_circulateurViewBase::tearDownScreen();
}

void Installation_hydraulique_gestion_circulateurView::vitesseCirculateur()
{
    switch(u8VitesseCirculateur)
    {
		default:
		case GC_AUTO:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT));
			break;
		case GC_V40:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT));
			break;
		case GC_V50:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT));
			break;
		case GC_V60:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT));
			break;
		case GC_V70:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT));
			break;
		case GC_V80:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT));
			break;
		case GC_V90:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT));
			break;
		case GC_V100:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT));
			break;
    }
    textArea_valeur_vitesse_circulateur.invalidate();
}

void Installation_hydraulique_gestion_circulateurView::bouton_moins_vitesse_circ()
{
	if(u8VitesseCirculateur == GC_AUTO)
	{
		u8VitesseCirculateur = GC_V100;
	}
	else u8VitesseCirculateur--;
	vitesseCirculateur();
}

void Installation_hydraulique_gestion_circulateurView::bouton_plus_vitesse_circ()
{
	if(++u8VitesseCirculateur > GC_V100)
	{
		u8VitesseCirculateur = GC_AUTO;
	}
	vitesseCirculateur();
}

void Installation_hydraulique_gestion_circulateurView::bouton_non_marche_forcee()
{
	if(toggleButton_non_oui_non_marche_forcee.getState())
	{
		toggleButton_oui_oui_non_marche_forcee.forceState(false);
		toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
		toggleButton_oui_oui_non_marche_forcee.invalidate();
		toggleButton_non_oui_non_marche_forcee.setTouchable(false);
		toggleButton_non_oui_non_marche_forcee.invalidate();
	}
}

void Installation_hydraulique_gestion_circulateurView::bouton_oui_marche_forcee()
{
	if(toggleButton_oui_oui_non_marche_forcee.getState())
	{
		toggleButton_non_oui_non_marche_forcee.forceState(false);
		toggleButton_non_oui_non_marche_forcee.setTouchable(true);
		toggleButton_non_oui_non_marche_forcee.invalidate();
		toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
		toggleButton_oui_oui_non_marche_forcee.invalidate();
	}
}

void Installation_hydraulique_gestion_circulateurView::bouton_gauche_type_circulateur()
{
	//
	if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
	{
		textArea_circuit_primaire.setVisible(true);
		container_vitesse_circulateur.setVisible(true);
		textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
	}
	else
	{
		textArea_circuit_primaire.setVisible(false);
		container_vitesse_circulateur.setVisible(false);
		textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
	}
	textArea_circuit_primaire.invalidate();
	container_vitesse_circulateur.invalidate();
	textArea_valeur_type_circulateur.invalidate();
}

void Installation_hydraulique_gestion_circulateurView::bouton_droite_type_circulateur()
{
	//
	if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
	{
		textArea_circuit_primaire.setVisible(true);
		container_vitesse_circulateur.setVisible(true);
		textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
	}
	else
	{
		textArea_circuit_primaire.setVisible(false);
		container_vitesse_circulateur.setVisible(false);
		textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
	}
	textArea_circuit_primaire.invalidate();
	container_vitesse_circulateur.invalidate();
	textArea_valeur_type_circulateur.invalidate();
}

void Installation_hydraulique_gestion_circulateurView::bouton_valider()
{
	// Vitesse circulateur
	sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.GestionCirculateur = u8VitesseCirculateur;
	// Marche forcée
	if(toggleButton_oui_oui_non_marche_forcee.getState())
	{
		sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bCirculateurForce = 1;
	}
	else sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bCirculateurForce = 0;
	// Type circulateur
	if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
	{
		sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bTypeCirculateur = TYPE_RELAIS;
	}
	else sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bTypeCirculateur = TYPE_GRUNDFOS;
	//
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_emetteur.plan_rad_vent.GestionCirculateur = sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.GestionCirculateur;
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_emetteur.plan_rad_vent.bTypeCirculateur = sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bTypeCirculateur;
	sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone].type_emetteur.plan_rad_vent.bCirculateurForce = sConfig_Hydrau_temp.sParamZx.type_emetteur.plan_rad_vent.bCirculateurForce;
	//
	presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
	application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydraulique_gestion_circulateurView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_gestion_circulateurView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_gestion_circulateurView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_gestion_circulateurView::changeDate(S_DATE *sDate)
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
