#ifndef PISCINEVIEW_HPP
#define PISCINEVIEW_HPP

#include <gui_generated/piscine_screen/PiscineViewBase.hpp>
#include <gui/piscine_screen/PiscinePresenter.hpp>

class PiscineView : public PiscineViewBase
{
public:
    PiscineView();
    virtual ~PiscineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void slider_reduit(int sliderValue);
    void slider_normal(int sliderValue);
    void slider_confort(int sliderValue);
    void bouton_arret();
    void bouton_marche();
    void bouton_moins_reduit();
    void bouton_plus_reduit();
    void bouton_moins_normal();
    void bouton_plus_normal();
    void bouton_moins_confort();
    void bouton_plus_confort();
protected:
    uint16_t u16ConsigneReduit, u16ConsigneNormal, u16ConsigneConfort;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_ConsigneReduit[5], textAreaBuffer_ConsigneNormal[5], textAreaBuffer_ConsigneConfort[5], textAreaBuffer_Titre[25];
};

#endif // PISCINEVIEW_HPP
