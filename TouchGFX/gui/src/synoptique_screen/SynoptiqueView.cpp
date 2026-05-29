#include <gui/synoptique_screen/SynoptiqueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>
#include <stdlib.h>
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
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	changeStatutPrimaire(&sStatut_Primaire);
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
	if (u8Page == 2)
	{
		u8Page = 1;
		update_container();
	}
}

void SynoptiqueView::bouton_droit()
{
	if (u8Page == 1)
	{
		u8Page = 2;
		update_container();
	}
}

void SynoptiqueView::update_container()
{
	container_ajpac_1.setVisible(false);
	container_ajpac_1.invalidate();
	container_ajpac_2.setVisible(false);
	container_ajpac_2.invalidate();
	container_geotwin_inverterra.setVisible(false);
	container_geotwin_inverterra.invalidate();
	container_mitsu_1.setVisible(false);
	container_mitsu_1.invalidate();
	container_mitsu_2.setVisible(false);
	container_mitsu_2.invalidate();
	container_comp2_geo.setVisible(false);
	container_comp2_geo.invalidate();
	Image_ajpac_froid_P1.setVisible(false);
	Image_ajpac_froid_P1.invalidate();
	Image_ajpac_double_P1.setVisible(false);
	Image_ajpac_double_P1.invalidate();
	Image_ajpac_simple_semi_P1.setVisible(false);
	Image_ajpac_simple_semi_P1.invalidate();
	Image_ajpac_simple_P2.setVisible(false);
	Image_ajpac_simple_P2.invalidate();
	Image_ajpac_semi_P2.setVisible(false);
	Image_ajpac_semi_P2.invalidate();
	Image_ajpac_double_P2.setVisible(false);
	Image_ajpac_double_P2.invalidate();
	Image_ajpac_froid_P2.setVisible(false);
	Image_ajpac_froid_P2.invalidate();
	Image_frigo_mitsu_froid.setVisible(false);
	Image_frigo_mitsu_froid.invalidate();
	Image_frigo_mitsu_chaud.setVisible(false);
	Image_frigo_mitsu_chaud.invalidate();
	Image_detendeur_mitsu_zuran_froid.setVisible(false);
	Image_detendeur_mitsu_zuran_froid.invalidate();
	Image_trait_violet_mitsu_baguio_froid.setVisible(false);
	Image_trait_violet_mitsu_baguio_froid.invalidate();
	Image_detendeur_mitsu_zuran_chaud.setVisible(false);
	Image_detendeur_mitsu_zuran_chaud.invalidate();
	Image_trait_orange_mitsu_baguio_chaud.setVisible(false);
	Image_trait_orange_mitsu_baguio_chaud.invalidate();
	Image_trait_rouge_hydrau_mitsu.setVisible(false);
	Image_trait_rouge_hydrau_mitsu.invalidate();
	Image_trait_violet_hydrau_mitsu.setVisible(false);
	Image_trait_violet_hydrau_mitsu.invalidate();
	Image_trait_bleu_hydrau_mitsu.setVisible(false);
	Image_trait_bleu_hydrau_mitsu.invalidate();
	Image_circuit_hydrau_zuran_baguio.setVisible(false);
	Image_circuit_hydrau_zuran_baguio.invalidate();
	Image_comp_rev_froid_seul.setVisible(false);
	Image_comp_rev_froid_seul.invalidate();
	Image_comp_rev_chaud_seul.setVisible(false);
	Image_comp_rev_chaud_seul.invalidate();
	Image_maison.setVisible(false);
	Image_maison.invalidate();
	Image_retour_eau_timax.setVisible(false);
	Image_retour_eau_timax.invalidate();
	Image_detendeur_ligne_liquide.setVisible(false);
	Image_detendeur_ligne_liquide.invalidate();
	textArea_temp_retour_eau_mitsu.setVisible(false);
	textArea_temp_retour_eau_mitsu.invalidate();
	textArea_temp_ext.setVisible(false);
	textArea_temp_ext.invalidate();
	textArea_EEVB_mitsu.setVisible(false);
	textArea_EEVB_mitsu.invalidate();
	textArea_EEVC_mitsu.setVisible(false);
	textArea_EEVC_mitsu.invalidate();

	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		default:
		case AJPAC_III:
			if (u8Page == 2)
			{
				if (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.V4V_R410 == true)
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
				container_ajpac_2.setVisible(true);
				container_ajpac_2.invalidate();

			}
			else
			{
				Image_maison.setVisible(true);
				Image_maison.invalidate();
				textArea_temp_ext.setVisible(true);
				textArea_temp_ext.invalidate();

				if (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.V4V_R410 == true)
				{
					Image_ajpac_froid_P1.setVisible(true);
					Image_ajpac_froid_P1.invalidate();
				}
				else if (sCyclRegFrigo[0].pac.ajpac.sStatut_Frigo_AJP.u8Mode_Comp == 3)
				{
					Image_ajpac_double_P1.setVisible(true);
					Image_ajpac_double_P1.invalidate();
				}
				else
				{
					Image_ajpac_simple_semi_P1.setVisible(true);
					Image_ajpac_simple_semi_P1.invalidate();
				}
				container_ajpac_1.setVisible(true);
				container_ajpac_1.invalidate();
			}
			button_droite_synoptique.setVisible(true);
			button_gauche_synoptique.setVisible(true);
			button_droite_synoptique.invalidate();
			button_gauche_synoptique.invalidate();
			break;
		case GEOTWIN_IV:
		case GEOINVERTER:
			//Bloc V4V
			if (sConfig_IHM.sModele_PAC.bReversible == 1)
			{

				if ((sCyclRegFrigo->pac.geotwin.OutTor.REL_V4V == false && sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
				||(sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.V4V == true && sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER))
				{
					Image_comp_chaud_seul.setVisible(false);
					Image_comp_chaud_seul.invalidate();
					Image_comp_rev_froid_seul.setVisible(true);
				}
				else
				{
					Image_comp_chaud_seul.setVisible(false);
					Image_comp_chaud_seul.invalidate();
					Image_comp_rev_chaud_seul.setVisible(true);
				}
			}
			//Bloc appoint
			if (sConfig_IHM.sOption_PAC.TypeAppoint == ELEC)
			{
				Image_no_appoint.setVisible(false);
				Image_no_appoint.invalidate();
				Image_appoint.setVisible(true);
				Image_appoint.invalidate();
				textArea_appoint_invert.setVisible(true);
				textArea_appoint_invert.invalidate();
			}
			else
			{
				Image_appoint.setVisible(false);
				Image_appoint.invalidate();
				textArea_appoint_invert.setVisible(false);
				textArea_appoint_invert.invalidate();
				Image_no_appoint.setVisible(true);
				Image_no_appoint.invalidate();
			}
			//Bloc comp 2
			if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2)
			{
				container_comp2_geo.setVisible(true);
				container_comp2_geo.invalidate();
				textArea_label_comp1.setVisible(true);
				textArea_label_comp2.setVisible(true);

			}
			else
			{
				textArea_label_comp1.setVisible(false);
				textArea_label_comp2.setVisible(false);
			}
			textArea_label_comp1.invalidate();
			textArea_label_comp2.invalidate();

			container_geotwin_inverterra.setVisible(true);
			button_droite_synoptique.setVisible(false);
			button_gauche_synoptique.setVisible(false);
			Image_maison.setVisible(true);
			Image_comp_rev_froid_seul.invalidate();
			Image_comp_rev_chaud_seul.invalidate();
			break;
		case BAGUIO_ZURAN_IV:
			if(u8Page == 1)
			{
				Image_maison.setVisible(true);
				textArea_temp_ext.setVisible(true);
				//BAGUIO PP P1
				if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PP)
				{
					Image_frigo_mitsu_chaud.setVisible(true);
					Image_trait_orange_mitsu_baguio_chaud.setVisible(true);
					textArea_percent_ventil_2_mitsu.setVisible(false);
					textArea_EEVA_mitsu.setVisible(true);
				}
				//BAGUIO
				else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO || sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PUZ)
				{
					Image_frigo_mitsu_chaud.setVisible(true);
					Image_trait_orange_mitsu_baguio_chaud.setVisible(true);
					if(sConfig_IHM.sModele_PAC.Gaz_C1 != GAZ_R32)
					{
						Image_detendeur_ligne_liquide.setVisible(true);
						textArea_EEVB_mitsu.setVisible(true);
					}
				}
				//ZURAN
				else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN_PUZ || sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN)
				{
					Image_frigo_mitsu_chaud.setVisible(true);
					Image_detendeur_mitsu_zuran_chaud.setVisible(true);
					textArea_EEVC_mitsu.setVisible(true);
					Image_detendeur_ligne_liquide.setVisible(true);
					textArea_EEVB_mitsu.setVisible(true);
				}
				else
				{
					Image_frigo_mitsu_chaud.setVisible(true);
					Image_detendeur_mitsu_zuran_chaud.setVisible(true);
					textArea_EEVC_mitsu.setVisible(true);
				}
			}
			else
			{
				Image_circuit_hydrau_zuran_baguio.setVisible(true);
				Image_trait_orange_hydrau_mitsu.setVisible(true);
				Image_trait_rouge_hydrau_mitsu.setVisible(true);
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
			textArea_EEVC_mitsu.invalidate();
			textArea_percent_ventil_2_mitsu.invalidate();
			textArea_EEVA_mitsu.invalidate();
			break;
		case TIMAX_III:
			if(u8Page == 1)
			{
				Image_maison.setVisible(true);
				textArea_temp_ext.setVisible(true);
				Image_frigo_mitsu_chaud.setVisible(true);
				Image_detendeur_ligne_liquide.setVisible(true);
				textArea_EEVB_mitsu.setVisible(true);

				if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO || sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PUZ )
				{
					Image_trait_orange_mitsu_baguio_chaud.setVisible(true);
				}
				else
				{
					Image_detendeur_mitsu_zuran_chaud.setVisible(true);
					textArea_EEVC_mitsu.setVisible(true);
				}
			}
			else
			{
				Image_circuit_hydrau_zuran_baguio.setVisible(true);
				Image_trait_orange_hydrau_mitsu.setVisible(true);
				Image_trait_rouge_hydrau_mitsu.setVisible(true);

				textArea_unite_exterieure.setVisible(true);
				trait_point_tille_horiz_bas.setVisible(true);
				trait_point_tille_horiz_haut.setVisible(true);
				trait_point_tille_vert.setVisible(true);
				textArea_unite_exterieure.invalidate();
				trait_point_tille_horiz_bas.invalidate();
				trait_point_tille_horiz_haut.invalidate();
				trait_point_tille_vert.invalidate();
				if(sConfig_IHM.sModele_PAC.Gaz_C1 != GAZ_R32)
				{
					textArea_temp_retour_eau_mitsu.setVisible(true);
					textArea_temp_retour_eau_mitsu.invalidate();
					Image_retour_eau_timax.setVisible(true);
					Image_retour_eau_timax.invalidate();
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
			Image_detendeur_ligne_liquide.invalidate();
			textArea_EEVB_mitsu.invalidate();
			textArea_EEVC_mitsu.invalidate();
			break;
		case PHOENIX:
			break;
	}
	changeStatutCyclFrigo(&sCyclRegFrigo[0]);
	changeStatutPrimaire(&sStatut_Primaire);
	changeStatutPAC(&sStatut_PAC);
}


void SynoptiqueView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
		{
			default:
			case AJPAC_III:
				if (u8Page == 2)
				{
					if(sStatut_PAC->sOutTor.Pw_Relec == 0)
					{
						textArea_appoint_ajp.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
					}
					else textArea_appoint_ajp.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
					textArea_appoint_ajp.invalidate();
				}
				break;
			case GEOTWIN_IV:
				if(sStatut_PAC->sOutTor.Pw_Relec == 0)
				{
					textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
				}
				else textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
				textArea_appoint_invert.invalidate();
				break;
			case GEOINVERTER:
				if(sStatut_PAC->sOutTor.Pw_Relec == 0)
				{
					textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
				}
				else textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
				textArea_appoint_invert.invalidate();
				break;
			case BAGUIO_ZURAN_IV:
			case TIMAX_III:
				if(u8Page == 1)
				{

				}
				else
				{
					if(sStatut_PAC->sOutTor.Pw_Relec == 0)
					{
						textArea_appoint_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
					}
					else textArea_appoint_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
					textArea_appoint_mitsu.invalidate();
				}
				break;
			case PHOENIX:
				break;
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

void SynoptiqueView::changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire)
{
	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
	{
		default:
		case AJPAC_III:
			if (u8Page == 2)
			{
				Unicode::snprintf(textAreaBuffer_T_Dep_Prim_ajp, 7, sStatut_Primaire->i16TeauDepart < 0 ? "-%d.%d" : "%d.%d", abs(sStatut_Primaire->i16TeauDepart / 10), abs(sStatut_Primaire->i16TeauDepart % 10));
				textArea_temp_dep_ch_ajp.setWildcard(textAreaBuffer_T_Dep_Prim_ajp);
				textArea_temp_dep_ch_ajp.invalidate();
				Unicode::snprintf(textAreaBuffer_T_Ret_Prim_ajp, 7, sStatut_Primaire->i16TeauRetour < 0 ? "-%d.%d" : "%d.%d", abs(sStatut_Primaire->i16TeauRetour / 10), abs(sStatut_Primaire->i16TeauRetour % 10));
				textArea_temp_ret_ch_ajp.setWildcard(textAreaBuffer_T_Ret_Prim_ajp);
				textArea_temp_ret_ch_ajp.invalidate();
				Unicode::snprintf(textAreaBuffer_DebitPrim_ajp, 7,"%d", (sStatut_Primaire->u16DebitPrimaire));
				textArea_debit_ajp.setWildcard(textAreaBuffer_DebitPrim_ajp);
				textArea_debit_ajp.invalidate();
				Unicode::snprintf(textAreaBuffer_Percent_Circ_ajp, 4,"%d", (sStatut_Primaire->u8ConsigneCirculateur));
				textArea_circ_chauf_ajp.setWildcard(textAreaBuffer_Percent_Circ_ajp);
				textArea_circ_chauf_ajp.invalidate();
			}
			break;

		case BAGUIO_ZURAN_IV:
		case TIMAX_III:
			if(u8Page == 2)
			{
				Unicode::snprintf(textAreaBuffer_Temp_Dep_Prim_mitsu, 7, sStatut_Primaire->i16TeauDepart < 0 ? "-%d.%d" : "%d.%d", abs(sStatut_Primaire->i16TeauDepart / 10), abs(sStatut_Primaire->i16TeauDepart % 10));
				textArea_temp_dep_ch_mitsu.setWildcard(textAreaBuffer_Temp_Dep_Prim_mitsu);
				textArea_temp_dep_ch_mitsu.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ret_Prim_mitsu, 7, sStatut_Primaire->i16TeauRetour < 0 ? "-%d.%d" : "%d.%d", abs(sStatut_Primaire->i16TeauRetour / 10), abs(sStatut_Primaire->i16TeauRetour % 10));
				textArea_temp_ret_ch_mitsu.setWildcard(textAreaBuffer_Temp_Ret_Prim_mitsu);
				textArea_temp_ret_ch_mitsu.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Debit_mitsu, 7,"%d", (sStatut_Primaire->u16DebitPrimaire));
				textArea_debit_mitsu.setWildcard(textAreaBuffer_Temp_Debit_mitsu);
				textArea_debit_mitsu.invalidate();
				Unicode::snprintf(textAreaBuffer_Percent_Circ_mitsu, 4,"%d", (sStatut_Primaire->u8ConsigneCirculateur));
				textArea_circ_chauf_mitsu.setWildcard(textAreaBuffer_Percent_Circ_mitsu);
				textArea_circ_chauf_mitsu.invalidate();
			}
			break;
	}
}

void SynoptiqueView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
	int i16TempCond = 0;
	int i16TempEvap = 0;
	int i16PressCond = 0;

	switch(sConfig_IHM.sModele_PAC.u8ModelePAC)
		{
			default:
			case AJPAC_III:
				if (u8Page == 2)
				{
					Unicode::snprintf(textAreaBuffer_Temp_Liq_Evap_Cond_P2_ajp, 7, sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B / 10), abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B % 10));
					textArea_temp_out_liquide_ech_int_ajp.setWildcard(textAreaBuffer_Temp_Liq_Evap_Cond_P2_ajp);
					textArea_temp_out_liquide_ech_int_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_Liq_Cond410_P2_ajp, 7, sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_A < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_A / 10), abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_A % 10));
					textArea_out_liq_cond_410_ajp.setWildcard(textAreaBuffer_Temp_Liq_Cond410_P2_ajp);
					textArea_out_liq_cond_410_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_Liq_Cond134_P2_ajp, 7, sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TEV134 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TEV134 / 10), abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TEV134 % 10));
					textArea_temp_evap_134_ajp.setWildcard(textAreaBuffer_Temp_Liq_Cond134_P2_ajp);
					textArea_temp_evap_134_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_HP_134_ajp, 7, sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH134 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH134 / 10), abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH134 % 10));
					textArea_temp_hp_134_ajp.setWildcard(textAreaBuffer_Temp_HP_134_ajp);
					textArea_temp_hp_134_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_134_ajp, 7, sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP134_Cible < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP134_Cible / 10), abs(sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP134_Cible % 10));
					textArea_temp_hp_134_cible_ajp.setWildcard(textAreaBuffer_Temp_HP_Cible_134_ajp);
					textArea_temp_hp_134_cible_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_EEV_410_P2_ajp, 4,"%d", (sCyclRegFrigo->pac.ajpac.sStatut_EEV_AJP.u16Position_Pulse_EEV410));
					textArea_EEV_410_ajp.setWildcard(textAreaBuffer_EEV_410_P2_ajp);
					textArea_EEV_410_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_EEV_134_P2_ajp, 4,"%d", (sCyclRegFrigo->pac.ajpac.sStatut_EEV_AJP.u16Position_Pulse_EEV134));
					textArea_EEV_134_ajp.setWildcard(textAreaBuffer_EEV_134_P2_ajp);
					textArea_EEV_134_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Press_Cond_134_ajp, 7, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP134 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP134 / 10), abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP134 % 10));
					textArea_pression_temp_hp_134_ajp.setWildcard1(textAreaBuffer_Press_Cond_134_ajp);
					i16TempCond = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C2, 0, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP134 /*+ 10*/);
					Unicode::snprintf(textAreaBuffer_Temp_Cond_134_ajp, 7, i16TempCond < 0 ? "-%d.%d" : "%d.%d", abs(i16TempCond / 10), abs(i16TempCond % 10));
					textArea_pression_temp_hp_134_ajp.setWildcard2(textAreaBuffer_Temp_Cond_134_ajp);
					textArea_pression_temp_hp_134_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Press_Evap_134_ajp, 7, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP134 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP134 / 10), abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP134 % 10));
					textArea_pression_temp_bp_134_ajp.setWildcard1(textAreaBuffer_Press_Evap_134_ajp);
					i16TempEvap = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C2, 0, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP134 /*+ 10*/);
					Unicode::snprintf(textAreaBuffer_Temp_Evap_134_ajp, 7, i16TempEvap < 0 ? "-%d.%d" : "%d.%d", abs(i16TempEvap / 10), abs(i16TempEvap % 10));
					textArea_pression_temp_bp_134_ajp.setWildcard2(textAreaBuffer_Temp_Evap_134_ajp);
					textArea_pression_temp_bp_134_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Press_410_P2_ajp, 7, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT / 10), abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT % 10));
					textArea_pression_temp_inter_p2_ajp.setWildcard1(textAreaBuffer_Press_410_P2_ajp);
					i16TempCond = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, 0, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT /*+ 10*/);
					Unicode::snprintf(textAreaBuffer_TempCond_410_P2_ajp, 7, i16TempCond < 0 ? "-%d.%d" : "%d.%d", abs(i16TempCond / 10), abs(i16TempCond % 10));
					textArea_pression_temp_inter_p2_ajp.setWildcard2(textAreaBuffer_TempCond_410_P2_ajp);
					textArea_pression_temp_inter_p2_ajp.invalidate();

					if(sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8_Comp134 == 1)
					{
						textArea_comp2_ajp.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
					}
					else textArea_comp2_ajp.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
					textArea_comp2_ajp.invalidate();

				}
				else //AJPAC Page 1
				{
					Unicode::snprintf(textAreaBuffer_Temp_Ext, 7, sCyclRegFrigo->pac.ajpac.sRetourFan.i16Text < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sRetourFan.i16Text / 10), abs(sCyclRegFrigo->pac.ajpac.sRetourFan.i16Text % 10));
					textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
					textArea_temp_ext.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_In_UE_ajp, 7, sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_IN < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_IN / 10), abs(sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_IN % 10));
					textArea_temp_in_ue_ajp.setWildcard(textAreaBuffer_Temp_In_UE_ajp);
					textArea_temp_in_ue_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_Out_UE_ajp, 7, sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_OUT < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_OUT / 10), abs(sCyclRegFrigo->pac.ajpac.sRetourFan.i16Temp_TEV_OUT % 10));
					textArea_temp_out_ue_ajp.setWildcard(textAreaBuffer_Temp_Out_UE_ajp);
					textArea_temp_out_ue_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Percent_Ventil_UE_ajp, 4,"%d", (sCyclRegFrigo->pac.ajpac.sRetourFan.u16In_Vitesse_Ventilateur_1));
					textArea_percent_ventil_ajp.setWildcard(textAreaBuffer_Percent_Ventil_UE_ajp);
					textArea_percent_ventil_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_EEV_410_BP_ajp, 4,"%d", (sCyclRegFrigo->pac.ajpac.sRetourFan.u16Position_Pulse_EEV410BP));
					textArea_EEV_EV_ajp.setWildcard(textAreaBuffer_EEV_410_BP_ajp);
					textArea_EEV_EV_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_EV_UE_ajp, 4,"%s", (sCyclRegFrigo->pac.ajpac.sRetourFan.sOutTorFAN.Evap_EV1 == 1) ? touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText() :
					touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_EV_ue_ajp.setWildcard(textAreaBuffer_EV_UE_ajp);
					textArea_EV_ue_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_EV_UI_ajp, 4,"%s", (sCyclRegFrigo->pac.ajpac.sOutTorFrigo.Electrovanne_HP410 == 1) ? touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText() :
					touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_EV_ui_ajp.setWildcard(textAreaBuffer_EV_UI_ajp);
					textArea_EV_ui_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Palier_Comp_410_ajp, 4,"%d", (sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.Palier_Comp410));
					textArea_palier_hz_comp_ajp.setWildcard1(textAreaBuffer_Palier_Comp_410_ajp);
					Unicode::snprintf(textAreaBuffer_freq_Comp_410_ajp, 4,"%d", (sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.u8Freq_Comp410));
					textArea_palier_hz_comp_ajp.setWildcard2(textAreaBuffer_freq_Comp_410_ajp);
					textArea_palier_hz_comp_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_HP_Comp_410_ajp, 7, sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH410 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH410 / 10), abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSH410 % 10));
					textArea_temp_hp_410_ajp.setWildcard(textAreaBuffer_Temp_HP_Comp_410_ajp);
					textArea_temp_hp_410_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_In_Bout_Liqu_ajp, 7, sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B / 10), abs(sCyclRegFrigo->pac.ajpac.sInTempFrigo.i16Temp_Frigo_TSC410_B % 10));
					textArea_temp_in_bout_liq_ajp.setWildcard(textAreaBuffer_Temp_In_Bout_Liqu_ajp);
					textArea_temp_in_bout_liq_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_410_ajp, 7, sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP410_Cible < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP410_Cible / 10), abs(sCyclRegFrigo->pac.ajpac.sStatut_Frigo_AJP.i16Temp_HP410_Cible % 10));
					textArea_temp_HP_cible_ajp.setWildcard(textAreaBuffer_Temp_HP_Cible_410_ajp);
					textArea_temp_HP_cible_ajp.invalidate();


					Unicode::snprintf(textAreaBuffer_Press_Cond_410_ajp, 7, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410 / 10), abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410 % 10));
					textArea_pression_temp_hp_ajp.setWildcard1(textAreaBuffer_Press_Cond_410_ajp);
					Unicode::snprintf(textAreaBuffer_Press_Evap_410_ajp, 7, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410 / 10), abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410 % 10));
					textArea_pression_temp_bp_ajp.setWildcard1(textAreaBuffer_Press_Evap_410_ajp);
					Unicode::snprintf(textAreaBuffer_Press_Cond2_410_ajp, 7, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT / 10), abs(sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT % 10));
					textArea_pression_temp_hp_int_ajp.setWildcard1(textAreaBuffer_Press_Cond2_410_ajp);

					i16TempCond = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, 0, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HP410 /*+ 10*/);
					i16TempEvap = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, 0, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_BP410 /*+ 10*/);
					Unicode::snprintf(textAreaBuffer_Temp_Cond_410_ajp, 7, i16TempCond < 0 ? "-%d.%d" : "%d.%d", abs(i16TempCond / 10), abs(i16TempCond % 10));
					textArea_pression_temp_hp_ajp.setWildcard2(textAreaBuffer_Temp_Cond_410_ajp);
					textArea_pression_temp_hp_ajp.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_Evap_410_ajp, 7, i16TempEvap < 0 ? "-%d.%d" : "%d.%d", abs(i16TempEvap / 10), abs(i16TempEvap % 10));
					textArea_pression_temp_bp_ajp.setWildcard2(textAreaBuffer_Temp_Evap_410_ajp);
					textArea_pression_temp_bp_ajp.invalidate();
					i16TempCond = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, 0, sCyclRegFrigo->pac.ajpac.sInPressFrigo.i16In_Pression_HPINT /*+ 10*/);
					Unicode::snprintf(textAreaBuffer_Temp_Cond2_P1_410_ajp, 7, i16TempCond < 0 ? "-%d.%d" : "%d.%d", abs(i16TempCond / 10), abs(i16TempCond % 10));
					textArea_pression_temp_hp_int_ajp.setWildcard2(textAreaBuffer_Temp_Cond2_P1_410_ajp);
					textArea_pression_temp_hp_int_ajp.invalidate();
				}
				break;

			case GEOTWIN_IV:
				Unicode::snprintf(textAreaBuffer_Temp_Dep_Prim_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_PRI < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_PRI / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_PRI % 10));
				textArea_temp_DCh_invert.setWildcard(textAreaBuffer_Temp_Dep_Prim_Inv);
				textArea_temp_DCh_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ret_Prim_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_PRI < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_PRI / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_PRI % 10));
				textArea_temp_RCh_invert.setWildcard(textAreaBuffer_Temp_Ret_Prim_Inv);
				textArea_temp_RCh_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ret_Capt_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_CAP < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_CAP / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_RET_CAP % 10));
				textArea_temp_RCa_invert.setWildcard(textAreaBuffer_Temp_Ret_Capt_Inv);
				textArea_temp_RCa_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Dep_Capt_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_CAP < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_CAP / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_ALL_CAP % 10));
				textArea_temp_DCa_invert.setWildcard(textAreaBuffer_Temp_Dep_Capt_Inv);
				textArea_temp_DCa_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ext, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_EXT < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_EXT / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_EXT % 10));
				textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
				textArea_temp_ext.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_HP1_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP1 / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP1 % 10));
				textArea_temp_HP1_invert.setWildcard(textAreaBuffer_Temp_HP1_Inv);
				textArea_temp_HP1_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_BP1_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP1 / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP1 % 10));
				textArea_temp_BP1_invert.setWildcard(textAreaBuffer_Temp_BP1_Inv);
				textArea_temp_BP1_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Liq_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_COND < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_COND / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_COND % 10));
				textArea_temp_liquide_invert.setWildcard(textAreaBuffer_Temp_Liq_Inv);
				textArea_temp_liquide_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Press_Cond_Inv, 7, sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazHP < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazHP / 10), abs(sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazHP % 10));
				textArea_pression_temp_hp_invert.setWildcard1(textAreaBuffer_Press_Cond_Inv);
				Unicode::snprintf(textAreaBuffer_Press_Evap_Inv, 7, sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazBP < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazBP / 10), abs(sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazBP % 10));
				textArea_pression_temp_bp_invert.setWildcard1(textAreaBuffer_Press_Evap_Inv);

				i16TempCond = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, 1, sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazHP /*+ 10*/);
				i16TempEvap = ConvertPressionToTemperature((E_TYPE_GAZ)sConfig_IHM.sModele_PAC.Gaz_C1, 0, sCyclRegFrigo->pac.geotwin.InPress.i16Pression_GazBP /*+ 10*/);
				Unicode::snprintf(textAreaBuffer_Temp_Cond_Inv, 7, i16TempCond < 0 ? "-%d.%d" : "%d.%d", abs(i16TempCond / 10), abs(i16TempCond % 10));
				textArea_pression_temp_hp_invert.setWildcard2(textAreaBuffer_Temp_Cond_Inv);
				textArea_pression_temp_hp_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Evap_Inv, 7, i16TempEvap < 0 ? "-%d.%d" : "%d.%d", abs(i16TempEvap / 10), abs(i16TempEvap % 10));
				textArea_pression_temp_bp_invert.setWildcard2(textAreaBuffer_Temp_Evap_Inv);
				textArea_pression_temp_bp_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_Inv, 6,"%d", sCyclRegFrigo->pac.geotwin.StatutEEV.i16Temp_HP_Cible);
				textArea_temp_HP_cible_invert.setWildcard(textAreaBuffer_Temp_HP_Cible_Inv);
				textArea_temp_HP_cible_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Debit_Prim_Inv, 6,"%d", sCyclRegFrigo->pac.geotwin.InAna.u16Debit_PRI);
				textArea_debit_chauf_invert.setWildcard(textAreaBuffer_Debit_Prim_Inv);
				textArea_debit_chauf_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Debit_Capt_Inv, 6,"%d", sCyclRegFrigo->pac.geotwin.InAna.u16Debit_CAP);
				textArea_debit_capt_invert.setWildcard(textAreaBuffer_Debit_Capt_Inv);
				textArea_debit_capt_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Percent_Circ_Cap_Inv, 4,"%d", sCyclRegFrigo->pac.geotwin.u8ConsigneCirculateurCaptage);
				textArea_circ_cap_invert.setWildcard(textAreaBuffer_Percent_Circ_Cap_Inv);
				textArea_circ_cap_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Percent_Circ_Prim_Inv, 4,"%d", sCyclRegFrigo->pac.geotwin.u8ConsigneCirculateurPrimaire);
				textArea_circ_chauf_invert.setWildcard(textAreaBuffer_Percent_Circ_Prim_Inv);
				textArea_circ_chauf_invert.invalidate();
//				Unicode::snprintf(textAreaBuffer_ConsIntZone1, 5, "%s",touchgfx::TypedText(T_TEXT_VAR_SYS_OFF_DROIT_DEFAUT).getText())
				Unicode::snprintf(textAreaBuffer_Hz_comp_invert, 4,"%s", (sCyclRegFrigo->pac.geotwin.OutTor.REL_Compresseur1 == 1) ? touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText() :
				touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
				textArea_on_off_comp_1.setWildcard(textAreaBuffer_Hz_comp_invert);
				textArea_on_off_comp_1.invalidate();
				Unicode::snprintf(textAreaBuffer_Position_EEV, 4,"%d", sCyclRegFrigo->pac.geotwin.StatutEEV.u16Position_Pulse_EV);
				textArea_EEV_invert.setWildcard(textAreaBuffer_Position_EEV);
				textArea_EEV_invert.invalidate();
				//Comp 2
				if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2)
				{
					Unicode::snprintf(textAreaBuffer_comp_2, 4,"%s", (sCyclRegFrigo->pac.geotwin.OutTor.REL_Compresseur2 == 1) ? touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText() :
					touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
					textArea_on_off_comp_2.setWildcard(textAreaBuffer_comp_2);
					textArea_on_off_comp_2.invalidate();
					//Temp hp et bp
					Unicode::snprintf(textAreaBuffer_Temp_HP2_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP2 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP2 / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_HP2 % 10));
					textArea_temp_HP2_invert.setWildcard(textAreaBuffer_Temp_HP2_Inv);
					textArea_temp_HP2_invert.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_BP2_Inv, 7, sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP2 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP2 / 10), abs(sCyclRegFrigo->pac.geotwin.Temp.i16Temp_BP2 % 10));
					textArea_temp_BP2_invert.setWildcard(textAreaBuffer_Temp_BP2_Inv);
					textArea_temp_BP2_invert.invalidate();

				}

				break;
			case GEOINVERTER:
				Unicode::snprintf(textAreaBuffer_Temp_Dep_Prim_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire % 10));
				textArea_temp_DCh_invert.setWildcard(textAreaBuffer_Temp_Dep_Prim_Inv);
				textArea_temp_DCh_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ret_Prim_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire % 10));
				textArea_temp_RCh_invert.setWildcard(textAreaBuffer_Temp_Ret_Prim_Inv);
				textArea_temp_RCh_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ret_Capt_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur % 10));
				textArea_temp_RCa_invert.setWildcard(textAreaBuffer_Temp_Ret_Capt_Inv);
				textArea_temp_RCa_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Dep_Capt_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur % 10));
				textArea_temp_DCa_invert.setWildcard(textAreaBuffer_Temp_Dep_Capt_Inv);
				textArea_temp_DCa_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Ext, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur % 10));
				textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
				textArea_temp_ext.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_HP1_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1 / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1 % 10));
				textArea_temp_HP1_invert.setWildcard(textAreaBuffer_Temp_HP1_Inv);
				textArea_temp_HP1_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_BP1_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1 / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1 % 10));
				textArea_temp_BP1_invert.setWildcard(textAreaBuffer_Temp_BP1_Inv);
				textArea_temp_BP1_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Liq_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide % 10));
				textArea_temp_liquide_invert.setWildcard(textAreaBuffer_Temp_Liq_Inv);
				textArea_temp_liquide_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Press_Cond_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 % 10));
				textArea_pression_temp_hp_invert.setWildcard1(textAreaBuffer_Press_Cond_Inv);
				Unicode::snprintf(textAreaBuffer_Press_Evap_Inv, 7, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 / 10), abs(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 % 10));
				textArea_pression_temp_bp_invert.setWildcard1(textAreaBuffer_Press_Evap_Inv);

				i16TempCond = ConvertPressionToTemperature(GAZ_R454C, 1, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 + 10);
				i16TempEvap = ConvertPressionToTemperature(GAZ_R454C, 0, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 + 10);
				Unicode::snprintf(textAreaBuffer_Temp_Cond_Inv, 7, i16TempCond < 0 ? "-%d.%d" : "%d.%d", abs(i16TempCond / 10), abs(i16TempCond % 10));
				textArea_pression_temp_hp_invert.setWildcard2(textAreaBuffer_Temp_Cond_Inv);
				textArea_pression_temp_hp_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_Evap_Inv, 7, i16TempEvap < 0 ? "-%d.%d" : "%d.%d", abs(i16TempEvap / 10), abs(i16TempEvap % 10));
				textArea_pression_temp_bp_invert.setWildcard2(textAreaBuffer_Temp_Evap_Inv);
				textArea_pression_temp_bp_invert.invalidate();
				Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_Inv, 6,"%d", (sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16Temp_HP_Cible[0]/10));
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
				Unicode::snprintf(textAreaBuffer_Hz_comp_invert, 4,"%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorRunningSpeed /*/ 60*/);
				Unicode::snprintf(&textAreaBuffer_Hz_comp_invert[Unicode::strlen(textAreaBuffer_Hz_comp_invert)], 4," Hz");
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
				break;
			case BAGUIO_ZURAN_IV:
				if(u8Page == 1)
				{
					//BAGUIO PP
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PP)
					{
						Unicode::snprintf(textAreaBuffer_Temp_Ext, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Text/10));
						textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
						textArea_temp_ext.invalidate();
						if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Tension_DC == 0)
						{
							textArea_temp_hp_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_hp_comp_mitsu.invalidate();
							textArea_pression_temp_hp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_CENTRE_DEFAUT));
							textArea_pression_temp_hp_mitsu.invalidate();
							textArea_temp_milieu_batterie_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_milieu_batterie_mitsu.invalidate();
							textArea_temp_bp_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
							textArea_temp_bp_comp_mitsu.invalidate();
							if (sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1 == 1)
							{
								textArea_percent_ventil_1_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
							}
							else textArea_percent_ventil_1_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
							textArea_percent_ventil_1_mitsu.invalidate();
							textArea_temp_cloche_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_cloche_comp_mitsu.invalidate();
							textArea_temp_in_ue_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_in_ue_mitsu.invalidate();
							textArea_temp_out_evap_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
							textArea_temp_out_evap_mitsu.invalidate();
						}
						else
						{
							textArea_temp_cloche_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_cloche_comp_mitsu.invalidate();

							Unicode::snprintf(textAreaBuffer_Temp_HP_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement);
							textArea_temp_hp_comp_mitsu.setWildcard(textAreaBuffer_Temp_HP_mitsu);
							textArea_temp_hp_comp_mitsu.invalidate();
							textArea_temp_bp_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
							textArea_temp_bp_comp_mitsu.invalidate();
							Unicode::snprintf(textAreaBuffer_EEVA_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA));
							textArea_EEVA_mitsu.setWildcard(textAreaBuffer_EEVA_mitsu);
							textArea_EEVA_mitsu.invalidate();
							textArea_temp_in_ue_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_in_ue_mitsu.invalidate();
							if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R32)
							{
								i16PressCond = ConvertTemperatureToPression(GAZ_R32,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
								Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
								textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
							}
							else
							{
								i16PressCond = ConvertTemperatureToPression(GAZ_R410,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS*10);
								Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
								textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
							}
							Unicode::snprintf(textAreaBuffer_Temp_Cond_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS));
							textArea_pression_temp_hp_mitsu.setWildcard2(textAreaBuffer_Temp_Cond_mitsu);
							textArea_pression_temp_hp_mitsu.invalidate();
							if(sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3 > 250)
							{
								textArea_temp_milieu_batterie_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							}
							else
							{
								Unicode::snprintf(textAreaBuffer_Temp_Batt_Milieu_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3);
								textArea_temp_milieu_batterie_mitsu.setWildcard(textAreaBuffer_Temp_Batt_Milieu_mitsu);
							}
							textArea_temp_milieu_batterie_mitsu.invalidate();
							Unicode::snprintf(textAreaBuffer_Vit_Ventil1_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
							textArea_percent_ventil_1_mitsu.setWildcard(textAreaBuffer_Vit_Ventil1_mitsu);
							textArea_percent_ventil_1_mitsu.invalidate();
							Unicode::snprintf(textAreaBuffer_Frequence_mitsu, 2,"(");
							Unicode::snprintf(&textAreaBuffer_Frequence_mitsu[Unicode::strlen(textAreaBuffer_Frequence_mitsu)], 4,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Cible);
							Unicode::snprintf(&textAreaBuffer_Frequence_mitsu[Unicode::strlen(textAreaBuffer_Frequence_mitsu)], 2,")");
							textArea_frequence_mitsu.setWildcard(textAreaBuffer_Frequence_mitsu);
							textArea_frequence_mitsu.invalidate();
							textArea_temp_out_evap_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
							textArea_temp_out_evap_mitsu.invalidate();
						}
					}

					//P1 Autre que BAGUIO PP (BAGUIO)
					else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO || sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PUZ)
					{
						Unicode::snprintf(textAreaBuffer_Temp_Ext, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Text/10));
						textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
						textArea_temp_ext.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_HP_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement));
						textArea_temp_hp_comp_mitsu.setWildcard(textAreaBuffer_Temp_HP_mitsu);
						textArea_temp_hp_comp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_EEVA_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA));
						textArea_EEVA_mitsu.setWildcard(textAreaBuffer_EEVA_mitsu);
						textArea_EEVA_mitsu.invalidate();
						if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
						{
							Unicode::snprintf(textAreaBuffer_EEVB_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVB));
							textArea_EEVB_mitsu.setWildcard(textAreaBuffer_EEVB_mitsu);
							textArea_EEVB_mitsu.invalidate();
						}
						if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R32)
						{
							i16PressCond = ConvertTemperatureToPression(GAZ_R32,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
							Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
							textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
						}
						else
						{
							i16PressCond = ConvertTemperatureToPression(GAZ_R410,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS * 10);
							Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
							textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);

						}
						Unicode::snprintf(textAreaBuffer_Temp_Batt_Milieu_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6);
						textArea_temp_milieu_batterie_mitsu.setWildcard(textAreaBuffer_Temp_Batt_Milieu_mitsu);
						textArea_temp_milieu_batterie_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_Cond_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS));
						textArea_pression_temp_hp_mitsu.setWildcard2(textAreaBuffer_Temp_Cond_mitsu);
						textArea_pression_temp_hp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Vit_Ventil1_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
						textArea_percent_ventil_1_mitsu.setWildcard(textAreaBuffer_Vit_Ventil1_mitsu);
						textArea_percent_ventil_1_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Vit_Ventil2_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur2);
						textArea_percent_ventil_2_mitsu.setWildcard(textAreaBuffer_Vit_Ventil2_mitsu);
						textArea_percent_ventil_2_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Frequence_mitsu, 4,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Compresseur);
						textArea_frequence_mitsu.setWildcard(textAreaBuffer_Frequence_mitsu);
						textArea_frequence_mitsu.invalidate();

						//Ajouté suite essai PUHZ-SW50
						textArea_temp_bp_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
						textArea_temp_bp_comp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_In_Batt_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3);
						textArea_temp_in_ue_mitsu.setWildcard(textAreaBuffer_Temp_In_Batt_mitsu);
						textArea_temp_in_ue_mitsu.invalidate();
						textArea_temp_out_evap_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
						textArea_temp_out_evap_mitsu.invalidate();
						textArea_temp_cloche_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
						textArea_temp_cloche_comp_mitsu.invalidate();

					}
					else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN_PUZ)
					{
						Unicode::snprintf(textAreaBuffer_Temp_Ext, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Text/10));
						textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
						textArea_temp_ext.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_HP_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement));
						textArea_temp_hp_comp_mitsu.setWildcard(textAreaBuffer_Temp_HP_mitsu);
						textArea_temp_hp_comp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_BP_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Aspiration));
						textArea_temp_bp_comp_mitsu.setWildcard(textAreaBuffer_Temp_BP_mitsu);
						textArea_temp_bp_comp_mitsu.invalidate();
						textArea_temp_cloche_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
						textArea_temp_cloche_comp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_EEVA_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA));
						textArea_EEVA_mitsu.setWildcard(textAreaBuffer_EEVA_mitsu);
						textArea_EEVA_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_EEVB_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVB));
						textArea_EEVB_mitsu.setWildcard(textAreaBuffer_EEVB_mitsu);
						textArea_EEVB_mitsu.invalidate();
						if (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3 > 250)
						{
							textArea_temp_in_ue_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
							textArea_temp_in_ue_mitsu.invalidate();
						}
						else
						{
							Unicode::snprintf(textAreaBuffer_Temp_In_Batt_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH3);
							textArea_temp_in_ue_mitsu.setWildcard(textAreaBuffer_Temp_In_Batt_mitsu);
							textArea_temp_in_ue_mitsu.invalidate();
						}
						i16PressCond = ConvertTemperatureToPression(GAZ_R32,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
						Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
						textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
						Unicode::snprintf(textAreaBuffer_Temp_Cond_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS));
						textArea_pression_temp_hp_mitsu.setWildcard2(textAreaBuffer_Temp_Cond_mitsu);
						textArea_pression_temp_hp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_Batt_Milieu_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6);
						textArea_temp_milieu_batterie_mitsu.setWildcard(textAreaBuffer_Temp_Batt_Milieu_mitsu);
						textArea_temp_milieu_batterie_mitsu.invalidate();
//						textArea_temp_milieu_batterie_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
//						textArea_temp_milieu_batterie_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Vit_Ventil1_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
						textArea_percent_ventil_1_mitsu.setWildcard(textAreaBuffer_Vit_Ventil1_mitsu);
						textArea_percent_ventil_1_mitsu.invalidate();
						textArea_percent_ventil_2_mitsu.setVisible(false);
						textArea_percent_ventil_2_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Frequence_mitsu, 4,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Compresseur);
						textArea_frequence_mitsu.setWildcard(textAreaBuffer_Frequence_mitsu);
						textArea_frequence_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_EEVC_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVC));
						textArea_EEVC_mitsu.setWildcard(textAreaBuffer_EEVC_mitsu);
						textArea_EEVC_mitsu.invalidate();
						textArea_temp_out_evap_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
						textArea_temp_out_evap_mitsu.invalidate();
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_Temp_Ext, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Text/10));
						textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
						textArea_temp_ext.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_HP_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement));
						textArea_temp_hp_comp_mitsu.setWildcard(textAreaBuffer_Temp_HP_mitsu);
						textArea_temp_hp_comp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_BP_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Aspiration));
						textArea_temp_bp_comp_mitsu.setWildcard(textAreaBuffer_Temp_BP_mitsu);
						textArea_temp_bp_comp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_EEVA_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA));
						textArea_EEVA_mitsu.setWildcard(textAreaBuffer_EEVA_mitsu);
						textArea_EEVA_mitsu.invalidate();
						if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R410)
						{
							Unicode::snprintf(textAreaBuffer_EEVB_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVB));
							textArea_EEVB_mitsu.setWildcard(textAreaBuffer_EEVB_mitsu);
							textArea_EEVB_mitsu.invalidate();
						}
//						Unicode::snprintf(textAreaBuffer_Temp_Batt_Milieu_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6));
						textArea_temp_milieu_batterie_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
						textArea_temp_milieu_batterie_mitsu.invalidate();
						if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R32)
						{
							i16PressCond = ConvertTemperatureToPression(GAZ_R32,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
							Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
							textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
						}
						else
						{
							i16PressCond = ConvertTemperatureToPression(GAZ_R410,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS * 10);
							Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
							textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
						}
						Unicode::snprintf(textAreaBuffer_Temp_Cond_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS));
						textArea_pression_temp_hp_mitsu.setWildcard2(textAreaBuffer_Temp_Cond_mitsu);
						textArea_pression_temp_hp_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Vit_Ventil1_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
						textArea_percent_ventil_1_mitsu.setWildcard(textAreaBuffer_Vit_Ventil1_mitsu);
						textArea_percent_ventil_1_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Vit_Ventil2_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur2);
						textArea_percent_ventil_2_mitsu.setWildcard(textAreaBuffer_Vit_Ventil2_mitsu);
						textArea_percent_ventil_2_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Frequence_mitsu, 4,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Compresseur);
						textArea_frequence_mitsu.setWildcard(textAreaBuffer_Frequence_mitsu);
						textArea_frequence_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_EEVC_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVC));
						textArea_EEVC_mitsu.setWildcard(textAreaBuffer_EEVC_mitsu);
						textArea_EEVC_mitsu.invalidate();
						textArea_temp_cloche_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
						textArea_temp_cloche_comp_mitsu.invalidate();
						textArea_temp_out_evap_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
						textArea_temp_out_evap_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_In_Batt_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6);
						textArea_temp_in_ue_mitsu.setWildcard(textAreaBuffer_Temp_In_Batt_mitsu);
						textArea_temp_in_ue_mitsu.invalidate();
					}
				}
				//Page 2 ZURAN/BAGUIO
				else
				{
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PP)
					{
						Unicode::snprintf(textAreaBuffer_Temp_Liquide_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS - sCyclRegFrigo->pac.zuba.sStatutFrigo.u8SousRefroidissement);
						textArea_temp_liquide_mitsu.setWildcard(textAreaBuffer_Temp_Liquide_mitsu);
						textArea_temp_liquide_mitsu.invalidate();
					}
					else if (sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO || sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN ||sConfig_IHM.sModele_PAC.u3SousTypePAC == SOUS_TYPE_ZURAN_PUZ)
					{
						Unicode::snprintf(textAreaBuffer_Temp_Liquide_mitsu, 7, sCyclRegFrigo->pac.zuba.sInAnaFrigo.i16Temp_S1 < 0 ? "-%d.%d" : "%d.%d", abs(sCyclRegFrigo->pac.zuba.sInAnaFrigo.i16Temp_S1 / 10), abs(sCyclRegFrigo->pac.zuba.sInAnaFrigo.i16Temp_S1 % 10));
						textArea_temp_liquide_mitsu.setWildcard(textAreaBuffer_Temp_Liquide_mitsu);
						textArea_temp_liquide_mitsu.invalidate();
					}
				}
				break;
			case TIMAX_III:
				if(u8Page == 1)
				{
					Unicode::snprintf(textAreaBuffer_Temp_Ext, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.Text/10));
					textArea_temp_ext.setWildcard(textAreaBuffer_Temp_Ext);
					textArea_temp_ext.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_HP_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Refoulement));
					textArea_temp_hp_comp_mitsu.setWildcard(textAreaBuffer_Temp_HP_mitsu);
					textArea_temp_hp_comp_mitsu.invalidate();
					Unicode::snprintf(textAreaBuffer_EEVA_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVA));
					textArea_EEVA_mitsu.setWildcard(textAreaBuffer_EEVA_mitsu);
					textArea_EEVA_mitsu.invalidate();
					Unicode::snprintf(textAreaBuffer_EEVB_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVB));
					textArea_EEVB_mitsu.setWildcard(textAreaBuffer_EEVB_mitsu);
					textArea_EEVB_mitsu.invalidate();
					if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R32)
					{
						i16PressCond = ConvertTemperatureToPression(GAZ_R32,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS);
						Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
						textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
					}
					else
					{

						i16PressCond = ConvertTemperatureToPression(GAZ_R410,sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS*10);
						Unicode::snprintf(textAreaBuffer_Press_Cond_mitsu, 7, i16PressCond < 0 ? "-%d.%d" : "%d.%d", abs(i16PressCond / 10), abs(i16PressCond % 10));
						textArea_pression_temp_hp_mitsu.setWildcard1(textAreaBuffer_Press_Cond_mitsu);
					}
					Unicode::snprintf(textAreaBuffer_Temp_Cond_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.T63HS));
					textArea_pression_temp_hp_mitsu.setWildcard2(textAreaBuffer_Temp_Cond_mitsu);
					textArea_pression_temp_hp_mitsu.invalidate();
					Unicode::snprintf(textAreaBuffer_Temp_Batt_Milieu_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6);
					textArea_temp_milieu_batterie_mitsu.setWildcard(textAreaBuffer_Temp_Batt_Milieu_mitsu);
					textArea_temp_milieu_batterie_mitsu.invalidate();
					Unicode::snprintf(textAreaBuffer_Vit_Ventil1_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur1);
					textArea_percent_ventil_1_mitsu.setWildcard(textAreaBuffer_Vit_Ventil1_mitsu);
					textArea_percent_ventil_1_mitsu.invalidate();
					Unicode::snprintf(textAreaBuffer_Vit_Ventil2_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Vitesse_Ventilateur2);
					textArea_percent_ventil_2_mitsu.setWildcard(textAreaBuffer_Vit_Ventil2_mitsu);
					textArea_percent_ventil_2_mitsu.invalidate();
					Unicode::snprintf(textAreaBuffer_Frequence_mitsu, 4,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.Freq_Compresseur);
					textArea_frequence_mitsu.setWildcard(textAreaBuffer_Frequence_mitsu);
					textArea_frequence_mitsu.invalidate();

					//Suite test PUHZ-W85
					if (sConfig_IHM.sModele_PAC.u3SousTypePAC != SOUS_TYPE_BAGUIO)
					{
						Unicode::snprintf(textAreaBuffer_Temp_BP_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Aspiration);
						textArea_temp_bp_comp_mitsu.setWildcard(textAreaBuffer_Temp_BP_mitsu);
						textArea_temp_bp_comp_mitsu.invalidate();

						Unicode::snprintf(textAreaBuffer_EEVC_mitsu, 7,"%d", (sCyclRegFrigo->pac.zuba.sStatutMitsu.LEVC));
						textArea_EEVC_mitsu.setWildcard(textAreaBuffer_EEVC_mitsu);
						textArea_EEVC_mitsu.invalidate();
					}
					else
					{
						textArea_temp_bp_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
						textArea_temp_bp_comp_mitsu.invalidate();
					}

					textArea_temp_in_ue_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
					textArea_temp_in_ue_mitsu.invalidate();
					textArea_temp_cloche_comp_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_GAUCHE_DEFAUT));
					textArea_temp_cloche_comp_mitsu.invalidate();
					textArea_temp_out_evap_mitsu.setTypedText(touchgfx::TypedText(T_TEXT_NA_DROITE_DEFAUT));
					textArea_temp_out_evap_mitsu.invalidate();
				}
				//TIMAX Page 2
				else
				{
					if(sConfig_IHM.sModele_PAC.Gaz_C1 == GAZ_R32)
					{
						Unicode::snprintf(textAreaBuffer_Temp_Liquide_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Liquide2);
						textArea_temp_liquide_mitsu.setWildcard(textAreaBuffer_Temp_Liquide_mitsu);
						textArea_temp_liquide_mitsu.invalidate();
					}
					else
					{
						Unicode::snprintf(textAreaBuffer_Temp_Liquide_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_TH6);
						textArea_temp_liquide_mitsu.setWildcard(textAreaBuffer_Temp_Liquide_mitsu);
						textArea_temp_liquide_mitsu.invalidate();
						Unicode::snprintf(textAreaBuffer_Temp_Retour_Eau_mitsu, 7,"%d", sCyclRegFrigo->pac.zuba.sStatutMitsu.T_Liquide2);
						textArea_temp_retour_eau_mitsu.setWildcard(textAreaBuffer_Temp_Retour_Eau_mitsu);
						textArea_temp_retour_eau_mitsu.invalidate();
					}
				}
				break;
			case PHOENIX:
				break;
		}


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



