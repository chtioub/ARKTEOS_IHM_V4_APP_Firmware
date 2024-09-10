#ifndef MAINTENANCEVIEW_HPP
#define MAINTENANCEVIEW_HPP

#include <gui_generated/maintenance_screen/MaintenanceViewBase.hpp>
#include <gui/maintenance_screen/MaintenancePresenter.hpp>

class MaintenanceView : public MaintenanceViewBase
{
public:
    MaintenanceView();
    virtual ~MaintenanceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_raz_histo_err();
    void bouton_derog_pression();
    void bouton_shunt_tempo();
    void bouton_redemarrer_pac();
    void bouton_redemarrer_ihm();
    void bouton_retour();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeDemandeFrigo(S_DEMANDE_FRIGO *sDemande_Frigo);

protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_DEMANDE_FRIGO sDemande_Frigo_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // MAINTENANCEVIEW_HPP
