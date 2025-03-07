#include <gui/installation_param_avances_screen/Installation_param_avancesView.hpp>
#include <gui/installation_param_avances_screen/Installation_param_avancesPresenter.hpp>

Installation_param_avancesPresenter::Installation_param_avancesPresenter(Installation_param_avancesView& v)
    : view(v)
{

}

void Installation_param_avancesPresenter::activate()
{

}

void Installation_param_avancesPresenter::deactivate()
{

}

void Installation_param_avancesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_param_avancesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_param_avancesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_param_avancesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

