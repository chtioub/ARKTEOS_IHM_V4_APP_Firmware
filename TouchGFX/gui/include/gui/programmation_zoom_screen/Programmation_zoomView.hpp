#ifndef PROGRAMMATION_ZOOMVIEW_HPP
#define PROGRAMMATION_ZOOMVIEW_HPP

#include <gui_generated/programmation_zoom_screen/Programmation_zoomViewBase.hpp>
#include <gui/programmation_zoom_screen/Programmation_zoomPresenter.hpp>

class Programmation_zoomView : public Programmation_zoomViewBase
{
public:
    Programmation_zoomView();
    virtual ~Programmation_zoomView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_plus();
    void bouton_moins();
    void slider_zoom_fonction(int slidervalue);
    void slider_zoom_plus_fonction(int slidervalue);
    void majTexteHeures(uint8_t u8Origine);
    void bouton_prog_1();
    void bouton_prog_2();
    void bouton_prog_3();
    void bouton_prog_4();
    void bouton_prog_5();
    void bouton_prog_6();
    void editer_prog(uint8_t u8NumeroProg);
    void boutonProg(uint8_t u8NumeroProg,uint8_t u8Prog);
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Temp_Affichee_0[8], textAreaBuffer_Temp_Affichee_1[8], textAreaBuffer_Temp_Affichee_2[8], textAreaBuffer_Temp_Affichee_3[8];
    uint8_t u8NiveauZoom, u8Prog_bouton[6], u8Prog_jour[24];
    uint8_t u8ValeurProg[96];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_1[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_2[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_3[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_4[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_5[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_6[3];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_texte_7[3];
    touchgfx::Bitmap image_off, image1, image2, image3;
    touchgfx::Image image_prog[96];
    touchgfx::Container container_jour;
    touchgfx::Bitmap bouton_off, bouton1, bouton2, bouton3, bouton_mixte;
};

#endif // PROGRAMMATION_ZOOMVIEW_HPP
