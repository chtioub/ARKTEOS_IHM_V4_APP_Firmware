#ifndef USINE_PARAM_AVANCESVIEW_HPP
#define USINE_PARAM_AVANCESVIEW_HPP

#include <gui_generated/usine_param_avances_screen/Usine_param_avancesViewBase.hpp>
#include <gui/usine_param_avances_screen/Usine_param_avancesPresenter.hpp>

class Usine_param_avancesView : public Usine_param_avancesViewBase
{
public:
    Usine_param_avancesView();
    virtual ~Usine_param_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_redemarrer();
    void bouton_raz_soft();
    void bouton_raz_log_ether();
    void bouton_raz_tps_fonct();
    void bouton_raz_energies();
    //void bouton_calibrage_sondes();

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
};

#endif // USINE_PARAM_AVANCESVIEW_HPP
