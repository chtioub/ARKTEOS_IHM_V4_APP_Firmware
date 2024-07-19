#include <gui/installation_hydraulique_screen/Installation_hydrauliqueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_hydrauliqueView::Installation_hydrauliqueView()
{
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	barre_titre.titre(T_TEXT_CONFIG_INSTALL_HYDRAU_CENTRE_LARGE);
}

void Installation_hydrauliqueView::setupScreen()
{
    Installation_hydrauliqueViewBase::setupScreen();
}

void Installation_hydrauliqueView::tearDownScreen()
{
    Installation_hydrauliqueViewBase::tearDownScreen();
}

void Installation_hydrauliqueView::bouton_defilement_droit_type_regulation()
{
	// Incrémentation de la variable
	if(++u8Regulation > 4)
	{
		u8Regulation = 0;
	}
	// Masque l'ensemble des containers
	container_regul_directe.setVisible(false);
	container_regul_directe.invalidate();
	container_regul_2_zones.setVisible(false);
	container_regul_2_zones.invalidate();
	container_regul_multizones.setVisible(false);
	container_regul_multizones.invalidate();
	container_regul_externe.setVisible(false);
	container_regul_externe.invalidate();
	container_regul_esclave.setVisible(false);
	container_regul_esclave.invalidate();
	textArea_circulateurs_arkteos.setVisible(false);
	textArea_circulateurs_arkteos.invalidate();
	textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NB_PAC_CENTRE_DEFAUT));
	textArea_nombre_pac.invalidate();
	container_nombre_pac.setVisible(true);
	container_nombre_pac.invalidate();
	// Affichage du container de la régulation sélectionnee
	switch(u8Regulation)
	{
		case 0:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_directe.setVisible(true);
			container_regul_directe.invalidate();
			container_nombre_pac.setVisible(false);
			container_nombre_pac.invalidate();
			break;
		case 1:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_2_zones.setVisible(true);
			container_regul_2_zones.invalidate();
			textArea_circulateurs_arkteos.setVisible(true);
			textArea_circulateurs_arkteos.invalidate();
			break;
		case 2:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTI_ZONES_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_multizones.setVisible(true);
			container_regul_multizones.invalidate();
			break;
		case 3:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_externe.setVisible(true);
			container_regul_externe.invalidate();
			break;
		case 4:
			if(u8Nb_PAC == 1)
			{
				u8Nb_PAC = 2;
			    Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
			    textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
			    textArea_valeur_nombre_pac.invalidate();
			}
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_ESCLAVE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NUM_PAC_CENTRE_DEFAUT));
			textArea_nombre_pac.invalidate();
			container_regul_esclave.setVisible(true);
			container_regul_esclave.invalidate();
			break;
	}
}

void Installation_hydrauliqueView::bouton_defilement_gauche_type_regulation()
{
	// Incrémentation de la variable
	if(u8Regulation > 0)
	{
		u8Regulation--;
	}
	else u8Regulation = 4;
	// Masque l'ensemble des containers
	container_regul_directe.setVisible(false);
	container_regul_directe.invalidate();
	container_regul_2_zones.setVisible(false);
	container_regul_2_zones.invalidate();
	container_regul_multizones.setVisible(false);
	container_regul_multizones.invalidate();
	container_regul_externe.setVisible(false);
	container_regul_externe.invalidate();
	container_regul_esclave.setVisible(false);
	container_regul_esclave.invalidate();
	textArea_circulateurs_arkteos.setVisible(false);
	textArea_circulateurs_arkteos.invalidate();
	textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NB_PAC_CENTRE_DEFAUT));
	textArea_nombre_pac.invalidate();
	container_nombre_pac.setVisible(true);
	container_nombre_pac.invalidate();
	// Affichage du container de la régulation sélectionnee
	switch(u8Regulation)
	{
		case 0:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_directe.setVisible(true);
			container_regul_directe.invalidate();
			container_nombre_pac.setVisible(false);
			container_nombre_pac.invalidate();
			break;
		case 1:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_2_zones.setVisible(true);
			container_regul_2_zones.invalidate();
			textArea_circulateurs_arkteos.setVisible(true);
			textArea_circulateurs_arkteos.invalidate();
			break;
		case 2:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTI_ZONES_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_multizones.setVisible(true);
			container_regul_multizones.invalidate();
			break;
		case 3:
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			container_regul_externe.setVisible(true);
			container_regul_externe.invalidate();
			break;
		case 4:
			if(u8Nb_PAC == 1)
			{
				u8Nb_PAC = 2;
			    Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
			    textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
			    textArea_valeur_nombre_pac.invalidate();
			}
			textArea_valeur_type_regulation.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_ESCLAVE_CENTRE_DEFAUT));
			textArea_valeur_type_regulation.invalidate();
			textArea_nombre_pac.setTypedText(touchgfx::TypedText(T_TEXT_NUM_PAC_CENTRE_DEFAUT));
			textArea_nombre_pac.invalidate();
			container_regul_esclave.setVisible(true);
			container_regul_esclave.invalidate();
			break;
	}
}

void Installation_hydrauliqueView::bouton_defilement_droit_nb_pac()
{
	// Maximum 8 PACs en cascade
    if(u8Nb_PAC < 8)
    {
    	u8Nb_PAC++;
    }
    // Possibilité d'activer la résistance de terminaison (si plus d'une PAC)
    if(u8Nb_PAC > 1)
    {
        touchgfx_printf("resistance terminaison affichee\n");
    	container_resistance_terminaison_regul_2_zones.setVisible(true);
    	container_resistance_terminaison_regul_2_zones.invalidate();
    	container_resistance_terminaison_regul_multizones.setVisible(true);
    	container_resistance_terminaison_regul_multizones.invalidate();
		container_resistance_terminaison_regul_externe.setVisible(true);
		container_resistance_terminaison_regul_externe.invalidate();
		container_resistance_terminaison_regul_esclave.setVisible(true);
		container_resistance_terminaison_regul_esclave.invalidate();
    }
    // MAJ de la valeur
    touchgfx_printf("nb pac = %d\n", u8Nb_PAC);
    Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
    textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
    textArea_valeur_nombre_pac.invalidate();
}

void Installation_hydrauliqueView::bouton_defilement_gauche_nb_pac()
{
	// Maximum 8 PACs en cascade
    if((u8Nb_PAC > 1 && u8Regulation != 4) || u8Nb_PAC > 2)
    {
    	u8Nb_PAC--;
    }
    // Possibilité d'activer la résistance de terminaison (si plus d'une PAC)
    if(u8Nb_PAC <= 1)
    {
        touchgfx_printf("resistance terminaison non affichee\n");
    	container_resistance_terminaison_regul_2_zones.setVisible(false);
    	container_resistance_terminaison_regul_2_zones.invalidate();
    	container_resistance_terminaison_regul_multizones.setVisible(false);
    	container_resistance_terminaison_regul_multizones.invalidate();
		container_resistance_terminaison_regul_externe.setVisible(false);
		container_resistance_terminaison_regul_externe.invalidate();
		container_resistance_terminaison_regul_esclave.setVisible(false);
		container_resistance_terminaison_regul_esclave.invalidate();
    }
    // MAJ de la valeur
    touchgfx_printf("nb pac = %d\n", u8Nb_PAC);
    Unicode::snprintf(textAreaBuffer_nb_pac, 2, "%d", u8Nb_PAC);
    textArea_valeur_nombre_pac.setWildcard(textAreaBuffer_nb_pac);
    textArea_valeur_nombre_pac.invalidate();
}

void Installation_hydrauliqueView::bouton_zone_1_directe()
{
	touchgfx_printf("status bouton zone 1 : %s\n", toggleButton_zone_1_on_off_regul_directe.getState() ? "true" : "false");

	if(toggleButton_zone_1_on_off_regul_directe.getState())
	{
		button_zone_1_regul_directe.setVisible(true);
		button_zone_1_regul_directe.invalidate();
		textArea_bouton_zone_1_regul_directe.setVisible(true);
		textArea_bouton_zone_1_regul_directe.invalidate();
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
	}
	else
	{
		button_zone_1_regul_directe.setVisible(false);
		button_zone_1_regul_directe.invalidate();
		textArea_bouton_zone_1_regul_directe.setVisible(false);
		textArea_bouton_zone_1_regul_directe.invalidate();
		textArea_zone_1_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
	}
}

void Installation_hydrauliqueView::bouton_zone_2_directe()
{
	touchgfx_printf("status bouton zone 2 : %s\n", toggleButton_zone_2_on_off_regul_directe.getState() ? "true" : "false");

	if(toggleButton_zone_2_on_off_regul_directe.getState())
	{
		button_zone_2_regul_directe.setVisible(true);
		button_zone_2_regul_directe.invalidate();
		textArea_bouton_zone_2_regul_directe.setVisible(true);
		textArea_bouton_zone_2_regul_directe.invalidate();
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
	}
	else
	{
		button_zone_2_regul_directe.setVisible(false);
		button_zone_2_regul_directe.invalidate();
		textArea_bouton_zone_2_regul_directe.setVisible(false);
		textArea_bouton_zone_2_regul_directe.invalidate();
		textArea_zone_2_on_off_regul_directe.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_directe.invalidate();
	}
}

void Installation_hydrauliqueView::bouton_zone_1_2_zones()
{
	touchgfx_printf("status bouton zone 1 : %s\n", toggleButton_zone_1_on_off_regul_2_zones.getState() ? "true" : "false");

	if(toggleButton_zone_1_on_off_regul_2_zones.getState())
	{
		button_zone_1_regul_2_zones.setVisible(true);
		button_zone_1_regul_2_zones.invalidate();
		textArea_bouton_zone_1_regul_2_zones.setVisible(true);
		textArea_bouton_zone_1_regul_2_zones.invalidate();
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_directe.invalidate();
	}
	else
	{
		button_zone_1_regul_2_zones.setVisible(false);
		button_zone_1_regul_2_zones.invalidate();
		textArea_bouton_zone_1_regul_2_zones.setVisible(false);
		textArea_bouton_zone_1_regul_2_zones.invalidate();
		textArea_zone_1_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_1_on_off_regul_2_zones.invalidate();
	}
}

void Installation_hydrauliqueView::bouton_zone_2_2_zones()
{
	touchgfx_printf("status bouton zone 2 : %s\n", toggleButton_zone_2_on_off_regul_2_zones.getState() ? "true" : "false");

	if(toggleButton_zone_2_on_off_regul_2_zones.getState())
	{
		button_zone_2_regul_2_zones.setVisible(true);
		button_zone_2_regul_2_zones.invalidate();
		textArea_bouton_zone_2_regul_2_zones.setVisible(true);
		textArea_bouton_zone_2_regul_2_zones.invalidate();
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_2_zones.invalidate();
	}
	else
	{
		button_zone_2_regul_2_zones.setVisible(false);
		button_zone_2_regul_2_zones.invalidate();
		textArea_bouton_zone_2_regul_2_zones.setVisible(false);
		textArea_bouton_zone_2_regul_2_zones.invalidate();
		textArea_zone_2_on_off_regul_2_zones.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
		textArea_zone_2_on_off_regul_2_zones.invalidate();
	}
}
