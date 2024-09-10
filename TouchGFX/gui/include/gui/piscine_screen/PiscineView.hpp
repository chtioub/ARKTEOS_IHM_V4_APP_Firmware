#ifndef PISCINEVIEW_HPP
#define PISCINEVIEW_HPP

#include <gui_generated/piscine_screen/PiscineViewBase.hpp>
#include <gui/piscine_screen/PiscinePresenter.hpp>

class PiscineView : public PiscineViewBase
{
public:
    PiscineView();
    virtual ~PiscineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void slider_reduit(int sliderValue);
    void slider_normal(int sliderValue);
    void slider_confort(int sliderValue);
    void bouton_arret();
    void bouton_marche();
    void bouton_moins_reduit();
    void bouton_plus_reduit();
    void bouton_moins_normal();
    void bouton_plus_normal();
    void bouton_moins_confort();
    void bouton_plus_confort();
    void timer_100ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_ConsigneReduit[5], textAreaBuffer_ConsigneNormal[5], textAreaBuffer_ConsigneConfort[5];
    uint16_t u16ConsigneReduit, u16ConsigneNormal, u16ConsigneConfort, u16TempoEnvoiConsigne;
};

#endif // PISCINEVIEW_HPP
