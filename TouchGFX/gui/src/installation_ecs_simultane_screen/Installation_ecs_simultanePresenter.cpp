#include <gui/installation_ecs_simultane_screen/Installation_ecs_simultaneView.hpp>
#include <gui/installation_ecs_simultane_screen/Installation_ecs_simultanePresenter.hpp>

Installation_ecs_simultanePresenter::Installation_ecs_simultanePresenter(Installation_ecs_simultaneView& v)
    : view(v)
{

}

void Installation_ecs_simultanePresenter::c_install_ecs()
{
	model->c_install_ecs();
}

void Installation_ecs_simultanePresenter::activate()
{

}

void Installation_ecs_simultanePresenter::deactivate()
{

}

void Installation_ecs_simultanePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_simultanePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_simultanePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_simultanePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
