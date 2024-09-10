#include <gui/derogation_screen/DerogationView.hpp>
#include <gui/derogation_screen/DerogationPresenter.hpp>

DerogationPresenter::DerogationPresenter(DerogationView& v)
    : view(v)
{

}

void DerogationPresenter::activate()
{

}

void DerogationPresenter::deactivate()
{

}

void DerogationPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void DerogationPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void DerogationPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void DerogationPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void DerogationPresenter::c_user_zx(uint8_t u8Zone)
{
	model->c_user_zx(u8Zone);
}

void DerogationPresenter::c_user_reg_ext()
{
	model->c_user_reg_ext();
}
