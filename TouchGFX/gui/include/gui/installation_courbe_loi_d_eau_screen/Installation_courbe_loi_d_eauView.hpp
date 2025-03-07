#ifndef INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
#define INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP

#include <gui_generated/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauViewBase.hpp>
#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauPresenter.hpp>

class Installation_courbe_loi_d_eauView : public Installation_courbe_loi_d_eauViewBase
{
public:
    Installation_courbe_loi_d_eauView();
    virtual ~Installation_courbe_loi_d_eauView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_valider();
    void slider_20(int sliderValue);
    void slider_15(int sliderValue);
    void slider_10(int sliderValue);
    void slider_0(int sliderValue);
    void slider_m10(int sliderValue);
    void slider_m25(int sliderValue);
    void bouton_loi_eau_20();
    void bouton_loi_eau_15();
    void bouton_loi_eau_10();
    void bouton_loi_eau_0();
    void bouton_loi_eau_m10();
    void bouton_loi_eau_m25();
    void bouton_0();
    void bouton_1();
    void bouton_2();
    void bouton_3();
    void bouton_4();
    void bouton_5();
    void bouton_6();
    void bouton_7();
    void bouton_8();
    void bouton_9();
    void bouton_supprimer();
    void bouton_valider_pave_num();
    void pave_numerique(bool bPaveNum);


    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);//SER
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    uint8_t u8NumZone;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_20[3], textAreaBuffer_15[3], textAreaBuffer_10[3], textAreaBuffer_0[3], textAreaBuffer_m10[3], textAreaBuffer_m25[3], *textAreaBuffer;
    uint16_t u16LoiDeau[6], u16LoiDeau_MAX[6], u16LoiDeau_MIN[6], u16TermoMAX, u16ValeurPaveNumeric;
    touchgfx::Slider *slider_text;
    touchgfx::TextAreaWithOneWildcard *textArea_temp_loi_eau;
};

#endif // INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
