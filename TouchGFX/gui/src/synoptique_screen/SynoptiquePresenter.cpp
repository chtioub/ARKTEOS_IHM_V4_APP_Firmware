#include <gui/synoptique_screen/SynoptiqueView.hpp>
#include <gui/synoptique_screen/SynoptiquePresenter.hpp>

SynoptiquePresenter::SynoptiquePresenter(SynoptiqueView& v)
    : view(v)
{

}

void SynoptiquePresenter::activate()
{

}

void SynoptiquePresenter::deactivate()
{

}

void SynoptiquePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void SynoptiquePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void SynoptiquePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void SynoptiquePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void SynoptiquePresenter::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	view.changeStatutCyclFrigo(sCyclRegFrigo);
}
