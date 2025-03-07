#include <gui/installation_mz_gestion_registre_screen/Installation_MZ_gestion_registreView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_MZ_gestion_registreView::Installation_MZ_gestion_registreView()
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

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_GESTION_REGISTRE_ZONE_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sParamZxMZtemp[u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	barre_titre.titre(textAreaBuffer_Titre);

	bRegistreForce = sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bRegistreForce;
	u8GestionRegistre = sParamZxMZtemp[u8NumZone].type_emetteur.gainable.u4GestionRegistre * 10;
	if (u8GestionRegistre < 10) u8GestionRegistre = 10;

	if (bRegistreForce)
	{
		container_valeur_ouverture_registre.setVisible(true);
		toggleButton_oui_oui_non_forcer_registre.forceState(true);
		toggleButton_oui_oui_non_forcer_registre.setTouchable(false);
		toggleButton_non_oui_non_forcer_registre.forceState(false);
		toggleButton_non_oui_non_forcer_registre.setTouchable(true);
	}
	else
	{
		container_valeur_ouverture_registre.setVisible(false);
		toggleButton_oui_oui_non_forcer_registre.forceState(false);
		toggleButton_oui_oui_non_forcer_registre.setTouchable(true);
		toggleButton_non_oui_non_forcer_registre.forceState(true);
		toggleButton_non_oui_non_forcer_registre.setTouchable(false);
	}
	Unicode::snprintf(textAreaBuffer_ValeurRegistre, 4, "%d", u8GestionRegistre);
	textArea_valeur_ouverture_registre.setWildcard(textAreaBuffer_ValeurRegistre);
	container_valeur_ouverture_registre.invalidate();
	toggleButton_non_oui_non_forcer_registre.invalidate();
	toggleButton_oui_oui_non_forcer_registre.invalidate();
}



void Installation_MZ_gestion_registreView::bouton_non()
{
	if(toggleButton_non_oui_non_forcer_registre.getState())
	{
		toggleButton_oui_oui_non_forcer_registre.forceState(false);
		toggleButton_oui_oui_non_forcer_registre.setTouchable(true);
		toggleButton_oui_oui_non_forcer_registre.invalidate();
		toggleButton_non_oui_non_forcer_registre.setTouchable(false);
		toggleButton_non_oui_non_forcer_registre.invalidate();
		bRegistreForce = 0;
		container_valeur_ouverture_registre.setVisible(false);
		container_valeur_ouverture_registre.invalidate();
	}
}

void Installation_MZ_gestion_registreView::bouton_oui()
{
	if(toggleButton_oui_oui_non_forcer_registre.getState())
	{
		toggleButton_non_oui_non_forcer_registre.forceState(false);
		toggleButton_non_oui_non_forcer_registre.setTouchable(true);
		toggleButton_non_oui_non_forcer_registre.invalidate();
		toggleButton_oui_oui_non_forcer_registre.setTouchable(false);
		toggleButton_oui_oui_non_forcer_registre.invalidate();
		bRegistreForce = 1;
		container_valeur_ouverture_registre.setVisible(true);
		container_valeur_ouverture_registre.invalidate();
	}
}

void Installation_MZ_gestion_registreView ::bouton_droite_consigne()
{
	if (u8GestionRegistre < 100) u8GestionRegistre = u8GestionRegistre + 10;
	Unicode::snprintf(textAreaBuffer_ValeurRegistre, 4, "%d", u8GestionRegistre);
	textArea_valeur_ouverture_registre.setWildcard(textAreaBuffer_ValeurRegistre);
	textArea_valeur_ouverture_registre.invalidate();
}

void Installation_MZ_gestion_registreView ::bouton_gauche_consigne()
{
	if (u8GestionRegistre > 10) u8GestionRegistre = u8GestionRegistre - 10;
	Unicode::snprintf(textAreaBuffer_ValeurRegistre, 4, "%d", u8GestionRegistre);
	textArea_valeur_ouverture_registre.setWildcard(textAreaBuffer_ValeurRegistre);
	textArea_valeur_ouverture_registre.invalidate();
}

void Installation_MZ_gestion_registreView::bouton_valider()
{
	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.bRegistreForce = bRegistreForce;
	sParamZxMZtemp[u8NumZone].type_emetteur.gainable.u4GestionRegistre = (u8GestionRegistre / 10) & 0x0F;
}

void Installation_MZ_gestion_registreView::setupScreen()
{
    Installation_MZ_gestion_registreViewBase::setupScreen();
}

void Installation_MZ_gestion_registreView::tearDownScreen()
{
    Installation_MZ_gestion_registreViewBase::tearDownScreen();
}


void Installation_MZ_gestion_registreView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_gestion_registreView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_gestion_registreView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_gestion_registreView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_gestion_registreView::changeDate(S_DATE *sDate)
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


