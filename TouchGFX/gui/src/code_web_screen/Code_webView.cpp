#include <gui/code_web_screen/Code_webView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Code_webView::Code_webView()
{

}

void Code_webView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_COMPTE_CLIENT_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Affichage du code web
    Unicode::snprintf(textAreaBuffer_CodeWeb, 5, "%d", 85420 % 10000);
	textArea_code_web.setWildcard(textAreaBuffer_CodeWeb);
	textArea_code_web.invalidate();

    Code_webViewBase::setupScreen();
}

void Code_webView::tearDownScreen()
{
    Code_webViewBase::tearDownScreen();
}
