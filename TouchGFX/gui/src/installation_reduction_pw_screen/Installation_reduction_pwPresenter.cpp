#include <gui/installation_reduction_pw_screen/Installation_reduction_pwView.hpp>
#include <gui/installation_reduction_pw_screen/Installation_reduction_pwPresenter.hpp>

Installation_reduction_pwPresenter::Installation_reduction_pwPresenter(Installation_reduction_pwView& v)
    : view(v)
{

}

void Installation_reduction_pwPresenter::activate()
{

}

void Installation_reduction_pwPresenter::deactivate()
{

}

void Installation_reduction_pwPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_reduction_pwPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_reduction_pwPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_reduction_pwPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_reduction_pwPresenter::c_install_param()
{
	model->c_install_param();
}
