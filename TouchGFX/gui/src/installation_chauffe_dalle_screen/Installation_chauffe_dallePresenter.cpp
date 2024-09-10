#include <gui/installation_chauffe_dalle_screen/Installation_chauffe_dalleView.hpp>
#include <gui/installation_chauffe_dalle_screen/Installation_chauffe_dallePresenter.hpp>

Installation_chauffe_dallePresenter::Installation_chauffe_dallePresenter(Installation_chauffe_dalleView& v)
    : view(v)
{

}

void Installation_chauffe_dallePresenter::activate()
{

}

void Installation_chauffe_dallePresenter::deactivate()
{

}
void Installation_chauffe_dallePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_chauffe_dallePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_chauffe_dallePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_chauffe_dallePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_chauffe_dallePresenter::c_install_param()
{
	model->c_install_param();
}
