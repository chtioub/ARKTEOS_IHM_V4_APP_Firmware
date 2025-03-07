#include <gui/installation_gestion_v3v_screen/Installation_gestion_v3vView.hpp>
#include <gui/installation_gestion_v3v_screen/Installation_gestion_v3vPresenter.hpp>

Installation_gestion_v3vPresenter::Installation_gestion_v3vPresenter(Installation_gestion_v3vView& v)
    : view(v)
{

}

void Installation_gestion_v3vPresenter::activate()
{

}

void Installation_gestion_v3vPresenter::deactivate()
{

}

void Installation_gestion_v3vPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_gestion_v3vPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_gestion_v3vPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_gestion_v3vPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_gestion_v3vPresenter::c_install_piscine()
{
	model->c_install_piscine();
}
