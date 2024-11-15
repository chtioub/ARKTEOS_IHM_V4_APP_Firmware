#include <gui/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>


Installation_MZ_param_complementaires_froidView::Installation_MZ_param_complementaires_froidView()
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

	//	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_INSTALLATION_CENTRE_DEFAUT).getText());
	//	barre_titre.titre(textAreaBuffer_Titre);

		//sParamZxMZtemp[] sConfig_Hydrau_temp.

		Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_PARAMETRES_CENTRE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
		Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
		//Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", (sConfig_Hydrau_temp.u8NumZone == 8) ? 'A' : 'B');
		Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
		barre_titre.titre(textAreaBuffer_Titre);

//		Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, textAreaBuffer_Question, 10);
//		textArea_question_oui_non.setWildcard(textAreaBuffer_Question);
//		textArea_question_oui_non.invalidate();
}

void Installation_MZ_param_complementaires_froidView::setupScreen()
{
    Installation_MZ_param_complementaires_froidViewBase::setupScreen();
}

void Installation_MZ_param_complementaires_froidView::tearDownScreen()
{
    Installation_MZ_param_complementaires_froidViewBase::tearDownScreen();
}


void Installation_MZ_param_complementaires_froidView::bouton_valider()
{
//	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));//SER
//	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
//	sConfig_Hydrau_temp
//	sConfig_IHM.sParam_PAC.TypeRegul = sConfig_Hydrau_temp.u8TypeRegul;
//	sConfig_IHM.sParam_PAC.numEsclave = u8Nb_PAC - 1;
//	sConfig_IHM.sOption_PAC.sZone = sConfig_Hydrau_temp.sZones;
//	presenter->c_install_param();
//	if(bCartePhoenix == false)
//	{
//		// Vitesse circulateur
//		sConfig_IHM.sParam_PAC.eGestionCirculateurPrimaire = u8VitesseCirculateur;
//		// Marche forcée
//		if(toggleButton_oui_oui_non_marche_forcee.getState())
//		{
//			sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce = 1;
//		}
//		else sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce = 0;
//		// Type circulateur
//		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sParam_PAC.TypeCirculateur = TYPE_RELAIS;
//		}
//		else sConfig_IHM.sParam_PAC.TypeCirculateur = TYPE_GRUNDFOS;
//		//
//		presenter->c_install_param();
//	}
//	else
//	{
//		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_GRUNDFOS;
//		}
//		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_WILO;
//		}
//		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_RELAIS;
//		}
//		//
//		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = u8VitesseCirculateur;
//		// Marche forcée
//		if(toggleButton_oui_oui_non_marche_forcee.getState())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce = 1;
//		}
//		else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce = 0;
//		//
//		presenter->c_usine_phoenix(0);
//	}
	//application().gotoInstallationScreenNoTransition();
}

void Installation_MZ_param_complementaires_froidView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	;
}

void Installation_MZ_param_complementaires_froidView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_param_complementaires_froidView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_complementaires_froidView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_complementaires_froidView::changeDate(S_DATE *sDate)
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
