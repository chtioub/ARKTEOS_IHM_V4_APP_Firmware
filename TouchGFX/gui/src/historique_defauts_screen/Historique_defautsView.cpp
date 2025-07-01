#include <gui/historique_defauts_screen/Historique_defautsView.hpp>
#include <images/BitmapDatabase.hpp>

Historique_defautsView::Historique_defautsView()
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
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_HISTO_DEFAUT_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	// Affichage des données
	for(int i = 0, pointeur = sHisto_Erreur.Pointeur - 1; i < 50; i++, pointeur--)
	{
		//
		if(pointeur < 0)
		{
			pointeur = 49;
		}
		//
		if(sHisto_Erreur.Defaut[pointeur] != 0 && (bPageUsine || ((sHisto_Erreur.Defaut[pointeur] & DEFAUT_NV_HISTORIQUE) == 0)))
		{
			// Image jaune ou rouge
			image_defaut[i].setXY(0, 10 + 74 * i);
			if(sHisto_Erreur.Defaut[pointeur] & T_DEF_DEFAUT)
			{
				image_defaut[i].setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_DEFAUT_ROUGE_UNCLICKED_L79XH55_ID));
			}
			else image_defaut[i].setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ALERTE_JAUNE_UNCLICKED_L79XH55_ID));
			scrollableContainer.add(image_defaut[i]);
			// Ligne de fin de défaut
			line[i].setPosition(0, 74 + 74 * i, 920, 4);
			linePainter[i].setColor(BLANC);
			line[i].setPainter(linePainter[i]);
			line[i].setStart(0, 2);
			line[i].setEnd(920, 2);
			line[i].setLineWidth(4);
			line[i].setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
			scrollableContainer.add(line[i]);
			// Date heure du défaut
			textArea_date_heure_def[i].setPosition(663, 24 + 74 * i, 257, 22);
			textArea_date_heure_def[i].setColor(BLANC);
			textArea_date_heure_def[i].setLinespacing(0);
			Unicode::snprintf(&textArea_date_heure_def_Buffer[i][0], 20, "%02d:%02d %02d/%02d/20%02d", sHisto_Erreur.Date[pointeur].Hours, sHisto_Erreur.Date[pointeur].Minutes, sHisto_Erreur.Date[pointeur].Date, sHisto_Erreur.Date[pointeur].Month, sHisto_Erreur.Date[pointeur].Year);
			textArea_date_heure_def[i].setWildcard(&textArea_date_heure_def_Buffer[i][0]);
			textArea_date_heure_def[i].setTypedText(touchgfx::TypedText(T_TEXT_DATE_HEURE_ERREUR_DROITE_DEFAUT));
			scrollableContainer.add(textArea_date_heure_def[i]);
			// Numéro du défaut
			textArea_def_num[i].setPosition(0, 26 + 74 * i, 79, 23);
			textArea_def_num[i].setColor(BLANC);
			textArea_def_num[i].setLinespacing(0);
			textArea_def_num_Buffer[i][0] = 0;
			Unicode::snprintf(&textArea_def_num_Buffer[i][0], 4, "%d", sHisto_Erreur.Defaut[pointeur] & 0x3ff);
			textArea_def_num[i].setWildcard(&textArea_def_num_Buffer[i][0]);
			textArea_def_num[i].setTypedText(touchgfx::TypedText(T_TEXT_TEMP_EXT_CENTRE_DEFAUT));
			scrollableContainer.add(textArea_def_num[i]);
			// Titre du défaut
//			textArea_def[i].setPosition(95, 24 + 74 * i, 600, 23);
//			textArea_def[i].setColor(BLANC);
//			textArea_def[i].setLinespacing(0);
//
//
//			if(u32Erreurs[sHisto_Erreur.Defaut[pointeur] & 0x3ff] != 0)
//			{
//				textArea_def[i].setTypedText(touchgfx::TypedText(u32Erreurs[sHisto_Erreur.Defaut[pointeur] & 0x3ff]));
//			}
//			else textArea_def[i].setTypedText(touchgfx::TypedText(T_TEXT_ERR_INCONNUE_GAUCHE_DEFAUT));
//
//			scrollableContainer.add(textArea_def[i]);


			scrollableContainerLabelDef[i].setPosition(95,22 + 74 * i,600,27);

			textArea_def[i].setPosition(0, 0, 800, 23);
			textArea_def[i].setColor(BLANC);
			textArea_def[i].setLinespacing(0);

			if(u32Erreurs[sHisto_Erreur.Defaut[pointeur] & 0x3ff] != 0)
			{
				textArea_def[i].setTypedText(touchgfx::TypedText(u32Erreurs[sHisto_Erreur.Defaut[pointeur] & 0x3ff]));
			}
			else textArea_def[i].setTypedText(touchgfx::TypedText(T_TEXT_ERR_INCONNUE_GAUCHE_DEFAUT));

			scrollableContainerLabelDef[i].add(textArea_def[i]);
			scrollableContainerLabelDef[i].invalidate();

			scrollableContainer.add(scrollableContainerLabelDef[i]);
		}
	}
	scrollableContainer.invalidate();
}

void Historique_defautsView::setupScreen()
{
    Historique_defautsViewBase::setupScreen();
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
