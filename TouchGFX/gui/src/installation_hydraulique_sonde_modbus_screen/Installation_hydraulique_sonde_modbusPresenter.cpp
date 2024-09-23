#include <gui/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusView.hpp>
#include <gui/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusPresenter.hpp>

Installation_hydraulique_sonde_modbusPresenter::Installation_hydraulique_sonde_modbusPresenter(Installation_hydraulique_sonde_modbusView& v)
    : view(v)
{

}

void Installation_hydraulique_sonde_modbusPresenter::activate()
{

}

void Installation_hydraulique_sonde_modbusPresenter::deactivate()
{

}

void Installation_hydraulique_sonde_modbusPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_sonde_modbusPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_sonde_modbusPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_sonde_modbusPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hydraulique_sonde_modbusPresenter::c_install_zx(uint8_t u8NumZone)
{
	model->c_install_zx(u8NumZone);
}
