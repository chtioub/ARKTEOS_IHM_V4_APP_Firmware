#ifndef SYNOPTIQUEVIEW_HPP
#define SYNOPTIQUEVIEW_HPP

#include <gui_generated/synoptique_screen/SynoptiqueViewBase.hpp>
#include <gui/synoptique_screen/SynoptiquePresenter.hpp>

class SynoptiqueView : public SynoptiqueViewBase
{
public:
    SynoptiqueView();
    virtual ~SynoptiqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);
	virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);
	virtual void bouton_retour();

	void update_container();

	void bouton_gauche();
	void bouton_droit();

protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
    uint8_t u8Page;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6],  textAreaBuffer_Date[9],
	textAreaBuffer_Temp_Ext[7],
	textAreaBuffer_Temp_Dep_Prim_Inv[7], textAreaBuffer_Temp_Ret_Prim_Inv[7], textAreaBuffer_Temp_Dep_Capt_Inv[7],  textAreaBuffer_Temp_Ret_Capt_Inv[7],
	textAreaBuffer_Debit_Capt_Inv[6], textAreaBuffer_Debit_Prim_Inv[6], textAreaBuffer_Percent_Circ_Cap_Inv[4],textAreaBuffer_Percent_Circ_Prim_Inv[4],
	textAreaBuffer_Temp_HP1_Inv[7], textAreaBuffer_Temp_BP1_Inv[7], textAreaBuffer_Temp_Liq_Inv[7], textAreaBuffer_Temp_HP_Cible_Inv[6],
	textAreaBuffer_Press_Cond_Inv[7], textAreaBuffer_Press_Evap_Inv[7], textAreaBuffer_Temp_Cond_Inv[7], textAreaBuffer_Temp_Evap_Inv[7], textAreaBuffer_Hz_comp_invert[8],
	textAreaBuffer_Position_EEV[4],
	textAreaBuffer_comp_2[4],textAreaBuffer_Temp_HP2_Inv[7], textAreaBuffer_Temp_BP2_Inv[7],
	textAreaBuffer_Temp_In_UE_ajp[4],textAreaBuffer_Temp_Out_UE_ajp[7], textAreaBuffer_Temp_In_Bout_Liqu_ajp[7],  textAreaBuffer_Temp_HP_Comp_410_ajp[7],textAreaBuffer_Percent_Ventil_UE_ajp[4],
	textAreaBuffer_EV_UE_ajp[4],textAreaBuffer_EV_UI_ajp[4], textAreaBuffer_EEV_410_BP_ajp[4],textAreaBuffer_Palier_Comp_410_ajp[4], textAreaBuffer_freq_Comp_410_ajp[4],
	textAreaBuffer_Press_Cond_410_ajp[7], textAreaBuffer_Press_Evap_410_ajp[7], textAreaBuffer_Temp_Cond_410_ajp[7], textAreaBuffer_Temp_Evap_410_ajp[7], textAreaBuffer_Press_Cond2_410_ajp[7],
	textAreaBuffer_Temp_Cond2_P1_410_ajp[7],textAreaBuffer_Temp_HP_Cible_410_ajp[7],
	textAreaBuffer_Temp_Cond2_P2_410_ajp[7],textAreaBuffer_Temp_Liq_Evap_Cond_P2_ajp[7],textAreaBuffer_Temp_Liq_Cond410_P2_ajp[7],textAreaBuffer_Temp_Liq_Cond134_P2_ajp[7],textAreaBuffer_Temp_HP_Cible_134_ajp[7],
    textAreaBuffer_Temp_HP_134_ajp[7],textAreaBuffer_T_Dep_Prim_ajp[7],textAreaBuffer_T_Ret_Prim_ajp[7],textAreaBuffer_DebitPrim_ajp[7],textAreaBuffer_Percent_Circ_ajp[4], textAreaBuffer_EEV_410_P2_ajp[4],textAreaBuffer_EEV_134_P2_ajp[7],
	textAreaBuffer_Press_Cond_134_ajp[7],textAreaBuffer_Press_Evap_134_ajp[7],textAreaBuffer_Temp_Cond_134_ajp[7],textAreaBuffer_Temp_Evap_134_ajp[7],textAreaBuffer_Press_410_P2_ajp[7],textAreaBuffer_TempCond_410_P2_ajp[7],
	textAreaBuffer_Temp_HP_mitsu[7],textAreaBuffer_EEVA_mitsu[4],textAreaBuffer_EEVB_mitsu[4],textAreaBuffer_EEVC_mitsu[4],textAreaBuffer_Temp_Cond_mitsu[7],textAreaBuffer_Press_Cond_mitsu[7],textAreaBuffer_Temp_Batt_Milieu_mitsu[7],textAreaBuffer_Temp_In_Batt_mitsu[7],
	textAreaBuffer_Vit_Ventil1_mitsu[7],textAreaBuffer_Vit_Ventil2_mitsu[7],textAreaBuffer_Temp_BP_mitsu[7],textAreaBuffer_Frequence_mitsu[6],textAreaBuffer_Temp_Dep_Prim_mitsu[7],textAreaBuffer_Temp_Ret_Prim_mitsu[7],textAreaBuffer_Temp_Debit_mitsu[7],
	textAreaBuffer_Percent_Circ_mitsu[4], textAreaBuffer_Temp_Liquide_mitsu[7], textAreaBuffer_Temp_Retour_Eau_mitsu[7];
	S_CYCL_REG_FRI sCyclRegFrigo_old;
};

#endif // SYNOPTIQUEVIEW_HPP
