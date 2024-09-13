#include <gui/usine_config_inverterra_screen/Usine_config_inverterraView.hpp>

Usine_config_inverterraView::Usine_config_inverterraView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_INVERTERRA_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	if(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bSupply)
	{
		textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_TRI_CENTRE_DEFAUT));
	}
	//
	if(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bReversible)
	{
		toggleButton_reversible.forceState(true);
		textArea_on_off_reversible.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	//
	if(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u3SousType == GEOINV_SAGITAIR)
	{
		textArea_valeur_type_pac.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_PAC_INVERTERRA_SAGITAIR_CENTRE_DEFAUT));
		container_fluide_inverterra_sajiter.setVisible(true);
	}
	//
	u8Puissance = sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u7Puissance;
	if(u8Puissance < 4 || u8Puissance > 100)
	{
		u8Puissance = 4;
	}
	Unicode::snprintf(textAreaBuffer_Puissance, 4, "%d", u8Puissance);
	textArea_valeur_puissance_pac.setWildcard(textAreaBuffer_Puissance);
	//
	u8FluideC1 = sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u4TypeGaz;
	affichageFluideC1();
	//
}

void Usine_config_inverterraView::setupScreen()
{
    Usine_config_inverterraViewBase::setupScreen();
}

void Usine_config_inverterraView::tearDownScreen()
{
    Usine_config_inverterraViewBase::tearDownScreen();
}

void Usine_config_inverterraView::bouton_droite_fluide_c1()
{
	if(++u8FluideC1 > GAZ_R454C)
	{
		u8FluideC1 = GAZ_NONE;
	}
	affichageFluideC1();
}

void Usine_config_inverterraView::bouton_gauche_fluide_c1()
{
	if(u8FluideC1 == GAZ_NONE)
	{
		u8FluideC1 = GAZ_R454C;
	}
	else u8FluideC1--;
	affichageFluideC1();
}

void Usine_config_inverterraView::affichageFluideC1()
{
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
	textArea_valeur_fluide_inverterra_sajiter.setWildcard(textAreaBuffer_FluideC1);
	textArea_valeur_fluide_inverterra_sajiter.invalidate();
}

void Usine_config_inverterraView::bouton_moins_puissance()
{
	if(u8Puissance > 4)
	{
		u8Puissance--;
		Unicode::snprintf(textAreaBuffer_Puissance, 4, "%d", u8Puissance);
		textArea_valeur_puissance_pac.setWildcard(textAreaBuffer_Puissance);
		textArea_valeur_puissance_pac.invalidate();
	}
}

void Usine_config_inverterraView::bouton_plus_puissance()
{
	if(u8Puissance < 100)
	{
		u8Puissance++;
		Unicode::snprintf(textAreaBuffer_Puissance, 4, "%d", u8Puissance);
		textArea_valeur_puissance_pac.setWildcard(textAreaBuffer_Puissance);
		textArea_valeur_puissance_pac.invalidate();
	}
}

void Usine_config_inverterraView::bouton_on_off()
{
	if(toggleButton_reversible.getState())
	{
		textArea_on_off_reversible.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	else textArea_on_off_reversible.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
	textArea_on_off_reversible.invalidate();
}

void Usine_config_inverterraView::bouton_mono_tri()
{
	if(textArea_valeur_alim_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_TRI_CENTRE_DEFAUT));
	}
	else textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT));
	textArea_valeur_alim_pac.invalidate();
}

void Usine_config_inverterraView::bouton_type_inverterra()
{
	if(textArea_valeur_type_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_PAC_INVERTERRA_R454C_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_type_pac.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_PAC_INVERTERRA_SAGITAIR_CENTRE_DEFAUT));
		container_fluide_inverterra_sajiter.setVisible(true);
	}
	else
	{
		textArea_valeur_type_pac.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_PAC_INVERTERRA_R454C_CENTRE_DEFAUT));
		container_fluide_inverterra_sajiter.setVisible(false);
	}
	textArea_valeur_type_pac.invalidate();
	container_fluide_inverterra_sajiter.invalidate();
}

void Usine_config_inverterraView::timer_10ms()
{
	//
	if(button_gauche_puissance_pac.getPressedState())
	{
		if(u8PressionLongue_gauche < 15)
		{
			u8PressionLongue_gauche++;
		}
		else bouton_moins_puissance();
	}
	else u8PressionLongue_gauche = 0;
	//
	if(button_droite_puissance_pac.getPressedState())
	{
		if(u8PressionLongue_droite < 15)
		{
			u8PressionLongue_droite++;
		}
		else bouton_plus_puissance();
	}
	else u8PressionLongue_droite = 0;
}

void Usine_config_inverterraView::bouton_valider()
{
	if(textArea_valeur_alim_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT).getId())
	{
		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bSupply = 0;
	}
	else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bSupply = 1;
	//
	if(textArea_on_off_reversible.getTypedText().getId() == touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getId())
	{
		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bReversible = 1;
	}
	else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bReversible = 0;
	//
	if(textArea_valeur_type_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_PAC_INVERTERRA_SAGITAIR_CENTRE_DEFAUT).getId())
	{
		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u3SousType = GEOINV_SAGITAIR;
		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u4TypeGaz = u8FluideC1;
	}
	else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u3SousType = GEOINV_STD;
	// Débitmètres
	sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u4DebitmetreCaptage = HUBA_DN_20;
	sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u4DebitmetreChauffage = HUBA_DN_20;
	//
	sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.u7Puissance = u8Puissance & 0x7f;
	// Init type capteur
	sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeDeCaptage = 0;
	//
	presenter->c_usine_phoenix(0);
	application().gotoUsineScreenNoTransition();
}

void Usine_config_inverterraView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_config_inverterraView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_config_inverterraView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_config_inverterraView::changeDate(S_DATE *sDate)
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
