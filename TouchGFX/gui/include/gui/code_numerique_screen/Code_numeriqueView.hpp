#ifndef CODE_NUMERIQUEVIEW_HPP
#define CODE_NUMERIQUEVIEW_HPP

#include <gui_generated/code_numerique_screen/Code_numeriqueViewBase.hpp>
#include <gui/code_numerique_screen/Code_numeriquePresenter.hpp>

class Code_numeriqueView : public Code_numeriqueViewBase
{
public:
    Code_numeriqueView();
    virtual ~Code_numeriqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_valider_modal_window();
    void affichageNumero();
    void bouton_retour();
    void bouton_valider();
    void bouton_supprimer();
    void bouton_0();
    void bouton_1();
    void bouton_2();
    void bouton_3();
    void bouton_4();
    void bouton_5();
    void bouton_6();
    void bouton_7();
    void bouton_8();
    void bouton_9();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8Longueur, u8BufferCode[12];
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Valeur[25];
};

#endif // CODE_NUMERIQUEVIEW_HPP
