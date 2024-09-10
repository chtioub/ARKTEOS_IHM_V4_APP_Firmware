#include <gui/position_ecran_screen/Position_ecranView.hpp>
#include <gui/position_ecran_screen/Position_ecranPresenter.hpp>

Position_ecranPresenter::Position_ecranPresenter(Position_ecranView& v)
    : view(v)
{

}

void Position_ecranPresenter::activate()
{

}

void Position_ecranPresenter::deactivate()
{

}

void Position_ecranPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Position_ecranPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Position_ecranPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Position_ecranPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Position_ecranPresenter::c_user_param()
{
	model->c_user_param();
}

