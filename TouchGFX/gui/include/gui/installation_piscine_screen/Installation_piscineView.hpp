#ifndef INSTALLATION_PISCINEVIEW_HPP
#define INSTALLATION_PISCINEVIEW_HPP

#include <gui_generated/installation_piscine_screen/Installation_piscineViewBase.hpp>
#include <gui/installation_piscine_screen/Installation_piscinePresenter.hpp>

class Installation_piscineView : public Installation_piscineViewBase
{
public:
    Installation_piscineView();
    virtual ~Installation_piscineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_piscine_non();
    void bouton_piscine_oui();
    void bouton_piscine();
    void bouton_maison();
    void bouton_50_50();
    void bouton_consigne_moins();
    void bouton_consigne_plus();
    void bouton_simultane();
    void bouton_hysteresis();
    void bouton_valider();
    void timer_10ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

protected:
    bool bConnexionDistance;
    uint8_t u8PressionLongue_droite, u8PressionLongue_gauche;
    uint16_t u16ErreurAffichee, u16ConsignePiscine;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Temp[5];
};

#endif // INSTALLATION_PISCINEVIEW_HPP
