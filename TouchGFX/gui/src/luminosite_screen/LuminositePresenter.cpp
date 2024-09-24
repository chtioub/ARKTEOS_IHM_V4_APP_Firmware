#include <gui/luminosite_screen/LuminositeView.hpp>
#include <gui/luminosite_screen/LuminositePresenter.hpp>

LuminositePresenter::LuminositePresenter(LuminositeView& v)
    : view(v)
{

}

void LuminositePresenter::activate()
{

}

void LuminositePresenter::deactivate()
{

}

void LuminositePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void LuminositePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void LuminositePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void LuminositePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void LuminositePresenter::c_user_param()
{
	model->c_user_param();
}

void LuminositePresenter::editLuminosite(uint8_t u8Luminosite)
{
	model->editLuminosite(u8Luminosite);
}
