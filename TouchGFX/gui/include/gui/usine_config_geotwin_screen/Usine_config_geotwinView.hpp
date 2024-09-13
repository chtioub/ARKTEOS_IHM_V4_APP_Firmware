#ifndef USINE_CONFIG_GEOTWINVIEW_HPP
#define USINE_CONFIG_GEOTWINVIEW_HPP

#include <gui_generated/usine_config_geotwin_screen/Usine_config_geotwinViewBase.hpp>
#include <gui/usine_config_geotwin_screen/Usine_config_geotwinPresenter.hpp>

class Usine_config_geotwinView : public Usine_config_geotwinViewBase
{
public:
    Usine_config_geotwinView();
    virtual ~Usine_config_geotwinView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();


    void bouton_droite_debitmetre_chauffage();
    void bouton_gauche_debitmetre_chauffage();
    void affichage_debitmetre_chauffage();
    void bouton_droite_debitmetre_captage();
    void bouton_gauche_debitmetre_captage();
    void affichage_debitmetre_captage();
    void bouton_moins_puissance();
    void bouton_plus_puissance();
    void bouton_dem_prog();
    void timer_10ms();
    void bouton_compresseur();
    void bouton_nappe_directe();
    void bouton_reversible();
    void bouton_mono_tri();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

protected:
    bool bConnexionDistance;
    uint8_t u8Puissance, u8PressionLongue_droite, u8PressionLongue_gauche, u8NbComp, u8DebitmetreCaptage, u8DebitmetreChauffage;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Compresseur[2], textAreaBuffer_Puissance[4], textAreaBuffer_DebitmetreCaptage[13], textAreaBuffer_DebitmetreChauffage[13];
};

#endif // USINE_CONFIG_GEOTWINVIEW_HPP
