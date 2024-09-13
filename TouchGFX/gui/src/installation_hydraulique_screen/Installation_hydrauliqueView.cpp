#include <gui/installation_hydraulique_screen/Installation_hydrauliqueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Installation_hydrauliqueView::Installation_hydrauliqueView()
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
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_INSTALL_HYDRAU_CENTRE_LARGE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
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
    sConfig_Hydrau_temp.u8TypeRegul = sConfig_IHM.sParam_PAC.TypeRegul;
	affichage_type_regul();
	//
	if(u8Nb_PAC > 1)
	{
		container_resistance_terminaison_regul_2_zones.setVisible(true);
		container_resistance_terminaison_regul_multizones.setVisible(true);
		container_resistance_terminaison_regul_externe.setVisible(true);
		container_resistance_terminaison_regul_esclave.setVisible(true);
	}
	else
	{
		container_resistance_terminaison_regul_2_zones.setVisible(false);
		container_resistance_terminaison_regul_multizones.setVisible(false);
		container_resistance_terminaison_regul_externe.setVisible(false);
		container_resistance_terminaison_regul_esclave.setVisible(false);
	}
	Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
	textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
	// Zones actives
	sConfig_Hydrau_temp.sZones = sConfig_IHM.sOption_PAC.sZone;
	if(sConfig_Hydrau_temp.sZones.bZone1)
	{
		// Regul directe
		button_zone_1_regul_directe.setVisible(true);
		textArea_bouton_zone_1_regul_directe.setVisible(true);
		toggleButton_zone_1_on_off_regul_directe.forceState(true);
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_regul_directe_1.setWildcard(textAreaBuffer_nom_zone1);
		textArea_bouton_zone_1_regul_directe.setWildcard(textAreaBuffer_nom_zone1);
		// Regul BCP / 2 zones
		button_zone_1_regul_2_zones.setVisible(true);
		textArea_bouton_zone_1_regul_2_zones.setVisible(true);
		toggleButton_zone_1_on_off_regul_2_zones.forceState(true);
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_regul_2_zones.setWildcard(textAreaBuffer_nom_zone1);
		textArea_bouton_zone_1_regul_2_zones.setWildcard(textAreaBuffer_nom_zone1);
	}
	if(sConfig_Hydrau_temp.sZones.bZone2)
	{
		// Regul directe
		button_zone_2_regul_directe.setVisible(true);
		textArea_bouton_zone_2_regul_directe.setVisible(true);
		toggleButton_zone_2_on_off_regul_directe.forceState(true);
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_regul_directe_1.setWildcard(textAreaBuffer_nom_zone2);
		textArea_bouton_zone_2_regul_directe.setWildcard(textAreaBuffer_nom_zone2);
		// Regul BCP / 2 zones
		button_zone_2_regul_2_zones.setVisible(true);
		textArea_bouton_zone_2_regul_2_zones.setVisible(true);
		toggleButton_zone_2_on_off_regul_2_zones.forceState(true);
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_regul_2_zones.setWildcard(textAreaBuffer_nom_zone2);
		textArea_bouton_zone_2_regul_2_zones.setWildcard(textAreaBuffer_nom_zone2);
	}
	if(sConfig_Hydrau_temp.sZones.bZone1 && sConfig_Hydrau_temp.sZones.bZone2)
	{
		buttonWithLabel_repartition_puissance_zones_regul_directe.setVisible(true);
	}
	// Appoint
	if(sConfig_IHM.sOption_PAC.TypeAppoint != 0)
	{
		image_on_off_appoint_chauffage.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
	    textArea_on_off_appoint_chauffage.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
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
	affichage_type_regul();
}

void Installation_hydrauliqueView::affichage_type_regul()
{
	// Masque l'ensemble des containers
	container_regul_directe.setVisible(false);
	container_regul_directe.invalidate();
	container_regul_2_zones.setVisible(false);
	container_regul_2_zones.invalidate();
	container_regul_multizones.setVisible(false);
	container_regul_multizones.invalidate();
	container_regul_externe.setVisible(false);
	container_regul_externe.invalidate();
	container_regul_esclave.setVisible(false);
	container_regul_esclave.invalidate();
	textArea_circulateurs_arkteos.setVisible(false);
	textArea_circulateurs_arkteos.invalidate();
	textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NB_PAC_CENTRE_DEFAUT));
	textArea_nombre_pac.invalidate();
	container_nombre_pac.setVisible(true);
	container_nombre_pac.invalidate();
	// Affichage du container de la régulation sélectionnee
	switch(sConfig_Hydrau_temp.u8TypeRegul)
	{
		case REGUL_DIRECTE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_directe.setVisible(true);
			container_regul_directe.invalidate();
			container_nombre_pac.setVisible(false);
			container_nombre_pac.invalidate();
			break;
		case REGUL_BCP_INTERNE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_BCP_INTERNE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			button_gauche_type_regulation.setVisible(false);
			button_gauche_type_regulation.invalidate();
			button_droite_type_regulation.setVisible(false);
			button_droite_type_regulation.invalidate();
			container_regul_2_zones.setVisible(true);
			container_regul_2_zones.invalidate();
			container_nombre_pac.setVisible(false);
			container_nombre_pac.invalidate();
			break;
		case REGUL_BAL_TAMPON_2_ZONES:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_2_zones.setVisible(true);
			container_regul_2_zones.invalidate();
			textArea_circulateurs_arkteos.setVisible(true);
			textArea_circulateurs_arkteos.invalidate();
			break;
		case REGUL_BAL_TAMPON_MULTI_ZONE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTI_ZONES_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_multizones.setVisible(true);
			container_regul_multizones.invalidate();
			break;
		case REGUL_EXTERNE:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_externe.setVisible(true);
			container_regul_externe.invalidate();
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
			textArea_valeur_type_regulation.invalidate();
			textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NUM_PAC_CENTRE_DEFAUT));
			textArea_nombre_pac.invalidate();
			container_regul_esclave.setVisible(true);
			container_regul_esclave.invalidate();
			break;
	}
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
    		container_resistance_terminaison_regul_esclave.setVisible(true);
    		container_resistance_terminaison_regul_esclave.invalidate();
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
    		container_resistance_terminaison_regul_esclave.setVisible(false);
    		container_resistance_terminaison_regul_esclave.invalidate();
        }
        // MAJ de la valeur
        touchgfx_printf("nb pac = %d\n", u8Nb_PAC);
        Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
        textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
        textArea_valeur_nombre_pac.invalidate();
    }
}

void Installation_hydrauliqueView::bouton_zone_1_directe()
{
	touchgfx_printf("status bouton zone 1 : %s\n", toggleButton_zone_1_on_off_regul_directe.getState() ? "true" : "false");

	if(toggleButton_zone_1_on_off_regul_directe.getState())
	{
		button_zone_1_regul_directe.setVisible(true);
		button_zone_1_regul_directe.invalidate();
		textArea_bouton_zone_1_regul_directe.setVisible(true);
		textArea_bouton_zone_1_regul_directe.invalidate();
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
	}
	else
	{
		button_zone_1_regul_directe.setVisible(false);
		button_zone_1_regul_directe.invalidate();
		textArea_bouton_zone_1_regul_directe.setVisible(false);
		textArea_bouton_zone_1_regul_directe.invalidate();
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
	}
}

void Installation_hydrauliqueView::bouton_zone_2_directe()
{
	touchgfx_printf("status bouton zone 2 : %s\n", toggleButton_zone_2_on_off_regul_directe.getState() ? "true" : "false");

	if(toggleButton_zone_2_on_off_regul_directe.getState())
	{
		button_zone_2_regul_directe.setVisible(true);
		button_zone_2_regul_directe.invalidate();
		textArea_bouton_zone_2_regul_directe.setVisible(true);
		textArea_bouton_zone_2_regul_directe.invalidate();
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
	}
	else
	{
		button_zone_2_regul_directe.setVisible(false);
		button_zone_2_regul_directe.invalidate();
		textArea_bouton_zone_2_regul_directe.setVisible(false);
		textArea_bouton_zone_2_regul_directe.invalidate();
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
	}
}

void Installation_hydrauliqueView::bouton_zone_1_2_zones()
{
	touchgfx_printf("status bouton zone 1 : %s\n", toggleButton_zone_1_on_off_regul_2_zones.getState() ? "true" : "false");

	if(toggleButton_zone_1_on_off_regul_2_zones.getState())
	{
		button_zone_1_regul_2_zones.setVisible(true);
		button_zone_1_regul_2_zones.invalidate();
		textArea_bouton_zone_1_regul_2_zones.setVisible(true);
		textArea_bouton_zone_1_regul_2_zones.invalidate();
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
	}
	else
	{
		button_zone_1_regul_2_zones.setVisible(false);
		button_zone_1_regul_2_zones.invalidate();
		textArea_bouton_zone_1_regul_2_zones.setVisible(false);
		textArea_bouton_zone_1_regul_2_zones.invalidate();
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_2_zones.invalidate();
	}
}

void Installation_hydrauliqueView::bouton_zone_2_2_zones()
{
	touchgfx_printf("status bouton zone 2 : %s\n", toggleButton_zone_2_on_off_regul_2_zones.getState() ? "true" : "false");

	if(toggleButton_zone_2_on_off_regul_2_zones.getState())
	{
		button_zone_2_regul_2_zones.setVisible(true);
		button_zone_2_regul_2_zones.invalidate();
		textArea_bouton_zone_2_regul_2_zones.setVisible(true);
		textArea_bouton_zone_2_regul_2_zones.invalidate();
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_2_zones.invalidate();
	}
	else
	{
		button_zone_2_regul_2_zones.setVisible(false);
		button_zone_2_regul_2_zones.invalidate();
		textArea_bouton_zone_2_regul_2_zones.setVisible(false);
		textArea_bouton_zone_2_regul_2_zones.invalidate();
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_2_zones.invalidate();
	}
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
