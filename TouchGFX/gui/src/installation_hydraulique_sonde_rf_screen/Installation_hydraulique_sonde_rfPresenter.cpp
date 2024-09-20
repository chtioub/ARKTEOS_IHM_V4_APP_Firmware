#include <gui/installation_hydraulique_sonde_rf_screen/Installation_hydraulique_sonde_rfView.hpp>
#include <gui/installation_hydraulique_sonde_rf_screen/Installation_hydraulique_sonde_rfPresenter.hpp>

Installation_hydraulique_sonde_rfPresenter::Installation_hydraulique_sonde_rfPresenter(Installation_hydraulique_sonde_rfView& v)
    : view(v)
{

}

void Installation_hydraulique_sonde_rfPresenter::activate()
{

}

void Installation_hydraulique_sonde_rfPresenter::deactivate()
{

}

void Installation_hydraulique_sonde_rfPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_sonde_rfPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_sonde_rfPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_sonde_rfPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hydraulique_sonde_rfPresenter::changeStatutRF(S_STATUT_RF *sStatut_RF)
{
	view.changeStatutRF(sStatut_RF);
}

void Installation_hydraulique_sonde_rfPresenter::c_install_zx(uint8_t u8NumZone)
{
	model->c_install_zx(u8NumZone);
}

void Installation_hydraulique_sonde_rfPresenter::c_install_th_association(uint8_t u8NumZone)
{
	model->c_install_th_association(u8NumZone);
}

void Installation_hydraulique_sonde_rfPresenter::c_install_th_dissociation(uint8_t u8NumZone)
{
	model->c_install_th_dissociation(u8NumZone);
}
