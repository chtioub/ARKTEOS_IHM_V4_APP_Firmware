#include <gui/maintenance_test_composants_screen/Maintenance_test_composantsView.hpp>
#include <BitmapDatabase.hpp>


Maintenance_test_composantsView::Maintenance_test_composantsView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
//	changeStatutCyclFrigo(&sCyclRegFrigo[0]);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TEST_COMPOSANTS_TITRE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.sansAccueil();

	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			scrollableContainer_geotwin.setVisible(false);
//			scrollableContainer_geotwin.invalidate();
			container_default.setVisible(false);
//			container_default.invalidate();
			scrollableContainer_inverterra.setVisible(true);
//			scrollableContainer_inverterra.invalidate();
			break;
		case GEOTWIN_IV:
			container_default.setVisible(false);
//			container_default.invalidate();
			scrollableContainer_inverterra.setVisible(false);
//			scrollableContainer_inverterra.invalidate();
			scrollableContainer_geotwin.setVisible(true);
//			scrollableContainer_geotwin.invalidate();
			break;
		default:
			scrollableContainer_geotwin.setVisible(false);
//			scrollableContainer_geotwin.invalidate();
			scrollableContainer_inverterra.setVisible(false);
//			scrollableContainer_inverterra.invalidate();
			container_default.setVisible(true);
//			container_default.invalidate();
			break;
	}

	scrollableContainer_geotwin.invalidate();
	scrollableContainer_inverterra.invalidate();
	container_default.invalidate();

	u8NumVoie = 0;
	u8NumCarte = 0;
	updateNumVoie();
	updateNumCarte();
	presenter->c_sav_test_cps_start();
	u8TimerCircRegP = 0;
	u8TimerCircRegZ1 = 0;
	u8TimerCircRegZ2 = 0;
	u8TimerVanneMel = 0;
	u8TimerRelaisReg = 0;
	u8TimerSortieAnaECS = 0;
	u8TimerRelaisCircECS = 0;
	u8TimerRelaisAppECS = 0;
	u8TimerV3VECS = 0;
	u8TimerRelaisMZ = 0;
	u8TimerSortieAnaMZ = 0;
	u8TimerRelaisAppoint = 0;
	u8TimerRelaisC1 = 0;
	u8TimerRelaisC2 = 0;
	u8TimerDetGeot = 0;
	u8TimerRelaisGeot = 0;
	u8TimerRelaisCircGeot = 0;
	bButtonV4VOn = false;
	bButtonRVOn = false;
	bButtonEVOn = false;
	bButtonSpa1On = false;
	bButtonSpa2On = false;
	bButtonPuitsOn = false;
	bButtonVentCaptsOn = false;
	bButtonCircPrimOn = false;
	bButtonOutVentil = false;
	bButtonOutOption = false;
	bButtonOutDet1 = false;
	bButtonOutDet2 = false;
	bButtonOutDet3 = false;
	bButtonOutDet4 = false;
}

void Maintenance_test_composantsView::setupScreen()
{
    Maintenance_test_composantsViewBase::setupScreen();
}

void Maintenance_test_composantsView::tearDownScreen()
{
    Maintenance_test_composantsViewBase::tearDownScreen();
}

void Maintenance_test_composantsView::timer_1s()
{
	//Circulateurs Carte REG
	if (u8TimerCircRegP)
	{
		u8TimerCircRegP--;
		if (u8TimerCircRegP == 0)
		{
			u8TimerCircRegZ1 = 10;
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_circulateur_carte_reg_inv.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_Z1_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_circulateur_carte_reg_geot.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_Z1_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_geot.invalidate();
					break;
				default:
					buttonWithLabel_circulateur_carte_reg_default.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_Z1_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_default.invalidate();
					break;
			}

		}
	}
	if (u8TimerCircRegZ1)
	{
		u8TimerCircRegZ1--;
		if (u8TimerCircRegZ1 == 0)
		{
			u8TimerCircRegZ2 = 10;
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_circulateur_carte_reg_inv.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_Z2_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_circulateur_carte_reg_geot.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_Z2_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_geot.invalidate();
					break;
				default:
					buttonWithLabel_circulateur_carte_reg_default.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_Z2_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_default.invalidate();
					break;
			}

		}
	}
	if (u8TimerCircRegZ2)
	{
		u8TimerCircRegZ2--;
		if (u8TimerCircRegZ2 == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_circulateur_carte_reg_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_circulateur_carte_reg_inv.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_circulateur_carte_reg_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_circulateur_carte_reg_geot.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_geot.invalidate();
					break;
				default:
					buttonWithLabel_circulateur_carte_reg_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_circulateur_carte_reg_default.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_CENTRE_DEFAUT));
					buttonWithLabel_circulateur_carte_reg_default.invalidate();
					break;
			}
		}
	}
	//Vanne de mélange
	if (u8TimerVanneMel)
	{
		u8TimerVanneMel--;
		if (u8TimerVanneMel == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_vanne_melange_reg_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_vanne_melange_reg_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_vanne_melange_reg_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_vanne_melange_reg_geot.invalidate();
					break;
				default:
					buttonWithLabel_vanne_melange_reg_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_vanne_melange_reg_default.invalidate();
					break;
			}
		}
	}
	//Relais REG
	if (u8TimerRelaisReg)
	{
		u8TimerRelaisReg--;
		if (u8TimerRelaisReg == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_relais_carte_reg_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_carte_reg_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_relais_carte_reg_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_carte_reg_geot.invalidate();
					break;
				default:
					buttonWithLabel_relais_carte_reg_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_carte_reg_default.invalidate();
					break;
			}
		}
	}
	//Sortie Ana ECS
	if (u8TimerSortieAnaECS)
	{
		u8TimerSortieAnaECS--;
		if (u8TimerSortieAnaECS == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_sortie_ana_carte_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_ana_carte_ecs_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_sortie_ana_carte_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_ana_carte_ecs_geot.invalidate();
					break;
				default:
					buttonWithLabel_sortie_ana_carte_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_ana_carte_ecs_default.invalidate();
					break;
			}
		}
	}
	//Relais circ ECS
	if (u8TimerRelaisCircECS)
	{
		u8TimerRelaisCircECS--;
		if (u8TimerRelaisCircECS == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_relais_circ_carte_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_circ_carte_ecs_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_relais_circ_carte_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_circ_carte_ecs_geot.invalidate();
					break;
				default:
					buttonWithLabel_relais_circ_carte_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_circ_carte_ecs_default.invalidate();
					break;
			}
		}
	}
	//Relais App ECS
	if (u8TimerRelaisAppECS)
	{
		u8TimerRelaisAppECS--;
		if (u8TimerRelaisAppECS == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_relais_appoint_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_appoint_ecs_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_relais_appoint_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_appoint_ecs_geot.invalidate();
					break;
				default:
					buttonWithLabel_relais_appoint_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_appoint_ecs_default.invalidate();
					break;
			}
		}
	}
	//Relais V3V ECS
	if (u8TimerV3VECS)
	{
		u8TimerV3VECS--;
		if (u8TimerV3VECS == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_relais_v3v_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_v3v_ecs_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_relais_v3v_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_v3v_ecs_geot.invalidate();
					break;
				default:
					buttonWithLabel_relais_v3v_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_relais_v3v_ecs_default.invalidate();
					break;
			}
		}
	}
	//Relais MZ
	if (u8TimerRelaisMZ)
	{
		u8TimerRelaisMZ--;
		if (u8TimerRelaisMZ == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_sortie_relais_carte_mz_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_relais_carte_mz_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_sortie_relais_carte_mz_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_relais_carte_mz_geot.invalidate();
					break;
				default:
					buttonWithLabel_sortie_relais_carte_mz_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_relais_carte_mz_default.invalidate();
					break;
			}
		}
	}
	//Sortie 0-10V MZ
	if (u8TimerSortieAnaMZ)
	{
		u8TimerSortieAnaMZ--;
		if (u8TimerSortieAnaMZ == 0)
		{
			switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
			{
				case GEOINVERTER :
					buttonWithLabel_sortie_0_10v_mz_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_0_10v_mz_inv.invalidate();
					break;
				case GEOTWIN_IV:
					buttonWithLabel_sortie_0_10v_mz_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_0_10v_mz_geot.invalidate();
					break;
				default:
					buttonWithLabel_sortie_0_10v_mz_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
					buttonWithLabel_sortie_0_10v_mz_default.invalidate();
					break;
			}
		}
	}
	//Détendeur Géotwin
	if (u8TimerDetGeot)
	{
		u8TimerDetGeot--;
		if (u8TimerDetGeot == 0)
		{
			buttonWithLabel_sortie_detendeur_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_detendeur_geot.invalidate();
		}
	}
	//Relais Géotwin
	if (u8TimerRelaisGeot)
	{
		u8TimerRelaisGeot--;
		if (u8TimerRelaisGeot == 0)
		{
			buttonWithLabel_sortie_relais_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_geot.invalidate();
		}
	}
	//Relais Circulateur
	if (u8TimerRelaisCircGeot)
	{
		u8TimerRelaisCircGeot--;
		if (u8TimerRelaisCircGeot == 0)
		{
			buttonWithLabel_sortie_circulateur_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_circulateur_geot.invalidate();
		}
	}
	//Relais appoint 3s
	if (u8TimerRelaisAppoint)
	{
		u8TimerRelaisAppoint--;
		if (u8TimerRelaisAppoint == 0 && sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
		{
			buttonWithLabel_sortie_relais_appoint_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_appoint_inv.invalidate();
		}
	}
	//Relais C1
	if (u8TimerRelaisC1)
	{
		u8TimerRelaisC1--;
		if (u8TimerRelaisC1 == 0 && sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
		{
			buttonWithLabel_sortie_relais_c1_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_c1_inv.invalidate();
		}
		else if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
		{
			buttonWithLabel_sortie_relais_c1_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_c1_geot.invalidate();
		}
	}
	//Relais C2
	if (u8TimerRelaisC2)
	{
		u8TimerRelaisC2--;
		if (u8TimerRelaisC2 == 0 && sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
		{
			buttonWithLabel_sortie_relais_c2_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_c2_inv.invalidate();
		}
		else if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
		{
			buttonWithLabel_sortie_relais_c2_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_c2_geot.invalidate();
		}
	}

}

void  Maintenance_test_composantsView::bouton_valider()
{
	presenter->c_sav_test_cps_stop();
	if (bTestPacComposantDepuisUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else
	{
		application().gotoMaintenanceScreenNoTransition();
	}
}

void  Maintenance_test_composantsView::updateNumVoie()
{
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			if (u8NumVoie < 5)
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 2, "%d", u8NumVoie + 1);
				buttonWithLabel_sortie_relais_carte_mz_inv.setVisible(true);
			}
			else if (u8NumVoie == 5)
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 8, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_DEFAUT).getText());
				buttonWithLabel_sortie_relais_carte_mz_inv.setVisible(false);
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 8, touchgfx::TypedText(T_TEXT_FAN_CENTRE_DEFAUT).getText());
				buttonWithLabel_sortie_relais_carte_mz_inv.setVisible(false);
			}
			buttonWithLabel_sortie_relais_carte_mz_inv.invalidate();
			textArea_voie_carte_mz_inv.setWildcard(textAreaBuffer_NumVoie);
			textArea_voie_carte_mz_inv.invalidate();
			break;
		case GEOTWIN_IV:
			if (u8NumVoie < 5)
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 2, "%d", u8NumVoie + 1);
				buttonWithLabel_sortie_relais_carte_mz_geot.setVisible(true);
			}
			else if (u8NumVoie == 5)
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 8, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_DEFAUT).getText());
				buttonWithLabel_sortie_relais_carte_mz_geot.setVisible(false);
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 8, touchgfx::TypedText(T_TEXT_FAN_CENTRE_DEFAUT).getText());
				buttonWithLabel_sortie_relais_carte_mz_geot.setVisible(false);
			}
			buttonWithLabel_sortie_relais_carte_mz_geot.invalidate();
			textArea_voie_carte_mz_geot.setWildcard(textAreaBuffer_NumVoie);
			textArea_voie_carte_mz_geot.invalidate();
			break;
		default:
			if (u8NumVoie < 5)
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 2, "%d", u8NumVoie + 1);
				buttonWithLabel_sortie_relais_carte_mz_default.setVisible(true);
			}
			else if (u8NumVoie == 5)
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 8, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_DEFAUT).getText());
				buttonWithLabel_sortie_relais_carte_mz_default.setVisible(false);
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_NumVoie, 8, touchgfx::TypedText(T_TEXT_FAN_CENTRE_DEFAUT).getText());
				buttonWithLabel_sortie_relais_carte_mz_default.setVisible(false);
			}
			buttonWithLabel_sortie_relais_carte_mz_default.invalidate();
			textArea_voie_carte_mz_default.setWildcard(textAreaBuffer_NumVoie);
			textArea_voie_carte_mz_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::updateNumCarte()
{
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			if (u8NumCarte == 0)
			{
				textArea_carte_mz_inv.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
				textArea_carte_mz_inv.invalidate();
			}
			else
			{
				textArea_carte_mz_inv.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
				textArea_carte_mz_inv.invalidate();
			}
			break;
		case GEOTWIN_IV:
			if (u8NumCarte == 0)
			{
				textArea_carte_mz_geot.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
				textArea_carte_mz_geot.invalidate();
			}
			else
			{
				textArea_carte_mz_geot.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
				textArea_carte_mz_geot.invalidate();
			}
			break;
		default:
			if (u8NumCarte == 0)
			{
				textArea_carte_mz_default.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
				textArea_carte_mz_default.invalidate();
			}
			else
			{
				textArea_carte_mz_default.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
				textArea_carte_mz_default.invalidate();
			}
			break;
	}
}


void  Maintenance_test_composantsView::bouton_circulateur_reg()
{
	presenter->c_sav_test_cps(0);
	u8TimerCircRegP = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_circulateur_carte_reg_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_circulateur_carte_reg_inv.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_P_CENTRE_DEFAUT));
			buttonWithLabel_circulateur_carte_reg_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_circulateur_carte_reg_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_circulateur_carte_reg_geot.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_P_CENTRE_DEFAUT));
			buttonWithLabel_circulateur_carte_reg_geot.invalidate();
			break;
		default:
			buttonWithLabel_circulateur_carte_reg_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_circulateur_carte_reg_default.setLabelText(touchgfx::TypedText(T_TEXT_CIRCULATEUR_CARTE_REG_P_CENTRE_DEFAUT));
			buttonWithLabel_circulateur_carte_reg_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_vanne_melange_reg()
{
	presenter->c_sav_test_cps(2);
	u8TimerVanneMel = 20;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_vanne_melange_reg_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_vanne_melange_reg_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_vanne_melange_reg_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_vanne_melange_reg_geot.invalidate();
			break;
		default:
			buttonWithLabel_vanne_melange_reg_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_vanne_melange_reg_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_relais_reg()
{
	presenter->c_sav_test_cps(3);
	u8TimerRelaisReg = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_relais_carte_reg_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_carte_reg_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_relais_carte_reg_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_carte_reg_geot.invalidate();
			break;
		default:
			buttonWithLabel_relais_carte_reg_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_carte_reg_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_sortie_ana_ecs()
{
	presenter->c_sav_test_cps(10);
	u8TimerSortieAnaECS = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_sortie_ana_carte_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_ana_carte_ecs_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_sortie_ana_carte_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_ana_carte_ecs_geot.invalidate();
			break;
		default:
			buttonWithLabel_sortie_ana_carte_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_ana_carte_ecs_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_circulateur_ecs()
{
	presenter->c_sav_test_cps(11);
	u8TimerRelaisCircECS = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_relais_circ_carte_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_circ_carte_ecs_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_relais_circ_carte_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_circ_carte_ecs_geot.invalidate();
			break;
		default:
			buttonWithLabel_relais_circ_carte_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_circ_carte_ecs_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_appoint_ecs()
{
	presenter->c_sav_test_cps(12);
	u8TimerRelaisAppECS = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_relais_appoint_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_appoint_ecs_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_relais_appoint_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_appoint_ecs_geot.invalidate();
			break;
		default:
			buttonWithLabel_relais_appoint_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_appoint_ecs_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_v3v_ecs()
{
	presenter->c_sav_test_cps(13);
	u8TimerV3VECS = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_relais_v3v_ecs_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_v3v_ecs_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_relais_v3v_ecs_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_v3v_ecs_geot.invalidate();
			break;
		default:
			buttonWithLabel_relais_v3v_ecs_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_relais_v3v_ecs_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_relais_mz()
{
	presenter->c_sav_test_cps(14 + u8NumCarte*12 + u8NumVoie);
	u8TimerRelaisMZ = 10;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_sortie_relais_carte_mz_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_carte_mz_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_sortie_relais_carte_mz_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_carte_mz_geot.invalidate();
			break;
		default:
			buttonWithLabel_sortie_relais_carte_mz_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_relais_carte_mz_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_0_10_mz()
{
	if (u8NumVoie != 6)
	{
		presenter->c_sav_test_cps(20 + u8NumCarte*12 + u8NumVoie);
	}
	else
	{
		presenter->c_sav_test_cps(25 + u8NumCarte*12 + u8NumVoie);
	}

	u8TimerSortieAnaMZ = 60;
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		case GEOINVERTER :
			buttonWithLabel_sortie_0_10v_mz_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_0_10v_mz_inv.invalidate();
			break;
		case GEOTWIN_IV:
			buttonWithLabel_sortie_0_10v_mz_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_0_10v_mz_geot.invalidate();
			break;
		default:
			buttonWithLabel_sortie_0_10v_mz_default.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
			buttonWithLabel_sortie_0_10v_mz_default.invalidate();
			break;
	}
}

void  Maintenance_test_composantsView::bouton_carte_mz()
{
	if (u8NumCarte == 0) u8NumCarte++;
	else u8NumCarte = 0;

	updateNumCarte();
}

void  Maintenance_test_composantsView::bouton_voie_carte_mz()
{
	if (u8NumVoie < 6) u8NumVoie++;
	else u8NumVoie = 0;

	updateNumVoie();
}

void  Maintenance_test_composantsView::bouton_relais_appoint()
{
	presenter->c_sav_test_cps(38);
	u8TimerRelaisAppoint = 3;
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		buttonWithLabel_sortie_relais_appoint_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		buttonWithLabel_sortie_relais_appoint_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_v4v()
{
	presenter->c_sav_test_cps(39);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
//		bButtonV4VOn ? buttonWithLabel_sortie_relais_v4v_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID))
//				: buttonWithLabel_sortie_relais_v4v_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		if (!bButtonV4VOn)
		{
			bButtonV4VOn = true;
			buttonWithLabel_sortie_relais_v4v_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonV4VOn = false;
			buttonWithLabel_sortie_relais_v4v_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_relais_v4v_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_rv()
{
	presenter->c_sav_test_cps(40);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonRVOn)
		{
			bButtonRVOn = true;
			buttonWithLabel_sortie_relais_rv_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonRVOn = false;
			buttonWithLabel_sortie_relais_rv_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_relais_rv_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_ev()
{
	presenter->c_sav_test_cps(41);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonEVOn)
		{
			bButtonEVOn = true;
			buttonWithLabel_sortie_relais_ev_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonEVOn = false;
			buttonWithLabel_sortie_relais_ev_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_relais_ev_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_rc()
{
	presenter->c_sav_test_cps(42);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonRCOn)
		{
			bButtonRCOn = true;
			buttonWithLabel_sortie_relais_rc_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonRCOn = false;
			buttonWithLabel_sortie_relais_rc_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_relais_rc_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_c1()
{
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		presenter->c_sav_test_cps(4);
		u8TimerRelaisC1 = 4;
		buttonWithLabel_sortie_relais_c1_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		buttonWithLabel_sortie_relais_c1_geot.invalidate();
	}
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		presenter->c_sav_test_cps(43);
		u8TimerRelaisC1 = 3;
		buttonWithLabel_sortie_relais_c1_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		buttonWithLabel_sortie_relais_c1_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_c2()
{
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		presenter->c_sav_test_cps(5);
		u8TimerRelaisC2 = 4;
		buttonWithLabel_sortie_relais_c2_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		buttonWithLabel_sortie_relais_c2_geot.invalidate();
	}
	else if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		presenter->c_sav_test_cps(44);
		u8TimerRelaisC2 = 3;
		buttonWithLabel_sortie_relais_c2_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		buttonWithLabel_sortie_relais_c2_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_spa1()
{
	presenter->c_sav_test_cps(45);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonSpa1On)
		{
			bButtonSpa1On = true;
			buttonWithLabel_sortie_spa1_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonSpa1On = false;
			buttonWithLabel_sortie_spa1_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_spa1_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_spa2()
{
	presenter->c_sav_test_cps(46);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonSpa2On)
		{
			bButtonSpa2On = true;
			buttonWithLabel_sortie_spa2_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonSpa2On = false;
			buttonWithLabel_sortie_spa2_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_spa2_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_puits()
{
	presenter->c_sav_test_cps(47);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonPuitsOn)
		{
			bButtonPuitsOn = true;
			buttonWithLabel_sortie_relais_puits_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonPuitsOn = false;
			buttonWithLabel_sortie_relais_puits_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_relais_puits_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_cric_vent()
{
	presenter->c_sav_test_cps(48);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonVentCaptsOn)
		{
			bButtonVentCaptsOn = true;
			buttonWithLabel_sortie_circ_vent_capt_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonVentCaptsOn = false;
			buttonWithLabel_sortie_circ_vent_capt_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_circ_vent_capt_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_relais_circ_prim()
{
	presenter->c_sav_test_cps(49);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonCircPrimOn)
		{
			bButtonCircPrimOn = true;
			buttonWithLabel_sortie_relais_circ_prim_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonCircPrimOn = false;
			buttonWithLabel_sortie_relais_circ_prim_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_relais_circ_prim_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_out_ventil()
{
	presenter->c_sav_test_cps(50);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonOutVentil)
		{
			bButtonOutVentil = true;
			buttonWithLabel_sortie_vent_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonOutVentil = false;
			buttonWithLabel_sortie_vent_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_vent_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_out_option()
{
	presenter->c_sav_test_cps(51);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonOutOption)
		{
			bButtonOutOption = true;
			buttonWithLabel_sortie_option_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonOutOption = false;
			buttonWithLabel_sortie_option_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_option_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_out_det1()
{
	presenter->c_sav_test_cps(52);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonOutDet1)
		{
			bButtonOutDet1 = true;
			buttonWithLabel_sortie_det1_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonOutDet1 = false;
			buttonWithLabel_sortie_det1_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_det1_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_out_det2()
{
	presenter->c_sav_test_cps(53);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonOutDet2)
		{
			bButtonOutDet2 = true;
			buttonWithLabel_sortie_det2_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonOutDet2 = false;
			buttonWithLabel_sortie_det2_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_det2_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_out_det3()
{
	presenter->c_sav_test_cps(54);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonOutDet3)
		{
			bButtonOutDet3 = true;
			buttonWithLabel_sortie_det3_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonOutDet3 = false;
			buttonWithLabel_sortie_det3_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_det3_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_out_det4()
{
	presenter->c_sav_test_cps(55);
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER)
	{
		if (!bButtonOutDet4)
		{
			bButtonOutDet4 = true;
			buttonWithLabel_sortie_det4_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
		}
		else
		{
			bButtonOutDet4 = false;
			buttonWithLabel_sortie_det4_inv.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_BEIGE_CLICKED_L168XH102_ID));
		}
		buttonWithLabel_sortie_det4_inv.invalidate();
	}
}

void  Maintenance_test_composantsView::bouton_detendeur()
{
	//Geotwin
	presenter->c_sav_test_cps(7);
	u8TimerDetGeot = 4;
	buttonWithLabel_sortie_detendeur_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
	buttonWithLabel_sortie_detendeur_geot.invalidate();

}

void  Maintenance_test_composantsView::bouton_relais_geot()
{
	//Geotwin
	presenter->c_sav_test_cps(8);
	u8TimerRelaisGeot = 4;
	buttonWithLabel_sortie_relais_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
	buttonWithLabel_sortie_relais_geot.invalidate();
}

void  Maintenance_test_composantsView::bouton_circulateur_geot()
{
	//Geotwin
	presenter->c_sav_test_cps(6);
	u8TimerRelaisCircGeot = 4;
	buttonWithLabel_sortie_circulateur_geot.setBitmaps(touchgfx::Bitmap(BITMAP_BOUTON_VERT_UNCLICKED_L168XH102_ID), touchgfx::Bitmap(BITMAP_BOUTON_VERT_CLICKED_L168XH102_ID));
	buttonWithLabel_sortie_circulateur_geot.invalidate();
}

void Maintenance_test_composantsView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Maintenance_test_composantsView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Maintenance_test_composantsView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Maintenance_test_composantsView::changeDate(S_DATE *sDate)
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
