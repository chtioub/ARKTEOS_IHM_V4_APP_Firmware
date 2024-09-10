#include <gui/installation_wattmetre_screen/Installation_wattmetreView.hpp>
#include <gui/installation_wattmetre_screen/Installation_wattmetrePresenter.hpp>

Installation_wattmetrePresenter::Installation_wattmetrePresenter(Installation_wattmetreView& v)
    : view(v)
{

}

void Installation_wattmetrePresenter::activate()
{

}

void Installation_wattmetrePresenter::deactivate()
{

}

void Installation_wattmetrePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_wattmetrePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_wattmetrePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_wattmetrePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_wattmetrePresenter::c_install_param()
{
	model->c_install_param();
}
