#include <gui/installation_config_in_out_screen/Installation_config_in_outView.hpp>
#include <gui/installation_config_in_out_screen/Installation_config_in_outPresenter.hpp>

Installation_config_in_outPresenter::Installation_config_in_outPresenter(Installation_config_in_outView& v)
    : view(v)
{

}

void Installation_config_in_outPresenter::activate()
{

}

void Installation_config_in_outPresenter::deactivate()
{

}

void Installation_config_in_outPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_config_in_outPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_config_in_outPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_config_in_outPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_config_in_outPresenter::c_install_param()
{
	model->c_install_param();
}
