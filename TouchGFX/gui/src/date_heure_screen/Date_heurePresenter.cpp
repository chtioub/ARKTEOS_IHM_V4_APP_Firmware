#include <gui/date_heure_screen/Date_heureView.hpp>
#include <gui/date_heure_screen/Date_heurePresenter.hpp>

Date_heurePresenter::Date_heurePresenter(Date_heureView& v)
    : view(v)
{

}

void Date_heurePresenter::activate()
{

}

void Date_heurePresenter::deactivate()
{

}

void Date_heurePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Date_heurePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Date_heurePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Date_heurePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
