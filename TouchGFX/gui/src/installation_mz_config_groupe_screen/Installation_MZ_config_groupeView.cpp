#include <gui/installation_mz_config_groupe_screen/Installation_MZ_config_groupeView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_MZ_config_groupeView::Installation_MZ_config_groupeView()
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

//	Unicode::snprintf(textAreaBuffer_Question, 60,touchgfx::TypedText(T_TEXT_QUESTION_ACTIVATION_GROUPE).getText());
//	Unicode::snprintf(&textAreaBuffer_Question[Unicode::strlen(textAreaBuffer_Question)], 5, " ");
//	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Question[Unicode::strlen(textAreaBuffer_Question)], 10);
//	Unicode::snprintf(&textAreaBuffer_Question[Unicode::strlen(textAreaBuffer_Question)], 3, " ?");
//	textArea_question_oui_non.setWildcard(textAreaBuffer_Question);


//	Unicode::snprintf(textAreaBuffer_Question, 50,touchgfx::TypedText(T_TEXT_QUESTION_ACTIVATION_GROUPE).getText());
//	//Unicode::snprintf(&textAreaBuffer_Question[Unicode::strlen(textAreaBuffer_Question)], 50, " ");
////	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Question[Unicode::strlen(textAreaBuffer_Question)], 50);
////	Unicode::snprintf(&textAreaBuffer_Question[Unicode::strlen(textAreaBuffer_Question)], 50, " ?");
//	textArea_question_oui_non.setWildcard(textAreaBuffer_Question);
//	textArea_question_oui_non.invalidate();
	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, textAreaBuffer_Question, 10);
	textArea_question_oui_non.setWildcard(textAreaBuffer_Question);
	textArea_question_oui_non.invalidate();
}

void Installation_MZ_config_groupeView::setupScreen()
{
    Installation_MZ_config_groupeViewBase::setupScreen();
}

void Installation_MZ_config_groupeView::tearDownScreen()
{
    Installation_MZ_config_groupeViewBase::tearDownScreen();
}


void Installation_MZ_config_groupeView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_config_groupeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_config_groupeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_config_groupeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_config_groupeView::changeDate(S_DATE *sDate)
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

