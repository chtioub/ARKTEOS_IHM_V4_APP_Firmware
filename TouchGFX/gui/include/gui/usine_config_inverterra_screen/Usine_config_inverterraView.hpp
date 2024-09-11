#ifndef USINE_CONFIG_INVERTERRAVIEW_HPP
#define USINE_CONFIG_INVERTERRAVIEW_HPP

#include <gui_generated/usine_config_inverterra_screen/Usine_config_inverterraViewBase.hpp>
#include <gui/usine_config_inverterra_screen/Usine_config_inverterraPresenter.hpp>

class Usine_config_inverterraView : public Usine_config_inverterraViewBase
{
public:
    Usine_config_inverterraView();
    virtual ~Usine_config_inverterraView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_droite_fluide_c1();
    void bouton_gauche_fluide_c1();
    void affichageFluideC1();
    void bouton_moins_puissance();
    void bouton_plus_puissance();
    void bouton_mono_tri();
    void bouton_type_inverterra();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

protected:
    bool bConnexionDistance;
    uint8_t u8FluideC1;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_FluideC1[6];
};

#endif // USINE_CONFIG_INVERTERRAVIEW_HPP
