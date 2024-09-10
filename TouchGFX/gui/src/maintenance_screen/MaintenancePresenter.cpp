#include <gui/maintenance_screen/MaintenanceView.hpp>
#include <gui/maintenance_screen/MaintenancePresenter.hpp>

MaintenancePresenter::MaintenancePresenter(MaintenanceView& v)
    : view(v)
{

}

void MaintenancePresenter::activate()
{

}

void MaintenancePresenter::deactivate()
{

}

void MaintenancePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void MaintenancePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void MaintenancePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void MaintenancePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void MaintenancePresenter::changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo)
{
	view.changeDemandeFrigo(sDemandeFrigo);
}

void MaintenancePresenter::c_sav_histo_err()
{
	model->c_sav_histo_err();
}
