#include <gui/configuration_screen/ConfigurationView.hpp>
#include <gui/configuration_screen/ConfigurationPresenter.hpp>

ConfigurationPresenter::ConfigurationPresenter(ConfigurationView& v)
: view(v)
{

}

void ConfigurationPresenter::activate()
{

}

void ConfigurationPresenter::deactivate()
{

}


void ConfigurationPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}


void ConfigurationPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void ConfigurationPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}


void ConfigurationPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void ConfigurationPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void ConfigurationPresenter::editLuminosite(uint8_t u8Luminosite)
{
	model->editLuminosite(u8Luminosite);
}
