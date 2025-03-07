#ifndef INSTALLATION_GESTION_V3VVIEW_HPP
#define INSTALLATION_GESTION_V3VVIEW_HPP

#include <gui_generated/installation_gestion_v3v_screen/Installation_gestion_v3vViewBase.hpp>
#include <gui/installation_gestion_v3v_screen/Installation_gestion_v3vPresenter.hpp>

class Installation_gestion_v3vView : public Installation_gestion_v3vViewBase
{
public:
    Installation_gestion_v3vView();
    virtual ~Installation_gestion_v3vView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_droit();
    void bouton_gauche();
    void update_gestion_v3v();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    unsigned char Type_Gestion_V3V  :1;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_GestionV3V[2];
};

#endif // INSTALLATION_GESTION_V3VVIEW_HPP
