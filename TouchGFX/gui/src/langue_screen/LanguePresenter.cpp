#include <gui/langue_screen/LangueView.hpp>
#include <gui/langue_screen/LanguePresenter.hpp>

LanguePresenter::LanguePresenter(LangueView& v)
    : view(v)
{

}

void LanguePresenter::activate()
{

}

void LanguePresenter::deactivate()
{

}

void LanguePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void LanguePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void LanguePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void LanguePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void LanguePresenter::c_user_param()
{
	model->c_user_param();
}
