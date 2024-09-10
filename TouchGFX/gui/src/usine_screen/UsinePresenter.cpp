#include <gui/usine_screen/UsineView.hpp>
#include <gui/usine_screen/UsinePresenter.hpp>

UsinePresenter::UsinePresenter(UsineView& v)
    : view(v)
{

}

void UsinePresenter::activate()
{

}

void UsinePresenter::deactivate()
{

}

void UsinePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void UsinePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void UsinePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void UsinePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void UsinePresenter::c_sav_histo_err()
{
	model->c_sav_histo_err();
}
