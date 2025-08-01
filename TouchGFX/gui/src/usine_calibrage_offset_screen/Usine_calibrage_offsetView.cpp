#include <gui/usine_calibrage_offset_screen/Usine_calibrage_offsetView.hpp>

Usine_calibrage_offsetView::Usine_calibrage_offsetView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	bConnexionDistance = false;
	changeDate(&sDate);
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutEther(&sCycEther);
	changeStatutPAC(&sStatut_PAC);
	u8NumSonde = OFF_DEP_PRIM;
	sConfig_OffsetTemp = sConfig_Offset;
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_CALIBRAGE_OFFSET_SONDES).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	toggleButton_oui_oui_non.forceState(false);
	toggleButton_oui_oui_non.setTouchable(true);
	toggleButton_non_oui_non.forceState(true);
	toggleButton_non_oui_non.setTouchable(false);
	toggleButton_oui_oui_non.invalidate();
	toggleButton_non_oui_non.invalidate();

	update_type_sonde();
	update_offset();
}

void Usine_calibrage_offsetView::setupScreen()
{
    Usine_calibrage_offsetViewBase::setupScreen();
}

void Usine_calibrage_offsetView::tearDownScreen()
{
    Usine_calibrage_offsetViewBase::tearDownScreen();
}

void Usine_calibrage_offsetView::bouton_oui()
{
	if(toggleButton_oui_oui_non.getState())
	{
		toggleButton_non_oui_non.forceState(false);
		toggleButton_non_oui_non.setTouchable(true);
		toggleButton_non_oui_non.invalidate();
		toggleButton_oui_oui_non.setTouchable(false);
		toggleButton_oui_oui_non.invalidate();
	}
}

void Usine_calibrage_offsetView::bouton_non()
{
	if(toggleButton_non_oui_non.getState())
	{
		toggleButton_oui_oui_non.forceState(false);
		toggleButton_oui_oui_non.setTouchable(true);
		toggleButton_oui_oui_non.invalidate();
		toggleButton_non_oui_non.setTouchable(false);
		toggleButton_non_oui_non.invalidate();
	}
}

void Usine_calibrage_offsetView::bouton_valider()
{
	if(toggleButton_oui_oui_non.getState())
	{
		send_new_value();
	}
}

void Usine_calibrage_offsetView::send_new_value()
{
	sConfig_Offset = sConfig_OffsetTemp;;

	presenter->c_usine_offset();

	//A mettre à la fin une fois la valeur envoyée
	toggleButton_oui_oui_non.forceState(false);
	toggleButton_oui_oui_non.setTouchable(true);
	toggleButton_oui_oui_non.invalidate();
	toggleButton_non_oui_non.forceState(true);
	toggleButton_non_oui_non.setTouchable(false);
	toggleButton_non_oui_non.invalidate();
}

void Usine_calibrage_offsetView::bouton_gauche_choix_sonde()
{
	if (u8NumSonde > OFF_DEP_PRIM) u8NumSonde--;
	else u8NumSonde = OFF_ECS_BASSE;
	update_type_sonde();
}

void Usine_calibrage_offsetView::bouton_droit_choix_sonde()
{
	if (u8NumSonde < OFF_ECS_BASSE) u8NumSonde++;
	else u8NumSonde = OFF_DEP_PRIM;
	update_type_sonde();
}

void Usine_calibrage_offsetView::update_type_sonde()
{
	switch(u8NumSonde)
	{
		case OFF_DEP_PRIM:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_DEPART_PRIMAIRE_CENTRE).getText());
			break;
		case OFF_RET_PRIM:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_RETOUR_PRIMAIRE_CENTRE).getText());
			break;
		case OFF_DEP_CAP:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_DEPART_CAPTEUR_CENTRE).getText());
			break;
		case OFF_RET_CAP:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_RETOUR_CAPTEUR_CENTRE).getText());
			break;
		case OFF_BAL_TAMP:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_BALLON_TAMPON_CENTRE).getText());
			break;
		case OFF_HP1:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_HP1_CENTRE).getText());
			break;
		case OFF_HP2:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_HP2_CENTRE).getText());
			break;
		case OFF_ECS_HAUTE:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_ECS_HAUT_CENTRE).getText());
			break;
		case OFF_ECS_BASSE:
			Unicode::snprintf(textAreaBuffer_sonde, 16, touchgfx::TypedText(T_TEXT_ECS_BAS_CENTRE).getText());
			break;
		default:
			break;
	}
	textArea_valeur_sonde.setWildcard(textAreaBuffer_sonde);
	textArea_valeur_sonde.invalidate();

	//i8ValOffset = 0;
	update_offset();
}

void Usine_calibrage_offsetView::bouton_gauche_offset_sonde()
{
	if (sConfig_OffsetTemp.i8Val[u8NumSonde] > -100) sConfig_OffsetTemp.i8Val[u8NumSonde]--;
	update_offset();
}

void Usine_calibrage_offsetView::bouton_droit_offset_sonde()
{
	if (sConfig_OffsetTemp.i8Val[u8NumSonde] < 100) sConfig_OffsetTemp.i8Val[u8NumSonde]++;
	update_offset();
}


void Usine_calibrage_offsetView::update_offset()
{
	Unicode::UnicodeChar degre[] = {0x00B0};
	Unicode::snprintfFloat(textAreaBuffer_valeur_offset, 6, "%.1f", ((float)sConfig_OffsetTemp.i8Val[u8NumSonde]/10));
	Unicode::snprintf(&textAreaBuffer_valeur_offset[Unicode::strlen(textAreaBuffer_valeur_offset)], 2,"%s", degre);
	Unicode::snprintf(&textAreaBuffer_valeur_offset[Unicode::strlen(textAreaBuffer_valeur_offset)], 2,"C");
	textArea_valeur_offset.setWildcard(textAreaBuffer_valeur_offset);
	textArea_valeur_offset.invalidate();
}


//void Usine_calibrage_offsetView::changeOffset(S_CONFIG_OFFSET *sConfig_Offset)
//{
////	memcpy(&sConfig_OffsetTemp, sConfig_Offset, sizeof(S_CONFIG_OFFSET));
////	update_offset();
//}

void Usine_calibrage_offsetView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_calibrage_offsetView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_calibrage_offsetView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void Usine_calibrage_offsetView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_calibrage_offsetView::changeDate(S_DATE *sDate)
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
