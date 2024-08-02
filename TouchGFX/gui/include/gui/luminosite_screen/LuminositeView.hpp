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
protected:
    uint8_t u8Luminosite;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[30], textAreaBuffer_Luminosite[4];
};

#endif // LUMINOSITEVIEW_HPP
