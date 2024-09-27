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

    virtual void changeStatutRegulEsclave(S_STATUT_REGUL_ESCLAVE *sStatut_RegulEsclave);
    virtual void changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);
    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_CYCL_REG_FRI sCyclRegFrigo_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    // Primaire
    touchgfx::Unicode::UnicodeChar textArea_Buffer_tps_mise_tension[7], textArea_Buffer_AppointVal[4], textArea_Buffer_pw_consommee[7], textArea_Buffer_pw_produite[7], textAreaBuffer_PressionPrimaire[7], textAreaBuffer_DebitPrimaire[7], textAreaBuffer_ConsignePrimaire[7], textAreaBuffer_BallonTamponPrimaire[7], textAreaBuffer_BallonTamponFroid[7], textAreaBuffer_DepartPrimaire[6], textAreaBuffer_RetourPrimaire[7], textAreaBuffer_Temp_Ext[7], textAreaBuffer_CirculateurPrimaire[4], textAreaBuffer_HystBallonPlus[5], textAreaBuffer_HystBallonMoins[5], textAreaBuffer_HystExtPlus[5], textAreaBuffer_HystExtMoins[5], textAreaBuffer_TempExtEqui[5], textAreaBuffer_MaxPW[4], textAreaBuffer_AppointAutorise[4], textAreaBuffer_CircForce[4], textAreaBuffer_GestCirc[15], textAreaBuffer_AppointEnCours[4], textAreaBuffer_TypeAppoint[20], textAreaBuffer_Demande[20], textAreaBuffer_DemandeCascade[20], textAreaBuffer_CascadePresence[9], textAreaBuffer_CascadeTotal[3], textAreaBuffer_CascadeOn[3], textAreaBuffer_CascadeDispo[3], textAreaBuffer_NumLigne[99][3];
};

#endif // VARIABLES_SYSTEMEVIEW_HPP
