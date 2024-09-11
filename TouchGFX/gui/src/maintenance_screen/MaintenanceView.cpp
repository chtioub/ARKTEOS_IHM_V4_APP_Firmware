#include <gui/maintenance_screen/MaintenanceView.hpp>

MaintenanceView::MaintenanceView()
{
	bPageUsine = 0;
	memset(&sDemande_Frigo_old, 0, sizeof(sDemande_Frigo_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeDemandeFrigo(&sDemandeFrigo);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_MAINTENANCE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	// Récup histo défaut
	presenter->c_sav_histo_err();
}

void MaintenanceView::setupScreen()
{
    MaintenanceViewBase::setupScreen();
}

void MaintenanceView::tearDownScreen()
{
    MaintenanceViewBase::tearDownScreen();
}

void MaintenanceView::bouton_modif_code()
{
	eCode = MODIF_CODE_MAINT;
	application().gotoCode_numeriqueScreenNoTransition();
}

void MaintenanceView::bouton_retour()
{
	if(bMaintenanceDepuisUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else application().gotoConfigurationScreenNoTransition();
}

void MaintenanceView::bouton_raz_histo_err()
{
	eOuiNon = OUI_NON_RAZ_HISTO_ERREUR;
	application().gotoPage_oui_nonScreenNoTransition();
}

void MaintenanceView::bouton_derog_pression()
{
	eOuiNon = OUI_NON_MODE_SECOURS_PRESSION;
	application().gotoPage_oui_nonScreenNoTransition();
}

void MaintenanceView::bouton_shunt_tempo()
{
	eOuiNon = OUI_NON_SHUNT_TEMPO;
	application().gotoPage_oui_nonScreenNoTransition();
}

void MaintenanceView::bouton_redemarrer_pac()
{
	eOuiNon = OUI_NON_RESTART;
	application().gotoPage_oui_nonScreenNoTransition();
}

void MaintenanceView::bouton_redemarrer_ihm()
{
	eOuiNon = OUI_NON_RESTART_IHM;
	application().gotoPage_oui_nonScreenNoTransition();
}

void MaintenanceView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	// Derog pression
	if(sStatut_PAC_old.bDerogationPression != sStatut_PAC->bDerogationPression)
	{
		if(sStatut_PAC->bDerogationPression)
		{
			buttonWithLabel_derogation_pression_on_maintenance.setVisible(true);
		}
		else buttonWithLabel_derogation_pression_on_maintenance.setVisible(false);
		buttonWithLabel_derogation_pression_on_maintenance.invalidate();
	}
	// Test PAC
	if(sStatut_PAC_old.Test != sStatut_PAC->Test)
	{
		if(sStatut_PAC->Test)
		{
			buttonWithLabel_test_pac_on_maintenance.setVisible(true);
		}
		else buttonWithLabel_test_pac_on_maintenance.setVisible(false);
		buttonWithLabel_test_pac_on_maintenance.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void MaintenanceView::changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo)
{
	// Demande Frigo
	if(sDemande_Frigo_old.bShuntTempo != sDemandeFrigo->bShuntTempo)
	{
		if(sDemandeFrigo->bShuntTempo)
		{
			buttonWithLabel_shunt_tempo_on_maintenance.setVisible(true);
		}
		else buttonWithLabel_shunt_tempo_on_maintenance.setVisible(false);
		buttonWithLabel_shunt_tempo_on_maintenance.invalidate();
	}
	memcpy(&sDemande_Frigo_old, sDemandeFrigo, sizeof(S_STATUT_PAC));
}

void MaintenanceView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void MaintenanceView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void MaintenanceView::changeDate(S_DATE *sDate)
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
