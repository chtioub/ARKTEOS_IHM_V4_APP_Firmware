#include <gui/programmation_screen/ProgrammationView.hpp>
#include <BitmapDatabase.hpp>

ProgrammationView::ProgrammationView()
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
	container.setXY(u8PositionX, u8PositionY);
	// Definition des images à afficher
	image_off = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_OFF_L8XH46_ID);

	switch(eProg)
	{
		case PRO_CHAUD:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_ZONE_CHAUD_CENTRE_DEFAUT).getText());
			Unicode::fromUTF8(sConfig_IHM.sParam_Zx[u8ZoneSelect].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_FROID:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_CONFORT_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_CONFORT_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_ZONE_CHAUD_CENTRE_DEFAUT).getText());
			Unicode::fromUTF8(sConfig_IHM.sParam_Zx[u8ZoneSelect].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_EXT_CHAUD:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_REGUL_EXT_CHAUD_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_EXT_FROID:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_CONFORT_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_CONFORT_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_REGUL_EXT_RAFRAICHISSEMENT_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_PISCINE:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_PISCINE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_ECS:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUFFE_EAU_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_ECS_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_PISCINE_CONFORT:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_CONFORT_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_PISCINE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_OPTION:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_BOUCLAGE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_SILENCE:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUFFE_EAU_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_SILENCE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
	}
	// Positionnement des images
	for(int j = 0; j < 7; j++)
	{
		container_jour[j].setVisible(true);
		container_jour[j].setPosition(15, 128 + 51 * j, 768, 46);
		for(int i = 0; i < 24; i++)
		{
			for(int k = 0; k < 4; k++)
			{
				switch((u8Prog[j][i] >> (k * 2)) & 0x3)
				{
					case 0:
						if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
						{
							u8Prog[j][i] = u8Prog[j][i] | (0b01 << (k * 2));
							image_prog[j][i * 4 + k].setBitmap(image1);
						}
						else
							image_prog[j][i * 4 + k].setBitmap(image_off);
						break;
					case 1:
						image_prog[j][i * 4 + k].setBitmap(image1);
						break;
					case 2:
						image_prog[j][i * 4 + k].setBitmap(image2);
						break;
					case 3:
						image_prog[j][i * 4 + k].setBitmap(image3);
						break;
				}
				image_prog[j][i * 4 + k].setXY((i * 4 + k) * 8, 0);
				image_prog[j][i * 4 + k].setVisible(true);
				container_jour[j].add(image_prog[j][i * 4 + k]);
			}
		}
		container.add(container_jour[j]);
	}
	// Mise au premier plan des heures
	container.remove(container_barre_heure_1);
	container.remove(textArea_jour_1);
	container.remove(toggleButton_barre_heure_1);
	container.add(container_barre_heure_1);
    container.add(textArea_jour_1);
    container.add(toggleButton_barre_heure_1);
	container.remove(container_barre_heure_2);
	container.remove(textArea_jour_2);
	container.remove(toggleButton_barre_heure_2);
	container.add(container_barre_heure_2);
    container.add(textArea_jour_2);
    container.add(toggleButton_barre_heure_2);
	container.remove(container_barre_heure_3);
	container.remove(textArea_jour_3);
	container.remove(toggleButton_barre_heure_3);
	container.add(container_barre_heure_3);
    container.add(textArea_jour_3);
    container.add(toggleButton_barre_heure_3);
	container.remove(container_barre_heure_4);
	container.remove(textArea_jour_4);
	container.remove(toggleButton_barre_heure_4);
	container.add(container_barre_heure_4);
    container.add(textArea_jour_4);
    container.add(toggleButton_barre_heure_4);
	container.remove(container_barre_heure_5);
	container.remove(textArea_jour_5);
	container.remove(toggleButton_barre_heure_5);
	container.add(container_barre_heure_5);
    container.add(textArea_jour_5);
    container.add(toggleButton_barre_heure_5);
	container.remove(container_barre_heure_6);
	container.remove(textArea_jour_6);
	container.remove(toggleButton_barre_heure_6);
	container.add(container_barre_heure_6);
    container.add(textArea_jour_6);
    container.add(toggleButton_barre_heure_6);
	container.remove(container_barre_heure_7);
	container.remove(textArea_jour_7);
	container.remove(toggleButton_barre_heure_7);
	container.add(container_barre_heure_7);
    container.add(textArea_jour_7);
    container.add(toggleButton_barre_heure_7);
	// Init des boutons
    u8JourProg = 0;
	buttonWithLabel_coller.setVisible(false);
	toggleButton_barre_heure_1.forceState(true);
	toggleButton_barre_heure_1.setTouchable(false);
	toggleButton_barre_heure_2.forceState(false);
	toggleButton_barre_heure_3.forceState(false);
	toggleButton_barre_heure_4.forceState(false);
	toggleButton_barre_heure_5.forceState(false);
	toggleButton_barre_heure_6.forceState(false);
	toggleButton_barre_heure_7.forceState(false);
}

void ProgrammationView::setupScreen()
{
    ProgrammationViewBase::setupScreen();
}

void ProgrammationView::tearDownScreen()
{
    ProgrammationViewBase::tearDownScreen();
}

void ProgrammationView::bouton_copier()
{
	buttonWithLabel_coller.setVisible(true);
	buttonWithLabel_coller.invalidate();
	if(toggleButton_barre_heure_1.getState())
	{
		u8Copie = 0;
		barre_mardi();
	}
	else if(toggleButton_barre_heure_2.getState())
	{
		u8Copie = 1;
		barre_mercredi();
	}
	else if(toggleButton_barre_heure_3.getState())
	{
		u8Copie = 2;
		barre_jeudi();
	}
	else if(toggleButton_barre_heure_4.getState())
	{
		u8Copie = 3;
		barre_vendredi();
	}
	else if(toggleButton_barre_heure_5.getState())
	{
		u8Copie = 4;
		barre_samedi();
	}
	else if(toggleButton_barre_heure_6.getState())
	{
		u8Copie = 5;
		barre_dimanche();
	}
	else if(toggleButton_barre_heure_7.getState())
	{
		u8Copie = 6;
		barre_lundi();
	}
}

void ProgrammationView::bouton_coller()
{
	uint8_t u8BarreHeure = 0;

	if(toggleButton_barre_heure_1.getState())
	{
		u8BarreHeure = 0;
		barre_mardi();
	}
	else if(toggleButton_barre_heure_2.getState())
	{
		u8BarreHeure = 1;
		barre_mercredi();
	}
	else if(toggleButton_barre_heure_3.getState())
	{
		u8BarreHeure = 2;
		barre_jeudi();
	}
	else if(toggleButton_barre_heure_4.getState())
	{
		u8BarreHeure = 3;
		barre_vendredi();
	}
	else if(toggleButton_barre_heure_5.getState())
	{
		u8BarreHeure = 4;
		barre_samedi();
	}
	else if(toggleButton_barre_heure_6.getState())
	{
		u8BarreHeure = 5;
		barre_dimanche();
	}
	else if(toggleButton_barre_heure_7.getState())
	{
		u8BarreHeure = 6;
		barre_lundi();
	}
	// Copie des datas
	for(int i = 0; i < 24; i++)
	{
		if(eProg == PRO_ECS || eProg == PRO_SILENCE)
		{
			u8Prog[u8BarreHeure][i] = (u8Prog[u8BarreHeure][i] & 0xAA) + (u8Prog[u8Copie][i] & 0x55);
		}
		else u8Prog[u8BarreHeure][i] = u8Prog[u8Copie][i];
	}
	// MAJ des graphiques
	for(int j = 0; j < 7; j++)
	{
		for(int i = 0; i < 24; i++)
		{
			for(int k = 0; k < 4; k++)
			{
				switch((u8Prog[j][i] >> (k * 2)) & 0x3)
				{
					case 0:
						image_prog[j][i * 4 + k].setBitmap(image_off);
						break;
					case 1:
						image_prog[j][i * 4 + k].setBitmap(image1);
						break;
					case 2:
						image_prog[j][i * 4 + k].setBitmap(image2);
						break;
					case 3:
						image_prog[j][i * 4 + k].setBitmap(image3);
						break;
				}
			}
		}
	}
}

void ProgrammationView::bouton_retour()
{
	switch(eProg)
	{
		case PRO_CHAUD:
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_FROID:
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_EXT_CHAUD:
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_EXT_FROID:
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_PISCINE:
			application().gotoPiscineScreenNoTransition();
			break;
		case PRO_ECS:
			application().gotoEau_chaude_sanitaireScreenNoTransition();
			break;
		case PRO_PISCINE_CONFORT:
			application().gotoPiscineScreenNoTransition();
			break;
		case PRO_OPTION:
			application().gotoBouclage_ecsScreenNoTransition();
			break;
		case PRO_SILENCE:
			application().gotoInstallation_mode_silencieuxScreenNoTransition();
			break;
	}
}

void ProgrammationView::bouton_valider()
{
	switch(eProg)
	{
		case PRO_CHAUD:
			if(memcmp(u8Prog, au8Prog_Chaud_Zx[u8ZoneSelect], sizeof(u8Prog)))
			{
				memcpy(au8Prog_Chaud_Zx[u8ZoneSelect], u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_zone_chaud(u8ZoneSelect, true);
#endif
			}
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_FROID:
			if(memcmp(u8Prog, au8Prog_Froid_Zx[u8ZoneSelect], sizeof(u8Prog)))
			{
				memcpy(au8Prog_Froid_Zx[u8ZoneSelect], u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_zone_froid(u8ZoneSelect, true);
#endif
			}
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_EXT_CHAUD:
			if(memcmp(u8Prog, au8Prog_Regul_Ext_Chaud, sizeof(u8Prog)))
			{
				memcpy(au8Prog_Regul_Ext_Chaud, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_reg_ext_chaud(true);
#endif
			}
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_EXT_FROID:
			if(memcmp(u8Prog, au8Prog_Regul_Ext_Froid, sizeof(u8Prog)))
			{
				memcpy(au8Prog_Regul_Ext_Froid, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_reg_ext_froid(true);
#endif
			}
			application().gotoZoneScreenNoTransition();
			break;
		case PRO_PISCINE:
			if(memcmp(u8Prog, au8Prog_Piscine, sizeof(u8Prog)))
			{
				memcpy(au8Prog_Piscine, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_piscine(true);
#endif
			}
			application().gotoPiscineScreenNoTransition();
			break;
		case PRO_ECS:
			if(memcmp(u8Prog, au8Prog_ECS, sizeof(u8Prog)))
			{
				memcpy(au8Prog_ECS, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_ecs(true);
#endif
			}
			application().gotoEau_chaude_sanitaireScreenNoTransition();
			break;
		case PRO_PISCINE_CONFORT:
			if(memcmp(u8Prog, au8Prog_Piscine, sizeof(u8Prog)))
			{
				memcpy(au8Prog_Piscine, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_piscine(true);
#endif
			}
			application().gotoPiscineScreenNoTransition();
			break;
		case PRO_OPTION:
			if(memcmp(u8Prog, au8Prog_Options, sizeof(u8Prog)))
			{
				memcpy(au8Prog_Options, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_option(true);
#endif
			}
			application().gotoBouclage_ecsScreenNoTransition();
			break;
		case PRO_SILENCE:
			if(memcmp(u8Prog, au8Prog_ModeSilence, sizeof(u8Prog)))
			{
				memcpy(au8Prog_ModeSilence, u8Prog, sizeof(u8Prog));
#ifndef SIMULATOR
				presenter->c_prog_silence(true);
#endif
			}
			sConfig_IHM.sMode_PAC.bModeSilencieux = 1;
			application().gotoInstallation_mode_silencieuxScreenNoTransition();
			break;
	}
}

void ProgrammationView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void ProgrammationView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void ProgrammationView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void ProgrammationView::changeDate(S_DATE *sDate)
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

void ProgrammationView::barre_lundi()
{
	u8JourProg = 0;
	toggleButton_barre_heure_1.forceState(true);
	toggleButton_barre_heure_1.setTouchable(false);
	toggleButton_barre_heure_1.invalidate();
	if(toggleButton_barre_heure_2.getState())
	{
		toggleButton_barre_heure_2.forceState(false);
		toggleButton_barre_heure_2.setTouchable(true);
		toggleButton_barre_heure_2.invalidate();
	}
	if(toggleButton_barre_heure_3.getState())
	{
		toggleButton_barre_heure_3.forceState(false);
		toggleButton_barre_heure_3.setTouchable(true);
		toggleButton_barre_heure_3.invalidate();
	}
	if(toggleButton_barre_heure_4.getState())
	{
		toggleButton_barre_heure_4.forceState(false);
		toggleButton_barre_heure_4.setTouchable(true);
		toggleButton_barre_heure_4.invalidate();
	}
	if(toggleButton_barre_heure_5.getState())
	{
		toggleButton_barre_heure_5.forceState(false);
		toggleButton_barre_heure_5.setTouchable(true);
		toggleButton_barre_heure_5.invalidate();
	}
	if(toggleButton_barre_heure_6.getState())
	{
		toggleButton_barre_heure_6.forceState(false);
		toggleButton_barre_heure_6.setTouchable(true);
		toggleButton_barre_heure_6.invalidate();
	}
	if(toggleButton_barre_heure_7.getState())
	{
		toggleButton_barre_heure_7.forceState(false);
		toggleButton_barre_heure_7.setTouchable(true);
		toggleButton_barre_heure_7.invalidate();
	}
}

void ProgrammationView::barre_mardi()
{
	u8JourProg = 1;
	if(toggleButton_barre_heure_1.getState())
	{
		toggleButton_barre_heure_1.forceState(false);
		toggleButton_barre_heure_1.setTouchable(true);
		toggleButton_barre_heure_1.invalidate();
	}
	toggleButton_barre_heure_2.forceState(true);
	toggleButton_barre_heure_2.setTouchable(false);
	toggleButton_barre_heure_2.invalidate();
	if(toggleButton_barre_heure_3.getState())
	{
		toggleButton_barre_heure_3.forceState(false);
		toggleButton_barre_heure_3.setTouchable(true);
		toggleButton_barre_heure_3.invalidate();
	}
	if(toggleButton_barre_heure_4.getState())
	{
		toggleButton_barre_heure_4.forceState(false);
		toggleButton_barre_heure_4.setTouchable(true);
		toggleButton_barre_heure_4.invalidate();
	}
	if(toggleButton_barre_heure_5.getState())
	{
		toggleButton_barre_heure_5.forceState(false);
		toggleButton_barre_heure_5.setTouchable(true);
		toggleButton_barre_heure_5.invalidate();
	}
	if(toggleButton_barre_heure_6.getState())
	{
		toggleButton_barre_heure_6.forceState(false);
		toggleButton_barre_heure_6.setTouchable(true);
		toggleButton_barre_heure_6.invalidate();
	}
	if(toggleButton_barre_heure_7.getState())
	{
		toggleButton_barre_heure_7.forceState(false);
		toggleButton_barre_heure_7.setTouchable(true);
		toggleButton_barre_heure_7.invalidate();
	}
}

void ProgrammationView::barre_mercredi()
{
	u8JourProg = 2;
	if(toggleButton_barre_heure_1.getState())
	{
		toggleButton_barre_heure_1.forceState(false);
		toggleButton_barre_heure_1.setTouchable(true);
		toggleButton_barre_heure_1.invalidate();
	}
	if(toggleButton_barre_heure_2.getState())
	{
		toggleButton_barre_heure_2.forceState(false);
		toggleButton_barre_heure_2.setTouchable(true);
		toggleButton_barre_heure_2.invalidate();
	}
	toggleButton_barre_heure_3.forceState(true);
	toggleButton_barre_heure_3.setTouchable(false);
	toggleButton_barre_heure_3.invalidate();
	if(toggleButton_barre_heure_4.getState())
	{
		toggleButton_barre_heure_4.forceState(false);
		toggleButton_barre_heure_4.setTouchable(true);
		toggleButton_barre_heure_4.invalidate();
	}
	if(toggleButton_barre_heure_5.getState())
	{
		toggleButton_barre_heure_5.forceState(false);
		toggleButton_barre_heure_5.setTouchable(true);
		toggleButton_barre_heure_5.invalidate();
	}
	if(toggleButton_barre_heure_6.getState())
	{
		toggleButton_barre_heure_6.forceState(false);
		toggleButton_barre_heure_6.setTouchable(true);
		toggleButton_barre_heure_6.invalidate();
	}
	if(toggleButton_barre_heure_7.getState())
	{
		toggleButton_barre_heure_7.forceState(false);
		toggleButton_barre_heure_7.setTouchable(true);
		toggleButton_barre_heure_7.invalidate();
	}
}

void ProgrammationView::barre_jeudi()
{
	u8JourProg = 3;
	if(toggleButton_barre_heure_1.getState())
	{
		toggleButton_barre_heure_1.forceState(false);
		toggleButton_barre_heure_1.setTouchable(true);
		toggleButton_barre_heure_1.invalidate();
	}
	if(toggleButton_barre_heure_2.getState())
	{
		toggleButton_barre_heure_2.forceState(false);
		toggleButton_barre_heure_2.setTouchable(true);
		toggleButton_barre_heure_2.invalidate();
	}
	if(toggleButton_barre_heure_3.getState())
	{
		toggleButton_barre_heure_3.forceState(false);
		toggleButton_barre_heure_3.setTouchable(true);
		toggleButton_barre_heure_3.invalidate();
	}
	toggleButton_barre_heure_4.forceState(true);
	toggleButton_barre_heure_4.setTouchable(false);
	toggleButton_barre_heure_4.invalidate();
	if(toggleButton_barre_heure_5.getState())
	{
		toggleButton_barre_heure_5.forceState(false);
		toggleButton_barre_heure_5.setTouchable(true);
		toggleButton_barre_heure_5.invalidate();
	}
	if(toggleButton_barre_heure_6.getState())
	{
		toggleButton_barre_heure_6.forceState(false);
		toggleButton_barre_heure_6.setTouchable(true);
		toggleButton_barre_heure_6.invalidate();
	}
	if(toggleButton_barre_heure_7.getState())
	{
		toggleButton_barre_heure_7.forceState(false);
		toggleButton_barre_heure_7.setTouchable(true);
		toggleButton_barre_heure_7.invalidate();
	}
}

void ProgrammationView::barre_vendredi()
{
	u8JourProg = 4;
	if(toggleButton_barre_heure_1.getState())
	{
		toggleButton_barre_heure_1.forceState(false);
		toggleButton_barre_heure_1.setTouchable(true);
		toggleButton_barre_heure_1.invalidate();
	}
	if(toggleButton_barre_heure_2.getState())
	{
		toggleButton_barre_heure_2.forceState(false);
		toggleButton_barre_heure_2.setTouchable(true);
		toggleButton_barre_heure_2.invalidate();
	}
	if(toggleButton_barre_heure_3.getState())
	{
		toggleButton_barre_heure_3.forceState(false);
		toggleButton_barre_heure_3.setTouchable(true);
		toggleButton_barre_heure_3.invalidate();
	}
	if(toggleButton_barre_heure_4.getState())
	{
		toggleButton_barre_heure_4.forceState(false);
		toggleButton_barre_heure_4.setTouchable(true);
		toggleButton_barre_heure_4.invalidate();
	}
	toggleButton_barre_heure_5.forceState(true);
	toggleButton_barre_heure_5.setTouchable(false);
	toggleButton_barre_heure_5.invalidate();
	if(toggleButton_barre_heure_6.getState())
	{
		toggleButton_barre_heure_6.forceState(false);
		toggleButton_barre_heure_6.setTouchable(true);
		toggleButton_barre_heure_6.invalidate();
	}
	if(toggleButton_barre_heure_7.getState())
	{
		toggleButton_barre_heure_7.forceState(false);
		toggleButton_barre_heure_7.setTouchable(true);
		toggleButton_barre_heure_7.invalidate();
	}
}

void ProgrammationView::barre_samedi()
{
	u8JourProg = 5;
	if(toggleButton_barre_heure_1.getState())
	{
		toggleButton_barre_heure_1.forceState(false);
		toggleButton_barre_heure_1.setTouchable(true);
		toggleButton_barre_heure_1.invalidate();
	}
	if(toggleButton_barre_heure_2.getState())
	{
		toggleButton_barre_heure_2.forceState(false);
		toggleButton_barre_heure_2.setTouchable(true);
		toggleButton_barre_heure_2.invalidate();
	}
	if(toggleButton_barre_heure_3.getState())
	{
		toggleButton_barre_heure_3.forceState(false);
		toggleButton_barre_heure_3.setTouchable(true);
		toggleButton_barre_heure_3.invalidate();
	}
	if(toggleButton_barre_heure_4.getState())
	{
		toggleButton_barre_heure_4.forceState(false);
		toggleButton_barre_heure_4.setTouchable(true);
		toggleButton_barre_heure_4.invalidate();
	}
	if(toggleButton_barre_heure_5.getState())
	{
		toggleButton_barre_heure_5.forceState(false);
		toggleButton_barre_heure_5.setTouchable(true);
		toggleButton_barre_heure_5.invalidate();
	}
	toggleButton_barre_heure_6.forceState(true);
	toggleButton_barre_heure_6.setTouchable(false);
	toggleButton_barre_heure_6.invalidate();
	if(toggleButton_barre_heure_7.getState())
	{
		toggleButton_barre_heure_7.forceState(false);
		toggleButton_barre_heure_7.setTouchable(true);
		toggleButton_barre_heure_7.invalidate();
	}
}

void ProgrammationView::barre_dimanche()
{
	u8JourProg = 6;
	if(toggleButton_barre_heure_1.getState())
	{
		toggleButton_barre_heure_1.forceState(false);
		toggleButton_barre_heure_1.setTouchable(true);
		toggleButton_barre_heure_1.invalidate();
	}
	if(toggleButton_barre_heure_2.getState())
	{
		toggleButton_barre_heure_2.forceState(false);
		toggleButton_barre_heure_2.setTouchable(true);
		toggleButton_barre_heure_2.invalidate();
	}
	if(toggleButton_barre_heure_3.getState())
	{
		toggleButton_barre_heure_3.forceState(false);
		toggleButton_barre_heure_3.setTouchable(true);
		toggleButton_barre_heure_3.invalidate();
	}
	if(toggleButton_barre_heure_4.getState())
	{
		toggleButton_barre_heure_4.forceState(false);
		toggleButton_barre_heure_4.setTouchable(true);
		toggleButton_barre_heure_4.invalidate();
	}
	if(toggleButton_barre_heure_5.getState())
	{
		toggleButton_barre_heure_5.forceState(false);
		toggleButton_barre_heure_5.setTouchable(true);
		toggleButton_barre_heure_5.invalidate();
	}
	if(toggleButton_barre_heure_6.getState())
	{
		toggleButton_barre_heure_6.forceState(false);
		toggleButton_barre_heure_6.setTouchable(true);
		toggleButton_barre_heure_6.invalidate();
	}
	toggleButton_barre_heure_7.forceState(true);
	toggleButton_barre_heure_7.setTouchable(false);
	toggleButton_barre_heure_7.invalidate();
}
