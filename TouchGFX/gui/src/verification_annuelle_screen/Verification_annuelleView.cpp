#include <gui/verification_annuelle_screen/Verification_annuelleView.hpp>

Verification_annuelleView::Verification_annuelleView()
{
    // Affichage des messages
    Unicode::snprintf(textAreaBuffer_MessTitre, 40, touchgfx::TypedText(T_TEXT_TITRE_VERIFICATION_ANNUELLE).getText());
    message_GF.titre(textAreaBuffer_MessTitre);

    Unicode::snprintf(textAreaBuffer_MessMess, 800, touchgfx::TypedText(T_TEXT_VERIFICATION_ANODE).getText());
    message_GF.message(textAreaBuffer_MessMess);
    message_GF.invalidate();
}

void Verification_annuelleView::setupScreen()
{
    Verification_annuelleViewBase::setupScreen();
}

void Verification_annuelleView::tearDownScreen()
{
    Verification_annuelleViewBase::tearDownScreen();
}

void Verification_annuelleView::bouton_valider_message()
{
	sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle++;
	presenter->c_install_install_pac();
	bMessageEnCoursAffichage = false;
	oui_veille = 1; //Pour autoriser l'IHM à passer en veille
}
