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

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);

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
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    // Primaire
    touchgfx::Unicode::UnicodeChar textArea_Buffer_tps_mise_tension[7], textArea_Buffer_pw_consommee[7], textArea_Buffer_pw_produite[7], textAreaBuffer_PressionPrimaire[7], textAreaBuffer_DebitPrimaire[7], textAreaBuffer_ConsignePrimaire[7], textAreaBuffer_BallonTamponPrimaire[7], textAreaBuffer_DepartPrimaire[6], textAreaBuffer_RetourPrimaire[7], textAreaBuffer_CirculateurPrimaire[4], textAreaBuffer_HystBallonPlus[5], textAreaBuffer_HystBallonMoins[5], textAreaBuffer_HystExtPlus[5], textAreaBuffer_HystExtMoins[5], textAreaBuffer_NumLigne[99][3];
};

#endif // VARIABLES_SYSTEMEVIEW_HPP
