#ifndef INSTALLATION_HYDRAULIQUE_PARAM_COMPVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_PARAM_COMPVIEW_HPP

#include <gui_generated/installation_hydraulique_param_comp_screen/Installation_hydraulique_param_compViewBase.hpp>
#include <gui/installation_hydraulique_param_comp_screen/Installation_hydraulique_param_compPresenter.hpp>

class Installation_hydraulique_param_compView : public Installation_hydraulique_param_compViewBase
{
public:
    Installation_hydraulique_param_compView();
    virtual ~Installation_hydraulique_param_compView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
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
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // INSTALLATION_HYDRAULIQUE_PARAM_COMPVIEW_HPP
