#include <gui/configuration_screen/ConfigurationView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ConfigurationView::ConfigurationView()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CONFIGURATION_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Bouton accueil et retour masqués
	barre_titre.sansAccueil();
	barre_titre.sansRetour();
}

void ConfigurationView::setupScreen()
{
    ConfigurationViewBase::setupScreen();
}

void ConfigurationView::tearDownScreen()
{
    ConfigurationViewBase::tearDownScreen();
}
