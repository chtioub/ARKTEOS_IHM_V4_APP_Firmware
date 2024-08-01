#include <gui/parametres_screen/ParametresView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ParametresView::ParametresView()
{

}

void ParametresView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CONFIGURATION_PARAMETRES_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);

    ParametresViewBase::setupScreen();
}

void ParametresView::tearDownScreen()
{
    ParametresViewBase::tearDownScreen();
}
