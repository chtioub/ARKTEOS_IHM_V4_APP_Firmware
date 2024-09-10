#include <gui/secours_screen/SecoursView.hpp>
#include <gui/secours_screen/SecoursPresenter.hpp>

SecoursPresenter::SecoursPresenter(SecoursView& v)
    : view(v)
{

}

void SecoursPresenter::activate()
{

}

void SecoursPresenter::deactivate()
{

}

void SecoursPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void SecoursPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void SecoursPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void SecoursPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void SecoursPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
