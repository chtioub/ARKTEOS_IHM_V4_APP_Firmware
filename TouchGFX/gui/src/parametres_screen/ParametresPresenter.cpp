#include <gui/parametres_screen/ParametresView.hpp>
#include <gui/parametres_screen/ParametresPresenter.hpp>

ParametresPresenter::ParametresPresenter(ParametresView& v)
    : view(v)
{

}

void ParametresPresenter::activate()
{

}

void ParametresPresenter::deactivate()
{

}

void ParametresPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void ParametresPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void ParametresPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void ParametresPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
