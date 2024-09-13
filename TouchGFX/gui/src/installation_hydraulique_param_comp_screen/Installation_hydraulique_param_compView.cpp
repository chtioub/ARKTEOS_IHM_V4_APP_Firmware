#include <gui/installation_hydraulique_param_comp_screen/Installation_hydraulique_param_compView.hpp>

Installation_hydraulique_param_compView::Installation_hydraulique_param_compView()
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
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		textArea_question_oui_non_chauffage.setTypedText(touchgfx::TypedText(T_TEXT_CHAUFFAGE_CENTRE_DEFAUT));
		textArea_question_oui_non_rafraichissement.setTypedText(touchgfx::TypedText(T_TEXT_RAFRAICHISSEMENT_CENTRE_DEFAUT));
		Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_COMPLEMENTAIRE_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_COMPLEMENTAIRE_ZONE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		//
		if(sConfig_IHM.sParam_RegulExt.bModeChaud == 0)
		{
			toggleButton_oui_oui_non_chauffage.forceState(false);
			toggleButton_oui_oui_non_chauffage.setTouchable(true);
			toggleButton_non_oui_non_chauffage.forceState(true);
			toggleButton_non_oui_non_chauffage.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_chauffage.forceState(true);
			toggleButton_oui_oui_non_chauffage.setTouchable(false);
			toggleButton_non_oui_non_chauffage.forceState(false);
			toggleButton_non_oui_non_chauffage.setTouchable(true);
		}
		//
		if(sConfig_IHM.sParam_RegulExt.bModeFroid == 0)
		{
			toggleButton_oui_oui_non_chauffage.forceState(false);
			toggleButton_oui_oui_non_chauffage.setTouchable(true);
			toggleButton_non_oui_non_chauffage.forceState(true);
			toggleButton_non_oui_non_chauffage.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_chauffage.forceState(true);
			toggleButton_oui_oui_non_chauffage.setTouchable(false);
			toggleButton_non_oui_non_chauffage.forceState(false);
			toggleButton_non_oui_non_chauffage.setTouchable(true);
		}
	}
//	if()
//		container_temp_depart_eau_raf.setVisible(true);
}

void Installation_hydraulique_param_compView::setupScreen()
{
    Installation_hydraulique_param_compViewBase::setupScreen();
}

void Installation_hydraulique_param_compView::tearDownScreen()
{
    Installation_hydraulique_param_compViewBase::tearDownScreen();
}

void Installation_hydraulique_param_compView::bouton_retour()
{
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
//	else application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydraulique_param_compView::bouton_valider()
{
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
	else
	{
//		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_hydraulique_param_compView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_param_compView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_param_compView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_param_compView::changeDate(S_DATE *sDate)
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
