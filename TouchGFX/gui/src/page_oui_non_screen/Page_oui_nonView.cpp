#include <gui/page_oui_non_screen/Page_oui_nonView.hpp>

Page_oui_nonView::Page_oui_nonView()
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
	// Init du bouton
	toggleButton_oui_oui_non.forceState(false);
	toggleButton_oui_oui_non.setTouchable(true);
	toggleButton_non_oui_non.forceState(true);
	toggleButton_non_oui_non.setTouchable(false);
	//
	switch(eOuiNon)
	{
		case OUI_NON_RAZ_CONF_USINE:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RAZ_CONFIG_USINE_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_CONFIG_USINE_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_CONFIG_USINE_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_CODE_INST:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RAZ_CODE_INSTALL_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_CODE_INSTALL_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_CODE_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_CODE_MAIN:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RAZ_CODE_MAINT_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_CODE_MAINT_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_CODE_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_HISTO_ERREUR:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RAZ_HISTO_ERREUR_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_HISTO_ERREUR_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_HISTO_ERREUR_CENTRE_DEFAUT));
			break;
		case OUI_NON_SHUNT_TEMPO:
			if(sConfig_IHM.sParam_SAV.bShuntTempo)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SHUNT_TEMPO_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_SHUNT_TEMPO_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_SHUNT_TEMPO_CENTRE_DEFAUT));
			break;
		case OUI_NON_MODE_SECOURS:
			// Init du bouton
			if(sConfig_IHM.sMode_PAC.bSecours)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SECOURS_PAC_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_SECOURS_PAC_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_SECOURS_CENTRE_DEFAUT));
			break;
		case OUI_NON_MODE_DATE:
			// Affichage du texte
			textArea_date_heure.setVisible(true);
			// Affichage du titre
		    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_DATE_HEURE_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_DATE_HEURE_CENTRE_DEFAUT));
			break;
		case OUI_NON_CUMUL:
			// Affichage du texte
			textArea_cumul_energie.setVisible(true);
			// Affichage du titre
		    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_TITRE_CUMUL_ENERGIE_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_CUMUL_ENERGIE_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_CONF_INSTALL:
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_RAZ_CONFIG_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_CONFIG_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
			textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_CONFIG_CENTRE_DEFAUT));
			break;
		case OUI_NON_RESTART:
		case OUI_NON_RESTART_USINE:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RESTART_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RESTART_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RESTART_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_SOFT_FLASH:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RAZ_SOFT_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_SOFT_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_SOFT_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_LOG_ETHER:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RAZ_LOG_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_LOG_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_LOG_CENTRE_DEFAUT));
			break;
		case OUI_NON_RESTART_IHM:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RESTART_IHM_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RESTART_IHM_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RESTART_IHM_CENTRE_DEFAUT));
			break;
		case OUI_NON_MODE_SECOURS_ECS:
			// Init du bouton
			if(sConfig_IHM.sMode_ECS.bUserECSSecours)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Affichage du texte
			textArea_secours_ecs.setVisible(true);
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SECOURS_ECS_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_SECOURS_CENTRE_DEFAUT));
			break;
		case OUI_NON_MODE_SECOURS_PRESSION :
			if(sStatut_PAC.bDerogationPression != 0)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SECOURS_PRESSION_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_SECOURS_PRESSION_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_DEROG_PRESSION_CENTRE_DEFAUT));
			break;
		case OUI_NON_DEROG_PRESSION_BP:
			if(sStatut_PAC.bDerogationPressionBP != 0)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_DEROG_PRESSION_BP_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_DEROG_PRESSION_BP_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_DEROG_PRESSION_CENTRE_DEFAUT));
			break;
		case OUI_NON_MARCHE_GENERAL:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MARCHE_GENERAL_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_MARCHE_GENERAL_CENTRE_DEFAUT));
			break;
		case OUI_NON_ARRET_GENERAL:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_ARRET_GENERAL_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_GENERAL_CENTRE_DEFAUT));
			break;
		case OUI_NON_CHAUFFE_DALLE:
			// Bouton oui actif si déjà en chauffe de dalle
			for(int i = 0; i < 8; i++)
			{
				if(sConfig_IHM.sMode_Zx[i].Exception == DALLE)
				{
					toggleButton_oui_oui_non.forceState(true);
					toggleButton_oui_oui_non.setTouchable(false);
					toggleButton_non_oui_non.forceState(false);
					toggleButton_non_oui_non.setTouchable(true);
					break;
				}
			}
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_MISE_CHAUFFE_DALLE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setVisible(false);
			textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_CHAUFFE_DALLE_CENTRE_DEFAUT));
			break;
		case OUI_NON_FREECOOLING:
			// Init du bouton
			if((sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV && sConfig_IHM.sConfig_PAC.ConfigGeo.bFreecooling) || (sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA && sConfig_IHM.sConfig_PAC.ConfigGeoInverter.bFreecooling))
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_FREECOOLING_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_FREECOOLING_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
			textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_FREECOOLING_CENTRE_DEFAUT));
			break;
		case OUI_NON_SIMULTANE_PISCINE:
			if(sConfig_IHM.sParam_Piscine.bGestionSimultanee)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MODE_SIMULTANE_PISCINE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setVisible(false);
			textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_MODE_SIMULTANE_PISCINE_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_TPS_FONCT:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_RAZ_TPS_FONCT_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_CENTRE_DEFAUT));
			break;
		case OUI_NON_RAZ_ENERGIES:
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_RAZ_ENERGIES_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RAZ_ENERGIES_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RAZ_CENTRE_DEFAUT));
			break;
		case OUI_NON_RESIST_TERM:
			if(sConfig_IHM.sParam_PAC.bConfigCascade120R)
			{
				toggleButton_oui_oui_non.forceState(true);
				toggleButton_oui_oui_non.setTouchable(false);
				toggleButton_non_oui_non.forceState(false);
				toggleButton_non_oui_non.setTouchable(true);
			}
			// Titre
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RESISTANCE_TERMINAISON_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
			textArea_texte_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_TEXTE_RESISTANCE_TERMINAISON_CENTRE_DEFAUT));
			textArea_texte_oui_non.setVisible(true);
		    textArea_question_oui_non.setTypedText(touchgfx::TypedText(T_TEXT_QUESTION_RESISTANCE_TERMINAISON_CENTRE_DEFAUT));
			break;
	}
}

void Page_oui_nonView::setupScreen()
{
    Page_oui_nonViewBase::setupScreen();
}

void Page_oui_nonView::tearDownScreen()
{
    Page_oui_nonViewBase::tearDownScreen();
}

void Page_oui_nonView::bouton_non_page_oui_non()
{
	if(toggleButton_non_oui_non.getState())
	{
		toggleButton_oui_oui_non.forceState(false);
		toggleButton_oui_oui_non.setTouchable(true);
		toggleButton_oui_oui_non.invalidate();
		toggleButton_non_oui_non.setTouchable(false);
		toggleButton_non_oui_non.invalidate();
	}
}

void Page_oui_nonView::bouton_oui_page_oui_non()
{
	if(toggleButton_oui_oui_non.getState())
	{
		toggleButton_non_oui_non.forceState(false);
		toggleButton_non_oui_non.setTouchable(true);
		toggleButton_non_oui_non.invalidate();
		toggleButton_oui_oui_non.setTouchable(false);
		toggleButton_oui_oui_non.invalidate();
	}
}

void Page_oui_nonView::bouton_retour()
{
	switch(eOuiNon)
	{
		case OUI_NON_RAZ_CONF_USINE:
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_RAZ_CODE_INST:
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_RAZ_CODE_MAIN:
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_RAZ_HISTO_ERREUR:
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_SHUNT_TEMPO:
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_MODE_SECOURS:
			application().gotoSecoursScreenNoTransition();
			break;
		case OUI_NON_MODE_DATE:
			application().gotoDate_heureScreenNoTransition();
			break;
		case OUI_NON_CUMUL:
			application().gotoEnergies_cumulScreenNoTransition();
			break;
		case OUI_NON_RAZ_CONF_INSTALL:
			application().gotoInstallationScreenNoTransition();
			break;
		case OUI_NON_RESTART:
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_RESTART_USINE:
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RAZ_SOFT_FLASH:
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RAZ_LOG_ETHER:
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RESTART_IHM:
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_MODE_SECOURS_ECS:
			application().gotoSecoursScreenNoTransition();
			break;
		case OUI_NON_MODE_SECOURS_PRESSION :
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_DEROG_PRESSION_BP:
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_MARCHE_GENERAL:
			application().gotoAccueilScreenNoTransition();
			break;
		case OUI_NON_ARRET_GENERAL:
			application().gotoAccueilScreenNoTransition();
			break;
		case OUI_NON_CHAUFFE_DALLE:
			application().gotoInstallationScreenNoTransition();
			break;
		case OUI_NON_FREECOOLING:
			application().gotoInstallationScreenNoTransition();
			break;
		case OUI_NON_SIMULTANE_PISCINE:
			application().gotoPiscineScreenNoTransition();
			break;
		case OUI_NON_RAZ_TPS_FONCT:
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RAZ_ENERGIES:
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RESIST_TERM:
			application().gotoInstallation_hydrauliqueScreenNoTransition();
			break;
	}
}

void Page_oui_nonView::bouton_valider()
{
	switch(eOuiNon)
	{
		case OUI_NON_RAZ_CONF_USINE:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_usine_raz_config();
			}
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_RAZ_CODE_INST:
			if(toggleButton_oui_oui_non.getState())
			{
				memset(sConfig_IHM.sInstall_PAC.auc8PW_Installateur, '1', sizeof(sConfig_IHM.sInstall_PAC.auc8PW_Installateur));
				presenter->c_usine_password();
			}
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_RAZ_CODE_MAIN:
			if(toggleButton_oui_oui_non.getState())
			{
				memset(sConfig_IHM.sInstall_PAC.auc8PW_Maintenance, '1', sizeof(sConfig_IHM.sInstall_PAC.auc8PW_Installateur));
				presenter->c_usine_password();
			}
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_RAZ_HISTO_ERREUR:
			if(toggleButton_oui_oui_non.getState())
			{
				memset(&sHisto_Erreur, 0, sizeof(S_HISTO_ERR));
				presenter->c_install_raz_histo_err();
			}
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_SHUNT_TEMPO:
			sConfig_IHM.sParam_SAV.bShuntTempo = toggleButton_oui_oui_non.getState();
			presenter->c_sav_shunt_tempo();
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_MODE_SECOURS:
			if(toggleButton_oui_oui_non.getState() != sConfig_IHM.sMode_PAC.bSecours)
			{
				sConfig_IHM.sMode_PAC.bSecours = toggleButton_oui_oui_non.getState();
				presenter->c_user_param();
			}
			application().gotoSecoursScreenNoTransition();
			break;
		case OUI_NON_MODE_DATE:
			if(toggleButton_oui_oui_non.getState())
			{
				memcpy(&sDate, &sDate_modif, sizeof(S_DATE));
				presenter->c_user_date();
			}
			application().gotoParametresScreenNoTransition();
			break;
		case OUI_NON_CUMUL:
			if(toggleButton_oui_oui_non.getState())
			{
				// Cumul produite
				memset(&sEnergie.Cumul_Produite.Partiel_Chaud, 0, sizeof(sEnergie.Cumul_Produite.Partiel_Chaud));
				memset(&sEnergie.Cumul_Produite.Partiel_ECS, 0, sizeof(sEnergie.Cumul_Produite.Partiel_ECS));
				memset(&sEnergie.Cumul_Produite.Partiel_Froid, 0, sizeof(sEnergie.Cumul_Produite.Partiel_Froid));
				memset(&sEnergie.Cumul_Produite.Partiel_Piscine, 0, sizeof(sEnergie.Cumul_Produite.Partiel_Piscine));
				memset(&sEnergie.Cumul_Produite.Partiel_ElecChaud, 0, sizeof(sEnergie.Cumul_Produite.Partiel_ElecChaud));
				memset(&sEnergie.Cumul_Produite.Partiel_ElecECS, 0, sizeof(sEnergie.Cumul_Produite.Partiel_ElecECS));
				memcpy(&sEnergie.Cumul_Produite.Partiel_Date_Reset, &sDate, sizeof(S_DATE));
				// Cumul consommée
				memset(&sEnergie.Cumul_Consommee.Partiel_Chaud, 0, sizeof(sEnergie.Cumul_Consommee.Partiel_Chaud));
				memset(&sEnergie.Cumul_Consommee.Partiel_ECS, 0, sizeof(sEnergie.Cumul_Consommee.Partiel_ECS));
				memset(&sEnergie.Cumul_Consommee.Partiel_Froid, 0, sizeof(sEnergie.Cumul_Consommee.Partiel_Froid));
				memset(&sEnergie.Cumul_Consommee.Partiel_Piscine, 0, sizeof(sEnergie.Cumul_Consommee.Partiel_Piscine));
				memset(&sEnergie.Cumul_Consommee.Partiel_ElecChaud, 0, sizeof(sEnergie.Cumul_Consommee.Partiel_ElecChaud));
				memset(&sEnergie.Cumul_Consommee.Partiel_ElecECS, 0, sizeof(sEnergie.Cumul_Consommee.Partiel_ElecECS));
				memcpy(&sEnergie.Cumul_Consommee.Partiel_Date_Reset, &sDate, sizeof(S_DATE));
				// Envoi de la trame de reset
				presenter->c_ener_raz();
			}
			application().gotoEnergies_cumulScreenNoTransition();
			break;
		case OUI_NON_RAZ_CONF_INSTALL:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_install_raz_config();
			}
			application().gotoInstallationScreenNoTransition();
			break;
		case OUI_NON_RESTART:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_restart();
			}
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_RESTART_USINE:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_restart();
			}
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RAZ_SOFT_FLASH:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_sav_raz_soft_flash();
			}
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RAZ_LOG_ETHER:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_sav_raz_log();
			}
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RESTART_IHM:
			if(toggleButton_oui_oui_non.getState())
			{
#ifndef SIMULATOR
				NVIC_SystemReset();
#endif
			}
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_MODE_SECOURS_ECS:
			if(toggleButton_oui_oui_non.getState() != sConfig_IHM.sMode_ECS.bUserECSSecours)
			{
				sConfig_IHM.sMode_ECS.bUserECSSecours = toggleButton_oui_oui_non.getState();
				presenter->c_user_ecs();
			}
			application().gotoSecoursScreenNoTransition();
			break;
		case OUI_NON_MODE_SECOURS_PRESSION :
			if(toggleButton_oui_oui_non.getState())
			{
				u32ValAction = u32ValAction | 0x01;
			}
			else u32ValAction = u32ValAction & 0x02;
			//
			u16NumAction = SC_SAV_PARAM_DEROG;
			presenter->c_sav_param();
			//
			application().gotoMaintenanceScreenNoTransition();
			break;
		case OUI_NON_DEROG_PRESSION_BP:
			if(toggleButton_oui_oui_non.getState())
			{
				u32ValAction = u32ValAction | 0x02;
			}
			else u32ValAction = u32ValAction & 0x01;
			//
			u16NumAction = SC_SAV_PARAM_DEROG;
			presenter->c_sav_param();
			//
			application().gotoUsineScreenNoTransition();
			break;
		case OUI_NON_MARCHE_GENERAL:
			if(toggleButton_oui_oui_non.getState())
			{
				sConfig_IHM.sMode_PAC.bEtatPAC = 1;
				presenter->c_user_param();
			}
			application().gotoAccueilScreenNoTransition();
			break;
		case OUI_NON_ARRET_GENERAL:
			if(toggleButton_oui_oui_non.getState())
			{
				sConfig_IHM.sMode_PAC.bEtatPAC = 0;
				presenter->c_user_param();
			}
			application().gotoAccueilScreenNoTransition();
			break;
		case OUI_NON_CHAUFFE_DALLE:
			for(int i = 0; i < 8; i++)
			{
				if(sConfig_IHM.sParam_Zx[i].TypeEmmetteur == PLANCHER)
				{
					if(toggleButton_oui_oui_non.getState())
					{
						sConfig_IHM.sMode_Zx[i].Exception = DALLE;
					}
					else if(sConfig_IHM.sMode_Zx[i].Exception == DALLE)
					{
						sConfig_IHM.sMode_Zx[i].Exception = NO_EXCEPTION;
					}
				}
			}
			presenter->c_user_zx_all();
			if(toggleButton_oui_oui_non.getState())
			{
				application().gotoInstallation_chauffe_dalleScreenNoTransition();
			}
			else
			{
				sConfig_IHM.sParam_PAC.u8CTime_Sablier_Dalle_Jour = 0;
				// Multiple trame
				//presenter->c_install_param();
				application().gotoInstallationScreenNoTransition();
			}
			break;
		case OUI_NON_FREECOOLING:
			if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
			{
				sConfig_IHM.sConfig_PAC.ConfigGeo.bFreecooling = toggleButton_oui_oui_non.getState();
			}
			else if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA)
			{
				sConfig_IHM.sConfig_PAC.ConfigGeoInverter.bFreecooling = toggleButton_oui_oui_non.getState();
			}
			presenter->c_install_config_pac();
			application().gotoInstallationScreenNoTransition();
			break;
		case OUI_NON_SIMULTANE_PISCINE:
			if(toggleButton_oui_oui_non.getState())
			{
				sConfig_IHM.sParam_Piscine.bGestionSimultanee = 1;
			}
			else sConfig_IHM.sParam_Piscine.bGestionSimultanee = 0;
			presenter->c_install_piscine();
			application().gotoPiscineScreenNoTransition();
			break;
		case OUI_NON_RAZ_TPS_FONCT:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_sav_raz_tps_fonct(0);
			}
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RAZ_ENERGIES:
			if(toggleButton_oui_oui_non.getState())
			{
				presenter->c_usine_raz_energie();
			}
			application().gotoUsine_param_avancesScreenNoTransition();
			break;
		case OUI_NON_RESIST_TERM:
			if(toggleButton_oui_oui_non.getState())
			{
				sConfig_IHM.sParam_PAC.bConfigCascade120R = 1;
			}
			else sConfig_IHM.sParam_PAC.bConfigCascade120R = 0;
			presenter->c_install_param();
			application().gotoInstallation_hydrauliqueScreenNoTransition();
			break;
	}
}

void c_sav_param();


void Page_oui_nonView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Page_oui_nonView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Page_oui_nonView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Page_oui_nonView::changeDate(S_DATE *sDate)
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
