#include <gui/maintenance_frequence_historiques_screen/Maintenance_frequence_historiquesView.hpp>
#include <gui/maintenance_frequence_historiques_screen/Maintenance_frequence_historiquesPresenter.hpp>

Maintenance_frequence_historiquesPresenter::Maintenance_frequence_historiquesPresenter(Maintenance_frequence_historiquesView& v)
    : view(v)
{

}

void Maintenance_frequence_historiquesPresenter::activate()
{

}

void Maintenance_frequence_historiquesPresenter::deactivate()
{

}

void Maintenance_frequence_historiquesPresenter::c_sav_param()
{
	model->c_sav_param();
}

void Maintenance_frequence_historiquesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Maintenance_frequence_historiquesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Maintenance_frequence_historiquesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Maintenance_frequence_historiquesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
