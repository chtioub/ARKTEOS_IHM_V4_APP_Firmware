#ifndef ENERGIESVIEW_HPP
#define ENERGIESVIEW_HPP

#include <gui_generated/energies_screen/EnergiesViewBase.hpp>
#include <gui/energies_screen/EnergiesPresenter.hpp>

class EnergiesView : public EnergiesViewBase
{
public:
    EnergiesView();
    virtual ~EnergiesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_histo_conso();
    void bouton_cumul_conso();

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

#endif // ENERGIESVIEW_HPP
