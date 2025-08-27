#include <gui/variables_systeme_screen/Variables_systemeView.hpp>
#include <touchgfx/Utils.hpp>

Variables_systemeView::Variables_systemeView()
{
//	int j = 0;

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
	changeStatutCyclFrigo(&sCyclRegFrigo[0]);
	changeStatutRF(&sStatut_RF[0]);
	changeStatutRF(&sStatut_RF[1]);

	changeStatutZx(0, &sStatut_Zx[0]);
	changeStatutZx(1, &sStatut_Zx[1]);
	changeStatutZx(2, &sStatut_Zx[2]);
	changeStatutZx(3, &sStatut_Zx[3]);
	changeStatutZx(4, &sStatut_Zx[4]);
	changeStatutZx(5, &sStatut_Zx[5]);
	changeStatutZx(6, &sStatut_Zx[6]);
	changeStatutZx(7, &sStatut_Zx[7]);
	changeStatutZx(8, &sStatut_Zx[8]);
	changeStatutZx(9, &sStatut_Zx[9]);

	changeStatutECS(&sStatut_ECS);
	changeStatutPiscine(&sStatut_Piscine);
	changeDemandeFrigo(&sDemandeFrigo);
	changeStatutTempsFonct(&sStatut_TpsFonct);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_VARIABLES_SYSTEMES_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	//Pour afficher la page primaire en premier
	bouton_primaire();
	//
	toggleButton_primaire.setTouchable(false);

	oldTempHP = 0;;

}

void Variables_systemeView::setupScreen()
{
    Variables_systemeViewBase::setupScreen();
}

void Variables_systemeView::tearDownScreen()
{
    Variables_systemeViewBase::tearDownScreen();
}

void Variables_systemeView::update_num_ligne_primaire()
{
	int j = 0;
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
}

void Variables_systemeView::update_num_ligne_zone()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	for( int k = 0; k < 8; k++)
	{
		Unicode::snprintf(&textAreaBuffer_NumZone[k][0],3,"%d", k+1);
	}
	//Zone 1
	textArea_mode_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_temp_int_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_cons_int_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_type_sonde_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_temp_dep_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_temp_ret_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_cons_temp_dep_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	textArea_debit_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[0].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
		textArea_consigne_circulateur_zone_1.setVisible(false);
		textArea_circulateur_zone_1.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
		textArea_circulateur_zone_1.setVisible(false);
		textArea_consigne_circulateur_zone_1.setVisible(true);
	}
	textArea_circulateur_zone_1.invalidate();
	textArea_consigne_circulateur_zone_1.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[0].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
		textArea_cons_v3v_zone_1.setVisible(false);
		textArea_cons_registre_zone_1.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_1.setWildcard2(&textAreaBuffer_NumZone[0][0]);
		textArea_cons_registre_zone_1.setVisible(false);
		textArea_cons_v3v_zone_1.setVisible(true);
	}
	textArea_cons_v3v_zone_1.invalidate();
	textArea_cons_registre_zone_1.invalidate();
	j++;
	textArea_vide_zone_1.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 2
	textArea_mode_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_temp_int_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_cons_int_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_type_sonde_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_temp_dep_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_temp_ret_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_cons_temp_dep_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	textArea_debit_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[1].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
		textArea_consigne_circulateur_zone_2.setVisible(false);
		textArea_circulateur_zone_2.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
		textArea_circulateur_zone_2.setVisible(false);
		textArea_consigne_circulateur_zone_2.setVisible(true);
	}
	textArea_circulateur_zone_2.invalidate();
	textArea_consigne_circulateur_zone_2.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[1].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
		textArea_cons_v3v_zone_2.setVisible(false);
		textArea_cons_registre_zone_2.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_2.setWildcard2(&textAreaBuffer_NumZone[1][0]);
		textArea_cons_registre_zone_2.setVisible(false);
		textArea_cons_v3v_zone_2.setVisible(true);
	}
	textArea_cons_v3v_zone_2.invalidate();
	textArea_cons_registre_zone_2.invalidate();
	j++;
	textArea_vide_zone_2.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 3
	textArea_mode_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_temp_int_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_cons_int_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_type_sonde_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_temp_dep_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_temp_ret_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_cons_temp_dep_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	textArea_debit_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[2].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
		textArea_consigne_circulateur_zone_3.setVisible(false);
		textArea_circulateur_zone_3.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
		textArea_circulateur_zone_3.setVisible(false);
		textArea_consigne_circulateur_zone_3.setVisible(true);
	}
	textArea_circulateur_zone_3.invalidate();
	textArea_consigne_circulateur_zone_3.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[2].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
		textArea_cons_v3v_zone_3.setVisible(false);
		textArea_cons_registre_zone_3.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_3.setWildcard2(&textAreaBuffer_NumZone[2][0]);
		textArea_cons_registre_zone_3.setVisible(false);
		textArea_cons_v3v_zone_3.setVisible(true);
	}
	textArea_cons_v3v_zone_3.invalidate();
	textArea_cons_registre_zone_3.invalidate();
	j++;
	textArea_vide_zone_3.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 4
	textArea_mode_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_temp_int_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_cons_int_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_type_sonde_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_temp_dep_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_temp_ret_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_cons_temp_dep_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	textArea_debit_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[3].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
		textArea_consigne_circulateur_zone_4.setVisible(false);
		textArea_circulateur_zone_4.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
		textArea_circulateur_zone_4.setVisible(false);
		textArea_consigne_circulateur_zone_4.setVisible(true);
	}
	textArea_circulateur_zone_4.invalidate();
	textArea_consigne_circulateur_zone_4.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[3].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
		textArea_cons_v3v_zone_4.setVisible(false);
		textArea_cons_registre_zone_4.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_4.setWildcard2(&textAreaBuffer_NumZone[3][0]);
		textArea_cons_registre_zone_4.setVisible(false);
		textArea_cons_v3v_zone_4.setVisible(true);
	}
	textArea_cons_v3v_zone_4.invalidate();
	textArea_cons_registre_zone_4.invalidate();
	j++;
	textArea_vide_zone_4.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 5
	textArea_mode_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_temp_int_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_cons_int_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_type_sonde_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_temp_dep_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_temp_ret_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_cons_temp_dep_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	textArea_debit_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[4].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
		textArea_consigne_circulateur_zone_5.setVisible(false);
		textArea_circulateur_zone_5.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
		textArea_circulateur_zone_5.setVisible(false);
		textArea_consigne_circulateur_zone_5.setVisible(true);
	}
	textArea_circulateur_zone_5.invalidate();
	textArea_consigne_circulateur_zone_5.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[4].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
		textArea_cons_v3v_zone_5.setVisible(false);
		textArea_cons_registre_zone_5.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_5.setWildcard2(&textAreaBuffer_NumZone[4][0]);
		textArea_cons_registre_zone_5.setVisible(false);
		textArea_cons_v3v_zone_5.setVisible(true);
	}
	textArea_cons_v3v_zone_5.invalidate();
	textArea_cons_registre_zone_5.invalidate();
	j++;
	textArea_vide_zone_5.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 6
	textArea_mode_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_temp_int_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_cons_int_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_type_sonde_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_temp_dep_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_temp_ret_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_cons_temp_dep_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	textArea_debit_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[5].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
		textArea_consigne_circulateur_zone_6.setVisible(false);
		textArea_circulateur_zone_6.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
		textArea_circulateur_zone_6.setVisible(false);
		textArea_consigne_circulateur_zone_6.setVisible(true);
	}
	textArea_circulateur_zone_6.invalidate();
	textArea_consigne_circulateur_zone_6.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[5].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
		textArea_cons_v3v_zone_6.setVisible(false);
		textArea_cons_registre_zone_6.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_6.setWildcard2(&textAreaBuffer_NumZone[5][0]);
		textArea_cons_registre_zone_6.setVisible(false);
		textArea_cons_v3v_zone_6.setVisible(true);
	}
	textArea_cons_v3v_zone_6.invalidate();
	textArea_cons_registre_zone_6.invalidate();
	j++;
	textArea_vide_zone_6.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 7
	textArea_mode_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_temp_int_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_cons_int_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_type_sonde_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_temp_dep_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_temp_ret_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_cons_temp_dep_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	textArea_debit_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[6].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
		textArea_consigne_circulateur_zone_7.setVisible(false);
		textArea_circulateur_zone_7.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
		textArea_circulateur_zone_7.setVisible(false);
		textArea_consigne_circulateur_zone_7.setVisible(true);
	}
	textArea_circulateur_zone_7.invalidate();
	textArea_consigne_circulateur_zone_7.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[6].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
		textArea_cons_v3v_zone_7.setVisible(false);
		textArea_cons_registre_zone_7.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_7.setWildcard2(&textAreaBuffer_NumZone[6][0]);
		textArea_cons_registre_zone_7.setVisible(false);
		textArea_cons_v3v_zone_7.setVisible(true);
	}
	textArea_cons_v3v_zone_7.invalidate();
	textArea_cons_registre_zone_7.invalidate();
	j++;
	textArea_vide_zone_7.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	//Zone 8
	textArea_mode_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_mode_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_temp_int_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_int_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_cons_int_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_int_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_hyst_sonde_ambiance_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_hyst_sonde_ambiance_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_type_sonde_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_type_sonde_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_temp_dep_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_dep_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_temp_ret_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_temp_ret_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_cons_temp_dep_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_cons_temp_dep_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	textArea_debit_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	textArea_debit_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
	j++;
	if (sConfig_IHM.sParam_Zx[7].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_RELAIS)
	{
		textArea_circulateur_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_circulateur_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
		textArea_consigne_circulateur_zone_8.setVisible(false);
		textArea_circulateur_zone_8.setVisible(true);
	}
	else
	{
		textArea_consigne_circulateur_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_consigne_circulateur_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
		textArea_circulateur_zone_8.setVisible(false);
		textArea_consigne_circulateur_zone_8.setVisible(true);
	}
	textArea_circulateur_zone_8.invalidate();
	textArea_consigne_circulateur_zone_8.invalidate();
	j++;
	if (sConfig_IHM.sParam_Zx[7].TypeEmmetteur == GAINABLE)
	{
		textArea_cons_registre_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_registre_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
		textArea_cons_v3v_zone_8.setVisible(false);
		textArea_cons_registre_zone_8.setVisible(true);
	}
	else
	{
		textArea_cons_v3v_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
		textArea_cons_v3v_zone_8.setWildcard2(&textAreaBuffer_NumZone[7][0]);
		textArea_cons_registre_zone_8.setVisible(false);
		textArea_cons_v3v_zone_8.setVisible(true);
	}
	textArea_cons_v3v_zone_8.invalidate();
	textArea_cons_registre_zone_8.invalidate();
	j++;
	textArea_vide_zone_8.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
}

void Variables_systemeView::update_num_ligne_groupes()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_mode_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_dep_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ret_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_temp_dep_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_circ_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_v3V_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_circ_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_groupe_a.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_mode_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_dep_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ret_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_temp_dep_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_circ_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_v3V_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_circ_groupe_b.setWildcard1(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_groupe_b.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;

	//Groupe A
	Unicode::snprintf(textAreaBuffer_EmettGroupeA, 9, touchgfx::TypedText(T_TEXT_VALUE_GROUPEA).getText());
	Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 3, " (");
	switch(sConfig_IHM.sParam_Zx[ZONE_GROUPE_A].TypeEmmetteur)
	{
		case RADIATEUR:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 17, touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT).getText());
			break;
		case VENTILO:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 17, touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT).getText());
			break;
		case PLANCHER:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 17, touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT).getText());
			break;
		case GAINABLE:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 17, touchgfx::TypedText(T_TEXT_GAINABLE_CENTRE_DEFAUT).getText());
			break;
		case SOUS_STATION:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 17, touchgfx::TypedText(T_TEXT_SOUS_STATION_CENTRE_DEFAUT).getText());
			break;
		default:
			break;
	}
	Unicode::snprintf(&textAreaBuffer_EmettGroupeA[Unicode::strlen(textAreaBuffer_EmettGroupeA)], 2, ")");
	textArea_mode_groupe_a.setWildcard2(textAreaBuffer_EmettGroupeA);
	textArea_mode_groupe_a.invalidate();

	Unicode::snprintf(textAreaBuffer_NomGroupeA, 9, touchgfx::TypedText(T_TEXT_VALUE_GROUPEA).getText());
	textArea_temp_dep_groupe_a.setWildcard2(textAreaBuffer_NomGroupeA);
	textArea_temp_dep_groupe_a.invalidate();
	textArea_temp_ret_groupe_a.setWildcard2(textAreaBuffer_NomGroupeA);
	textArea_temp_ret_groupe_a.invalidate();
	textArea_cons_temp_dep_groupe_a.setWildcard2(textAreaBuffer_NomGroupeA);
	textArea_cons_temp_dep_groupe_a.invalidate();
	textArea_circ_groupe_a.setWildcard2(textAreaBuffer_NomGroupeA);
	textArea_circ_groupe_a.invalidate();
	textArea_cons_v3V_groupe_a.setWildcard2(textAreaBuffer_NomGroupeA);
	textArea_cons_v3V_groupe_a.invalidate();
	textArea_cons_circ_groupe_a.setWildcard2(textAreaBuffer_NomGroupeA);
	textArea_cons_circ_groupe_a.invalidate();

	//Groupe B
	Unicode::snprintf(textAreaBuffer_EmettGroupeB, 9, touchgfx::TypedText(T_TEXT_VALUE_GROUPEB).getText());
	Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 3, " (");
	switch(sConfig_IHM.sParam_Zx[ZONE_GROUPE_B].TypeEmmetteur)
	{
		case RADIATEUR:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 17, touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT).getText());
			break;
		case VENTILO:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 17, touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT).getText());
			break;
		case PLANCHER:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 17, touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT).getText());
			break;
		case GAINABLE:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 17, touchgfx::TypedText(T_TEXT_GAINABLE_CENTRE_DEFAUT).getText());
			break;
		case SOUS_STATION:
			Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 17, touchgfx::TypedText(T_TEXT_SOUS_STATION_CENTRE_DEFAUT).getText());
			break;
		default:
			break;
	}
	Unicode::snprintf(&textAreaBuffer_EmettGroupeB[Unicode::strlen(textAreaBuffer_EmettGroupeB)], 2, ")");
	textArea_mode_groupe_b.setWildcard2(textAreaBuffer_EmettGroupeB);
	textArea_mode_groupe_b.invalidate();

	Unicode::snprintf(textAreaBuffer_NomGroupeB, 9, touchgfx::TypedText(T_TEXT_VALUE_GROUPEB).getText());
	textArea_temp_dep_groupe_b.setWildcard2(textAreaBuffer_NomGroupeB);
	textArea_temp_dep_groupe_b.invalidate();
	textArea_temp_ret_groupe_b.setWildcard2(textAreaBuffer_NomGroupeB);
	textArea_temp_ret_groupe_b.invalidate();
	textArea_cons_temp_dep_groupe_b.setWildcard2(textAreaBuffer_NomGroupeB);
	textArea_cons_temp_dep_groupe_b.invalidate();
	textArea_circ_groupe_b.setWildcard2(textAreaBuffer_NomGroupeB);
	textArea_circ_groupe_b.invalidate();
	textArea_cons_v3V_groupe_b.setWildcard2(textAreaBuffer_NomGroupeB);
	textArea_cons_v3V_groupe_b.invalidate();
	textArea_cons_circ_groupe_b.setWildcard2(textAreaBuffer_NomGroupeB);
	textArea_cons_circ_groupe_b.invalidate();
}


void Variables_systemeView::update_num_ligne_option()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_temp_ecs_milieu.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_ecs_bas.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_relance_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_hyst_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_app_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cycle_legion.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_duree_cycle_thermo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_tps_rotation_v3v.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_fin_cycle_thermo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_sonde_spare1_depart.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_sonde_spare2_depart.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_options_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_temp_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cons_depart_eau_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_hyst_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_option_relance.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_tps_rotation_v3v_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_auto_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_option_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
}

void Variables_systemeView::update_num_ligne_frigo_zu_ba_tim()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	switch (sConfig_IHM.sModele_PAC.u3SousTypePAC)
	{
		case SOUS_TYPE_BAGUIO_PP:
			if (sCyclRegFrigo[0].pac.zuba.sStatutMitsu.Tension_DC == 0)
			{
				textArea_zuba_vide_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_statut_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_freq_cible.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_type_capacite_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_tps_fct_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_degivrage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_nb_degivrage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_ventilateur_on_off.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_dep_prim_mitsu.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_cons_depart_eau_mitsu.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sortie_tor_relais1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sortie_tor_relais2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sortie_tor_relais3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_trame_connue.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_code_trame_inconnue.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_nb_trame_inconnue.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_code_erreur_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_5.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_6.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_7.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
			}
			else
			{
				textArea_zuba_vide_1_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_2_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_statut_pac_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_freq_cible_actu_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_type_capacite_pac_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_tps_fct_pac_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_tps_fct_comp_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_nb_cycle_comp_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_tension_dc_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_courant_ac_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_3_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_temp_cond_pression_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_temp_refoul_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_temp_in_evapo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_temp_rad_driver.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_temp_liquide.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_4_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_surchauffe.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sous_refr_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_5_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_detendeur_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_degivrage_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_nb_degivrage_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_ventilateur_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_6_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_dep_prim_mitsu_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_cons_depart_eau_mitsu_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_7_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sortie_tor_relais1_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sortie_tor_relais2_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_sortie_tor_relais3_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_trame_connue_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_code_trame_inconnue_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_nb_trame_inconnue_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_code_erreur_pac_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
				textArea_zuba_vide_8_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				j++;
			}
			break;
		default:
			textArea_zuba_statut_pac_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_freq_cible_actu_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_type_capacite_pac_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_tps_fct_pac_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_tps_fct_comp_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_nb_cycle_comp_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_tension_dc_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_courant_ac_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_vide_1_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_temp_cond_pression_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_temp_refoul_comp_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_temp_evapo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_temp_in_evapo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_temp_entree_evapo_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_aspi_comp_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R32)
			{
				textArea_zuba_temp_liquide_TH34_2.setVisible(true);
				textArea_zuba_temp_liquide_TH32_2.setVisible(false);
				textArea_zuba_temp_liquide_TH34_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				textArea_zuba_temp_liquide_TH34_2.invalidate();
				textArea_zuba_temp_liquide_TH32_2.invalidate();
			}
			else
			{
				textArea_zuba_temp_liquide_TH34_2.setVisible(false);
				textArea_zuba_temp_liquide_TH32_2.setVisible(true);
				textArea_zuba_temp_liquide_TH32_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				textArea_zuba_temp_liquide_TH34_2.invalidate();
				textArea_zuba_temp_liquide_TH32_2.invalidate();
			}
			j++;
			if (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3 > 250)
			{
				textArea_zuba_surchauffe_TH4_T63_2.setVisible(true);
				textArea_zuba_surchauffe_SHD_2.setVisible(false);
				textArea_zuba_surchauffe_TH4_T63_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				textArea_zuba_surchauffe_TH4_T63_2.invalidate();
				textArea_zuba_surchauffe_SHD_2.invalidate();
			}
			else
			{
				textArea_zuba_surchauffe_TH4_T63_2.setVisible(false);
				textArea_zuba_surchauffe_SHD_2.setVisible(true);
				textArea_zuba_surchauffe_SHD_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
				textArea_zuba_surchauffe_TH4_T63_2.invalidate();
				textArea_zuba_surchauffe_SHD_2.invalidate();
			}
			j++;
			textArea_zuba_sous_refr_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_vide_2_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_vide_3_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_vide_4_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_detendeur_A_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_detendeur_B_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_detendeur_C_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_degivrage_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_nb_degivrage_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_ventilateur_1_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_ventilateur_2_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_vide_5_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_sortie_tor_relais1_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_sortie_tor_relais2_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_sortie_tor_relais3_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_trame_connue_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_code_trame_inconnue_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_nb_trame_inconnue_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_acces_mode_cde.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_code_erreur_pac_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			textArea_zuba_vide_6_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
			j++;
			break;
	}
}


void Variables_systemeView::update_num_ligne_in_out()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_option_app_elec.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_option_nb_zones.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_option_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_option_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_option_app_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_option_wattmetre.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_config_in_out_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_ecs_dem_debut_cycle.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_ecs_entree_contact.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_ecs_bain_marie.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_piscine_confort.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_hyst_chaud_froid.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_hyst_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_hyst_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_adapt_loi_eau.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_chaud_froid_simu.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_mode_secours_defaut_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_duree_cycle_degivrage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_mode_silencieux.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_reduction_pw.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_priorite_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_shunt_tempo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_cycle_antilegionelle.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_config_mode_gestion_v3v.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_config_in_out_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_marche_piscine.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_v3v_pisc_sirc.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_config_in_out_3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_th1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_th2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_ejp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_defaut_app.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_adapt_loi_deau.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_adapt_consigne.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_tor_free_heating.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_marche_arret_general.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_abaissement_cons.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_marche_arret.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_chaud_froid.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_delestage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_fonction4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_fonction5.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_fonction6.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_fonction7.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_config_in_out_4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_autorisation_solaire.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_in_boost_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_circul_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_v3v_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_appoint_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_bouclage_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_config_in_out_5.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_pw_appoint.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_resistance_carter.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_releve_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_info_chaud_froid.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_defaut_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_chaud_froid_simu1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_chaud_froid_simu2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_marche_arret_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_fonction8.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_fonction9.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_out_fonction10.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_vide_config_in_out_6.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
}


void Variables_systemeView::update_num_ligne_frigo_inv()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_inv_type_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_modele_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_reversible.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textAreainv_freecool.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_fluide.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_modele_driver.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_nbcycle.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temps_fct.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_statut_reduc_pw.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_statut_driver.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_dsp_reset.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_defaut_driver.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_dem_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_redem_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_augm_vit.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_dim_vit.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_protect_lim_vit_basse.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_protect_lim_vit_haute.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_pfc.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_courant_phase.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_courant_in_ac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_tenion_in_ac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_tension_dc.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_ipm.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_pfc.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_courant_u_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_courant_v_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_courant_w_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_vit_mes_courant.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_dlt.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_statut_frigo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_cond_max.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_cond_min.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_press_hp_max.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_type_restriction.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_machine_ok.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_retour_huile.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_pb_thermo.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_pre_chauf.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_spare.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea__inv_analogiques.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_dep_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_ret_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_press_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_debit_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_ext.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_dep_cap.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_ret_cap.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_press_cap.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_debit_cap.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_liqu.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_hp_cible.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_hp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_temp_bp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_press_hp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_press_bp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_demande_vitesse.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_vitesse_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_vitesse_comp_stable.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_analogiques.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_pos_eev_ev.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_pos_eev_cd.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_cons_circ_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_gestion_circ_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_gestion_circ_cap.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_vitesse_pompe_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_appoint1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_appoint23.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_comp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_comp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_contact_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_ev_froid.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_resist_carter.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_resist_vase.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_spare1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_spare2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_v4v.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_out_tor_ventil_driver.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_tor.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_debit_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_defaut_app1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_defaut_app2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_defaut_app3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_defaut_dempro1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_defaut_dempro2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_klixon_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_secu_hp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_secu_hp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_sw1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_sw2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_sw3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_in_sw4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_config_switchx.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_inv_vide.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
}


void Variables_systemeView::update_num_ligne_frigo_geo()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_geo_config_switch.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_vide_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_type_captage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_freecooling.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_circ_prim_gestion.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_circ_capt_gestion.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_vitesse_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_pw_captee_inst.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textAreageo_pw_restituee.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_nb_comp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_reversibilite.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_alimentation.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_dem_pro.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_statut_pac.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_cycle_retour_huile.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_limitation_pw_froid.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_limitation_pw_ecs.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_defaut_comp_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_defaut_comp_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_statut_comp_1_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temps_fct_comp_1_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_nb_cycle_comp_1_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_pression_captage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_debit_captage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temp_captage_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_press_temp_hp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_press_temp_bp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_pos_eev_spare.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_vide_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_coef_poly_cible.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temp_hp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temp_hp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temp_bp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temp_bp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_temp_cond.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_vide_3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_in_tor_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_in_secu_hp.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_in_dem_pro_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_in_dem_pro_2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	text_var_sys_geo_vide_4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_circ_prim.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_circ_capt.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_v4v.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_puits.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_comp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_comp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_spare1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_out_spare2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_led_defaut.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_geo_led_verte.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	text_var_sys_geo_vide_5.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
}

void Variables_systemeView::update_num_ligne_frigo_ajpac()
{
	int j = 0;
	for(int i = 0; i < 99; i++)
	{
		Unicode::snprintf(&textAreaBuffer_NumLigne[i][0], 3, "%d", i + 1);
	}
	//
	textArea_ajp_statut_comp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_tps_fct_comp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_nb_cycle_comp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_statut_comp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_tps_fct_comp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_nb_cycle_comp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_alim_AC.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_alim_DC.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_vide_1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_demande_comp1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_demande_comp2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_objectif_temp_410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tds_410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tsc410a.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tsc410b.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_objectif_temp_134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tds_134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tev_134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_igbt.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pression_temp_hp410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pression_temp_bp410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pression_temp_int410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pression_temp_bp134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pression_temp_hp134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pressostat_hp410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pressostat_hp134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_v4v.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_nb_defrost.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pos_eev_int.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_pos_eev134.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ev410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ventil_pw.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_spare.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_mode_mode_hz_max_min.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_vide.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_vide1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ventil_ue_tor.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ev_ue.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ev3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ev4.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ev5.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_ventil_ue_ana.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_led_defaut.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_eev_ue410.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tev_in.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_temp_tev_out.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_vitesse_ventil1.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_vitesse_ventil2.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_degivrage.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
	textArea_ajp_vide3.setWildcard(&textAreaBuffer_NumLigne[j][0]);
	j++;
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

	update_num_ligne_primaire();
	changeStatutPrimaire(&sStatut_Primaire);
	scrollableContainer_primaire.setVisible(true);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_frigo_geoinv.setVisible(false);
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_zu_ba_tim.setVisible(false);
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geotwin.setVisible(false);
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.setVisible(false);
	scrollableContainer_frigo_ajpac.invalidate();
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

	update_num_ligne_zone();
	changeStatutZx(0, &sStatut_Zx[0]);
	changeStatutZx(1, &sStatut_Zx[1]);
	changeStatutZx(2, &sStatut_Zx[2]);
	changeStatutZx(3, &sStatut_Zx[3]);
	changeStatutZx(4, &sStatut_Zx[4]);
	changeStatutZx(5, &sStatut_Zx[5]);
	changeStatutZx(6, &sStatut_Zx[6]);
	changeStatutZx(7, &sStatut_Zx[7]);
	changeStatutRF(&sStatut_RF[0]);
	changeStatutRF(&sStatut_RF[1]);
	changeStatutRF(&sStatut_RF[2]);
	changeStatutRF(&sStatut_RF[3]);
	changeStatutRF(&sStatut_RF[4]);
	changeStatutRF(&sStatut_RF[5]);
	changeStatutRF(&sStatut_RF[6]);
	changeStatutRF(&sStatut_RF[7]);
	changeConfig(&sConfig_IHM);
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(true);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_frigo_geoinv.setVisible(false);
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_zu_ba_tim.setVisible(false);
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geotwin.setVisible(false);
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.setVisible(false);
	scrollableContainer_frigo_ajpac.invalidate();
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

	update_num_ligne_groupes();
	changeStatutZx(8, &sStatut_Zx[8]);
	changeStatutZx(9, &sStatut_Zx[9]);
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(true);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_frigo_geoinv.setVisible(false);
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_zu_ba_tim.setVisible(false);
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geotwin.setVisible(false);
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.setVisible(false);
	scrollableContainer_frigo_ajpac.invalidate();
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

	update_num_ligne_option();
	changeStatutECS(&sStatut_ECS);
	changeStatutPiscine(&sStatut_Piscine);
	changeConfig(&sConfig_IHM);
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(true);
	scrollableContainer_options.invalidate();
	scrollableContainer_frigo_geoinv.setVisible(false);
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_zu_ba_tim.setVisible(false);
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geotwin.setVisible(false);
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.setVisible(false);
	scrollableContainer_frigo_ajpac.invalidate();
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

	switch( sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		default:
		case AJPAC_III:
			update_num_ligne_frigo_ajpac();
			break;
		case GEOINVERTER:
			update_num_ligne_frigo_inv();
			break;
		case GEOTWIN_IV:
			update_num_ligne_frigo_geo();
			break;
		case BAGUIO_ZURAN_IV:
		case TIMAX_III:
			update_num_ligne_frigo_zu_ba_tim();
			break;
		case PHOENIX:
			break;
	}
	//changeConfig(&sConfig_IHM);
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

	scrollableContainer_frigo_geoinv.setVisible(false);
	scrollableContainer_frigo_zu_ba_tim.setVisible(false);
	scrollableContainer_frigo_geotwin.setVisible(false);
	scrollableContainer_frigo_ajpac.setVisible(false);
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.invalidate();
	switch( sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		default:
		case AJPAC_III:
			scrollableContainer_frigo_ajpac.setVisible(true);
			break;
		case GEOINVERTER:
			scrollableContainer_frigo_geoinv.setVisible(true);
			break;
		case GEOTWIN_IV:
			scrollableContainer_frigo_geotwin.setVisible(true);
			break;
		case BAGUIO_ZURAN_IV:
		case TIMAX_III:
			scrollableContainer_frigo_zu_ba_tim.setVisible(true);

			container_zu_ba_tim_PP_UDC_0.setVisible(false);
			container_zu_ba_tim_PP_UDC_1.setVisible(false);
			container_zu_ba_tim_other.setVisible(false);
			switch (sConfig_IHM.sModele_PAC.u3SousTypePAC)
			{
				case SOUS_TYPE_BAGUIO_PP:
					if (sCyclRegFrigo[0].pac.zuba.sStatutMitsu.Tension_DC == 0)
					{
						container_zu_ba_tim_PP_UDC_0.setVisible(true);
					}
					else
					{
						container_zu_ba_tim_PP_UDC_1.setVisible(true);
					}
					break;
				default:
					container_zu_ba_tim_other.setVisible(true);
					break;
			}
			container_zu_ba_tim_PP_UDC_0.invalidate();
			container_zu_ba_tim_PP_UDC_1.invalidate();
			container_zu_ba_tim_other.invalidate();
			break;
		case PHOENIX:
			break;
	}
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.invalidate();
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

	update_num_ligne_in_out();
	scrollableContainer_primaire.setVisible(false);
	scrollableContainer_primaire.invalidate();
	scrollableContainer_zones.setVisible(false);
	scrollableContainer_zones.invalidate();
	scrollableContainer_groupes.setVisible(false);
	scrollableContainer_groupes.invalidate();
	scrollableContainer_options.setVisible(false);
	scrollableContainer_options.invalidate();
	scrollableContainer_frigo_geoinv.setVisible(false);
	scrollableContainer_frigo_geoinv.invalidate();
	scrollableContainer_frigo_zu_ba_tim.setVisible(false);
	scrollableContainer_frigo_zu_ba_tim.invalidate();
	scrollableContainer_frigo_geotwin.setVisible(false);
	scrollableContainer_frigo_geotwin.invalidate();
	scrollableContainer_frigo_ajpac.setVisible(false);
	scrollableContainer_frigo_ajpac.invalidate();
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
	Unicode::UnicodeChar degre[] = {0x00B0};

	//Primaire
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
	Unicode::snprintf(&textAreaBuffer_HystExtMoins[Unicode::strlen(textAreaBuffer_HystExtMoins)], 4," / ");
	Unicode::snprintfFloat(textAreaBuffer_HystExtPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisTextPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystExtPlus[Unicode::strlen(textAreaBuffer_HystExtPlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystExtPlus[Unicode::strlen(textAreaBuffer_HystExtPlus)], 2,"C");
	textArea_hysteresis_sonde_ext_val.setWildcard1(textAreaBuffer_HystExtMoins);
    textArea_hysteresis_sonde_ext_val.setWildcard2(textAreaBuffer_HystExtPlus);
    textArea_hysteresis_sonde_ext_val.invalidate();
    //
	Unicode::snprintfFloat(textAreaBuffer_HystBallonMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisEauMoins) / 10);
	Unicode::snprintf(&textAreaBuffer_HystBallonMoins[Unicode::strlen(textAreaBuffer_HystBallonMoins)], 4," / ");
	Unicode::snprintfFloat(textAreaBuffer_HystBallonPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisEauPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystBallonPlus[Unicode::strlen(textAreaBuffer_HystBallonPlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystBallonPlus[Unicode::strlen(textAreaBuffer_HystBallonPlus)], 2,"C");
	textArea_hysteresis_prim_val.setWildcard1(textAreaBuffer_HystBallonMoins);
	textArea_hysteresis_prim_val.setWildcard2(textAreaBuffer_HystBallonPlus);
	textArea_hysteresis_prim_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_TempExtEqui, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8Text_Ref_Appoint * 10) / 10);
	Unicode::snprintf(&textAreaBuffer_TempExtEqui[Unicode::strlen(textAreaBuffer_TempExtEqui)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_TempExtEqui[Unicode::strlen(textAreaBuffer_TempExtEqui)], 2,"C");
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
			Unicode::snprintf(textAreaBuffer_TypeAppoint, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_ELECTRIQUE_DROITE_DEFAUT).getText());
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
	if (sConfig_IHM->sModele_PAC.u8ModelePAC != GEOINVERTER && sConfig_IHM->sModele_PAC.u8ModelePAC != PHOENIX)
	{
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
	}
	else
	{
		//Circulateur Forcé
		if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce)
		{
			Unicode::snprintf(textAreaBuffer_CircForce, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_CircForce, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		textArea_circ_prim_val.setWildcard1(textAreaBuffer_CircForce);

		//Circulateur Relais
		if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire == TYPE_RELAIS)
		{
			Unicode::snprintf(textAreaBuffer_GestCirc, 11, touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getText());
		}
		else
		{
			switch(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.eGestionCirculateurPrimaire)
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

		}
		textArea_circ_prim_val.setWildcard2(textAreaBuffer_GestCirc);
		textArea_circ_prim_val.invalidate();
	}


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


	//Zone 1 - Cons / Temp Int
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone1 == 1)
	{
		changeStatutZx(0, &sStatut_Zx[0]);
	}
	changeStatutRF(&sStatut_RF[0]);//Pour MAj Tyope de thermostat si changé

	//Zone 1 - Hyst Int
	if (sConfig_IHM->sParam_Zx[0].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone1, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[0].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone1[Unicode::strlen(textAreaBuffer_HystMoinsZone1)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_1.setWildcard1(textAreaBuffer_HystMoinsZone1);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone1, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[0].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone1[Unicode::strlen(textAreaBuffer_HystPlusZone1)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone1[Unicode::strlen(textAreaBuffer_HystPlusZone1)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_1.setWildcard2(textAreaBuffer_HystPlusZone1);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone1, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_1.setWildcard1(textAreaBuffer_HystMoinsZone1);
		textArea_val_hyst_sonde_ambiance_zone_1.setWildcard2(textAreaBuffer_HystPlusZone1);
	}
	textArea_val_hyst_sonde_ambiance_zone_1.invalidate();

	//Zone 2 - Cons / Temp Int (à conserver en doublon pour MAJ consigne si changement TH
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone2 == 1)
	{
		changeStatutZx(1, &sStatut_Zx[1]);
	}
	changeStatutRF(&sStatut_RF[1]);//Pour MAj Tyope de thermostat si changé

	//Zone 2 - Hyst Int
	if (sConfig_IHM->sParam_Zx[1].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone2, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[1].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone2[Unicode::strlen(textAreaBuffer_HystMoinsZone2)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_2.setWildcard1(textAreaBuffer_HystMoinsZone2);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone2, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[1].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone2[Unicode::strlen(textAreaBuffer_HystPlusZone2)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone2[Unicode::strlen(textAreaBuffer_HystPlusZone2)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_2.setWildcard2(textAreaBuffer_HystPlusZone2);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone2, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_2.setWildcard1(textAreaBuffer_HystMoinsZone2);
		textArea_val_hyst_sonde_ambiance_zone_2.setWildcard2(textAreaBuffer_HystPlusZone2);
	}
	textArea_val_hyst_sonde_ambiance_zone_2.invalidate();


	//Zone 3 - Cons / Temp Int
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone3 == 1)
	{
		changeStatutZx(2, &sStatut_Zx[2]);
	}
	changeStatutRF(&sStatut_RF[2]);//Pour MAj Tyope de thermostat si changé

	//Zone 3 - Hyst Int
	if (sConfig_IHM->sParam_Zx[2].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone3, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[2].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone3[Unicode::strlen(textAreaBuffer_HystMoinsZone3)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_3.setWildcard1(textAreaBuffer_HystMoinsZone3);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone3, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[2].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone3[Unicode::strlen(textAreaBuffer_HystPlusZone3)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone3[Unicode::strlen(textAreaBuffer_HystPlusZone3)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_3.setWildcard2(textAreaBuffer_HystPlusZone3);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone3, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_3.setWildcard1(textAreaBuffer_HystMoinsZone3);
		textArea_val_hyst_sonde_ambiance_zone_3.setWildcard2(textAreaBuffer_HystPlusZone3);
	}
	textArea_val_hyst_sonde_ambiance_zone_3.invalidate();

	//Zone 4 - Cons / Temp Int (à conserver en doublon pour MAJ consigne si changement TH
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone4 == 1)
	{
		changeStatutZx(3, &sStatut_Zx[3]);
	}
	changeStatutRF(&sStatut_RF[3]);//Pour MAj Tyope de thermostat si changé

	//Zone 4 - Hyst Int
	if (sConfig_IHM->sParam_Zx[3].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone4, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[3].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone4[Unicode::strlen(textAreaBuffer_HystMoinsZone4)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_4.setWildcard1(textAreaBuffer_HystMoinsZone4);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone4, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[3].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone4[Unicode::strlen(textAreaBuffer_HystPlusZone4)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone4[Unicode::strlen(textAreaBuffer_HystPlusZone4)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_4.setWildcard2(textAreaBuffer_HystPlusZone4);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone4, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_4.setWildcard1(textAreaBuffer_HystMoinsZone4);
		textArea_val_hyst_sonde_ambiance_zone_4.setWildcard2(textAreaBuffer_HystPlusZone4);
	}
	textArea_val_hyst_sonde_ambiance_zone_4.invalidate();

	//Zone 5 - Cons / Temp Int
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone5 == 1)
	{
		changeStatutZx(4, &sStatut_Zx[4]);
	}
	changeStatutRF(&sStatut_RF[4]);//Pour MAj Tyope de thermostat si changé

	//Zone 5 - Hyst Int
	if (sConfig_IHM->sParam_Zx[4].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone5, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[4].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone5[Unicode::strlen(textAreaBuffer_HystMoinsZone5)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_5.setWildcard1(textAreaBuffer_HystMoinsZone5);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone5, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[4].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone5[Unicode::strlen(textAreaBuffer_HystPlusZone5)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone5[Unicode::strlen(textAreaBuffer_HystPlusZone5)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_5.setWildcard2(textAreaBuffer_HystPlusZone5);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone5, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_5.setWildcard1(textAreaBuffer_HystMoinsZone5);
		textArea_val_hyst_sonde_ambiance_zone_5.setWildcard2(textAreaBuffer_HystPlusZone5);
	}
	textArea_val_hyst_sonde_ambiance_zone_5.invalidate();

	//Zone 6 - Cons / Temp Int (à conserver en doublon pour MAJ consigne si changement TH
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone6 == 1)
	{
		changeStatutZx(5, &sStatut_Zx[5]);
	}
	changeStatutRF(&sStatut_RF[5]);//Pour MAj Tyope de thermostat si changé

	//Zone 6 - Hyst Int
	if (sConfig_IHM->sParam_Zx[5].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone6, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[5].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone6[Unicode::strlen(textAreaBuffer_HystMoinsZone6)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_6.setWildcard1(textAreaBuffer_HystMoinsZone6);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone6, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[5].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone6[Unicode::strlen(textAreaBuffer_HystPlusZone6)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone6[Unicode::strlen(textAreaBuffer_HystPlusZone6)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_6.setWildcard2(textAreaBuffer_HystPlusZone6);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone6, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_6.setWildcard1(textAreaBuffer_HystMoinsZone6);
		textArea_val_hyst_sonde_ambiance_zone_6.setWildcard2(textAreaBuffer_HystPlusZone6);
	}
	textArea_val_hyst_sonde_ambiance_zone_6.invalidate();

	//Zone 7 - Cons / Temp Int
	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone7 == 1)
	{
		changeStatutZx(6, &sStatut_Zx[6]);
	}
	changeStatutRF(&sStatut_RF[6]);//Pour MAj Tyope de thermostat si changé

	//Zone 7 - Hyst Int
	if (sConfig_IHM->sParam_Zx[6].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone7, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[6].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone7[Unicode::strlen(textAreaBuffer_HystMoinsZone7)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_7.setWildcard1(textAreaBuffer_HystMoinsZone7);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone7, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[6].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone7[Unicode::strlen(textAreaBuffer_HystPlusZone7)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone7[Unicode::strlen(textAreaBuffer_HystPlusZone7)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_7.setWildcard2(textAreaBuffer_HystPlusZone7);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone7, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_7.setWildcard1(textAreaBuffer_HystMoinsZone7);
		textArea_val_hyst_sonde_ambiance_zone_7.setWildcard2(textAreaBuffer_HystPlusZone7);
	}
	textArea_val_hyst_sonde_ambiance_zone_7.invalidate();

	if (sConfig_IHM->sOption_PAC.sZone.zone.bZone8 == 1)
	{
		changeStatutZx(7, &sStatut_Zx[7]);
	}
	changeStatutRF(&sStatut_RF[7]);//Pour MAj Tyope de thermostat si changé

	//Zone 8 - Hyst Int
	if (sConfig_IHM->sParam_Zx[7].type_zone.zone.TypeThermostat != TH_CONTACT)
	{
		Unicode::snprintfFloat(textAreaBuffer_HystMoinsZone8, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[7].i8HysteresisMoins) / 10);
		Unicode::snprintf(&textAreaBuffer_HystMoinsZone8[Unicode::strlen(textAreaBuffer_HystMoinsZone8)], 4," / ");
		textArea_val_hyst_sonde_ambiance_zone_8.setWildcard1(textAreaBuffer_HystMoinsZone8);
		Unicode::snprintfFloat(textAreaBuffer_HystPlusZone8, 5, "%.1f", ((float) sConfig_IHM->sParam_Zx[7].i8HysteresisPlus) / 10);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone8[Unicode::strlen(textAreaBuffer_HystPlusZone8)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_HystPlusZone8[Unicode::strlen(textAreaBuffer_HystPlusZone8)], 2,"C");
		textArea_val_hyst_sonde_ambiance_zone_8.setWildcard2(textAreaBuffer_HystPlusZone8);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_HystMoinsZone8, 5, "");//,touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_HystPlusZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_val_hyst_sonde_ambiance_zone_8.setWildcard1(textAreaBuffer_HystMoinsZone8);
		textArea_val_hyst_sonde_ambiance_zone_8.setWildcard2(textAreaBuffer_HystPlusZone8);
	}
	textArea_val_hyst_sonde_ambiance_zone_8.invalidate();



	//Groupe B
	if(sConfig_IHM->sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 0)
	{
		textArea_mode_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
	}
	else textArea_mode_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
	textArea_mode_groupe_b_val.invalidate();

	//Consigne ECS Fin
	Unicode::snprintfFloat(textAreaBuffer_Cons_ECS_Fin, 7, "%.1f", ((float) sConfig_IHM->sMode_ECS.i16Consigne_ECS_Normal) / 10);
	Unicode::snprintf(&textAreaBuffer_Cons_ECS_Fin[Unicode::strlen(textAreaBuffer_Cons_ECS_Fin)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Cons_ECS_Fin[Unicode::strlen(textAreaBuffer_Cons_ECS_Fin)], 2,"C");
	textArea_cons_ecs_val.setWildcard(textAreaBuffer_Cons_ECS_Fin);
	textArea_cons_ecs_val.invalidate();

	//Consigne ECS Relance
	Unicode::snprintfFloat(textAreaBuffer_Cons_Ecs_Relance, 7, "%.1f", ((float) sConfig_IHM->sMode_ECS.i16Consigne_ECS_Relance) / 10);
	Unicode::snprintf(&textAreaBuffer_Cons_Ecs_Relance[Unicode::strlen(textAreaBuffer_Cons_Ecs_Relance)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Cons_Ecs_Relance[Unicode::strlen(textAreaBuffer_Cons_Ecs_Relance)], 2,"C");
	textArea_cons_relance_ecs_val.setWildcard(textAreaBuffer_Cons_Ecs_Relance);
	textArea_cons_relance_ecs_val.invalidate();

	//Hyst ECS
	Unicode::snprintfFloat(textAreaBuffer_HystECSMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_ECS.i8HysteresisECSMoins) / 10);
	Unicode::snprintf(&textAreaBuffer_HystECSMoins[Unicode::strlen(textAreaBuffer_HystECSMoins)], 4," / ");
	textArea_hyst_ecs_val.setWildcard1(textAreaBuffer_HystECSMoins);
	Unicode::snprintfFloat(textAreaBuffer_HystECSPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_ECS.i8HysteresisECSPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystECSPlus[Unicode::strlen(textAreaBuffer_HystECSPlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystECSPlus[Unicode::strlen(textAreaBuffer_HystECSPlus)], 2,"C");
	textArea_hyst_ecs_val.setWildcard2(textAreaBuffer_HystECSPlus);
	textArea_hyst_ecs_val.invalidate();

	//Appoint ECS Autorisation/Etat
	if (sConfig_IHM->sOption_PAC.ECS == 0)
	{
		Unicode::snprintf(textAreaBuffer_AppECS_Autorise, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		Unicode::snprintf(textAreaBuffer_AppECS_Etat, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_app_ecs_val.setWildcard1(textAreaBuffer_AppECS_Autorise);
		textArea_app_ecs_val.setWildcard2(textAreaBuffer_AppECS_Etat);
		textArea_app_ecs_val.invalidate();
	}
	else
	{
		//App autorisé
		if (sConfig_IHM->sParam_ECS.bTypeAppointECS == 0) Unicode::snprintf(textAreaBuffer_AppECS_Autorise, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		else Unicode::snprintf(textAreaBuffer_AppECS_Autorise, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_app_ecs_val.setWildcard1(textAreaBuffer_AppECS_Autorise);
		textArea_app_ecs_val.invalidate();
	}
	//ECS Legionelle
	if (sConfig_IHM->sParam_ECS.bAntiLegionnel == 0)Unicode::snprintf(textAreaBuffer_Legionelle_Autorise, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Legionelle_Autorise, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_cycle_legion_val.setWildcard(textAreaBuffer_Legionelle_Autorise);
	textArea_cycle_legion_val.invalidate();

	//ECS Durée Cycle Thermo
	Unicode::snprintf(textAreaBuffer_Duree_Thermo, 4, "%d", sConfig_IHM->sParam_ECS.Time_ECS_Thermo);
	textArea_duree_cycle_thermo_val.setWildcard(textAreaBuffer_Duree_Thermo);
	textArea_duree_cycle_thermo_val.invalidate();

	//ECS Temps Rotation Vanne
	Unicode::snprintf(textAreaBuffer_Temps_Rotation_Vanne_ECS, 4, "%d", sConfig_IHM->sParam_ECS.Time_Bascul_V3V_ECS);
	textArea_tps_rotation_v3v_val.setWildcard(textAreaBuffer_Temps_Rotation_Vanne_ECS);
	textArea_tps_rotation_v3v_val.invalidate();

	//Consigne Piscine Primaire
	Unicode::snprintfFloat(textAreaBuffer_Cons_Prim_Piscine, 7, "%.1f", ((float) sConfig_IHM->sParam_Piscine.i16ConsigneDepartEauPiscine) / 10);
	Unicode::snprintf(&textAreaBuffer_Cons_Prim_Piscine[Unicode::strlen(textAreaBuffer_Cons_Prim_Piscine)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Cons_Prim_Piscine[Unicode::strlen(textAreaBuffer_Cons_Prim_Piscine)], 2,"C");
	textArea_cons_depart_eau_piscine_val.setWildcard(textAreaBuffer_Cons_Prim_Piscine);
	textArea_cons_depart_eau_piscine_val.invalidate();

	//Hyst Piscine
	Unicode::snprintfFloat(textAreaBuffer_HystPiscMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_Piscine.i8HysteresisEauMoins) / 10);
	Unicode::snprintf(&textAreaBuffer_HystPiscMoins[Unicode::strlen(textAreaBuffer_HystPiscMoins)], 4," / ");
	textArea_hyst_piscine_val.setWildcard1(textAreaBuffer_HystPiscMoins);
	Unicode::snprintfFloat(textAreaBuffer_HystPiscPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_Piscine.i8HysteresisEauPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystPiscPlus[Unicode::strlen(textAreaBuffer_HystPiscPlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystPiscPlus[Unicode::strlen(textAreaBuffer_HystPiscPlus)], 2,"C");
	textArea_hyst_piscine_val.setWildcard2(textAreaBuffer_HystPiscPlus);
	textArea_hyst_piscine_val.invalidate();

	//Priorité Piscine
	switch ( sConfig_IHM->sParam_Piscine.PrioritePiscine)
	{
		case PRIORITE_CHAUD:
			Unicode::snprintf(textAreaBuffer_Priorite_Pisc, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_DROIT_DEFAUT).getText());
			break;
		case PRIORITE_EGAL:
			Unicode::snprintf(textAreaBuffer_Priorite_Pisc, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_EGAL_DROITE_DEFAUT).getText());
			break;
		case PRIORITE_PISCINE :
			Unicode::snprintf(textAreaBuffer_Priorite_Pisc, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_VAL_PRIORITE_RELANCE_DROIT_DEFAUT).getText());
			break;
		case PRIORITE_SIMULTANEE:
			Unicode::snprintf(textAreaBuffer_Priorite_Pisc, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_VAL_PRIORITE_RELANCE_DROIT_DEFAUT).getText());
			break;
		default:
			Unicode::snprintf(textAreaBuffer_Priorite_Pisc, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
			break;
	}
	textArea_option_relance_val.setWildcard(textAreaBuffer_Priorite_Pisc);
	textArea_option_relance_val.invalidate();
	//Partie In_Out
	textArea_val_priorite_piscine.setWildcard(textAreaBuffer_Priorite_Pisc);
	textArea_val_priorite_piscine.invalidate();

	//Pisc Temps Rotation Vanne
	Unicode::snprintf(textAreaBuffer_Temps_Rotation_Vanne_Pisc, 4, "%d", sConfig_IHM->sParam_Piscine.Time_Bascul_V3V_PISCINE);
	textArea_tps_rotation_v3v_piscine_val.setWildcard(textAreaBuffer_Temps_Rotation_Vanne_Pisc);
	textArea_tps_rotation_v3v_piscine_val.invalidate();

	//Frigo GéoInv
	if (sConfig_IHM->sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		//Modèle PAC Inv
		switch (sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.u3SousType)
		{
			case GEOINV_STD:
				Unicode::snprintf(textAreaBuffer_Modele_PAC_Inv, 7,"STD - ");
				break;
			case  GEOINV_BI_COMP:
				Unicode::snprintf(textAreaBuffer_Modele_PAC_Inv, 7,"BIC - ");
				break;
			case GEOINV_BI_ETAGE:
				Unicode::snprintf(textAreaBuffer_Modele_PAC_Inv, 7,"BIE - ");
				break;
			case GEOINV_SAGITAIR:
				Unicode::snprintf(textAreaBuffer_Modele_PAC_Inv, 7,"SAG - ");
				break;
			case GEOINV_DEFROST:
				Unicode::snprintf(textAreaBuffer_Modele_PAC_Inv, 7,"DEF - ");
				break;
			default:
				Unicode::snprintf(textAreaBuffer_Modele_PAC_Inv, 7,"XXX - ");
				break;
		}
		//Réversibilité Inv
		if (sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bReversible == 0)
		{
			Unicode::snprintf(&textAreaBuffer_Modele_PAC_Inv[Unicode::strlen(textAreaBuffer_Modele_PAC_Inv)], 1,"");
		}
		else Unicode::snprintf(&textAreaBuffer_Modele_PAC_Inv[Unicode::strlen(textAreaBuffer_Modele_PAC_Inv)], 5,"R - ");
		//Puissance PAC Inv
		Unicode::snprintf(&textAreaBuffer_Modele_PAC_Inv[Unicode::strlen(textAreaBuffer_Modele_PAC_Inv)], 3, "%d", sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.u7Puissance);
		Unicode::snprintf(&textAreaBuffer_Modele_PAC_Inv[Unicode::strlen(textAreaBuffer_Modele_PAC_Inv)], 7," KW - ");
		//Mono/Tri Inv
		if (sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bSupply == 0)
		{
			Unicode::snprintf(&textAreaBuffer_Modele_PAC_Inv[Unicode::strlen(textAreaBuffer_Modele_PAC_Inv)], 3,"1~");
		}
		else Unicode::snprintf(&textAreaBuffer_Modele_PAC_Inv[Unicode::strlen(textAreaBuffer_Modele_PAC_Inv)], 3,"3~");
		textArea_inv_val_modele_pac.setWildcard(textAreaBuffer_Modele_PAC_Inv);
		textArea_inv_val_modele_pac.invalidate();
		//Réversibilité Inv
		if (sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bReversible == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Reversible_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Reversible_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_reversible.setWildcard(textAreaBuffer_Reversible_Inv);
		textArea_inv_val_reversible.invalidate();
		//Freecool Inv
		if (sConfig_IHM->sConfig_PAC.ConfigGeoInverter.bFreecooling == 0)
		{
			 Unicode::snprintf(textAreaBuffer_FreeCool_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_FreeCool_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_freecool.setWildcard(textAreaBuffer_FreeCool_Inv);
		textArea_inv_val_freecool.invalidate();
		//Fluide Inv
		switch(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.u4TypeGaz)
		{
			default:
			case GAZ_NONE:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "NA");
				break;
			case GAZ_R410:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "R410A");
				break;
			case GAZ_R134:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "R134a");
				break;
			case GAZ_R407:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "R4107C");
				break;
			case GAZ_R32:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "R32");
				break;
			case GAZ_HELIUM:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "HELIUM");
				break;
			case GAZ_R513:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "R513");
				break;
			case GAZ_R454C:
				Unicode::snprintf(textAreaBuffer_Fluide_Inv, 7, "R454C");
				break;
		}
		textArea_inv_val_fluide.setWildcard(textAreaBuffer_Fluide_Inv);
		textArea_inv_val_fluide.invalidate();
		//Driver Ruking Inv
		for (int i = 0; i<8; i++)
		{
			textAreaBuffer_RefDriver_Inv[i] = sConfig_IHM->sConfigFrigo[0].sRukingModel_FRIGO.Ruking_Model[i];
		}
		//Unicode::snprintf(textAreaBuffer_RefDriver_Inv,12, "%s", sConfig_IHM->sConfigFrigo[0].sRukingModel_FRIGO.Ruking_Model);
		textArea_inv_val_modele_driver.setWildcard(textAreaBuffer_RefDriver_Inv);
		textArea_inv_val_modele_driver.invalidate();
		//Nb cyle Inv
		Unicode::snprintf(textAreaBuffer_NbCycles_Inv,11, "%d", sConfig_IHM->sConfigFrigo[0].sTpsFonct_FRIGO.u32NbCycleC1);
		textArea_inv_val_nbcycle.setWildcard(textAreaBuffer_NbCycles_Inv);
		textArea_inv_val_nbcycle.invalidate();
		//Tps fonctionnement Inv
		Unicode::snprintf(textAreaBuffer_NbHeures_Inv,11, "%d h", (sConfig_IHM->sConfigFrigo[0].sTpsFonct_FRIGO.u32TpsFonctC1 / 3600));
		Unicode::snprintf(&textAreaBuffer_NbHeures_Inv[Unicode::strlen(textAreaBuffer_NbHeures_Inv)],11, " %d mn", ((sConfig_IHM->sConfigFrigo[0].sTpsFonct_FRIGO.u32TpsFonctC1 % 3600)/ 60));
		textArea_inv_val_temps_fct.setWildcard(textAreaBuffer_NbHeures_Inv);
		textArea_inv_val_temps_fct.invalidate();
		//Gestion Circ Prim / Forcé oui/non
		if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce)
		{
			Unicode::snprintf(textAreaBuffer_Circ_Prim_Force_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Circ_Prim_Force_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		textArea_inv_val_gestion_circ_prim.setWildcard1(textAreaBuffer_Circ_Prim_Force_Inv);
		if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire == TYPE_RELAIS)
		{
			Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getText());
		}
		else
		{
			switch(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.eGestionCirculateurPrimaire)
			{
				default:
				case GC_AUTO:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT).getText());
					break;
				case GC_V40:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT).getText());
					break;
				case GC_V50:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT).getText());
					break;
				case GC_V60:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT).getText());
					break;
				case GC_V70:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT).getText());
					break;
				case GC_V80:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT).getText());
					break;
				case GC_V90:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT).getText());
					break;
				case GC_V100:
					Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT).getText());
					break;
			}

		}
		textArea_inv_val_gestion_circ_prim.setWildcard2(textAreaBuffer_Circ_Prim_Gestion_Inv);
		textArea_inv_val_gestion_circ_prim.invalidate();
		//Gestion Circ Capt / Forcé oui/non
		if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce)
		{
			Unicode::snprintf(textAreaBuffer_Circ_Capt_Force_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Circ_Capt_Force_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		textArea_inv_val_gestion_circ_cap.setWildcard1(textAreaBuffer_Circ_Capt_Force_Inv);
		if(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.eTypeVentiloCircCaptage == TYPE_RELAIS)
		{
			Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getText());
		}
		else
		{
			switch(sConfig_IHM->sConfigFrigo[0].sModele_FRIGO.eGestionCirculateurCaptage)
			{
				default:
				case GC_AUTO:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT).getText());
					break;
				case GC_V40:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT).getText());
					break;
				case GC_V50:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT).getText());
					break;
				case GC_V60:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT).getText());
					break;
				case GC_V70:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT).getText());
					break;
				case GC_V80:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT).getText());
					break;
				case GC_V90:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT).getText());
					break;
				case GC_V100:
					Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Inv, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT).getText());
					break;
			}
		}
		textArea_inv_val_gestion_circ_cap.setWildcard2(textAreaBuffer_Circ_Capt_Gestion_Inv);
		textArea_inv_val_gestion_circ_cap.invalidate();
	}

	//GEOTWIN
	if (sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		//Type captage
		switch(sConfig_IHM->sConfig_PAC.ConfigGeo.eTypeDeCaptage)
		{
			case E_TYPE_CAPTAGE_CAPTEUR:
				Unicode::snprintf(textAreaBuffer_TypeCapteur_Geot, 15, touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getText());
				break;
			case E_TYPE_CAPTAGE_NAPPE_DIRECTE:
				Unicode::snprintf(textAreaBuffer_TypeCapteur_Geot, 15, touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_DIRECTE_CENTRE_DEFAUT).getText());
				break;
			case E_TYPE_CAPTAGE_NAPPE_BARRAGE:
				Unicode::snprintf(textAreaBuffer_TypeCapteur_Geot, 15, touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT).getText());
				break;
			default:
				break;
		}
		textArea_geo_val_type_captage.setWildcard(textAreaBuffer_TypeCapteur_Geot);
		textArea_geo_val_type_captage.invalidate();
		//Freecooling
		if(sConfig_IHM->sConfig_PAC.ConfigGeo.bFreecooling)
		{
			Unicode::snprintf(textAreaBuffer_Freecooling_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Freecooling_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		textArea_geo_val_freecooling.setWildcard(textAreaBuffer_Freecooling_Geot);
		textArea_geo_val_freecooling.invalidate();
		//Gestion Circ Prim / Forcé oui/non
		if(sConfig_IHM->sParam_PAC.bCirculateurPrimaireForce)
		{
			Unicode::snprintf(textAreaBuffer_Circ_Prim_Force_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Circ_Prim_Force_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		textArea_geo_val_circ_prim_gestion.setWildcard1(textAreaBuffer_Circ_Prim_Force_Geot);
		textArea_geo_val_circ_prim_gestion.invalidate();

		//Gestion Circ Capt / Forcé oui/non
		if(sConfig_IHM->sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce)
		{
			Unicode::snprintf(textAreaBuffer_Circ_Capt_Force_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Circ_Capt_Force_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		textArea_geo_val_circ_capt_gestion.setWildcard1(textAreaBuffer_Circ_Capt_Force_Geot);
		switch(sConfig_IHM->sConfig_PAC.ConfigGeo.eGestionCirculateurCaptage)
		{
			default:
			case GC_AUTO:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT).getText());
				break;
			case GC_V40:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT).getText());
				break;
			case GC_V50:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT).getText());
				break;
			case GC_V60:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT).getText());
				break;
			case GC_V70:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT).getText());
				break;
			case GC_V80:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT).getText());
				break;
			case GC_V90:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT).getText());
				break;
			case GC_V100:
				Unicode::snprintf(textAreaBuffer_Circ_Capt_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT).getText());
				break;
		}
		textArea_geo_val_circ_capt_gestion.setWildcard2(textAreaBuffer_Circ_Capt_Gestion_Geot);
		textArea_geo_val_circ_capt_gestion.invalidate();
		//PW Géo
		Unicode::snprintf(textAreaBuffer_PW_PAC_Geot,4, "%d", sConfig_IHM->sModele_PAC.u8PwPac);
		textArea_geo_val_pw_restituee.setWildcard(textAreaBuffer_PW_PAC_Geot);
		textArea_geo_val_pw_restituee.invalidate();
		//Nb Comp
		Unicode::snprintf(textAreaBuffer_Nb_Comp_Geot,2, "%d", sConfig_IHM->sModele_PAC.nbCompresseur + 1);
		textArea_geo_val_nb_comp.setWildcard(textAreaBuffer_Nb_Comp_Geot);
		textArea_geo_val_nb_comp.invalidate();
		//Réversible
		if( sConfig_IHM->sModele_PAC.bReversible)
		{
			Unicode::snprintf(textAreaBuffer_Reversible_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Reversible_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_reversibilite.setWildcard(textAreaBuffer_Reversible_Geot);
		textArea_geo_val_reversibilite.invalidate();
		//Alimentation
		if( sConfig_IHM->sModele_PAC.bSupply == 0)
		{
			Unicode::snprintf(textAreaBuffer_Alimentation_Geot,3, "1~");
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Alimentation_Geot,3, "3~");
		}
		textArea_geo_val_alimentation.setWildcard(textAreaBuffer_Alimentation_Geot);
		textArea_geo_val_alimentation.invalidate();
		//Demarreur progressif
		if( sConfig_IHM->sModele_PAC.bDemarreurProgressif)
		{
			Unicode::snprintf(textAreaBuffer_DemPro_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_DemPro_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_dem_pro.setWildcard(textAreaBuffer_DemPro_Geot);
		textArea_geo_val_dem_pro.invalidate();
		//Rédu PW Mode froid
		if(sConfig_IHM->sConfig_PAC.ConfigGeo.bLimitationPW_Froid)
		{
			Unicode::snprintf(textAreaBuffer_LimitationPW_Froid_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_LimitationPW_Froid_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_limitation_pw_froid.setWildcard(textAreaBuffer_LimitationPW_Froid_Geot);
		textArea_geo_val_limitation_pw_froid.invalidate();
		//Rédu PW Mode ECS
		if(sConfig_IHM->sConfig_PAC.ConfigGeo.bLimitationPW_ECS)
		{
			Unicode::snprintf(textAreaBuffer_LimitationPW_ECS_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_LimitationPW_ECS_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_limitation_pw_ecs.setWildcard(textAreaBuffer_LimitationPW_ECS_Geot);
		textArea_geo_val_limitation_pw_ecs.invalidate();
	}//Fin Geotwin


	//In_Out Appoint
	switch ( sConfig_IHM->sOption_PAC.TypeAppoint)
	{
		case RELEVE_CHAUDIERE:
			Unicode::snprintf(textAreaBuffer_Type_Appoint, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_RELEVE_CHAUDIERE_DROITE_DEFAUT).getText());
			break;
		case APPOINT_CHAUDIERE:
			Unicode::snprintf(textAreaBuffer_Type_Appoint, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_APPOINT_CHAUDIERE_DROITE_DEFAUT).getText());
			break;
		case ELEC :
			Unicode::snprintf(textAreaBuffer_Type_Appoint, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_ELECTRIQUE_DROITE_DEFAUT).getText());
			break;
		case NO_APPOINT:
			Unicode::snprintf(textAreaBuffer_Type_Appoint, 8, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
			break;
		default:
			Unicode::snprintf(textAreaBuffer_Type_Appoint, 8, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
			break;
	}
	textArea_val_option_app_elec.setWildcard(textAreaBuffer_Type_Appoint);
	textArea_val_option_app_elec.invalidate();

	//In_Out Nb Zones
	uint8_t u8_nb_zones = 0;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone1  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone2  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone3  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone4  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone5  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone6  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone7  & 1) == 1) u8_nb_zones++;
	if ((sConfig_IHM->sOption_PAC.sZone.zone.bZone8  & 1) == 1) u8_nb_zones++;
	Unicode::snprintf(textAreaBuffer_Nb_Zones, 3, "%d", u8_nb_zones);
	textArea_val_option_nb_zones.setWildcard(textAreaBuffer_Nb_Zones);
	textArea_val_option_nb_zones.invalidate();

	//In_Out Piscine
	if (sConfig_IHM->sOption_PAC.Piscine == 0) Unicode::snprintf(textAreaBuffer_Option_Piscine, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Option_Piscine, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_option_piscine.setWildcard(textAreaBuffer_Option_Piscine);
	textArea_val_option_piscine.invalidate();

	//In_Out ECS
	if (sConfig_IHM->sOption_PAC.ECS == 0) Unicode::snprintf(textAreaBuffer_Option_ECS, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Option_ECS, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_option_ecs.setWildcard(textAreaBuffer_Option_ECS);
	textArea_val_option_ecs.invalidate();

	//In_Out Appoint ECS / Secours ECS
	if (sConfig_IHM->sOption_PAC.ECS != 0)
	{
		sConfig_IHM->sParam_ECS.bTypeAppointECS == 0 ? Unicode::snprintf(textAreaBuffer_TypeApp_ECS, 4, touchgfx::TypedText(T_TEXT_ECS_CENTRE_DEFAUT).getText())
				: Unicode::snprintf(textAreaBuffer_TypeApp_ECS, 4, touchgfx::TypedText(T_TEXT_PAC_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_TypeApp_ECS, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());

	if (sConfig_IHM->sOption_PAC.ECS != 0)
	{
		sConfig_IHM->sMode_ECS.bUserECSSecours == 0 ? Unicode::snprintf(textAreaBuffer_SecoursApp_ECS, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText())
		      : Unicode::snprintf(textAreaBuffer_SecoursApp_ECS, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_SecoursApp_ECS, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
	textArea_val_option_app_ecs.setWildcard1(textAreaBuffer_TypeApp_ECS);
	textArea_val_option_app_ecs.setWildcard2(textAreaBuffer_SecoursApp_ECS);
	textArea_val_option_app_ecs.invalidate();

	//In_Out Comptage PW
	switch(sConfig_IHM->sOption_PAC.CoeffComptagePW)
	{
		case  NO_COMPTAGE_PW :
			 Unicode::snprintf(textAreaBuffer_Comptage_PW, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
			 Unicode::snprintf(textAreaBuffer_NbPulses, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
			break;
		case  PULSE_800:
			 Unicode::snprintf(textAreaBuffer_Comptage_PW, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
						 Unicode::snprintf(textAreaBuffer_NbPulses, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_800_PULSES).getText());
			break;
		case PULSE_1000:
			 Unicode::snprintf(textAreaBuffer_Comptage_PW, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
			 Unicode::snprintf(textAreaBuffer_NbPulses, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_1000_PULSES).getText());
			break;
	}
	textArea_val_option_wattmetre.setWildcard1(textAreaBuffer_Comptage_PW);
	textArea_val_option_wattmetre.setWildcard2(textAreaBuffer_NbPulses);
	textArea_val_option_wattmetre.invalidate();

	//In_Out ECS Forcé
	if (sConfig_IHM->sParam_ECS.bModeGestionHysteresis == 0) Unicode::snprintf(textAreaBuffer_ECS_Force, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_ECS_Force, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	textArea_val_config_ecs_dem_debut_cycle.setWildcard(textAreaBuffer_ECS_Force);
	textArea_val_config_ecs_dem_debut_cycle.invalidate();

	//In_Out ECS Contact
	if (sConfig_IHM->sParam_ECS.bSolaire == 0) Unicode::snprintf(textAreaBuffer_ECS_Entree_Contact, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_ECS_Entree_Contact, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_config_ecs_entree_contact.setWildcard(textAreaBuffer_ECS_Entree_Contact);
	textArea_val_config_ecs_entree_contact.invalidate();

	//In_Out ECS Bain Marie
	if (sConfig_IHM->sParam_ECS.u2TypeEchangeur == ECS_BAIN_MARIE) Unicode::snprintf(textAreaBuffer_ECS_Bain_Marie, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_ECS_Bain_Marie, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	textArea_val_config_ecs_bain_marie.setWildcard1(textAreaBuffer_ECS_Bain_Marie);
	textArea_val_config_ecs_bain_marie.invalidate();

	//In_Out Piscine Confort
	if (sConfig_IHM->sParam_Piscine.bConfort == 0) Unicode::snprintf(textAreaBuffer_Piscine_Confort, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Piscine_Confort, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_config_piscine_confort.setWildcard(textAreaBuffer_Piscine_Confort);
	textArea_val_config_piscine_confort.invalidate();

	//In_Out HystEau
	Unicode::snprintfFloat(textAreaBuffer_HystEauMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisEauMoins) / 10);
	Unicode::snprintf(&textAreaBuffer_HystEauMoins[Unicode::strlen(textAreaBuffer_HystEauMoins)], 4," / ");
	textArea_val_config_hyst_chaud_froid.setWildcard1(textAreaBuffer_HystEauMoins);
	Unicode::snprintfFloat(textAreaBuffer_HystEauPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_PAC.i8HysteresisEauPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystEauPlus[Unicode::strlen(textAreaBuffer_HystEauPlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystEauPlus[Unicode::strlen(textAreaBuffer_HystEauPlus)], 2,"C");
	textArea_val_config_hyst_chaud_froid.setWildcard2(textAreaBuffer_HystEauPlus);
	textArea_val_config_hyst_chaud_froid.invalidate();

	//In_Out HystEau ECS
	Unicode::snprintfFloat(textAreaBuffer_HystEauECSMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_ECS.i8HysteresisECSMoins) / 10);
	Unicode::snprintf(&textAreaBuffer_HystEauECSMoins[Unicode::strlen(textAreaBuffer_HystEauECSMoins)], 4," / ");
	textArea_val_config_hyst_ecs.setWildcard1(textAreaBuffer_HystEauECSMoins);
	Unicode::snprintfFloat(textAreaBuffer_HystEauECSPlus, 7, "%.1f", ((float) sConfig_IHM->sParam_ECS.i8HysteresisECSPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystEauECSPlus[Unicode::strlen(textAreaBuffer_HystEauECSPlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystEauECSPlus[Unicode::strlen(textAreaBuffer_HystEauECSPlus)], 2,"C");
	textArea_val_config_hyst_ecs.setWildcard2(textAreaBuffer_HystEauECSPlus);
	textArea_val_config_hyst_ecs.invalidate();

	//In_Out HystEau Piscine
	Unicode::snprintfFloat(textAreaBuffer_HystEauPiscineMoins, 7, "%.1f", ((float) sConfig_IHM->sParam_Piscine.i8HysteresisEauMoins) / 10);
	Unicode::snprintf(&textAreaBuffer_HystEauPiscineMoins[Unicode::strlen(textAreaBuffer_HystEauPiscineMoins)], 4," / ");
	textArea_val_config_hyst_piscine.setWildcard1(textAreaBuffer_HystEauPiscineMoins);
	Unicode::snprintfFloat(textAreaBuffer_HystEauPiscinePlus, 7, "%.1f", ((float) sConfig_IHM->sParam_Piscine.i8HysteresisEauPlus) / 10);
	Unicode::snprintf(&textAreaBuffer_HystEauPiscinePlus[Unicode::strlen(textAreaBuffer_HystEauPiscinePlus)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_HystEauPiscinePlus[Unicode::strlen(textAreaBuffer_HystEauPiscinePlus)], 2,"C");
	textArea_val_config_hyst_piscine.setWildcard2(textAreaBuffer_HystEauPiscinePlus);
	textArea_val_config_hyst_piscine.invalidate();

	//In_Out Adaptation Loi d'eau
	if (sConfig_IHM->sMode_PAC.bUserAdaptationLoiDeau == 0) Unicode::snprintf(textAreaBuffer_Adapt_LoiDeau, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Adapt_LoiDeau, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_config_adapt_loi_eau.setWildcard(textAreaBuffer_Adapt_LoiDeau);
	textArea_val_config_adapt_loi_eau.invalidate();

	//In_Out Chaud/Froid Simultané
	if (sConfig_IHM->sParam_PAC.bChaudFroidSimultane == 0) Unicode::snprintf(textAreaBuffer_ChaudFroid_Simu, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_ChaudFroid_Simu, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_config_chaud_froid_simu.setWildcard(textAreaBuffer_ChaudFroid_Simu);
	textArea_val_config_chaud_froid_simu.invalidate();

	//In_Out Appoint Defaut PAC
	if (sConfig_IHM->sParam_PAC.bModeSecoursDefautPAC == 0) Unicode::snprintf(textAreaBuffer_SecoursDefautPAC, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_SecoursDefautPAC, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_mode_secours_def_pac.setWildcard(textAreaBuffer_SecoursDefautPAC);
	textArea_val_mode_secours_def_pac.invalidate();

	//In_Out Durée Cycle Defrost
	switch (sConfig_IHM->sParam_Frigo.Type_Degivrage)
	{
	case DEGIVRAGE_NORMAL:
		Unicode::snprintf(textAreaBuffer_TypeDefrost, 20, touchgfx::TypedText(T_TEXT_NORMAL).getText());
		break;
	case DEGIVRAGE_LONG:
		Unicode::snprintf(textAreaBuffer_TypeDefrost, 20, touchgfx::TypedText(T_TEXT_TAUX_HUMIDITE_ELEVE).getText());
		break;
	default:
		Unicode::snprintf(textAreaBuffer_TypeDefrost, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
		break;
	}
	textArea_val_duree_degivrage.setWildcard1(textAreaBuffer_TypeDefrost);
	textArea_val_duree_degivrage.invalidate();

	//In_Out Priorité Piscine
	//(placé plus haut car fonction déjà utilisée)

	//In_Out Shunt Tempo
	if (sConfig_IHM->sParam_SAV.bShuntTempo == 0) Unicode::snprintf(textAreaBuffer_ShuntTempo, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_ShuntTempo, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_shunt_tempo.setWildcard(textAreaBuffer_ShuntTempo);
	textArea_val_shunt_tempo.invalidate();

	//In_Out Antilegionnel
	if (sConfig_IHM->sParam_ECS.bAntiLegionnel == 0) Unicode::snprintf(textAreaBuffer_Antilegionel, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else
	{
		Unicode::snprintf(textAreaBuffer_Antilegionel, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4," / ");
		switch(sConfig_IHM->sParam_ECS.Jour_Legionel)
		{
			case 0 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_LUNDI_PROG_EDIT_LEFT_DEFAUT).getText()); break;
			case 1 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_MARDI_PROG_EDIT_LEFT_DEFAUT).getText()); break;
			case 2 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_MERCREDI_PROG_EDIT_LEFT_DEFAUT).getText()); break;
			case 3 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_JEUDI_PROG_EDIT_LEFT_DEFAUT).getText()); break;
			case 4 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_VENDREDI_PROG_EDIT_LEFT_DEFAUT).getText()); break;
			case 5 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_SAMEDI_PROG_EDIT_LEFT_DEFAUT).getText()); break;
			case 6 :Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4, touchgfx::TypedText(T_TEXT_DIMANCHE_PROG_EDIT_LEFT_DEFAUT).getText()); break;
		}
		Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4," / ");
		Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 2, "%d", sConfig_IHM->sParam_ECS.Heure_Legionel);
		Unicode::snprintf(&textAreaBuffer_Antilegionel[Unicode::strlen(textAreaBuffer_Antilegionel)], 4," H");
	}
	textArea_val_antilegionelle.setWildcard(textAreaBuffer_Antilegionel);
	textArea_val_antilegionelle.invalidate();

	//In_Out Gestion V3V Pisc
	if (sConfig_IHM->sParam_Piscine.Type_Gestion_V3V == E_TYPE_GESTION_V3V_MODE_2) 	Unicode::snprintf(textAreaBuffer_ModeV3V_Pisc, 2,"2");
	else Unicode::snprintf(textAreaBuffer_ModeV3V_Pisc, 2,"1");
	textArea_val_mode_gestion_v3v.setWildcard(textAreaBuffer_ModeV3V_Pisc);
	textArea_val_mode_gestion_v3v.invalidate();




//	//In_Out Res. carter
//	if (sConfig_IHM->sParam_PAC.OutxCarter == 0)
//	{
//		Unicode::snprintf(textAreaBuffer_Res_Carter, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
//	}
//	else
//	{
//		Unicode::snprintf(textAreaBuffer_Res_Carter, 5,"Out ");
//		Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 2, "%d", sConfig_IHM.sParam_PAC.OutxCarter);
//		Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 4," / ");
//		if (sStatut_PAC->sFonctOutxTor.bCarter == 0)
//		{
//			Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
//		}
//		else Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
//
//	}
//	textArea_val_resistance_carter.setWildcard(textAreaBuffer_Res_Carter);
//	textArea_val_resistance_carter.invalidate();


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
	Unicode::UnicodeChar degre[] = {0x00B0};

	if (sConfig_IHM.sModele_PAC.u8ModelePAC != GEOINVERTER && sConfig_IHM.sModele_PAC.u8ModelePAC != PHOENIX)
	{
		//
		Unicode::snprintfFloat(textAreaBuffer_ConsignePrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16ConsigneTeauPrimaire) / 10);
		Unicode::snprintf(&textAreaBuffer_ConsignePrimaire[Unicode::strlen(textAreaBuffer_ConsignePrimaire)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_ConsignePrimaire[Unicode::strlen(textAreaBuffer_ConsignePrimaire)], 2,"C");

		textArea_demande_pac_val.setWildcard2(textAreaBuffer_ConsignePrimaire);
		textArea_demande_pac_val.invalidate();
		textArea_cons_temp_prim_val.setWildcard1(textAreaBuffer_ConsignePrimaire);
		textArea_cons_temp_prim_val.invalidate();
		textArea_cascade_demande_val.setWildcard2(textAreaBuffer_ConsignePrimaire);
		textArea_cascade_demande_val.invalidate();
		//
		Unicode::snprintf(textAreaBuffer_CirculateurPrimaire, 4, "%d", sStatut_Primaire->u8ConsigneCirculateur);
		Unicode::snprintf(&textAreaBuffer_CirculateurPrimaire[Unicode::strlen(textAreaBuffer_CirculateurPrimaire)], 2, "%");
		textArea_cons_circ_prim_val.setWildcard(textAreaBuffer_CirculateurPrimaire);
		textArea_cons_circ_prim_val.invalidate();
	}
	//
	Unicode::snprintfFloat(textAreaBuffer_PressionPrimaire, 7, "%.1f", ((float) sStatut_Primaire->u16In_Pression_Eau) / 10);
	textArea_pression_prim_val.setWildcard(textAreaBuffer_PressionPrimaire);
	textArea_pression_prim_val.invalidate();
	//
	Unicode::snprintf(textAreaBuffer_DebitPrimaire, 7, "%d", sStatut_Primaire->u16DebitPrimaire);
	textArea_debit_prim_val.setWildcard(textAreaBuffer_DebitPrimaire);
	textArea_debit_prim_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_BallonTamponPrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16TeauBallonTampon) / 10);
	Unicode::snprintf(&textAreaBuffer_BallonTamponPrimaire[Unicode::strlen(textAreaBuffer_BallonTamponPrimaire)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_BallonTamponPrimaire[Unicode::strlen(textAreaBuffer_BallonTamponPrimaire)], 2,"C");
	textArea_temp_ballon_val.setWildcard(textAreaBuffer_BallonTamponPrimaire);
	textArea_temp_ballon_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_DepartPrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16TeauDepart) / 10);
	Unicode::snprintf(&textAreaBuffer_DepartPrimaire[Unicode::strlen(textAreaBuffer_DepartPrimaire)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_DepartPrimaire[Unicode::strlen(textAreaBuffer_DepartPrimaire)], 2,"C");
	textArea_temp_dep_prim_val.setWildcard(textAreaBuffer_DepartPrimaire);
	textArea_temp_dep_prim_val.invalidate();
	//
	Unicode::snprintfFloat(textAreaBuffer_RetourPrimaire, 7, "%.1f", ((float) sStatut_Primaire->i16TeauRetour) / 10);
	Unicode::snprintf(&textAreaBuffer_RetourPrimaire[Unicode::strlen(textAreaBuffer_RetourPrimaire)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_RetourPrimaire[Unicode::strlen(textAreaBuffer_RetourPrimaire)], 2,"C");
	textArea_temp_ret_prim_val.setWildcard(textAreaBuffer_RetourPrimaire);
	textArea_temp_ret_prim_val.invalidate();

	//
//	memcpy(&sStatut_Primaire_old, sStatut_Primaire, sizeof(S_STATUT_PRIMAIRE));
}

void Variables_systemeView::changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx)
{
	Unicode::UnicodeChar degre[] = {0x00B0};

	switch (u8Zone)
	{
		case ZONE1 :
			//Zone 1 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_1.invalidate();


			//Zone 1 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				if (sConfig_IHM.sParam_Zx[0].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone1, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone1[Unicode::strlen(textAreaBuffer_TintZone1)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone1[Unicode::strlen(textAreaBuffer_TintZone1)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone1, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone1[Unicode::strlen(textAreaBuffer_ConsIntZone1)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone1[Unicode::strlen(textAreaBuffer_ConsIntZone1)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_TintZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_1.setWildcard(textAreaBuffer_ConsIntZone1);
			textArea_val_temp_int_zone_1.setWildcard(textAreaBuffer_TintZone1);
			textArea_val_cons_int_zone_1.invalidate();
			textArea_val_temp_int_zone_1.invalidate();

			//Zone 1 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				if (sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone1, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone1[Unicode::strlen(textAreaBuffer_DepartZone1)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone1[Unicode::strlen(textAreaBuffer_DepartZone1)], 2,"C");
					textArea_val_temp_dep_zone_1.setWildcard(textAreaBuffer_DepartZone1);
				}
				else
				{
					textArea_val_temp_dep_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_1.invalidate();

			//Zone 1 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				if (sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone1, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone1[Unicode::strlen(textAreaBuffer_RetourZone1)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone1[Unicode::strlen(textAreaBuffer_RetourZone1)], 2,"C");
					textArea_val_temp_ret_zone_1.setWildcard(textAreaBuffer_RetourZone1);
				}
				else
				{
					textArea_val_temp_ret_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_1.invalidate();

			//Zone 1 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				if (sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[0].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone1, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone1[Unicode::strlen(textAreaBuffer_ConsigneTeauZone1)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone1[Unicode::strlen(textAreaBuffer_ConsigneTeauZone1)], 2,"C");
					textArea_val_cons_temp_dep_zone_1.setWildcard(textAreaBuffer_ConsigneTeauZone1);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 1 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone1, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_1.setWildcard(textAreaBuffer_DebitZone1);
				}
				else
				{
					textArea_val_debit_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_1.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 1 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone1, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[0].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[0].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[0].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone1, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone1[Unicode::strlen(textAreaBuffer_CirculateurZone1)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone1, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone1, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone1, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_1.setWildcard(textAreaBuffer_CirculateurZone1);
			textArea_val_consigne_circ_zone_1.invalidate();

			//Zone 1 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[0].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_1.setVisible(false);
				textArea_cons_registre_zone_1.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_1.setVisible(false);
				textArea_cons_v3v_zone_1.setVisible(true);
			}
			textArea_cons_registre_zone_1.invalidate();
			textArea_cons_v3v_zone_1.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone1, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone1[Unicode::strlen(textAreaBuffer_V3VZone1)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone1, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_1.setWildcard(textAreaBuffer_V3VZone1);
			textArea_val_cons_v3v_registre_zone_1.invalidate();
			break;
		case ZONE2 :
			//Zone 2 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_2.invalidate();


			//Zone 2 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				if (sConfig_IHM.sParam_Zx[1].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone2, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone2[Unicode::strlen(textAreaBuffer_TintZone2)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone2[Unicode::strlen(textAreaBuffer_TintZone2)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone2, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone2[Unicode::strlen(textAreaBuffer_ConsIntZone2)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone2[Unicode::strlen(textAreaBuffer_ConsIntZone2)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_ConsIntZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_TintZone2, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_2.setWildcard(textAreaBuffer_ConsIntZone2);
			textArea_val_temp_int_zone_2.setWildcard(textAreaBuffer_TintZone2);
			textArea_val_cons_int_zone_2.invalidate();
			textArea_val_temp_int_zone_2.invalidate();

			//Zone 2 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				if (sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone2, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone2[Unicode::strlen(textAreaBuffer_DepartZone2)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone2[Unicode::strlen(textAreaBuffer_DepartZone2)], 2,"C");
					textArea_val_temp_dep_zone_2.setWildcard(textAreaBuffer_DepartZone2);
				}
				else
				{
					textArea_val_temp_dep_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_2.invalidate();

			//Zone 2 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				if (sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone2, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone2[Unicode::strlen(textAreaBuffer_RetourZone2)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone2[Unicode::strlen(textAreaBuffer_RetourZone2)], 2,"C");
					textArea_val_temp_ret_zone_2.setWildcard(textAreaBuffer_RetourZone2);
				}
				else
				{
					textArea_val_temp_ret_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_2.invalidate();

			//Zone 2 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				if (sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[1].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone2, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone2[Unicode::strlen(textAreaBuffer_ConsigneTeauZone2)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone2[Unicode::strlen(textAreaBuffer_ConsigneTeauZone2)], 2,"C");
					textArea_val_cons_temp_dep_zone_2.setWildcard(textAreaBuffer_ConsigneTeauZone2);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 2 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone2, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_2.setWildcard(textAreaBuffer_DebitZone2);
				}
				else
				{
					textArea_val_debit_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_2.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 2 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone2, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[1].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[1].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[1].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone2, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone2[Unicode::strlen(textAreaBuffer_CirculateurZone2)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone2, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone2, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone2, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_2.setWildcard(textAreaBuffer_CirculateurZone2);
			textArea_val_consigne_circ_zone_2.invalidate();

			//Zone 2 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[1].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_2.setVisible(false);
				textArea_cons_registre_zone_2.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_2.setVisible(false);
				textArea_cons_v3v_zone_2.setVisible(true);
			}
			textArea_cons_registre_zone_2.invalidate();
			textArea_cons_v3v_zone_2.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone2, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone2[Unicode::strlen(textAreaBuffer_V3VZone2)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone2, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_2.setWildcard(textAreaBuffer_V3VZone2);
			textArea_val_cons_v3v_registre_zone_2.invalidate();
			break;

		case ZONE3 :
			//Zone 3 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_3.invalidate();


			//Zone 3 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				if (sConfig_IHM.sParam_Zx[2].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone3, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone3[Unicode::strlen(textAreaBuffer_TintZone3)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone3[Unicode::strlen(textAreaBuffer_TintZone3)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone3, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone3[Unicode::strlen(textAreaBuffer_ConsIntZone3)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone3[Unicode::strlen(textAreaBuffer_ConsIntZone3)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_ConsIntZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_TintZone3, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_3.setWildcard(textAreaBuffer_ConsIntZone3);
			textArea_val_temp_int_zone_3.setWildcard(textAreaBuffer_TintZone3);
			textArea_val_cons_int_zone_3.invalidate();
			textArea_val_temp_int_zone_3.invalidate();

			//Zone 3 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				if (sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone3, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone3[Unicode::strlen(textAreaBuffer_DepartZone3)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone3[Unicode::strlen(textAreaBuffer_DepartZone3)], 2,"C");
					textArea_val_temp_dep_zone_3.setWildcard(textAreaBuffer_DepartZone3);
				}
				else
				{
					textArea_val_temp_dep_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_3.invalidate();

			//Zone 3 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				if (sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone3, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone3[Unicode::strlen(textAreaBuffer_RetourZone3)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone3[Unicode::strlen(textAreaBuffer_RetourZone3)], 2,"C");
					textArea_val_temp_ret_zone_3.setWildcard(textAreaBuffer_RetourZone3);
				}
				else
				{
					textArea_val_temp_ret_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_3.invalidate();

			//Zone 3 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				if (sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[2].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone3, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone3[Unicode::strlen(textAreaBuffer_ConsigneTeauZone3)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone3[Unicode::strlen(textAreaBuffer_ConsigneTeauZone3)], 2,"C");
					textArea_val_cons_temp_dep_zone_3.setWildcard(textAreaBuffer_ConsigneTeauZone3);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 3 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone3, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_3.setWildcard(textAreaBuffer_DebitZone3);
				}
				else
				{
					textArea_val_debit_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_3.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 2- Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone3, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[2].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[2].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[2].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone3, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone3[Unicode::strlen(textAreaBuffer_CirculateurZone3)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone3, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone3, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone3, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_3.setWildcard(textAreaBuffer_CirculateurZone3);
			textArea_val_consigne_circ_zone_3.invalidate();

			//Zone 3 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[2].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_3.setVisible(false);
				textArea_cons_registre_zone_3.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_3.setVisible(false);
				textArea_cons_v3v_zone_3.setVisible(true);
			}
			textArea_cons_registre_zone_3.invalidate();
			textArea_cons_v3v_zone_3.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone3 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone3, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone3[Unicode::strlen(textAreaBuffer_V3VZone3)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone3, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_3.setWildcard(textAreaBuffer_V3VZone3);
			textArea_val_cons_v3v_registre_zone_3.invalidate();
			break;
		case ZONE4 :
			//Zone 4 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_4.invalidate();


			//Zone 4 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				if (sConfig_IHM.sParam_Zx[3].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone4, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone4[Unicode::strlen(textAreaBuffer_TintZone4)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone4[Unicode::strlen(textAreaBuffer_TintZone4)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone4, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone4[Unicode::strlen(textAreaBuffer_ConsIntZone4)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone4[Unicode::strlen(textAreaBuffer_ConsIntZone4)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_TintZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_ConsIntZone4, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_4.setWildcard(textAreaBuffer_ConsIntZone4);
			textArea_val_temp_int_zone_4.setWildcard(textAreaBuffer_TintZone4);
			textArea_val_cons_int_zone_4.invalidate();
			textArea_val_temp_int_zone_4.invalidate();

			//Zone 4 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				if (sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone4, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone4[Unicode::strlen(textAreaBuffer_DepartZone4)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone4[Unicode::strlen(textAreaBuffer_DepartZone4)], 2,"C");
					textArea_val_temp_dep_zone_4.setWildcard(textAreaBuffer_DepartZone4);
				}
				else
				{
					textArea_val_temp_dep_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_4.invalidate();

			//Zone 4 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				if (sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone4, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone4[Unicode::strlen(textAreaBuffer_RetourZone4)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone4[Unicode::strlen(textAreaBuffer_RetourZone4)], 2,"C");
					textArea_val_temp_ret_zone_4.setWildcard(textAreaBuffer_RetourZone4);
				}
				else
				{
					textArea_val_temp_ret_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_4.invalidate();

			//Zone 4 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				if (sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[3].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone4, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone4[Unicode::strlen(textAreaBuffer_ConsigneTeauZone4)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone4[Unicode::strlen(textAreaBuffer_ConsigneTeauZone4)], 2,"C");
					textArea_val_cons_temp_dep_zone_4.setWildcard(textAreaBuffer_ConsigneTeauZone4);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 4 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone4, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_4.setWildcard(textAreaBuffer_DebitZone4);
				}
				else
				{
					textArea_val_debit_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_4.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 4 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone4, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[3].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[3].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[3].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone4, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone4[Unicode::strlen(textAreaBuffer_CirculateurZone4)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone4, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone4, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone4, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_4.setWildcard(textAreaBuffer_CirculateurZone4);
			textArea_val_consigne_circ_zone_4.invalidate();

			//Zone 4 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[3].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_4.setVisible(false);
				textArea_cons_registre_zone_4.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_4.setVisible(false);
				textArea_cons_v3v_zone_4.setVisible(true);
			}
			textArea_cons_registre_zone_4.invalidate();
			textArea_cons_v3v_zone_4.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone4 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone4, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone4[Unicode::strlen(textAreaBuffer_V3VZone4)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone4, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_4.setWildcard(textAreaBuffer_V3VZone4);
			textArea_val_cons_v3v_registre_zone_4.invalidate();
			break;

		case ZONE5 :
			//Zone 5 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_5.invalidate();


			//Zone 5 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				if (sConfig_IHM.sParam_Zx[4].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone5, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone5[Unicode::strlen(textAreaBuffer_TintZone5)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone5[Unicode::strlen(textAreaBuffer_TintZone5)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone5, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone5[Unicode::strlen(textAreaBuffer_ConsIntZone5)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone5[Unicode::strlen(textAreaBuffer_ConsIntZone5)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_TintZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_ConsIntZone5, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_5.setWildcard(textAreaBuffer_ConsIntZone5);
			textArea_val_temp_int_zone_5.setWildcard(textAreaBuffer_TintZone5);
			textArea_val_cons_int_zone_5.invalidate();
			textArea_val_temp_int_zone_5.invalidate();

			//Zone 5 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				if (sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone5, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone5[Unicode::strlen(textAreaBuffer_DepartZone5)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone5[Unicode::strlen(textAreaBuffer_DepartZone5)], 2,"C");
					textArea_val_temp_dep_zone_5.setWildcard(textAreaBuffer_DepartZone5);
				}
				else
				{
					textArea_val_temp_dep_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_5.invalidate();

			//Zone 5 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				if (sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone5, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone5[Unicode::strlen(textAreaBuffer_RetourZone5)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone5[Unicode::strlen(textAreaBuffer_RetourZone5)], 2,"C");
					textArea_val_temp_ret_zone_5.setWildcard(textAreaBuffer_RetourZone5);
				}
				else
				{
					textArea_val_temp_ret_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_5.invalidate();

			//Zone 5 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				if (sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[4].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone5, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone5[Unicode::strlen(textAreaBuffer_ConsigneTeauZone5)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone5[Unicode::strlen(textAreaBuffer_ConsigneTeauZone5)], 2,"C");
					textArea_val_cons_temp_dep_zone_5.setWildcard(textAreaBuffer_ConsigneTeauZone5);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 5 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone5, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_5.setWildcard(textAreaBuffer_DebitZone5);
				}
				else
				{
					textArea_val_debit_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_5.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 5 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone5, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[4].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[4].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[4].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone5, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone5[Unicode::strlen(textAreaBuffer_CirculateurZone5)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone5, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone5, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone5, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_5.setWildcard(textAreaBuffer_CirculateurZone5);
			textArea_val_consigne_circ_zone_5.invalidate();

			//Zone 5 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[4].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_5.setVisible(false);
				textArea_cons_registre_zone_5.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_5.setVisible(false);
				textArea_cons_v3v_zone_5.setVisible(true);
			}
			textArea_cons_registre_zone_5.invalidate();
			textArea_cons_v3v_zone_5.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone5 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone5, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone5[Unicode::strlen(textAreaBuffer_V3VZone5)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone5, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_5.setWildcard(textAreaBuffer_V3VZone5);
			textArea_val_cons_v3v_registre_zone_5.invalidate();
			break;

		case ZONE6 :
			//Zone 6 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_6.invalidate();


			//Zone 6 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				if (sConfig_IHM.sParam_Zx[5].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone6, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone6[Unicode::strlen(textAreaBuffer_TintZone6)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone6[Unicode::strlen(textAreaBuffer_TintZone6)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone6, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone6[Unicode::strlen(textAreaBuffer_ConsIntZone6)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone6[Unicode::strlen(textAreaBuffer_ConsIntZone6)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_TintZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_ConsIntZone6, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_6.setWildcard(textAreaBuffer_ConsIntZone6);
			textArea_val_temp_int_zone_6.setWildcard(textAreaBuffer_TintZone6);
			textArea_val_cons_int_zone_6.invalidate();
			textArea_val_temp_int_zone_6.invalidate();

			//Zone 6 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				if (sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone6, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone6[Unicode::strlen(textAreaBuffer_DepartZone6)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone6[Unicode::strlen(textAreaBuffer_DepartZone6)], 2,"C");
					textArea_val_temp_dep_zone_6.setWildcard(textAreaBuffer_DepartZone6);
				}
				else
				{
					textArea_val_temp_dep_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_6.invalidate();

			//Zone 6 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				if (sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone6, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone6[Unicode::strlen(textAreaBuffer_RetourZone6)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone6[Unicode::strlen(textAreaBuffer_RetourZone6)], 2,"C");
					textArea_val_temp_ret_zone_6.setWildcard(textAreaBuffer_RetourZone6);
				}
				else
				{
					textArea_val_temp_ret_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_6.invalidate();

			//Zone 6 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				if (sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[5].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone6, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone6[Unicode::strlen(textAreaBuffer_ConsigneTeauZone6)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone6[Unicode::strlen(textAreaBuffer_ConsigneTeauZone6)], 2,"C");
					textArea_val_cons_temp_dep_zone_6.setWildcard(textAreaBuffer_ConsigneTeauZone6);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 6 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone6, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_6.setWildcard(textAreaBuffer_DebitZone6);
				}
				else
				{
					textArea_val_debit_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_6.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 6 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone6, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[5].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[5].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[5].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone6, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone6[Unicode::strlen(textAreaBuffer_CirculateurZone6)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone6, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone6, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone6, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_6.setWildcard(textAreaBuffer_CirculateurZone6);
			textArea_val_consigne_circ_zone_6.invalidate();

			//Zone 6 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[5].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_6.setVisible(false);
				textArea_cons_registre_zone_6.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_6.setVisible(false);
				textArea_cons_v3v_zone_6.setVisible(true);
			}
			textArea_cons_registre_zone_6.invalidate();
			textArea_cons_v3v_zone_6.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone6 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone6, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone6[Unicode::strlen(textAreaBuffer_V3VZone6)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone6, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_6.setWildcard(textAreaBuffer_V3VZone6);
			textArea_val_cons_v3v_registre_zone_6.invalidate();
			break;

		case ZONE7 :
			//Zone 7 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_7.invalidate();


			//Zone 7 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				if (sConfig_IHM.sParam_Zx[6].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone7, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone7[Unicode::strlen(textAreaBuffer_TintZone7)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone7[Unicode::strlen(textAreaBuffer_TintZone7)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone7, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone7[Unicode::strlen(textAreaBuffer_ConsIntZone7)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone7[Unicode::strlen(textAreaBuffer_ConsIntZone7)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_TintZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_ConsIntZone7, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_7.setWildcard(textAreaBuffer_ConsIntZone7);
			textArea_val_temp_int_zone_7.setWildcard(textAreaBuffer_TintZone7);
			textArea_val_cons_int_zone_7.invalidate();
			textArea_val_temp_int_zone_7.invalidate();

			//Zone 7 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				if (sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone7, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone7[Unicode::strlen(textAreaBuffer_DepartZone7)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone7[Unicode::strlen(textAreaBuffer_DepartZone7)], 2,"C");
					textArea_val_temp_dep_zone_7.setWildcard(textAreaBuffer_DepartZone7);
				}
				else
				{
					textArea_val_temp_dep_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_7.invalidate();

			//Zone 7 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				if (sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone7, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone7[Unicode::strlen(textAreaBuffer_RetourZone7)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone7[Unicode::strlen(textAreaBuffer_RetourZone7)], 2,"C");
					textArea_val_temp_ret_zone_7.setWildcard(textAreaBuffer_RetourZone7);
				}
				else
				{
					textArea_val_temp_ret_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_7.invalidate();

			//Zone 7 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				if (sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[6].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone7, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone7[Unicode::strlen(textAreaBuffer_ConsigneTeauZone7)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone7[Unicode::strlen(textAreaBuffer_ConsigneTeauZone7)], 2,"C");
					textArea_val_cons_temp_dep_zone_7.setWildcard(textAreaBuffer_ConsigneTeauZone7);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 7 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone7, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_7.setWildcard(textAreaBuffer_DebitZone7);
				}
				else
				{
					textArea_val_debit_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_7.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

//			//Zone 7 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone7, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[6].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[6].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[6].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone7, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone7[Unicode::strlen(textAreaBuffer_CirculateurZone7)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone7, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone7, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone7, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_7.setWildcard(textAreaBuffer_CirculateurZone7);
			textArea_val_consigne_circ_zone_7.invalidate();

			//Zone 7 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[5].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_7.setVisible(false);
				textArea_cons_registre_zone_7.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_7.setVisible(false);
				textArea_cons_v3v_zone_7.setVisible(true);
			}
			textArea_cons_registre_zone_7.invalidate();
			textArea_cons_v3v_zone_7.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone7 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone7, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone7[Unicode::strlen(textAreaBuffer_V3VZone7)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone7, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_7.setWildcard(textAreaBuffer_V3VZone7);
			textArea_val_cons_v3v_registre_zone_7.invalidate();
			break;

		case ZONE8 :
			//Zone 8 - Mode
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				switch(sStatut_Zx->Mode)
				{
					case ARRET:
						textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					case MARCHE_CHAUD:
						textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_CHAUD:
						textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_CHAUD_AUTO_PROG_DROITE_DEFAUT));
						break;
					case MARCHE_FROID:
						textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					case AUTO_FROID:
						textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_FROID_AUTO_PROG_DROITE_DEFAUT));
						break;
					case HORS_GEL :
						textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
				}
			}
			else textArea_val_mode_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			textArea_val_mode_zone_8.invalidate();


			//Zone 8 - T Int / Consigne
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				if (sConfig_IHM.sParam_Zx[7].type_zone.zone.TypeThermostat <= TH_MODBUS)
				{
					Unicode::snprintfFloat(textAreaBuffer_TintZone8, 5, "%.1f", ((float) sStatut_Zx->i16Tint / 10));
					Unicode::snprintf(&textAreaBuffer_TintZone8[Unicode::strlen(textAreaBuffer_TintZone8)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TintZone8[Unicode::strlen(textAreaBuffer_TintZone8)], 2,"C");

					if (sStatut_Zx->i16ConsigneTint > 0 && sStatut_Zx->Mode != ARRET)
					{
						Unicode::snprintfFloat(textAreaBuffer_ConsIntZone8, 5, "%f",  ((float) sStatut_Zx->i16ConsigneTint / 10));//, ce_caract);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone8[Unicode::strlen(textAreaBuffer_ConsIntZone8)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_ConsIntZone8[Unicode::strlen(textAreaBuffer_ConsIntZone8)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TintZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

					if (sStatut_Zx->Mode == AUTO_CHAUD || sStatut_Zx->Mode == MARCHE_CHAUD || sStatut_Zx->Mode == HORS_GEL)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else if (sStatut_Zx->Mode == AUTO_FROID || sStatut_Zx->Mode == MARCHE_FROID)
					{
						sStatut_Zx->bTorThermostat == 0 ?
						Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
						:Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_TintZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_int_zone_8.setWildcard(textAreaBuffer_ConsIntZone8);
			textArea_val_temp_int_zone_8.setWildcard(textAreaBuffer_TintZone8);
			textArea_val_cons_int_zone_8.invalidate();
			textArea_val_temp_int_zone_8.invalidate();

			//Zone 8 - T°C Depart
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				if (sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_DepartZone8, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
					Unicode::snprintf(&textAreaBuffer_DepartZone8[Unicode::strlen(textAreaBuffer_DepartZone8)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_DepartZone8[Unicode::strlen(textAreaBuffer_DepartZone8)], 2,"C");
					textArea_val_temp_dep_zone_8.setWildcard(textAreaBuffer_DepartZone8);
				}
				else
				{
					textArea_val_temp_dep_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_dep_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_dep_zone_8.invalidate();

			//Zone 8 - T°C Retour
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				if (sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_RetourZone8, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
					Unicode::snprintf(&textAreaBuffer_RetourZone8[Unicode::strlen(textAreaBuffer_RetourZone8)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_RetourZone8[Unicode::strlen(textAreaBuffer_RetourZone8)], 2,"C");
					textArea_val_temp_ret_zone_8.setWildcard(textAreaBuffer_RetourZone8);
				}
				else
				{
					textArea_val_temp_ret_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_temp_ret_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_val_temp_ret_zone_8.invalidate();

			//Zone 8 - Cons Dép Eau
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				if (sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 0 ||
						(sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == SOUS_STATION) ||
						(sConfig_IHM.sParam_Zx[7].u2RattachementGroupe == 2 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == SOUS_STATION))
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauZone8, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone8[Unicode::strlen(textAreaBuffer_ConsigneTeauZone8)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_ConsigneTeauZone8[Unicode::strlen(textAreaBuffer_ConsigneTeauZone8)], 2,"C");
					textArea_val_cons_temp_dep_zone_8.setWildcard(textAreaBuffer_ConsigneTeauZone8);
				}
				else
				{
					textArea_val_cons_temp_dep_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_cons_temp_dep_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

			//Zone 8 - Debit
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
				{
					Unicode::snprintf(textAreaBuffer_DebitZone8, 7, "%d", sStatut_Zx->u16Debit);
					textArea_val_debit_zone_8.setWildcard(textAreaBuffer_DebitZone8);
				}
				else
				{
					textArea_val_debit_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				}
			}
			else
			{
				textArea_val_debit_zone_8.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}

//			Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
//			:Unicode::snprintf(textAreaBuffer_ConsIntZone8, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
//			textArea_val_cons_int_zone_8.setWildcard(textAreaBuffer_ConsIntZone8);
//
			//Zone 8 - Circulateur
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				if (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_DIRECTE)
				{
					Unicode::snprintf(textAreaBuffer_CirculateurZone8, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				else
				{
					if ((sConfig_IHM.sParam_PAC.TypeRegul != REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[7].type_emetteur.plan_rad_vent.bTypeCirculateur == 0)
					|| (sConfig_IHM.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sParam_Zx[7].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[7].type_emetteur.plan_rad_vent.bTypeCirculateur == 0))
					{
						Unicode::snprintf(textAreaBuffer_CirculateurZone8, 7, "%d", sStatut_Zx->u8ConsigneCirculateur);
						Unicode::snprintf(&textAreaBuffer_CirculateurZone8[Unicode::strlen(textAreaBuffer_CirculateurZone8)], 2,"%");
					}
					else
					{
						if (sStatut_Zx->u8ConsigneCirculateur != 0)
						{
							Unicode::snprintf(textAreaBuffer_CirculateurZone8, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT).getText());
						}
						else Unicode::snprintf(textAreaBuffer_CirculateurZone8, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText());
					}
				}
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_CirculateurZone8, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_consigne_circ_zone_8.setWildcard(textAreaBuffer_CirculateurZone8);
			textArea_val_consigne_circ_zone_8.invalidate();

			//Zone 8 - Registre / V3V
			if (sConfig_IHM.sParam_Zx[5].TypeEmmetteur == GAINABLE)
			{
				textArea_cons_v3v_zone_8.setVisible(false);
				textArea_cons_registre_zone_8.setVisible(true);
			}
			else
			{
				textArea_cons_registre_zone_8.setVisible(false);
				textArea_cons_v3v_zone_8.setVisible(true);
			}
			textArea_cons_registre_zone_8.invalidate();
			textArea_cons_v3v_zone_8.invalidate();

			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone8 == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VZone8, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VZone8[Unicode::strlen(textAreaBuffer_V3VZone8)], 2,"%");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_V3VZone8, 4, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
			}
			textArea_val_cons_v3v_registre_zone_8.setWildcard(textAreaBuffer_V3VZone8);
			textArea_val_cons_v3v_registre_zone_8.invalidate();
			break;
		case ZONE_GROUPE_A :
			///Mode Groupe A
			if(sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 0)
			{
				textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			else
			{
				switch (sStatut_Zx->Mode)
				{
					  case ARRET:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					  case MARCHE_CHAUD:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_DROIT_DEFAUT));
						break;
					  case AUTO_CHAUD:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_DROIT_DEFAUT));
//							) +
//							' ' +
//							FlutterI18n.translate(
//							  context,
//							  "AUTO_PROG",
//							);
						break;
					  case HORS_GEL:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
					  case MARCHE_FROID:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					  case AUTO_FROID:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
//							' ' +
//							FlutterI18n.translate(
//							  context,
//							  "AUTO_PROG",
//							);
						break;
					  default:
						break;
					}
			}
			textArea_mode_groupe_a_val.invalidate();
			//T°C Depart
			if (sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintfFloat(textAreaBuffer_DepartGroupeA, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
				Unicode::snprintf(&textAreaBuffer_DepartGroupeA[Unicode::strlen(textAreaBuffer_DepartGroupeA)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_DepartGroupeA[Unicode::strlen(textAreaBuffer_DepartGroupeA)], 2,"C");
				textArea_temp_dep_groupe_a_val.setWildcard(textAreaBuffer_DepartGroupeA);
			}
			else
			{
				textArea_temp_dep_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_temp_dep_groupe_a_val.invalidate();
			//T°C Retour
			if (sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintfFloat(textAreaBuffer_RetourGroupeA, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
				Unicode::snprintf(&textAreaBuffer_RetourGroupeA[Unicode::strlen(textAreaBuffer_RetourGroupeA)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_RetourGroupeA[Unicode::strlen(textAreaBuffer_RetourGroupeA)], 2,"C");
				textArea_temp_ret_groupe_a_val.setWildcard(textAreaBuffer_RetourGroupeA);
			}
			else
			{
				textArea_temp_ret_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_temp_ret_groupe_a_val.invalidate();
			//Consigne départ
			if (sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauGroupeA, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
				Unicode::snprintf(&textAreaBuffer_ConsigneTeauGroupeA[Unicode::strlen(textAreaBuffer_ConsigneTeauGroupeA)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_ConsigneTeauGroupeA[Unicode::strlen(textAreaBuffer_ConsigneTeauGroupeA)], 2,"C");
				textArea_cons_temp_dep_groupe_a_val.setWildcard(textAreaBuffer_ConsigneTeauGroupeA);
			}
			else
			{
				textArea_cons_temp_dep_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_cons_temp_dep_groupe_a_val.invalidate();
			//Circulateur
//			textArea_circ_groupe_a_on_off_val.setVisible(false);
//			textArea_circ_groupe_a_percent_val.setVisible(false);
//			if(sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 0)
//			{
//				textArea_circ_groupe_a_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
//				textArea_circ_groupe_a_on_off_val.setVisible(true);
//				textArea_circ_groupe_a_on_off_val.invalidate();
//			}
//			else if( sConfig_IHM.sParam_Zx[8].NumCarteMZ != 3 && sConfig_IHM.sParam_Zx[8].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_GRUNDFOS)
//			{
//				Unicode::snprintf(textAreaBuffer_CirculateurGroupeA, 4, "%d", sStatut_Zx->u8ConsigneCirculateur);
//				Unicode::snprintf(&textAreaBuffer_CirculateurGroupeA[Unicode::strlen(textAreaBuffer_CirculateurGroupeA)], 2,"%");
//				textArea_circ_groupe_a_percent_val.setWildcard(textAreaBuffer_CirculateurGroupeA);
//				textArea_circ_groupe_a_percent_val.setVisible(true);
//				textArea_circ_groupe_a_percent_val.invalidate();
//			}
//			else
//			{
//				if (sStatut_Zx->u8ConsigneCirculateur == 1)
//				{
//					textArea_circ_groupe_a_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT));
//				}
//				else textArea_circ_groupe_a_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT));
//				textArea_circ_groupe_a_on_off_val.setVisible(true);
//				textArea_circ_groupe_a_on_off_val.invalidate();
//			}
			textArea_circ_groupe_a_on_off_val.setVisible(false);
			textArea_circ_groupe_a_percent_val.setVisible(false);
			if(sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 0)
			{
				textArea_circ_groupe_a_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				textArea_circ_groupe_a_on_off_val.setVisible(true);
				textArea_circ_groupe_a_on_off_val.invalidate();
			}
			else if( sConfig_IHM.sParam_Zx[8].NumCarteMZ == 3 && sConfig_IHM.sParam_Zx[8].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_GRUNDFOS)
			{
				Unicode::snprintf(textAreaBuffer_CirculateurGroupeA, 4, "%d", sStatut_Zx->u8ConsigneCirculateur);
				Unicode::snprintf(&textAreaBuffer_CirculateurGroupeA[Unicode::strlen(textAreaBuffer_CirculateurGroupeA)], 2,"%");
				textArea_circ_groupe_a_on_off_val.setVisible(false);
				textArea_circ_groupe_a_on_off_val.invalidate();
				textArea_circ_groupe_a_percent_val.setWildcard(textAreaBuffer_CirculateurGroupeA);
				textArea_circ_groupe_a_percent_val.setVisible(true);
				textArea_circ_groupe_a_percent_val.invalidate();

			}
			else
			{
				if (sStatut_Zx->u8ConsigneCirculateur != 0)
				{
					textArea_circ_groupe_a_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT));
				}
				else textArea_circ_groupe_a_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT));
				textArea_circ_groupe_a_percent_val.setVisible(false);
				textArea_circ_groupe_a_percent_val.invalidate();
				textArea_circ_groupe_a_on_off_val.setVisible(true);
				textArea_circ_groupe_a_on_off_val.invalidate();
			}
			//Consigne V3V
			if (sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VGroupeA, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VGroupeA[Unicode::strlen(textAreaBuffer_V3VGroupeA)], 2,"%");
				textArea_cons_v3v_groupe_a_val.setWildcard(textAreaBuffer_V3VGroupeA);
			}
			else
			{
				textArea_cons_v3v_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_cons_v3v_groupe_a_val.invalidate();
			//Consigne Ventil
			if (sConfig_IHM.sParam_Zx[8].type_zone.GroupeEau.bGroupeActif == 1 && sConfig_IHM.sParam_Zx[8].TypeEmmetteur == GAINABLE)
			{
				Unicode::snprintf(textAreaBuffer_ConsVentilGroupeA, 4, "%d", sStatut_Zx->u8ConsigneFanCassette);
				Unicode::snprintf(&textAreaBuffer_ConsVentilGroupeA[Unicode::strlen(textAreaBuffer_ConsVentilGroupeA)], 2,"%");
				textArea_cons_ventil_groupe_a_val.setWildcard(textAreaBuffer_ConsVentilGroupeA);
			}
			else
			{
				textArea_cons_ventil_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_cons_ventil_groupe_a_val.invalidate();
			break;
		case ZONE_GROUPE_B :
			//Mode Groupe B
			if(sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 0)
			{
				textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			else
			{
				switch (sStatut_Zx->Mode)
				{
					  case ARRET:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_ARRET_DROITE_DEFAUT));
						break;
					  case MARCHE_CHAUD:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_DROIT_DEFAUT));
						break;
					  case AUTO_CHAUD:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_DROIT_DEFAUT));
//							) +
//							' ' +
//							FlutterI18n.translate(
//							  context,
//							  "AUTO_PROG",
//							);
						break;
					  case HORS_GEL:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_HORS_GEL_DROITE_DEFAUT));
						break;
					  case MARCHE_FROID:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
						break;
					  case AUTO_FROID:
						  textArea_mode_groupe_a_val.setTypedText(touchgfx::TypedText(T_TEXT_FROID_MARCHE_DROITE_DEFAUT));
//							' ' +
//							FlutterI18n.translate(
//							  context,
//							  "AUTO_PROG",
//							);
						break;
					  default:
						break;
					}
			}
			textArea_mode_groupe_a_val.invalidate();
			//T°C Depart
			if (sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintfFloat(textAreaBuffer_DepartGroupeB, 7, "%.1f", ((float) sStatut_Zx->i16TeauDepart) / 10);
				Unicode::snprintf(&textAreaBuffer_DepartGroupeB[Unicode::strlen(textAreaBuffer_DepartGroupeB)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_DepartGroupeB[Unicode::strlen(textAreaBuffer_DepartGroupeB)], 2,"C");
				textArea_temp_dep_groupe_b_val.setWildcard(textAreaBuffer_DepartGroupeB);
			}
			else
			{
				textArea_temp_dep_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_temp_dep_groupe_b_val.invalidate();
			//T°C Retour
			if (sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintfFloat(textAreaBuffer_RetourGroupeB, 7, "%.1f", ((float) sStatut_Zx->i16TeauRetour) / 10);
				Unicode::snprintf(&textAreaBuffer_RetourGroupeB[Unicode::strlen(textAreaBuffer_RetourGroupeB)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_RetourGroupeB[Unicode::strlen(textAreaBuffer_RetourGroupeB)], 2,"C");
				textArea_temp_ret_groupe_b_val.setWildcard(textAreaBuffer_RetourGroupeB);
			}
			else
			{
				textArea_temp_ret_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_temp_ret_groupe_b_val.invalidate();
			//Consigne départ
			if (sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintfFloat(textAreaBuffer_ConsigneTeauGroupeB, 7, "%.1f", ((float) sStatut_Zx->i16ConsigneTeau) / 10);
				Unicode::snprintf(&textAreaBuffer_ConsigneTeauGroupeB[Unicode::strlen(textAreaBuffer_ConsigneTeauGroupeB)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_ConsigneTeauGroupeB[Unicode::strlen(textAreaBuffer_ConsigneTeauGroupeB)], 2,"C");
				textArea_cons_temp_dep_groupe_b_val.setWildcard(textAreaBuffer_ConsigneTeauGroupeB);
			}
			else
			{
				textArea_cons_temp_dep_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_cons_temp_dep_groupe_b_val.invalidate();
			//Circulateur
			textArea_circ_groupe_b_on_off_val.setVisible(false);
			textArea_circ_groupe_b_percent_val.setVisible(false);
			if(sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 0)
			{
				textArea_circ_groupe_b_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
				textArea_circ_groupe_b_on_off_val.setVisible(true);
				textArea_circ_groupe_b_on_off_val.invalidate();
			}
			else if(sConfig_IHM.sParam_Zx[9].NumCarteMZ != 3 && sConfig_IHM.sParam_Zx[9].type_emetteur.plan_rad_vent.bTypeCirculateur == TYPE_GRUNDFOS)
			{
				Unicode::snprintf(textAreaBuffer_CirculateurGroupeB, 4, "%d", sStatut_Zx->u8ConsigneCirculateur);
				Unicode::snprintf(&textAreaBuffer_CirculateurGroupeB[Unicode::strlen(textAreaBuffer_CirculateurGroupeB)], 2,"%");
				textArea_circ_groupe_b_percent_val.setWildcard(textAreaBuffer_CirculateurGroupeB);
				textArea_circ_groupe_b_percent_val.setVisible(true);
				textArea_circ_groupe_b_percent_val.invalidate();
			}
			else
			{
				if (sStatut_Zx->u8ConsigneCirculateur == 1)
				{
					textArea_circ_groupe_b_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_ON_DROIT_DEFAUT));
				}
				else textArea_circ_groupe_b_on_off_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT));
				textArea_circ_groupe_b_on_off_val.setVisible(true);
				textArea_circ_groupe_b_on_off_val.invalidate();
			}
			//Consigne V3V
			if (sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 1)
			{
				Unicode::snprintf(textAreaBuffer_V3VGroupeB, 4, "%d", sStatut_Zx->u8ConsigneVanneMelange);
				Unicode::snprintf(&textAreaBuffer_V3VGroupeB[Unicode::strlen(textAreaBuffer_V3VGroupeB)], 2,"%");
				textArea_cons_v3v_groupe_b_val.setWildcard(textAreaBuffer_V3VGroupeA);
			}
			else
			{
				textArea_cons_v3v_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_cons_v3v_groupe_b_val.invalidate();
			//Consigne Ventil
			if (sConfig_IHM.sParam_Zx[9].type_zone.GroupeEau.bGroupeActif == 1 && sConfig_IHM.sParam_Zx[9].TypeEmmetteur == GAINABLE)
			{
				Unicode::snprintf(textAreaBuffer_ConsVentilGroupeB, 4, "%d", sStatut_Zx->u8ConsigneFanCassette);
				Unicode::snprintf(&textAreaBuffer_ConsVentilGroupeB[Unicode::strlen(textAreaBuffer_ConsVentilGroupeB)], 2,"%");
				textArea_cons_ventil_groupe_b_val.setWildcard(textAreaBuffer_ConsVentilGroupeB);
			}
			else
			{
				textArea_cons_ventil_groupe_b_val.setTypedText(touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT));
			}
			textArea_cons_ventil_groupe_b_val.invalidate();
			break;
		default:
			break;
	}
}

void Variables_systemeView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	Unicode::UnicodeChar degre[] = {0x00B0};
	int valtemp;

	//Geoinverter
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER || sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX)
	{
		//Circulateur
		if (sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire == TYPE_RELAIS)
		{
			//Consigne Relais
			sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire == 0 ?
					Unicode::snprintf(textAreaBuffer_CirculateurPrimaire, 4, touchgfx::TypedText(T_TEXT_OFF_DROITE_DEFAUT).getText()):
					Unicode::snprintf(textAreaBuffer_CirculateurPrimaire, 4, touchgfx::TypedText(T_TEXT_ON_DROITE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_CirculateurPrimaire, 4, "%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire);
			Unicode::snprintf(&textAreaBuffer_CirculateurPrimaire[Unicode::strlen(textAreaBuffer_CirculateurPrimaire)], 2, "%");
		}
		textArea_cons_circ_prim_val.setWildcard(textAreaBuffer_CirculateurPrimaire);
		textArea_cons_circ_prim_val.invalidate();
	}


	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		//Demande
		switch(sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.u4Demande)
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
		//Consigne
		Unicode::snprintfFloat(textAreaBuffer_ConsignePrimaire, 7, "%.1f", ((float) sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16ConsignePrimaire) / 10);
		Unicode::snprintf(&textAreaBuffer_ConsignePrimaire[Unicode::strlen(textAreaBuffer_ConsignePrimaire)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_ConsignePrimaire[Unicode::strlen(textAreaBuffer_ConsignePrimaire)], 2,"C");
		textArea_cons_temp_prim_val.setWildcard(textAreaBuffer_ConsignePrimaire);
		textArea_cons_temp_prim_val.invalidate();
		textArea_demande_pac_val.setWildcard2(textAreaBuffer_ConsignePrimaire);
		textArea_demande_pac_val.invalidate();


	}
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX)
	{
		switch(sCyclRegFrigo->pac.phoenix.sStatutFrigoPhoenix.u4Demande)
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
		//Consigne
		Unicode::snprintfFloat(textAreaBuffer_ConsignePrimaire, 7, "%.1f", ((float) sCyclRegFrigo->pac.phoenix.sStatutFrigoPhoenix.i16ConsignePrimaire) / 10);
		Unicode::snprintf(&textAreaBuffer_ConsignePrimaire[Unicode::strlen(textAreaBuffer_ConsignePrimaire)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_ConsignePrimaire[Unicode::strlen(textAreaBuffer_ConsignePrimaire)], 2,"C");
		textArea_cons_temp_prim_val.setWildcard(textAreaBuffer_ConsignePrimaire);
		textArea_cons_temp_prim_val.invalidate();
		textArea_demande_pac_val.setWildcard2(textAreaBuffer_ConsignePrimaire);
		textArea_demande_pac_val.invalidate();
	}
	//
	Unicode::snprintfFloat(textAreaBuffer_Temp_Ext, 7, "%.1f", ((float) sCyclRegFrigo->commun.i16Text) / 10);
	Unicode::snprintf(&textAreaBuffer_Temp_Ext[Unicode::strlen(textAreaBuffer_Temp_Ext)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Temp_Ext[Unicode::strlen(textAreaBuffer_Temp_Ext)], 2,"C");
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

	//ECS Fin thermo
	if (sCyclRegFrigo->commun.sStatut.bFinThermoDynamique == 0)	Unicode::snprintf(textAreaBuffer_Fin_Thermo, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Fin_Thermo, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_fin_cycle_thermo_val.setWildcard(textAreaBuffer_Fin_Thermo);
	textArea_fin_cycle_thermo_val.invalidate();

	//Inverterra
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		//Reduc PW Inv
		switch (sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.u3Reduction_PW)
		{
			default:
			case R0 :
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R0).getText());
				break;
			case R1:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R1).getText());
				break;
			case R2:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R2).getText());
				break;
			case R3:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R3).getText());
				break;
			case R4:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R4).getText());
				break;
			case R5:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R5).getText());
				break;
			case R6:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R6).getText());
				break;
			case R7:
				Unicode::snprintf(textAreaBuffer_ReducPW_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R7).getText());
				break;

		}
		textArea_inv_val_statut_reduc_pw.setWildcard(textAreaBuffer_ReducPW_Inv);
		textArea_inv_val_statut_reduc_pw.invalidate();
		//Driver DSP Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bDSP_ChipReset == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DSP_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DSP_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_dsp_reset.setWildcard(textAreaBuffer_DSP_Inv);
		textArea_inv_val_dsp_reset.invalidate();
		//Defaut Driver Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bDriveFault == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautDriver_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautDriver_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_defaut_driver.setWildcard(textAreaBuffer_DefautDriver_Inv);
		textArea_inv_val_defaut_driver.invalidate();
		//Demarrage comp Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorStartup == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Dem_Comp_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Dem_Comp_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_dem_comp.setWildcard(textAreaBuffer_Dem_Comp_Inv);
		textArea_inv_val_dem_comp.invalidate();
		//Re-demarrage comp Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorRestartup == 0)
		{
			 Unicode::snprintf(textAreaBuffer_ReDem_Comp_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_ReDem_Comp_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_redem_comp.setWildcard(textAreaBuffer_ReDem_Comp_Inv);
		textArea_inv_val_redem_comp.invalidate();
		//Compreseur Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorRunning == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Comp_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Comp_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_comp.setWildcard(textAreaBuffer_Comp_Inv);
		textArea_inv_val_comp.invalidate();
		//Augmentation Vitesse Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorSpeedIncreasing == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Augm_Vit_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Augm_Vit_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_augm_vit.setWildcard(textAreaBuffer_Augm_Vit_Inv);
		textArea_inv_val_augm_vit.invalidate();
		//Diminution Vitesse Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorSpeedDecreasing == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Dim_Vit_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Dim_Vit_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_dim_vit.setWildcard(textAreaBuffer_Dim_Vit_Inv);
		textArea_inv_val_dim_vit.invalidate();
		//Protection Vitesse basse Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorSpeedDroopProtection == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Protect_Vit_Bas_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Protect_Vit_Bas_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_protect_lim_vit_basse.setWildcard(textAreaBuffer_Protect_Vit_Bas_Inv);
		textArea_inv_val_protect_lim_vit_basse.invalidate();
		//Protection Vitesse haute Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorSpeedLimitProtection == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Protect_Vit_Haut_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Protect_Vit_Haut_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_protect_lim_vit_haute.setWildcard(textAreaBuffer_Protect_Vit_Haut_Inv);
		textArea_inv_val_protect_lim_vit_haute.invalidate();
		//PFC Inv
		if (sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bSupply == 0)
		{
			if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bPFC_ON_OFF == 0)
			{
				 Unicode::snprintf(textAreaBuffer_PFC_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
			}
			else Unicode::snprintf(textAreaBuffer_PFC_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_PFC_Inv, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_inv_val_pfc.setWildcard(textAreaBuffer_PFC_Inv);
		textArea_inv_val_pfc.invalidate();
		//Courant Phase comp Inv
		Unicode::snprintfFloat(textAreaBuffer_CourantPhase_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorPhaseCurrent) / 10);
		textArea_inv_val_courant_in_ac.setWildcard(textAreaBuffer_CourantPhase_Inv);
		textArea_inv_val_courant_in_ac.invalidate();
		//Courant AC Inv
		Unicode::snprintfFloat(textAreaBuffer_CourantAC_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16AC_InputCurrent) / 10);
		textArea_inv_val_courant_in_ac.setWildcard(textAreaBuffer_CourantAC_Inv);
		textArea_inv_val_courant_in_ac.invalidate();
		//Tension AC Inv
		Unicode::snprintfFloat(textAreaBuffer_TensionAC_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16AC_InputVoltage) / 10);
		textArea_inv_val_tension_in_ac.setWildcard(textAreaBuffer_TensionAC_Inv);
		textArea_inv_val_tension_in_ac.invalidate();
		//Tension DC Inv
		Unicode::snprintfFloat(textAreaBuffer_TensionDC_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16DC_Voltage) / 10);
		textArea_inv_val_tension_dc.setWildcard(textAreaBuffer_TensionDC_Inv);
		textArea_inv_val_tension_dc.invalidate();
		//Temp IPM Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_IPM_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16IPM_Temperature) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_IPM_Inv[Unicode::strlen(textAreaBuffer_Temp_IPM_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_IPM_Inv[Unicode::strlen(textAreaBuffer_Temp_IPM_Inv)], 2,"C");
		textArea_inv_val_temp_ipm.setWildcard(textAreaBuffer_Temp_IPM_Inv);
		textArea_inv_val_temp_ipm.invalidate();
		//Temp PFC Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_PFC_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16PFC_Temperature) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_PFC_Inv[Unicode::strlen(textAreaBuffer_Temp_PFC_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_PFC_Inv[Unicode::strlen(textAreaBuffer_Temp_PFC_Inv)], 2,"C");
		textArea_inv_val_temp_pfc.setWildcard(textAreaBuffer_Temp_PFC_Inv);
		textArea_inv_val_temp_pfc.invalidate();
		//Courant U Inv
		Unicode::snprintfFloat(textAreaBuffer_Courant_U_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorU_PhaseCurrent) / 10);
		textArea_inv_val_courant_u_comp.setWildcard(textAreaBuffer_Courant_U_Inv);
		textArea_inv_val_courant_u_comp.invalidate();
		//Courant V Inv
		Unicode::snprintfFloat(textAreaBuffer_Courant_V_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorV_PhaseCurrent) / 10);
		textArea_inv_val_courant_v_comp.setWildcard(textAreaBuffer_Courant_V_Inv);
		textArea_inv_val_courant_v_comp.invalidate();
		//Courant W Inv
		Unicode::snprintfFloat(textAreaBuffer_Courant_W_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorW_PhaseCurrent) / 10);
		textArea_inv_val_courant_w_comp.setWildcard(textAreaBuffer_Courant_W_Inv);
		textArea_inv_val_courant_w_comp.invalidate();
		//Fréquence/RPM Inv
		Unicode::snprintf(textAreaBuffer_FrequenceCurrent_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16DetectedSpeedByCurrentFrequency);
		textArea_inv_val_vit_mes_courant.setWildcard1(textAreaBuffer_FrequenceCurrent_Inv);
		Unicode::snprintf(textAreaBuffer_RPMCurrent_Inv, 5, "%d", (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16DetectedSpeedByCurrentFrequency / 60));
		textArea_inv_val_vit_mes_courant.setWildcard2(textAreaBuffer_RPMCurrent_Inv);
		textArea_inv_val_vit_mes_courant.invalidate();
		//Temp DLT Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16DLT_Temperature != 0)
		{
			Unicode::snprintfFloat(textAreaBuffer_Temp_DLT_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16DLT_Temperature) / 10);
			Unicode::snprintf(&textAreaBuffer_Temp_DLT_Inv[Unicode::strlen(textAreaBuffer_Temp_DLT_Inv)], 2,"%s", degre);
			Unicode::snprintf(&textAreaBuffer_Temp_DLT_Inv[Unicode::strlen(textAreaBuffer_Temp_DLT_Inv)], 2,"C");
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Temp_DLT_Inv, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_inv_val_temp_dlt.setWildcard(textAreaBuffer_Temp_DLT_Inv);
		textArea_inv_val_temp_dlt.invalidate();
		//Temp Cond Max VS Evap Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16MaxCondensingTempVSEvap) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv[Unicode::strlen(textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv[Unicode::strlen(textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv)], 2,"C");
		textArea_inv_val_temp_cond_max.setWildcard(textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv);
		textArea_inv_val_temp_cond_max.invalidate();
		//Temp Cond Min VS Evap Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16MinCondensingTempVSEvap) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv[Unicode::strlen(textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv[Unicode::strlen(textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv)], 2,"C");
		textArea_inv_val_temp_cond_min.setWildcard(textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv);
		textArea_inv_val_temp_cond_min.invalidate();
		//Press HP Max VS vitesse Inv
		Unicode::snprintfFloat(textAreaBuffer_Press_HP_Max_VS_Vitesse_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16MaxPressureHP_VS_RPM) / 10);
		textArea_inv_val_press_hp_max.setWildcard(textAreaBuffer_Press_HP_Max_VS_Vitesse_Inv);
		textArea_inv_val_press_hp_max.invalidate();
		//Restriction Inv
		if ((sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.u8TypeRestriction & 0x04) == 0x04)
		{
			Unicode::snprintf(textAreaBuffer_Restriction_Inv, 2, "1");
		}
		else Unicode::snprintf(textAreaBuffer_Restriction_Inv, 2, "0");
		if ((sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.u8TypeRestriction & 0x02) == 0x02)
		{
			Unicode::snprintf(&textAreaBuffer_Restriction_Inv[Unicode::strlen(textAreaBuffer_Restriction_Inv)], 2, "1");
		}
		else Unicode::snprintf(&textAreaBuffer_Restriction_Inv[Unicode::strlen(textAreaBuffer_Restriction_Inv)], 2, "0");
		if ((sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.u8TypeRestriction & 0x01) == 0x01)
		{
			Unicode::snprintf(&textAreaBuffer_Restriction_Inv[Unicode::strlen(textAreaBuffer_Restriction_Inv)], 2, "1");
		}
		else Unicode::snprintf(&textAreaBuffer_Restriction_Inv[Unicode::strlen(textAreaBuffer_Restriction_Inv)], 2, "0");
		textArea_inv_val_type_restriction.setWildcard(textAreaBuffer_Restriction_Inv);
		textArea_inv_val_type_restriction.invalidate();
		//Machine OK Inv
		if (sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.bMachineOK == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Machine_OK_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Machine_OK_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_machine_ok.setWildcard(textAreaBuffer_Machine_OK_Inv);
		textArea_inv_val_machine_ok.invalidate();
		//Cycle retour d'huile Inv
		if (sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.bCycleRetourHuile == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Retour_Huile_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Retour_Huile_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_retour_huile.setWildcard(textAreaBuffer_Retour_Huile_Inv);
		textArea_inv_val_retour_huile.invalidate();
		//Pb thermodynapique Inv
		if (sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.bProblemeThermodynamique == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Pb_Thermo_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Pb_Thermo_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_pb_thermo.setWildcard(textAreaBuffer_Pb_Thermo_Inv);
		textArea_inv_val_pb_thermo.invalidate();
		//Pré-chauffage Inv
		if (sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.bPreHeating== 0)
		{
			 Unicode::snprintf(textAreaBuffer_Pre_Chauffage_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Pre_Chauffage_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_pre_chauf.setWildcard(textAreaBuffer_Pre_Chauffage_Inv);
		textArea_inv_val_pre_chauf.invalidate();
		//Frigo Spare Inv
		Unicode::snprintf(textAreaBuffer_Frigo_Spare_Inv, 11, "%d", sCyclRegFrigo->commun.u32Spare);
		textArea_inv_val_spare.setWildcard(textAreaBuffer_Frigo_Spare_Inv);
		textArea_inv_val_spare.invalidate();
		//Temp Dep Prim Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Prim_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Dep_Prim_Inv[Unicode::strlen(textAreaBuffer_Temp_Dep_Prim_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Dep_Prim_Inv[Unicode::strlen(textAreaBuffer_Temp_Dep_Prim_Inv)], 2,"C");
		textArea_inv_val_dep_prim.setWildcard(textAreaBuffer_Temp_Dep_Prim_Inv);
		textArea_inv_val_dep_prim.invalidate();
		//Temp Ret Prim Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Ret_Prim_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Ret_Prim_Inv[Unicode::strlen(textAreaBuffer_Temp_Ret_Prim_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Ret_Prim_Inv[Unicode::strlen(textAreaBuffer_Temp_Ret_Prim_Inv)], 2,"C");
		textArea_inv_val_ret_prim.setWildcard(textAreaBuffer_Temp_Ret_Prim_Inv);
		textArea_inv_val_ret_prim.invalidate();
		//Press Prim Inv
		Unicode::snprintfFloat(textAreaBuffer_Press_Prim_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_EauChauffage) / 10);
		textArea_inv_val_press_prim.setWildcard(textAreaBuffer_Press_Prim_Inv);
		textArea_inv_val_press_prim.invalidate();
		//Debit Prim Inv
		Unicode::snprintf(textAreaBuffer_Debit_Prim_Inv, 6, "%d", sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.u16DebitPrimaire);
		textArea_inv_val_debit_prim.setWildcard(textAreaBuffer_Debit_Prim_Inv);
		textArea_inv_val_debit_prim.invalidate();
		//Temp Ext Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Ext_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Ext_Inv[Unicode::strlen(textAreaBuffer_Temp_Ext_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Ext_Inv[Unicode::strlen(textAreaBuffer_Temp_Ext_Inv)], 2,"C");
		textArea_inv_val_temp_ext.setWildcard(textAreaBuffer_Temp_Ext_Inv);
		textArea_inv_val_temp_ext.invalidate();
		//Temp Dep Capt Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Capt_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Dep_Capt_Inv[Unicode::strlen(textAreaBuffer_Temp_Dep_Capt_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Dep_Capt_Inv[Unicode::strlen(textAreaBuffer_Temp_Dep_Capt_Inv)], 2,"C");
		textArea_inv_val_dep_cap.setWildcard(textAreaBuffer_Temp_Dep_Capt_Inv);
		textArea_inv_val_dep_cap.invalidate();
		//Temp Ret Capt Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Ret_Capt_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Ret_Capt_Inv[Unicode::strlen(textAreaBuffer_Temp_Ret_Capt_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Ret_Capt_Inv[Unicode::strlen(textAreaBuffer_Temp_Ret_Capt_Inv)], 2,"C");
		textArea_inv_val_ret_cap.setWildcard(textAreaBuffer_Temp_Ret_Capt_Inv);
		textArea_inv_val_ret_cap.invalidate();
		//Press Capt Inv
		Unicode::snprintfFloat(textAreaBuffer_Press_Capt_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_EauCapteur) / 10);
		textArea_inv_val_press_cap.setWildcard(textAreaBuffer_Press_Capt_Inv);
		textArea_inv_val_press_cap.invalidate();
		//Debit Capt Inv
		Unicode::snprintf(textAreaBuffer_Temp_Debit_Capt_Inv, 6, "%d", sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.u16DebitCapteur);
		textArea_inv_val_debit_cap.setWildcard(textAreaBuffer_Temp_Debit_Capt_Inv);
		textArea_inv_val_debit_cap.invalidate();
		//Temp Liquide Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_Liquide_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_Liquide_Inv[Unicode::strlen(textAreaBuffer_Temp_Liquide_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Liquide_Inv[Unicode::strlen(textAreaBuffer_Temp_Liquide_Inv)], 2,"C");
		textArea_inv_val_temp_liqu.setWildcard(textAreaBuffer_Temp_Liquide_Inv);
		textArea_inv_val_temp_liqu.invalidate();
		//Temp HP Cible Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_HP_Cible_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16Temp_HP_Cible[0]) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_HP_Cible_Inv[Unicode::strlen(textAreaBuffer_Temp_HP_Cible_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_HP_Cible_Inv[Unicode::strlen(textAreaBuffer_Temp_HP_Cible_Inv)], 2,"C");
		textArea_val_inv_temp_hp_cible.setWildcard(textAreaBuffer_Temp_HP_Cible_Inv);
		textArea_val_inv_temp_hp_cible.invalidate();
		//Temp HP Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_HP_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_HP_Inv[Unicode::strlen(textAreaBuffer_Temp_HP_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_HP_Inv[Unicode::strlen(textAreaBuffer_Temp_HP_Inv)], 2,"C");
		textArea_val_inv_temp_hp.setWildcard(textAreaBuffer_Temp_HP_Inv);
		textArea_val_inv_temp_hp.invalidate();
		//Temp BP Inv
		Unicode::snprintfFloat(textAreaBuffer_Temp_BP_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_BP_Inv[Unicode::strlen(textAreaBuffer_Temp_BP_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_BP_Inv[Unicode::strlen(textAreaBuffer_Temp_BP_Inv)], 2,"C");
		textArea_val_inv_temp_bp.setWildcard(textAreaBuffer_Temp_BP_Inv);
		textArea_val_inv_temp_bp.invalidate();
		//Press / Temp Cond Inv
		Unicode::snprintfFloat(textAreaBuffer_Press_Temp_Cond_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1) / 10);
		Unicode::snprintf(&textAreaBuffer_Press_Temp_Cond_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Cond_Inv)], 9," bars / ");
		Unicode::snprintfFloat(&textAreaBuffer_Press_Temp_Cond_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Cond_Inv)], 6,"%.1f",((float)ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u4TypeGaz, true, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 + 10)/10));
		Unicode::snprintf(&textAreaBuffer_Press_Temp_Cond_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Cond_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Press_Temp_Cond_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Cond_Inv)], 2,"C");
		textArea_inv_val_press_hp.setWildcard(textAreaBuffer_Press_Temp_Cond_Inv);
		textArea_inv_val_press_hp.invalidate();
		//Press / Temp Evap Inv
		Unicode::snprintfFloat(textAreaBuffer_Press_Temp_Evap_Inv, 8, "%.1f", ((float)sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1) / 10);
		Unicode::snprintf(&textAreaBuffer_Press_Temp_Evap_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Evap_Inv)], 9," bars / ");
		Unicode::snprintfFloat(&textAreaBuffer_Press_Temp_Evap_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Evap_Inv)], 6,"%.1f",((float)ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u4TypeGaz, false, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 + 10)/10));
		Unicode::snprintf(&textAreaBuffer_Press_Temp_Evap_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Evap_Inv)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Press_Temp_Evap_Inv[Unicode::strlen(textAreaBuffer_Press_Temp_Evap_Inv)], 2,"C");
		textArea_inv_val_press_bp.setWildcard(textAreaBuffer_Press_Temp_Evap_Inv);
		textArea_inv_val_press_bp.invalidate();
		//Demande vitesse Inv
		Unicode::snprintf(textAreaBuffer_Dde_Vit_Freq_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.u16CompSpeedDemande);
		Unicode::snprintf(textAreaBuffer_Dde_Vit_Rpm_Inv, 5, "%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.u16CompSpeedDemande * 60);
		textArea_inv_val_demande_vitesse.setWildcard1(textAreaBuffer_Dde_Vit_Freq_Inv);
		textArea_inv_val_demande_vitesse.setWildcard2(textAreaBuffer_Dde_Vit_Rpm_Inv);
		textArea_inv_val_demande_vitesse.invalidate();
		//Vitesse Inv
		Unicode::snprintf(textAreaBuffer_Vit_Freq_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorRunningSpeed);
		Unicode::snprintf(textAreaBuffer_Vit_Rpm_Inv, 5, "%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorRunningSpeed * 60);
		textArea_inv_val_vitesse_comp.setWildcard1(textAreaBuffer_Vit_Freq_Inv);
		textArea_inv_val_vitesse_comp.setWildcard2(textAreaBuffer_Vit_Rpm_Inv);
		textArea_inv_val_vitesse_comp.invalidate();
		//Vitesse stable Inv
		if (sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.bCompressorSpeedStable == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Vit_Stable_Inv, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Vit_Stable_Inv, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		textArea_inv_val_vitesse_comp_stable.setWildcard(textAreaBuffer_Vit_Stable_Inv);
		textArea_inv_val_vitesse_comp_stable.invalidate();
		//Pos EEV EV Inv
		Unicode::snprintf(textAreaBuffer_Pos_EEV_EV_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u16PositionDetendeur1);
		textArea_inv_val_pos_eev_ev.setWildcard(textAreaBuffer_Pos_EEV_EV_Inv);
		textArea_inv_val_pos_eev_ev.invalidate();
		//Pos EEV CD Inv
		Unicode::snprintf(textAreaBuffer_Pos_EEV_CD_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u16PositionDetendeur2);
		textArea_inv_val_pos_eev_cd.setWildcard(textAreaBuffer_Pos_EEV_CD_Inv);
		textArea_inv_val_pos_eev_cd.invalidate();
		//Cons Circ Prim Inv
		Unicode::snprintf(textAreaBuffer_Cons_Circ_Prim_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire);
		textArea_inv_val_cons_circ_prim.setWildcard(textAreaBuffer_Cons_Circ_Prim_Inv);
		textArea_inv_val_cons_circ_prim.invalidate();
		//Gestion Circ Prim Inv
		Unicode::snprintf(textAreaBuffer_Cons_Circ_Prim_Inv, 4, "%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire);
		textArea_inv_val_cons_circ_prim.setWildcard(textAreaBuffer_Cons_Circ_Prim_Inv);
		textArea_inv_val_cons_circ_prim.invalidate();
		//Vitesse Pompe Puits Inv
		if (sConfig_IHM.sConfig_PAC.ConfigGeoInverter.u8ConsignePompePuitsMax != 0)
		{
			Unicode::snprintf(textAreaBuffer_Cons_Pompe_Puits_Inv,4, "%d", sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.u8ConsignePompePuits);
		}
		else  Unicode::snprintf(textAreaBuffer_Cons_Pompe_Puits_Inv, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		textArea_inv_val_vitesse_pompe_puits.setWildcard(textAreaBuffer_Cons_Pompe_Puits_Inv);
		textArea_inv_val_vitesse_pompe_puits.invalidate();
		//App 1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Appoint1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_App1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_App1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_appoint1.setWildcard(textAreaBuffer_App1_Inv);
		textArea_inv_val_out_tor_appoint1.invalidate();
		//App 23 Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Appoint2_3 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_App23_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_App23_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_appoint23.setWildcard(textAreaBuffer_App23_Inv);
		textArea_inv_val_out_tor_appoint23.invalidate();
		//Comp 1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Compresseur1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Comp1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Comp1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_comp1.setWildcard(textAreaBuffer_Comp1_Inv);
		textArea_inv_val_out_tor_comp1.invalidate();
		//Comp 2 Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Compresseur2 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Comp2_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Comp2_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_comp2.setWildcard(textAreaBuffer_Comp2_Inv);
		textArea_inv_val_out_tor_comp2.invalidate();
		//Pompe Puits Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.ContactPuit == 0)
		{
			 Unicode::snprintf(textAreaBuffer_PompePuits_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_PompePuits_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_contact_puits.setWildcard(textAreaBuffer_PompePuits_Inv);
		textArea_inv_val_out_tor_contact_puits.invalidate();
		//EV Froid Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.ElectrovanneFroid == 0)
		{
			 Unicode::snprintf(textAreaBuffer_EV_Froid_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_EV_Froid_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_ev_froid.setWildcard(textAreaBuffer_EV_Froid_Inv);
		textArea_inv_val_out_tor_ev_froid.invalidate();
		//Res Carter Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.ResistanceCarter == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Res_Carter_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Res_Carter_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_resist_carter.setWildcard(textAreaBuffer_Res_Carter_Inv);
		textArea_inv_val_out_tor_resist_carter.invalidate();
		//Res vase Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.ResistanceVase == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Res_Vase_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Res_Vase_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_resist_vase.setWildcard(textAreaBuffer_Res_Vase_Inv);
		textArea_inv_val_resist_vase.invalidate();
		//Spare 1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Spare1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Spare1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Spare1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_spare1.setWildcard(textAreaBuffer_Spare1_Inv);
		textArea_inv_val_out_tor_spare1.invalidate();
		//Spare 2 Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Spare2 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Spare2_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Spare2_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_spare2.setWildcard(textAreaBuffer_Spare2_Inv);
		textArea_inv_val_out_tor_spare2.invalidate();
		//V4V Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.V4V == 0)
		{
			 Unicode::snprintf(textAreaBuffer_V4V_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_V4V_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_v4v.setWildcard(textAreaBuffer_V4V_Inv);
		textArea_inv_val_out_tor_v4v.invalidate();
		//Ventil Driver Inv
		if (sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Ventilateur == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Ventil_Driver_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Ventil_Driver_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_out_tor_ventil_driver.setWildcard(textAreaBuffer_Ventil_Driver_Inv);
		textArea_inv_val_out_tor_ventil_driver.invalidate();
		//Debistat Puits Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InDebitPuit == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Debistat_Puits_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Debistat_Puits_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_debit_puits.setWildcard(textAreaBuffer_Debistat_Puits_Inv);
		textArea_inv_val_debit_puits.invalidate();
		//Défaut App1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InDefautAppoint1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautApp1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautApp1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_defaut_app1.setWildcard(textAreaBuffer_DefautApp1_Inv);
		textArea_inv_val_in_defaut_app1.invalidate();
		//Défaut App2 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InDefautAppoint2 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautApp2_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautApp2_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_defaut_app2.setWildcard(textAreaBuffer_DefautApp2_Inv);
		textArea_inv_val_in_defaut_app2.invalidate();
		//Défaut App3 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InDefautAppoint3 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautApp3_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautApp3_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_defaut_app3.setWildcard(textAreaBuffer_DefautApp3_Inv);
		textArea_inv_val_in_defaut_app3.invalidate();
		//Défaut Dem Pro 1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InDefautDemarreur1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautDemPro1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautDemPro1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_defaut_dempro1.setWildcard(textAreaBuffer_DefautDemPro1_Inv);
		textArea_inv_val_in_defaut_dempro1.invalidate();
		//Défaut Dem Pro 2 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InDefautDemarreur2 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautDemPro2_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautDemPro2_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_defaut_dempro2.setWildcard(textAreaBuffer_DefautDemPro2_Inv);
		textArea_inv_val_in_defaut_dempro2.invalidate();
		//Klixon Comp 1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InKlixonCompresseur == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautKlixon_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautKlixon_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_klixon_comp.setWildcard(textAreaBuffer_DefautKlixon_Inv);
		textArea_inv_val_in_klixon_comp.invalidate();
		//Pressostat HP1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InPressostatHP1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautHP1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautHP1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_secu_hp1.setWildcard(textAreaBuffer_DefautHP1_Inv);
		textArea_inv_val_in_secu_hp1.invalidate();
		//Pressostat HP2 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InPressostatHP2 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_DefautHP2_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_DefautHP2_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_secu_hp2.setWildcard(textAreaBuffer_DefautHP2_Inv);
		textArea_inv_val_in_secu_hp2.invalidate();
		//Switch 1 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW1 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Switch1_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Switch1_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_sw1.setWildcard(textAreaBuffer_Switch1_Inv);
		textArea_inv_val_in_sw1.invalidate();
		//Switch 2 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW2 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Switch2_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Switch2_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_sw2.setWildcard(textAreaBuffer_Switch2_Inv);
		textArea_inv_val_in_sw2.invalidate();
		//Switch 3 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW3 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Switch3_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Switch3_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_sw3.setWildcard(textAreaBuffer_Switch3_Inv);
		textArea_inv_val_in_sw3.invalidate();
		//Switch 4 Inv
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW4 == 0)
		{
			 Unicode::snprintf(textAreaBuffer_Switch4_Inv, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Switch4_Inv, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		textArea_inv_val_in_sw4.setWildcard(textAreaBuffer_Switch4_Inv);
		textArea_inv_val_in_sw4.invalidate();
		//Config Switch Inv
		uint8_t u8adresse;
		if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW1 == 0)
		{
			u8adresse = 1 + sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW4 +
					sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW3 * 2 +
					sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW2 * 4;

			Unicode::snprintf(textAreaBuffer_Config_Switch_Inv, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_INV_NORMAL_ADRESSE).getText());
			Unicode::snprintf(&textAreaBuffer_Config_Switch_Inv[Unicode::strlen(textAreaBuffer_Config_Switch_Inv)], 3,"%d)", u8adresse);
		}
		else
		{
			if (sCyclRegFrigo->pac.geoinverter.sInTorGeoinv.InSW2 == 0)
			{
				Unicode::snprintf(textAreaBuffer_Config_Switch_Inv, 30, touchgfx::TypedText(T_TEXT_VAR_SYS_INV_SECOURS_CHAUD).getText());
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_Config_Switch_Inv, 30, touchgfx::TypedText(T_TEXT_VAR_SYS_INV_SECOURS_FROID).getText());
			}
		}
		textArea_inv_val_config_switchs.setWildcard(textAreaBuffer_Config_Switch_Inv);
		textArea_inv_val_config_switchs.invalidate();
	}
	//Zuran / Baguio / Timax
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV || sConfig_IHM.sModele_PAC.u8ModelePAC == TIMAX_III)
	{
		switch (sConfig_IHM.sModele_PAC.u3SousTypePAC)
		{
			case SOUS_TYPE_BAGUIO_PP:
				//Baguio PP Tension DC == 0
				if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Tension_DC == 0)
				{
					//Statut PAC
					switch(sCyclRegFrigo->pac.zuba.sStatutMitsu.Statut & 0x00F0)
					{
						case 0x00:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_ARRET_ZUBA).getText());
							break;
						case 0x10:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_RAF_ZUBA).getText());
							break;
						case 0x20:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_DEFROST_ZUBA).getText());
							break;
						case 0x30:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_ZUBA).getText());
							break;
						default:
							break;
					}
					textArea_zuba_val_statut_pac.setWildcard(textAreaBuffer_Statut_ZuBa);
					textArea_zuba_val_statut_pac.invalidate();
					//Fréquence cible
					Unicode::snprintf(textAreaBuffer_FreqCible_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Cible);
					textArea_zuba_val_freq_cible.setWildcard(textAreaBuffer_FreqCible_ZuBa);
					textArea_zuba_val_freq_cible.invalidate();
					//Type/Capacité PAC
					Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 21, "SUZ-S(H)WM40/75 - 1~");
					textArea_zuba_val_type_capacite_pac.setWildcard(textAreaBuffer_TypeCapacitePac_ZuBa);
					textArea_zuba_val_type_capacite_pac.invalidate();
					//Dégivrage en cours
					if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Statut == 0x0030)
					{
						Unicode::snprintf(textAreaBuffer_DefrostPac_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_DefrostPac_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
					textArea_zuba_val_degivrage.setWildcard(textAreaBuffer_DefrostPac_ZuBa);
					textArea_zuba_val_degivrage.invalidate();
					//Nb dégivrage
					Unicode::snprintf(textAreaBuffer_NbDefrost_ZuBa, 6, "%d", sCyclRegFrigo->commun.u16NbDegivrage);
					textArea_zuba_val_nb_degivrage.setWildcard(textAreaBuffer_NbDefrost_ZuBa);
					textArea_zuba_val_nb_degivrage.invalidate();
					//Ventilateur
					if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1 == 1)
					{
						Unicode::snprintf(textAreaBuffer_Ventil_MA_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_Ventil_MA_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_ventilateur_on_off.setWildcard(textAreaBuffer_Ventil_MA_ZuBa);
					textArea_zuba_val_ventilateur_on_off.invalidate();
					//Départ Primaire Mitsu
					Unicode::snprintfFloat(textAreaBuffer_Dep_Prim_Mitsu, 8, "%.1f", ((float)sCyclRegFrigo->pac.zuba.sStatutMitsu.Autre) / 10);
					Unicode::snprintf(&textAreaBuffer_Dep_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Dep_Prim_Mitsu)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_Dep_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Dep_Prim_Mitsu)], 2,"C");
					textArea_zuba_val_dep_prim_mitsu.setWildcard(textAreaBuffer_Dep_Prim_Mitsu);
					textArea_zuba_val_dep_prim_mitsu.invalidate();
					//Consigne Primaire Mitsu
					Unicode::snprintf(textAreaBuffer_Cons_Prim_Mitsu, 3, "%d", sCyclRegFrigo->pac.zuba.sStatutFrigo.u8ConsigneEau_BaguioPP);
					Unicode::snprintf(&textAreaBuffer_Cons_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Cons_Prim_Mitsu)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_Cons_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Cons_Prim_Mitsu)], 2,"C");
					textArea_zuba_val_cons_dep_eau_mitsu.setWildcard(textAreaBuffer_Cons_Prim_Mitsu);
					textArea_zuba_val_cons_dep_eau_mitsu.invalidate();
					//Sortie TOR 1
					if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW1 == 1)
					{
						Unicode::snprintf(textAreaBuffer_OutTor1_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_OutTor1_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_sortie_tor1.setWildcard(textAreaBuffer_OutTor1_ZuBa);
					textArea_zuba_val_sortie_tor1.invalidate();
					//Sortie TOR 2
					if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW2 == 1)
					{
						Unicode::snprintf(textAreaBuffer_OutTor2_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_OutTor2_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_sortie_tor2.setWildcard(textAreaBuffer_OutTor2_ZuBa);
					textArea_zuba_val_sortie_tor2.invalidate();
					//Sortie TOR 3
					if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW3 == 1)
					{
						Unicode::snprintf(textAreaBuffer_OutTor3_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_OutTor3_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_sortie_tor3.setWildcard(textAreaBuffer_OutTor3_ZuBa);
					textArea_zuba_val_sortie_tor3.invalidate();
					//Trame connue
					if (sCyclRegFrigo->pac.zuba.sInfoTrame.bTrameConnue == 1)
					{
						Unicode::snprintf(textAreaBuffer_TrameConnue_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_TrameConnue_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
					textArea_zuba_val_trame_connue.setWildcard(textAreaBuffer_TrameConnue_ZuBa);
					textArea_zuba_val_trame_connue.invalidate();
					//Code trame inconnue
					Unicode::snprintf(textAreaBuffer_CodeTrameInconnue_ZuBa, 6, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.u8CodeTrameInconnu);
					textArea_zuba_val_code_trame_inconnue.setWildcard(textAreaBuffer_CodeTrameInconnue_ZuBa);
					textArea_zuba_val_code_trame_inconnue.invalidate();
					//Nb trame inconnue
					Unicode::snprintf(textAreaBuffer_NbTrameInconnue_ZuBa, 6, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.u16nombretrameInconnue);
					textArea_zuba_val_nb_trame_inconnue.setWildcard(textAreaBuffer_NbTrameInconnue_ZuBa);
					textArea_zuba_val_nb_trame_inconnue.invalidate();
					//Code erreur
					Unicode::snprintf(textAreaBuffer_CodeErreur_ZuBa, 11, "%d", ((sCyclRegFrigo->pac.zuba.sInfoTrame.u32CodeErreurMitsu >> 8) & 0xffff));
					textArea_zuba_val_code_erreur_pac.setWildcard(textAreaBuffer_CodeErreur_ZuBa);
					textArea_zuba_val_code_erreur_pac.invalidate();
				}//Fin Baguio PP Tension DC == 0
				else //Baguio PP Tension DC != 0
				{
					//Statut PAC
					switch(sCyclRegFrigo->pac.zuba.sStatutMitsu.Statut & 0x00F0)
					{
						case 0x00:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_ARRET_ZUBA).getText());
							break;
						case 0x10:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_RAF_ZUBA).getText());
							break;
						case 0x20:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_DEFROST_ZUBA).getText());
							break;
						case 0x30:
							Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_ZUBA).getText());
							break;
						default:
							break;
					}
					textArea_zuba_val_statut_pac_1.setWildcard(textAreaBuffer_Statut_ZuBa);
					textArea_zuba_val_statut_pac_1.invalidate();
					//Fréquence cible
					Unicode::snprintf(textAreaBuffer_FreqCible_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Cible);
					textArea_zuba_val_freq_cible_actu_1.setWildcard1(textAreaBuffer_FreqCible_ZuBa);
					textArea_zuba_val_freq_cible_actu_1.invalidate();
					//Fréquence actuelle
					Unicode::snprintf(textAreaBuffer_FreqActu_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Compresseur);
					textArea_zuba_val_freq_cible_actu_1.setWildcard2(textAreaBuffer_FreqActu_ZuBa);
					textArea_zuba_val_freq_cible_actu_1.invalidate();
					//Type/Capacité PAC
					Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 21, "SUZ-S(H)WM40/75 - 1~");
					textArea_zuba_val_type_capacite_pac_1.setWildcard(textAreaBuffer_TypeCapacitePac_ZuBa);
					textArea_zuba_val_type_capacite_pac_1.invalidate();
					//Tps fonctionnement Compresseur
					Unicode::snprintf(textAreaBuffer_TempsFctComp_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Temps_Compresseur *10));
					textArea_zuba_val_tps_fct_comp_1.setWildcard(textAreaBuffer_TempsFctComp_ZuBa);
					textArea_zuba_val_tps_fct_comp_1.invalidate();
					//Nb cycles Compresseur
					Unicode::snprintf(textAreaBuffer_NbCycleComp_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Nb_Cycle_Compresseur));
					textArea_zuba_val_nb_cycle_comp_1.setWildcard(textAreaBuffer_NbCycleComp_ZuBa);
					textArea_zuba_val_nb_cycle_comp_1.invalidate();
					//Tension DC
					Unicode::snprintf(textAreaBuffer_TensionDC_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Tension_DC));
					textArea_zuba_val_tension_dc_1.setWildcard(textAreaBuffer_TensionDC_ZuBa);
					textArea_zuba_val_tension_dc_1.invalidate();
					//Courant
					Unicode::snprintf(textAreaBuffer_CourantAC_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Intensite_Primaire);
					textArea_zuba_val_courant_ac_1.setWildcard(textAreaBuffer_CourantAC_ZuBa);
					textArea_zuba_val_courant_ac_1.invalidate();
					//Temp Cond
					if (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS != oldTempHP)
					{
						//Temp Cond
						Unicode::snprintf(textAreaBuffer_TempCond_ZuBa, 8, "%d", (float)sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
						Unicode::snprintf(&textAreaBuffer_TempCond_ZuBa[Unicode::strlen(textAreaBuffer_TempCond_ZuBa)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_TempCond_ZuBa[Unicode::strlen(textAreaBuffer_TempCond_ZuBa)], 2,"C");
						textArea_zuba_val_temp_cond_pression_1.setWildcard1(textAreaBuffer_TempCond_ZuBa);
						textArea_zuba_val_temp_cond_pression_1.invalidate();
						//Pression Cond

						valtemp = ConvertTemperatureToPression(GAZ_R32, (int16_t)sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);

						if (valtemp != 0)
						{
							Unicode::snprintfFloat(textAreaBuffer_Pression_ZuBa, 13, "%.1f", ((float)valtemp / 10));
							textArea_zuba_val_temp_cond_pression_1.setWildcard2(textAreaBuffer_Pression_ZuBa);
						}
						oldTempHP = sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS;
						textArea_zuba_val_temp_cond_pression_1.invalidate();
					}
					//Temp HP RT62
					Unicode::snprintf(textAreaBuffer_TempHP_ZuBa, 8, "%.1f", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement);
					Unicode::snprintf(&textAreaBuffer_TempHP_ZuBa[Unicode::strlen(textAreaBuffer_TempHP_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempHP_ZuBa[Unicode::strlen(textAreaBuffer_TempHP_ZuBa)], 2,"C");
					textArea_zuba_val_temp_refoul_comp.setWildcard(textAreaBuffer_TempHP_ZuBa);
					textArea_zuba_val_temp_refoul_comp.invalidate();
					//Temp evap RT61
					Unicode::snprintf(textAreaBuffer_TempEvapo_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3);
					Unicode::snprintf(&textAreaBuffer_TempEvapo_ZuBa[Unicode::strlen(textAreaBuffer_TempEvapo_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempEvapo_ZuBa[Unicode::strlen(textAreaBuffer_TempEvapo_ZuBa)], 2,"C");
					textArea_zuba_val_temp_in_evapo.setWildcard(textAreaBuffer_TempEvapo_ZuBa);
					textArea_zuba_val_temp_in_evapo.invalidate();
					//Temp radiateur driver
					Unicode::snprintf(textAreaBuffer_TempRadDriver_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_HeatSink);
					Unicode::snprintf(&textAreaBuffer_TempRadDriver_ZuBa[Unicode::strlen(textAreaBuffer_TempRadDriver_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempRadDriver_ZuBa[Unicode::strlen(textAreaBuffer_TempRadDriver_ZuBa)], 2,"C");
					textArea_zuba_val_temp_rad_driver.setWildcard(textAreaBuffer_TempRadDriver_ZuBa);
					textArea_zuba_val_temp_rad_driver.invalidate();
					//Temp liquide
					Unicode::snprintf(textAreaBuffer_TempLiquide_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS - sCyclRegFrigo->pac.zuba.sStatutFrigo.u8SousRefroidissement));
					Unicode::snprintf(&textAreaBuffer_TempLiquide_ZuBa[Unicode::strlen(textAreaBuffer_TempLiquide_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempLiquide_ZuBa[Unicode::strlen(textAreaBuffer_TempLiquide_ZuBa)], 2,"C");
					textArea_zuba_val_temp_liquide.setWildcard(textAreaBuffer_TempLiquide_ZuBa);
					textArea_zuba_val_temp_liquide.invalidate();
					//Surchauffe Refoulement
					Unicode::snprintf(textAreaBuffer_SurchauffeRef_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutFrigo.u8SurchauffeRefoulement);
					Unicode::snprintf(&textAreaBuffer_SurchauffeRef_ZuBa[Unicode::strlen(textAreaBuffer_SurchauffeRef_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_SurchauffeRef_ZuBa[Unicode::strlen(textAreaBuffer_SurchauffeRef_ZuBa)], 2,"C");
					textArea_zuba_val_surchauffe.setWildcard(textAreaBuffer_SurchauffeRef_ZuBa);
					textArea_zuba_val_surchauffe.invalidate();
					//Sous-refroidissement
					Unicode::snprintf(textAreaBuffer_SousRef_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutFrigo.u8SousRefroidissement);
					Unicode::snprintf(&textAreaBuffer_SousRef_ZuBa[Unicode::strlen(textAreaBuffer_SousRef_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_SousRef_ZuBa[Unicode::strlen(textAreaBuffer_SousRef_ZuBa)], 2,"C");
					textArea_zuba_val_sous_refr_1.setWildcard(textAreaBuffer_SousRef_ZuBa);
					textArea_zuba_val_sous_refr_1.invalidate();
					//Détendeur
					Unicode::snprintf(textAreaBuffer_Detendeur_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA);
					textArea_zuba_val_detendeur_1.setWildcard(textAreaBuffer_Detendeur_ZuBa);
					textArea_zuba_val_detendeur_1.invalidate();
					//Dégivrage en cours
					if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Statut == 0x0030)
					{
						Unicode::snprintf(textAreaBuffer_DefrostPac_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_DefrostPac_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
					textArea_zuba_val_degivrage_1.setWildcard(textAreaBuffer_DefrostPac_ZuBa);
					textArea_zuba_val_degivrage_1.invalidate();
					//Nb dégivrage
					Unicode::snprintf(textAreaBuffer_NbDefrost_ZuBa, 6, "%d", sCyclRegFrigo->commun.u16NbDegivrage);
					textArea_zuba_val_nb_degivrage_1.setWildcard(textAreaBuffer_NbDefrost_ZuBa);
					textArea_zuba_val_nb_degivrage_1.invalidate();
					//Ventilateur
					Unicode::snprintf(textAreaBuffer_VitVentil1_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
					textArea_zuba_val_ventilateur_1.setWildcard(textAreaBuffer_VitVentil1_ZuBa);
					textArea_zuba_val_ventilateur_1.invalidate();
					//Départ Primaire Mitsu
					Unicode::snprintfFloat(textAreaBuffer_Dep_Prim_Mitsu, 8, "%.1f", ((float)sCyclRegFrigo->pac.zuba.sStatutMitsu.Autre) / 10);
					Unicode::snprintf(&textAreaBuffer_Dep_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Dep_Prim_Mitsu)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_Dep_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Dep_Prim_Mitsu)], 2,"C");
					textArea_zuba_val_dep_prim_mitsu_1.setWildcard(textAreaBuffer_Dep_Prim_Mitsu);
					textArea_zuba_val_dep_prim_mitsu_1.invalidate();
					//Consigne Primaire Mitsu
					Unicode::snprintf(textAreaBuffer_Cons_Prim_Mitsu, 3, "%d", sCyclRegFrigo->pac.zuba.sStatutFrigo.u8ConsigneEau_BaguioPP);
					Unicode::snprintf(&textAreaBuffer_Cons_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Cons_Prim_Mitsu)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_Cons_Prim_Mitsu[Unicode::strlen(textAreaBuffer_Cons_Prim_Mitsu)], 2,"C");
					textArea_zuba_val_cons_dep_eau_mitsu_1.setWildcard(textAreaBuffer_Cons_Prim_Mitsu);
					textArea_zuba_val_cons_dep_eau_mitsu_1.invalidate();
					//Sortie TOR 1
					if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW1 == 1)
					{
						Unicode::snprintf(textAreaBuffer_OutTor1_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_OutTor1_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_sortie_tor1_1.setWildcard(textAreaBuffer_OutTor1_ZuBa);
					textArea_zuba_val_sortie_tor1_1.invalidate();
					//Sortie TOR 2
					if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW2 == 1)
					{
						Unicode::snprintf(textAreaBuffer_OutTor2_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_OutTor2_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_sortie_tor2_1.setWildcard(textAreaBuffer_OutTor2_ZuBa);
					textArea_zuba_val_sortie_tor2_1.invalidate();
					//Sortie TOR 3
					if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW3 == 1)
					{
						Unicode::snprintf(textAreaBuffer_OutTor3_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_OutTor3_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_zuba_val_sortie_tor3_1.setWildcard(textAreaBuffer_OutTor3_ZuBa);
					textArea_zuba_val_sortie_tor3_1.invalidate();
					//Trame connue
					if (sCyclRegFrigo->pac.zuba.sInfoTrame.bTrameConnue == 1)
					{
						Unicode::snprintf(textAreaBuffer_TrameConnue_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
					}
					else Unicode::snprintf(textAreaBuffer_TrameConnue_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
					textArea_zuba_val_trame_connue_1.setWildcard(textAreaBuffer_TrameConnue_ZuBa);
					textArea_zuba_val_trame_connue_1.invalidate();
					//Code trame inconnue
					Unicode::snprintf(textAreaBuffer_CodeTrameInconnue_ZuBa, 6, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.u8CodeTrameInconnu);
					textArea_zuba_val_code_trame_inconnue.setWildcard(textAreaBuffer_CodeTrameInconnue_ZuBa);
					textArea_zuba_val_code_trame_inconnue.invalidate();
					//Nb trame inconnue
					Unicode::snprintf(textAreaBuffer_NbTrameInconnue_ZuBa, 6, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.u16nombretrameInconnue);
					textArea_zuba_val_nb_trame_inconnue_1.setWildcard(textAreaBuffer_NbTrameInconnue_ZuBa);
					textArea_zuba_val_nb_trame_inconnue_1.invalidate();
					//Code erreur
					Unicode::snprintf(textAreaBuffer_CodeErreur_ZuBa, 11, "%d", ((sCyclRegFrigo->pac.zuba.sInfoTrame.u32CodeErreurMitsu >> 8) & 0xffff));
					textArea_zuba_val_code_erreur_pac_1.setWildcard(textAreaBuffer_CodeErreur_ZuBa);
					textArea_zuba_val_code_erreur_pac_1.invalidate();
				}//Fin Baguio PP Tension DC != 0
				break;
			default:
				//Statut PAC
				switch(sCyclRegFrigo->pac.zuba.sStatutMitsu.Statut & 0x00F0)
				{
					case 0x00:
						Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_ARRET_ZUBA).getText());
						break;
					case 0x10:
						Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_RAF_ZUBA).getText());
						break;
					case 0x20:
						Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_DEFROST_ZUBA).getText());
						break;
					case 0x30:
						Unicode::snprintf(textAreaBuffer_Statut_ZuBa, 17, touchgfx::TypedText(T_TEXT_VAR_SYS_CHAUD_ZUBA).getText());
						break;
					default:
						break;
				}
				textArea_zuba_val_statut_pac_2.setWildcard(textAreaBuffer_Statut_ZuBa);
				textArea_zuba_val_statut_pac_2.invalidate();
				//Fréquence cible
				Unicode::snprintf(textAreaBuffer_FreqCible_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Cible);
				textArea_zuba_val_freq_cible_actu_2.setWildcard1(textAreaBuffer_FreqCible_ZuBa);
				textArea_zuba_val_freq_cible_actu_2.invalidate();
				//Fréquence actuelle
				Unicode::snprintf(textAreaBuffer_FreqActu_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Compresseur);
				textArea_zuba_val_freq_cible_actu_2.setWildcard2(textAreaBuffer_FreqActu_ZuBa);
				textArea_zuba_val_freq_cible_actu_2.invalidate();
				//Type/Capacité PAC
				if (sConfig_IHM.sModele_PAC.u8ModelePAC == TIMAX_III)
				{
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO)
					{
						switch (sCyclRegFrigo->pac.zuba.sStatutMitsu.Capacite)
						{
							case 10:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-W50");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-WM50");
								break;
							case 11:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-WM60");
								break;
							case 14:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-W85");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-WM85");
								break;
							case 20:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-W112");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-WM112");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
								break;
						}
					}
					else
					{
						switch (sCyclRegFrigo->pac.zuba.sStatutMitsu.Capacite)
						{
							case 20:
								 Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-HW112");
								break;
							case 25:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-HW140");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-HWM140");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
								break;
						}
					}
				}
				else //Autres que Timax
				{
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO)
					{
						switch (sCyclRegFrigo->pac.zuba.sStatutMitsu.Capacite)
						{
							case 2:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW45");
								break;
							case 9:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "RP35");
								break;
							case 10:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW50");
								break;
							case 11:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "RP60");
								break;
							case 14:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW75");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SWM80");
								break;
							case 20:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW100");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SWM100");
								break;
							case 25:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW120");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SWM120");
								break;
							case 28:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "RP140");
								break;
							case 40:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW160");
								break;
							case 50:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SW200");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
								break;
						}
					}
					else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN)
					{
						switch (sCyclRegFrigo->pac.zuba.sStatutMitsu.Capacite)
						{
							case 14:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SHW80");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SHWM80");
								break;
							case 20:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SHW112");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SHWM100");
								break;
							case 25:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SHW140");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SHWM120");
								break;
							case 28:
								if (sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "140");
								}
								else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SHWM140");
								break;
							case 40:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUHZ-SHW230");
								break;
							case 50:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "250");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
								break;
						}
					}
					else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PUZ)
					{
						switch (sCyclRegFrigo->pac.zuba.sStatutMitsu.Capacite)
						{
							case 14:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-SWM80");
								break;
							case 20:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-SWM100");
								break;
							case 25:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SWM120");
								break;
							case 28:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SWM140");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
								break;
						}
					}
					else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN_PUZ)
					{
						switch (sCyclRegFrigo->pac.zuba.sStatutMitsu.Capacite)
						{
							case 14:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-SHWM80");
								break;
							case 20:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUZ-SHWM100");
								break;
							case 25:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SHWM120");
								break;
							case 28:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 12, "PUD-SHWM140");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
								break;
						}
					}
					else Unicode::snprintf(textAreaBuffer_TypeCapacitePac_ZuBa, 4, "xxx");
				}
				if ((sCyclRegFrigo->pac.zuba.sStatutMitsu.Type & 0xF0) > 0x10)
				{
					Unicode::snprintf(&textAreaBuffer_TypeCapacitePac_ZuBa[Unicode::strlen(textAreaBuffer_TypeCapacitePac_ZuBa)], 7," - 3 ~");
				}
				else Unicode::snprintf(&textAreaBuffer_TypeCapacitePac_ZuBa[Unicode::strlen(textAreaBuffer_TypeCapacitePac_ZuBa)], 7," - 1 ~");
				textArea_zuba_val_type_capacite_pac_2.setWildcard(textAreaBuffer_TypeCapacitePac_ZuBa);
				textArea_zuba_val_type_capacite_pac_2.invalidate();
				//Tps fonctionnement Compresseur
				Unicode::snprintf(textAreaBuffer_TempsFctComp_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Temps_Compresseur *10));
				textArea_zuba_val_tps_fct_comp_2.setWildcard(textAreaBuffer_TempsFctComp_ZuBa);
				textArea_zuba_val_tps_fct_comp_2.invalidate();
				//Nb cycles Compresseur
				Unicode::snprintf(textAreaBuffer_NbCycleComp_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Nb_Cycle_Compresseur));
				textArea_zuba_val_nb_cycle_comp_2.setWildcard(textAreaBuffer_NbCycleComp_ZuBa);
				textArea_zuba_val_nb_cycle_comp_2.invalidate();
				//Tension DC
				Unicode::snprintf(textAreaBuffer_TensionDC_ZuBa, 8, "%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Tension_DC));
				textArea_zuba_val_tension_dc_2.setWildcard(textAreaBuffer_TensionDC_ZuBa);
				textArea_zuba_val_tension_dc_2.invalidate();
				//Courant
				Unicode::snprintf(textAreaBuffer_CourantAC_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Intensite_Primaire);
				textArea_zuba_val_courant_ac_2.setWildcard(textAreaBuffer_CourantAC_ZuBa);
				textArea_zuba_val_courant_ac_2.invalidate();
				//Temp Cond
				if (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS != oldTempHP)
				{
					//Temp Cond
					Unicode::snprintf(textAreaBuffer_TempCond_ZuBa, 8, "%d", (float)sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
					Unicode::snprintf(&textAreaBuffer_TempCond_ZuBa[Unicode::strlen(textAreaBuffer_TempCond_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempCond_ZuBa[Unicode::strlen(textAreaBuffer_TempCond_ZuBa)], 2,"C");
					textArea_zuba_val_temp_cond_pression_2.setWildcard1(textAreaBuffer_TempCond_ZuBa);
					//Pression Cond
					switch (sConfig_IHM.sModele_PAC.Gaz_C1)
					{
						case GAZ_R410:
							valtemp = ConvertTemperatureToPression(GAZ_R410, (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS * 10));
						break;

						case GAZ_R32:
							valtemp = ConvertTemperatureToPression(GAZ_R32, sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
							break;

						default:
							valtemp = 0;
							break;
					}
					Unicode::snprintfFloat(textAreaBuffer_Pression_ZuBa, 13, "%.1f", ((float)valtemp) / 10);
					textArea_zuba_val_temp_cond_pression_2.setWildcard2(textAreaBuffer_Pression_ZuBa);

					oldTempHP = sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS;
					textArea_zuba_val_temp_cond_pression_2.invalidate();
				}
				//Temp HP TH4
				Unicode::snprintf(textAreaBuffer_TempHP_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement);
				Unicode::snprintf(&textAreaBuffer_TempHP_ZuBa[Unicode::strlen(textAreaBuffer_TempHP_ZuBa)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_TempHP_ZuBa[Unicode::strlen(textAreaBuffer_TempHP_ZuBa)], 2,"C");
				textArea_zuba_val_temp_refoul_comp_2.setWildcard(textAreaBuffer_TempHP_ZuBa);
				textArea_zuba_val_temp_refoul_comp_2.invalidate();
				//Temp evap TH6
				Unicode::snprintf(textAreaBuffer_TempEvapo_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6);
				Unicode::snprintf(&textAreaBuffer_TempEvapo_ZuBa[Unicode::strlen(textAreaBuffer_TempEvapo_ZuBa)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_TempEvapo_ZuBa[Unicode::strlen(textAreaBuffer_TempEvapo_ZuBa)], 2,"C");
				textArea_zuba_val_temp_evapo.setWildcard(textAreaBuffer_TempEvapo_ZuBa);
				textArea_zuba_val_temp_evapo.invalidate();
				//Temp in evap TH3
				if (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3 < 250)
				{
					Unicode::snprintf(textAreaBuffer_TempInEvapo_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3);
					Unicode::snprintf(&textAreaBuffer_TempInEvapo_ZuBa[Unicode::strlen(textAreaBuffer_TempInEvapo_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempInEvapo_ZuBa[Unicode::strlen(textAreaBuffer_TempInEvapo_ZuBa)], 2,"C");
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TempInEvapo_ZuBa, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				textArea_zuba_val_temp_entree_evapo_2.setWildcard(textAreaBuffer_TempInEvapo_ZuBa);
				textArea_zuba_val_temp_entree_evapo_2.invalidate();
				//Temp aspiration
				if (sConfig_IHM.sModele_PAC.u8ModelePAC != TIMAX_III)
				{
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO)
					{
						Unicode::snprintf(textAreaBuffer_TempAspi_ZuBa, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_TempAspi_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Aspiration);
						Unicode::snprintf(&textAreaBuffer_TempAspi_ZuBa[Unicode::strlen(textAreaBuffer_TempAspi_ZuBa)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_TempAspi_ZuBa[Unicode::strlen(textAreaBuffer_TempAspi_ZuBa)], 2,"C");
					}
				}
				else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN)
				{
					Unicode::snprintf(textAreaBuffer_TempAspi_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Aspiration);
					Unicode::snprintf(&textAreaBuffer_TempAspi_ZuBa[Unicode::strlen(textAreaBuffer_TempAspi_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempAspi_ZuBa[Unicode::strlen(textAreaBuffer_TempAspi_ZuBa)], 2,"C");
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TempAspi_ZuBa, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
				}
				textArea_zuba_val_temp_aspi_comp_2.setWildcard(textAreaBuffer_TempAspi_ZuBa);
				textArea_zuba_val_temp_aspi_comp_2.invalidate();
				//Temp liquide
				if (sConfig_IHM.sModele_PAC.u8ModelePAC != TIMAX_III)
				{
					if (sCyclRegFrigo->pac.zuba.sInAnaFrigo.i16Temp_S1 != 32766)
					{
						Unicode::snprintfFloat(textAreaBuffer_TempLiquide_ZuBa, 8, "%.1f", ((float)sCyclRegFrigo->pac.zuba.sInAnaFrigo.i16Temp_S1 / 10));
						Unicode::snprintf(&textAreaBuffer_TempLiquide_ZuBa[Unicode::strlen(textAreaBuffer_TempLiquide_ZuBa)], 2,"%s", degre);
						Unicode::snprintf(&textAreaBuffer_TempLiquide_ZuBa[Unicode::strlen(textAreaBuffer_TempLiquide_ZuBa)], 2,"C");
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_TempLiquide_ZuBa, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
					}
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_TempLiquide_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Liquide2);
					Unicode::snprintf(&textAreaBuffer_TempLiquide_ZuBa[Unicode::strlen(textAreaBuffer_TempLiquide_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_TempLiquide_ZuBa[Unicode::strlen(textAreaBuffer_TempLiquide_ZuBa)], 2,"C");
				}
				textArea_zuba_val_temp_liquide_2.setWildcard(textAreaBuffer_TempLiquide_ZuBa);
				textArea_zuba_val_temp_liquide_2.invalidate();
				//Surchauffe Refoulement
				if (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3 > 250)
				{
					Unicode::snprintfFloat(textAreaBuffer_SurchauffeRef_ZuBa, 8, "%.1f", ((float)(sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement - sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS*10) / 10));
					Unicode::snprintf(&textAreaBuffer_SurchauffeRef_ZuBa[Unicode::strlen(textAreaBuffer_SurchauffeRef_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_SurchauffeRef_ZuBa[Unicode::strlen(textAreaBuffer_SurchauffeRef_ZuBa)], 2,"C");
				}
				else
				{
					Unicode::snprintf(textAreaBuffer_SurchauffeRef_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutFrigo.u8SurchauffeRefoulement);
					Unicode::snprintf(&textAreaBuffer_SurchauffeRef_ZuBa[Unicode::strlen(textAreaBuffer_SurchauffeRef_ZuBa)], 2,"%s", degre);
					Unicode::snprintf(&textAreaBuffer_SurchauffeRef_ZuBa[Unicode::strlen(textAreaBuffer_SurchauffeRef_ZuBa)], 2,"C");
				}
				textArea_zuba_val_surchauffe_2.setWildcard(textAreaBuffer_SurchauffeRef_ZuBa);
				textArea_zuba_val_surchauffe_2.invalidate();
				//Sous-refroidissement
				Unicode::snprintf(textAreaBuffer_SousRef_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutFrigo.u8SousRefroidissement);
				Unicode::snprintf(&textAreaBuffer_SousRef_ZuBa[Unicode::strlen(textAreaBuffer_SousRef_ZuBa)], 2,"%s", degre);
				Unicode::snprintf(&textAreaBuffer_SousRef_ZuBa[Unicode::strlen(textAreaBuffer_SousRef_ZuBa)], 2,"C");
				textArea_zuba_val_sous_refr_2.setWildcard(textAreaBuffer_SousRef_ZuBa);
				textArea_zuba_val_sous_refr_2.invalidate();
				//Détendeur A
				Unicode::snprintf(textAreaBuffer_DetendeurA_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA);
				textArea_zuba_val_detendeur_A_2.setWildcard(textAreaBuffer_DetendeurA_ZuBa);
				textArea_zuba_val_detendeur_A_2.invalidate();
				//Détendeur B
				Unicode::snprintf(textAreaBuffer_DetendeurB_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVB);
				textArea_zuba_val_detendeur_B_2.setWildcard(textAreaBuffer_DetendeurB_ZuBa);
				textArea_zuba_val_detendeur_B_2.invalidate();
				//Détendeur C
				Unicode::snprintf(textAreaBuffer_DetendeurC_ZuBa, 4, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVC);
				textArea_zuba_val_detendeur_C_2.setWildcard(textAreaBuffer_DetendeurC_ZuBa);
				textArea_zuba_val_detendeur_C_2.invalidate();
				//Dégivrage en cours
				if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Statut == 0x0030)
				{
					Unicode::snprintf(textAreaBuffer_DefrostPac_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
				}
				else Unicode::snprintf(textAreaBuffer_DefrostPac_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
				textArea_zuba_val_degivrage_2.setWildcard(textAreaBuffer_DefrostPac_ZuBa);
				textArea_zuba_val_degivrage_2.invalidate();
				//Nb dégivrage
				Unicode::snprintf(textAreaBuffer_NbDefrost_ZuBa, 6, "%d", sCyclRegFrigo->commun.u16NbDegivrage);
				textArea_zuba_val_nb_degivrage_2.setWildcard(textAreaBuffer_NbDefrost_ZuBa);
				textArea_zuba_val_nb_degivrage_2.invalidate();
				//Ventilateur1
				Unicode::snprintf(textAreaBuffer_VitVentil1_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
				textArea_zuba_val_ventilateur_1_2.setWildcard(textAreaBuffer_VitVentil1_ZuBa);
				textArea_zuba_val_ventilateur_1_2.invalidate();
				//Ventilateur2
				Unicode::snprintf(textAreaBuffer_VitVentil2_ZuBa, 8, "%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur2);
				textArea_zuba_val_ventilateur_2_2.setWildcard(textAreaBuffer_VitVentil2_ZuBa);
				textArea_zuba_val_ventilateur_2_2.invalidate();
				//Sortie TOR 1
				if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW1 == 1)
				{
					Unicode::snprintf(textAreaBuffer_OutTor1_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
				}
				else Unicode::snprintf(textAreaBuffer_OutTor1_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
				textArea_zuba_val_sortie_tor1_2.setWildcard(textAreaBuffer_OutTor1_ZuBa);
				textArea_zuba_val_sortie_tor1_2.invalidate();
				//Sortie TOR 2
				if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW2 == 1)
				{
					Unicode::snprintf(textAreaBuffer_OutTor2_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
				}
				else Unicode::snprintf(textAreaBuffer_OutTor2_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
				textArea_zuba_val_sortie_tor2_2.setWildcard(textAreaBuffer_OutTor2_ZuBa);
				textArea_zuba_val_sortie_tor2_2.invalidate();
				//Sortie TOR 3
				if (sCyclRegFrigo->pac.zuba.sOutTorFrigo.Pac_PW3 == 1)
				{
					Unicode::snprintf(textAreaBuffer_OutTor3_ZuBa, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
				}
				else Unicode::snprintf(textAreaBuffer_OutTor3_ZuBa, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
				textArea_zuba_val_sortie_tor3_2.setWildcard(textAreaBuffer_OutTor3_ZuBa);
				textArea_zuba_val_sortie_tor3_2.invalidate();
				//Trame connue
				if (sCyclRegFrigo->pac.zuba.sInfoTrame.bTrameConnue == 1)
				{
					Unicode::snprintf(textAreaBuffer_TrameConnue_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
				}
				else Unicode::snprintf(textAreaBuffer_TrameConnue_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
				textArea_zuba_val_trame_connue_2.setWildcard(textAreaBuffer_TrameConnue_ZuBa);
				textArea_zuba_val_trame_connue_2.invalidate();
				//Code trame inconnue
				Unicode::snprintf(textAreaBuffer_CodeTrameInconnue_ZuBa, 6, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.u8CodeTrameInconnu);
				textArea_zuba_val_code_trame_inconnue_2.setWildcard(textAreaBuffer_CodeTrameInconnue_ZuBa);
				textArea_zuba_val_code_trame_inconnue_2.invalidate();
				//Nb trame inconnue
				Unicode::snprintf(textAreaBuffer_NbTrameInconnue_ZuBa, 6, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.u16nombretrameInconnue);
				textArea_zuba_val_nb_trame_inconnue_2.setWildcard(textAreaBuffer_NbTrameInconnue_ZuBa);
				textArea_zuba_val_nb_trame_inconnue_2.invalidate();
				//Accès mode commande
				if (sCyclRegFrigo->pac.zuba.sInfoTrame.bAcces_Com_SAV == 0)
				{
					Unicode::snprintf(textAreaBuffer_AccesModeCde_ZuBa, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
				}
				else Unicode::snprintf(textAreaBuffer_AccesModeCde_ZuBa, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
				textArea_zuba_val_acces_mode_cde.setWildcard(textAreaBuffer_AccesModeCde_ZuBa);
				textArea_zuba_val_acces_mode_cde.invalidate();
				//Code erreur
				Unicode::snprintf(textAreaBuffer_CodeErreur_ZuBa, 11, "%d", ((sCyclRegFrigo->pac.zuba.sInfoTrame.u32CodeErreurMitsu >> 8) & 0xffff));
				textArea_zuba_val_code_erreur_pac_2.setWildcard(textAreaBuffer_CodeErreur_ZuBa);
				textArea_zuba_val_code_erreur_pac_2.invalidate();
				break;
		}
	}
	//Geotwin
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		//Switch SW
		for (int i = 0; i<8; i++)
		{
			if (i == 0)
			{
				(sCyclRegFrigo->pac.geotwin.InSW.sw.SW1_SW2 >> i) == 1 ? Unicode::snprintf(textAreaBuffer_ConfigSw_Geot, 2, "1") :  Unicode::snprintf(textAreaBuffer_ConfigSw_Geot, 2, "0");
			}
			else
			{
				(sCyclRegFrigo->pac.geotwin.InSW.sw.SW1_SW2 >> i) == 1 ? Unicode::snprintf(&textAreaBuffer_ConfigSw_Geot[Unicode::strlen(textAreaBuffer_ConfigSw_Geot)], 2,"1") : Unicode::snprintf(&textAreaBuffer_ConfigSw_Geot[Unicode::strlen(textAreaBuffer_ConfigSw_Geot)], 2,"0");
			}
		}
		textArea_geo_val_config_switch.setWildcard(textAreaBuffer_ConfigSw_Geot);
		textArea_geo_val_config_switch.invalidate();
		//Vitesse pompe de puits
		if (sConfig_IHM.sConfig_PAC.ConfigGeo.u8ConsignePompePuitsMax != 0)
		{
			Unicode::snprintf(textAreaBuffer_Vitesse_Pompe_Puits_Geot,4, "%d", sCyclRegFrigo->pac.geotwin.u8ConsignePompePuits);
			Unicode::snprintf(&textAreaBuffer_Vitesse_Pompe_Puits_Geot[Unicode::strlen(textAreaBuffer_Vitesse_Pompe_Puits_Geot)], 2,"%");
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Vitesse_Pompe_Puits_Geot, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_geo_val_vitesse_puits.setWildcard(textAreaBuffer_Vitesse_Pompe_Puits_Geot);
		textArea_geo_val_vitesse_puits.invalidate();
		//PW Captée
		Unicode::snprintf(textAreaBuffer_PW_Captee_Geot,7, "%d", sCyclRegFrigo->pac.geotwin.InfoConsoPAc.u32PWInstCaptage);
		textArea_geo_val_pw_captee_inst.setWildcard(textAreaBuffer_PW_Captee_Geot);
		textArea_geo_val_pw_captee_inst.invalidate();
		//Statut PAC OK
		if( sCyclRegFrigo->pac.geotwin.sStatutFrigo.bMachineOK)
		{
			Unicode::snprintf(textAreaBuffer_PacOK_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_PacOK_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_statut_pac.setWildcard(textAreaBuffer_DemPro_Geot);
		textArea_geo_val_statut_pac.invalidate();
		//Cycle retour d'huile
		if( sCyclRegFrigo->pac.geotwin.sStatutFrigo.bCycleRetourHuile)
		{
			Unicode::snprintf(textAreaBuffer_CycleRetourHuile_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_CycleRetourHuile_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_cycle_retour_huile.setWildcard(textAreaBuffer_CycleRetourHuile_Geot);
		textArea_geo_val_cycle_retour_huile.invalidate();
		//Comp 1 OK
		if( sCyclRegFrigo->pac.geotwin.sStatutFrigo.bCompresseur_1_OK)
		{
			Unicode::snprintf(textAreaBuffer_Comp1_OK_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Comp1_OK_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_defaut_comp_1.setWildcard(textAreaBuffer_Comp1_OK_Geot);
		textArea_geo_val_defaut_comp_1.invalidate();
		//Comp 2 OK
		if (sConfig_IHM.sModele_PAC.nbCompresseur > 0)
		{
			if( sCyclRegFrigo->pac.geotwin.sStatutFrigo.bCompresseur_2_OK)
			{
				Unicode::snprintf(textAreaBuffer_Comp2_OK_Geot, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_Comp2_OK_Geot, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
			}
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Comp2_OK_Geot, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_geo_val_defaut_comp_2.setWildcard(textAreaBuffer_Comp2_OK_Geot);
		textArea_geo_val_defaut_comp_2.invalidate();
		//Statut Comp
		if(sCyclRegFrigo->pac.geotwin.OutTor.REL_Compresseur1)
		{
			Unicode::snprintf(textAreaBuffer_Statut_Comp1_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Statut_Comp1_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_statut_comp_1_2.setWildcard1(textAreaBuffer_Statut_Comp1_Geot);
		if (sConfig_IHM.sModele_PAC.nbCompresseur > 0)
		{
			if(sCyclRegFrigo->pac.geotwin.OutTor.REL_Compresseur2)
			{
				Unicode::snprintf(textAreaBuffer_Statut_Comp2_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_Statut_Comp2_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
			}
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Statut_Comp2_Geot, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_geo_val_statut_comp_1_2.setWildcard2(textAreaBuffer_Statut_Comp2_Geot);
		textArea_geo_val_statut_comp_1_2.invalidate();
		//Pression captage
		if (sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage != E_TYPE_CAPTAGE_NAPPE_DIRECTE)
		{
			Unicode::snprintfFloat(textAreaBuffer_Press_Capteur_Geot,4, "%.1f", ((float)sCyclRegFrigo->pac.geotwin.InPress.i16Pression_EauCaptage / 10));
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Press_Capteur_Geot, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_geo_val_pression_captage.setWildcard(textAreaBuffer_Press_Capteur_Geot);
		textArea_geo_val_pression_captage.invalidate();
		//Débit capteur
		Unicode::snprintf(textAreaBuffer_Debit_Capteur_Geot,6, "%d", sCyclRegFrigo->pac.geotwin.InAna.u16Debit_CAP);
		textArea_geo_val_debit_captage.setWildcard(textAreaBuffer_Debit_Capteur_Geot);
		textArea_geo_val_debit_captage.invalidate();
		//Temp Captage / Puits
		//Out
		Unicode::snprintfFloat(textAreaBuffer_Temp_Out_Capteur_Geot, 7, "%.1f", ((float) sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_CAP) / 10);
		textArea_geo_val_temp_captage_puits.setWildcard1(textAreaBuffer_Temp_Out_Capteur_Geot);
		//In
		Unicode::snprintfFloat(textAreaBuffer_Temp_In_Capteur_Geot, 7, "%.1f", ((float) sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_CAP) / 10);
		Unicode::snprintf(&textAreaBuffer_Temp_In_Capteur_Geot[Unicode::strlen(textAreaBuffer_Temp_In_Capteur_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_In_Capteur_Geot[Unicode::strlen(textAreaBuffer_Temp_In_Capteur_Geot)], 2,"C");
		textArea_geo_val_temp_captage_puits.setWildcard2(textAreaBuffer_Temp_In_Capteur_Geot);
		textArea_geo_val_temp_captage_puits.invalidate();
		//Pression HP / Temp Cond
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_HP_Geot, 7, "%.1f", ((float) sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazHP) / 10);
		textArea_geo_val_press_temp_hp.setWildcard1(textAreaBuffer_Press_HP_Geot);
		//Temp Cond
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond_Geot, 7, "%.1f", ((float)ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, true, sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazHP)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_Cond_Geot[Unicode::strlen(textAreaBuffer_Temp_Cond_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond_Geot[Unicode::strlen(textAreaBuffer_Temp_Cond_Geot)], 2,"C");
		textArea_geo_val_press_temp_hp.setWildcard2(textAreaBuffer_Temp_Cond_Geot);
		textArea_geo_val_press_temp_hp.invalidate();
		//Pression BP / Temp Evap
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_BP_Geot, 7, "%.1f", ((float) sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazBP) / 10);
		textArea_geo_val_press_temp_bp.setWildcard1(textAreaBuffer_Press_BP_Geot);
		//Temp Evap
		Unicode::snprintfFloat(textAreaBuffer_Temp_Evap_Geot, 7, "%.1f", ((float)ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, false, sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazBP)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_Evap_Geot[Unicode::strlen(textAreaBuffer_Temp_Evap_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Evap_Geot[Unicode::strlen(textAreaBuffer_Temp_Evap_Geot)], 2,"C");
		textArea_geo_val_press_temp_bp.setWildcard2(textAreaBuffer_Temp_Evap_Geot);
		textArea_geo_val_press_temp_bp.invalidate();
		//Position détendeurs
		Unicode::snprintf(textAreaBuffer_Pos_EEVEV_Geot,4, "%d", sCyclRegFrigo->pac.geotwin.StatutEEV.u16Position_Pulse_EV);
		textArea_geo_val_pos_eev_spare.setWildcard1(textAreaBuffer_Pos_EEVEV_Geot);
		Unicode::snprintf(textAreaBuffer_Pos_EEVSP_Geot,4, "%d", sCyclRegFrigo->pac.geotwin.StatutEEV.u16Position_Pulse_SP);
		textArea_geo_val_pos_eev_spare.setWildcard2(textAreaBuffer_Pos_EEVSP_Geot);
		textArea_geo_val_pos_eev_spare.invalidate();
		//Coef Poly / Cible
		Unicode::snprintfFloat(textAreaBuffer_Coef_Poly_Geot, 7, "%.4f", ((float) sCyclRegFrigo->pac.geotwin.StatutEEV.u16Coef_Poly) / 10000);
		textArea_geo_val_coef_poly_cible.setWildcard1(textAreaBuffer_Coef_Poly_Geot);
		Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_Geot, 3, "%d", sCyclRegFrigo->pac.geotwin.StatutEEV.i16Temp_HP_Cible);
		textArea_geo_val_coef_poly_cible.setWildcard2(textAreaBuffer_Temp_HP_Cible_Geot);
		textArea_geo_val_coef_poly_cible.invalidate();
		//Temp HP1
		Unicode::snprintfFloat(textAreaBuffer_Temp_HP1_Geot, 7, "%.1f", ((float)sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP1)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_HP1_Geot[Unicode::strlen(textAreaBuffer_Temp_HP1_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_HP1_Geot[Unicode::strlen(textAreaBuffer_Temp_HP1_Geot)], 2,"C");
		textArea_geo_val_temp_hp1.setWildcard1(textAreaBuffer_Temp_HP1_Geot);
		textArea_geo_val_temp_hp1.invalidate();
		//Temp HP2
		Unicode::snprintfFloat(textAreaBuffer_Temp_HP2_Geot, 7, "%.1f", ((float)sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP2)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_HP2_Geot[Unicode::strlen(textAreaBuffer_Temp_HP2_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_HP2_Geot[Unicode::strlen(textAreaBuffer_Temp_HP2_Geot)], 2,"C");
		textArea_geo_val_temp_hp2.setWildcard1(textAreaBuffer_Temp_HP2_Geot);
		textArea_geo_val_temp_hp2.invalidate();
		//Temp BP1
		Unicode::snprintfFloat(textAreaBuffer_Temp_BP1_Geot, 7, "%.1f", ((float)sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP1)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_BP1_Geot[Unicode::strlen(textAreaBuffer_Temp_BP1_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_BP1_Geot[Unicode::strlen(textAreaBuffer_Temp_BP1_Geot)], 2,"C");
		textArea_geo_val_temp_bp1.setWildcard1(textAreaBuffer_Temp_BP1_Geot);
		textArea_geo_val_temp_bp1.invalidate();
		//Temp BP2
		Unicode::snprintfFloat(textAreaBuffer_Temp_BP2_Geot, 7, "%.1f", ((float)sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP2)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_BP2_Geot[Unicode::strlen(textAreaBuffer_Temp_BP2_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_BP2_Geot[Unicode::strlen(textAreaBuffer_Temp_BP2_Geot)], 2,"C");
		textArea_geo_val_temp_bp2.setWildcard1(textAreaBuffer_Temp_BP2_Geot);
		textArea_geo_val_temp_bp2.invalidate();
		//Temp Cond
		Unicode::snprintfFloat(textAreaBuffer_Temp_OutCond_Geot, 7, "%.1f", ((float)sCyclRegFrigo->pac.geotwin.Temp.i16Temp_COND)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_OutCond_Geot[Unicode::strlen(textAreaBuffer_Temp_OutCond_Geot)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_OutCond_Geot[Unicode::strlen(textAreaBuffer_Temp_OutCond_Geot)], 2,"C");
		textArea_geo_val_temp_cond.setWildcard(textAreaBuffer_Temp_OutCond_Geot);
		textArea_geo_val_temp_cond.invalidate();
		//In TOR Puits
		if(sCyclRegFrigo->pac.geotwin.InTor.Puits)
		{
			Unicode::snprintf(textAreaBuffer_InTor_Puits_OK_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_InTor_Puits_OK_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_in_tor_puits.setWildcard(textAreaBuffer_InTor_Puits_OK_Geot);
		textArea_geo_val_in_tor_puits.invalidate();
		//In TOR Pressostat HP
		if(sCyclRegFrigo->pac.geotwin.InTor.HP)
		{
			Unicode::snprintf(textAreaBuffer_InTor_HP_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_InTor_HP_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_in_secu_hp.setWildcard(textAreaBuffer_InTor_HP_Geot);
		textArea_geo_val_in_secu_hp.invalidate();
		//In  TOR Dem Pro1
		if(sCyclRegFrigo->pac.geotwin.InTor.DemarreurC1)
		{
			Unicode::snprintf(textAreaBuffer_InTor_DemPro1_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_InTor_DemPro1_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_in_dem_pro_1.setWildcard(textAreaBuffer_InTor_DemPro1_Geot);
		textArea_geo_val_in_dem_pro_1.invalidate();
		//In  TOR Dem Pro2
		if(sCyclRegFrigo->pac.geotwin.InTor.DemarreurC2)
		{
			Unicode::snprintf(textAreaBuffer_InTor_DemPro2_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_InTor_DemPro2_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_in_dem_pro_2.setWildcard(textAreaBuffer_InTor_DemPro2_Geot);
		textArea_geo_val_in_dem_pro_2.invalidate();
		//Circ Prim / PW
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_CirculateurPrimaire == 0)
		{
			Unicode::snprintf(textAreaBuffer_CircPrim_Out_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_CircPrim_Out_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		Unicode::snprintf(&textAreaBuffer_CircPrim_Out_Geot[Unicode::strlen(textAreaBuffer_CircPrim_Out_Geot)], 4, " - ");
		Unicode::snprintf(&textAreaBuffer_CircPrim_Out_Geot[Unicode::strlen(textAreaBuffer_CircPrim_Out_Geot)], 4, "%d",sCyclRegFrigo->pac.geotwin.u8ConsigneCirculateurPrimaire & 0xFF);
		textArea_geo_val_out_circ_prim.setWildcard1(textAreaBuffer_CircPrim_Out_Geot);
		Unicode::snprintf(textAreaBuffer_CircPrim_Pw_Geot, 4, "%d",sCyclRegFrigo->pac.geotwin.InAna.u16Vitesse_Circul_PRI);
		textArea_geo_val_out_circ_prim.setWildcard2(textAreaBuffer_CircPrim_Pw_Geot);
		textArea_geo_val_out_circ_prim.invalidate();
		//Circ Capt / PW
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_CirculateurCaptage == 0)
		{
			Unicode::snprintf(textAreaBuffer_CircCapt_Out_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_CircCapt_Out_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		Unicode::snprintf(&textAreaBuffer_CircCapt_Out_Geot[Unicode::strlen(textAreaBuffer_CircCapt_Out_Geot)], 4, " - ");
		Unicode::snprintf(&textAreaBuffer_CircCapt_Out_Geot[Unicode::strlen(textAreaBuffer_CircCapt_Out_Geot)], 4, "%d",sCyclRegFrigo->pac.geotwin.u8ConsigneCirculateurCaptage & 0xFF);
		textArea_geo_val_out_circ_capt.setWildcard1(textAreaBuffer_CircCapt_Out_Geot);
		Unicode::snprintf(textAreaBuffer_CircCapt_Pw_Geot, 4, "%d",sCyclRegFrigo->pac.geotwin.InAna.u16Vitesse_Circul_CAP);
		textArea_geo_val_out_circ_capt.setWildcard2(textAreaBuffer_CircCapt_Pw_Geot);
		textArea_geo_val_out_circ_capt.invalidate();
		//Relais V4V
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_V4V == 0)
		{
			Unicode::snprintf(textAreaBuffer_Out_V4V_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Out_V4V_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_out_v4v.setWildcard(textAreaBuffer_Out_V4V_Geot);
		textArea_geo_val_out_v4v.invalidate();
		//Relais Puits
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_PompeDePuit == 0)
		{
			Unicode::snprintf(textAreaBuffer_Out_Pompe_Puits_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Out_Pompe_Puits_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_out_puits.setWildcard(textAreaBuffer_Out_Pompe_Puits_Geot);
		textArea_geo_val_out_puits.invalidate();
		//Relais Comp1
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_Compresseur1 == 0)
		{
			Unicode::snprintf(textAreaBuffer_Out_Comp1_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Out_Comp1_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_out_comp1.setWildcard(textAreaBuffer_Out_Comp1_Geot);
		textArea_geo_val_out_comp1.invalidate();
		//Relais Comp2
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_Compresseur2 == 0)
		{
			Unicode::snprintf(textAreaBuffer_Out_Comp2_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Out_Comp2_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_out_comp2.setWildcard(textAreaBuffer_Out_Comp2_Geot);
		textArea_geo_val_out_comp2.invalidate();
		//Relais Sapre1
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_Spare1 == 0)
		{
			Unicode::snprintf(textAreaBuffer_Spare1_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Spare1_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_out_spare1.setWildcard(textAreaBuffer_Spare1_Geot);
		textArea_geo_val_out_spare1.invalidate();
		//Relais Sapre2
		if (sCyclRegFrigo->pac.geotwin.OutTor.REL_Spare2 == 0)
		{
			Unicode::snprintf(textAreaBuffer_Spare2_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Spare2_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_out_spare2.setWildcard(textAreaBuffer_Spare2_Geot);
		textArea_geo_val_out_spare2.invalidate();
		//Led Rouge
		if (sCyclRegFrigo->pac.geotwin.OutTor.LED_Defaut == 0)
		{
			Unicode::snprintf(textAreaBuffer_Led_Defaut_Geot, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Led_Defaut_Geot, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_led_defaut.setWildcard(textAreaBuffer_Led_Defaut_Geot);
		textArea_geo_val_led_defaut.invalidate();
		//Led Rouge
		if (sCyclRegFrigo->pac.geotwin.OutTor.LED_Verte == 0)
		{
			Unicode::snprintf(textAreaBuffer_Led_Verte, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Led_Verte, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		textArea_geo_val_led_verte.setWildcard(textAreaBuffer_Led_Verte);
		textArea_geo_val_led_verte.invalidate();
	}
	//AJPAC
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		//Palier / Fréquence
		Unicode::snprintf(textAreaBuffer_Palier_Ajp, 3, "%d",sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.Palier_Comp410);
		textArea_ajp_val_statut_comp1.setWildcard1(textAreaBuffer_Palier_Ajp);
		Unicode::snprintf(textAreaBuffer_Frequence_Ajp, 4, "%d",sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8Freq_Comp410);
		textArea_ajp_val_statut_comp1.setWildcard2(textAreaBuffer_Frequence_Ajp);
		textArea_ajp_val_statut_comp1.invalidate();
		//Statut Comp 134
		if (sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8_Comp134 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Statut_Comp2_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Statut_Comp2_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_statut_comp2.setWildcard(textAreaBuffer_Statut_Comp2_Ajp);
		textArea_ajp_val_statut_comp2.invalidate();
		//Alimentation AC
		Unicode::snprintf(textAreaBuffer_AlimAC_U_Ajp, 4, "%d",sCyclRegFrigo->pac.ajpac.sInfo_U_I_AJP.u16U_Alim_AC);
		textArea_ajp_val_alim_AC.setWildcard1(textAreaBuffer_AlimAC_U_Ajp);
		Unicode::snprintf(textAreaBuffer_AlimAC_I_Ajp, 4, "%d",sCyclRegFrigo->pac.ajpac.sInfo_U_I_AJP.u16I_Alim_AC);
		textArea_ajp_val_alim_AC.setWildcard2(textAreaBuffer_AlimAC_I_Ajp);
		textArea_ajp_val_alim_AC.invalidate();
		//Alimentation DC
		Unicode::snprintf(textAreaBuffer_AlimDC_U_Ajp, 4, "%d",sCyclRegFrigo->pac.ajpac.sInfo_U_I_AJP.u16U_Alim_DC);
		textArea_ajp_val_alim_DC.setWildcard1(textAreaBuffer_AlimDC_U_Ajp);
		Unicode::snprintf(textAreaBuffer_AlimDC_I_Ajp, 4, "%d",sCyclRegFrigo->pac.ajpac.sInfo_U_I_AJP.u16I_Alim_DC);
		textArea_ajp_val_alim_DC.setWildcard2(textAreaBuffer_AlimDC_I_Ajp);
		textArea_ajp_val_alim_DC.invalidate();
		//Demande palier 410
		Unicode::snprintf(textAreaBuffer_Dde_Palier410_Ajp, 3, "%d",sCyclRegFrigo->pac.ajpac.sDemandePW.PalierCompresseur1);
		textArea_ajp_val_demande_comp1.setWildcard(textAreaBuffer_Dde_Palier410_Ajp);
		textArea_ajp_val_demande_comp1.invalidate();
		//Demande comp 134
		if (sCyclRegFrigo->pac.ajpac.sDemandePW.bCompresseur2 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Dde_Comp2_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Dde_Comp2_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_demande_comp2.setWildcard(textAreaBuffer_Dde_Comp2_Ajp);
		textArea_ajp_val_demande_comp2.invalidate();
		//Temp cible 410
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cible_Comp1_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP410_Cible)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_Cible_Comp1_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cible_Comp1_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cible_Comp1_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cible_Comp1_Ajp)], 2,"C");
		textArea_ajp_val_objectif_410.setWildcard(textAreaBuffer_Temp_Cible_Comp1_Ajp);
		textArea_ajp_val_objectif_410.invalidate();
		//Temp TDS 410
		Unicode::snprintfFloat(textAreaBuffer_Temp_TDS410_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH410)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TDS410_Ajp[Unicode::strlen(textAreaBuffer_Temp_TDS410_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TDS410_Ajp[Unicode::strlen(textAreaBuffer_Temp_TDS410_Ajp)], 2,"C");
		textArea_ajp_val_temp_tds_410.setWildcard(textAreaBuffer_Temp_TDS410_Ajp);
		textArea_ajp_val_temp_tds_410.invalidate();
		//Temp TSC 410A
		Unicode::snprintfFloat(textAreaBuffer_Temp_TSC410A_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_A)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TSC410A_Ajp[Unicode::strlen(textAreaBuffer_Temp_TSC410A_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TSC410A_Ajp[Unicode::strlen(textAreaBuffer_Temp_TSC410A_Ajp)], 2,"C");
		textArea_ajp_val_temp_tsc410a.setWildcard(textAreaBuffer_Temp_TSC410A_Ajp);
		textArea_ajp_val_temp_tsc410a.invalidate();
		//Temp TSC 410B
		Unicode::snprintfFloat(textAreaBuffer_Temp_TSC410B_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B )/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TSC410B_Ajp[Unicode::strlen(textAreaBuffer_Temp_TSC410B_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TSC410B_Ajp[Unicode::strlen(textAreaBuffer_Temp_TSC410B_Ajp)], 2,"C");
		textArea_ajp_val_temp_tsc410b.setWildcard(textAreaBuffer_Temp_TSC410B_Ajp);
		textArea_ajp_val_temp_tsc410b.invalidate();
		//Temp cible 134
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cible_Comp2_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP134_Cible )/10);
		Unicode::snprintf(&textAreaBuffer_Temp_Cible_Comp2_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cible_Comp2_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cible_Comp2_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cible_Comp2_Ajp)], 2,"C");
		textArea_ajp_val_objectif_temp_134.setWildcard(textAreaBuffer_Temp_Cible_Comp2_Ajp);
		textArea_ajp_val_objectif_temp_134.invalidate();
		//Temp TDS 134
		Unicode::snprintfFloat(textAreaBuffer_Temp_TDS134_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH134)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TDS134_Ajp[Unicode::strlen(textAreaBuffer_Temp_TDS134_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TDS134_Ajp[Unicode::strlen(textAreaBuffer_Temp_TDS134_Ajp)], 2,"C");
		textArea_ajp_val_temp_tds_134.setWildcard(textAreaBuffer_Temp_TDS134_Ajp);
		textArea_ajp_val_temp_tds_134.invalidate();
		//Temp TEV 134
		Unicode::snprintfFloat(textAreaBuffer_Temp_TEV134_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TEV134)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TEV134_Ajp[Unicode::strlen(textAreaBuffer_Temp_TEV134_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TEV134_Ajp[Unicode::strlen(textAreaBuffer_Temp_TEV134_Ajp)], 2,"C");
		textArea_ajp_val_temp_tev_134.setWildcard(textAreaBuffer_Temp_TEV134_Ajp);
		textArea_ajp_val_temp_tev_134.invalidate();
		//Temp T IGBT
		Unicode::snprintfFloat(textAreaBuffer_Temp_IGBT_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TIGBT)/10);
		Unicode::snprintf(&textAreaBuffer_Temp_IGBT_Ajp[Unicode::strlen(textAreaBuffer_Temp_IGBT_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_IGBT_Ajp[Unicode::strlen(textAreaBuffer_Temp_IGBT_Ajp)], 2,"C");
		textArea_ajp_val_temp_igbt.setWildcard(textAreaBuffer_Temp_IGBT_Ajp);
		textArea_ajp_val_temp_igbt.invalidate();
		//Pression HP / Temp Cond 410
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_HP1_Ajp, 7, "%.1f", ((float) sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410) / 10);
		textArea_ajp_val_pression_temp_hp410.setWildcard1(textAreaBuffer_Press_HP1_Ajp);
		//Temp Cond
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond1_Ajp, 7, "%.1f", ((float)ConvertPressionToTemperature(GAZ_R410, true, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_Cond1_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cond1_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond1_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cond1_Ajp)], 2,"C");
		textArea_ajp_val_pression_temp_hp410.setWildcard2(textAreaBuffer_Temp_Cond1_Ajp);
		textArea_ajp_val_pression_temp_hp410.invalidate();
		//Pression BP / Temp Evap 410
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_BP1_Ajp, 7, "%.1f", ((float) sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410) / 10);
		textArea_ajp_val_pression_temp_bp410.setWildcard1(textAreaBuffer_Press_BP1_Ajp);
		//Temp Evap
		Unicode::snprintfFloat(textAreaBuffer_Temp_Evap1_Ajp, 7, "%.1f", ((float)ConvertPressionToTemperature(GAZ_R410, false, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_Evap1_Ajp[Unicode::strlen(textAreaBuffer_Temp_Evap1_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Evap1_Ajp[Unicode::strlen(textAreaBuffer_Temp_Evap1_Ajp)], 2,"C");
		textArea_ajp_val_pression_temp_bp410.setWildcard2(textAreaBuffer_Temp_Evap1_Ajp);
		textArea_ajp_val_pression_temp_bp410.invalidate();
		//Pression HP / Temp Cond 410 Int
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_HPInt_Ajp, 7, "%.1f", ((float) sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT) / 10);
		textArea_ajp_val_pression_temp_int410.setWildcard1(textAreaBuffer_Press_HPInt_Ajp);
		//Temp Cond
		Unicode::snprintfFloat(textAreaBuffer_Temp_CondInt_Ajp, 7, "%.1f", ((float)ConvertPressionToTemperature(GAZ_R410, true, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_CondInt_Ajp[Unicode::strlen(textAreaBuffer_Temp_CondInt_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_CondInt_Ajp[Unicode::strlen(textAreaBuffer_Temp_CondInt_Ajp)], 2,"C");
		textArea_ajp_val_pression_temp_int410.setWildcard2(textAreaBuffer_Temp_CondInt_Ajp);
		textArea_ajp_val_pression_temp_int410.invalidate();
		//Pression HP / Temp Cond 134
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_HP2_Ajp, 7, "%.1f", ((float) sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP134) / 10);
		textArea_ajp_val_pression_temp_hp134.setWildcard1(textAreaBuffer_Press_HP2_Ajp);
		//Temp Cond
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond2_Ajp, 7, "%.1f", ((float)ConvertPressionToTemperature(GAZ_R134, true, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP134)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_Cond2_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cond2_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Cond2_Ajp[Unicode::strlen(textAreaBuffer_Temp_Cond2_Ajp)], 2,"C");
		textArea_ajp_val_pression_temp_hp134.setWildcard2(textAreaBuffer_Temp_Cond2_Ajp);
		textArea_ajp_val_pression_temp_hp134.invalidate();
		//Pression BP / Temp Evap 134
		//Pression
		Unicode::snprintfFloat(textAreaBuffer_Press_BP2_Ajp, 7, "%.1f", ((float) sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP134) / 10);
		textArea_ajp_val_pression_temp_bp134.setWildcard1(textAreaBuffer_Press_BP2_Ajp);
		//Temp Evap
		Unicode::snprintfFloat(textAreaBuffer_Temp_Evap2_Ajp, 7, "%.1f", ((float)ConvertPressionToTemperature(GAZ_R134, false, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP134)/10));
		Unicode::snprintf(&textAreaBuffer_Temp_Evap2_Ajp[Unicode::strlen(textAreaBuffer_Temp_Evap2_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_Evap2_Ajp[Unicode::strlen(textAreaBuffer_Temp_Evap2_Ajp)], 2,"C");
		textArea_ajp_val_pression_temp_bp134.setWildcard2(textAreaBuffer_Temp_Evap2_Ajp);
		textArea_ajp_val_pression_temp_bp134.invalidate();
		//Pressostat HP410
		if (sCyclRegFrigo->pac.ajpac.sInTorFrigo.Pressostat_HP410 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Pressostat_HP1_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Pressostat_HP1_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_pressostat_hp410.setWildcard(textAreaBuffer_Pressostat_HP1_Ajp);
		textArea_ajp_val_pressostat_hp410.invalidate();
		//Pressostat HP134
		if (sCyclRegFrigo->pac.ajpac.sInTorFrigo.Pressostat_HP134 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Pressostat_HP2_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Pressostat_HP2_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_pressostat_hp134.setWildcard(textAreaBuffer_Pressostat_HP2_Ajp);
		textArea_ajp_val_pressostat_hp134.invalidate();
		//Sortie Tor V4V
		if (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.V4V_R410 == 1)
		{
			Unicode::snprintf(textAreaBuffer_V4V_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_V4V_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_v4v.setWildcard(textAreaBuffer_V4V_Tor_Ajp);
		textArea_ajp_val_v4v.invalidate();
		//Nb dégivrage
		Unicode::snprintf(textAreaBuffer_Nb_Defrost_Ajp, 6, "%d", sCyclRegFrigo->commun.u16NbDegivrage);
		textArea_ajp_val_nb_defrost.setWildcard1(textAreaBuffer_Nb_Defrost_Ajp);
		textArea_ajp_val_nb_defrost.invalidate();
		//EEV Int
		Unicode::snprintf(textAreaBuffer_EEV_Int_Ajp, 4, "%d", sCyclRegFrigo->pac.ajpac.sStatut_EEV_AJP.u16Position_Pulse_EEV410);
		textArea_ajp_val_pos_eev_int.setWildcard1(textAreaBuffer_EEV_Int_Ajp);
		textArea_ajp_val_pos_eev_int.invalidate();
		//EEV 134
		Unicode::snprintf(textAreaBuffer_EEV_134_Ajp, 4, "%d", sCyclRegFrigo->pac.ajpac.sStatut_EEV_AJP.u16Position_Pulse_EEV134);
		textArea_ajp_val_pos_eev134.setWildcard1(textAreaBuffer_EEV_134_Ajp);
		textArea_ajp_val_pos_eev134.invalidate();
		//Sortie Tor Electrovanne
		if (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.Electrovanne_HP410 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Electrovanne_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Electrovanne_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ev410.setWildcard(textAreaBuffer_Electrovanne_Tor_Ajp);
		textArea_ajp_val_ev410.invalidate();
		//Sortie Tor Ventilateur PW
		if (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.Ventilateur_PW == 1)
		{
			Unicode::snprintf(textAreaBuffer_Ventil_PW_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Ventil_PW_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ventil_pw.setWildcard(textAreaBuffer_Ventil_PW_Tor_Ajp);
		textArea_ajp_val_ventil_pw.invalidate();
		//Sortie Tor Spare
		if (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.Spare == 1)
		{
			Unicode::snprintf(textAreaBuffer_Spare_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Spare_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_spare.setWildcard(textAreaBuffer_Spare_Tor_Ajp);
		textArea_ajp_val_spare.invalidate();
		//Mode / Mode / Fmax / Fmin
		Unicode::snprintf(textAreaBuffer_ModeCompVal_Ajp, 2, "%d", sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8Mode_Comp);
		Unicode::snprintf(&textAreaBuffer_ModeCompVal_Ajp[Unicode::strlen(textAreaBuffer_ModeCompVal_Ajp)], 4," / ");
		Unicode::snprintf(&textAreaBuffer_ModeCompVal_Ajp[Unicode::strlen(textAreaBuffer_ModeCompVal_Ajp)],  2, "%d", sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8Modeval);
		textArea_ajp_val_mode_mode_hz_max_min.setWildcard1(textAreaBuffer_ModeCompVal_Ajp);
		Unicode::snprintf(textAreaBuffer_FmaxFmin_Ajp, 4, "%d", sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8Fmax);
		Unicode::snprintf(&textAreaBuffer_FmaxFmin_Ajp[Unicode::strlen(textAreaBuffer_FmaxFmin_Ajp)], 4," / ");
		Unicode::snprintf(&textAreaBuffer_FmaxFmin_Ajp[Unicode::strlen(textAreaBuffer_FmaxFmin_Ajp)],  4, "%d", sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8Fmin);
		textArea_ajp_val_mode_mode_hz_max_min.setWildcard2(textAreaBuffer_FmaxFmin_Ajp);
		textArea_ajp_val_mode_mode_hz_max_min.invalidate();
		//Sortie Tor Ventil UE
		if (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.Evap_EV1 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Ventil_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Ventil_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ventil_ue_tor.setWildcard(textAreaBuffer_Ventil_UE_Tor_Ajp);
		textArea_ajp_val_ventil_ue_tor.invalidate();
		//Sortie Tor Electrovanne UE
		if (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.Evap_EV2 == 1)
		{
			Unicode::snprintf(textAreaBuffer_Electrovanne_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Electrovanne_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ev_ue.setWildcard(textAreaBuffer_Electrovanne_UE_Tor_Ajp);
		textArea_ajp_val_ev_ue.invalidate();
		//Sortie Tor EV3 UE
		if (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.Evap_EV3 == 1)
		{
			Unicode::snprintf(textAreaBuffer_EV3_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_EV3_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ev3.setWildcard(textAreaBuffer_EV3_UE_Tor_Ajp);
		textArea_ajp_val_ev3.invalidate();
		//Sortie Tor EV4 UE
		if (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.Evap_EV4 == 1)
		{
			Unicode::snprintf(textAreaBuffer_EV4_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_EV4_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ev4.setWildcard(textAreaBuffer_EV4_UE_Tor_Ajp);
		textArea_ajp_val_ev4.invalidate();
		//Sortie Tor EV5 UE
		if (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.Evap_EV5 == 1)
		{
			Unicode::snprintf(textAreaBuffer_EV5_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_EV5_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_ev5.setWildcard(textAreaBuffer_EV5_UE_Tor_Ajp);
		textArea_ajp_val_ev5.invalidate();
		//Sortie Tor Ana Ventil UE
		if (sCyclRegFrigo->pac.ajpac.sDemandeFan.sConsigneVentilateur.Ventilateur1 == 0)
		{
			Unicode::snprintf(textAreaBuffer_Ana_Vit_Ventil_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Ana_Vit_Ventil_UE_Tor_Ajp, 4, "%d", sCyclRegFrigo->pac.ajpac.sDemandeFan.sConsigneVentilateur.Ventilateur1);
			Unicode::snprintf(&textAreaBuffer_Ana_Vit_Ventil_UE_Tor_Ajp[Unicode::strlen(textAreaBuffer_Ana_Vit_Ventil_UE_Tor_Ajp)], 2,"%");
		}
		textArea_ajp_val_ventil_ue_ana.setWildcard(textAreaBuffer_Ana_Vit_Ventil_UE_Tor_Ajp);
		textArea_ajp_val_ventil_ue_ana.invalidate();
		//Sortie Tor Led défaut UE
		if (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.LED_Defaut == 1)
		{
			Unicode::snprintf(textAreaBuffer_Led_Defaut_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Led_Defaut_UE_Tor_Ajp, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_led_defaut.setWildcard(textAreaBuffer_Led_Defaut_UE_Tor_Ajp);
		textArea_ajp_val_led_defaut.invalidate();
		//EEV 410 UE
		Unicode::snprintf(textAreaBuffer_EEV410_UE_Ajp, 4, "%d", sCyclRegFrigo->pac.ajpac.sRetourFan.u16Position_Pulse_EEV410BP);
		textArea_ajp_val_eev_ue410.setWildcard(textAreaBuffer_EEV410_UE_Ajp);
		textArea_ajp_val_eev_ue410.invalidate();
		//Temp TEV IN
		Unicode::snprintfFloat(textAreaBuffer_Temp_TEVIN_UE_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_IN )/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TEVIN_UE_Ajp[Unicode::strlen(textAreaBuffer_Temp_TEVIN_UE_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TEVIN_UE_Ajp[Unicode::strlen(textAreaBuffer_Temp_TEVIN_UE_Ajp)], 2,"C");
		textArea_ajp_val_temp_tev_in.setWildcard(textAreaBuffer_Temp_TEVIN_UE_Ajp);
		textArea_ajp_val_temp_tev_in.invalidate();
		//Temp TEV OUT
		Unicode::snprintfFloat(textAreaBuffer_Temp_TEVOUT_UE_Ajp, 7, "%.1f", ((float)sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_OUT )/10);
		Unicode::snprintf(&textAreaBuffer_Temp_TEVOUT_UE_Ajp[Unicode::strlen(textAreaBuffer_Temp_TEVOUT_UE_Ajp)], 2,"%s", degre);
		Unicode::snprintf(&textAreaBuffer_Temp_TEVOUT_UE_Ajp[Unicode::strlen(textAreaBuffer_Temp_TEVOUT_UE_Ajp)], 2,"C");
		textArea_ajp_val_temp_tev_out.setWildcard(textAreaBuffer_Temp_TEVOUT_UE_Ajp);
		textArea_ajp_val_temp_tev_out.invalidate();
		//Vitesse Ventil1 UE
		Unicode::snprintf(textAreaBuffer_Vitesse_Ventil1_UE_Ajp, 6, "%d", sCyclRegFrigo->pac.ajpac.sRetourFan.u16In_Vitesse_Ventilateur_1);
		textArea_ajp_val_vitesse_ventil1.setWildcard(textAreaBuffer_Vitesse_Ventil1_UE_Ajp);
		textArea_ajp_val_vitesse_ventil1.invalidate();
		//Vitesse Ventil2 UE
		Unicode::snprintf(textAreaBuffer_Vitesse_Ventil2_UE_Ajp, 6, "%d", sCyclRegFrigo->pac.ajpac.sRetourFan.u16In_Vitesse_Ventilateur_2);
		textArea_ajp_val_vitesse_ventil2.setWildcard(textAreaBuffer_Vitesse_Ventil2_UE_Ajp);
		textArea_ajp_val_vitesse_ventil2.invalidate();
		//Dégivrage UE
		if (sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.bDegivrageEnCours == 1)
		{
			Unicode::snprintf(textAreaBuffer_Defrost_Ajp, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Defrost_Ajp, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
		}
		textArea_ajp_val_degivrage.setWildcard(textAreaBuffer_Defrost_Ajp);
		textArea_ajp_val_degivrage.invalidate();

	}


	// Mémorisation de l'état précédent
	memcpy(&sCyclRegFrigo_old, sCyclRegFrigo, sizeof(S_CYCL_REG_FRI));
}

void Variables_systemeView::changeStatutTempsFonct(S_STATUT_TPS_FONCT *sStatut_TpsFonct)
{
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV || sConfig_IHM.sModele_PAC.u8ModelePAC == TIMAX_III)
	{
		switch (sConfig_IHM.sModele_PAC.u3SousTypePAC)
		{
			case SOUS_TYPE_BAGUIO_PP:
				//Baguio PP Tension DC == 0
				if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Tension_DC == 0)
				{
					//Zuran / Baguio / Timax
					//Tps fonctionnement PAC
					Unicode::snprintf(textAreaBuffer_TempsFctPac_ZuBa, 8, "%d", (sStatut_TpsFonct->u32TpsCompresseur1 / 3600));
					textArea_zuba_val_tps_fct_pac.setWildcard(textAreaBuffer_TempsFctPac_ZuBa);
					textArea_zuba_val_tps_fct_pac.invalidate();
				}
				else //Baguio PP Tension DC =!= 0
				{
					//Tps fonctionnement PAC
					Unicode::snprintf(textAreaBuffer_TempsFctPac_ZuBa, 8, "%d", (sStatut_TpsFonct->u32TpsCompresseur1 / 3600));
					textArea_zuba_val_tps_fct_pac_1.setWildcard(textAreaBuffer_TempsFctPac_ZuBa);
					textArea_zuba_val_tps_fct_pac_1.invalidate();
				}
				break;

			default:
				//Tps fonctionnement PAC
				Unicode::snprintf(textAreaBuffer_TempsFctPac_ZuBa, 8, "%d", (sStatut_TpsFonct->u32TpsCompresseur1 / 3600));
				textArea_zuba_val_tps_fct_pac_2.setWildcard(textAreaBuffer_TempsFctPac_ZuBa);
				textArea_zuba_val_tps_fct_pac_2.invalidate();
				break;
		}
	}
	//GEOTWIN
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{

		//Tps fonctionnement Comp 1 / Comp 2
		Unicode::snprintf(textAreaBuffer_Tps_Comp1_Geot, 11, "%d", (sStatut_TpsFonct->u32TpsCompresseur1 / 3600));
		textArea_geo_val_temps_fct_comp_1_2.setWildcard1(textAreaBuffer_Tps_Comp1_Geot);
		if (sConfig_IHM.sModele_PAC.nbCompresseur > 0)
		{
			Unicode::snprintf(textAreaBuffer_Tps_Comp2_Geot, 11, "%d", (sStatut_TpsFonct->u32TpsCompresseur2 / 3600));
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Tps_Comp2_Geot, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_geo_val_temps_fct_comp_1_2.setWildcard2(textAreaBuffer_Tps_Comp2_Geot);
		textArea_geo_val_temps_fct_comp_1_2.invalidate();
		//Nb Cycle Comp 1 / Comp 2
		Unicode::snprintf(textAreaBuffer_Nb_Cycle_Comp1_Geot, 11, "%d", (sStatut_TpsFonct->u32NbCycleCompresseur1));
		textArea_geo_val_nb_cycle_comp_1_2.setWildcard1(textAreaBuffer_Nb_Cycle_Comp1_Geot);
		if (sConfig_IHM.sModele_PAC.nbCompresseur > 0)
		{
			Unicode::snprintf(textAreaBuffer_Nb_Cycle_Comp2_Geot, 11, "%d", (sStatut_TpsFonct->u32NbCycleCompresseur2));
		}
		else
		{
			Unicode::snprintf(textAreaBuffer_Tps_Comp2_Geot, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
		}
		textArea_geo_val_nb_cycle_comp_1_2.setWildcard2(textAreaBuffer_Nb_Cycle_Comp2_Geot);
		textArea_geo_val_nb_cycle_comp_1_2.invalidate();
	}
	//AJPAC
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		//Tps Fonctionnement comp 410
		Unicode::snprintf(textAreaBuffer_Tps_Fct_Comp1_Ajp, 8, "%d",(sStatut_TpsFonct->u32TpsCompresseur1 / 3600));
		textArea_ajp_val_tps_fct_comp1.setWildcard(textAreaBuffer_Tps_Fct_Comp1_Ajp);
		textArea_ajp_val_tps_fct_comp1.invalidate();
		//Nb cycle comp 410
		Unicode::snprintf(textAreaBuffer_Nb_Cycle_Comp1_Ajp, 11, "%d",sStatut_TpsFonct->u32NbCycleCompresseur1);
		textArea_ajp_val_nb_cycle_comp1.setWildcard(textAreaBuffer_Nb_Cycle_Comp1_Ajp);
		textArea_ajp_val_nb_cycle_comp1.invalidate();
		//Tps Fonctionnement comp 134
		Unicode::snprintf(textAreaBuffer_Tps_Fct_Comp2_Ajp, 8, "%d",(sStatut_TpsFonct->u32TpsCompresseur2 / 3600));
		textArea_ajp_val_tps_fct_comp2.setWildcard(textAreaBuffer_Tps_Fct_Comp2_Ajp);
		textArea_ajp_val_tps_fct_comp2.invalidate();
		//Nb cycle comp 134
		Unicode::snprintf(textAreaBuffer_Nb_Cycle_Comp2_Ajp, 11, "%d",sStatut_TpsFonct->u32NbCycleCompresseur2);
		textArea_ajp_val_nb_cycle_comp2.setWildcard(textAreaBuffer_Nb_Cycle_Comp2_Ajp);
		textArea_ajp_val_nb_cycle_comp2.invalidate();
	}
}

void Variables_systemeView::changeStatutECS(S_STATUT_ECS *sStatut_ECS)
{
	Unicode::UnicodeChar degre[] = {0x00B0};

	//Temp ECS Milieu
	Unicode::snprintfFloat(textAreaBuffer_Temp_Ecs_Milieu, 7, "%.1f", ((float) sStatut_ECS->i16TeauMilieu) / 10);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Milieu[Unicode::strlen(textAreaBuffer_Temp_Ecs_Milieu)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Milieu[Unicode::strlen(textAreaBuffer_Temp_Ecs_Milieu)], 2,"C");
	textArea_val_temp_ecs_milieu.setWildcard(textAreaBuffer_Temp_Ecs_Milieu);
	textArea_val_temp_ecs_milieu.invalidate();
	//Temp ECS Bas
	Unicode::snprintfFloat(textAreaBuffer_Temp_Ecs_Bas, 7, "%.1f", ((float) sStatut_ECS->i16TeauBas) / 10);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Bas[Unicode::strlen(textAreaBuffer_Temp_Ecs_Bas)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Bas[Unicode::strlen(textAreaBuffer_Temp_Ecs_Bas)], 2,"C");
	textArea_val_temp_ecs_bas.setWildcard(textAreaBuffer_Temp_Ecs_Bas);
	textArea_val_temp_ecs_bas.invalidate();
	//Temp ECS Spare 1 Départ
	Unicode::snprintfFloat(textAreaBuffer_Temp_Ecs_Spare1, 7, "%.1f", ((float) sStatut_ECS->i16TempDepart) / 10);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Spare1[Unicode::strlen(textAreaBuffer_Temp_Ecs_Spare1)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Spare1[Unicode::strlen(textAreaBuffer_Temp_Ecs_Spare1)], 2,"C");
	textArea_sonde_spare1_val.setWildcard(textAreaBuffer_Temp_Ecs_Spare1);
	textArea_sonde_spare1_val.invalidate();
	//Temp ECS Spare 2 Retour
	Unicode::snprintfFloat(textAreaBuffer_Temp_Ecs_Spare2, 7, "%.1f", ((float) sStatut_ECS->i16TempRetour) / 10);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Spare2[Unicode::strlen(textAreaBuffer_Temp_Ecs_Spare2)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Temp_Ecs_Spare2[Unicode::strlen(textAreaBuffer_Temp_Ecs_Spare2)], 2,"C");
	textArea_sonde_spare2_val.setWildcard(textAreaBuffer_Temp_Ecs_Spare2);
	textArea_sonde_spare2_val.invalidate();

	//Statut App ECS
	if (sConfig_IHM.sParam_ECS.bTypeAppointECS == 0)
	{
		//Etat App
		if (sStatut_ECS->bOutTorAppoint_ECS == 0)
		{
			Unicode::snprintf(textAreaBuffer_AppECS_Etat, 4, touchgfx::TypedText(T_TEXT_OFF_DROITE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_AppECS_Etat, 4, touchgfx::TypedText(T_TEXT_ON_DROITE_DEFAUT).getText());
		textArea_app_ecs_val.setWildcard2(textAreaBuffer_AppECS_Etat);
		textArea_app_ecs_val.invalidate();
	}

	//In_Out Solaire
	if (sConfig_IHM.sParam_ECS.bSolaire == 0)
	{
		Unicode::snprintf(textAreaBuffer_Solaire, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_NA_DROITE_DEFAUT).getText());
	}
	else
	{
		if (sStatut_ECS->bInTorECS_Spare == 0)
		{
			Unicode::snprintf(textAreaBuffer_Solaire, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(textAreaBuffer_Solaire, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	}
	textArea_val_autorisation_ecs.setWildcard(textAreaBuffer_Solaire);
	textArea_val_autorisation_ecs.invalidate();

	//In_Out Boost ECS
	if (sStatut_ECS->bInTorECS_Spare == 0)
	{
		Unicode::snprintf(textAreaBuffer_BoostECS, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_BoostECS, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_boost_ecs.setWildcard(textAreaBuffer_BoostECS);
	textArea_val_boost_ecs.invalidate();

	//In_Out Circul ECS
	if (sStatut_ECS->bOutTor_Circulateur == 0)
	{
		Unicode::snprintf(textAreaBuffer_CircECS, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_CircECS, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_circulateur_ecs.setWildcard(textAreaBuffer_CircECS);
	textArea_val_circulateur_ecs.invalidate();

	//In_Out V3V ECS
	if (sStatut_ECS->bOutTorV3V_ECS == 0)
	{
		Unicode::snprintf(textAreaBuffer_V3V_ECS, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_V3V_ECS, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_v3v_ecs.setWildcard(textAreaBuffer_V3V_ECS);
	textArea_val_v3v_ecs.invalidate();

	//In_Out App ECS
	if (sStatut_ECS->bOutTorAppoint_ECS == 0)
	{
		Unicode::snprintf(textAreaBuffer_App_ECS, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_App_ECS, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_appoint_ecs.setWildcard(textAreaBuffer_App_ECS);
	textArea_val_appoint_ecs.invalidate();

	//In_Out Bouclage ECS
	if (sStatut_ECS->bOutTor_Spare1 == 0)
	{
		Unicode::snprintf(textAreaBuffer_Bcle_ECS, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Bcle_ECS, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_bouclage_ecs.setWildcard(textAreaBuffer_Bcle_ECS);
	textArea_val_bouclage_ecs.invalidate();
}

void Variables_systemeView::changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine)
{
	Unicode::UnicodeChar degre[] = {0x00B0};

	//Temp Piscine
	Unicode::snprintfFloat(textAreaBuffer_Temp_Piscine, 7, "%.1f", ((float) sStatut_Piscine->i16TeauPiscine) / 10);
	Unicode::snprintf(&textAreaBuffer_Temp_Piscine[Unicode::strlen(textAreaBuffer_Temp_Piscine)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Temp_Piscine[Unicode::strlen(textAreaBuffer_Temp_Piscine)], 2,"C");
	textArea_val_temp_piscine.setWildcard(textAreaBuffer_Temp_Piscine);
	textArea_val_temp_piscine.invalidate();

	//Consigne Piscine
	Unicode::snprintfFloat(textAreaBuffer_Cons_Piscine, 7, "%.1f", ((float) sStatut_Piscine->i16ConsignePiscine) / 10);
	Unicode::snprintf(&textAreaBuffer_Cons_Piscine[Unicode::strlen(textAreaBuffer_Cons_Piscine)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_Cons_Piscine[Unicode::strlen(textAreaBuffer_Cons_Piscine)], 2,"C");
	textArea_cons_piscine_val.setWildcard(textAreaBuffer_Cons_Piscine);
	textArea_cons_piscine_val.invalidate();

	//Autorisation Piscine
	if (sStatut_Piscine->bInTor_Piscine == 0)
	{
		Unicode::snprintf(textAreaBuffer_Autorisation_Pisc, 4, touchgfx::TypedText(T_TEXT_OFF_DROITE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Autorisation_Pisc, 4, touchgfx::TypedText(T_TEXT_ON_DROITE_DEFAUT).getText());
	textArea_auto_piscine_val.setWildcard(textAreaBuffer_Autorisation_Pisc);
	textArea_auto_piscine_val.invalidate();

	//Autorisation Piscine
	if (sStatut_Piscine->bInTor_Piscine == 0)
	{
		Unicode::snprintf(textAreaBuffer_Autorisation_Pisc, 4, touchgfx::TypedText(T_TEXT_OFF_DROITE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Autorisation_Pisc, 4, touchgfx::TypedText(T_TEXT_ON_DROITE_DEFAUT).getText());
	textArea_auto_piscine_val.setWildcard(textAreaBuffer_Autorisation_Pisc);
	textArea_auto_piscine_val.invalidate();

	//In_Out In tor Piscine
	if (sStatut_Piscine->bInTor_Piscine == 0) Unicode::snprintf(textAreaBuffer_InTorPiscine, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_InTorPiscine, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_mode_marche_piscine.setWildcard(textAreaBuffer_InTorPiscine);
	textArea_val_mode_marche_piscine.invalidate();

	//In_Out Out tor Piscine
	if (sStatut_Piscine->bOutTorV3V_Piscine == 0) Unicode::snprintf(textAreaBuffer_OutTorPiscine, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_OutTorPiscine, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_v3v_pisc_circ.setWildcard(textAreaBuffer_OutTorPiscine);
	textArea_val_v3v_pisc_circ.invalidate();
}


void Variables_systemeView::changeStatutRF(S_STATUT_RF *sStatut_RF)
{
	//Zone 1 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[0].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone1, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[0].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone1, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[0].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone1, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone1[Unicode::strlen(textAreaBuffer_TypeSondeZone1)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone1[Unicode::strlen(textAreaBuffer_TypeSondeZone1)], 5, "%d", sStatut_RF[0].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone1[Unicode::strlen(textAreaBuffer_TypeSondeZone1)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone1, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_1.setWildcard(textAreaBuffer_TypeSondeZone1);
	textArea_val_type_sonde_zone_1.invalidate();

	//Zone 2 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[1].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone2, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[1].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone2, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[1].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone2, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone2[Unicode::strlen(textAreaBuffer_TypeSondeZone2)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone2[Unicode::strlen(textAreaBuffer_TypeSondeZone2)], 5, "%d", sStatut_RF[1].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone2[Unicode::strlen(textAreaBuffer_TypeSondeZone2)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone2, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_2.setWildcard(textAreaBuffer_TypeSondeZone2);
	textArea_val_type_sonde_zone_2.invalidate();

	//Zone 3 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[2].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone3, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[2].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone3, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[2].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone3, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone3[Unicode::strlen(textAreaBuffer_TypeSondeZone3)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone3[Unicode::strlen(textAreaBuffer_TypeSondeZone3)], 5, "%d", sStatut_RF[2].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone3[Unicode::strlen(textAreaBuffer_TypeSondeZone3)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone3, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_3.setWildcard(textAreaBuffer_TypeSondeZone3);
	textArea_val_type_sonde_zone_3.invalidate();

	//Zone 4 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[3].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone4, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[3].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone4, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[3].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone4, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone4[Unicode::strlen(textAreaBuffer_TypeSondeZone4)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone4[Unicode::strlen(textAreaBuffer_TypeSondeZone4)], 5, "%d", sStatut_RF[3].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone4[Unicode::strlen(textAreaBuffer_TypeSondeZone4)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone4, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_4.setWildcard(textAreaBuffer_TypeSondeZone4);
	textArea_val_type_sonde_zone_4.invalidate();

	//Zone 5 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[4].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone5, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[4].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone5, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[4].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone5, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone5[Unicode::strlen(textAreaBuffer_TypeSondeZone5)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone5[Unicode::strlen(textAreaBuffer_TypeSondeZone5)], 5, "%d", sStatut_RF[4].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone5[Unicode::strlen(textAreaBuffer_TypeSondeZone5)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone5, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_5.setWildcard(textAreaBuffer_TypeSondeZone5);
	textArea_val_type_sonde_zone_5.invalidate();

	//Zone 6 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[5].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone6, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[5].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone6, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[5].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone6, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone6[Unicode::strlen(textAreaBuffer_TypeSondeZone6)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone6[Unicode::strlen(textAreaBuffer_TypeSondeZone6)], 5, "%d", sStatut_RF[5].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone6[Unicode::strlen(textAreaBuffer_TypeSondeZone6)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone6, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_6.setWildcard(textAreaBuffer_TypeSondeZone6);
	textArea_val_type_sonde_zone_6.invalidate();

	//Zone 7 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[6].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone7, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[6].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone7, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[6].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone7, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone7[Unicode::strlen(textAreaBuffer_TypeSondeZone7)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone7[Unicode::strlen(textAreaBuffer_TypeSondeZone7)], 5, "%d", sStatut_RF[6].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone7[Unicode::strlen(textAreaBuffer_TypeSondeZone7)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone7, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_7.setWildcard(textAreaBuffer_TypeSondeZone7);
	textArea_val_type_sonde_zone_7.invalidate();

	//Zone 8 - Type Sonde ambiance
	if (sConfig_IHM.sParam_Zx[7].type_zone.zone.TypeThermostat == TH_CONTACT)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone8, 15, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_CONTACT_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[7].type_zone.zone.TypeThermostat == TH_MODBUS)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone8, 7, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_MODBUS_DROITE_DEFAUT).getText());
	}
	else if (sConfig_IHM.sParam_Zx[7].type_zone.zone.TypeThermostat == TH_RF)
	{
		Unicode::snprintf(textAreaBuffer_TypeSondeZone8, 6, touchgfx::TypedText(T_TEXT_VAR_SYS_TH_RADIO_DROITE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone8[Unicode::strlen(textAreaBuffer_TypeSondeZone8)], 4, " / ");
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone8[Unicode::strlen(textAreaBuffer_TypeSondeZone8)], 5, "%d", sStatut_RF[7].Niveau_Reception);
		Unicode::snprintf(&textAreaBuffer_TypeSondeZone8[Unicode::strlen(textAreaBuffer_TypeSondeZone8)], 4, " dB");
	}
	else Unicode::snprintf(textAreaBuffer_TypeSondeZone8, 3, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());

	textArea_val_type_sonde_zone_8.setWildcard(textAreaBuffer_TypeSondeZone8);
	textArea_val_type_sonde_zone_8.invalidate();
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
	Unicode::snprintf(textArea_Buffer_pw_produite, 6, "%d", sStatut_PAC->u16PWinstantaneeProduite * 10);
	textArea_puissance_produite_val.setWildcard(textArea_Buffer_pw_produite);
	textArea_puissance_produite_val.invalidate();
	//
	Unicode::snprintf(textArea_Buffer_pw_consommee, 6, "%d", sStatut_PAC->u16PWinstantaneeConsommee * 10);
	textArea_puissance_consommee_val.setWildcard(textArea_Buffer_pw_consommee);
	textArea_puissance_consommee_val.invalidate();
	//
	Unicode::snprintf(textArea_Buffer_tps_mise_tension, 6, "%d", sStatut_PAC->u16TpsMiseSousTension);
	textArea_puissance_consommee_val_1.setWildcard(textArea_Buffer_tps_mise_tension);
	textArea_puissance_consommee_val_1.invalidate();

	//Statut App ECS
	if (sConfig_IHM.sParam_ECS.bTypeAppointECS != 0)
	{
		//Etat App
		if (sStatut_PAC->S_Mode ==  S_ECS)
		{
			switch(sStatut_PAC->sOutTor.Pw_Relec)
			{
			case P0:
				Unicode::snprintf(textAreaBuffer_AppECS_Etat, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_0PERCENT_CENTRE_DEFAUT).getText());
				break;
			case P33:
				Unicode::snprintf(textAreaBuffer_AppECS_Etat, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_33PERCENT_CENTRE_DEFAUT).getText());
				break;
			case P66:
				Unicode::snprintf(textAreaBuffer_AppECS_Etat, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_66PERCENT_CENTRE_DEFAUT).getText());
				break;
			case P100:
				Unicode::snprintf(textAreaBuffer_AppECS_Etat, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_100PERCENT_CENTRE_DEFAUT).getText());
				break;
			default:
				Unicode::snprintf(textAreaBuffer_AppECS_Etat, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
				break;
			}

		}
		else Unicode::snprintf(textAreaBuffer_AppECS_Etat, 5, touchgfx::TypedText(T_TEXT_VAR_SYS_100PERCENT_CENTRE_DEFAUT).getText());
		textArea_app_ecs_val.setWildcard2(textAreaBuffer_AppECS_Etat);
		textArea_app_ecs_val.invalidate();
	}

	//In_Out Defaut App
	if (sStatut_PAC->sInTor.bDefautAppoint == 0) Unicode::snprintf(textAreaBuffer_Def_Appoint, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	else Unicode::snprintf(textAreaBuffer_Def_Appoint, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_defaut_appoint.setWildcard(textAreaBuffer_Def_Appoint);
	textArea_val_defaut_appoint.invalidate();

	//In_Out Th Z1
	if (sConfig_IHM.sParam_PAC.InxTH1 == 0)
	{
		Unicode::snprintf(textAreaBuffer_ThZone1, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_ThZone1, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_ThZone1[Unicode::strlen(textAreaBuffer_ThZone1)], 2, "%d", sConfig_IHM.sParam_PAC.InxTH1);
		Unicode::snprintf(&textAreaBuffer_ThZone1[Unicode::strlen(textAreaBuffer_ThZone1)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorTH1 == 0)
		{
			Unicode::snprintf(&textAreaBuffer_ThZone1[Unicode::strlen(textAreaBuffer_ThZone1)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_ThZone1[Unicode::strlen(textAreaBuffer_ThZone1)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_th_zone1.setWildcard(textAreaBuffer_ThZone1);
	textArea_val_th_zone1.invalidate();

	//In_Out Th Z2
	if (sConfig_IHM.sParam_PAC.InxTH2 == 0)
	{
		Unicode::snprintf(textAreaBuffer_ThZone2, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_ThZone2, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_ThZone2[Unicode::strlen(textAreaBuffer_ThZone2)], 2, "%d", sConfig_IHM.sParam_PAC.InxTH2);
		Unicode::snprintf(&textAreaBuffer_ThZone2[Unicode::strlen(textAreaBuffer_ThZone2)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorTH2 == 0)
		{
			Unicode::snprintf(&textAreaBuffer_ThZone2[Unicode::strlen(textAreaBuffer_ThZone2)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_ThZone2[Unicode::strlen(textAreaBuffer_ThZone1)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_th_zone2.setWildcard(textAreaBuffer_ThZone2);
	textArea_val_th_zone2.invalidate();

	//In_Out EJP
	if (sConfig_IHM.sParam_PAC.InxEJP == 0)
	{
		Unicode::snprintf(textAreaBuffer_EJP, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_EJP, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_EJP[Unicode::strlen(textAreaBuffer_EJP)], 2, "%d", sConfig_IHM.sParam_PAC.InxEJP);
		Unicode::snprintf(&textAreaBuffer_EJP[Unicode::strlen(textAreaBuffer_EJP)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorEJP== 0)
		{
			Unicode::snprintf(&textAreaBuffer_EJP[Unicode::strlen(textAreaBuffer_EJP)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_EJP[Unicode::strlen(textAreaBuffer_EJP)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_ejp.setWildcard(textAreaBuffer_EJP);
	textArea_val_ejp.invalidate();

	//In_Out Adapt Loi D'eau
	if (sConfig_IHM.sParam_PAC.InxAdaptationLoiDeau == 0)
	{
		Unicode::snprintf(textAreaBuffer_Adap_Loi_Deau, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Adap_Loi_Deau, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_Adap_Loi_Deau[Unicode::strlen(textAreaBuffer_Adap_Loi_Deau)], 2, "%d", sConfig_IHM.sParam_PAC.InxAdaptationLoiDeau);
		Unicode::snprintf(&textAreaBuffer_Adap_Loi_Deau[Unicode::strlen(textAreaBuffer_Adap_Loi_Deau)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bAdaptationLoiDeau == 0)
		{
			Unicode::snprintf(&textAreaBuffer_Adap_Loi_Deau[Unicode::strlen(textAreaBuffer_Adap_Loi_Deau)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_Adap_Loi_Deau[Unicode::strlen(textAreaBuffer_Adap_Loi_Deau)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_adapt_loi_deau.setWildcard(textAreaBuffer_Adap_Loi_Deau);
	textArea_val_adapt_loi_deau.invalidate();

	//In_Out Adapt Consigne
	if (sConfig_IHM.sParam_PAC.InxAdaptationConsigne == 0)
	{
		Unicode::snprintf(textAreaBuffer_Adap_Consigne, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Adap_Consigne, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_Adap_Consigne[Unicode::strlen(textAreaBuffer_Adap_Consigne)], 2, "%d", sConfig_IHM.sParam_PAC.InxAdaptationConsigne);
		Unicode::snprintf(&textAreaBuffer_Adap_Consigne[Unicode::strlen(textAreaBuffer_Adap_Consigne)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bAdaptationConsigne == 0)
		{
			Unicode::snprintf(&textAreaBuffer_Adap_Consigne[Unicode::strlen(textAreaBuffer_Adap_Consigne)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_Adap_Consigne[Unicode::strlen(textAreaBuffer_Adap_Consigne)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_adapt_consigne.setWildcard(textAreaBuffer_Adap_Consigne);
	textArea_val_adapt_consigne.invalidate();

	//In_Out Free Heating
	if (sConfig_IHM.sParam_PAC.InxFreeHeating == 0)
	{
		Unicode::snprintf(textAreaBuffer_FreeHeating, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_FreeHeating, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_FreeHeating[Unicode::strlen(textAreaBuffer_FreeHeating)], 2, "%d", sConfig_IHM.sParam_PAC.InxFreeHeating);
		Unicode::snprintf(&textAreaBuffer_FreeHeating[Unicode::strlen(textAreaBuffer_FreeHeating)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorFreeHeating == 0)
		{
			Unicode::snprintf(&textAreaBuffer_FreeHeating[Unicode::strlen(textAreaBuffer_FreeHeating)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_FreeHeating[Unicode::strlen(textAreaBuffer_FreeHeating)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_free_heating.setWildcard(textAreaBuffer_FreeHeating);
	textArea_val_free_heating.invalidate();

	//In_Out Marche/Arret General
	if (sConfig_IHM.sParam_PAC.InxMarcheArretGeneral == 0)
	{
		Unicode::snprintf(textAreaBuffer_MA_General, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_MA_General, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_MA_General[Unicode::strlen(textAreaBuffer_MA_General)], 2, "%d", sConfig_IHM.sParam_PAC.InxMarcheArretGeneral);
		Unicode::snprintf(&textAreaBuffer_MA_General[Unicode::strlen(textAreaBuffer_MA_General)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorMarcheArretGeneral == 0)
		{
			Unicode::snprintf(&textAreaBuffer_MA_General[Unicode::strlen(textAreaBuffer_MA_General)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_MA_General[Unicode::strlen(textAreaBuffer_MA_General)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_marche_arret_general.setWildcard(textAreaBuffer_MA_General);
	textArea_val_marche_arret_general.invalidate();

	//In_Out Abaiss. Consigne
	if (sConfig_IHM.sParam_PAC.InxMarcheArretGeneral == 0)
	{
		Unicode::snprintf(textAreaBuffer_AbaissCons, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_AbaissCons, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_AbaissCons[Unicode::strlen(textAreaBuffer_AbaissCons)], 2, "%d", sConfig_IHM.sParam_PAC.InxAbaissementConsigne);
		Unicode::snprintf(&textAreaBuffer_AbaissCons[Unicode::strlen(textAreaBuffer_AbaissCons)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorAbaissementConsigne == 0)
		{
			Unicode::snprintf(&textAreaBuffer_AbaissCons[Unicode::strlen(textAreaBuffer_AbaissCons)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_AbaissCons[Unicode::strlen(textAreaBuffer_AbaissCons)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_abaissement_amb.setWildcard(textAreaBuffer_AbaissCons);
	textArea_val_abaissement_amb.invalidate();

	//In_Out Marche/Arret
	if (sConfig_IHM.sParam_PAC.InxMarcheArret == 0)
	{
		Unicode::snprintf(textAreaBuffer_InMarche, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_InMarche, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_InMarche[Unicode::strlen(textAreaBuffer_InMarche)], 2, "%d", sConfig_IHM.sParam_PAC.InxMarcheArret);
		Unicode::snprintf(&textAreaBuffer_InMarche[Unicode::strlen(textAreaBuffer_InMarche)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorMarcheArret == 0)
		{
			Unicode::snprintf(&textAreaBuffer_InMarche[Unicode::strlen(textAreaBuffer_InMarche)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_InMarche[Unicode::strlen(textAreaBuffer_InMarche)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_marche_arret.setWildcard(textAreaBuffer_InMarche);
	textArea_val_marche_arret.invalidate();

	//In_Out Chaud/Froid
	if (sConfig_IHM.sParam_PAC.InxChaudFroid == 0)
	{
		Unicode::snprintf(textAreaBuffer_InChaud, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_InChaud, 4,"In ");
		Unicode::snprintf(&textAreaBuffer_InChaud[Unicode::strlen(textAreaBuffer_InChaud)], 2, "%d", sConfig_IHM.sParam_PAC.InxChaudFroid);
		Unicode::snprintf(&textAreaBuffer_InChaud[Unicode::strlen(textAreaBuffer_InChaud)], 4," / ");
		if (sStatut_PAC->sFonctInxTor.bTorChaudFroid == 0)
		{
			Unicode::snprintf(&textAreaBuffer_InChaud[Unicode::strlen(textAreaBuffer_InChaud)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
		}
		else Unicode::snprintf(&textAreaBuffer_InChaud[Unicode::strlen(textAreaBuffer_InChaud)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());

	}
	textArea_val_chaud_froid.setWildcard(textAreaBuffer_InChaud);
	textArea_val_chaud_froid.invalidate();

	//In_Out Delestage
	if (sStatut_PAC->sFonctInxTor.bTorDelestage == 0)
	{
		Unicode::snprintf(textAreaBuffer_InDelestage, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_InDelestage, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_delestage.setWildcard(textAreaBuffer_InDelestage);
	textArea_val_delestage.invalidate();

	//In_Out Fct4
	if (sStatut_PAC->sFonctInxTor.bTorFonction4 == 0)
	{
		Unicode::snprintf(textAreaBuffer_InFct4, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_InFct4, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction4.setWildcard(textAreaBuffer_InFct4);
	textArea_val_fonction4.invalidate();

	//In_Out Fct5
	if (sStatut_PAC->sFonctInxTor.bTorFonction5 == 0)
	{
		Unicode::snprintf(textAreaBuffer_InFct5, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_InFct5, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction5.setWildcard(textAreaBuffer_InFct5);
	textArea_val_fonction5.invalidate();

	//In_Out Fct6
	if (sStatut_PAC->sFonctInxTor.bTorFonction6 == 0)
	{
		Unicode::snprintf(textAreaBuffer_InFct6, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_InFct6, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction6.setWildcard(textAreaBuffer_InFct6);
	textArea_val_fonction6.invalidate();

	//In_Out Fct7
	if (sStatut_PAC->sFonctInxTor.bTorFonction7 == 0)
	{
		Unicode::snprintf(textAreaBuffer_InFct7, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_InFct7, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction7.setWildcard(textAreaBuffer_InFct7);
	textArea_val_fonction7.invalidate();

	//In_Out PW Appoint
	switch(sStatut_PAC->sOutTor.Pw_Relec)
	{
		case P0:
			Unicode::snprintf(textAreaBuffer_PW_App, 5, "0%");
			break;
		case P33:
			Unicode::snprintf(textAreaBuffer_PW_App, 5, "33%");
			break;
		case P66:
			Unicode::snprintf(textAreaBuffer_PW_App, 5, "66%");
			break;
		case P100:
			Unicode::snprintf(textAreaBuffer_PW_App, 5, "100%");
			break;
		default:
			Unicode::snprintf(textAreaBuffer_InFct7, 4, touchgfx::TypedText(T_TEXT_VAR_SYS_TIRET_TIRET_DROITE_DEFAUT).getText());
			break;
	}
	textArea_val_pw_appoint.setWildcard(textAreaBuffer_PW_App);
	textArea_val_pw_appoint.invalidate();

	//In_Out Resistance carter
	Unicode::snprintf(textAreaBuffer_Res_Carter, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 2, "%d", sConfig_IHM.sParam_PAC.OutxCarter);
	Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bCarter == 0)
	{
		Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_Res_Carter[Unicode::strlen(textAreaBuffer_Res_Carter)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_resistance_carter.setWildcard(textAreaBuffer_Res_Carter);
	textArea_val_resistance_carter.invalidate();

	//In_Out Relève
	Unicode::snprintf(textAreaBuffer_Releve_PAC, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_Releve_PAC[Unicode::strlen(textAreaBuffer_Releve_PAC)], 2, "%d", sConfig_IHM.sParam_PAC.OutxRelevePAC);
	Unicode::snprintf(&textAreaBuffer_Releve_PAC[Unicode::strlen(textAreaBuffer_Releve_PAC)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bRelevePAC == 0)
	{
		Unicode::snprintf(&textAreaBuffer_Releve_PAC[Unicode::strlen(textAreaBuffer_Releve_PAC)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_Releve_PAC[Unicode::strlen(textAreaBuffer_Releve_PAC)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_releve_pac.setWildcard(textAreaBuffer_Releve_PAC);
	textArea_val_releve_pac.invalidate();

	//In_Out Chaud/Froid
	Unicode::snprintf(textAreaBuffer_Info_Ch_Fr, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_Info_Ch_Fr[Unicode::strlen(textAreaBuffer_Info_Ch_Fr)], 2, "%d", sConfig_IHM.sParam_PAC.OutxModeChaudFroid);
	Unicode::snprintf(&textAreaBuffer_Info_Ch_Fr[Unicode::strlen(textAreaBuffer_Info_Ch_Fr)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bModeFroid == 0)
	{
		Unicode::snprintf(&textAreaBuffer_Info_Ch_Fr[Unicode::strlen(textAreaBuffer_Info_Ch_Fr)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_Info_Ch_Fr[Unicode::strlen(textAreaBuffer_Info_Ch_Fr)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_info_chaud_froid.setWildcard(textAreaBuffer_Info_Ch_Fr);
	textArea_val_info_chaud_froid.invalidate();

	//In_Out Defaut PAC
	if (sStatut_PAC->sFonctOutxTor.bInfoDefautPAC == 0)
	{
		Unicode::snprintf(textAreaBuffer_Def_PAC, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Def_PAC, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_defaut_pac.setWildcard(textAreaBuffer_Def_PAC);
	textArea_val_defaut_pac.invalidate();

	//In_Out Ch/Fr Simu 1
	if (sStatut_PAC->sFonctOutxTor.bChaudFroidVoie1 == 0)
	{
		Unicode::snprintf(textAreaBuffer_Ch_fr_Simu1, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Ch_fr_Simu1, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_chaud_froid_simu1.setWildcard(textAreaBuffer_Ch_fr_Simu1);
	textArea_val_chaud_froid_simu1.invalidate();

	//In_Out Ch/Fr Simu 2
	if (sStatut_PAC->sFonctOutxTor.bChaudFroidVoie2 == 0)
	{
		Unicode::snprintf(textAreaBuffer_Ch_fr_Simu2, 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Ch_fr_Simu2, 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_chaud_froid_simu2.setWildcard(textAreaBuffer_Ch_fr_Simu2);
	textArea_val_chaud_froid_simu2.invalidate();

	//In_Out Info M/A Comp
	Unicode::snprintf(textAreaBuffer_MA_Comp, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_MA_Comp[Unicode::strlen(textAreaBuffer_MA_Comp)], 2, "%d", sConfig_IHM.sParam_PAC.OutxInfoMarcheArret);
	Unicode::snprintf(&textAreaBuffer_MA_Comp[Unicode::strlen(textAreaBuffer_MA_Comp)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bInfoMarcheArret == 0)
	{
		Unicode::snprintf(&textAreaBuffer_MA_Comp[Unicode::strlen(textAreaBuffer_MA_Comp)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_MA_Comp[Unicode::strlen(textAreaBuffer_MA_Comp)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_marche_arret_comp.setWildcard(textAreaBuffer_MA_Comp);
	textArea_val_marche_arret_comp.invalidate();

	//In_Out Fonction 8
	Unicode::snprintf(textAreaBuffer_Fct8, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_Fct8[Unicode::strlen(textAreaBuffer_Fct8)], 2, "%d", sConfig_IHM.sParam_PAC.OutxFonction8);
	Unicode::snprintf(&textAreaBuffer_Fct8[Unicode::strlen(textAreaBuffer_Fct8)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bFonction8 == 0)
	{
		Unicode::snprintf(&textAreaBuffer_Fct8[Unicode::strlen(textAreaBuffer_Fct8)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_Fct8[Unicode::strlen(textAreaBuffer_Fct8)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction8.setWildcard(textAreaBuffer_Fct8);
	textArea_val_fonction8.invalidate();

	//In_Out Fonction 9
	Unicode::snprintf(textAreaBuffer_Fct9, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_Fct9[Unicode::strlen(textAreaBuffer_Fct9)], 2, "%d", sConfig_IHM.sParam_PAC.OutxFonction9);
	Unicode::snprintf(&textAreaBuffer_Fct9[Unicode::strlen(textAreaBuffer_Fct9)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bFonction9 == 0)
	{
		Unicode::snprintf(&textAreaBuffer_Fct9[Unicode::strlen(textAreaBuffer_Fct9)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_Fct9[Unicode::strlen(textAreaBuffer_Fct9)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction9.setWildcard(textAreaBuffer_Fct9);
	textArea_val_fonction9.invalidate();

	//In_Out Fonction 10
	Unicode::snprintf(textAreaBuffer_Fct10, 5,"Out ");
	Unicode::snprintf(&textAreaBuffer_Fct10[Unicode::strlen(textAreaBuffer_Fct10)], 2, "%d", sConfig_IHM.sParam_PAC.OutxFonction10);
	Unicode::snprintf(&textAreaBuffer_Fct10[Unicode::strlen(textAreaBuffer_Fct10)], 4," / ");
	if (sStatut_PAC->sFonctOutxTor.bFonction10 == 0)
	{
		Unicode::snprintf(&textAreaBuffer_Fct10[Unicode::strlen(textAreaBuffer_Fct10)], 4, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(&textAreaBuffer_Fct10[Unicode::strlen(textAreaBuffer_Fct10)], 4, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	textArea_val_fonction10.setWildcard(textAreaBuffer_Fct10);
	textArea_val_fonction10.invalidate();

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Variables_systemeView::changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo)
{
	//Si GTI ou  Phoenix on prend le statut frigo
	if (sConfig_IHM.sModele_PAC.u8ModelePAC != GEOINVERTER && sConfig_IHM.sModele_PAC.u8ModelePAC != PHOENIX)
	{
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
	}
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

	//In_Out Demande Frigo
	if (sDemandeFrigo->bModeSilencieux == 0)
	{
		Unicode::snprintf(textAreaBuffer_ModeSilencieux, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	}
	else Unicode::snprintf(textAreaBuffer_ModeSilencieux, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	textArea_val_mode_silencieux.setWildcard(textAreaBuffer_ModeSilencieux);
	textArea_val_mode_silencieux.invalidate();

	//In_Out Reduc PW
	switch (sDemandeFrigo->Reduc_PW)
	{
		default:
		case R0 :
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R0).getText());
			break;
		case R1:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R1).getText());
			break;
		case R2:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R2).getText());
			break;
		case R3:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R3).getText());
			break;
		case R4:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R4).getText());
			break;
		case R5:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R5).getText());
			break;
		case R6:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R6).getText());
			break;
		case R7:
			Unicode::snprintf(textAreaBuffer_ReducPW, 20, touchgfx::TypedText(T_TEXT_VAR_SYS_REDUC_PW_R7).getText());
			break;

	}
	textArea_val_reduct_pw.setWildcard(textAreaBuffer_ReducPW);
	textArea_val_reduct_pw.invalidate();

	//GEOTWIN
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		//Gestion circulateur primaire
		switch(sDemandeFrigo->eGestionCirculateurPrimaire)
		{
			default:
			case GC_AUTO:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT).getText());
				break;
			case GC_V40:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT).getText());
				break;
			case GC_V50:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT).getText());
				break;
			case GC_V60:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT).getText());
				break;
			case GC_V70:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT).getText());
				break;
			case GC_V80:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT).getText());
				break;
			case GC_V90:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT).getText());
				break;
			case GC_V100:
				Unicode::snprintf(textAreaBuffer_Circ_Prim_Gestion_Geot, 11, touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT).getText());
				break;
		}
		textArea_geo_val_circ_prim_gestion.setWildcard2(textAreaBuffer_Circ_Prim_Gestion_Geot);
		textArea_geo_val_circ_prim_gestion.invalidate();

	}

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
