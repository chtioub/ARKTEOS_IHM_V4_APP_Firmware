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
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[30];
    uint8_t u8Langue;
};

#endif // LANGUEVIEW_HPP
