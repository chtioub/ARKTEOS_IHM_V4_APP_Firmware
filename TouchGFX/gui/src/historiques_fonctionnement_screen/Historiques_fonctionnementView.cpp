#include <gui/historiques_fonctionnement_screen/Historiques_fonctionnementView.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Historiques_fonctionnementView::Historiques_fonctionnementView()
{

}

void Historiques_fonctionnementView::setupScreen()
{
    // Init des variables
    u8AffichageGraphiques = 0;
	// Init des graphiques
	for(int i = 0; i < 360; i++)
	{
		// Etat PAC
		box_etat_pac[i].setPosition(115 + i * 2, 432, 2, 16);
		box_etat_pac[i].setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		box_etat_pac[i].setVisible(false);
		container.add(box_etat_pac[i]);
		// Appoint chaud
		box_appoint_chaud[i].setPosition(115 + i * 2, 412, 2, 16);
		box_appoint_chaud[i].setColor(0xf53d3d);
		box_appoint_chaud[i].setVisible(false);
		container.add(box_appoint_chaud[i]);
		// Appoint ECS
		box_appoint_ecs[i].setPosition(115 + i * 2, 392, 2, 16);
		box_appoint_ecs[i].setColor(0xE4348B);
		box_appoint_ecs[i].setVisible(false);
		container.add(box_appoint_ecs[i]);
		// Init des graphiques
		dynamicGraph_eau_1.addDataPoint(i);
		dynamicGraph_eau_2.addDataPoint(i);
		dynamicGraph_ext.addDataPoint(i);
		graph_test.addDataPoint(i, i);
	}
	// MAJ des données affichées
	changement_page();
	maj_graphiques();

    Historiques_fonctionnementViewBase::setupScreen();
}

void Historiques_fonctionnementView::tearDownScreen()
{
    Historiques_fonctionnementViewBase::tearDownScreen();
}

void Historiques_fonctionnementView::bouton_droit()
{
	if(++u8AffichageGraphiques > 1)
	{
	    touchgfx_printf("changment page = 2 / %d\n", u8AffichageGraphiques);
		u8AffichageGraphiques = 0;
	}
	changement_page();
}

void Historiques_fonctionnementView::bouton_gauche()
{
	if(u8AffichageGraphiques == 0)
	{
	    touchgfx_printf("changment page = 1 / %d\n", u8AffichageGraphiques);
		u8AffichageGraphiques = 1;
	}
	else u8AffichageGraphiques = 0;
	changement_page();
}

void Historiques_fonctionnementView::changement_page()
{
    touchgfx_printf("changment page = %d\n", u8AffichageGraphiques);
	// Modification du titre
    if(u8AffichageGraphiques == 0)
    {
		Unicode::snprintf(textAreaBuffer_Titre, 30, touchgfx::TypedText(T_TEXT_HISTO_EAU_CENTRE_LARGE).getText());
		barre_titre.titre(textAreaBuffer_Titre);
    	dynamicGraph_eau_1Line1Painter.setColor(0xF53D3D);
    	circle_sonde_depart_1.setVisible(true);
    	circle_sonde_depart_2.setVisible(true);
    	circle_sonde_depart_1Painter.setColor(0xF53D3D);
    	circle_sonde_depart_2Painter.setColor(0xF53D3D);
    	dynamicGraph_eau_2.setVisible(true);
    	dynamicGraph_eau_2Line1Painter.setColor(0x006F95);
    	circle_sonde_retour_1.setVisible(true);
    	circle_sonde_retour_2.setVisible(true);
    	circle_sonde_retour_1Painter.setColor(0x006F95);
    	circle_sonde_retour_2Painter.setColor(0x006F95);
    	textArea_b.setVisible(false);
    	textArea_d.setVisible(true);
    	textArea_r.setVisible(true);
    }
    else
    {
    	Unicode::snprintf(textAreaBuffer_Titre, 30, touchgfx::TypedText(T_TEXT_HISTO_CENTRE_LARGE).getText());
    	barre_titre.titre(textAreaBuffer_Titre);
    	dynamicGraph_eau_1Line1Painter.setColor(0xE27E00);
    	circle_sonde_depart_1Painter.setColor(0xE27E00);
    	circle_sonde_depart_2Painter.setColor(0xE27E00);
    	// Si ballon
    	dynamicGraph_eau_2.setVisible(false);
    	circle_sonde_retour_1.setVisible(false);
    	circle_sonde_retour_2.setVisible(false);
    	textArea_b.setVisible(true);
    	textArea_d.setVisible(false);
    	textArea_r.setVisible(false);
    	container_z1.setVisible(false);
    	container_z2.setVisible(false);
    	// Si zone
//    	container_z1.setVisible(true);
//    	circle_sonde_depart_1.setVisible(false);
//    	circle_sonde_depart_2.setVisible(false);
    	// Si Zone 2
//    	container_z2.setVisible(true);
//    	dynamicGraph_eau_2.setVisible(true);
//    	dynamicGraph_eau_2Line1Painter.setColor(0xFFD300);
//    	circle_sonde_retour_1.setVisible(false);
//    	circle_sonde_retour_2.setVisible(false);
//    	textArea_b.setVisible(false);
//    	textArea_d.setVisible(false);
//    	textArea_r.setVisible(false);
    }
	dynamicGraph_eau_1.invalidate();
	dynamicGraph_eau_2.invalidate();
	circle_sonde_depart_1.invalidate();
	circle_sonde_depart_2.invalidate();
	circle_sonde_retour_1.invalidate();
	circle_sonde_retour_2.invalidate();
	textArea_b.invalidate();
	textArea_d.invalidate();
	textArea_r.invalidate();
	container_z1.invalidate();
	container_z2.invalidate();
    barre_titre.invalidate();
    // MAJ des graphiques
    maj_graphiques();
}

void Historiques_fonctionnementView::maj_data()
{
//	graph_test.setVisible(false);
//	graph_test.invalidate();
//	graph_test.clear();
//	for(int i = 0; i < 360; i++)
//	{
//		graph_test.addDataPoint(i, i);
//	}
//	graph_test.setVisible(true);
//	graph_test.invalidate();
	dynamicGraph_eau_1.addDataPoint(20);
//	dynamicGraph_eau_2.addDataPoint(-50);
//	dynamicGraph_ext.addDataPoint(50);
}

void Historiques_fonctionnementView::maj_graphiques()
{
	int16_t i16TempHaut_eau = 120, i16TempBas_eau = 0, i16TempBas_ext = -120, i16TempHaut_ext = 120;
	// Recherche min et max
	if(u8AffichageGraphiques == 0)
	{
		i16TempHaut_eau = 300;
		i16TempBas_eau = -100;
	}
	else
	{
		i16TempHaut_eau = 200;
		i16TempBas_eau = 0;
	}
	// Mise à jour des températures
	Unicode::snprintfFloat(textAreaBuffer_temp_ext_haut, 6, "%.1f", (float) (i16TempHaut_ext / 10));
	textArea_ext_haut.setWildcard(textAreaBuffer_temp_ext_haut);
	textArea_ext_haut.invalidate();
	Unicode::snprintfFloat(textAreaBuffer_temp_ext_bas, 6, "%.1f", (float) (i16TempBas_ext / 10));
	textArea_ext_bas.setWildcard(textAreaBuffer_temp_ext_bas);
	textArea_ext_bas.invalidate();
	Unicode::snprintfFloat(textAreaBuffer_temp_eau_haut, 6, "%.1f", (float) (i16TempHaut_eau / 10));
	textArea_eau_haut.setWildcard(textAreaBuffer_temp_eau_haut);
	textArea_eau_haut.invalidate();
	Unicode::snprintfFloat(textAreaBuffer_temp_eau_bas, 6, "%.1f", (float) (i16TempBas_eau / 10));
	textArea_eau_bas.setWildcard(textAreaBuffer_temp_eau_bas);
	textArea_eau_bas.invalidate();
	// Mise à jour de la partie haute
	dynamicGraph_eau_1.setGraphRangeY(i16TempBas_eau, i16TempHaut_eau);
	dynamicGraph_eau_1.invalidate();
	dynamicGraph_eau_2.setGraphRangeY(i16TempBas_eau, i16TempHaut_eau);
	dynamicGraph_eau_2.invalidate();
	dynamicGraph_ext.setGraphRangeY(i16TempBas_ext, i16TempHaut_ext);
	dynamicGraph_ext.invalidate();
	// Mise à jours de la partie basse
	for(int i = 0; i < 360; i++)
	{
		// Etat PAC
		if(i % 2)
		{
			box_etat_pac[i].setVisible(true);

			box_etat_pac[i].setColor(0xffffff);
			box_etat_pac[i].setColor(0xE27E00);
			box_etat_pac[i].setColor(0x3ABAD9);
			box_etat_pac[i].setColor(0xE4348B);
			box_etat_pac[i].setColor(0xB9C400);
		}
		else box_etat_pac[i].setVisible(false);
	    // Appoint chaud
		if(i % 2)
		{
			box_appoint_chaud[i].setVisible(true);
		}
		else box_appoint_chaud[i].setVisible(false);
	    // Appoint ECS
		if(i % 2)
		{
			box_appoint_ecs[i].setVisible(true);
		}
		else box_appoint_ecs[i].setVisible(false);
	}
}
