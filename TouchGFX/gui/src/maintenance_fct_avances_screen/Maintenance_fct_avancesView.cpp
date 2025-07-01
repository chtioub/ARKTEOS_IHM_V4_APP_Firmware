#include <gui/maintenance_fct_avances_screen/Maintenance_fct_avancesView.hpp>

Maintenance_fct_avancesView::Maintenance_fct_avancesView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_FONCTION_MAINTENANCE_AVANCEE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	//AJPAC
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		buttonWithLabel_pump_down.setVisible(true);
	}
	else buttonWithLabel_pump_down.setVisible(false);
	buttonWithLabel_pump_down.invalidate();

	//Gamme Zu/BA - Tim / Phoenix / Geoinverter
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV || sConfig_IHM.sModele_PAC.u8ModelePAC ==  TIMAX_III
	|| sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX || sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		buttonWithLabel_mode_commande.setVisible(true);
	}
	else buttonWithLabel_mode_commande.setVisible(false);
	buttonWithLabel_mode_commande.invalidate();
}

void Maintenance_fct_avancesView::setupScreen()
{
    Maintenance_fct_avancesViewBase::setupScreen();
}

void Maintenance_fct_avancesView::tearDownScreen()
{
    Maintenance_fct_avancesViewBase::tearDownScreen();
}

void Maintenance_fct_avancesView::button_mode_commande()
{
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX || sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		eCode = MODE_COMMANDE_PH;
		application().gotoCode_numeriqueScreenNoTransition();
	}
	else
	{
		application().gotoMaintenance_mode_commandeScreenNoTransition();
	}
}

void Maintenance_fct_avancesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Maintenance_fct_avancesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Maintenance_fct_avancesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Maintenance_fct_avancesView::changeDate(S_DATE *sDate)
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
