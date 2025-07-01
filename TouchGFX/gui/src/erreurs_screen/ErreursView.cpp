#include <gui/erreurs_screen/ErreursView.hpp>
#include <images/BitmapDatabase.hpp>

ErreursView::ErreursView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_ALARMES_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void ErreursView::setupScreen()
{
    ErreursViewBase::setupScreen();
}

void ErreursView::tearDownScreen()
{
    ErreursViewBase::tearDownScreen();
}

void ErreursView::bouton_retour()
{
    switch(eAnciennePage)
    {
		default:
			application().gotoAccueilScreenNoTransition();
			break;
    }
}

void ErreursView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void ErreursView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void ErreursView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
	//
	scrollableContainer.removeAll();
	//
	for(int i = 0; i < 25; i++)
	{
		//
		if(u16ListeErreurEncours[i] != 0 && (u16ListeErreurEncours[i] & DEFAUT_NV_IHM) == 0)
		{
			// Image jaune ou rouge
			image_defaut[i].setXY(0, 10 + 74 * i);
			if(u16ListeErreurEncours[i] & T_DEF_DEFAUT)
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
			// Numéro du défaut
			textArea_def_num[i].setPosition(0, 26 + 74 * i, 79, 23);
			textArea_def_num[i].setColor(BLANC);
			textArea_def_num[i].setLinespacing(0);
			textArea_def_num_Buffer[i][0] = 0;
			Unicode::snprintf(&textArea_def_num_Buffer[i][0], 4, "%d", u16ListeErreurEncours[i] & 0x3ff);
			textArea_def_num[i].setWildcard(&textArea_def_num_Buffer[i][0]);
			textArea_def_num[i].setTypedText(touchgfx::TypedText(T_TEXT_TEMP_EXT_CENTRE_DEFAUT));
			scrollableContainer.add(textArea_def_num[i]);
			// Titre du défaut
			textArea_def[i].setPosition(95, 24 + 74 * i, 600, 23);
			textArea_def[i].setColor(BLANC);
			textArea_def[i].setLinespacing(0);

			//Inverterra
			if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
			{
				if(u32ErreursINV[u16ListeErreurEncours[i] & 0x3ff] != 0)
				{
					textArea_def[i].setTypedText(touchgfx::TypedText(u32ErreursINV[u16ListeErreurEncours[i] & 0x3ff]));
				}
				else textArea_def[i].setTypedText(touchgfx::TypedText(T_TEXT_ERR_INCONNUE_GAUCHE_DEFAUT));
			}
			else
			{
				if(u32Erreurs[u16ListeErreurEncours[i] & 0x3ff] != 0)
				{
					textArea_def[i].setTypedText(touchgfx::TypedText(u32Erreurs[u16ListeErreurEncours[i] & 0x3ff]));
				}
				else textArea_def[i].setTypedText(touchgfx::TypedText(T_TEXT_ERR_INCONNUE_GAUCHE_DEFAUT));
			}
			scrollableContainer.add(textArea_def[i]);
		}
		else break;
	}
	scrollableContainer.invalidate();
}

void ErreursView::changeDate(S_DATE *sDate)
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
