#ifndef USINE_CHOIX_MODELE_PACVIEW_HPP
#define USINE_CHOIX_MODELE_PACVIEW_HPP

#include <gui_generated/usine_choix_modele_pac_screen/Usine_choix_modele_pacViewBase.hpp>
#include <gui/usine_choix_modele_pac_screen/Usine_choix_modele_pacPresenter.hpp>

class Usine_choix_modele_pacView : public Usine_choix_modele_pacViewBase
{
public:
    Usine_choix_modele_pacView();
    virtual ~Usine_choix_modele_pacView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void afficheModelePAC(uint8_t u8Modele);
    void bouton_valider();
    void bouton_droite_modele_pac();
    void bouton_gauche_modele_pac();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8ModelePAC;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Gamme[20];
};

#endif // USINE_CHOIX_MODELE_PACVIEW_HPP
