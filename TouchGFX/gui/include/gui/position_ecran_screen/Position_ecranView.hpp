#ifndef POSITION_ECRANVIEW_HPP
#define POSITION_ECRANVIEW_HPP

#include <gui_generated/position_ecran_screen/Position_ecranViewBase.hpp>
#include <gui/position_ecran_screen/Position_ecranPresenter.hpp>

class Position_ecranView : public Position_ecranViewBase
{
public:
    Position_ecranView();
    virtual ~Position_ecranView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_valider();
    void bouton_droit();
    void bouton_gauche();
    void bouton_bas();
    void bouton_haut();
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[30], textAreaBuffer_OffsetX[3], textAreaBuffer_OffsetY[3];
};

#endif // POSITION_ECRANVIEW_HPP
