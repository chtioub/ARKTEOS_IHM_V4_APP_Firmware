#include <gui/infos_systeme_screen/Infos_systemeView.hpp>
#include <gui/infos_systeme_screen/Infos_systemePresenter.hpp>

Infos_systemePresenter::Infos_systemePresenter(Infos_systemeView& v)
    : view(v)
{

}

void Infos_systemePresenter::activate()
{

}

void Infos_systemePresenter::deactivate()
{

}

void Infos_systemePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Infos_systemePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Infos_systemePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Infos_systemePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Infos_systemePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
