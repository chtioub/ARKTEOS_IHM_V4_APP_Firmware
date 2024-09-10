#include <gui/programmation_zoom_screen/Programmation_zoomView.hpp>
#include <gui/programmation_zoom_screen/Programmation_zoomPresenter.hpp>

Programmation_zoomPresenter::Programmation_zoomPresenter(Programmation_zoomView& v)
    : view(v)
{

}

void Programmation_zoomPresenter::activate()
{

}

void Programmation_zoomPresenter::deactivate()
{

}

void Programmation_zoomPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Programmation_zoomPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Programmation_zoomPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Programmation_zoomPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
