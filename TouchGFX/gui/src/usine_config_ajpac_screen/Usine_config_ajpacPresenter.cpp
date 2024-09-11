#include <gui/usine_config_ajpac_screen/Usine_config_ajpacView.hpp>
#include <gui/usine_config_ajpac_screen/Usine_config_ajpacPresenter.hpp>

Usine_config_ajpacPresenter::Usine_config_ajpacPresenter(Usine_config_ajpacView& v)
    : view(v)
{

}

void Usine_config_ajpacPresenter::activate()
{

}

void Usine_config_ajpacPresenter::deactivate()
{

}

void Usine_config_ajpacPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_config_ajpacPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_config_ajpacPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_config_ajpacPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Usine_config_ajpacPresenter::c_usine_param()
{
	model->c_usine_param();
}

