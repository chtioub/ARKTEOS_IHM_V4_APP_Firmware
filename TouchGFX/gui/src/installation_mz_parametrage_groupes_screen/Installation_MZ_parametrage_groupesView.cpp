#include <gui/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>


Installation_MZ_parametrage_groupesView::Installation_MZ_parametrage_groupesView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));//SER
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);//SER
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAMETRAGE_GROUPES_EAU_CENTRE_LARGE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	u16CarteGroupeA = sParamZxMZtemp[8].NumCarteMZ;
	u16CarteGroupeB = sParamZxMZtemp[9].NumCarteMZ;
	u16NumVoieGroupeA = sParamZxMZtemp[8].NumVoieMZ;
	u16NumVoieGroupeB = sParamZxMZtemp[9].NumVoieMZ;
	bGroupeAOnOff = sParamZxMZtemp[8].type_zone.GroupeEau.bGroupeActif;
	bGroupeBOnOff = sParamZxMZtemp[9].type_zone.GroupeEau.bGroupeActif;
	bAttentionClicked = false;

//	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_PARAMETRES_CENTRE_DEFAUT).getText());
//	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
//	Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
//	Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
//	barre_titre.titre(textAreaBuffer_Titre);

	if (u16CarteGroupeA == 3)
	{
		if (u16NumVoieGroupeA > 1) u16NumVoieGroupeA = 1; //Voie 2
	}
	else if(u16NumVoieGroupeA > 5) u16NumVoieGroupeA = 5;

	if (u16CarteGroupeB == 3)
	{
		if (u16NumVoieGroupeB > 1) u16NumVoieGroupeB = 1; //Voie 2
	}
	else if(u16NumVoieGroupeB > 5) u16NumVoieGroupeB = 5;

	MAJ_Type_GroupeA();
	MAJ_Type_GroupeB();

	Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_GroupeA, 10);
	textArea_bouton_groupe_A.setWildcard(textAreaBuffer_GroupeA);
	Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_GroupeB, 10);
	textArea_bouton_groupe_B.setWildcard(textAreaBuffer_GroupeB);
	textArea_bouton_groupe_A.invalidate();
	textArea_bouton_groupe_B.invalidate();
	container_attention.setVisible(false);
	container_attention.invalidate();
}

void Installation_MZ_parametrage_groupesView::MAJ_Type_GroupeA()
{
	if (bGroupeAOnOff)
	{
		image_on_off_groupe_A.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		switch (sParamZxMZtemp[8].TypeEmmetteur)
		{
			case PLANCHER:
				textArea_valeur_type_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT));
				break;
			case RADIATEUR:
				textArea_valeur_type_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
				break;
			case VENTILO:
				textArea_valeur_type_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT));
				break;
			case GAINABLE:
				textArea_valeur_type_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_GAINABLE_CENTRE_DEFAUT));
				break;
			case SOUS_STATION:
				textArea_valeur_type_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_SOUS_STATION_CENTRE_DEFAUT));
				break;
			default:
				break;
		}
		textArea_valeur_type_groupe_A.invalidate();
		container_groupe_A_type.setVisible(true);
	}
	else
	{
		image_on_off_groupe_A.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
		textArea_on_off_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		container_groupe_A_type.setVisible(false);
	}
	container_groupe_A_type.invalidate();
	textArea_on_off_groupe_A.invalidate();
}


void Installation_MZ_parametrage_groupesView::MAJ_Type_GroupeB()
{
	if (bGroupeBOnOff)
		{
			image_on_off_groupe_B.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
			textArea_on_off_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			switch (sParamZxMZtemp[8].TypeEmmetteur)
			{
				case PLANCHER:
					textArea_valeur_type_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT));
					break;
				case RADIATEUR:
					textArea_valeur_type_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
					break;
				case VENTILO:
					textArea_valeur_type_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT));
					break;
				case GAINABLE:
					textArea_valeur_type_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_GAINABLE_CENTRE_DEFAUT));
					break;
				case SOUS_STATION:
					textArea_valeur_type_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_SOUS_STATION_CENTRE_DEFAUT));
					break;
				default:
					break;
			}
			textArea_valeur_type_groupe_B.invalidate();
			container_groupe_B_type.setVisible(true);
		}
		else
		{
			image_on_off_groupe_B.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
			textArea_on_off_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			container_groupe_B_type.setVisible(false);
		}
		container_groupe_B_type.invalidate();
		textArea_on_off_groupe_B.invalidate();
}

void Installation_MZ_parametrage_groupesView::bouton_choix_carte_MZ_groupe_A()
{
	// Incrémentation de la variable attention pas de carte MZ3 on saute à a REG
	switch(sParamZxMZtemp[8].NumCarteMZ)
	{
		case CARTE_MZ1:
			sParamZxMZtemp[8].NumCarteMZ = CARTE_MZ2;
			textArea_bouton_carte_MZ_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			break;
		case CARTE_MZ2:
			sParamZxMZtemp[8].NumCarteMZ = CARTE_REG;
			textArea_bouton_carte_MZ_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			if (sParamZxMZtemp[8].NumVoieMZ > 2) sParamZxMZtemp[8].NumVoieMZ = 2;
			Unicode::snprintf(textAreaBuffer_Voie_GroupeA, 2, "%d", sParamZxMZtemp[8].NumVoieMZ);
			textArea_sortie_voie_groupe_A.setWildcard(textAreaBuffer_Voie_GroupeA);
			textArea_sortie_voie_groupe_A.invalidate();
			if (bAttentionClicked == false)
			{
				affichage_attention();
			}
			break;
		case CARTE_REG:
			sParamZxMZtemp[8].NumCarteMZ = CARTE_MZ1;
			textArea_bouton_carte_MZ_groupe_A.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			break;
		default:
			break;
	}
	textArea_bouton_carte_MZ_groupe_A.invalidate();
}

void Installation_MZ_parametrage_groupesView::bouton_choix_carte_MZ_groupe_B()
{
	// Incrémentation de la variable attention pas de carte MZ3 on saute à a REG
	switch(sParamZxMZtemp[9].NumCarteMZ)
	{
		case CARTE_MZ1:
			sParamZxMZtemp[9].NumCarteMZ = CARTE_MZ2;
			textArea_bouton_carte_MZ_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			break;
		case CARTE_MZ2:
			sParamZxMZtemp[9].NumCarteMZ = CARTE_REG;
			textArea_bouton_carte_MZ_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			if (sParamZxMZtemp[9].NumVoieMZ > 2) sParamZxMZtemp[9].NumVoieMZ = 2;
			Unicode::snprintf(textAreaBuffer_Voie_GroupeB, 2, "%d", sParamZxMZtemp[9].NumVoieMZ);
			textArea_sortie_voie_groupe_B.setWildcard(textAreaBuffer_Voie_GroupeB);
			textArea_sortie_voie_groupe_B.invalidate();
			if (bAttentionClicked == false)
			{
				affichage_attention();
			}
			break;
		case CARTE_REG:
			sParamZxMZtemp[9].NumCarteMZ = CARTE_MZ1;
			textArea_bouton_carte_MZ_groupe_B.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			break;
		default:
			break;
	}
	textArea_bouton_carte_MZ_groupe_B.invalidate();
}

void Installation_MZ_parametrage_groupesView:: bouton_sortie_groupe_A()
{
	uint16_t u16ValMax;
	if (sParamZxMZtemp[8].NumCarteMZ == CARTE_MZ1 || sParamZxMZtemp[8].NumCarteMZ == CARTE_MZ2)
	{
		u16ValMax = 5;
	}
	else u16ValMax = 2;

	if (sParamZxMZtemp[8].NumVoieMZ < u16ValMax) sParamZxMZtemp[8].NumVoieMZ++;
	else sParamZxMZtemp[8].NumVoieMZ = 1;

	Unicode::snprintf(textAreaBuffer_Voie_GroupeA, 2, "%d", sParamZxMZtemp[8].NumVoieMZ);
	textArea_sortie_voie_groupe_A.setWildcard(textAreaBuffer_Voie_GroupeA);
	textArea_sortie_voie_groupe_A.invalidate();
}

void Installation_MZ_parametrage_groupesView:: bouton_sortie_groupe_B()
{
	uint16_t u16ValMax;
	if (sParamZxMZtemp[9].NumCarteMZ == CARTE_MZ1 || sParamZxMZtemp[9].NumCarteMZ == CARTE_MZ2)
	{
		u16ValMax = 5;
	}
	else u16ValMax = 2;

	if (sParamZxMZtemp[9].NumVoieMZ < u16ValMax) sParamZxMZtemp[9].NumVoieMZ++;
	else sParamZxMZtemp[9].NumVoieMZ = 1;

	Unicode::snprintf(textAreaBuffer_Voie_GroupeB, 2, "%d", sParamZxMZtemp[9].NumVoieMZ);
	textArea_sortie_voie_groupe_B.setWildcard(textAreaBuffer_Voie_GroupeB);
	textArea_sortie_voie_groupe_B.invalidate();
}

void Installation_MZ_parametrage_groupesView:: bouton_groupe_A()
{
	sConfig_Hydrau_temp.u8NumZone = 8;
}

void Installation_MZ_parametrage_groupesView:: bouton_groupe_B()
{
	sConfig_Hydrau_temp.u8NumZone = 9;
}

void Installation_MZ_parametrage_groupesView:: affichage_attention()
{
	bAttentionClicked = true;
	container_attention.setVisible(true);
	container_attention.invalidate();
	button_valider.setTouchable(false);
	button_retour.setTouchable(false);
	//barre_titre.setTouchable(false); ne marche pas
}

void Installation_MZ_parametrage_groupesView:: attention_valid_button_clicked()
{
	container_attention.setVisible(false);
	container_attention.invalidate();
	button_valider.setTouchable(true);
	button_retour.setTouchable(true);
	//barre_titre.setTouchable(true);ne marche pas
}


void Installation_MZ_parametrage_groupesView::setupScreen()
{
    Installation_MZ_parametrage_groupesViewBase::setupScreen();
}

void Installation_MZ_parametrage_groupesView::tearDownScreen()
{
    Installation_MZ_parametrage_groupesViewBase::tearDownScreen();
}


void Installation_MZ_parametrage_groupesView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_parametrage_groupesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_parametrage_groupesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_parametrage_groupesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_parametrage_groupesView::changeDate(S_DATE *sDate)
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
