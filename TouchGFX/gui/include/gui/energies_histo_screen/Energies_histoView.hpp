#ifndef ENERGIES_HISTOVIEW_HPP
#define ENERGIES_HISTOVIEW_HPP

#include <gui_generated/energies_histo_screen/Energies_histoViewBase.hpp>
#include <gui/energies_histo_screen/Energies_histoPresenter.hpp>

class Energies_histoView : public Energies_histoViewBase
{
public:
    Energies_histoView();
    virtual ~Energies_histoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_pac();
    void bouton_chaud();
    void bouton_froid();
    void bouton_ecs();
    void bouton_piscine();
    void bouton_12mois();
    void bouton_24jours();
    void bouton_24heures();
    void couleur_barres(uint32_t u32Couleur);
    void jours(uint8_t u8Jours, uint8_t u8NbJoursMois);
    void heures(uint8_t u8Heure);
    void mois(uint8_t u8Mois);
    void majbarres_mois();
    void majbarres_jours_heures(bool bJourHeure);
protected:
	touchgfx::Unicode::UnicodeChar textAreaBuffer_1[5], textAreaBuffer_2[5], textAreaBuffer_3[5], textAreaBuffer_4[5], textAreaBuffer_5[5], textAreaBuffer_6[5], textAreaBuffer_7[5], textAreaBuffer_8[5], textAreaBuffer_9[5], textAreaBuffer_10[5], textAreaBuffer_11[5], textAreaBuffer_12[5], textAreaBuffer_13[3], textAreaBuffer_14[3], textAreaBuffer_15[3], textAreaBuffer_16[3], textAreaBuffer_17[3], textAreaBuffer_18[3], textAreaBuffer_19[3], textAreaBuffer_20[3], textAreaBuffer_21[3], textAreaBuffer_22[3], textAreaBuffer_23[3], textAreaBuffer_24[3], textAreaBuffer_value_1[7], textAreaBuffer_value_2[7], textAreaBuffer_value_3[7], textAreaBuffer_value_4[7], textAreaBuffer_value_5[7], textAreaBuffer_Titre[25];
	uint16_t u16Energies_mois_chaud[12] = {12000, 19000, 15000, 0, 0, 0, 0, 0, 0, 60000, 32000, 50000};
	uint16_t u16Energies_mois_chaud_elec[12] = {5000, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 1500};
	uint16_t u16Energies_mois_froid[12] = {0, 0, 0, 0, 0, 6000, 25000, 32350, 15000, 0, 0, 0};
	uint16_t u16Energies_mois_ecs[12] = {8000, 9000, 7000, 5000, 4500, 8000, 3000, 9000, 6000, 8000, 8600, 9320};
	uint16_t u16Energies_mois_ecs_elec[12] = {1500, 0, 0, 0, 500, 0, 0, 0, 800, 300, 0, 0};
	uint16_t u16Energies_mois_piscine[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint16_t u16Energies_jours_chaud[24] = {12000, 19000, 15000, 0, 0, 0, 0, 0, 0, 60000, 32000, 50000, 12000, 19000, 15000, 0, 0, 0, 0, 0, 0, 60000, 32000, 50000};
	uint16_t u16Energies_jours_chaud_elec[24] = {0, 0, 800, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 500};
	uint16_t u16Energies_jours_froid[24] = {0, 0, 0, 0, 0, 6000, 25000, 32350, 15000, 0, 0, 0, 0, 0, 0, 0, 0, 6000, 25000, 32350, 15000, 0, 0, 0};
	uint16_t u16Energies_jours_ecs[24] = {8000, 9000, 7000, 5000, 4500, 8000, 3000, 9000, 6000, 8000, 8600, 9320, 8000, 9000, 7000, 5000, 4500, 8000, 3000, 9000, 6000, 8000, 8600, 9320};
	uint16_t u16Energies_jours_ecs_elec[24] = {100, 0, 0, 0, 0, 0, 300, 900, 0, 0, 0, 900, 0, 0, 0, 0, 450, 0, 0, 0, 0, 0, 0, 0};
	uint16_t u16Energies_jours_piscine[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint16_t u16Energies_heures_chaud[24] = {40000, 10000, 8000, 0, 0, 0, 0, 0, 0, 60000, 32000, 50000, 12000, 19000, 15000, 0, 0, 0, 0, 0, 0, 60000, 32000, 50000};
	uint16_t u16Energies_heures_chaud_elec[24] = {0, 0, 800, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 500};
	uint16_t u16Energies_heures_froid[24] = {0, 0, 0, 0, 0, 6000, 5000, 5000, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 6000, 25000, 32350, 15000, 0, 0, 0};
	uint16_t u16Energies_heures_ecs[24] = {2000, 5000, 2500, 5000, 4500, 8000, 3000, 9000, 6000, 8000, 8600, 9320, 8000, 9000, 7000, 5000, 4500, 8000, 3000, 9000, 6000, 8000, 8600, 9320};
	uint16_t u16Energies_heures_ecs_elec[24] = {100, 0, 0, 0, 0, 0, 300, 900, 0, 0, 0, 900, 0, 0, 0, 0, 450, 0, 0, 0, 0, 0, 0, 0};
	uint16_t u16Energies_heures_piscine[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

#endif // ENERGIES_HISTOVIEW_HPP
