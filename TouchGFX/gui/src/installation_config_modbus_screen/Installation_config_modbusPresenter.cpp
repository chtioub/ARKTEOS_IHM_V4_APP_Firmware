#include <gui/installation_config_modbus_screen/Installation_config_modbusView.hpp>
#include <gui/installation_config_modbus_screen/Installation_config_modbusPresenter.hpp>

Installation_config_modbusPresenter::Installation_config_modbusPresenter(Installation_config_modbusView& v)
    : view(v)
{

}

void Installation_config_modbusPresenter::activate()
{

}

void Installation_config_modbusPresenter::deactivate()
{

}

void Installation_config_modbusPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_config_modbusPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_config_modbusPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_config_modbusPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_config_modbusPresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_config_modbusPresenter::c_install_modbus()
{
	model->c_install_modbus();
}

