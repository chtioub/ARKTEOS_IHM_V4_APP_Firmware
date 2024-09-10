#include <gui/derogation_ecs_screen/Derogation_ecsView.hpp>
#include <gui/derogation_ecs_screen/Derogation_ecsPresenter.hpp>

Derogation_ecsPresenter::Derogation_ecsPresenter(Derogation_ecsView& v)
    : view(v)
{

}

void Derogation_ecsPresenter::activate()
{

}

void Derogation_ecsPresenter::deactivate()
{

}

void Derogation_ecsPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Derogation_ecsPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Derogation_ecsPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Derogation_ecsPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Derogation_ecsPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Derogation_ecsPresenter::c_user_ecs()
{
	model->c_user_ecs();
}
