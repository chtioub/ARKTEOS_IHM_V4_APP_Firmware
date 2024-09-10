#include <gui/installation_circuit_primaire_screen/Installation_circuit_primaireView.hpp>

Installation_circuit_primaireView::Installation_circuit_primaireView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_CIRCUIT_PRIM_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sModele_PAC.u8ModelePAC <= GEOTWIN_IV)
	{
		bCartePhoenix = false;
	}
	else bCartePhoenix = true;
	//
	if(bCartePhoenix == false)
	{
		container_type_circulateur.setX(15);
		//
		if(sConfig_IHM.sParam_PAC.TypeCirculateur == TYPE_GRUNDFOS)
		{
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
		}
		else
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		//
		u8VitesseCirculateur = sConfig_IHM.sParam_PAC.eGestionCirculateurPrimaire;
		vitesseCirculateur();
		// Marche forcée
		if(sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce == 0)
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
	else
	{
		container_type_circulateur.setX(486);
		textArea_circuit_primaire.setVisible(false);
		// Type Circulateur
		switch(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire)
		{
			case TYPE_GRUNDFOS:
				textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT));
				break;
			case TYPE_WILO:
				textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT));
				break;
			case TYPE_RELAIS:
				textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
				break;
		}
		//
		u8VitesseCirculateur = sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire;
		vitesseCirculateur();
		// Marche forcée
		if(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce == 0)
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
}

void Installation_circuit_primaireView::setupScreen()
{
    Installation_circuit_primaireViewBase::setupScreen();
}

void Installation_circuit_primaireView::tearDownScreen()
{
    Installation_circuit_primaireViewBase::tearDownScreen();
}

void Installation_circuit_primaireView::vitesseCirculateur()
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

void Installation_circuit_primaireView::bouton_moins_vitesse_circ()
{
	if(u8VitesseCirculateur == GC_AUTO)
	{
		u8VitesseCirculateur = GC_V100;
	}
	else u8VitesseCirculateur--;
	vitesseCirculateur();
}

void Installation_circuit_primaireView::bouton_plus_vitesse_circ()
{
	if(++u8VitesseCirculateur > GC_V100)
	{
		u8VitesseCirculateur = GC_AUTO;
	}
	vitesseCirculateur();
}

void Installation_circuit_primaireView::bouton_non_marche_forcee()
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

void Installation_circuit_primaireView::bouton_oui_marche_forcee()
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

void Installation_circuit_primaireView::bouton_gauche_type_circulateur()
{
	if(bCartePhoenix == false)
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
	else
	{
		// Type Circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT));
		}
		textArea_circuit_primaire.setVisible(false);
		textArea_circuit_primaire.invalidate();
		container_vitesse_circulateur.invalidate();
		textArea_valeur_type_circulateur.invalidate();
	}
}

void Installation_circuit_primaireView::bouton_droite_type_circulateur()
{
	if(bCartePhoenix == false)
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
	else
	{
		// Type Circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT));
		}
		textArea_circuit_primaire.setVisible(false);
		textArea_circuit_primaire.invalidate();
		container_vitesse_circulateur.invalidate();
		textArea_valeur_type_circulateur.invalidate();
	}
}

void Installation_circuit_primaireView::bouton_valider()
{
	if(bCartePhoenix == false)
	{
		// Vitesse circulateur
		sConfig_IHM.sParam_PAC.eGestionCirculateurPrimaire = u8VitesseCirculateur;
		// Marche forcée
		if(toggleButton_oui_oui_non_marche_forcee.getState())
		{
			sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce = 1;
		}
		else sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce = 0;
		// Type circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sParam_PAC.TypeCirculateur = TYPE_RELAIS;
		}
		else sConfig_IHM.sParam_PAC.TypeCirculateur = TYPE_GRUNDFOS;
		//
		presenter->c_install_param();
	}
	else
	{
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_GRUNDFOS;
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_WILO;
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_RELAIS;
		}
		//
		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = u8VitesseCirculateur;
		// Marche forcée
		if(toggleButton_oui_oui_non_marche_forcee.getState())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce = 1;
		}
		else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce = 0;
		//
		presenter->c_usine_phoenix(0);
	}
	application().gotoInstallationScreenNoTransition();
}

void Installation_circuit_primaireView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_circuit_primaireView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_circuit_primaireView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_circuit_primaireView::changeDate(S_DATE *sDate)
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
