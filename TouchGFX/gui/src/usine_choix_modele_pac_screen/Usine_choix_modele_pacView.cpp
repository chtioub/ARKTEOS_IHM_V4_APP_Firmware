#include <gui/usine_choix_modele_pac_screen/Usine_choix_modele_pacView.hpp>

Usine_choix_modele_pacView::Usine_choix_modele_pacView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_SELECT_MODELE_PAC_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	u8ModelePAC = sConfig_IHM.sModele_PAC.u8ModelePAC;
	if(u8ModelePAC == GEOTWIN_IV && sConfig_IHM.sModele_PAC.u3SousTypePAC != 0)
	{
		toggleButton_sajiter.forceState(true);
	}
	else toggleButton_sajiter.forceState(false);
	afficheModelePAC(u8ModelePAC);
}

void Usine_choix_modele_pacView::setupScreen()
{
    Usine_choix_modele_pacViewBase::setupScreen();
}

void Usine_choix_modele_pacView::tearDownScreen()
{
    Usine_choix_modele_pacViewBase::tearDownScreen();
}

void Usine_choix_modele_pacView::afficheModelePAC(uint8_t u8Modele)
{
	container_sajiter.setVisible(false);
	switch(u8Modele)
	{
		default:
		case AJPAC_III:
			Unicode::snprintf(textAreaBuffer_Gamme, 10, "AJPAC III");
			break;
		case BAGUIO_ZURAN_IV:
			Unicode::snprintf(textAreaBuffer_Gamme, 18, "ZURAN / BAGUIO IV");
			break;
		case TIMAX_III:
			Unicode::snprintf(textAreaBuffer_Gamme, 9, "TIMAX III");
			break;
		case GEOTWIN_IV:
			container_sajiter.setVisible(true);
			Unicode::snprintf(textAreaBuffer_Gamme, 11, "GEOTWIN IV");
			break;
		case CAIROX:
			Unicode::snprintf(textAreaBuffer_Gamme, 9, "CAIROX");
			break;
		case PHOENIX:
			Unicode::snprintf(textAreaBuffer_Gamme, 9, "PHOENIX");
			break;
		case ARKTEA:
			Unicode::snprintf(textAreaBuffer_Gamme, 7, "ARKTEA");
			break;
		case INVERTERRA:
			Unicode::snprintf(textAreaBuffer_Gamme, 11, "INVERTERRA");
			break;
	}
	textArea_valeur_choix_modele_pac.setWildcard(textAreaBuffer_Gamme);
	textArea_valeur_choix_modele_pac.invalidate();
	container_sajiter.invalidate();
}

void Usine_choix_modele_pacView::bouton_valider()
{
	sConfig_IHM.sModele_PAC.u8ModelePAC = u8ModelePAC;
	if(u8ModelePAC == GEOTWIN_IV && sConfig_IHM.sModele_PAC.u3SousTypePAC != 0)
	{
		if(toggleButton_sajiter.getState())
		{
			sConfig_IHM.sModele_PAC.u3SousTypePAC = SOUS_TYPE_SAGITAIR;
		}
		else sConfig_IHM.sModele_PAC.u3SousTypePAC = SOUS_TYPE_GEOTWIN;
	}
	presenter->c_usine_param();
	//
	eCode = NUM_SERIE;
	application().gotoCode_numeriqueScreenNoTransition();
}

void Usine_choix_modele_pacView::bouton_droite_modele_pac()
{
	if(++u8ModelePAC >= LAST_MODEL)
	{
		u8ModelePAC = AJPAC_III;
	}
	afficheModelePAC(u8ModelePAC);
}

void Usine_choix_modele_pacView::bouton_gauche_modele_pac()
{
	if(u8ModelePAC == AJPAC_III)
	{
		u8ModelePAC = LAST_MODEL - 1;
	}
	else u8ModelePAC--;
	afficheModelePAC(u8ModelePAC);
}

void Usine_choix_modele_pacView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_choix_modele_pacView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_choix_modele_pacView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_choix_modele_pacView::changeDate(S_DATE *sDate)
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
