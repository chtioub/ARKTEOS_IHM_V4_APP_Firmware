#include <gui/usine_screen/UsineView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>

UsineView::UsineView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bPageUsine = 1;
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	bMaintenanceDepuisUsine = true;
	bInstallationDepuisUsine = true;
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_USINE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA)
	{
		buttonWithLabel_derog_pression_bp.setVisible(true);
	}
	// Récup histo défaut
	presenter->c_sav_histo_err();
}

void UsineView::setupScreen()
{
    UsineViewBase::setupScreen();
}

void UsineView::tearDownScreen()
{
    UsineViewBase::tearDownScreen();
}

void UsineView::bouton_raz_code_maintenance()
{
	eOuiNon = OUI_NON_RAZ_CODE_MAIN;
	application().gotoPage_oui_nonScreenNoTransition();
}

void UsineView::bouton_raz_code_installation()
{
	eOuiNon = OUI_NON_RAZ_CODE_INST;
	application().gotoPage_oui_nonScreenNoTransition();
}

void UsineView::bouton_raz_config_usine()
{
	eOuiNon = OUI_NON_RAZ_CONF_USINE;
	application().gotoPage_oui_nonScreenNoTransition();
}

void UsineView::bouton_derog_pression_bp()
{
	eOuiNon = OUI_NON_DEROG_PRESSION_BP;
	application().gotoPage_oui_nonScreenNoTransition();
}

void UsineView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	// derog pression bp
	if(sStatut_PAC_old.bDerogationPressionBP != sStatut_PAC->bDerogationPressionBP)
	{
		if(buttonWithLabel_derog_pression_bp_on.isVisible() && sStatut_PAC->bDerogationPressionBP)
		{
			buttonWithLabel_derog_pression_bp_on.setVisible(true);
		}
		else buttonWithLabel_derog_pression_bp_on.setVisible(false);
		buttonWithLabel_derog_pression_bp_on.invalidate();
	}
	// Test PAC
	if(sStatut_PAC_old.Test != sStatut_PAC->Test)
	{
		if(sStatut_PAC->Test)
		{
			buttonWithLabel_test_pac_on_usine.setVisible(true);
		}
		else buttonWithLabel_test_pac_on_usine.setVisible(false);
		buttonWithLabel_test_pac_on_usine.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void UsineView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void UsineView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void UsineView::changeDate(S_DATE *sDate)
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
