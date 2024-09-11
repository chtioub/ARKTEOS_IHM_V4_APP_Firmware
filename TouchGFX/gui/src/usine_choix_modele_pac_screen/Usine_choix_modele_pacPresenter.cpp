#include <gui/usine_choix_modele_pac_screen/Usine_choix_modele_pacView.hpp>
#include <gui/usine_choix_modele_pac_screen/Usine_choix_modele_pacPresenter.hpp>

Usine_choix_modele_pacPresenter::Usine_choix_modele_pacPresenter(Usine_choix_modele_pacView& v)
    : view(v)
{

}

void Usine_choix_modele_pacPresenter::activate()
{

}

void Usine_choix_modele_pacPresenter::deactivate()
{

}

void Usine_choix_modele_pacPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_choix_modele_pacPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_choix_modele_pacPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_choix_modele_pacPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Usine_choix_modele_pacPresenter::c_usine_param()
{
	model->c_usine_param();
}
