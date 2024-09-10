#include <gui/installation_circuit_primaire_screen/Installation_circuit_primaireView.hpp>
#include <gui/installation_circuit_primaire_screen/Installation_circuit_primairePresenter.hpp>

Installation_circuit_primairePresenter::Installation_circuit_primairePresenter(Installation_circuit_primaireView& v)
    : view(v)
{

}

void Installation_circuit_primairePresenter::activate()
{

}

void Installation_circuit_primairePresenter::deactivate()
{

}

void Installation_circuit_primairePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_circuit_primairePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_circuit_primairePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_circuit_primairePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_circuit_primairePresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_circuit_primairePresenter::c_usine_phoenix(int u8Esclave)
{
	model->c_usine_phoenix(u8Esclave);
}
