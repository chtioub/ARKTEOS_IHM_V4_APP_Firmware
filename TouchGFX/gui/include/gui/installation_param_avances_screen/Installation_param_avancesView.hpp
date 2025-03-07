#ifndef INSTALLATION_PARAM_AVANCESVIEW_HPP
#define INSTALLATION_PARAM_AVANCESVIEW_HPP

#include <gui_generated/installation_param_avances_screen/Installation_param_avancesViewBase.hpp>
#include <gui/installation_param_avances_screen/Installation_param_avancesPresenter.hpp>

class Installation_param_avancesView : public Installation_param_avancesViewBase
{
public:
    Installation_param_avancesView();
    virtual ~Installation_param_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_resistance_carter();
    void bouton_menu_special();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // INSTALLATION_PARAM_AVANCESVIEW_HPP
