#ifndef INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP
#define INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP

#include <gui_generated/installation_mz_config_zone_screen/Installation_MZ_config_zoneViewBase.hpp>
#include <gui/installation_mz_config_zone_screen/Installation_MZ_config_zonePresenter.hpp>

class Installation_MZ_config_zoneView : public Installation_MZ_config_zoneViewBase
{
public:
    Installation_MZ_config_zoneView();
    virtual ~Installation_MZ_config_zoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_non();
    void bouton_oui();
    void bouton_froid();
    void bouton_chaud();
    void bouton_droite_type_emetteur();
    void bouton_gauche_type_emetteur();
    void bouton_droite_type_sonde();
    void bouton_gauche_type_sonde();
    void bouton_droite_pdc_gaines();
    void bouton_gauche_pdc_gaines();
    void bouton_droite_volume_zone();
    void bouton_gauche_volume_zone();
    void bouton_valider_information();
    void renommer_zone();
    void bouton_valider();

    virtual void ViewHideButtonContainer();
    virtual void InitContainer();
    virtual void MAJBoutonActiverZone();
    virtual void MAJBoutonActiverChaud();
    virtual void MAJBoutonActiverFroid();
    virtual void record_zone_active_oui_non();
    virtual void MAJEmetteur();
    virtual void affichage_froid_non_autorise();
    virtual void affichage_chaud_non_autorise();
    virtual void MAJTypeSonde();
    virtual void MAJPertesDeCharges();
    virtual void MAJVolumePiece();
    virtual void MAJActivationCorrectionDebitAir();

    virtual void changeStatutRF(S_STATUT_RF *sStatut_RF);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	uint8_t u8Loideau_Plancher[6] =	{29, 31, 34, 38, 42, 45};
	uint8_t u8Loideau_Ventilo[6] = 	{40, 43, 45, 50, 55, 55};
	uint8_t u8Loideau_Radiateur[6] ={45, 47, 48, 53, 55, 55};
    bool bConnexionDistance, bZoneActive;
    uint16_t u16ErreurAffichee;
    uint8_t u8NumZone;
    uint8_t u8NomZone[10];
    int8_t i8PertesDeCharges;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_STATUT_RF sStatut_RF_old;
	unsigned short TypeEmetteur : 3;
	unsigned short VolumePiece;
	unsigned char TypeThermostat : 2;
	unsigned char bActivationCorrection , bModeChaud, bModeFroid;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[500],
	textAreaBuffer_PertesDeCharges[5],textAreaBuffer_VolumeZone[4];

};

#endif // INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP
