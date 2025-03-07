#include <gui/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpView.hpp>
#include <gui/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpPresenter.hpp>

Installation_ecs_inhibition_ejpPresenter::Installation_ecs_inhibition_ejpPresenter(Installation_ecs_inhibition_ejpView& v)
    : view(v)
{

}

void Installation_ecs_inhibition_ejpPresenter::activate()
{

}

void Installation_ecs_inhibition_ejpPresenter::deactivate()
{

}

void Installation_ecs_inhibition_ejpPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_inhibition_ejpPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_inhibition_ejpPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_inhibition_ejpPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_ecs_inhibition_ejpPresenter::c_install_ecs()
{
	model->c_install_ecs();
}
