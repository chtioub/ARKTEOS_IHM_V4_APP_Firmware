#include <gui/installation_hydraulique_gestion_circulateur_screen/Installation_hydraulique_gestion_circulateurView.hpp>
#include <gui/installation_hydraulique_gestion_circulateur_screen/Installation_hydraulique_gestion_circulateurPresenter.hpp>

Installation_hydraulique_gestion_circulateurPresenter::Installation_hydraulique_gestion_circulateurPresenter(Installation_hydraulique_gestion_circulateurView& v)
    : view(v)
{

}

void Installation_hydraulique_gestion_circulateurPresenter::activate()
{

}

void Installation_hydraulique_gestion_circulateurPresenter::deactivate()
{

}

void Installation_hydraulique_gestion_circulateurPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_gestion_circulateurPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_gestion_circulateurPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_gestion_circulateurPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hydraulique_gestion_circulateurPresenter::c_install_zx(uint8_t u8Zone)
{
	model->c_install_zx(u8Zone);
}
