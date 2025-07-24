#include <gui/installation_ecs_avances_screen/Installation_ecs_avancesView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecs_avancesView::Installation_ecs_avancesView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);

	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_AVANCES_ECS).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	Time_Bascul_V3V_ECS = sParam_ECS_temp.Time_Bascul_V3V_ECS;
	bTypeAppointECS = sParam_ECS_temp.bTypeAppointECS;
	u2TypeEchangeur = u2TypeEchangeurECSTemp2 & 0b11;
	bSolaire = sParam_ECS_temp.bSolaire;
	bCouplageEJP = sParam_ECS_temp.bCouplageEJP;
	bBouclageECS = bBouclageECSTemp2;

	//Pas de choix appoint si appoint chauffage non déclaré
	if (sConfig_IHM.sOption_PAC.TypeAppoint == ELEC)
	{
		button_droite_type_appoint_ecs.setVisible(true);
		button_gauche_type_appoint_ecs.setVisible(true);
	}
	else
	{
		button_droite_type_appoint_ecs.setVisible(false);
		button_gauche_type_appoint_ecs.setVisible(false);
	}
	button_droite_type_appoint_ecs.invalidate();
	button_gauche_type_appoint_ecs.invalidate();

	//MAJ des boutons On/Off
	if (bSolaire == 1)
	{
		buttonWithLabel_off_solaire_ecs.setVisible(false);
		buttonWithLabel_on_solaire_ecs.setVisible(true);
	}
	else
	{
		buttonWithLabel_off_solaire_ecs.setVisible(true);
		buttonWithLabel_on_solaire_ecs.setVisible(false);
	}
	buttonWithLabel_off_solaire_ecs.invalidate();
	buttonWithLabel_on_solaire_ecs.invalidate();


	if (bCouplageEJP == 1)
	{
		buttonWithLabel_off_ejp_ecs.setVisible(false);
		buttonWithLabel_on_ejp_ecs.setVisible(true);
		Unicode::snprintf(textAreaBuffer_CouplageEJP, 4,touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	}
	else
	{
		buttonWithLabel_off_ejp_ecs.setVisible(true);
		buttonWithLabel_on_ejp_ecs.setVisible(false);
		Unicode::snprintf(textAreaBuffer_CouplageEJP, 4,touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	buttonWithLabel_off_ejp_ecs.invalidate();
	buttonWithLabel_on_ejp_ecs.invalidate();

	if (bBouclageECS == 1)
	{
		toggleButton_bouclage_ecs.forceState(true);
		Unicode::snprintf(textAreaBuffer_BouclageECS, 4,touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	}
	else
	{
		toggleButton_bouclage_ecs.forceState(false);
		Unicode::snprintf(textAreaBuffer_BouclageECS, 4,touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	toggleButton_bouclage_ecs.invalidate();
	textArea_on_off_bouclage_ecs.setWildcard(textAreaBuffer_BouclageECS);
	textArea_on_off_bouclage_ecs.invalidate();

	update_temps_rotation_vanne();
	update_type_appoint();
	update_type_echangeur();
}

void Installation_ecs_avancesView::update_temps_rotation_vanne()
{
	Unicode::snprintf(textAreaBuffer_TempsV3V, 13, "%d min %02d sec", Time_Bascul_V3V_ECS / 60, Time_Bascul_V3V_ECS % 60);
	textArea_valeur_temps_vanne_ecs.setWildcard(textAreaBuffer_TempsV3V);
	textArea_valeur_temps_vanne_ecs.invalidate();
}

void Installation_ecs_avancesView::update_type_appoint()
{
	if (bTypeAppointECS == ELEC_ECS)
	{
		Unicode::snprintf(textAreaBuffer_TypeAppoint, 24,touchgfx::TypedText(T_TEXT_TYPE_APPOINT_ECS_ECS).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_TypeAppoint, 24,touchgfx::TypedText(T_TEXT_TYPE_APPOINT_ECS_PAC).getText());
	}

	textArea_valeur_type_appoint_ecs.setWildcard(textAreaBuffer_TypeAppoint);
	textArea_valeur_type_appoint_ecs.invalidate();
}

void Installation_ecs_avancesView::update_type_echangeur()
{
	switch (u2TypeEchangeur)
	{
		case ECS_PLAQUE:
			Unicode::snprintf(textAreaBuffer_TypeEchangeur, 11,touchgfx::TypedText(T_TEXT_ECHANGEUR_ECS_PLAQUE_CENTRE_DEFAUT).getText());
			buttonWithLabel_puissance_echangeur_ecs.setVisible(true);
			break;
		case ECS_BAIN_MARIE:
			Unicode::snprintf(textAreaBuffer_TypeEchangeur, 11,touchgfx::TypedText(T_TEXT_ECHANGEUR_ECS_BAIN_MARIE_CENTRE_DEFAUT).getText());
			buttonWithLabel_puissance_echangeur_ecs.setVisible(false);
			break;
		case ECS_SERPENTIN:
			Unicode::snprintf(textAreaBuffer_TypeEchangeur, 11,touchgfx::TypedText(T_TEXT_ECHANGEUR_ECS_SERPENTIN_CENTRE_DEFAUT).getText());
			buttonWithLabel_puissance_echangeur_ecs.setVisible(true);
			break;
	}
	textArea_valeur_type_echangeur_ecs.setWildcard(textAreaBuffer_TypeEchangeur);
	textArea_valeur_type_echangeur_ecs.invalidate();
	buttonWithLabel_puissance_echangeur_ecs.invalidate();
	u2TypeEchangeurECSTemp2 = u2TypeEchangeur;
}

void Installation_ecs_avancesView::bouton_gauche_type_appoint()
{
	if (bTypeAppointECS == ELEC_ECS) bTypeAppointECS = ELEC_PAC;
	else bTypeAppointECS = ELEC_ECS;
	update_type_appoint();
}

void Installation_ecs_avancesView::bouton_droit_type_appoint()
{
	if (bTypeAppointECS == ELEC_ECS) bTypeAppointECS = ELEC_PAC;
	else bTypeAppointECS = ELEC_ECS;
	update_type_appoint();
}

void Installation_ecs_avancesView::bouton_gauche_type_echangeur()
{
	switch (u2TypeEchangeur)
	{
		case ECS_PLAQUE:
			u2TypeEchangeur = ECS_SERPENTIN;
			break;
		case ECS_BAIN_MARIE:
			u2TypeEchangeur = ECS_PLAQUE;
			break;
		case ECS_SERPENTIN:
			u2TypeEchangeur = ECS_BAIN_MARIE;;
			break;
	}
	update_type_echangeur();
}

void Installation_ecs_avancesView::bouton_droit_type_echangeur()
{
	switch (u2TypeEchangeur)
	{
		case ECS_PLAQUE:
			u2TypeEchangeur = ECS_BAIN_MARIE;
			break;
		case ECS_BAIN_MARIE:
			u2TypeEchangeur = ECS_SERPENTIN;
			break;
		case ECS_SERPENTIN:
			u2TypeEchangeur = ECS_PLAQUE;;
			break;
	}
	update_type_echangeur();
}

void Installation_ecs_avancesView::bouton_gauche_temps_vanne_ecs()
{
	if (Time_Bascul_V3V_ECS > 20) Time_Bascul_V3V_ECS--;
	update_temps_rotation_vanne();
}

void Installation_ecs_avancesView::bouton_droit_temps_vanne_ecs()
{
	if (Time_Bascul_V3V_ECS < 240) Time_Bascul_V3V_ECS++;
	update_temps_rotation_vanne();
}

void Installation_ecs_avancesView::bouton_bouclage_ecs()
{
//	if(toggleButton_bouclage_ecs.getState())
	if (bBouclageECS == 1)
	{
		toggleButton_bouclage_ecs.forceState(false);
		bBouclageECSTemp2 = 0;
		bBouclageECS = 0;
		Unicode::snprintf(textAreaBuffer_BouclageECS, 4,touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		toggleButton_bouclage_ecs.forceState(true);
		bBouclageECSTemp2 = 1;
		bBouclageECS = 1;
		Unicode::snprintf(textAreaBuffer_BouclageECS, 4,touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
	}
	toggleButton_bouclage_ecs.invalidate();
	textArea_on_off_bouclage_ecs.setWildcard(textAreaBuffer_BouclageECS);
	textArea_on_off_bouclage_ecs.invalidate();
}

void Installation_ecs_avancesView::bouton_valider()
{
	sParam_ECS_temp.Time_Bascul_V3V_ECS = Time_Bascul_V3V_ECS;
	sParam_ECS_temp.bTypeAppointECS = bTypeAppointECS & 1;
	sParam_ECS_temp.u2TypeEchangeur = u2TypeEchangeur & 0b11;
	sParam_ECS_temp.bBouclageECS = bBouclageECS & 1;

	sConfig_IHM.sParam_ECS.Time_Bascul_V3V_ECS = Time_Bascul_V3V_ECS;
	sConfig_IHM.sParam_ECS.bTypeAppointECS = bTypeAppointECS & 1;
	sConfig_IHM.sParam_ECS.u2TypeEchangeur = u2TypeEchangeur & 0b11;
	sConfig_IHM.sParam_ECS.bBouclageECS = bBouclageECS & 1;

	presenter->c_install_ecs();
}

void Installation_ecs_avancesView::setupScreen()
{
    Installation_ecs_avancesViewBase::setupScreen();
}

void Installation_ecs_avancesView::tearDownScreen()
{
    Installation_ecs_avancesViewBase::tearDownScreen();
}


void Installation_ecs_avancesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_avancesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_avancesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_avancesView::changeDate(S_DATE *sDate)
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
