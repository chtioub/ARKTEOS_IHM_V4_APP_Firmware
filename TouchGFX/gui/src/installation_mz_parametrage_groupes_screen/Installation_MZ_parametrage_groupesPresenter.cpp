#include <gui/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesView.hpp>
#include <gui/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesPresenter.hpp>

Installation_MZ_parametrage_groupesPresenter::Installation_MZ_parametrage_groupesPresenter(Installation_MZ_parametrage_groupesView& v)
    : view(v)
{

}

void Installation_MZ_parametrage_groupesPresenter::activate()
{

}

void Installation_MZ_parametrage_groupesPresenter::deactivate()
{

}


void Installation_MZ_parametrage_groupesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_MZ_parametrage_groupesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_MZ_parametrage_groupesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_MZ_parametrage_groupesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_MZ_parametrage_groupesPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
