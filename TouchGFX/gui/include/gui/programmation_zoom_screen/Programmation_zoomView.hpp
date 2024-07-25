#ifndef PROGRAMMATION_ZOOMVIEW_HPP
#define PROGRAMMATION_ZOOMVIEW_HPP

#include <gui_generated/programmation_zoom_screen/Programmation_zoomViewBase.hpp>
#include <gui/programmation_zoom_screen/Programmation_zoomPresenter.hpp>

class Programmation_zoomView : public Programmation_zoomViewBase
{
public:
    Programmation_zoomView();
    virtual ~Programmation_zoomView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_plus();
    void bouton_moins();
    void slider_zoom_fonction(int slidervalue);
    void slider_zoom_plus_fonction(int slidervalue);
    void majTexteHeures(uint8_t u8Origine);
    void bouton_prog_1();
    void bouton_prog_2();
    void bouton_prog_3();
    void bouton_prog_4();
    void bouton_prog_5();
    void bouton_prog_6();
    void editerProg(uint8_t u8NumeroProg,uint8_t u8Prog);
    void boutonProg(uint8_t u8NumeroProg,uint8_t u8Prog);
protected:
    uint8_t u8NiveauZoom, u8Prog_1, u8Prog_2, u8Prog_3, u8Prog_4, u8Prog_5, u8Prog_6;
    uint8_t u8ValeurProg[96];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_1[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_2[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_3[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_4[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_5[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_6[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_7[3];
};

#endif // PROGRAMMATION_ZOOMVIEW_HPP
