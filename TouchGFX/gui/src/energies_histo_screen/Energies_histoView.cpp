#include <gui/energies_histo_screen/Energies_histoView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Energies_histoView::Energies_histoView()
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
	// Init des boutons
	toggleButton_pac.forceState(true);
	toggleButton_12_mois.forceState(true);
	toggleButton_12_mois.setTouchable(false);
	container_barres_verticales_12.setVisible(true);
	container_barres_verticales_24.setVisible(false);
	container_lignes_verticales_24.setVisible(false);
    mois(sDate.Month);
    majbarres_mois();
    // Titre histo produites ou consommees
	if(bConsoProd == 0)
	{
		Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_HISTO_PRODUITES_CENTRE_LARGE).getText());
		barre_titre.titre(textAreaBuffer_Titre);
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_HISTO_CONSOMMEES_CENTRE_LARGE).getText());
		barre_titre.titre(textAreaBuffer_Titre);
	}
}

void Energies_histoView::setupScreen()
{
    Energies_histoViewBase::setupScreen();
}

void Energies_histoView::tearDownScreen()
{
  Energies_histoViewBase::tearDownScreen();
}

void Energies_histoView::bouton_pac()
{
//  presenter->energieState(1);
  if(toggleButton_pac.getState())
  {
    toggleButton_pac.setTouchable(false);
    toggleButton_pac.invalidate();
    toggleButton_chaud.setTouchable(true);
    toggleButton_chaud.forceState(false);
    toggleButton_chaud.invalidate();
    toggleButton_froid.setTouchable(true);
    toggleButton_froid.forceState(false);
    toggleButton_froid.invalidate();
    toggleButton_ecs.setTouchable(true);
    toggleButton_ecs.forceState(false);
    toggleButton_ecs.invalidate();
    toggleButton_piscine.setTouchable(true);
    toggleButton_piscine.forceState(false);
    toggleButton_piscine.invalidate();
    couleur_barres(0xffcd00);
		// MAJ des barres
		if(toggleButton_12_mois.getState())
		{
			majbarres_mois();
		}
		else if(toggleButton_24_jours.getState())
		{
		    majbarres_jours_heures(true);
		}
		else
		{
		    majbarres_jours_heures(false);
		}
  }
}

void Energies_histoView::bouton_chaud()
{
//  presenter->energieState(2);
  if(toggleButton_chaud.getState())
  {
    toggleButton_pac.setTouchable(true);
    toggleButton_pac.forceState(false);
    toggleButton_pac.invalidate();
    toggleButton_chaud.setTouchable(false);
    toggleButton_chaud.invalidate();
    toggleButton_froid.setTouchable(true);
    toggleButton_froid.forceState(false);
    toggleButton_froid.invalidate();
    toggleButton_ecs.setTouchable(true);
    toggleButton_ecs.forceState(false);
    toggleButton_ecs.invalidate();
    toggleButton_piscine.setTouchable(true);
    toggleButton_piscine.forceState(false);
    toggleButton_piscine.invalidate();
    couleur_barres(0xc14d00);
		// MAJ des barres
		if(toggleButton_12_mois.getState())
		{
			majbarres_mois();
		}
		else if(toggleButton_24_jours.getState())
		{
		    majbarres_jours_heures(true);
		}
		else
		{
		    majbarres_jours_heures(false);
		}
  }
}

void Energies_histoView::bouton_froid()
{
//  presenter->energieState(3);
  if(toggleButton_froid.getState())
  {
    toggleButton_pac.setTouchable(true);
    toggleButton_pac.forceState(false);
    toggleButton_pac.invalidate();
    toggleButton_chaud.setTouchable(true);
    toggleButton_chaud.forceState(false);
    toggleButton_chaud.invalidate();
    toggleButton_froid.setTouchable(false);
    toggleButton_froid.invalidate();
    toggleButton_ecs.setTouchable(true);
    toggleButton_ecs.forceState(false);
    toggleButton_ecs.invalidate();
    toggleButton_piscine.setTouchable(true);
    toggleButton_piscine.forceState(false);
    toggleButton_piscine.invalidate();
    couleur_barres(0x3ab0c8);
		// MAJ des barres
		if(toggleButton_12_mois.getState())
		{
			majbarres_mois();
		}
		else if(toggleButton_24_jours.getState())
		{
		    majbarres_jours_heures(true);
		}
		else
		{
		    majbarres_jours_heures(false);
		}
  }
}
void Energies_histoView::bouton_ecs()
{
	if(toggleButton_ecs.getState())
	{
		toggleButton_pac.setTouchable(true);
		toggleButton_pac.forceState(false);
		toggleButton_pac.invalidate();
		toggleButton_chaud.setTouchable(true);
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.invalidate();
		toggleButton_froid.setTouchable(true);
		toggleButton_froid.forceState(false);
		toggleButton_froid.invalidate();
		toggleButton_ecs.setTouchable(false);
		toggleButton_ecs.invalidate();
		toggleButton_piscine.setTouchable(true);
		toggleButton_piscine.forceState(false);
		toggleButton_piscine.invalidate();
		couleur_barres(0xe70094);
		// MAJ des barres
		if(toggleButton_12_mois.getState())
		{
			majbarres_mois();
		}
		else if(toggleButton_24_jours.getState())
		{
		    majbarres_jours_heures(true);
		}
		else
		{
		    majbarres_jours_heures(false);
		}
	}
}

void Energies_histoView::bouton_piscine()
{
	if(toggleButton_piscine.getState())
	{
		toggleButton_pac.setTouchable(true);
		toggleButton_pac.forceState(false);
		toggleButton_pac.invalidate();
		toggleButton_chaud.setTouchable(true);
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.invalidate();
		toggleButton_froid.setTouchable(true);
		toggleButton_froid.forceState(false);
		toggleButton_froid.invalidate();
		toggleButton_ecs.setTouchable(true);
		toggleButton_ecs.forceState(false);
		toggleButton_ecs.invalidate();
		toggleButton_piscine.setTouchable(false);
		toggleButton_piscine.invalidate();
		couleur_barres(0xb9c400);
		// MAJ des barres
		if(toggleButton_12_mois.getState())
		{
			majbarres_mois();
		}
		else if(toggleButton_24_jours.getState())
		{
		    majbarres_jours_heures(true);
		}
		else
		{
		    majbarres_jours_heures(false);
		}
	}
}

void Energies_histoView::bouton_12mois()
{
	if(toggleButton_12_mois.getState())
	{
		toggleButton_12_mois.setTouchable(false);
		toggleButton_12_mois.invalidate();
		toggleButton_24_jours.setTouchable(true);
		toggleButton_24_jours.forceState(false);
		toggleButton_24_jours.invalidate();
		toggleButton_24_heures.setTouchable(true);
		toggleButton_24_heures.forceState(false);
		toggleButton_24_heures.invalidate();
		container_barres_verticales_12.setVisible(true);
		container_barres_verticales_12.invalidate();
		container_barres_verticales_24.setVisible(false);
		container_barres_verticales_24.invalidate();
		container_lignes_verticales_24.setVisible(false);
		container_lignes_verticales_24.invalidate();
	    textArea_kwh.setTypedText(touchgfx::TypedText(T_TEXT_KWH_CENTRE_DEFAUT));
	    textArea_kwh.invalidate();
		textArea_mois.setTypedText(touchgfx::TypedText(T_TEXT_MOIS_GAUCHE_DEFAUT));
		textArea_mois.invalidate();
	    mois(sDate.Month);
		// MAJ des barres
	    majbarres_mois();
	}
}

void Energies_histoView::bouton_24jours()
{
	if(toggleButton_24_jours.getState())
	{
		toggleButton_12_mois.setTouchable(true);
		toggleButton_12_mois.forceState(false);
		toggleButton_12_mois.invalidate();
		toggleButton_24_jours.setTouchable(false);
		toggleButton_24_jours.invalidate();
		toggleButton_24_heures.setTouchable(true);
		toggleButton_24_heures.forceState(false);
		toggleButton_24_heures.invalidate();
		container_barres_verticales_12.setVisible(false);
		container_barres_verticales_12.invalidate();
		container_barres_verticales_24.setVisible(true);
		container_barres_verticales_24.invalidate();
		container_lignes_verticales_24.setVisible(true);
		container_lignes_verticales_24.invalidate();
	    textArea_kwh.setTypedText(touchgfx::TypedText(T_TEXT_KWH_CENTRE_DEFAUT));
	    textArea_kwh.invalidate();
		textArea_mois.setTypedText(touchgfx::TypedText(T_TEXT_JOURS_GAUCHE_DEFAUT));
		textArea_mois.invalidate();
	    jours(sDate.Date - 1, sDate.Month - 1, sDate.Year);
		// MAJ des barres
	    majbarres_jours_heures(true);
	}
}

void Energies_histoView::bouton_24heures()
{
	if(toggleButton_24_heures.getState())
	{
		toggleButton_12_mois.setTouchable(true);
		toggleButton_12_mois.forceState(false);
		toggleButton_12_mois.invalidate();
		toggleButton_24_jours.setTouchable(true);
		toggleButton_24_jours.forceState(false);
		toggleButton_24_jours.invalidate();
		toggleButton_24_heures.setTouchable(false);
		toggleButton_24_heures.invalidate();
		container_barres_verticales_12.setVisible(false);
		container_barres_verticales_12.invalidate();
		container_barres_verticales_24.setVisible(true);
		container_barres_verticales_24.invalidate();
		container_lignes_verticales_24.setVisible(true);
		container_lignes_verticales_24.invalidate();
	    textArea_kwh.setTypedText(touchgfx::TypedText(T_TEXT_WH_CENTRE_DEFAUT));
	    textArea_kwh.invalidate();
		textArea_mois.setTypedText(touchgfx::TypedText(T_TEXT_HEURES_GAUCHE_DEFAUT));
		textArea_mois.invalidate();
	    heures(sDate.Hours);
		// MAJ des barres
	    majbarres_jours_heures(false);
	}
}

void Energies_histoView::majbarres_mois()
{
	uint32_t u32ValeurMax = 10;	// Pour éviter de diviser par 0
	uint32_t u32Energies_mois[12], u32Energies_mois_elec[12];
	// Chargement d'un buffer unique
    for(int i = 0; i < 12; i++)
    {
    	if(toggleButton_pac.getState())
    	{
    		if(bConsoProd == 0)
    		{
				u32Energies_mois[i] = (uint32_t) sEnergie.Prod_12M.Chaud[(i + sEnergie.Prod_12M.Pointeur + 1) % 12] + (uint32_t) sEnergie.Prod_12M.Froid[(i + sEnergie.Prod_12M.Pointeur + 1) % 12] + (uint32_t) sEnergie.Prod_12M.ECS[(i + sEnergie.Prod_12M.Pointeur + 1) % 12] + (uint32_t) sEnergie.Prod_12M.Piscine[(i + sEnergie.Prod_12M.Pointeur + 1) % 12];
    		}
    		else u32Energies_mois[i] = (uint32_t) sEnergie.Conso_12M.Chaud[(i + sEnergie.Conso_12M.Pointeur + 1) % 12] + (uint32_t) sEnergie.Conso_12M.Froid[(i + sEnergie.Conso_12M.Pointeur + 1) % 12] + (uint32_t) sEnergie.Conso_12M.ECS[(i + sEnergie.Conso_12M.Pointeur + 1) % 12] + (uint32_t) sEnergie.Conso_12M.Piscine[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
    		u32Energies_mois_elec[i] = sEnergie.Conso_12M.ElecChaud[(i + sEnergie.Conso_12M.Pointeur + 1) % 12] + sEnergie.Conso_12M.ElecECS[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
    	}
    	else if(toggleButton_chaud.getState())
    	{
    		if(bConsoProd == 0)
    		{
				u32Energies_mois[i] = sEnergie.Prod_12M.Chaud[(i + sEnergie.Prod_12M.Pointeur + 1) % 12];
    		}
    		else u32Energies_mois[i] = sEnergie.Conso_12M.Chaud[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
			u32Energies_mois_elec[i] = sEnergie.Conso_12M.ElecChaud[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
    	}
    	else if(toggleButton_froid.getState())
    	{
    		if(bConsoProd == 0)
    		{
				u32Energies_mois[i] = sEnergie.Prod_12M.Froid[(i + sEnergie.Prod_12M.Pointeur + 1) % 12];
				u32Energies_mois_elec[i] = 0;
    		}
    		else u32Energies_mois[i] = sEnergie.Conso_12M.Froid[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
			u32Energies_mois_elec[i] = 0;
    	}
    	else if(toggleButton_ecs.getState())
    	{
    		if(bConsoProd == 0)
    		{
				u32Energies_mois[i] = sEnergie.Prod_12M.ECS[(i + sEnergie.Prod_12M.Pointeur + 1) % 12];
    		}
    		else u32Energies_mois[i] = sEnergie.Conso_12M.ECS[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
			u32Energies_mois_elec[i] = sEnergie.Conso_12M.ElecECS[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
    	}
    	else
		{
    		if(bConsoProd == 0)
    		{
				u32Energies_mois[i] = sEnergie.Prod_12M.Piscine[(i + sEnergie.Prod_12M.Pointeur + 1) % 12];
    		}
    		else u32Energies_mois[i] = sEnergie.Conso_12M.Piscine[(i + sEnergie.Conso_12M.Pointeur + 1) % 12];
			u32Energies_mois_elec[i] = 0;
		}
    	// Sauvegarde du max
		if(u32Energies_mois[i] > u32ValeurMax)
		{
			u32ValeurMax = u32Energies_mois[i] + 10;
		}
    }
	// Modification des labels de graduation
    Unicode::snprintf(textAreaBuffer_value_1, 7, "%d", (u32ValeurMax / 5));
    textArea_energies_cumul_1.setWildcard(textAreaBuffer_value_1);
    textArea_energies_cumul_1.invalidate();
    Unicode::snprintf(textAreaBuffer_value_2, 7, "%d", (u32ValeurMax / 5) * 2);
    textArea_energies_cumul_2.setWildcard(textAreaBuffer_value_2);
    textArea_energies_cumul_2.invalidate();
    Unicode::snprintf(textAreaBuffer_value_3, 7, "%d", (u32ValeurMax / 5) * 3);
    textArea_energies_cumul_3.setWildcard(textAreaBuffer_value_3);
    textArea_energies_cumul_3.invalidate();
    Unicode::snprintf(textAreaBuffer_value_4, 7, "%d", (u32ValeurMax / 5) * 4);
    textArea_energies_cumul_4.setWildcard(textAreaBuffer_value_4);
    textArea_energies_cumul_4.invalidate();
    Unicode::snprintf(textAreaBuffer_value_5, 7, "%d", (u32ValeurMax / 5) * 5);
    textArea_energies_cumul_5.setWildcard(textAreaBuffer_value_5);
    textArea_energies_cumul_5.invalidate();
    // Modification des barres
	box_mois_1.setHeight(u32Energies_mois[0] * 294 / u32ValeurMax);
	box_mois_1.setY(294 - box_mois_1.getHeight());
	box_mois_1.invalidate();
	box_mois_1_elec.setHeight(u32Energies_mois_elec[0] * 294 / u32ValeurMax);
	box_mois_1_elec.setY(box_mois_1.getY());
	if(box_mois_1.getHeight() > box_mois_1_elec.getHeight())
	{
		box_mois_1_elec.setVisible(true);
	}
	else box_mois_1_elec.setVisible(false);
	box_mois_1_elec.invalidate();
	box_mois_2.setHeight(u32Energies_mois[1] * 294 / u32ValeurMax);
	box_mois_2.setY(294 - box_mois_2.getHeight());
	box_mois_2.invalidate();
	box_mois_2_elec.setHeight(u32Energies_mois_elec[1] * 294 / u32ValeurMax);
	box_mois_2_elec.setY(box_mois_2.getY());
	if(box_mois_2.getHeight() > box_mois_2_elec.getHeight())
	{
		box_mois_2_elec.setVisible(true);
	}
	else box_mois_2_elec.setVisible(false);
	box_mois_2_elec.invalidate();
	box_mois_3.setHeight(u32Energies_mois[2] * 294 / u32ValeurMax);
	box_mois_3.setY(294 - box_mois_3.getHeight());
	box_mois_3.invalidate();
	box_mois_3_elec.setHeight(u32Energies_mois_elec[2] * 294 / u32ValeurMax);
	box_mois_3_elec.setY(box_mois_3.getY());
	if(box_mois_3.getHeight() > box_mois_3_elec.getHeight())
	{
		box_mois_3_elec.setVisible(true);
	}
	else box_mois_3_elec.setVisible(false);
	box_mois_3_elec.invalidate();
	box_mois_4.setHeight(u32Energies_mois[3] * 294 / u32ValeurMax);
	box_mois_4.setY(294 - box_mois_4.getHeight());
	box_mois_4.invalidate();
	box_mois_4_elec.setHeight(u32Energies_mois_elec[3] * 294 / u32ValeurMax);
	box_mois_4_elec.setY(box_mois_4.getY());
	if(box_mois_4.getHeight() > box_mois_4_elec.getHeight())
	{
		box_mois_4_elec.setVisible(true);
	}
	else box_mois_4_elec.setVisible(false);
	box_mois_4_elec.invalidate();
	box_mois_5.setHeight(u32Energies_mois[4] * 294 / u32ValeurMax);
	box_mois_5.setY(294 - box_mois_5.getHeight());
	box_mois_5.invalidate();
	box_mois_5_elec.setHeight(u32Energies_mois_elec[4] * 294 / u32ValeurMax);
	box_mois_5_elec.setY(box_mois_5.getY());
	if(box_mois_5.getHeight() > box_mois_5_elec.getHeight())
	{
		box_mois_5_elec.setVisible(true);
	}
	else box_mois_5_elec.setVisible(false);
	box_mois_5_elec.invalidate();
	box_mois_6.setHeight(u32Energies_mois[5] * 294 / u32ValeurMax);
	box_mois_6.setY(294 - box_mois_6.getHeight());
	box_mois_6.invalidate();
	box_mois_6_elec.setHeight(u32Energies_mois_elec[5] * 294 / u32ValeurMax);
	box_mois_6_elec.setY(box_mois_6.getY());
	if(box_mois_6.getHeight() > box_mois_6_elec.getHeight())
	{
		box_mois_6_elec.setVisible(true);
	}
	else box_mois_6_elec.setVisible(false);
	box_mois_6_elec.invalidate();
	box_mois_7.setHeight(u32Energies_mois[6] * 294 / u32ValeurMax);
	box_mois_7.setY(294 - box_mois_7.getHeight());
	box_mois_7.invalidate();
	box_mois_7_elec.setHeight(u32Energies_mois_elec[0] * 294 / u32ValeurMax);
	box_mois_7_elec.setY(box_mois_7.getY());
	if(box_mois_7.getHeight() > box_mois_7_elec.getHeight())
	{
		box_mois_7_elec.setVisible(true);
	}
	else box_mois_7_elec.setVisible(false);
	box_mois_7_elec.invalidate();
	box_mois_8.setHeight(u32Energies_mois[7] * 294 / u32ValeurMax);
	box_mois_8.setY(294 - box_mois_8.getHeight());
	box_mois_8.invalidate();
	box_mois_8_elec.setHeight(u32Energies_mois_elec[7] * 294 / u32ValeurMax);
	box_mois_8_elec.setY(box_mois_8.getY());
	if(box_mois_8.getHeight() > box_mois_8_elec.getHeight())
	{
		box_mois_8_elec.setVisible(true);
	}
	else box_mois_8_elec.setVisible(false);
	box_mois_8_elec.invalidate();
	box_mois_9.setHeight(u32Energies_mois[8] * 294 / u32ValeurMax);
	box_mois_9.setY(294 - box_mois_9.getHeight());
	box_mois_9.invalidate();
	box_mois_9_elec.setHeight(u32Energies_mois_elec[8] * 294 / u32ValeurMax);
	box_mois_9_elec.setY(box_mois_9.getY());
	if(box_mois_9.getHeight() > box_mois_9_elec.getHeight())
	{
		box_mois_9_elec.setVisible(true);
	}
	else box_mois_9_elec.setVisible(false);
	box_mois_9_elec.invalidate();
	box_mois_10.setHeight(u32Energies_mois[9] * 294 / u32ValeurMax);
	box_mois_10.setY(294 - box_mois_10.getHeight());
	box_mois_10.invalidate();
	box_mois_10_elec.setHeight(u32Energies_mois_elec[9] * 294 / u32ValeurMax);
	box_mois_10_elec.setY(box_mois_10.getY());
	if(box_mois_10.getHeight() > box_mois_10_elec.getHeight())
	{
		box_mois_10_elec.setVisible(true);
	}
	else box_mois_10_elec.setVisible(false);
	box_mois_10_elec.invalidate();
	box_mois_11.setHeight(u32Energies_mois[10] * 294 / u32ValeurMax);
	box_mois_11.setY(294 - box_mois_11.getHeight());
	box_mois_11.invalidate();
	box_mois_11_elec.setHeight(u32Energies_mois_elec[10] * 294 / u32ValeurMax);
	box_mois_11_elec.setY(box_mois_11.getY());
	if(box_mois_11.getHeight() > box_mois_11_elec.getHeight())
	{
		box_mois_11_elec.setVisible(true);
	}
	else box_mois_11_elec.setVisible(false);
	box_mois_11_elec.invalidate();
	box_mois_12.setHeight(u32Energies_mois[11] * 294 / u32ValeurMax);
	box_mois_12.setY(294 - box_mois_12.getHeight());
	box_mois_12.invalidate();
	box_mois_12_elec.setHeight(u32Energies_mois_elec[11] * 294 / u32ValeurMax);
	box_mois_12_elec.setY(box_mois_12.getY());
	if(box_mois_12.getHeight() > box_mois_12_elec.getHeight())
	{
		box_mois_12_elec.setVisible(true);
	}
	else box_mois_12_elec.setVisible(false);
	box_mois_12_elec.invalidate();
}

void Energies_histoView::mois(uint8_t u8Mois)
{
	touchgfx::TextArea *textArea_mois;

	for(int i = 0; i < 12; i++)
	{
		switch(i)
		{
			default:
				textArea_mois = &textArea_mois_1;
				break;
			case 1:
				textArea_mois = &textArea_mois_2;
				break;
			case 2:
				textArea_mois = &textArea_mois_3;
				break;
			case 3:
				textArea_mois = &textArea_mois_4;
				break;
			case 4:
				textArea_mois = &textArea_mois_5;
				break;
			case 5:
				textArea_mois = &textArea_mois_6;
				break;
			case 6:
				textArea_mois = &textArea_mois_7;
				break;
			case 7:
				textArea_mois = &textArea_mois_8;
				break;
			case 8:
				textArea_mois = &textArea_mois_9;
				break;
			case 9:
				textArea_mois = &textArea_mois_10;
				break;
			case 10:
				textArea_mois = &textArea_mois_11;
				break;
			case 11:
				textArea_mois = &textArea_mois_12;
				break;
		}

		switch((u8Mois + i) % 12)
		{
			default:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_JANVIER_CENTRE_DEFAUT));
				break;
			case 1:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_FEVRIER_CENTRE_DEFAUT));
				break;
			case 2:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_MARS_CENTRE_DEFAUT));
				break;
			case 3:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_AVRIL_CENTRE_DEFAUT));
				break;
			case 4:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_MAI_CENTRE_DEFAUT));
				break;
			case 5:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_JUIN_CENTRE_DEFAUT));
				break;
			case 6:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_JUILLET_CENTRE_DEFAUT));
				break;
			case 7:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_AOUT_CENTRE_DEFAUT));
				break;
			case 8:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_SEPTEMBRE_CENTRE_DEFAUT));
				break;
			case 9:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_OCTOBRE_CENTRE_DEFAUT));
				break;
			case 10:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_NOVEMBRE_CENTRE_DEFAUT));
				break;
			case 11:
				textArea_mois->setTypedText(touchgfx::TypedText(T_TEXT_ENERGIES_DECEMBRE_CENTRE_DEFAUT));
				break;
		}
		textArea_mois->invalidate();
	}
}

void Energies_histoView::majbarres_jours_heures(bool bJourHeure)
{
	uint32_t u32ValeurMax = 10;	// Pour éviter de diviser par 0
	uint32_t u32Energies_jours_heures[24], u32Energies_jours_heures_elec[24];
	// Chargement d'un buffer unique
    for(int i = 0; i < 24; i++)
    {
    	if(toggleButton_pac.getState())
    	{
    		if(bJourHeure == true)
    		{
        		if(bConsoProd == 0)
        		{
        			u32Energies_jours_heures[i] = sEnergie.Prod_24J.Chaud[(i + sEnergie.Prod_24J.Pointeur + 1) % 24] + sEnergie.Prod_24J.Froid[(i + sEnergie.Prod_24J.Pointeur + 1) % 24] + sEnergie.Prod_24J.ECS[(i + sEnergie.Prod_24J.Pointeur + 1) % 24] + sEnergie.Prod_24J.Piscine[(i + sEnergie.Prod_24J.Pointeur + 1) % 24];
        		}
        		else u32Energies_jours_heures[i] = sEnergie.Conso_24J.Chaud[(i + sEnergie.Conso_24J.Pointeur + 1) % 24] + sEnergie.Conso_24J.Froid[(i + sEnergie.Conso_24J.Pointeur + 1) % 24] + sEnergie.Conso_24J.ECS[(i + sEnergie.Conso_24J.Pointeur + 1) % 24] + sEnergie.Conso_24J.Piscine[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
        		u32Energies_jours_heures_elec[i] = sEnergie.Conso_24J.ElecChaud[(i + sEnergie.Conso_24J.Pointeur + 1) % 24] + sEnergie.Conso_24J.ElecECS[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
    		}
    		else
			{
        		if(bConsoProd == 0)
        		{
        			u32Energies_jours_heures[i] = sEnergie.Prod_24H.Chaud[(i + sEnergie.Prod_24H.Pointeur + 1) % 24] + sEnergie.Prod_24H.Froid[(i + sEnergie.Prod_24H.Pointeur + 1) % 24] + sEnergie.Prod_24H.ECS[(i + sEnergie.Prod_24H.Pointeur + 1) % 24] + sEnergie.Prod_24H.Piscine[(i + sEnergie.Prod_24H.Pointeur + 1) % 24];
        		}
        		else u32Energies_jours_heures[i] = sEnergie.Conso_24H.Chaud[(i + sEnergie.Conso_24H.Pointeur + 1) % 24] + sEnergie.Conso_24H.Froid[(i + sEnergie.Conso_24H.Pointeur + 1) % 24] + sEnergie.Conso_24H.ECS[(i + sEnergie.Conso_24H.Pointeur + 1) % 24] + sEnergie.Conso_24H.Piscine[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
        		u32Energies_jours_heures_elec[i] = sEnergie.Conso_24H.ElecChaud[(i + sEnergie.Conso_24H.Pointeur + 1) % 24] + sEnergie.Conso_24H.ElecECS[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
			}
    	}
    	else if(toggleButton_chaud.getState())
    	{
    		if(bJourHeure == true)
    		{
        		if(bConsoProd == 0)
        		{
        			u32Energies_jours_heures[i] = sEnergie.Prod_24J.Chaud[(i + sEnergie.Prod_24J.Pointeur + 1) % 24];
        		}
        		else u32Energies_jours_heures[i] = sEnergie.Conso_24J.Chaud[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
        		u32Energies_jours_heures_elec[i] = sEnergie.Conso_24J.ElecChaud[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
    		}
    		else
			{
        		if(bConsoProd == 0)
        		{
        			u32Energies_jours_heures[i] = sEnergie.Prod_24H.Chaud[(i + sEnergie.Prod_24H.Pointeur + 1) % 24];
        		}
        		else u32Energies_jours_heures[i] = sEnergie.Conso_24H.Chaud[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
        		u32Energies_jours_heures_elec[i] = sEnergie.Conso_24H.ElecChaud[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
			}
    	}
    	else if(toggleButton_froid.getState())
    	{
    		if(bJourHeure == true)
    		{
    			if(bConsoProd == 0)
				{
					u32Energies_jours_heures[i] = sEnergie.Prod_24J.Froid[(i + sEnergie.Prod_24J.Pointeur + 1) % 24];
				}
				else u32Energies_jours_heures[i] = sEnergie.Conso_24J.Froid[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
    		}
    		else
    		{
    			if(bConsoProd == 0)
				{
					u32Energies_jours_heures[i] = sEnergie.Prod_24H.Froid[(i + sEnergie.Prod_24H.Pointeur + 1) % 24];
				}
				else u32Energies_jours_heures[i] = sEnergie.Conso_24H.Froid[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
    		}
			u32Energies_jours_heures_elec[i] = 0;
    	}
    	else if(toggleButton_ecs.getState())
    	{
    		if(bJourHeure == true)
    		{
    			if(bConsoProd == 0)
				{
					u32Energies_jours_heures[i] = sEnergie.Prod_24J.ECS[(i + sEnergie.Prod_24J.Pointeur + 1) % 24];
				}
				else u32Energies_jours_heures[i] = sEnergie.Conso_24J.ECS[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
    			u32Energies_jours_heures_elec[i] = sEnergie.Conso_24J.ElecECS[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
    		}
    		else
    		{
    			if(bConsoProd == 0)
				{
					u32Energies_jours_heures[i] = sEnergie.Prod_24H.ECS[(i + sEnergie.Prod_24H.Pointeur + 1) % 24];
				}
				else u32Energies_jours_heures[i] = sEnergie.Conso_24H.ECS[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
    			u32Energies_jours_heures_elec[i] = sEnergie.Conso_24H.ElecECS[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
    		}
    	}
    	else
    	{
    		if(bJourHeure == true)
    		{
    			if(bConsoProd == 0)
				{
					u32Energies_jours_heures[i] = sEnergie.Prod_24J.Piscine[(i + sEnergie.Prod_24J.Pointeur + 1) % 24];
				}
				else u32Energies_jours_heures[i] = sEnergie.Conso_24J.Piscine[(i + sEnergie.Conso_24J.Pointeur + 1) % 24];
    		}
    		else
    		{
    			if(bConsoProd == 0)
				{
					u32Energies_jours_heures[i] = sEnergie.Prod_24H.Piscine[(i + sEnergie.Prod_24H.Pointeur + 1) % 24];
				}
				else u32Energies_jours_heures[i] = sEnergie.Conso_24H.Piscine[(i + sEnergie.Conso_24H.Pointeur + 1) % 24];
    		}
    		u32Energies_jours_heures_elec[i] = 0;
    	}
    	// Sauvegarde du max
		if(u32Energies_jours_heures[i] > u32ValeurMax)
		{
			u32ValeurMax = u32Energies_jours_heures[i] + 10;
		}
    }
	// Modification des labels de graduation
    Unicode::snprintf(textAreaBuffer_value_1, 7, "%d", (u32ValeurMax / 5));
    textArea_energies_cumul_1.setWildcard(textAreaBuffer_value_1);
    textArea_energies_cumul_1.invalidate();
    Unicode::snprintf(textAreaBuffer_value_2, 7, "%d", (u32ValeurMax / 5) * 2);
    textArea_energies_cumul_2.setWildcard(textAreaBuffer_value_2);
    textArea_energies_cumul_2.invalidate();
    Unicode::snprintf(textAreaBuffer_value_3, 7, "%d", (u32ValeurMax / 5) * 3);
    textArea_energies_cumul_3.setWildcard(textAreaBuffer_value_3);
    textArea_energies_cumul_3.invalidate();
    Unicode::snprintf(textAreaBuffer_value_4, 7, "%d", (u32ValeurMax / 5) * 4);
    textArea_energies_cumul_4.setWildcard(textAreaBuffer_value_4);
    textArea_energies_cumul_4.invalidate();
    Unicode::snprintf(textAreaBuffer_value_5, 7, "%d", (u32ValeurMax / 5) * 5);
    textArea_energies_cumul_5.setWildcard(textAreaBuffer_value_5);
    textArea_energies_cumul_5.invalidate();
    // Modification des barres
	box_24_1.setHeight(u32Energies_jours_heures[0] * 294 / u32ValeurMax);
	box_24_1.setY(294 - box_24_1.getHeight());
	box_24_1.invalidate();
	box_24_1_elec.setHeight(u32Energies_jours_heures_elec[0] * 294 / u32ValeurMax);
	box_24_1_elec.setY(box_24_1.getY());
	if(box_24_1.getHeight() > box_24_1_elec.getHeight())
	{
		box_24_1_elec.setVisible(true);
	}
	else box_24_1_elec.setVisible(false);
	box_24_1_elec.invalidate();
	box_24_2.setHeight(u32Energies_jours_heures[1] * 294 / u32ValeurMax);
	box_24_2.setY(294 - box_24_2.getHeight());
	box_24_2.invalidate();
	box_24_2_elec.setHeight(u32Energies_jours_heures_elec[1] * 294 / u32ValeurMax);
	box_24_2_elec.setY(box_24_2.getY());
	if(box_24_2.getHeight() > box_24_2_elec.getHeight())
	{
		box_24_2_elec.setVisible(true);
	}
	else box_24_2_elec.setVisible(false);
	box_24_2_elec.invalidate();
	box_24_3.setHeight(u32Energies_jours_heures[2] * 294 / u32ValeurMax);
	box_24_3.setY(294 - box_24_3.getHeight());
	box_24_3.invalidate();
	box_24_3_elec.setHeight(u32Energies_jours_heures_elec[2] * 294 / u32ValeurMax);
	box_24_3_elec.setY(box_24_3.getY());
	if(box_24_3.getHeight() > box_24_3_elec.getHeight())
	{
		box_24_3_elec.setVisible(true);
	}
	else box_24_3_elec.setVisible(false);
	box_24_3_elec.invalidate();
	box_24_4.setHeight(u32Energies_jours_heures[3] * 294 / u32ValeurMax);
	box_24_4.setY(294 - box_24_4.getHeight());
	box_24_4.invalidate();
	box_24_4_elec.setHeight(u32Energies_jours_heures_elec[3] * 294 / u32ValeurMax);
	box_24_4_elec.setY(box_24_4.getY());
	if(box_24_4.getHeight() > box_24_4_elec.getHeight())
	{
		box_24_4_elec.setVisible(true);
	}
	else box_24_4_elec.setVisible(false);
	box_24_4_elec.invalidate();
	box_24_5.setHeight(u32Energies_jours_heures[4] * 294 / u32ValeurMax);
	box_24_5.setY(294 - box_24_5.getHeight());
	box_24_5.invalidate();
	box_24_5_elec.setHeight(u32Energies_jours_heures_elec[4] * 294 / u32ValeurMax);
	box_24_5_elec.setY(box_24_5.getY());
	if(box_24_5.getHeight() > box_24_5_elec.getHeight())
	{
		box_24_5_elec.setVisible(true);
	}
	else box_24_5_elec.setVisible(false);
	box_24_5_elec.invalidate();
	box_24_6.setHeight(u32Energies_jours_heures[5] * 294 / u32ValeurMax);
	box_24_6.setY(294 - box_24_6.getHeight());
	box_24_6.invalidate();
	box_24_6_elec.setHeight(u32Energies_jours_heures_elec[5] * 294 / u32ValeurMax);
	box_24_6_elec.setY(box_24_6.getY());
	if(box_24_6.getHeight() > box_24_6_elec.getHeight())
	{
		box_24_6_elec.setVisible(true);
	}
	else box_24_6_elec.setVisible(false);
	box_24_6_elec.invalidate();
	box_24_7.setHeight(u32Energies_jours_heures[6] * 294 / u32ValeurMax);
	box_24_7.setY(294 - box_24_7.getHeight());
	box_24_7.invalidate();
	box_24_7_elec.setHeight(u32Energies_jours_heures_elec[0] * 294 / u32ValeurMax);
	box_24_7_elec.setY(box_24_7.getY());
	if(box_24_7.getHeight() > box_24_7_elec.getHeight())
	{
		box_24_7_elec.setVisible(true);
	}
	else box_24_7_elec.setVisible(false);
	box_24_7_elec.invalidate();
	box_24_8.setHeight(u32Energies_jours_heures[7] * 294 / u32ValeurMax);
	box_24_8.setY(294 - box_24_8.getHeight());
	box_24_8.invalidate();
	box_24_8_elec.setHeight(u32Energies_jours_heures_elec[7] * 294 / u32ValeurMax);
	box_24_8_elec.setY(box_24_8.getY());
	if(box_24_8.getHeight() > box_24_8_elec.getHeight())
	{
		box_24_8_elec.setVisible(true);
	}
	else box_24_8_elec.setVisible(false);
	box_24_8_elec.invalidate();
	box_24_9.setHeight(u32Energies_jours_heures[8] * 294 / u32ValeurMax);
	box_24_9.setY(294 - box_24_9.getHeight());
	box_24_9.invalidate();
	box_24_9_elec.setHeight(u32Energies_jours_heures_elec[8] * 294 / u32ValeurMax);
	box_24_9_elec.setY(box_24_9.getY());
	if(box_24_9.getHeight() > box_24_9_elec.getHeight())
	{
		box_24_9_elec.setVisible(true);
	}
	else box_24_9_elec.setVisible(false);
	box_24_9_elec.invalidate();
	box_24_10.setHeight(u32Energies_jours_heures[9] * 294 / u32ValeurMax);
	box_24_10.setY(294 - box_24_10.getHeight());
	box_24_10.invalidate();
	box_24_10_elec.setHeight(u32Energies_jours_heures_elec[9] * 294 / u32ValeurMax);
	box_24_10_elec.setY(box_24_10.getY());
	if(box_24_10.getHeight() > box_24_10_elec.getHeight())
	{
		box_24_10_elec.setVisible(true);
	}
	else box_24_10_elec.setVisible(false);
	box_24_10_elec.invalidate();
	box_24_11.setHeight(u32Energies_jours_heures[10] * 294 / u32ValeurMax);
	box_24_11.setY(294 - box_24_11.getHeight());
	box_24_11.invalidate();
	box_24_11_elec.setHeight(u32Energies_jours_heures_elec[10] * 294 / u32ValeurMax);
	box_24_11_elec.setY(box_24_11.getY());
	if(box_24_11.getHeight() > box_24_11_elec.getHeight())
	{
		box_24_11_elec.setVisible(true);
	}
	else box_24_11_elec.setVisible(false);
	box_24_11_elec.invalidate();
	box_24_12.setHeight(u32Energies_jours_heures[11] * 294 / u32ValeurMax);
	box_24_12.setY(294 - box_24_12.getHeight());
	box_24_12.invalidate();
	box_24_12_elec.setHeight(u32Energies_jours_heures_elec[11] * 294 / u32ValeurMax);
	box_24_12_elec.setY(box_24_12.getY());
	if(box_24_12.getHeight() > box_24_12_elec.getHeight())
	{
		box_24_12_elec.setVisible(true);
	}
	else box_24_12_elec.setVisible(false);
	box_24_12_elec.invalidate();
	box_24_13.setHeight(u32Energies_jours_heures[12] * 294 / u32ValeurMax);
	box_24_13.setY(294 - box_24_13.getHeight());
	box_24_13.invalidate();
	box_24_13_elec.setHeight(u32Energies_jours_heures_elec[12] * 294 / u32ValeurMax);
	box_24_13_elec.setY(box_24_13.getY());
	if(box_24_13.getHeight() > box_24_13_elec.getHeight())
	{
		box_24_13_elec.setVisible(true);
	}
	else box_24_13_elec.setVisible(false);
	box_24_13_elec.invalidate();
	box_24_14.setHeight(u32Energies_jours_heures[13] * 294 / u32ValeurMax);
	box_24_14.setY(294 - box_24_14.getHeight());
	box_24_14.invalidate();
	box_24_14_elec.setHeight(u32Energies_jours_heures_elec[13] * 294 / u32ValeurMax);
	box_24_14_elec.setY(box_24_14.getY());
	if(box_24_14.getHeight() > box_24_14_elec.getHeight())
	{
		box_24_14_elec.setVisible(true);
	}
	else box_24_14_elec.setVisible(false);
	box_24_13_elec.invalidate();
	box_24_15.setHeight(u32Energies_jours_heures[14] * 294 / u32ValeurMax);
	box_24_15.setY(294 - box_24_15.getHeight());
	box_24_15.invalidate();
	box_24_15_elec.setHeight(u32Energies_jours_heures_elec[14] * 294 / u32ValeurMax);
	box_24_15_elec.setY(box_24_15.getY());
	if(box_24_15.getHeight() > box_24_15_elec.getHeight())
	{
		box_24_15_elec.setVisible(true);
	}
	else box_24_15_elec.setVisible(false);
	box_24_15_elec.invalidate();
	box_24_16.setHeight(u32Energies_jours_heures[15] * 294 / u32ValeurMax);
	box_24_16.setY(294 - box_24_16.getHeight());
	box_24_16.invalidate();
	box_24_16_elec.setHeight(u32Energies_jours_heures_elec[15] * 294 / u32ValeurMax);
	box_24_16_elec.setY(box_24_16.getY());
	if(box_24_16.getHeight() > box_24_16_elec.getHeight())
	{
		box_24_16_elec.setVisible(true);
	}
	else box_24_16_elec.setVisible(false);
	box_24_16_elec.invalidate();
	box_24_17.setHeight(u32Energies_jours_heures[16] * 294 / u32ValeurMax);
	box_24_17.setY(294 - box_24_17.getHeight());
	box_24_17.invalidate();
	box_24_17_elec.setHeight(u32Energies_jours_heures_elec[16] * 294 / u32ValeurMax);
	box_24_17_elec.setY(box_24_17.getY());
	if(box_24_17.getHeight() > box_24_17_elec.getHeight())
	{
		box_24_17_elec.setVisible(true);
	}
	else box_24_17_elec.setVisible(false);
	box_24_17_elec.invalidate();
	box_24_18.setHeight(u32Energies_jours_heures[17] * 294 / u32ValeurMax);
	box_24_18.setY(294 - box_24_18.getHeight());
	box_24_18.invalidate();
	box_24_18_elec.setHeight(u32Energies_jours_heures_elec[17] * 294 / u32ValeurMax);
	box_24_18_elec.setY(box_24_18.getY());
	if(box_24_18.getHeight() > box_24_18_elec.getHeight())
	{
		box_24_18_elec.setVisible(true);
	}
	else box_24_18_elec.setVisible(false);
	box_24_18_elec.invalidate();
	box_24_19.setHeight(u32Energies_jours_heures[18] * 294 / u32ValeurMax);
	box_24_19.setY(294 - box_24_19.getHeight());
	box_24_19.invalidate();
	box_24_19_elec.setHeight(u32Energies_jours_heures_elec[18] * 294 / u32ValeurMax);
	box_24_19_elec.setY(box_24_19.getY());
	if(box_24_19.getHeight() > box_24_19_elec.getHeight())
	{
		box_24_19_elec.setVisible(true);
	}
	else box_24_19_elec.setVisible(false);
	box_24_19_elec.invalidate();
	box_24_20.setHeight(u32Energies_jours_heures[19] * 294 / u32ValeurMax);
	box_24_20.setY(294 - box_24_20.getHeight());
	box_24_20.invalidate();
	box_24_20_elec.setHeight(u32Energies_jours_heures_elec[19] * 294 / u32ValeurMax);
	box_24_20_elec.setY(box_24_20.getY());
	if(box_24_20.getHeight() > box_24_20_elec.getHeight())
	{
		box_24_20_elec.setVisible(true);
	}
	else box_24_20_elec.setVisible(false);
	box_24_20_elec.invalidate();
	box_24_21.setHeight(u32Energies_jours_heures[20] * 294 / u32ValeurMax);
	box_24_21.setY(294 - box_24_21.getHeight());
	box_24_21.invalidate();
	box_24_21_elec.setHeight(u32Energies_jours_heures_elec[20] * 294 / u32ValeurMax);
	box_24_21_elec.setY(box_24_21.getY());
	if(box_24_21.getHeight() > box_24_21_elec.getHeight())
	{
		box_24_21_elec.setVisible(true);
	}
	else box_24_21_elec.setVisible(false);
	box_24_21_elec.invalidate();
	box_24_22.setHeight(u32Energies_jours_heures[21] * 294 / u32ValeurMax);
	box_24_22.setY(294 - box_24_22.getHeight());
	box_24_22.invalidate();
	box_24_22_elec.setHeight(u32Energies_jours_heures_elec[21] * 294 / u32ValeurMax);
	box_24_22_elec.setY(box_24_22.getY());
	if(box_24_22.getHeight() > box_24_22_elec.getHeight())
	{
		box_24_22_elec.setVisible(true);
	}
	else box_24_22_elec.setVisible(false);
	box_24_22_elec.invalidate();
	box_24_23.setHeight(u32Energies_jours_heures[22] * 294 / u32ValeurMax);
	box_24_23.setY(294 - box_24_23.getHeight());
	box_24_23.invalidate();
	box_24_23_elec.setHeight(u32Energies_jours_heures_elec[22] * 294 / u32ValeurMax);
	box_24_23_elec.setY(box_24_23.getY());
	if(box_24_23.getHeight() > box_24_23_elec.getHeight())
	{
		box_24_23_elec.setVisible(true);
	}
	else box_24_23_elec.setVisible(false);
	box_24_23_elec.invalidate();
	box_24_24.setHeight(u32Energies_jours_heures[23] * 294 / u32ValeurMax);
	box_24_24.setY(294 - box_24_24.getHeight());
	box_24_24.invalidate();
	box_24_24_elec.setHeight(u32Energies_jours_heures_elec[23] * 294 / u32ValeurMax);
	box_24_24_elec.setY(box_24_24.getY());
	if(box_24_24.getHeight() > box_24_24_elec.getHeight())
	{
		box_24_24_elec.setVisible(true);
	}
	else box_24_24_elec.setVisible(false);
	box_24_24_elec.invalidate();
}

void Energies_histoView::jours(uint8_t u8Jours, uint8_t u8Mois, uint8_t u8Annee)
{
	uint8_t u8NbJoursMois = 31;
	// Nombre de jours par mois
	if(u8Mois == 0 || u8Mois == 1 || u8Mois == 3 || u8Mois == 5 || u8Mois == 7 || u8Mois == 8 || u8Mois == 10 || u8Mois == 12)
	{
		u8NbJoursMois = 31;
	}
	else if(u8Mois == 4 || u8Mois == 6 || u8Mois == 9 || u8Mois == 11)
	{
		u8NbJoursMois = 30;
	}
	else
	{
		if((u8Annee % 4 == 0 && u8Annee % 100 != 0) || u8Annee % 400 == 0)
		{
			u8NbJoursMois = 29;	// Année bisextile
		}
		else u8NbJoursMois = 28;
	}
	// u8Jours de 0 à 30
    Unicode::snprintf(textAreaBuffer_1, 3, "%d", ((u8Jours + u8NbJoursMois - 23) % u8NbJoursMois) + 1);
    textArea_chiffre_1.setWildcard(textAreaBuffer_1);
    textArea_chiffre_1.invalidate();
    Unicode::snprintf(textAreaBuffer_2, 3, "%d", ((u8Jours + u8NbJoursMois - 22) % u8NbJoursMois) + 1);
    textArea_chiffre_2.setWildcard(textAreaBuffer_2);
    textArea_chiffre_2.invalidate();
    Unicode::snprintf(textAreaBuffer_3, 3, "%d", ((u8Jours + u8NbJoursMois - 21) % u8NbJoursMois) + 1);
    textArea_chiffre_3.setWildcard(textAreaBuffer_3);
    textArea_chiffre_3.invalidate();
    Unicode::snprintf(textAreaBuffer_4, 3, "%d", ((u8Jours + u8NbJoursMois - 20) % u8NbJoursMois) + 1);
    textArea_chiffre_4.setWildcard(textAreaBuffer_4);
    textArea_chiffre_4.invalidate();
    Unicode::snprintf(textAreaBuffer_5, 3, "%d", ((u8Jours + u8NbJoursMois - 19) % u8NbJoursMois) + 1);
    textArea_chiffre_5.setWildcard(textAreaBuffer_5);
    textArea_chiffre_5.invalidate();
    Unicode::snprintf(textAreaBuffer_6, 3, "%d", ((u8Jours + u8NbJoursMois - 18) % u8NbJoursMois) + 1);
    textArea_chiffre_6.setWildcard(textAreaBuffer_6);
    textArea_chiffre_6.invalidate();
    Unicode::snprintf(textAreaBuffer_7, 3, "%d", ((u8Jours + u8NbJoursMois - 17) % u8NbJoursMois) + 1);
    textArea_chiffre_7.setWildcard(textAreaBuffer_7);
    textArea_chiffre_7.invalidate();
    Unicode::snprintf(textAreaBuffer_8, 3, "%d", ((u8Jours + u8NbJoursMois - 16) % u8NbJoursMois) + 1);
    textArea_chiffre_8.setWildcard(textAreaBuffer_8);
    textArea_chiffre_8.invalidate();
    Unicode::snprintf(textAreaBuffer_9, 3, "%d", ((u8Jours + u8NbJoursMois - 15) % u8NbJoursMois) + 1);
    textArea_chiffre_9.setWildcard(textAreaBuffer_9);
    textArea_chiffre_9.invalidate();
    Unicode::snprintf(textAreaBuffer_10, 3, "%d", ((u8Jours + u8NbJoursMois - 14) % u8NbJoursMois) + 1);
    textArea_chiffre_10.setWildcard(textAreaBuffer_10);
    textArea_chiffre_10.invalidate();
    Unicode::snprintf(textAreaBuffer_11, 3, "%d", ((u8Jours + u8NbJoursMois - 13) % u8NbJoursMois) + 1);
    textArea_chiffre_11.setWildcard(textAreaBuffer_11);
    textArea_chiffre_11.invalidate();
    Unicode::snprintf(textAreaBuffer_12, 3, "%d", ((u8Jours + u8NbJoursMois - 12) % u8NbJoursMois) + 1);
    textArea_chiffre_12.setWildcard(textAreaBuffer_12);
    textArea_chiffre_12.invalidate();
    Unicode::snprintf(textAreaBuffer_13, 3, "%d", ((u8Jours + u8NbJoursMois - 11) % u8NbJoursMois) + 1);
    textArea_chiffre_13.setWildcard(textAreaBuffer_13);
    textArea_chiffre_13.invalidate();
    Unicode::snprintf(textAreaBuffer_14, 3, "%d", ((u8Jours + u8NbJoursMois - 10) % u8NbJoursMois) + 1);
    textArea_chiffre_14.setWildcard(textAreaBuffer_14);
    textArea_chiffre_14.invalidate();
    Unicode::snprintf(textAreaBuffer_15, 3, "%d", ((u8Jours + u8NbJoursMois - 9) % u8NbJoursMois) + 1);
    textArea_chiffre_15.setWildcard(textAreaBuffer_15);
    textArea_chiffre_15.invalidate();
    Unicode::snprintf(textAreaBuffer_16, 3, "%d", ((u8Jours + u8NbJoursMois - 8) % u8NbJoursMois) + 1);
    textArea_chiffre_16.setWildcard(textAreaBuffer_16);
    textArea_chiffre_16.invalidate();
    Unicode::snprintf(textAreaBuffer_17, 3, "%d", ((u8Jours + u8NbJoursMois - 7) % u8NbJoursMois) + 1);
    textArea_chiffre_17.setWildcard(textAreaBuffer_17);
    textArea_chiffre_17.invalidate();
    Unicode::snprintf(textAreaBuffer_18, 3, "%d", ((u8Jours + u8NbJoursMois - 6) % u8NbJoursMois) + 1);
    textArea_chiffre_18.setWildcard(textAreaBuffer_18);
    textArea_chiffre_18.invalidate();
    Unicode::snprintf(textAreaBuffer_19, 3, "%d", ((u8Jours + u8NbJoursMois - 5) % u8NbJoursMois) + 1);
    textArea_chiffre_19.setWildcard(textAreaBuffer_19);
    textArea_chiffre_19.invalidate();
    Unicode::snprintf(textAreaBuffer_20, 3, "%d", ((u8Jours + u8NbJoursMois - 4) % u8NbJoursMois) + 1);
    textArea_chiffre_20.setWildcard(textAreaBuffer_20);
    textArea_chiffre_20.invalidate();
    Unicode::snprintf(textAreaBuffer_21, 3, "%d", ((u8Jours + u8NbJoursMois - 3) % u8NbJoursMois) + 1);
    textArea_chiffre_21.setWildcard(textAreaBuffer_21);
    textArea_chiffre_21.invalidate();
    Unicode::snprintf(textAreaBuffer_22, 3, "%d", ((u8Jours + u8NbJoursMois - 2) % u8NbJoursMois) + 1);
    textArea_chiffre_22.setWildcard(textAreaBuffer_22);
    textArea_chiffre_22.invalidate();
    Unicode::snprintf(textAreaBuffer_23, 3, "%d", ((u8Jours + u8NbJoursMois - 1) % u8NbJoursMois) + 1);
    textArea_chiffre_23.setWildcard(textAreaBuffer_23);
    textArea_chiffre_23.invalidate();
    Unicode::snprintf(textAreaBuffer_24, 3, "%d", ((u8Jours + u8NbJoursMois) % u8NbJoursMois) + 1);
    textArea_chiffre_24.setWildcard(textAreaBuffer_24);
    textArea_chiffre_24.invalidate();
}

void Energies_histoView::heures(uint8_t u8Heure)
{
    Unicode::snprintf(textAreaBuffer_1, 3, "%d", (u8Heure + 1) % 24);
    textArea_chiffre_1.setWildcard(textAreaBuffer_1);
    textArea_chiffre_1.invalidate();
    Unicode::snprintf(textAreaBuffer_2, 3, "%d", (u8Heure + 2) % 24);
    textArea_chiffre_2.setWildcard(textAreaBuffer_2);
    textArea_chiffre_2.invalidate();
    Unicode::snprintf(textAreaBuffer_3, 3, "%d", (u8Heure + 3) % 24);
    textArea_chiffre_3.setWildcard(textAreaBuffer_3);
    textArea_chiffre_3.invalidate();
    Unicode::snprintf(textAreaBuffer_3, 3, "%d", (u8Heure + 3) % 24);
    textArea_chiffre_3.setWildcard(textAreaBuffer_3);
    textArea_chiffre_3.invalidate();
    Unicode::snprintf(textAreaBuffer_4, 3, "%d", (u8Heure + 4) % 24);
    textArea_chiffre_4.setWildcard(textAreaBuffer_4);
    textArea_chiffre_4.invalidate();
    Unicode::snprintf(textAreaBuffer_5, 3, "%d", (u8Heure + 5) % 24);
    textArea_chiffre_5.setWildcard(textAreaBuffer_5);
    textArea_chiffre_5.invalidate();
    Unicode::snprintf(textAreaBuffer_6, 3, "%d", (u8Heure + 6) % 24);
    textArea_chiffre_6.setWildcard(textAreaBuffer_6);
    textArea_chiffre_6.invalidate();
    Unicode::snprintf(textAreaBuffer_7, 3, "%d", (u8Heure + 7) % 24);
    textArea_chiffre_7.setWildcard(textAreaBuffer_7);
    textArea_chiffre_7.invalidate();
    Unicode::snprintf(textAreaBuffer_8, 3, "%d", (u8Heure + 8) % 24);
    textArea_chiffre_8.setWildcard(textAreaBuffer_8);
    textArea_chiffre_8.invalidate();
    Unicode::snprintf(textAreaBuffer_9, 3, "%d", (u8Heure + 9) % 24);
    textArea_chiffre_9.setWildcard(textAreaBuffer_9);
    textArea_chiffre_9.invalidate();
    Unicode::snprintf(textAreaBuffer_10, 3, "%d", (u8Heure + 10) % 24);
    textArea_chiffre_10.setWildcard(textAreaBuffer_10);
    textArea_chiffre_10.invalidate();
    Unicode::snprintf(textAreaBuffer_11, 3, "%d", (u8Heure + 11) % 24);
    textArea_chiffre_11.setWildcard(textAreaBuffer_11);
    textArea_chiffre_11.invalidate();
    Unicode::snprintf(textAreaBuffer_12, 3, "%d", (u8Heure + 12) % 24);
    textArea_chiffre_12.setWildcard(textAreaBuffer_12);
    textArea_chiffre_12.invalidate();
    Unicode::snprintf(textAreaBuffer_13, 3, "%d", (u8Heure + 13) % 24);
    textArea_chiffre_13.setWildcard(textAreaBuffer_13);
    textArea_chiffre_13.invalidate();
    Unicode::snprintf(textAreaBuffer_14, 3, "%d", (u8Heure + 14) % 24);
    textArea_chiffre_14.setWildcard(textAreaBuffer_14);
    textArea_chiffre_14.invalidate();
    Unicode::snprintf(textAreaBuffer_15, 3, "%d", (u8Heure + 15) % 24);
    textArea_chiffre_15.setWildcard(textAreaBuffer_15);
    textArea_chiffre_15.invalidate();
    Unicode::snprintf(textAreaBuffer_16, 3, "%d", (u8Heure + 16) % 24);
    textArea_chiffre_16.setWildcard(textAreaBuffer_16);
    textArea_chiffre_16.invalidate();
    Unicode::snprintf(textAreaBuffer_17, 3, "%d", (u8Heure + 17) % 24);
    textArea_chiffre_17.setWildcard(textAreaBuffer_17);
    textArea_chiffre_17.invalidate();
    Unicode::snprintf(textAreaBuffer_18, 3, "%d", (u8Heure + 18) % 24);
    textArea_chiffre_18.setWildcard(textAreaBuffer_18);
    textArea_chiffre_18.invalidate();
    Unicode::snprintf(textAreaBuffer_19, 3, "%d", (u8Heure + 19) % 24);
    textArea_chiffre_19.setWildcard(textAreaBuffer_19);
    textArea_chiffre_19.invalidate();
    Unicode::snprintf(textAreaBuffer_20, 3, "%d", (u8Heure + 20) % 24);
    textArea_chiffre_20.setWildcard(textAreaBuffer_20);
    textArea_chiffre_20.invalidate();
    Unicode::snprintf(textAreaBuffer_21, 3, "%d", (u8Heure + 21) % 24);
    textArea_chiffre_21.setWildcard(textAreaBuffer_21);
    textArea_chiffre_21.invalidate();
    Unicode::snprintf(textAreaBuffer_22, 3, "%d", (u8Heure + 22) % 24);
    textArea_chiffre_22.setWildcard(textAreaBuffer_22);
    textArea_chiffre_22.invalidate();
    Unicode::snprintf(textAreaBuffer_23, 3, "%d", (u8Heure + 23) % 24);
    textArea_chiffre_23.setWildcard(textAreaBuffer_23);
    textArea_chiffre_23.invalidate();
    Unicode::snprintf(textAreaBuffer_24, 3, "%d", (u8Heure + 24) % 24);
    textArea_chiffre_24.setWildcard(textAreaBuffer_24);
    textArea_chiffre_24.invalidate();
}

void Energies_histoView::couleur_barres(uint32_t u32Couleur)
{
  box_mois_1.setColor(u32Couleur);
  box_mois_1.invalidate();
  box_mois_2.setColor(u32Couleur);
  box_mois_2.invalidate();
  box_mois_3.setColor(u32Couleur);
  box_mois_3.invalidate();
  box_mois_4.setColor(u32Couleur);
  box_mois_4.invalidate();
  box_mois_5.setColor(u32Couleur);
  box_mois_5.invalidate();
  box_mois_6.setColor(u32Couleur);
  box_mois_6.invalidate();
  box_mois_7.setColor(u32Couleur);
  box_mois_7.invalidate();
  box_mois_8.setColor(u32Couleur);
  box_mois_8.invalidate();
  box_mois_9.setColor(u32Couleur);
  box_mois_9.invalidate();
  box_mois_10.setColor(u32Couleur);
  box_mois_10.invalidate();
  box_mois_11.setColor(u32Couleur);
  box_mois_11.invalidate();
  box_mois_12.setColor(u32Couleur);
  box_mois_12.invalidate();
  box_24_1.setColor(u32Couleur);
  box_24_1.invalidate();
  box_24_2.setColor(u32Couleur);
  box_24_2.invalidate();
  box_24_3.setColor(u32Couleur);
  box_24_3.invalidate();
  box_24_4.setColor(u32Couleur);
  box_24_4.invalidate();
  box_24_5.setColor(u32Couleur);
  box_24_5.invalidate();
  box_24_6.setColor(u32Couleur);
  box_24_6.invalidate();
  box_24_7.setColor(u32Couleur);
  box_24_7.invalidate();
  box_24_8.setColor(u32Couleur);
  box_24_8.invalidate();
  box_24_9.setColor(u32Couleur);
  box_24_9.invalidate();
  box_24_10.setColor(u32Couleur);
  box_24_10.invalidate();
  box_24_11.setColor(u32Couleur);
  box_24_11.invalidate();
  box_24_12.setColor(u32Couleur);
  box_24_12.invalidate();
  box_24_13.setColor(u32Couleur);
  box_24_13.invalidate();
  box_24_14.setColor(u32Couleur);
  box_24_14.invalidate();
  box_24_15.setColor(u32Couleur);
  box_24_15.invalidate();
  box_24_16.setColor(u32Couleur);
  box_24_16.invalidate();
  box_24_17.setColor(u32Couleur);
  box_24_17.invalidate();
  box_24_18.setColor(u32Couleur);
  box_24_18.invalidate();
  box_24_19.setColor(u32Couleur);
  box_24_19.invalidate();
  box_24_20.setColor(u32Couleur);
  box_24_20.invalidate();
  box_24_21.setColor(u32Couleur);
  box_24_21.invalidate();
  box_24_22.setColor(u32Couleur);
  box_24_22.invalidate();
  box_24_23.setColor(u32Couleur);
  box_24_23.invalidate();
  box_24_24.setColor(u32Couleur);
  box_24_24.invalidate();
}

void Energies_histoView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Energies_histoView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Energies_histoView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Energies_histoView::changeDate(S_DATE *sDate)
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
