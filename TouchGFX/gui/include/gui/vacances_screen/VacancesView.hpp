#ifndef VACANCESVIEW_HPP
#define VACANCESVIEW_HPP

#include <gui_generated/vacances_screen/VacancesViewBase.hpp>
#include <gui/vacances_screen/VacancesPresenter.hpp>

class VacancesView : public VacancesViewBase
{
public:
    VacancesView();
    virtual ~VacancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void slider_pisc(int sliderValue);
    void bouton_piscine();
    void bouton_piscine_plus();
    void bouton_piscine_moins();

    void bouton_zone_1();
    void bouton_zone_2();
    void bouton_zone_3();
    void bouton_zone_4();
    void bouton_zone_5();
    void bouton_zone_6();
    void bouton_zone_7();
    void bouton_zone_8();
    void bouton_zone_x(touchgfx::ToggleButton *toggleButton_zone, touchgfx::Container *container_slider_zone);

    void slider_zone1(int sliderValue);
    void slider_zone2(int sliderValue);
    void slider_zone3(int sliderValue);
    void slider_zone4(int sliderValue);
    void slider_zone5(int sliderValue);
    void slider_zone6(int sliderValue);
    void slider_zone7(int sliderValue);
    void slider_zone8(int sliderValue);
    void slider_zone_x(uint8_t u8Zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone);

    void bouton_zone_1_plus();
    void bouton_zone_2_plus();
    void bouton_zone_3_plus();
    void bouton_zone_4_plus();
    void bouton_zone_5_plus();
    void bouton_zone_6_plus();
    void bouton_zone_7_plus();
    void bouton_zone_8_plus();
    void bouton_zone_x_plus(uint8_t u8Zone, touchgfx::Slider *slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone);

    void bouton_zone_1_moins();
    void bouton_zone_2_moins();
    void bouton_zone_3_moins();
    void bouton_zone_4_moins();
    void bouton_zone_5_moins();
    void bouton_zone_6_moins();
    void bouton_zone_7_moins();
    void bouton_zone_8_moins();
    void bouton_zone_x_moins(uint8_t u8Zone, touchgfx::Slider *slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone);

    void bouton_nb_jours_plus();
    void bouton_nb_jours_moins();
    void bouton_vacances_oui();
    void bouton_vacances_non();
    void bouton_valider();
    void bouton_retour();
    void text_vacances_off();
    void affichageZone(uint8_t u8Zone, touchgfx::Container *container_zone, touchgfx::ToggleButton *toggleButton_zone, touchgfx::Container *container_slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_vacances_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_Zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone, touchgfx::Slider *slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone);
protected:
    bool bConnexionDistance;
    uint8_t u8NbJoursVacances, u8NbBoutons;
    uint16_t u16ErreurAffichee, u16ConsigneTempVacances[8], u16ConsignePiscineTempVacances;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_NbJours[3], textAreaBuffer_Zone1[11], textAreaBuffer_TempZone1[5], textAreaBuffer_Zone2[11], textAreaBuffer_TempZone2[5], textAreaBuffer_Zone3[11], textAreaBuffer_TempZone3[5], textAreaBuffer_Zone4[11], textAreaBuffer_TempZone4[5], textAreaBuffer_Zone5[11], textAreaBuffer_TempZone5[5], textAreaBuffer_Zone6[11], textAreaBuffer_TempZone6[5], textAreaBuffer_Zone7[11], textAreaBuffer_TempZone7[5], textAreaBuffer_Zone8[11], textAreaBuffer_TempZone8[5], textAreaBuffer_TempPiscine[5];
};

#endif // VACANCESVIEW_HPP
