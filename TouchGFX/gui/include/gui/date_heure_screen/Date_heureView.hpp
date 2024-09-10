#ifndef DATE_HEUREVIEW_HPP
#define DATE_HEUREVIEW_HPP

#include <gui_generated/date_heure_screen/Date_heureViewBase.hpp>
#include <gui/date_heure_screen/Date_heurePresenter.hpp>

class Date_heureView : public Date_heureViewBase
{
public:
    Date_heureView();
    virtual ~Date_heureView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_minutes_bas();
    void bouton_minutes_haut();
    void bouton_heures_bas();
    void bouton_heures_haut();
    void bouton_annee_bas();
    void bouton_annee_haut();
    void bouton_mois_bas();
    void bouton_mois_haut();
    void bouton_jour_bas();
    void bouton_jour_haut();
    void majNbJoursMois();
    void majMois();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8Minutes, u8Heures, u8Jour, u8Mois, u8Annee, u8NbJoursMois;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Minutes[3], textAreaBuffer_Heures[3], textAreaBuffer_Jour[3], textAreaBuffer_Mois[3], textAreaBuffer_Annee[3], textAreaBuffer_AnneeComplete[5];
};

#endif // DATE_HEUREVIEW_HPP
