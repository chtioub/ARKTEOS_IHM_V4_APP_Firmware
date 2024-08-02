#ifndef INSTALLATION_HYDRAULIQUEVIEW_HPP
#define INSTALLATION_HYDRAULIQUEVIEW_HPP

#include <gui_generated/installation_hydraulique_screen/Installation_hydrauliqueViewBase.hpp>
#include <gui/installation_hydraulique_screen/Installation_hydrauliquePresenter.hpp>

class Installation_hydrauliqueView : public Installation_hydrauliqueViewBase
{
public:
    Installation_hydrauliqueView();
    virtual ~Installation_hydrauliqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_defilement_droit_type_regulation();
    void bouton_defilement_gauche_type_regulation();
    void bouton_defilement_droit_nb_pac();
    void bouton_defilement_gauche_nb_pac();
    void bouton_zone_1_directe();
    void bouton_zone_2_directe();
    void bouton_zone_1_2_zones();
    void bouton_zone_2_2_zones();
protected:
    uint8_t u8Nb_PAC, u8Regulation;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_nb_pac[2], textAreaBuffer_Titre[25];
};

#endif // INSTALLATION_HYDRAULIQUEVIEW_HPP
