#include <gui/energies_cumul_screen/Energies_cumulView.hpp>
#include <gui/energies_cumul_screen/Energies_cumulPresenter.hpp>

Energies_cumulPresenter::Energies_cumulPresenter(Energies_cumulView& v)
    : view(v)
{

}

void Energies_cumulPresenter::activate()
{

}

void Energies_cumulPresenter::deactivate()
{

}

void Energies_cumulPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Energies_cumulPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Energies_cumulPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Energies_cumulPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
