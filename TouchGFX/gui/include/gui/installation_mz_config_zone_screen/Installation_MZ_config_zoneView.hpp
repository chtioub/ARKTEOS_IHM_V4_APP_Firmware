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

	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
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

#endif // INSTALLATION_MZ_CONFIG_ZONEVIEW_HPP
