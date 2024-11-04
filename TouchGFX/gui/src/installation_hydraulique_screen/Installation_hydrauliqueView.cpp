#include <gui/installation_hydraulique_screen/Installation_hydrauliqueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_hydrauliqueView::Installation_hydrauliqueView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_INSTALL_HYDRAU_CENTRE_LARGE).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	// Copie des zones
	for (int i = 0; i < 8; i++)
	{
		sParamZxMZtemp[i] = sConfig_IHM.sParam_Zx[i];
	}
	// Copie des groupes
	for (int i = 8; i < 10; i++)
	{
		sParamZxMZtemp[i] = sConfig_IHM.sParam_Zx[i];
	}
    //
	u8Nb_PAC = sConfig_IHM.sParam_PAC.numEsclave + 1;
	//
	if(sConfig_IHM.sOption_PAC.TypeAppoint != 0)
	{
		image_on_off_resistance_terminaison_regul_2_zones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
	    textArea_on_off_resistance_terminaison_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		image_on_off_resistance_terminaison_regul_multizones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
	    textArea_on_off_resistance_terminaison_regul_multizones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		image_on_off_resistance_terminaison_regul_externe.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
	    textArea_on_off_resistance_terminaison_regul_externe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		image_on_off_resistance_terminaison_regul_esclave.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
	    textArea_on_off_resistance_terminaison_regul_esclave.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	// Affichage de la regul en cours
	affichage_type_regul();
	//
	if(u8Nb_PAC > 1)
	{
		container_resistance_terminaison_regul_2_zones.setVisible(true);
		container_resistance_terminaison_regul_multizones.setVisible(true);
		container_resistance_terminaison_regul_externe.setVisible(true);
	}
	else
	{
		container_resistance_terminaison_regul_2_zones.setVisible(false);
		container_resistance_terminaison_regul_multizones.setVisible(false);
		container_resistance_terminaison_regul_externe.setVisible(false);
	}
	Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
	textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
	// Param zones 1
	if(sConfig_Hydrau_temp.sZones.bZone1)
	{
		toggleButton_zone_1_on_off_regul_directe.forceState(true);
		toggleButton_zone_1_on_off_regul_2_zones.forceState(true);
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	Unicode::fromUTF8(sConfig_IHM.sParam_Zx[0].u8NomZone, textAreaBuffer_nom_zone1, 10);
	textArea_zone_1_regul_directe.setWildcard(textAreaBuffer_nom_zone1);
	textArea_bouton_zone_1_regul_directe.setWildcard(textAreaBuffer_nom_zone1);
	textArea_zone_1_regul_2_zones.setWildcard(textAreaBuffer_nom_zone1);
	textArea_bouton_zone_1_regul_2_zones.setWildcard(textAreaBuffer_nom_zone1);
	Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
	textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
	// Param zones 2
	if(sConfig_Hydrau_temp.sZones.bZone2)
	{
		toggleButton_zone_2_on_off_regul_directe.forceState(true);
		toggleButton_zone_2_on_off_regul_2_zones.forceState(true);
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	Unicode::fromUTF8(sConfig_IHM.sParam_Zx[1].u8NomZone, textAreaBuffer_nom_zone2, 10);
	textArea_zone_2_regul_directe.setWildcard(textAreaBuffer_nom_zone2);
	textArea_bouton_zone_2_regul_directe.setWildcard(textAreaBuffer_nom_zone2);
	textArea_zone_2_regul_2_zones.setWildcard(textAreaBuffer_nom_zone2);
	textArea_bouton_zone_2_regul_2_zones.setWildcard(textAreaBuffer_nom_zone2);
	// Zones actives
	affichage_zones();
	// Appoint
	if(sConfig_IHM.sOption_PAC.TypeAppoint != 0)
	{
		image_on_off_appoint_chauffage.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
	    textArea_on_off_appoint_chauffage.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}
	// Resistance de terminaison
	if(sConfig_IHM.sParam_PAC.bConfigCascade120R != 0)
	{
		image_on_off_resistance_terminaison_regul_2_zones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_resistance_terminaison_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		image_on_off_resistance_terminaison_regul_multizones.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_resistance_terminaison_regul_multizones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		image_on_off_resistance_terminaison_regul_externe.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_resistance_terminaison_regul_externe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		image_on_off_resistance_terminaison_regul_esclave.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
		textArea_on_off_resistance_terminaison_regul_esclave.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
	}

	// Multizones
	if (sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE)
	{
		MAJ_Etat_Bouton_Oui_Non_Multizone();
	}
}

void Installation_hydrauliqueView::setupScreen()
{
    Installation_hydrauliqueViewBase::setupScreen();
}

void Installation_hydrauliqueView::tearDownScreen()
{
    Installation_hydrauliqueViewBase::tearDownScreen();
}

void Installation_hydrauliqueView::bouton_resistance_terminaison()
{
	eOuiNon = OUI_NON_RESIST_TERM;
	application().gotoPage_oui_nonScreenNoTransition();
}

void Installation_hydrauliqueView::bouton_defilement_droit_type_regulation()
{
	// Incrémentation de la variable
	sConfig_Hydrau_temp.u8TypeRegul++;
	if(sConfig_Hydrau_temp.u8TypeRegul > 5)
	{
		sConfig_Hydrau_temp.u8TypeRegul = 0;
	}
	else if(sConfig_Hydrau_temp.u8TypeRegul == 1)
	{
		sConfig_Hydrau_temp.u8TypeRegul = 2;
	}
	//
	memset(&sConfig_Hydrau_temp.sZones, 0, sizeof(S_ZONE));
	// RAZ
	toggleButton_zone_1_on_off_regul_directe.forceState(false);
	toggleButton_zone_1_on_off_regul_directe.invalidate();
	toggleButton_zone_1_on_off_regul_2_zones.forceState(false);
	toggleButton_zone_1_on_off_regul_2_zones.invalidate();
	toggleButton_zone_2_on_off_regul_directe.forceState(false);
	toggleButton_zone_2_on_off_regul_directe.invalidate();
	toggleButton_zone_2_on_off_regul_2_zones.forceState(false);
	toggleButton_zone_2_on_off_regul_2_zones.invalidate();
	//
	affichage_type_regul();
}

void Installation_hydrauliqueView::bouton_defilement_gauche_type_regulation()
{
	// Incrémentation de la variable
	if(sConfig_Hydrau_temp.u8TypeRegul > 0)
	{
		sConfig_Hydrau_temp.u8TypeRegul--;
		if(sConfig_Hydrau_temp.u8TypeRegul == 1)
		{
			sConfig_Hydrau_temp.u8TypeRegul = 0;
		}
	}
	else sConfig_Hydrau_temp.u8TypeRegul = 5;
	//
	memset(&sConfig_Hydrau_temp.sZones, 0, sizeof(S_ZONE));
	// RAZ
	toggleButton_zone_1_on_off_regul_directe.forceState(false);
	toggleButton_zone_1_on_off_regul_directe.invalidate();
	toggleButton_zone_1_on_off_regul_2_zones.forceState(false);
	toggleButton_zone_1_on_off_regul_2_zones.invalidate();
	toggleButton_zone_2_on_off_regul_directe.forceState(false);
	toggleButton_zone_2_on_off_regul_directe.invalidate();
	toggleButton_zone_2_on_off_regul_2_zones.forceState(false);
	toggleButton_zone_2_on_off_regul_2_zones.invalidate();
	//
	affichage_type_regul();
}

void Installation_hydrauliqueView::affichage_type_regul()
{
	// Masque l'ensemble des containers
	container_regul_directe.setVisible(false);
	container_regul_2_zones.setVisible(false);
	container_regul_multizones.setVisible(false);
	container_regul_externe.setVisible(false);
	container_regul_esclave.setVisible(false);
	textArea_circulateurs_arkteos.setVisible(false);
	textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NB_PAC_CENTRE_DEFAUT));
	container_nombre_pac.setVisible(true);
	// Affichage du container de la régulation sélectionnee
	switch(sConfig_Hydrau_temp.u8TypeRegul)
	{
		case REGUL_DIRECTE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_CENTRE_DEFAUT));
			container_regul_directe.setVisible(true);
			container_nombre_pac.setVisible(false);
			break;
		case REGUL_BCP_INTERNE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_BCP_INTERNE_CENTRE_DEFAUT));
			button_gauche_type_regulation.setVisible(false);
			button_droite_type_regulation.setVisible(false);
			container_regul_2_zones.setVisible(true);
			container_nombre_pac.setVisible(false);
			break;
		case REGUL_BAL_TAMPON_2_ZONES:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_CENTRE_DEFAUT));
			container_regul_2_zones.setVisible(true);
			textArea_circulateurs_arkteos.setVisible(true);
			break;
		case REGUL_BAL_TAMPON_MULTI_ZONE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTI_ZONES_CENTRE_DEFAUT));
			container_regul_multizones.setVisible(true);
			MAJ_Etat_Bouton_Oui_Non_Multizone();
			break;
		case REGUL_EXTERNE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_CENTRE_DEFAUT));
			container_regul_externe.setVisible(true);
			break;
		case REGUL_ESCLAVE:
			if(u8Nb_PAC <= 1)
			{
				u8Nb_PAC = 2;
				Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
				textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
				textArea_valeur_nombre_pac.invalidate();
			}
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_ESCLAVE_CENTRE_DEFAUT));
			textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NUM_PAC_CENTRE_DEFAUT));
			container_regul_esclave.setVisible(true);
			break;
	}
	textArea_valeur_type_regulation.invalidate();
	container_regul_directe.invalidate();
	container_regul_2_zones.invalidate();
	container_regul_multizones.invalidate();
	container_regul_externe.invalidate();
	container_regul_esclave.invalidate();
	textArea_circulateurs_arkteos.invalidate();
	textArea_nombre_pac.invalidate();
	container_nombre_pac.invalidate();
	//
	affichage_zones();
}

void Installation_hydrauliqueView::bouton_defilement_droit_nb_pac()
{
	// Maximum 8 PACs en cascade
    if(u8Nb_PAC < 8)
    {
    	u8Nb_PAC++;
        // Possibilité d'activer la résistance de terminaison (si plus d'une PAC)
        if(u8Nb_PAC > 1)
        {
            touchgfx_printf("resistance terminaison affichee\n");
        	container_resistance_terminaison_regul_2_zones.setVisible(true);
        	container_resistance_terminaison_regul_2_zones.invalidate();
        	container_resistance_terminaison_regul_multizones.setVisible(true);
        	container_resistance_terminaison_regul_multizones.invalidate();
    		container_resistance_terminaison_regul_externe.setVisible(true);
    		container_resistance_terminaison_regul_externe.invalidate();
        }
        // MAJ de la valeur
        touchgfx_printf("nb pac = %d\n", u8Nb_PAC);
        Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
        textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
        textArea_valeur_nombre_pac.invalidate();
    }
}

void Installation_hydrauliqueView::bouton_defilement_gauche_nb_pac()
{
	// Maximum 8 PACs en cascade
    if((u8Nb_PAC > 1 && sConfig_Hydrau_temp.u8TypeRegul != REGUL_ESCLAVE) || u8Nb_PAC > 2)
    {
    	u8Nb_PAC--;
        // Possibilité d'activer la résistance de terminaison (si plus d'une PAC)
        if(u8Nb_PAC <= 1)
        {
            touchgfx_printf("resistance terminaison non affichee\n");
        	container_resistance_terminaison_regul_2_zones.setVisible(false);
        	container_resistance_terminaison_regul_2_zones.invalidate();
        	container_resistance_terminaison_regul_multizones.setVisible(false);
        	container_resistance_terminaison_regul_multizones.invalidate();
    		container_resistance_terminaison_regul_externe.setVisible(false);
    		container_resistance_terminaison_regul_externe.invalidate();
        }
        // MAJ de la valeur
        touchgfx_printf("nb pac = %d\n", u8Nb_PAC);
        Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
        textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
        textArea_valeur_nombre_pac.invalidate();
    }
}

void Installation_hydrauliqueView::bouton_zone_1()
{
	if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE)
	{
		sConfig_Hydrau_temp.sZones.bZone1 = toggleButton_zone_1_on_off_regul_directe.getState();
	}
	else sConfig_Hydrau_temp.sZones.bZone1 = toggleButton_zone_1_on_off_regul_2_zones.getState();
	affichage_zones();
}

void Installation_hydrauliqueView::bouton_zone_2()
{
	if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE)
	{
		sConfig_Hydrau_temp.sZones.bZone2 = toggleButton_zone_2_on_off_regul_directe.getState();
	}
	else sConfig_Hydrau_temp.sZones.bZone2 = toggleButton_zone_2_on_off_regul_2_zones.getState();
	affichage_zones();
}

void Installation_hydrauliqueView::bouton_param_zone_1()
{
	sConfig_Hydrau_temp.u8NumZone = 0;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[0], sizeof(S_PARAM_ZX));
	application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydrauliqueView::bouton_param_zone_2()
{
	sConfig_Hydrau_temp.u8NumZone = 1;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[1], sizeof(S_PARAM_ZX));
	application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
}

void Installation_hydrauliqueView::MAJ_Etat_Bouton_Oui_Non_Multizone()
{
	if (sParamZxMZtemp[8].type_zone.GroupeEau.bGroupeActif == true || sParamZxMZtemp[9].type_zone.GroupeEau.bGroupeActif == true)
	{
		toggleButton_non_oui_non_regroupement.forceState(false);
		toggleButton_non_oui_non_regroupement.invalidate();
		toggleButton_oui_oui_non_regroupement.forceState(true);
		toggleButton_oui_oui_non_regroupement.invalidate();
		buttonWithLabel_parametrage_groupes_zones.setLabelText(touchgfx::TypedText(T_TEXT_PARAM_GROUPE_ZONE_CENTRE_DEFAUT));
		buttonWithLabel_parametrage_groupes_zones.invalidate();
		bRegroupementZoneTemp = true;
	}
	else
	{
		toggleButton_non_oui_non_regroupement.forceState(true);
		toggleButton_non_oui_non_regroupement.invalidate();
		toggleButton_oui_oui_non_regroupement.forceState(false);
		toggleButton_oui_oui_non_regroupement.invalidate();
		buttonWithLabel_parametrage_groupes_zones.setLabelText(touchgfx::TypedText(T_TEXT_PARAMETRAGE_ZONE_INDEPENDANTES));
		buttonWithLabel_parametrage_groupes_zones.invalidate();
		bRegroupementZoneTemp = false;
	}
}

void Installation_hydrauliqueView::bouton_oui_regroupement()
{
	toggleButton_non_oui_non_regroupement.forceState(false);
	toggleButton_non_oui_non_regroupement.invalidate();
	toggleButton_oui_oui_non_regroupement.forceState(true);
	toggleButton_oui_oui_non_regroupement.invalidate();
	buttonWithLabel_parametrage_groupes_zones.setLabelText(touchgfx::TypedText(T_TEXT_PARAM_GROUPE_ZONE_CENTRE_DEFAUT));
	buttonWithLabel_parametrage_groupes_zones.invalidate();
	bRegroupementZoneTemp = true;
	//application().gotoInstallation_hydraulique_message_multizonesScreenNoTransition();
}

void Installation_hydrauliqueView::bouton_non_regroupement()
{
	toggleButton_non_oui_non_regroupement.forceState(true);
	toggleButton_non_oui_non_regroupement.invalidate();
	toggleButton_oui_oui_non_regroupement.forceState(false);
	toggleButton_oui_oui_non_regroupement.invalidate();
	buttonWithLabel_parametrage_groupes_zones.setLabelText(touchgfx::TypedText(T_TEXT_PARAMETRAGE_ZONE_INDEPENDANTES));
	buttonWithLabel_parametrage_groupes_zones.invalidate();
	bRegroupementZoneTemp = false;
}

void Installation_hydrauliqueView::bouton_parametrage_groupes_zones()
{
	if (bRegroupementZoneTemp)
	{
		application().gotoInstallation_MZ_parametrage_groupesScreenNoTransition();
	}
	else
	{
		application().gotoInstallation_MZ_param_ou_regroupement_zonesScreenNoTransition();
	}
}

void Installation_hydrauliqueView::affichage_zones()
{
	// Zone 1
	if(sConfig_Hydrau_temp.sZones.bZone1 != 0 && button_zone_1_regul_directe.isVisible() == false)
	{
		// Regul directe
		button_zone_1_regul_directe.setVisible(true);
		button_zone_1_regul_directe.invalidate();
		textArea_bouton_zone_1_regul_directe.setVisible(true);
		textArea_bouton_zone_1_regul_directe.invalidate();
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
		// Regul BCP / 2 zones
		button_zone_1_regul_2_zones.setVisible(true);
		button_zone_1_regul_2_zones.invalidate();
		textArea_bouton_zone_1_regul_2_zones.setVisible(true);
		textArea_bouton_zone_1_regul_2_zones.invalidate();
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_2_zones.invalidate();
	}
	else if(sConfig_Hydrau_temp.sZones.bZone1 == 0 && button_zone_1_regul_directe.isVisible() == true)
	{
		// Regul directe
		button_zone_1_regul_directe.setVisible(false);
		button_zone_1_regul_directe.invalidate();
		textArea_bouton_zone_1_regul_directe.setVisible(false);
		textArea_bouton_zone_1_regul_directe.invalidate();
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
		// Regul BCP / 2 zones
		button_zone_1_regul_2_zones.setVisible(false);
		button_zone_1_regul_2_zones.invalidate();
		textArea_bouton_zone_1_regul_2_zones.setVisible(false);
		textArea_bouton_zone_1_regul_2_zones.invalidate();
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_2_zones.invalidate();
	}
	// Zone 2
	if(sConfig_Hydrau_temp.sZones.bZone2 != 0 && button_zone_2_regul_directe.isVisible() == false)
	{
		// Regul directe
		button_zone_2_regul_directe.setVisible(true);
		button_zone_2_regul_directe.invalidate();
		textArea_bouton_zone_2_regul_directe.setVisible(true);
		textArea_bouton_zone_2_regul_directe.invalidate();
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
		// Regul BCP / 2 zones
		button_zone_2_regul_2_zones.setVisible(true);
		button_zone_2_regul_2_zones.invalidate();
		textArea_bouton_zone_2_regul_2_zones.setVisible(true);
		textArea_bouton_zone_2_regul_2_zones.invalidate();
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
	}
	else if(sConfig_Hydrau_temp.sZones.bZone2 == 0 && button_zone_2_regul_directe.isVisible() == true)
	{
		// Regul directe
		button_zone_2_regul_directe.setVisible(false);
		button_zone_2_regul_directe.invalidate();
		textArea_bouton_zone_2_regul_directe.setVisible(false);
		textArea_bouton_zone_2_regul_directe.invalidate();
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
		// Regul BCP / 2 zones
		button_zone_2_regul_2_zones.setVisible(false);
		button_zone_2_regul_2_zones.invalidate();
		textArea_bouton_zone_2_regul_2_zones.setVisible(false);
		textArea_bouton_zone_2_regul_2_zones.invalidate();
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_2_zones.invalidate();
	}
	//
	if(sConfig_Hydrau_temp.u8TypeRegul == REGUL_DIRECTE && sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2)// button_zone_1_regul_directe.isVisible() && button_zone_2_regul_directe.isVisible() && buttonWithLabel_repartition_puissance_zones_regul_directe.isVisible() == false)
	{
		buttonWithLabel_repartition_puissance_zones_regul_directe.setVisible(true);
		buttonWithLabel_repartition_puissance_zones_regul_directe.invalidate();
		textArea_regul_plancher.setVisible(true);
		textArea_regul_plancher.invalidate();
	}
	else //if(sConfig_Hydrau_temp.u8TypeRegul != REGUL_DIRECTE || ((button_zone_1_regul_directe.isVisible() == false || button_zone_2_regul_directe.isVisible() == false) && buttonWithLabel_repartition_puissance_zones_regul_directe.isVisible() == true))
	{
		buttonWithLabel_repartition_puissance_zones_regul_directe.setVisible(false);
		buttonWithLabel_repartition_puissance_zones_regul_directe.invalidate();
		textArea_regul_plancher.setVisible(false);
		textArea_regul_plancher.invalidate();
	}
}

void Installation_hydrauliqueView ::bouton_repartition_puissance_zone()
{
	application().gotoInstallation_hydraulique_repartition_PW_zoneScreenNoTransition();
}

void Installation_hydrauliqueView ::bouton_hysteresis_regul_directe()
{
	application().gotoInstallation_hysteresisScreenNoTransition();
}

void Installation_hydrauliqueView::bouton_valider() //SER
{
//	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));//SER
//	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
//	sConfig_Hydrau_temp
	sConfig_IHM.sParam_PAC.TypeRegul = sConfig_Hydrau_temp.u8TypeRegul;
	sConfig_IHM.sParam_PAC.numEsclave = u8Nb_PAC - 1;
	sConfig_IHM.sOption_PAC.sZone = sConfig_Hydrau_temp.sZones;
	presenter->c_install_param();
//	if(bCartePhoenix == false)
//	{
//		// Vitesse circulateur
//		sConfig_IHM.sParam_PAC.eGestionCirculateurPrimaire = u8VitesseCirculateur;
//		// Marche forcée
//		if(toggleButton_oui_oui_non_marche_forcee.getState())
//		{
//			sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce = 1;
//		}
//		else sConfig_IHM.sParam_PAC.bCirculateurPrimaireForce = 0;
//		// Type circulateur
//		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sParam_PAC.TypeCirculateur = TYPE_RELAIS;
//		}
//		else sConfig_IHM.sParam_PAC.TypeCirculateur = TYPE_GRUNDFOS;
//		//
//		presenter->c_install_param();
//	}
//	else
//	{
//		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_GRUNDFOS;
//		}
//		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_WILO;
//		}
//		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = TYPE_RELAIS;
//		}
//		//
//		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeCirculateurPrimaire = u8VitesseCirculateur;
//		// Marche forcée
//		if(toggleButton_oui_oui_non_marche_forcee.getState())
//		{
//			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce = 1;
//		}
//		else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurPrimaireForce = 0;
//		//
//		presenter->c_usine_phoenix(0);
//	}
	application().gotoInstallationScreenNoTransition();
}

void Installation_hydrauliqueView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	;
}

void Installation_hydrauliqueView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_hydrauliqueView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_hydrauliqueView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_hydrauliqueView::changeDate(S_DATE *sDate)
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
