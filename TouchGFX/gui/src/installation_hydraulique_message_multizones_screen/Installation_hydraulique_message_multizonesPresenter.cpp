#include <gui/installation_hydraulique_message_multizones_screen/Installation_hydraulique_message_multizonesView.hpp>
#include <gui/installation_hydraulique_message_multizones_screen/Installation_hydraulique_message_multizonesPresenter.hpp>

Installation_hydraulique_message_multizonesPresenter::Installation_hydraulique_message_multizonesPresenter(Installation_hydraulique_message_multizonesView& v)
    : view(v)
{

}

void Installation_hydraulique_message_multizonesPresenter::activate()
{

}

void Installation_hydraulique_message_multizonesPresenter::deactivate()
{

}

void Installation_hydraulique_message_multizonesPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Installation_hydraulique_message_multizonesPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Installation_hydraulique_message_multizonesPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Installation_hydraulique_message_multizonesPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Installation_hydraulique_message_multizonesPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}
