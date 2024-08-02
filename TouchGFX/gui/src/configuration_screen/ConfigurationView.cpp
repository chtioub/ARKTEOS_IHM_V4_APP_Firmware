#include <gui/configuration_screen/ConfigurationView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ConfigurationView::ConfigurationView()
{

}

void ConfigurationView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CONFIGURATION_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);

    ConfigurationViewBase::setupScreen();
}

void ConfigurationView::tearDownScreen()
{
    ConfigurationViewBase::tearDownScreen();
}
