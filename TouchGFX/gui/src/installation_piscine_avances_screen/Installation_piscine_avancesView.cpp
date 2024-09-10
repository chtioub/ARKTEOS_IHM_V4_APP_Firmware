#include <gui/installation_piscine_avances_screen/Installation_piscine_avancesView.hpp>

Installation_piscine_avancesView::Installation_piscine_avancesView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_AVANCE_PISCINE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sParam_Piscine.bConfort)
	{
		textArea_valeur_prog_3_niveau_piscine.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	}
	else textArea_valeur_prog_3_niveau_piscine.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
	//
	u8TpsBasculementVanne = sConfig_IHM.sParam_Piscine.Time_Bascul_V3V_PISCINE;
	Unicode::snprintf(textAreaBuffer_TpsBasculementVanne, 15, "%d min %02d sec", u8TpsBasculementVanne / 60, u8TpsBasculementVanne % 60);
	textArea_valeur_temps_rotation_vanne.setWildcard(textAreaBuffer_TpsBasculementVanne);
}

void Installation_piscine_avancesView::setupScreen()
{
    Installation_piscine_avancesViewBase::setupScreen();
}

void Installation_piscine_avancesView::tearDownScreen()
{
    Installation_piscine_avancesViewBase::tearDownScreen();
}

void Installation_piscine_avancesView::timer_10ms()
{
	//
	if(button_gauche_prog_3_niveau_piscine.getPressedState())
	{
		if(u8PressionLongue_gauche < 15)
		{
			u8PressionLongue_gauche++;
		}
		else bouton_vanne_moins();
	}
	else u8PressionLongue_gauche = 0;
	//
	if(button_droite_prog_3_niveau_piscine.getPressedState())
	{
		if(u8PressionLongue_droite < 15)
		{
			u8PressionLongue_droite++;
		}
		else bouton_vanne_plus();
	}
	else u8PressionLongue_droite = 0;
}

void Installation_piscine_avancesView::bouton_vanne_moins()
{
	if(u8TpsBasculementVanne <= 20) return;
	//
	u8TpsBasculementVanne--;
	Unicode::snprintf(textAreaBuffer_TpsBasculementVanne, 15, "%d min %02d sec", u8TpsBasculementVanne / 60, u8TpsBasculementVanne % 60);
	textArea_valeur_temps_rotation_vanne.setWildcard(textAreaBuffer_TpsBasculementVanne);
	textArea_valeur_temps_rotation_vanne.invalidate();
}

void Installation_piscine_avancesView::bouton_vanne_plus()
{
	if(u8TpsBasculementVanne >= 240) return;
	//
	u8TpsBasculementVanne++;
	Unicode::snprintf(textAreaBuffer_TpsBasculementVanne, 15, "%d min %02d sec", u8TpsBasculementVanne / 60, u8TpsBasculementVanne % 60);
	textArea_valeur_temps_rotation_vanne.setWildcard(textAreaBuffer_TpsBasculementVanne);
	textArea_valeur_temps_rotation_vanne.invalidate();
}

void Installation_piscine_avancesView::bouton_confort()
{
	if(textArea_valeur_prog_3_niveau_piscine.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_prog_3_niveau_piscine.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
	}
	else textArea_valeur_prog_3_niveau_piscine.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
	textArea_valeur_prog_3_niveau_piscine.invalidate();
}

void Installation_piscine_avancesView::bouton_valider()
{
	if(textArea_valeur_prog_3_niveau_piscine.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
	{
		if(sConfig_IHM.sParam_Piscine.bConfort != 1)
		{
			for(int j = 0; j < 7; j++)
			{
				for(int i = 0; i < 8; i++)
				{
					au8Prog_Piscine[j][i] = 85;
				}
				for(int i = 8; i < 16; i++)
				{
					au8Prog_Piscine[j][i] = 170;
				}
				for(int i = 16; i < 24; i++)
				{
					au8Prog_Piscine[j][i] = 255;
				}
			}
			// Multiple trame
//			presenter->c_prog_piscine(true);
		}
		sConfig_IHM.sParam_Piscine.bConfort = 1;
	}
	else
	{
		if(sConfig_IHM.sParam_Piscine.bConfort != 0)
		{
			for(int j = 0; j < 7; j++)
			{
				for(int i = 0; i < 8; i++)
				{
					au8Prog_Piscine[j][i] = 0;
				}
				for(int i = 8; i < 16; i++)
				{
					au8Prog_Piscine[j][i] = 170;
				}
				for(int i = 16; i < 24; i++)
				{
					au8Prog_Piscine[j][i] = 0;
				}
			}
			// Multiple trame
//			presenter->c_prog_piscine(true);
		}
		sConfig_IHM.sParam_Piscine.bConfort = 0;
	}
	//
	sConfig_IHM.sParam_Piscine.Time_Bascul_V3V_PISCINE = u8TpsBasculementVanne;
	//
	presenter->c_install_piscine();
	application().gotoInstallation_piscineScreenNoTransition();
}

void Installation_piscine_avancesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_piscine_avancesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_piscine_avancesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_piscine_avancesView::changeDate(S_DATE *sDate)
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
