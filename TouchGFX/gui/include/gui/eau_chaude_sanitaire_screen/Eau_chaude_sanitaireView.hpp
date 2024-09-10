#ifndef EAU_CHAUDE_SANITAIREVIEW_HPP
#define EAU_CHAUDE_SANITAIREVIEW_HPP

#include <gui_generated/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireViewBase.hpp>
#include <gui/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.hpp>

class Eau_chaude_sanitaireView : public Eau_chaude_sanitaireViewBase
{
public:
    Eau_chaude_sanitaireView();
    virtual ~Eau_chaude_sanitaireView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void slider_consigne(int sliderValue);
    void slider_relance(int sliderValue);
    void bouton_moins_consigne();
    void bouton_plus_consigne();
    void bouton_moins_relance();
    void bouton_plus_relance();
    void bouton_appoint();
    void bouton_arret();
    void bouton_marche_ecs();
    void timer_100ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee, u16Consigne, u16Relance, u16TempoEnvoiConsigne;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_consigne[5], textAreaBuffer_relance[5], textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // EAU_CHAUDE_SANITAIREVIEW_HPP
