#include <gui/langue_screen/LangueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LangueView::LangueView()
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
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_LANGUE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Récupération de la langue
    u8Langue = sConfig_IHM.sParam_Utilisateur.Langue;
	// Changement langue
	changementLangue();
}

void LangueView::setupScreen()
{
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
	if(sConfig_IHM.sParam_Utilisateur.Langue != u8Langue)
	{
		sConfig_IHM.sParam_Utilisateur.Langue = u8Langue;
		presenter->c_user_param();
	}
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

void LangueView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void LangueView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void LangueView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void LangueView::changeDate(S_DATE *sDate)
{
	if(sDate_old.Date != sDate->Date)
	{
		// Affichage de la date
	    Unicode::snprintf(textAreaBuffer_Date, 9, "%02d/%02d/%02d", sDate->Date, sDate->Month, sDate->Year);
	    barre_titre.date(textAreaBuffer_Date);
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
	else if(sDate_old.Minutes != sDate->Minutes)
	{
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
    barre_titre.invalidate();
	memcpy(&sDate_old, sDate, sizeof(S_DATE));
}
