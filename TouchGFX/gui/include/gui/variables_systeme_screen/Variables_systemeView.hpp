#ifndef VARIABLES_SYSTEMEVIEW_HPP
#define VARIABLES_SYSTEMEVIEW_HPP

#include <gui_generated/variables_systeme_screen/Variables_systemeViewBase.hpp>
#include <gui/variables_systeme_screen/Variables_systemePresenter.hpp>

class Variables_systemeView : public Variables_systemeViewBase
{
public:
    Variables_systemeView();
    virtual ~Variables_systemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_primaire();
    void bouton_zones();
    void bouton_groupes();
    void bouton_options();
    void bouton_frigo();
    void bouton_config_in_out();
    void update_num_ligne_primaire();
    void update_num_ligne_groupes();
    void update_num_ligne_zone();
    void update_num_ligne_option();
    void update_num_ligne_in_out();
    void update_num_ligne_frigo_inv();
    void update_num_ligne_frigo_zu_ba_tim();
    void update_num_ligne_frigo_geo();
    void update_num_ligne_frigo_ajpac();

    virtual void changeStatutRegulEsclave(S_STATUT_REGUL_ESCLAVE *sStatut_RegulEsclave);
    virtual void changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);
    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx);
    virtual void changeStatutRF(S_STATUT_RF *sStatut_RF);
    virtual void changeStatutECS(S_STATUT_ECS *sStatut_ECS);
    virtual void changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine);
    virtual void changeStatutTempsFonct(S_STATUT_TPS_FONCT *sStatut_TpsFonct);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    int16_t oldTempHP;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_CYCL_REG_FRI sCyclRegFrigo_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    // Primaire
    touchgfx::Unicode::UnicodeChar textArea_Buffer_tps_mise_tension[7], textArea_Buffer_AppointVal[4], textArea_Buffer_pw_consommee[7], textArea_Buffer_pw_produite[7], textAreaBuffer_PressionPrimaire[7], textAreaBuffer_DebitPrimaire[7], textAreaBuffer_ConsignePrimaire[9], textAreaBuffer_BallonTamponPrimaire[9], textAreaBuffer_BallonTamponFroid[9], textAreaBuffer_DepartPrimaire[9], textAreaBuffer_RetourPrimaire[9], textAreaBuffer_Temp_Ext[9], textAreaBuffer_CirculateurPrimaire[5], textAreaBuffer_HystBallonPlus[7], textAreaBuffer_HystBallonMoins[11], textAreaBuffer_HystExtPlus[7], textAreaBuffer_HystExtMoins[11], textAreaBuffer_TempExtEqui[9], textAreaBuffer_MaxPW[4], textAreaBuffer_AppointAutorise[4], textAreaBuffer_CircForce[4], textAreaBuffer_GestCirc[15], textAreaBuffer_AppointEnCours[4], textAreaBuffer_TypeAppoint[20], textAreaBuffer_Demande[20], textAreaBuffer_DemandeCascade[20], textAreaBuffer_CascadePresence[9], textAreaBuffer_CascadeTotal[3], textAreaBuffer_CascadeOn[3], textAreaBuffer_CascadeDispo[3], textAreaBuffer_NumLigne[99][3],textAreaBuffer_NumZone[8][3],
	textAreaBuffer_NomGroupeA[9],textAreaBuffer_EmettGroupeA[30],textAreaBuffer_DepartGroupeA[7],textAreaBuffer_RetourGroupeA[7],textAreaBuffer_ConsigneTeauGroupeA[7],textAreaBuffer_CirculateurGroupeA[5],textAreaBuffer_V3VGroupeA[4],textAreaBuffer_ConsVentilGroupeA[4],
	textAreaBuffer_NomGroupeB[9],textAreaBuffer_EmettGroupeB[30],textAreaBuffer_DepartGroupeB[7],textAreaBuffer_RetourGroupeB[7],textAreaBuffer_ConsigneTeauGroupeB[7],textAreaBuffer_CirculateurGroupeB[5],textAreaBuffer_V3VGroupeB[4],textAreaBuffer_ConsVentilGroupeB[4],
	textAreaBuffer_NomZone1[9],textAreaBuffer_ModeZone1[16],textAreaBuffer_TintZone1[7],textAreaBuffer_ConsIntZone1[7],textAreaBuffer_TypeSondeZone1[16],textAreaBuffer_HystMoinsZone1[11],textAreaBuffer_HystPlusZone1[7],textAreaBuffer_EmettZone1[30],textAreaBuffer_DepartZone1[7],textAreaBuffer_RetourZone1[7],textAreaBuffer_ConsigneTeauZone1[7],textAreaBuffer_DebitZone1[7],textAreaBuffer_CirculateurZone1[6],textAreaBuffer_V3VZone1[6],
	textAreaBuffer_NomZone2[9],textAreaBuffer_ModeZone2[16],textAreaBuffer_TintZone2[7],textAreaBuffer_ConsIntZone2[7],textAreaBuffer_TypeSondeZone2[16],textAreaBuffer_HystMoinsZone2[11],textAreaBuffer_HystPlusZone2[7],textAreaBuffer_EmettZone2[30],textAreaBuffer_DepartZone2[7],textAreaBuffer_RetourZone2[7],textAreaBuffer_ConsigneTeauZone2[7],textAreaBuffer_DebitZone2[7],textAreaBuffer_CirculateurZone2[6],textAreaBuffer_V3VZone2[6],
	textAreaBuffer_NomZone3[9],textAreaBuffer_ModeZone3[16],textAreaBuffer_TintZone3[7],textAreaBuffer_ConsIntZone3[7],textAreaBuffer_TypeSondeZone3[16],textAreaBuffer_HystMoinsZone3[11],textAreaBuffer_HystPlusZone3[7],textAreaBuffer_EmettZone3[30],textAreaBuffer_DepartZone3[7],textAreaBuffer_RetourZone3[7],textAreaBuffer_ConsigneTeauZone3[7],textAreaBuffer_DebitZone3[7],textAreaBuffer_CirculateurZone3[6],textAreaBuffer_V3VZone3[6],
	textAreaBuffer_NomZone4[9],textAreaBuffer_ModeZone4[16],textAreaBuffer_TintZone4[7],textAreaBuffer_ConsIntZone4[7],textAreaBuffer_TypeSondeZone4[16],textAreaBuffer_HystMoinsZone4[11],textAreaBuffer_HystPlusZone4[7],textAreaBuffer_EmettZone4[30],textAreaBuffer_DepartZone4[7],textAreaBuffer_RetourZone4[7],textAreaBuffer_ConsigneTeauZone4[7],textAreaBuffer_DebitZone4[7],textAreaBuffer_CirculateurZone4[6],textAreaBuffer_V3VZone4[6],
	textAreaBuffer_NomZone5[9],textAreaBuffer_ModeZone5[16],textAreaBuffer_TintZone5[7],textAreaBuffer_ConsIntZone5[7],textAreaBuffer_TypeSondeZone5[16],textAreaBuffer_HystMoinsZone5[11],textAreaBuffer_HystPlusZone5[7],textAreaBuffer_EmettZone5[30],textAreaBuffer_DepartZone5[7],textAreaBuffer_RetourZone5[7],textAreaBuffer_ConsigneTeauZone5[7],textAreaBuffer_DebitZone5[7],textAreaBuffer_CirculateurZone5[6],textAreaBuffer_V3VZone5[6],
	textAreaBuffer_NomZone6[9],textAreaBuffer_ModeZone6[16],textAreaBuffer_TintZone6[7],textAreaBuffer_ConsIntZone6[7],textAreaBuffer_TypeSondeZone6[16],textAreaBuffer_HystMoinsZone6[11],textAreaBuffer_HystPlusZone6[7],textAreaBuffer_EmettZone6[30],textAreaBuffer_DepartZone6[7],textAreaBuffer_RetourZone6[7],textAreaBuffer_ConsigneTeauZone6[7],textAreaBuffer_DebitZone6[7],textAreaBuffer_CirculateurZone6[6],textAreaBuffer_V3VZone6[6],
	textAreaBuffer_NomZone7[9],textAreaBuffer_ModeZone7[16],textAreaBuffer_TintZone7[7],textAreaBuffer_ConsIntZone7[7],textAreaBuffer_TypeSondeZone7[16],textAreaBuffer_HystMoinsZone7[11],textAreaBuffer_HystPlusZone7[7],textAreaBuffer_EmettZone7[30],textAreaBuffer_DepartZone7[7],textAreaBuffer_RetourZone7[7],textAreaBuffer_ConsigneTeauZone7[7],textAreaBuffer_DebitZone7[7],textAreaBuffer_CirculateurZone7[6],textAreaBuffer_V3VZone7[6],
	textAreaBuffer_NomZone8[9],textAreaBuffer_ModeZone8[16],textAreaBuffer_TintZone8[7],textAreaBuffer_ConsIntZone8[7],textAreaBuffer_TypeSondeZone8[16],textAreaBuffer_HystMoinsZone8[11],textAreaBuffer_HystPlusZone8[7],textAreaBuffer_EmettZone8[30],textAreaBuffer_DepartZone8[7],textAreaBuffer_RetourZone8[7],textAreaBuffer_ConsigneTeauZone8[7],textAreaBuffer_DebitZone8[7],textAreaBuffer_CirculateurZone8[6],textAreaBuffer_V3VZone8[6],
	textAreaBuffer_Temp_Ecs_Milieu[9],textAreaBuffer_Temp_Ecs_Bas[9],textAreaBuffer_Temp_Ecs_Spare1[9],textAreaBuffer_Temp_Ecs_Spare2[9],textAreaBuffer_Cons_ECS_Fin[9], textAreaBuffer_Cons_Ecs_Relance[9], textAreaBuffer_HystECSPlus[7], textAreaBuffer_HystECSMoins[11], textAreaBuffer_AppECS_Autorise[4], textAreaBuffer_AppECS_Etat[5],textAreaBuffer_Legionelle_Autorise[4],textAreaBuffer_Duree_Thermo[4],textAreaBuffer_Temps_Rotation_Vanne_ECS[4],textAreaBuffer_Fin_Thermo[4],
	textAreaBuffer_Temp_Piscine[9],textAreaBuffer_Cons_Piscine[9],textAreaBuffer_Cons_Prim_Piscine[9],textAreaBuffer_HystPiscPlus[7],textAreaBuffer_HystPiscMoins[11], textAreaBuffer_Priorite_Pisc[8], textAreaBuffer_Temps_Rotation_Vanne_Pisc[4], textAreaBuffer_Autorisation_Pisc[4],
	textAreaBuffer_Type_Appoint[20], textAreaBuffer_Nb_Zones[3], textAreaBuffer_Option_Piscine[4], textAreaBuffer_Option_ECS[4], textAreaBuffer_TypeApp_ECS[4], textAreaBuffer_SecoursApp_ECS[4], textAreaBuffer_Comptage_PW[4], textAreaBuffer_NbPulses[5],textAreaBuffer_ECS_Force[4],textAreaBuffer_ECS_Entree_Contact[4],textAreaBuffer_ECS_Bain_Marie[4],textAreaBuffer_Piscine_Confort[4], textAreaBuffer_HystEauPlus[7], textAreaBuffer_HystEauMoins[11],
	textAreaBuffer_HystEauECSPlus[7], textAreaBuffer_HystEauECSMoins[11],textAreaBuffer_HystEauPiscinePlus[7], textAreaBuffer_HystEauPiscineMoins[11], textAreaBuffer_Adapt_LoiDeau[4],textAreaBuffer_ChaudFroid_Simu[4], textAreaBuffer_SecoursDefautPAC[4], textAreaBuffer_TypeDefrost[20],textAreaBuffer_ModeSilencieux[4], textAreaBuffer_ReducPW[20],textAreaBuffer_ShuntTempo[4],textAreaBuffer_Antilegionel[20], textAreaBuffer_ModeV3V_Pisc[2],
	textAreaBuffer_InTorPiscine[4],textAreaBuffer_OutTorPiscine[4],textAreaBuffer_ThZone1[11],textAreaBuffer_ThZone2[11],textAreaBuffer_EJP[11],textAreaBuffer_Def_Appoint[4],textAreaBuffer_Adap_Loi_Deau[11],textAreaBuffer_Adap_Consigne[11],textAreaBuffer_FreeHeating[11],textAreaBuffer_MA_General[11],textAreaBuffer_AbaissCons[11],textAreaBuffer_InMarche[11],textAreaBuffer_InChaud[11],textAreaBuffer_InDelestage[4],textAreaBuffer_InFct4[4],
	textAreaBuffer_InFct5[4],textAreaBuffer_InFct6[4],textAreaBuffer_InFct7[4],textAreaBuffer_Solaire[4],textAreaBuffer_BoostECS[4],textAreaBuffer_CircECS[4],textAreaBuffer_V3V_ECS[4],textAreaBuffer_App_ECS[4],textAreaBuffer_Bcle_ECS[4],textAreaBuffer_PW_App[5],textAreaBuffer_Res_Carter[12],textAreaBuffer_Releve_PAC[12],textAreaBuffer_Info_Ch_Fr[12],textAreaBuffer_Def_PAC[4],textAreaBuffer_Ch_fr_Simu1[4],textAreaBuffer_Ch_fr_Simu2[4],
	textAreaBuffer_MA_Comp[12],textAreaBuffer_Fct8[12],textAreaBuffer_Fct9[12],textAreaBuffer_Fct10[12],
	textAreaBuffer_Modele_PAC_Inv[22], textAreaBuffer_Reversible_Inv[4], textAreaBuffer_FreeCool_Inv[4], textAreaBuffer_Fluide_Inv[7], textAreaBuffer_RefDriver_Inv[13],textAreaBuffer_NbCycles_Inv[11],textAreaBuffer_NbHeures_Inv[11], textAreaBuffer_ReducPW_Inv[20], textAreaBuffer_DSP_Inv[4], textAreaBuffer_DefautDriver_Inv[4],textAreaBuffer_Dem_Comp_Inv[4],textAreaBuffer_ReDem_Comp_Inv[4],textAreaBuffer_Comp_Inv[4],textAreaBuffer_Augm_Vit_Inv[4],
	textAreaBuffer_Dim_Vit_Inv[4],textAreaBuffer_Protect_Vit_Bas_Inv[4],textAreaBuffer_Protect_Vit_Haut_Inv[4],textAreaBuffer_PFC_Inv[4],textAreaBuffer_CourantPhase_Inv[8],textAreaBuffer_CourantAC_Inv[8],textAreaBuffer_TensionAC_Inv[8],textAreaBuffer_TensionDC_Inv[8], textAreaBuffer_Temp_IPM_Inv[8],textAreaBuffer_Temp_PFC_Inv[11],textAreaBuffer_Courant_U_Inv[8],textAreaBuffer_Courant_V_Inv[8],textAreaBuffer_Courant_W_Inv[8],textAreaBuffer_FrequenceCurrent_Inv[4],
	textAreaBuffer_RPMCurrent_Inv[5],textAreaBuffer_Temp_DLT_Inv[11], textAreaBuffer_Temp_Cond_Max_VS_Evap_Inv[11],textAreaBuffer_Temp_Cond_Min_VS_Evap_Inv[11],textAreaBuffer_Press_HP_Max_VS_Vitesse_Inv[6],textAreaBuffer_Restriction_Inv[4], textAreaBuffer_Machine_OK_Inv[4], textAreaBuffer_Retour_Huile_Inv[4], textAreaBuffer_Pb_Thermo_Inv[4], textAreaBuffer_Pre_Chauffage_Inv[4], textAreaBuffer_Frigo_Spare_Inv[11],
	textAreaBuffer_Temp_Dep_Prim_Inv[11], textAreaBuffer_Temp_Ret_Prim_Inv[11], textAreaBuffer_Press_Prim_Inv[11], textAreaBuffer_Debit_Prim_Inv[6], textAreaBuffer_Temp_Ext_Inv[11], textAreaBuffer_Temp_Dep_Capt_Inv[11], textAreaBuffer_Temp_Ret_Capt_Inv[11], textAreaBuffer_Press_Capt_Inv[11], textAreaBuffer_Temp_Debit_Capt_Inv[6], textAreaBuffer_Temp_Liquide_Inv[11], textAreaBuffer_Temp_HP_Cible_Inv[11], textAreaBuffer_Temp_HP_Inv[11], textAreaBuffer_Temp_BP_Inv[11],
	textAreaBuffer_Press_Temp_Cond_Inv[30], textAreaBuffer_Press_Temp_Evap_Inv[30], textAreaBuffer_Dde_Vit_Freq_Inv[4], textAreaBuffer_Dde_Vit_Rpm_Inv[5], textAreaBuffer_Vit_Freq_Inv[4], textAreaBuffer_Vit_Rpm_Inv[5], textAreaBuffer_Vit_Stable_Inv[4], textAreaBuffer_Pos_EEV_EV_Inv[4], textAreaBuffer_Pos_EEV_CD_Inv[4], textAreaBuffer_Cons_Circ_Prim_Inv[4], textAreaBuffer_Circ_Prim_Force_Inv[4], textAreaBuffer_Circ_Prim_Gestion_Inv[11],
	textAreaBuffer_Circ_Capt_Force_Inv[4], textAreaBuffer_Circ_Capt_Gestion_Inv[11],textAreaBuffer_Cons_Pompe_Puits_Inv[4],textAreaBuffer_App1_Inv[4],textAreaBuffer_App23_Inv[4],textAreaBuffer_Comp1_Inv[4],textAreaBuffer_Comp2_Inv[4],textAreaBuffer_PompePuits_Inv[4],textAreaBuffer_EV_Froid_Inv[4],textAreaBuffer_Res_Carter_Inv[4],textAreaBuffer_Res_Vase_Inv[4],textAreaBuffer_Spare1_Inv[4],textAreaBuffer_Spare2_Inv[4],textAreaBuffer_V4V_Inv[4],
	textAreaBuffer_Ventil_Driver_Inv[4],textAreaBuffer_Debistat_Puits_Inv[4],textAreaBuffer_DefautApp1_Inv[4],textAreaBuffer_DefautApp2_Inv[4],textAreaBuffer_DefautApp3_Inv[4],textAreaBuffer_DefautDemPro1_Inv[4],textAreaBuffer_DefautDemPro2_Inv[4],textAreaBuffer_DefautKlixon_Inv[4],textAreaBuffer_DefautHP1_Inv[4],textAreaBuffer_DefautHP2_Inv[4],textAreaBuffer_Switch1_Inv[4],textAreaBuffer_Switch2_Inv[4],textAreaBuffer_Switch3_Inv[4],textAreaBuffer_Switch4_Inv[4],
	textAreaBuffer_Config_Switch_Inv[30],
    textAreaBuffer_Statut_ZuBa[17], textAreaBuffer_FreqCible_ZuBa[17], textAreaBuffer_FreqActu_ZuBa[17], textAreaBuffer_TypeCapacitePac_ZuBa[21], textAreaBuffer_TempsFctPac_ZuBa[8],textAreaBuffer_TempsFctComp_ZuBa[8], textAreaBuffer_NbCycleComp_ZuBa[8],textAreaBuffer_TensionDC_ZuBa[8], textAreaBuffer_CourantAC_ZuBa[8], textAreaBuffer_TempCond_ZuBa[11],textAreaBuffer_Pression_ZuBa[13],textAreaBuffer_DefrostPac_ZuBa[4],textAreaBuffer_NbDefrost_ZuBa[6], textAreaBuffer_Ventil_MA_ZuBa[4],
	textAreaBuffer_Dep_Prim_Mitsu[11], textAreaBuffer_Cons_Prim_Mitsu[5], textAreaBuffer_OutTor1_ZuBa[4], textAreaBuffer_OutTor2_ZuBa[4], textAreaBuffer_OutTor3_ZuBa[4], textAreaBuffer_TrameConnue_ZuBa[4],textAreaBuffer_CodeTrameInconnue_ZuBa[6], textAreaBuffer_NbTrameInconnue_ZuBa[6],  textAreaBuffer_CodeErreur_ZuBa[11],textAreaBuffer_TempHP_ZuBa[11], textAreaBuffer_TempEvapo_ZuBa[11], textAreaBuffer_TempRadDriver_ZuBa[11], textAreaBuffer_TempLiquide_ZuBa[11],
	textAreaBuffer_SurchauffeRef_ZuBa[11], textAreaBuffer_SousRef_ZuBa[11], textAreaBuffer_Detendeur_ZuBa[4], textAreaBuffer_VitVentil1_ZuBa[8],textAreaBuffer_VitVentil2_ZuBa[8],textAreaBuffer_TempInEvapo_ZuBa[11], textAreaBuffer_TempAspi_ZuBa[11], textAreaBuffer_DetendeurA_ZuBa[4],textAreaBuffer_DetendeurB_ZuBa[4],textAreaBuffer_DetendeurC_ZuBa[4],textAreaBuffer_AccesModeCde_ZuBa[4],
	textAreaBuffer_ConfigSw_Geot[9], textAreaBuffer_TypeCapteur_Geot[15], textAreaBuffer_Freecooling_Geot[4],  textAreaBuffer_Circ_Prim_Force_Geot[4], textAreaBuffer_Circ_Prim_Gestion_Geot[11], textAreaBuffer_Circ_Capt_Force_Geot[4], textAreaBuffer_Circ_Capt_Gestion_Geot[11],  textAreaBuffer_Vitesse_Pompe_Puits_Geot[5], textAreaBuffer_PW_Captee_Geot[7], textAreaBuffer_PW_PAC_Geot[4],  textAreaBuffer_Nb_Comp_Geot[2],  textAreaBuffer_Reversible_Geot[4],
	textAreaBuffer_Alimentation_Geot[3], textAreaBuffer_DemPro_Geot[4], textAreaBuffer_PacOK_Geot[4], textAreaBuffer_CycleRetourHuile_Geot[4], textAreaBuffer_LimitationPW_Froid_Geot[4], textAreaBuffer_LimitationPW_ECS_Geot[4], textAreaBuffer_Comp1_OK_Geot[4], textAreaBuffer_Comp2_OK_Geot[4],textAreaBuffer_Statut_Comp1_Geot[4], textAreaBuffer_Statut_Comp2_Geot[4], textAreaBuffer_Tps_Comp1_Geot[11], textAreaBuffer_Tps_Comp2_Geot[11],
	textAreaBuffer_Nb_Cycle_Comp1_Geot[11],textAreaBuffer_Nb_Cycle_Comp2_Geot[11], textAreaBuffer_Press_Capteur_Geot[4], textAreaBuffer_Debit_Capteur_Geot[6], textAreaBuffer_Temp_Out_Capteur_Geot[11], textAreaBuffer_Temp_In_Capteur_Geot[11], textAreaBuffer_Press_HP_Geot[11], textAreaBuffer_Temp_Cond_Geot[11], textAreaBuffer_Press_BP_Geot[11], textAreaBuffer_Temp_Evap_Geot[11], textAreaBuffer_Pos_EEVEV_Geot[4], textAreaBuffer_Pos_EEVSP_Geot[4],
	textAreaBuffer_Coef_Poly_Geot[7], textAreaBuffer_Temp_HP_Cible_Geot[3], textAreaBuffer_Temp_HP1_Geot[11], textAreaBuffer_Temp_HP2_Geot[11], textAreaBuffer_Temp_BP1_Geot[11], textAreaBuffer_Temp_BP2_Geot[11], textAreaBuffer_Temp_OutCond_Geot[11],textAreaBuffer_InTor_Puits_OK_Geot[4],textAreaBuffer_InTor_HP_Geot[4],textAreaBuffer_InTor_DemPro1_Geot[4],textAreaBuffer_InTor_DemPro2_Geot[4],textAreaBuffer_CircPrim_Out_Geot[10],textAreaBuffer_CircPrim_Pw_Geot[4],
	textAreaBuffer_CircCapt_Out_Geot[10],textAreaBuffer_CircCapt_Pw_Geot[4],textAreaBuffer_Out_V4V_Geot[4],textAreaBuffer_Out_Pompe_Puits_Geot[4],textAreaBuffer_Out_Comp1_Geot[4],textAreaBuffer_Out_Comp2_Geot[4], textAreaBuffer_Spare1_Geot[4], textAreaBuffer_Spare2_Geot[4], textAreaBuffer_Led_Defaut_Geot[4], textAreaBuffer_Led_Verte[4],
	textAreaBuffer_Palier_Ajp[3], textAreaBuffer_Frequence_Ajp[4], textAreaBuffer_Tps_Fct_Comp1_Ajp[8], textAreaBuffer_Nb_Cycle_Comp1_Ajp[11], textAreaBuffer_Statut_Comp2_Ajp[4],textAreaBuffer_Tps_Fct_Comp2_Ajp[8], textAreaBuffer_Nb_Cycle_Comp2_Ajp[11], textAreaBuffer_AlimAC_U_Ajp[4], textAreaBuffer_AlimAC_I_Ajp[4], textAreaBuffer_AlimDC_U_Ajp[4], textAreaBuffer_AlimDC_I_Ajp[4], textAreaBuffer_Dde_Palier410_Ajp[3], textAreaBuffer_Dde_Comp2_Ajp[4],
	textAreaBuffer_Temp_Cible_Comp1_Ajp[11], textAreaBuffer_Temp_TDS410_Ajp[11], textAreaBuffer_Temp_TSC410A_Ajp[11], textAreaBuffer_Temp_TSC410B_Ajp[11], textAreaBuffer_Temp_Cible_Comp2_Ajp[11],textAreaBuffer_Temp_TDS134_Ajp[11],textAreaBuffer_Temp_TEV134_Ajp[11],textAreaBuffer_Temp_IGBT_Ajp[11], textAreaBuffer_Press_HP1_Ajp[11], textAreaBuffer_Temp_Cond1_Ajp[11], textAreaBuffer_Press_BP1_Ajp[11], textAreaBuffer_Temp_Evap1_Ajp[11],
	textAreaBuffer_Press_HPInt_Ajp[11], textAreaBuffer_Temp_CondInt_Ajp[11], textAreaBuffer_Press_HP2_Ajp[11], textAreaBuffer_Temp_Cond2_Ajp[11], textAreaBuffer_Press_BP2_Ajp[11], textAreaBuffer_Temp_Evap2_Ajp[11], textAreaBuffer_Pressostat_HP1_Ajp[4], textAreaBuffer_Pressostat_HP2_Ajp[4], textAreaBuffer_V4V_Tor_Ajp[4], textAreaBuffer_Nb_Defrost_Ajp[6], textAreaBuffer_EEV_Int_Ajp[4],textAreaBuffer_EEV_134_Ajp[4], textAreaBuffer_Electrovanne_Tor_Ajp[4],
	textAreaBuffer_Ventil_PW_Tor_Ajp[4], textAreaBuffer_Spare_Tor_Ajp[4], textAreaBuffer_ModeCompVal_Ajp[6], textAreaBuffer_FmaxFmin_Ajp[10], textAreaBuffer_Ventil_UE_Tor_Ajp[4], textAreaBuffer_Electrovanne_UE_Tor_Ajp[4], textAreaBuffer_EV3_UE_Tor_Ajp[4], textAreaBuffer_EV4_UE_Tor_Ajp[4], textAreaBuffer_EV5_UE_Tor_Ajp[4], textAreaBuffer_Ana_Vit_Ventil_UE_Tor_Ajp[5], textAreaBuffer_Led_Defaut_UE_Tor_Ajp[4], textAreaBuffer_EEV410_UE_Ajp[4],
	textAreaBuffer_Temp_TEVIN_UE_Ajp[11], textAreaBuffer_Temp_TEVOUT_UE_Ajp[11], textAreaBuffer_Vitesse_Ventil1_UE_Ajp[6], textAreaBuffer_Vitesse_Ventil2_UE_Ajp[6], textAreaBuffer_Defrost_Ajp[4];

};

#endif // VARIABLES_SYSTEMEVIEW_HPP
