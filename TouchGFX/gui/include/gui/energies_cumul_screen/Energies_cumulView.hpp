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

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_date[9], textAreaBuffer_value_1[2], textAreaBuffer_value_2[7], textAreaBuffer_value_3[7], textAreaBuffer_value_4[7], textAreaBuffer_value_5[7], textAreaBuffer_value_6[7], textAreaBuffer_value_pac[14], textAreaBuffer_value_chaud[14], textAreaBuffer_value_froid[7], textAreaBuffer_value_ecs[14], textAreaBuffer_value_piscine[7];
    uint8_t u8TypeCumul; // 0: mise en service; 1: année; 2: partiel
    uint8_t u8Jour, u8Mois, u8Annee;
    uint32_t u32EnergiesCumul_Chaud;
    uint32_t u32EnergiesCumul_Froid;
    uint32_t u32EnergiesCumul_ECS;
    uint32_t u32EnergiesCumul_Piscine;
    uint32_t u32EnergiesCumul_Elec_ECS;
    uint32_t u32EnergiesCumul_Elec_Chaud;
};

#endif // ENERGIES_CUMULVIEW_HPP
