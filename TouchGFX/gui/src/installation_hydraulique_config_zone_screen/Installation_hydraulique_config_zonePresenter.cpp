#include <gui/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zoneView.hpp>
#include <gui/installation_hydraulique_config_zone_screen/Installation_hydraulique_config_zonePresenter.hpp>

Installation_hydraulique_config_zonePresenter::Installation_hydraulique_config_zonePresenter(Installation_hydraulique_config_zoneView& v)
    : view(v)
{

}

void Installation_hydraulique_config_zonePresenter::activate()
{

}

void Installation_hydraulique_config_zonePresenter::deactivate()
{

}

void Installation_hydraulique_config_zonePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_config_zonePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_config_zonePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_config_zonePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hydraulique_config_zonePresenter::changeStatutRF(S_STATUT_RF *sStatut_RF)
{
	view.changeStatutRF(sStatut_RF);
}

void Installation_hydraulique_config_zonePresenter::c_install_zx(uint8_t u8NumZone)
{
	model->c_install_zx(u8NumZone);
}
