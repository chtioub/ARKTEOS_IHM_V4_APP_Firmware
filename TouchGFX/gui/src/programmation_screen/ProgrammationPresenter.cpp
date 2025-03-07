#include <gui/programmation_screen/ProgrammationView.hpp>
#include <gui/programmation_screen/ProgrammationPresenter.hpp>

ProgrammationPresenter::ProgrammationPresenter(ProgrammationView& v)
    : view(v)
{

}

void ProgrammationPresenter::activate()
{

}

void ProgrammationPresenter::deactivate()
{

}

void ProgrammationPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void ProgrammationPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void ProgrammationPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void ProgrammationPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void ProgrammationPresenter::c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi)
{
	model->c_prog_zone_chaud(u8Zone, bEnvoi);
}

void ProgrammationPresenter::c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi)
{
	model->c_prog_zone_froid(u8Zone, bEnvoi);
}

void ProgrammationPresenter::c_prog_piscine(bool bEnvoi)
{
	model->c_prog_piscine(bEnvoi);
}

void ProgrammationPresenter::c_prog_option(bool bEnvoi)
{
	model->c_prog_option(bEnvoi);
}

void ProgrammationPresenter::c_prog_ecs(bool bEnvoi)
{
	model->c_prog_ecs(bEnvoi);
}

void ProgrammationPresenter::c_prog_reg_ext_chaud(bool bEnvoi)
{
	model->c_prog_reg_ext_chaud(bEnvoi);
}

void ProgrammationPresenter::c_prog_reg_ext_froid(bool bEnvoi)
{
	model->c_prog_reg_ext_froid(bEnvoi);
}

void ProgrammationPresenter::c_prog_silence(bool bEnvoi)
{
	model->c_prog_silence(bEnvoi);
}

