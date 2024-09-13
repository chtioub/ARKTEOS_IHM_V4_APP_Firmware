#include <gui/usine_config_geotwin_screen/Usine_config_geotwinView.hpp>

Usine_config_geotwinView::Usine_config_geotwinView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_GEOTWIN_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	u8Puissance = sConfig_IHM.sModele_PAC.u8PwPac;
	if(u8Puissance < 4 || u8Puissance > 254)
	{
		u8Puissance = 4;
	}
	Unicode::snprintf(textAreaBuffer_Puissance, 4, "%d", u8Puissance);
	textArea_valeur_puissance_pac.setWildcard(textAreaBuffer_Puissance);
	//
	u8NbComp = sConfig_IHM.sModele_PAC.nbCompresseur;
	Unicode::snprintf(textAreaBuffer_Compresseur, 2, "%d", u8NbComp + 1);
	textArea_valeur_nombre_comp.setWildcard(textAreaBuffer_Compresseur);
	//
	if(sConfig_IHM.sModele_PAC.bSupply)
	{
		textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_TRI_CENTRE_DEFAUT));
	}
	//
	if(sConfig_IHM.sModele_PAC.bReversible)
	{
		textArea_valeur_geotwin_reversible.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	}
	//
	if(sConfig_IHM.sModele_PAC.bDemarreurProgressif)
	{
		toggleButton_demarreur_progressif.forceState(true);
		textArea_oui_non_demarreur_progressif.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	}
	//
	if(sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage == E_TYPE_CAPTAGE_NAPPE_DIRECTE)
	{
		textArea_oui_non_nappe_directe.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
		toggleButton_nappe_directe.forceState(true);
	}
	//
	u8DebitmetreCaptage = sConfig_IHM.sConfig_PAC.ConfigGeo.u4DebitmetreCaptage;
	affichage_debitmetre_captage();
	u8DebitmetreChauffage = sConfig_IHM.sConfig_PAC.ConfigGeo.u4DebitmetreChauffage;
	affichage_debitmetre_chauffage();
}

void Usine_config_geotwinView::setupScreen()
{
    Usine_config_geotwinViewBase::setupScreen();
}

void Usine_config_geotwinView::tearDownScreen()
{
    Usine_config_geotwinViewBase::tearDownScreen();
}

void Usine_config_geotwinView::bouton_droite_debitmetre_chauffage()
{
	if(++u8DebitmetreChauffage > SIKA_VTR1050)
	{
		u8DebitmetreChauffage = HUBA_DN_10;
	}
	affichage_debitmetre_chauffage();
}

void Usine_config_geotwinView::bouton_gauche_debitmetre_chauffage()
{
	if(u8DebitmetreChauffage == HUBA_DN_10)
	{
		u8DebitmetreChauffage = SIKA_VTR1050;
	}
	else u8DebitmetreChauffage--;
	affichage_debitmetre_chauffage();
}

void Usine_config_geotwinView::affichage_debitmetre_chauffage()
{
	switch(u8DebitmetreChauffage)
	{
		case HUBA_DN_10:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "HUBA 10");
			break;
		case HUBA_DN_15:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "HUBA 15");
			break;
		case HUBA_DN_20:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "HUBA 20");
			break;
		case HUBA_DN_25:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "HUBA 25");
			break;
		case HUBA_DN_32:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "HUBA 32");
			break;
		case SIKA_DN_32:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "SIKA 32");
			break;
		case SIKA_DN_40:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 8, "SIKA 40");
			break;
		case SIKA_VTR1050:
			Unicode::snprintf(textAreaBuffer_DebitmetreChauffage, 13, "SIKA VTR1050");
			break;
	}
	textArea_valeur_type_debitmetre_chauffage.setWildcard(textAreaBuffer_DebitmetreChauffage);
	textArea_valeur_type_debitmetre_chauffage.invalidate();
}

void Usine_config_geotwinView::bouton_droite_debitmetre_captage()
{
	if(++u8DebitmetreCaptage > SIKA_VTR1050)
	{
		u8DebitmetreCaptage = HUBA_DN_10;
	}
	affichage_debitmetre_captage();
}

void Usine_config_geotwinView::bouton_gauche_debitmetre_captage()
{
	if(u8DebitmetreCaptage == HUBA_DN_10)
	{
		u8DebitmetreCaptage = SIKA_VTR1050;
	}
	else u8DebitmetreCaptage--;
	affichage_debitmetre_captage();
}

void Usine_config_geotwinView::affichage_debitmetre_captage()
{
	switch(u8DebitmetreCaptage)
	{
		case HUBA_DN_10:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "HUBA 10");
			break;
		case HUBA_DN_15:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "HUBA 15");
			break;
		case HUBA_DN_20:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "HUBA 20");
			break;
		case HUBA_DN_25:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "HUBA 25");
			break;
		case HUBA_DN_32:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "HUBA 32");
			break;
		case SIKA_DN_32:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "SIKA 32");
			break;
		case SIKA_DN_40:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 8, "SIKA 40");
			break;
		case SIKA_VTR1050:
			Unicode::snprintf(textAreaBuffer_DebitmetreCaptage, 13, "SIKA VTR1050");
			break;
	}
	textArea_valeur_type_debitmetre_captage.setWildcard(textAreaBuffer_DebitmetreCaptage);
	textArea_valeur_type_debitmetre_captage.invalidate();
}

void Usine_config_geotwinView::bouton_moins_puissance()
{
	if(u8Puissance > 4)
	{
		u8Puissance--;
		Unicode::snprintf(textAreaBuffer_Puissance, 4, "%d", u8Puissance);
		textArea_valeur_puissance_pac.setWildcard(textAreaBuffer_Puissance);
		textArea_valeur_puissance_pac.invalidate();
	}
}

void Usine_config_geotwinView::bouton_plus_puissance()
{
	if(u8Puissance < 100)
	{
		u8Puissance++;
		Unicode::snprintf(textAreaBuffer_Puissance, 4, "%d", u8Puissance);
		textArea_valeur_puissance_pac.setWildcard(textAreaBuffer_Puissance);
		textArea_valeur_puissance_pac.invalidate();
	}
}

void Usine_config_geotwinView::bouton_dem_prog()
{
	if(toggleButton_demarreur_progressif.getState())
	{
		textArea_oui_non_demarreur_progressif.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	}
	else textArea_oui_non_demarreur_progressif.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
	textArea_oui_non_demarreur_progressif.invalidate();
}

void Usine_config_geotwinView::timer_10ms()
{
	//
	if(button_gauche_puissance_pac.getPressedState())
	{
		if(u8PressionLongue_gauche < 15)
		{
			u8PressionLongue_gauche++;
		}
		else bouton_moins_puissance();
	}
	else u8PressionLongue_gauche = 0;
	//
	if(button_droite_puissance_pac.getPressedState())
	{
		if(u8PressionLongue_droite < 15)
		{
			u8PressionLongue_droite++;
		}
		else bouton_plus_puissance();
	}
	else u8PressionLongue_droite = 0;
}

void Usine_config_geotwinView::bouton_compresseur()
{
	if(u8NbComp == 0)
	{
		u8NbComp = 1;
	}
	else u8NbComp = 0;
	Unicode::snprintf(textAreaBuffer_Compresseur, 2, "%d", u8NbComp + 1);
	textArea_valeur_nombre_comp.setWildcard(textAreaBuffer_Compresseur);
	textArea_valeur_nombre_comp.invalidate();
}

void Usine_config_geotwinView::bouton_nappe_directe()
{
	if(toggleButton_nappe_directe.getState())
	{
		textArea_oui_non_nappe_directe.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	}
	else textArea_oui_non_nappe_directe.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
	textArea_oui_non_nappe_directe.invalidate();
}

void Usine_config_geotwinView::bouton_reversible()
{
	if(textArea_valeur_geotwin_reversible.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_geotwin_reversible.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
	}
	else textArea_valeur_geotwin_reversible.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	textArea_valeur_geotwin_reversible.invalidate();
}

void Usine_config_geotwinView::bouton_mono_tri()
{
	if(textArea_valeur_alim_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_TRI_CENTRE_DEFAUT));
	}
	else textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT));
	textArea_valeur_alim_pac.invalidate();
}

void Usine_config_geotwinView::bouton_valider()
{

	sConfig_IHM.sModele_PAC.u8PwPac = u8Puissance;
	//
	sConfig_IHM.sModele_PAC.nbCompresseur = u8NbComp;
	//
	if(textArea_valeur_alim_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT).getId())
	{
		sConfig_IHM.sModele_PAC.bSupply = 0;
	}
	else sConfig_IHM.sModele_PAC.bSupply = 1;
	//
	if(textArea_valeur_geotwin_reversible.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
	{
		sConfig_IHM.sModele_PAC.bReversible = 1;
	}
	else sConfig_IHM.sModele_PAC.bReversible = 0;
	//
	if(toggleButton_demarreur_progressif.getState())
	{
		sConfig_IHM.sModele_PAC.bDemarreurProgressif = 1;
	}
	else sConfig_IHM.sModele_PAC.bDemarreurProgressif = 0;
	//
	if(toggleButton_nappe_directe.getState())
	{
		sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage = E_TYPE_CAPTAGE_NAPPE_DIRECTE;
	}
	else if(sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage == E_TYPE_CAPTAGE_NAPPE_DIRECTE)
	{
		sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage = E_TYPE_CAPTAGE_CAPTEUR;
	}
	//
	sConfig_IHM.sConfig_PAC.ConfigGeo.u4DebitmetreCaptage = u8DebitmetreCaptage;
	sConfig_IHM.sConfig_PAC.ConfigGeo.u4DebitmetreChauffage = u8DebitmetreChauffage;
	//
	presenter->c_usine_param();
	application().gotoUsine_choix_fluideScreenNoTransition();
}

void Usine_config_geotwinView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_config_geotwinView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_config_geotwinView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_config_geotwinView::changeDate(S_DATE *sDate)
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
