#ifndef INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
#define INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP

#include <gui_generated/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauViewBase.hpp>
#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauPresenter.hpp>

class Installation_courbe_loi_d_eauView : public Installation_courbe_loi_d_eauViewBase
{
public:
    Installation_courbe_loi_d_eauView();
    virtual ~Installation_courbe_loi_d_eauView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void slider_20(int sliderValue);
    void slider_15(int sliderValue);
    void slider_10(int sliderValue);
    void slider_0(int sliderValue);
    void slider_m10(int sliderValue);
    void slider_m25(int sliderValue);
    void bouton_loi_eau_20();
    void bouton_loi_eau_15();
    void bouton_loi_eau_10();
    void bouton_loi_eau_0();
    void bouton_loi_eau_m10();
    void bouton_loi_eau_m25();
    void bouton_0();
    void bouton_1();
    void bouton_2();
    void bouton_3();
    void bouton_4();
    void bouton_5();
    void bouton_6();
    void bouton_7();
    void bouton_8();
    void bouton_9();
    void bouton_supprimer();
    void bouton_valider();
    void pave_numerique(bool bPaveNum);
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_20[3], textAreaBuffer_15[3], textAreaBuffer_10[3], textAreaBuffer_0[3], textAreaBuffer_m10[3], textAreaBuffer_m25[3], *textAreaBuffer, textAreaBuffer_Titre[25];
    uint16_t u16LoiDeau[6], u16TermoMAX, u16ValeurPaveNumeric;
    touchgfx::Slider *slider_text;
    touchgfx::TextAreaWithOneWildcard *textArea_temp_loi_eau;
};

#endif // INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
