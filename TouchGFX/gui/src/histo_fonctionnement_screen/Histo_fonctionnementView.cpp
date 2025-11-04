#include <gui/histo_fonctionnement_screen/Histo_fonctionnementView.hpp>
#include <touchgfx/Utils.hpp>
#include <touchgfx/Color.hpp>



Histo_fonctionnementView::Histo_fonctionnementView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);

	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_HISTO_CENTRE_LARGE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}


void Histo_fonctionnementView::setupScreen()
{
	Histo_fonctionnementViewBase::setupScreen();

	bGraphPage1 = true;
	if (sConfig_Hydrau_temp.u8TypeRegul < REGUL_BAL_TAMPON_MULTI_ZONE)
	{
		bAffichageTempBallon = false;
	}
	else bAffichageTempBallon = true;
	bPremierPassage = true;

	for (int i = 0; i < 360; ++i)
	{
		box_etat_pac[i].setPosition(i*2, 0, 2, 18);
		box_etat_pac[i].setVisible(false);
		container_etat_pac.add(box_etat_pac[i]);

		box_etat_app_chauf[i].setPosition(i*2, 0, 2, 18);
		box_etat_app_chauf[i].setVisible(false);
		container_etat_app_chauf.add(box_etat_app_chauf[i]);

		box_etat_app_ecs[i].setPosition(i*2, 0, 2, 18);
		box_etat_app_ecs[i].setVisible(false);
		container_etat_app_ecs.add(box_etat_app_ecs[i]);
	}

	update_container();

}

void Histo_fonctionnementView::clear_graph()
{
	memset(&data_histo, 0, sizeof(DATA_HISTO));
	data_histo.bTableauPlein = false;
	data_histo.i16ValminText = 0xFFFF;
	data_histo.u16ValminTeau = 0xFFFF;
	data_histo.u16ValminAmbBall = 0xFFFF;

	graph_temp_z1_ballon.clear();
	graph_temp_z2.clear();
	graph_eau_depart.clear();
	graph_eau_retour.clear();
	graph_temp_ext.clear();

	for (int i = 0; i < 360; ++i)
	{
		box_etat_pac[i].setVisible(false);
		box_etat_app_chauf[i].setVisible(false);
		box_etat_app_ecs[i].setVisible(false);
	}
	container_etat_pac.invalidate();
	container_etat_app_chauf.invalidate();
	container_etat_app_ecs.invalidate();
}

void Histo_fonctionnementView::bouton_droit()
{
	if (bGraphPage1 == true)
	{
		bGraphPage1 = false;
		update_container();
	}
}

void Histo_fonctionnementView::bouton_gauche()
{
	if (bGraphPage1 == false)
	{
		bGraphPage1 = true;
		update_container();
	}
}

void Histo_fonctionnementView::update_container()
{
	if (bGraphPage1 == true)
	{
		container_cercle_depart_retour.setVisible(false);
		container_cercle_depart_retour.invalidate();
		if (bAffichageTempBallon == false)
		{
			container_cercle_ballon_tampon.setVisible(false);
			container_cercle_ballon_tampon.invalidate();
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				container_z1.setVisible(true);
				container_z1.invalidate();
			}
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				container_z2.setVisible(true);
				container_z2.invalidate();
			}
		}
		else
		{
			container_z1.setVisible(false);
			container_z1.invalidate();
			container_z2.setVisible(false);
			container_z2.invalidate();
			container_cercle_ballon_tampon.setVisible(true);
			container_cercle_ballon_tampon.invalidate();
		}
	}
	else
	{
		container_z1.setVisible(false);
		container_z1.invalidate();
		container_z2.setVisible(false);
		container_z2.invalidate();
		container_cercle_ballon_tampon.setVisible(false);
		container_cercle_ballon_tampon.invalidate();
		container_cercle_depart_retour.setVisible(true);
		container_cercle_depart_retour.invalidate();
	}
	container_etat_pac.setVisible(true);
	container_etat_pac.invalidate();
	container_etat_app_chauf.setVisible(true);
	container_etat_app_chauf.invalidate();
	container_etat_app_ecs.setVisible(true);
	container_etat_app_ecs.invalidate();

	update_graph_histo(&data_histo);
}

void Histo_fonctionnementView::tearDownScreen()
{
    Histo_fonctionnementViewBase::tearDownScreen();
}


void Histo_fonctionnementView::update_graph_histo(DATA_HISTO *data_histo)
{
	touchgfx::colortype ColorEtat;

    //MAJ Text Min/Max
    if (bGraphPage1)
    {
		Unicode::snprintf(textArea_Buffer_temp_gauche_max, 7, "%d", (data_histo->u16ValmaxAmbBall/10));
		text_temp_eau_max.setWildcard(textArea_Buffer_temp_gauche_max);
		text_temp_eau_max.invalidate();
		Unicode::snprintf(textArea_Buffer_temp_gauche_min, 7, "%d", (data_histo->u16ValminAmbBall/10));
		text_temp_eau_min.setWildcard(textArea_Buffer_temp_gauche_min);
		text_temp_eau_min.invalidate();
    }
    else
    {
		Unicode::snprintf(textArea_Buffer_temp_gauche_max, 7, "%d", (data_histo->u16ValmaxTeau/10));
		text_temp_eau_max.setWildcard(textArea_Buffer_temp_gauche_max);
		text_temp_eau_max.invalidate();
		Unicode::snprintf(textArea_Buffer_temp_gauche_min, 7, "%d", (data_histo->u16ValminTeau/10));
		text_temp_eau_min.setWildcard(textArea_Buffer_temp_gauche_min);
		text_temp_eau_min.invalidate();
    }

	Unicode::snprintf(textArea_Buffer_temp_droite_max, 7, "%d", (data_histo->i16ValmaxText/10));
	text_temp_ext_max.setWildcard(textArea_Buffer_temp_droite_max);
	text_temp_ext_max.invalidate();
	Unicode::snprintf(textArea_Buffer_temp_droite_min, 7, "%d", (data_histo->i16ValminText/10));
	text_temp_ext_min.setWildcard(textArea_Buffer_temp_droite_min);
	text_temp_ext_min.invalidate();

    //MAJ Définition des limites Min/Max des graphs
	if (bGraphPage1)
	{
		if (bAffichageTempBallon)
		{
			graph_temp_z1_ballon.setGraphRange(0, 359, data_histo->u16ValminAmbBall, data_histo->u16ValmaxAmbBall);
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				graph_temp_z1_ballon.setGraphRange(0, 359, data_histo->u16ValminAmbBall, data_histo->u16ValmaxAmbBall);
			}
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				graph_temp_z2.setGraphRange(0, 359, data_histo->u16ValminAmbBall, data_histo->u16ValmaxAmbBall);
			}
		}
	}
	else
	{
		graph_eau_depart.setGraphRange(0, 359, data_histo->u16ValminTeau, data_histo->u16ValmaxTeau);
		graph_eau_retour.setGraphRange(0, 359, data_histo->u16ValminTeau, data_histo->u16ValmaxTeau);
	}
	graph_temp_ext.setGraphRange(0, 359, data_histo->i16ValminText, data_histo->i16ValmaxText);

	graph_eau_depart.clear();
	graph_eau_retour.clear();
	graph_temp_z1_ballon.clear();
	graph_temp_z2.clear();
	graph_temp_ext.clear();


	if (data_histo->bTableauPlein)
    {
    	for (int i = 0; i < 360; i++)
        {
    		int index = (((data_histo->u16PointeurTableau + 360)%360) - (360 - i) + 360)%360;

            graph_eau_depart.addDataPoint(i, data_histo->u16TempDepart[index]);
            graph_eau_retour.addDataPoint(i, data_histo->u16TempRetour[index]);
            graph_temp_z1_ballon.addDataPoint(i, data_histo->u16TempBallon_Z1[index]);
            graph_temp_z2.addDataPoint(i, data_histo->u16Temp_Z2[index]);
            graph_temp_ext.addDataPoint(i, data_histo->i16TempExt[index]);

            //Etat PAC
			switch(data_histo->etat_pac[index])
			{
				default:
				case COLOR_BLANC: 	ColorEtat = WHITE;	break;
				case COLOR_ORANGE: 	ColorEtat = ORANGE;	break;
				case COLOR_BLEU: 	ColorEtat = BLUE;	break;
				case COLOR_ROSE: 	ColorEtat = PINK;	break;
				case COLOR_VERT: 	ColorEtat = GREEN;	break;
			}
			box_etat_pac[i].setColor(ColorEtat);
			if (data_histo->etat_pac[index] == COLOR_NONE)
			{
				box_etat_pac[i].setVisible(false);
			}
			else box_etat_pac[i].setVisible(true);
			box_etat_pac[i].invalidate();


			//Statut appoint PAC
			if (data_histo->etat_app_chaud[index] == COLOR_ROUGE)
			{
				box_etat_app_chauf[i].setColor(RED);
				box_etat_app_chauf[i].setVisible(true);
			}
			else
			{
				box_etat_app_chauf[i].setVisible(false);
			}
			box_etat_app_chauf[i].invalidate();

			//Statut appoint ECS
			if (data_histo->etat_app_ecs[index] == COLOR_ROSE)
			{
				box_etat_app_ecs[i].setColor(PINK);
				box_etat_app_ecs[i].setVisible(true);
			}
			else
			{
				box_etat_app_ecs[i].setVisible(false);
			}
			box_etat_app_ecs[i].invalidate();
        }
    }
    else
    {
		for (int i = 0; i < data_histo->limit; i++) // = 360 si tableau plein ou sinon pointeur
		{
			int graphIndex = (360 - data_histo->limit + i); //22/10/25 % 360;

			graph_eau_depart.addDataPoint(graphIndex, data_histo->u16TempDepart[i]);
			graph_eau_retour.addDataPoint(graphIndex, data_histo->u16TempRetour[i]);
			graph_temp_z1_ballon.addDataPoint(graphIndex, data_histo->u16TempBallon_Z1[i]);
			graph_temp_z2.addDataPoint(graphIndex, data_histo->u16Temp_Z2[i]);
			graph_temp_ext.addDataPoint(graphIndex, data_histo->i16TempExt[i]);

			//Etat PAC
			switch(data_histo->etat_pac[i])
			{
				default:
				case COLOR_BLANC: 	ColorEtat = WHITE;	break;
				case COLOR_ORANGE: 	ColorEtat = ORANGE;	break;
				case COLOR_BLEU: 	ColorEtat = BLUE;	break;
				case COLOR_ROSE: 	ColorEtat = PINK;	break;
				case COLOR_VERT: 	ColorEtat = GREEN;	break;
			}
			box_etat_pac[graphIndex].setColor(ColorEtat);
			if (data_histo->etat_pac[i] == COLOR_NONE)
			{
				box_etat_pac[graphIndex].setVisible(false);
			}
			else box_etat_pac[graphIndex].setVisible(true);
			box_etat_pac[graphIndex].invalidate();


			//Statut appoint PAC
			if (data_histo->etat_app_chaud[i] == COLOR_ROUGE)
			{
				box_etat_app_chauf[graphIndex].setColor(RED);
				box_etat_app_chauf[graphIndex].setVisible(true);
			}
			else
			{
				box_etat_app_chauf[graphIndex].setVisible(false);
			}
			box_etat_app_chauf[graphIndex].invalidate();

			//Statut appoint ECS
			if (data_histo->etat_app_ecs[i] == COLOR_ROSE)
			{
				box_etat_app_ecs[graphIndex].setColor(PINK);
				box_etat_app_ecs[graphIndex].setVisible(true);
			}
			else
			{
				box_etat_app_ecs[graphIndex].setVisible(false);
			}
			box_etat_app_ecs[graphIndex].invalidate();
		}
    }

    if (bGraphPage1)
	{
		if (bAffichageTempBallon)
		{
			if (graph_temp_z1_ballon.isVisible() == false)
			{
				graph_temp_z1_ballon.setVisible(true);
			}
			graph_temp_z1_ballon.invalidate();
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				if (graph_temp_z1_ballon.isVisible() == false)
				{
					graph_temp_z1_ballon.setVisible(true);
				}
				graph_temp_z1_ballon.invalidate();
			}
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				if (graph_temp_z2.isVisible() == false)
				{
					graph_temp_z2.setVisible(true);
				}
				graph_temp_z2.invalidate();
			}

		}
		graph_eau_depart.setVisible(false);
		graph_eau_depart.invalidate();
		graph_eau_retour.setVisible(false);
		graph_eau_retour.invalidate();
	}
    else
    {
    	graph_temp_z1_ballon.setVisible(false);
		graph_temp_z1_ballon.invalidate();
		graph_temp_z2.setVisible(false);
		graph_temp_z2.invalidate();

		graph_eau_depart.setVisible(true);
		graph_eau_depart.invalidate();
		if (graph_eau_retour.isVisible() == false)
		{
			graph_eau_retour.setVisible(true);
		}
		graph_eau_retour.invalidate();
    }
    if (graph_temp_ext.isVisible() == false)
	{
    	graph_temp_ext.setVisible(true);
	}
    graph_temp_ext.invalidate();

    //Ajout pour essai
    container_etat_pac.invalidate();
    container_etat_app_chauf.invalidate();
    container_etat_app_ecs.invalidate();
}


void Histo_fonctionnementView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Histo_fonctionnementView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Histo_fonctionnementView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Histo_fonctionnementView::changeDate(S_DATE *sDate)
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

