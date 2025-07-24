#include <gui/date_heure_screen/Date_heureView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Date_heureView::Date_heureView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_DATE_HEURE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Init des variables
    if(sDate.Year != 0)
    {
    	u8Minutes = sDate.Minutes;
		u8Heures = sDate.Hours;
		u8Jour = sDate.Date;
		u8Mois = sDate.Month;
		u8Annee = sDate.Year;
    }
    else
    {
		u8Minutes = 25;
		u8Heures = 6;
		u8Jour = 25;
		u8Mois = 06;
		u8Annee = 21;
    }
	// Verification du nombre de jours dans le mois
	majNbJoursMois();
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Minutes, 3, "%02d", u8Minutes);
    textArea_minutes.setWildcard(textAreaBuffer_Minutes);
    Unicode::snprintf(textAreaBuffer_Heures, 3, "%02d", u8Heures);
    textArea_heure.setWildcard(textAreaBuffer_Heures);
    Unicode::snprintf(textAreaBuffer_Annee, 3, "%02d", u8Annee);
    textArea_annee.setWildcard(textAreaBuffer_Annee);
    Unicode::snprintf(textAreaBuffer_AnneeComplete, 5, "20%02d", u8Annee);
    textArea_annee_complete.setWildcard(textAreaBuffer_AnneeComplete);
	Unicode::snprintf(textAreaBuffer_Mois, 5, "%02d", u8Mois);
	textArea_mois.setWildcard(textAreaBuffer_Mois);
	majMois();
    Unicode::snprintf(textAreaBuffer_Jour, 5, "%02d", u8Jour);
    textArea_jours_cal.setWildcard(textAreaBuffer_Jour);
    textArea_jours.setWildcard(textAreaBuffer_Jour);
}

void Date_heureView::setupScreen()
{
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
    Unicode::snprintf(textAreaBuffer_Minutes, 3, "%02d", u8Minutes);
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
    Unicode::snprintf(textAreaBuffer_Minutes, 3, "%02d", u8Minutes);
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
    Unicode::snprintf(textAreaBuffer_Heures, 3, "%02d", u8Heures);
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
    Unicode::snprintf(textAreaBuffer_Heures, 3, "%02d", u8Heures);
    textArea_heure.setWildcard(textAreaBuffer_Heures);
    textArea_heure.invalidate();
}

void Date_heureView::bouton_annee_haut()
{
	if(++u8Annee > 99)
	{
		u8Annee = 20;
	}
	// Verification du nombre de jours dans le mois
	majNbJoursMois();
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Annee, 3, "%02d", u8Annee);
    textArea_annee.setWildcard(textAreaBuffer_Annee);
    textArea_annee.invalidate();
    Unicode::snprintf(textAreaBuffer_AnneeComplete, 5, "20%02d", u8Annee);
    textArea_annee_complete.setWildcard(textAreaBuffer_AnneeComplete);
    textArea_annee_complete.invalidate();
}

void Date_heureView::bouton_annee_bas()
{
	if(u8Annee == 0)
	{
		u8Annee = 99;
	}
	else u8Annee--;
	// Verification du nombre de jours dans le mois
	majNbJoursMois();
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Annee, 3, "%02d", u8Annee);
    textArea_annee.setWildcard(textAreaBuffer_Annee);
    textArea_annee.invalidate();
    Unicode::snprintf(textAreaBuffer_AnneeComplete, 5, "20%02d", u8Annee);
    textArea_annee_complete.setWildcard(textAreaBuffer_AnneeComplete);
    textArea_annee_complete.invalidate();
}

void Date_heureView::bouton_mois_haut()
{
	if(++u8Mois > 12)
	{
		u8Mois = 1;
	}
	majMois();
	textArea_mois_cal.invalidate();
	// Verification du nombre de jours dans le mois
	majNbJoursMois();
	// Affichage de la valeur
	Unicode::snprintf(textAreaBuffer_Mois, 5, "%02d", u8Mois);
	textArea_mois.setWildcard(textAreaBuffer_Mois);
	textArea_mois.invalidate();
}

void Date_heureView::bouton_mois_bas()
{
	if(u8Mois == 1)
	{
		u8Mois = 12;
	}
	else u8Mois--;
	majMois();
	textArea_mois_cal.invalidate();
	// Verification du nombre de jours dans le mois
	majNbJoursMois();
	// Affichage de la valeur
	Unicode::snprintf(textAreaBuffer_Mois, 5, "%02d", u8Mois);
	textArea_mois.setWildcard(textAreaBuffer_Mois);
	textArea_mois.invalidate();
}

void Date_heureView::bouton_jour_haut()
{
	if(++u8Jour > u8NbJoursMois)
	{
		u8Jour = 1;
	}
	// Affichage de la valeur
	Unicode::snprintf(textAreaBuffer_Jour, 5, "%02d", u8Jour);
	textArea_jours_cal.setWildcard(textAreaBuffer_Jour);
	textArea_jours_cal.invalidate();
	textArea_jours.setWildcard(textAreaBuffer_Jour);
	textArea_jours.invalidate();
}

void Date_heureView::bouton_jour_bas()
{
	if(u8Jour == 1)
	{
		u8Jour = u8NbJoursMois;
	}
	else u8Jour--;
	// Affichage de la valeur
	Unicode::snprintf(textAreaBuffer_Jour, 5, "%02d", u8Jour);
	textArea_jours_cal.setWildcard(textAreaBuffer_Jour);
	textArea_jours_cal.invalidate();
	textArea_jours.setWildcard(textAreaBuffer_Jour);
	textArea_jours.invalidate();
}

void Date_heureView::majMois()
{
	switch(u8Mois)
	{
		default:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_JANVIER_CENTRE_LARGE));
			break;
		case 2:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_FEVRIER_CENTRE_LARGE));
			break;
		case 3:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_MARS_CENTRE_LARGE));
			break;
		case 4:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_AVRIL_CENTRE_LARGE));
			break;
		case 5:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_MAI_CENTRE_LARGE));
			break;
		case 6:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_JUIN_CENTRE_LARGE));
			break;
		case 7:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_JUILLET_CENTRE_LARGE));
			break;
		case 8:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_AOUT_CENTRE_LARGE));
			break;
		case 9:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_SEPTEMBRE_CENTRE_LARGE));
			break;
		case 10:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_OCTOBRE_CENTRE_LARGE));
			break;
		case 11:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_NOVEMBRE_CENTRE_LARGE));
			break;
		case 12:
			textArea_mois_cal.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_DECEMBRE_CENTRE_LARGE));
			break;
	}
}

void Date_heureView::majNbJoursMois()
{
	if(u8Mois == 1 || u8Mois == 3 || u8Mois == 5 || u8Mois == 7 || u8Mois == 8 || u8Mois == 10 || u8Mois == 12)
	{
		u8NbJoursMois = 31;
	}
	else if(u8Mois == 4 || u8Mois == 6 || u8Mois == 9 || u8Mois == 11)
	{
		u8NbJoursMois = 30;
	}
	else
	{
		if((u8Annee % 4 == 0 && u8Annee % 100 != 0) || u8Annee % 400 == 0)
		{
			u8NbJoursMois = 29;	// Année bisextile
		}
		else u8NbJoursMois = 28;
	}
	//
	if(u8Jour > u8NbJoursMois)
	{
		u8Jour = u8NbJoursMois;
	}
	// Affichage de la valeur
	Unicode::snprintf(textAreaBuffer_Jour, 5, "%02d", u8Jour);
	textArea_jours_cal.setWildcard(textAreaBuffer_Jour);
	textArea_jours_cal.invalidate();
	textArea_jours.setWildcard(textAreaBuffer_Jour);
	textArea_jours.invalidate();
}

void Date_heureView::bouton_valider()
{
	sDate_modif.Minutes = u8Minutes;
	sDate_modif.Hours = u8Heures;
	sDate_modif.Date = u8Jour;
	sDate_modif.Month = u8Mois;
	sDate_modif.Year = u8Annee;
	// Page oui non
	eOuiNon = OUI_NON_MODE_DATE;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Date_heureView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Date_heureView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Date_heureView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Date_heureView::changeDate(S_DATE *sDate)
{
	if(sDate_old.Date != sDate->Date || sDate_old.Month!= sDate->Month || sDate_old.Year!= sDate->Year )
	{
		// Affichage de la date
	    Unicode::snprintf(textAreaBuffer_Date, 9, "%02d/%02d/%02d", sDate->Date, sDate->Month, sDate->Year);
	    barre_titre.date(textAreaBuffer_Date);
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
	else if(sDate_old.Minutes != sDate->Minutes || sDate_old.Hours != sDate->Hours)
	{
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
    barre_titre.invalidate();
	memcpy(&sDate_old, sDate, sizeof(S_DATE));
}
