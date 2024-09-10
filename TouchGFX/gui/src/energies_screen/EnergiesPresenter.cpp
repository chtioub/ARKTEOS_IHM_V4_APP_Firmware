#include <gui/energies_screen/EnergiesView.hpp>
#include <gui/energies_screen/EnergiesPresenter.hpp>

EnergiesPresenter::EnergiesPresenter(EnergiesView& v)
    : view(v)
{

}

void EnergiesPresenter::activate()
{

}

void EnergiesPresenter::deactivate()
{

}

void EnergiesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void EnergiesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void EnergiesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void EnergiesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void EnergiesPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void EnergiesPresenter::c_ener_cumul_prod()
{
	model->c_ener_cumul_prod();
}

void EnergiesPresenter::c_ener_cumul_conso()
{
	model->c_ener_cumul_conso();
}

void EnergiesPresenter::c_ener_histo_12m_conso()
{
	model->c_ener_histo_12m_conso();
}

void EnergiesPresenter::c_ener_histo_24j_conso()
{
	model->c_ener_histo_24j_conso();
}

void EnergiesPresenter::c_ener_histo_24h_conso()
{
	model->c_ener_histo_24h_conso();
}

void EnergiesPresenter::c_ener_histo_12m_prod()
{
	model->c_ener_histo_12m_prod();
}

void EnergiesPresenter::c_ener_histo_24j_prod()
{
	model->c_ener_histo_24j_prod();
}

void EnergiesPresenter::c_ener_histo_24h_prod()
{
	model->c_ener_histo_24h_prod();
}

