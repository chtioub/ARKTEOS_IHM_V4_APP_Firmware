#ifndef PROGRAMMATIONVIEW_HPP
#define PROGRAMMATIONVIEW_HPP

#include <gui_generated/programmation_screen/ProgrammationViewBase.hpp>
#include <gui/programmation_screen/ProgrammationPresenter.hpp>

class ProgrammationView : public ProgrammationViewBase
{
public:
    ProgrammationView();
    virtual ~ProgrammationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_copier();
    void bouton_coller();
    void barre_lundi();
    void barre_mardi();
    void barre_mercredi();
    void barre_jeudi();
    void barre_vendredi();
    void barre_samedi();
    void barre_dimanche();
    void bouton_retour();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8Copie;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    touchgfx::Bitmap image_off, image1, image2, image3;
    touchgfx::Image image_prog[7][96];
    touchgfx::Container container_jour[7];
};

#endif // PROGRAMMATIONVIEW_HPP
