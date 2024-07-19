#include <gui/programmation_zoom_screen/Programmation_zoomView.hpp>

Programmation_zoomView::Programmation_zoomView()
{
	uint8_t u8Tmp = 0;
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
	u8Prog_1 = 0;
//	Image_piscine_confort_1.setVisible(false);
//	Image_piscine_reduit_1.setVisible(false);
//	Image_off_1.setVisible(false);
//	Image_piscine_mixte_1.setVisible(true);
	u8Prog_2 = 0;
//	Image_piscine_confort_2.setVisible(false);
//	Image_piscine_reduit_2.setVisible(false);
//	Image_off_2.setVisible(false);
//	Image_piscine_mixte_2.setVisible(true);
	u8Prog_3 = 0;
//	Image_piscine_confort_3.setVisible(false);
//	Image_piscine_reduit_3.setVisible(false);
//	Image_off_3.setVisible(false);
//	Image_piscine_mixte_3.setVisible(true);
	u8Prog_4 = 0;
//	Image_piscine_confort_4.setVisible(false);
//	Image_piscine_reduit_4.setVisible(false);
//	Image_off_4.setVisible(false);
//	Image_piscine_mixte_4.setVisible(true);
	u8Prog_5 = 0;
//	Image_piscine_confort_5.setVisible(false);
//	Image_piscine_reduit_5.setVisible(false);
//	Image_off_5.setVisible(false);
//	Image_piscine_mixte_5.setVisible(true);
	u8Prog_6 = 0;
//	Image_piscine_confort_6.setVisible(false);
//	Image_piscine_reduit_6.setVisible(false);
//	Image_off_6.setVisible(false);
//	Image_piscine_mixte_6.setVisible(true);
	// Affichage des boutons
	for(int i = 0; i < 6; i++)
	{
		u8Tmp = u8ValeurProg[i * 16];
		for(int j = 1; j < 16; j++)
		{
			if(u8Tmp == u8ValeurProg[i * 16 + j])
			{
				if(j == 15)
				{
					boutonProg(i + 1, u8ValeurProg[i * 16]);
				}
			}
			else boutonProg(i + 1, 3);
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
			u8Tmp = u8ValeurProg[i * 16];
			for(int j = 1; j < 16; j++)
			{
				if(u8Tmp == u8ValeurProg[i * 16 + j])
				{
					if(j == 15)
					{
						boutonProg(i + 1, u8ValeurProg[i * 16]);
					}
				}
				else
				{
					boutonProg(i + 1, 3);
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
		if(u8ValeurProg[(slidervalue + i) * 4] == u8ValeurProg[(slidervalue + i) * 4 + 1] &&
			u8ValeurProg[(slidervalue + i) * 4] == u8ValeurProg[(slidervalue + i) * 4 + 2] &&
			u8ValeurProg[(slidervalue + i) * 4] == u8ValeurProg[(slidervalue + i) * 4 + 3])
		{
			boutonProg(i + 1, u8ValeurProg[(slidervalue + i) * 4]);
		}
		else boutonProg(i + 1, 3);
	}
	majTexteHeures(slidervalue);
}

void Programmation_zoomView::slider_zoom_plus_fonction(int slidervalue)
{
	slider_zoom_plus_rectangle.setValue(slidervalue);
	slider_zoom_plus_rectangle.invalidate();
	boutonProg(1, u8ValeurProg[slidervalue]);
	boutonProg(2, u8ValeurProg[slidervalue + 1]);
	boutonProg(3, u8ValeurProg[slidervalue + 2]);
	boutonProg(4, u8ValeurProg[slidervalue + 3]);
	boutonProg(5, u8ValeurProg[slidervalue + 4]);
	boutonProg(6, u8ValeurProg[slidervalue + 5]);
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

void Programmation_zoomView::bouton_prog_1()
{
	u8Prog_1++;
	// On masque tous les boutons
	Image_piscine_confort_1.setVisible(false);
	Image_piscine_confort_1.invalidate();
	Image_piscine_reduit_1.setVisible(false);
	Image_piscine_reduit_1.invalidate();
	Image_off_1.setVisible(false);
	Image_off_1.invalidate();
	Image_piscine_mixte_1.setVisible(false);
	Image_piscine_mixte_1.invalidate();
	// Affichage du bouton choisi
	switch(u8Prog_1)
	{
		case 1:
			Image_pisc_conf_1.setVisible(false);
			Image_pisc_conf_1.invalidate();
			break;
		case 2:
			Image_piscine_confort_1.setVisible(true);
			Image_piscine_confort_1.invalidate();
			break;
		default:
			u8Prog_1 = 0;
			Image_piscine_reduit_1.setVisible(true);
			Image_piscine_reduit_1.invalidate();
			break;
	}
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = 0; i < 16; i++)
			{
				editerProg(i + 1, u8Prog_1);
			}
			break;
		case 1:
			for(int i = (slider_zoom_rectangle.getValue() * 4); i < (slider_zoom_rectangle.getValue() * 4) + 4; i++)
			{
				editerProg(i + 1, u8Prog_1);
			}
			break;
		case 2:
			editerProg(slider_zoom_plus_rectangle.getValue() + 1, u8Prog_1);
			break;
	}
}

void Programmation_zoomView::bouton_prog_2()
{
	u8Prog_2++;
	// On masque tous les boutons
	Image_piscine_confort_2.setVisible(false);
	Image_piscine_confort_2.invalidate();
	Image_piscine_reduit_2.setVisible(false);
	Image_piscine_reduit_2.invalidate();
	Image_off_2.setVisible(false);
	Image_off_2.invalidate();
	Image_piscine_mixte_2.setVisible(false);
	Image_piscine_mixte_2.invalidate();
	// Affichage du bouton choisi
	switch(u8Prog_2)
	{
		case 1:
			Image_pisc_conf_2.setVisible(false);
			Image_pisc_conf_2.invalidate();
			break;
		case 2:
			Image_piscine_confort_2.setVisible(true);
			Image_piscine_confort_2.invalidate();
			break;
		default:
			u8Prog_2 = 0;
			Image_piscine_reduit_2.setVisible(true);
			Image_piscine_reduit_2.invalidate();
			break;
	}
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = 16; i < 32; i++)
			{
				editerProg(i + 1, u8Prog_2);
			}
			break;
		case 1:
			for(int i = ((slider_zoom_rectangle.getValue() + 1) * 4); i < ((slider_zoom_rectangle.getValue() + 1) * 4) + 4; i++)
			{
				editerProg(i + 1, u8Prog_2);
			}
			break;
		case 2:
			editerProg(slider_zoom_plus_rectangle.getValue() + 2, u8Prog_2);
			break;
	}
}

void Programmation_zoomView::bouton_prog_3()
{
	u8Prog_3++;
	// On masque tous les boutons
	Image_piscine_confort_3.setVisible(false);
	Image_piscine_confort_3.invalidate();
	Image_piscine_reduit_3.setVisible(false);
	Image_piscine_reduit_3.invalidate();
	Image_off_3.setVisible(false);
	Image_off_3.invalidate();
	Image_piscine_mixte_3.setVisible(false);
	Image_piscine_mixte_3.invalidate();
	// Affichage du bouton choisi
	switch(u8Prog_3)
	{
		case 1:
			Image_pisc_conf_3.setVisible(false);
			Image_pisc_conf_3.invalidate();
			break;
		case 2:
			Image_piscine_confort_3.setVisible(true);
			Image_piscine_confort_3.invalidate();
			break;
		default:
			u8Prog_3 = 0;
			Image_piscine_reduit_3.setVisible(true);
			Image_piscine_reduit_3.invalidate();
			break;
	}
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = 32; i < 48; i++)
			{
				editerProg(i + 1, u8Prog_3);
			}
			break;
		case 1:
			for(int i = ((slider_zoom_rectangle.getValue() + 2) * 4); i < ((slider_zoom_rectangle.getValue() + 2) * 4) + 4; i++)
			{
				editerProg(i + 1, u8Prog_3);
			}
			break;
		case 2:
			editerProg(slider_zoom_plus_rectangle.getValue() + 3, u8Prog_3);
			break;
	}
}

void Programmation_zoomView::bouton_prog_4()
{
	u8Prog_4++;
	// On masque tous les boutons
	Image_piscine_confort_4.setVisible(false);
	Image_piscine_confort_4.invalidate();
	Image_piscine_reduit_4.setVisible(false);
	Image_piscine_reduit_4.invalidate();
	Image_off_4.setVisible(false);
	Image_off_4.invalidate();
	Image_piscine_mixte_4.setVisible(false);
	Image_piscine_mixte_4.invalidate();
	// Affichage du bouton choisi
	switch(u8Prog_4)
	{
		case 1:
			Image_pisc_conf_4.setVisible(false);
			Image_pisc_conf_4.invalidate();
			break;
		case 2:
			Image_piscine_confort_4.setVisible(true);
			Image_piscine_confort_4.invalidate();
			break;
		default:
			u8Prog_4 = 0;
			Image_piscine_reduit_4.setVisible(true);
			Image_piscine_reduit_4.invalidate();
			break;
	}
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = 48; i < 64; i++)
			{
				editerProg(i + 1, u8Prog_4);
			}
			break;
		case 1:
			for(int i = ((slider_zoom_rectangle.getValue() + 3) * 4); i < ((slider_zoom_rectangle.getValue() + 3) * 4) + 4; i++)
			{
				editerProg(i + 1, u8Prog_4);
			}
			break;
		case 2:
			editerProg(slider_zoom_plus_rectangle.getValue() + 4, u8Prog_4);
			break;
	}
}

void Programmation_zoomView::bouton_prog_5()
{
	u8Prog_5++;
	// On masque tous les boutons
	Image_piscine_confort_5.setVisible(false);
	Image_piscine_confort_5.invalidate();
	Image_piscine_reduit_5.setVisible(false);
	Image_piscine_reduit_5.invalidate();
	Image_off_5.setVisible(false);
	Image_off_5.invalidate();
	Image_piscine_mixte_5.setVisible(false);
	Image_piscine_mixte_5.invalidate();
	// Affichage du bouton choisi
	switch(u8Prog_5)
	{
		case 1:
			Image_pisc_conf_5.setVisible(false);
			Image_pisc_conf_5.invalidate();
			break;
		case 2:
			Image_piscine_confort_5.setVisible(true);
			Image_piscine_confort_5.invalidate();
			break;
		default:
			u8Prog_5 = 0;
			Image_piscine_reduit_5.setVisible(true);
			Image_piscine_reduit_5.invalidate();
			break;
	}
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = 64; i < 80; i++)
			{
				editerProg(i + 1, u8Prog_5);
			}
			break;
		case 1:
			for(int i = ((slider_zoom_rectangle.getValue() + 4) * 4); i < ((slider_zoom_rectangle.getValue() + 4) * 4) + 4; i++)
			{
				editerProg(i + 1, u8Prog_5);
			}
			break;
		case 2:
			editerProg(slider_zoom_plus_rectangle.getValue() + 5, u8Prog_5);
			break;
	}
}

void Programmation_zoomView::bouton_prog_6()
{
	u8Prog_6++;
	// On masque tous les boutons
	Image_piscine_confort_6.setVisible(false);
	Image_piscine_confort_6.invalidate();
	Image_piscine_reduit_6.setVisible(false);
	Image_piscine_reduit_6.invalidate();
	Image_off_6.setVisible(false);
	Image_off_6.invalidate();
	Image_piscine_mixte_6.setVisible(false);
	Image_piscine_mixte_6.invalidate();
	// Affichage du bouton choisi
	switch(u8Prog_6)
	{
		case 1:
			Image_pisc_conf_6.setVisible(false);
			Image_pisc_conf_6.invalidate();
			break;
		case 2:
			Image_piscine_confort_6.setVisible(true);
			Image_piscine_confort_6.invalidate();
			break;
		default:
			u8Prog_6 = 0;
			Image_piscine_reduit_6.setVisible(true);
			Image_piscine_reduit_6.invalidate();
			break;
	}
	switch(u8NiveauZoom)
	{
		case 0:
			for(int i = 80; i < 96; i++)
			{
				editerProg(i + 1, u8Prog_6);
			}
			break;
		case 1:
			for(int i = ((slider_zoom_rectangle.getValue() + 5) * 4); i < ((slider_zoom_rectangle.getValue() + 5) * 4) + 4; i++)
			{
				editerProg(i + 1, u8Prog_6);
			}
			break;
		case 2:
			editerProg(slider_zoom_plus_rectangle.getValue() + 6, u8Prog_6);
			break;
	}
}

void Programmation_zoomView::boutonProg(uint8_t u8NumeroProg,uint8_t u8Prog)
{
	switch(u8NumeroProg)
	{
		case 1:
			// On masque tous les boutons
			Image_piscine_confort_1.setVisible(false);
			Image_piscine_confort_1.invalidate();
			Image_piscine_reduit_1.setVisible(false);
			Image_piscine_reduit_1.invalidate();
			Image_off_1.setVisible(false);
			Image_off_1.invalidate();
			Image_piscine_mixte_1.setVisible(false);
			Image_piscine_mixte_1.invalidate();
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					Image_piscine_reduit_1.setVisible(true);
					Image_piscine_reduit_1.invalidate();
					break;
				case 1:
					Image_pisc_conf_1.setVisible(false);
					Image_pisc_conf_1.invalidate();
					break;
				case 2:
					Image_piscine_confort_1.setVisible(true);
					Image_piscine_confort_1.invalidate();
					break;
				case 3:
					Image_piscine_mixte_1.setVisible(true);
					Image_piscine_mixte_1.invalidate();
					break;
			}
			break;
		case 2:
			// On masque tous les boutons
			Image_piscine_confort_2.setVisible(false);
			Image_piscine_confort_2.invalidate();
			Image_piscine_reduit_2.setVisible(false);
			Image_piscine_reduit_2.invalidate();
			Image_off_2.setVisible(false);
			Image_off_2.invalidate();
			Image_piscine_mixte_2.setVisible(false);
			Image_piscine_mixte_2.invalidate();
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					Image_piscine_reduit_2.setVisible(true);
					Image_piscine_reduit_2.invalidate();
					break;
				case 1:
					Image_pisc_conf_2.setVisible(false);
					Image_pisc_conf_2.invalidate();
					break;
				case 2:
					Image_piscine_confort_2.setVisible(true);
					Image_piscine_confort_2.invalidate();
					break;
				case 3:
					Image_piscine_mixte_2.setVisible(true);
					Image_piscine_mixte_2.invalidate();
					break;
			}
			break;
		case 3:
			// On masque tous les boutons
			Image_piscine_confort_3.setVisible(false);
			Image_piscine_confort_3.invalidate();
			Image_piscine_reduit_3.setVisible(false);
			Image_piscine_reduit_3.invalidate();
			Image_off_3.setVisible(false);
			Image_off_3.invalidate();
			Image_piscine_mixte_3.setVisible(false);
			Image_piscine_mixte_3.invalidate();
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					Image_piscine_reduit_3.setVisible(true);
					Image_piscine_reduit_3.invalidate();
					break;
				case 1:
					Image_pisc_conf_3.setVisible(false);
					Image_pisc_conf_3.invalidate();
					break;
				case 2:
					Image_piscine_confort_3.setVisible(true);
					Image_piscine_confort_3.invalidate();
					break;
				case 3:
					Image_piscine_mixte_3.setVisible(true);
					Image_piscine_mixte_3.invalidate();
					break;
			}
			break;
		case 4:
			// On masque tous les boutons
			Image_piscine_confort_4.setVisible(false);
			Image_piscine_confort_4.invalidate();
			Image_piscine_reduit_4.setVisible(false);
			Image_piscine_reduit_4.invalidate();
			Image_off_4.setVisible(false);
			Image_off_4.invalidate();
			Image_piscine_mixte_4.setVisible(false);
			Image_piscine_mixte_4.invalidate();
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					Image_piscine_reduit_4.setVisible(true);
					Image_piscine_reduit_4.invalidate();
					break;
				case 1:
					Image_pisc_conf_4.setVisible(false);
					Image_pisc_conf_4.invalidate();
					break;
				case 2:
					Image_piscine_confort_4.setVisible(true);
					Image_piscine_confort_4.invalidate();
					break;
				case 3:
					Image_piscine_mixte_4.setVisible(true);
					Image_piscine_mixte_4.invalidate();
					break;
			}
			break;
		case 5:
			// On masque tous les boutons
			Image_piscine_confort_5.setVisible(false);
			Image_piscine_confort_5.invalidate();
			Image_piscine_reduit_5.setVisible(false);
			Image_piscine_reduit_5.invalidate();
			Image_off_5.setVisible(false);
			Image_off_5.invalidate();
			Image_piscine_mixte_5.setVisible(false);
			Image_piscine_mixte_5.invalidate();
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					Image_piscine_reduit_5.setVisible(true);
					Image_piscine_reduit_5.invalidate();
					break;
				case 1:
					Image_pisc_conf_5.setVisible(false);
					Image_pisc_conf_5.invalidate();
					break;
				case 2:
					Image_piscine_confort_5.setVisible(true);
					Image_piscine_confort_5.invalidate();
					break;
				case 3:
					Image_piscine_mixte_5.setVisible(true);
					Image_piscine_mixte_5.invalidate();
					break;
			}
			break;
		case 6:
			// On masque tous les boutons
			Image_piscine_confort_6.setVisible(false);
			Image_piscine_confort_6.invalidate();
			Image_piscine_reduit_6.setVisible(false);
			Image_piscine_reduit_6.invalidate();
			Image_off_6.setVisible(false);
			Image_off_6.invalidate();
			Image_piscine_mixte_6.setVisible(false);
			Image_piscine_mixte_6.invalidate();
			// Affichage du bouton choisi
			switch(u8Prog)
			{
				case 0:
					Image_piscine_reduit_6.setVisible(true);
					Image_piscine_reduit_6.invalidate();
					break;
				case 1:
					Image_pisc_conf_6.setVisible(false);
					Image_pisc_conf_6.invalidate();
					break;
				case 2:
					Image_piscine_confort_6.setVisible(true);
					Image_piscine_confort_6.invalidate();
					break;
				case 3:
					Image_piscine_mixte_6.setVisible(true);
					Image_piscine_mixte_6.invalidate();
					break;
			}
			break;
	}
}

void Programmation_zoomView::editerProg(uint8_t u8NumeroProg,uint8_t u8Prog)
{
	u8ValeurProg[u8NumeroProg - 1] = u8Prog;
	switch(u8NumeroProg)
	{
		case 1 :
			Image_pisc_conf_1.setVisible(false);
			Image_pisc_conf_1.invalidate();
			Image_pisc_off_1.setVisible(false);
			Image_pisc_off_1.invalidate();
			Image_pisc_1.setVisible(false);
			Image_pisc_1.invalidate();
			Image_pisc_red_1.setVisible(false);
			Image_pisc_red_1.invalidate();
			switch(u8Prog)
			{
				case 1:
					Image_pisc_1.setVisible(true);
					Image_pisc_1.invalidate();
					break;
				case 2:
					Image_pisc_conf_1.setVisible(true);
					Image_pisc_conf_1.invalidate();
					break;
				default:
					Image_pisc_red_1.setVisible(true);
					Image_pisc_red_1.invalidate();
					break;
			}
			break;
		case 2 :
			Image_pisc_conf_2.setVisible(false);
			Image_pisc_conf_2.invalidate();
			Image_pisc_off_2.setVisible(false);
			Image_pisc_off_2.invalidate();
			Image_pisc_2.setVisible(false);
			Image_pisc_2.invalidate();
			Image_pisc_red_2.setVisible(false);
			Image_pisc_red_2.invalidate();
			switch(u8Prog)
			{
				case 1:
					Image_pisc_2.setVisible(true);
					Image_pisc_2.invalidate();
					break;
				case 2:
					Image_pisc_conf_2.setVisible(true);
					Image_pisc_conf_2.invalidate();
					break;
				default:
					Image_pisc_red_2.setVisible(true);
					Image_pisc_red_2.invalidate();
					break;
			}
			break;
		case 3 :
			Image_pisc_conf_3.setVisible(false);
			Image_pisc_conf_3.invalidate();
			Image_pisc_off_3.setVisible(false);
			Image_pisc_off_3.invalidate();
			Image_pisc_3.setVisible(false);
			Image_pisc_3.invalidate();
			Image_pisc_red_3.setVisible(false);
			Image_pisc_red_3.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_3.setVisible(true);
			        Image_pisc_3.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_3.setVisible(true);
			        Image_pisc_conf_3.invalidate();
			        break;
			    default:
			        Image_pisc_red_3.setVisible(true);
			        Image_pisc_red_3.invalidate();
			        break;
			}
			break;
		case 4 :
			Image_pisc_conf_4.setVisible(false);
			Image_pisc_conf_4.invalidate();
			Image_pisc_off_4.setVisible(false);
			Image_pisc_off_4.invalidate();
			Image_pisc_4.setVisible(false);
			Image_pisc_4.invalidate();
			Image_pisc_red_4.setVisible(false);
			Image_pisc_red_4.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_4.setVisible(true);
			        Image_pisc_4.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_4.setVisible(true);
			        Image_pisc_conf_4.invalidate();
			        break;
			    default:
			        Image_pisc_red_4.setVisible(true);
			        Image_pisc_red_4.invalidate();
			        break;
			}
			break;
		case 5 :
			Image_pisc_conf_5.setVisible(false);
			Image_pisc_conf_5.invalidate();
			Image_pisc_off_5.setVisible(false);
			Image_pisc_off_5.invalidate();
			Image_pisc_5.setVisible(false);
			Image_pisc_5.invalidate();
			Image_pisc_red_5.setVisible(false);
			Image_pisc_red_5.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_5.setVisible(true);
			        Image_pisc_5.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_5.setVisible(true);
			        Image_pisc_conf_5.invalidate();
			        break;
			    default:
			        Image_pisc_red_5.setVisible(true);
			        Image_pisc_red_5.invalidate();
			        break;
			}
			break;
		case 6 :
			Image_pisc_conf_6.setVisible(false);
			Image_pisc_conf_6.invalidate();
			Image_pisc_off_6.setVisible(false);
			Image_pisc_off_6.invalidate();
			Image_pisc_6.setVisible(false);
			Image_pisc_6.invalidate();
			Image_pisc_red_6.setVisible(false);
			Image_pisc_red_6.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_6.setVisible(true);
			        Image_pisc_6.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_6.setVisible(true);
			        Image_pisc_conf_6.invalidate();
			        break;
			    default:
			        Image_pisc_red_6.setVisible(true);
			        Image_pisc_red_6.invalidate();
			        break;
			}
			break;
		case 7 :
			Image_pisc_conf_7.setVisible(false);
			Image_pisc_conf_7.invalidate();
			Image_pisc_off_7.setVisible(false);
			Image_pisc_off_7.invalidate();
			Image_pisc_7.setVisible(false);
			Image_pisc_7.invalidate();
			Image_pisc_red_7.setVisible(false);
			Image_pisc_red_7.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_7.setVisible(true);
			        Image_pisc_7.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_7.setVisible(true);
			        Image_pisc_conf_7.invalidate();
			        break;
			    default:
			        Image_pisc_red_7.setVisible(true);
			        Image_pisc_red_7.invalidate();
			        break;
			}
			break;
		case 8 :
			Image_pisc_conf_8.setVisible(false);
			Image_pisc_conf_8.invalidate();
			Image_pisc_off_8.setVisible(false);
			Image_pisc_off_8.invalidate();
			Image_pisc_8.setVisible(false);
			Image_pisc_8.invalidate();
			Image_pisc_red_8.setVisible(false);
			Image_pisc_red_8.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_8.setVisible(true);
			        Image_pisc_8.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_8.setVisible(true);
			        Image_pisc_conf_8.invalidate();
			        break;
			    default:
			        Image_pisc_red_8.setVisible(true);
			        Image_pisc_red_8.invalidate();
			        break;
			}
			break;
		case 9 :
			Image_pisc_conf_9.setVisible(false);
			Image_pisc_conf_9.invalidate();
			Image_pisc_off_9.setVisible(false);
			Image_pisc_off_9.invalidate();
			Image_pisc_9.setVisible(false);
			Image_pisc_9.invalidate();
			Image_pisc_red_9.setVisible(false);
			Image_pisc_red_9.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_9.setVisible(true);
			        Image_pisc_9.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_9.setVisible(true);
			        Image_pisc_conf_9.invalidate();
			        break;
			    default:
			        Image_pisc_red_9.setVisible(true);
			        Image_pisc_red_9.invalidate();
			        break;
			}
			break;
		case 10 :
			Image_pisc_conf_10.setVisible(false);
			Image_pisc_conf_10.invalidate();
			Image_pisc_off_10.setVisible(false);
			Image_pisc_off_10.invalidate();
			Image_pisc_10.setVisible(false);
			Image_pisc_10.invalidate();
			Image_pisc_red_10.setVisible(false);
			Image_pisc_red_10.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_10.setVisible(true);
			        Image_pisc_10.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_10.setVisible(true);
			        Image_pisc_conf_10.invalidate();
			        break;
			    default:
			        Image_pisc_red_10.setVisible(true);
			        Image_pisc_red_10.invalidate();
			        break;
			}
			break;
		case 11 :
			Image_pisc_conf_11.setVisible(false);
			Image_pisc_conf_11.invalidate();
			Image_pisc_off_11.setVisible(false);
			Image_pisc_off_11.invalidate();
			Image_pisc_11.setVisible(false);
			Image_pisc_11.invalidate();
			Image_pisc_red_11.setVisible(false);
			Image_pisc_red_11.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_11.setVisible(true);
			        Image_pisc_11.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_11.setVisible(true);
			        Image_pisc_conf_11.invalidate();
			        break;
			    default:
			        Image_pisc_red_11.setVisible(true);
			        Image_pisc_red_11.invalidate();
			        break;
			}
			break;
		case 12 :
			Image_pisc_conf_12.setVisible(false);
			Image_pisc_conf_12.invalidate();
			Image_pisc_off_12.setVisible(false);
			Image_pisc_off_12.invalidate();
			Image_pisc_12.setVisible(false);
			Image_pisc_12.invalidate();
			Image_pisc_red_12.setVisible(false);
			Image_pisc_red_12.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_12.setVisible(true);
			        Image_pisc_12.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_12.setVisible(true);
			        Image_pisc_conf_12.invalidate();
			        break;
			    default:
			        Image_pisc_red_12.setVisible(true);
			        Image_pisc_red_12.invalidate();
			        break;
			}
			break;
		case 13 :
			Image_pisc_conf_13.setVisible(false);
			Image_pisc_conf_13.invalidate();
			Image_pisc_off_13.setVisible(false);
			Image_pisc_off_13.invalidate();
			Image_pisc_13.setVisible(false);
			Image_pisc_13.invalidate();
			Image_pisc_red_13.setVisible(false);
			Image_pisc_red_13.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_13.setVisible(true);
			        Image_pisc_13.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_13.setVisible(true);
			        Image_pisc_conf_13.invalidate();
			        break;
			    default:
			        Image_pisc_red_13.setVisible(true);
			        Image_pisc_red_13.invalidate();
			        break;
			}
			break;
		case 14 :
			Image_pisc_conf_14.setVisible(false);
			Image_pisc_conf_14.invalidate();
			Image_pisc_off_14.setVisible(false);
			Image_pisc_off_14.invalidate();
			Image_pisc_14.setVisible(false);
			Image_pisc_14.invalidate();
			Image_pisc_red_14.setVisible(false);
			Image_pisc_red_14.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_14.setVisible(true);
			        Image_pisc_14.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_14.setVisible(true);
			        Image_pisc_conf_14.invalidate();
			        break;
			    default:
			        Image_pisc_red_14.setVisible(true);
			        Image_pisc_red_14.invalidate();
			        break;
			}
			break;
		case 15 :
			Image_pisc_conf_15.setVisible(false);
			Image_pisc_conf_15.invalidate();
			Image_pisc_off_15.setVisible(false);
			Image_pisc_off_15.invalidate();
			Image_pisc_15.setVisible(false);
			Image_pisc_15.invalidate();
			Image_pisc_red_15.setVisible(false);
			Image_pisc_red_15.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_15.setVisible(true);
			        Image_pisc_15.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_15.setVisible(true);
			        Image_pisc_conf_15.invalidate();
			        break;
			    default:
			        Image_pisc_red_15.setVisible(true);
			        Image_pisc_red_15.invalidate();
			        break;
			}
			break;
		case 16 :
			Image_pisc_conf_16.setVisible(false);
			Image_pisc_conf_16.invalidate();
			Image_pisc_off_16.setVisible(false);
			Image_pisc_off_16.invalidate();
			Image_pisc_16.setVisible(false);
			Image_pisc_16.invalidate();
			Image_pisc_red_16.setVisible(false);
			Image_pisc_red_16.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_16.setVisible(true);
			        Image_pisc_16.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_16.setVisible(true);
			        Image_pisc_conf_16.invalidate();
			        break;
			    default:
			        Image_pisc_red_16.setVisible(true);
			        Image_pisc_red_16.invalidate();
			        break;
			}
			break;
		case 17 :
			Image_pisc_conf_17.setVisible(false);
			Image_pisc_conf_17.invalidate();
			Image_pisc_off_17.setVisible(false);
			Image_pisc_off_17.invalidate();
			Image_pisc_17.setVisible(false);
			Image_pisc_17.invalidate();
			Image_pisc_red_17.setVisible(false);
			Image_pisc_red_17.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_17.setVisible(true);
			        Image_pisc_17.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_17.setVisible(true);
			        Image_pisc_conf_17.invalidate();
			        break;
			    default:
			        Image_pisc_red_17.setVisible(true);
			        Image_pisc_red_17.invalidate();
			        break;
			}
			break;
		case 18 :
			Image_pisc_conf_18.setVisible(false);
			Image_pisc_conf_18.invalidate();
			Image_pisc_off_18.setVisible(false);
			Image_pisc_off_18.invalidate();
			Image_pisc_18.setVisible(false);
			Image_pisc_18.invalidate();
			Image_pisc_red_18.setVisible(false);
			Image_pisc_red_18.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_18.setVisible(true);
			        Image_pisc_18.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_18.setVisible(true);
			        Image_pisc_conf_18.invalidate();
			        break;
			    default:
			        Image_pisc_red_18.setVisible(true);
			        Image_pisc_red_18.invalidate();
			        break;
			}
			break;
		case 19 :
			Image_pisc_conf_19.setVisible(false);
			Image_pisc_conf_19.invalidate();
			Image_pisc_off_19.setVisible(false);
			Image_pisc_off_19.invalidate();
			Image_pisc_19.setVisible(false);
			Image_pisc_19.invalidate();
			Image_pisc_red_19.setVisible(false);
			Image_pisc_red_19.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_19.setVisible(true);
			        Image_pisc_19.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_19.setVisible(true);
			        Image_pisc_conf_19.invalidate();
			        break;
			    default:
			        Image_pisc_red_19.setVisible(true);
			        Image_pisc_red_19.invalidate();
			        break;
			}
			break;
		case 20 :
			Image_pisc_conf_20.setVisible(false);
			Image_pisc_conf_20.invalidate();
			Image_pisc_off_20.setVisible(false);
			Image_pisc_off_20.invalidate();
			Image_pisc_20.setVisible(false);
			Image_pisc_20.invalidate();
			Image_pisc_red_20.setVisible(false);
			Image_pisc_red_20.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_20.setVisible(true);
			        Image_pisc_20.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_20.setVisible(true);
			        Image_pisc_conf_20.invalidate();
			        break;
			    default:
			        Image_pisc_red_20.setVisible(true);
			        Image_pisc_red_20.invalidate();
			        break;
			}
			break;
		case 21 :
			Image_pisc_conf_21.setVisible(false);
			Image_pisc_conf_21.invalidate();
			Image_pisc_off_21.setVisible(false);
			Image_pisc_off_21.invalidate();
			Image_pisc_21.setVisible(false);
			Image_pisc_21.invalidate();
			Image_pisc_red_21.setVisible(false);
			Image_pisc_red_21.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_21.setVisible(true);
			        Image_pisc_21.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_21.setVisible(true);
			        Image_pisc_conf_21.invalidate();
			        break;
			    default:
			        Image_pisc_red_21.setVisible(true);
			        Image_pisc_red_21.invalidate();
			        break;
			}
			break;
		case 22 :
			Image_pisc_conf_22.setVisible(false);
			Image_pisc_conf_22.invalidate();
			Image_pisc_off_22.setVisible(false);
			Image_pisc_off_22.invalidate();
			Image_pisc_22.setVisible(false);
			Image_pisc_22.invalidate();
			Image_pisc_red_22.setVisible(false);
			Image_pisc_red_22.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_22.setVisible(true);
			        Image_pisc_22.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_22.setVisible(true);
			        Image_pisc_conf_22.invalidate();
			        break;
			    default:
			        Image_pisc_red_22.setVisible(true);
			        Image_pisc_red_22.invalidate();
			        break;
			}
			break;
		case 23 :
			Image_pisc_conf_23.setVisible(false);
			Image_pisc_conf_23.invalidate();
			Image_pisc_off_23.setVisible(false);
			Image_pisc_off_23.invalidate();
			Image_pisc_23.setVisible(false);
			Image_pisc_23.invalidate();
			Image_pisc_red_23.setVisible(false);
			Image_pisc_red_23.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_23.setVisible(true);
			        Image_pisc_23.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_23.setVisible(true);
			        Image_pisc_conf_23.invalidate();
			        break;
			    default:
			        Image_pisc_red_23.setVisible(true);
			        Image_pisc_red_23.invalidate();
			        break;
			}
			break;
		case 24 :
			Image_pisc_conf_24.setVisible(false);
			Image_pisc_conf_24.invalidate();
			Image_pisc_off_24.setVisible(false);
			Image_pisc_off_24.invalidate();
			Image_pisc_24.setVisible(false);
			Image_pisc_24.invalidate();
			Image_pisc_red_24.setVisible(false);
			Image_pisc_red_24.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_24.setVisible(true);
			        Image_pisc_24.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_24.setVisible(true);
			        Image_pisc_conf_24.invalidate();
			        break;
			    default:
			        Image_pisc_red_24.setVisible(true);
			        Image_pisc_red_24.invalidate();
			        break;
			}
			break;
		case 25 :
			Image_pisc_conf_25.setVisible(false);
			Image_pisc_conf_25.invalidate();
			Image_pisc_off_25.setVisible(false);
			Image_pisc_off_25.invalidate();
			Image_pisc_25.setVisible(false);
			Image_pisc_25.invalidate();
			Image_pisc_red_25.setVisible(false);
			Image_pisc_red_25.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_25.setVisible(true);
			        Image_pisc_25.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_25.setVisible(true);
			        Image_pisc_conf_25.invalidate();
			        break;
			    default:
			        Image_pisc_red_25.setVisible(true);
			        Image_pisc_red_25.invalidate();
			        break;
			}
			break;
		case 26 :
			Image_pisc_conf_26.setVisible(false);
			Image_pisc_conf_26.invalidate();
			Image_pisc_off_26.setVisible(false);
			Image_pisc_off_26.invalidate();
			Image_pisc_26.setVisible(false);
			Image_pisc_26.invalidate();
			Image_pisc_red_26.setVisible(false);
			Image_pisc_red_26.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_26.setVisible(true);
			        Image_pisc_26.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_26.setVisible(true);
			        Image_pisc_conf_26.invalidate();
			        break;
			    default:
			        Image_pisc_red_26.setVisible(true);
			        Image_pisc_red_26.invalidate();
			        break;
			}
			break;
		case 27 :
			Image_pisc_conf_27.setVisible(false);
			Image_pisc_conf_27.invalidate();
			Image_pisc_off_27.setVisible(false);
			Image_pisc_off_27.invalidate();
			Image_pisc_27.setVisible(false);
			Image_pisc_27.invalidate();
			Image_pisc_red_27.setVisible(false);
			Image_pisc_red_27.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_27.setVisible(true);
			        Image_pisc_27.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_27.setVisible(true);
			        Image_pisc_conf_27.invalidate();
			        break;
			    default:
			        Image_pisc_red_27.setVisible(true);
			        Image_pisc_red_27.invalidate();
			        break;
			}
			break;
		case 28 :
			Image_pisc_conf_28.setVisible(false);
			Image_pisc_conf_28.invalidate();
			Image_pisc_off_28.setVisible(false);
			Image_pisc_off_28.invalidate();
			Image_pisc_28.setVisible(false);
			Image_pisc_28.invalidate();
			Image_pisc_red_28.setVisible(false);
			Image_pisc_red_28.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_28.setVisible(true);
			        Image_pisc_28.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_28.setVisible(true);
			        Image_pisc_conf_28.invalidate();
			        break;
			    default:
			        Image_pisc_red_28.setVisible(true);
			        Image_pisc_red_28.invalidate();
			        break;
			}
			break;
		case 29 :
			Image_pisc_conf_29.setVisible(false);
			Image_pisc_conf_29.invalidate();
			Image_pisc_off_29.setVisible(false);
			Image_pisc_off_29.invalidate();
			Image_pisc_29.setVisible(false);
			Image_pisc_29.invalidate();
			Image_pisc_red_29.setVisible(false);
			Image_pisc_red_29.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_29.setVisible(true);
			        Image_pisc_29.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_29.setVisible(true);
			        Image_pisc_conf_29.invalidate();
			        break;
			    default:
			        Image_pisc_red_29.setVisible(true);
			        Image_pisc_red_29.invalidate();
			        break;
			}
			break;
		case 30 :
			Image_pisc_conf_30.setVisible(false);
			Image_pisc_conf_30.invalidate();
			Image_pisc_off_30.setVisible(false);
			Image_pisc_off_30.invalidate();
			Image_pisc_30.setVisible(false);
			Image_pisc_30.invalidate();
			Image_pisc_red_30.setVisible(false);
			Image_pisc_red_30.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_30.setVisible(true);
			        Image_pisc_30.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_30.setVisible(true);
			        Image_pisc_conf_30.invalidate();
			        break;
			    default:
			        Image_pisc_red_30.setVisible(true);
			        Image_pisc_red_30.invalidate();
			        break;
			}
			break;
		case 31 :
			Image_pisc_conf_31.setVisible(false);
			Image_pisc_conf_31.invalidate();
			Image_pisc_off_31.setVisible(false);
			Image_pisc_off_31.invalidate();
			Image_pisc_31.setVisible(false);
			Image_pisc_31.invalidate();
			Image_pisc_red_31.setVisible(false);
			Image_pisc_red_31.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_31.setVisible(true);
			        Image_pisc_31.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_31.setVisible(true);
			        Image_pisc_conf_31.invalidate();
			        break;
			    default:
			        Image_pisc_red_31.setVisible(true);
			        Image_pisc_red_31.invalidate();
			        break;
			}
			break;
		case 32 :
			Image_pisc_conf_32.setVisible(false);
			Image_pisc_conf_32.invalidate();
			Image_pisc_off_32.setVisible(false);
			Image_pisc_off_32.invalidate();
			Image_pisc_32.setVisible(false);
			Image_pisc_32.invalidate();
			Image_pisc_red_32.setVisible(false);
			Image_pisc_red_32.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_32.setVisible(true);
			        Image_pisc_32.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_32.setVisible(true);
			        Image_pisc_conf_32.invalidate();
			        break;
			    default:
			        Image_pisc_red_32.setVisible(true);
			        Image_pisc_red_32.invalidate();
			        break;
			}
			break;
		case 33 :
			Image_pisc_conf_33.setVisible(false);
			Image_pisc_conf_33.invalidate();
			Image_pisc_off_33.setVisible(false);
			Image_pisc_off_33.invalidate();
			Image_pisc_33.setVisible(false);
			Image_pisc_33.invalidate();
			Image_pisc_red_33.setVisible(false);
			Image_pisc_red_33.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_33.setVisible(true);
			        Image_pisc_33.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_33.setVisible(true);
			        Image_pisc_conf_33.invalidate();
			        break;
			    default:
			        Image_pisc_red_33.setVisible(true);
			        Image_pisc_red_33.invalidate();
			        break;
			}
			break;
		case 34 :
			Image_pisc_conf_34.setVisible(false);
			Image_pisc_conf_34.invalidate();
			Image_pisc_off_34.setVisible(false);
			Image_pisc_off_34.invalidate();
			Image_pisc_34.setVisible(false);
			Image_pisc_34.invalidate();
			Image_pisc_red_34.setVisible(false);
			Image_pisc_red_34.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_34.setVisible(true);
			        Image_pisc_34.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_34.setVisible(true);
			        Image_pisc_conf_34.invalidate();
			        break;
			    default:
			        Image_pisc_red_34.setVisible(true);
			        Image_pisc_red_34.invalidate();
			        break;
			}
			break;
		case 35 :
			Image_pisc_conf_35.setVisible(false);
			Image_pisc_conf_35.invalidate();
			Image_pisc_off_35.setVisible(false);
			Image_pisc_off_35.invalidate();
			Image_pisc_35.setVisible(false);
			Image_pisc_35.invalidate();
			Image_pisc_red_35.setVisible(false);
			Image_pisc_red_35.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_35.setVisible(true);
			        Image_pisc_35.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_35.setVisible(true);
			        Image_pisc_conf_35.invalidate();
			        break;
			    default:
			        Image_pisc_red_35.setVisible(true);
			        Image_pisc_red_35.invalidate();
			        break;
			}
			break;
		case 36 :
			Image_pisc_conf_36.setVisible(false);
			Image_pisc_conf_36.invalidate();
			Image_pisc_off_36.setVisible(false);
			Image_pisc_off_36.invalidate();
			Image_pisc_36.setVisible(false);
			Image_pisc_36.invalidate();
			Image_pisc_red_36.setVisible(false);
			Image_pisc_red_36.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_36.setVisible(true);
			        Image_pisc_36.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_36.setVisible(true);
			        Image_pisc_conf_36.invalidate();
			        break;
			    default:
			        Image_pisc_red_36.setVisible(true);
			        Image_pisc_red_36.invalidate();
			        break;
			}
			break;
		case 37 :
			Image_pisc_conf_37.setVisible(false);
			Image_pisc_conf_37.invalidate();
			Image_pisc_off_37.setVisible(false);
			Image_pisc_off_37.invalidate();
			Image_pisc_37.setVisible(false);
			Image_pisc_37.invalidate();
			Image_pisc_red_37.setVisible(false);
			Image_pisc_red_37.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_37.setVisible(true);
			        Image_pisc_37.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_37.setVisible(true);
			        Image_pisc_conf_37.invalidate();
			        break;
			    default:
			        Image_pisc_red_37.setVisible(true);
			        Image_pisc_red_37.invalidate();
			        break;
			}
			break;
		case 38 :
			Image_pisc_conf_38.setVisible(false);
			Image_pisc_conf_38.invalidate();
			Image_pisc_off_38.setVisible(false);
			Image_pisc_off_38.invalidate();
			Image_pisc_38.setVisible(false);
			Image_pisc_38.invalidate();
			Image_pisc_red_38.setVisible(false);
			Image_pisc_red_38.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_38.setVisible(true);
			        Image_pisc_38.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_38.setVisible(true);
			        Image_pisc_conf_38.invalidate();
			        break;
			    default:
			        Image_pisc_red_38.setVisible(true);
			        Image_pisc_red_38.invalidate();
			        break;
			}
			break;
		case 39 :
			Image_pisc_conf_39.setVisible(false);
			Image_pisc_conf_39.invalidate();
			Image_pisc_off_39.setVisible(false);
			Image_pisc_off_39.invalidate();
			Image_pisc_39.setVisible(false);
			Image_pisc_39.invalidate();
			Image_pisc_red_39.setVisible(false);
			Image_pisc_red_39.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_39.setVisible(true);
			        Image_pisc_39.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_39.setVisible(true);
			        Image_pisc_conf_39.invalidate();
			        break;
			    default:
			        Image_pisc_red_39.setVisible(true);
			        Image_pisc_red_39.invalidate();
			        break;
			}
			break;
		case 40 :
			Image_pisc_conf_40.setVisible(false);
			Image_pisc_conf_40.invalidate();
			Image_pisc_off_40.setVisible(false);
			Image_pisc_off_40.invalidate();
			Image_pisc_40.setVisible(false);
			Image_pisc_40.invalidate();
			Image_pisc_red_40.setVisible(false);
			Image_pisc_red_40.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_40.setVisible(true);
			        Image_pisc_40.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_40.setVisible(true);
			        Image_pisc_conf_40.invalidate();
			        break;
			    default:
			        Image_pisc_red_40.setVisible(true);
			        Image_pisc_red_40.invalidate();
			        break;
			}
			break;
		case 41 :
			Image_pisc_conf_41.setVisible(false);
			Image_pisc_conf_41.invalidate();
			Image_pisc_off_41.setVisible(false);
			Image_pisc_off_41.invalidate();
			Image_pisc_41.setVisible(false);
			Image_pisc_41.invalidate();
			Image_pisc_red_41.setVisible(false);
			Image_pisc_red_41.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_41.setVisible(true);
			        Image_pisc_41.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_41.setVisible(true);
			        Image_pisc_conf_41.invalidate();
			        break;
			    default:
			        Image_pisc_red_41.setVisible(true);
			        Image_pisc_red_41.invalidate();
			        break;
			}
			break;
		case 42 :
			Image_pisc_conf_42.setVisible(false);
			Image_pisc_conf_42.invalidate();
			Image_pisc_off_42.setVisible(false);
			Image_pisc_off_42.invalidate();
			Image_pisc_42.setVisible(false);
			Image_pisc_42.invalidate();
			Image_pisc_red_42.setVisible(false);
			Image_pisc_red_42.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_42.setVisible(true);
			        Image_pisc_42.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_42.setVisible(true);
			        Image_pisc_conf_42.invalidate();
			        break;
			    default:
			        Image_pisc_red_42.setVisible(true);
			        Image_pisc_red_42.invalidate();
			        break;
			}
			break;
		case 43 :
			Image_pisc_conf_43.setVisible(false);
			Image_pisc_conf_43.invalidate();
			Image_pisc_off_43.setVisible(false);
			Image_pisc_off_43.invalidate();
			Image_pisc_43.setVisible(false);
			Image_pisc_43.invalidate();
			Image_pisc_red_43.setVisible(false);
			Image_pisc_red_43.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_43.setVisible(true);
			        Image_pisc_43.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_43.setVisible(true);
			        Image_pisc_conf_43.invalidate();
			        break;
			    default:
			        Image_pisc_red_43.setVisible(true);
			        Image_pisc_red_43.invalidate();
			        break;
			}
			break;
		case 44 :
			Image_pisc_conf_44.setVisible(false);
			Image_pisc_conf_44.invalidate();
			Image_pisc_off_44.setVisible(false);
			Image_pisc_off_44.invalidate();
			Image_pisc_44.setVisible(false);
			Image_pisc_44.invalidate();
			Image_pisc_red_44.setVisible(false);
			Image_pisc_red_44.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_44.setVisible(true);
			        Image_pisc_44.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_44.setVisible(true);
			        Image_pisc_conf_44.invalidate();
			        break;
			    default:
			        Image_pisc_red_44.setVisible(true);
			        Image_pisc_red_44.invalidate();
			        break;
			}
			break;
		case 45 :
			Image_pisc_conf_45.setVisible(false);
			Image_pisc_conf_45.invalidate();
			Image_pisc_off_45.setVisible(false);
			Image_pisc_off_45.invalidate();
			Image_pisc_45.setVisible(false);
			Image_pisc_45.invalidate();
			Image_pisc_red_45.setVisible(false);
			Image_pisc_red_45.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_45.setVisible(true);
			        Image_pisc_45.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_45.setVisible(true);
			        Image_pisc_conf_45.invalidate();
			        break;
			    default:
			        Image_pisc_red_45.setVisible(true);
			        Image_pisc_red_45.invalidate();
			        break;
			}
			break;
		case 46 :
			Image_pisc_conf_46.setVisible(false);
			Image_pisc_conf_46.invalidate();
			Image_pisc_off_46.setVisible(false);
			Image_pisc_off_46.invalidate();
			Image_pisc_46.setVisible(false);
			Image_pisc_46.invalidate();
			Image_pisc_red_46.setVisible(false);
			Image_pisc_red_46.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_46.setVisible(true);
			        Image_pisc_46.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_46.setVisible(true);
			        Image_pisc_conf_46.invalidate();
			        break;
			    default:
			        Image_pisc_red_46.setVisible(true);
			        Image_pisc_red_46.invalidate();
			        break;
			}
			break;
		case 47 :
			Image_pisc_conf_47.setVisible(false);
			Image_pisc_conf_47.invalidate();
			Image_pisc_off_47.setVisible(false);
			Image_pisc_off_47.invalidate();
			Image_pisc_47.setVisible(false);
			Image_pisc_47.invalidate();
			Image_pisc_red_47.setVisible(false);
			Image_pisc_red_47.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_47.setVisible(true);
			        Image_pisc_47.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_47.setVisible(true);
			        Image_pisc_conf_47.invalidate();
			        break;
			    default:
			        Image_pisc_red_47.setVisible(true);
			        Image_pisc_red_47.invalidate();
			        break;
			}
			break;
		case 48 :
			Image_pisc_conf_48.setVisible(false);
			Image_pisc_conf_48.invalidate();
			Image_pisc_off_48.setVisible(false);
			Image_pisc_off_48.invalidate();
			Image_pisc_48.setVisible(false);
			Image_pisc_48.invalidate();
			Image_pisc_red_48.setVisible(false);
			Image_pisc_red_48.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_48.setVisible(true);
			        Image_pisc_48.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_48.setVisible(true);
			        Image_pisc_conf_48.invalidate();
			        break;
			    default:
			        Image_pisc_red_48.setVisible(true);
			        Image_pisc_red_48.invalidate();
			        break;
			}
			break;
		case 49 :
			Image_pisc_conf_49.setVisible(false);
			Image_pisc_conf_49.invalidate();
			Image_pisc_off_49.setVisible(false);
			Image_pisc_off_49.invalidate();
			Image_pisc_49.setVisible(false);
			Image_pisc_49.invalidate();
			Image_pisc_red_49.setVisible(false);
			Image_pisc_red_49.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_49.setVisible(true);
			        Image_pisc_49.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_49.setVisible(true);
			        Image_pisc_conf_49.invalidate();
			        break;
			    default:
			        Image_pisc_red_49.setVisible(true);
			        Image_pisc_red_49.invalidate();
			        break;
			}
			break;
		case 50 :
			Image_pisc_conf_50.setVisible(false);
			Image_pisc_conf_50.invalidate();
			Image_pisc_off_50.setVisible(false);
			Image_pisc_off_50.invalidate();
			Image_pisc_50.setVisible(false);
			Image_pisc_50.invalidate();
			Image_pisc_red_50.setVisible(false);
			Image_pisc_red_50.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_50.setVisible(true);
			        Image_pisc_50.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_50.setVisible(true);
			        Image_pisc_conf_50.invalidate();
			        break;
			    default:
			        Image_pisc_red_50.setVisible(true);
			        Image_pisc_red_50.invalidate();
			        break;
			}
			break;
		case 51 :
			Image_pisc_conf_51.setVisible(false);
			Image_pisc_conf_51.invalidate();
			Image_pisc_off_51.setVisible(false);
			Image_pisc_off_51.invalidate();
			Image_pisc_51.setVisible(false);
			Image_pisc_51.invalidate();
			Image_pisc_red_51.setVisible(false);
			Image_pisc_red_51.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_51.setVisible(true);
			        Image_pisc_51.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_51.setVisible(true);
			        Image_pisc_conf_51.invalidate();
			        break;
			    default:
			        Image_pisc_red_51.setVisible(true);
			        Image_pisc_red_51.invalidate();
			        break;
			}
			break;
		case 52 :
			Image_pisc_conf_52.setVisible(false);
			Image_pisc_conf_52.invalidate();
			Image_pisc_off_52.setVisible(false);
			Image_pisc_off_52.invalidate();
			Image_pisc_52.setVisible(false);
			Image_pisc_52.invalidate();
			Image_pisc_red_52.setVisible(false);
			Image_pisc_red_52.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_52.setVisible(true);
			        Image_pisc_52.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_52.setVisible(true);
			        Image_pisc_conf_52.invalidate();
			        break;
			    default:
			        Image_pisc_red_52.setVisible(true);
			        Image_pisc_red_52.invalidate();
			        break;
			}
			break;
		case 53 :
			Image_pisc_conf_53.setVisible(false);
			Image_pisc_conf_53.invalidate();
			Image_pisc_off_53.setVisible(false);
			Image_pisc_off_53.invalidate();
			Image_pisc_53.setVisible(false);
			Image_pisc_53.invalidate();
			Image_pisc_red_53.setVisible(false);
			Image_pisc_red_53.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_53.setVisible(true);
			        Image_pisc_53.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_53.setVisible(true);
			        Image_pisc_conf_53.invalidate();
			        break;
			    default:
			        Image_pisc_red_53.setVisible(true);
			        Image_pisc_red_53.invalidate();
			        break;
			}
			break;
		case 54 :
			Image_pisc_conf_54.setVisible(false);
			Image_pisc_conf_54.invalidate();
			Image_pisc_off_54.setVisible(false);
			Image_pisc_off_54.invalidate();
			Image_pisc_54.setVisible(false);
			Image_pisc_54.invalidate();
			Image_pisc_red_54.setVisible(false);
			Image_pisc_red_54.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_54.setVisible(true);
			        Image_pisc_54.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_54.setVisible(true);
			        Image_pisc_conf_54.invalidate();
			        break;
			    default:
			        Image_pisc_red_54.setVisible(true);
			        Image_pisc_red_54.invalidate();
			        break;
			}
			break;
		case 55 :
			Image_pisc_conf_55.setVisible(false);
			Image_pisc_conf_55.invalidate();
			Image_pisc_off_55.setVisible(false);
			Image_pisc_off_55.invalidate();
			Image_pisc_55.setVisible(false);
			Image_pisc_55.invalidate();
			Image_pisc_red_55.setVisible(false);
			Image_pisc_red_55.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_55.setVisible(true);
			        Image_pisc_55.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_55.setVisible(true);
			        Image_pisc_conf_55.invalidate();
			        break;
			    default:
			        Image_pisc_red_55.setVisible(true);
			        Image_pisc_red_55.invalidate();
			        break;
			}
			break;
		case 56 :
			Image_pisc_conf_56.setVisible(false);
			Image_pisc_conf_56.invalidate();
			Image_pisc_off_56.setVisible(false);
			Image_pisc_off_56.invalidate();
			Image_pisc_56.setVisible(false);
			Image_pisc_56.invalidate();
			Image_pisc_red_56.setVisible(false);
			Image_pisc_red_56.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_56.setVisible(true);
			        Image_pisc_56.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_56.setVisible(true);
			        Image_pisc_conf_56.invalidate();
			        break;
			    default:
			        Image_pisc_red_56.setVisible(true);
			        Image_pisc_red_56.invalidate();
			        break;
			}
			break;
		case 57 :
			Image_pisc_conf_57.setVisible(false);
			Image_pisc_conf_57.invalidate();
			Image_pisc_off_57.setVisible(false);
			Image_pisc_off_57.invalidate();
			Image_pisc_57.setVisible(false);
			Image_pisc_57.invalidate();
			Image_pisc_red_57.setVisible(false);
			Image_pisc_red_57.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_57.setVisible(true);
			        Image_pisc_57.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_57.setVisible(true);
			        Image_pisc_conf_57.invalidate();
			        break;
			    default:
			        Image_pisc_red_57.setVisible(true);
			        Image_pisc_red_57.invalidate();
			        break;
			}
			break;
		case 58 :
			Image_pisc_conf_58.setVisible(false);
			Image_pisc_conf_58.invalidate();
			Image_pisc_off_58.setVisible(false);
			Image_pisc_off_58.invalidate();
			Image_pisc_58.setVisible(false);
			Image_pisc_58.invalidate();
			Image_pisc_red_58.setVisible(false);
			Image_pisc_red_58.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_58.setVisible(true);
			        Image_pisc_58.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_58.setVisible(true);
			        Image_pisc_conf_58.invalidate();
			        break;
			    default:
			        Image_pisc_red_58.setVisible(true);
			        Image_pisc_red_58.invalidate();
			        break;
			}
			break;
		case 59 :
			Image_pisc_conf_59.setVisible(false);
			Image_pisc_conf_59.invalidate();
			Image_pisc_off_59.setVisible(false);
			Image_pisc_off_59.invalidate();
			Image_pisc_59.setVisible(false);
			Image_pisc_59.invalidate();
			Image_pisc_red_59.setVisible(false);
			Image_pisc_red_59.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_59.setVisible(true);
			        Image_pisc_59.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_59.setVisible(true);
			        Image_pisc_conf_59.invalidate();
			        break;
			    default:
			        Image_pisc_red_59.setVisible(true);
			        Image_pisc_red_59.invalidate();
			        break;
			}
			break;
		case 60 :
			Image_pisc_conf_60.setVisible(false);
			Image_pisc_conf_60.invalidate();
			Image_pisc_off_60.setVisible(false);
			Image_pisc_off_60.invalidate();
			Image_pisc_60.setVisible(false);
			Image_pisc_60.invalidate();
			Image_pisc_red_60.setVisible(false);
			Image_pisc_red_60.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_60.setVisible(true);
			        Image_pisc_60.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_60.setVisible(true);
			        Image_pisc_conf_60.invalidate();
			        break;
			    default:
			        Image_pisc_red_60.setVisible(true);
			        Image_pisc_red_60.invalidate();
			        break;
			}
			break;
		case 61 :
			Image_pisc_conf_61.setVisible(false);
			Image_pisc_conf_61.invalidate();
			Image_pisc_off_61.setVisible(false);
			Image_pisc_off_61.invalidate();
			Image_pisc_61.setVisible(false);
			Image_pisc_61.invalidate();
			Image_pisc_red_61.setVisible(false);
			Image_pisc_red_61.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_61.setVisible(true);
			        Image_pisc_61.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_61.setVisible(true);
			        Image_pisc_conf_61.invalidate();
			        break;
			    default:
			        Image_pisc_red_61.setVisible(true);
			        Image_pisc_red_61.invalidate();
			        break;
			}
			break;
		case 62 :
			Image_pisc_conf_62.setVisible(false);
			Image_pisc_conf_62.invalidate();
			Image_pisc_off_62.setVisible(false);
			Image_pisc_off_62.invalidate();
			Image_pisc_62.setVisible(false);
			Image_pisc_62.invalidate();
			Image_pisc_red_62.setVisible(false);
			Image_pisc_red_62.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_62.setVisible(true);
			        Image_pisc_62.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_62.setVisible(true);
			        Image_pisc_conf_62.invalidate();
			        break;
			    default:
			        Image_pisc_red_62.setVisible(true);
			        Image_pisc_red_62.invalidate();
			        break;
			}
			break;
		case 63 :
			Image_pisc_conf_63.setVisible(false);
			Image_pisc_conf_63.invalidate();
			Image_pisc_off_63.setVisible(false);
			Image_pisc_off_63.invalidate();
			Image_pisc_63.setVisible(false);
			Image_pisc_63.invalidate();
			Image_pisc_red_63.setVisible(false);
			Image_pisc_red_63.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_63.setVisible(true);
			        Image_pisc_63.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_63.setVisible(true);
			        Image_pisc_conf_63.invalidate();
			        break;
			    default:
			        Image_pisc_red_63.setVisible(true);
			        Image_pisc_red_63.invalidate();
			        break;
			}
			break;
		case 64 :
			Image_pisc_conf_64.setVisible(false);
			Image_pisc_conf_64.invalidate();
			Image_pisc_off_64.setVisible(false);
			Image_pisc_off_64.invalidate();
			Image_pisc_64.setVisible(false);
			Image_pisc_64.invalidate();
			Image_pisc_red_64.setVisible(false);
			Image_pisc_red_64.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_64.setVisible(true);
			        Image_pisc_64.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_64.setVisible(true);
			        Image_pisc_conf_64.invalidate();
			        break;
			    default:
			        Image_pisc_red_64.setVisible(true);
			        Image_pisc_red_64.invalidate();
			        break;
			}
			break;
		case 65 :
			Image_pisc_conf_65.setVisible(false);
			Image_pisc_conf_65.invalidate();
			Image_pisc_off_65.setVisible(false);
			Image_pisc_off_65.invalidate();
			Image_pisc_65.setVisible(false);
			Image_pisc_65.invalidate();
			Image_pisc_red_65.setVisible(false);
			Image_pisc_red_65.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_65.setVisible(true);
			        Image_pisc_65.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_65.setVisible(true);
			        Image_pisc_conf_65.invalidate();
			        break;
			    default:
			        Image_pisc_red_65.setVisible(true);
			        Image_pisc_red_65.invalidate();
			        break;
			}
			break;
		case 66 :
			Image_pisc_conf_66.setVisible(false);
			Image_pisc_conf_66.invalidate();
			Image_pisc_off_66.setVisible(false);
			Image_pisc_off_66.invalidate();
			Image_pisc_66.setVisible(false);
			Image_pisc_66.invalidate();
			Image_pisc_red_66.setVisible(false);
			Image_pisc_red_66.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_66.setVisible(true);
			        Image_pisc_66.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_66.setVisible(true);
			        Image_pisc_conf_66.invalidate();
			        break;
			    default:
			        Image_pisc_red_66.setVisible(true);
			        Image_pisc_red_66.invalidate();
			        break;
			}
			break;
		case 67 :
			Image_pisc_conf_67.setVisible(false);
			Image_pisc_conf_67.invalidate();
			Image_pisc_off_67.setVisible(false);
			Image_pisc_off_67.invalidate();
			Image_pisc_67.setVisible(false);
			Image_pisc_67.invalidate();
			Image_pisc_red_67.setVisible(false);
			Image_pisc_red_67.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_67.setVisible(true);
			        Image_pisc_67.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_67.setVisible(true);
			        Image_pisc_conf_67.invalidate();
			        break;
			    default:
			        Image_pisc_red_67.setVisible(true);
			        Image_pisc_red_67.invalidate();
			        break;
			}
			break;
		case 68 :
			Image_pisc_conf_68.setVisible(false);
			Image_pisc_conf_68.invalidate();
			Image_pisc_off_68.setVisible(false);
			Image_pisc_off_68.invalidate();
			Image_pisc_68.setVisible(false);
			Image_pisc_68.invalidate();
			Image_pisc_red_68.setVisible(false);
			Image_pisc_red_68.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_68.setVisible(true);
			        Image_pisc_68.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_68.setVisible(true);
			        Image_pisc_conf_68.invalidate();
			        break;
			    default:
			        Image_pisc_red_68.setVisible(true);
			        Image_pisc_red_68.invalidate();
			        break;
			}
			break;
		case 69 :
			Image_pisc_conf_69.setVisible(false);
			Image_pisc_conf_69.invalidate();
			Image_pisc_off_69.setVisible(false);
			Image_pisc_off_69.invalidate();
			Image_pisc_69.setVisible(false);
			Image_pisc_69.invalidate();
			Image_pisc_red_69.setVisible(false);
			Image_pisc_red_69.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_69.setVisible(true);
			        Image_pisc_69.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_69.setVisible(true);
			        Image_pisc_conf_69.invalidate();
			        break;
			    default:
			        Image_pisc_red_69.setVisible(true);
			        Image_pisc_red_69.invalidate();
			        break;
			}
			break;
		case 70 :
			Image_pisc_conf_70.setVisible(false);
			Image_pisc_conf_70.invalidate();
			Image_pisc_off_70.setVisible(false);
			Image_pisc_off_70.invalidate();
			Image_pisc_70.setVisible(false);
			Image_pisc_70.invalidate();
			Image_pisc_red_70.setVisible(false);
			Image_pisc_red_70.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_70.setVisible(true);
			        Image_pisc_70.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_70.setVisible(true);
			        Image_pisc_conf_70.invalidate();
			        break;
			    default:
			        Image_pisc_red_70.setVisible(true);
			        Image_pisc_red_70.invalidate();
			        break;
			}
			break;
		case 71 :
			Image_pisc_conf_71.setVisible(false);
			Image_pisc_conf_71.invalidate();
			Image_pisc_off_71.setVisible(false);
			Image_pisc_off_71.invalidate();
			Image_pisc_71.setVisible(false);
			Image_pisc_71.invalidate();
			Image_pisc_red_71.setVisible(false);
			Image_pisc_red_71.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_71.setVisible(true);
			        Image_pisc_71.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_71.setVisible(true);
			        Image_pisc_conf_71.invalidate();
			        break;
			    default:
			        Image_pisc_red_71.setVisible(true);
			        Image_pisc_red_71.invalidate();
			        break;
			}
			break;
		case 72 :
			Image_pisc_conf_72.setVisible(false);
			Image_pisc_conf_72.invalidate();
			Image_pisc_off_72.setVisible(false);
			Image_pisc_off_72.invalidate();
			Image_pisc_72.setVisible(false);
			Image_pisc_72.invalidate();
			Image_pisc_red_72.setVisible(false);
			Image_pisc_red_72.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_72.setVisible(true);
			        Image_pisc_72.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_72.setVisible(true);
			        Image_pisc_conf_72.invalidate();
			        break;
			    default:
			        Image_pisc_red_72.setVisible(true);
			        Image_pisc_red_72.invalidate();
			        break;
			}
			break;
		case 73 :
			Image_pisc_conf_73.setVisible(false);
			Image_pisc_conf_73.invalidate();
			Image_pisc_off_73.setVisible(false);
			Image_pisc_off_73.invalidate();
			Image_pisc_73.setVisible(false);
			Image_pisc_73.invalidate();
			Image_pisc_red_73.setVisible(false);
			Image_pisc_red_73.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_73.setVisible(true);
			        Image_pisc_73.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_73.setVisible(true);
			        Image_pisc_conf_73.invalidate();
			        break;
			    default:
			        Image_pisc_red_73.setVisible(true);
			        Image_pisc_red_73.invalidate();
			        break;
			}
			break;
		case 74 :
			Image_pisc_conf_74.setVisible(false);
			Image_pisc_conf_74.invalidate();
			Image_pisc_off_74.setVisible(false);
			Image_pisc_off_74.invalidate();
			Image_pisc_74.setVisible(false);
			Image_pisc_74.invalidate();
			Image_pisc_red_74.setVisible(false);
			Image_pisc_red_74.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_74.setVisible(true);
			        Image_pisc_74.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_74.setVisible(true);
			        Image_pisc_conf_74.invalidate();
			        break;
			    default:
			        Image_pisc_red_74.setVisible(true);
			        Image_pisc_red_74.invalidate();
			        break;
			}
			break;
		case 75 :
			Image_pisc_conf_75.setVisible(false);
			Image_pisc_conf_75.invalidate();
			Image_pisc_off_75.setVisible(false);
			Image_pisc_off_75.invalidate();
			Image_pisc_75.setVisible(false);
			Image_pisc_75.invalidate();
			Image_pisc_red_75.setVisible(false);
			Image_pisc_red_75.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_75.setVisible(true);
			        Image_pisc_75.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_75.setVisible(true);
			        Image_pisc_conf_75.invalidate();
			        break;
			    default:
			        Image_pisc_red_75.setVisible(true);
			        Image_pisc_red_75.invalidate();
			        break;
			}
			break;
		case 76 :
			Image_pisc_conf_76.setVisible(false);
			Image_pisc_conf_76.invalidate();
			Image_pisc_off_76.setVisible(false);
			Image_pisc_off_76.invalidate();
			Image_pisc_76.setVisible(false);
			Image_pisc_76.invalidate();
			Image_pisc_red_76.setVisible(false);
			Image_pisc_red_76.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_76.setVisible(true);
			        Image_pisc_76.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_76.setVisible(true);
			        Image_pisc_conf_76.invalidate();
			        break;
			    default:
			        Image_pisc_red_76.setVisible(true);
			        Image_pisc_red_76.invalidate();
			        break;
			}
			break;
		case 77 :
			Image_pisc_conf_77.setVisible(false);
			Image_pisc_conf_77.invalidate();
			Image_pisc_off_77.setVisible(false);
			Image_pisc_off_77.invalidate();
			Image_pisc_77.setVisible(false);
			Image_pisc_77.invalidate();
			Image_pisc_red_77.setVisible(false);
			Image_pisc_red_77.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_77.setVisible(true);
			        Image_pisc_77.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_77.setVisible(true);
			        Image_pisc_conf_77.invalidate();
			        break;
			    default:
			        Image_pisc_red_77.setVisible(true);
			        Image_pisc_red_77.invalidate();
			        break;
			}
			break;
		case 78 :
			Image_pisc_conf_78.setVisible(false);
			Image_pisc_conf_78.invalidate();
			Image_pisc_off_78.setVisible(false);
			Image_pisc_off_78.invalidate();
			Image_pisc_78.setVisible(false);
			Image_pisc_78.invalidate();
			Image_pisc_red_78.setVisible(false);
			Image_pisc_red_78.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_78.setVisible(true);
			        Image_pisc_78.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_78.setVisible(true);
			        Image_pisc_conf_78.invalidate();
			        break;
			    default:
			        Image_pisc_red_78.setVisible(true);
			        Image_pisc_red_78.invalidate();
			        break;
			}
			break;
		case 79 :
			Image_pisc_conf_79.setVisible(false);
			Image_pisc_conf_79.invalidate();
			Image_pisc_off_79.setVisible(false);
			Image_pisc_off_79.invalidate();
			Image_pisc_79.setVisible(false);
			Image_pisc_79.invalidate();
			Image_pisc_red_79.setVisible(false);
			Image_pisc_red_79.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_79.setVisible(true);
			        Image_pisc_79.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_79.setVisible(true);
			        Image_pisc_conf_79.invalidate();
			        break;
			    default:
			        Image_pisc_red_79.setVisible(true);
			        Image_pisc_red_79.invalidate();
			        break;
			}
			break;
		case 80 :
			Image_pisc_conf_80.setVisible(false);
			Image_pisc_conf_80.invalidate();
			Image_pisc_off_80.setVisible(false);
			Image_pisc_off_80.invalidate();
			Image_pisc_80.setVisible(false);
			Image_pisc_80.invalidate();
			Image_pisc_red_80.setVisible(false);
			Image_pisc_red_80.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_80.setVisible(true);
			        Image_pisc_80.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_80.setVisible(true);
			        Image_pisc_conf_80.invalidate();
			        break;
			    default:
			        Image_pisc_red_80.setVisible(true);
			        Image_pisc_red_80.invalidate();
			        break;
			}
			break;
		case 81 :
			Image_pisc_conf_81.setVisible(false);
			Image_pisc_conf_81.invalidate();
			Image_pisc_off_81.setVisible(false);
			Image_pisc_off_81.invalidate();
			Image_pisc_81.setVisible(false);
			Image_pisc_81.invalidate();
			Image_pisc_red_81.setVisible(false);
			Image_pisc_red_81.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_81.setVisible(true);
			        Image_pisc_81.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_81.setVisible(true);
			        Image_pisc_conf_81.invalidate();
			        break;
			    default:
			        Image_pisc_red_81.setVisible(true);
			        Image_pisc_red_81.invalidate();
			        break;
			}
			break;
		case 82 :
			Image_pisc_conf_82.setVisible(false);
			Image_pisc_conf_82.invalidate();
			Image_pisc_off_82.setVisible(false);
			Image_pisc_off_82.invalidate();
			Image_pisc_82.setVisible(false);
			Image_pisc_82.invalidate();
			Image_pisc_red_82.setVisible(false);
			Image_pisc_red_82.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_82.setVisible(true);
			        Image_pisc_82.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_82.setVisible(true);
			        Image_pisc_conf_82.invalidate();
			        break;
			    default:
			        Image_pisc_red_82.setVisible(true);
			        Image_pisc_red_82.invalidate();
			        break;
			}
			break;
		case 83 :
			Image_pisc_conf_83.setVisible(false);
			Image_pisc_conf_83.invalidate();
			Image_pisc_off_83.setVisible(false);
			Image_pisc_off_83.invalidate();
			Image_pisc_83.setVisible(false);
			Image_pisc_83.invalidate();
			Image_pisc_red_83.setVisible(false);
			Image_pisc_red_83.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_83.setVisible(true);
			        Image_pisc_83.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_83.setVisible(true);
			        Image_pisc_conf_83.invalidate();
			        break;
			    default:
			        Image_pisc_red_83.setVisible(true);
			        Image_pisc_red_83.invalidate();
			        break;
			}
			break;
		case 84 :
			Image_pisc_conf_84.setVisible(false);
			Image_pisc_conf_84.invalidate();
			Image_pisc_off_84.setVisible(false);
			Image_pisc_off_84.invalidate();
			Image_pisc_84.setVisible(false);
			Image_pisc_84.invalidate();
			Image_pisc_red_84.setVisible(false);
			Image_pisc_red_84.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_84.setVisible(true);
			        Image_pisc_84.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_84.setVisible(true);
			        Image_pisc_conf_84.invalidate();
			        break;
			    default:
			        Image_pisc_red_84.setVisible(true);
			        Image_pisc_red_84.invalidate();
			        break;
			}
			break;
		case 85 :
			Image_pisc_conf_85.setVisible(false);
			Image_pisc_conf_85.invalidate();
			Image_pisc_off_85.setVisible(false);
			Image_pisc_off_85.invalidate();
			Image_pisc_85.setVisible(false);
			Image_pisc_85.invalidate();
			Image_pisc_red_85.setVisible(false);
			Image_pisc_red_85.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_85.setVisible(true);
			        Image_pisc_85.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_85.setVisible(true);
			        Image_pisc_conf_85.invalidate();
			        break;
			    default:
			        Image_pisc_red_85.setVisible(true);
			        Image_pisc_red_85.invalidate();
			        break;
			}
			break;
		case 86 :
			Image_pisc_conf_86.setVisible(false);
			Image_pisc_conf_86.invalidate();
			Image_pisc_off_86.setVisible(false);
			Image_pisc_off_86.invalidate();
			Image_pisc_86.setVisible(false);
			Image_pisc_86.invalidate();
			Image_pisc_red_86.setVisible(false);
			Image_pisc_red_86.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_86.setVisible(true);
			        Image_pisc_86.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_86.setVisible(true);
			        Image_pisc_conf_86.invalidate();
			        break;
			    default:
			        Image_pisc_red_86.setVisible(true);
			        Image_pisc_red_86.invalidate();
			        break;
			}
			break;
		case 87 :
			Image_pisc_conf_87.setVisible(false);
			Image_pisc_conf_87.invalidate();
			Image_pisc_off_87.setVisible(false);
			Image_pisc_off_87.invalidate();
			Image_pisc_87.setVisible(false);
			Image_pisc_87.invalidate();
			Image_pisc_red_87.setVisible(false);
			Image_pisc_red_87.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_87.setVisible(true);
			        Image_pisc_87.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_87.setVisible(true);
			        Image_pisc_conf_87.invalidate();
			        break;
			    default:
			        Image_pisc_red_87.setVisible(true);
			        Image_pisc_red_87.invalidate();
			        break;
			}
			break;
		case 88 :
			Image_pisc_conf_88.setVisible(false);
			Image_pisc_conf_88.invalidate();
			Image_pisc_off_88.setVisible(false);
			Image_pisc_off_88.invalidate();
			Image_pisc_88.setVisible(false);
			Image_pisc_88.invalidate();
			Image_pisc_red_88.setVisible(false);
			Image_pisc_red_88.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_88.setVisible(true);
			        Image_pisc_88.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_88.setVisible(true);
			        Image_pisc_conf_88.invalidate();
			        break;
			    default:
			        Image_pisc_red_88.setVisible(true);
			        Image_pisc_red_88.invalidate();
			        break;
			}
			break;
		case 89 :
			Image_pisc_conf_89.setVisible(false);
			Image_pisc_conf_89.invalidate();
			Image_pisc_off_89.setVisible(false);
			Image_pisc_off_89.invalidate();
			Image_pisc_89.setVisible(false);
			Image_pisc_89.invalidate();
			Image_pisc_red_89.setVisible(false);
			Image_pisc_red_89.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_89.setVisible(true);
			        Image_pisc_89.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_89.setVisible(true);
			        Image_pisc_conf_89.invalidate();
			        break;
			    default:
			        Image_pisc_red_89.setVisible(true);
			        Image_pisc_red_89.invalidate();
			        break;
			}
			break;
		case 90 :
			Image_pisc_conf_90.setVisible(false);
			Image_pisc_conf_90.invalidate();
			Image_pisc_off_90.setVisible(false);
			Image_pisc_off_90.invalidate();
			Image_pisc_90.setVisible(false);
			Image_pisc_90.invalidate();
			Image_pisc_red_90.setVisible(false);
			Image_pisc_red_90.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_90.setVisible(true);
			        Image_pisc_90.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_90.setVisible(true);
			        Image_pisc_conf_90.invalidate();
			        break;
			    default:
			        Image_pisc_red_90.setVisible(true);
			        Image_pisc_red_90.invalidate();
			        break;
			}
			break;
		case 91 :
			Image_pisc_conf_91.setVisible(false);
			Image_pisc_conf_91.invalidate();
			Image_pisc_off_91.setVisible(false);
			Image_pisc_off_91.invalidate();
			Image_pisc_91.setVisible(false);
			Image_pisc_91.invalidate();
			Image_pisc_red_91.setVisible(false);
			Image_pisc_red_91.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_91.setVisible(true);
			        Image_pisc_91.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_91.setVisible(true);
			        Image_pisc_conf_91.invalidate();
			        break;
			    default:
			        Image_pisc_red_91.setVisible(true);
			        Image_pisc_red_91.invalidate();
			        break;
			}
			break;
		case 92 :
			Image_pisc_conf_92.setVisible(false);
			Image_pisc_conf_92.invalidate();
			Image_pisc_off_92.setVisible(false);
			Image_pisc_off_92.invalidate();
			Image_pisc_92.setVisible(false);
			Image_pisc_92.invalidate();
			Image_pisc_red_92.setVisible(false);
			Image_pisc_red_92.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_92.setVisible(true);
			        Image_pisc_92.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_92.setVisible(true);
			        Image_pisc_conf_92.invalidate();
			        break;
			    default:
			        Image_pisc_red_92.setVisible(true);
			        Image_pisc_red_92.invalidate();
			        break;
			}
			break;
		case 93 :
			Image_pisc_conf_93.setVisible(false);
			Image_pisc_conf_93.invalidate();
			Image_pisc_off_93.setVisible(false);
			Image_pisc_off_93.invalidate();
			Image_pisc_93.setVisible(false);
			Image_pisc_93.invalidate();
			Image_pisc_red_93.setVisible(false);
			Image_pisc_red_93.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_93.setVisible(true);
			        Image_pisc_93.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_93.setVisible(true);
			        Image_pisc_conf_93.invalidate();
			        break;
			    default:
			        Image_pisc_red_93.setVisible(true);
			        Image_pisc_red_93.invalidate();
			        break;
			}
			break;
		case 94 :
			Image_pisc_conf_94.setVisible(false);
			Image_pisc_conf_94.invalidate();
			Image_pisc_off_94.setVisible(false);
			Image_pisc_off_94.invalidate();
			Image_pisc_94.setVisible(false);
			Image_pisc_94.invalidate();
			Image_pisc_red_94.setVisible(false);
			Image_pisc_red_94.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_94.setVisible(true);
			        Image_pisc_94.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_94.setVisible(true);
			        Image_pisc_conf_94.invalidate();
			        break;
			    default:
			        Image_pisc_red_94.setVisible(true);
			        Image_pisc_red_94.invalidate();
			        break;
			}
			break;
		case 95 :
			Image_pisc_conf_95.setVisible(false);
			Image_pisc_conf_95.invalidate();
			Image_pisc_off_95.setVisible(false);
			Image_pisc_off_95.invalidate();
			Image_pisc_95.setVisible(false);
			Image_pisc_95.invalidate();
			Image_pisc_red_95.setVisible(false);
			Image_pisc_red_95.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_95.setVisible(true);
			        Image_pisc_95.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_95.setVisible(true);
			        Image_pisc_conf_95.invalidate();
			        break;
			    default:
			        Image_pisc_red_95.setVisible(true);
			        Image_pisc_red_95.invalidate();
			        break;
			}
			break;
		case 96 :
			Image_pisc_conf_96.setVisible(false);
			Image_pisc_conf_96.invalidate();
			Image_pisc_off_96.setVisible(false);
			Image_pisc_off_96.invalidate();
			Image_pisc_96.setVisible(false);
			Image_pisc_96.invalidate();
			Image_pisc_red_96.setVisible(false);
			Image_pisc_red_96.invalidate();
			switch(u8Prog)
			{
			    case 1:
			        Image_pisc_96.setVisible(true);
			        Image_pisc_96.invalidate();
			        break;
			    case 2:
			        Image_pisc_conf_96.setVisible(true);
			        Image_pisc_conf_96.invalidate();
			        break;
			    default:
			        Image_pisc_red_96.setVisible(true);
			        Image_pisc_red_96.invalidate();
			        break;
			}
			break;
	}
}
