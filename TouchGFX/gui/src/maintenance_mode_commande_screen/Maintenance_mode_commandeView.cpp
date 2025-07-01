#include <gui/maintenance_mode_commande_screen/Maintenance_mode_commandeView.hpp>

Maintenance_mode_commandeView::Maintenance_mode_commandeView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeStatutCyclFrigo(&sCyclRegFrigo[0]);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_MODE_COMMANDE_TITRE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	//Lancement procédure
	toggleButton_non_oui_non.forceState(true);
	toggleButton_non_oui_non.setTouchable(false);
	toggleButton_oui_oui_non.forceState(false);
	toggleButton_oui_oui_non.setTouchable(true);
	toggleButton_non_oui_non.invalidate();
	toggleButton_oui_oui_non.invalidate();

	u16CodeCommande = 0;
	update_code_commande();
}

void Maintenance_mode_commandeView::setupScreen()
{
    Maintenance_mode_commandeViewBase::setupScreen();
}

void Maintenance_mode_commandeView::tearDownScreen()
{
    Maintenance_mode_commandeViewBase::tearDownScreen();
}

void Maintenance_mode_commandeView::bouton_gauche()
{
	if (u16CodeCommande > 0) u16CodeCommande--;
	else u16CodeCommande = 191;
	update_code_commande();
}

void Maintenance_mode_commandeView::bouton_droite()
{
	if (u16CodeCommande < 191) u16CodeCommande++;
	else u16CodeCommande = 0;
	update_code_commande();
}

void Maintenance_mode_commandeView::update_code_commande()
{
	Unicode::snprintf(textAreaBuffer_ValCodeCde, 4, "%d", u16CodeCommande);
	textArea_valeur_test_code.setWildcard(textAreaBuffer_ValCodeCde);
	textArea_valeur_test_code.invalidate();
}

void Maintenance_mode_commandeView::bouton_oui()
{
	toggleButton_oui_oui_non.forceState(true);
	toggleButton_oui_oui_non.setTouchable(false);
	toggleButton_non_oui_non.forceState(false);
	toggleButton_non_oui_non.setTouchable(true);
	toggleButton_non_oui_non.invalidate();
	toggleButton_oui_oui_non.invalidate();

	sCyclRegFrigo[0].pac.zuba.sInfoTrame.bTrame_SAV_IHM_Valide = 0;
	presenter->c_sav_par21();
}

void Maintenance_mode_commandeView::bouton_non()
{
	toggleButton_non_oui_non.forceState(true);
	toggleButton_non_oui_non.setTouchable(false);
	toggleButton_oui_oui_non.forceState(false);
	toggleButton_oui_oui_non.setTouchable(true);
	toggleButton_non_oui_non.invalidate();
	toggleButton_oui_oui_non.invalidate();
}

void Maintenance_mode_commandeView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	if (sCyclRegFrigo->pac.zuba.sInfoTrame.bTrame_SAV_IHM_Valide != 0)
	{

		Unicode::snprintf(textAreaBuffer_Valeur, 10, touchgfx::TypedText(T_TEXT_MODE_COMMANDE_VALEUR).getText());
		Unicode::snprintf(&textAreaBuffer_Valeur[Unicode::strlen(textAreaBuffer_Valeur)], 5, "%d", sCyclRegFrigo->pac.zuba.sInfoTrame.i16Resultat_Trame_Ihm_Sav);
	}
	else if (sCyclRegFrigo->pac.zuba.sInfoTrame.bAcces_Com_SAV == 1)
	{
		Unicode::snprintf(textAreaBuffer_Valeur, 60, touchgfx::TypedText(T_TEXT_MODE_COMMANDE_CDE_ENCOURS).getText());
	}
	else Unicode::snprintf(textAreaBuffer_Valeur, 60, touchgfx::TypedText(T_TEXT_NO_MODE_COMMANDE_DEFAUT).getText());
	textArea_retour_mode_commande.setWildcard(textAreaBuffer_Valeur);
	textArea_retour_mode_commande.invalidate();
}

void Maintenance_mode_commandeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Maintenance_mode_commandeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Maintenance_mode_commandeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Maintenance_mode_commandeView::changeDate(S_DATE *sDate)
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
