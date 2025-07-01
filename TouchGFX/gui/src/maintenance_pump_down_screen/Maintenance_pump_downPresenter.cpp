#include <gui/maintenance_pump_down_screen/Maintenance_pump_downView.hpp>
#include <gui/maintenance_pump_down_screen/Maintenance_pump_downPresenter.hpp>

Maintenance_pump_downPresenter::Maintenance_pump_downPresenter(Maintenance_pump_downView& v)
    : view(v)
{

}

void Maintenance_pump_downPresenter::activate()
{

}

void Maintenance_pump_downPresenter::deactivate()
{

}

void Maintenance_pump_downPresenter::c_sav_mode_pump_down_recup_ui()
{
	model->c_sav_mode_pump_down_recup_ui();
}

void Maintenance_pump_downPresenter::c_sav_mode_pump_down_recup_ue()
{
	model->c_sav_mode_pump_down_recup_ue();
}

void Maintenance_pump_downPresenter::c_sav_mode_pump_down_stop()
{
	model->c_sav_mode_pump_down_stop();
}
void Maintenance_pump_downPresenter::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	view.changeStatutCyclFrigo(sCyclRegFrigo);
}

void Maintenance_pump_downPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Maintenance_pump_downPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Maintenance_pump_downPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Maintenance_pump_downPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
