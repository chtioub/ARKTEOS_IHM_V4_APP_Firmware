#include <gui/installation_ecs_avances_screen/Installation_ecs_avancesView.hpp>
#include <gui/installation_ecs_avances_screen/Installation_ecs_avancesPresenter.hpp>

Installation_ecs_avancesPresenter::Installation_ecs_avancesPresenter(Installation_ecs_avancesView& v)
    : view(v)
{

}

void Installation_ecs_avancesPresenter::activate()
{

}

void Installation_ecs_avancesPresenter::deactivate()
{

}

void Installation_ecs_avancesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_avancesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_avancesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_avancesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_ecs_avancesPresenter::c_install_ecs()
{
	model->c_install_ecs();
}

