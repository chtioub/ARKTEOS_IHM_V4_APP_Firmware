#include <gui/variables_systeme_screen/Variables_systemeView.hpp>

Variables_systemeView::Variables_systemeView()
{
	int j = 0;

	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPrimaire(&sStatut_Primaire);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_VARIABLES_SYSTEMES_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_marche_arret.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ext.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_temp_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_dep_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ret_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_debit_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_pression_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_type_regul.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_circ_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_circ_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_demande_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ballon_froid.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ballon.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_hysteresis_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cascade_demande.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cascade_nombre_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cascade_pac_on_dispo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_appoint.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_consigne_appoint.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ext_equilibre.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_hysteresis_sonde_ext.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_appoint_en_cours.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_puissance_produite.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_puissance_consommee.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_puissance_consommee_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//
	toggleButton_primaire.setTouchable(false);
}

void Variables_systemeView::setupScreen()
{
    Variables_systemeViewBase::setupScreen();
}

void Variables_systemeView::tearDownScreen()
{
    Variables_systemeViewBase::tearDownScreen();
}

void Variables_systemeView::bouton_retour()
{
	if(bPageUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else application().gotoMaintenanceScreenNoTransition();
}

void Variables_systemeView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	//
	if(sConfig_IHM->sMode_PAC.bEtatPAC != 0)
	{
		textArea_marche_arret_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT));
	}
	else textArea_marche_arret_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT));
    textArea_marche_arret_val.invalidate();
	//
    switch(sConfig_IHM->sParam_PAC.TypeRegul)
	{
		case REGUL_DIRECTE:
			textArea_type_regul_val.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_DROITE_DEFAUT));
			break;
		case REGUL_BCP_INTERNE:
			textArea_type_regul_val.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_BCP_INTERNE_DROITE_DEFAUT));
			break;
		case REGUL_BAL_TAMPON_2_ZONES:
			textArea_type_regul_val.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_DROITE_DEFAUT));
			break;
		case REGUL_BAL_TAMPON_MULTI_ZONE:
			textArea_type_regul_val.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTIZONES_DROITE_DEFAUT));
			break;
		case REGUL_EXTERNE:
			textArea_type_regul_val.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_DROITE_DEFAUT));
			break;
		case REGUL_ESCLAVE:
			textArea_type_regul_val.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_ESCLAVE_DROITE_DEFAUT));
			break;
	}
    textArea_type_regul_val.invalidate();
    //
//    textAreaBuffer_HystBallonPlus[5], textAreaBuffer_HystBallonMoins[5], textAreaBuffer_TempExtEquilibre[6]
	Unicode::snprintfFloat(textAreaBuffer_HystExtMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisTextMoins) / 10);
	Unicode::snprintfFloat(textAreaBuffer_HystExtPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisTextPlus) / 10);
    textArea_hysteresis_sonde_ext_val.setWildcard1(textAreaBuffer_HystExtMoins);
    textArea_hysteresis_sonde_ext_val.setWildcard2(textAreaBuffer_HystExtPlus);
    textArea_hysteresis_sonde_ext_val.invalidate();
    //
	Unicode::snprintfFloat(textAreaBuffer_HystBallonMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisEauMoins) / 10);
	Unicode::snprintfFloat(textAreaBuffer_HystBallonPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisEauPlus) / 10);
	textArea_hysteresis_prim_val.setWildcard1(textAreaBuffer_HystBallonMoins);
	textArea_hysteresis_prim_val.setWildcard2(textAreaBuffer_HystBallonPlus);
	textArea_hysteresis_prim_val.invalidate();
}

void Variables_systemeView::changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire)
{
	//
	Unicode::snprintfFloat(textAreaBuffer_PressionPrimaire, 7, "%.1f", ((float) sStatut_Primaire->u16In_Pression_Eau) / 10);
	textArea_pression_prim_val.setWildcard(textAreaBuffer_PressionPrimaire);
	textArea_pression_prim_val.invalidate();
	//
	Unicode::snprintf(textAreaBuffer_DebitPrimaire, 7, "%d", sStatut_Primaire->u16DebitPrimaire);
	textArea_debit_prim_val.setWildcard(textAreaBuffer_DebitPrimaire);
	textArea_debit_prim_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_ConsignePrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16ConsigneTeauPrimaire) / 10);
	textArea_cons_temp_prim_val.setWildcard(textAreaBuffer_ConsignePrimaire);
	textArea_cons_temp_prim_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_BallonTamponPrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16TeauBallonTampon) / 10);
	textArea_temp_ballon_val.setWildcard(textAreaBuffer_BallonTamponPrimaire);
	textArea_temp_ballon_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_DepartPrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16TeauDepart) / 10);
	textArea_temp_dep_prim_val.setWildcard(textAreaBuffer_DepartPrimaire);
	textArea_temp_dep_prim_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_RetourPrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16TeauRetour) / 10);
	textArea_temp_ret_prim_val.setWildcard(textAreaBuffer_RetourPrimaire);
	textArea_temp_ret_prim_val.invalidate();
	//
	Unicode::snprintf(textAreaBuffer_CirculateurPrimaire, 4, "%d", sStatut_Primaire->u8ConsigneCirculateur);
	textArea_cons_circ_prim_val.setWildcard(textAreaBuffer_CirculateurPrimaire);
	textArea_cons_circ_prim_val.invalidate();
	//
//	memcpy(&sStatut_Primaire_old, sStatut_Primaire, sizeof(S_STATUT_PRIMAIRE));
}

void Variables_systemeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	//
	Unicode::snprintf(textArea_Buffer_pw_produite, 6, "%d", sStatut_PAC->u16PWinstantaneeProduite);
	textArea_puissance_produite_val.setWildcard(textArea_Buffer_pw_produite);
	textArea_puissance_produite_val.invalidate();
	//
	Unicode::snprintf(textArea_Buffer_pw_consommee, 6, "%d", sStatut_PAC->u16PWinstantaneeConsommee);
	textArea_puissance_consommee_val.setWildcard(textArea_Buffer_pw_consommee);
	textArea_puissance_consommee_val.invalidate();
	//
	Unicode::snprintf(textArea_Buffer_tps_mise_tension, 6, "%d", sStatut_PAC->u16TpsMiseSousTension);
	textArea_puissance_consommee_val_1.setWildcard(textArea_Buffer_tps_mise_tension);
	textArea_puissance_consommee_val_1.invalidate();
	//
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Variables_systemeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Variables_systemeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Variables_systemeView::changeDate(S_DATE *sDate)
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
