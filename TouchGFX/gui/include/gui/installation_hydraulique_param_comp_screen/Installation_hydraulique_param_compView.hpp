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

    void bouton_dep_eau_moins();
    void bouton_dep_eau_plus();
    void bouton_oui_chauffage();
    void bouton_non_chauffage();
    void bouton_oui_rafraichissement();
    void bouton_non_rafraichissement();
    void bouton_retour();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint8_t u8TempDepartEau, u8TempDepartEau_MIN, u8TempDepartEau_MAX;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[45], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_TempDepartEau[5];
};

#endif // INSTALLATION_HYDRAULIQUE_PARAM_COMPVIEW_HPP
