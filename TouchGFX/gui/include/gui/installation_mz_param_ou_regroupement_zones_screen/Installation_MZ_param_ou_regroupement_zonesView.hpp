#ifndef INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP
#define INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP

#include <gui_generated/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesViewBase.hpp>
#include <gui/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesPresenter.hpp>

class Installation_MZ_param_ou_regroupement_zonesView : public Installation_MZ_param_ou_regroupement_zonesViewBase
{
public:
    Installation_MZ_param_ou_regroupement_zonesView();
    virtual ~Installation_MZ_param_ou_regroupement_zonesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void Button_Rattachement_Z1();
    void Button_Rattachement_Z2();
    void Button_Rattachement_Z3();
    void Button_Rattachement_Z4();
    void Button_Rattachement_Z5();
    void Button_Rattachement_Z6();
    void Button_Rattachement_Z7();
    void Button_Rattachement_Z8();
    void Button_Carte_MZ_Z1();
    void Button_Carte_MZ_Z2();
    void Button_Carte_MZ_Z3();
    void Button_Carte_MZ_Z4();
    void Button_Carte_MZ_Z5();
    void Button_Carte_MZ_Z6();
    void Button_Carte_MZ_Z7();
    void Button_Carte_MZ_Z8();
    void Button_Voie_Z1();
    void Button_Voie_Z2();
    void Button_Voie_Z3();
    void Button_Voie_Z4();
    void Button_Voie_Z5();
    void Button_Voie_Z6();
    void Button_Voie_Z7();
    void Button_Voie_Z8();
    void bouton_valider_information();
    void bouton_param_zone_1();
    void bouton_param_zone_2();
    void bouton_param_zone_3();
    void bouton_param_zone_4();
    void bouton_param_zone_5();
    void bouton_param_zone_6();
    void bouton_param_zone_7();
    void bouton_param_zone_8();



    virtual void RefreshRattachement();
    virtual void RefreshNomZone();
    virtual void MAJRattachement();
    virtual void MAJType_Carte();
    virtual void RefreshTypeCarte();
    virtual void MAJVoie_Zone();
    virtual void RefreshVoieZone();
    virtual void RefreshZoneActive();
    virtual void affichage_information();
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance,bMessageAttentionVu;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    uint8_t u8CarteMZ[8], u8NumVoie[8];
    unsigned char u2Rattachement[8];
    uint8_t u8LigneZone;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_NomGroupeZ1[11],textAreaBuffer_NomGroupeZ2[11],
	textAreaBuffer_NomGroupeZ3[11],textAreaBuffer_NomGroupeZ4[11],textAreaBuffer_NomGroupeZ5[11],textAreaBuffer_NomGroupeZ6[11],textAreaBuffer_NomGroupeZ7[11],textAreaBuffer_NomGroupeZ8[11],
	textAreaBuffer_NomZone[8][11],textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[500], textAreaBuffer_CarteZ1[4], textAreaBuffer_CarteZ2[4],textAreaBuffer_CarteZ3[4],
	textAreaBuffer_CarteZ4[4],textAreaBuffer_CarteZ5[4], textAreaBuffer_CarteZ6[4], textAreaBuffer_CarteZ7[4],textAreaBuffer_CarteZ8[4], textAreaBuffer_Voie_Z1[2], textAreaBuffer_Voie_Z2[2],
	textAreaBuffer_Voie_Z3[2], textAreaBuffer_Voie_Z4[2], textAreaBuffer_Voie_Z5[2], textAreaBuffer_Voie_Z6[2], textAreaBuffer_Voie_Z7[2], textAreaBuffer_Voie_Z8[2],
	textAreaBuffer_NomZ1[11], textAreaBuffer_NomZ2[11], textAreaBuffer_NomZ3[11], textAreaBuffer_NomZ4[11], textAreaBuffer_NomZ5[11], textAreaBuffer_NomZ6[11], textAreaBuffer_NomZ7[11],
	textAreaBuffer_NomZ8[11];
};

#endif // INSTALLATION_MZ_PARAM_OU_REGROUPEMENT_ZONESVIEW_HPP
