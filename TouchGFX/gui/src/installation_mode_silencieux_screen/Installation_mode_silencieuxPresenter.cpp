#include <gui/installation_mode_silencieux_screen/Installation_mode_silencieuxView.hpp>
#include <gui/installation_mode_silencieux_screen/Installation_mode_silencieuxPresenter.hpp>

Installation_mode_silencieuxPresenter::Installation_mode_silencieuxPresenter(Installation_mode_silencieuxView& v)
    : view(v)
{

}

void Installation_mode_silencieuxPresenter::activate()
{

}

void Installation_mode_silencieuxPresenter::deactivate()
{

}

void Installation_mode_silencieuxPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_mode_silencieuxPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_mode_silencieuxPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_mode_silencieuxPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_mode_silencieuxPresenter::c_user_param()
{
	model->c_user_param();
}

void Installation_mode_silencieuxPresenter::c_install_param()
{
	model->c_install_param();
}

