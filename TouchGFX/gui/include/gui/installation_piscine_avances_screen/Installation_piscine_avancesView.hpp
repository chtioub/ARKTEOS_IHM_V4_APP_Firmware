#ifndef INSTALLATION_PISCINE_AVANCESVIEW_HPP
#define INSTALLATION_PISCINE_AVANCESVIEW_HPP

#include <gui_generated/installation_piscine_avances_screen/Installation_piscine_avancesViewBase.hpp>
#include <gui/installation_piscine_avances_screen/Installation_piscine_avancesPresenter.hpp>

class Installation_piscine_avancesView : public Installation_piscine_avancesViewBase
{
public:
    Installation_piscine_avancesView();
    virtual ~Installation_piscine_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_vanne_moins();
    void bouton_vanne_plus();
    void bouton_confort();
    void bouton_valider();
    void timer_10ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8TpsBasculementVanne, u8PressionLongue_droite, u8PressionLongue_gauche;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_TpsBasculementVanne[15];
};

#endif // INSTALLATION_PISCINE_AVANCESVIEW_HPP
