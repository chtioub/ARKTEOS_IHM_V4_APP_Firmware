#include <gui/programmation_zoom_screen/Programmation_zoomView.hpp>
#include <BitmapDatabase.hpp>

Programmation_zoomView::Programmation_zoomView()
{
	uint8_t u8Tmp = 0;

	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Init du tableau de valeur
	memcpy(u8Prog_jour, u8Prog[u8JourProg], sizeof(u8Prog_jour));
	// Definition des images à afficher
	image_off = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_OFF_L8XH46_ID);
	bouton_off = touchgfx::Bitmap(BITMAP_BOUTON_PROG_OFF_L108XH71_ID);
	Unicode::snprintf(textAreaBuffer_Temp_Affichee_0, 7, touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT).getText());
	//
	switch(eProg)
	{
		case PRO_CHAUD:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_REDUIT_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_ON_OU_CONFORT_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_CONFORT_PLUS_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_ZOOM_L108XH71_ID);
			//
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_1, 5, "%.1f", ((float) sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_2, 5, "%.1f", ((float) sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Normal) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_3, 5, "%.1f", ((float) sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort) / 10);
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
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_EXTERNE_FROID_ON_OU_REDUIT_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_FROID_CONFORT_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_FROID_CONFORT_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_FROID_ZOOM_L108XH71_ID);
			//
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_1, 5, "%.1f", ((float) sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Reduit) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_2, 5, "%.1f", ((float) sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_3, 5, "%.1f", ((float) sConfig_IHM.sMode_Zx[u8ZoneSelect].i16Consigne_Tint_Confort) / 10);
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
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_REDUIT_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_ON_OU_CONFORT_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_CONFORT_PLUS_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_ZOOM_L108XH71_ID);
			//
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_1, 6, "%.1f", ((float) sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Reduit) - 200);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_2, 6, "%.1f", ((float) sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Normal) - 200);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_3, 6, "%.1f", ((float) sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Confort) - 200);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_REGUL_EXT_CHAUD_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			// Titre
			break;
		case PRO_EXT_FROID:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_CONFORT_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_FROID_CONFORT_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_EXTERNE_FROID_ON_OU_REDUIT_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_FROID_CONFORT_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_FROID_CONFORT_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_FROID_ZOOM_L108XH71_ID);
			//
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_1, 6, "%.1f", ((float) sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Reduit) - 200);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_2, 6, "%.1f", ((float) sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Confort) - 200);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_3, 6, "%.1f", ((float) sConfig_IHM.sMode_RegulExt.i16Consigne_Eau_Confort) - 200);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_REGUL_EXT_RAFRAICHISSEMENT_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_PISCINE:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ZOOM_L108XH71_ID);
			//
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_1, 5, "%.1f", ((float) sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_2, 5, "%.1f", ((float) sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_3, 5, "%.1f", ((float) sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal) / 10);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_PISCINE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_ECS:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUFFE_EAU_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUFFE_EAU_ON_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_CONFORT_PLUS_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_CONFORT_PLUS_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUFFE_EAU_ZOOM_L108XH71_ID);
			//
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_1, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_2, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_3, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_ECS_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_PISCINE_CONFORT:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_REDUIT_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_CONFORT_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_REDUIT_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_CONFORT_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ZOOM_L108XH71_ID);
			//
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_1, 5, "%.1f", ((float) sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_2, 5, "%.1f", ((float) sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal) / 10);
			Unicode::snprintfFloat(textAreaBuffer_Temp_Affichee_3, 5, "%.1f", ((float) sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort) / 10);
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_PISCINE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_OPTION:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_PISCINE_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ON_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_PISCINE_ZOOM_L108XH71_ID);
			//
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_1, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_2, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_3, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_BOUCLAGE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
		case PRO_SILENCE:
			// Definition des images
			image1 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUFFE_EAU_L8XH46_ID);
			image2 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			image3 = touchgfx::Bitmap(BITMAP_BARRE_PROG_HEBDO_CHAUD_CONFORT_PLUS_L8XH46_ID);
			//
			bouton1 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUFFE_EAU_ON_L108XH71_ID);
			bouton2 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_CONFORT_PLUS_L108XH71_ID);
			bouton3 = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUD_CONFORT_PLUS_L108XH71_ID);
			bouton_mixte = touchgfx::Bitmap(BITMAP_BOUTON_PROG_CHAUFFE_EAU_ZOOM_L108XH71_ID);
			//
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_1, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_2, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			Unicode::snprintf(textAreaBuffer_Temp_Affichee_3, 5, touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT).getText());
			// Titre
			Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PROG_SILENCE_CENTRE_DEFAUT).getText());
			barre_titre.titre(textAreaBuffer_Titre);
			break;
	}
	//
	buttonWithLabel_zoom_moins.setVisible(false);
	buttonWithLabel_zoom_plus.setVisible(true);
	slider_zoom_plus.setVisible(false);
	slider_zoom.setVisible(false);
	slider_zoom_rectangle.setVisible(false);
	slider_zoom_plus_rectangle.setVisible(false);
	slider_zoom_rectangle.setTouchable(false);
	slider_zoom_plus_rectangle.setTouchable(false);
	u8NiveauZoom = 0;
	majTexteHeures(0);
	u8Prog_bouton[0] = 0;
	u8Prog_bouton[1] = 0;
	u8Prog_bouton[2] = 0;
	u8Prog_bouton[3] = 0;
	u8Prog_bouton[4] = 0;
	u8Prog_bouton[5] = 0;
	//
	switch(u8JourProg)
	{
		case 0:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_LUNDI_PROG_EDIT_LEFT_DEFAUT));
			break;
		case 1:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_MARDI_PROG_EDIT_LEFT_DEFAUT));
			break;
		case 2:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_MERCREDI_PROG_EDIT_LEFT_DEFAUT));
			break;
		case 3:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_JEUDI_PROG_EDIT_LEFT_DEFAUT));
			break;
		case 4:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_VENDREDI_PROG_EDIT_LEFT_DEFAUT));
			break;
		case 5:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_SAMEDI_PROG_EDIT_LEFT_DEFAUT));
			break;
		case 6:
			textArea_jour.setTypedText(touchgfx::TypedText(T_TEXT_DIMANCHE_PROG_EDIT_LEFT_DEFAUT));
			break;
	}
	// Affichage de la barre des heures
	container_jour.setVisible(true);
	container_jour.setPosition(15, 370, 768, 46);
	for(int i = 0; i < 24; i++)
	{
		for(int k = 0; k < 4; k++)
		{
			switch((u8Prog_jour[i] >> (k * 2)) & 0x3)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						image_prog[i * 4 + k].setBitmap(image1);
					}
					else image_prog[i * 4 + k].setBitmap(image_off);
					break;
				case 1:
					image_prog[i * 4 + k].setBitmap(image1);
					break;
				case 2:
					image_prog[i * 4 + k].setBitmap(image2);
					break;
				case 3:
					image_prog[i * 4 + k].setBitmap(image3);
					break;
			}
			image_prog[i * 4 + k].setXY((i * 4 + k) * 8, 0);
			image_prog[i * 4 + k].setVisible(true);
			container_jour.add(image_prog[i * 4 + k]);
		}
	}
	container.add(container_jour);
	//
	container.remove(slider_zoom_plus_rectangle);
	container.add(slider_zoom_plus_rectangle);
	container.remove(slider_zoom_rectangle);
	container.add(slider_zoom_rectangle);
	container.remove(container_barre_heure_1);
	container.add(container_barre_heure_1);
	container.remove(textArea_jour);
	container.add(textArea_jour);
	// Affichage des boutons
	for(int i = 0; i < 6; i++)
	{
		u8Tmp = u8Prog_jour[i * 4];
		for(int j = 1; j < 4; j++)
		{
			if(u8Tmp == u8Prog_jour[i * 4 + j])
			{
				if(j == 3)
				{
					u8Prog_bouton[i] = u8Prog_jour[i * 4] & 0x3;
					boutonProg(i + 1, u8Prog_jour[i * 4] & 0x3);
				}
			}
			else
			{
				u8Prog_bouton[i] = 0;
				boutonProg(i + 1, 4);
				break;
			}
		}
	}
}

void Programmation_zoomView::setupScreen()
{
    Programmation_zoomViewBase::setupScreen();
}

void Programmation_zoomView::tearDownScreen()
{
    Programmation_zoomViewBase::tearDownScreen();
}

void Programmation_zoomView::bouton_plus()
{
	u8NiveauZoom++;
	buttonWithLabel_zoom_moins.setVisible(true);
	buttonWithLabel_zoom_moins.invalidate();
	if(u8NiveauZoom == 1)
	{
		majTexteHeures(0);
		slider_zoom.setValue(0);
		slider_zoom.setVisible(true);
		slider_zoom.invalidate();
		slider_zoom_plus.setVisible(false);
		slider_zoom_plus.invalidate();
		slider_zoom_rectangle.setValue(0);
		slider_zoom_rectangle.setVisible(true);
		slider_zoom_rectangle.invalidate();
		slider_zoom_plus_rectangle.setVisible(false);
		slider_zoom_plus_rectangle.invalidate();
	}
	else
	{
		u8NiveauZoom = 2;
		majTexteHeures(0);
		slider_zoom.setVisible(false);
		slider_zoom.invalidate();
		slider_zoom_plus.setValue(0);
		slider_zoom_plus.setVisible(true);
		slider_zoom_plus.invalidate();
		slider_zoom_rectangle.setVisible(false);
		slider_zoom_rectangle.invalidate();
		slider_zoom_plus_rectangle.setValue(0);
		slider_zoom_plus_rectangle.setVisible(true);
		slider_zoom_plus_rectangle.invalidate();
		buttonWithLabel_zoom_plus.setVisible(false);
		buttonWithLabel_zoom_plus.invalidate();
	}
}

void Programmation_zoomView::bouton_moins()
{
	uint8_t u8Tmp = 0;

	u8NiveauZoom--;
	buttonWithLabel_zoom_plus.setVisible(true);
	buttonWithLabel_zoom_plus.invalidate();
	if(u8NiveauZoom == 1)
	{
		majTexteHeures(0);
		slider_zoom.setValue(0);
		slider_zoom.setVisible(true);
		slider_zoom.invalidate();
		slider_zoom_plus.setVisible(false);
		slider_zoom_plus.invalidate();
		slider_zoom_rectangle.setValue(0);
		slider_zoom_rectangle.setVisible(true);
		slider_zoom_rectangle.invalidate();
		slider_zoom_plus_rectangle.setVisible(false);
		slider_zoom_plus_rectangle.invalidate();
	}
	else
	{
		u8NiveauZoom = 0;
		majTexteHeures(0);
		slider_zoom.setVisible(false);
		slider_zoom.invalidate();
		slider_zoom_plus.setValue(0);
		slider_zoom_plus.setVisible(false);
		slider_zoom_plus.invalidate();
		slider_zoom_rectangle.setVisible(false);
		slider_zoom_rectangle.invalidate();
		slider_zoom_plus_rectangle.setVisible(false);
		slider_zoom_plus_rectangle.invalidate();
		buttonWithLabel_zoom_moins.setVisible(false);
		buttonWithLabel_zoom_moins.invalidate();
		// Affichage des boutons
		for(int i = 0; i < 6; i++)
		{
			u8Tmp = u8Prog_jour[i * 4];
			for(int j = 1; j < 4; j++)
			{
				if(u8Tmp == u8Prog_jour[i * 4 + j])
				{
					if(j == 3)
					{
						u8Prog_bouton[i] = u8Prog_jour[i * 4] & 0x3;
						boutonProg(i + 1, u8Prog_jour[i * 4] & 0x3);
					}
				}
				else
				{
					u8Prog_bouton[i] = 0;
					boutonProg(i + 1, 4);
					break;
				}
			}
		}
	}
}

void Programmation_zoomView::slider_zoom_fonction(int slidervalue)
{
	slider_zoom_rectangle.setValue(slidervalue);
	slider_zoom_rectangle.invalidate();
	for(int i = 0; i < 6; i++)
	{
		if((u8Prog_jour[slidervalue + i] & 0x03) == ((u8Prog_jour[slidervalue + i] >> 2) & 0x03) &&
			(u8Prog_jour[slidervalue + i] & 0x03) == ((u8Prog_jour[slidervalue + i] >> 4) & 0x03) &&
			(u8Prog_jour[slidervalue + i] & 0x03) == ((u8Prog_jour[slidervalue + i] >> 6) & 0x03))
		{
			u8Prog_bouton[i] = u8Prog_jour[slidervalue + i] & 0x03;
			boutonProg(i + 1, u8Prog_jour[slidervalue + i] & 0x03);
		}
		else
		{
			u8Prog_bouton[i] = 0;
			boutonProg(i + 1, 4);
		}
	}
	majTexteHeures(slidervalue);
}

void Programmation_zoomView::slider_zoom_plus_fonction(int slidervalue)
{
	slider_zoom_plus_rectangle.setValue(slidervalue);
	slider_zoom_plus_rectangle.invalidate();
	u8Prog_bouton[0] = (u8Prog_jour[slidervalue / 4] >> ((slidervalue % 4) * 2)) & 0x03;
	boutonProg(1, (u8Prog_jour[slidervalue / 4] >> ((slidervalue % 4) * 2)) & 0x03);
	u8Prog_bouton[1] = (u8Prog_jour[(slidervalue + 1) / 4] >> (((slidervalue + 1) % 4) * 2)) & 0x03;
	boutonProg(2, (u8Prog_jour[(slidervalue + 1) / 4] >> (((slidervalue + 1) % 4) * 2)) & 0x03);
	u8Prog_bouton[2] = (u8Prog_jour[(slidervalue + 2) / 4] >> (((slidervalue + 2) % 4) * 2)) & 0x03;
	boutonProg(3, (u8Prog_jour[(slidervalue + 2) / 4] >> (((slidervalue + 2) % 4) * 2)) & 0x03);
	u8Prog_bouton[3] = (u8Prog_jour[(slidervalue + 3) / 4] >> (((slidervalue + 3) % 4) * 2)) & 0x03;
	boutonProg(4, (u8Prog_jour[(slidervalue + 3) / 4] >> (((slidervalue + 3) % 4) * 2)) & 0x03);
	u8Prog_bouton[4] = (u8Prog_jour[(slidervalue + 4) / 4] >> (((slidervalue + 4) % 4) * 2)) & 0x03;
	boutonProg(5, (u8Prog_jour[(slidervalue + 4) / 4] >> (((slidervalue + 4) % 4) * 2)) & 0x03);
	u8Prog_bouton[5] = (u8Prog_jour[(slidervalue + 5) / 4] >> (((slidervalue + 5) % 4) * 2)) & 0x03;
	boutonProg(6, (u8Prog_jour[(slidervalue + 5) / 4] >> (((slidervalue + 5) % 4) * 2)) & 0x03);
	majTexteHeures(slidervalue);
}

void Programmation_zoomView::majTexteHeures(uint8_t u8Origine)
{
	if(u8NiveauZoom == 0)
	{
	    Unicode::snprintf(textAreaBuffer_texte_1, 3, "0");
		textArea_prog_1.setWildcard(textAreaBuffer_texte_1);
		textArea_prog_1.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_2, 3, "4");
		textArea_prog_2.setWildcard(textAreaBuffer_texte_2);
		textArea_prog_2.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_3, 3, "8");
		textArea_prog_3.setWildcard(textAreaBuffer_texte_3);
		textArea_prog_3.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_4, 4, "12");
		textArea_prog_4.setWildcard(textAreaBuffer_texte_4);
		textArea_prog_4.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_5, 3, "16");
		textArea_prog_5.setWildcard(textAreaBuffer_texte_5);
		textArea_prog_5.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_6, 3, "20");
		textArea_prog_6.setWildcard(textAreaBuffer_texte_6);
		textArea_prog_6.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_7, 3, "24");
		textArea_prog_7.setWildcard(textAreaBuffer_texte_7);
		textArea_prog_7.invalidate();
	}
	else if(u8NiveauZoom == 1)
	{
	    Unicode::snprintf(textAreaBuffer_texte_1, 3, "%d", u8Origine);
		textArea_prog_1.setWildcard(textAreaBuffer_texte_1);
		textArea_prog_1.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_2, 3, "%d", u8Origine + 1);
		textArea_prog_2.setWildcard(textAreaBuffer_texte_2);
		textArea_prog_2.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_3, 3, "%d", u8Origine + 2);
		textArea_prog_3.setWildcard(textAreaBuffer_texte_3);
		textArea_prog_3.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_4, 4, "%d", u8Origine + 3);
		textArea_prog_4.setWildcard(textAreaBuffer_texte_4);
		textArea_prog_4.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_5, 3, "%d", u8Origine + 4);
		textArea_prog_5.setWildcard(textAreaBuffer_texte_5);
		textArea_prog_5.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_6, 3, "%d", u8Origine + 5);
		textArea_prog_6.setWildcard(textAreaBuffer_texte_6);
		textArea_prog_6.invalidate();
	    Unicode::snprintf(textAreaBuffer_texte_7, 3, "%d", u8Origine + 6);
		textArea_prog_7.setWildcard(textAreaBuffer_texte_7);
		textArea_prog_7.invalidate();
	}
	else
	{
		if(u8Origine % 4 == 0)
	    {
			Unicode::snprintf(textAreaBuffer_texte_1, 3, "%d", u8Origine / 4);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_1, 3, "");
		textArea_prog_1.setWildcard(textAreaBuffer_texte_1);
		textArea_prog_1.invalidate();
		if(u8Origine % 4 == 3)
	    {
		    Unicode::snprintf(textAreaBuffer_texte_2, 3, "%d", (u8Origine / 4) + 1);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_2, 3, "");
		textArea_prog_2.setWildcard(textAreaBuffer_texte_2);
		textArea_prog_2.invalidate();
		if(u8Origine % 4 == 2)
	    {
		    Unicode::snprintf(textAreaBuffer_texte_3, 3, "%d", (u8Origine / 4) + 1);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_3, 3, "");
		textArea_prog_3.setWildcard(textAreaBuffer_texte_3);
		textArea_prog_3.invalidate();
		if(u8Origine % 4 == 1)
	    {
		    Unicode::snprintf(textAreaBuffer_texte_4, 3, "%d", (u8Origine / 4) + 1);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_4, 3, "");
		textArea_prog_4.setWildcard(textAreaBuffer_texte_4);
		textArea_prog_4.invalidate();
		if(u8Origine % 4 == 0)
	    {
		    Unicode::snprintf(textAreaBuffer_texte_5, 3, "%d", (u8Origine / 4) + 1);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_5, 3, "");
		textArea_prog_5.setWildcard(textAreaBuffer_texte_5);
		textArea_prog_5.invalidate();
		if(u8Origine % 4 == 3)
	    {
		    Unicode::snprintf(textAreaBuffer_texte_6, 3, "%d", (u8Origine / 4) + 2);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_6, 3, "");
		textArea_prog_6.setWildcard(textAreaBuffer_texte_6);
		textArea_prog_6.invalidate();
		if(u8Origine % 4 == 2)
	    {
		    Unicode::snprintf(textAreaBuffer_texte_7, 3, "%d", (u8Origine / 4) + 2);
	    }
		else Unicode::snprintf(textAreaBuffer_texte_7, 3, "");
		textArea_prog_7.setWildcard(textAreaBuffer_texte_7);
		textArea_prog_7.invalidate();
	}
}

void Programmation_zoomView::bouton_valider()
{
	memcpy(u8Prog[u8JourProg], u8Prog_jour, sizeof(u8Prog_jour));
	application().gotoProgrammationScreenNoTransition();
}

void Programmation_zoomView::bouton_prog_1()
{
	editer_prog(0);
}

void Programmation_zoomView::bouton_prog_2()
{
	editer_prog(1);
}

void Programmation_zoomView::bouton_prog_3()
{
	editer_prog(2);
}

void Programmation_zoomView::bouton_prog_4()
{
	editer_prog(3);
}

void Programmation_zoomView::bouton_prog_5()
{
	editer_prog(4);
}

void Programmation_zoomView::bouton_prog_6()
{
	editer_prog(5);
}

void Programmation_zoomView::boutonProg(uint8_t u8NumeroProg,uint8_t u8Prog)
{
	switch(u8NumeroProg)
	{
		case 1:
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						Image_prog_1.setBitmap(bouton1);
						textArea_value_1.setVisible(false);
						textArea_value_temp_1.setVisible(true);

						textArea_value_1.setWildcard(textAreaBuffer_Temp_Affichee_1);
						textArea_value_temp_1.setWildcard(textAreaBuffer_Temp_Affichee_1);
					}
					else
					{
						Image_prog_1.setBitmap(bouton_off);
						textArea_value_1.setVisible(true);
						textArea_value_temp_1.setVisible(false);
						textArea_value_1.setWildcard(textAreaBuffer_Temp_Affichee_0);
						textArea_value_temp_1.setWildcard(textAreaBuffer_Temp_Affichee_0);
					}
					break;
				case 1:
					Image_prog_1.setBitmap(bouton1);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_1.setVisible(true);
						textArea_value_temp_1.setVisible(false);
					}
					else
					{
						textArea_value_1.setVisible(false);
						textArea_value_temp_1.setVisible(true);
					}
					textArea_value_1.setWildcard(textAreaBuffer_Temp_Affichee_1);
					textArea_value_temp_1.setWildcard(textAreaBuffer_Temp_Affichee_1);
					break;
				case 2:
					Image_prog_1.setBitmap(bouton2);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_1.setVisible(true);
						textArea_value_temp_1.setVisible(false);
					}
					else
					{
						textArea_value_1.setVisible(false);
						textArea_value_temp_1.setVisible(true);
					}
					textArea_value_1.setWildcard(textAreaBuffer_Temp_Affichee_2);
					textArea_value_temp_1.setWildcard(textAreaBuffer_Temp_Affichee_2);
					break;
				case 3:
					Image_prog_1.setBitmap(bouton3);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_1.setVisible(true);
						textArea_value_temp_1.setVisible(false);
					}
					else
					{
						textArea_value_1.setVisible(false);
						textArea_value_temp_1.setVisible(true);
					}
					textArea_value_1.setWildcard(textAreaBuffer_Temp_Affichee_3);
					textArea_value_temp_1.setWildcard(textAreaBuffer_Temp_Affichee_3);
					break;
				case 4:
					Image_prog_1.setBitmap(bouton_mixte);
					textArea_value_1.setVisible(false);
					textArea_value_temp_1.setVisible(false);
					break;
			}
			Image_prog_1.invalidate();
			textArea_value_1.invalidate();
			textArea_value_temp_1.invalidate();
			break;
		case 2:
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						Image_prog_2.setBitmap(bouton1);
						textArea_value_2.setVisible(false);
						textArea_value_temp_2.setVisible(true);

						textArea_value_2.setWildcard(textAreaBuffer_Temp_Affichee_1);
						textArea_value_temp_2.setWildcard(textAreaBuffer_Temp_Affichee_1);
					}
					else
					{
						Image_prog_2.setBitmap(bouton_off);
						textArea_value_2.setVisible(true);
						textArea_value_temp_2.setVisible(false);
						textArea_value_2.setWildcard(textAreaBuffer_Temp_Affichee_0);
						textArea_value_temp_2.setWildcard(textAreaBuffer_Temp_Affichee_0);
					}
					break;
				case 1:
					Image_prog_2.setBitmap(bouton1);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_2.setVisible(true);
						textArea_value_temp_2.setVisible(false);
					}
					else
					{
						textArea_value_2.setVisible(false);
						textArea_value_temp_2.setVisible(true);
					}
					textArea_value_2.setWildcard(textAreaBuffer_Temp_Affichee_1);
					textArea_value_temp_2.setWildcard(textAreaBuffer_Temp_Affichee_1);
					break;
				case 2:
					Image_prog_2.setBitmap(bouton2);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_2.setVisible(true);
						textArea_value_temp_2.setVisible(false);
					}
					else
					{
						textArea_value_2.setVisible(false);
						textArea_value_temp_2.setVisible(true);
					}
					textArea_value_2.setWildcard(textAreaBuffer_Temp_Affichee_2);
					textArea_value_temp_2.setWildcard(textAreaBuffer_Temp_Affichee_2);
					break;
				case 3:
					Image_prog_2.setBitmap(bouton3);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_2.setVisible(true);
						textArea_value_temp_2.setVisible(false);
					}
					else
					{
						textArea_value_2.setVisible(false);
						textArea_value_temp_2.setVisible(true);
					}
					textArea_value_2.setWildcard(textAreaBuffer_Temp_Affichee_3);
					textArea_value_temp_2.setWildcard(textAreaBuffer_Temp_Affichee_3);
					break;
				case 4:
					Image_prog_2.setBitmap(bouton_mixte);
					textArea_value_2.setVisible(false);
					textArea_value_temp_2.setVisible(false);
					break;
			}
			Image_prog_2.invalidate();
			textArea_value_2.invalidate();
			textArea_value_temp_2.invalidate();
			break;
		case 3:
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						Image_prog_3.setBitmap(bouton1);
						textArea_value_3.setVisible(false);
						textArea_value_temp_3.setVisible(true);

						textArea_value_3.setWildcard(textAreaBuffer_Temp_Affichee_1);
						textArea_value_temp_3.setWildcard(textAreaBuffer_Temp_Affichee_1);
					}
					else
					{
						Image_prog_3.setBitmap(bouton_off);
						textArea_value_3.setVisible(true);
						textArea_value_temp_3.setVisible(false);
						textArea_value_3.setWildcard(textAreaBuffer_Temp_Affichee_0);
						textArea_value_temp_3.setWildcard(textAreaBuffer_Temp_Affichee_0);
					}
					break;
				case 1:
					Image_prog_3.setBitmap(bouton1);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_3.setVisible(true);
						textArea_value_temp_3.setVisible(false);
					}
					else
					{
						textArea_value_3.setVisible(false);
						textArea_value_temp_3.setVisible(true);
					}
					textArea_value_3.setWildcard(textAreaBuffer_Temp_Affichee_1);
					textArea_value_temp_3.setWildcard(textAreaBuffer_Temp_Affichee_1);
					break;
				case 2:
					Image_prog_3.setBitmap(bouton2);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_3.setVisible(true);
						textArea_value_temp_3.setVisible(false);
					}
					else
					{
						textArea_value_3.setVisible(false);
						textArea_value_temp_3.setVisible(true);
					}
					textArea_value_3.setWildcard(textAreaBuffer_Temp_Affichee_2);
					textArea_value_temp_3.setWildcard(textAreaBuffer_Temp_Affichee_2);
					break;
				case 3:
					Image_prog_3.setBitmap(bouton3);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_3.setVisible(true);
						textArea_value_temp_3.setVisible(false);
					}
					else
					{
						textArea_value_3.setVisible(false);
						textArea_value_temp_3.setVisible(true);
					}
					textArea_value_3.setWildcard(textAreaBuffer_Temp_Affichee_3);
					textArea_value_temp_3.setWildcard(textAreaBuffer_Temp_Affichee_3);
					break;
				case 4:
					Image_prog_3.setBitmap(bouton_mixte);
					textArea_value_3.setVisible(false);
					textArea_value_temp_3.setVisible(false);
					break;
			}
			Image_prog_3.invalidate();
			textArea_value_3.invalidate();
			textArea_value_temp_3.invalidate();
			break;
		case 4:
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						Image_prog_4.setBitmap(bouton1);
						textArea_value_4.setVisible(false);
						textArea_value_temp_4.setVisible(true);

						textArea_value_4.setWildcard(textAreaBuffer_Temp_Affichee_1);
						textArea_value_temp_4.setWildcard(textAreaBuffer_Temp_Affichee_1);
					}
					else
					{
						Image_prog_4.setBitmap(bouton_off);
						textArea_value_4.setVisible(true);
						textArea_value_temp_4.setVisible(false);
						textArea_value_4.setWildcard(textAreaBuffer_Temp_Affichee_0);
						textArea_value_temp_4.setWildcard(textAreaBuffer_Temp_Affichee_0);
					}
					break;
				case 1:
					Image_prog_4.setBitmap(bouton1);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_4.setVisible(true);
						textArea_value_temp_4.setVisible(false);
					}
					else
					{
						textArea_value_4.setVisible(false);
						textArea_value_temp_4.setVisible(true);
					}
					textArea_value_4.setWildcard(textAreaBuffer_Temp_Affichee_1);
					textArea_value_temp_4.setWildcard(textAreaBuffer_Temp_Affichee_1);
					break;
				case 2:
					Image_prog_4.setBitmap(bouton2);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_4.setVisible(true);
						textArea_value_temp_4.setVisible(false);
					}
					else
					{
						textArea_value_4.setVisible(false);
						textArea_value_temp_4.setVisible(true);
					}
					textArea_value_4.setWildcard(textAreaBuffer_Temp_Affichee_2);
					textArea_value_temp_4.setWildcard(textAreaBuffer_Temp_Affichee_2);
					break;
				case 3:
					Image_prog_4.setBitmap(bouton3);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_4.setVisible(true);
						textArea_value_temp_4.setVisible(false);
					}
					else
					{
						textArea_value_4.setVisible(false);
						textArea_value_temp_4.setVisible(true);
					}
					textArea_value_4.setWildcard(textAreaBuffer_Temp_Affichee_3);
					textArea_value_temp_4.setWildcard(textAreaBuffer_Temp_Affichee_3);
					break;
				case 4:
					Image_prog_4.setBitmap(bouton_mixte);
					textArea_value_4.setVisible(false);
					textArea_value_temp_4.setVisible(false);
					break;
			}
			Image_prog_4.invalidate();
			textArea_value_4.invalidate();
			textArea_value_temp_4.invalidate();
			break;
		case 5:
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						Image_prog_5.setBitmap(bouton1);
						textArea_value_5.setVisible(false);
						textArea_value_temp_5.setVisible(true);

						textArea_value_5.setWildcard(textAreaBuffer_Temp_Affichee_1);
						textArea_value_temp_5.setWildcard(textAreaBuffer_Temp_Affichee_1);
					}
					else
					{
						Image_prog_5.setBitmap(bouton_off);
						textArea_value_5.setVisible(true);
						textArea_value_temp_5.setVisible(false);
						textArea_value_5.setWildcard(textAreaBuffer_Temp_Affichee_0);
						textArea_value_temp_5.setWildcard(textAreaBuffer_Temp_Affichee_0);
					}
					break;
				case 1:
					Image_prog_5.setBitmap(bouton1);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_5.setVisible(true);
						textArea_value_temp_5.setVisible(false);
					}
					else
					{
						textArea_value_5.setVisible(false);
						textArea_value_temp_5.setVisible(true);
					}
					textArea_value_5.setWildcard(textAreaBuffer_Temp_Affichee_1);
					textArea_value_temp_5.setWildcard(textAreaBuffer_Temp_Affichee_1);
					break;
				case 2:
					Image_prog_5.setBitmap(bouton2);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_5.setVisible(true);
						textArea_value_temp_5.setVisible(false);
					}
					else
					{
						textArea_value_5.setVisible(false);
						textArea_value_temp_5.setVisible(true);
					}
					textArea_value_5.setWildcard(textAreaBuffer_Temp_Affichee_2);
					textArea_value_temp_5.setWildcard(textAreaBuffer_Temp_Affichee_2);
					break;
				case 3:
					Image_prog_5.setBitmap(bouton3);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_5.setVisible(true);
						textArea_value_temp_5.setVisible(false);
					}
					else
					{
						textArea_value_5.setVisible(false);
						textArea_value_temp_5.setVisible(true);
					}
					textArea_value_5.setWildcard(textAreaBuffer_Temp_Affichee_3);
					textArea_value_temp_5.setWildcard(textAreaBuffer_Temp_Affichee_3);
					break;
				case 4:
					Image_prog_5.setBitmap(bouton_mixte);
					textArea_value_5.setVisible(false);
					textArea_value_temp_5.setVisible(false);
					break;
			}
			Image_prog_5.invalidate();
			textArea_value_5.invalidate();
			textArea_value_temp_5.invalidate();
			break;
		case 6:
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					if (eProg == PRO_PISCINE_CONFORT || eProg == PRO_CHAUD)
					{
						Image_prog_6.setBitmap(bouton1);
						textArea_value_6.setVisible(false);
						textArea_value_temp_6.setVisible(true);

						textArea_value_6.setWildcard(textAreaBuffer_Temp_Affichee_1);
						textArea_value_temp_6.setWildcard(textAreaBuffer_Temp_Affichee_1);
					}
					else
					{
						Image_prog_6.setBitmap(bouton_off);
						textArea_value_6.setVisible(true);
						textArea_value_temp_6.setVisible(false);
						textArea_value_6.setWildcard(textAreaBuffer_Temp_Affichee_0);
						textArea_value_temp_6.setWildcard(textAreaBuffer_Temp_Affichee_0);
					}
					break;
				case 1:
					Image_prog_6.setBitmap(bouton1);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_6.setVisible(true);
						textArea_value_temp_6.setVisible(false);
					}
					else
					{
						textArea_value_6.setVisible(false);
						textArea_value_temp_6.setVisible(true);
					}
					textArea_value_6.setWildcard(textAreaBuffer_Temp_Affichee_1);
					textArea_value_temp_6.setWildcard(textAreaBuffer_Temp_Affichee_1);
					break;
				case 2:
					Image_prog_6.setBitmap(bouton2);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_6.setVisible(true);
						textArea_value_temp_6.setVisible(false);
					}
					else
					{
						textArea_value_6.setVisible(false);
						textArea_value_temp_6.setVisible(true);
					}
					textArea_value_6.setWildcard(textAreaBuffer_Temp_Affichee_2);
					textArea_value_temp_6.setWildcard(textAreaBuffer_Temp_Affichee_2);
					break;
				case 3:
					Image_prog_6.setBitmap(bouton3);
					if(eProg == PRO_ECS || eProg == PRO_SILENCE)
					{
						textArea_value_6.setVisible(true);
						textArea_value_temp_6.setVisible(false);
					}
					else
					{
						textArea_value_6.setVisible(false);
						textArea_value_temp_6.setVisible(true);
					}
					textArea_value_6.setWildcard(textAreaBuffer_Temp_Affichee_3);
					textArea_value_temp_6.setWildcard(textAreaBuffer_Temp_Affichee_3);
					break;
				case 4:
					Image_prog_6.setBitmap(bouton_mixte);
					textArea_value_6.setVisible(false);
					textArea_value_temp_6.setVisible(false);
					break;
			}
			Image_prog_6.invalidate();
			textArea_value_6.invalidate();
			textArea_value_temp_6.invalidate();
			break;
	}
}


void Programmation_zoomView::editer_prog(uint8_t u8NumeroProg)//5
{
	// Modification de l'affichage
	if(eProg == PRO_CHAUD || eProg == PRO_EXT_CHAUD || eProg == PRO_PISCINE_CONFORT)	// NIVEAU 1 / NIVEAU 2 / NIVEAU 3
	{
		if((eProg == PRO_CHAUD || eProg == PRO_PISCINE_CONFORT) && u8Prog_bouton[u8NumeroProg] == 0)
		{
			u8Prog_bouton[u8NumeroProg] = 1;
		}
		if(++u8Prog_bouton[u8NumeroProg] > 3)
		{
			u8Prog_bouton[u8NumeroProg] = 1;
		}
	}
	else if(eProg == PRO_FROID || eProg == PRO_EXT_FROID)								// ON / NIVEAU 1 / NIVEAU 2
	{
		if(++u8Prog_bouton[u8NumeroProg] > 2)
		{
			u8Prog_bouton[u8NumeroProg] = 0;
		}
	}
	else if(eProg == PRO_PISCINE || eProg == PRO_OPTION || eProg == PRO_SILENCE)	// ON / OFF
	{
		if(++u8Prog_bouton[u8NumeroProg] > 1)
		{
			u8Prog_bouton[u8NumeroProg] = 0;
		}
	}
	else if(eProg == PRO_ECS)
	{
		if(++u8Prog_bouton[u8NumeroProg] > 1)
		{
			u8Prog_bouton[u8NumeroProg] = 0;
		}
	}
	boutonProg(u8NumeroProg + 1, u8Prog_bouton[u8NumeroProg]);
	// Mise à jour des progs
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = u8NumeroProg * 16; i < (16 + u8NumeroProg * 16); i++)
			{
				// Init du tableau de valeur
				if(eProg == PRO_ECS || eProg == PRO_SILENCE)
				{
					u8Prog_jour[i / 4] = u8Prog_jour[i / 4] & 0xAA;
					u8Prog_jour[i / 4] += (u8Prog_bouton[u8NumeroProg] + (u8Prog_bouton[u8NumeroProg] << 2) + (u8Prog_bouton[u8NumeroProg] << 4) + (u8Prog_bouton[u8NumeroProg] << 6)) & 0x55;
				}
				else u8Prog_jour[i / 4] = u8Prog_bouton[u8NumeroProg] + (u8Prog_bouton[u8NumeroProg] << 2) + (u8Prog_bouton[u8NumeroProg] << 4) + (u8Prog_bouton[u8NumeroProg] << 6);
			}
			break;
		case 1:
			for(int i = ((slider_zoom_rectangle.getValue() + u8NumeroProg) * 4); i < ((slider_zoom_rectangle.getValue() + u8NumeroProg) * 4) + 4; i++)
			{
				// Init du tableau de valeur
				if(eProg == PRO_ECS || eProg == PRO_SILENCE)
				{
					u8Prog_jour[i / 4] = u8Prog_jour[i / 4] & 0xAA;
					u8Prog_jour[i / 4] += (u8Prog_bouton[u8NumeroProg] + (u8Prog_bouton[u8NumeroProg] << 2) + (u8Prog_bouton[u8NumeroProg] << 4) + (u8Prog_bouton[u8NumeroProg] << 6)) & 0x55;
				}
				else u8Prog_jour[i / 4] = u8Prog_bouton[u8NumeroProg] + (u8Prog_bouton[u8NumeroProg] << 2) + (u8Prog_bouton[u8NumeroProg] << 4) + (u8Prog_bouton[u8NumeroProg] << 6);
			}
			break;
		case 2:
			// Init du tableau de valeur
			if(eProg == PRO_ECS || eProg == PRO_SILENCE)
			{

				u8Prog_jour[(slider_zoom_plus_rectangle.getValue() + u8NumeroProg) / 4] = (u8Prog_jour[(slider_zoom_plus_rectangle.getValue() + u8NumeroProg) / 4] & ~(0x01 << (((slider_zoom_plus_rectangle.getValue() + u8NumeroProg) % 4) * 2)));
				u8Prog_jour[(slider_zoom_plus_rectangle.getValue() + u8NumeroProg) / 4] += (u8Prog_bouton[u8NumeroProg] << (((slider_zoom_plus_rectangle.getValue() + u8NumeroProg) % 4) * 2));// & 0x01;//26/08/25
			}
			else
			{
				u8Prog_jour[(slider_zoom_plus_rectangle.getValue() + u8NumeroProg) / 4] = (u8Prog_jour[(slider_zoom_plus_rectangle.getValue() + u8NumeroProg) / 4] & ~(0x03 << (((slider_zoom_plus_rectangle.getValue() + u8NumeroProg) % 4) * 2)));
				u8Prog_jour[(slider_zoom_plus_rectangle.getValue() + u8NumeroProg) / 4] += (u8Prog_bouton[u8NumeroProg] << (((slider_zoom_plus_rectangle.getValue() + u8NumeroProg) % 4) * 2));
			}
			break;
	}
	// MAJ du graphique du bas
	for(int i = 0; i < 24; i++)
	{
		for(int k = 0; k < 4; k++)
		{
			switch((u8Prog_jour[i] >> (k * 2)) & 0x3)
			{
				case 0:
					if(eProg == PRO_CHAUD || eProg == PRO_PISCINE_CONFORT)
					{
						image_prog[i * 4 + k].setBitmap(image1);
					}
					else
					{
						image_prog[i * 4 + k].setBitmap(image_off);
					}
					break;
				case 1:
					image_prog[i * 4 + k].setBitmap(image1);
					break;
				case 2:
					image_prog[i * 4 + k].setBitmap(image2);
					break;
				case 3:
					image_prog[i * 4 + k].setBitmap(image3);
					break;
			}
		}
	}
	container_jour.invalidate();
}

void Programmation_zoomView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Programmation_zoomView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Programmation_zoomView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Programmation_zoomView::changeDate(S_DATE *sDate)
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
