#include <gui/vacances_screen/VacancesView.hpp>
#include <gui/vacances_screen/VacancesPresenter.hpp>

VacancesPresenter::VacancesPresenter(VacancesView& v)
    : view(v)
{

}

void VacancesPresenter::activate()
{

}

void VacancesPresenter::deactivate()
{

}

void VacancesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void VacancesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void VacancesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void VacancesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void VacancesPresenter::c_user_vacances()
{
	model->c_user_vacances();
}
