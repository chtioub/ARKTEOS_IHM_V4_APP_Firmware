#include <gui/installation_hysteresis_screen/Installation_hysteresisView.hpp>
#include <gui/installation_hysteresis_screen/Installation_hysteresisPresenter.hpp>

Installation_hysteresisPresenter::Installation_hysteresisPresenter(Installation_hysteresisView& v)
    : view(v)
{

}

void Installation_hysteresisPresenter::activate()
{

}

void Installation_hysteresisPresenter::deactivate()
{

}

void Installation_hysteresisPresenter::c_install_param_zx()
{
	model->c_install_param_zx();
}

void Installation_hysteresisPresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_hysteresisPresenter::c_install_ecs()
{
	model->c_install_ecs();
}

void Installation_hysteresisPresenter::c_install_piscine()
{
	model->c_install_piscine();
}

void Installation_hysteresisPresenter::c_install_config_pac()
{
	model->c_install_config_pac();
}

void Installation_hysteresisPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hysteresisPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hysteresisPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hysteresisPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hysteresisPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
//void Installation_hysteresisPresenter::Red_Butt()
//{
//	view.Red_Butt();
//}
//
//void Installation_hysteresisPresenter::Blue_Butt()
//{
//	view.Blue_Butt();
//}
