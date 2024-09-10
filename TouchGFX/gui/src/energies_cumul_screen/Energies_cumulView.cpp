#include <gui/energies_cumul_screen/Energies_cumulView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Energies_cumulView::Energies_cumulView()
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
    // Titre histo produites ou consommees
	if(bConsoProd == 0)
	{
		Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CUMUL_PRODUITES_CENTRE_LARGE).getText());
		barre_titre.titre(textAreaBuffer_Titre);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_CUMUL_CONSOMMEES_CENTRE_LARGE).getText());
	    barre_titre.titre(textAreaBuffer_Titre);
	}
    // Init des variables
	u8TypeCumul = 0;
	textArea_energies_cumul.setTypedText(touchgfx::TypedText(T_TEXT_DEPUIS_MISE_EN_SERVICE_CENTRE_DEFAUT));
	// MAJ de l'affichage
	maj_affichage();
}

void Energies_cumulView::setupScreen()
{
    Energies_cumulViewBase::setupScreen();
}

void Energies_cumulView::tearDownScreen()
{
    Energies_cumulViewBase::tearDownScreen();
}

void Energies_cumulView::bouton_gauche()
{
	// Incrémentation de la variable
	if(u8TypeCumul == 0)
	{
		u8TypeCumul = 2;
	}
	else u8TypeCumul--;
	// MAJ de l'affichage
	maj_affichage();
}

void Energies_cumulView::bouton_droite()
{
	// Incrémentation de la variable
	if(++u8TypeCumul > 2)
	{
		u8TypeCumul = 0;
	}
	// MAJ de l'affichage
	maj_affichage();
}

void Energies_cumulView::bouton_raz()
{
	// Page oui / non
	eOuiNon = OUI_NON_CUMUL;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Energies_cumulView::maj_affichage()
{
	uint32_t u32ValeurMax = 10, u32EnergiesCumul_PAC = 0;
	// Modification du titre
	switch(u8TypeCumul)
	{
		default:
			textArea_energies_cumul.setTypedText(touchgfx::TypedText(T_TEXT_DEPUIS_MISE_EN_SERVICE_CENTRE_DEFAUT));
			buttonWithLabel_raz.setVisible(false);
			if(bConsoProd == 0)
			{
				// Init des variables
				u32EnergiesCumul_Chaud = sEnergie.Cumul_Produite.Debut_Chaud;
				u32EnergiesCumul_Froid = sEnergie.Cumul_Produite.Debut_Froid;
				u32EnergiesCumul_ECS = sEnergie.Cumul_Produite.Debut_ECS;
				u32EnergiesCumul_Piscine = sEnergie.Cumul_Produite.Debut_Piscine;
				u32EnergiesCumul_Elec_ECS = sEnergie.Cumul_Consommee.Debut_ElecECS;
				u32EnergiesCumul_Elec_Chaud = sEnergie.Cumul_Consommee.Debut_ElecChaud;
				// Init de la date
			    u8Jour = sEnergie.Cumul_Produite.Debut_Date.Date;
			    u8Mois = sEnergie.Cumul_Produite.Debut_Date.Month;
			    u8Annee = sEnergie.Cumul_Produite.Debut_Date.Year;
			}
			else
			{
				// Init des variables
				u32EnergiesCumul_Chaud = sEnergie.Cumul_Consommee.Debut_Chaud;
				u32EnergiesCumul_Froid = sEnergie.Cumul_Consommee.Debut_Froid;
				u32EnergiesCumul_ECS = sEnergie.Cumul_Consommee.Debut_ECS;
				u32EnergiesCumul_Piscine = sEnergie.Cumul_Consommee.Debut_Piscine;
				u32EnergiesCumul_Elec_ECS = sEnergie.Cumul_Consommee.Debut_ElecECS;
				u32EnergiesCumul_Elec_Chaud = sEnergie.Cumul_Consommee.Debut_ElecChaud;
				// Init de la date
			    u8Jour = sEnergie.Cumul_Consommee.Debut_Date.Date;
			    u8Mois = sEnergie.Cumul_Consommee.Debut_Date.Month;
			    u8Annee = sEnergie.Cumul_Consommee.Debut_Date.Year;
			}
			break;
		case 1:
			textArea_energies_cumul.setTypedText(touchgfx::TypedText(T_TEXT_ANNEE_EN_COURS_CENTRE_DEFAUT));
			buttonWithLabel_raz.setVisible(false);
			if(bConsoProd == 0)
			{
				// Init des variables
				u32EnergiesCumul_Chaud = sEnergie.Cumul_Produite.Annee_Chaud;
				u32EnergiesCumul_Froid = sEnergie.Cumul_Produite.Annee_Froid;
				u32EnergiesCumul_ECS = sEnergie.Cumul_Produite.Annee_ECS;
				u32EnergiesCumul_Piscine = sEnergie.Cumul_Produite.Annee_Piscine;
				u32EnergiesCumul_Elec_ECS = sEnergie.Cumul_Consommee.Annee_ElecECS;
				u32EnergiesCumul_Elec_Chaud = sEnergie.Cumul_Consommee.Annee_ElecChaud;
				// Init de la date
			    u8Jour = sEnergie.Cumul_Produite.Annee_Date.Date;
			    u8Mois = sEnergie.Cumul_Produite.Annee_Date.Month;
			    u8Annee = sEnergie.Cumul_Produite.Annee_Date.Year;
			}
			else
			{
				// Init des variables
				u32EnergiesCumul_Chaud = sEnergie.Cumul_Consommee.Annee_Chaud;
				u32EnergiesCumul_Froid = sEnergie.Cumul_Consommee.Annee_Froid;
				u32EnergiesCumul_ECS = sEnergie.Cumul_Consommee.Annee_ECS;
				u32EnergiesCumul_Piscine = sEnergie.Cumul_Consommee.Annee_Piscine;
				u32EnergiesCumul_Elec_ECS = sEnergie.Cumul_Consommee.Annee_ElecECS;
				u32EnergiesCumul_Elec_Chaud = sEnergie.Cumul_Consommee.Annee_ElecChaud;
				// Init de la date
			    u8Jour = sEnergie.Cumul_Consommee.Annee_Date.Date;
			    u8Mois = sEnergie.Cumul_Consommee.Annee_Date.Month;
			    u8Annee = sEnergie.Cumul_Consommee.Annee_Date.Year;
			}
			break;
		case 2:
			textArea_energies_cumul.setTypedText(touchgfx::TypedText(T_TEXT_CUMUL_PARTIEL_CENTRE_DEFAUT));
			buttonWithLabel_raz.setVisible(true);
			if(bConsoProd == 0)
			{
				// Init des variables
				u32EnergiesCumul_Chaud = sEnergie.Cumul_Produite.Partiel_Chaud;
				u32EnergiesCumul_Froid = sEnergie.Cumul_Produite.Partiel_Froid;
				u32EnergiesCumul_ECS = sEnergie.Cumul_Produite.Partiel_ECS;
				u32EnergiesCumul_Piscine = sEnergie.Cumul_Produite.Partiel_Piscine;
				u32EnergiesCumul_Elec_ECS = sEnergie.Cumul_Consommee.Partiel_ElecECS;
				u32EnergiesCumul_Elec_Chaud = sEnergie.Cumul_Consommee.Partiel_ElecChaud;
				// Init de la date
			    u8Jour = sEnergie.Cumul_Produite.Partiel_Date_Reset.Date;
			    u8Mois = sEnergie.Cumul_Produite.Partiel_Date_Reset.Month;
			    u8Annee = sEnergie.Cumul_Produite.Partiel_Date_Reset.Year;
			}
			else
			{
				// Init des variables
				u32EnergiesCumul_Chaud = sEnergie.Cumul_Consommee.Partiel_Chaud;
				u32EnergiesCumul_Froid = sEnergie.Cumul_Consommee.Partiel_Froid;
				u32EnergiesCumul_ECS = sEnergie.Cumul_Consommee.Partiel_ECS;
				u32EnergiesCumul_Piscine = sEnergie.Cumul_Consommee.Partiel_Piscine;
				u32EnergiesCumul_Elec_ECS = sEnergie.Cumul_Consommee.Partiel_ElecECS;
				u32EnergiesCumul_Elec_Chaud = sEnergie.Cumul_Consommee.Partiel_ElecChaud;
				// Init de la date
			    u8Jour = sEnergie.Cumul_Consommee.Partiel_Date_Reset.Date;
			    u8Mois = sEnergie.Cumul_Consommee.Partiel_Date_Reset.Month;
			    u8Annee = sEnergie.Cumul_Consommee.Partiel_Date_Reset.Year;
			}
			break;
	}
	textArea_energies_cumul.invalidate();
	buttonWithLabel_raz.invalidate();
	// Calcul de l'énergie totale
	u32EnergiesCumul_PAC = u32EnergiesCumul_Chaud + u32EnergiesCumul_Froid + u32EnergiesCumul_ECS + u32EnergiesCumul_Piscine;
	if(u32EnergiesCumul_PAC > u32ValeurMax)
	{
		u32ValeurMax = u32EnergiesCumul_PAC;
	}
	// Affichage de la graduation
    Unicode::snprintf(textAreaBuffer_value_1, 2, "0");
    textArea_energies_histo_1.setWildcard(textAreaBuffer_value_1);
    textArea_energies_histo_1.invalidate();
    Unicode::snprintf(textAreaBuffer_value_2, 7, "%d", (u32ValeurMax / 5) * 1);
    textArea_energies_histo_2.setWildcard(textAreaBuffer_value_2);
    textArea_energies_histo_2.invalidate();
    Unicode::snprintf(textAreaBuffer_value_3, 7, "%d", (u32ValeurMax / 5) * 2);
    textArea_energies_histo_3.setWildcard(textAreaBuffer_value_3);
    textArea_energies_histo_3.invalidate();
    Unicode::snprintf(textAreaBuffer_value_4, 7, "%d", (u32ValeurMax / 5) * 3);
    textArea_energies_histo_4.setWildcard(textAreaBuffer_value_4);
    textArea_energies_histo_4.invalidate();
    Unicode::snprintf(textAreaBuffer_value_5, 7, "%d", (u32ValeurMax / 5) * 4);
    textArea_energies_histo_5.setWildcard(textAreaBuffer_value_5);
    textArea_energies_histo_5.invalidate();
    Unicode::snprintf(textAreaBuffer_value_6, 7, "%d", (u32ValeurMax / 5) * 5);
    textArea_energies_histo_6.setWildcard(textAreaBuffer_value_6);
    textArea_energies_histo_6.invalidate();
    // Modification de la date
    Unicode::snprintf(textAreaBuffer_date, 9, "%02d/%02d/%02d", u8Jour, u8Mois, u8Annee);
    textArea_date.setWildcard(textAreaBuffer_date);
    textArea_date.invalidate();
    // Modifciation des valeurs
    if((u32EnergiesCumul_Elec_Chaud + u32EnergiesCumul_Elec_ECS) > 0)
    {
    	Unicode::snprintf(textAreaBuffer_value_pac, 14, "%d / %d", u32EnergiesCumul_PAC, (u32EnergiesCumul_Elec_Chaud + u32EnergiesCumul_Elec_ECS));
    }
    else Unicode::snprintf(textAreaBuffer_value_pac, 14, "%d", u32EnergiesCumul_PAC);
    textArea_energies_histo_pac.setWildcard(textAreaBuffer_value_pac);
    textArea_energies_histo_pac.invalidate();
    if(u32EnergiesCumul_Elec_Chaud > 0)
    {
    	Unicode::snprintf(textAreaBuffer_value_chaud, 14, "%d / %d", u32EnergiesCumul_Chaud, u32EnergiesCumul_Elec_Chaud);
    }
    else Unicode::snprintf(textAreaBuffer_value_chaud, 14, "%d", u32EnergiesCumul_Chaud);
    textArea_energies_histo_chaud.setWildcard(textAreaBuffer_value_chaud);
    textArea_energies_histo_chaud.invalidate();
    Unicode::snprintf(textAreaBuffer_value_froid, 7, "%d", u32EnergiesCumul_Froid);
    textArea_energies_histo_froid.setWildcard(textAreaBuffer_value_froid);
    textArea_energies_histo_froid.invalidate();
    if(u32EnergiesCumul_Elec_ECS > 0)
    {
    	Unicode::snprintf(textAreaBuffer_value_ecs, 14, "%d / %d", u32EnergiesCumul_ECS, u32EnergiesCumul_Elec_ECS);
    }
    else Unicode::snprintf(textAreaBuffer_value_ecs, 14, "%d", u32EnergiesCumul_ECS);
    textArea_energies_histo_ecs.setWildcard(textAreaBuffer_value_ecs);
    textArea_energies_histo_ecs.invalidate();
    Unicode::snprintf(textAreaBuffer_value_piscine, 7, "%d", u32EnergiesCumul_Piscine);
    textArea_energies_histo_piscine.setWildcard(textAreaBuffer_value_piscine);
    textArea_energies_histo_piscine.invalidate();
    // Modification des barres
    box_pac.setVisible(false);
    box_pac.invalidate();
    box_pac.setWidth(u32EnergiesCumul_PAC * 623 / u32ValeurMax);
    box_pac.setVisible(true);
    box_pac.invalidate();
    box_elec.setVisible(false);
    box_elec.invalidate();
    box_elec.setWidth((u32EnergiesCumul_Elec_ECS + u32EnergiesCumul_Elec_Chaud) * 623 / u32ValeurMax);
    box_elec.setX(box_pac.getX() + box_pac.getWidth() - box_elec.getWidth());
    if(box_pac.getWidth() > box_elec.getWidth())
    {
        box_elec.setVisible(true);
    }
    box_elec.invalidate();
    box_chaud.setVisible(false);
    box_chaud.invalidate();
    box_chaud.setWidth(u32EnergiesCumul_Chaud * 623 / u32ValeurMax);
    box_chaud.setVisible(true);
    box_chaud.invalidate();
    box_elec_chaud.setVisible(false);
    box_elec_chaud.invalidate();
    box_elec_chaud.setWidth(u32EnergiesCumul_Elec_Chaud * 623 / u32ValeurMax);
    box_elec_chaud.setX(box_chaud.getX() + box_chaud.getWidth() - box_elec_chaud.getWidth());
    if(box_chaud.getWidth() > box_elec_chaud.getWidth())
    {
    	box_elec_chaud.setVisible(true);
    }
    box_elec_chaud.invalidate();
    box_froid.setVisible(false);
    box_froid.invalidate();
    box_froid.setWidth(u32EnergiesCumul_Froid * 623 / u32ValeurMax);
    box_froid.setVisible(true);
    box_froid.invalidate();
    box_ecs.setVisible(false);
    box_ecs.invalidate();
    box_ecs.setWidth(u32EnergiesCumul_ECS * 623 / u32ValeurMax);
    box_ecs.setVisible(true);
    box_ecs.invalidate();
    box_elec_ecs.setVisible(false);
    box_elec_ecs.invalidate();
    box_elec_ecs.setWidth(u32EnergiesCumul_Elec_ECS * 623 / u32ValeurMax);
    box_elec_ecs.setX(box_ecs.getX() + box_ecs.getWidth() - box_elec_ecs.getWidth());
    if(box_ecs.getWidth() > box_elec_ecs.getWidth())
    {
        box_elec_ecs.setVisible(true);
    }
    box_elec_ecs.invalidate();
    box_piscine.setVisible(false);
    box_piscine.invalidate();
    box_piscine.setWidth(u32EnergiesCumul_Piscine * 623 / u32ValeurMax);
    box_piscine.setVisible(true);
    box_piscine.invalidate();
}

void Energies_cumulView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Energies_cumulView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Energies_cumulView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Energies_cumulView::changeDate(S_DATE *sDate)
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
