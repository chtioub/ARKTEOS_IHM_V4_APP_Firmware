#include <gui/synoptique_screen/SynoptiqueView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Utils.hpp>
SynoptiqueView::SynoptiqueView()
{
//	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sCyclRegFrigo_old, 0, sizeof(sCyclRegFrigo_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
//	changeConfig(&sConfig_IHM);
//	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_SYNOPTIQUE_MAINTENANCE_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    changeStatutCyclFrigo(&sCyclRegFrigo[0]);


	// Récupération des progs
#ifndef SIMULATOR
	//presenter->c_prog_piscine(false);
#endif
}


void SynoptiqueView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void SynoptiqueView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void SynoptiqueView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void SynoptiqueView::changeDate(S_DATE *sDate)
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

void SynoptiqueView::changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo)
{
//	if(sCyclRegFrigo_old.pac. != sCyclRegFrigo->pac)
//	{
		// Affichage de l'heure
		Unicode::snprintfFloat(textAreaBuffer_Temp_Dep_Prim, 7,"%.1f", ((float)(sCyclRegFrigo->pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire)/10));
		textArea_temp_DCh_invert.setWildcard(textAreaBuffer_Temp_Dep_Prim);
		textArea_temp_DCh_invert.invalidate();
		memcpy(&sCyclRegFrigo_old, sCyclRegFrigo, sizeof(S_CYCL_REG_FRI));
//	}

}

void SynoptiqueView::setupScreen()
{
    SynoptiqueViewBase::setupScreen();
}

void SynoptiqueView::tearDownScreen()
{
	SynoptiqueViewBase::tearDownScreen();
}

void SynoptiqueView::bouton_retour()
{
	if(bPageUsine)
	{
		application().gotoUsineScreenNoTransition();
	}
	else application().gotoMaintenanceScreenNoTransition();
}



