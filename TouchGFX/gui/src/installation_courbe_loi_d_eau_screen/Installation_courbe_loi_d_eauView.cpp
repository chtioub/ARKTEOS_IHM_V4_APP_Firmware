#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauView.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <math.h>

Installation_courbe_loi_d_eauView::Installation_courbe_loi_d_eauView()
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
    //
	container_pave_numeric.setVisible(false);
	// Thermo max
	if(sConfig_IHM.sModele_PAC.u8ThermoMaxPac > 50 && sConfig_IHM.sModele_PAC.u8ThermoMaxPac < 100)
	{
		u16TermoMAX = sConfig_IHM.sModele_PAC.u8ThermoMaxPac * 10;
	}
	else u16TermoMAX = 800;
	//
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		for(int i = 0; i < 6; i++)
		{
			u16LoiDeau[i] = sConfig_IHM.sParam_RegulExt.u8LoiDeau[i] * 10;
		}
		// Titre
	    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_COURBE_LOI_EAU_CENTRE_LARGE).getText());
	    barre_titre.titre(textAreaBuffer_Titre);
	}
	else
	{
		for(int i = 0; i < 6; i++)
		{
			u16LoiDeau[i] = sConfig_Hydrau_temp.sParamZx.u8LoiDeau[i] * 10;
		}
		// Titre
	    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_COURBE_LOI_EAU_CENTRE_LARGE).getText());
	    Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " - ");
		Unicode::fromUTF8(sConfig_Hydrau_temp.sParamZx.u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
	    Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)", sConfig_Hydrau_temp.u8NumZone + 1);
	    barre_titre.titre(textAreaBuffer_Titre);
	}
	//
	for(int i = 0; i < 6; i++)
	{
//		if(u16LoiDeau[i] > u16TermoMAX)
//		{
//			u16LoiDeau[i] = (uint16_t) u16TermoMAX;
//		}
		//
		if((sConfig_Hydrau_temp.u8TypeRegul == REGUL_BCP_INTERNE || sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_2_ZONES) && sConfig_Hydrau_temp.sZones.bZone1 == 1 && sConfig_Hydrau_temp.sZones.bZone2 == 1)
		{
			if(sConfig_Hydrau_temp.u8NumZone == 0)
			{
				u16LoiDeau_MAX[i] = fmax(u16TermoMAX, 0);
				u16LoiDeau_MIN[i] = sConfig_IHM.sParam_Zx[1].u8LoiDeau[i] * 10;
			}
			else
			{
				u16LoiDeau_MAX[i] = fmax(u16TermoMAX, sConfig_IHM.sParam_Zx[0].u8LoiDeau[i] * 10);
				u16LoiDeau_MIN[i] = 200;
			}
		}
		else
		{
			u16LoiDeau_MAX[i] = fmax(u16TermoMAX, 0);
			u16LoiDeau_MIN[i] = 200;
		}
		// Verif max
		if(u16LoiDeau[i] > u16LoiDeau_MAX[i])
		{
			u16LoiDeau[i] = u16LoiDeau_MAX[i];
		}
		// Verif min
		if(u16LoiDeau[i] < u16LoiDeau_MIN[i])
		{
			u16LoiDeau[i] = u16LoiDeau_MIN[i];
		}
	}
	slider_text_m25_deg.setValue((int) u16LoiDeau[5]);
	slider_text_m10_deg.setValue((int) u16LoiDeau[4]);
	slider_text_0_deg.setValue((int) u16LoiDeau[3]);
	slider_text_10_deg.setValue((int) u16LoiDeau[2]);
	slider_text_15_deg.setValue((int) u16LoiDeau[1]);
	slider_text_20_deg.setValue((int) u16LoiDeau[0]);
}

void Installation_courbe_loi_d_eauView::setupScreen()
{
    Installation_courbe_loi_d_eauViewBase::setupScreen();
}

void Installation_courbe_loi_d_eauView::tearDownScreen()
{
    Installation_courbe_loi_d_eauViewBase::tearDownScreen();
}

void Installation_courbe_loi_d_eauView::bouton_retour()
{
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
	else if(sConfig_Hydrau_temp.u8TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
	{
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_courbe_loi_d_eauView::bouton_valider()
{
	if(sConfig_Hydrau_temp.u8TypeRegul >= REGUL_EXTERNE)
	{
		for(int i = 0; i < 6; i++)
		{
			sConfig_IHM.sParam_RegulExt.u8LoiDeau[i] = u16LoiDeau[i] / 10;
		}
		//
		presenter->c_install_reg_ext();
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
	else if(sConfig_Hydrau_temp.u8TypeRegul <= REGUL_BAL_TAMPON_2_ZONES)
	{
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void Installation_courbe_loi_d_eauView::slider_20(int sliderValue)
{
	u16LoiDeau[0] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[1])
	{
		slider_text_20_deg.setValue((int) u16LoiDeau[1]);
		slider_text_20_deg.invalidate();
		sliderValue = u16LoiDeau[1];
		u16LoiDeau[0] = u16LoiDeau[1];
	}
	else if(sliderValue > u16LoiDeau_MAX[0])
	{
		slider_text_20_deg.setValue((int) u16LoiDeau_MAX[0]);
		slider_text_20_deg.invalidate();
		sliderValue = u16LoiDeau_MAX[0];
		u16LoiDeau[0] = u16LoiDeau_MAX[0];
	}
	// Verif pour éviter le dépassement négatif
	else if(sliderValue < u16LoiDeau_MIN[0])
	{
		slider_text_20_deg.setValue((int) u16LoiDeau_MIN[0]);
		slider_text_20_deg.invalidate();
		sliderValue = u16LoiDeau_MIN[0];
		u16LoiDeau[0] = u16LoiDeau_MIN[0];
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_20, 3, "%d", (sliderValue / 10));
		textArea_temp_loi_eau_1.setWildcard(textAreaBuffer_20);
		textArea_temp_loi_eau_1.invalidate();
		line_loi_eau_1.setVisible(false);
		line_loi_eau_1.invalidate();
		line_loi_eau_1.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_1.setVisible(true);
		line_loi_eau_1.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::slider_15(int sliderValue)
{
	u16LoiDeau[1] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[2] || sliderValue > u16LoiDeau_MAX[1])
	{
		slider_text_15_deg.setValue((int) u16LoiDeau[2]);
		slider_text_15_deg.invalidate();
		sliderValue = u16LoiDeau[2];
		u16LoiDeau[1] = u16LoiDeau[2];
	}
	// Verif pour éviter le dépassement négatif
	else if(sliderValue < u16LoiDeau[0] || sliderValue < u16LoiDeau_MIN[1])
	{
		slider_text_15_deg.setValue((int) u16LoiDeau[0]);
		slider_text_15_deg.invalidate();
		sliderValue = u16LoiDeau[0];
		u16LoiDeau[1] = u16LoiDeau[0];
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_15, 3, "%d", (sliderValue / 10));
		textArea_temp_loi_eau_2.setWildcard(textAreaBuffer_15);
		textArea_temp_loi_eau_2.invalidate();
		line_loi_eau_1.setVisible(false);
		line_loi_eau_1.invalidate();
		line_loi_eau_1.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_1.setVisible(true);
		line_loi_eau_1.invalidate();
		line_loi_eau_2.setVisible(false);
		line_loi_eau_2.invalidate();
		line_loi_eau_2.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_2.setVisible(true);
		line_loi_eau_2.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::slider_10(int sliderValue)
{
	u16LoiDeau[2] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[3] || sliderValue > u16LoiDeau_MAX[2])
	{
		slider_text_10_deg.setValue((int) u16LoiDeau[3]);
		slider_text_10_deg.invalidate();
		sliderValue = u16LoiDeau[3];
		u16LoiDeau[2] = u16LoiDeau[3];
	}
	// Verif pour éviter le dépassement négatif
	else if(sliderValue < u16LoiDeau[1] || sliderValue < u16LoiDeau_MIN[2])
	{
		slider_text_10_deg.setValue((int) u16LoiDeau[1]);
		slider_text_10_deg.invalidate();
		sliderValue = u16LoiDeau[1];
		u16LoiDeau[2] = u16LoiDeau[1];
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_10, 3, "%d", (sliderValue / 10));
		textArea_temp_loi_eau_3.setWildcard(textAreaBuffer_10);
		textArea_temp_loi_eau_3.invalidate();
		line_loi_eau_2.setVisible(false);
		line_loi_eau_2.invalidate();
		line_loi_eau_2.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_2.setVisible(true);
		line_loi_eau_2.invalidate();
		line_loi_eau_3.setVisible(false);
		line_loi_eau_3.invalidate();
		line_loi_eau_3.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_3.setVisible(true);
		line_loi_eau_3.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::slider_0(int sliderValue)
{
	u16LoiDeau[3] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[4] || sliderValue > u16LoiDeau_MAX[3])
	{
		slider_text_0_deg.setValue((int) u16LoiDeau[4]);
		slider_text_0_deg.invalidate();
		sliderValue = u16LoiDeau[4];
		u16LoiDeau[3] = u16LoiDeau[4];
	}
	// Verif pour éviter le dépassement négatif
	else if(sliderValue < u16LoiDeau[2] || sliderValue < u16LoiDeau_MIN[3])
	{
		slider_text_0_deg.setValue((int) u16LoiDeau[2]);
		slider_text_0_deg.invalidate();
		sliderValue = u16LoiDeau[2];
		u16LoiDeau[3] = u16LoiDeau[2];
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_0, 3, "%d", (sliderValue / 10));
		textArea_temp_loi_eau_4.setWildcard(textAreaBuffer_0);
		textArea_temp_loi_eau_4.invalidate();
		line_loi_eau_3.setVisible(false);
		line_loi_eau_3.invalidate();
		line_loi_eau_3.setEnd(178, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_3.setVisible(true);
		line_loi_eau_3.invalidate();
		line_loi_eau_4.setVisible(false);
		line_loi_eau_4.invalidate();
		line_loi_eau_4.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_4.setVisible(true);
		line_loi_eau_4.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::slider_m10(int sliderValue)
{
	u16LoiDeau[4] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[5] || sliderValue > u16LoiDeau_MAX[4])
	{
		slider_text_m10_deg.setValue((int) u16LoiDeau[5]);
		slider_text_m10_deg.invalidate();
		sliderValue = u16LoiDeau[5];
		u16LoiDeau[4] = u16LoiDeau[5];
	}
	// Verif pour éviter le dépassement négatif
	else if(sliderValue < u16LoiDeau[3] || sliderValue < u16LoiDeau_MIN[4])
	{
		slider_text_m10_deg.setValue((int) u16LoiDeau[3]);
		slider_text_m10_deg.invalidate();
		sliderValue = u16LoiDeau[3];
		u16LoiDeau[4] = u16LoiDeau[3];
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_m10, 3, "%d", (sliderValue / 10));
		textArea_temp_loi_eau_5.setWildcard(textAreaBuffer_m10);
		textArea_temp_loi_eau_5.invalidate();
		line_loi_eau_4.setVisible(false);
		line_loi_eau_4.invalidate();
		line_loi_eau_4.setEnd(178, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_4.setVisible(true);
		line_loi_eau_4.invalidate();
		line_loi_eau_5.setVisible(false);
		line_loi_eau_5.invalidate();
		line_loi_eau_5.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_5.setVisible(true);
		line_loi_eau_5.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::slider_m25(int sliderValue)
{
	u16LoiDeau[5] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau_MAX[5])
	{
		slider_text_m25_deg.setValue(u16TermoMAX);
		slider_text_m25_deg.invalidate();
		sliderValue = u16LoiDeau_MAX[5];
		u16LoiDeau[5] = u16LoiDeau_MAX[5];
	}
	// Verif pour éviter le dépassement négatif
	else if(sliderValue < u16LoiDeau[4] || sliderValue < u16LoiDeau_MIN[5])
	{
		slider_text_m25_deg.setValue((int) u16LoiDeau[4]);
		slider_text_m25_deg.invalidate();
		sliderValue = u16LoiDeau[4];
		u16LoiDeau[5] = u16LoiDeau[4];
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_m25, 3, "%d", (sliderValue / 10));
		textArea_temp_loi_eau_6.setWildcard(textAreaBuffer_m25);
		textArea_temp_loi_eau_6.invalidate();
		line_loi_eau_5.setVisible(false);
		line_loi_eau_5.invalidate();
		line_loi_eau_5.setEnd(272, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
		line_loi_eau_5.setVisible(true);
		line_loi_eau_5.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::bouton_loi_eau_20()
{
	if(container_pave_numeric.isVisible())
	{
		pave_numerique(false);
		textArea_temp_loi_eau_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau_1.invalidate();
	}
	else
	{
		pave_numerique(true);
		textArea_temp_loi_eau_1.setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau_1.invalidate();
	}
	slider_text = &slider_text_20_deg;
	textArea_temp_loi_eau = &textArea_temp_loi_eau_1;
	textAreaBuffer = &textAreaBuffer_20[0];
	u16ValeurPaveNumeric = 0;
}

void Installation_courbe_loi_d_eauView::bouton_loi_eau_15()
{
	if(container_pave_numeric.isVisible())
	{
		pave_numerique(false);
		textArea_temp_loi_eau_2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau_2.invalidate();
	}
	else
	{
		pave_numerique(true);
		textArea_temp_loi_eau_2.setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau_2.invalidate();
	}
	slider_text = &slider_text_15_deg;
	textArea_temp_loi_eau = &textArea_temp_loi_eau_2;
	textAreaBuffer = &textAreaBuffer_15[0];
	u16ValeurPaveNumeric = 0;
}

void Installation_courbe_loi_d_eauView::bouton_loi_eau_10()
{
	if(container_pave_numeric.isVisible())
	{
		pave_numerique(false);
		textArea_temp_loi_eau_3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau_3.invalidate();
	}
	else
	{
		pave_numerique(true);
		textArea_temp_loi_eau_3.setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau_3.invalidate();
	}
	slider_text = &slider_text_10_deg;
	textArea_temp_loi_eau = &textArea_temp_loi_eau_3;
	textAreaBuffer = &textAreaBuffer_10[0];
	u16ValeurPaveNumeric = 0;
}

void Installation_courbe_loi_d_eauView::bouton_loi_eau_0()
{
	if(container_pave_numeric.isVisible())
	{
		pave_numerique(false);
		textArea_temp_loi_eau_4.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau_4.invalidate();
	}
	else
	{
		pave_numerique(true);
		textArea_temp_loi_eau_4.setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau_4.invalidate();
	}
	slider_text = &slider_text_0_deg;
	textArea_temp_loi_eau = &textArea_temp_loi_eau_4;
	textAreaBuffer = &textAreaBuffer_0[0];
	u16ValeurPaveNumeric = 0;
}

void Installation_courbe_loi_d_eauView::bouton_loi_eau_m10()
{
	if(container_pave_numeric.isVisible())
	{
		pave_numerique(false);
		textArea_temp_loi_eau_5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau_5.invalidate();
	}
	else
	{
		pave_numerique(true);
		textArea_temp_loi_eau_5.setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau_5.invalidate();
	}
	slider_text = &slider_text_m10_deg;
	textArea_temp_loi_eau = &textArea_temp_loi_eau_5;
	textAreaBuffer = &textAreaBuffer_m10[0];
	u16ValeurPaveNumeric = 0;
}

void Installation_courbe_loi_d_eauView::bouton_loi_eau_m25()
{
	if(container_pave_numeric.isVisible())
	{
		pave_numerique(false);
		textArea_temp_loi_eau_6.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau_6.invalidate();
	}
	else
	{
		pave_numerique(true);
		textArea_temp_loi_eau_6.setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau_6.invalidate();
	}
	slider_text = &slider_text_m25_deg;
	textArea_temp_loi_eau = &textArea_temp_loi_eau_6;
	textAreaBuffer = &textAreaBuffer_m25[0];
	u16ValeurPaveNumeric = 0;
}

void Installation_courbe_loi_d_eauView::bouton_0()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10;
		}
	}
	else u16ValeurPaveNumeric = 0;
	//
	touchgfx_printf("Bouton 0; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_1()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 1;
		}
	}
	else u16ValeurPaveNumeric = 1;
	//
	touchgfx_printf("Bouton 1; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_2()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 2;
		}
	}
	else u16ValeurPaveNumeric = 2;
	//
	touchgfx_printf("Bouton 2; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_3()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 3;
		}
	}
	else u16ValeurPaveNumeric = 3;
	//
	touchgfx_printf("Bouton 3; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_4()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 4;
		}
	}
	else u16ValeurPaveNumeric = 4;
	//
	touchgfx_printf("Bouton 4; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_5()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 5;
		}
	}
	else u16ValeurPaveNumeric = 5;
	//
	touchgfx_printf("Bouton 5; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_6()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 6;
		}
	}
	else u16ValeurPaveNumeric = 6;
	//
	touchgfx_printf("Bouton 6; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_7()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 7;
		}
	}
	else u16ValeurPaveNumeric = 7;
	//
	touchgfx_printf("Bouton 7; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_8()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 8;
		}
	}
	else u16ValeurPaveNumeric = 8;
	//
	touchgfx_printf("Bouton 8; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_9()
{
	if(u16ValeurPaveNumeric != 0)
	{
		if(u16ValeurPaveNumeric < 10)
		{
			u16ValeurPaveNumeric = u16ValeurPaveNumeric * 10 + 9;
		}
	}
	else u16ValeurPaveNumeric = 9;
	//
	touchgfx_printf("Bouton 9; val = %d\n", u16ValeurPaveNumeric);
	//
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
	textArea_temp_loi_eau->setVisible(true);
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
}

void Installation_courbe_loi_d_eauView::bouton_supprimer()
{
	int temperature_modifiee = 0;
	// Recherche de la température en cours de modification
	if(textAreaBuffer == &textAreaBuffer_20[0]) temperature_modifiee = 0;
	else if(textAreaBuffer == &textAreaBuffer_15[0]) temperature_modifiee = 1;
	else if(textAreaBuffer == &textAreaBuffer_10[0]) temperature_modifiee = 2;
	else if(textAreaBuffer == &textAreaBuffer_0[0]) temperature_modifiee = 3;
	else if(textAreaBuffer == &textAreaBuffer_m10[0]) temperature_modifiee = 4;
	else temperature_modifiee = 5;
	//
	touchgfx_printf("Bouton supprimer; val = %d\n", u16ValeurPaveNumeric);
	//
	if(u16ValeurPaveNumeric > 10)
	{
		u16ValeurPaveNumeric /= 10;
		//
		Unicode::snprintf(textAreaBuffer, 3, "%d", u16ValeurPaveNumeric);
		textArea_temp_loi_eau->setColor(touchgfx::Color::getColorFromRGB(255, 55, 55));
		textArea_temp_loi_eau->setWildcard(textAreaBuffer);
		textArea_temp_loi_eau->invalidate();
	}
	else
	{
		pave_numerique(false);
		Unicode::snprintf(textAreaBuffer, 3, "%d", u16LoiDeau[temperature_modifiee] / 10);
		textArea_temp_loi_eau->setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		textArea_temp_loi_eau->setWildcard(textAreaBuffer);
		textArea_temp_loi_eau->invalidate();
		slider_text->setTouchable(true);
		slider_text->invalidate();
	}
}

void Installation_courbe_loi_d_eauView::bouton_valider_pave_num()
{
	int temperature_modifiee = 0;
	// Recherche de la température en cours de modification
	if(textAreaBuffer == &textAreaBuffer_20[0]) temperature_modifiee = 0;
	else if(textAreaBuffer == &textAreaBuffer_15[0]) temperature_modifiee = 1;
	else if(textAreaBuffer == &textAreaBuffer_10[0]) temperature_modifiee = 2;
	else if(textAreaBuffer == &textAreaBuffer_0[0]) temperature_modifiee = 3;
	else if(textAreaBuffer == &textAreaBuffer_m10[0]) temperature_modifiee = 4;
	else temperature_modifiee = 5;
	//
	touchgfx_printf("Bouton valider; val = %d\n", u16ValeurPaveNumeric);
	//
	if(u16ValeurPaveNumeric > 20 && u16ValeurPaveNumeric < u16TermoMAX)
	{
		if(temperature_modifiee == 0 && u16ValeurPaveNumeric < (u16LoiDeau[1] / 10))
		{
			u16LoiDeau[0] = u16ValeurPaveNumeric * 10;
			slider_text->setValue((int) u16LoiDeau[0] + 1);
		}
		else if(temperature_modifiee == 5 && u16ValeurPaveNumeric > (u16LoiDeau[4] / 10))
		{
			u16LoiDeau[5] = u16ValeurPaveNumeric * 10;
			slider_text->setValue((int) u16LoiDeau[5] + 1);
		}
		else if(u16ValeurPaveNumeric < (u16LoiDeau[temperature_modifiee + 1] / 10) && u16ValeurPaveNumeric > (u16LoiDeau[temperature_modifiee - 1] / 10))
		{
			u16LoiDeau[temperature_modifiee] = u16ValeurPaveNumeric * 10;
			slider_text->setValue((int) u16LoiDeau[temperature_modifiee] + 1);
		}
	}
	pave_numerique(false);
	Unicode::snprintf(textAreaBuffer, 3, "%d", u16LoiDeau[temperature_modifiee]);
	textArea_temp_loi_eau->setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	textArea_temp_loi_eau->setWildcard(textAreaBuffer);
	textArea_temp_loi_eau->invalidate();
	slider_text->setTouchable(true);
	slider_text->invalidate();
}

void Installation_courbe_loi_d_eauView::pave_numerique(bool bPaveNum)
{
	// Pave numérique
	container_pave_numeric.setVisible(bPaveNum);
	container_pave_numeric.invalidate();
	// Sliders
	slider_text_20_deg.setTouchable(!bPaveNum);
	slider_text_20_deg.invalidate();
	slider_text_15_deg.setTouchable(!bPaveNum);
	slider_text_15_deg.invalidate();
	slider_text_10_deg.setTouchable(!bPaveNum);
	slider_text_10_deg.invalidate();
	slider_text_0_deg.setTouchable(!bPaveNum);
	slider_text_0_deg.invalidate();
	slider_text_m10_deg.setTouchable(!bPaveNum);
	slider_text_m10_deg.invalidate();
	slider_text_m25_deg.setTouchable(!bPaveNum);
	slider_text_m25_deg.invalidate();
	// Boutons de température
	button_loi_eau_20.setTouchable(!bPaveNum);
	button_loi_eau_20.invalidate();
	button_loi_eau_15.setTouchable(!bPaveNum);
	button_loi_eau_15.invalidate();
	button_loi_eau_10.setTouchable(!bPaveNum);
	button_loi_eau_10.invalidate();
	button_loi_eau_0.setTouchable(!bPaveNum);
	button_loi_eau_0.invalidate();
	button_loi_eau_m10.setTouchable(!bPaveNum);
	button_loi_eau_m10.invalidate();
	button_loi_eau_m25.setTouchable(!bPaveNum);
	button_loi_eau_m25.invalidate();
}

void Installation_courbe_loi_d_eauView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_courbe_loi_d_eauView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_courbe_loi_d_eauView::changeDate(S_DATE *sDate)
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
