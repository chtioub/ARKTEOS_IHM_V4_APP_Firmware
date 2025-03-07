#include <gui/containers/Barre_titre.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "arkteos_defauts.h"

Barre_titre::Barre_titre()
{

}

void Barre_titre::initialize()
{
    Barre_titreBase::initialize();
}

void Barre_titre::connexionDistante(bool bConnexionDistante)
{
	Image_conn_distant.setVisible(bConnexionDistante);
	Image_conn_distant.invalidate();
}

void Barre_titre::recupConfig(bool bRecupConfig)
{
	Image_recup_config.setVisible(bRecupConfig);
	Image_recup_config.invalidate();
}

void Barre_titre::titre(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_titre.setWildcard(textArea_Buffer);
	textArea_titre.setTypedText(touchgfx::TypedText(T_TEXT_TITRE_CENTRE_LARGE));
	textArea_titre.invalidate();
}

void Barre_titre::heure(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_heure.setWildcard(textArea_Buffer);
	textArea_heure.setTypedText(touchgfx::TypedText(T_TEXT_TITRE_CENTRE_LARGE));
	textArea_heure.invalidate();
}

void Barre_titre::date(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_date.setWildcard(textArea_Buffer);
	textArea_date.setTypedText(touchgfx::TypedText(T_TEXT_TITRE_CENTRE_LARGE));
	textArea_date.invalidate();
}

void Barre_titre::sansRetour()
{
	button_retour_old.setVisible(false);
	button_retour_old.invalidate();
}

void Barre_titre::sansAccueil()
{
	button_accueil.setVisible(false);
	button_accueil.invalidate();
}

void Barre_titre::bouton_accueil()
{
	bPageAccueil = true;
}

void Barre_titre::erreur(uint16_t u16Erreur)
{
	//
	if(u16Erreur)
	{
	    Unicode::snprintf(textArea_Erreur, 4, "%d", u16Erreur & MASK_DEFAUT);
		textArea_code_def.setWildcard(textArea_Erreur);
		textArea_code_def.setVisible(true);
		if((u16Erreur & T_DEF_DEFAUT) == T_DEF_DEFAUT)
		{
			button_alerte.setVisible(false);
			button_defaut.setVisible(true);
		}
		else
		{
			button_defaut.setVisible(false);
			button_alerte.setVisible(true);
		}
	}
	else
	{
		textArea_code_def.setVisible(false);
		button_defaut.setVisible(false);
		button_alerte.setVisible(false);
	}
	textArea_code_def.invalidate();
	button_defaut.invalidate();
	button_alerte.invalidate();
}
