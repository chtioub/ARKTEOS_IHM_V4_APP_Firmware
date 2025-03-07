#include <gui/installation_param_avances_screen/Installation_param_avancesView.hpp>

Installation_param_avancesView::Installation_param_avancesView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAMETRES_AVANCES_TITRE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	//Modbus oui/non
	if(sConfig_IHM.sParam_PAC.bConfigThermostats120R == 1)
	{
		buttonWithLabel_configuration_modbus_off.setVisible(false);
		buttonWithLabel_configuration_modbus_on.setVisible(true);
	}
	else
	{
		buttonWithLabel_configuration_modbus_on.setVisible(false);
		buttonWithLabel_configuration_modbus_off.setVisible(true);
	}
	buttonWithLabel_configuration_modbus_off.invalidate();
	buttonWithLabel_configuration_modbus_on.invalidate();

	//View/Hide dégivrage button
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		buttonWithLabel_degivrage_liaison.setVisible(true);
	}
	else buttonWithLabel_degivrage_liaison.setVisible(false);
	buttonWithLabel_degivrage_liaison.invalidate();

	//View/Hide silencieux button
	if (sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III || sConfig_IHM.sModele_PAC.u8ModelePAC == GEOINVERTER
			|| sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX)
	{
		buttonWithLabel_mode_silencieux.setVisible(true);
	}
	else buttonWithLabel_mode_silencieux.setVisible(false);
	buttonWithLabel_mode_silencieux.invalidate();
}

void Installation_param_avancesView::setupScreen()
{
    Installation_param_avancesViewBase::setupScreen();
}

void Installation_param_avancesView::tearDownScreen()
{
    Installation_param_avancesViewBase::tearDownScreen();
}

void Installation_param_avancesView::bouton_resistance_carter()
{
	eOuiNon = OUI_NON_RESIST_CARTER;
}

void Installation_param_avancesView:: bouton_menu_special()
{
	eTypeClavierAlpha = CODE_LOGO;
}

void Installation_param_avancesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_param_avancesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_param_avancesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_param_avancesView::changeDate(S_DATE *sDate)
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
