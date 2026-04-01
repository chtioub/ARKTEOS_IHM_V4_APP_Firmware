#ifndef MAINTENANCE_TEST_COMPOSANTSVIEW_HPP
#define MAINTENANCE_TEST_COMPOSANTSVIEW_HPP

#include <gui_generated/maintenance_test_composants_screen/Maintenance_test_composantsViewBase.hpp>
#include <gui/maintenance_test_composants_screen/Maintenance_test_composantsPresenter.hpp>

class Maintenance_test_composantsView : public Maintenance_test_composantsViewBase
{
public:
    Maintenance_test_composantsView();
    virtual ~Maintenance_test_composantsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void bouton_valider();
    void bouton_circulateur_reg();
    void bouton_vanne_melange_reg();
    void bouton_relais_reg();
    void bouton_sortie_ana_ecs();
    void bouton_circulateur_ecs();
    void bouton_appoint_ecs();
    void bouton_v3v_ecs();
    void bouton_relais_mz();
    void bouton_0_10_mz();
    void bouton_carte_mz();
    void bouton_voie_carte_mz();
    void bouton_relais_appoint();
    void bouton_relais_v4v();
    void bouton_relais_rv();
    void bouton_relais_ev();
    void bouton_relais_rc();
    void bouton_relais_c1();
    void bouton_relais_c2();
    void bouton_relais_puits();
    void bouton_detendeur();
    void bouton_relais_geot();
    void bouton_circulateur_geot();
    void bouton_relais_spa1();
    void bouton_relais_spa2();
    void bouton_relais_cric_vent();
    void bouton_relais_circ_prim();
    void bouton_out_ventil();
    void bouton_out_option();
    void bouton_out_det1();
    void bouton_out_det2();
    void bouton_out_det3();
    void bouton_out_det4();
    void updateNumVoie();
    void updateNumCarte();
    void timer_1s();
protected:
    bool bConnexionDistance;
   	uint16_t u16ErreurAffichee;
   	uint8_t u8NumVoie, u8NumCarte, u8TimerCircRegP, u8TimerCircRegZ1, u8TimerCircRegZ2, u8TimerVanneMel, u8TimerRelaisReg, u8TimerSortieAnaECS,
   	u8TimerRelaisCircECS, u8TimerRelaisAppECS, u8TimerV3VECS,u8TimerRelaisMZ,u8TimerSortieAnaMZ,u8TimerRelaisAppoint, u8TimerRelaisC1, u8TimerRelaisC2,u8TimerDetGeot, u8TimerRelaisGeot, u8TimerRelaisCircGeot;
   	bool bButtonV4VOn, bButtonRVOn, bButtonEVOn, bButtonRCOn, bButtonSpa1On, bButtonSpa2On, bButtonPuitsOn, bButtonVentCaptsOn, bButtonCircPrimOn, bButtonOutVentil,
   	bButtonOutOption, bButtonOutDet1, bButtonOutDet2, bButtonOutDet3,bButtonOutDet4;
   	S_DATE sDate_old;
   	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9],textAreaBuffer_NumVoie[8];
};

#endif // MAINTENANCE_TEST_COMPOSANTSVIEW_HPP
