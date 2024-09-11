#ifndef CONFIGURATIONVIEW_HPP
#define CONFIGURATIONVIEW_HPP

#include <gui_generated/configuration_screen/ConfigurationViewBase.hpp>
#include <gui/configuration_screen/ConfigurationPresenter.hpp>

class ConfigurationView : public ConfigurationViewBase
{
public:
    ConfigurationView();
    virtual ~ConfigurationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_maintenance();
    void bouton_installation();
    void bouton_usine();

    void changeConfig(S_CONFIG_IHM *sConfig_IHM);
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

#endif // CONFIGURATIONVIEW_HPP
