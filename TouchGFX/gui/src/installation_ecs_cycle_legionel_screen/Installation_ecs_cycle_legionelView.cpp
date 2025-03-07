#include <gui/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelView.hpp>
#include <texts/TextKeysAndLanguages.hpp>


Installation_ecs_cycle_legionelView::Installation_ecs_cycle_legionelView()
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
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CYCLE_ANTILEGIONELLOSE_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    barre_titre.invalidate();

    bAntiLegionnel = sParam_ECS_temp.bAntiLegionnel;
    Jour_Legionel = sParam_ECS_temp.Jour_Legionel;
    Heure_Legionel = sParam_ECS_temp.Heure_Legionel;

    //Legionelle Oui/Non
	if(bAntiLegionnel == 0)
	{
		toggleButton_oui_oui_non_cycle_legionel_ecs.forceState(false);
		toggleButton_oui_oui_non_cycle_legionel_ecs.setTouchable(true);
		toggleButton_non_oui_non_cycle_legionel_ecs.forceState(true);
		toggleButton_non_oui_non_cycle_legionel_ecs.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_cycle_legionel_ecs.forceState(true);
		toggleButton_oui_oui_non_cycle_legionel_ecs.setTouchable(false);
		toggleButton_non_oui_non_cycle_legionel_ecs.forceState(false);
		toggleButton_non_oui_non_cycle_legionel_ecs.setTouchable(true);
	}
	toggleButton_oui_oui_non_cycle_legionel_ecs.invalidate();
	toggleButton_non_oui_non_cycle_legionel_ecs.invalidate();

    update_heure_antilegionellose();
    update_jour_antilegionellose();
}

void Installation_ecs_cycle_legionelView::update_jour_antilegionellose()
{
	switch (Jour_Legionel)
	{
		case 0:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_LUNDI_CENTRE_DEFAUT).getText());
				break;
		case 1:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_MARDI_CENTRE_DEFAUT).getText());
				break;
		case 2:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_MERCREDI_CENTRE_DEFAUT).getText());
				break;
		case 3:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_JEUDI_CENTRE_DEFAUT).getText());
				break;
		case 4:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_VENDREDI_CENTRE_DEFAUT).getText());
				break;
		case 5:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_SAMEDI_CENTRE_DEFAUT).getText());
				break;
		case 6:
			   Unicode::snprintf(textAreaBuffer_JourLegionelle, 25, touchgfx::TypedText(T_TEXT_VALEUR_JOUR_DIMANCHE_CENTRE_DEFAUT).getText());
				break;
	}
	textArea_valeur_jour_cycle_legionel_ecs.setWildcard(textAreaBuffer_JourLegionelle);
	textArea_valeur_jour_cycle_legionel_ecs.invalidate();
}

void Installation_ecs_cycle_legionelView::update_heure_antilegionellose()
{
	Unicode::snprintf(textAreaBuffer_HeureLegionelle, 8, "%d h 00", Heure_Legionel);
	textArea_valeur_heure_cycle_legionel_ecs.setWildcard(textAreaBuffer_HeureLegionelle);
	textArea_valeur_heure_cycle_legionel_ecs.invalidate();
}


void Installation_ecs_cycle_legionelView::bouton_oui_legionelle()
{
	if(toggleButton_oui_oui_non_cycle_legionel_ecs.getState())
	{
		toggleButton_non_oui_non_cycle_legionel_ecs.forceState(false);
		toggleButton_non_oui_non_cycle_legionel_ecs.setTouchable(true);
		toggleButton_non_oui_non_cycle_legionel_ecs.invalidate();
		toggleButton_oui_oui_non_cycle_legionel_ecs.setTouchable(false);
		toggleButton_oui_oui_non_cycle_legionel_ecs.invalidate();
	}
	bAntiLegionnel = 1;
}

void Installation_ecs_cycle_legionelView::bouton_non_legionelle()
{
	if(toggleButton_non_oui_non_cycle_legionel_ecs.getState())
	{
		toggleButton_oui_oui_non_cycle_legionel_ecs.forceState(false);
		toggleButton_oui_oui_non_cycle_legionel_ecs.setTouchable(true);
		toggleButton_oui_oui_non_cycle_legionel_ecs.invalidate();
		toggleButton_non_oui_non_cycle_legionel_ecs.setTouchable(false);
		toggleButton_non_oui_non_cycle_legionel_ecs.invalidate();
	}
	bAntiLegionnel = 0;
}

void Installation_ecs_cycle_legionelView::bouton_gauche_jour()
{
	if (Jour_Legionel > 0) Jour_Legionel--;
	else Jour_Legionel = 6;
	update_jour_antilegionellose();
}

void Installation_ecs_cycle_legionelView::bouton_droit_jour()
{
	if (Jour_Legionel < 6) Jour_Legionel++;
	else Jour_Legionel = 0;
	update_jour_antilegionellose();
}

void Installation_ecs_cycle_legionelView::bouton_gauche_heure()
{
	if (Heure_Legionel > 0) Heure_Legionel--;
	else Heure_Legionel = 23;
	update_heure_antilegionellose();
}

void Installation_ecs_cycle_legionelView::bouton_droit_heure()
{
	if (Heure_Legionel < 23) Heure_Legionel++;
	else Heure_Legionel = 0;
	update_heure_antilegionellose();
}

void Installation_ecs_cycle_legionelView::bouton_valider()
{
	sParam_ECS_temp.bAntiLegionnel = bAntiLegionnel & 1;
	sParam_ECS_temp.Jour_Legionel = Jour_Legionel & 0b111;
	sParam_ECS_temp.Heure_Legionel = Heure_Legionel & 0b11111;

	sConfig_IHM.sParam_ECS.bAntiLegionnel = bAntiLegionnel & 1;
	sConfig_IHM.sParam_ECS.bAntiLegionnel = Jour_Legionel & 0b111;
	sConfig_IHM.sParam_ECS.bAntiLegionnel = Heure_Legionel & 0b11111;

	presenter->c_install_ecs();
}

void Installation_ecs_cycle_legionelView::setupScreen()
{
    Installation_ecs_cycle_legionelViewBase::setupScreen();
}

void Installation_ecs_cycle_legionelView::tearDownScreen()
{
    Installation_ecs_cycle_legionelViewBase::tearDownScreen();
}

void Installation_ecs_cycle_legionelView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_cycle_legionelView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_cycle_legionelView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_cycle_legionelView::changeDate(S_DATE *sDate)
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
