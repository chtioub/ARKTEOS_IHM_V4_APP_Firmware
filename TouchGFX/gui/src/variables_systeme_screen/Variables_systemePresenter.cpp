#include <gui/variables_systeme_screen/Variables_systemeView.hpp>
#include <gui/variables_systeme_screen/Variables_systemePresenter.hpp>

Variables_systemePresenter::Variables_systemePresenter(Variables_systemeView& v)
    : view(v)
{

}

void Variables_systemePresenter::activate()
{

}

void Variables_systemePresenter::deactivate()
{

}

void Variables_systemePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void Variables_systemePresenter::changeStatutRegulEsclave(S_STATUT_REGUL_ESCLAVE *sStatut_RegulEsclave)
{
	view.changeStatutRegulEsclave(sStatut_RegulEsclave);
}

void Variables_systemePresenter::changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo)
{
	view.changeDemandeFrigo(sDemandeFrigo);
}

void Variables_systemePresenter::changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire)
{
	view.changeStatutPrimaire(sStatut_Primaire);
}

void Variables_systemePresenter::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	view.changeStatutCyclFrigo(sCyclRegFrigo);
}

void Variables_systemePresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Variables_systemePresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void Variables_systemePresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Variables_systemePresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
