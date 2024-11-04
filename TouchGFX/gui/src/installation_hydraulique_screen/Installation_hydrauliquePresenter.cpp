#include <gui/installation_hydraulique_screen/Installation_hydrauliqueView.hpp>
#include <gui/installation_hydraulique_screen/Installation_hydrauliquePresenter.hpp>

Installation_hydrauliquePresenter::Installation_hydrauliquePresenter(Installation_hydrauliqueView& v)
    : view(v)
{

}

void Installation_hydrauliquePresenter::activate()
{

}

void Installation_hydrauliquePresenter::deactivate()
{

}

void Installation_hydrauliquePresenter::c_install_param()
{
	model->c_install_param();
}

void Installation_hydrauliquePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydrauliquePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydrauliquePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydrauliquePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hydrauliquePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
