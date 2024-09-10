#include <gui/code_web_screen/Code_webView.hpp>
#include <gui/code_web_screen/Code_webPresenter.hpp>

Code_webPresenter::Code_webPresenter(Code_webView& v)
    : view(v)
{

}

void Code_webPresenter::activate()
{

}

void Code_webPresenter::deactivate()
{

}

void Code_webPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Code_webPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Code_webPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Code_webPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
