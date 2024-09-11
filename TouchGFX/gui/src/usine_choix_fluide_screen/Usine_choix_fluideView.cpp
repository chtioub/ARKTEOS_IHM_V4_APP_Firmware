#include <gui/usine_choix_fluide_screen/Usine_choix_fluideView.hpp>

Usine_choix_fluideView::Usine_choix_fluideView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MARCHE_GENERAL_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PP)
	{
		toggleButton_baguio_pp.forceState(true);
		textArea_on_off_baguio_pp.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	//
	u8FluideC1 = sConfig_IHM.sModele_PAC.Gaz_C1;
	affichageFluideC1();
	u8FluideC2 = sConfig_IHM.sModele_PAC.Gaz_C2;
	affichageFluideC2();
}

void Usine_choix_fluideView::setupScreen()
{
    Usine_choix_fluideViewBase::setupScreen();
}

void Usine_choix_fluideView::tearDownScreen()
{
    Usine_choix_fluideViewBase::tearDownScreen();
}

void Usine_choix_fluideView::bouton_on_off()
{
	if(toggleButton_baguio_pp.getState())
	{
		textArea_on_off_baguio_pp.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_baguio_pp.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_baguio_pp.invalidate();
}

void Usine_choix_fluideView::bouton_droite_fluide_c1()
{
	if(++u8FluideC1 > GAZ_R454C)
	{
		u8FluideC1 = GAZ_NONE;
	}
	affichageFluideC1();
}

void Usine_choix_fluideView::bouton_gauche_fluide_c1()
{
	if(u8FluideC1 == GAZ_NONE)
	{
		u8FluideC1 = GAZ_R454C;
	}
	else u8FluideC1--;
	affichageFluideC1();
}

void Usine_choix_fluideView::affichageFluideC1()
{
	container_baguio_pp.setVisible(false);
	switch(u8FluideC1)
	{
		case GAZ_NONE:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "NA");
			break;
		case GAZ_R410:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R410A");
			break;
		case GAZ_R134:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R134a");
			break;
		case GAZ_R407:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R407C");
			break;
		case GAZ_R32:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R32");
			if(sConfig_IHM.sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV)
			{
				container_baguio_pp.setVisible(true);
			}
			break;
		case GAZ_HELIUM:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "He");
			break;
		case GAZ_R513:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R513");
			break;
		case GAZ_R454C:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R454C");
			break;
	}
	textArea_valeur_choix_fluide_c1.setWildcard(textAreaBuffer_FluideC1);
	textArea_valeur_choix_fluide_c1.invalidate();
	container_baguio_pp.invalidate();
}

void Usine_choix_fluideView::bouton_droite_fluide_c2()
{
	if(++u8FluideC2 > GAZ_R454C)
	{
		u8FluideC2 = GAZ_NONE;
	}
	affichageFluideC2();
}

void Usine_choix_fluideView::bouton_gauche_fluide_c2()
{
	if(u8FluideC2 == GAZ_NONE)
	{
		u8FluideC2 = GAZ_R454C;
	}
	else u8FluideC2--;
	affichageFluideC2();
}

void Usine_choix_fluideView::affichageFluideC2()
{
	switch(u8FluideC2)
	{
		case GAZ_NONE:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "NA");
			break;
		case GAZ_R410:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "R410A");
			break;
		case GAZ_R134:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "R134a");
			break;
		case GAZ_R407:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "R407C");
			break;
		case GAZ_R32:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "R32");
			break;
		case GAZ_HELIUM:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "He");
			break;
		case GAZ_R513:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "R513");
			break;
		case GAZ_R454C:
			Unicode::snprintf(textAreaBuffer_FluideC2, 6, "R454C");
			break;
	}
	textArea_valeur_choix_fluide_c2.setWildcard(textAreaBuffer_FluideC2);
	textArea_valeur_choix_fluide_c2.invalidate();
}

void Usine_choix_fluideView::bouton_retour()
{
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		application().gotoUsine_config_geotwinScreenNoTransition();
	}
	else if(sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		application().gotoUsine_config_ajpacScreenNoTransition();
	}
	else if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA)
	{
		application().gotoUsine_config_inverterraScreenNoTransition();
	}
	else application().gotoCode_numeriqueScreenNoTransition();
}

void Usine_choix_fluideView::bouton_valider()
{
	// Sauvegarde des fluides
	sConfig_IHM.sModele_PAC.Gaz_C1 = u8FluideC1;
	sConfig_IHM.sModele_PAC.Gaz_C2 = u8FluideC2;
    // Configuration des PACs Mitsu
    if(sConfig_IHM.sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV)
    {
		switch(sConfig_IHM.sModele_PAC.Gaz_C1)
		{
			case GAZ_R32:
				if(toggleButton_baguio_pp.getState())
				{
					sConfig_IHM.sModele_PAC.bReversible = 1;
					sConfig_IHM.sModele_PAC.bSupply = 0;
					sConfig_IHM.sModele_PAC.u3SousTypePAC = SOUS_TYPE_BAGUIO_PP;
				}
				else
				{
					sConfig_IHM.sModele_PAC.bReversible = 0;
					sConfig_IHM.sModele_PAC.u3SousTypePAC = SOUS_TYPE_UNDEFINED;
				}
				break;
			case GAZ_R410:
				sConfig_IHM.sModele_PAC.bReversible = 1;
				sConfig_IHM.sModele_PAC.u3SousTypePAC = SOUS_TYPE_UNDEFINED;
				break;
		}
    }
    else if(sConfig_IHM.sModele_PAC.u8ModelePAC == TIMAX_III)
    {
    	sConfig_IHM.sModele_PAC.bReversible = 1;
    	sConfig_IHM.sModele_PAC.u3SousTypePAC = SOUS_TYPE_UNDEFINED;
    }
    presenter->c_usine_param();
	application().gotoUsine_config_additionnelleScreenNoTransition();
}

void Usine_choix_fluideView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_choix_fluideView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_choix_fluideView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_choix_fluideView::changeDate(S_DATE *sDate)
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
