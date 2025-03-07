#ifndef SECOURSVIEW_HPP
#define SECOURSVIEW_HPP

#include <gui_generated/secours_screen/SecoursViewBase.hpp>
#include <gui/secours_screen/SecoursPresenter.hpp>

class SecoursView : public SecoursViewBase
{
public:
    SecoursView();
    virtual ~SecoursView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_secours_ecs();
    void bouton_secours_pac();
    void bouton_retour();
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
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

#endif // SECOURSVIEW_HPP
