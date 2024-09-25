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
	virtual void bouton_retour();
protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6],  textAreaBuffer_Date[9],
	textAreaBuffer_Temp_Dep_Prim_Inv[7], textAreaBuffer_Temp_Ret_Prim_Inv[7], textAreaBuffer_Temp_Dep_Capt_Inv[7],  textAreaBuffer_Temp_Ret_Capt_Inv[7],
	textAreaBuffer_Debit_Capt_Inv[6], textAreaBuffer_Debit_Prim_Inv[6], textAreaBuffer_Percent_Circ_Cap_Inv[4],textAreaBuffer_Percent_Circ_Prim_Inv[4],
	textAreaBuffer_Temp_Ext_Inv[7], textAreaBuffer_Temp_HP_Inv[7], textAreaBuffer_Temp_BP_Inv[7], textAreaBuffer_Temp_Liq_Inv[7], textAreaBuffer_Temp_HP_Cible_Inv[6],
	textAreaBuffer_Press_Cond_Inv[7], textAreaBuffer_Press_Evap_Inv[7], textAreaBuffer_Temp_Cond_Inv[7], textAreaBuffer_Temp_Evap_Inv[7], textAreaBuffer_Hz_comp_invert[4];

	S_CYCL_REG_FRI sCyclRegFrigo_old;
};

#endif // SYNOPTIQUEVIEW_HPP
