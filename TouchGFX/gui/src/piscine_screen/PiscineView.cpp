#include <gui/piscine_screen/PiscineView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>

PiscineView::PiscineView()
{
//	barre_titre.titre(T_TEXT_PISCINE_CENTRE_LARGE);
	toggleButton_arret_ecs.forceState(false);
	button_marche_ecs_on.setVisible(true);
	// Option piscine arret
	container_slider_vert_clair.setVisible(false);
	container_slider_vert.setVisible(false);
	container_slider_vert_fonce.setVisible(false);
	// Option piscine normal
	container_slider_vert_clair.setVisible(false);
	container_slider_vert.setVisible(true);
	container_slider_vert_fonce.setVisible(false);
	// Option confort
	container_slider_vert_clair.setVisible(true);
	container_slider_vert.setVisible(true);
	container_slider_vert_fonce.setVisible(true);
	// Affichage des points de consigne
	u16ConsigneReduit = 250;
	slider_vert_clair.setValue(u16ConsigneReduit);
	u16ConsigneNormal = 300;
	slider_vert.setValue(u16ConsigneNormal);
	u16ConsigneConfort = 350;
	slider_vert_fonce.setValue(u16ConsigneConfort);
}

void PiscineView::setupScreen()
{
    PiscineViewBase::setupScreen();
}

void PiscineView::tearDownScreen()
{
    PiscineViewBase::tearDownScreen();
}

void PiscineView::slider_reduit(int sliderValue)
{
	u16ConsigneReduit = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
    textArea_vert_clair.setWildcard(textAreaBuffer_ConsigneReduit);
    textArea_vert_clair.moveTo((int)((float) slider_vert_clair.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_clair.getWidth()/2  + ((float)sliderValue - (float)150) * (float)1.98),51);
    textArea_vert_clair.invalidate();
}

void PiscineView::slider_normal(int sliderValue)
{
	u16ConsigneNormal = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
    textArea_vert.setWildcard(textAreaBuffer_ConsigneNormal);
    textArea_vert.moveTo((int)((float) slider_vert.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert.getWidth()/2  + ((float)sliderValue - (float)150) * (float)1.98),51);
    textArea_vert.invalidate();
}

void PiscineView::slider_confort(int sliderValue)
{
	u16ConsigneConfort = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
    textArea_vert_fonce.setWildcard(textAreaBuffer_ConsigneConfort);
    textArea_vert_fonce.moveTo((int)((float) slider_vert_fonce.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_fonce.getWidth()/2  + ((float)sliderValue - (float)150) * (float)1.98),51);
    textArea_vert_fonce.invalidate();
}

void PiscineView::bouton_arret()
{
	if(toggleButton_arret_ecs.getState())
	{
		toggleButton_arret_ecs.setTouchable(false);
		toggleButton_arret_ecs.invalidate();
		button_marche_ecs_on.setVisible(false);
		button_marche_ecs_on.invalidate();
		container_slider_vert_clair.setVisible(false);
		container_slider_vert_clair.invalidate();
		container_slider_vert.setVisible(false);
		container_slider_vert.invalidate();
		container_slider_vert_fonce.setVisible(false);
		container_slider_vert_fonce.invalidate();
		textArea_consigne.setVisible(false);
		textArea_consigne.invalidate();
	}
}

void PiscineView::bouton_marche()
{
	toggleButton_arret_ecs.forceState(false);
	toggleButton_arret_ecs.invalidate();
	button_marche_ecs_on.setVisible(true);
	button_marche_ecs_on.invalidate();
	// Option piscine normal
	container_slider_vert_clair.setVisible(false);
	container_slider_vert_clair.invalidate();
	container_slider_vert.setVisible(true);
	container_slider_vert.invalidate();
	container_slider_vert_fonce.setVisible(false);
	container_slider_vert_fonce.invalidate();
	// Option confort
	container_slider_vert_clair.setVisible(true);
	container_slider_vert_clair.invalidate();
	container_slider_vert.setVisible(true);
	container_slider_vert.invalidate();
	container_slider_vert_fonce.setVisible(true);
	container_slider_vert_fonce.invalidate();
	application().gotoProgrammationScreenNoTransition();
}

void PiscineView::bouton_plus_reduit()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneReduit == 400) return;
	u16ConsigneReduit++;
	//
	touchgfx_printf("Bouton plus; val = %d\n", u16ConsigneReduit);
	slider_vert_clair.setValue(u16ConsigneReduit);
	slider_vert_clair.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
    textArea_vert_clair.setWildcard(textAreaBuffer_ConsigneReduit);
    textArea_vert_clair.moveTo((int)((float) slider_vert_clair.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_clair.getWidth()/2 + ((float)u16ConsigneReduit - (float)150) * (float)1.98),51);
    textArea_vert_clair.invalidate();
}

void PiscineView::bouton_moins_reduit()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneReduit == 150) return;
	u16ConsigneReduit--;
	slider_vert_clair.setValue(u16ConsigneReduit);
	slider_vert_clair.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
    textArea_vert_clair.setWildcard(textAreaBuffer_ConsigneReduit);
    textArea_vert_clair.moveTo((int)((float) slider_vert_clair.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_clair.getWidth()/2 + ((float)u16ConsigneReduit - (float)150) * (float)1.98),51);
    textArea_vert_clair.invalidate();
}

void PiscineView::bouton_plus_normal()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneNormal == 400) return;
	u16ConsigneNormal++;
	//
	touchgfx_printf("Bouton plus; val = %d\n", u16ConsigneNormal);
	slider_vert.setValue(u16ConsigneNormal);
	slider_vert.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
    textArea_vert.setWildcard(textAreaBuffer_ConsigneNormal);
    textArea_vert.moveTo((int)((float) slider_vert.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert.getWidth()/2 + ((float)u16ConsigneNormal - (float)150) * (float)1.98),51);
    textArea_vert.invalidate();
}

void PiscineView::bouton_moins_normal()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneNormal == 150) return;
	u16ConsigneNormal--;
	slider_vert.setValue(u16ConsigneNormal);
	slider_vert.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
    textArea_vert.setWildcard(textAreaBuffer_ConsigneNormal);
    textArea_vert.moveTo((int)((float) slider_vert.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert.getWidth()/2 + ((float)u16ConsigneNormal - (float)150) * (float)1.98),51);
    textArea_vert.invalidate();
}

void PiscineView::bouton_plus_confort()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneConfort == 400) return;
	u16ConsigneConfort++;
	//
	touchgfx_printf("Bouton plus; val = %d\n", u16ConsigneConfort);
	slider_vert_fonce.setValue(u16ConsigneConfort);
	slider_vert_fonce.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
    textArea_vert_fonce.setWildcard(textAreaBuffer_ConsigneConfort);
    textArea_vert_fonce.moveTo((int)((float) slider_vert_fonce.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_fonce.getWidth()/2 + ((float)u16ConsigneConfort - (float)150) * (float)1.98),51);
    textArea_vert_fonce.invalidate();
}

void PiscineView::bouton_moins_confort()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneConfort == 150) return;
	u16ConsigneConfort--;
	slider_vert_fonce.setValue(u16ConsigneConfort);
	slider_vert_fonce.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
    textArea_vert_fonce.setWildcard(textAreaBuffer_ConsigneConfort);
    textArea_vert_fonce.moveTo((int)((float) slider_vert_fonce.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_fonce.getWidth()/2 + ((float)u16ConsigneConfort - (float)150) * (float)1.98),51);
    textArea_vert_fonce.invalidate();
}
