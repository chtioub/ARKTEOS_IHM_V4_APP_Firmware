#include <gui/installation_regulation_avancee_screen/Installation_regulation_avanceeView.hpp>

Installation_regulation_avanceeView::Installation_regulation_avanceeView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_REGULATION_AVANCEE_TITRE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();
	//
//	bUserAdaptationLoiDeau = sConfig_IHM.sMode_PAC.bUserAdaptationLoiDeau;
//	TempNonChauffage = sConfig_IHM.sParam_PAC.TempNonChauffage;
	//Simultané
//	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
//	{
//		eTypeSimultaneChaudFroid = sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid;
//
//	}
//	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
//	{
//		eTypeSimultaneChaudFroid = sConfig_IHM.sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid;
//	}
	//Limitation froid & ECS ci-dessous à mettre en adéquation avec la page d'avant
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		container_limitation_froid.setVisible(true);
		if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2 && sConfig_IHM.sOption_PAC.ECS)
		{
			container_limitation_ECS.setVisible(true);
		}
		else
		{
			container_limitation_ECS.setVisible(false);
		}
	}
	else
	{
		container_limitation_froid.setVisible(false);
		container_limitation_ECS.setVisible(false);
	}



	if (bLimitationPW_Froid) toggleButton_limitation_froid.forceState(true);
	else toggleButton_limitation_froid.forceState(false);
	toggleButton_limitation_froid.invalidate();

	if (bLimitationPW_ECS) toggleButton_limitation_ECS.forceState(true);
	else toggleButton_limitation_ECS.forceState(false);
	toggleButton_limitation_ECS.invalidate();

	container_limitation_froid.invalidate();
	container_limitation_ECS.invalidate();

	update_adapt_loi_deau();
	update_chaud_froid_simu();
	update_temp_ext_non_chauf();
	update_limitation_ecs();
	update_limitation_froid();
}

void  Installation_regulation_avanceeView::bouton_gauche_temp_non_chauf()
{
	if (TempNonChauffage > 0) TempNonChauffage--;
	else TempNonChauffage = 15;
	update_temp_ext_non_chauf();
}

void  Installation_regulation_avanceeView::bouton_droit_temp_non_chauf()
{
	if (TempNonChauffage < 15) TempNonChauffage++;
	else TempNonChauffage = 0;
	update_temp_ext_non_chauf();
}

void  Installation_regulation_avanceeView::bouton_gauche_chaud_froid_simu()
{
	if (eTypeSimultaneChaudFroid > SIMULTANE_CHAUD_FROID_NONE )
	{
		eTypeSimultaneChaudFroid--;
	}
	else eTypeSimultaneChaudFroid = SIMULTANE_CHAUD_FROID_CONFIGURATION_2;
	update_chaud_froid_simu();
}

void  Installation_regulation_avanceeView::bouton_droit_chaud_froid_simu()
{
	if (eTypeSimultaneChaudFroid < SIMULTANE_CHAUD_FROID_CONFIGURATION_2)
	{
		eTypeSimultaneChaudFroid++;
	}
	else eTypeSimultaneChaudFroid = SIMULTANE_CHAUD_FROID_NONE;
	update_chaud_froid_simu();
}

void  Installation_regulation_avanceeView::bouton_gauche_adapt_loi_deau()
{
	if (bUserAdaptationLoiDeau == 0) bUserAdaptationLoiDeau = 1;
	else bUserAdaptationLoiDeau = 0;
	update_adapt_loi_deau();
}

void  Installation_regulation_avanceeView::bouton_droit_adapt_loi_deau()
{
	if (bUserAdaptationLoiDeau == 0) bUserAdaptationLoiDeau = 1;
	else bUserAdaptationLoiDeau = 0;
	update_adapt_loi_deau();
}

void  Installation_regulation_avanceeView::bouton_hysteresis()
{
	eHysteresis = HYST_EXT;
	ePageHystExt = HYST_EXT_REGUL_AVANCEE;
}

void Installation_regulation_avanceeView::bouton_limitation_ecs()
{
	if(toggleButton_limitation_ECS.getState())
	{
		textArea_on_off_limitation_ECS.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		bLimitationPW_ECS = 1;
	}
	else
	{
		textArea_on_off_limitation_ECS.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		bLimitationPW_ECS = 0;
	}
	textArea_on_off_limitation_ECS.invalidate();
}

void Installation_regulation_avanceeView::bouton_limitation_froid()
{
	if(toggleButton_limitation_froid.getState())
	{
		textArea_on_off_limitation_froid.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		bLimitationPW_Froid = 1;
	}
	else
	{
		textArea_on_off_limitation_froid.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		bLimitationPW_Froid = 0;
	}
	textArea_on_off_limitation_froid.invalidate();
}

void  Installation_regulation_avanceeView::update_adapt_loi_deau()
{
	if (bUserAdaptationLoiDeau == 0)
	{
		textArea_valeur_adapt_loi_deau.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	}
	else
	{
		textArea_valeur_adapt_loi_deau.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	textArea_valeur_adapt_loi_deau.invalidate();
}

void  Installation_regulation_avanceeView::update_chaud_froid_simu()
{

	switch (eTypeSimultaneChaudFroid)
	{
		default:
		case SIMULTANE_CHAUD_FROID_NONE:
			textArea_attention_v3v.setVisible(false);
			textArea_valeur_chaud_froid_simu.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
			break;
		case SIMULTANE_CHAUD_FROID_CONFIGURATION_1:
			textArea_attention_v3v.setVisible(true);
			textArea_valeur_chaud_froid_simu.setTypedText(touchgfx::TypedText(T_TEXT_FREECOOLING_CENTRE_DEFAUT));
			break;
		case SIMULTANE_CHAUD_FROID_CONFIGURATION_2:
			textArea_attention_v3v.setVisible(true);
			textArea_valeur_chaud_froid_simu.setTypedText(touchgfx::TypedText(T_TEXT_FROID_ACTIF_CENTRE_DEFAUT));
			break;
	}
	textArea_attention_v3v.invalidate();
	textArea_valeur_chaud_froid_simu.invalidate();
}

void  Installation_regulation_avanceeView::update_temp_ext_non_chauf()
{
	//Pour affichage du symbol degré
	Unicode::UnicodeChar degre[] = {0x00B0};

	if (TempNonChauffage == 0)
	{
		//textArea_valeur_temp_ext_non_chauf.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		Unicode::snprintf(textAreaBuffer_TempNonChauf, 4, "Off");
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_TempNonChauf, 4, "%d%s", (TempNonChauffage + 15),degre);//, ce_caract);
		Unicode::snprintf(&textAreaBuffer_TempNonChauf[Unicode::strlen(textAreaBuffer_TempNonChauf)], 2, "C");
		//textArea_valeur_temp_ext_non_chauf.setWildcard(textAreaBuffer_TempNonChauf);
	}
	textArea_valeur_temp_ext_non_chauf.setWildcard(textAreaBuffer_TempNonChauf);
	textArea_valeur_temp_ext_non_chauf.invalidate();
}

void  Installation_regulation_avanceeView::update_limitation_ecs()
{
	if (bLimitationPW_ECS)
	{
		textArea_on_off_limitation_ECS.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else
	{
		textArea_on_off_limitation_ECS.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	}
	textArea_on_off_limitation_ECS.invalidate();
}

void  Installation_regulation_avanceeView::update_limitation_froid()
{
	if (bLimitationPW_Froid)
	{
		textArea_on_off_limitation_froid.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else
	{
		textArea_on_off_limitation_froid.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	}
	textArea_on_off_limitation_froid.invalidate();
}

void  Installation_regulation_avanceeView::bouton_retour()
{
	bUserAdaptationLoiDeau = sConfig_IHM.sMode_PAC.bUserAdaptationLoiDeau;
	TempNonChauffage = sConfig_IHM.sParam_PAC.TempNonChauffage;
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		eTypeSimultaneChaudFroid = sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid ;
	}
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		eTypeSimultaneChaudFroid = sConfig_IHM.sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid;
	}
	bLimitationPW_Froid = sConfig_IHM.sConfig_PAC.ConfigGeo.bLimitationPW_Froid;
	bLimitationPW_ECS = sConfig_IHM.sConfig_PAC.ConfigGeo.bLimitationPW_ECS;
}

void  Installation_regulation_avanceeView::bouton_valider()
{
	sConfig_IHM.sMode_PAC.bUserAdaptationLoiDeau = bUserAdaptationLoiDeau;
	sConfig_IHM.sParam_PAC.TempNonChauffage = TempNonChauffage;
	//Simultané
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid = eTypeSimultaneChaudFroid;
	}
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		sConfig_IHM.sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid = eTypeSimultaneChaudFroid;
	}
	//Simultané
	if (eTypeSimultaneChaudFroid > 0)
	{
		sConfig_IHM.sParam_PAC.bChaudFroidSimultane = 1;
		if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
		{
			sConfig_IHM.sParam_PAC.TypeRegul = REGUL_BAL_TAMPON_MULTI_ZONE;
		}
	}
	else
	{
		sConfig_IHM.sParam_PAC.bChaudFroidSimultane = 0;
	}
	//Limitation froid & ECS
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		sConfig_IHM.sConfig_PAC.ConfigGeo.bLimitationPW_Froid = bLimitationPW_Froid;
		sConfig_IHM.sConfig_PAC.ConfigGeo.bLimitationPW_ECS = bLimitationPW_ECS;
	}

	presenter->c_install_param();
	presenter->c_user_zx_all();
	presenter->c_usine_param();
}


void Installation_regulation_avanceeView::setupScreen()
{
    Installation_regulation_avanceeViewBase::setupScreen();
}

void Installation_regulation_avanceeView::tearDownScreen()
{
    Installation_regulation_avanceeViewBase::tearDownScreen();
}


void Installation_regulation_avanceeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_regulation_avanceeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_regulation_avanceeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_regulation_avanceeView::changeDate(S_DATE *sDate)
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
