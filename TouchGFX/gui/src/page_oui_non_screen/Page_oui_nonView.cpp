#include <gui/page_oui_non_screen/Page_oui_nonView.hpp>

Page_oui_nonView::Page_oui_nonView()
{
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	changeErreur(u16ErreurEncours);
	// Init du bouton
	toggleButton_oui_oui_non.forceState(false);
	toggleButton_oui_oui_non.setTouchable(true);
	toggleButton_non_oui_non.forceState(true);
	toggleButton_non_oui_non.setTouchable(false);
	//
	switch(eOuiNon)
	{
		case OUI_NON_ANTIL:
			break;
		case OUI_NON_RAZ_CONF:
			break;
		case OUI_NON_RAZ_INST:
			break;
		case OUI_NON_RAZ_MAIN:
			break;
		case OUI_NON_RAZ_PARAM:
			break;
		case OUI_NON_SHUNT_TEMPO:
			break;
		case OUI_NON_MODE_SECOURS:
			break;
		case OUI_NON_MODE_SILENCE:
			break;
		case OUI_NON_MODE_DATE:
			break;
		case OUI_NON_CUMUL:
			break;
		case OUI_NON_RAZ_CONF_INSTALL:
			break;
		case OUI_NON_RESTART:
			break;
		case OUI_NON_RAZ_SOFT_FLASH:
			break;
		case OUI_NON_RAZ_LOG_ETHER:
			break;
		case OUI_NON_RESTART_IHM:
			break;
		case OUI_NON_MODE_SECOURS_ECS:
			break;
		case OUI_NON_MODE_SECOURS_PRESSION :
			break;
		case OUI_NON_MARCHE_GENERAL:
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MARCHE_GENERAL_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setWildcard(textAreaBuffer_Titre);
			break;
		case OUI_NON_ARRET_GENERAL:
		    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_ARRET_GENERAL_CENTRE_DEFAUT).getText());
		    barre_titre.titre(textAreaBuffer_Titre);
		    textArea_question_oui_non.setWildcard(textAreaBuffer_Titre);
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
		case OUI_NON_ANTIL:
			break;
		case OUI_NON_RAZ_CONF:
			break;
		case OUI_NON_RAZ_INST:
			break;
		case OUI_NON_RAZ_MAIN:
			break;
		case OUI_NON_RAZ_PARAM:
			break;
		case OUI_NON_SHUNT_TEMPO:
			break;
		case OUI_NON_MODE_SECOURS:
			break;
		case OUI_NON_MODE_SILENCE:
			break;
		case OUI_NON_MODE_DATE:
			break;
		case OUI_NON_CUMUL:
			break;
		case OUI_NON_RAZ_CONF_INSTALL:
			break;
		case OUI_NON_RESTART:
			break;
		case OUI_NON_RAZ_SOFT_FLASH:
			break;
		case OUI_NON_RAZ_LOG_ETHER:
			break;
		case OUI_NON_RESTART_IHM:
			break;
		case OUI_NON_MODE_SECOURS_ECS:
			break;
		case OUI_NON_MODE_SECOURS_PRESSION :
			break;
		case OUI_NON_MARCHE_GENERAL:
			application().gotoAccueilScreenNoTransition();
			break;
		case OUI_NON_ARRET_GENERAL:
			application().gotoAccueilScreenNoTransition();
			break;
	}
}

void Page_oui_nonView::bouton_valider()
{
	switch(eOuiNon)
	{
		case OUI_NON_ANTIL:
			break;
		case OUI_NON_RAZ_CONF:
			break;
		case OUI_NON_RAZ_INST:
			break;
		case OUI_NON_RAZ_MAIN:
			break;
		case OUI_NON_RAZ_PARAM:
			break;
		case OUI_NON_SHUNT_TEMPO:
			break;
		case OUI_NON_MODE_SECOURS:
			break;
		case OUI_NON_MODE_SILENCE:
			break;
		case OUI_NON_MODE_DATE:
			break;
		case OUI_NON_CUMUL:
			break;
		case OUI_NON_RAZ_CONF_INSTALL:
			break;
		case OUI_NON_RESTART:
			break;
		case OUI_NON_RAZ_SOFT_FLASH:
			break;
		case OUI_NON_RAZ_LOG_ETHER:
			break;
		case OUI_NON_RESTART_IHM:
			break;
		case OUI_NON_MODE_SECOURS_ECS:
			break;
		case OUI_NON_MODE_SECOURS_PRESSION :
			break;
		case OUI_NON_MARCHE_GENERAL:
			application().gotoAccueilScreenNoTransition();
			break;
		case OUI_NON_ARRET_GENERAL:
			application().gotoAccueilScreenNoTransition();
			break;
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
