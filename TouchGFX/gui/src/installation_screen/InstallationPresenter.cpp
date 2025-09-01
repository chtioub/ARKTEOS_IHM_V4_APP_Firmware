#include <gui/installation_screen/InstallationView.hpp>
#include <gui/installation_screen/InstallationPresenter.hpp>

InstallationPresenter::InstallationPresenter(InstallationView& v)
    : view(v)
{

}

void InstallationPresenter::activate()
{

}

void InstallationPresenter::deactivate()
{

}

void InstallationPresenter::c_prog_silence(bool bEnvoi)
{
	model->c_prog_silence(bEnvoi);
}

void InstallationPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void InstallationPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void InstallationPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void InstallationPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void InstallationPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
