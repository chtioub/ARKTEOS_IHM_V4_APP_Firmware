#ifndef INSTALLATION_HYDRAULIQUEVIEW_HPP
#define INSTALLATION_HYDRAULIQUEVIEW_HPP

#include <gui_generated/installation_hydraulique_screen/Installation_hydrauliqueViewBase.hpp>
#include <gui/installation_hydraulique_screen/Installation_hydrauliquePresenter.hpp>

class Installation_hydrauliqueView : public Installation_hydrauliqueViewBase
{
public:
    Installation_hydrauliqueView();
    virtual ~Installation_hydrauliqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_resistance_terminaison();
    void bouton_defilement_droit_type_regulation();
    void bouton_defilement_gauche_type_regulation();
    void bouton_defilement_droit_nb_pac();
    void bouton_defilement_gauche_nb_pac();
    void affichage_type_regul();
    void affichage_zones();
    void bouton_zone_1();
    void bouton_zone_2();
    void bouton_param_zone_1();
    void bouton_param_zone_2();
    void bouton_repartition_puissance_zone();
    void bouton_hysteresis_regul_directe();
    void bouton_valider();
    void bouton_oui_regroupement();
    void bouton_non_regroupement();
    void bouton_parametrage_groupes_zones();
    void MAJ_Etat_Bouton_Oui_Non_Multizone();


    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8Nb_PAC;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_nb_pac[2], textAreaBuffer_nom_zone1[11], textAreaBuffer_nom_zone2[11];
};

#endif // INSTALLATION_HYDRAULIQUEVIEW_HPP
