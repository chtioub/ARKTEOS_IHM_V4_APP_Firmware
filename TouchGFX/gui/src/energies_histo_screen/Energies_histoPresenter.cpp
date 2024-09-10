#include <gui/energies_histo_screen/Energies_histoView.hpp>
#include <gui/energies_histo_screen/Energies_histoPresenter.hpp>

Energies_histoPresenter::Energies_histoPresenter(Energies_histoView& v)
    : view(v)
{

}

void Energies_histoPresenter::activate()
{

}

void Energies_histoPresenter::deactivate()
{

}

void Energies_histoPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Energies_histoPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Energies_histoPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Energies_histoPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
