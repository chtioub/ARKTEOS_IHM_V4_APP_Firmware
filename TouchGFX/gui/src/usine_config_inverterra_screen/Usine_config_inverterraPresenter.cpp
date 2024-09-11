#include <gui/usine_config_inverterra_screen/Usine_config_inverterraView.hpp>
#include <gui/usine_config_inverterra_screen/Usine_config_inverterraPresenter.hpp>

Usine_config_inverterraPresenter::Usine_config_inverterraPresenter(Usine_config_inverterraView& v)
    : view(v)
{

}

void Usine_config_inverterraPresenter::activate()
{

}

void Usine_config_inverterraPresenter::deactivate()
{

}

void Usine_config_inverterraPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_config_inverterraPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_config_inverterraPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_config_inverterraPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Usine_config_inverterraPresenter::c_usine_param()
{
	model->c_usine_param();
}
