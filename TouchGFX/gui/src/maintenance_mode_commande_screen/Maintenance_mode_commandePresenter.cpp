#include <gui/maintenance_mode_commande_screen/Maintenance_mode_commandeView.hpp>
#include <gui/maintenance_mode_commande_screen/Maintenance_mode_commandePresenter.hpp>

Maintenance_mode_commandePresenter::Maintenance_mode_commandePresenter(Maintenance_mode_commandeView& v)
    : view(v)
{

}

void Maintenance_mode_commandePresenter::activate()
{

}

void Maintenance_mode_commandePresenter::deactivate()
{

}

void Maintenance_mode_commandePresenter::c_sav_par21()
{
	model->c_sav_par21();
}

void Maintenance_mode_commandePresenter::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	view.changeStatutCyclFrigo(sCyclRegFrigo);
}

void Maintenance_mode_commandePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Maintenance_mode_commandePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Maintenance_mode_commandePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Maintenance_mode_commandePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
