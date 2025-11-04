#ifndef VERIFICATION_ANNUELLEVIEW_HPP
#define VERIFICATION_ANNUELLEVIEW_HPP

#include <gui_generated/verification_annuelle_screen/Verification_annuelleViewBase.hpp>
#include <gui/verification_annuelle_screen/Verification_annuellePresenter.hpp>

class Verification_annuelleView : public Verification_annuelleViewBase
{
public:
    Verification_annuelleView();
    virtual ~Verification_annuelleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider_message();

    touchgfx::Unicode::UnicodeChar  textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[800];
protected:
};

#endif // VERIFICATION_ANNUELLEVIEW_HPP
