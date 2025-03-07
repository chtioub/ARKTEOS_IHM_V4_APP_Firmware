#include <gui/installation_ecs_solaire_screen/Installation_ecs_solaireView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecs_solaireView::Installation_ecs_solaireView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_SOLAIRE_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	bContact = sParam_ECS_temp.bLogiqueSolaire;
	bSolaire = sParam_ECS_temp.bSolaire;
	update_contact();

	//Solaire Oui/Non
	if(bSolaire == 0)
	{
		toggleButton_oui_oui_non_solaire_ecs.forceState(false);
		toggleButton_oui_oui_non_solaire_ecs.setTouchable(true);
		toggleButton_non_oui_non_solaire_ecs.forceState(true);
		toggleButton_non_oui_non_solaire_ecs.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_solaire_ecs.forceState(true);
		toggleButton_oui_oui_non_solaire_ecs.setTouchable(false);
		toggleButton_non_oui_non_solaire_ecs.forceState(false);
		toggleButton_non_oui_non_solaire_ecs.setTouchable(true);
	}
	toggleButton_oui_oui_non_solaire_ecs.invalidate();
	toggleButton_non_oui_non_solaire_ecs.invalidate();

}

void Installation_ecs_solaireView::bouton_oui_solaire()
{
	if(toggleButton_oui_oui_non_solaire_ecs.getState())
	{
		toggleButton_non_oui_non_solaire_ecs.forceState(false);
		toggleButton_non_oui_non_solaire_ecs.setTouchable(true);
		toggleButton_non_oui_non_solaire_ecs.invalidate();
		toggleButton_oui_oui_non_solaire_ecs.setTouchable(false);
		toggleButton_oui_oui_non_solaire_ecs.invalidate();
	}
	bSolaire = 1;
}

void Installation_ecs_solaireView::bouton_non_solaire()
{
	if(toggleButton_non_oui_non_solaire_ecs.getState())
	{
		toggleButton_oui_oui_non_solaire_ecs.forceState(false);
		toggleButton_oui_oui_non_solaire_ecs.setTouchable(true);
		toggleButton_oui_oui_non_solaire_ecs.invalidate();
		toggleButton_non_oui_non_solaire_ecs.setTouchable(false);
		toggleButton_non_oui_non_solaire_ecs.invalidate();
	}
	bSolaire = 0;
}

void Installation_ecs_solaireView::bouton_gauche_contact()
{
	if (bContact == 0) bContact = 1;
	else bContact = 0;
	update_contact();
}

void Installation_ecs_solaireView::bouton_droite_contact()
{
	if (bContact == 0) bContact = 1;
	else bContact = 0;
	update_contact();
}

void Installation_ecs_solaireView::update_contact()
{
	if (bContact == 0)
	{
		Unicode::snprintf(textAreaBuffer_Contact, 7,touchgfx::TypedText(T_TEXT_VALEUR_ETAT_CONTACT_SOLAIRE_ECS_FERME_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Contact, 7,touchgfx::TypedText(T_TEXT_VALEUR_ETAT_CONTACT_SOLAIRE_ECS_OUVERT_CENTRE_DEFAUT).getText());
	}
	textArea_valeur_etat_contact_solaire_ecs.setWildcard(textAreaBuffer_Contact);
	textArea_valeur_etat_contact_solaire_ecs.invalidate();
}

void Installation_ecs_solaireView::bouton_valider()
{
	sParam_ECS_temp.bLogiqueSolaire = bContact & 1;
	sParam_ECS_temp.bSolaire = bSolaire & 1;

	sConfig_IHM.sParam_ECS.bLogiqueSolaire = bContact & 1;
	sConfig_IHM.sParam_ECS.bSolaire = bSolaire & 1;
	presenter->c_install_ecs();
}

void Installation_ecs_solaireView::setupScreen()
{
    Installation_ecs_solaireViewBase::setupScreen();
}

void Installation_ecs_solaireView::tearDownScreen()
{
    Installation_ecs_solaireViewBase::tearDownScreen();
}

void Installation_ecs_solaireView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_solaireView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_solaireView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_solaireView::changeDate(S_DATE *sDate)
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
