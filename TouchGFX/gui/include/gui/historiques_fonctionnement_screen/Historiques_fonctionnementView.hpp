#ifndef HISTORIQUES_FONCTIONNEMENTVIEW_HPP
#define HISTORIQUES_FONCTIONNEMENTVIEW_HPP

#include <gui_generated/historiques_fonctionnement_screen/Historiques_fonctionnementViewBase.hpp>
#include <gui/historiques_fonctionnement_screen/Historiques_fonctionnementPresenter.hpp>

class Historiques_fonctionnementView : public Historiques_fonctionnementViewBase
{
public:
    Historiques_fonctionnementView();
    virtual ~Historiques_fonctionnementView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void maj_data();
    void maj_graphiques();
    void changement_page();
    void bouton_droit();
    void bouton_gauche();
    void bouton_retour();
protected:
    uint8_t u8AffichageGraphiques;
    touchgfx::Box box_etat_pac[360], box_appoint_chaud[360], box_appoint_ecs[360];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_temp_eau_haut[6], textAreaBuffer_temp_eau_bas[6], textAreaBuffer_temp_ext_haut[6], textAreaBuffer_temp_ext_bas[6], textAreaBuffer_Titre[30];
};

#endif // HISTORIQUES_FONCTIONNEMENTVIEW_HPP
