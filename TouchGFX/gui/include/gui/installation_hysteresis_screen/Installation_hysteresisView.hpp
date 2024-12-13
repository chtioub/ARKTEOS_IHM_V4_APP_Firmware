#ifndef INSTALLATION_HYSTERESISVIEW_HPP
#define INSTALLATION_HYSTERESISVIEW_HPP

#include <gui_generated/installation_hysteresis_screen/Installation_hysteresisViewBase.hpp>
#include <gui/installation_hysteresis_screen/Installation_hysteresisPresenter.hpp>

class Installation_hysteresisView : public Installation_hysteresisViewBase
{
public:
    Installation_hysteresisView();
    virtual ~Installation_hysteresisView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

//    virtual void Red_Butt();
//    virtual void Blue_Butt();
    void Slider_Plus(int valSlid);
    void Slider_Moins(int valSlid);
//    virtual void Slid_Plus_Show();
//    virtual void Slid_Moins_Show();
protected:
    uint16_t u16ValMin, u16ValMax;
    int16_t  i16OffsetFleGau, i16OffsetFleDro, i16OffsetLblMoins, i16OffsetLblPlus;
    bool bConnexionDistance;
       uint8_t u8Nb_PAC;
       uint16_t u16ErreurAffichee;
       S_DATE sDate_old;
       S_CONFIG_IHM sConfig_IHM_old;
       S_STATUT_PAC sStatut_PAC_old;
       touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_hyst_moins[5], textAreaBuffer_hyst_plus[5];
};

#endif // INSTALLATION_HYSTERESISVIEW_HPP
