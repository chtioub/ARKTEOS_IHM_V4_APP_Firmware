#include <gui/configuration_screen/ConfigurationView.hpp>

ConfigurationView::ConfigurationView()
{
	//MAJ de la page en fonction de là d'ou on vient
//	if (bPageAccueil == true)
//	{
//		swipeContainerMain.setSelectedPage(0);
////		swipeContainerMain.invalidate();
//		barre_titre.titre(textAreaBuffer_Titre_Date);
////		barre_titre.invalidate();
//		circle_point_page_config.setVisible(false);
//		textArea_config_page.setVisible(false);
//		circle_point_page_accueil.setVisible(true);
//		textArea_accueil_page.setVisible(true);
//	}
//	else
//	{
//		swipeContainerMain.setSelectedPage(1);
//		swipeContainerMain.invalidate();
		Unicode::snprintf(textAreaBuffer_Titre_Titre, 40, touchgfx::TypedText(T_TEXT_CONFIGURATION_CENTRE_DEFAUT).getText());
		barre_titre.titre(textAreaBuffer_Titre_Titre);
//		barre_titre.invalidate();

		circle_point_page_config.setVisible(true);
		textArea_config_page.setVisible(true);
//	}
//	swipeContainerMain.invalidate();
	barre_titre.invalidate();
	circle_point_page_config.invalidate();
	textArea_config_page.invalidate();
//	circle_point_page_accueil.invalidate();
//	textArea_accueil_page.invalidate();

	memset(&sDate_old, 0, sizeof(sDate));
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM));
	memset(&sCyclRegFrigo_old, 0, sizeof(sCyclRegFrigo_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	u8Zone1 = 0xff;
	u8Zone2 = 0xff;
	u8NbZones = 0;
	bPageUsine = 0;
	bConnexionDistance = false;
	changeDate(&sDate);
	changeConfig(&sConfig_IHM);
	changeErreur(u16ErreurEncours);
	changeStatutEther(&sCycEther);

	barre_titre.sansAccueil();
	barre_titre.sansRetour();


	//Pour Page Configuration
	bMaintenanceDepuisUsine = false;
	bInstallationDepuisUsine = false;


	if (oui_veille == 1)
	{
		toggleButton_oui_oui_non_veille.forceState(false);
		toggleButton_oui_oui_non_veille.setTouchable(true);
		toggleButton_non_oui_non_veille.forceState(true);
		toggleButton_non_oui_non_veille.setTouchable(false);
	}
	else
	{
		toggleButton_oui_oui_non_veille.forceState(true);
		toggleButton_oui_oui_non_veille.setTouchable(false);
		toggleButton_non_oui_non_veille.forceState(false);
		toggleButton_non_oui_non_veille.setTouchable(true);
	}
	toggleButton_oui_oui_non_veille.invalidate();
	toggleButton_non_oui_non_veille.invalidate();

	//Container Vacances
	if ((sConfig_IHM.sParam_PAC.TypeRegul <= REGUL_BAL_TAMPON_MULTI_ZONE && sConfig_IHM.sOption_PAC.sZone.u8val != 0)
			|| sConfig_IHM.sOption_PAC.ECS != 0 || sConfig_IHM.sOption_PAC.Piscine != 0)
	{
		container_vacances.setVisible(true);
	}
	else
	{
		container_vacances.setVisible(false);
	}
	container_vacances.invalidate();
}

void ConfigurationView::setupScreen()
{
	ConfigurationViewBase::setupScreen();

}

void ConfigurationView::tearDownScreen()
{
	ConfigurationViewBase::tearDownScreen();
}

//void AccueilView::swipeCallbackHandler(int16_t velocity)
//{
//    if(velocity < 0)
//    {
//		application().gotoConfigurationScreenSlideTransitionEast();
//    }
//}

void ConfigurationView::handleGestureEvent(const touchgfx::GestureEvent& evt)
{
    if (evt.getType() == touchgfx::GestureEvent::SWIPE_HORIZONTAL)
    {
        if (evt.getVelocity() > 0)
        {
            // Swipe de gauche vers droite
        	application().gotoAccueilScreenNoTransition();
        }
        else
        {
            // Swipe de droite vers gauche
        	application().gotoAccueilScreenNoTransition();
        }
    }
}

void ConfigurationView::bouton_oui_veille()
{
	toggleButton_oui_oui_non_veille.forceState(true);
	toggleButton_oui_oui_non_veille.setTouchable(false);
	toggleButton_non_oui_non_veille.forceState(false);
	toggleButton_non_oui_non_veille.setTouchable(true);
	oui_veille = 0;
	toggleButton_oui_oui_non_veille.invalidate();
	toggleButton_non_oui_non_veille.invalidate();
}

void ConfigurationView::bouton_non_veille()
{
	toggleButton_oui_oui_non_veille.forceState(false);
	toggleButton_oui_oui_non_veille.setTouchable(true);
	toggleButton_non_oui_non_veille.forceState(true);
	toggleButton_non_oui_non_veille.setTouchable(false);
	oui_veille = 1;
	toggleButton_oui_oui_non_veille.invalidate();
	toggleButton_non_oui_non_veille.invalidate();
}


void ConfigurationView::bouton_maintenance()
{
	if (bAutorisationNoCode)
	{
		application().gotoMaintenanceScreenNoTransition();
	}
	else
	{
		eCode = CODE_ACCES_MAINT;
		application().gotoCode_numeriqueScreenNoTransition();
	}
}

void ConfigurationView::bouton_installation()
{
	if (bAutorisationNoCode)
	{
		application().gotoInstallationScreenNoTransition();
	}
	else
	{
		eCode = CODE_ACCES_INSTALL;
		application().gotoCode_numeriqueScreenNoTransition();
	}
}

void ConfigurationView::bouton_usine()
{
	eCode = CODE_ACCES_USINE;
	application().gotoCode_numeriqueScreenNoTransition();
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
			buttonWithIcon_secours_off.setVisible(false);
			buttonWithIcon_secours_on.setVisible(true);
		}
		else
		{
			buttonWithIcon_secours_on.setVisible(false);
			buttonWithIcon_secours_off.setVisible(true);
		}
		buttonWithIcon_secours_on.invalidate();
		buttonWithIcon_secours_off.invalidate();
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

void ConfigurationView::changeDate(S_DATE *sDate)
{
	uint32_t u32Mois, u32Jour;


//	if(sDate_old.Date != sDate->Date || sDate_old.Month != sDate->Month || sDate_old.Year != sDate->Year  || sDate_old.WeekDay != sDate->WeekDay
//			|| sDate_old.Hours != sDate->Hours || sDate_old.Minutes != sDate->Minutes)
//	{
		// Affichage de l'heure
		if(sDate_old.Hours != sDate->Hours || sDate_old.Minutes != sDate->Minutes)
		{
				Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
				barre_titre.heure(textAreaBuffer_Heure);
		}

		if(sDate_old.Date != sDate->Date || sDate_old.Month != sDate->Month || sDate_old.Year != sDate->Year  || sDate_old.WeekDay != sDate->WeekDay)
		{
			// Affichage de la date
			Unicode::snprintf(textAreaBuffer_Date, 9, "%02d/%02d/%02d", sDate->Date, sDate->Month, sDate->Year);
			barre_titre.date(textAreaBuffer_Date);

			// Affichage du titre
			switch(sDate->WeekDay)
			{
				default:
					u32Jour = T_TEXT_LUNDI_CENTRE_LARGE;
					break;
				case 1:
					u32Jour = T_TEXT_MARDI_CENTRE_LARGE;
					break;
				case 2:
					u32Jour = T_TEXT_MERCREDI_CENTRE_LARGE;
					break;
				case 3:
					u32Jour = T_TEXT_JEUDI_CENTRE_LARGE;
					break;
				case 4:
					u32Jour = T_TEXT_VENDREDI_CENTRE_LARGE;
					break;
				case 5:
					u32Jour = T_TEXT_SAMEDI_CENTRE_LARGE;
					break;
				case 6:
					u32Jour = T_TEXT_DIMANCHE_CENTRE_LARGE;
					break;
			}
			switch(sDate->Month)
			{
				default:
					u32Mois = T_TEXT_MOIS_JANVIER_CENTRE_LARGE;
					break;
				case 2:
					u32Mois = T_TEXT_MOIS_FEVRIER_CENTRE_LARGE;
					break;
				case 3:
					u32Mois = T_TEXT_MOIS_MARS_CENTRE_LARGE;
					break;
				case 4:
					u32Mois = T_TEXT_MOIS_AVRIL_CENTRE_LARGE;
					break;
				case 5:
					u32Mois = T_TEXT_MOIS_MAI_CENTRE_LARGE;
					break;
				case 6:
					u32Mois = T_TEXT_MOIS_JUIN_CENTRE_LARGE;
					break;
				case 7:
					u32Mois = T_TEXT_MOIS_JUILLET_CENTRE_LARGE;
					break;
				case 8:
					u32Mois = T_TEXT_MOIS_AOUT_CENTRE_LARGE;
					break;
				case 9:
					u32Mois = T_TEXT_MOIS_SEPTEMBRE_CENTRE_LARGE;
					break;
				case 10:
					u32Mois = T_TEXT_MOIS_OCTOBRE_CENTRE_LARGE;
					break;
				case 11:
					u32Mois = T_TEXT_MOIS_NOVEMBRE_CENTRE_LARGE;
					break;
				case 12:
					u32Mois = T_TEXT_MOIS_DECEMBRE_CENTRE_LARGE;
					break;
			}
			Unicode::snprintf(textAreaBuffer_Titre_Date, 30, "%s %d %s 20%02d", touchgfx::TypedText(u32Jour).getText(), sDate->Date, touchgfx::TypedText(u32Mois).getText(), sDate->Year);

		}

		barre_titre.invalidate();
		memcpy(&sDate_old, sDate, sizeof(S_DATE));
//	}
}
