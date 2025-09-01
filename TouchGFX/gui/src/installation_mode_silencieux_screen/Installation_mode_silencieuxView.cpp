#include <gui/installation_mode_silencieux_screen/Installation_mode_silencieuxView.hpp>

Installation_mode_silencieuxView::Installation_mode_silencieuxView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MODE_SILENCIEUX_TITRE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	bModeSilencieux = sConfig_IHM.sMode_PAC.bModeSilencieux;
	u2NiveauSilence = sConfig_IHM.sParam_Frigo.u2NiveauSilence;

	if (sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		container_limitation_PW.setVisible(false);
		textArea_commentaire_silencieux_ajpac.setVisible(true);
		textArea_commentaire_silencieux_geo.setVisible(false);
	}
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		textArea_commentaire_silencieux_ajpac.setVisible(false);
		container_limitation_PW.setVisible(true);
		textArea_commentaire_silencieux_geo.setVisible(true);
	}
	textArea_commentaire_silencieux_ajpac.invalidate();
	container_limitation_PW.invalidate();
	textArea_commentaire_silencieux_geo.invalidate();

	update_toggle_boutons();

	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		update_val_limitation_PW();
	}

	memcpy(u8Prog, au8Prog_ModeSilence, sizeof(u8Prog));
	eProg = PRO_SILENCE;
}

void Installation_mode_silencieuxView::update_val_limitation_PW()
{
	Unicode::snprintf(textAreaBuffer_LimitationPW, 3, "%d", 80 - (((uint8_t)u2NiveauSilence)*10));
	textArea_valeur_limitation_PW.setWildcard(textAreaBuffer_LimitationPW);
	textArea_valeur_limitation_PW.invalidate();
}

void Installation_mode_silencieuxView::bouton_gauche_limitation_pw()
{
	if (u2NiveauSilence < 3) u2NiveauSilence++;
	else u2NiveauSilence = 0;
	update_val_limitation_PW();
}

void Installation_mode_silencieuxView::bouton_droit_limitation_pw()
{
	if (u2NiveauSilence > 0) u2NiveauSilence--;
	else u2NiveauSilence = 3;
	update_val_limitation_PW();
}

void Installation_mode_silencieuxView:: update_toggle_boutons()
{
	if (bModeSilencieux == 1)
	{
		toggleButton_arret.setTouchable(true);
		toggleButton_arret.forceState(false);
		toggleButton_marche_prog.setTouchable(true);
		toggleButton_marche_prog.forceState(true);
	}
	else
	{
		toggleButton_arret.setTouchable(false);
		toggleButton_arret.forceState(true);
		toggleButton_marche_prog.setTouchable(true);
		toggleButton_marche_prog.forceState(false);
	}
	toggleButton_arret.invalidate();
	toggleButton_marche_prog.invalidate();
}

void Installation_mode_silencieuxView::bouton_arret()
{
	bModeSilencieux = 0;
	update_toggle_boutons();
}

void Installation_mode_silencieuxView::bouton_marche_prog()
{
	memcpy(u8Prog, au8Prog_ModeSilence, sizeof(u8Prog));
	eProg = PRO_SILENCE;
}

void Installation_mode_silencieuxView::bouton_valider()
{
	sConfig_IHM.sMode_PAC.bModeSilencieux = bModeSilencieux & 1;
	sConfig_IHM.sParam_Frigo.u2NiveauSilence = u2NiveauSilence & 0b11;
	presenter->c_user_param();
	presenter->c_install_param();
}

void Installation_mode_silencieuxView::setupScreen()
{
    Installation_mode_silencieuxViewBase::setupScreen();
}

void Installation_mode_silencieuxView::tearDownScreen()
{
    Installation_mode_silencieuxViewBase::tearDownScreen();
}

void Installation_mode_silencieuxView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_mode_silencieuxView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_mode_silencieuxView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_mode_silencieuxView::changeDate(S_DATE *sDate)
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
