#include <gui/installation_gestion_v3v_screen/Installation_gestion_v3vView.hpp>

Installation_gestion_v3vView::Installation_gestion_v3vView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_GESTION_DES_VANNES_3_VOIES).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();
	//
	Type_Gestion_V3V = sConfig_IHM.sParam_Piscine.Type_Gestion_V3V;
	update_gestion_v3v();
}

void Installation_gestion_v3vView::bouton_droit()
{
	if (Type_Gestion_V3V == 0) Type_Gestion_V3V = 1;
	else Type_Gestion_V3V = 0;
	update_gestion_v3v();
}

void Installation_gestion_v3vView::bouton_gauche()
{
	if (Type_Gestion_V3V == 0) Type_Gestion_V3V = 1;
	else Type_Gestion_V3V = 0;
	update_gestion_v3v();
}

void Installation_gestion_v3vView::update_gestion_v3v()
{
	if (Type_Gestion_V3V == 0)
	{
		image_ecs.setX(27);
		image_piscine.setX(172);
		container_maison.setX(324);
	}
	else
	{
		image_ecs.setX(176);
		image_piscine.setX(318);
		container_maison.setX(26);
	}
//	image_ecs.invalidate();
//	image_piscine.invalidate();
//	container_maison.invalidate();
	container_images.invalidate();
	Unicode::snprintf(textAreaBuffer_GestionV3V, 2, "%d", Type_Gestion_V3V + 1);
	textArea_valeur_type_gestion.setWildcard(textAreaBuffer_GestionV3V);
	textArea_valeur_type_gestion.invalidate();
}

void Installation_gestion_v3vView::bouton_valider()
{
	sConfig_IHM.sParam_Piscine.Type_Gestion_V3V = Type_Gestion_V3V;
	presenter->c_install_piscine();
}


void Installation_gestion_v3vView::setupScreen()
{
    Installation_gestion_v3vViewBase::setupScreen();
}

void Installation_gestion_v3vView::tearDownScreen()
{
    Installation_gestion_v3vViewBase::tearDownScreen();
}


void Installation_gestion_v3vView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_gestion_v3vView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_gestion_v3vView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_gestion_v3vView::changeDate(S_DATE *sDate)
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
