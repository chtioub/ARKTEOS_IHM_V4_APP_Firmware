#include <gui/position_ecran_screen/Position_ecranView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Position_ecranView::Position_ecranView()
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
	// Modification de l'origine
	container.setXY(u8PositionX, u8PositionY);
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_POSITION_ECRAN_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Init des variables d'offset
    Unicode::snprintf(textAreaBuffer_OffsetX, 3, "%d", container.getX());
    textArea_position.setWildcard1(textAreaBuffer_OffsetX);
    Unicode::snprintf(textAreaBuffer_OffsetY, 3, "%d", container.getY());
    textArea_position.setWildcard2(textAreaBuffer_OffsetY);
}

void Position_ecranView::setupScreen()
{
    Position_ecranViewBase::setupScreen();
}

void Position_ecranView::tearDownScreen()
{
    Position_ecranViewBase::tearDownScreen();
}

void Position_ecranView::bouton_valider()
{
	if(((container.getX() + 1) != sConfig_IHM.sParam_Utilisateur.u8PositionX) || ((container.getY() + 1) != sConfig_IHM.sParam_Utilisateur.u8PositionY))
	{
		sConfig_IHM.sParam_Utilisateur.u8PositionX = u8PositionX = container.getX() + 1;
		sConfig_IHM.sParam_Utilisateur.u8PositionY = u8PositionY = container.getY() + 1;
		presenter->c_user_param();
	}
	application().gotoParametresScreenNoTransition();
}

void Position_ecranView::bouton_droit()
{
	if(container.getX() < (1023 - container.getWidth()))
	{
		container.setX(container.getX() + 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de X
	    Unicode::snprintf(textAreaBuffer_OffsetX, 3, "%d", container.getX());
	    textArea_position.setWildcard1(textAreaBuffer_OffsetX);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::bouton_gauche()
{
	if(container.getX() > 0)
	{
		container.setX(container.getX() - 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de X
	    Unicode::snprintf(textAreaBuffer_OffsetX, 3, "%d", container.getX());
	    textArea_position.setWildcard1(textAreaBuffer_OffsetX);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::bouton_bas()
{
	if(container.getY() < (599 - container.getHeight()))
	{
		container.setY(container.getY() + 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de Y
	    Unicode::snprintf(textAreaBuffer_OffsetY, 3, "%d", container.getY());
	    textArea_position.setWildcard2(textAreaBuffer_OffsetY);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::bouton_haut()
{
	if(container.getY() > 0)
	{
		container.setY(container.getY() - 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de Y
	    Unicode::snprintf(textAreaBuffer_OffsetY, 3, "%d", container.getY());
	    textArea_position.setWildcard2(textAreaBuffer_OffsetY);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Position_ecranView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Position_ecranView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Position_ecranView::changeDate(S_DATE *sDate)
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
