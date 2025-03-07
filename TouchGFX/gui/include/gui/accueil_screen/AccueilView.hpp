#ifndef ACCUEILVIEW_HPP
#define ACCUEILVIEW_HPP

#include <gui_generated/accueil_screen/AccueilViewBase.hpp>
#include <gui/accueil_screen/AccueilPresenter.hpp>

class AccueilView : public AccueilViewBase
{
public:
    AccueilView();
    virtual ~AccueilView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void Timer_500ms();
    void Timer_Swipe_Detection();
    void bouton_marche_arret();
    void bouton_zone_1();
    void bouton_zone_2();
    void bouton_maintenance();
    void bouton_installation();
    void bouton_usine();
    void changeLogo(bool bVisible);
    void change_to_config_screen();
    void change_to_accueil_screen();
//    void update_titre_page();
    virtual void changeModePac(bool marche);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx);
    virtual void changeStatutECS(S_STATUT_ECS *sStatut_ECS);
    virtual void changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine);
    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);
    virtual void changeStatutRegulExt(S_STATUT_REG_EXT *sStatut_RegulExt);
protected:
    bool bConnexionDistance;
	uint8_t u8NbZones, u8Zone1 = 0xff, u8Zone2 = 0xff;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_ECS sStatut_ECS_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_STATUT_PRIMAIRE sStatut_Primaire_old;
    S_STATUT_PISCINE sStatut_Piscine_old;
    S_CYCL_REG_FRI sCyclRegFrigo_old;
    S_STATUT_REG_EXT sStatut_RegulExt_old;
    S_STATUT_ZX sStatut_Zx_old[20];
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre_Date[30],textAreaBuffer_Titre_Titre[40], textAreaBuffer_Zone_1[11], textAreaBuffer_Zone_2[11], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Pression_Capt[7], textAreaBuffer_pression_chauf[7],textAreaBuffer_Pression[7], textAreaBuffer_ECS_Milieu[7], textAreaBuffer_ECS_Bas[7], textAreaBuffer_Piscine[7], textAreaBuffer_Temp_Ext[7], textAreaBuffer_Temp_Zone_1[7], textAreaBuffer_Temp_Zone_2[7];

private:
   // touchgfx::Callback<AccueilView, int16_t> swipeCallback;

    //void swipeCallbackHandler(int16_t);

};

#endif // ACCUEILVIEW_HPP
