#include <gui/erreurs_screen/ErreursView.hpp>
#include <gui/erreurs_screen/ErreursPresenter.hpp>

ErreursPresenter::ErreursPresenter(ErreursView& v)
    : view(v)
{

}

void ErreursPresenter::activate()
{

}

void ErreursPresenter::deactivate()
{

}

void ErreursPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void ErreursPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void ErreursPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void ErreursPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
