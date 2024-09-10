#include <gui/installation_piscine_screen/Installation_piscineView.hpp>
#include <gui/installation_piscine_screen/Installation_piscinePresenter.hpp>

Installation_piscinePresenter::Installation_piscinePresenter(Installation_piscineView& v)
    : view(v)
{

}

void Installation_piscinePresenter::activate()
{

}

void Installation_piscinePresenter::deactivate()
{

}

void Installation_piscinePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_piscinePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_piscinePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_piscinePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_piscinePresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_piscinePresenter::c_install_piscine()
{
	model->c_install_piscine();
}
