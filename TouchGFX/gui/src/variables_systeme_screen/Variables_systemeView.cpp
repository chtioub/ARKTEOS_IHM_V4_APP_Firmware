#include <gui/variables_systeme_screen/Variables_systemeView.hpp>

Variables_systemeView::Variables_systemeView()
{
	int j = 0;

	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	memset(&sCyclRegFrigo_old, 0, sizeof(sCyclRegFrigo_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPrimaire(&sStatut_Primaire);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeStatutRegulEsclave(&sStatut_RegulEsclave);
	changeStatutCyclFrigo(&sCyclRegFrigo);
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

void Variables_systemeView::bouton_primaire()
{
	toggleButton_primaire.setTouchable(false);
	toggleButton_primaire.invalidate();
	toggleButton_zones.forceState(false);
	toggleButton_zones.setTouchable(true);
	toggleButton_zones.invalidate();
	toggleButton_groupes.forceState(false);
	toggleButton_groupes.setTouchable(true);
	toggleButton_groupes.invalidate();
	toggleButton_options.forceState(false);
	toggleButton_options.setTouchable(true);
	toggleButton_options.invalidate();
	toggleButton_frigo.forceState(false);
	toggleButton_frigo.setTouchable(true);
	toggleButton_frigo.invalidate();
	toggleButton_config_in_out.forceState(false);
	toggleButton_config_in_out.setTouchable(true);
	toggleButton_config_in_out.invalidate();
	scrollableContainer_primaire.setVisible(true);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_config_in_out.setVisible(false);
	scrollableContainer_config_in_out.invalidate();
}

void Variables_systemeView::bouton_zones()
{
	toggleButton_primaire.forceState(false);
	toggleButton_primaire.setTouchable(true);
	toggleButton_primaire.invalidate();
	toggleButton_zones.setTouchable(false);
	toggleButton_zones.invalidate();
	toggleButton_groupes.forceState(false);
	toggleButton_groupes.setTouchable(true);
	toggleButton_groupes.invalidate();
	toggleButton_options.forceState(false);
	toggleButton_options.setTouchable(true);
	toggleButton_options.invalidate();
	toggleButton_frigo.forceState(false);
	toggleButton_frigo.setTouchable(true);
	toggleButton_frigo.invalidate();
	toggleButton_config_in_out.forceState(false);
	toggleButton_config_in_out.setTouchable(true);
	toggleButton_config_in_out.invalidate();
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(true);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_config_in_out.setVisible(false);
	scrollableContainer_config_in_out.invalidate();
}

void Variables_systemeView::bouton_groupes()
{
	toggleButton_primaire.forceState(false);
	toggleButton_primaire.setTouchable(true);
	toggleButton_primaire.invalidate();
	toggleButton_zones.forceState(false);
	toggleButton_zones.setTouchable(true);
	toggleButton_zones.invalidate();
	toggleButton_groupes.setTouchable(false);
	toggleButton_groupes.invalidate();
	toggleButton_options.forceState(false);
	toggleButton_options.setTouchable(true);
	toggleButton_options.invalidate();
	toggleButton_frigo.forceState(false);
	toggleButton_frigo.setTouchable(true);
	toggleButton_frigo.invalidate();
	toggleButton_config_in_out.forceState(false);
	toggleButton_config_in_out.setTouchable(true);
	toggleButton_config_in_out.invalidate();
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(true);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_config_in_out.setVisible(false);
	scrollableContainer_config_in_out.invalidate();
}

void Variables_systemeView::bouton_options()
{
	toggleButton_primaire.forceState(false);
	toggleButton_primaire.setTouchable(true);
	toggleButton_primaire.invalidate();
	toggleButton_zones.forceState(false);
	toggleButton_zones.setTouchable(true);
	toggleButton_zones.invalidate();
	toggleButton_groupes.forceState(false);
	toggleButton_groupes.setTouchable(true);
	toggleButton_groupes.invalidate();
	toggleButton_options.setTouchable(false);
	toggleButton_options.invalidate();
	toggleButton_frigo.forceState(false);
	toggleButton_frigo.setTouchable(true);
	toggleButton_frigo.invalidate();
	toggleButton_config_in_out.forceState(false);
	toggleButton_config_in_out.setTouchable(true);
	toggleButton_config_in_out.invalidate();
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(true);
	scrollableContainer_options.invalidate();
	scrollableContainer_config_in_out.setVisible(false);
	scrollableContainer_config_in_out.invalidate();
}

void Variables_systemeView::bouton_frigo()
{
	toggleButton_primaire.forceState(false);
	toggleButton_primaire.setTouchable(true);
	toggleButton_primaire.invalidate();
	toggleButton_zones.forceState(false);
	toggleButton_zones.setTouchable(true);
	toggleButton_zones.invalidate();
	toggleButton_groupes.forceState(false);
	toggleButton_groupes.setTouchable(true);
	toggleButton_groupes.invalidate();
	toggleButton_options.forceState(false);
	toggleButton_options.setTouchable(true);
	toggleButton_options.invalidate();
	toggleButton_frigo.setTouchable(false);
	toggleButton_frigo.invalidate();
	toggleButton_config_in_out.forceState(false);
	toggleButton_config_in_out.setTouchable(true);
	toggleButton_config_in_out.invalidate();
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_config_in_out.setVisible(false);
	scrollableContainer_config_in_out.invalidate();
}

void Variables_systemeView::bouton_config_in_out()
{
	toggleButton_primaire.forceState(false);
	toggleButton_primaire.setTouchable(true);
	toggleButton_primaire.invalidate();
	toggleButton_zones.forceState(false);
	toggleButton_zones.setTouchable(true);
	toggleButton_zones.invalidate();
	toggleButton_groupes.forceState(false);
	toggleButton_groupes.setTouchable(true);
	toggleButton_groupes.invalidate();
	toggleButton_options.forceState(false);
	toggleButton_options.setTouchable(true);
	toggleButton_options.invalidate();
	toggleButton_frigo.forceState(false);
	toggleButton_frigo.setTouchable(true);
	toggleButton_frigo.invalidate();
	toggleButton_config_in_out.setTouchable(false);
	toggleButton_config_in_out.invalidate();
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_config_in_out.setVisible(true);
	scrollableContainer_config_in_out.invalidate();
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
	//
	Unicode::snprintfFloat(textAreaBuffer_TempExtEqui, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8Text_Ref_Appoint * 10) / 10);
	textArea_temp_ext_equilibre_val.setWildcard(textAreaBuffer_TempExtEqui);
	textArea_temp_ext_equilibre_val.invalidate();
	//
	if(sConfig_IHM->sMode_PAC.bAppointUser)
	{
		Unicode::snprintf(textAreaBuffer_AppointAutorise, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_AppointAutorise, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	textArea_config_appoint_val.setWildcard1(textAreaBuffer_AppointAutorise);
	textArea_config_appoint_val.invalidate();
	//
	switch(sConfig_IHM->sOption_PAC.TypeAppoint)
	{
		case NO_APPOINT:
			Unicode::snprintf(textAreaBuffer_TypeAppoint, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
			break;
		case ELEC:
			Unicode::snprintf(textAreaBuffer_TypeAppoint, 20, touchgfx::TypedText(T_TEXT_ELECTRIQUE_CENTRE_DEFAUT).getText());
			break;
		case APPOINT_CHAUDIERE:
			Unicode::snprintf(textAreaBuffer_TypeAppoint, 20, touchgfx::TypedText(T_TEXT_APP_CHAUDIERE_CENTRE_DEFAUT).getText());
			break;
		case RELEVE_CHAUDIERE:
			Unicode::snprintf(textAreaBuffer_TypeAppoint, 20, touchgfx::TypedText(T_TEXT_RELEVE_CHAUDIERE_CENTRE_DEFAUT).getText());
			break;
	}
	textArea_config_appoint_val.setWildcard2(textAreaBuffer_TypeAppoint);
	textArea_config_appoint_val.invalidate();
	//
	if(sConfig_IHM->sParam_PAC.bCirculateurPrimaireForce)
	{
		Unicode::snprintf(textAreaBuffer_CircForce, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_CircForce, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	textArea_circ_prim_val.setWildcard1(textAreaBuffer_CircForce);
	textArea_circ_prim_val.invalidate();
	//
	switch(sConfig_IHM->sParam_PAC.eGestionCirculateurPrimaire)
	{
		default:
		case GC_AUTO:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT).getText());
			break;
		case GC_V40:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT).getText());
			break;
		case GC_V50:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT).getText());
			break;
		case GC_V60:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT).getText());
			break;
		case GC_V70:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT).getText());
			break;
		case GC_V80:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT).getText());
			break;
		case GC_V90:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT).getText());
			break;
		case GC_V100:
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT).getText());
			break;
	}
	textArea_circ_prim_val.setWildcard2(textAreaBuffer_GestCirc);
	textArea_circ_prim_val.invalidate();
	//
	if((sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV && sConfig_IHM->sConfig_PAC.ConfigGeo.eTypeSimultaneChaudFroid != 0) || (sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA && sConfig_IHM->sConfig_PAC.ConfigGeoInverter.eTypeSimultaneChaudFroid != 0))
	{
		textArea_temp_ballon_froid.setTypedText(touchgfx::TypedText(T_TEXT_BALLON_TAMPON_FROID_GAUCHE_DEFAUT));
		textArea_temp_ballon_froid_val.setVisible(true);
	}
	else
	{
		textArea_temp_ballon_froid.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_VIDE_GAUCHE_DEFAUT));
		textArea_temp_ballon_froid_val.setVisible(false);
	}
	textArea_temp_ballon_froid.invalidate();
	textArea_temp_ballon_froid_val.invalidate();
	//
	if(sConfig_IHM->sParam_PAC.TypeRegul > REGUL_DIRECTE && sConfig_IHM->sParam_PAC.TypeRegul < REGUL_ESCLAVE && sConfig_IHM->sParam_PAC.bGestionCascade == 1 && sConfig_IHM->sParam_PAC.numEsclave > 0)
	{
		textArea_cascade_na.setVisible(false);
		textArea_cascade_demande_val.setVisible(true);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_CascadePresence, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_cascade_nombre_pac_val.setWildcard1(textAreaBuffer_CascadePresence);
		Unicode::snprintf(textAreaBuffer_CascadeTotal, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_cascade_nombre_pac_val.setWildcard2(textAreaBuffer_CascadeTotal);
		textArea_cascade_nombre_pac_val.invalidate();
		Unicode::snprintf(textAreaBuffer_CascadeOn, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_cascade_pac_on_dispo_val.setWildcard1(textAreaBuffer_CascadeOn);
		Unicode::snprintf(textAreaBuffer_CascadeDispo, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_cascade_pac_on_dispo_val.setWildcard2(textAreaBuffer_CascadeDispo);
		textArea_cascade_pac_on_dispo_val.invalidate();
		textArea_cascade_na.setVisible(true);
		textArea_cascade_demande_val.setVisible(false);
	}
	textArea_cascade_na.invalidate();
	textArea_cascade_demande_val.invalidate();
}

void Variables_systemeView::changeStatutRegulEsclave(S_STATUT_REGUL_ESCLAVE *sStatut_RegulEsclave)
{
	//
	switch(sStatut_RegulEsclave->maitre.u8OperatingDemande)
	{
		default:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_ARRET_CENTRE_DEFAUT).getText());
			break;
		case F_CHAUD:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_CHAUD_CENTRE_DEFAUT).getText());
			break;
		case F_FROID:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_FROID_CENTRE_DEFAUT).getText());
			break;
		case F_PISCINE:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_DEFAUT).getText());
			break;
		case F_ECS:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_ECS_CENTRE_DEFAUT).getText());
			break;
		case F_ARRET_URGENT:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_ARRET_URGENCE_CENTRE_DEFAUT).getText());
			break;
		case F_PUMP_DOWN:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_PUMP_DOWN_CENTRE_DEFAUT).getText());
			break;
		case F_TEST_CPS:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_TEST_CPS_CENTRE_DEFAUT).getText());
			break;
		case F_CIRCUL:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_CIRCULATEUR_CENTRE_DEFAUT).getText());
			break;
		case F_CHAUD_FROID:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_CHAUD_FROID_CENTRE_DEFAUT).getText());
			break;
		case F_ECS_FROID:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_ECS_FROID_CENTRE_DEFAUT).getText());
			break;
		case F_PISCINE_FROID:
			Unicode::snprintf(textAreaBuffer_DemandeCascade, 20, touchgfx::TypedText(T_TEXT_PISCINE_FROID_CENTRE_DEFAUT).getText());
			break;
	}
	textArea_cascade_demande_val.setWildcard1(textAreaBuffer_DemandeCascade);
	textArea_cascade_demande_val.invalidate();
	//
	for(int i = 0; i < 8; i++)
	{
		if((sStatut_RegulEsclave->maitre.u8PacPresente & (1 >> i)) != 0)
		{
			textAreaBuffer_CascadePresence[7 - i] = '1';
		}
		else textAreaBuffer_CascadePresence[7 - i] = '0';
	}
	textAreaBuffer_CascadePresence[8] = 0;
	textArea_cascade_nombre_pac_val.setWildcard1(textAreaBuffer_CascadePresence);
	Unicode::snprintf(textAreaBuffer_CascadeTotal, 3, "%d", sStatut_RegulEsclave->maitre.u8NbPacCascadeTotale);
	textArea_cascade_nombre_pac_val.setWildcard2(textAreaBuffer_CascadeTotal);
	textArea_cascade_nombre_pac_val.invalidate();
	Unicode::snprintf(textAreaBuffer_CascadeOn, 3, "%d", sStatut_RegulEsclave->maitre.u8PacEnMarche);
	textArea_cascade_pac_on_dispo_val.setWildcard1(textAreaBuffer_CascadeOn);
	Unicode::snprintf(textAreaBuffer_CascadeDispo, 3, "%d", sStatut_RegulEsclave->maitre.u8NbPacCascadeDispo);
	textArea_cascade_pac_on_dispo_val.setWildcard2(textAreaBuffer_CascadeDispo);
	textArea_cascade_pac_on_dispo_val.invalidate();
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
	textArea_demande_pac_val.setWildcard2(textAreaBuffer_ConsignePrimaire);
	textArea_demande_pac_val.invalidate();
	textArea_cons_temp_prim_val.setWildcard1(textAreaBuffer_ConsignePrimaire);
	textArea_cons_temp_prim_val.invalidate();
	textArea_cascade_demande_val.setWildcard2(textAreaBuffer_ConsignePrimaire);
	textArea_cascade_demande_val.invalidate();
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

void Variables_systemeView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	//
	Unicode::snprintfFloat(textAreaBuffer_Temp_Ext, 7, "%.1f", ((float) sCyclRegFrigo->commun.i16Text) / 10);
	textArea_temp_ext_val.setWildcard(textAreaBuffer_Temp_Ext);
	textArea_temp_ext_val.invalidate();
	//
	if(sCyclRegFrigo->commun.sStatut.bMaxPW)
	{
		Unicode::snprintf(textAreaBuffer_MaxPW, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_MaxPW, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	textArea_appoint_en_cours_val.setWildcard1(textAreaBuffer_MaxPW);
	textArea_appoint_en_cours_val.invalidate();

	// Mémorisation de l'état précédent
	memcpy(&sCyclRegFrigo_old, sCyclRegFrigo, sizeof(S_CYCL_REG_FRI));
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
	switch(sStatut_PAC->sFonctOutxTor.u2PW_Elec)
	{
		case P0:
			Unicode::snprintf(textArea_Buffer_AppointVal, 4, "0");
			Unicode::snprintf(textAreaBuffer_AppointEnCours, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
			break;
		case P33:
			Unicode::snprintf(textArea_Buffer_AppointVal, 4, "33");
			Unicode::snprintf(textAreaBuffer_AppointEnCours, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
			break;
		case P66:
			Unicode::snprintf(textArea_Buffer_AppointVal, 4, "66");
			Unicode::snprintf(textAreaBuffer_AppointEnCours, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
			break;
		case P100:
			Unicode::snprintf(textArea_Buffer_AppointVal, 4, "100");
			Unicode::snprintf(textAreaBuffer_AppointEnCours, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
			break;
	}
	textArea_consigne_appoint_val.setWildcard(textArea_Buffer_AppointVal);
	textArea_consigne_appoint_val.invalidate();
	textArea_appoint_en_cours_val.setWildcard2(textAreaBuffer_AppointEnCours);
	textArea_appoint_en_cours_val.invalidate();
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

void Variables_systemeView::changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo)
{
	//
	switch(sDemandeFrigo->Demande)
	{
		default:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_ARRET_CENTRE_DEFAUT).getText());
			break;
		case F_CHAUD:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_CHAUD_CENTRE_DEFAUT).getText());
			break;
		case F_FROID:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_FROID_CENTRE_DEFAUT).getText());
			break;
		case F_PISCINE:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_DEFAUT).getText());
			break;
		case F_ECS:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_ECS_CENTRE_DEFAUT).getText());
			break;
		case F_ARRET_URGENT:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_ARRET_URGENCE_CENTRE_DEFAUT).getText());
			break;
		case F_PUMP_DOWN:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_PUMP_DOWN_CENTRE_DEFAUT).getText());
			break;
		case F_TEST_CPS:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_TEST_CPS_CENTRE_DEFAUT).getText());
			break;
		case F_CIRCUL:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_CIRCULATEUR_CENTRE_DEFAUT).getText());
			break;
		case F_CHAUD_FROID:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_CHAUD_FROID_CENTRE_DEFAUT).getText());
			break;
		case F_ECS_FROID:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_ECS_FROID_CENTRE_DEFAUT).getText());
			break;
		case F_PISCINE_FROID:
			Unicode::snprintf(textAreaBuffer_Demande, 20, touchgfx::TypedText(T_TEXT_PISCINE_FROID_CENTRE_DEFAUT).getText());
			break;
	}
	textArea_demande_pac_val.setWildcard1(textAreaBuffer_Demande);
	textArea_demande_pac_val.invalidate();
	//
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		Unicode::snprintfFloat(textAreaBuffer_BallonTamponFroid, 7, "%.1f", ((float) sDemandeFrigo->sSupplementPAC.Geo.i16ConsigneTeauFroid) / 10);
	}
	else if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA)
	{
		Unicode::snprintfFloat(textAreaBuffer_BallonTamponFroid, 7, "%.1f", ((float) sDemandeFrigo->sSupplementPAC.geoinverter.i16ConsigneTeauFroid) / 10);
	}
	textArea_temp_ballon_val.setWildcard(textAreaBuffer_BallonTamponFroid);
	textArea_temp_ballon_val.invalidate();

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
