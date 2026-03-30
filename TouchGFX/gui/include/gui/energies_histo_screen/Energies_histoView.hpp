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
    void jours(uint8_t u8Jours, uint8_t u8Mois, uint8_t u8Annee);
    void heures(uint8_t u8Heure);
    void mois(uint8_t u8Mois);
    void majbarres_mois();
    void majbarres_jours_heures(bool bJourHeure);

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
	touchgfx::Unicode::UnicodeChar textAreaBuffer_1[5], textAreaBuffer_2[5], textAreaBuffer_3[5], textAreaBuffer_4[5], textAreaBuffer_5[5], textAreaBuffer_6[5], textAreaBuffer_7[5], textAreaBuffer_8[5], textAreaBuffer_9[5], textAreaBuffer_10[5], textAreaBuffer_11[5], textAreaBuffer_12[5], textAreaBuffer_13[3], textAreaBuffer_14[3], textAreaBuffer_15[3], textAreaBuffer_16[3], textAreaBuffer_17[3], textAreaBuffer_18[3], textAreaBuffer_19[3], textAreaBuffer_20[3], textAreaBuffer_21[3], textAreaBuffer_22[3], textAreaBuffer_23[3], textAreaBuffer_24[3], textAreaBuffer_value_1[7], textAreaBuffer_value_2[7], textAreaBuffer_value_3[7], textAreaBuffer_value_4[7], textAreaBuffer_value_5[7];

};

#endif // ENERGIES_HISTOVIEW_HPP
