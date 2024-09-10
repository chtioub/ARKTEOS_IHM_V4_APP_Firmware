#include <gui/installation_piscine_avances_screen/Installation_piscine_avancesView.hpp>
#include <gui/installation_piscine_avances_screen/Installation_piscine_avancesPresenter.hpp>

Installation_piscine_avancesPresenter::Installation_piscine_avancesPresenter(Installation_piscine_avancesView& v)
    : view(v)
{

}

void Installation_piscine_avancesPresenter::activate()
{

}

void Installation_piscine_avancesPresenter::deactivate()
{

}

void Installation_piscine_avancesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_piscine_avancesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_piscine_avancesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_piscine_avancesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_piscine_avancesPresenter::c_install_piscine()
{
	model->c_install_piscine();
}

void Installation_piscine_avancesPresenter::c_prog_piscine(bool bEnvoi)
{
	model->c_prog_piscine(bEnvoi);
}
