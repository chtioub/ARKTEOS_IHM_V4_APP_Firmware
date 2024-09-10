#include <gui/usine_param_avances_screen/Usine_param_avancesView.hpp>
#include <gui/usine_param_avances_screen/Usine_param_avancesPresenter.hpp>

Usine_param_avancesPresenter::Usine_param_avancesPresenter(Usine_param_avancesView& v)
    : view(v)
{

}

void Usine_param_avancesPresenter::activate()
{

}

void Usine_param_avancesPresenter::deactivate()
{

}

void Usine_param_avancesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_param_avancesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_param_avancesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_param_avancesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
