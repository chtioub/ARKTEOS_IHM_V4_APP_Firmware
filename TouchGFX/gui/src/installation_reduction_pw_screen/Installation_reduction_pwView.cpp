#include <gui/installation_reduction_pw_screen/Installation_reduction_pwView.hpp>

Installation_reduction_pwView::Installation_reduction_pwView()
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_REDUCTION_PUISSANCE_TITRE_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	Reduc_PW = sConfig_IHM.sParam_Frigo.Reduc_PW;
	update_val_reduc_pw();
}

void Installation_reduction_pwView::bouton_gauche()
{
	if (Reduc_PW > 0) Reduc_PW--;
	else Reduc_PW = 7;
	update_val_reduc_pw();
}

void Installation_reduction_pwView::bouton_droit()
{
	if (Reduc_PW < 7) Reduc_PW++;
	else Reduc_PW = 0;
	update_val_reduc_pw();
}

void Installation_reduction_pwView::update_val_reduc_pw()
{
	switch (Reduc_PW)
	{
		case R0:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 100% / P : 100%");
			break;
		case R1:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 66% / P : 100%");
			break;
		case R2:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 33% / P : 100%");
			break;
		case R3:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 0% / P : 100%");
			break;
		case R4:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 0% / P : 80%");
			break;
		case R5:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 0% / P : 70%");
			break;
		case R6:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 0% / P : 60%");
			break;
		case R7:
			Unicode::snprintf(textAreaBuffer_ReductionPW,20, "E : 0% / P : 50%");
			break;
	}

	textArea_valeur_reduction_pw.setWildcard(textAreaBuffer_ReductionPW);
	textArea_valeur_reduction_pw.invalidate();
}

void Installation_reduction_pwView::bouton_valider()
{
	sConfig_IHM.sParam_Frigo.Reduc_PW = Reduc_PW & 0b111;
	presenter->c_install_param();
}

void Installation_reduction_pwView::setupScreen()
{
    Installation_reduction_pwViewBase::setupScreen();
}

void Installation_reduction_pwView::tearDownScreen()
{
    Installation_reduction_pwViewBase::tearDownScreen();
}

void Installation_reduction_pwView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_reduction_pwView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_reduction_pwView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_reduction_pwView::changeDate(S_DATE *sDate)
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
