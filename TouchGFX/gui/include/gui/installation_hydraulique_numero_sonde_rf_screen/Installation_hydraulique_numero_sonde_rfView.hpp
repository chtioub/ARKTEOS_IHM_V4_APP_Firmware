#ifndef INSTALLATION_HYDRAULIQUE_NUMERO_SONDE_RFVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_NUMERO_SONDE_RFVIEW_HPP

#include <gui_generated/installation_hydraulique_numero_sonde_rf_screen/Installation_hydraulique_numero_sonde_rfViewBase.hpp>
#include <gui/installation_hydraulique_numero_sonde_rf_screen/Installation_hydraulique_numero_sonde_rfPresenter.hpp>

class Installation_hydraulique_numero_sonde_rfView : public Installation_hydraulique_numero_sonde_rfViewBase
{
public:
    Installation_hydraulique_numero_sonde_rfView();
    virtual ~Installation_hydraulique_numero_sonde_rfView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_moins_numero_sonde();
    void bouton_plus_numero_sonde();
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
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[50], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_num_sonde[3],textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[500];
};

#endif // INSTALLATION_HYDRAULIQUE_NUMERO_SONDE_RFVIEW_HPP
