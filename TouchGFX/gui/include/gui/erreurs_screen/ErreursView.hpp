#ifndef ERREURSVIEW_HPP
#define ERREURSVIEW_HPP

#include <gui_generated/erreurs_screen/ErreursViewBase.hpp>
#include <gui/erreurs_screen/ErreursPresenter.hpp>

class ErreursView : public ErreursViewBase
{
public:
    ErreursView();
    virtual ~ErreursView() {}
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
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    touchgfx::Image image_defaut[25];
    touchgfx::Line line[25];
    touchgfx::PainterRGB565 linePainter[25];
    touchgfx::TextAreaWithOneWildcard textArea_date_heure_def[25];
    touchgfx::TextAreaWithOneWildcard textArea_def_num[25];
    touchgfx::TextArea textArea_def[25];
    touchgfx::Unicode::UnicodeChar textArea_date_heure_def_Buffer[25][20];
    touchgfx::Unicode::UnicodeChar textArea_def_num_Buffer[25][4];
};

#endif // ERREURSVIEW_HPP
