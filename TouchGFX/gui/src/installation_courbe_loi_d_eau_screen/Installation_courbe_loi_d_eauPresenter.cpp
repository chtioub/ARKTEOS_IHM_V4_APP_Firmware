#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauView.hpp>
#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauPresenter.hpp>

Installation_courbe_loi_d_eauPresenter::Installation_courbe_loi_d_eauPresenter(Installation_courbe_loi_d_eauView& v)
    : view(v)
{

}

void Installation_courbe_loi_d_eauPresenter::activate()
{

}

void Installation_courbe_loi_d_eauPresenter::deactivate()
{

}

void Installation_courbe_loi_d_eauPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Installation_courbe_loi_d_eauPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_courbe_loi_d_eauPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_courbe_loi_d_eauPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_courbe_loi_d_eauPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_courbe_loi_d_eauPresenter::c_install_reg_ext()
{
	model->c_install_reg_ext();
}
