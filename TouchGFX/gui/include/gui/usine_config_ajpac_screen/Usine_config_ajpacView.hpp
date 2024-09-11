#ifndef USINE_CONFIG_AJPACVIEW_HPP
#define USINE_CONFIG_AJPACVIEW_HPP

#include <gui_generated/usine_config_ajpac_screen/Usine_config_ajpacViewBase.hpp>
#include <gui/usine_config_ajpac_screen/Usine_config_ajpacPresenter.hpp>

class Usine_config_ajpacView : public Usine_config_ajpacViewBase
{
public:
    Usine_config_ajpacView();
    virtual ~Usine_config_ajpacView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void afficheTypeAJPAC();
    void bouton_droite_ajpac();
    void bouton_gauche_ajpac();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8TypeAJPAC;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // USINE_CONFIG_AJPACVIEW_HPP
