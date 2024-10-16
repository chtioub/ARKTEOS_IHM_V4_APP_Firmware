#include <gui/installation_circuit_captage_screen/Installation_circuit_captageView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>

Installation_circuit_captageView::Installation_circuit_captageView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAM_CIRCUIT_CAPT_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	changeStatutCyclFrigo(&sCyclRegFrigo[0]);


	if(sConfig_IHM.sModele_PAC.u8ModelePAC == GEOTWIN_IV)
	{
		bCartePhoenix = false;
		u8ConsignePompePuitsMin = sConfig_IHM.sConfig_PAC.ConfigGeo.u8ConsignePompePuitsMin;
		u8ConsignePompePuitsMax = sConfig_IHM.sConfig_PAC.ConfigGeo.u8ConsignePompePuitsMax;
		bPilotagePompedePuits = (sConfig_IHM.sConfig_PAC.ConfigGeo.u8ConsignePompePuitsMax != 0) ? true:false;
	}
	else
	{
		bCartePhoenix = true;
		u8ConsignePompePuitsMin = sConfig_IHM.sConfig_PAC.ConfigGeoInverter.u8ConsignePompePuitsMin;
		u8ConsignePompePuitsMax = sConfig_IHM.sConfig_PAC.ConfigGeoInverter.u8ConsignePompePuitsMax;
		bPilotagePompedePuits = (sConfig_IHM.sConfig_PAC.ConfigGeoInverter.u8ConsignePompePuitsMax != 0) ? true:false;
	}


	if(bCartePhoenix == false)
	{
		//Capteur Géotwin
		if (sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage == E_TYPE_CAPTAGE_CAPTEUR)
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
			textArea_valeur_type_capteur.invalidate();
			textArea_pilotage_pompe_puits.setVisible(false);
			container_oui_non_pilotage_pompe_puits.setVisible(false);
			container_oui_non_marche_forcee.setVisible(true);
			container_vitesse_min_pompe_puits.setVisible(false);
			container_vitesse_max_pompe_puits.setVisible(false);
			container_type_circulateur.setVisible(false);
		}
		//Nappe Directe Géotwin
		else if (sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage == E_TYPE_CAPTAGE_NAPPE_DIRECTE)
		{

			scrollableContainer.setScrollbarsVisible(false);
			scrollableContainer.invalidate();

			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_DIRECTE_CENTRE_DEFAUT));
			textArea_valeur_type_capteur.invalidate();
			container_oui_non_pilotage_pompe_puits.setXY(15, 0);
			container_oui_non_pilotage_pompe_puits.setVisible(true);
			container_vitesse_min_pompe_puits.setXY(15, 152);
			if (bPilotagePompedePuits == true)
			{
				container_vitesse_min_pompe_puits.setVisible(true);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(true);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(false);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(false);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(true);

				textArea_pilotage_pompe_puits.setXY(486, 0);
				textArea_pilotage_pompe_puits.setVisible(true);
				textArea_pilotage_pompe_puits.invalidate();
				update_vitesse_min_pompe_puits();
				update_vitesse_max_pompe_puits();

				if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2)
				{
					container_vitesse_max_pompe_puits.setXY(486, 152);
					container_vitesse_max_pompe_puits.setVisible(true);
					container_vitesse_max_pompe_puits.invalidate();
				}
				else
				{
					textArea_vitesse_min_pompe_puits.setTypedText(touchgfx::TypedText(T_TEXT_VITESSE_POMPE_DE_PUITS));
					textArea_vitesse_min_pompe_puits.invalidate();
					container_vitesse_max_pompe_puits.setVisible(false);
					container_vitesse_max_pompe_puits.invalidate();
				}
			}
			else
			{
				container_vitesse_min_pompe_puits.setVisible(false);
				container_vitesse_min_pompe_puits.invalidate();
				container_vitesse_max_pompe_puits.setVisible(false);
				container_vitesse_max_pompe_puits.invalidate();
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(false);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(true);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(true);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(false);

				textArea_pilotage_pompe_puits.setVisible(false);
			}

			container_type_capteur.setVisible(false);
			container_oui_non_marche_forcee.setVisible(false);
			container_type_circulateur.setVisible(false);
			container_vitesse_circulateur.setVisible(false);
		}
		//Nappe Barrage Géotwin
		else
		{
			container_type_circulateur.setVisible(false);
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
			textArea_valeur_type_capteur.invalidate();
			container_oui_non_pilotage_pompe_puits.setXY(15, 304);
			container_oui_non_pilotage_pompe_puits.invalidate();
//			container_oui_non_pilotage_pompe_puits.setVisible(false);
//			container_vitesse_pompe_puits_geotwin.setVisible(true);

			//Ajout
			if (bPilotagePompedePuits == true)
			{
				container_vitesse_min_pompe_puits.setVisible(true);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(true);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(false);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(false);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(true);

				textArea_pilotage_pompe_puits.setXY(486, 303);
				textArea_pilotage_pompe_puits.setVisible(true);
				textArea_pilotage_pompe_puits.invalidate();
				update_vitesse_min_pompe_puits();
				update_vitesse_max_pompe_puits();

				if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2)
				{
					container_vitesse_max_pompe_puits.setXY(486, 152);
					container_vitesse_max_pompe_puits.setVisible(true);
					container_vitesse_max_pompe_puits.invalidate();
				}
				else
				{
					textArea_vitesse_min_pompe_puits.setTypedText(touchgfx::TypedText(T_TEXT_VITESSE_POMPE_DE_PUITS));
					textArea_vitesse_min_pompe_puits.invalidate();
					container_vitesse_max_pompe_puits.setVisible(false);
					container_vitesse_max_pompe_puits.invalidate();
				}
			}
			else
			{
				container_vitesse_min_pompe_puits.setVisible(false);
				container_vitesse_min_pompe_puits.invalidate();
				container_vitesse_max_pompe_puits.setVisible(false);
				container_vitesse_max_pompe_puits.invalidate();
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(false);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(true);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(true);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(false);

				textArea_pilotage_pompe_puits.setVisible(false);
			}
			//Ajout

		}

		if(sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeCirculateurCaptage == TYPE_GRUNDFOS)
		{
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
		}
		else
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		//
		u8VitesseCirculateur = sConfig_IHM.sConfig_PAC.ConfigGeo.eGestionCirculateurCaptage;
		vitesseCirculateur();
		// Marche forcée
		if(sConfig_IHM.sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce == 0)
		{
			toggleButton_oui_oui_non_marche_forcee.forceState(false);
			toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
			toggleButton_non_oui_non_marche_forcee.forceState(true);
			toggleButton_non_oui_non_marche_forcee.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_marche_forcee.forceState(true);
			toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
			toggleButton_non_oui_non_marche_forcee.forceState(false);
			toggleButton_non_oui_non_marche_forcee.setTouchable(true);
		}
		toggleButton_oui_oui_non_marche_forcee.invalidate();
		toggleButton_non_oui_non_marche_forcee.invalidate();
	}
	else
	{
		if (sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeDeCaptage == E_TYPE_CAPTAGE_CAPTEUR)
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
			textArea_valeur_type_capteur.invalidate();

			container_oui_non_pilotage_pompe_puits.setVisible(false);
			container_oui_non_pilotage_pompe_puits.invalidate();
			textArea_pilotage_pompe_puits.setVisible(false);
			textArea_pilotage_pompe_puits.invalidate();
			container_vitesse_min_pompe_puits.setVisible(false);
			container_vitesse_min_pompe_puits.invalidate();
			container_vitesse_max_pompe_puits.setVisible(false);
			container_vitesse_max_pompe_puits.invalidate();
		}
		else
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
			textArea_valeur_type_capteur.invalidate();

			container_oui_non_pilotage_pompe_puits.setVisible(true);
			container_oui_non_pilotage_pompe_puits.invalidate();

			if (bPilotagePompedePuits)
			{
				update_vitesse_min_pompe_puits();
				update_vitesse_max_pompe_puits();
				container_vitesse_min_pompe_puits.setVisible(true);
				container_vitesse_min_pompe_puits.invalidate();
				container_vitesse_max_pompe_puits.setVisible(true);
				container_vitesse_max_pompe_puits.invalidate();
				textArea_pilotage_pompe_puits.setXY(486, 303);
				textArea_pilotage_pompe_puits.setVisible(true);
				textArea_pilotage_pompe_puits.invalidate();
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(true);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(false);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(false);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(true);

			}
			else
			{
				container_vitesse_min_pompe_puits.setVisible(false);
				container_vitesse_min_pompe_puits.invalidate();
				container_vitesse_max_pompe_puits.setVisible(false);
				container_vitesse_max_pompe_puits.invalidate();
				textArea_pilotage_pompe_puits.setVisible(false);
				textArea_pilotage_pompe_puits.invalidate();
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(false);
				toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(true);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(true);
				toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(false);
			}
			toggleButton_oui_oui_non_pilotage_vit_pompe_puits.invalidate();
			toggleButton_non_oui_non_pilotage_vit_pompe_puits.invalidate();
		}

		// Type Circulateur
		switch(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeVentiloCircCaptage)
		{
			case TYPE_GRUNDFOS:
				textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT));
				break;
			case TYPE_WILO:
				textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT));
				break;
			case TYPE_RELAIS:
				textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
				container_vitesse_circulateur.setVisible(false);
				break;
		}
		//
		u8VitesseCirculateur = sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eGestionCirculateurCaptage;
		vitesseCirculateur();
		// Marche forcée
		if(sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce == 0)
		{
			toggleButton_oui_oui_non_marche_forcee.forceState(false);
			toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
			toggleButton_non_oui_non_marche_forcee.forceState(true);
			toggleButton_non_oui_non_marche_forcee.setTouchable(false);
		}
		else
		{
			toggleButton_oui_oui_non_marche_forcee.forceState(true);
			toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
			toggleButton_non_oui_non_marche_forcee.forceState(false);
			toggleButton_non_oui_non_marche_forcee.setTouchable(true);
		}
		toggleButton_oui_oui_non_marche_forcee.invalidate();
		toggleButton_non_oui_non_marche_forcee.invalidate();
	}

}


void Installation_circuit_captageView::vitesseCirculateur()
{
    switch(u8VitesseCirculateur)
    {
		default:
		case GC_AUTO:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_DEFAUT_CENTRE_DEFAUT));
			break;
		case GC_V40:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V40_CENTRE_DEFAUT));
			break;
		case GC_V50:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V50_CENTRE_DEFAUT));
			break;
		case GC_V60:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V60_CENTRE_DEFAUT));
			break;
		case GC_V70:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V70_CENTRE_DEFAUT));
			break;
		case GC_V80:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V80_CENTRE_DEFAUT));
			break;
		case GC_V90:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V90_CENTRE_DEFAUT));
			break;
		case GC_V100:
			textArea_valeur_vitesse_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_VIT_CIRCULTEUR_V100_CENTRE_DEFAUT));
			break;
    }
    textArea_valeur_vitesse_circulateur.invalidate();
}

void Installation_circuit_captageView::bouton_moins_vitesse_circ()
{
	if(u8VitesseCirculateur == GC_AUTO)
	{
		u8VitesseCirculateur = GC_V100;
	}
	else u8VitesseCirculateur--;
	vitesseCirculateur();
}

void Installation_circuit_captageView::bouton_plus_vitesse_circ()
{
	if(++u8VitesseCirculateur > GC_V100)
	{
		u8VitesseCirculateur = GC_AUTO;
	}
	vitesseCirculateur();
}

void Installation_circuit_captageView::bouton_moins_vitesse_min_pompe_puits()
{
	if(u8ConsignePompePuitsMin > 25)
	{
		u8ConsignePompePuitsMin = u8ConsignePompePuitsMin - 5;
	}

	update_vitesse_min_pompe_puits();
	if (u8ConsignePompePuitsMin > u8ConsignePompePuitsMax)
	{
		u8ConsignePompePuitsMax = u8ConsignePompePuitsMin;
		update_vitesse_max_pompe_puits();
	}
}

void Installation_circuit_captageView::bouton_plus_vitesse_min_pompe_puits()
{
	if(u8ConsignePompePuitsMin < 100)
	{
		u8ConsignePompePuitsMin = u8ConsignePompePuitsMin + 5;
	}
	update_vitesse_min_pompe_puits();
	if (u8ConsignePompePuitsMin > u8ConsignePompePuitsMax)
	{
		u8ConsignePompePuitsMax = u8ConsignePompePuitsMin;
		update_vitesse_max_pompe_puits();
	}
}

void Installation_circuit_captageView::bouton_moins_vitesse_max_pompe_puits()
{
	if(u8ConsignePompePuitsMax > 25)
	{
		u8ConsignePompePuitsMax = u8ConsignePompePuitsMax - 5;
	}
	update_vitesse_max_pompe_puits();
	if (u8ConsignePompePuitsMax < u8ConsignePompePuitsMin)
	{
		u8ConsignePompePuitsMin = u8ConsignePompePuitsMax;
		update_vitesse_min_pompe_puits();
	}
}

void Installation_circuit_captageView::bouton_plus_vitesse_max_pompe_puits()
{
	if(u8ConsignePompePuitsMax < 100)
	{
		u8ConsignePompePuitsMax = u8ConsignePompePuitsMax + 5;
	}
	update_vitesse_max_pompe_puits();
	if (u8ConsignePompePuitsMax < u8ConsignePompePuitsMin)
	{
		u8ConsignePompePuitsMin = u8ConsignePompePuitsMax;
		update_vitesse_min_pompe_puits();
	}
}

void Installation_circuit_captageView::bouton_non_marche_forcee()
{
	if(toggleButton_non_oui_non_marche_forcee.getState())
	{
		toggleButton_oui_oui_non_marche_forcee.forceState(false);
		toggleButton_oui_oui_non_marche_forcee.setTouchable(true);
		toggleButton_oui_oui_non_marche_forcee.invalidate();
		toggleButton_non_oui_non_marche_forcee.setTouchable(false);
		toggleButton_non_oui_non_marche_forcee.invalidate();
	}
}

void Installation_circuit_captageView::bouton_oui_marche_forcee()
{
	if(toggleButton_oui_oui_non_marche_forcee.getState())
	{
		toggleButton_non_oui_non_marche_forcee.forceState(false);
		toggleButton_non_oui_non_marche_forcee.setTouchable(true);
		toggleButton_non_oui_non_marche_forcee.invalidate();
		toggleButton_oui_oui_non_marche_forcee.setTouchable(false);
		toggleButton_oui_oui_non_marche_forcee.invalidate();
	}
}

void Installation_circuit_captageView::bouton_non_pilotage_vit_pompe_puits()
{
	if(toggleButton_non_oui_non_pilotage_vit_pompe_puits.getState())
	{
		toggleButton_oui_oui_non_pilotage_vit_pompe_puits.forceState(false);
		toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(true);
		toggleButton_oui_oui_non_pilotage_vit_pompe_puits.invalidate();
		toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(false);
		toggleButton_non_oui_non_pilotage_vit_pompe_puits.invalidate();

		textArea_pilotage_pompe_puits.setVisible(false);
		textArea_pilotage_pompe_puits.invalidate();
		bPilotagePompedePuits = false;
		if(bCartePhoenix == false)
		{
			container_vitesse_min_pompe_puits.setVisible(false);
			container_vitesse_min_pompe_puits.invalidate();
			if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2)
			{
				container_vitesse_max_pompe_puits.setVisible(false);
				container_vitesse_max_pompe_puits.invalidate();
			}
		}
		else
		{
			container_vitesse_min_pompe_puits.setVisible(false);
			container_vitesse_min_pompe_puits.invalidate();
			container_vitesse_max_pompe_puits.setVisible(false);
			container_vitesse_max_pompe_puits.invalidate();
		}
		u8ConsignePompePuitsMin = 0;
		u8ConsignePompePuitsMax = 0;
		update_vitesse_min_pompe_puits();
		update_vitesse_max_pompe_puits();
	}
}

void Installation_circuit_captageView::bouton_oui_pilotage_vit_pompe_puits()
{
	if(	toggleButton_oui_oui_non_pilotage_vit_pompe_puits.getState())
	{
		toggleButton_non_oui_non_pilotage_vit_pompe_puits.forceState(false);
		toggleButton_non_oui_non_pilotage_vit_pompe_puits.setTouchable(true);
		toggleButton_non_oui_non_pilotage_vit_pompe_puits.invalidate();
		toggleButton_oui_oui_non_pilotage_vit_pompe_puits.setTouchable(false);
		toggleButton_oui_oui_non_pilotage_vit_pompe_puits.invalidate();
		if(bCartePhoenix == false && sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage == E_TYPE_CAPTAGE_NAPPE_DIRECTE)
		{
			textArea_pilotage_pompe_puits.setXY(486, 0);
		}

		textArea_pilotage_pompe_puits.setVisible(true);
		textArea_pilotage_pompe_puits.invalidate();
		bPilotagePompedePuits = true;

		u8ConsignePompePuitsMin = 60;
		u8ConsignePompePuitsMax = 100;
		bPilotagePompedePuits = true;

		if(bCartePhoenix == false)
		{
			if (sConfig_IHM.sModele_PAC.nbCompresseur == NB_COMPRESSEUR_2)
			{
				container_vitesse_max_pompe_puits.setXY(486, 152);
				container_vitesse_max_pompe_puits.setVisible(true);
				container_vitesse_max_pompe_puits.invalidate();
			}
			else
			{
				textArea_vitesse_min_pompe_puits.setTypedText(touchgfx::TypedText(T_TEXT_VITESSE_POMPE_DE_PUITS));
				textArea_vitesse_min_pompe_puits.invalidate();
				container_vitesse_max_pompe_puits.setVisible(false);
				container_vitesse_max_pompe_puits.invalidate();
			}
		}
		else
		{
			//container_vitesse_max_pompe_puits.setXY(486, 459);
			container_vitesse_max_pompe_puits.setVisible(true);
			container_vitesse_max_pompe_puits.invalidate();
		}

		container_vitesse_min_pompe_puits.setVisible(true);
		container_vitesse_min_pompe_puits.invalidate();

		update_vitesse_min_pompe_puits();
		update_vitesse_max_pompe_puits();
		//scrollableContainer.invalidate();
	}
}

void Installation_circuit_captageView::bouton_gauche_type_circulateur()
{
	if(bCartePhoenix == false)
	{
		//
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
		}
		else
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		container_vitesse_circulateur.invalidate();
		textArea_valeur_type_circulateur.invalidate();
	}
	else
	{
		// Type Circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT));
		}
		container_vitesse_circulateur.invalidate();
		textArea_valeur_type_circulateur.invalidate();
	}
}

void Installation_circuit_captageView::bouton_droite_type_circulateur()
{
	if(bCartePhoenix == false)
	{
		//
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PILOTE_CENTRE_DEFAUT));
		}
		else
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		container_vitesse_circulateur.invalidate();
		textArea_valeur_type_circulateur.invalidate();
	}
	else
	{
		// Type Circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(false);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT));
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			container_vitesse_circulateur.setVisible(true);
			textArea_valeur_type_circulateur.setTypedText(touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT));
		}
		container_vitesse_circulateur.invalidate();
		textArea_valeur_type_circulateur.invalidate();
	}
}

void Installation_circuit_captageView::bouton_gauche_type_capteur()
{
	if(bCartePhoenix == false)
	{
		//
		if(textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getId())
		{
			//container_type_capteur.setVisible(true);
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
			container_oui_non_pilotage_pompe_puits.setXY(15, 304);
			container_oui_non_pilotage_pompe_puits.invalidate();
		}
		else
		{
			//container_type_capteur.setVisible(false);
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
		}

	}
	else
	{

		if(textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getId())
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
			container_oui_non_pilotage_pompe_puits.setXY(15, 304);
			container_oui_non_pilotage_pompe_puits.setVisible(true);
		}
		else
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
			container_oui_non_pilotage_pompe_puits.setVisible(false);
			textArea_pilotage_pompe_puits.setVisible(false);
			container_vitesse_min_pompe_puits.setVisible(false);
			container_vitesse_max_pompe_puits.setVisible(false);
		}
	}
	container_oui_non_pilotage_pompe_puits.invalidate();
	textArea_pilotage_pompe_puits.invalidate();
	container_vitesse_min_pompe_puits.invalidate();
	container_vitesse_max_pompe_puits.invalidate();
	container_type_capteur.invalidate();
	textArea_valeur_type_capteur.invalidate();
}

void Installation_circuit_captageView::bouton_droite_type_capteur()
{
	if(bCartePhoenix == false)
	{
		//
		if(textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getId())
		{
			//container_type_capteur.setVisible(true);
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
		}
		else
		{
			//container_type_capteur.setVisible(false);
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
		}

	}
	else
	{

		if(textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getId())
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
			container_oui_non_pilotage_pompe_puits.setXY(15, 304);
			container_oui_non_pilotage_pompe_puits.setVisible(true);
		}
		else
		{
			textArea_valeur_type_capteur.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
			container_oui_non_pilotage_pompe_puits.setVisible(false);
			textArea_pilotage_pompe_puits.setVisible(false);
			container_vitesse_min_pompe_puits.setVisible(false);
			container_vitesse_max_pompe_puits.setVisible(false);
		}
	}
	container_oui_non_pilotage_pompe_puits.invalidate();
	textArea_pilotage_pompe_puits.invalidate();
	container_vitesse_min_pompe_puits.invalidate();
	container_vitesse_max_pompe_puits.invalidate();
	container_type_capteur.invalidate();
	textArea_valeur_type_capteur.invalidate();
}

void Installation_circuit_captageView::update_vitesse_min_pompe_puits()
{
	Unicode::snprintf(textAreaBuffer_Vitesse_Min_Pompe_Puits, 4,"%d", u8ConsignePompePuitsMin);
	textArea_valeur_vitesse_min_pompe_puits.setWildcard(textAreaBuffer_Vitesse_Min_Pompe_Puits);
	textArea_valeur_vitesse_min_pompe_puits.invalidate();
}

void Installation_circuit_captageView::update_vitesse_max_pompe_puits()
{
	Unicode::snprintf(textAreaBuffer_Vitesse_Max_Pompe_Puits, 4,"%d", u8ConsignePompePuitsMax);
	textArea_valeur_vitesse_max_pompe_puits.setWildcard(textAreaBuffer_Vitesse_Max_Pompe_Puits);
	textArea_valeur_vitesse_max_pompe_puits.invalidate();
}


void Installation_circuit_captageView::bouton_valider()
{
	if(bCartePhoenix == false)
	{
		// Vitesse circulateur
		sConfig_IHM.sConfig_PAC.ConfigGeo.eGestionCirculateurCaptage = u8VitesseCirculateur;
		// Marche forcée
		if(toggleButton_oui_oui_non_marche_forcee.getState())
		{
			sConfig_IHM.sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce = 1;
		}
		else sConfig_IHM.sConfig_PAC.ConfigGeo.bGestionCirculateurCaptageForce = 0;
		// Type circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeCirculateurCaptage = TYPE_RELAIS;
		}
		else sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeCirculateurCaptage = TYPE_GRUNDFOS;

		// Type de capteur
		if(textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage = E_TYPE_CAPTAGE_CAPTEUR;
		}
		else if (textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage = E_TYPE_CAPTAGE_NAPPE_BARRAGE;
		}
		else sConfig_IHM.sConfig_PAC.ConfigGeo.eTypeDeCaptage = E_TYPE_CAPTAGE_NAPPE_DIRECTE;



		sConfig_IHM.sConfig_PAC.ConfigGeo.u8ConsignePompePuitsMin = u8ConsignePompePuitsMin;
		sConfig_IHM.sConfig_PAC.ConfigGeo.u8ConsignePompePuitsMax = u8ConsignePompePuitsMax;
		presenter->c_usine_param();

	}
	else
	{
		sConfig_IHM.sConfig_PAC.ConfigGeoInverter.u8ConsignePompePuitsMin = u8ConsignePompePuitsMin;
		sConfig_IHM.sConfig_PAC.ConfigGeoInverter.u8ConsignePompePuitsMax = u8ConsignePompePuitsMax;
		presenter->c_usine_param();

		// Type de circulateur
		if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_PWM_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeVentiloCircCaptage = TYPE_GRUNDFOS;
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_0_10V_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeVentiloCircCaptage = TYPE_WILO;
		}
		else if(textArea_valeur_type_circulateur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_TYPE_CIRCULATEUR_RELAIS_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeVentiloCircCaptage = TYPE_RELAIS;
		}

		// Type de capteur
		if(textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeDeCaptage = E_TYPE_CAPTAGE_CAPTEUR;
		}
		else if (textArea_valeur_type_capteur.getTypedText().getId() == touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT).getId())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeDeCaptage = E_TYPE_CAPTAGE_NAPPE_BARRAGE;
		}
		else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eTypeDeCaptage = E_TYPE_CAPTAGE_NAPPE_DIRECTE;

		// Vitesse circulateur
		sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.eGestionCirculateurCaptage = u8VitesseCirculateur;
		// Marche forcée
		if(toggleButton_oui_oui_non_marche_forcee.getState())
		{
			sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce = 1;
		}
		else sConfig_IHM.sConfigFrigo[0].sModele_FRIGO.bCirculateurCaptageForce = 0;
		//
		presenter->c_usine_phoenix(0);
	}
	application().gotoInstallationScreenNoTransition();
}

void Installation_circuit_captageView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
//	int i16TempCond = 0;
//	int i16TempEvap = 0;
////	if(sCyclRegFrigo_old.pac. != sCyclRegFrigo->pac)
////	{
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Prim_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire)/10));
//		textArea_temp_DCh_invert.setWildcard(textAreaBuffer_Temp_Dep_Prim_Inv);
//		textArea_temp_DCh_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Ret_Prim_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire)/10));
//		textArea_temp_RCh_invert.setWildcard(textAreaBuffer_Temp_Ret_Prim_Inv);
//		textArea_temp_RCh_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Ret_Capt_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur)/10));
//		textArea_temp_RCa_invert.setWildcard(textAreaBuffer_Temp_Ret_Capt_Inv);
//		textArea_temp_RCa_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Capt_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur)/10));
//		textArea_temp_DCa_invert.setWildcard(textAreaBuffer_Temp_Dep_Capt_Inv);
//		textArea_temp_DCa_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Ext_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur)/10));
//		textArea_temp_ext_invert.setWildcard(textAreaBuffer_Temp_Ext_Inv);
//		textArea_temp_ext_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_HP_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_HP1)/10));
//		textArea_temp_HP_invert.setWildcard(textAreaBuffer_Temp_HP_Inv);
//		textArea_temp_HP_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_BP_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_BP1)/10));
//		textArea_temp_BP_invert.setWildcard(textAreaBuffer_Temp_BP_Inv);
//		textArea_temp_BP_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Liq_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide)/10));
//		textArea_temp_liquide_invert.setWildcard(textAreaBuffer_Temp_Liq_Inv);
//		textArea_temp_liquide_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Press_Cond_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1)/10));
//		textArea_pression_temp_hp_invert.setWildcard1(textAreaBuffer_Press_Cond_Inv);
//		Unicode::snprintfFloat(textAreaBuffer_Press_Evap_Inv, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1)/10));
//		textArea_pression_temp_bp_invert.setWildcard1(textAreaBuffer_Press_Evap_Inv);
//
//		i16TempCond = ConvertPressionToTemperature(GAZ_R454C, 1, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_HP1 + 10);
//		i16TempEvap = ConvertPressionToTemperature(GAZ_R454C, 0, sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Press_BP1 + 10);
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Cond_Inv, 7,"%.1f", ((float)(i16TempCond)/10));
//		textArea_pression_temp_hp_invert.setWildcard2(textAreaBuffer_Temp_Cond_Inv);
//		textArea_pression_temp_hp_invert.invalidate();
//		Unicode::snprintfFloat(textAreaBuffer_Temp_Evap_Inv, 7,"%.1f", ((float)(i16TempEvap)/10));
//		textArea_pression_temp_bp_invert.setWildcard2(textAreaBuffer_Temp_Evap_Inv);
//		textArea_pression_temp_bp_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Temp_HP_Cible_Inv, 6,"%d", sCyclRegFrigo->pac.geoinverter.sStatutFrigoGeoinv.i16Temp_HP_Cible[0]);
//		textArea_temp_HP_cible_invert.setWildcard(textAreaBuffer_Temp_HP_Cible_Inv);
//		textArea_temp_HP_cible_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Debit_Prim_Inv, 6,"%d", sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.u16DebitPrimaire);
//		textArea_debit_chauf_invert.setWildcard(textAreaBuffer_Debit_Prim_Inv);
//		textArea_debit_chauf_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Debit_Capt_Inv, 6,"%d", sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.u16DebitCapteur);
//		textArea_debit_capt_invert.setWildcard(textAreaBuffer_Debit_Capt_Inv);
//		textArea_debit_capt_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Percent_Circ_Cap_Inv, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurCapteur);
//		textArea_circ_cap_invert.setWildcard(textAreaBuffer_Percent_Circ_Cap_Inv);
//		textArea_circ_cap_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Percent_Circ_Prim_Inv, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire);
//		textArea_circ_chauf_invert.setWildcard(textAreaBuffer_Percent_Circ_Prim_Inv);
//		textArea_circ_chauf_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Hz_comp_invert, 4,"%d", sCyclRegFrigo->pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorRunningSpeed / 60);
//		textArea_Hz_comp_invert.setWildcard(textAreaBuffer_Hz_comp_invert);
//		textArea_Hz_comp_invert.invalidate();
//		Unicode::snprintf(textAreaBuffer_Position_EEV, 4,"%d", sCyclRegFrigo->pac.geoinverter.sOutAnaGeoinv.u16PositionDetendeur1);
//		textArea_EEV_invert.setWildcard(textAreaBuffer_Position_EEV);
//		textArea_EEV_invert.invalidate();
//
//		if(sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Appoint1 || sCyclRegFrigo->pac.geoinverter.sOutTorGeoinv.Appoint2_3)
//		{
//			textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
//		}
//		else textArea_appoint_invert.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
//		textArea_appoint_invert.invalidate();
//
//
////		textArea_temp_ballon_froid.setTypedText(touchgfx::TypedText(T_TEXT_BALLON_TAMPON_FROID_GAUCHE_DEFAUT));
//
//		memcpy(&sCyclRegFrigo_old, sCyclRegFrigo, sizeof(S_CYCL_REG_FRI));
////	}

}


void Installation_circuit_captageView::setupScreen()
{
    Installation_circuit_captageViewBase::setupScreen();
}

void Installation_circuit_captageView::tearDownScreen()
{
    Installation_circuit_captageViewBase::tearDownScreen();
}

void Installation_circuit_captageView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_circuit_captageView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_circuit_captageView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_circuit_captageView::changeDate(S_DATE *sDate)
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
