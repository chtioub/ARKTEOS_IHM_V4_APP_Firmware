#include <gui/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupeView.hpp>
#include <gui/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupePresenter.hpp>

Installation_MZ_param_complementaires_groupePresenter::Installation_MZ_param_complementaires_groupePresenter(Installation_MZ_param_complementaires_groupeView& v)
    : view(v)
{

}

void Installation_MZ_param_complementaires_groupePresenter::activate()
{

}

void Installation_MZ_param_complementaires_groupePresenter::deactivate()
{

}

void Installation_MZ_param_complementaires_groupePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_MZ_param_complementaires_groupePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_MZ_param_complementaires_groupePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_MZ_param_complementaires_groupePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_MZ_param_complementaires_groupePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
