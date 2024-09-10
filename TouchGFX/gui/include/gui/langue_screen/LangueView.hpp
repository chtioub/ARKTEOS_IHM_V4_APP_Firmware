#ifndef LANGUEVIEW_HPP
#define LANGUEVIEW_HPP

#include <gui_generated/langue_screen/LangueViewBase.hpp>
#include <gui/langue_screen/LanguePresenter.hpp>

class LangueView : public LangueViewBase
{
public:
    LangueView();
    virtual ~LangueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_droit();
    void bouton_gauche();
    void bouton_valider();
    void changementLangue();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8Langue;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // LANGUEVIEW_HPP
