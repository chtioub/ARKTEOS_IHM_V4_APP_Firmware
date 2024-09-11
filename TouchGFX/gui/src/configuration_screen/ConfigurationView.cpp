#include <gui/configuration_screen/ConfigurationView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ConfigurationView::ConfigurationView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	bPageUsine = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	bMaintenanceDepuisUsine = false;
	bInstallationDepuisUsine = false;
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Bouton accueil et retour masqués
	barre_titre.sansAccueil();
	barre_titre.sansRetour();
}

void ConfigurationView::setupScreen()
{
    ConfigurationViewBase::setupScreen();
}

void ConfigurationView::tearDownScreen()
{
    ConfigurationViewBase::tearDownScreen();
}

void ConfigurationView::bouton_maintenance()
{
	eCode = CODE_ACCES_MAINT;
	application().gotoCode_numeriqueScreenNoTransition();
}

void ConfigurationView::bouton_installation()
{
	eCode = CODE_ACCES_INSTALL;
	application().gotoCode_numeriqueScreenNoTransition();
}

void ConfigurationView::bouton_usine()
{
	eCode = CODE_ACCES_USINE;
	application().gotoCode_numeriqueScreenNoTransition();
}

void ConfigurationView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	S_ZONE sZone_tmp;
	memset(&sZone_tmp, 0, sizeof(S_ZONE));

	if(sConfig_IHM->sOption_PAC.TypeAppoint != sConfig_IHM_old.sOption_PAC.TypeAppoint || (sConfig_IHM->sOption_PAC.ECS != sConfig_IHM_old.sOption_PAC.ECS) || (sConfig_IHM->sMode_ECS.bUserAppointECS != sConfig_IHM_old.sMode_ECS.bUserAppointECS))
	{
		if(sConfig_IHM->sOption_PAC.TypeAppoint != NO_APPOINT || (sConfig_IHM->sOption_PAC.ECS == 1 && sConfig_IHM->sMode_ECS.bUserAppointECS == 1))
		{
			container_secours.setVisible(true);
		}
		else container_secours.setVisible(false);
		container_secours.invalidate();
	}

	if((sConfig_IHM->sMode_PAC.bSecours != sConfig_IHM_old.sMode_PAC.bSecours) || (sConfig_IHM->sMode_ECS.bUserECSSecours != sConfig_IHM_old.sMode_ECS.bUserECSSecours))
	{
		if(sConfig_IHM->sMode_PAC.bSecours == 1 || sConfig_IHM->sMode_ECS.bUserECSSecours == 1)
		{
			buttonWithIcon_secours_on.setVisible(true);
		}
		else buttonWithIcon_secours_on.setVisible(false);
		buttonWithIcon_secours_on.invalidate();
	}

	if((sConfig_IHM->sParam_PAC.TypeRegul != sConfig_IHM_old.sParam_PAC.TypeRegul) || memcmp(&sConfig_IHM->sOption_PAC.sZone, &sConfig_IHM_old.sOption_PAC.sZone, sizeof(S_ZONE)) || (sConfig_IHM->sOption_PAC.ECS != sConfig_IHM_old.sOption_PAC.ECS) || (sConfig_IHM->sOption_PAC.Piscine != sConfig_IHM_old.sOption_PAC.Piscine))
	{
		if((sConfig_IHM->sParam_PAC.TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE && memcmp(&sConfig_IHM->sOption_PAC.sZone, &sZone_tmp, sizeof(S_ZONE))) || sConfig_IHM->sOption_PAC.ECS || sConfig_IHM->sOption_PAC.Piscine)
		{
			container_vacances.setVisible(true);
		}
		else container_vacances.setVisible(false);
		container_vacances.invalidate();
	}

	if(sConfig_IHM->sMode_ECS.Exception != sConfig_IHM_old.sMode_ECS.Exception)
	{
		if(sConfig_IHM->sMode_ECS.Exception == VACANCES)
		{
			buttonWithIcon_vacances_on.setVisible(true);
		}
		else buttonWithIcon_vacances_on.setVisible(false);
		buttonWithIcon_vacances_on.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void ConfigurationView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void ConfigurationView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void ConfigurationView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void ConfigurationView::changeDate(S_DATE *sDate)
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
