#ifndef MULTIZONESVIEW_HPP
#define MULTIZONESVIEW_HPP

#include <gui_generated/multizones_screen/MultizonesViewBase.hpp>
#include <gui/multizones_screen/MultizonesPresenter.hpp>

class MultizonesView : public MultizonesViewBase
{
public:
    MultizonesView();
    virtual ~MultizonesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

	void bouton_zone_1();
	void bouton_zone_2();
	void bouton_zone_3();
	void bouton_zone_4();
	void bouton_zone_5();
	void bouton_zone_6();
	void bouton_zone_7();
	void bouton_zone_8();
	void changeConfigZx(uint8_t u8Zone, S_PARAM_ZX *sParam_Zx, touchgfx::Button *button_orange_zone, touchgfx::Button *button_marron_zone, touchgfx::Button *button_violet_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_Zone);
	void changeZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx, touchgfx::Circle *circle_demande_zone, touchgfx::PainterRGB565 *circle_demande_zonePainter, touchgfx::Circle *circle_mode_zone, touchgfx::PainterRGB565 *circle_mode_zonePainter, touchgfx::TextAreaWithOneWildcard *textArea_temp_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_Temp_Zone);
protected:
	bool bConnexionDistance;
	uint8_t u8ZoneCorrespondante[NB_ZONE];
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
    S_STATUT_ZX sStatut_Zx_old[20];
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Zone_1[11], textAreaBuffer_Zone_2[11], textAreaBuffer_Zone_3[11], textAreaBuffer_Zone_4[11], textAreaBuffer_Zone_5[11], textAreaBuffer_Zone_6[11], textAreaBuffer_Zone_7[11], textAreaBuffer_Zone_8[11];
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Temp_Zone_1[7], textAreaBuffer_Temp_Zone_2[7], textAreaBuffer_Temp_Zone_3[7], textAreaBuffer_Temp_Zone_4[7], textAreaBuffer_Temp_Zone_5[7], textAreaBuffer_Temp_Zone_6[7], textAreaBuffer_Temp_Zone_7[7], textAreaBuffer_Temp_Zone_8[7];

};

#endif // MULTIZONESVIEW_HPP
