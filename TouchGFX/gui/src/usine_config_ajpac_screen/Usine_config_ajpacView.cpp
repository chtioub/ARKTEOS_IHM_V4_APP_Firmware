#include <gui/usine_config_ajpac_screen/Usine_config_ajpacView.hpp>

Usine_config_ajpacView::Usine_config_ajpacView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_AJPAC_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sModele_PAC.u8PwPac == 16 && sConfig_IHM.sModele_PAC.bSupply == 0)
	{
		u8TypeAJPAC = MONO_16KW;
	}
	else if(sConfig_IHM.sModele_PAC.u8PwPac == 16 && sConfig_IHM.sModele_PAC.bSupply == 1)
	{
		u8TypeAJPAC = TRI_16KW;
	}
	else if(sConfig_IHM.sModele_PAC.u8PwPac == 20 && sConfig_IHM.sModele_PAC.bSupply == 1)
	{
		u8TypeAJPAC = TRI_20KW;
	}
	else if(sConfig_IHM.sModele_PAC.u8PwPac == 24 && sConfig_IHM.sModele_PAC.bSupply == 1)
	{
		u8TypeAJPAC = TRI_24KW;
	}
	else u8TypeAJPAC = MONO_16KW;
	afficheTypeAJPAC();
}

void Usine_config_ajpacView::setupScreen()
{
    Usine_config_ajpacViewBase::setupScreen();
}

void Usine_config_ajpacView::tearDownScreen()
{
    Usine_config_ajpacViewBase::tearDownScreen();
}

void Usine_config_ajpacView::bouton_droite_ajpac()
{
	//
	if(u8TypeAJPAC == MONO_16KW)
	{
		u8TypeAJPAC = TRI_24KW;
	}
	else if(u8TypeAJPAC == TRI_16KW)
	{
		u8TypeAJPAC = MONO_16KW;
	}
	else if(u8TypeAJPAC == TRI_20KW)
	{
		u8TypeAJPAC = TRI_16KW;
	}
	else u8TypeAJPAC = TRI_20KW;
	//
	afficheTypeAJPAC();
}

void Usine_config_ajpacView::bouton_gauche_ajpac()
{
	//
	if(u8TypeAJPAC == MONO_16KW)
	{
		u8TypeAJPAC = TRI_16KW;
	}
	else if(u8TypeAJPAC == TRI_16KW)
	{
		u8TypeAJPAC = TRI_20KW;
	}
	else if(u8TypeAJPAC == TRI_20KW)
	{
		u8TypeAJPAC = TRI_24KW;
	}
	else u8TypeAJPAC = MONO_16KW;
	//
	afficheTypeAJPAC();
}

void Usine_config_ajpacView::afficheTypeAJPAC()
{
	switch(u8TypeAJPAC)
	{
		default:
		case MONO_16KW:
			textArea_valeur_modele_ajpac.setTypedText(touchgfx::TypedText(T_TEXT_MONO_16_AJPAC_CENTRE_DEFAUT));
			break;
		case TRI_16KW:
			textArea_valeur_modele_ajpac.setTypedText(touchgfx::TypedText(T_TEXT_TRI_16_AJPAC_CENTRE_DEFAUT));
			break;
		case TRI_20KW:
			textArea_valeur_modele_ajpac.setTypedText(touchgfx::TypedText(T_TEXT_TRI_20_AJPAC_CENTRE_DEFAUT));
			break;
		case TRI_24KW:
			textArea_valeur_modele_ajpac.setTypedText(touchgfx::TypedText(T_TEXT_TRI_24_AJPAC_CENTRE_DEFAUT));
			break;
	}
	textArea_valeur_modele_ajpac.invalidate();
}

void Usine_config_ajpacView::bouton_valider()
{
	switch(u8TypeAJPAC)
	{
		default:
		case MONO_16KW:
			sConfig_IHM.sModele_PAC.u8PwPac = 16;
			sConfig_IHM.sModele_PAC.bReversible = 1;
			sConfig_IHM.sModele_PAC.bDemarreurProgressif = 1;
			sConfig_IHM.sModele_PAC.bSupply = 0;
			break;
		case TRI_16KW:
			sConfig_IHM.sModele_PAC.u8PwPac = 16;
			sConfig_IHM.sModele_PAC.bReversible = 1;
			sConfig_IHM.sModele_PAC.bDemarreurProgressif = 1;
			sConfig_IHM.sModele_PAC.bSupply = 1;
			break;
		case TRI_20KW:
			sConfig_IHM.sModele_PAC.u8PwPac = 20;
			sConfig_IHM.sModele_PAC.bReversible = 1;
			sConfig_IHM.sModele_PAC.bDemarreurProgressif = 1;
			sConfig_IHM.sModele_PAC.bSupply = 1;
			break;
		case TRI_24KW:
			sConfig_IHM.sModele_PAC.u8PwPac = 24;
			sConfig_IHM.sModele_PAC.bReversible = 0;
			sConfig_IHM.sModele_PAC.bDemarreurProgressif = 1;
			sConfig_IHM.sModele_PAC.bSupply = 1;
			break;
	}
	//
	presenter->c_usine_param();
	application().gotoUsine_choix_fluideScreenNoTransition();
}

void Usine_config_ajpacView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_config_ajpacView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_config_ajpacView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_config_ajpacView::changeDate(S_DATE *sDate)
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
