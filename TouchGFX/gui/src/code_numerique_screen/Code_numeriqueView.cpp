#include <gui/code_numerique_screen/Code_numeriqueView.hpp>
#include <images/BitmapDatabase.hpp>
#include <touchgfx/Utils.hpp>



Code_numeriqueView::Code_numeriqueView()
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
	modalWindow_code_inconnu.setBackground(touchgfx::BitmapId(BITMAP_BARRE_TITRE_L950XH63_ID), u8PositionX, u8PositionY + 524 - 64);
	modalWindow_code_inconnu.hide();
	modalWindow_code_inconnu.invalidate();

#ifdef SIMULATOR
			for (int i = 0; i<4;i++)
			{
				sConfig_IHM.sInstall_PAC.auc8PW_Maintenance[i] = '1';
				sConfig_IHM.sInstall_PAC.auc8PW_Installateur[i] = '1';
			}
#endif
	//
	memset(u8BufferCode, 0, 12);
	u8Longueur = 0;
	//
	switch(eCode)
	{
		case CODE_ACCES_INSTALL:
			//
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CODE_ACCES_CENTRE_DEFAUT).getText());
			break;
		case CODE_ACCES_USINE:
			//
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CODE_ACCES_CENTRE_DEFAUT).getText());
			break;
		case CODE_ACCES_MAINT:
			//
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CODE_ACCES_CENTRE_DEFAUT).getText());
			break;
		case MODIF_CODE_INSTALL:
			//
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_MODIF_CODE_ACCES_CENTRE_DEFAUT).getText());
			break;
		case MODIF_CODE_MAINT:
			//
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_MODIF_CODE_ACCES_CENTRE_DEFAUT).getText());
			break;
		case NUM_SERIE:
			for(int i = 0; i < 12; i++)
			{
				if(sConfig_IHM.sInstall_PAC.auc8Serial_Number_PAC[i] < '0' || sConfig_IHM.sInstall_PAC.auc8Serial_Number_PAC[i] > '9')
				{
					break;
				}
				if(i == 11)
				{
					u8Longueur = 12;
					memcpy(u8BufferCode, sConfig_IHM.sInstall_PAC.auc8Serial_Number_PAC, 12);
				}
				else u8Longueur = 0;
			}
			//
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_NUM_SERIE_DROITE_DEFAUT).getText());
			break;
	}
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();
	affichageNumero();
}

void Code_numeriqueView::setupScreen()
{
    Code_numeriqueViewBase::setupScreen();
}

void Code_numeriqueView::tearDownScreen()
{
    Code_numeriqueViewBase::tearDownScreen();
}

void Code_numeriqueView::affichageNumero()
{
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Valeur_tmp[25];
	int longueur = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueur = 12;
	}
	//
	for(int i = 0; i < longueur; i++)
	{
		if(u8BufferCode[i] >= '0' && u8BufferCode[i] <= '9')
		{
			if(eCode == CODE_ACCES_INSTALL || eCode == CODE_ACCES_USINE || eCode == CODE_ACCES_MAINT)
			{
				textAreaBuffer_Valeur_tmp[i * 2] = '*';
			}
			else textAreaBuffer_Valeur_tmp[i * 2] = u8BufferCode[i];
		}
		else textAreaBuffer_Valeur_tmp[i * 2] = '_';
		textAreaBuffer_Valeur_tmp[i * 2 + 1] = ' ';
	}
	textAreaBuffer_Valeur_tmp[longueur * 2 - 1] = 0;
	Unicode::strncpy(textAreaBuffer_Valeur, textAreaBuffer_Valeur_tmp, longueur * 2);
	textArea_value.setWildcard(textAreaBuffer_Valeur);
	textArea_value.invalidate();
}

void Code_numeriqueView::bouton_retour()
{
	switch(eCode)
	{
		case CODE_ACCES_INSTALL:
		case CODE_ACCES_USINE:
		case CODE_ACCES_MAINT:
//			application().gotoConfigurationScreenNoTransition();
			bPageAccueil = false;
			application().gotoAccueilScreenNoTransition();
			break;
		case MODIF_CODE_INSTALL:
			application().gotoInstallationScreenNoTransition();
			break;
		case MODIF_CODE_MAINT:
			application().gotoMaintenanceScreenNoTransition();
			break;
		case NUM_SERIE:
			application().gotoUsine_choix_modele_pacScreenNoTransition();
			break;
	}
}

void Code_numeriqueView::bouton_valider()
{
	touchgfx::Unicode::UnicodeChar BufferCodeUsine[5], BufferCode[5];

	switch(eCode)
	{
		case CODE_ACCES_INSTALL:
			if(u8Longueur == 4 && memcmp(&sConfig_IHM.sInstall_PAC.auc8PW_Installateur[0], &u8BufferCode[0], 4) == 0)
			{
				application().gotoInstallationScreenNoTransition();
			}
			else
			{
				modalWindow_code_inconnu.show();
				modalWindow_code_inconnu.invalidate();
			}
			break;
		case CODE_ACCES_USINE:
			Unicode::snprintf(BufferCodeUsine, 5, "%d", sDate.Date * 100 + sDate.Month + sDate.Year + 2000);
			Unicode::fromUTF8(u8BufferCode, BufferCode, 5);
			if(u8Longueur == 4 && Unicode::strncmp(&BufferCode[0], &BufferCodeUsine[0], 4) == 0)
			{
				application().gotoUsineScreenNoTransition();
			}
			else
			{
				modalWindow_code_inconnu.show();
				modalWindow_code_inconnu.invalidate();
			}
			break;
		case CODE_ACCES_MAINT:
			for (int i = 0; i< 4; i++)
			{
				touchgfx_printf("value %c\n",sConfig_IHM.sInstall_PAC.auc8PW_Maintenance[i]);
				touchgfx_printf("Buffer %c\n",u8BufferCode[i]);
				touchgfx_printf("Longueur %d\n",u8Longueur);
			}
			u8Longueur = 4;
			touchgfx_printf("Longueur %d\n",u8Longueur);

			if(u8Longueur == 4 && memcmp(&sConfig_IHM.sInstall_PAC.auc8PW_Maintenance[0], &u8BufferCode[0], 4) == 0)
			{
//			if(u8Longueur == 4 && memcmp(&sConfig_IHM.sInstall_PAC.auc8PW_Maintenance[0], &sConfig_IHM.sInstall_PAC.auc8PW_Maintenance[0], 4) == 0)
//			{
				application().gotoMaintenanceScreenNoTransition();
			}
			else
			{
				modalWindow_code_inconnu.show();
				modalWindow_code_inconnu.invalidate();
			}
			break;
		case MODIF_CODE_INSTALL:
			if(u8Longueur == 4)
			{
				memcpy(sConfig_IHM.sInstall_PAC.auc8PW_Installateur, u8BufferCode, 4);
				presenter->c_usine_password();
				application().gotoInstallationScreenNoTransition();
			}
			break;
		case MODIF_CODE_MAINT:
			if(u8Longueur == 4)
			{
				memcpy(sConfig_IHM.sInstall_PAC.auc8PW_Maintenance, u8BufferCode, 4);
				presenter->c_usine_password();
				application().gotoMaintenanceScreenNoTransition();
			}
			break;
		case NUM_SERIE:
			if(u8Longueur == 12)
			{
				memcpy(sConfig_IHM.sInstall_PAC.auc8Serial_Number_PAC, u8BufferCode, 12);
				presenter->c_usine_password();
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
				else application().gotoUsine_choix_fluideScreenNoTransition();
			}
			break;
	}
}

void Code_numeriqueView::bouton_valider_modal_window()
{
	memset(u8BufferCode, 0, 12);
	u8Longueur = 0;
	affichageNumero();
	modalWindow_code_inconnu.hide();
	modalWindow_code_inconnu.invalidate();
}

void Code_numeriqueView::bouton_supprimer()
{
	if(u8Longueur != 0)
	{
		u8BufferCode[u8Longueur - 1] = 0;
		u8Longueur--;
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_0()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '0';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_1()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '1';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_2()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '2';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_3()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '3';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_4()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '4';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_5()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '5';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_6()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '6';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_7()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '7';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_8()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '8';
		affichageNumero();
	}
}

void Code_numeriqueView::bouton_9()
{
	int longueurMax = 4;
	//
	if(eCode == NUM_SERIE)
	{
		longueurMax = 12;
	}
	//
	if(u8Longueur < longueurMax)
	{
		u8BufferCode[u8Longueur++] = '9';
		affichageNumero();
	}
}

void Code_numeriqueView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Code_numeriqueView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Code_numeriqueView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Code_numeriqueView::changeDate(S_DATE *sDate)
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

