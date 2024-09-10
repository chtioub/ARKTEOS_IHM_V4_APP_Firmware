#ifndef PAGE_OUI_NONVIEW_HPP
#define PAGE_OUI_NONVIEW_HPP

#include <gui_generated/page_oui_non_screen/Page_oui_nonViewBase.hpp>
#include <gui/page_oui_non_screen/Page_oui_nonPresenter.hpp>

class Page_oui_nonView : public Page_oui_nonViewBase
{
public:
    Page_oui_nonView();
    virtual ~Page_oui_nonView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_non_page_oui_non();
    void bouton_oui_page_oui_non();
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
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // PAGE_OUI_NONVIEW_HPP
