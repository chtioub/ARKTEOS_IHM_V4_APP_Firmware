#include <gui/installation_circuit_captage_screen/Installation_circuit_captageView.hpp>
#include <gui/installation_circuit_captage_screen/Installation_circuit_captagePresenter.hpp>

Installation_circuit_captagePresenter::Installation_circuit_captagePresenter(Installation_circuit_captageView& v)
    : view(v)
{

}

void Installation_circuit_captagePresenter::activate()
{

}

void Installation_circuit_captagePresenter::deactivate()
{

}

void Installation_circuit_captagePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_circuit_captagePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_circuit_captagePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_circuit_captagePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}



void Installation_circuit_captagePresenter::c_install_config_pac()
{
	model->c_install_config_pac();
}

void Installation_circuit_captagePresenter::c_usine_phoenix(int u8Esclave)
{
	model->c_usine_phoenix(u8Esclave);
}


