#include <gui/renommer_screen/RenommerView.hpp>
#include <gui/renommer_screen/RenommerPresenter.hpp>

RenommerPresenter::RenommerPresenter(RenommerView& v)
    : view(v)
{

}

void RenommerPresenter::activate()
{

}

void RenommerPresenter::deactivate()
{

}

void RenommerPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void RenommerPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void RenommerPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void RenommerPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

//void RenommerPresenter::c_install_zx(uint8_t u8NumZone)
//{
//	model->c_install_zx(u8NumZone);
//}
