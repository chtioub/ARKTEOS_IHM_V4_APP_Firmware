#include <gui/usine_config_geotwin_screen/Usine_config_geotwinView.hpp>
#include <gui/usine_config_geotwin_screen/Usine_config_geotwinPresenter.hpp>

Usine_config_geotwinPresenter::Usine_config_geotwinPresenter(Usine_config_geotwinView& v)
    : view(v)
{

}

void Usine_config_geotwinPresenter::activate()
{

}

void Usine_config_geotwinPresenter::deactivate()
{

}

void Usine_config_geotwinPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_config_geotwinPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_config_geotwinPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_config_geotwinPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Usine_config_geotwinPresenter::c_usine_param()
{
	model->c_usine_param();
}
