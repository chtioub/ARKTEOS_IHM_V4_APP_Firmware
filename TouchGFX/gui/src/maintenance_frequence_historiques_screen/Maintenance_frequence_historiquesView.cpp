#include <gui/maintenance_frequence_historiques_screen/Maintenance_frequence_historiquesView.hpp>

Maintenance_frequence_historiquesView::Maintenance_frequence_historiquesView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_FREQUENCE_ENREGISTREMENT_HISTORIQUE_TITRE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	u32ValAction_tmp = u32ValAction;
	if (u32ValAction_tmp < 5) u32ValAction_tmp = 5;
	else if (u32ValAction_tmp > 300) u32ValAction_tmp = 300;
	update_valeur_frequence();
}

void Maintenance_frequence_historiquesView::setupScreen()
{
    Maintenance_frequence_historiquesViewBase::setupScreen();
}

void Maintenance_frequence_historiquesView::tearDownScreen()
{
    Maintenance_frequence_historiquesViewBase::tearDownScreen();
}

void Maintenance_frequence_historiquesView::bouton_gauche()
{
	if (u32ValAction_tmp > 5) u32ValAction_tmp -= 5;
	update_valeur_frequence();
}

void Maintenance_frequence_historiquesView::bouton_droit()
{
	if (u32ValAction_tmp < 300) u32ValAction_tmp += 5;
	update_valeur_frequence();
}

void Maintenance_frequence_historiquesView::update_valeur_frequence()
{
	Unicode::snprintf(textAreaBuffer_Frequence, 4, "%d", u32ValAction_tmp);
	textArea_valeur_frequence.setWildcard(textAreaBuffer_Frequence);
	textArea_valeur_frequence.invalidate();
}

void Maintenance_frequence_historiquesView::bouton_valider()
{
	u16NumAction = SC_SAV_PARAM_FREQ_HISTO;
	u32ValAction = u32ValAction_tmp;
	presenter->c_sav_param();
}

void Maintenance_frequence_historiquesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Maintenance_frequence_historiquesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Maintenance_frequence_historiquesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Maintenance_frequence_historiquesView::changeDate(S_DATE *sDate)
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
