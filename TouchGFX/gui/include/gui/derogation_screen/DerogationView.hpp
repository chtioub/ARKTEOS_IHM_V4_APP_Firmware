#ifndef DEROGATIONVIEW_HPP
#define DEROGATIONVIEW_HPP

#include <gui_generated/derogation_screen/DerogationViewBase.hpp>
#include <gui/derogation_screen/DerogationPresenter.hpp>

class DerogationView : public DerogationViewBase
{
public:
    DerogationView();
    virtual ~DerogationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_valider();
    void bouton_non_derog();
    void bouton_oui_derog();
    void bouton_moins_derog();
    void bouton_plus_derog();
    void timer_10ms();
    void bouton_moins_consigne();
    void bouton_plus_consigne();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ValMin, u16ValMax, u16ErreurAffichee, u16Time_Derogation, u16Consigne_Derogation, u8PressionLongue_gauche, u8PressionLongue_droite, u8PressionLongue_gauche_consigne, u8PressionLongue_droite_consigne;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Derogation[6], textAreaBuffer_Consigne[5];
};

#endif // DEROGATIONVIEW_HPP
