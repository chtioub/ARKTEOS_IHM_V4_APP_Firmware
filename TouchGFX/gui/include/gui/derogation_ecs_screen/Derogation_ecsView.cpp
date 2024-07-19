#include <gui/derogation_ecs_screen/Derogation_ecsView.hpp>

Derogation_ecsView::Derogation_ecsView()
{
//	barre_titre.fonctionRetour(&application().gotoEau_chaude_sanitaireScreenNoTransition);
}

void Derogation_ecsView::setupScreen()
{
    Derogation_ecsViewBase::setupScreen();
}

void Derogation_ecsView::tearDownScreen()
{
    Derogation_ecsViewBase::tearDownScreen();
}


void Derogation_ecsView::bouton_non_derog_ecs()
{
	if(toggleButton_non_oui_non_derog_ecs.getState())
	{
		toggleButton_oui_oui_non_derog_ecs.forceState(false);
		toggleButton_oui_oui_non_derog_ecs.setTouchable(true);
		toggleButton_oui_oui_non_derog_ecs.invalidate();
		toggleButton_non_oui_non_derog_ecs.setTouchable(false);
		toggleButton_non_oui_non_derog_ecs.invalidate();
	}
}

void Derogation_ecsView::bouton_oui_derog_ecs()
{
	if(toggleButton_oui_oui_non_derog_ecs.getState())
	{
		toggleButton_non_oui_non_derog_ecs.forceState(false);
		toggleButton_non_oui_non_derog_ecs.setTouchable(true);
		toggleButton_non_oui_non_derog_ecs.invalidate();
		toggleButton_oui_oui_non_derog_ecs.setTouchable(false);
		toggleButton_oui_oui_non_derog_ecs.invalidate();
	}
}

void Derogation_ecsView::bouton_valider()
{
	application().gotoEau_chaude_sanitaireScreenNoTransition();
}
