#include <gui/usine_calibrage_offset_screen/Usine_calibrage_offsetView.hpp>
#include <gui/usine_calibrage_offset_screen/Usine_calibrage_offsetPresenter.hpp>

Usine_calibrage_offsetPresenter::Usine_calibrage_offsetPresenter(Usine_calibrage_offsetView& v)
    : view(v)
{

}

void Usine_calibrage_offsetPresenter::activate()
{

}

void Usine_calibrage_offsetPresenter::deactivate()
{

}

void Usine_calibrage_offsetPresenter::c_usine_offset()
{
	model->c_usine_offset();
}

void Usine_calibrage_offsetPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Usine_calibrage_offsetPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Usine_calibrage_offsetPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Usine_calibrage_offsetPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Usine_calibrage_offsetPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
