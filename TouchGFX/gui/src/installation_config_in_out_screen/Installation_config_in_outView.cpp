#include <gui/installation_config_in_out_screen/Installation_config_in_outView.hpp>


Installation_config_in_outView::Installation_config_in_outView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_AFFECTATION_FCT_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	InxAdaptationLoiDeau = sConfig_IHM.sParam_PAC.InxAdaptationLoiDeau;
	InxAdaptationConsigne = sConfig_IHM.sParam_PAC.InxAdaptationConsigne;
	InxEJP = sConfig_IHM.sParam_PAC.InxEJP;
	InxAbaissementConsigne = sConfig_IHM.sParam_PAC.InxAbaissementConsigne;
	InxDelestage  = sConfig_IHM.sParam_PAC.InxDelestage;
	InxTH1 = sConfig_IHM.sParam_PAC.InxTH1;
	InxTH2 = sConfig_IHM.sParam_PAC.InxTH2;
	InxMarcheArret = sConfig_IHM.sParam_PAC.InxMarcheArret;
	InxChaudFroid = sConfig_IHM.sParam_PAC.InxChaudFroid;
	InxMarcheArretGeneral = sConfig_IHM.sParam_PAC.InxMarcheArretGeneral;
	InxFonction4 = sConfig_IHM.sParam_PAC.InxFonction4;
	InxFonction5 = sConfig_IHM.sParam_PAC.InxFonction5;
	InxFonction6 = sConfig_IHM.sParam_PAC.InxFonction6;
	InxFonction7 = sConfig_IHM.sParam_PAC.InxFonction7;
	OutxCarter = sConfig_IHM.sParam_PAC.OutxCarter;
	OutxRelevePAC = sConfig_IHM.sParam_PAC.OutxRelevePAC;
	OutxModeChaudFroid = sConfig_IHM.sParam_PAC.OutxModeChaudFroid;
	OutxInfoDefautPAC = sConfig_IHM.sParam_PAC.OutxInfoDefautPAC;
	OutxChaudFroidVoie1 = sConfig_IHM.sParam_PAC.OutxChaudFroidVoie1;
	OutxChaudFroidVoie2 = sConfig_IHM.sParam_PAC.OutxChaudFroidVoie2;
	OutxInfoMarcheArret = sConfig_IHM.sParam_PAC.OutxInfoMarcheArret;
	OutxFonction8 = sConfig_IHM.sParam_PAC.OutxFonction8;
	OutxFonction9 = sConfig_IHM.sParam_PAC.OutxFonction9;
	OutxFonction10 = sConfig_IHM.sParam_PAC.OutxFonction10;

	//In TOR
	MAJ_voie_ejp();
	MAJ_voie_delestage();
	MAJ_voie_abaissement();
	MAJ_voie_th1();
	MAJ_voie_th2();
	MAJ_voie_InxMarcheArret();
	MAJ_voie_InxChaudFroid();
	MAJ_voie_InxMarcheArretGeneral();
	MAJ_voie_InxFonction4();
	MAJ_voie_InxFonction5();
	MAJ_voie_InxFonction6();
	MAJ_voie_InxFonction7();
	MAJ_voie_AdaptLoiDeau();
	MAJ_voie_AdaptConsigne();

	//OutTOR
	MAJ_voie_OutxResistance();
	MAJ_voie_OutxReleve();
	MAJ_voie_OutxChaudFroid();
	MAJ_voie_OutxDefautGeneral();
	MAJ_voie_OutxChaudFroid1();
	MAJ_voie_OutxChaudFroid2();
	MAJ_voie_OutxInfoMarcheArret();
	MAJ_voie_OutxFonction8();
	MAJ_voie_OutxFonction9();
	MAJ_voie_OutxFonction10();
}

void Installation_config_in_outView::setupScreen()
{
    Installation_config_in_outViewBase::setupScreen();
}

void Installation_config_in_outView::tearDownScreen()
{
    Installation_config_in_outViewBase::tearDownScreen();
}

void Installation_config_in_outView::MAJ_TabInOutTor()
{
	tabInOutTor[0] = InxAdaptationLoiDeau;
	tabInOutTor[1] = InxAdaptationConsigne;
	tabInOutTor[2] = InxEJP;
	tabInOutTor[3] = InxDelestage;
	tabInOutTor[4] = InxTH1;
	tabInOutTor[5] = InxTH2;
	tabInOutTor[6] = InxMarcheArret;
	tabInOutTor[7] = InxChaudFroid;
	tabInOutTor[8] = InxMarcheArretGeneral;
	tabInOutTor[9] = InxFonction4;
	tabInOutTor[10] = InxFonction5;
	tabInOutTor[11] = InxFonction6;
	tabInOutTor[12] = InxFonction7; //Fin InTOR
	tabInOutTor[13] = InxAbaissementConsigne;

	tabInOutTor[14] = OutxCarter;
	tabInOutTor[15] = OutxRelevePAC;
	tabInOutTor[16] = OutxModeChaudFroid;
	tabInOutTor[17] = OutxInfoDefautPAC;
	tabInOutTor[18] = OutxChaudFroidVoie1;
	tabInOutTor[19] = OutxChaudFroidVoie2;
	tabInOutTor[20] = OutxInfoMarcheArret;
	tabInOutTor[21] = OutxFonction8;
	tabInOutTor[22] = OutxFonction9;
	tabInOutTor[23] = OutxFonction10; //Fin OutTor
}

void Installation_config_in_outView::controle_doublon()
{
	int i;
	int j;

	button_valider.setVisible(true);
	textArea_conflit_entree.setVisible(false);
	button_valider.invalidate();
	textArea_conflit_entree.invalidate();
	textArea_conflit_sortie.setVisible(false);
	textArea_conflit_sortie.invalidate();

	//Controle des affectations en entree
	for (i = 0; i <= 13; i++)
	{
		for (j = i + 1; j <= 13; j++)
		{
			if (tabInOutTor[i] == tabInOutTor[j] && tabInOutTor[i] != 0 && tabInOutTor[j]!= 0
			&& !(i == 0 && j == 1 && tabInOutTor[0] == 13 && tabInOutTor[1]))
			{
				button_valider.setVisible(false);
				textArea_conflit_entree.setVisible(true);
				button_valider.invalidate();
				textArea_conflit_entree.invalidate();
			}
		}
	}

	//Controle des affectations en sortie
	if (textArea_conflit_entree.isVisible() == false)
	{
		for (i = 14; i <= 23; i++)
		{
			for (j = i + 1; j <= 23; j++)
			{
				if (tabInOutTor[i] == tabInOutTor[j] && tabInOutTor[i] != 0 && tabInOutTor[j]!= 0)
				{
					button_valider.setVisible(false);
					textArea_conflit_sortie.setVisible(true);
					button_valider.invalidate();
					textArea_conflit_sortie.invalidate();
				}
			}
		}
	}
}

void Installation_config_in_outView::bouton_ejp()
{
	if (InxEJP < 7) InxEJP++;
	else InxEJP = 0;
	MAJ_voie_ejp();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_ejp()
{
	if (InxEJP != 0 ) Unicode::snprintf(textAreaBufferEJP, 3, "%d", InxEJP);
	else Unicode::snprintf(textAreaBufferEJP, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_ejp.setWildcard(textAreaBufferEJP);
	textArea_num_ejp.invalidate();
}

void Installation_config_in_outView::bouton_delestage()
{
	if (InxDelestage < 7) InxDelestage++;
	else InxDelestage = 0;
	MAJ_voie_delestage();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_delestage()
{
	if (InxDelestage != 0 ) Unicode::snprintf(textAreaBufferDelestage, 3, "%d", InxDelestage);
	else Unicode::snprintf(textAreaBufferDelestage, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_delestage.setWildcard(textAreaBufferDelestage);
	textArea_num_delestage.invalidate();
}

void Installation_config_in_outView::bouton_abaissement()
{
	if (InxAbaissementConsigne < 7) InxAbaissementConsigne++;
	else InxAbaissementConsigne = 0;
	MAJ_voie_abaissement();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_abaissement()
{
	if (InxAbaissementConsigne != 0 ) Unicode::snprintf(textAreaBufferAbaissement, 3, "%d", InxAbaissementConsigne);
	else Unicode::snprintf(textAreaBufferAbaissement, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_abaissement_consigne.setWildcard(textAreaBufferAbaissement);
	textArea_num_abaissement_consigne.invalidate();
}


void Installation_config_in_outView::bouton_th1()
{
	if (InxTH1< 7) InxTH1++;
	else InxTH1 = 0;
	MAJ_voie_th1();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_th1()
{
	if (InxTH1 != 0 ) Unicode::snprintf(textAreaBufferTh1, 3, "%d", InxTH1);
	else Unicode::snprintf(textAreaBufferTh1, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_th_1.setWildcard(textAreaBufferTh1);
	textArea_num_th_1.invalidate();
}


void Installation_config_in_outView::bouton_th2()
{
	if (InxTH2< 7) InxTH2++;
	else InxTH2 = 0;
	MAJ_voie_th2();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_th2()
{
	if (InxTH2 != 0 ) Unicode::snprintf(textAreaBufferTh2, 3, "%d", InxTH2);
	else Unicode::snprintf(textAreaBufferTh2, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_th_2.setWildcard(textAreaBufferTh2);
	textArea_num_th_2.invalidate();
}

void Installation_config_in_outView::bouton_marche_arret_zones()
{
	if (InxMarcheArret< 7) InxMarcheArret++;
	else InxMarcheArret = 0;
	MAJ_voie_InxMarcheArret();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxMarcheArret()
{
	if (InxMarcheArret != 0 ) Unicode::snprintf(textAreaBufferMarcheArretZones, 3, "%d", InxMarcheArret);
	else Unicode::snprintf(textAreaBufferMarcheArretZones, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_marche_zones.setWildcard(textAreaBufferMarcheArretZones);
	textArea_num_marche_zones.invalidate();
}

void Installation_config_in_outView::bouton_chaud_froid()
{
	if (InxChaudFroid< 7) InxChaudFroid++;
	else InxChaudFroid = 0;
	MAJ_voie_InxChaudFroid();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxChaudFroid()
{
	if (InxChaudFroid != 0 ) Unicode::snprintf(textAreaBufferChaudFroid, 3, "%d", InxChaudFroid);
	else Unicode::snprintf(textAreaBufferChaudFroid, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_chaud_zones.setWildcard(textAreaBufferChaudFroid);
	textArea_num_chaud_zones.invalidate();
}

void Installation_config_in_outView::bouton_marche_arret_general()
{
	if (InxMarcheArretGeneral< 7) InxMarcheArretGeneral++;
	else InxMarcheArretGeneral = 0;
	MAJ_voie_InxMarcheArretGeneral();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxMarcheArretGeneral()
{
	if (InxMarcheArretGeneral != 0 ) Unicode::snprintf(textAreaBufferMarcheArretGeneral, 3, "%d", InxMarcheArretGeneral);
	else Unicode::snprintf(textAreaBufferMarcheArretGeneral, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_marche_general.setWildcard(textAreaBufferMarcheArretGeneral);
	textArea_num_marche_general.invalidate();
}

void Installation_config_in_outView::bouton_fonction_4()
{
	if (InxFonction4< 7) InxFonction4++;
	else InxFonction4 = 0;
	MAJ_voie_InxFonction4();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxFonction4()
{
	if (InxFonction4 != 0 ) Unicode::snprintf(textAreaBufferFonction4, 3, "%d", InxFonction4);
	else Unicode::snprintf(textAreaBufferFonction4, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_4.setWildcard(textAreaBufferFonction4);
	textArea_num_fonction_4.invalidate();
}

void Installation_config_in_outView::bouton_fonction_5()
{
	if (InxFonction5< 7) InxFonction5++;
	else InxFonction5 = 0;
	MAJ_voie_InxFonction5();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxFonction5()
{
	if (InxFonction5 != 0 ) Unicode::snprintf(textAreaBufferFonction5, 3, "%d", InxFonction5);
	else Unicode::snprintf(textAreaBufferFonction5, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_5.setWildcard(textAreaBufferFonction5);
	textArea_num_fonction_5.invalidate();
}

void Installation_config_in_outView::bouton_fonction_6()
{
	if (InxFonction6< 7) InxFonction6++;
	else InxFonction6 = 0;
	MAJ_voie_InxFonction6();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxFonction6()
{
	if (InxFonction6 != 0 ) Unicode::snprintf(textAreaBufferFonction6, 3, "%d", InxFonction6);
	else Unicode::snprintf(textAreaBufferFonction6, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_6.setWildcard(textAreaBufferFonction6);
	textArea_num_fonction_6.invalidate();
}

void Installation_config_in_outView::bouton_fonction_7()
{
	if (InxFonction7< 7) InxFonction7++;
	else InxFonction7 = 0;
	MAJ_voie_InxFonction7();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_InxFonction7()
{
	if (InxFonction7 != 0 ) Unicode::snprintf(textAreaBufferFonction7, 3, "%d", InxFonction7);
	else Unicode::snprintf(textAreaBufferFonction7, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_7.setWildcard(textAreaBufferFonction7);
	textArea_num_fonction_7.invalidate();
}

void Installation_config_in_outView::bouton_adapt_loi_deau()
{
	if (InxAdaptationLoiDeau< 7) InxAdaptationLoiDeau++;
	else InxAdaptationLoiDeau = 0;
	MAJ_voie_AdaptLoiDeau();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_AdaptLoiDeau()
{
	if (InxAdaptationLoiDeau != 0 ) Unicode::snprintf(textAreaBufferAdaptLoiDeau, 3, "%d", InxAdaptationLoiDeau);
	else Unicode::snprintf(textAreaBufferAdaptLoiDeau, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_adapt_loi_eau_pv.setWildcard(textAreaBufferAdaptLoiDeau);
	textArea_num_adapt_loi_eau_pv.invalidate();
}

void Installation_config_in_outView::bouton_adapt_consigne()
{
	if (InxAdaptationConsigne< 7) InxAdaptationConsigne++;
	else InxAdaptationConsigne = 0;
	MAJ_voie_AdaptConsigne();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_AdaptConsigne()
{
	if (InxAdaptationConsigne!= 0 ) Unicode::snprintf(textAreaBufferAdaptConsigne, 3, "%d", InxAdaptationConsigne);
	else Unicode::snprintf(textAreaBufferAdaptConsigne, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_adapt_cons_pv.setWildcard(textAreaBufferAdaptConsigne);
	textArea_num_adapt_cons_pv.invalidate();
}

void Installation_config_in_outView::bouton_resistance_carter()
{
	if (OutxCarter < 6) OutxCarter++;
	else OutxCarter = 0;
	MAJ_voie_OutxResistance();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxResistance()
{
	if (OutxCarter!= 0 ) Unicode::snprintf(textAreaBufferResistanceCarter, 3, "%d", OutxCarter);
	else Unicode::snprintf(textAreaBufferResistanceCarter, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_resist_carter.setWildcard(textAreaBufferResistanceCarter);
	textArea_num_resist_carter.invalidate();
}

void Installation_config_in_outView::bouton_releve_PAC()
{
	if (OutxRelevePAC < 6) OutxRelevePAC++;
	else OutxRelevePAC = 0;
	MAJ_voie_OutxReleve();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxReleve()
{
	if (OutxRelevePAC!= 0 ) Unicode::snprintf(textAreaBufferRelevePac, 3, "%d", OutxRelevePAC);
	else Unicode::snprintf(textAreaBufferRelevePac, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_releve_pac.setWildcard(textAreaBufferRelevePac);
	textArea_num_releve_pac.invalidate();
}

void Installation_config_in_outView::bouton_info_chaud_froid()
{
	if (OutxModeChaudFroid < 6) OutxModeChaudFroid++;
	else OutxModeChaudFroid = 0;
	MAJ_voie_OutxChaudFroid();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxChaudFroid()
{
	if (OutxModeChaudFroid!= 0 ) Unicode::snprintf(textAreaBufferChaudFroid, 3, "%d", OutxModeChaudFroid);
	else Unicode::snprintf(textAreaBufferChaudFroid, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_info_chaud_froid.setWildcard(textAreaBufferChaudFroid);
	textArea_num_info_chaud_froid.invalidate();
}

void Installation_config_in_outView::bouton_defaut_general()
{
	if (OutxInfoDefautPAC < 6) OutxInfoDefautPAC++;
	else OutxInfoDefautPAC = 0;
	MAJ_voie_OutxDefautGeneral();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxDefautGeneral()
{
	if (OutxInfoDefautPAC!= 0 ) Unicode::snprintf(textAreaBufferDefautGeneralPac, 3, "%d", OutxInfoDefautPAC);
	else Unicode::snprintf(textAreaBufferDefautGeneralPac, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_def_general.setWildcard(textAreaBufferDefautGeneralPac);
	textArea_num_def_general.invalidate();
}

void Installation_config_in_outView::bouton_chaud_froid_voie_1()
{
	if (OutxChaudFroidVoie1 < 6) OutxChaudFroidVoie1++;
	else OutxChaudFroidVoie1 = 0;
	MAJ_voie_OutxChaudFroid1();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxChaudFroid1()
{
	if (OutxChaudFroidVoie1!= 0 ) Unicode::snprintf(textAreaBufferChaudFroidVoie1, 3, "%d", OutxChaudFroidVoie1);
	else Unicode::snprintf(textAreaBufferChaudFroidVoie1, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_chaud_froid_voie_1.setWildcard(textAreaBufferChaudFroidVoie1);
	textArea_num_chaud_froid_voie_1.invalidate();
}

void Installation_config_in_outView::bouton_chaud_froid_voie_2()
{
	if (OutxChaudFroidVoie2 < 6) OutxChaudFroidVoie2++;
	else OutxChaudFroidVoie2 = 0;
	MAJ_voie_OutxChaudFroid2();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxChaudFroid2()
{
	if (OutxChaudFroidVoie2!= 0 ) Unicode::snprintf(textAreaBufferChaudFroidVoie2, 3, "%d", OutxChaudFroidVoie2);
	else Unicode::snprintf(textAreaBufferChaudFroidVoie2, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_chaud_froid_voie_2.setWildcard(textAreaBufferChaudFroidVoie2);
	textArea_num_chaud_froid_voie_2.invalidate();
}

void Installation_config_in_outView::bouton_info_marche_arret_comp()
{
	if (OutxInfoMarcheArret < 6) OutxInfoMarcheArret++;
	else OutxInfoMarcheArret = 0;
	MAJ_voie_OutxInfoMarcheArret();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxInfoMarcheArret()
{
	if (OutxInfoMarcheArret!= 0 ) Unicode::snprintf(textAreaBufferMarcheArretComp, 3, "%d", OutxInfoMarcheArret);
	else Unicode::snprintf(textAreaBufferMarcheArretComp, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_info_comp.setWildcard(textAreaBufferMarcheArretComp);
	textArea_num_info_comp.invalidate();
}

void Installation_config_in_outView::bouton_fonction_8()
{
	if (OutxFonction8 < 6) OutxFonction8++;
	else OutxFonction8 = 0;
	MAJ_voie_OutxFonction8();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxFonction8()
{
	if (OutxFonction8!= 0 ) Unicode::snprintf(textAreaBufferFonction8, 3, "%d", OutxFonction8);
	else Unicode::snprintf(textAreaBufferFonction8, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_8.setWildcard(textAreaBufferFonction8);
	textArea_num_fonction_8.invalidate();
}

void Installation_config_in_outView::bouton_fonction_9()
{
	if (OutxFonction9 < 6) OutxFonction9++;
	else OutxFonction9 = 0;
	MAJ_voie_OutxFonction9();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxFonction9()
{
	if (OutxFonction9!= 0 ) Unicode::snprintf(textAreaBufferFonction9, 3, "%d", OutxFonction9);
	else Unicode::snprintf(textAreaBufferFonction9, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_9.setWildcard(textAreaBufferFonction9);
	textArea_num_fonction_9.invalidate();
}

void Installation_config_in_outView::bouton_fonction_10()
{
	if (OutxFonction10 < 6) OutxFonction10++;
	else OutxFonction10 = 0;
	MAJ_voie_OutxFonction10();
	MAJ_TabInOutTor();
	controle_doublon();
}

void Installation_config_in_outView::MAJ_voie_OutxFonction10()
{
	if (OutxFonction10!= 0 ) Unicode::snprintf(textAreaBufferFonction10, 3, "%d", OutxFonction10);
	else Unicode::snprintf(textAreaBufferFonction10, 3, touchgfx::TypedText(T_TEXT_NU_CENTRE_DEFAUT).getText());

	textArea_num_fonction_10.setWildcard(textAreaBufferFonction10);
	textArea_num_fonction_10.invalidate();
}

void Installation_config_in_outView::bouton_valider()
{

	sConfig_IHM.sParam_PAC.InxAdaptationLoiDeau = InxAdaptationLoiDeau & 0x0F;
	sConfig_IHM.sParam_PAC.InxAdaptationConsigne = InxAdaptationConsigne & 0x0F;
	sConfig_IHM.sParam_PAC.InxEJP = InxEJP & 0x0F;
	sConfig_IHM.sParam_PAC.InxAbaissementConsigne = InxAbaissementConsigne & 0x0F;
	sConfig_IHM.sParam_PAC.InxDelestage = InxDelestage & 0x0F;
	sConfig_IHM.sParam_PAC.InxTH1 = InxTH1 & 0x0F;
	sConfig_IHM.sParam_PAC.InxTH2 = InxTH2 & 0x0F;
	sConfig_IHM.sParam_PAC.InxMarcheArret = InxMarcheArret & 0x0F;
	sConfig_IHM.sParam_PAC.InxChaudFroid = InxChaudFroid & 0x0F;
	sConfig_IHM.sParam_PAC.InxMarcheArretGeneral = InxMarcheArretGeneral & 0x0F;
	sConfig_IHM.sParam_PAC.InxFonction4 = InxFonction4 & 0x0F;
	sConfig_IHM.sParam_PAC.InxFonction5 = InxFonction5 & 0x0F;
	sConfig_IHM.sParam_PAC.InxFonction6 = InxFonction6 & 0x0F;
	sConfig_IHM.sParam_PAC.InxFonction7 = InxFonction7 & 0x0F;
	sConfig_IHM.sParam_PAC.OutxCarter = OutxCarter & 0x07;
	sConfig_IHM.sParam_PAC.OutxRelevePAC = OutxRelevePAC & 0x07;
	sConfig_IHM.sParam_PAC.OutxModeChaudFroid = OutxModeChaudFroid & 0x07;
	sConfig_IHM.sParam_PAC.OutxInfoDefautPAC = OutxInfoDefautPAC & 0x07;
	sConfig_IHM.sParam_PAC.OutxChaudFroidVoie1 = OutxChaudFroidVoie1 & 0x07;
	sConfig_IHM.sParam_PAC.OutxChaudFroidVoie2 = OutxChaudFroidVoie2 & 0x07;
	sConfig_IHM.sParam_PAC.OutxInfoMarcheArret = OutxInfoMarcheArret & 0x07;
	sConfig_IHM.sParam_PAC.OutxFonction8 = OutxFonction8 & 0x07;
	sConfig_IHM.sParam_PAC.OutxFonction9 = OutxFonction9 & 0x07;
	sConfig_IHM.sParam_PAC.OutxFonction10 = OutxFonction10 & 0x07;
	//
	presenter->c_install_param();
	application().gotoInstallationScreenNoTransition();
}

void Installation_config_in_outView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_config_in_outView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_config_in_outView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_config_in_outView::changeDate(S_DATE *sDate)
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
