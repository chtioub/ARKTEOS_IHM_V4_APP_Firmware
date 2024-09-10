#include <gui/installation_wattmetre_screen/Installation_wattmetreView.hpp>

Installation_wattmetreView::Installation_wattmetreView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_WATTMETRE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	// Etat intial
	if(sConfig_IHM.sOption_PAC.CoeffComptagePW == 0)
	{
		toggleButton_oui_oui_non_config_wattmetre.forceState(false);
		toggleButton_oui_oui_non_config_wattmetre.setTouchable(true);
		toggleButton_oui_oui_non_config_wattmetre.invalidate();
		toggleButton_non_oui_non_config_wattmetre.forceState(true);
		toggleButton_non_oui_non_config_wattmetre.setTouchable(false);
		toggleButton_non_oui_non_config_wattmetre.invalidate();
	}
	else
	{
		toggleButton_non_oui_non_config_wattmetre.forceState(false);
		toggleButton_non_oui_non_config_wattmetre.setTouchable(true);
		toggleButton_non_oui_non_config_wattmetre.invalidate();
		toggleButton_oui_oui_non_config_wattmetre.forceState(true);
		toggleButton_oui_oui_non_config_wattmetre.setTouchable(false);
		toggleButton_oui_oui_non_config_wattmetre.invalidate();
	}
	if(sConfig_IHM.sOption_PAC.CoeffComptagePW == 2)
	{
		u16NbImpulsions = 1000;
	}
	else u16NbImpulsions = 800;
	Unicode::snprintf(textAreaBuffer_Impulsions, 5, "%d", u16NbImpulsions);
	textArea_valeur_param_wattmetre.setWildcard(textAreaBuffer_Impulsions);
	textArea_valeur_param_wattmetre.invalidate();
}

void Installation_wattmetreView::setupScreen()
{
    Installation_wattmetreViewBase::setupScreen();
}

void Installation_wattmetreView::tearDownScreen()
{
    Installation_wattmetreViewBase::tearDownScreen();
}

void Installation_wattmetreView::bouton_wattmetre_non()
{
	if(toggleButton_non_oui_non_config_wattmetre.getState())
	{
		toggleButton_oui_oui_non_config_wattmetre.forceState(false);
		toggleButton_oui_oui_non_config_wattmetre.setTouchable(true);
		toggleButton_oui_oui_non_config_wattmetre.invalidate();
		toggleButton_non_oui_non_config_wattmetre.setTouchable(false);
		toggleButton_non_oui_non_config_wattmetre.invalidate();
	}
}

void Installation_wattmetreView::bouton_wattmetre_oui()
{
	if(toggleButton_oui_oui_non_config_wattmetre.getState())
	{
		toggleButton_non_oui_non_config_wattmetre.forceState(false);
		toggleButton_non_oui_non_config_wattmetre.setTouchable(true);
		toggleButton_non_oui_non_config_wattmetre.invalidate();
		toggleButton_oui_oui_non_config_wattmetre.setTouchable(false);
		toggleButton_oui_oui_non_config_wattmetre.invalidate();
	}
}

void Installation_wattmetreView::bouton_nb_impulsions()
{
	if(u16NbImpulsions == 800)
	{
		u16NbImpulsions = 1000;
	}
	else u16NbImpulsions = 800;
	Unicode::snprintf(textAreaBuffer_Impulsions, 5, "%d", u16NbImpulsions);
	textArea_valeur_param_wattmetre.setWildcard(textAreaBuffer_Impulsions);
	textArea_valeur_param_wattmetre.invalidate();
}

void Installation_wattmetreView::bouton_valider()
{
	if(toggleButton_oui_oui_non_config_wattmetre.getState() && u16NbImpulsions == 1000)
	{
		sConfig_IHM.sOption_PAC.CoeffComptagePW = 2;
	}
	else if(toggleButton_oui_oui_non_config_wattmetre.getState() && u16NbImpulsions == 800)
	{
		sConfig_IHM.sOption_PAC.CoeffComptagePW = 1;
	}
	else sConfig_IHM.sOption_PAC.CoeffComptagePW = 0;
	//
	presenter->c_install_param();
	application().gotoInstallationScreenNoTransition();
}

void Installation_wattmetreView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_wattmetreView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_wattmetreView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_wattmetreView::changeDate(S_DATE *sDate)
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
