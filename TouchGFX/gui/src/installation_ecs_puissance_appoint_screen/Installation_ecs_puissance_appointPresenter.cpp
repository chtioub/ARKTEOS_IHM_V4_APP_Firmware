#include <gui/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointView.hpp>
#include <gui/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointPresenter.hpp>

Installation_ecs_puissance_appointPresenter::Installation_ecs_puissance_appointPresenter(Installation_ecs_puissance_appointView& v)
    : view(v)
{

}

void Installation_ecs_puissance_appointPresenter::activate()
{

}

void Installation_ecs_puissance_appointPresenter::deactivate()
{

}

void Installation_ecs_puissance_appointPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_puissance_appointPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_puissance_appointPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_puissance_appointPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_ecs_puissance_appointPresenter::c_install_ecs()
{
	model->c_install_ecs();
}

