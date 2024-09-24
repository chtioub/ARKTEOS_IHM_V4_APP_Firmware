#include <gui/accueil_screen/AccueilView.hpp>
#include <gui/accueil_screen/AccueilPresenter.hpp>

AccueilPresenter::AccueilPresenter(AccueilView& v)
    : view(v)
{

}

void AccueilPresenter::activate()
{

}

void AccueilPresenter::deactivate()
{

}

void AccueilPresenter::changeModePac(bool marche)
{
  view.changeModePac(marche);
}

void AccueilPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void AccueilPresenter::changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire)
{
	view.changeStatutPrimaire(sStatut_Primaire);
}

void AccueilPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

void AccueilPresenter::changeStatutECS(S_STATUT_ECS *sStatut_ECS)
{
	view.changeStatutECS(sStatut_ECS);
}

void AccueilPresenter::changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx)
{
	view.changeStatutZx(u8Zone, sStatut_Zx);
}

void AccueilPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void AccueilPresenter::changeStatutRegulExt(S_STATUT_REG_EXT *sStatut_RegulExt)
{
	view.changeStatutRegulExt(sStatut_RegulExt);
}

void AccueilPresenter::changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine)
{
	view.changeStatutPiscine(sStatut_Piscine);
}

void AccueilPresenter::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
    view.changeStatutCyclFrigo(sCyclRegFrigo);
}

void AccueilPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void AccueilPresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void AccueilPresenter::editLuminosite(uint8_t u8Luminosite)
{
	model->editLuminosite(u8Luminosite);
}
