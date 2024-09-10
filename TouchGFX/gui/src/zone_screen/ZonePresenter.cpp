#include <gui/zone_screen/ZoneView.hpp>
#include <gui/zone_screen/ZonePresenter.hpp>

ZonePresenter::ZonePresenter(ZoneView& v)
    : view(v)
{

}

void ZonePresenter::activate()
{

}

void ZonePresenter::deactivate()
{

}

void ZonePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void ZonePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void ZonePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void ZonePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void ZonePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void ZonePresenter::c_user_param()
{
	model->c_user_param();
}

void ZonePresenter::c_user_zx(uint8_t u8Zone)
{
	model->c_user_zx(u8Zone);
}

void ZonePresenter::c_user_reg_ext()
{
	model->c_user_reg_ext();
}

void ZonePresenter::c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi)
{
	model->c_prog_zone_chaud(u8Zone, bEnvoi);
}

void ZonePresenter::c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi)
{
	model->c_prog_zone_froid(u8Zone, bEnvoi);
}

void ZonePresenter::c_prog_reg_ext_chaud(bool bEnvoi)
{
	model->c_prog_reg_ext_chaud(bEnvoi);
}

void ZonePresenter::c_prog_reg_ext_froid(bool bEnvoi)
{
	model->c_prog_reg_ext_froid(bEnvoi);
}
