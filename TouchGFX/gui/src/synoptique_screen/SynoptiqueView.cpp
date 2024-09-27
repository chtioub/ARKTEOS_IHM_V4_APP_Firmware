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


	// Récupération des progs
#ifndef SIMULATOR
	//presenter->c_prog_piscine(false);
#endif
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
		Unicode::snprintfFloat(textAreaBuffer_Temp_HP_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1)/10));
		textArea_temp_HP_invert.setWildcard(textAreaBuffer_Temp_HP_Inv);
		textArea_temp_HP_invert.invalidate();
		Unicode::snprintfFloat(textAreaBuffer_Temp_BP_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1)/10));
		textArea_temp_BP_invert.setWildcard(textAreaBuffer_Temp_BP_Inv);
		textArea_temp_BP_invert.invalidate();
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
		textArea_Hz_comp_invert.setWildcard(textAreaBuffer_Hz_comp_invert);
		textArea_Hz_comp_invert.invalidate();
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



