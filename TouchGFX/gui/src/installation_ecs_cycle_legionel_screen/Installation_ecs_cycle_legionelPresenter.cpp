#include <gui/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelView.hpp>
#include <gui/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelPresenter.hpp>

Installation_ecs_cycle_legionelPresenter::Installation_ecs_cycle_legionelPresenter(Installation_ecs_cycle_legionelView& v)
    : view(v)
{

}

void Installation_ecs_cycle_legionelPresenter::c_install_ecs()
{
	model->c_install_ecs();
}

void Installation_ecs_cycle_legionelPresenter::activate()
{

}

void Installation_ecs_cycle_legionelPresenter::deactivate()
{

}

void Installation_ecs_cycle_legionelPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_cycle_legionelPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_cycle_legionelPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_cycle_legionelPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
