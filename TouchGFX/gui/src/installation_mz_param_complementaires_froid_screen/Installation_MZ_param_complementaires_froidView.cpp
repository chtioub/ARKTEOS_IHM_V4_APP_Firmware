#include <gui/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>


Installation_MZ_param_complementaires_froidView::Installation_MZ_param_complementaires_froidView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MODE_RAFRAICHISSEMENT_CENTRE_DEFAUT).getText());
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
	Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
	//Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", (sConfig_Hydrau_temp.u8NumZone == 8) ? 'A' : 'B');
	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
	barre_titre.titre(textAreaBuffer_Titre);

	// Mode Froid actif oui/non
	bModeFroid = (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].bModeFroid == 1) ? true : false;
	if(bModeFroid == false)
	{
		toggleButton_oui_oui_non_rafraichissement.forceState(false);
		toggleButton_oui_oui_non_rafraichissement.setTouchable(true);
		toggleButton_oui_oui_non_rafraichissement.invalidate();
		toggleButton_non_oui_non_rafraichissement.forceState(true);
		toggleButton_non_oui_non_rafraichissement.setTouchable(false);
		toggleButton_non_oui_non_rafraichissement.invalidate();
		container_temp_depart_eau_raf.setVisible(false);
	}
	else
	{
		toggleButton_oui_oui_non_rafraichissement.forceState(true);
		toggleButton_oui_oui_non_rafraichissement.setTouchable(false);
		toggleButton_oui_oui_non_rafraichissement.invalidate();
		toggleButton_non_oui_non_rafraichissement.forceState(false);
		toggleButton_non_oui_non_rafraichissement.setTouchable(true);
		toggleButton_non_oui_non_rafraichissement.invalidate();
		container_temp_depart_eau_raf.setVisible(true);
	}
	container_temp_depart_eau_raf.invalidate();

	// Consigne Froid
	if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur == PLANCHER)
	{
		if ((sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid + 7) < 17)
		{
			u16ConsigneFroid = 17;
		}
		else if ((sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid + 7) > 22)
		{
			u16ConsigneFroid = 22;
		}
		else
		{
			u16ConsigneFroid = sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid + 7;
		}
	}
	else
	{
		if ((sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid + 7) < 7)
		{
			u16ConsigneFroid = 7;
		}
		else if ((sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid + 7) > 17)
		{
			u16ConsigneFroid = 17;
		}
		else
		{
			u16ConsigneFroid = sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid + 7;
		}
	}

	Unicode::snprintf(textAreaBuffer_Consigne, 3, "%d", u16ConsigneFroid);
	textArea_valeur_temp_depart_eau_raf.setWildcard(textAreaBuffer_Consigne);
	textArea_valeur_temp_depart_eau_raf.invalidate();
}

void Installation_MZ_param_complementaires_froidView::bouton_droite_consigne()
{
	if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur == PLANCHER)
	{
		if (u16ConsigneFroid < 22)
		{
			u16ConsigneFroid++;
		}
	}
	else
	{
		if (u16ConsigneFroid < 17)
		{
			u16ConsigneFroid++;
		}
	}

//	Unicode::snprintf(textArea_Buffer_pw_produite, 6, "%d", sStatut_PAC->u16PWinstantaneeProduite);
//		textArea_puissance_produite_val.setWildcard(textArea_Buffer_pw_produite);
//		textArea_puissance_produite_val.invalidate();

//	Unicode::snprintf(textArea_Buffer_pw_produite, 6, "%d", sStatut_PAC->u16PWinstantaneeProduite);
//	textArea_puissance_produite_val.setWildcard(textArea_Buffer_pw_produite);
//	textArea_puissance_produite_val.invalidate();

	Unicode::snprintf(textAreaBuffer_Consigne, 3, "%d", u16ConsigneFroid);
	textArea_valeur_temp_depart_eau_raf.setWildcard(textAreaBuffer_Consigne);
	textArea_valeur_temp_depart_eau_raf.invalidate();
}

void Installation_MZ_param_complementaires_froidView::bouton_gauche_consigne()
{
	if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur == PLANCHER)
	{
		if (u16ConsigneFroid > 17)
		{
			u16ConsigneFroid--;
		}
	}
	else
	{
		if (u16ConsigneFroid  > 7)
		{
			u16ConsigneFroid--;
		}
	}

	Unicode::snprintf(textAreaBuffer_Consigne, 3, "%d", u16ConsigneFroid);
	textArea_valeur_temp_depart_eau_raf.setWildcard(textAreaBuffer_Consigne);
	textArea_valeur_temp_depart_eau_raf.invalidate();
}


//void Page_oui_nonView::bouton_oui_page_oui_non()
//{
//	if(toggleButton_oui_oui_non.getState())
//	{
//		toggleButton_non_oui_non.forceState(false);
//		toggleButton_non_oui_non.setTouchable(true);
//		toggleButton_non_oui_non.invalidate();
//		toggleButton_oui_oui_non.setTouchable(false);
//		toggleButton_oui_oui_non.invalidate();
//	}
//}

void Installation_MZ_param_complementaires_froidView::bouton_oui()
{
	if (toggleButton_oui_oui_non_rafraichissement.getState())
	{
		toggleButton_oui_oui_non_rafraichissement.setTouchable(false);
		toggleButton_oui_oui_non_rafraichissement.invalidate();
		toggleButton_non_oui_non_rafraichissement.forceState(false);
		toggleButton_non_oui_non_rafraichissement.setTouchable(true);
		toggleButton_non_oui_non_rafraichissement.invalidate();
		bModeFroid = true;

		container_temp_depart_eau_raf.setVisible(true);
		container_temp_depart_eau_raf.invalidate();
	}
}

void Installation_MZ_param_complementaires_froidView::bouton_non()
{
	if (toggleButton_non_oui_non_rafraichissement.getState())
	{
		toggleButton_non_oui_non_rafraichissement.setTouchable(false);
		toggleButton_non_oui_non_rafraichissement.invalidate();
		toggleButton_oui_oui_non_rafraichissement.forceState(false);
		toggleButton_oui_oui_non_rafraichissement.setTouchable(true);
		toggleButton_oui_oui_non_rafraichissement.invalidate();
		bModeFroid = false;

		container_temp_depart_eau_raf.setVisible(false);
		container_temp_depart_eau_raf.invalidate();
	}
}

void Installation_MZ_param_complementaires_froidView::setupScreen()
{
    Installation_MZ_param_complementaires_froidViewBase::setupScreen();
}

void Installation_MZ_param_complementaires_froidView::tearDownScreen()
{
    Installation_MZ_param_complementaires_froidViewBase::tearDownScreen();
}


void Installation_MZ_param_complementaires_froidView::bouton_valider()
{
	sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u4ConsigneTeauFroid = (( unsigned char)u16ConsigneFroid - 7);
	if (bModeFroid == true)
	{
		sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].bModeFroid = 1;
	}
	else
	{
		sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].bModeFroid = 0;
	}
}

void Installation_MZ_param_complementaires_froidView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	;
}

void Installation_MZ_param_complementaires_froidView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_param_complementaires_froidView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_complementaires_froidView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_complementaires_froidView::changeDate(S_DATE *sDate)
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