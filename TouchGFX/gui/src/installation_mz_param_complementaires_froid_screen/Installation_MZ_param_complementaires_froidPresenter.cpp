#include <gui/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidView.hpp>
#include <gui/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidPresenter.hpp>

Installation_MZ_param_complementaires_froidPresenter::Installation_MZ_param_complementaires_froidPresenter(Installation_MZ_param_complementaires_froidView& v)
    : view(v)
{

}

void Installation_MZ_param_complementaires_froidPresenter::activate()
{

}

void Installation_MZ_param_complementaires_froidPresenter::deactivate()
{

}

void Installation_MZ_param_complementaires_froidPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_MZ_param_complementaires_froidPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_MZ_param_complementaires_froidPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_MZ_param_complementaires_froidPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}


void Installation_MZ_param_complementaires_froidPresenter::c_install_zx(uint8_t u8NumZone)
{
	model->c_install_zx(u8NumZone);
}
