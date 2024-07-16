#ifndef EAU_CHAUDE_SANITAIREVIEW_HPP
#define EAU_CHAUDE_SANITAIREVIEW_HPP

#include <gui_generated/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireViewBase.hpp>
#include <gui/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.hpp>

class Eau_chaude_sanitaireView : public Eau_chaude_sanitaireViewBase
{
public:
    Eau_chaude_sanitaireView();
    virtual ~Eau_chaude_sanitaireView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void slider_consigne(int sliderValue);
    void slider_relance(int sliderValue);
protected:
    float fConsigne, fRelance;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_consigne[5];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_relance[5];
};

#endif // EAU_CHAUDE_SANITAIREVIEW_HPP
