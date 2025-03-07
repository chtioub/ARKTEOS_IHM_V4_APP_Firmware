#include <gui/installation_mz_reglage_debit_air_screen/Installation_MZ_reglage_debit_airView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_MZ_reglage_debit_airView::Installation_MZ_reglage_debit_airView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));//De CPA
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeConfig(&sConfig_IHM);

	container.setXY(u8PositionX, u8PositionY);
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	u8NumZone = sConfig_Hydrau_temp.u8NumZone;

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_REGLAGE_DEBIT_AIR_ZONE_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sParamZxMZtemp[u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	barre_titre.titre(textAreaBuffer_Titre);

	bActivationCorrection = sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bActivationCorrection;
	CorrectionDebitAir = sParamZxMZtemp[u8NumZone].type_emetteur.gainable.CorrectionDebitAir;

	if (CorrectionDebitAir < 5) 		CorrectionDebitAir = 5;
	else if (CorrectionDebitAir > 75) 	CorrectionDebitAir = 75;

	if (bActivationCorrection)
	{
		container_valeur_reglage_debit_air.setVisible(true);
		toggleButton_oui_oui_non_reglage_debit_air.forceState(true);
		toggleButton_oui_oui_non_reglage_debit_air.setTouchable(false);
		toggleButton_non_oui_non_reglage_debit_air.forceState(false);
		toggleButton_non_oui_non_reglage_debit_air.setTouchable(true);
	}
	else
	{
		container_valeur_reglage_debit_air.setVisible(false);
		toggleButton_oui_oui_non_reglage_debit_air.forceState(false);
		toggleButton_oui_oui_non_reglage_debit_air.setTouchable(true);
		toggleButton_non_oui_non_reglage_debit_air.forceState(true);
		toggleButton_non_oui_non_reglage_debit_air.setTouchable(false);
	}
	Unicode::snprintf(textAreaBuffer_ValeurVitesseVentil, 4, "%d", CorrectionDebitAir);
	textArea_valeur_reglage_debit_air.setWildcard(textAreaBuffer_ValeurVitesseVentil);
	container_valeur_reglage_debit_air.invalidate();
	toggleButton_non_oui_non_reglage_debit_air.invalidate();
	toggleButton_oui_oui_non_reglage_debit_air.invalidate();
}



void Installation_MZ_reglage_debit_airView::bouton_non()
{
	if(toggleButton_non_oui_non_reglage_debit_air.getState())
	{
		toggleButton_oui_oui_non_reglage_debit_air.forceState(false);
		toggleButton_oui_oui_non_reglage_debit_air.setTouchable(true);
		toggleButton_oui_oui_non_reglage_debit_air.invalidate();
		toggleButton_non_oui_non_reglage_debit_air.setTouchable(false);
		toggleButton_non_oui_non_reglage_debit_air.invalidate();
		bActivationCorrection = 0;
		container_valeur_reglage_debit_air.setVisible(false);
		container_valeur_reglage_debit_air.invalidate();
	}
}

void Installation_MZ_reglage_debit_airView::bouton_oui()
{
	if(toggleButton_oui_oui_non_reglage_debit_air.getState())
	{
		toggleButton_non_oui_non_reglage_debit_air.forceState(false);
		toggleButton_non_oui_non_reglage_debit_air.setTouchable(true);
		toggleButton_non_oui_non_reglage_debit_air.invalidate();
		toggleButton_oui_oui_non_reglage_debit_air.setTouchable(false);
		toggleButton_oui_oui_non_reglage_debit_air.invalidate();
		bActivationCorrection = 1;
		container_valeur_reglage_debit_air.setVisible(true);
		container_valeur_reglage_debit_air.invalidate();
	}
}

void Installation_MZ_reglage_debit_airView ::bouton_droite_consigne()
{
	if (CorrectionDebitAir < 75) CorrectionDebitAir = CorrectionDebitAir + 1;
	Unicode::snprintf(textAreaBuffer_ValeurVitesseVentil, 4, "%d", CorrectionDebitAir);
	textArea_valeur_reglage_debit_air.setWildcard(textAreaBuffer_ValeurVitesseVentil);
	container_valeur_reglage_debit_air.invalidate();
}

void Installation_MZ_reglage_debit_airView ::bouton_gauche_consigne()
{
	if (CorrectionDebitAir > 5) CorrectionDebitAir = CorrectionDebitAir - 1;
	Unicode::snprintf(textAreaBuffer_ValeurVitesseVentil, 4, "%d", CorrectionDebitAir);
	textArea_valeur_reglage_debit_air.setWildcard(textAreaBuffer_ValeurVitesseVentil);
	container_valeur_reglage_debit_air.invalidate();
}

void Installation_MZ_reglage_debit_airView::bouton_valider()
{
	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bActivationCorrection = bActivationCorrection;
	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.CorrectionDebitAir = (CorrectionDebitAir & 0x7F);
}

void Installation_MZ_reglage_debit_airView::setupScreen()
{
	Installation_MZ_reglage_debit_airViewBase::setupScreen();
}

void Installation_MZ_reglage_debit_airView::tearDownScreen()
{
	Installation_MZ_reglage_debit_airViewBase::tearDownScreen();
}

void Installation_MZ_reglage_debit_airView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_reglage_debit_airView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_reglage_debit_airView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_reglage_debit_airView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_reglage_debit_airView::changeDate(S_DATE *sDate)
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
