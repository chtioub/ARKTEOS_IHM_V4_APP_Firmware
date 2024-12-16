#include <gui/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesView.hpp>
#include <gui/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesPresenter.hpp>

Installation_MZ_param_ou_regroupement_zonesPresenter::Installation_MZ_param_ou_regroupement_zonesPresenter(Installation_MZ_param_ou_regroupement_zonesView& v)
    : view(v)
{

}

void Installation_MZ_param_ou_regroupement_zonesPresenter::activate()
{

}

void Installation_MZ_param_ou_regroupement_zonesPresenter::deactivate()
{

}


void Installation_MZ_param_ou_regroupement_zonesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_MZ_param_ou_regroupement_zonesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_MZ_param_ou_regroupement_zonesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_MZ_param_ou_regroupement_zonesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_MZ_param_ou_regroupement_zonesPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
