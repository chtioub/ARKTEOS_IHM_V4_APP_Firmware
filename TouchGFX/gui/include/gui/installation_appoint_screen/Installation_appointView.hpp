#ifndef INSTALLATION_APPOINTVIEW_HPP
#define INSTALLATION_APPOINTVIEW_HPP

#include <gui_generated/installation_appoint_screen/Installation_appointViewBase.hpp>
#include <gui/installation_appoint_screen/Installation_appointPresenter.hpp>

class Installation_appointView : public Installation_appointViewBase
{
public:
    Installation_appointView();
    virtual ~Installation_appointView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_type_appoint_droite();
    void bouton_type_appoint_gauche();
    void affichage_type_appoint();
    void bouton_temp_equilibre_plus();
    void bouton_temp_equilibre_moins();
    void bouton_appoint_on_off();
    void bouton_hysteresis_ext();
    void bouton_chaudiere();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    int8_t i8TempExt;
    uint8_t u8TypeAppoint;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_TempExt[6];
};

#endif // INSTALLATION_APPOINTVIEW_HPP
