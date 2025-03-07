#include <gui/installation_ecs_screen/Installation_ecsView.hpp>
#include <gui/installation_ecs_screen/Installation_ecsPresenter.hpp>

Installation_ecsPresenter::Installation_ecsPresenter(Installation_ecsView& v)
    : view(v)
{

}

void Installation_ecsPresenter::activate()
{

}

void Installation_ecsPresenter::deactivate()
{

}

void Installation_ecsPresenter::c_install_param()
{
	model->c_install_param();;
}


void Installation_ecsPresenter::c_install_ecs()
{
	model->c_install_ecs();
}

void Installation_ecsPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecsPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecsPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecsPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}


