#include <gui/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Installation_ecs_puissance_appointView::Installation_ecs_puissance_appointView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PUISSANCE_APPOINT_ECS_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	u6PW_Brin = sParam_ECS_temp.u6PW_Brin; //Valeur de puissance / 100
	update_PW_appoint();
}

void Installation_ecs_puissance_appointView::bouton_gauche_puissance()
{
	if (u6PW_Brin > 10) u6PW_Brin--;
	update_PW_appoint();
}

void Installation_ecs_puissance_appointView::bouton_droit_puissance()
{
	if (u6PW_Brin < 60) u6PW_Brin++;
	update_PW_appoint();
}

void Installation_ecs_puissance_appointView::update_PW_appoint()
{
	Unicode::snprintf(textAreaBuffer_PWAppoint, 5, "%d", u6PW_Brin * 100);
	textArea_valeur_puissance_appoint_ecs.setWildcard(textAreaBuffer_PWAppoint);
	textArea_valeur_puissance_appoint_ecs.invalidate();
}

void Installation_ecs_puissance_appointView::bouton_valider()
{
	sParam_ECS_temp.u6PW_Brin = u6PW_Brin & 0x3F;
	sConfig_IHM.sParam_ECS.u6PW_Brin = u6PW_Brin & 0x3F;
	presenter->c_install_ecs();
}

void Installation_ecs_puissance_appointView::setupScreen()
{
    Installation_ecs_puissance_appointViewBase::setupScreen();
}

void Installation_ecs_puissance_appointView::tearDownScreen()
{
    Installation_ecs_puissance_appointViewBase::tearDownScreen();
}

void Installation_ecs_puissance_appointView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_ecs_puissance_appointView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_ecs_puissance_appointView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_ecs_puissance_appointView::changeDate(S_DATE *sDate)
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
