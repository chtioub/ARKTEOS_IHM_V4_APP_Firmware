#ifndef ZONEVIEW_HPP
#define ZONEVIEW_HPP

#include <gui_generated/zone_screen/ZoneViewBase.hpp>
#include <gui/zone_screen/ZonePresenter.hpp>

class ZoneView : public ZoneViewBase
{
public:
    ZoneView();
    virtual ~ZoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_arret();
    void bouton_chaud();
    void bouton_froid();
    void bouton_prog();
    void bouton_appoint();
    void bouton_hors_gel();
    void slider_reduit(int sliderValue);
    void slider_normal(int sliderValue);
    void slider_confort(int sliderValue);
    void bouton_moins_reduit();
    void bouton_plus_reduit();
    void bouton_moins_normal();
    void bouton_plus_normal();
    void bouton_moins_confort();
    void bouton_plus_confort();
protected:
    uint16_t u16ConsigneReduit, u16ConsigneNormal, u16ConsigneConfort;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_ConsigneReduit[5], textAreaBuffer_ConsigneNormal[5], textAreaBuffer_ConsigneConfort[5], textAreaBuffer[25];
};

#endif // ZONEVIEW_HPP
