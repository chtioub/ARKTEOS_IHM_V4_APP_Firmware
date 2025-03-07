#ifndef INSTALLATION_REGULATION_AVANCEEVIEW_HPP
#define INSTALLATION_REGULATION_AVANCEEVIEW_HPP

#include <gui_generated/installation_regulation_avancee_screen/Installation_regulation_avanceeViewBase.hpp>
#include <gui/installation_regulation_avancee_screen/Installation_regulation_avanceePresenter.hpp>

class Installation_regulation_avanceeView : public Installation_regulation_avanceeViewBase
{
public:
    Installation_regulation_avanceeView();
    virtual ~Installation_regulation_avanceeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_gauche_temp_non_chauf();
    void bouton_droit_temp_non_chauf();
    void bouton_gauche_chaud_froid_simu();
    void bouton_droit_chaud_froid_simu();
    void bouton_gauche_adapt_loi_deau();
    void bouton_droit_adapt_loi_deau();
    void bouton_limitation_ecs();
    void bouton_limitation_froid();
    void bouton_hysteresis();
    void update_adapt_loi_deau();
    void update_chaud_froid_simu();
    void update_temp_ext_non_chauf();
    void update_limitation_froid();
	void update_limitation_ecs();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    unsigned char eTypeSimultaneChaudFroid :3;
    unsigned char bLimitationPW_Froid :1;
    unsigned char bLimitationPW_ECS :1;
    uint16_t u16ErreurAffichee;
    uint8_t bUserAdaptationLoiDeau:1;
    uint16_t TempNonChauffage:4;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_TempNonChauf[8];
};

#endif // INSTALLATION_REGULATION_AVANCEEVIEW_HPP
