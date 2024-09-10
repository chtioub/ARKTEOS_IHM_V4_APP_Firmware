#include <gui/energies_screen/EnergiesView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

EnergiesView::EnergiesView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	bConsoProd = 0;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre de la page
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_SUIVI_ENERGIES_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);
#ifndef SIMULATOR
    // Multiple trame
//    presenter->c_ener_cumul_prod();
//    presenter->c_ener_cumul_conso();
//    presenter->c_ener_histo_12m_conso();
//    presenter->c_ener_histo_24j_conso();
//    presenter->c_ener_histo_24h_conso();
    presenter->c_ener_histo_12m_prod();
//    presenter->c_ener_histo_24j_prod();
//    presenter->c_ener_histo_24h_prod();
#endif
}

void EnergiesView::setupScreen()
{
    EnergiesViewBase::setupScreen();
}

void EnergiesView::tearDownScreen()
{
    EnergiesViewBase::tearDownScreen();
}

void EnergiesView::bouton_histo_conso()
{
	bConsoProd = 1;
	application().gotoEnergies_histoScreenNoTransition();
}

void EnergiesView::bouton_cumul_conso()
{
	bConsoProd = 1;
	application().gotoEnergies_cumulScreenNoTransition();
}

void EnergiesView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	if((sConfig_IHM->sOption_PAC.CoeffComptagePW != sConfig_IHM_old.sOption_PAC.CoeffComptagePW) || (sConfig_IHM->sModele_PAC.u8ModelePAC != sConfig_IHM_old.sModele_PAC.u8ModelePAC))
	{
		if(sConfig_IHM->sOption_PAC.CoeffComptagePW || sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA)
		{
			buttonWithLabel_histo_conso.setVisible(true);
			buttonWithLabel_cumul_conso.setVisible(true);
		}
		else
		{
			buttonWithLabel_histo_conso.setVisible(false);
			buttonWithLabel_cumul_conso.setVisible(false);
		}
		buttonWithLabel_histo_conso.invalidate();
		buttonWithLabel_cumul_conso.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void EnergiesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void EnergiesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void EnergiesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void EnergiesView::changeDate(S_DATE *sDate)
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
