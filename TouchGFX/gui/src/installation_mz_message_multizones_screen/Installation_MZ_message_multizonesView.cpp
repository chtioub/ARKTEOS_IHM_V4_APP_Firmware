#include <gui/installation_mz_message_multizones_screen/Installation_MZ_message_multizonesView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_MZ_message_multizonesView::Installation_MZ_message_multizonesView()
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
		if (bRegroupementZoneTemp)
		{
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_REGROUPEMENT_ZONES_CENTRE).getText());
			container_zones_seules.setVisible(false);
			container_groupes.setVisible(true);

//			textArea_text_blanc_groupes.setVisible(true);
//			textArea_text_rouge_groupes.setVisible(true);
//			textArea_text_blanc_zones_seules.setVisible(false);
//			textArea_text_rouge_zones_seules.setVisible(false);
//			textArea_text_blanc_groupes.invalidate();
//			textArea_text_rouge_groupes.invalidate();
//			textArea_text_blanc_zones_seules.invalidate();
//			textArea_text_rouge_zones_seules.invalidate();
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAMETRAGE_ZONES_CENTRE).getText());
			container_zones_seules.setVisible(true);
			container_groupes.setVisible(false);
//			textArea_text_blanc_groupes.setVisible(false);
//			textArea_text_rouge_groupes.setVisible(false);
//			textArea_text_blanc_zones_seules.setVisible(true);
//			textArea_text_rouge_zones_seules.setVisible(true);
//			textArea_text_blanc_groupes.invalidate();
//			textArea_text_rouge_groupes.invalidate();
//			textArea_text_blanc_zones_seules.invalidate();
//			textArea_text_rouge_zones_seules.invalidate();
		}
		container_zones_seules.invalidate();
		container_groupes.invalidate();
		barre_titre.titre(textAreaBuffer_Titre);
}

void Installation_MZ_message_multizonesView::setupScreen()
{
	Installation_MZ_message_multizonesViewBase::setupScreen();
}

void Installation_MZ_message_multizonesView::tearDownScreen()
{
	Installation_MZ_message_multizonesViewBase::tearDownScreen();
}

void Installation_MZ_message_multizonesView::bouton_retour()
{
	application().gotoInstallation_hydrauliqueScreenNoTransition();
}

void Installation_MZ_message_multizonesView::bouton_valider()
{
//	if (bRegroupementZoneTemp)
//	{
//		application().gotoInstallation_MZ_parametrage_groupesScreenNoTransition();
//	}
//	else
//	{
//		//application().gotoInstallation_MZ_param_ou_regroupement_zonesScreenNoTransition();
//	}

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
//	application().gotoInstallationScreenNoTransition();
}

void Installation_MZ_message_multizonesView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	// Chauffe dalle
//	if(sConfig_IHM->sParam_PAC.u8CTime_Sablier_Dalle_Jour != sConfig_IHM_old.sParam_PAC.u8CTime_Sablier_Dalle_Jour)
//	{
//		if(sConfig_IHM->sParam_PAC.u8CTime_Sablier_Dalle_Jour != 0)
//		{
//			buttonWithLabel_mise_chauffe_dalle_on.setVisible(true);
//		}
//		else buttonWithLabel_mise_chauffe_dalle_on.setVisible(false);
//		buttonWithLabel_mise_chauffe_dalle_on.invalidate();
//	}
//	//
//	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void Installation_MZ_message_multizonesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_message_multizonesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_message_multizonesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_message_multizonesView::changeDate(S_DATE *sDate)
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
