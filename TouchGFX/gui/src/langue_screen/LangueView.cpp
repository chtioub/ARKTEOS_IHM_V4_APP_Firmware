#include <gui/langue_screen/LangueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LangueView::LangueView()
{

}

void LangueView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_LANGUE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Récupération de la langue
    u8Langue = Texts::getLanguage();
	// Changement langue
	changementLangue();

    LangueViewBase::setupScreen();
}

void LangueView::tearDownScreen()
{
    LangueViewBase::tearDownScreen();
}

void LangueView::bouton_droit()
{
	if(++u8Langue == NUMBER_OF_LANGUAGES)
	{
		u8Langue = 0;
	}
	// Changement langue
	changementLangue();
}

void LangueView::bouton_gauche()
{
	if(u8Langue == 0)
	{
		u8Langue = NUMBER_OF_LANGUAGES - 1;
	}
	else u8Langue--;
	// Changement langue
	changementLangue();
}

void LangueView::bouton_valider()
{
	Texts::setLanguage(u8Langue);
	application().gotoParametresScreenNoTransition();
}

void LangueView::changementLangue()
{
	switch(u8Langue)
	{
		default:
			textArea_valeur_choix_langue.setTypedText(touchgfx::TypedText(T_TEXT_CHOIX_LANGUE_FRANCAIS_VALEUR_CENTRE_DEFAUT));
			textArea_valeur_choix_langue.invalidate();
			Image_allemand.setVisible(false);
			Image_allemand.invalidate();
			Image_anglais.setVisible(false);
			Image_anglais.invalidate();
			Image_francais.setVisible(true);
			Image_francais.invalidate();
			Image_neerlandais.setVisible(false);
			Image_neerlandais.invalidate();
			Image_portugais.setVisible(false);
			Image_portugais.invalidate();
			break;
		case GB:
			textArea_valeur_choix_langue.setTypedText(touchgfx::TypedText(T_TEXT_CHOIX_LANGUE_ANGLAIS_VALEUR_CENTRE_DEFAUT));
			textArea_valeur_choix_langue.invalidate();
			Image_allemand.setVisible(false);
			Image_allemand.invalidate();
			Image_anglais.setVisible(true);
			Image_anglais.invalidate();
			Image_francais.setVisible(false);
			Image_francais.invalidate();
			Image_neerlandais.setVisible(false);
			Image_neerlandais.invalidate();
			Image_portugais.setVisible(false);
			Image_portugais.invalidate();
			break;
		case PT:
			textArea_valeur_choix_langue.setTypedText(touchgfx::TypedText(T_TEXT_CHOIX_LANGUE_PORTUGAIS_VALEUR_CENTRE_DEFAUT));
			textArea_valeur_choix_langue.invalidate();
			Image_allemand.setVisible(false);
			Image_allemand.invalidate();
			Image_anglais.setVisible(false);
			Image_anglais.invalidate();
			Image_francais.setVisible(false);
			Image_francais.invalidate();
			Image_neerlandais.setVisible(false);
			Image_neerlandais.invalidate();
			Image_portugais.setVisible(true);
			Image_portugais.invalidate();
			break;
		case NL:
			textArea_valeur_choix_langue.setTypedText(touchgfx::TypedText(T_TEXT_CHOIX_LANGUE_NEERLANDAIS_VALEUR_CENTRE_DEFAUT));
			textArea_valeur_choix_langue.invalidate();
			Image_allemand.setVisible(false);
			Image_allemand.invalidate();
			Image_anglais.setVisible(false);
			Image_anglais.invalidate();
			Image_francais.setVisible(false);
			Image_francais.invalidate();
			Image_neerlandais.setVisible(true);
			Image_neerlandais.invalidate();
			Image_portugais.setVisible(false);
			Image_portugais.invalidate();
			break;
		case DE:
			textArea_valeur_choix_langue.setTypedText(touchgfx::TypedText(T_TEXT_CHOIX_LANGUE_ALLEMAND_VALEUR_CENTRE_DEFAUT));
			textArea_valeur_choix_langue.invalidate();
			Image_allemand.setVisible(true);
			Image_allemand.invalidate();
			Image_anglais.setVisible(false);
			Image_anglais.invalidate();
			Image_francais.setVisible(false);
			Image_francais.invalidate();
			Image_neerlandais.setVisible(false);
			Image_neerlandais.invalidate();
			Image_portugais.setVisible(false);
			Image_portugais.invalidate();
			break;
	}
}
