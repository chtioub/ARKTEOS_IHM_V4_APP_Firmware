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
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_20[3], textAreaBuffer_15[3], textAreaBuffer_10[3], textAreaBuffer_0[3], textAreaBuffer_m10[3], textAreaBuffer_m25[3];
    uint16_t u16LoiDeau[6], u16TermoMAX;
};

#endif // INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
