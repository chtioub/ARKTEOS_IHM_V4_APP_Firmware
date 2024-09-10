#ifndef INSTALLATION_WATTMETREVIEW_HPP
#define INSTALLATION_WATTMETREVIEW_HPP

#include <gui_generated/installation_wattmetre_screen/Installation_wattmetreViewBase.hpp>
#include <gui/installation_wattmetre_screen/Installation_wattmetrePresenter.hpp>

class Installation_wattmetreView : public Installation_wattmetreViewBase
{
public:
    Installation_wattmetreView();
    virtual ~Installation_wattmetreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_wattmetre_non();
    void bouton_wattmetre_oui();
    void bouton_nb_impulsions();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee, u16NbImpulsions;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Impulsions[5];
};

#endif // INSTALLATION_WATTMETREVIEW_HPP
