#include <gui/test_pac_screen/Test_pacView.hpp>

Test_pacView::Test_pacView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	bConnexionDistance = false;
	changeDate(&sDate);
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutEther(&sCycEther);
	changeStatutPAC(&sStatut_PAC);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_TEST_PAC_MAINTENANCE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	ModeTest = sParam_Test_PAC.ModeTest;
	bTestPAC = sParam_Test_PAC.bTestPAC;
	Pw = sParam_Test_PAC.Pw;
	Teau = sParam_Test_PAC.Teau;

	if (Teau == 0) Teau = 1;

	if (bTestPAC == 0)
	{
		toggleButton_oui_oui_non_test_pac.forceState(false);
		toggleButton_oui_oui_non_test_pac.setTouchable(true);
		toggleButton_non_oui_non_test_pac.forceState(true);
		toggleButton_non_oui_non_test_pac.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_test_pac.forceState(true);
		toggleButton_oui_oui_non_test_pac.setTouchable(false);
		toggleButton_non_oui_non_test_pac.forceState(false);
		toggleButton_non_oui_non_test_pac.setTouchable(true);
	}
	toggleButton_oui_oui_non_test_pac.invalidate();
	toggleButton_non_oui_non_test_pac.invalidate();

	update_pw_pac();
	update_mode_pac();
	update_test_code();
}

void Test_pacView::bouton_retour()
{
	sParam_Test_PAC.ModeTest = T_CHAUD;
	sParam_Test_PAC.Pw = 0;
	sParam_Test_PAC.Teau = 1;
	sParam_Test_PAC.bTestPAC = false;
}

void Test_pacView::setupScreen()
{
    Test_pacViewBase::setupScreen();
}

void Test_pacView::tearDownScreen()
{
    Test_pacViewBase::tearDownScreen();
}

void Test_pacView::bouton_oui()
{
	if(toggleButton_oui_oui_non_test_pac.getState())
	{
		toggleButton_non_oui_non_test_pac.forceState(false);
		toggleButton_non_oui_non_test_pac.setTouchable(true);
		toggleButton_non_oui_non_test_pac.invalidate();
		toggleButton_oui_oui_non_test_pac.setTouchable(false);
		toggleButton_oui_oui_non_test_pac.invalidate();
	}
}

void Test_pacView::bouton_non()
{
	if(toggleButton_non_oui_non_test_pac.getState())
	{
		toggleButton_oui_oui_non_test_pac.forceState(false);
		toggleButton_oui_oui_non_test_pac.setTouchable(true);
		toggleButton_oui_oui_non_test_pac.invalidate();
		toggleButton_non_oui_non_test_pac.setTouchable(false);
		toggleButton_non_oui_non_test_pac.invalidate();
	}
}

void Test_pacView::bouton_gauche_pw()
{
	if (Pw > 0) Pw--;
	else Pw = 1;
	update_pw_pac();
}

void Test_pacView::bouton_droit_pw()
{
	if (Pw < 10)Pw++;
	else Pw = 0;
	update_pw_pac();
}

void Test_pacView::update_pw_pac()
{
	if (Pw == 0)
	{
		Unicode::snprintf(textAreaBuffer_Pw_Pac, 5, touchgfx::TypedText(T_TEXT_VALEUR_PUISSANCE_TEST_2_CENTRE_DEFAUT).getText());
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_Pw_Pac, 4, "%d",  (Pw *10));
		Unicode::snprintf(&textAreaBuffer_Pw_Pac[Unicode::strlen(textAreaBuffer_Pw_Pac)], 2,"%");
	}
	textArea_valeur_puissance_test.setWildcard(textAreaBuffer_Pw_Pac);
	textArea_valeur_puissance_test.invalidate();
}

void Test_pacView::bouton_gauche_mode()
{
	if (ModeTest > T_CHAUD) ModeTest--;
	else ModeTest = T_ECS;
	update_mode_pac();
}

void Test_pacView::bouton_droit_mode()
{
	if (ModeTest < T_ECS) ModeTest++;
	else ModeTest = T_CHAUD;
	update_mode_pac();
}

void Test_pacView::update_mode_pac()
{
	switch (ModeTest)
	{
		case T_CHAUD:
		default:
			Unicode::snprintf(textAreaBuffer_Mode_test_Pac, 12, touchgfx::TypedText(T_TEXT_CHAUD_CENTRE_DEFAUT).getText());
			break;
		case T_FROID:
			Unicode::snprintf(textAreaBuffer_Mode_test_Pac, 12, touchgfx::TypedText(T_TEXT_FROID_CENTRE_DEFAUT).getText());
			break;
		case T_PISCINE:
			Unicode::snprintf(textAreaBuffer_Mode_test_Pac, 12, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_DEFAUT).getText());
			break;
		case T_ECS:
			Unicode::snprintf(textAreaBuffer_Mode_test_Pac, 12, touchgfx::TypedText(T_TEXT_ACCUEIL_ECS_CENTRE_DEFAUT).getText());
			break;

	}

	textArea_valeur_mode_test.setWildcard(textAreaBuffer_Mode_test_Pac);
	textArea_valeur_mode_test.invalidate();
}

void Test_pacView::bouton_gauche_test_code()
{
	if(Teau > 1) Teau--;
	else Teau = 199;
	update_test_code();
}

void Test_pacView::bouton_droit_test_code()
{
	if(Teau < 198) Teau++;
	else Teau = 1;
	update_test_code();
}

void Test_pacView::update_test_code()
{
	Unicode::snprintf(textAreaBuffer_Test_Code, 4, "%d", Teau);
	textArea_valeur_test_code.setWildcard(textAreaBuffer_Test_Code);
	textArea_valeur_test_code.invalidate();
}

void Test_pacView::bouton_valider()
{
	if (toggleButton_oui_oui_non_test_pac.getState())
	{
		bTestPAC = 1;
		sParam_Test_PAC.ModeTest = ModeTest;
		sParam_Test_PAC.bTestPAC = bTestPAC;
		sParam_Test_PAC.Pw = Pw;
		sParam_Test_PAC.Teau = Teau;
		//sStatut_PAC.Test = S_TF_PAC;
	}
	else
	{
		bTestPAC = 0;
		sParam_Test_PAC.ModeTest = T_CHAUD;
		sParam_Test_PAC.bTestPAC = 	0;
		sParam_Test_PAC.Pw = 0;
		sParam_Test_PAC.Teau = 1;
		//sStatut_PAC.Test = S_NO_TF;
	}

	presenter->c_sav_test_pac();
}

void Test_pacView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Test_pacView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Test_pacView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
//	if(sConfig_IHM->sOption_PAC.TypeAppoint != sConfig_IHM_old.sOption_PAC.TypeAppoint)
//	{
//		if(sConfig_IHM->sOption_PAC.TypeAppoint != NO_APPOINT)
//		{
//			container_secours_pac.setVisible(true);
//		}
//		else container_secours_pac.setVisible(false);
//		container_secours_pac.invalidate();
//	}
//
//	if(sConfig_IHM->sMode_PAC.bSecours != sConfig_IHM_old.sMode_PAC.bSecours)
//	{
//		if(sConfig_IHM->sMode_PAC.bSecours == 1)
//		{
//			buttonWithIcon_secours_pac_on.setVisible(true);
//		}
//		else buttonWithIcon_secours_pac_on.setVisible(false);
//		buttonWithIcon_secours_pac_on.invalidate();
//	}
//
//	if((sConfig_IHM->sOption_PAC.ECS != sConfig_IHM_old.sOption_PAC.ECS) || (sConfig_IHM->sMode_ECS.bUserAppointECS != sConfig_IHM_old.sMode_ECS.bUserAppointECS))
//	{
//		if(sConfig_IHM->sOption_PAC.ECS == 1 && sConfig_IHM->sMode_ECS.bUserAppointECS == 1)
//		{
//			container_secours_ecs.setVisible(true);
//		}
//		else container_secours_ecs.setVisible(false);
//		container_secours_ecs.invalidate();
//	}
//
//	if(sConfig_IHM->sMode_ECS.bUserECSSecours != sConfig_IHM_old.sMode_ECS.bUserECSSecours)
//	{
//		if(sConfig_IHM->sMode_ECS.bUserECSSecours == 1)
//		{
//			buttonWithIcon_secours_ecs_on.setVisible(true);
//		}
//		else buttonWithIcon_secours_ecs_on.setVisible(false);
//		buttonWithIcon_secours_ecs_on.invalidate();
//	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void Test_pacView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Test_pacView::changeDate(S_DATE *sDate)
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
