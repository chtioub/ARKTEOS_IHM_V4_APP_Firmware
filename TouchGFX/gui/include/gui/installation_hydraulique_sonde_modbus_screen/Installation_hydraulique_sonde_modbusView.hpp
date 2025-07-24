#ifndef INSTALLATION_HYDRAULIQUE_SONDE_MODBUSVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_SONDE_MODBUSVIEW_HPP

#include <gui_generated/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusViewBase.hpp>
#include <gui/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusPresenter.hpp>

class Installation_hydraulique_sonde_modbusView : public Installation_hydraulique_sonde_modbusViewBase
{
public:
    Installation_hydraulique_sonde_modbusView();
    virtual ~Installation_hydraulique_sonde_modbusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_moins_numero_sonde();
    void bouton_plus_numero_sonde();
    void bouton_retour();
    void bouton_verrouillage_consigne();
    void bouton_arret_defaut();
    void bouton_hysteresis();
    void bouton_resistance_terminaison();
    void bouton_valider();
    void affichage_attention();
    void bouton_valider_attention();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance, bAttentionClicked;
    uint8_t u8NumSonde;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_num_sonde[3],textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[500];

};

#endif // INSTALLATION_HYDRAULIQUE_SONDE_MODBUSVIEW_HPP
