#ifndef HISTORIQUE_DEFAUTSVIEW_HPP
#define HISTORIQUE_DEFAUTSVIEW_HPP

#include <gui_generated/historique_defauts_screen/Historique_defautsViewBase.hpp>
#include <gui/historique_defauts_screen/Historique_defautsPresenter.hpp>

class Historique_defautsView : public Historique_defautsViewBase
{
public:
    Historique_defautsView();
    virtual ~Historique_defautsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    int8_t pointeur;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    touchgfx::Image image_defaut[50];
    touchgfx::Line line[50];
    touchgfx::PainterRGB565 linePainter[50];
    touchgfx::TextAreaWithOneWildcard textArea_date_heure_def[50];
    touchgfx::TextAreaWithOneWildcard textArea_def_num[50];
    touchgfx::TextArea textArea_def[50];
    touchgfx::Unicode::UnicodeChar textArea_date_heure_def_Buffer[50][20];
    touchgfx::Unicode::UnicodeChar textArea_def_num_Buffer[50][4];
    touchgfx::ScrollableContainer scrollableContainerLabelDef[50];
};

#endif // HISTORIQUE_DEFAUTSVIEW_HPP
