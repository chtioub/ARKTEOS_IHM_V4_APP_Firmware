#include <gui/installation_mz_reglage_debit_air_screen/Installation_MZ_reglage_debit_airView.hpp>
#include <gui/installation_mz_reglage_debit_air_screen/Installation_MZ_reglage_debit_airPresenter.hpp>

Installation_MZ_reglage_debit_airPresenter::Installation_MZ_reglage_debit_airPresenter(Installation_MZ_reglage_debit_airView& v)
    : view(v)
{

}

void Installation_MZ_reglage_debit_airPresenter::activate()
{

}

void Installation_MZ_reglage_debit_airPresenter::deactivate()
{

}

void Installation_MZ_reglage_debit_airPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_MZ_reglage_debit_airPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_MZ_reglage_debit_airPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_MZ_reglage_debit_airPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_MZ_reglage_debit_airPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}


