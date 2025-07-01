#include <gui/maintenance_fct_avances_screen/Maintenance_fct_avancesView.hpp>
#include <gui/maintenance_fct_avances_screen/Maintenance_fct_avancesPresenter.hpp>

Maintenance_fct_avancesPresenter::Maintenance_fct_avancesPresenter(Maintenance_fct_avancesView& v)
    : view(v)
{

}

void Maintenance_fct_avancesPresenter::activate()
{

}

void Maintenance_fct_avancesPresenter::deactivate()
{

}


void Maintenance_fct_avancesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Maintenance_fct_avancesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Maintenance_fct_avancesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Maintenance_fct_avancesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
