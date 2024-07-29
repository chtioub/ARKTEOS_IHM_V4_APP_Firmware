#include <gui/zone_screen/ZoneView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ZoneView::ZoneView()
{

}

void ZoneView::setupScreen()
{
    Unicode::snprintf(textAreaBuffer_Titre, 25, "Zone 1");
    barre_titre.titre(textAreaBuffer_Titre);
	toggleButton_arret.forceState(false);
	toggleButton_chaud.forceState(true);
	// Arret
	container_slider_jaune.setVisible(false);
	container_slider_orange.setVisible(false);
	container_slider_rouge.setVisible(false);
	container_slider_bleu.setVisible(false);
	container_slider_bleu_ciel.setVisible(false);
	// Chaud / Froid normal
	container_slider_jaune.setVisible(false);
	container_slider_orange.setVisible(true);
	container_slider_rouge.setVisible(false);
	container_slider_bleu.setVisible(false);
	container_slider_bleu_ciel.setVisible(false);
	// Prog
	container_slider_jaune.setVisible(true);
	container_slider_orange.setVisible(true);
	container_slider_rouge.setVisible(true);
	container_slider_bleu.setVisible(false);
	container_slider_bleu_ciel.setVisible(false);
	// Affichage des points de consigne
	u16ConsigneReduit = 180;
	slider_jaune.setValue(u16ConsigneReduit);
	u16ConsigneNormal = 190;
	slider_orange.setValue(u16ConsigneNormal);
	slider_bleu_ciel.setValue(u16ConsigneNormal);
	u16ConsigneConfort = 200;
	slider_rouge.setValue(u16ConsigneConfort);
	slider_bleu.setValue(u16ConsigneConfort);

//	barre_titre.fonctionRetour(&application().gotoAccueilScreenNoTransition);

    ZoneViewBase::setupScreen();
}

void ZoneView::tearDownScreen()
{
    ZoneViewBase::tearDownScreen();
}

void ZoneView::bouton_arret()
{
	if(toggleButton_arret.getState())
	{
		toggleButton_arret.setTouchable(false);
		toggleButton_arret.invalidate();
		toggleButton_chaud.setTouchable(true);
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.invalidate();
		toggleButton_hors_gel.setTouchable(true);
		toggleButton_hors_gel.forceState(false);
		toggleButton_hors_gel.invalidate();
		toggleButton_froid.setTouchable(true);
		toggleButton_froid.forceState(false);
		toggleButton_froid.invalidate();
		container_auto_prog.setVisible(false);
		container_auto_prog.invalidate();
		container_derogation.setVisible(false);
		container_derogation.invalidate();
		container_slider_jaune.setVisible(false);
		container_slider_jaune.invalidate();
		container_slider_orange.setVisible(false);
		container_slider_orange.invalidate();
		container_slider_rouge.setVisible(false);
		container_slider_rouge.invalidate();
		container_slider_bleu.setVisible(false);
		container_slider_bleu.invalidate();
		container_slider_bleu_ciel.setVisible(false);
		container_slider_bleu_ciel.invalidate();
		textArea_consigne.setVisible(false);
		textArea_consigne.invalidate();
	}
}

void ZoneView::bouton_chaud()
{
	if(toggleButton_chaud.getState())
	{
		toggleButton_chaud.setTouchable(false);
		toggleButton_chaud.invalidate();
		toggleButton_arret.setTouchable(true);
		toggleButton_arret.forceState(false);
		toggleButton_arret.invalidate();
		toggleButton_hors_gel.setTouchable(true);
		toggleButton_hors_gel.forceState(false);
		toggleButton_hors_gel.invalidate();
		toggleButton_froid.setTouchable(true);
		toggleButton_froid.forceState(false);
		toggleButton_froid.invalidate();
		container_auto_prog.setVisible(true);
		container_auto_prog.invalidate();
		container_derogation.setVisible(true);
		container_derogation.invalidate();
		container_slider_jaune.setVisible(true);
		container_slider_jaune.invalidate();
		container_slider_orange.setVisible(true);
		container_slider_orange.invalidate();
		container_slider_rouge.setVisible(true);
		container_slider_rouge.invalidate();
		container_slider_bleu.setVisible(false);
		container_slider_bleu.invalidate();
		container_slider_bleu_ciel.setVisible(false);
		container_slider_bleu_ciel.invalidate();
		textArea_consigne.setVisible(true);
		textArea_consigne.invalidate();
	}
}

void ZoneView::bouton_froid()
{
	if(toggleButton_froid.getState())
	{
		toggleButton_froid.setTouchable(false);
		toggleButton_froid.invalidate();
		toggleButton_arret.setTouchable(true);
		toggleButton_arret.forceState(false);
		toggleButton_arret.invalidate();
		toggleButton_hors_gel.setTouchable(true);
		toggleButton_hors_gel.forceState(false);
		toggleButton_hors_gel.invalidate();
		toggleButton_chaud.setTouchable(true);
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.invalidate();
		container_auto_prog.setVisible(true);
		container_auto_prog.invalidate();
		container_derogation.setVisible(true);
		container_derogation.invalidate();
		container_slider_jaune.setVisible(false);
		container_slider_jaune.invalidate();
		container_slider_orange.setVisible(false);
		container_slider_orange.invalidate();
		container_slider_rouge.setVisible(false);
		container_slider_rouge.invalidate();
		container_slider_bleu.setVisible(true);
		container_slider_bleu.invalidate();
		container_slider_bleu_ciel.setVisible(true);
		container_slider_bleu_ciel.invalidate();
		textArea_consigne.setVisible(true);
		textArea_consigne.invalidate();
	}
}

void ZoneView::bouton_hors_gel()
{
	if(toggleButton_hors_gel.getState())
	{
		toggleButton_hors_gel.setTouchable(false);
		toggleButton_hors_gel.invalidate();
		toggleButton_arret.setTouchable(true);
		toggleButton_arret.forceState(false);
		toggleButton_arret.invalidate();
		toggleButton_froid.setTouchable(true);
		toggleButton_froid.forceState(false);
		toggleButton_froid.invalidate();
		toggleButton_chaud.setTouchable(true);
		toggleButton_chaud.forceState(false);
		toggleButton_chaud.invalidate();
		container_auto_prog.setVisible(false);
		container_auto_prog.invalidate();
		container_derogation.setVisible(false);
		container_derogation.invalidate();
		container_slider_jaune.setVisible(false);
		container_slider_jaune.invalidate();
		container_slider_orange.setVisible(false);
		container_slider_orange.invalidate();
		container_slider_rouge.setVisible(false);
		container_slider_rouge.invalidate();
		container_slider_bleu.setVisible(false);
		container_slider_bleu.invalidate();
		container_slider_bleu_ciel.setVisible(false);
		container_slider_bleu_ciel.invalidate();
		textArea_consigne.setVisible(false);
		textArea_consigne.invalidate();
	}
}

void ZoneView::slider_reduit(int sliderValue)
{
	u16ConsigneReduit = sliderValue;
	Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
	textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_jaune.moveTo((int)((float) slider_jaune.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_jaune.getWidth()/2  + ((float)sliderValue - (float)120) * (float)1.98),51);
	textArea_jaune.invalidate();
}

void ZoneView::bouton_plus_reduit()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneReduit == 300) return;
	u16ConsigneReduit++;
	slider_jaune.setValue(u16ConsigneReduit);
	slider_jaune.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
    textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
    textArea_jaune.moveTo((int)((float) slider_jaune.getX() + 19 /*+ slider_jaune.background.getX()*/ - textArea_jaune.getWidth()/2 + ((float)u16ConsigneReduit - (float)120) * (float)1.98),51);
    textArea_jaune.invalidate();
}

void ZoneView::bouton_moins_reduit()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneReduit == 120) return;
	u16ConsigneReduit--;
	slider_jaune.setValue(u16ConsigneReduit);
	slider_jaune.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
    textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
    textArea_jaune.moveTo((int)((float) slider_jaune.getX() + 19 /*+ slider_jaune.background.getX()*/ - textArea_jaune.getWidth()/2 + ((float)u16ConsigneReduit - (float)120) * (float)1.98),51);
    textArea_jaune.invalidate();
}

void ZoneView::slider_normal(int sliderValue)
{
	u16ConsigneNormal = sliderValue;
	Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
	textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_orange.moveTo((int)((float) slider_orange.getX() + 19 /*+ slider_orange.background.getX()*/ - textArea_orange.getWidth()/2  + ((float)sliderValue - (float)120) * (float)1.98),51);
	textArea_orange.invalidate();
	textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_bleu_ciel.moveTo((int)((float) slider_bleu_ciel.getX() + 19 /*+ slider_orange.background.getX()*/ - textArea_bleu_ciel.getWidth()/2  + ((float)sliderValue - (float)120) * (float)1.98),51);
	textArea_bleu_ciel.invalidate();
}

void ZoneView::bouton_plus_normal()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneNormal == 300) return;
	u16ConsigneNormal++;
	slider_orange.setValue(u16ConsigneNormal);
	slider_orange.invalidate();
	slider_bleu_ciel.setValue(u16ConsigneNormal);
	slider_bleu_ciel.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
    textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
    textArea_orange.moveTo((int)((float) slider_orange.getX() + 19 /*+ slider_orange.background.getX()*/ - textArea_orange.getWidth()/2 + ((float)u16ConsigneNormal - (float)120) * (float)1.98),51);
    textArea_orange.invalidate();
	textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_bleu_ciel.moveTo((int)((float) slider_bleu_ciel.getX() + 19 /*+ slider_orange.background.getX()*/ - textArea_bleu_ciel.getWidth()/2  + ((float)u16ConsigneNormal - (float)120) * (float)1.98),51);
	textArea_bleu_ciel.invalidate();
}

void ZoneView::bouton_moins_normal()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneNormal == 120) return;
	u16ConsigneNormal--;
	slider_orange.setValue(u16ConsigneNormal);
	slider_orange.invalidate();
	slider_bleu_ciel.setValue(u16ConsigneNormal);
	slider_bleu_ciel.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
    textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
    textArea_orange.moveTo((int)((float) slider_orange.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/ - textArea_orange.getWidth()/2 + ((float)u16ConsigneNormal - (float)120) * (float)1.98),51);
    textArea_orange.invalidate();
	textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_bleu_ciel.moveTo((int)((float) slider_bleu_ciel.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/ - textArea_bleu_ciel.getWidth()/2  + ((float)u16ConsigneNormal - (float)120) * (float)1.98),51);
	textArea_bleu_ciel.invalidate();
}

void ZoneView::slider_confort(int sliderValue)
{
	u16ConsigneConfort = sliderValue;
	Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
	textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_rouge.moveTo((int)((float) slider_rouge.getX() + 19 /*+ slider_bleu.background.getX()*/ - textArea_rouge.getWidth()/2  + ((float)sliderValue - (float)120) * (float)1.98),51);
	textArea_rouge.invalidate();
	textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_bleu.moveTo((int)((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/ - textArea_bleu.getWidth()/2  + ((float)sliderValue - (float)120) * (float)1.98),51);
	textArea_bleu.invalidate();
}

void ZoneView::bouton_plus_confort()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneConfort == 300) return;
	u16ConsigneConfort++;
	slider_rouge.setValue(u16ConsigneConfort);
	slider_rouge.invalidate();
	slider_bleu.setValue(u16ConsigneConfort);
	slider_bleu.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
    textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
    textArea_rouge.moveTo((int)((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/ - textArea_rouge.getWidth()/2 + ((float)u16ConsigneConfort - (float)120) * (float)1.98),51);
    textArea_rouge.invalidate();
	textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_bleu.moveTo((int)((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/ - textArea_bleu.getWidth()/2  + ((float)u16ConsigneConfort - (float)120) * (float)1.98),51);
	textArea_bleu.invalidate();
}

void ZoneView::bouton_moins_confort()
{
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneConfort == 120) return;
	u16ConsigneConfort--;
	slider_rouge.setValue(u16ConsigneConfort);
	slider_rouge.invalidate();
	slider_bleu.setValue(u16ConsigneConfort);
	slider_bleu.invalidate();
    Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
    textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
    textArea_rouge.moveTo((int)((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/ - textArea_rouge.getWidth()/2 + ((float)u16ConsigneConfort - (float)120) * (float)1.98),51);
    textArea_rouge.invalidate();
	textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_bleu.moveTo((int)((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/ - textArea_bleu.getWidth()/2  + ((float)u16ConsigneConfort - (float)120) * (float)1.98),51);
	textArea_bleu.invalidate();
}
