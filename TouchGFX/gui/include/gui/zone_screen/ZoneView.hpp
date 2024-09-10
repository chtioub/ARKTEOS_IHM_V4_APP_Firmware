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
    void bouton_retour();
    void timer_100ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
protected:
    bool bConnexionDistance;
    uint8_t u8NbZone;
    uint16_t u16ErreurAffichee, u16ValMin, u16ValMax;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    uint16_t u16ConsigneReduit, u16ConsigneNormal, u16ConsigneConfort, u16TempoEnvoiConsigne;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_ConsigneReduit[6], textAreaBuffer_ConsigneNormal[6], textAreaBuffer_ConsigneConfort[6];
};

#endif // ZONEVIEW_HPP
