#ifndef ENERGIES_CUMULVIEW_HPP
#define ENERGIES_CUMULVIEW_HPP

#include <gui_generated/energies_cumul_screen/Energies_cumulViewBase.hpp>
#include <gui/energies_cumul_screen/Energies_cumulPresenter.hpp>

class Energies_cumulView : public Energies_cumulViewBase
{
public:
    Energies_cumulView();
    virtual ~Energies_cumulView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_gauche();
    void bouton_droite();
    void maj_affichage();
    void bouton_raz();
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_date[9], textAreaBuffer_value_1[2], textAreaBuffer_value_2[7], textAreaBuffer_value_3[7], textAreaBuffer_value_4[7], textAreaBuffer_value_5[7], textAreaBuffer_value_6[7], textAreaBuffer_value_pac[14], textAreaBuffer_value_chaud[14], textAreaBuffer_value_froid[7], textAreaBuffer_value_ecs[14], textAreaBuffer_value_piscine[7], textAreaBuffer_Titre[25];
    uint8_t u8TypeCumul; // 0: mise en service; 1: année; 2: partiel
    uint8_t u8Jour, u8Mois, u8Annee;
    uint32_t u32EnergiesCumul_Chaud = 18000;
    uint32_t u32EnergiesCumul_Froid = 2500;
    uint32_t u32EnergiesCumul_ECS = 3500;
    uint32_t u32EnergiesCumul_Piscine = 4500;
    uint32_t u32EnergiesCumul_Elec_ECS = 1500;
    uint32_t u32EnergiesCumul_Elec_Chaud = 4500;
};

#endif // ENERGIES_CUMULVIEW_HPP
