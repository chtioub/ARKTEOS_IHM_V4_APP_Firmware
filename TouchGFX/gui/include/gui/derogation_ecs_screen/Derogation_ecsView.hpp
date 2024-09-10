#ifndef DEROGATION_ECSVIEW_HPP
#define DEROGATION_ECSVIEW_HPP

#include <gui_generated/derogation_ecs_screen/Derogation_ecsViewBase.hpp>
#include <gui/derogation_ecs_screen/Derogation_ecsPresenter.hpp>

class Derogation_ecsView : public Derogation_ecsViewBase
{
public:
    Derogation_ecsView();
    virtual ~Derogation_ecsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_non_derog_ecs();
    void bouton_oui_derog_ecs();
    void bouton_valider();
    void bouton_legionel_non();
    void bouton_legionel_oui();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];

};

#endif // DEROGATION_ECSVIEW_HPP
