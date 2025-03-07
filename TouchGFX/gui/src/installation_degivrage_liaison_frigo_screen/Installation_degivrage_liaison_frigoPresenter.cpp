#include <gui/installation_degivrage_liaison_frigo_screen/Installation_degivrage_liaison_frigoView.hpp>
#include <gui/installation_degivrage_liaison_frigo_screen/Installation_degivrage_liaison_frigoPresenter.hpp>

Installation_degivrage_liaison_frigoPresenter::Installation_degivrage_liaison_frigoPresenter(Installation_degivrage_liaison_frigoView& v)
    : view(v)
{

}

void Installation_degivrage_liaison_frigoPresenter::activate()
{

}

void Installation_degivrage_liaison_frigoPresenter::deactivate()
{

}

void Installation_degivrage_liaison_frigoPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_degivrage_liaison_frigoPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_degivrage_liaison_frigoPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_degivrage_liaison_frigoPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_degivrage_liaison_frigoPresenter::c_install_param()
{
	model->c_install_param();
}
