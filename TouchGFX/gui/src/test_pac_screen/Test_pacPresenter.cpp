#include <gui/test_pac_screen/Test_pacView.hpp>
#include <gui/test_pac_screen/Test_pacPresenter.hpp>

Test_pacPresenter::Test_pacPresenter(Test_pacView& v)
    : view(v)
{

}

void Test_pacPresenter::activate()
{

}

void Test_pacPresenter::deactivate()
{

}

void Test_pacPresenter::c_sav_test_pac()
{
	model->c_sav_test_pac();
}

void Test_pacPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Test_pacPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Test_pacPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Test_pacPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Test_pacPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
