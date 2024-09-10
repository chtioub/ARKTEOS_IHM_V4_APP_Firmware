#ifndef PARAMETRESVIEW_HPP
#define PARAMETRESVIEW_HPP

#include <gui_generated/parametres_screen/ParametresViewBase.hpp>
#include <gui/parametres_screen/ParametresPresenter.hpp>

class ParametresView : public ParametresViewBase
{
public:
    ParametresView();
    virtual ~ParametresView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
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

#endif // PARAMETRESVIEW_HPP
