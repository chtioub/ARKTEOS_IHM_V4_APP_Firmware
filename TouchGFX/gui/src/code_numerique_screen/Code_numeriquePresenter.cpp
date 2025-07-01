#include <gui/code_numerique_screen/Code_numeriqueView.hpp>
#include <gui/code_numerique_screen/Code_numeriquePresenter.hpp>

Code_numeriquePresenter::Code_numeriquePresenter(Code_numeriqueView& v)
    : view(v)
{

}

void Code_numeriquePresenter::activate()
{

}

void Code_numeriquePresenter::deactivate()
{

}

void Code_numeriquePresenter::c_sav_mode_commande()
{
	model->c_sav_mode_commande();
}

void Code_numeriquePresenter::c_install_date_install()
{
	model->c_install_date_install();
}

void Code_numeriquePresenter::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	view.changeStatutCyclFrigo(sCyclRegFrigo);
}

void Code_numeriquePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Code_numeriquePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Code_numeriquePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Code_numeriquePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Code_numeriquePresenter::c_usine_password()
{
	model->c_usine_password();
}
