#include <gui/luminosite_screen/LuminositeView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LuminositeView::LuminositeView()
{

}

void LuminositeView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_LUMINOSITE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Init des variables d'offset
    u8Luminosite = 30;
	slider_luminosite.setValue(u8Luminosite);
    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
	textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
	textArea_luminosite.invalidate();

    LuminositeViewBase::setupScreen();
}

void LuminositeView::tearDownScreen()
{
    LuminositeViewBase::tearDownScreen();
}

void LuminositeView::slider_lumi(int sliderValue)
{
	if(sliderValue < 10)
	{
		u8Luminosite = 10;
		slider_luminosite.setValue(u8Luminosite);
	}
	else u8Luminosite = sliderValue;
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
	textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
	textArea_luminosite.invalidate();
}

void LuminositeView::bouton_moins()
{
	if(u8Luminosite > 0)
	{
		u8Luminosite--;
		slider_luminosite.setValue(u8Luminosite);
		// Affichage de la valeur
	    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
		textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
		textArea_luminosite.invalidate();
	}
}

void LuminositeView::bouton_plus()
{
	if(u8Luminosite < 100)
	{
		u8Luminosite++;
		slider_luminosite.setValue(u8Luminosite);
		// Affichage de la valeur
	    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
		textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
		textArea_luminosite.invalidate();
	}
}

void LuminositeView::bouton_valider()
{
	application().gotoParametresScreenNoTransition();
}
