#include <gui/page_oui_non_screen/Page_oui_nonView.hpp>
#include <gui/page_oui_non_screen/Page_oui_nonPresenter.hpp>

Page_oui_nonPresenter::Page_oui_nonPresenter(Page_oui_nonView& v)
    : view(v)
{

}

void Page_oui_nonPresenter::activate()
{

}

void Page_oui_nonPresenter::deactivate()
{

}
void Page_oui_nonPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Page_oui_nonPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Page_oui_nonPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Page_oui_nonPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Page_oui_nonPresenter::c_user_param()
{
	model->c_user_param();
}

void Page_oui_nonPresenter::c_user_zx_all()
{
	model->c_user_zx_all();
}

void Page_oui_nonPresenter::c_user_ecs()
{
	model->c_user_ecs();
}

void Page_oui_nonPresenter::c_user_date()
{
	model->c_user_date();
}

void Page_oui_nonPresenter::c_ener_raz()
{
	model->c_ener_raz();
}

void Page_oui_nonPresenter::c_install_param()
{
	model->c_install_param();
}

void Page_oui_nonPresenter::c_install_raz_config()
{
	model->c_install_raz_config();
}

void Page_oui_nonPresenter::c_install_config_pac()
{
	model->c_install_config_pac();
}

void Page_oui_nonPresenter::c_install_piscine()
{
	model->c_install_piscine();
}

void Page_oui_nonPresenter::c_install_raz_histo_err()
{
	model->c_install_raz_histo_err();
}

void Page_oui_nonPresenter::c_usine_password()
{
	model->c_usine_password();
}

void Page_oui_nonPresenter::c_usine_raz_energie()
{
	model->c_usine_raz_energie();
}

void Page_oui_nonPresenter::c_usine_raz_config()
{
	model->c_usine_raz_config();
}

void Page_oui_nonPresenter::c_sav_param()
{
	model->c_sav_param();
}

void Page_oui_nonPresenter::c_sav_shunt_tempo()
{
	model->c_sav_shunt_tempo();
}

void Page_oui_nonPresenter::c_sav_raz_tps_fonct(uint8_t u8Esclave)
{
	model->c_sav_raz_tps_fonct(u8Esclave);
}

void Page_oui_nonPresenter::c_sav_raz_soft_flash()
{
	model->c_sav_raz_soft_flash();
}

void Page_oui_nonPresenter::c_sav_raz_log()
{
	model->c_sav_raz_log();
}

void Page_oui_nonPresenter::c_restart()
{
	model->c_restart();
}
