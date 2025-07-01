#include <gui/installation_ecs_screen/Installation_ecsView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecsView::Installation_ecsView()
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
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CHAUFFE_EAU_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    barre_titre.invalidate();

    bOptionECS = sConfig_IHM.sOption_PAC.ECS;

    //Legionel ON/Off
    if(sParam_ECS_temp.bAntiLegionnel)
	{
		buttonWithLabel_on_cycle_legionel.setVisible(true);
		buttonWithLabel_off_cycle_legionel.setVisible(false);
	}
	else
	{
		buttonWithLabel_on_cycle_legionel.setVisible(false);
		buttonWithLabel_off_cycle_legionel.setVisible(true);
	}
    buttonWithLabel_on_cycle_legionel.invalidate();
    buttonWithLabel_off_cycle_legionel.invalidate();

	//ECS Oui/Non
    if(bOptionECS == 0)
	{
		toggleButton_oui_oui_non_ecs.forceState(false);
		toggleButton_oui_oui_non_ecs.setTouchable(true);
		toggleButton_non_oui_non_ecs.forceState(true);
		toggleButton_non_oui_non_ecs.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_ecs.forceState(true);
		toggleButton_oui_oui_non_ecs.setTouchable(false);
		toggleButton_non_oui_non_ecs.forceState(false);
		toggleButton_non_oui_non_ecs.setTouchable(true);
	}
    toggleButton_oui_oui_non_ecs.invalidate();
    toggleButton_non_oui_non_ecs.invalidate();


    //Temps max thermo
    update_time_ECS_thermo();
    //Demande forcée en début de cycle
    update_demande_forcee();
    //Simultane
    update_simultane();
}

void Installation_ecsView::update_time_ECS_thermo()
{
	if (sParam_ECS_temp.Time_ECS_Thermo == 0)
	{
		Unicode::snprintf(textAreaBuffer_Time_Thermo_Max, 8, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Time_Thermo_Max, 8, "%d h %02d min", sParam_ECS_temp.Time_ECS_Thermo / 60, sParam_ECS_temp.Time_ECS_Thermo % 60);
	}
	textArea_valeur_duree_cycle_thermo.setWildcard(textAreaBuffer_Time_Thermo_Max);
	textArea_valeur_duree_cycle_thermo.invalidate();
}

void Installation_ecsView::update_demande_forcee()
{
	if (sParam_ECS_temp.bModeGestionHysteresis == 1)
	{
		Unicode::snprintf(textAreaBuffer_DemandeForcee, 4, touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_DemandeForcee, 4, touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getText());
	}
	textArea_valeur_demande_debut_cycle_ecs.setWildcard(textAreaBuffer_DemandeForcee);
	textArea_valeur_demande_debut_cycle_ecs.invalidate();
}

void Installation_ecsView::update_simultane()
{
	if (sConfig_IHM.sParam_PAC.TypeRegul != REGUL_DIRECTE)
	{
		container_simultane_ecs.setVisible(true);
	}
	else container_simultane_ecs.setVisible(false);
	container_simultane_ecs.invalidate();

	if (sParam_ECS_temp.bGestionSimultanee == 1)
	{
		buttonWithLabel_on_simultane_ecs.setVisible(true);
	}
	else
	{
		buttonWithLabel_on_simultane_ecs.setVisible(false);
	}
	buttonWithLabel_on_simultane_ecs.invalidate();
}

void Installation_ecsView::bouton_oui_ecs()
{
	if(toggleButton_oui_oui_non_ecs.getState())
	{
		toggleButton_non_oui_non_ecs.forceState(false);
		toggleButton_non_oui_non_ecs.setTouchable(true);
		toggleButton_non_oui_non_ecs.invalidate();
		toggleButton_oui_oui_non_ecs.setTouchable(false);
		toggleButton_oui_oui_non_ecs.invalidate();
	}
	bOptionECS = 1;
}

void Installation_ecsView::bouton_non_ecs()
{
	if(toggleButton_non_oui_non_ecs.getState())
	{
		toggleButton_oui_oui_non_ecs.forceState(false);
		toggleButton_oui_oui_non_ecs.setTouchable(true);
		toggleButton_oui_oui_non_ecs.invalidate();
		toggleButton_non_oui_non_ecs.setTouchable(false);
		toggleButton_non_oui_non_ecs.invalidate();
	}
	bOptionECS = 0;
}

void Installation_ecsView::bouton_demande_forcee()
{
	if (sParam_ECS_temp.bModeGestionHysteresis == 1) sParam_ECS_temp.bModeGestionHysteresis = 0;
	else sParam_ECS_temp.bModeGestionHysteresis = 1;
	update_demande_forcee();
}

void Installation_ecsView::bouton_gauche_duree_cycle()
{
	if (sParam_ECS_temp.Time_ECS_Thermo > 0) sParam_ECS_temp.Time_ECS_Thermo--;
	else sParam_ECS_temp.Time_ECS_Thermo = 120;
	update_time_ECS_thermo();
}

void Installation_ecsView::bouton_droite_duree_cycle()
{
	if (sParam_ECS_temp.Time_ECS_Thermo < 120) sParam_ECS_temp.Time_ECS_Thermo++;
	else sParam_ECS_temp.Time_ECS_Thermo = 0;
	update_time_ECS_thermo();
}

void Installation_ecsView::bouton_hysteresis_ECS()
{
	// Hysteresis
	eHysteresis = HYST_ECS;
}

void Installation_ecsView::bouton_valider()
{
	sConfig_IHM.sParam_ECS = sParam_ECS_temp;
	sConfig_IHM.sOption_PAC.ECS = bOptionECS;
	presenter->c_install_ecs();
	presenter->c_install_param();
}

void Installation_ecsView::setupScreen()
{
    Installation_ecsViewBase::setupScreen();
}

void Installation_ecsView::tearDownScreen()
{
    Installation_ecsViewBase::tearDownScreen();
}


void Installation_ecsView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecsView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecsView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecsView::changeDate(S_DATE *sDate)
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
