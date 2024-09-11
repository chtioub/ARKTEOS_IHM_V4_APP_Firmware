#include <gui/usine_config_inverterra_screen/Usine_config_inverterraView.hpp>

Usine_config_inverterraView::Usine_config_inverterraView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIG_INVERTERRA_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void Usine_config_inverterraView::setupScreen()
{
    Usine_config_inverterraViewBase::setupScreen();
}

void Usine_config_inverterraView::tearDownScreen()
{
    Usine_config_inverterraViewBase::tearDownScreen();
}

void Usine_config_inverterraView::bouton_droite_fluide_c1()
{
	if(++u8FluideC1 > GAZ_R454C)
	{
		u8FluideC1 = GAZ_NONE;
	}
	affichageFluideC1();
}

void Usine_config_inverterraView::bouton_gauche_fluide_c1()
{
	if(u8FluideC1 == GAZ_NONE)
	{
		u8FluideC1 = GAZ_R454C;
	}
	else u8FluideC1--;
	affichageFluideC1();
}

void Usine_config_inverterraView::affichageFluideC1()
{
	switch(u8FluideC1)
	{
		case GAZ_NONE:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "NA");
			break;
		case GAZ_R410:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R410A");
			break;
		case GAZ_R134:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R134a");
			break;
		case GAZ_R407:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R407C");
			break;
		case GAZ_R32:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R32");
			break;
		case GAZ_HELIUM:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "He");
			break;
		case GAZ_R513:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R513");
			break;
		case GAZ_R454C:
			Unicode::snprintf(textAreaBuffer_FluideC1, 6, "R454C");
			break;
	}
	textArea_valeur_fluide_inverterra_sajiter.setWildcard(textAreaBuffer_FluideC1);
	textArea_valeur_fluide_inverterra_sajiter.invalidate();
}

void Usine_config_inverterraView::bouton_moins_puissance()
{

}

void Usine_config_inverterraView::bouton_plus_puissance()
{

}

void Usine_config_inverterraView::bouton_mono_tri()
{
	if(textArea_valeur_alim_pac.getTypedText().getId() == touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT).getId())
	{
		textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_TRI_CENTRE_DEFAUT));
	}
	else textArea_valeur_alim_pac.setTypedText(touchgfx::TypedText(T_TEXT_ALIM_PAC_MONO_CENTRE_DEFAUT));
	textArea_valeur_alim_pac.invalidate();
}

void Usine_config_inverterraView::bouton_type_inverterra()
{
//	if(textArea_valeur_module_2_zones_int.getTypedText().getId() == touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT).getId())
//	{
//		textArea_valeur_module_2_zones_int.setTypedText(touchgfx::TypedText(T_TEXT_NON_CENTRE_DEFAUT));
//	}
//	else textArea_valeur_module_2_zones_int.setTypedText(touchgfx::TypedText(T_TEXT_OUI_CENTRE_DEFAUT));
//	textArea_valeur_module_2_zones_int.invalidate();
}

void Usine_config_inverterraView::bouton_valider()
{

	//
	presenter->c_usine_param();
	application().gotoUsineScreenNoTransition();
}

void Usine_config_inverterraView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Usine_config_inverterraView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Usine_config_inverterraView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Usine_config_inverterraView::changeDate(S_DATE *sDate)
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
