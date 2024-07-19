#include <gui/programmation_screen/ProgrammationView.hpp>

ProgrammationView::ProgrammationView()
{
	buttonWithLabel_coller.setVisible(false);
	toggleButton_barre_heure_1.forceState(true);
	toggleButton_barre_heure_1.setTouchable(false);
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_7.forceState(false);
}

void ProgrammationView::setupScreen()
{
    ProgrammationViewBase::setupScreen();
}

void ProgrammationView::tearDownScreen()
{
    ProgrammationViewBase::tearDownScreen();
}

void ProgrammationView::bouton_copier()
{
	buttonWithLabel_coller.setVisible(true);
	buttonWithLabel_coller.invalidate();
	if(toggleButton_barre_heure_1.getState())
	{
		barre_mardi();
	}
	else if(toggleButton_barre_heure_2.getState())
	{
		barre_mercredi();
	}
	else if(toggleButton_barre_heure_3.getState())
	{
		barre_jeudi();
	}
	else if(toggleButton_barre_heure_4.getState())
	{
		barre_vendredi();
	}
	else if(toggleButton_barre_heure_5.getState())
	{
		barre_samedi();
	}
	else if(toggleButton_barre_heure_6.getState())
	{
		barre_dimanche();
	}
	else if(toggleButton_barre_heure_7.getState())
	{
		barre_lundi();
	}
}

void ProgrammationView::bouton_coller()
{

}

void ProgrammationView::barre_lundi()
{
	toggleButton_barre_heure_1.forceState(true);
	toggleButton_barre_heure_1.setTouchable(false);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_2.setTouchable(true);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_3.setTouchable(true);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_4.setTouchable(true);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_5.setTouchable(true);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_6.setTouchable(true);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(false);
	toggleButton_barre_heure_7.setTouchable(true);
	toggleButton_barre_heure_7.invalidate();
}

void ProgrammationView::barre_mardi()
{
	toggleButton_barre_heure_1.forceState(false);
	toggleButton_barre_heure_1.setTouchable(true);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(true);
	toggleButton_barre_heure_2.setTouchable(false);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_3.setTouchable(true);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_4.setTouchable(true);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_5.setTouchable(true);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_6.setTouchable(true);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(false);
	toggleButton_barre_heure_7.setTouchable(true);
	toggleButton_barre_heure_7.invalidate();
}

void ProgrammationView::barre_mercredi()
{
	toggleButton_barre_heure_1.forceState(false);
	toggleButton_barre_heure_1.setTouchable(true);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_2.setTouchable(true);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(true);
	toggleButton_barre_heure_3.setTouchable(false);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_4.setTouchable(true);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_5.setTouchable(true);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_6.setTouchable(true);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(false);
	toggleButton_barre_heure_7.setTouchable(true);
	toggleButton_barre_heure_7.invalidate();
}

void ProgrammationView::barre_jeudi()
{
	toggleButton_barre_heure_1.forceState(false);
	toggleButton_barre_heure_1.setTouchable(true);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_2.setTouchable(true);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_3.setTouchable(true);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(true);
	toggleButton_barre_heure_4.setTouchable(false);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_5.setTouchable(true);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_6.setTouchable(true);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(false);
	toggleButton_barre_heure_7.setTouchable(true);
	toggleButton_barre_heure_7.invalidate();
}

void ProgrammationView::barre_vendredi()
{
	toggleButton_barre_heure_1.forceState(false);
	toggleButton_barre_heure_1.setTouchable(true);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_2.setTouchable(true);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_3.setTouchable(true);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_4.setTouchable(true);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(true);
	toggleButton_barre_heure_5.setTouchable(false);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_6.setTouchable(true);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(false);
	toggleButton_barre_heure_7.setTouchable(true);
	toggleButton_barre_heure_7.invalidate();
}

void ProgrammationView::barre_samedi()
{
	toggleButton_barre_heure_1.forceState(false);
	toggleButton_barre_heure_1.setTouchable(true);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_2.setTouchable(true);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_3.setTouchable(true);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_4.setTouchable(true);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_5.setTouchable(true);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(true);
	toggleButton_barre_heure_6.setTouchable(false);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(false);
	toggleButton_barre_heure_7.setTouchable(true);
	toggleButton_barre_heure_7.invalidate();
}

void ProgrammationView::barre_dimanche()
{
	toggleButton_barre_heure_1.forceState(false);
	toggleButton_barre_heure_1.setTouchable(true);
	toggleButton_barre_heure_1.invalidate();
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_2.setTouchable(true);
	toggleButton_barre_heure_2.invalidate();
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_3.setTouchable(true);
	toggleButton_barre_heure_3.invalidate();
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_4.setTouchable(true);
	toggleButton_barre_heure_4.invalidate();
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_5.setTouchable(true);
	toggleButton_barre_heure_5.invalidate();
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_6.setTouchable(true);
	toggleButton_barre_heure_6.invalidate();
	toggleButton_barre_heure_7.forceState(true);
	toggleButton_barre_heure_7.setTouchable(false);
	toggleButton_barre_heure_7.invalidate();
}
