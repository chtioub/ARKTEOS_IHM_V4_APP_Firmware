#include <gui/installation_degivrage_liaison_frigo_screen/Installation_degivrage_liaison_frigoView.hpp>

Installation_degivrage_liaison_frigoView::Installation_degivrage_liaison_frigoView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_DEGIVRAGE_LIAISON_FRIGO_TITRE).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	Type_Degivrage = sConfig_IHM.sParam_Frigo.Type_Degivrage;
	update_typedegivrage();
}

void Installation_degivrage_liaison_frigoView::update_typedegivrage()
{
	if (Type_Degivrage == 0)
	{
		textArea_valeur_condition.setTypedText(touchgfx::TypedText(T_TEXT_NORMAL));
	}
	else
	{
		textArea_valeur_condition.setTypedText(touchgfx::TypedText(T_TEXT_TAUX_HUMIDITE_ELEVE));
	}
	textArea_valeur_condition.invalidate();
}

void Installation_degivrage_liaison_frigoView::bouton_gauche_condition_degivrage()
{
	if (Type_Degivrage == 0) Type_Degivrage = 1;
	else Type_Degivrage = 0;
	update_typedegivrage();
}

void Installation_degivrage_liaison_frigoView::bouton_droit_condition_degivrage()
{
	if (Type_Degivrage == 0) Type_Degivrage = 1;
	else Type_Degivrage = 0;
	update_typedegivrage();
}

void Installation_degivrage_liaison_frigoView::bouton_valider()
{
	sConfig_IHM.sParam_Frigo.Type_Degivrage = Type_Degivrage;
	presenter-> c_install_param();
}

void Installation_degivrage_liaison_frigoView::setupScreen()
{
    Installation_degivrage_liaison_frigoViewBase::setupScreen();
}

void Installation_degivrage_liaison_frigoView::tearDownScreen()
{
    Installation_degivrage_liaison_frigoViewBase::tearDownScreen();
}

void Installation_degivrage_liaison_frigoView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_degivrage_liaison_frigoView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_degivrage_liaison_frigoView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_degivrage_liaison_frigoView::changeDate(S_DATE *sDate)
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

