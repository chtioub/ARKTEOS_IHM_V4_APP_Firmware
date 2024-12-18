#include <gui/usine_config_additionnelle_screen/Usine_config_additionnelleView.hpp>

Usine_config_additionnelleView::Usine_config_additionnelleView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_ADDITIONNELLE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BCP_INTERNE)
	{
		textArea_valeur_module_2_zones_int.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	}
	else textArea_valeur_module_2_zones_int.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
}

void Usine_config_additionnelleView::setupScreen()
{
    Usine_config_additionnelleViewBase::setupScreen();
}

void Usine_config_additionnelleView::tearDownScreen()
{
    Usine_config_additionnelleViewBase::tearDownScreen();
}

void Usine_config_additionnelleView::bouton_module_2_zones()
{
	if(textArea_valeur_module_2_zones_int.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_module_2_zones_int.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
	}
	else textArea_valeur_module_2_zones_int.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	textArea_valeur_module_2_zones_int.invalidate();
}

void Usine_config_additionnelleView::bouton_valider()
{
	if(textArea_valeur_module_2_zones_int.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
	{
		sConfig_IHM.sParam_PAC.TypeRegul = REGUL_BCP_INTERNE;
	}
	else if(sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BCP_INTERNE)
	{
		sConfig_IHM.sParam_PAC.TypeRegul = REGUL_DIRECTE;
	}
	presenter->c_install_param();
	application().gotoUsineScreenNoTransition();
}

void Usine_config_additionnelleView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_config_additionnelleView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_config_additionnelleView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_config_additionnelleView::changeDate(S_DATE *sDate)
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
