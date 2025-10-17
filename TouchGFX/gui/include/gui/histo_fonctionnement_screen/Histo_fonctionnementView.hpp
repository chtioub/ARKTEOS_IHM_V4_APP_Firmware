#ifndef HISTO_FONCTIONNEMENTVIEW_HPP
#define HISTO_FONCTIONNEMENTVIEW_HPP

#include <gui_generated/histo_fonctionnement_screen/Histo_fonctionnementViewBase.hpp>
#include <gui/histo_fonctionnement_screen/Histo_fonctionnementPresenter.hpp>
#include <touchgfx/Color.hpp>

class Histo_fonctionnementView : public Histo_fonctionnementViewBase
{
public:
    Histo_fonctionnementView();
    virtual ~Histo_fonctionnementView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void timer_10s();
    void clear_graph();
    void bouton_droit();
    void bouton_gauche();
    void update_container();


protected:
    touchgfx::Unicode::UnicodeChar textArea_Buffer_temp_gauche_max[7], textArea_Buffer_temp_gauche_min[7], textArea_Buffer_temp_droite_max[7], textArea_Buffer_temp_droite_min[7];
    uint16_t u16TempBallon_Z1[360],u16Temp_Z2[360], u16TempDepart[360],u16TempRetour[360], u16PointeurTableau;//, u16StartIndex;
    uint16_t u16ValmaxAmbBall, u16ValminAmbBall,  u16ValmaxTeau,u16ValminTeau;
    int16_t i16ValmaxText, i16ValminText, i16TempExt[360];
    bool bTableauPlein, bGraphPage1, bAffichageTempBallon, bPremierPassage;
    touchgfx::Box box_etat[360], box_arret, box_chaud;
    const touchgfx::colortype RED = touchgfx::Color::getColorFromRGB(255, 0, 0);    // rouge
    const touchgfx::colortype GREEN = touchgfx::Color::getColorFromRGB(0, 255, 0);    // vert
    const touchgfx::colortype BLUE = touchgfx::Color::getColorFromRGB(0, 0, 255);    // bleu
    const touchgfx::colortype COLOR4 = touchgfx::Color::getColorFromRGB(255, 255, 0);  // jaune
    const touchgfx::colortype COLOR5 = touchgfx::Color::getColorFromRGB(255, 165, 0);  // orange
};

#endif // HISTO_FONCTIONNEMENTVIEW_HPP
