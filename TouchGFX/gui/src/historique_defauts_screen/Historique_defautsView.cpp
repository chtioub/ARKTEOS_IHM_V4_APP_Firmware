#include <gui/historique_defauts_screen/Historique_defautsView.hpp>
#include <images/BitmapDatabase.hpp>

Historique_defautsView::Historique_defautsView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	bConnexionDistance = false;
//	changeDate(&sDate);
//	changeErreur(u16ErreurEncours);
//	changeStatutPAC(&sStatut_PAC);
//	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_HISTO_DEFAUT_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void Historique_defautsView::setupScreen()
{
    Historique_defautsViewBase::setupScreen();

    // --- Mise à jour des infos d’état ---
    changeDate(&sDate);
    changeErreur(u16ErreurEncours);
    changeStatutPAC(&sStatut_PAC);
    changeStatutEther(&sCycEther);

    // --- Nettoyage de l’affichage précédent ---
    scrollableContainer.removeAll();

    // --- Variables locales ---
    int pointeur = sHisto_Erreur.Pointeur - 1;  // index de lecture dans l’historique
    int indexAffichage = 0;                     // index des lignes effectivement affichées

    // --- Parcours de 50 entrées max ---
    for (int i = 0; i < 50; i++, pointeur--)
    {
        // Gestion du buffer circulaire
        if (pointeur < 0)
            pointeur = 49;

        uint16_t defaut = sHisto_Erreur.Defaut[pointeur];

        // On n’affiche que les défauts valides
        if (defaut != 0 && (bPageUsine || ((defaut & DEFAUT_NV_HISTORIQUE) == 0)))
        {
            // Calcul de la position verticale
            const int yPos = 10 + 75 * indexAffichage;

            // -------------------------------------------------------
            // Image jaune ou rouge
            // -------------------------------------------------------
            image_defaut[indexAffichage].setXY(0, yPos);
            if (defaut & T_DEF_DEFAUT)
                image_defaut[indexAffichage].setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_DEFAUT_ROUGE_UNCLICKED_L79XH55_ID));
            else
                image_defaut[indexAffichage].setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ALERTE_JAUNE_UNCLICKED_L79XH55_ID));
            scrollableContainer.add(image_defaut[indexAffichage]);

            // -------------------------------------------------------
            // Ligne de séparation
            // -------------------------------------------------------
            line[indexAffichage].setPosition(0, yPos + 67, 920, 4);
            linePainter[indexAffichage].setColor(BLANC);
            line[indexAffichage].setPainter(linePainter[indexAffichage]);
            line[indexAffichage].setStart(0, 2);
            line[indexAffichage].setEnd(920, 2);
            line[indexAffichage].setLineWidth(4);
            line[indexAffichage].setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
            scrollableContainer.add(line[indexAffichage]);

            // -------------------------------------------------------
            // Date et heure du défaut
            // -------------------------------------------------------
            textArea_date_heure_def[indexAffichage].setPosition(663, yPos + 14, 257, 22);
            textArea_date_heure_def[indexAffichage].setColor(BLANC);
            textArea_date_heure_def[indexAffichage].setLinespacing(0);
            Unicode::snprintf(&textArea_date_heure_def_Buffer[indexAffichage][0], 20,
                              "%02d:%02d %02d/%02d/20%02d",
                              sHisto_Erreur.Date[pointeur].Hours,
                              sHisto_Erreur.Date[pointeur].Minutes,
                              sHisto_Erreur.Date[pointeur].Date,
                              sHisto_Erreur.Date[pointeur].Month,
                              sHisto_Erreur.Date[pointeur].Year);
            textArea_date_heure_def[indexAffichage].setWildcard(&textArea_date_heure_def_Buffer[indexAffichage][0]);
            textArea_date_heure_def[indexAffichage].setTypedText(touchgfx::TypedText(T_TEXT_DATE_HEURE_ERREUR_DROITE_DEFAUT));
            scrollableContainer.add(textArea_date_heure_def[indexAffichage]);

            // -------------------------------------------------------
            // Numéro du défaut
            // -------------------------------------------------------
            textArea_def_num[indexAffichage].setPosition(0, yPos + 16, 79, 23);
            textArea_def_num[indexAffichage].setColor(BLANC);
            textArea_def_num[indexAffichage].setLinespacing(0);
            Unicode::snprintf(&textArea_def_num_Buffer[indexAffichage][0], 4, "%d", defaut & 0x3FF);
            textArea_def_num[indexAffichage].setWildcard(&textArea_def_num_Buffer[indexAffichage][0]);
            textArea_def_num[indexAffichage].setTypedText(touchgfx::TypedText(T_TEXT_TEMP_EXT_CENTRE_DEFAUT));
            scrollableContainer.add(textArea_def_num[indexAffichage]);

            // -------------------------------------------------------
            // Texte du défaut
            // -------------------------------------------------------
            textArea_def[indexAffichage].setPosition(95, yPos + 12, 600, 23);
            textArea_def[indexAffichage].setColor(BLANC);
            textArea_def[indexAffichage].setLinespacing(0);

            if (u32Erreurs[defaut & 0x3FF] != 0)
                textArea_def[indexAffichage].setTypedText(touchgfx::TypedText(u32Erreurs[defaut & 0x3FF]));
            else
                textArea_def[indexAffichage].setTypedText(touchgfx::TypedText(T_TEXT_ERR_INCONNUE_GAUCHE_DEFAUT));

            scrollableContainer.add(textArea_def[indexAffichage]);

            // -------------------------------------------------------
            // ✅ Seulement ici on incrémente l’index visuel
            // -------------------------------------------------------
            indexAffichage++;
        }
    }

    // --- Rafraîchissement visuel ---
    scrollableContainer.invalidate();
}

void Historique_defautsView::tearDownScreen()
{
    Historique_defautsViewBase::tearDownScreen();
}

void Historique_defautsView::bouton_retour()
{
	if(bPageUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else application().gotoMaintenanceScreenNoTransition();
}

void Historique_defautsView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Historique_defautsView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Historique_defautsView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Historique_defautsView::changeDate(S_DATE *sDate)
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
