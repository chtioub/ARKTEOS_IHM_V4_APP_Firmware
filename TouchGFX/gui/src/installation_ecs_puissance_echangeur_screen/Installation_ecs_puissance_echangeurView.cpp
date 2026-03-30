#include <gui/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecs_puissance_echangeurView::Installation_ecs_puissance_echangeurView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);

	// Titre
	Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PUISSANCE_ECHANGEUR_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	u2PW_Echangeur = sParam_ECS_temp.u2PW_Echangeur; //Valeur de puissance / 100
	update_PW_echangeur();
}

void Installation_ecs_puissance_echangeurView::bouton_gauche_puissance()
{
	if (u2PW_Echangeur > 0) u2PW_Echangeur--;
	else u2PW_Echangeur = 3;
	update_PW_echangeur();
}

void Installation_ecs_puissance_echangeurView::bouton_droit_puissance()
{
	if (u2PW_Echangeur < 3) u2PW_Echangeur++;
	else u2PW_Echangeur = 0;
	update_PW_echangeur();
}

void Installation_ecs_puissance_echangeurView::update_PW_echangeur()
{
	switch(u2PW_Echangeur)
	{
		case 0:
			textArea_valeur_puissance_echangeur_ecs.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_ECH_ECS_8KW_CENTRE_DEFAUT));
			break;
		case 1:
			textArea_valeur_puissance_echangeur_ecs.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_ECH_ECS_12KW_CENTRE_DEFAUT));
			break;
		case 2:
			textArea_valeur_puissance_echangeur_ecs.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_ECH_ECS_16KW_CENTRE_DEFAUT));
			break;
		case 3:
			textArea_valeur_puissance_echangeur_ecs.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_ECH_ECS_20KW_CENTRE_DEFAUT));
			break;
	}
	textArea_valeur_puissance_echangeur_ecs.invalidate();
}

void Installation_ecs_puissance_echangeurView::bouton_valider()
{
	sParam_ECS_temp.u2PW_Echangeur = u2PW_Echangeur & 0b11;
	sConfig_IHM.sParam_ECS.u2PW_Echangeur = u2PW_Echangeur & 0b11;
	presenter->c_install_ecs();
}

void Installation_ecs_puissance_echangeurView::setupScreen()
{
	Installation_ecs_puissance_echangeurViewBase::setupScreen();
}

void Installation_ecs_puissance_echangeurView::tearDownScreen()
{
	Installation_ecs_puissance_echangeurViewBase::tearDownScreen();
}

void Installation_ecs_puissance_echangeurView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_puissance_echangeurView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_puissance_echangeurView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_puissance_echangeurView::changeDate(S_DATE *sDate)
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
