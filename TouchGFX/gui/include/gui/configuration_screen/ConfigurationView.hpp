#ifndef CONFIGURATIONVIEW_HPP
#define CONFIGURATIONVIEW_HPP

#include <gui_generated/configuration_screen/ConfigurationViewBase.hpp>
#include <gui/configuration_screen/ConfigurationPresenter.hpp>

class ConfigurationView : public ConfigurationViewBase
{
public:
ConfigurationView();
	virtual ~ConfigurationView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();
	void bouton_maintenance();
	void bouton_installation();
	void bouton_usine();
	void bouton_oui_veille();
	void bouton_non_veille();

//    void update_titre_page();
	virtual void changeDate(S_DATE *sDate);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	 virtual void handleGestureEvent(const touchgfx::GestureEvent& evt) override;

protected:
	bool bConnexionDistance, bMarche, bDegivrage;
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
