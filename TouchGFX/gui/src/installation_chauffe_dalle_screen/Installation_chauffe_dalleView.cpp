#include <gui/installation_chauffe_dalle_screen/Installation_chauffe_dalleView.hpp>

Installation_chauffe_dalleView::Installation_chauffe_dalleView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TITRE_MISE_CHAUFFE_DALLE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	//
	slider_chauffe_dalle_j1.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[0] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[0][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[0]);
	textArea_temp_loi_eau_1.setWildcard(&textAreaBuffer_TempJour[0][0]);
	//
	slider_chauffe_dalle_j2.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[1] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[1][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[1]);
	textArea_temp_loi_eau_2.setWildcard(&textAreaBuffer_TempJour[1][0]);
	//
	slider_chauffe_dalle_j3.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[2] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[2][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[2]);
	textArea_temp_loi_eau_3.setWildcard(&textAreaBuffer_TempJour[2][0]);
	//
	slider_chauffe_dalle_j4.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[3] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[3][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[3]);
	textArea_temp_loi_eau_4.setWildcard(&textAreaBuffer_TempJour[3][0]);
	//
	slider_chauffe_dalle_j5.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[4] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[4][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[4]);
	textArea_temp_loi_eau_5.setWildcard(&textAreaBuffer_TempJour[4][0]);
	//
	slider_chauffe_dalle_j6.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[5] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[5][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[5]);
	textArea_temp_loi_eau_6.setWildcard(&textAreaBuffer_TempJour[5][0]);
	//
	slider_chauffe_dalle_j7.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[6] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[6][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[6]);
	textArea_temp_loi_eau_7.setWildcard(&textAreaBuffer_TempJour[6][0]);
	//
	slider_chauffe_dalle_j8.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[7] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[7][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[7]);
	textArea_temp_loi_eau_8.setWildcard(&textAreaBuffer_TempJour[7][0]);
	//
	slider_chauffe_dalle_j9.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[8] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[8][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[8]);
	textArea_temp_loi_eau_9.setWildcard(&textAreaBuffer_TempJour[8][0]);
	//
	slider_chauffe_dalle_j10.setValue(sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[9] * 10);
	Unicode::snprintf(&textAreaBuffer_TempJour[9][0], 3, "%d", sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[9]);
	textArea_temp_loi_eau_10.setWildcard(&textAreaBuffer_TempJour[9][0]);
}

void Installation_chauffe_dalleView::setupScreen()
{
    Installation_chauffe_dalleViewBase::setupScreen();
}

void Installation_chauffe_dalleView::tearDownScreen()
{
    Installation_chauffe_dalleViewBase::tearDownScreen();
}

void Installation_chauffe_dalleView::slider_j1(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[0][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_1.setWildcard(&textAreaBuffer_TempJour[0][0]);
	textArea_temp_loi_eau_1.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_1.setVisible(false);
	line_chauffe_dalle_1.invalidate();
	line_chauffe_dalle_1.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_1.setVisible(true);
	line_chauffe_dalle_1.invalidate();
}

void Installation_chauffe_dalleView::slider_j2(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[1][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_1.setWildcard(&textAreaBuffer_TempJour[1][0]);
	textArea_temp_loi_eau_1.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_1.setVisible(false);
	line_chauffe_dalle_1.invalidate();
	line_chauffe_dalle_1.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_1.setVisible(true);
	line_chauffe_dalle_1.invalidate();
	line_chauffe_dalle_2.setVisible(false);
	line_chauffe_dalle_2.invalidate();
	line_chauffe_dalle_2.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_2.setVisible(true);
	line_chauffe_dalle_2.invalidate();
}

void Installation_chauffe_dalleView::slider_j3(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[2][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_3.setWildcard(&textAreaBuffer_TempJour[2][0]);
	textArea_temp_loi_eau_3.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_2.setVisible(false);
	line_chauffe_dalle_2.invalidate();
	line_chauffe_dalle_2.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_2.setVisible(true);
	line_chauffe_dalle_2.invalidate();
	line_chauffe_dalle_3.setVisible(false);
	line_chauffe_dalle_3.invalidate();
	line_chauffe_dalle_3.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_3.setVisible(true);
	line_chauffe_dalle_3.invalidate();
}

void Installation_chauffe_dalleView::slider_j4(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[3][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_4.setWildcard(&textAreaBuffer_TempJour[3][0]);
	textArea_temp_loi_eau_4.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_3.setVisible(false);
	line_chauffe_dalle_3.invalidate();
	line_chauffe_dalle_3.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_3.setVisible(true);
	line_chauffe_dalle_3.invalidate();
	line_chauffe_dalle_4.setVisible(false);
	line_chauffe_dalle_4.invalidate();
	line_chauffe_dalle_4.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_4.setVisible(true);
	line_chauffe_dalle_4.invalidate();
}

void Installation_chauffe_dalleView::slider_j5(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[4][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_5.setWildcard(&textAreaBuffer_TempJour[4][0]);
	textArea_temp_loi_eau_5.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_4.setVisible(false);
	line_chauffe_dalle_4.invalidate();
	line_chauffe_dalle_4.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_4.setVisible(true);
	line_chauffe_dalle_4.invalidate();
	line_chauffe_dalle_5.setVisible(false);
	line_chauffe_dalle_5.invalidate();
	line_chauffe_dalle_5.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_5.setVisible(true);
	line_chauffe_dalle_5.invalidate();
}

void Installation_chauffe_dalleView::slider_j6(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[5][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_6.setWildcard(&textAreaBuffer_TempJour[5][0]);
	textArea_temp_loi_eau_6.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_5.setVisible(false);
	line_chauffe_dalle_5.invalidate();
	line_chauffe_dalle_5.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_5.setVisible(true);
	line_chauffe_dalle_5.invalidate();
	line_chauffe_dalle_6.setVisible(false);
	line_chauffe_dalle_6.invalidate();
	line_chauffe_dalle_6.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_6.setVisible(true);
	line_chauffe_dalle_6.invalidate();
}

void Installation_chauffe_dalleView::slider_j7(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[6][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_7.setWildcard(&textAreaBuffer_TempJour[6][0]);
	textArea_temp_loi_eau_7.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_6.setVisible(false);
	line_chauffe_dalle_6.invalidate();
	line_chauffe_dalle_6.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_6.setVisible(true);
	line_chauffe_dalle_6.invalidate();
	line_chauffe_dalle_7.setVisible(false);
	line_chauffe_dalle_7.invalidate();
	line_chauffe_dalle_7.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_7.setVisible(true);
	line_chauffe_dalle_7.invalidate();
}

void Installation_chauffe_dalleView::slider_j8(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[7][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_8.setWildcard(&textAreaBuffer_TempJour[7][0]);
	textArea_temp_loi_eau_8.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_7.setVisible(false);
	line_chauffe_dalle_7.invalidate();
	line_chauffe_dalle_7.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_7.setVisible(true);
	line_chauffe_dalle_7.invalidate();
	line_chauffe_dalle_8.setVisible(false);
	line_chauffe_dalle_8.invalidate();
	line_chauffe_dalle_8.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_8.setVisible(true);
	line_chauffe_dalle_8.invalidate();
}

void Installation_chauffe_dalleView::slider_j9(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[8][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_9.setWildcard(&textAreaBuffer_TempJour[8][0]);
	textArea_temp_loi_eau_9.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_8.setVisible(false);
	line_chauffe_dalle_8.invalidate();
	line_chauffe_dalle_8.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_8.setVisible(true);
	line_chauffe_dalle_8.invalidate();
	line_chauffe_dalle_9.setVisible(false);
	line_chauffe_dalle_9.invalidate();
	line_chauffe_dalle_9.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_9.setVisible(true);
	line_chauffe_dalle_9.invalidate();
}

void Installation_chauffe_dalleView::slider_j10(int sliderValue)
{
	Unicode::snprintf(&textAreaBuffer_TempJour[9][0], 3, "%d", sliderValue / 10);
	textArea_temp_loi_eau_10.setWildcard(&textAreaBuffer_TempJour[9][0]);
	textArea_temp_loi_eau_10.invalidate();
	// Mouvement de la ligne
	line_chauffe_dalle_9.setVisible(false);
	line_chauffe_dalle_9.invalidate();
	line_chauffe_dalle_9.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  1.093)));
	line_chauffe_dalle_9.setVisible(true);
	line_chauffe_dalle_9.invalidate();
}

void Installation_chauffe_dalleView::bouton_valider()
{
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[0] = slider_chauffe_dalle_j1.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[1] = slider_chauffe_dalle_j2.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[2] = slider_chauffe_dalle_j3.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[3] = slider_chauffe_dalle_j4.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[4] = slider_chauffe_dalle_j5.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[5] = slider_chauffe_dalle_j6.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[6] = slider_chauffe_dalle_j7.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[7] = slider_chauffe_dalle_j8.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[8] = slider_chauffe_dalle_j9.getValue() / 10;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[9] = slider_chauffe_dalle_j10.getValue() / 10;
	//
	presenter->c_install_param();
	application().gotoInstallationScreenNoTransition();
}

void Installation_chauffe_dalleView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_chauffe_dalleView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_chauffe_dalleView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_chauffe_dalleView::changeDate(S_DATE *sDate)
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
