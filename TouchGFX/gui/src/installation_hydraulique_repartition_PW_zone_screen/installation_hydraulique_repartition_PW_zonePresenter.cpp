#include <gui/installation_hydraulique_repartition_PW_zone_screen/Installation_hydraulique_repartition_PW_zoneView.hpp>
#include <gui/installation_hydraulique_repartition_PW_zone_screen/Installation_hydraulique_repartition_PW_zonePresenter.hpp>

Installation_hydraulique_repartition_PW_zonePresenter::Installation_hydraulique_repartition_PW_zonePresenter(Installation_hydraulique_repartition_PW_zoneView& v)
    : view(v)
{

}

void Installation_hydraulique_repartition_PW_zonePresenter::activate()
{

}

void Installation_hydraulique_repartition_PW_zonePresenter::deactivate()
{

}

void Installation_hydraulique_repartition_PW_zonePresenter::c_install_zx(uint8_t u8NumZone)
{
	model->c_install_zx(u8NumZone);
}

void Installation_hydraulique_repartition_PW_zonePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_repartition_PW_zonePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_repartition_PW_zonePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_repartition_PW_zonePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
