#include <gui/synoptique_screen/SynoptiqueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>
SynoptiqueView::SynoptiqueView()
{
//	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sCyclRegFrigo_old, 0, sizeof(sCyclRegFrigo_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
//	changeConfig(&sConfig_IHM);
//	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_SYNOPTIQUE_MAINTENANCE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    changeStatutCyclFrigo(&sCyclRegFrigo[0]);
    u8Page = 1;
    update_container();

	// Récupération des progs
#ifndef SIMULATOR
	//presenter->c_prog_piscine(false);
#endif
}

void SynoptiqueView::bouton_gauche()
{
	if (u8Page == 2) u8Page = 1;
	update_container();
}

void SynoptiqueView::bouton_droit()
{
	if (u8Page == 1) u8Page = 2;
	update_container();
}

void SynoptiqueView::update_container()
{
	container_ajpac_1.setVisible(false);
	container_ajpac_2.setVisible(false);
	container_geotwin_inverterra.setVisible(false);
	container_mitsu_1.setVisible(false);
	container_mitsu_2.setVisible(false);
	Image_ajpac_froid_P1.setVisible(false);
	Image_ajpac_double_P1.setVisible(false);
	Image_ajpac_simple_semi_P1.setVisible(false);
	Image_ajpac_simple_P2.setVisible(false);
	Image_ajpac_semi_P2.setVisible(false);
	Image_ajpac_double_P2.setVisible(false);
	Image_ajpac_froid_P2.setVisible(false);
	Image_frigo_mitsu_froid.setVisible(false);
	Image_frigo_mitsu_chaud.setVisible(false);
	Image_detendeur_mitsu_zuran_froid.setVisible(false);
	Image_trait_violet_mitsu_baguio_froid.setVisible(false);
	Image_detendeur_mitsu_zuran_chaud.setVisible(false);
	Image_trait_orange_mitsu_baguio_chaud.setVisible(false);
	Image_trait_rouge_hydrau_mitsu.setVisible(false);
	Image_trait_violet_hydrau_mitsu.setVisible(false);
	Image_trait_bleu_hydrau_mitsu.setVisible(false);
	Image_circuit_hydrau_zuran_baguio.setVisible(false);
	Image_maison.setVisible(false);

	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		default:
		case AJPAC_III:
			if (u8Page == 1)
			{
				container_ajpac_2.setVisible(false);
				container_ajpac_2.invalidate();
				container_ajpac_1.setVisible(true);
				container_ajpac_1.invalidate();

				Image_maison.setVisible(true);
				if (sStatut_PAC.S_Mode == S_FROID)
				{
					Image_ajpac_froid_P1.setVisible(true);
				}
				else if (sCyclRegFrigo[0].pac.ajpac.sStatut_Frigo_AJP.u8Mode_Comp == 3)
				{
					Image_ajpac_double_P1.setVisible(true);
				}
				else Image_ajpac_simple_semi_P1.setVisible(true);
			}
			else
			{
				Image_ajpac_froid_P1.setVisible(false);
				Image_ajpac_froid_P1.invalidate();
				Image_ajpac_double_P1.setVisible(false);
				Image_ajpac_double_P1.invalidate();
				Image_ajpac_simple_semi_P1.setVisible(false);
				Image_ajpac_simple_semi_P1.invalidate();

				container_ajpac_1.setVisible(false);
				container_ajpac_1.invalidate();
				container_ajpac_2.setVisible(true);
				container_ajpac_2.invalidate();
				if (sStatut_PAC.S_Mode == S_FROID)
				{
					Image_ajpac_froid_P2.setVisible(true);
					Image_ajpac_froid_P2.invalidate();
				}
				else if (sCyclRegFrigo[0].pac.ajpac.sStatut_Frigo_AJP.u8Mode_Comp == 3)
				{
					Image_ajpac_double_P2.setVisible(true);
					Image_ajpac_double_P2.invalidate();
				}
				else if (sCyclRegFrigo[0].pac.ajpac.sStatut_Frigo_AJP.u8Mode_Comp == 2)
				{
					Image_ajpac_semi_P2.setVisible(true);
					Image_ajpac_semi_P2.invalidate();
				}
				else
				{
					Image_ajpac_simple_P2.setVisible(true);
					Image_ajpac_simple_P2.invalidate();
				}
			}

			button_droite_synoptique.setVisible(true);
			button_gauche_synoptique.setVisible(true);
//			Image_ajpac_froid_P1.invalidate();
//			Image_ajpac_double_P1.invalidate();
//			Image_ajpac_simple_semi_P1.invalidate();
//			Image_ajpac_simple_P2.invalidate();
//			Image_ajpac_semi_P2.invalidate();
//			Image_ajpac_double_P2.invalidate();
//			Image_ajpac_froid_P2.invalidate();
			break;
		case GEOTWIN_IV:
		case GEOINVERTER:
			if (sConfig_IHM.sModele_PAC.bReversible == 1) sStatut_PAC.S_Mode == S_FROID? Image_comp_rev_froid_seul.setVisible(true) : Image_comp_rev_chaud_seul.setVisible(true);
			if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2) container_comp2_geo.setVisible(true);
			container_geotwin_inverterra.setVisible(true);
			button_droite_synoptique.setVisible(false);
			button_gauche_synoptique.setVisible(false);
			Image_maison.setVisible(true);
			Image_comp_rev_froid_seul.invalidate();
			Image_comp_rev_chaud_seul.invalidate();
			break;
		case BAGUIO_ZURAN_IV:
		case TIMAX_III:
			if(u8Page == 1)
			{
				Image_maison.setVisible(true);
				if (sStatut_PAC.S_Mode == S_FROID)
				{
					Image_frigo_mitsu_froid.setVisible(true);
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN_PUZ)
					{
						Image_detendeur_mitsu_zuran_froid.setVisible(true);
					}
					else
					{
						Image_trait_violet_mitsu_baguio_froid.setVisible(true);
					}
				}
				else
				{
					Image_frigo_mitsu_chaud.setVisible(true);
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN_PUZ)
					{
						Image_detendeur_mitsu_zuran_chaud.setVisible(true);
					}
					else
					{
						Image_trait_orange_mitsu_baguio_chaud.setVisible(true);
					}
				}
			}
			else
			{
				Image_circuit_hydrau_zuran_baguio.setVisible(true);
				if (sStatut_PAC.S_Mode == S_FROID)
				{
					Image_trait_violet_hydrau_mitsu.setVisible(true);
					Image_trait_bleu_hydrau_mitsu.setVisible(true);
				}
				else
				{
					Image_trait_orange_hydrau_mitsu.setVisible(true);
					Image_trait_rouge_hydrau_mitsu.setVisible(true);
				}
			}


			if (u8Page == 1) container_mitsu_1.setVisible(true);
			else container_mitsu_2.setVisible(true);
			button_droite_synoptique.setVisible(true);
			button_gauche_synoptique.setVisible(true);
			Image_frigo_mitsu_froid.invalidate();
			Image_frigo_mitsu_chaud.invalidate();
			Image_detendeur_mitsu_zuran_froid.invalidate();
			Image_trait_violet_mitsu_baguio_froid.invalidate();
			Image_detendeur_mitsu_zuran_chaud.invalidate();
			Image_trait_orange_mitsu_baguio_chaud.invalidate();
			Image_trait_rouge_hydrau_mitsu.invalidate();
			Image_trait_violet_hydrau_mitsu.invalidate();
			Image_trait_bleu_hydrau_mitsu.invalidate();
			Image_circuit_hydrau_zuran_baguio.invalidate();
			break;
		case PHOENIX:
			break;
	}
	button_droite_synoptique.invalidate();
	button_gauche_synoptique.invalidate();
	container_ajpac_1.invalidate();
	container_ajpac_2.invalidate();
	container_geotwin_inverterra.invalidate();
	container_mitsu_1.invalidate();
	container_mitsu_2.invalidate();
	Image_maison.invalidate();
}


void SynoptiqueView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void SynoptiqueView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void SynoptiqueView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void SynoptiqueView::changeDate(S_DATE *sDate)
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

void SynoptiqueView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	int i16TempCond = 0;
	int i16TempEvap = 0;
//	if(sCyclRegFrigo_old.pac. != sCyclRegFrigo->pac)
//	{
		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Prim_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire)/10));
		textArea_temp_DCh_invert.setWildcard(textAreaBuffer_Temp_Dep_Prim_Inv);
		textArea_temp_DCh_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_Ret_Prim_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire)/10));
		textArea_temp_RCh_invert.setWildcard(textAreaBuffer_Temp_Ret_Prim_Inv);
		textArea_temp_RCh_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_Ret_Capt_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur)/10));
		textArea_temp_RCa_invert.setWildcard(textAreaBuffer_Temp_Ret_Capt_Inv);
		textArea_temp_RCa_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Capt_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur)/10));
		textArea_temp_DCa_invert.setWildcard(textAreaBuffer_Temp_Dep_Capt_Inv);
		textArea_temp_DCa_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_Ext_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur)/10));
		textArea_temp_ext_invert.setWildcard(textAreaBuffer_Temp_Ext_Inv);
		textArea_temp_ext_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_HP1_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1)/10));
		textArea_temp_HP1_invert.setWildcard(textAreaBuffer_Temp_HP1_Inv);
		textArea_temp_HP1_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_BP1_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1)/10));
		textArea_temp_BP1_invert.setWildcard(textAreaBuffer_Temp_BP1_Inv);
		textArea_temp_BP1_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_Liq_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide)/10));
		textArea_temp_liquide_invert.setWildcard(textAreaBuffer_Temp_Liq_Inv);
		textArea_temp_liquide_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Press_Cond_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1)/10));
		textArea_pression_temp_hp_invert.setWildcard1(textAreaBuffer_Press_Cond_Inv);
		Unicode::snprintfFloat(textAreaBuffer_Press_Evap_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1)/10));
		textArea_pression_temp_bp_invert.setWildcard1(textAreaBuffer_Press_Evap_Inv);

		i16TempCond = ConvertPressionToTemperature(GAZ_R454C, 1, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 + 10);
		i16TempEvap = ConvertPressionToTemperature(GAZ_R454C, 0, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 + 10);
		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond_Inv, 7,"%.1f", ((float)(i16TempCond)/10));
		textArea_pression_temp_hp_invert.setWildcard2(textAreaBuffer_Temp_Cond_Inv);
		textArea_pression_temp_hp_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_Evap_Inv, 7,"%.1f", ((float)(i16TempEvap)/10));
		textArea_pression_temp_bp_invert.setWildcard2(textAreaBuffer_Temp_Evap_Inv);
		textArea_pression_temp_bp_invert.invalidate();
		Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_Inv, 6,"%d", sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16Temp_HP_Cible[0]);
		textArea_temp_HP_cible_invert.setWildcard(textAreaBuffer_Temp_HP_Cible_Inv);
		textArea_temp_HP_cible_invert.invalidate();
		Unicode::snprintf(textAreaBuffer_Debit_Prim_Inv, 6,"%d", sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.u16DebitPrimaire);
		textArea_debit_chauf_invert.setWildcard(textAreaBuffer_Debit_Prim_Inv);
		textArea_debit_chauf_invert.invalidate();
		Unicode::snprintf(textAreaBuffer_Debit_Capt_Inv, 6,"%d", sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.u16DebitCapteur);
		textArea_debit_capt_invert.setWildcard(textAreaBuffer_Debit_Capt_Inv);
		textArea_debit_capt_invert.invalidate();
		Unicode::snprintf(textAreaBuffer_Percent_Circ_Cap_Inv, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurCapteur);
		textArea_circ_cap_invert.setWildcard(textAreaBuffer_Percent_Circ_Cap_Inv);
		textArea_circ_cap_invert.invalidate();
		Unicode::snprintf(textAreaBuffer_Percent_Circ_Prim_Inv, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire);
		textArea_circ_chauf_invert.setWildcard(textAreaBuffer_Percent_Circ_Prim_Inv);
		textArea_circ_chauf_invert.invalidate();
		Unicode::snprintf(textAreaBuffer_Hz_comp_invert, 4,"%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorRunningSpeed / 60);
		textArea_on_off_comp_1.setWildcard(textAreaBuffer_Hz_comp_invert);
		textArea_on_off_comp_1.invalidate();
		Unicode::snprintf(textAreaBuffer_Position_EEV, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u16PositionDetendeur1);
		textArea_EEV_invert.setWildcard(textAreaBuffer_Position_EEV);
		textArea_EEV_invert.invalidate();

		if(sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Appoint1 || sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Appoint2_3)
		{
			textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		}
		else textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_appoint_invert.invalidate();


//		textArea_temp_ballon_froid.setTypedText(touchgfx::TypedText(T_TEXT_BALLON_TAMPON_FROID_GAUCHE_DEFAUT));

		memcpy(&sCyclRegFrigo_old, sCyclRegFrigo, sizeof(S_CYCL_REG_FRI));
//	}

}

void SynoptiqueView::setupScreen()
{
    SynoptiqueViewBase::setupScreen();
}

void SynoptiqueView::tearDownScreen()
{
	SynoptiqueViewBase::tearDownScreen();
}

void SynoptiqueView::bouton_retour()
{
	if(bPageUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else application().gotoMaintenanceScreenNoTransition();
}



