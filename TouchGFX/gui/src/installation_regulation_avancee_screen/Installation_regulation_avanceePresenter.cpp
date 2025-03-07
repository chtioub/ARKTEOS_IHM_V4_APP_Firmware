#include <gui/installation_regulation_avancee_screen/Installation_regulation_avanceeView.hpp>
#include <gui/installation_regulation_avancee_screen/Installation_regulation_avanceePresenter.hpp>

Installation_regulation_avanceePresenter::Installation_regulation_avanceePresenter(Installation_regulation_avanceeView& v)
    : view(v)
{

}

void Installation_regulation_avanceePresenter::activate()
{

}

void Installation_regulation_avanceePresenter::deactivate()
{

}

void Installation_regulation_avanceePresenter::c_install_config_pac()
{
	model->c_install_config_pac();
}

void Installation_regulation_avanceePresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_regulation_avanceePresenter::c_user_param()
{
	model->c_user_param();
}

void Installation_regulation_avanceePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_regulation_avanceePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_regulation_avanceePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_regulation_avanceePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

//void Installation_regulation_avanceePresenter::c_install_piscine()
//{
//	model->c_install_piscine();
//}
