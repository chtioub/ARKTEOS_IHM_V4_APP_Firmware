#include <gui/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.hpp>
#include <gui/eau_chaude_sanitaire_screen/Eau_chaude_sanitairePresenter.hpp>

Eau_chaude_sanitairePresenter::Eau_chaude_sanitairePresenter(Eau_chaude_sanitaireView& v)
    : view(v)
{

}

void Eau_chaude_sanitairePresenter::activate()
{

}

void Eau_chaude_sanitairePresenter::deactivate()
{

}

void Eau_chaude_sanitairePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Eau_chaude_sanitairePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Eau_chaude_sanitairePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Eau_chaude_sanitairePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Eau_chaude_sanitairePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Eau_chaude_sanitairePresenter::c_user_ecs()
{
	model->c_user_ecs();
}

void Eau_chaude_sanitairePresenter::c_prog_option(bool bEnvoi)
{
	model->c_prog_option(bEnvoi);
}

void Eau_chaude_sanitairePresenter::c_prog_ecs(bool bEnvoi)
{
	model->c_prog_ecs(bEnvoi);
}
