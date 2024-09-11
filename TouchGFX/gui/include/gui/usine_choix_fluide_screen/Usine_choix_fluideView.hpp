#ifndef USINE_CHOIX_FLUIDEVIEW_HPP
#define USINE_CHOIX_FLUIDEVIEW_HPP

#include <gui_generated/usine_choix_fluide_screen/Usine_choix_fluideViewBase.hpp>
#include <gui/usine_choix_fluide_screen/Usine_choix_fluidePresenter.hpp>

class Usine_choix_fluideView : public Usine_choix_fluideViewBase
{
public:
    Usine_choix_fluideView();
    virtual ~Usine_choix_fluideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_droite_fluide_c1();
    void bouton_gauche_fluide_c1();
    void affichageFluideC1();
    void bouton_droite_fluide_c2();
    void bouton_gauche_fluide_c2();
    void affichageFluideC2();
    void bouton_retour();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8FluideC1, u8FluideC2;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_FluideC1[6], textAreaBuffer_FluideC2[6];
};

#endif // USINE_CHOIX_FLUIDEVIEW_HPP
