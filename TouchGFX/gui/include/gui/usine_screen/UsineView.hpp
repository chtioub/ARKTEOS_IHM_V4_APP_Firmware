#ifndef USINEVIEW_HPP
#define USINEVIEW_HPP

#include <gui_generated/usine_screen/UsineViewBase.hpp>
#include <gui/usine_screen/UsinePresenter.hpp>

class UsineView : public UsineViewBase
{
public:
    UsineView();
    virtual ~UsineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_raz_code_maintenance();
    void bouton_raz_code_installation();
    void bouton_raz_config_usine();
    void bouton_derog_pression_bp();
    void bouton_retour();

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

#endif // USINEVIEW_HPP
