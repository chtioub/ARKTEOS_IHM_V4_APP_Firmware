#include <gui/installation_appoint_screen/Installation_appointView.hpp>
#include <gui/installation_appoint_screen/Installation_appointPresenter.hpp>

Installation_appointPresenter::Installation_appointPresenter(Installation_appointView& v)
    : view(v)
{

}

void Installation_appointPresenter::activate()
{

}

void Installation_appointPresenter::deactivate()
{

}

void Installation_appointPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_appointPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_appointPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_appointPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_appointPresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_appointPresenter::c_install_ecs()
{
	model->c_install_ecs();
}
