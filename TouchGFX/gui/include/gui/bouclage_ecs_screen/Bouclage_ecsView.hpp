#ifndef BOUCLAGE_ECSVIEW_HPP
#define BOUCLAGE_ECSVIEW_HPP

#include <gui_generated/bouclage_ecs_screen/Bouclage_ecsViewBase.hpp>
#include <gui/bouclage_ecs_screen/Bouclage_ecsPresenter.hpp>

class Bouclage_ecsView : public Bouclage_ecsViewBase
{
public:
    Bouclage_ecsView();
    virtual ~Bouclage_ecsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_moins_bouclage_ecs();
    void bouton_plus_bouclage_ecs();
    void bouton_valider();
    void bouton_prog();
    void timer_10ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    uint8_t u8Time_Bouclage_ECS, u8PressionLongue_gauche, u8PressionLongue_droite;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Tps_Bouclage[6];
};

#endif // BOUCLAGE_ECSVIEW_HPP
