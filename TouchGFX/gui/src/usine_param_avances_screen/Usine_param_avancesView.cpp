#include <gui/usine_param_avances_screen/Usine_param_avancesView.hpp>

Usine_param_avancesView::Usine_param_avancesView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_AVANCES_PISCINE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA || sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX)
	{
		buttonWithLabel_raz_tps_fonct.setVisible(true);
	}
}

void Usine_param_avancesView::setupScreen()
{
    Usine_param_avancesViewBase::setupScreen();
}

void Usine_param_avancesView::tearDownScreen()
{
    Usine_param_avancesViewBase::tearDownScreen();
}

void Usine_param_avancesView::bouton_redemarrer()
{
	eOuiNon = OUI_NON_RESTART_USINE;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Usine_param_avancesView::bouton_raz_soft()
{
	eOuiNon = OUI_NON_RAZ_SOFT_FLASH;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Usine_param_avancesView::bouton_raz_log_ether()
{
	eOuiNon = OUI_NON_RAZ_LOG_ETHER;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Usine_param_avancesView::bouton_raz_tps_fonct()
{
	eOuiNon = OUI_NON_RAZ_TPS_FONCT;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Usine_param_avancesView::bouton_raz_energies()
{
	eOuiNon = OUI_NON_RAZ_ENERGIES;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Usine_param_avancesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_param_avancesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_param_avancesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_param_avancesView::changeDate(S_DATE *sDate)
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
