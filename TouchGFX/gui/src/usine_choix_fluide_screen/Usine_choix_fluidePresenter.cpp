#include <gui/usine_choix_fluide_screen/Usine_choix_fluideView.hpp>
#include <gui/usine_choix_fluide_screen/Usine_choix_fluidePresenter.hpp>

Usine_choix_fluidePresenter::Usine_choix_fluidePresenter(Usine_choix_fluideView& v)
    : view(v)
{

}

void Usine_choix_fluidePresenter::activate()
{

}

void Usine_choix_fluidePresenter::deactivate()
{

}

void Usine_choix_fluidePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_choix_fluidePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_choix_fluidePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_choix_fluidePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Usine_choix_fluidePresenter::c_usine_param()
{
	model->c_usine_param();
}
