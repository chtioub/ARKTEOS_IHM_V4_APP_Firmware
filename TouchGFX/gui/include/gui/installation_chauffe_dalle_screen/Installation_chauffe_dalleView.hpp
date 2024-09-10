#ifndef INSTALLATION_CHAUFFE_DALLEVIEW_HPP
#define INSTALLATION_CHAUFFE_DALLEVIEW_HPP

#include <gui_generated/installation_chauffe_dalle_screen/Installation_chauffe_dalleViewBase.hpp>
#include <gui/installation_chauffe_dalle_screen/Installation_chauffe_dallePresenter.hpp>

class Installation_chauffe_dalleView : public Installation_chauffe_dalleViewBase
{
public:
    Installation_chauffe_dalleView();
    virtual ~Installation_chauffe_dalleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void slider_j1(int sliderValue);
    void slider_j2(int sliderValue);
    void slider_j3(int sliderValue);
    void slider_j4(int sliderValue);
    void slider_j5(int sliderValue);
    void slider_j6(int sliderValue);
    void slider_j7(int sliderValue);
    void slider_j8(int sliderValue);
    void slider_j9(int sliderValue);
    void slider_j10(int sliderValue);
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_TempJour[10][3];
};

#endif // INSTALLATION_CHAUFFE_DALLEVIEW_HPP
