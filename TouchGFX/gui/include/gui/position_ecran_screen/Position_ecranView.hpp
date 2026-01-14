#ifndef POSITION_ECRANVIEW_HPP
#define POSITION_ECRANVIEW_HPP

#include <gui_generated/position_ecran_screen/Position_ecranViewBase.hpp>
#include <gui/position_ecran_screen/Position_ecranPresenter.hpp>

class Position_ecranView : public Position_ecranViewBase
{
public:
    Position_ecranView();
    virtual ~Position_ecranView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_valider();
    void bouton_droit();
    void bouton_gauche();
    void bouton_bas();
    void bouton_haut();
    void timer_10ms();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    uint8_t u8PressionLongue_droite, u8PressionLongue_gauche,u8PressionLongue_haut, u8PressionLongue_bas;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_OffsetX[3], textAreaBuffer_OffsetY[3];
};

#endif // POSITION_ECRANVIEW_HPP
