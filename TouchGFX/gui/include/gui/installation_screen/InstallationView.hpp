#ifndef INSTALLATIONVIEW_HPP
#define INSTALLATIONVIEW_HPP

#include <gui_generated/installation_screen/InstallationViewBase.hpp>
#include <gui/installation_screen/InstallationPresenter.hpp>

class InstallationView : public InstallationViewBase
{
public:
    InstallationView();
    virtual ~InstallationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_mem_config();
    void bouton_mem_config_piscine();
    void bouton_mem_config_ecs();
    void bouton_modif_code();
    void bouton_raz_config();
    void bouton_freecooling();
    void bouton_dalle();
    void bouton_retour();

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
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

#endif // INSTALLATIONVIEW_HPP
