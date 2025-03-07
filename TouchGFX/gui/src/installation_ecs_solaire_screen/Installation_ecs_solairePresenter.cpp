#include <gui/installation_ecs_solaire_screen/Installation_ecs_solaireView.hpp>
#include <gui/installation_ecs_solaire_screen/Installation_ecs_solairePresenter.hpp>

Installation_ecs_solairePresenter::Installation_ecs_solairePresenter(Installation_ecs_solaireView& v)
    : view(v)
{

}

void Installation_ecs_solairePresenter::activate()
{

}

void Installation_ecs_solairePresenter::deactivate()
{

}

void Installation_ecs_solairePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_solairePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_solairePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_solairePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_ecs_solairePresenter::c_install_ecs()
{
	model->c_install_ecs();
}

