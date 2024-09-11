#include <gui/usine_config_additionnelle_screen/Usine_config_additionnelleView.hpp>
#include <gui/usine_config_additionnelle_screen/Usine_config_additionnellePresenter.hpp>

Usine_config_additionnellePresenter::Usine_config_additionnellePresenter(Usine_config_additionnelleView& v)
    : view(v)
{

}

void Usine_config_additionnellePresenter::activate()
{

}

void Usine_config_additionnellePresenter::deactivate()
{

}

void Usine_config_additionnellePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_config_additionnellePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_config_additionnellePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_config_additionnellePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Usine_config_additionnellePresenter::c_install_param()
{
	model->c_install_param();
}
