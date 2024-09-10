#ifndef LUMINOSITEVIEW_HPP
#define LUMINOSITEVIEW_HPP

#include <gui_generated/luminosite_screen/LuminositeViewBase.hpp>
#include <gui/luminosite_screen/LuminositePresenter.hpp>

class LuminositeView : public LuminositeViewBase
{
public:
    LuminositeView();
    virtual ~LuminositeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void slider_lumi(int sliderValue);
    void bouton_moins();
    void bouton_plus();
    void bouton_valider();
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8Luminosite;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Luminosite[4];
};

#endif // LUMINOSITEVIEW_HPP
