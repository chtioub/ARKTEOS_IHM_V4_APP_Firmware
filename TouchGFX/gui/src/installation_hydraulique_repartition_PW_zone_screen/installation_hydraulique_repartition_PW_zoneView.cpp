#include <gui/installation_hydraulique_repartition_PW_zone_screen/Installation_hydraulique_repartition_PW_zoneView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_hydraulique_repartition_PW_zoneView::Installation_hydraulique_repartition_PW_zoneView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));//SER
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);//SER
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	Unicode::snprintf(textAreaBuffer_Titre, 50, touchgfx::TypedText(T_TEXT_CENTRE_TITRE_REPARTITION_PUISSANCE_ZONE).getText());
	barre_titre.titre(textAreaBuffer_Titre);


//	sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire
	u7temp_Percent_Zone1 = sConfig_IHM.sParam_Zx[0].u7VolumePiece;
	u7temp_Percent_Zone2 = sConfig_IHM.sParam_Zx[1].u7VolumePiece;
	if (u7temp_Percent_Zone1 < 35 || u7temp_Percent_Zone1 > 65)
	{
		u7temp_Percent_Zone1 = 50;
		u7temp_Percent_Zone2 = 50;
	}

//	 u7temp_Percent_Zone2,
	Unicode::snprintf(textAreaBuffer_part_zone1, 8, "%d", u7temp_Percent_Zone1 );
	textArea_valeur_volume_zone1.setWildcard(textAreaBuffer_part_zone1);
	textArea_valeur_volume_zone1.invalidate();
	Unicode::snprintf(textAreaBuffer_part_zone2, 8, "%d",u7temp_Percent_Zone2);
	textArea_valeur_volume_zone2.setWildcard(textAreaBuffer_part_zone2);
	textArea_valeur_volume_zone2.invalidate();


//	Unicode::snprintf(textAreaBuffer_Percent_Circ_Prim_Inv, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire);
//			textArea_circ_chauf_invert.setWildcard(textAreaBuffer_Percent_Circ_Prim_Inv);
//			textArea_circ_chauf_invert.invalidate();


//	if(sConfig_IHM.sOption_PAC.TypeAppoint != 0)
//	{
//		image_on_off_resistance_terminaison_regul_2_zones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//	    textArea_on_off_resistance_terminaison_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		image_on_off_resistance_terminaison_regul_multizones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//	    textArea_on_off_resistance_terminaison_regul_multizones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		image_on_off_resistance_terminaison_regul_externe.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//	    textArea_on_off_resistance_terminaison_regul_externe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		image_on_off_resistance_terminaison_regul_esclave.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//	    textArea_on_off_resistance_terminaison_regul_esclave.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//	}
//	// Affichage de la regul en cours
//	affichage_type_regul();
//	//
//	if(u8Nb_PAC > 1)
//	{
//		container_resistance_terminaison_regul_2_zones.setVisible(true);
//		container_resistance_terminaison_regul_multizones.setVisible(true);
//		container_resistance_terminaison_regul_externe.setVisible(true);
//	}
//	else
//	{
//		container_resistance_terminaison_regul_2_zones.setVisible(false);
//		container_resistance_terminaison_regul_multizones.setVisible(false);
//		container_resistance_terminaison_regul_externe.setVisible(false);
//	}
//	Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
//	textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
//	// Param zones 1
//	if(sConfig_Hydrau_temp.sZones.bZone1)
//	{
//		toggleButton_zone_1_on_off_regul_directe.forceState(true);
//		toggleButton_zone_1_on_off_regul_2_zones.forceState(true);
//		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//	}
//	Unicode::fromUTF8(sConfig_IHM.sParam_Zx[0].u8NomZone, textAreaBuffer_nom_zone1, 10);
//	textArea_zone_1_regul_directe.setWildcard(textAreaBuffer_nom_zone1);
//	textArea_bouton_zone_1_regul_directe.setWildcard(textAreaBuffer_nom_zone1);
//	textArea_zone_1_regul_2_zones.setWildcard(textAreaBuffer_nom_zone1);
//	textArea_bouton_zone_1_regul_2_zones.setWildcard(textAreaBuffer_nom_zone1);
//	Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
//	textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
//	// Param zones 2
//	if(sConfig_Hydrau_temp.sZones.bZone2)
//	{
//		toggleButton_zone_2_on_off_regul_directe.forceState(true);
//		toggleButton_zone_2_on_off_regul_2_zones.forceState(true);
//		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//	}
//	Unicode::fromUTF8(sConfig_IHM.sParam_Zx[1].u8NomZone, textAreaBuffer_nom_zone2, 10);
//	textArea_zone_2_regul_directe.setWildcard(textAreaBuffer_nom_zone2);
//	textArea_bouton_zone_2_regul_directe.setWildcard(textAreaBuffer_nom_zone2);
//	textArea_zone_2_regul_2_zones.setWildcard(textAreaBuffer_nom_zone2);
//	textArea_bouton_zone_2_regul_2_zones.setWildcard(textAreaBuffer_nom_zone2);
//	// Zones actives
//	affichage_zones();
//	// Appoint
//	if(sConfig_IHM.sOption_PAC.TypeAppoint != 0)
//	{
//		image_on_off_appoint_chauffage.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//	    textArea_on_off_appoint_chauffage.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//	}
//	// Resistance de terminaison
//	if(sConfig_IHM.sParam_PAC.bConfigCascade120R != 0)
//	{
//		image_on_off_resistance_terminaison_regul_2_zones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//		textArea_on_off_resistance_terminaison_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		image_on_off_resistance_terminaison_regul_multizones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//		textArea_on_off_resistance_terminaison_regul_multizones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		image_on_off_resistance_terminaison_regul_externe.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//		textArea_on_off_resistance_terminaison_regul_externe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		image_on_off_resistance_terminaison_regul_esclave.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
//		textArea_on_off_resistance_terminaison_regul_esclave.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//	}
}

void Installation_hydraulique_repartition_PW_zoneView::setupScreen()
{
	Installation_hydraulique_repartition_PW_zoneViewBase::setupScreen();
}

void Installation_hydraulique_repartition_PW_zoneView::tearDownScreen()
{
	Installation_hydraulique_repartition_PW_zoneViewBase::tearDownScreen();
}

//void Installation_hydraulique_repartition_PW_zoneView::bouton_defilement_droit_type_regulation()
//{
//	// Incrémentation de la variable
//	sConfig_Hydrau_temp.u8TypeRegul++;
//	if(sConfig_Hydrau_temp.u8TypeRegul > 5)
//	{
//		sConfig_Hydrau_temp.u8TypeRegul = 0;
//	}
//	else if(sConfig_Hydrau_temp.u8TypeRegul == 1)
//	{
//		sConfig_Hydrau_temp.u8TypeRegul = 2;
//	}
//	//
//	memset(&sConfig_Hydrau_temp.sZones, 0, sizeof(S_ZONE));
//	// RAZ
//	toggleButton_zone_1_on_off_regul_directe.forceState(false);
//	toggleButton_zone_1_on_off_regul_directe.invalidate();
//	toggleButton_zone_1_on_off_regul_2_zones.forceState(false);
//	toggleButton_zone_1_on_off_regul_2_zones.invalidate();
//	toggleButton_zone_2_on_off_regul_directe.forceState(false);
//	toggleButton_zone_2_on_off_regul_directe.invalidate();
//	toggleButton_zone_2_on_off_regul_2_zones.forceState(false);
//	toggleButton_zone_2_on_off_regul_2_zones.invalidate();
//	//
//	affichage_type_regul();
//}

//void Installation_hydraulique_repartition_PW_zoneView::bouton_defilement_gauche_type_regulation()
//{
//	// Incrémentation de la variable
//	if(sConfig_Hydrau_temp.u8TypeRegul > 0)
//	{
//		sConfig_Hydrau_temp.u8TypeRegul--;
//		if(sConfig_Hydrau_temp.u8TypeRegul == 1)
//		{
//			sConfig_Hydrau_temp.u8TypeRegul = 0;
//		}
//	}
//	else sConfig_Hydrau_temp.u8TypeRegul = 5;
//	//
//	memset(&sConfig_Hydrau_temp.sZones, 0, sizeof(S_ZONE));
//	// RAZ
//	toggleButton_zone_1_on_off_regul_directe.forceState(false);
//	toggleButton_zone_1_on_off_regul_directe.invalidate();
//	toggleButton_zone_1_on_off_regul_2_zones.forceState(false);
//	toggleButton_zone_1_on_off_regul_2_zones.invalidate();
//	toggleButton_zone_2_on_off_regul_directe.forceState(false);
//	toggleButton_zone_2_on_off_regul_directe.invalidate();
//	toggleButton_zone_2_on_off_regul_2_zones.forceState(false);
//	toggleButton_zone_2_on_off_regul_2_zones.invalidate();
//	//
//	affichage_type_regul();
//}

//void Installation_hydraulique_repartition_PW_zoneView::affichage_type_regul()
//{
//	// Masque l'ensemble des containers
//	container_regul_directe.setVisible(false);
//	container_regul_2_zones.setVisible(false);
//	container_regul_multizones.setVisible(false);
//	container_regul_externe.setVisible(false);
//	container_regul_esclave.setVisible(false);
//	textArea_circulateurs_arkteos.setVisible(false);
//	textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NB_PAC_CENTRE_DEFAUT));
//	container_nombre_pac.setVisible(true);
//	// Affichage du container de la régulation sélectionnee
//	switch(sConfig_Hydrau_temp.u8TypeRegul)
//	{
//		case REGUL_DIRECTE:
//			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_CENTRE_DEFAUT));
//			container_regul_directe.setVisible(true);
//			container_nombre_pac.setVisible(false);
//			break;
//		case REGUL_BCP_INTERNE:
//			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_BCP_INTERNE_CENTRE_DEFAUT));
//			button_gauche_type_regulation.setVisible(false);
//			button_droite_type_regulation.setVisible(false);
//			container_regul_2_zones.setVisible(true);
//			container_nombre_pac.setVisible(false);
//			break;
//		case REGUL_BAL_TAMPON_2_ZONES:
//			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_CENTRE_DEFAUT));
//			container_regul_2_zones.setVisible(true);
//			textArea_circulateurs_arkteos.setVisible(true);
//			break;
//		case REGUL_BAL_TAMPON_MULTI_ZONE:
//			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTI_ZONES_CENTRE_DEFAUT));
//			container_regul_multizones.setVisible(true);
//			break;
//		case REGUL_EXTERNE:
//			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_CENTRE_DEFAUT));
//			container_regul_externe.setVisible(true);
//			break;
//		case REGUL_ESCLAVE:
//			if(u8Nb_PAC <= 1)
//			{
//				u8Nb_PAC = 2;
//				Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
//				textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
//				textArea_valeur_nombre_pac.invalidate();
//			}
//			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_ESCLAVE_CENTRE_DEFAUT));
//			textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NUM_PAC_CENTRE_DEFAUT));
//			container_regul_esclave.setVisible(true);
//			break;
//	}
//	textArea_valeur_type_regulation.invalidate();
//	container_regul_directe.invalidate();
//	container_regul_2_zones.invalidate();
//	container_regul_multizones.invalidate();
//	container_regul_externe.invalidate();
//	container_regul_esclave.invalidate();
//	textArea_circulateurs_arkteos.invalidate();
//	textArea_nombre_pac.invalidate();
//	container_nombre_pac.invalidate();
//	//
//	affichage_zones();
//}

void Installation_hydraulique_repartition_PW_zoneView::bouton_part_volume_zone1_gauche()
{
	if (u7temp_Percent_Zone1 > 35)
	{
		u7temp_Percent_Zone1 --;
		u7temp_Percent_Zone2 ++;
	}
	Update_Percent_value();
}

void Installation_hydraulique_repartition_PW_zoneView::bouton_part_volume_zone1_droit()
{
	if (u7temp_Percent_Zone1 < 65)
	{
		u7temp_Percent_Zone1 ++;
		u7temp_Percent_Zone2 --;
	}
	Update_Percent_value();
}

void Installation_hydraulique_repartition_PW_zoneView::bouton_part_volume_zone2_gauche()
{
	if (u7temp_Percent_Zone2 > 35)
	{
		u7temp_Percent_Zone2 --;
		u7temp_Percent_Zone1 ++;
	}
	Update_Percent_value();
}

void Installation_hydraulique_repartition_PW_zoneView::bouton_part_volume_zone2_droit()
{
	if (u7temp_Percent_Zone2 < 65)
	{
		u7temp_Percent_Zone2 ++;
		u7temp_Percent_Zone1 --;
	}
	Update_Percent_value();
}

void Installation_hydraulique_repartition_PW_zoneView::Update_Percent_value()
{
	Unicode::snprintf(textAreaBuffer_part_zone1, 8, "%d", u7temp_Percent_Zone1 );
	textArea_valeur_volume_zone1.setWildcard(textAreaBuffer_part_zone1);
	textArea_valeur_volume_zone1.invalidate();
	Unicode::snprintf(textAreaBuffer_part_zone2, 8, "%d",u7temp_Percent_Zone2);
	textArea_valeur_volume_zone2.setWildcard(textAreaBuffer_part_zone2);
	textArea_valeur_volume_zone2.invalidate();
}

void Installation_hydraulique_repartition_PW_zoneView::bouton_valider() //SER
{
	sConfig_IHM.sParam_Zx[0].u7VolumePiece = u7temp_Percent_Zone1;
	sConfig_IHM.sParam_Zx[1].u7VolumePiece = u7temp_Percent_Zone2;
	presenter->c_install_zx(0);
	presenter->c_install_zx(1);

	application().gotoInstallation_hydrauliqueScreenNoTransition();
}

void Installation_hydraulique_repartition_PW_zoneView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	;
}

void Installation_hydraulique_repartition_PW_zoneView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydraulique_repartition_PW_zoneView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_repartition_PW_zoneView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydraulique_repartition_PW_zoneView::changeDate(S_DATE *sDate)
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
