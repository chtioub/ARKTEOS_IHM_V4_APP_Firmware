#include <gui/bouclage_ecs_screen/Bouclage_ecsView.hpp>
#include <gui/bouclage_ecs_screen/Bouclage_ecsPresenter.hpp>

Bouclage_ecsPresenter::Bouclage_ecsPresenter(Bouclage_ecsView& v)
    : view(v)
{

}

void Bouclage_ecsPresenter::activate()
{

}

void Bouclage_ecsPresenter::deactivate()
{

}

void Bouclage_ecsPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Bouclage_ecsPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Bouclage_ecsPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Bouclage_ecsPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Bouclage_ecsPresenter::c_user_ecs()
{
	model->c_user_ecs();
}

void Bouclage_ecsPresenter::c_prog_option(bool bEnvoi)
{
	model->c_prog_option(bEnvoi);
}
