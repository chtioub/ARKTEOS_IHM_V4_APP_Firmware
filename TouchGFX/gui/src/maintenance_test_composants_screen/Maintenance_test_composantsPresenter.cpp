#include <gui/maintenance_test_composants_screen/Maintenance_test_composantsView.hpp>
#include <gui/maintenance_test_composants_screen/Maintenance_test_composantsPresenter.hpp>

Maintenance_test_composantsPresenter::Maintenance_test_composantsPresenter(Maintenance_test_composantsView& v)
    : view(v)
{

}

void Maintenance_test_composantsPresenter::activate()
{

}

void Maintenance_test_composantsPresenter::deactivate()
{

}

void Maintenance_test_composantsPresenter::c_sav_test_cps(uint16_t u16CodeTestCps)
{
	model->c_sav_test_cps(u16CodeTestCps);
}

void Maintenance_test_composantsPresenter::c_sav_test_cps_start()
{
	model->c_sav_test_cps_start();
}

void Maintenance_test_composantsPresenter::c_sav_test_cps_stop()
{
	model->c_sav_test_cps_stop();
}

void Maintenance_test_composantsPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Maintenance_test_composantsPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Maintenance_test_composantsPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Maintenance_test_composantsPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
