#ifndef INSTALLATION_HYDRAULIQUE_SONDE_RFVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_SONDE_RFVIEW_HPP

#include <gui_generated/installation_hydraulique_sonde_rf_screen/Installation_hydraulique_sonde_rfViewBase.hpp>
#include <gui/installation_hydraulique_sonde_rf_screen/Installation_hydraulique_sonde_rfPresenter.hpp>

class Installation_hydraulique_sonde_rfView : public Installation_hydraulique_sonde_rfViewBase
{
public:
    Installation_hydraulique_sonde_rfView();
    virtual ~Installation_hydraulique_sonde_rfView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_associer();
    void bouton_dissocier();
    void bouton_num_sonde();
    void bouton_retour();
    void bouton_verrouillage_consigne();
    void bouton_arret_defaut();
    void bouton_hysteresis();
    void bouton_resistance_terminaison();
    void bouton_valider();

    virtual void changeStatutRF(S_STATUT_RF *sStatut_RF);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_STATUT_RF sStatut_RF_old;
    unsigned char   bVerouillageConsigne,bArretZoneDefautSonde;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_num_sonde[3];
};

#endif // INSTALLATION_HYDRAULIQUE_SONDE_RFVIEW_HPP
