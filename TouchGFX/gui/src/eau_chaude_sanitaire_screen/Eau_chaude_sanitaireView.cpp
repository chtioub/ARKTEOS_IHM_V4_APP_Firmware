#include <gui/eau_chaude_sanitaire_screen/Eau_chaude_sanitaireView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Eau_chaude_sanitaireView::Eau_chaude_sanitaireView()
{
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CONFIG_INSTALL_HYDRAU_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);
}

void Eau_chaude_sanitaireView::setupScreen()
{
    Eau_chaude_sanitaireViewBase::setupScreen();
}

void Eau_chaude_sanitaireView::tearDownScreen()
{
    Eau_chaude_sanitaireViewBase::tearDownScreen();
}

void Eau_chaude_sanitaireView::slider_consigne(int sliderValue)
{
	if(((float)sliderValue / 10) < (fRelance + 5.0))
	{
		fConsigne = fRelance + 5.0;
		slider_rose.setValue((int) fConsigne * 10);
		sliderValue = (int) (fConsigne * 10);
	}
	else fConsigne = sliderValue / 10;
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", fConsigne);
    textArea_rose.setWildcard(textAreaBuffer_consigne);
    textArea_rose.moveTo((int)((float) slider_rose.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_rose.getWidth()/2  + ((float)sliderValue - (float)400) * (float)1.98),51);
    textArea_rose.invalidate();
}

void Eau_chaude_sanitaireView::slider_relance(int sliderValue)
{
	if(((float)sliderValue / 10) > (fConsigne - 5.0))
	{
		fRelance = fConsigne - 5.0;
		slider_gris.setValue((int) fRelance * 10);
		sliderValue = (int)(fRelance * 10);
	}
	else fRelance = sliderValue / 10;
    Unicode::snprintfFloat(textAreaBuffer_relance, 5, "%.1f", fRelance);
    textArea_gris.setWildcard(textAreaBuffer_relance);
    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)sliderValue - (float)400) * (float)1.98),51);
    textArea_gris.invalidate();
}

void Eau_chaude_sanitaireView::bouton_plus_relance()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(fRelance == (fConsigne - 5.0)) return;

	fRelance += 1.0;
	if(fRelance > (fConsigne - 5.0))
	{
		fRelance = fConsigne - 5.0;
	}
	slider_gris.setValue((int) fRelance * 10);
    Unicode::snprintfFloat(textAreaBuffer_relance, 5, "%.1f", fRelance);
    textArea_gris.setWildcard(textAreaBuffer_relance);
    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)(fRelance * 10) - (float)400) * (float)1.98),51);
    textArea_gris.invalidate();
}

void Eau_chaude_sanitaireView::bouton_moins_relance()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(fRelance == 40.0) return;

	fRelance -= 1.0;
	if(fRelance < 40.0)
	{
		fRelance = 40.0;
	}
	slider_gris.setValue((int) fRelance * 10);
    Unicode::snprintfFloat(textAreaBuffer_relance, 5, "%.1f", fRelance);
    textArea_gris.setWildcard(textAreaBuffer_relance);
    textArea_gris.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)(fRelance * 10) - (float)400) * (float)1.98),51);
    textArea_gris.invalidate();
}

void Eau_chaude_sanitaireView::bouton_plus_consigne()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(fConsigne == 65.0) return;

	fConsigne += 1.0;
	if(fConsigne > 65.0)
	{
		fConsigne = 65.0;
	}
	slider_rose.setValue((int) fConsigne * 10);
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", fConsigne);
    textArea_rose.setWildcard(textAreaBuffer_consigne);
    textArea_rose.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)(fConsigne * 10) - (float)400) * (float)1.98),51);
    textArea_rose.invalidate();
}

void Eau_chaude_sanitaireView::bouton_moins_consigne()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(fConsigne == (fRelance + 5.0)) return;

	fConsigne -= 1.0;
	if(fConsigne < (fRelance + 5.0))
	{
		fConsigne = fRelance + 5.0;
	}
	slider_rose.setValue((int) fConsigne * 10);
    Unicode::snprintfFloat(textAreaBuffer_consigne, 5, "%.1f", fConsigne);
    textArea_rose.setWildcard(textAreaBuffer_consigne);
    textArea_rose.moveTo((int)((float) slider_gris.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_gris.getWidth()/2 + ((float)(fConsigne * 10) - (float)400) * (float)1.98),51);
    textArea_rose.invalidate();
}
