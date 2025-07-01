#include <gui/zone_screen/ZoneView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ZoneView::ZoneView()
{
	// Affichage des barres de la bonne longueur
	if(u8ZoneSelect == 0xff || (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		if ((sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_FROID && u8ZoneSelect != 0xff) || (sConfig_IHM.sMode_RegulExt.Mode== AUTO_FROID  && u8ZoneSelect == 0xff))
		{
			u16ValMin = 190;
			u16ValMax = 210;
		}
		else
		{
			u16ValMin = 180;
			u16ValMax = 220;
		}
		textArea_consigne.setTypedText(touchgfx::TypedText(T_TEXT_OFFSET_LOI_EAU_CENTRE_DEFAUT));
	}
	else
	{
		u16ValMin = 120;
		u16ValMax = 300;
		textArea_consigne.setTypedText(touchgfx::TypedText(T_TEXT_TEMP_CONS_CENTRE_DEFAUT));
	}
    slider_jaune.setValue(190);
	slider_jaune.setValueRange(u16ValMin, u16ValMax);
	slider_bleu_reduit.setValue(190);//180);
	slider_bleu_reduit.setValueRange(u16ValMin, u16ValMax);
	slider_orange.setValue(190);
	slider_orange.setValueRange(u16ValMin, u16ValMax);
	slider_bleu_ciel.setValue(190);//180);
	slider_bleu_ciel.setValueRange(u16ValMin, u16ValMax);
	slider_rouge.setValue(190);
	slider_rouge.setValueRange(u16ValMin, u16ValMax);
	slider_bleu.setValue(190);//190);//180);
	slider_bleu.setValueRange(u16ValMin, u16ValMax);
	// Init des variables
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
	// Récupération des progs
#ifndef SIMULATOR
	if(u8ZoneSelect == 0xff)
	{
		// Multiple trame
		presenter->c_prog_reg_ext_chaud(false);
		presenter->c_prog_reg_ext_froid(false);
	}
	else
	{
		// Multiple trame
		presenter->c_prog_zone_chaud(u8ZoneSelect, false);
		presenter->c_prog_zone_froid(u8ZoneSelect, false);
	}
#endif
}

void ZoneView::setupScreen()
{
  ZoneViewBase::setupScreen();
}

void ZoneView::tearDownScreen()
{
	if(u8ZoneSelect == 0xff)
	{
		if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Confort != u16ConsigneConfort || sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Normal != u16ConsigneNormal || sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Reduit != u16ConsigneReduit)
		{
			sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Confort = u16ConsigneConfort;
			sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Normal = u16ConsigneNormal;
			sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Reduit = u16ConsigneReduit;
			presenter->c_user_reg_ext();
		}
	}
	else
	{
		if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort != u16ConsigneConfort || sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal != u16ConsigneNormal || sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit != u16ConsigneReduit)
		{
			sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort = u16ConsigneConfort;
			sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal = u16ConsigneNormal;
			sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit = u16ConsigneReduit;
			presenter->c_user_zx(u8ZoneSelect);
		}
	}

	ZoneViewBase::tearDownScreen();
}

void ZoneView::bouton_arret()
{
	if(toggleButton_arret.getState())
	{
		if(u8ZoneSelect == 0xff)
		{
			sConfig_IHM.sMode_RegulExt.Mode = ARRET;
			changeConfig(&sConfig_IHM);
			presenter->c_user_reg_ext();
		}
		else
		{
			sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode = ARRET;
			changeConfig(&sConfig_IHM);
			presenter->c_user_zx(u8ZoneSelect);
		}
	}
}

void ZoneView::bouton_chaud()
{
	if(u8ZoneSelect == 0xff)
	{
		if(sConfig_IHM.sMode_RegulExt.Mode != MARCHE_CHAUD)
		{
			sConfig_IHM.sMode_RegulExt.Mode = MARCHE_CHAUD;
			changeConfig(&sConfig_IHM);
			presenter->c_user_reg_ext();
		}
	}
	else
	{
		if(sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode != MARCHE_CHAUD)
		{
			sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode = MARCHE_CHAUD;
			changeConfig(&sConfig_IHM);
			presenter->c_user_zx(u8ZoneSelect);
		}
	}
}

void ZoneView::bouton_froid()
{
	if(u8ZoneSelect == 0xff)
	{
		if(sConfig_IHM.sMode_RegulExt.Mode != MARCHE_FROID)
		{
			sConfig_IHM.sMode_RegulExt.Mode = MARCHE_FROID;
			changeConfig(&sConfig_IHM);
			presenter->c_user_reg_ext();
		}
	}
	else
	{
		if(sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode != MARCHE_FROID)
		{
			sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode = MARCHE_FROID;
			changeConfig(&sConfig_IHM);
			presenter->c_user_zx(u8ZoneSelect);
		}
	}
}

void ZoneView::bouton_hors_gel()
{
	if(toggleButton_hors_gel.getState())
	{
		sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode = HORS_GEL;
		changeConfig(&sConfig_IHM);
		presenter->c_user_zx(u8ZoneSelect);
	}
}

void ZoneView::bouton_prog()
{
	if(u8ZoneSelect == 0xff)
	{
		if(sConfig_IHM_old.sMode_RegulExt.Mode == MARCHE_FROID || sConfig_IHM_old.sMode_RegulExt.Mode == AUTO_FROID)
		{
			if(sConfig_IHM_old.sMode_RegulExt.Mode == MARCHE_FROID)
			{
				sConfig_IHM.sMode_RegulExt.Mode = AUTO_FROID;
				changeConfig(&sConfig_IHM);
				presenter->c_user_reg_ext();
			}
			// Vers page programmation
			memcpy(u8Prog, au8Prog_Regul_Ext_Froid, sizeof(u8Prog));
			eProg = PRO_EXT_FROID;
			application().gotoProgrammationScreenNoTransition();
		}
		else
		{
			if(sConfig_IHM_old.sMode_RegulExt.Mode == MARCHE_CHAUD)
			{
				sConfig_IHM.sMode_RegulExt.Mode = AUTO_CHAUD;
				changeConfig(&sConfig_IHM);
				presenter->c_user_reg_ext();
			}
			// Vers page programmation
			memcpy(u8Prog, au8Prog_Regul_Ext_Chaud, sizeof(u8Prog));
			eProg = PRO_EXT_CHAUD;
			application().gotoProgrammationScreenNoTransition();
		}
	}
	else
	{
		if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].Mode == MARCHE_FROID || sConfig_IHM_old.sMode_Zx[u8ZoneSelect].Mode == AUTO_FROID)
		{
			if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].Mode == MARCHE_FROID)
			{
				sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode = AUTO_FROID;
				changeConfig(&sConfig_IHM);
				presenter->c_user_zx(u8ZoneSelect);
			}
			// Vers page programmation
			memcpy(u8Prog, au8Prog_Froid_Zx[u8ZoneSelect], sizeof(u8Prog));
			eProg = PRO_FROID;
			application().gotoProgrammationScreenNoTransition();
		}
		else
		{
			if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].Mode == MARCHE_CHAUD)
			{
				sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode = AUTO_CHAUD;
				changeConfig(&sConfig_IHM);
				presenter->c_user_zx(u8ZoneSelect);
			}
			// Vers page programmation
			memcpy(u8Prog, au8Prog_Chaud_Zx[u8ZoneSelect], sizeof(u8Prog));
			eProg = PRO_CHAUD;
			application().gotoProgrammationScreenNoTransition();
		}
	}
}

void ZoneView::bouton_appoint()
{
	sConfig_IHM.sMode_PAC.bAppointUser = toggleButton_appoint.getState();
	presenter->c_user_param();
}

void ZoneView::bouton_retour()
{
	if(u8NbZone > 2 && sConfig_IHM_old.sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE)
	{
		application().gotoMultizonesScreenNoTransition();
	}
	else
	{
		application().gotoAccueilScreenNoTransition();
	}
}


void ZoneView::slider_reduit(int sliderValue)
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	u16ConsigneReduit = sliderValue;
	if(u8ZoneSelect == 0xff || (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", (float) u16ConsigneReduit - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_jaune.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu_reduit.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", ((float) u16ConsigneReduit) / 10);
		positionEcran = ((float) slider_jaune.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 120) * (float) 1.98);
	}
	textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_jaune.moveTo(positionEcran, 51);
	textArea_jaune.invalidate();
	textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_bleu_reduit.moveTo(positionEcran, 51);
	textArea_bleu_reduit.invalidate();
}

void ZoneView::bouton_plus_reduit()
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneReduit == u16ValMax) return;

	u16ConsigneReduit++;
	slider_jaune.setValue(u16ConsigneReduit);
	slider_jaune.invalidate();
	slider_bleu_reduit.setValue(u16ConsigneReduit);
	slider_bleu_reduit.invalidate();
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", (float) u16ConsigneReduit - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_jaune.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu_reduit.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", ((float) u16ConsigneReduit) / 10);
		positionEcran = ((float) slider_jaune.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 120) * (float) 1.98);
	}
	textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_jaune.moveTo(positionEcran, 51);
	textArea_jaune.invalidate();
	textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_bleu_reduit.moveTo(positionEcran, 51);
	textArea_bleu_reduit.invalidate();
}

void ZoneView::bouton_moins_reduit()
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneReduit == u16ValMin) return;

	u16ConsigneReduit--;
	slider_jaune.setValue(u16ConsigneReduit);
	slider_jaune.invalidate();
	slider_bleu_reduit.setValue(u16ConsigneReduit);
	slider_bleu_reduit.invalidate();
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", (float) u16ConsigneReduit - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_jaune.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu_reduit.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", ((float) u16ConsigneReduit) / 10);
		positionEcran = ((float) slider_jaune.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 120) * (float) 1.98);
	}
	textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_jaune.moveTo(positionEcran, 51);
	textArea_jaune.invalidate();
	textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
	textArea_bleu_reduit.moveTo(positionEcran, 51);
	textArea_bleu_reduit.invalidate();
}

void ZoneView::slider_normal(int sliderValue)
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	u16ConsigneNormal = sliderValue;
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", (float) u16ConsigneNormal - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_orange.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu_ciel.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", ((float) u16ConsigneNormal) / 10);
		positionEcran = ((float) slider_orange.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 120) * (float) 1.98);
	}
	textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_orange.moveTo(positionEcran, 51);
	textArea_orange.invalidate();
	textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_bleu_ciel.moveTo(positionEcran, 51);
	textArea_bleu_ciel.invalidate();
}

void ZoneView::bouton_plus_normal()
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneNormal == u16ValMax) return;

	u16ConsigneNormal++;
	slider_orange.setValue(u16ConsigneNormal);
	slider_orange.invalidate();
	slider_bleu_ciel.setValue(u16ConsigneNormal);
	slider_bleu_ciel.invalidate();
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", (float) u16ConsigneNormal - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_orange.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu_ciel.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", ((float) u16ConsigneNormal) / 10);
		positionEcran = ((float) slider_orange.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 120) * (float) 1.98);
	}
	textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_orange.moveTo(positionEcran, 51);
	textArea_orange.invalidate();
	textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_bleu_ciel.moveTo(positionEcran, 51);
	textArea_bleu_ciel.invalidate();
}

void ZoneView::bouton_moins_normal()
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneNormal == u16ValMin) return;

	u16ConsigneNormal--;
	slider_orange.setValue(u16ConsigneNormal);
	slider_orange.invalidate();
	slider_bleu_ciel.setValue(u16ConsigneNormal);
	slider_bleu_ciel.invalidate();
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", (float) u16ConsigneNormal - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_orange.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu_ciel.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", ((float) u16ConsigneNormal) / 10);
		positionEcran = ((float) slider_orange.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 120) * (float) 1.98);
	}
	textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_orange.moveTo(positionEcran, 51);
	textArea_orange.invalidate();
	textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
	textArea_bleu_ciel.moveTo(positionEcran, 51);
	textArea_bleu_ciel.invalidate();
}

void ZoneView::slider_confort(int sliderValue)
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	u16ConsigneConfort = sliderValue;
	if(u8ZoneSelect == 0xff || (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", (float) u16ConsigneConfort - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", ((float) u16ConsigneConfort) / 10);
		positionEcran = ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 120) * (float) 1.98);
	}
	textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_rouge.moveTo(positionEcran, 51);
	textArea_rouge.invalidate();
	textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_bleu.moveTo(positionEcran, 51);
	textArea_bleu.invalidate();
}

void ZoneView::bouton_plus_confort()
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneConfort == u16ValMax) return;

	u16ConsigneConfort++;
	slider_rouge.setValue(u16ConsigneConfort);
	slider_rouge.invalidate();
	slider_bleu.setValue(u16ConsigneConfort);
	slider_bleu.invalidate();
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", (float) u16ConsigneConfort - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", ((float) u16ConsigneConfort) / 10);
		positionEcran = ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 120) * (float) 1.98);
	}
	textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_rouge.moveTo(positionEcran, 51);
	textArea_rouge.invalidate();
	textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_bleu.moveTo(positionEcran, 51);
	textArea_bleu.invalidate();
}

void ZoneView::bouton_moins_confort()
{
	int positionEcran;
	// Tempo avant envoi des consignes
	u16TempoEnvoiConsigne = 10;
	//
	// Pour éviter les petits sauts à l'appui sur les boutons
	if(u16ConsigneConfort == u16ValMin) return;

	u16ConsigneConfort--;
	slider_rouge.setValue(u16ConsigneConfort);
	slider_rouge.invalidate();
	slider_bleu.setValue(u16ConsigneConfort);
	slider_bleu.invalidate();
	if(u8ZoneSelect == 0xff ||  (sConfig_IHM.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT))
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", (float) u16ConsigneConfort - 200);
		if ((sConfig_IHM.sMode_RegulExt.Mode == AUTO_CHAUD && u8ZoneSelect == 0xff)|| (sConfig_IHM.sMode_Zx[u8ZoneSelect].Mode == AUTO_CHAUD && u8ZoneSelect != 0xff))
		{
			positionEcran = ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9);
		}
		else
		{
			positionEcran = ((float) slider_bleu.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 190) * (float) 17.8);
		}
	}
	else
	{
		Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", ((float) u16ConsigneConfort) / 10);
		positionEcran = ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 120) * (float) 1.98);
	}
	textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_rouge.moveTo(positionEcran , 51);
	textArea_rouge.invalidate();
	textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
	textArea_bleu.moveTo(positionEcran, 51);
	textArea_bleu.invalidate();
}

void ZoneView::timer_100ms()
{
	if(u16TempoEnvoiConsigne)
	{
		u16TempoEnvoiConsigne--;
		if(u16TempoEnvoiConsigne == 0)
		{
			if(u8ZoneSelect == 0xff)
			{
				if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Confort != u16ConsigneConfort || sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Normal != u16ConsigneNormal || sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Reduit != u16ConsigneReduit)
				{
					sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Confort = u16ConsigneConfort;
					sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Normal = u16ConsigneNormal;
					sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Reduit = u16ConsigneReduit;
					presenter->c_user_reg_ext();
				}
			}
			else
			{
				if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort != u16ConsigneConfort || sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal != u16ConsigneNormal || sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit != u16ConsigneReduit)
				{
					sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort = u16ConsigneConfort;
					sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal = u16ConsigneNormal;
					sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit = u16ConsigneReduit;
					presenter->c_user_zx(u8ZoneSelect);
				}
			}
		}
	}
}

void ZoneView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	//Régul Ext
	if(u8ZoneSelect == 0xff)
	{
		Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_BALLON_TAMPON_CENTRE_DEFAUT).getText());
		barre_titre.titre(textAreaBuffer_Titre);

		container_hors_gel.setVisible(false);
		container_hors_gel.invalidate();

		if(sConfig_IHM_old.sParam_RegulExt.bModeFroid != sConfig_IHM->sParam_RegulExt.bModeFroid)
		{
			if(sConfig_IHM->sParam_RegulExt.bModeFroid != 0)
			{
				container_froid.setVisible(true);
			}
			else container_froid.setVisible(false);
			container_froid.invalidate();
		}

		if(sConfig_IHM_old.sParam_RegulExt.bModeChaud != sConfig_IHM->sParam_RegulExt.bModeChaud)
		{
			if(sConfig_IHM->sParam_RegulExt.bModeChaud != 0)
			{
				container_chaud.setVisible(true);
			}
			else container_chaud.setVisible(false);
			container_chaud.invalidate();
		}

		if(sConfig_IHM_old.sMode_RegulExt.Mode != sConfig_IHM->sMode_RegulExt.Mode)
		{
			switch(sConfig_IHM->sMode_RegulExt.Mode)
			{
				case ARRET:
					toggleButton_arret.forceState(true);
					toggleButton_arret.setTouchable(false);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(false);
					container_derogation.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
				case MARCHE_CHAUD:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(true);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(false);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
				case AUTO_CHAUD:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(true);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(true);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(true);
					container_slider_orange.setVisible(true);
					container_slider_rouge.setVisible(true);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
				case MARCHE_FROID:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(true);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(false);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
				case AUTO_FROID:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(true);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(true);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(true);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(true);
					textArea_consigne.setVisible(true);
					break;
				case HORS_GEL:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(true);
					toggleButton_hors_gel.setTouchable(false);
					container_auto_prog.setVisible(false);
					container_derogation.setVisible(false);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
			}
			toggleButton_arret.invalidate();
			button_chaud_on.invalidate();
			button_froid_on.invalidate();
			toggleButton_hors_gel.invalidate();
			container_auto_prog.invalidate();
			container_derogation.invalidate();
			container_slider_jaune.invalidate();
			container_slider_orange.invalidate();
			container_slider_rouge.invalidate();
			container_slider_bleu_reduit.invalidate();
			container_slider_bleu.invalidate();
			container_slider_bleu_ciel.invalidate();
			textArea_consigne.invalidate();
		}

		if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Reduit != sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Reduit)
		{
			u16ConsigneReduit = sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Reduit;
			slider_jaune.setValue((int) u16ConsigneReduit);
			slider_jaune.invalidate();
			slider_bleu_reduit.setValue((int) u16ConsigneReduit);
			slider_bleu_reduit.invalidate();

			Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", (float) u16ConsigneReduit - 200);

			textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
			textArea_jaune.moveTo((int) ((float) slider_jaune.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9), 51);
			textArea_jaune.invalidate();

			textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
			textArea_bleu_reduit.moveTo((int) ((float) slider_bleu_reduit.getX() + 19 - textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 190) * (float) 17.8), 51);
			textArea_bleu_reduit.invalidate();
		}

		if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Normal != sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Normal)
		{
			u16ConsigneNormal = sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Normal;
			slider_orange.setValue(u16ConsigneNormal);
			slider_orange.invalidate();
			slider_bleu_ciel.setValue(u16ConsigneNormal);
			slider_bleu_ciel.invalidate();

			Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", (float) u16ConsigneNormal - 200);

			textArea_orange.moveTo((int) ((float) slider_orange.getX() + 19 - textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9), 51);
			textArea_orange.invalidate();
			textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
			textArea_bleu_ciel.moveTo((int) ((float) slider_bleu_ciel.getX() + 19 - textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9), 51);
			textArea_bleu_ciel.invalidate();
		}

		if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Confort != sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Confort)
		{
			u16ConsigneConfort = sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Confort;
			slider_rouge.setValue(u16ConsigneConfort);
			slider_rouge.invalidate();
			slider_bleu.setValue(u16ConsigneConfort);
			slider_bleu.invalidate();

			Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", (float) u16ConsigneConfort - 200);

			textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
			textArea_rouge.moveTo((int) ((float) slider_rouge.getX() + 19 - textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9), 51);
			textArea_rouge.invalidate();
			textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
			textArea_bleu.moveTo((int) ((float) slider_bleu.getX() + 19 - textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 190) * (float) 17.8), 51);
			textArea_bleu.invalidate();
		}

		if(sConfig_IHM_old.sMode_RegulExt.Exception != sConfig_IHM->sMode_RegulExt.Exception)
		{
			if(sConfig_IHM->sMode_RegulExt.Exception == SABLIER)
			{
				button_derog_on.setVisible(true);
			}
			else button_derog_on.setVisible(false);
			button_derog_on.invalidate();
		}
	} //Fin de Régul Externe
	else
	{
		if(memcmp(&sConfig_IHM_old.sOption_PAC.sZone, &sConfig_IHM->sOption_PAC.sZone, sizeof(sConfig_IHM_old.sOption_PAC.sZone)))
		{
			u8NbZone = sConfig_IHM->sOption_PAC.sZone.bZone1 +
						sConfig_IHM->sOption_PAC.sZone.bZone2 +
						sConfig_IHM->sOption_PAC.sZone.bZone3 +
						sConfig_IHM->sOption_PAC.sZone.bZone4 +
						sConfig_IHM->sOption_PAC.sZone.bZone5 +
						sConfig_IHM->sOption_PAC.sZone.bZone6 +
						sConfig_IHM->sOption_PAC.sZone.bZone7 +
						sConfig_IHM->sOption_PAC.sZone.bZone8;
		}

		if(memcmp(&sConfig_IHM_old.sParam_Zx[u8ZoneSelect].u8NomZone[0], &sConfig_IHM->sParam_Zx[u8ZoneSelect].u8NomZone[0], 10))
		{
			Unicode::fromUTF8(sConfig_IHM->sParam_Zx[u8ZoneSelect].u8NomZone, textAreaBuffer_Titre, 10);
			barre_titre.titre(textAreaBuffer_Titre);
		}

		if(sConfig_IHM_old.sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat != sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat)
		{
			if(sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat <= TH_MODBUS)
			{
				container_hors_gel.setVisible(true);
			}
			else container_hors_gel.setVisible(false);
			container_hors_gel.invalidate();
		}

		if(sConfig_IHM_old.sParam_Zx[u8ZoneSelect].bModeFroid != sConfig_IHM->sParam_Zx[u8ZoneSelect].bModeFroid)
		{
			if(sConfig_IHM->sParam_Zx[u8ZoneSelect].bModeFroid != 0)
			{
				container_froid.setVisible(true);
			}
			else container_froid.setVisible(false);
			container_froid.invalidate();
		}

		if(sConfig_IHM_old.sParam_Zx[u8ZoneSelect].bModeChaud != sConfig_IHM->sParam_Zx[u8ZoneSelect].bModeChaud)
		{
			if(sConfig_IHM->sParam_Zx[u8ZoneSelect].bModeChaud != 0)
			{
				container_chaud.setVisible(true);
			}
			else container_chaud.setVisible(false);
			container_chaud.invalidate();
		}

		if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].Mode != sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode)
		{
			switch(sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode)
			{
				case ARRET:
					toggleButton_arret.forceState(true);
					toggleButton_arret.setTouchable(false);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(false);
					container_derogation.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
				case MARCHE_CHAUD:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(true);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(false);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(true);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(true);
					break;
				case AUTO_CHAUD:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(true);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(true);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(true);
					container_slider_orange.setVisible(true);
					container_slider_rouge.setVisible(true);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(true);
					break;
				case MARCHE_FROID:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(true);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(false);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(true);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(true);
					break;
				case AUTO_FROID:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(true);
					toggleButton_hors_gel.forceState(false);
					toggleButton_hors_gel.setTouchable(true);
					container_auto_prog.setVisible(true);
					button_prog_on.setVisible(true);
					container_derogation.setVisible(true);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(true);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(true);
					textArea_consigne.setVisible(true);
					break;
				case HORS_GEL:
					toggleButton_arret.forceState(false);
					toggleButton_arret.setTouchable(true);
					button_chaud_on.setVisible(false);
					button_froid_on.setVisible(false);
					toggleButton_hors_gel.forceState(true);
					toggleButton_hors_gel.setTouchable(false);
					container_auto_prog.setVisible(false);
					container_derogation.setVisible(false);
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
					break;
			}

			//Pour MAJ des Sliders min/max suivant que l'on est sur l'eau ou sur l'ambiance
			if (sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT)
			{
				container_derogation.setVisible(false);

				if (sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode == MARCHE_CHAUD || sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode == MARCHE_FROID)
				{
					container_slider_jaune.setVisible(false);
					container_slider_orange.setVisible(false);
					container_slider_rouge.setVisible(false);
					container_slider_bleu.setVisible(false);
					container_slider_bleu_ciel.setVisible(false);
					container_slider_bleu_reduit.setVisible(false);
					textArea_consigne.setVisible(false);
				}
			}
			toggleButton_arret.invalidate();
			button_chaud_on.invalidate();
			button_froid_on.invalidate();
			toggleButton_hors_gel.invalidate();
			container_auto_prog.invalidate();
			container_derogation.invalidate();
			container_slider_jaune.invalidate();
			container_slider_orange.invalidate();
			container_slider_rouge.invalidate();
			container_slider_bleu_reduit.invalidate();
			container_slider_bleu.invalidate();
			container_slider_bleu_ciel.invalidate();
			textArea_consigne.invalidate();
		}

		//Pour MAJ des Consignes Slider en Thermosat Contact
//		if (sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT)
//		{
//			if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Reduit != sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Reduit)
//			{
//				u16ConsigneReduit = sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Reduit;
//				slider_jaune.setValue((int) u16ConsigneReduit);
//				slider_jaune.invalidate();
//				slider_bleu_reduit.setValue((int) u16ConsigneReduit);
//				slider_bleu_reduit.invalidate();
//
//				Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", (float) u16ConsigneReduit - 200);
//
//				textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
//				textArea_jaune.moveTo((int) ((float) slider_jaune.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9), 51);
//				textArea_jaune.invalidate();
//				textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
//				textArea_bleu_reduit.moveTo((int) ((float) slider_bleu_reduit.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9), 51);
//				textArea_bleu_reduit.invalidate();
//			}
//
//			if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Normal != sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Normal)
//			{
//				u16ConsigneNormal = sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Normal;
//				slider_orange.setValue(u16ConsigneNormal);
//				slider_orange.invalidate();
//				slider_bleu_ciel.setValue(u16ConsigneNormal);
//				slider_bleu_ciel.invalidate();
//
//				Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", (float) u16ConsigneNormal - 200);
//
//				textArea_orange.moveTo((int) ((float) slider_orange.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9), 51);
//				textArea_orange.invalidate();
//				textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
//				textArea_bleu_ciel.moveTo((int) ((float) slider_bleu_ciel.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9), 51);
//				textArea_bleu_ciel.invalidate();
//			}
//
//			if(sConfig_IHM_old.sMode_RegulExt.i16Consigne_Eau_Confort != sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Confort)
//			{
//				u16ConsigneConfort = sConfig_IHM->sMode_RegulExt.i16Consigne_Eau_Confort;
//				slider_rouge.setValue(u16ConsigneConfort);
//				slider_rouge.invalidate();
//				slider_bleu.setValue(u16ConsigneConfort);
//				slider_bleu.invalidate();
//
//				Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", (float) u16ConsigneConfort - 200);
//
//				textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
//				textArea_rouge.moveTo((int) ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9), 51);
//				textArea_rouge.invalidate();
//				textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
//				textArea_bleu.moveTo((int) ((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9), 51);
//				textArea_bleu.invalidate();
//			}
//		}
//		else
		{
			if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit != sConfig_IHM->sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit)
			{
				u16ConsigneReduit = sConfig_IHM->sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit;
				slider_jaune.setValue((int) u16ConsigneReduit);
				slider_jaune.invalidate();
				slider_bleu_reduit.setValue((int) u16ConsigneReduit);
				slider_bleu_reduit.invalidate();

				if (sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT)
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", (float) u16ConsigneReduit - 200);
					textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
					textArea_jaune.moveTo((int) ((float) slider_jaune.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 180) * (float) 8.9), 51);
					textArea_jaune.invalidate();
					textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
					textArea_bleu_reduit.moveTo((int) ((float) slider_bleu_reduit.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 190) * (float) 17.8), 51);
					textArea_bleu_reduit.invalidate();
				}
				else
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneReduit, 6, "%.1f", ((float) u16ConsigneReduit) / 10);
					textArea_jaune.setWildcard(textAreaBuffer_ConsigneReduit);
					textArea_jaune.moveTo((int) ((float) slider_jaune.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_jaune.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 120) * (float) 1.98), 51);
					textArea_jaune.invalidate();
					if (sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode == AUTO_FROID)
					{
						textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
						textArea_bleu_reduit.moveTo((int) ((float) slider_bleu_reduit.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 190) * (float) 17.8), 51);
						textArea_bleu_reduit.invalidate();
					}
					else
					{
						textArea_bleu_reduit.setWildcard(textAreaBuffer_ConsigneReduit);
						textArea_bleu_reduit.moveTo((int) ((float) slider_bleu_reduit.getX() + 19 /*+ slider_jaune.background.getX()*/- textArea_bleu_reduit.getWidth() / 2 + ((float) u16ConsigneReduit - (float) 120) * (float) 1.98), 51);
						textArea_bleu_reduit.invalidate();
					}

				}
			}

			if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal != sConfig_IHM->sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal)
			{
				u16ConsigneNormal = sConfig_IHM->sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal;
				slider_orange.setValue(u16ConsigneNormal);
				slider_orange.invalidate();
				slider_bleu_ciel.setValue(u16ConsigneNormal);
				slider_bleu_ciel.invalidate();

				if (sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT)
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", (float) u16ConsigneNormal - 200);
					textArea_orange.moveTo((int) ((float) slider_orange.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9), 51);
					textArea_orange.invalidate();
//					textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
//					textArea_bleu_ciel.moveTo((int) ((float) slider_bleu_ciel.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 180) * (float) 8.9), 51);
//					textArea_bleu_ciel.invalidate();
				}
				else
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneNormal, 6, "%.1f", ((float) u16ConsigneNormal) / 10);
					textArea_orange.setWildcard(textAreaBuffer_ConsigneNormal);
					textArea_orange.moveTo((int) ((float) slider_orange.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_orange.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 120) * (float) 1.98), 51);
					textArea_orange.invalidate();
					if (sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode == AUTO_FROID)
					{
						textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
						textArea_bleu_ciel.moveTo((int) ((float) slider_bleu_ciel.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 190) * (float) 17.8), 51);
						textArea_bleu_ciel.invalidate();
					}
					else
					{
						textArea_bleu_ciel.setWildcard(textAreaBuffer_ConsigneNormal);
						textArea_bleu_ciel.moveTo((int) ((float) slider_bleu_ciel.getX() + 19 /*+ slider_bleu_ciel.background.getX()*/- textArea_bleu_ciel.getWidth() / 2 + ((float) u16ConsigneNormal - (float) 120) * (float) 1.98), 51);
						textArea_bleu_ciel.invalidate();
					}
				}
			}

			if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort != sConfig_IHM->sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort)
			{
				u16ConsigneConfort = sConfig_IHM->sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort;
				slider_rouge.setValue(u16ConsigneConfort);
				slider_rouge.invalidate();
				slider_bleu.setValue(u16ConsigneConfort);
				slider_bleu.invalidate();

				if (sConfig_IHM->sParam_Zx[u8ZoneSelect].type_zone.zone.TypeThermostat == TH_CONTACT)
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", (float) u16ConsigneConfort - 200);
					textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
					textArea_rouge.moveTo((int) ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9), 51);
					textArea_rouge.invalidate();
					if (sConfig_IHM->sMode_Zx[u8ZoneSelect].Mode == AUTO_FROID)
					{
						textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
						textArea_bleu.moveTo((int) ((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 190) * (float) 17.8), 51);
						textArea_bleu.invalidate();
					}
					else
					{
						textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
						textArea_bleu.moveTo((int) ((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 180) * (float) 8.9), 51);
						textArea_bleu.invalidate();
					}
				}
				else
				{
					Unicode::snprintfFloat(textAreaBuffer_ConsigneConfort, 6, "%.1f", ((float) u16ConsigneConfort) / 10);
					textArea_rouge.setWildcard(textAreaBuffer_ConsigneConfort);
					textArea_rouge.moveTo((int) ((float) slider_rouge.getX() + 19 /*+ slider_rouge.background.getX()*/- textArea_rouge.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 120) * (float) 1.98), 51);
					textArea_rouge.invalidate();
					textArea_bleu.setWildcard(textAreaBuffer_ConsigneConfort);
					textArea_bleu.moveTo((int) ((float) slider_bleu.getX() + 19 /*+ slider_bleu.background.getX()*/- textArea_bleu.getWidth() / 2 + ((float) u16ConsigneConfort - (float) 120) * (float) 1.98), 51);
					textArea_bleu.invalidate();
				}
			}
		}

		if(sConfig_IHM_old.sMode_Zx[u8ZoneSelect].Exception != sConfig_IHM->sMode_Zx[u8ZoneSelect].Exception)
		{
			if(sConfig_IHM->sMode_Zx[u8ZoneSelect].Exception == SABLIER)
			{
				button_derog_on.setVisible(true);
			}
			else button_derog_on.setVisible(false);
			button_derog_on.invalidate();
		}
	}

	if(sConfig_IHM_old.sOption_PAC.TypeAppoint != sConfig_IHM->sOption_PAC.TypeAppoint)
	{
		if(sConfig_IHM->sOption_PAC.TypeAppoint != 0)
		{
			container_appoint.setVisible(true);
			if(sConfig_IHM->sOption_PAC.TypeAppoint == ELEC)
			{
				image_appoint.setVisible(true);
				image_chaudiere.setVisible(false);
			}
			else
			{
				image_appoint.setVisible(false);
				image_chaudiere.setVisible(true);
			}
		}
		else container_appoint.setVisible(false);
		container_appoint.invalidate();
	}

	if(sConfig_IHM_old.sMode_PAC.bAppointUser != sConfig_IHM->sMode_PAC.bAppointUser)
	{
		if(sConfig_IHM->sMode_PAC.bAppointUser == 1)
		{
			toggleButton_appoint.forceState(true);
		}
		else toggleButton_appoint.forceState(false);
		toggleButton_appoint.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void ZoneView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void ZoneView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void ZoneView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void ZoneView::changeDate(S_DATE *sDate)
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
