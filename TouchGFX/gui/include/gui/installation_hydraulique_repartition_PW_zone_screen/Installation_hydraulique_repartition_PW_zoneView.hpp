#ifndef INSTALLATION_HYDRAULIQUE_REPARTITION_PW_ZONEVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_REPARTITION_PW_ZONEVIEW_HPP

#include <gui_generated/installation_hydraulique_repartition_PW_zone_screen/Installation_hydraulique_repartition_PW_zoneViewBase.hpp>
#include <gui/installation_hydraulique_repartition_PW_zone_screen/Installation_hydraulique_repartition_PW_zonePresenter.hpp>

class Installation_hydraulique_repartition_PW_zoneView : public Installation_hydraulique_repartition_PW_zoneViewBase
{
public:
    Installation_hydraulique_repartition_PW_zoneView();
    virtual ~Installation_hydraulique_repartition_PW_zoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

//    void bouton_resistance_terminaison();
//    void bouton_defilement_droit_type_regulation();
//    void bouton_defilement_gauche_type_regulation();
//    void bouton_defilement_droit_nb_pac();
//    void bouton_defilement_gauche_nb_pac();
//    void affichage_type_regul();
//    void affichage_zones();
//    void bouton_zone_1();
//    void bouton_zone_2();
//    void bouton_param_zone_1();
//    void bouton_param_zone_2();
    void bouton_part_volume_zone1_gauche();
    void bouton_part_volume_zone1_droit();
    void bouton_part_volume_zone2_gauche();
    void bouton_part_volume_zone2_droit();
    void bouton_valider();

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void Update_Percent_value();
protected:
    bool bConnexionDistance;
    unsigned short u7temp_Percent_Zone1, u7temp_Percent_Zone2;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[50], textAreaBuffer_Heure[6], textAreaBuffer_Date[9],textAreaBuffer_part_zone1[8], textAreaBuffer_part_zone2[8];
    //, textAreaBuffer_nb_pac[2], textAreaBuffer_nom_zone1[11], textAreaBuffer_nom_zone2[11];
};

#endif // INSTALLATION_HYDRAULIQUE8REPARTITION_PW_ZONEVIEW_HPP
