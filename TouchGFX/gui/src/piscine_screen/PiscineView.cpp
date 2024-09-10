#include <gui/piscine_screen/PiscineView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>

PiscineView::PiscineView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PISCINE_CENTRE_LARGE).getText());
    barre_titre.titre(textAreaBuffer_Titre);
	// Récupération des progs
#ifndef SIMULATOR
	presenter->c_prog_piscine(false);
#endif
}

void PiscineView::setupScreen()
{
    PiscineViewBase::setupScreen();
}

void PiscineView::tearDownScreen()
{
	// En cas de changement de page on vérifie si les consignes ont été changées
	if(sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal != u16ConsigneNormal || sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort != u16ConsigneConfort || sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit != u16ConsigneReduit)
	{
		sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal = u16ConsigneNormal;
		sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort = u16ConsigneConfort;
		sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit = u16ConsigneReduit;
		presenter->c_user_piscine();
	}

    PiscineViewBase::tearDownScreen();
}

void PiscineView::timer_100ms()
{
	if(u16TempoEnvoiConsigne)
	{
		u16TempoEnvoiConsigne--;
		if(u16TempoEnvoiConsigne == 0)
		{
			if(sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal != u16ConsigneNormal || sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort != u16ConsigneConfort || sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit != u16ConsigneReduit)
			{
				sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal = u16ConsigneNormal;
				sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort = u16ConsigneConfort;
				sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit = u16ConsigneReduit;
				presenter->c_user_piscine();
			}
		}
	}
}

void PiscineView::slider_reduit(int sliderValue)
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	u16ConsigneReduit = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
    textArea_vert_clair.setWildcard(textAreaBuffer_ConsigneReduit);
    textArea_vert_clair.moveTo((int)((float) slider_vert_clair.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_clair.getWidth()/2  + ((float)sliderValue - (float)150) * (float)1.98),51);
    textArea_vert_clair.invalidate();
}

void PiscineView::slider_normal(int sliderValue)
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	u16ConsigneNormal = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
    textArea_vert.setWildcard(textAreaBuffer_ConsigneNormal);
    textArea_vert.moveTo((int)((float) slider_vert.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert.getWidth()/2  + ((float)sliderValue - (float)150) * (float)1.98),51);
    textArea_vert.invalidate();
}

void PiscineView::slider_confort(int sliderValue)
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	u16ConsigneConfort = sliderValue;
    Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
    textArea_vert_fonce.setWildcard(textAreaBuffer_ConsigneConfort);
    textArea_vert_fonce.moveTo((int)((float) slider_vert_fonce.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_fonce.getWidth()/2  + ((float)sliderValue - (float)150) * (float)1.98),51);
    textArea_vert_fonce.invalidate();
}

void PiscineView::bouton_arret()
{
	if(toggleButton_arret_piscine.getState())
	{
		toggleButton_arret_piscine.setTouchable(false);
		toggleButton_arret_piscine.invalidate();
		button_marche_piscine_on.setVisible(false);
		button_marche_piscine_on.invalidate();
		container_slider_vert_clair.setVisible(false);
		container_slider_vert_clair.invalidate();
		container_slider_vert.setVisible(false);
		container_slider_vert.invalidate();
		container_slider_vert_fonce.setVisible(false);
		container_slider_vert_fonce.invalidate();
		textArea_consigne.setVisible(false);
		textArea_consigne.invalidate();
	}
	// Passage à l'arret
	if(sConfig_IHM.sMode_Piscine.Mode != ARRET)
	{
		sConfig_IHM.sMode_Piscine.Mode = ARRET;
		presenter->c_user_piscine();
	}
}

void PiscineView::bouton_marche()
{
	if(sConfig_IHM.sMode_Piscine.Mode != AUTO_CHAUD)
	{
		sConfig_IHM.sMode_Piscine.Mode = AUTO_CHAUD;
		presenter->c_user_piscine();
	}
	// Copie des programmations
	memcpy(u8Prog, au8Prog_Piscine, sizeof(u8Prog));
	if(sConfig_IHM_old.sParam_Piscine.bConfort)
	{
		eProg = PRO_PISCINE_CONFORT;
	}
	else eProg = PRO_PISCINE;
	application().gotoProgrammationScreenNoTransition();
}

void PiscineView::bouton_plus_reduit()
{
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
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
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
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
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
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
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
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
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
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
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
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

void PiscineView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	if(sConfig_IHM_old.sMode_Piscine.Mode != sConfig_IHM->sMode_Piscine.Mode)
	{
		if(sConfig_IHM->sMode_Piscine.Mode == AUTO_CHAUD)
		{
			button_marche_piscine_on.setVisible(true);
			toggleButton_arret_piscine.forceState(false);
			toggleButton_arret_piscine.setTouchable(true);
			textArea_consigne.setVisible(true);
		}
		else
		{
			button_marche_piscine_on.setVisible(false);
			toggleButton_arret_piscine.forceState(true);
			toggleButton_arret_piscine.setTouchable(false);
			textArea_consigne.setVisible(false);
		}
		textArea_consigne.invalidate();
		button_marche_piscine_on.invalidate();
		toggleButton_arret_piscine.invalidate();
	}

	if(sConfig_IHM_old.sMode_Piscine.Mode != sConfig_IHM->sMode_Piscine.Mode || sConfig_IHM_old.sParam_Piscine.bConfort != sConfig_IHM->sParam_Piscine.bConfort || sConfig_IHM_old.sMode_Piscine.Mode != sConfig_IHM->sMode_Piscine.Mode)
	{
		if(sConfig_IHM->sParam_Piscine.bConfort != 0 && sConfig_IHM->sMode_Piscine.Mode == AUTO_CHAUD)
		{
			container_slider_vert.setVisible(true);
			container_slider_vert_fonce.setVisible(true);
			container_slider_vert_clair.setVisible(true);
		}
		else if(sConfig_IHM->sParam_Piscine.bConfort == 0 && sConfig_IHM->sMode_Piscine.Mode == AUTO_CHAUD)
		{
			container_slider_vert.setVisible(true);
			container_slider_vert_fonce.setVisible(false);
			container_slider_vert_clair.setVisible(false);
		}
		else
		{
			container_slider_vert.setVisible(false);
			container_slider_vert_fonce.setVisible(false);
			container_slider_vert_clair.setVisible(false);
		}
		container_slider_vert.invalidate();
		container_slider_vert_fonce.invalidate();
		container_slider_vert_clair.invalidate();
	}

	if(sConfig_IHM_old.sMode_Piscine.i16Consigne_Piscine_Confort != sConfig_IHM->sMode_Piscine.i16Consigne_Piscine_Confort)
	{
		u16ConsigneConfort = sConfig_IHM->sMode_Piscine.i16Consigne_Piscine_Confort;
		//
		slider_vert_fonce.setValue(u16ConsigneConfort);
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 5, "%.1f", ((float) u16ConsigneConfort) / 10);
		textArea_vert_fonce.setWildcard(textAreaBuffer_ConsigneConfort);
		textArea_vert_fonce.moveTo((int)((float) slider_vert_fonce.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_fonce.getWidth()/2 + ((float)u16ConsigneConfort - (float)150) * (float)1.98),51);
		textArea_vert_fonce.invalidate();
	}

	if(sConfig_IHM_old.sMode_Piscine.i16Consigne_Piscine_Normal != sConfig_IHM->sMode_Piscine.i16Consigne_Piscine_Normal)
	{
		u16ConsigneNormal = sConfig_IHM->sMode_Piscine.i16Consigne_Piscine_Normal;
		//
		slider_vert.setValue(u16ConsigneNormal);
	    Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 5, "%.1f", ((float) u16ConsigneNormal) / 10);
	    textArea_vert.setWildcard(textAreaBuffer_ConsigneNormal);
	    textArea_vert.moveTo((int)((float) slider_vert.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert.getWidth()/2 + ((float)u16ConsigneNormal - (float)150) * (float)1.98),51);
	    textArea_vert.invalidate();
	}

	if(sConfig_IHM_old.sMode_Piscine.i16Consigne_Piscine_Reduit != sConfig_IHM->sMode_Piscine.i16Consigne_Piscine_Reduit)
	{
		u16ConsigneReduit = sConfig_IHM->sMode_Piscine.i16Consigne_Piscine_Reduit;
		//
		slider_vert_clair.setValue(u16ConsigneReduit);
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 5, "%.1f", ((float) u16ConsigneReduit) / 10);
		textArea_vert_clair.setWildcard(textAreaBuffer_ConsigneReduit);
		textArea_vert_clair.moveTo((int)((float) slider_vert_clair.getX() + 19 /*+ slider_gris.background.getX()*/ - textArea_vert_clair.getWidth()/2 + ((float)u16ConsigneReduit - (float)150) * (float)1.98),51);
		textArea_vert_clair.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void PiscineView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void PiscineView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void PiscineView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void PiscineView::changeDate(S_DATE *sDate)
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
