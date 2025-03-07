#include <gui/installation_mz_gestion_registre_screen/Installation_MZ_gestion_registreView.hpp>
#include <gui/installation_mz_gestion_registre_screen/Installation_MZ_gestion_registrePresenter.hpp>

Installation_MZ_gestion_registrePresenter::Installation_MZ_gestion_registrePresenter(Installation_MZ_gestion_registreView& v)
    : view(v)
{

}

void Installation_MZ_gestion_registrePresenter::activate()
{

}

void Installation_MZ_gestion_registrePresenter::deactivate()
{

}

void Installation_MZ_gestion_registrePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Installation_MZ_gestion_registrePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_MZ_gestion_registrePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_MZ_gestion_registrePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_MZ_gestion_registrePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}




