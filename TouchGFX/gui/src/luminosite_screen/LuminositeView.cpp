#include <gui/luminosite_screen/LuminositeView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LuminositeView::LuminositeView()
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
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_LUMINOSITE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Init des variables d'offset
    u8Luminosite = sConfig_IHM.sParam_Utilisateur.u7Luminosite;
    if(u8Luminosite < 10)
    {
    	u8Luminosite = 10;
    }
	slider_luminosite.setValue(u8Luminosite);
    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
	textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
	textArea_luminosite.invalidate();
}

void LuminositeView::setupScreen()
{
    LuminositeViewBase::setupScreen();
}

void LuminositeView::tearDownScreen()
{
    LuminositeViewBase::tearDownScreen();
	//
	if(sConfig_IHM.sParam_Utilisateur.u7Luminosite != 0)
	{
		presenter->editLuminosite(sConfig_IHM.sParam_Utilisateur.u7Luminosite);
	}
	else presenter->editLuminosite(100);
}

void LuminositeView::slider_lumi(int sliderValue)
{
	if(sliderValue < 1)
	{
		u8Luminosite = 1;
		slider_luminosite.setValue(u8Luminosite);
	}
	else u8Luminosite = sliderValue;
	presenter->editLuminosite(u8Luminosite);
	// Affichage de la valeur
    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
	textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
	textArea_luminosite.invalidate();
}

void LuminositeView::bouton_moins()
{
	if(u8Luminosite > 1)
	{
		u8Luminosite--;
		slider_luminosite.setValue(u8Luminosite);
		presenter->editLuminosite(u8Luminosite);
		// Affichage de la valeur
	    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
		textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
		textArea_luminosite.invalidate();
	}
}

void LuminositeView::bouton_plus()
{
	if(u8Luminosite < 100)
	{
		u8Luminosite++;
		slider_luminosite.setValue(u8Luminosite);
		presenter->editLuminosite(u8Luminosite);
		// Affichage de la valeur
	    Unicode::snprintf(textAreaBuffer_Luminosite, 4, "%d", u8Luminosite);
		textArea_luminosite.setWildcard(textAreaBuffer_Luminosite);
		textArea_luminosite.invalidate();
	}
}

void LuminositeView::bouton_valider()
{
	if(sConfig_IHM.sParam_Utilisateur.u7Luminosite != u8Luminosite)
	{
		sConfig_IHM.sParam_Utilisateur.u7Luminosite = u8Luminosite;
		presenter->c_user_param();
		presenter->editLuminosite(u8Luminosite);
	}
	application().gotoParametresScreenNoTransition();
}

void LuminositeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void LuminositeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void LuminositeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void LuminositeView::changeDate(S_DATE *sDate)
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
