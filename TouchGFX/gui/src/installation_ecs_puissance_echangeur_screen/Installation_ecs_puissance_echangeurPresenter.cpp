#include <gui/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurView.hpp>
#include <gui/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurPresenter.hpp>

Installation_ecs_puissance_echangeurPresenter::Installation_ecs_puissance_echangeurPresenter(Installation_ecs_puissance_echangeurView& v)
    : view(v)
{

}

void Installation_ecs_puissance_echangeurPresenter::activate()
{

}

void Installation_ecs_puissance_echangeurPresenter::deactivate()
{

}

void Installation_ecs_puissance_echangeurPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_ecs_puissance_echangeurPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_ecs_puissance_echangeurPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_ecs_puissance_echangeurPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_ecs_puissance_echangeurPresenter::c_install_ecs()
{
	model->c_install_ecs();
}
