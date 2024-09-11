#ifndef INSTALLATION_CONFIG_IN_OUTVIEW_HPP
#define INSTALLATION_CONFIG_IN_OUTVIEW_HPP

#include <gui_generated/installation_config_in_out_screen/Installation_config_in_outViewBase.hpp>
#include <gui/installation_config_in_out_screen/Installation_config_in_outPresenter.hpp>

class Installation_config_in_outView : public Installation_config_in_outViewBase
{
public:
    Installation_config_in_outView();
    virtual ~Installation_config_in_outView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider();

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

#endif // INSTALLATION_CONFIG_IN_OUTVIEW_HPP
