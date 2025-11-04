#include <gui/histo_fonctionnement_screen/Histo_fonctionnementView.hpp>
#include <gui/histo_fonctionnement_screen/Histo_fonctionnementPresenter.hpp>

Histo_fonctionnementPresenter::Histo_fonctionnementPresenter(Histo_fonctionnementView& v)
    : view(v)
{

}

void Histo_fonctionnementPresenter::activate()
{

}

void Histo_fonctionnementPresenter::deactivate()
{

}

void Histo_fonctionnementPresenter::update_graph_histo(DATA_HISTO *data_histo)
{
	view.update_graph_histo(data_histo);
}


void Histo_fonctionnementPresenter::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	view.changeStatutEther(sCycEther);
}

void Histo_fonctionnementPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Histo_fonctionnementPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}

void Histo_fonctionnementPresenter::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	view.changeStatutPAC(sStatut_PAC);
}

