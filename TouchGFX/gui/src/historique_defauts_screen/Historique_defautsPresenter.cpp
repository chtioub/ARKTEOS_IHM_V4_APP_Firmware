#include <gui/historique_defauts_screen/Historique_defautsView.hpp>
#include <gui/historique_defauts_screen/Historique_defautsPresenter.hpp>

Historique_defautsPresenter::Historique_defautsPresenter(Historique_defautsView& v)
    : view(v)
{

}

void Historique_defautsPresenter::activate()
{

}

void Historique_defautsPresenter::deactivate()
{

}

void Historique_defautsPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Historique_defautsPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Historique_defautsPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Historique_defautsPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
