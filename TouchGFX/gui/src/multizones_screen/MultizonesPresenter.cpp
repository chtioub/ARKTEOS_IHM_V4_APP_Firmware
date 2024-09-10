#include <gui/multizones_screen/MultizonesView.hpp>
#include <gui/multizones_screen/MultizonesPresenter.hpp>

MultizonesPresenter::MultizonesPresenter(MultizonesView& v)
    : view(v)
{

}

void MultizonesPresenter::activate()
{

}

void MultizonesPresenter::deactivate()
{

}

void MultizonesPresenter::changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx)
{
	view.changeStatutZx(u8Zone, sStatut_Zx);
}

void MultizonesPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void MultizonesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void MultizonesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void MultizonesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void MultizonesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
