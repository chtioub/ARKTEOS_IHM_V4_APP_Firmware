#include <gui/piscine_screen/PiscineView.hpp>
#include <gui/piscine_screen/PiscinePresenter.hpp>

PiscinePresenter::PiscinePresenter(PiscineView& v)
    : view(v)
{

}

void PiscinePresenter::activate()
{

}

void PiscinePresenter::deactivate()
{

}

void PiscinePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void PiscinePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void PiscinePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void PiscinePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void PiscinePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void PiscinePresenter::c_user_piscine()
{
	model->c_user_piscine();
}

void PiscinePresenter::c_prog_piscine(bool bEnvoi)
{
	model->c_prog_piscine(bEnvoi);
}
