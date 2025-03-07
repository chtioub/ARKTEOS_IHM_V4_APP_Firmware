#ifndef INSTALLATION_CONFIG_IN_OUTVIEW_HPP
#define INSTALLATION_CONFIG_IN_OUTVIEW_HPP

#include <gui_generated/installation_config_in_out_screen/Installation_config_in_outViewBase.hpp>
#include <gui/installation_config_in_out_screen/Installation_config_in_outPresenter.hpp>

class Installation_config_in_outView : public Installation_config_in_outViewBase
{
public:
    Installation_config_in_outView();
    virtual ~Installation_config_in_outView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider();
    void bouton_ejp();
    void bouton_delestage();
    void bouton_abaissement();
    void bouton_th1();
    void bouton_th2();
    void bouton_marche_arret_zones();
    void bouton_chaud_froid();
    void bouton_marche_arret_general();
    void bouton_fonction_4();
    void bouton_fonction_5();
    void bouton_fonction_6();
    void bouton_fonction_7();
    void bouton_adapt_loi_deau();
    void bouton_adapt_consigne();
    void bouton_resistance_carter();
    void bouton_releve_PAC();
    void bouton_info_chaud_froid();
    void bouton_defaut_general();
    void bouton_chaud_froid_voie_1();
    void bouton_chaud_froid_voie_2();
    void bouton_info_marche_arret_comp();
    void bouton_fonction_8();
    void bouton_fonction_9();
    void bouton_fonction_10();
    //void affectation_entree();

    void MAJ_voie_ejp();
    void MAJ_voie_delestage();
    void MAJ_voie_abaissement();
    void MAJ_voie_th1();
    void MAJ_voie_th2();
    void MAJ_voie_InxMarcheArret();
    void MAJ_voie_InxChaudFroid();
    void MAJ_voie_InxMarcheArretGeneral();
    void MAJ_voie_InxFonction4();
    void MAJ_voie_InxFonction5();
    void MAJ_voie_InxFonction6();
    void MAJ_voie_InxFonction7();
    void MAJ_voie_AdaptLoiDeau();
    void MAJ_voie_AdaptConsigne();

    void MAJ_voie_OutxResistance();
    void MAJ_voie_OutxReleve();
    void MAJ_voie_OutxChaudFroid();
    void MAJ_voie_OutxDefautGeneral();
    void MAJ_voie_OutxChaudFroid1();
    void MAJ_voie_OutxChaudFroid2();
    void MAJ_voie_OutxInfoMarcheArret();
    void MAJ_voie_OutxFonction8();
    void MAJ_voie_OutxFonction9();
    void MAJ_voie_OutxFonction10();

    void controle_doublon();
    void MAJ_TabInOutTor();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee,InxAdaptationLoiDeau,InxAdaptationConsigne,InxEJP,InxDelestage,InxAbaissementConsigne,InxTH1,InxTH2,InxMarcheArret,
	InxChaudFroid,InxMarcheArretGeneral,InxFonction4, InxFonction5, InxFonction6, InxFonction7,
	OutxCarter,OutxRelevePAC,OutxModeChaudFroid,OutxInfoDefautPAC,OutxChaudFroidVoie1,OutxChaudFroidVoie2,
	OutxInfoMarcheArret,OutxFonction8, OutxFonction9, OutxFonction10;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBufferEJP[3], textAreaBufferDelestage[3],
	textAreaBufferAbaissement[3], textAreaBufferTh1[3], textAreaBufferTh2[3], textAreaBufferMarcheArretZones[3],  textAreaBufferChaudFroid[3],  textAreaBufferMarcheArretGeneral[3],
	textAreaBufferFonction4[3], textAreaBufferFonction5[3], textAreaBufferFonction6[3], textAreaBufferFonction7[3], textAreaBufferAdaptLoiDeau[3], textAreaBufferAdaptConsigne[3],
	textAreaBufferResistanceCarter[3], textAreaBufferRelevePac[3], textAreaBufferInfoChaudFroid[3], textAreaBufferDefautGeneralPac[3], textAreaBufferChaudFroidVoie1[3], textAreaBufferChaudFroidVoie2[3],
	textAreaBufferMarcheArretComp[3], textAreaBufferFonction8[3], textAreaBufferFonction9[3], textAreaBufferFonction10[3];
    uint16_t tabInOutTor[24];
};

#endif // INSTALLATION_CONFIG_IN_OUTVIEW_HPP
