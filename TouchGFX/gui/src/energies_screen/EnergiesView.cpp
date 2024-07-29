#include <gui/energies_screen/EnergiesView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

EnergiesView::EnergiesView()
{

}

void EnergiesView::setupScreen()
{
	// Titre de la page
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_SUIVI_ENERGIES_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);

    EnergiesViewBase::setupScreen();
}

void EnergiesView::tearDownScreen()
{
    EnergiesViewBase::tearDownScreen();
}
