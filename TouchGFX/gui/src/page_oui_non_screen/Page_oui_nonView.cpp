#include <gui/page_oui_non_screen/Page_oui_nonView.hpp>

Page_oui_nonView::Page_oui_nonView()
{
//	if(typePage == 2)
	{
		barre_titre.recupConfig(false);
		barre_titre.connexionDistante(false);
	}
}

void Page_oui_nonView::setupScreen()
{
    Page_oui_nonViewBase::setupScreen();
}

void Page_oui_nonView::tearDownScreen()
{
    Page_oui_nonViewBase::tearDownScreen();
}

void Page_oui_nonView::bouton_non_page_oui_non()
{
	if(toggleButton_non_oui_non.getState())
	{
		toggleButton_oui_oui_non.forceState(false);
		toggleButton_oui_oui_non.setTouchable(true);
		toggleButton_oui_oui_non.invalidate();
		toggleButton_non_oui_non.setTouchable(false);
		toggleButton_non_oui_non.invalidate();
	}
}

void Page_oui_nonView::bouton_oui_page_oui_non()
{
	if(toggleButton_oui_oui_non.getState())
	{
		toggleButton_non_oui_non.forceState(false);
		toggleButton_non_oui_non.setTouchable(true);
		toggleButton_non_oui_non.invalidate();
		toggleButton_oui_oui_non.setTouchable(false);
		toggleButton_oui_oui_non.invalidate();
	}
}

void Page_oui_nonView::bouton_valider()
{
	application().gotoAccueilScreenNoTransition();
}
