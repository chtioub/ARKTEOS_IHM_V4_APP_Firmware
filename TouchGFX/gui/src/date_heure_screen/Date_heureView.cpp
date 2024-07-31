#include <gui/date_heure_screen/Date_heureView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Date_heureView::Date_heureView()
{

}

void Date_heureView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_DATE_HEURE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Init des variables
    u8Minutes = 25;
    u8Heures = 6;
    u8Jour = 25;
    u8Mois = 06;
    u8Annee = 21;

    Date_heureViewBase::setupScreen();
}

void Date_heureView::tearDownScreen()
{
    Date_heureViewBase::tearDownScreen();
}

void Date_heureView::bouton_minutes_haut()
{
	if(++u8Minutes > 59)
	{
		u8Minutes = 0;
	}
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Minutes, 3, "%d", u8Minutes);
    textArea_minutes.setWildcard(textAreaBuffer_Minutes);
    textArea_minutes.invalidate();
}

void Date_heureView::bouton_minutes_bas()
{
	if(u8Minutes == 0)
	{
		u8Minutes = 59;
	}
	else u8Minutes--;
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Minutes, 3, "%d", u8Minutes);
    textArea_minutes.setWildcard(textAreaBuffer_Minutes);
    textArea_minutes.invalidate();
}

void Date_heureView::bouton_heures_haut()
{
	if(++u8Heures > 23)
	{
		u8Heures = 0;
	}
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Heures, 3, "%d", u8Heures);
    textArea_heure.setWildcard(textAreaBuffer_Heures);
    textArea_heure.invalidate();
}

void Date_heureView::bouton_heures_bas()
{
	if(u8Heures == 0)
	{
		u8Heures = 23;
	}
	else u8Heures--;
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Heures, 3, "%d", u8Heures);
    textArea_heure.setWildcard(textAreaBuffer_Heures);
    textArea_heure.invalidate();
}

void Date_heureView::bouton_annee_haut()
{
	if(++u8Annee > 99)
	{
		u8Annee = 20;
	}
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Annee, 3, "%d", u8Annee);
    textArea_annee.setWildcard(textAreaBuffer_Annee);
    textArea_annee.invalidate();
}

void Date_heureView::bouton_annee_bas()
{
	if(u8Annee == 20)
	{
		u8Annee = 99;
	}
	else u8Annee--;
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Annee, 3, "%d", u8Annee);
    textArea_annee.setWildcard(textAreaBuffer_Annee);
    textArea_annee.invalidate();
}

void Date_heureView::bouton_valider()
{
	application().gotoParametresScreenNoTransition();
}
