#ifndef INSTALLATION_MZ_CONFIG_GROUPEVIEW_HPP
#define INSTALLATION_MZ_CONFIG_GROUPEVIEW_HPP

#include <gui_generated/installation_mz_config_groupe_screen/Installation_MZ_config_groupeViewBase.hpp>
#include <gui/installation_mz_config_groupe_screen/Installation_MZ_config_groupePresenter.hpp>

class Installation_MZ_config_groupeView : public Installation_MZ_config_groupeViewBase
{
public:
    Installation_MZ_config_groupeView();
    virtual ~Installation_MZ_config_groupeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_droite_type_emetteur();
    void bouton_gauche_type_emetteur();
    void affichage_type_emetteur();
    void bouton_non();
    void bouton_oui();
    void bouton_froid();
    void bouton_chaud();
    void affichage_information();
    void bouton_valider_information();
    void renommer_groupe();


	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	uint8_t u8Loideau_Plancher[6] =	{29, 31, 34, 38, 42, 45};
	uint8_t u8Loideau_Ventilo[6] = 	{40, 43, 45, 50, 55, 55};
	uint8_t u8Loideau_Radiateur[6] ={45, 47, 48, 53, 55, 55};
	uint8_t u8Loideau_Gainable[6] = {40, 44, 47, 51, 53, 55};
	bool bConnexionDistance;
	unsigned short TypeEmetteur : 3;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Question[50],textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[500];
};

#endif // INSTALLATION_MZ_CONFIG_GROUPEVIEW_HPP
