#include <gui/vacances_screen/VacancesView.hpp>

VacancesView::VacancesView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	u8NbBoutons = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Init du nombre de jours
	if(sStatut_PAC.u8CTime_Vacances != 0)
	{
		u8NbJoursVacances = sStatut_PAC.u8CTime_Vacances;
	}
	else u8NbJoursVacances = sConfig_IHM.sParam_PAC.u8Time_Vacances;
	Unicode::snprintf(textAreaBuffer_NbJours, 3, "%d", u8NbJoursVacances);
	textArea_valeur_nb_jours_absence.setWildcard(textAreaBuffer_NbJours);
	// Vacances on ?
	if(sConfig_IHM.sMode_ECS.Exception == VACANCES)
	{
		toggleButton_oui_oui_non_vacances.forceState(true);
		toggleButton_oui_oui_non_vacances.setTouchable(false);
		toggleButton_non_oui_non_vacances.forceState(false);
		toggleButton_non_oui_non_vacances.setTouchable(true);
	}
	else
	{
		toggleButton_non_oui_non_vacances.forceState(true);
		toggleButton_non_oui_non_vacances.setTouchable(false);
		toggleButton_oui_oui_non_vacances.forceState(false);
		toggleButton_oui_oui_non_vacances.setTouchable(true);
	}
	// Nombre de boutons
	if(sConfig_IHM.sOption_PAC.sZone.bZone1)
	{
	    affichageZone(0, &container_zone_1, &toggleButton_zone_1, &container_slider_zone_1, &textArea_vacances_zone_1, textAreaBuffer_Zone1, textAreaBuffer_TempZone1, &slider_zone_1, &textArea_zone_1);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone2)
	{
	    affichageZone(1, &container_zone_2, &toggleButton_zone_2, &container_slider_zone_2, &textArea_vacances_zone_2, textAreaBuffer_Zone2, textAreaBuffer_TempZone2, &slider_zone_2, &textArea_zone_2);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone3)
	{
	    affichageZone(2, &container_zone_3, &toggleButton_zone_3, &container_slider_zone_3, &textArea_vacances_zone_3, textAreaBuffer_Zone3, textAreaBuffer_TempZone3, &slider_zone_3, &textArea_zone_3);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone4)
	{
	    affichageZone(3, &container_zone_4, &toggleButton_zone_4, &container_slider_zone_4, &textArea_vacances_zone_4, textAreaBuffer_Zone4, textAreaBuffer_TempZone4, &slider_zone_4, &textArea_zone_4);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone5)
	{
	    affichageZone(4, &container_zone_5, &toggleButton_zone_5, &container_slider_zone_5, &textArea_vacances_zone_5, textAreaBuffer_Zone5, textAreaBuffer_TempZone5, &slider_zone_5, &textArea_zone_5);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone6)
	{
	    affichageZone(5, &container_zone_6, &toggleButton_zone_6, &container_slider_zone_6, &textArea_vacances_zone_6, textAreaBuffer_Zone6, textAreaBuffer_TempZone6, &slider_zone_6, &textArea_zone_6);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone7)
	{
	    affichageZone(6, &container_zone_7, &toggleButton_zone_7, &container_slider_zone_7, &textArea_vacances_zone_7, textAreaBuffer_Zone7, textAreaBuffer_TempZone7, &slider_zone_7, &textArea_zone_7);
	}
	if(sConfig_IHM.sOption_PAC.sZone.bZone8)
	{
	    affichageZone(7, &container_zone_8, &toggleButton_zone_8, &container_slider_zone_8, &textArea_vacances_zone_8, textAreaBuffer_Zone8, textAreaBuffer_TempZone8, &slider_zone_8, &textArea_zone_8);
	}
	if(sConfig_IHM.sOption_PAC.Piscine)
	{
		container_piscine.setVisible(true);
		container_piscine.setY(u8NbBoutons * 74);
		// Mode activé ou non
		if(sConfig_IHM.sMode_Piscine.Exception == VACANCES && sConfig_IHM.sMode_ECS.Exception == VACANCES)
		{
			toggleButton_piscine.forceState(true);
			container_slider_piscine.setVisible(true);
		}
		else
		{
			toggleButton_piscine.forceState(false);
			container_slider_piscine.setVisible(false);
			if(toggleButton_oui_oui_non_vacances.getState() == false)
			{
				toggleButton_piscine.setTouchable(false);
			}
		}
		// Position de la température
		u16ConsignePiscineTempVacances = sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Vacances;
		slider_piscine.setValue(u16ConsignePiscineTempVacances);
		Unicode::snprintfFloat(textAreaBuffer_TempPiscine, 6, "%.1f", ((float) u16ConsignePiscineTempVacances) / 10);
		textArea_piscine.moveTo((int) ((float) slider_piscine.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_piscine.getWidth() / 2 + ((float) u16ConsignePiscineTempVacances - (float) 150) * (float) 1.42), 51);
		textArea_piscine.setWildcard(textAreaBuffer_TempPiscine);

		u8NbBoutons++;
	}
	if(sConfig_IHM.sOption_PAC.ECS)
	{
		container_ecs.setVisible(true);
		container_ecs.setY(u8NbBoutons * 74);
		if(sConfig_IHM.sMode_ECS.bUserECSVacancesOFF == 0 && sConfig_IHM.sMode_ECS.Exception == VACANCES)
		{
			toggleButton_ecs.forceState(true);
		}
		else
		{
			toggleButton_ecs.forceState(false);
			if(toggleButton_oui_oui_non_vacances.getState() == false)
			{
				toggleButton_ecs.setTouchable(false);
			}
		}
		u8NbBoutons++;
	}
	text_vacances_off();
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_VACANCES_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void VacancesView::slider_pisc(int sliderValue)
{
	u16ConsignePiscineTempVacances = sliderValue;
	Unicode::snprintfFloat(textAreaBuffer_TempPiscine, 6, "%.1f", ((float) u16ConsignePiscineTempVacances) / 10);
	textArea_piscine.moveTo((int) ((float) slider_piscine.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_piscine.getWidth() / 2 + ((float) u16ConsignePiscineTempVacances - (float) 150) * (float) 1.42), 51);
	textArea_piscine.setWildcard(textAreaBuffer_TempPiscine);
	textArea_piscine.invalidate();
}

void VacancesView::text_vacances_off()
{
	if(toggleButton_piscine.getState() || toggleButton_ecs.getState() || toggleButton_zone_1.getState() || toggleButton_zone_2.getState() || toggleButton_zone_3.getState() || toggleButton_zone_4.getState() || toggleButton_zone_5.getState() || toggleButton_zone_6.getState() || toggleButton_zone_7.getState() || toggleButton_zone_8.getState())
	{
		textArea_vacances_off.setVisible(false);
	}
	else textArea_vacances_off.setVisible(true);
	textArea_vacances_off.invalidate();
}

void VacancesView::bouton_piscine()
{
	if(toggleButton_piscine.getState())
	{
		container_slider_piscine.setVisible(true);
	}
	else container_slider_piscine.setVisible(false);
	container_slider_piscine.invalidate();
	text_vacances_off();
}

void VacancesView::bouton_piscine_plus()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsignePiscineTempVacances == 400) return;

	u16ConsignePiscineTempVacances++;
	slider_piscine.setValue(u16ConsignePiscineTempVacances);
	slider_piscine.invalidate();
	Unicode::snprintfFloat(textAreaBuffer_TempPiscine, 6, "%.1f", ((float) u16ConsignePiscineTempVacances) / 10);
	textArea_piscine.moveTo((int) ((float) slider_piscine.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_piscine.getWidth() / 2 + ((float) u16ConsignePiscineTempVacances - (float) 150) * (float) 1.42), 51);
	textArea_piscine.setWildcard(textAreaBuffer_TempPiscine);
	textArea_piscine.invalidate();
}

void VacancesView::bouton_piscine_moins()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsignePiscineTempVacances == 150) return;

	u16ConsignePiscineTempVacances--;
	slider_piscine.setValue(u16ConsignePiscineTempVacances);
	slider_piscine.invalidate();
	Unicode::snprintfFloat(textAreaBuffer_TempPiscine, 6, "%.1f", ((float) u16ConsignePiscineTempVacances) / 10);
	textArea_piscine.moveTo((int) ((float) slider_piscine.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_piscine.getWidth() / 2 + ((float) u16ConsignePiscineTempVacances - (float) 150) * (float) 1.42), 51);
	textArea_piscine.setWildcard(textAreaBuffer_TempPiscine);
	textArea_piscine.invalidate();
}

void VacancesView::bouton_zone_1()
{
	bouton_zone_x(&toggleButton_zone_1, &container_slider_zone_1);
}

void VacancesView::bouton_zone_2()
{
	bouton_zone_x(&toggleButton_zone_2, &container_slider_zone_2);
}

void VacancesView::bouton_zone_3()
{
	bouton_zone_x(&toggleButton_zone_3, &container_slider_zone_3);
}

void VacancesView::bouton_zone_4()
{
	bouton_zone_x(&toggleButton_zone_4, &container_slider_zone_4);
}

void VacancesView::bouton_zone_5()
{
	bouton_zone_x(&toggleButton_zone_5, &container_slider_zone_5);
}

void VacancesView::bouton_zone_6()
{
	bouton_zone_x(&toggleButton_zone_6, &container_slider_zone_6);
}

void VacancesView::bouton_zone_7()
{
	bouton_zone_x(&toggleButton_zone_7, &container_slider_zone_7);
}

void VacancesView::bouton_zone_8()
{
	bouton_zone_x(&toggleButton_zone_8, &container_slider_zone_8);
}

void VacancesView::bouton_zone_x(touchgfx::ToggleButton *toggleButton_zone, touchgfx::Container *container_slider_zone)
{
	if(toggleButton_zone->getState())
	{
		container_slider_zone->setVisible(true);
	}
	else container_slider_zone->setVisible(false);
	container_slider_zone->invalidate();
	//
	text_vacances_off();
}

void VacancesView::slider_zone1(int sliderValue)
{
	u16ConsigneTempVacances[0] = sliderValue;
	slider_zone_x(0, &textArea_zone_1, textAreaBuffer_TempZone1);
}

void VacancesView::slider_zone2(int sliderValue)
{
	u16ConsigneTempVacances[1] = sliderValue;
	slider_zone_x(1, &textArea_zone_2, textAreaBuffer_TempZone2);
}

void VacancesView::slider_zone3(int sliderValue)
{
	u16ConsigneTempVacances[2] = sliderValue;
	slider_zone_x(2, &textArea_zone_3, textAreaBuffer_TempZone3);
}

void VacancesView::slider_zone4(int sliderValue)
{
	u16ConsigneTempVacances[3] = sliderValue;
	slider_zone_x(3, &textArea_zone_4, textAreaBuffer_TempZone4);
}

void VacancesView::slider_zone5(int sliderValue)
{
	u16ConsigneTempVacances[4] = sliderValue;
	slider_zone_x(4, &textArea_zone_5, textAreaBuffer_TempZone5);
}

void VacancesView::slider_zone6(int sliderValue)
{
	u16ConsigneTempVacances[5] = sliderValue;
	slider_zone_x(5, &textArea_zone_6, textAreaBuffer_TempZone6);
}

void VacancesView::slider_zone7(int sliderValue)
{
	u16ConsigneTempVacances[6] = sliderValue;
	slider_zone_x(6, &textArea_zone_7, textAreaBuffer_TempZone7);
}

void VacancesView::slider_zone8(int sliderValue)
{
	u16ConsigneTempVacances[7] = sliderValue;
	slider_zone_x(7, &textArea_zone_8, textAreaBuffer_TempZone8);
}

void VacancesView::slider_zone_x(uint8_t u8Zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone)
{
	Unicode::snprintfFloat(textAreaBuffer_TempZone, 6, "%.1f", ((float) u16ConsigneTempVacances[u8Zone]) / 10);
	textArea_zone->moveTo((int) ((float) slider_zone_1.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_zone->getWidth() / 2 + ((float) u16ConsigneTempVacances[u8Zone] - (float) 120) * (float) 1.98), 51);
	textArea_zone->setWildcard(textAreaBuffer_TempZone);
	textArea_zone->invalidate();
}

void VacancesView::bouton_zone_1_plus()
{
	bouton_zone_x_plus(0, &slider_zone_1, &textArea_zone_1, textAreaBuffer_TempZone1);
}

void VacancesView::bouton_zone_2_plus()
{
	bouton_zone_x_plus(1, &slider_zone_2, &textArea_zone_2, textAreaBuffer_TempZone2);
}

void VacancesView::bouton_zone_3_plus()
{
	bouton_zone_x_plus(2, &slider_zone_3, &textArea_zone_3, textAreaBuffer_TempZone3);
}

void VacancesView::bouton_zone_4_plus()
{
	bouton_zone_x_plus(3, &slider_zone_4, &textArea_zone_4, textAreaBuffer_TempZone4);
}

void VacancesView::bouton_zone_5_plus()
{
	bouton_zone_x_plus(4, &slider_zone_5, &textArea_zone_5, textAreaBuffer_TempZone5);
}

void VacancesView::bouton_zone_6_plus()
{
	bouton_zone_x_plus(5, &slider_zone_6, &textArea_zone_6, textAreaBuffer_TempZone6);
}

void VacancesView::bouton_zone_7_plus()
{
	bouton_zone_x_plus(6, &slider_zone_7, &textArea_zone_7, textAreaBuffer_TempZone7);
}

void VacancesView::bouton_zone_8_plus()
{
	bouton_zone_x_plus(7, &slider_zone_8, &textArea_zone_8, textAreaBuffer_TempZone8);
}

void VacancesView::bouton_zone_x_plus(uint8_t u8Zone, touchgfx::Slider *slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone)
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneTempVacances[u8Zone] == 300) return;

	u16ConsigneTempVacances[u8Zone]++;
	slider_zone->setValue(u16ConsigneTempVacances[u8Zone]);
	slider_zone->invalidate();
	Unicode::snprintfFloat(textAreaBuffer_TempZone, 6, "%.1f", ((float) u16ConsigneTempVacances[u8Zone]) / 10);
	textArea_zone->moveTo((int) ((float) slider_zone->getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_zone->getWidth() / 2 + ((float) u16ConsigneTempVacances[u8Zone] - (float) 120) * (float) 1.98), 51);
	textArea_zone->setWildcard(textAreaBuffer_TempZone);
	textArea_zone->invalidate();
}
void VacancesView::bouton_zone_1_moins()
{
	bouton_zone_x_moins(0, &slider_zone_1, &textArea_zone_1, textAreaBuffer_TempZone1);
}

void VacancesView::bouton_zone_2_moins()
{
	bouton_zone_x_moins(1, &slider_zone_2, &textArea_zone_2, textAreaBuffer_TempZone2);
}

void VacancesView::bouton_zone_3_moins()
{
	bouton_zone_x_moins(2, &slider_zone_3, &textArea_zone_3, textAreaBuffer_TempZone3);
}

void VacancesView::bouton_zone_4_moins()
{
	bouton_zone_x_moins(3, &slider_zone_4, &textArea_zone_4, textAreaBuffer_TempZone4);
}

void VacancesView::bouton_zone_5_moins()
{
	bouton_zone_x_moins(4, &slider_zone_5, &textArea_zone_5, textAreaBuffer_TempZone5);
}

void VacancesView::bouton_zone_6_moins()
{
	bouton_zone_x_moins(5, &slider_zone_6, &textArea_zone_6, textAreaBuffer_TempZone6);
}

void VacancesView::bouton_zone_7_moins()
{
	bouton_zone_x_moins(6, &slider_zone_7, &textArea_zone_7, textAreaBuffer_TempZone7);
}

void VacancesView::bouton_zone_8_moins()
{
	bouton_zone_x_moins(7, &slider_zone_8, &textArea_zone_8, textAreaBuffer_TempZone8);
}

void VacancesView::bouton_zone_x_moins(uint8_t u8Zone, touchgfx::Slider *slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone)
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneTempVacances[u8Zone] == 120) return;

	u16ConsigneTempVacances[u8Zone]--;
	slider_zone->setValue(u16ConsigneTempVacances[u8Zone]);
	slider_zone->invalidate();
	Unicode::snprintfFloat(textAreaBuffer_TempZone, 6, "%.1f", ((float) u16ConsigneTempVacances[u8Zone]) / 10);
	textArea_zone->moveTo((int) ((float) slider_zone->getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_zone->getWidth() / 2 + ((float) u16ConsigneTempVacances[u8Zone] - (float) 120) * (float) 1.98), 51);
	textArea_zone->setWildcard(textAreaBuffer_TempZone);
	textArea_zone->invalidate();
}

void VacancesView::affichageZone(uint8_t u8Zone, touchgfx::Container *container_zone, touchgfx::ToggleButton *toggleButton_zone, touchgfx::Container *container_slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_vacances_zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_Zone, touchgfx::Unicode::UnicodeChar *textAreaBuffer_TempZone, touchgfx::Slider *slider_zone, touchgfx::TextAreaWithOneWildcard *textArea_zone)
{
	container_zone->setVisible(true);
	container_zone->setY(u8NbBoutons * 74);
	// Mode activé ou non
	if(sConfig_IHM.sMode_Zx[u8Zone].Exception == VACANCES && sConfig_IHM.sMode_ECS.Exception == VACANCES)
	{
		toggleButton_zone->forceState(true);
		container_slider_zone->setVisible(true);
	}
	else
	{
		toggleButton_zone->forceState(false);
		container_slider_zone->setVisible(false);
		if(toggleButton_oui_oui_non_vacances.getState() == false)
		{
			toggleButton_zone->setTouchable(false);
		}
	}
	// Position de la température
	u16ConsigneTempVacances[u8Zone] = sConfig_IHM.sMode_Zx[u8Zone].i16Consigne_Tint_Vacances;
	slider_zone->setValue(u16ConsigneTempVacances[u8Zone]);
	Unicode::snprintfFloat(textAreaBuffer_TempZone, 6, "%.1f", ((float) u16ConsigneTempVacances[u8Zone]) / 10);
	textArea_zone->moveTo((int) ((float) slider_zone->getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_zone->getWidth() / 2 + ((float) u16ConsigneTempVacances[u8Zone] - (float) 120) * (float) 1.98), 51);
	textArea_zone->setWildcard(textAreaBuffer_TempZone);
	// Nom de la zone
	Unicode::fromUTF8(sConfig_IHM.sParam_Zx[u8Zone].u8NomZone, textAreaBuffer_Zone, 10);
	textArea_vacances_zone->setWildcard(textAreaBuffer_Zone);
	// Incrémentation du bouton
	u8NbBoutons++;
}

void VacancesView::setupScreen()
{
    VacancesViewBase::setupScreen();
}

void VacancesView::tearDownScreen()
{
    VacancesViewBase::tearDownScreen();
}

void VacancesView::bouton_nb_jours_plus()
{
	if(u8NbJoursVacances < 99)
	{
		u8NbJoursVacances++;
		Unicode::snprintf(textAreaBuffer_NbJours, 3, "%d", u8NbJoursVacances);
		textArea_valeur_nb_jours_absence.setWildcard(textAreaBuffer_NbJours);
		textArea_valeur_nb_jours_absence.invalidate();
	}
}

void VacancesView::bouton_nb_jours_moins()
{
	if(u8NbJoursVacances > 2)
	{
		u8NbJoursVacances--;
		Unicode::snprintf(textAreaBuffer_NbJours, 3, "%d", u8NbJoursVacances);
		textArea_valeur_nb_jours_absence.setWildcard(textAreaBuffer_NbJours);
		textArea_valeur_nb_jours_absence.invalidate();
	}
}

void VacancesView::bouton_vacances_oui()
{
	if(toggleButton_oui_oui_non_vacances.getState())
	{
		toggleButton_non_oui_non_vacances.forceState(false);
		toggleButton_non_oui_non_vacances.setTouchable(true);
		toggleButton_non_oui_non_vacances.invalidate();
		toggleButton_oui_oui_non_vacances.setTouchable(false);
		toggleButton_oui_oui_non_vacances.invalidate();
		toggleButton_zone_1.setTouchable(true);
		toggleButton_zone_1.invalidate();
		toggleButton_zone_2.setTouchable(true);
		toggleButton_zone_2.invalidate();
		toggleButton_zone_3.setTouchable(true);
		toggleButton_zone_3.invalidate();
		toggleButton_zone_4.setTouchable(true);
		toggleButton_zone_4.invalidate();
		toggleButton_zone_5.setTouchable(true);
		toggleButton_zone_5.invalidate();
		toggleButton_zone_6.setTouchable(true);
		toggleButton_zone_6.invalidate();
		toggleButton_zone_7.setTouchable(true);
		toggleButton_zone_7.invalidate();
		toggleButton_zone_8.setTouchable(true);
		toggleButton_zone_8.invalidate();
		toggleButton_piscine.setTouchable(true);
		toggleButton_piscine.invalidate();
		toggleButton_ecs.setTouchable(true);
		toggleButton_ecs.invalidate();
		text_vacances_off();
	}
}

void VacancesView::bouton_vacances_non()
{
	if(toggleButton_non_oui_non_vacances.getState())
	{
		toggleButton_oui_oui_non_vacances.forceState(false);
		toggleButton_oui_oui_non_vacances.setTouchable(true);
		toggleButton_oui_oui_non_vacances.invalidate();
		toggleButton_non_oui_non_vacances.setTouchable(false);
		toggleButton_non_oui_non_vacances.invalidate();
		toggleButton_zone_1.setTouchable(false);
		toggleButton_zone_1.forceState(false);
		toggleButton_zone_1.invalidate();
		container_slider_zone_1.setVisible(false);
		container_slider_zone_1.invalidate();
		toggleButton_zone_2.setTouchable(false);
		toggleButton_zone_2.forceState(false);
		toggleButton_zone_2.invalidate();
		container_slider_zone_2.setVisible(false);
		container_slider_zone_2.invalidate();
		toggleButton_zone_3.setTouchable(false);
		toggleButton_zone_3.forceState(false);
		toggleButton_zone_3.invalidate();
		container_slider_zone_3.setVisible(false);
		container_slider_zone_3.invalidate();
		toggleButton_zone_4.setTouchable(false);
		toggleButton_zone_4.forceState(false);
		toggleButton_zone_4.invalidate();
		container_slider_zone_4.setVisible(false);
		container_slider_zone_4.invalidate();
		toggleButton_zone_5.setTouchable(false);
		toggleButton_zone_5.forceState(false);
		toggleButton_zone_5.invalidate();
		container_slider_zone_5.setVisible(false);
		container_slider_zone_5.invalidate();
		toggleButton_zone_6.setTouchable(false);
		toggleButton_zone_6.forceState(false);
		toggleButton_zone_6.invalidate();
		container_slider_zone_6.setVisible(false);
		container_slider_zone_6.invalidate();
		toggleButton_zone_7.setTouchable(false);
		toggleButton_zone_7.forceState(false);
		toggleButton_zone_7.invalidate();
		container_slider_zone_7.setVisible(false);
		container_slider_zone_7.invalidate();
		toggleButton_zone_8.setTouchable(false);
		toggleButton_zone_8.forceState(false);
		toggleButton_zone_8.invalidate();
		container_slider_zone_8.setVisible(false);
		container_slider_zone_8.invalidate();
		toggleButton_piscine.setTouchable(false);
		toggleButton_piscine.forceState(false);
		toggleButton_piscine.invalidate();
		container_slider_piscine.setVisible(false);
		container_slider_piscine.invalidate();
		toggleButton_ecs.setTouchable(false);
		toggleButton_ecs.forceState(false);
		toggleButton_ecs.invalidate();
		text_vacances_off();
	}
}

void VacancesView::bouton_valider()
{
	// Nombre de jours
	sConfig_IHM.sParam_PAC.u8Time_Vacances = u8NbJoursVacances;
	// Activation de vacances
	if(toggleButton_oui_oui_non_vacances.getState())
	{
		sConfig_IHM.sMode_ECS.Exception = VACANCES;
	}
	else sConfig_IHM.sMode_ECS.Exception = NO_EXCEPTION;
	// Zone 1
	if(sConfig_IHM.sOption_PAC.sZone.bZone1)
	{
		if(toggleButton_zone_1.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[0].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[0].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[0].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[0];
	}
	// Zone 2
	if(sConfig_IHM.sOption_PAC.sZone.bZone2)
	{
		if(toggleButton_zone_2.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[1].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[1].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[1].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[1];
	}
	// Zone 3
	if(sConfig_IHM.sOption_PAC.sZone.bZone3)
	{
		if(toggleButton_zone_3.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[2].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[2].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[2].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[2];
	}
	// Zone 4
	if(sConfig_IHM.sOption_PAC.sZone.bZone4)
	{
		if(toggleButton_zone_1.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[3].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[3].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[3].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[3];
	}
	// Zone 5
	if(sConfig_IHM.sOption_PAC.sZone.bZone5)
	{
		if(toggleButton_zone_5.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[4].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[4].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[4].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[4];
	}
	// Zone 6
	if(sConfig_IHM.sOption_PAC.sZone.bZone6)
	{
		if(toggleButton_zone_6.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[5].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[5].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[5].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[5];
	}
	// Zone 7
	if(sConfig_IHM.sOption_PAC.sZone.bZone7)
	{
		if(toggleButton_zone_7.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[6].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[6].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[6].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[6];
	}
	// Zone 8
	if(sConfig_IHM.sOption_PAC.sZone.bZone8)
	{
		if(toggleButton_zone_8.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Zx[7].Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Zx[7].Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Zx[7].i16Consigne_Tint_Vacances = u16ConsigneTempVacances[7];
	}
	// Piscine
	if(sConfig_IHM.sOption_PAC.Piscine)
	{
		if(toggleButton_piscine.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_Piscine.Exception = VACANCES;
		}
		else sConfig_IHM.sMode_Piscine.Exception = NO_EXCEPTION;
		sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Vacances = u16ConsignePiscineTempVacances;
	}
	// ECS
	if(sConfig_IHM.sOption_PAC.ECS)
	{
		if(toggleButton_ecs.getState() && toggleButton_oui_oui_non_vacances.getState())
		{
			sConfig_IHM.sMode_ECS.bUserECSVacancesOFF = 0;
		}
		else sConfig_IHM.sMode_ECS.bUserECSVacancesOFF = 1;
	}
	// Envoi de la trame
	presenter->c_user_vacances();
	// Retour à la page configuration
	application().gotoConfigurationScreenNoTransition();
}

void VacancesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void VacancesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void VacancesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void VacancesView::changeDate(S_DATE *sDate)
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
