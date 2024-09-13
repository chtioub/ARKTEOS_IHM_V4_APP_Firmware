#include <gui/installation_hydraulique_param_comp_screen/Installation_hydraulique_param_compView.hpp>
#include <gui/installation_hydraulique_param_comp_screen/Installation_hydraulique_param_compPresenter.hpp>

Installation_hydraulique_param_compPresenter::Installation_hydraulique_param_compPresenter(Installation_hydraulique_param_compView& v)
    : view(v)
{

}

void Installation_hydraulique_param_compPresenter::activate()
{

}

void Installation_hydraulique_param_compPresenter::deactivate()
{

}

void Installation_hydraulique_param_compPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_param_compPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_param_compPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_param_compPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
