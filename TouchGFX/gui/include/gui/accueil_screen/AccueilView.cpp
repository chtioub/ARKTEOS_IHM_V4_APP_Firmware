#include <gui/accueil_screen/AccueilView.hpp>

AccueilView::AccueilView() :
        swipeCallback(this, &AccueilView::swipeCallbackHandler)
{
	barre_titre.sansAccueil();
	barre_titre.sansRetour();
    swipeDetectContainerConfigurationScreen.setAction(swipeCallback);
}

void AccueilView::setupScreen()
{
    AccueilViewBase::setupScreen();
}

void AccueilView::tearDownScreen()
{
    AccueilViewBase::tearDownScreen();
}

void AccueilView::swipeCallbackHandler(int16_t velocity)
{
    if(velocity < 0)
    {
		application().gotoConfigurationScreenSlideTransitionEast();
    }
}

void AccueilView::Timer_500ms()
{
	if(textArea_alerte.isVisible()) // && bSecours)
	{
		textArea_alerte.setVisible(false);
		textArea_alerte.invalidate();
		Image_arkteos.setVisible(false);
		Image_arkteos.invalidate();
	}
	else
	{
		textArea_alerte.setVisible(true);
		textArea_alerte.invalidate();
		Image_arkteos.setVisible(true);
		Image_arkteos.invalidate();
	}

	// Si multizones
	if(button_violet_zone_1.isVisible())
	{
		button_violet_zone_1.setVisible(false);
		button_violet_zone_1.invalidate();
	}
	else
	{
		button_violet_zone_1.setVisible(true);
		button_violet_zone_1.invalidate();
	}
}

void AccueilView::bouton_marche_arret()
{
	application().gotoPage_oui_nonScreenNoTransition();
}
