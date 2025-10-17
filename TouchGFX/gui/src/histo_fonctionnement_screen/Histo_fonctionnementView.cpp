#include <gui/histo_fonctionnement_screen/Histo_fonctionnementView.hpp>
#include <touchgfx/Utils.hpp>
#include <touchgfx/Color.hpp>
//#include <touchgfx/widgets/graph/Graph.hpp>


Histo_fonctionnementView::Histo_fonctionnementView()
{

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

	update_container();
	clear_graph();
	timer_10s();
}

void Histo_fonctionnementView::clear_graph()
{
	u16PointeurTableau = 0;

	for (int i = 0; i < 360; i++)
	{
		u16TempBallon_Z1[i] = 0;
		u16Temp_Z2[i] = 0;
		u16TempDepart[i] = 0;
		u16TempRetour[i] = 0;
		i16TempExt[i] = 0;
	}
	graph_temp_z1_ballon.clear();
	graph_temp_z2.clear();
	graph_eau_depart.clear();
	graph_eau_retour.clear();
	graph_temp_ext.clear();

	bTableauPlein = false;
}

void Histo_fonctionnementView::bouton_droit()
{
	if (bGraphPage1 == true)
	{
		bGraphPage1 = false;
		update_container();
		timer_10s();
	}
}

void Histo_fonctionnementView::bouton_gauche()
{
	if (bGraphPage1 == false)
	{
		bGraphPage1 = true;
		update_container();
		timer_10s();
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
}

void Histo_fonctionnementView::tearDownScreen()
{
    Histo_fonctionnementViewBase::tearDownScreen();
}


void Histo_fonctionnementView::timer_10s()
{

    if (bAffichageTempBallon)
    {
    	u16TempBallon_Z1[u16PointeurTableau] = sStatut_Primaire.i16TeauBallonTampon / 10;
    }
    else
    {
    	u16TempBallon_Z1[u16PointeurTableau] = sStatut_Zx[0].i16Tint / 10;
    	u16Temp_Z2[u16PointeurTableau] = sStatut_Zx[1].i16Tint / 10;
    }
    i16TempExt[u16PointeurTableau] = sCyclRegFrigo[0].commun.i16Text / 10;
    u16TempDepart[u16PointeurTableau] = sStatut_Primaire.i16TeauDepart / 10;
    u16TempRetour[u16PointeurTableau] = sStatut_Primaire.i16TeauRetour / 10;


    //Init des val max
    if (bPremierPassage)
    {
		if (bAffichageTempBallon)
		{
			u16ValmaxAmbBall = u16TempBallon_Z1[0] + 1;//(u16TempBallon[0]>u16TempRetour[0]) ? u16TempBallon[0]:u16TempRetour[0];
			u16ValminAmbBall = u16TempBallon_Z1[0] - 1;//(u16TempBallon[0]<u16TempRetour[0]) ? u16TempBallon[0]:u16TempRetour[0];
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 && sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				u16ValmaxAmbBall = (u16TempBallon_Z1[0]>u16Temp_Z2[0]) ? u16TempBallon_Z1[0] + 1:u16Temp_Z2[0] + 1;
				u16ValminAmbBall = (u16TempBallon_Z1[0]<u16Temp_Z2[0]) ? u16TempBallon_Z1[0] - 1:u16Temp_Z2[0] - 1;
			}
			else if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				u16ValmaxAmbBall = u16TempBallon_Z1[0] + 1;
				u16ValminAmbBall = u16TempBallon_Z1[0] - 1;
			}
			else
			{
				u16ValmaxAmbBall = u16Temp_Z2[0] + 1;
				u16ValminAmbBall = u16Temp_Z2[0] - 1;
			}
		}
		u16ValmaxTeau = (u16TempDepart[0]>u16TempRetour[0]) ? u16TempDepart[0] + 1:u16TempRetour[0] + 1;
		u16ValminTeau = (u16TempDepart[0]<u16TempRetour[0]) ? u16TempDepart[0] - 1:u16TempRetour[0] - 1;
		i16ValmaxText = i16TempExt[0] + 1;
		i16ValminText = i16TempExt[0] - 1;

		bPremierPassage = false;
    }

    uint16_t limit = bTableauPlein ? 360 : u16PointeurTableau + 1;
    for (uint16_t i = 1; i < limit; i++)
    {
    	//Page 1
        if (bAffichageTempBallon)
		{
        	uint16_t valmaxgaucheP1 = u16TempBallon_Z1[i];//>u16TempRetour[i]) ? u16TempBallon[i]:u16TempRetour[i];//u16TempBallon[i];
			if (valmaxgaucheP1 > u16ValmaxAmbBall) u16ValmaxAmbBall = valmaxgaucheP1+1;
			uint16_t valmingaucheP1 = u16TempBallon_Z1[i];//(u16TempBallon[i]<u16TempRetour[i]) ? u16TempBallon[i]:u16TempRetour[i];
			if (valmingaucheP1 < u16ValminAmbBall) u16ValminAmbBall = valmingaucheP1-1;
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 && sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				uint16_t valmaxgaucheP1 = (u16TempBallon_Z1[i]>u16Temp_Z2[i]) ? u16TempBallon_Z1[i]:u16Temp_Z2[i];
				if (valmaxgaucheP1 > u16ValmaxAmbBall) u16ValmaxAmbBall = valmaxgaucheP1+1;
				uint16_t valmingaucheP1 = (u16TempBallon_Z1[i]<u16Temp_Z2[i]) ? u16TempBallon_Z1[i]:u16Temp_Z2[i];
				if (valmingaucheP1 < u16ValminAmbBall) u16ValminAmbBall = valmingaucheP1-1;
			}
			else if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				uint16_t valmaxgaucheP1 = u16TempBallon_Z1[i];//>u16Temp_Z2[i]) ? u16TempBallon_Z1[i]:u16Temp_Z2[i];
				if (valmaxgaucheP1 > u16ValmaxAmbBall) u16ValmaxAmbBall = valmaxgaucheP1+1;
				uint16_t valmingaucheP1 = u16TempBallon_Z1[i];//<u16Temp_Z2[i]) ? u16TempBallon_Z1[i]:u16Temp_Z2[i];
				if (valmingaucheP1 < u16ValminAmbBall) u16ValminAmbBall = valmingaucheP1-1;
			}
			else
			{
				uint16_t valmaxgaucheP1 = u16Temp_Z2[i];
				if (valmaxgaucheP1 > u16ValmaxAmbBall) u16ValmaxAmbBall = valmaxgaucheP1+1;
				uint16_t valmingaucheP1 = u16Temp_Z2[i];
				if (valmingaucheP1 < u16ValminAmbBall) u16ValminAmbBall = valmingaucheP1-1;
			}
		}

        //Page 2
        uint16_t valmaxgaucheP2 = (u16TempDepart[i]>u16TempRetour[i]) ? u16TempDepart[i]:u16TempRetour[i];
		if (valmaxgaucheP2 > u16ValmaxTeau) u16ValmaxTeau = valmaxgaucheP2+1;
		uint16_t valmingaucheP2 = (u16TempDepart[i]<u16TempRetour[i]) ? u16TempDepart[i]:u16TempRetour[i];
		if (valmingaucheP2 < u16ValminTeau) u16ValminTeau = valmingaucheP2-1;

		//Page 1 & 2
		int16_t valmaxdroiteP1P2 = i16TempExt[i];
		if (valmaxdroiteP1P2 > i16ValmaxText) i16ValmaxText = valmaxdroiteP1P2+1;
		int16_t valmindroiteP1P2 = i16TempExt[i];
		if (valmindroiteP1P2 < i16ValminText) i16ValminText = valmindroiteP1P2-1;
    }

    //MAJ Text Min/Max
    if (bGraphPage1)
    {
		Unicode::snprintf(textArea_Buffer_temp_gauche_max, 7, "%d", (u16ValmaxAmbBall));
		text_temp_eau_max.setWildcard(textArea_Buffer_temp_gauche_max);
		text_temp_eau_max.invalidate();
		Unicode::snprintf(textArea_Buffer_temp_gauche_min, 7, "%d", (u16ValminAmbBall));
		text_temp_eau_min.setWildcard(textArea_Buffer_temp_gauche_min);
		text_temp_eau_min.invalidate();
    }
    else
    {
		Unicode::snprintf(textArea_Buffer_temp_gauche_max, 7, "%d", (u16ValmaxTeau));
		text_temp_eau_max.setWildcard(textArea_Buffer_temp_gauche_max);
		text_temp_eau_max.invalidate();
		Unicode::snprintf(textArea_Buffer_temp_gauche_min, 7, "%d", (u16ValminTeau));
		text_temp_eau_min.setWildcard(textArea_Buffer_temp_gauche_min);
		text_temp_eau_min.invalidate();
    }

	Unicode::snprintf(textArea_Buffer_temp_droite_max, 7, "%d", (i16ValmaxText));
	text_temp_ext_max.setWildcard(textArea_Buffer_temp_droite_max);
	text_temp_ext_max.invalidate();
	Unicode::snprintf(textArea_Buffer_temp_droite_min, 7, "%d", (i16ValminText));
	text_temp_ext_min.setWildcard(textArea_Buffer_temp_droite_min);
	text_temp_ext_min.invalidate();

    // --- Mise à jour du graphe ---
    //graph_eau_depart.clear(); // Important : évite les doublons
//    graph_eau_depart.setGraphRange(0, 359, u16Valmin - 1, u16Valmax + 1);
//    //graph_eau_retour.clear(); // Important : évite les doublons
//    graph_eau_retour.setGraphRange(0, 359, u16Valmin - 1, u16Valmax + 1);

    //MAJ Définition des limites Min/Max des graphs
	if (bGraphPage1)
	{
		if (bAffichageTempBallon)
		{
			graph_temp_z1_ballon.setGraphRange(0, 359, u16ValminAmbBall, u16ValmaxAmbBall);
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				graph_temp_z1_ballon.setGraphRange(0, 359, u16ValminAmbBall, u16ValmaxAmbBall);
			}
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				graph_temp_z2.setGraphRange(0, 359, u16ValminAmbBall, u16ValmaxAmbBall);
			}
		}
	}
	else
	{
		graph_eau_depart.setGraphRange(0, 359, u16ValminTeau, u16ValmaxTeau);
		graph_eau_retour.setGraphRange(0, 359, u16ValminTeau, u16ValmaxTeau);
	}
	graph_temp_ext.setGraphRange(0, 359, i16ValminText, i16ValmaxText);


    if (bTableauPlein)
    {
        // tableau circulaire complet
    	for (int i = 0; i < 360; i++)
        {
            uint16_t index = (u16PointeurTableau + i + 1) % 360;
            graph_eau_depart.addDataPoint(i, u16TempDepart[index]);
            graph_eau_retour.addDataPoint(i, u16TempRetour[index]);
            graph_temp_z1_ballon.addDataPoint(i, u16TempBallon_Z1[index]);
            graph_temp_z2.addDataPoint(i, u16Temp_Z2[index]);
            graph_temp_ext.addDataPoint(i, i16TempExt[index]);
        }
    }
    else
    {
		for (int i = 0; i < limit; i++)
		{
			int graphIndex = (360 - limit + i) % 360; // <-- décalage à droite

			graph_eau_depart.addDataPoint(graphIndex, u16TempDepart[i]);
			graph_eau_retour.addDataPoint(graphIndex, u16TempRetour[i]);
			graph_temp_z1_ballon.addDataPoint(graphIndex, u16TempBallon_Z1[i]);
			graph_temp_z2.addDataPoint(graphIndex, u16Temp_Z2[i]);
			graph_temp_ext.addDataPoint(graphIndex, i16TempExt[i]);

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

    //Test SER
//	for (int i = 0; i<360; i++)
//	{
//		box_etat[i].setPosition(i, 0, 1, 18);
//		if (i<50)
//		{
//			box_etat[i].setColor(RED);
//		}
//		else if (i >= 50 && i <80)
//		{
//			box_etat[i].setColor(GREEN);
//		}
//		else box_etat[i].setColor(BLUE);
//		container_etat.add(box_etat[i]);
//	}
//	container_etat.invalidate();


    u16PointeurTableau++;
    if (u16PointeurTableau >= 360)
    {
        u16PointeurTableau = 0;
        bTableauPlein = true;
    }
}

