#ifndef INSTALLATION_HYDRAULIQUE_CONFIG_ZONEVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_CONFIG_ZONEVIEW_HPP

#include <gui_generated/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zoneViewBase.hpp>
#include <gui/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zonePresenter.hpp>

class Installation_hydraulique_config_zoneView : public Installation_hydraulique_config_zoneViewBase
{
public:
    Installation_hydraulique_config_zoneView();
    virtual ~Installation_hydraulique_config_zoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_droite_type_emetteur();
    void bouton_gauche_type_emetteur();
    void affichage_type_emetteur();
    void bouton_droite_type_sonde();
    void bouton_gauche_type_sonde();
    void affichage_type_sonde();
    void renommer_zone();
    void bouton_valider();

    virtual void changeStatutRF(S_STATUT_RF *sStatut_RF);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

protected:
    bool bConnexionDistance;
    uint8_t u8Loideau_Plancher[6] = {29, 31, 34, 38, 42, 45};
    uint8_t u8Loideau_Ventilo[6] = {40, 43, 45, 50, 55, 55};
    uint8_t u8Loideau_Radiateur[6] = {45, 47, 48, 53, 55, 55};
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_STATUT_RF sStatut_RF_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // INSTALLATION_HYDRAULIQUE_CONFIG_ZONEVIEW_HPP
