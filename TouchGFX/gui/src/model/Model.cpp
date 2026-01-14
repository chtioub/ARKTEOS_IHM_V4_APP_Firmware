#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "IHM_V4.h"
#include <string.h>
#include <touchgfx/Utils.hpp>
#include <gui/common/FrontendApplication.hpp>

extern uint8_t gTouched;

//Pour IHM en mode "Salon" (alim de l'IHM sans COM)
//#define DEMO_ARKTEOS

Model::Model() :
    modelListener(0), veilleCounter(0)
{
	//Utilisé pour init du Slid Page accueil/config
#if defined(SIMULATOR) || defined(DEMO_ARKTEOS)
	// Options PAC
	sConfig_IHM.sOption_PAC.sZone.bZone1 = 1;
	sConfig_IHM.sOption_PAC.sZone.bZone2 = 1;
	sConfig_IHM.sParam_Zx[0].bModeChaud = 1;
	sConfig_IHM.sParam_Zx[1].bModeChaud = 1;
	sConfig_IHM.sParam_Zx[0].bModeFroid = 1;
	sConfig_IHM.sParam_Zx[1].bModeFroid = 1;
	sConfig_IHM.sOption_PAC.ECS = 1;
	sConfig_IHM.sOption_PAC.Piscine = 1;
	// Install PAC
	memset(sConfig_IHM.sInstall_PAC.auc8Serial_Number_PAC, '1', 12);
	memset(sConfig_IHM.sInstall_PAC.auc8PW_Installateur, '1', 4);
	memset(sConfig_IHM.sInstall_PAC.auc8PW_Maintenance, '1', 4);
	// Statut PAC
	sStatut_PAC.S_Mode = S_ECS + S_PISCINE;
	// Config ECS
	sStatut_ECS.i16TeauBas = 444;
	sStatut_ECS.i16TeauMilieu = 562;
	sConfig_IHM.sParam_ECS.bBouclageECS = 1;
	sConfig_IHM.sParam_ECS.bAntiLegionnel = 1;
	sConfig_IHM.sMode_ECS.i16Consigne_ECS_Normal = 600;
	sConfig_IHM.sMode_ECS.i16Consigne_ECS_Relance = 500;
	sConfig_IHM.sMode_ECS.u8Time_Bouclage_ECS = 130;
	// Config Piscine
	sStatut_Piscine.i16TeauPiscine = 279;
	sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort = 350;
	sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal = 300;
	sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit = 290;
	// Config Piscine
	sStatut_Zx[u8Pointeur_buffer_tx].i16Tint = 196;
	strcpy((char *)&sConfig_IHM.sParam_Zx[u8Pointeur_buffer_tx].u8NomZone[0], "RCH");
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx].Mode = MARCHE_CHAUD;
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx].i16Consigne_Tint_Reduit = 160;
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx].i16Consigne_Tint_Normal = 186;
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx].i16Consigne_Tint_Confort = 200;
	sStatut_Zx[u8Pointeur_buffer_tx].Mode = ARRET;

	sStatut_Zx[u8Pointeur_buffer_tx + 1].i16Tint = 182;
	strcpy((char *)&sConfig_IHM.sParam_Zx[u8Pointeur_buffer_tx + 1].u8NomZone[0], "Etage");
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx + 1].Mode = MARCHE_CHAUD;
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx + 1].i16Consigne_Tint_Reduit = 160;
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx + 1].i16Consigne_Tint_Normal = 186;
	sConfig_IHM.sMode_Zx[u8Pointeur_buffer_tx + 1].i16Consigne_Tint_Confort = 215;
	sStatut_Zx[u8Pointeur_buffer_tx + 1].Mode = MARCHE_CHAUD;
	// Config chauffe dalle
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[0] = 35;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[1] = 40;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[2] = 45;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[3] = 50;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[4] = 40;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[5] = 45;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[6] = 50;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[7] = 35;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[8] = 35;
	sConfig_IHM.sParam_PAC.u8Consigne_Sablier_Dalle[9] = 35;
	// Skip page attente
	sConfig_IHM.u16RecupConfig = 4;
	sConfig_IHM.u16NbCyclique = 6;
	// Secours
	sConfig_IHM.sOption_PAC.TypeAppoint = ELEC;
	// Date
	sDate.Date = 12;
	sDate.Month = 9;
	sDate.Year = 24;
	sDate.Hours = 12;
	sDate.Minutes = 55;
	sDate.WeekDay = 5;
	//
	u16ErreurEncours = ERR_TINT_Z1;

	sConfig_IHM.sModele_PAC.u8ModelePAC = GEOINVERTER;
	sConfig_IHM.sModele_PAC.Gaz_C1 = GAZ_R454C;
	sConfig_IHM.sModele_PAC.bSupply = 0;
	sConfig_IHM.sModele_PAC.bReversible = 0;
	sConfig_IHM.sModele_PAC.u8PwPac = 9;
	sConfig_IHM.sModele_PAC.u8ThermoMaxPac = 75;
	sCyclRegFrigo[0].pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurCapteur = 80;
	sCyclRegFrigo[0].pac.geoinverter.sOutAnaGeoinv.u8ConsigneCirculateurPrimaire = 80;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.u16DebitCapteur = 2365;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.u16DebitPrimaire = 1555;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire = 455;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire = 402;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_DepartCapteur = -34;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_RetourCapteur = -5;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_HP1 = 870;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_BP1 = -40;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Press_HP1= 198;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Press_BP1= 27;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_Liquide= 432;
	sCyclRegFrigo[0].pac.geoinverter.sStatutFrigoGeoinv.i16Temp_HP_Cible[0] = 88;
	sCyclRegFrigo[0].pac.geoinverter.sRetourRukingRe.sDriveStatusInformation.u16CompressorRunningSpeed = 4920;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur = -23;
	sCyclRegFrigo[0].pac.geoinverter.sOutAnaGeoinv.u16PositionDetendeur1 = 267;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Press_EauCapteur= 18;
	sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Press_EauChauffage= 17;

	sStatut_Primaire.i16TeauDepart = sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_DepartPrimaire;
	sStatut_Primaire.i16TeauRetour = sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_RetourPrimaire;
	sStatut_Primaire.u16DebitPrimaire = sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.u16DebitPrimaire;
	sStatut_Primaire.u16In_Pression_Eau = sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Press_EauChauffage;
	sStatut_Primaire.i16ConsigneTeauPrimaire = 480;
	sCyclRegFrigo[0].commun.i16Text = sCyclRegFrigo[0].pac.geoinverter.sInAnaGeoinv.i16Temp_Exterieur;

	// Programmation mode chaud
	int zone, jour, heure;
	memset(au8Prog_Chaud_Zx, 0x55, sizeof (au8Prog_Chaud_Zx));
	for(zone = 0; zone < NB_ZONE; zone++)
	{
		// Semaine
		for(jour = 0; jour < 5; jour++)
		{
			// Confort : 6h/18h
			for(heure = 6; heure < 18; heure++)
			{
				au8Prog_Chaud_Zx[zone][jour][heure] = 0xAA;
			}
			// Confort plus : 18h/23h
			for(heure = 18; heure < 23; heure++)
			{
				au8Prog_Chaud_Zx[zone][jour][heure] = 0xFF;
			}
		}
		// Week-end
		for(jour=5; jour < 7; jour++)
		{
			// Confort : 6h/8h
			for (heure=6; heure < 8; heure++)
			{
				au8Prog_Chaud_Zx[zone][jour][heure] = 0xAA;
			}
			// Confort plus : 8h/23h
			for (heure = 8; heure < 23; heure++)
			{
				au8Prog_Chaud_Zx[zone][jour][heure] = 0xFF;
			}
		}
	}
	// Programmation mode froid
	memset(au8Prog_Froid_Zx, 0x55, sizeof (au8Prog_Froid_Zx));
	for(zone = 0; zone < NB_ZONE; zone++)
	{
		// Confort : 6h/9h et 12h/14 semaine
		for(jour = 0; jour < 5; jour++)
		{
			for(heure = 6; heure < 9; heure++)
			{
				au8Prog_Froid_Zx[zone][jour][heure] = 0xAA;
			}
			for(heure = 12; heure < 14; heure++)
			{
				au8Prog_Froid_Zx[zone][jour][heure] = 0xAA;
			}
		}
		// Confort : 6h/23h week end
		for(jour = 5; jour < 7; jour++)
		{
			for(heure = 6; heure < 23; heure++)
			{
				au8Prog_Froid_Zx[zone][jour][heure] = 0xAA;
			}
		}
	}
	// Programmation régulation externe (24/24)
	memset(au8Prog_Regul_Ext_Chaud, 0x55, sizeof(au8Prog_Regul_Ext_Chaud));
	memset(au8Prog_Regul_Ext_Froid, 0x55, sizeof(au8Prog_Regul_Ext_Froid));
	// Programmation ECS
	memset(au8Prog_ECS, 0, sizeof (au8Prog_ECS));
	for(jour = 0; jour < 7; jour++)
	{
		for(heure = 1; heure < 5; heure++)
		{
			au8Prog_ECS[jour][heure] = 0x55;
		}
	}
	// Programmation piscine
	memset(au8Prog_Piscine, 0, sizeof (au8Prog_Piscine));
	for(jour = 0; jour < 7; jour++)
	{
		for(heure = 5; heure < 11; heure++)
		{
			au8Prog_Piscine[jour][heure] = 0x55;
		}
		for(heure = 18; heure < 23; heure++)
		{
			au8Prog_Piscine[jour][heure] = 0x55;
		}
	}
	#endif
}

void Model::tick()
{
#ifndef SIMULATOR
	if(gTouched == 0 && bAutorisationCompteurVeille && !u16ErreurEncours)
	{
		if (oui_veille == 1)
		{
			veilleCounter++;
		}
		if(veilleCounter == VEILLE_1_COUNT)
		{
			setBackLightPWM(PWM_VEILLE_1);
		}
		else if(veilleCounter == VEILLE_2_COUNT)
		{
			static_cast<FrontendApplication*>(touchgfx::Application::getInstance())->gotoVeilleScreenNoTransition();
		}
		else if(veilleCounter > VEILLE_2_COUNT)
		{
			veilleCounter--;
		}
	}
	else
	{
		//Si pas là on a un clignottement sur la page de luminosité
		if(veilleCounter >= VEILLE_1_COUNT)
		{
			exitVeille();
		}
		gTouched = 0;
		veilleCounter = 0;
	}

	//Si Message vérification annuelle
	if (bMessageEnCoursAffichage)
	{
		oui_veille = 0;
		exitVeille();
		gTouched = 0;
		veilleCounter = 0;
	}

	//Si Défaut en cours => on sort de veille et reste allumé
	if (u16ErreurEncours && !page_accueil_displayed)
	{
		static_cast<FrontendApplication*>(touchgfx::Application::getInstance())->gotoAccueilScreenNoTransition();
		page_accueil_displayed = 1;
	}
	else if(!u16ErreurEncours)
	{
		page_accueil_displayed = 0;
	}

	//Pour l'affichage de l'historique des températures
	recordCounter++;
	if (recordCounter >= TIMER_RECORD_10S)
	{
		recordCounter = 0;
		update_data_histo();
		modelListener->update_graph_histo(&data_histo);

		if (bDdeRestartCartes)
		{
#ifndef SIMULATOR
		NVIC_SystemReset();
#endif
		}
	}
#endif

  if(dataUpdated != 0)
  {
    modelListener->changeModePac(cosebe_test.bModePAC);
    dataUpdated = 0;
  }
  if(arkteos_update.date_update)
  {
    modelListener->changeDate(&sDate);
    arkteos_update.date_update = false;
    MessageControlePeriodique();
  }
  if(arkteos_update.erreur_update)
  {
    modelListener->changeErreur(u16ErreurEncours);
    arkteos_update.erreur_update = false;
  }
  if(arkteos_update.statut_primaire_update)
  {
    modelListener->changeStatutPrimaire(&sStatut_Primaire);
    arkteos_update.statut_primaire_update = false;
  }
  if(arkteos_update.statut_zx_update[0])
  {
    modelListener->changeStatutZx(0, &sStatut_Zx[0]);
    arkteos_update.statut_zx_update[0] = false;
  }
  if(arkteos_update.statut_zx_update[1])
  {
    modelListener->changeStatutZx(1, &sStatut_Zx[1]);
    arkteos_update.statut_zx_update[1] = false;
  }
  if(arkteos_update.statut_zx_update[2])
  {
    modelListener->changeStatutZx(2, &sStatut_Zx[2]);
    arkteos_update.statut_zx_update[2] = false;
  }
  if(arkteos_update.statut_zx_update[3])
  {
    modelListener->changeStatutZx(3, &sStatut_Zx[3]);
    arkteos_update.statut_zx_update[3] = false;
  }
  if(arkteos_update.statut_zx_update[4])
  {
    modelListener->changeStatutZx(4, &sStatut_Zx[4]);
    arkteos_update.statut_zx_update[4] = false;
  }
  if(arkteos_update.statut_zx_update[5])
  {
    modelListener->changeStatutZx(5, &sStatut_Zx[5]);
    arkteos_update.statut_zx_update[5] = false;
  }
  if(arkteos_update.statut_zx_update[6])
  {
    modelListener->changeStatutZx(6, &sStatut_Zx[6]);
    arkteos_update.statut_zx_update[6] = false;
  }
  if(arkteos_update.statut_zx_update[7])
  {
    modelListener->changeStatutZx(7, &sStatut_Zx[7]);
    arkteos_update.statut_zx_update[7] = false;
  }
  if(arkteos_update.statut_zx_update[8])
  {
    modelListener->changeStatutZx(8, &sStatut_Zx[8]);
    arkteos_update.statut_zx_update[8] = false;
  }
  if(arkteos_update.statut_zx_update[9])
  {
    modelListener->changeStatutZx(9, &sStatut_Zx[9]);
    arkteos_update.statut_zx_update[9] = false;
  }
  if(arkteos_update.statut_pac_update)
  {
	modelListener->changeStatutPAC(&sStatut_PAC);
	if(sStatut_PAC.ModifConfig)
	{
		c_recup_config(0);
		c_recup_config(1);
		c_recup_config(2);
		if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA || sConfig_IHM.sModele_PAC.u8ModelePAC == PHOENIX || sConfig_IHM.sModele_PAC.u8ModelePAC == ARKTEA)
		{
			c_recup_config(3);
		}
	}
	else if(sStatut_PAC.ModifConfigSimple)
	{
		c_recup_config(1);
	}
	arkteos_update.statut_pac_update = false;
  }
  if(arkteos_update.statut_ether_update)
  {
    modelListener->changeStatutEther(&sCycEther);
    arkteos_update.statut_ether_update = false;
  }
  if(arkteos_update.statut_ecs_update)
  {
    modelListener->changeStatutECS(&sStatut_ECS);
    arkteos_update.statut_ecs_update = false;
  }
  if(arkteos_update.statut_piscine_update)
  {
    modelListener->changeStatutPiscine(&sStatut_Piscine);
    arkteos_update.statut_piscine_update = false;
  }
  if(arkteos_update.statut_regul_ext_update)
  {
    modelListener->changeStatutRegulExt(&sStatut_RegulExt);
    arkteos_update.statut_regul_ext_update = false;
  }
  if(arkteos_update.cycl_frigo_update)
  {
    modelListener->changeStatutCyclFrigo(&sCyclRegFrigo[0]);
    arkteos_update.cycl_frigo_update = false;
  }
  if(arkteos_update.config_update)
  {
    modelListener->changeConfig(&sConfig_IHM);
    arkteos_update.config_update = false;
  }
  if(arkteos_update.demande_frigo_update)
  {

//    switch (sDemandeFrigo.sSupplementPAC.)
//    switch (sConfig_IHM.sModele_PAC.u8ModelePAC)
//	{
//    	case GEOTWIN_IV	:
//    		sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.Geo.u4NumOffset] = sDemandeFrigo.sSupplementPAC.Geo.u8Offset;
//    		break;
//    	case GEOINVERTER:
//    		sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.geoinverter.u4NumOffset] = sDemandeFrigo.sSupplementPAC.geoinverter.u8Offset;
//    		break;
//    	case CAIROX :
//    		sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.geoinverter.u4NumOffset] = sDemandeFrigo.sSupplementPAC.geoinverter.u8Offset;
//			break;
//    	case BAGUIO_ZURAN_IV :
//		case TIMAX_III:
//			sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.ZuranBaguio.u4NumOffset] = sDemandeFrigo.sSupplementPAC.ZuranBaguio.u8Offset;
//			break;
//    	case AJPAC_III :
//    		sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.Ajpac.u4NumOffset] = sDemandeFrigo.sSupplementPAC.Ajpac.u8Offset;
//			break;
//    	case PHOENIX :
//    		sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.phoenix.u4NumOffset] = sDemandeFrigo.sSupplementPAC.phoenix.u8Offset;
//    		break;
//    	case ARKTEA:
//    		sConfig_Offset.i8Val[sDemandeFrigo.sSupplementPAC.arktea.u4NumOffset] = sDemandeFrigo.sSupplementPAC.arktea.u8Offset;
//    		break;
//    }
    modelListener->changeDemandeFrigo(&sDemandeFrigo);
    arkteos_update.demande_frigo_update = false;
  }
  if(arkteos_update.statut_rf_update)
  {
	modelListener->changeStatutRF(&sStatut_RF[0]);
	arkteos_update.statut_rf_update = false;
  }

  if(arkteos_update.statut_regul_esclave_update)
  {
	modelListener->changeStatutRegulEsclave(&sStatut_RegulEsclave);
	arkteos_update.statut_regul_esclave_update = false;
  }

  if(arkteos_update.statut_tps_fonct_update)
   {
 	modelListener->changeStatutTempsFonct(&sStatut_TpsFonct);
 	arkteos_update.statut_tps_fonct_update = false;
   }
}

//void Model::energieState(uint16_t state)
//{
//	if(state != cosebe_tx.u16Data)
//	{
//		cosebe_tx.u16Data = state;
//		sendData = 1;
//	}
//}

void Model::enterVeille()
{
#ifdef SIMULATOR
  touchgfx_printf("Veille \n");
#else
  setBackLightPWM(0);
#endif
}

void Model::editLuminosite(uint8_t u8Luminosite)
{
#ifndef SIMULATOR
	setBackLightPWM(u8Luminosite);
#endif
}

void Model::exitVeille()
{
#ifdef SIMULATOR
  touchgfx_printf("activation \n");
#else
  if(sConfig_IHM.sParam_Utilisateur.u7Luminosite != 0)
  {
	setBackLightPWM(sConfig_IHM.sParam_Utilisateur.u7Luminosite);
  }
  else setBackLightPWM(100);
//  uint8_t PWMActive = 100;
//  setBackLightPWM(PWMActive);
#endif
}

void Model::MessageControlePeriodique()
{
//	if (!bMessageControleAnodeActif
//			&& sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle != 0
//			&& ((sDate.Year - sConfig_IHM.sInstall_PAC.sDateMiseEnService.Year) > (sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle - 1))
//		    && sDate.Month >=  sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month && sDate.Date >=  sConfig_IHM.sInstall_PAC.sDateMiseEnService.Date)
//		|| (((sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month <= 6 && (sDate.Month - sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month) >= 6)
//		||(sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month > 6 && sDate.Month >= (sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month - 6)
//				&& sDate.Year > sConfig_IHM.sInstall_PAC.sDateMiseEnService.Year))
//				&& sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle == 0
//				&& sDate.Date >= sConfig_IHM.sInstall_PAC.sDateMiseEnService.Date))
//		&& !bActionMessage))
//		{
//			;
//		}
	//*********Fin premier commentaire
//			// Conditions intermédiaires pour plus de clarté
//		bool verificationAnnuelleActive = (sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle != 0);
//		bool verificationAnnuelleInactive = (sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle == 0);
//
//		bool delaiAnneeDepasse =
//			(sDate.Year - sConfig_IHM.sInstall_PAC.sDateMiseEnService.Year) >
//			(sConfig_IHM.sInstall_PAC.u5VerificationAnnuelle - 1);
//
//		bool dateDepassee =
//			sDate.Month >= sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month &&
//			sDate.Date  >= sConfig_IHM.sInstall_PAC.sDateMiseEnService.Date;
//
//		// Cas 1 : vérification annuelle activée
//		bool conditionAnnuelle =
//			verificationAnnuelleActive &&
//			delaiAnneeDepasse &&
//			dateDepassee;
//
//		// Cas 2 : vérification tous les 6 mois si non annuelle
//		bool conditionSemestrielle = false;
//
//		if (verificationAnnuelleInactive)
//		{
//			bool moisInferieur =
//				sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month <= 6 &&
//				(sDate.Month - sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month) >= 6;
//
//			bool moisSuperieur =
//				sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month > 6 &&
//				sDate.Month >= (sConfig_IHM.sInstall_PAC.sDateMiseEnService.Month - 6) &&
//				sDate.Year > sConfig_IHM.sInstall_PAC.sDateMiseEnService.Year;
//
//			conditionSemestrielle = (moisInferieur || moisSuperieur) && dateDepassee;
//		}
//
//		// Condition finale
//		if ((conditionAnnuelle || conditionSemestrielle) && !bMessageEnCoursAffichage && bRecupConfigTermine)
//		{
//			bMessageEnCoursAffichage = true;
//			static_cast<FrontendApplication*>(touchgfx::Application::getInstance())->gotoVerification_annuelleScreenNoTransition();
//		}

	// --- Conditions globales de sécurité ---
	    if (bMessageEnCoursAffichage || !bRecupConfigTermine)
	        return;

	    const auto& install = sConfig_IHM.sInstall_PAC;
	    const auto& dateMS = install.sDateMiseEnService;
	    const auto& dateCourante = sDate;

	    // --- Vérification de validité ---
	    if (dateMS.Year == 0 || dateCourante.Year == 0)
	        return;

	    // --- Calcul du nombre total de mois écoulés depuis la mise en service ---
	    int totalMonthsService = (dateCourante.Year - dateMS.Year) * 12 + (dateCourante.Month - dateMS.Month);

	    // Si on n’a pas encore atteint le jour exact du mois, on considère que le mois n’est pas encore complet
	    if (dateCourante.Date < dateMS.Date)
	        totalMonthsService--;

	    if (totalMonthsService < 0)
	        return; // Date système incohérente

	    // --- Calcul de la période cible en fonction du nombre de vérifications déjà effectuées ---
	    int periodeCible = 0; // en mois

	    if (install.u5VerificationAnnuelle == 0)
	    {
	        // Première vérification : à 6 mois après la mise en service
	        periodeCible = 6;
	    }
	    else
	    {
	        // Vérifications suivantes : tous les ans à partir de la première
	        periodeCible = 6 + (install.u5VerificationAnnuelle * 12);
	    }

	    // --- Condition d’affichage ---
	    if (totalMonthsService >= periodeCible)
	    {
	        // Sécurité : ne pas relancer pour la même valeur de u5VerificationAnnuelle
	        static uint8_t derniereVerifDeclenchee = 0xFF;
	        if (derniereVerifDeclenchee == install.u5VerificationAnnuelle)
	            return; // Déjà traité pour cette période

	        derniereVerifDeclenchee = install.u5VerificationAnnuelle;

	        // Déclenchement de l’affichage du message
	        bMessageEnCoursAffichage = true;

	        static_cast<FrontendApplication*>(touchgfx::Application::getInstance())
	            ->gotoVerification_annuelleScreenNoTransition();
	    }
}

void Model::update_data_histo()
{
	bool bConfigBallon = sConfig_Hydrau_temp.u8TypeRegul >= REGUL_BAL_TAMPON_MULTI_ZONE;
	static bool bPremierPassage = true;

	 if (bConfigBallon)
	{
		 data_histo.u16TempBallon_Z1[data_histo.u16PointeurTableau] = sStatut_Primaire.i16TeauBallonTampon;
	}
	else
	{
		//Zone 1
		if (sConfig_IHM.sParam_Zx[0].type_zone.zone.TypeThermostat == TH_RF || sConfig_IHM.sParam_Zx[0].type_zone.zone.TypeThermostat == TH_MODBUS)
		{
			data_histo.u16TempBallon_Z1[data_histo.u16PointeurTableau] = sStatut_Zx[0].i16Tint;
		}
		else
		{
			if (sStatut_PAC.sFonctInxTor.bTorTH1 == 0)
			{
				data_histo.u16TempBallon_Z1[data_histo.u16PointeurTableau] = 100;
			}
			else
			{
				data_histo.u16TempBallon_Z1[data_histo.u16PointeurTableau] = 190;
			}
		}
		//Zone 2
		if (sConfig_IHM.sParam_Zx[1].type_zone.zone.TypeThermostat == TH_RF || sConfig_IHM.sParam_Zx[1].type_zone.zone.TypeThermostat == TH_MODBUS)
		{
			data_histo.u16Temp_Z2[data_histo.u16PointeurTableau] = sStatut_Zx[1].i16Tint;
		}
		else
		{
			if (sStatut_PAC.sFonctInxTor.bTorTH1 == 0)
			{
				data_histo.u16Temp_Z2[data_histo.u16PointeurTableau] = 100;
			}
			else
			{
				data_histo.u16Temp_Z2[data_histo.u16PointeurTableau] = 190;
			}
		}
	}
	 data_histo.i16TempExt[data_histo.u16PointeurTableau] = sCyclRegFrigo[0].commun.i16Text;
	 data_histo.u16TempDepart[data_histo.u16PointeurTableau] = sStatut_Primaire.i16TeauDepart;
	 data_histo.u16TempRetour[data_histo.u16PointeurTableau] = sStatut_Primaire.i16TeauRetour;


	//Init des val max
	if (bPremierPassage)
	{
		if (bConfigBallon)
		{
			data_histo.u16ValmaxAmbBall = data_histo.u16TempBallon_Z1[0] + 10;
			data_histo.u16ValminAmbBall = data_histo.u16TempBallon_Z1[0] - 10;
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 && sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				data_histo.u16ValmaxAmbBall = (data_histo.u16TempBallon_Z1[0]>data_histo.u16Temp_Z2[0]) ? data_histo.u16TempBallon_Z1[0] + 10:data_histo.u16Temp_Z2[0] + 10;
				data_histo.u16ValminAmbBall = (data_histo.u16TempBallon_Z1[0]<data_histo.u16Temp_Z2[0]) ? data_histo.u16TempBallon_Z1[0] - 10:data_histo.u16Temp_Z2[0] - 10;
			}
			else if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				data_histo.u16ValmaxAmbBall = data_histo.u16TempBallon_Z1[0] + 10;
				data_histo.u16ValminAmbBall = data_histo.u16TempBallon_Z1[0] - 10;
			}
			else
			{
				data_histo.u16ValmaxAmbBall = data_histo.u16Temp_Z2[0] + 10;
				data_histo.u16ValminAmbBall = data_histo.u16Temp_Z2[0] - 10;
			}
		}
		data_histo.u16ValmaxTeau = (data_histo.u16TempDepart[0]>data_histo.u16TempRetour[0]) ? data_histo.u16TempDepart[0] + 10:data_histo.u16TempRetour[0] + 10;
		data_histo.u16ValminTeau = (data_histo.u16TempDepart[0]<data_histo.u16TempRetour[0]) ? data_histo.u16TempDepart[0] - 10:data_histo.u16TempRetour[0] - 10;
		data_histo.i16ValmaxText = data_histo.i16TempExt[0] + 10;
		data_histo.i16ValminText = data_histo.i16TempExt[0] - 10;

		bPremierPassage = false;
	}

	data_histo.limit = data_histo.bTableauPlein ? 360 : data_histo.u16PointeurTableau;
	for (uint16_t i = 0; i < data_histo.limit; i++)
	{
		//Page 1
		if (bConfigBallon)
		{
			data_histo.valmaxgaucheP1 = data_histo.u16TempBallon_Z1[i];
			if (data_histo.valmaxgaucheP1 > data_histo.u16ValmaxAmbBall) data_histo.u16ValmaxAmbBall = data_histo.valmaxgaucheP1 + 10;
			data_histo.valmingaucheP1 = data_histo.u16TempBallon_Z1[i];
			if (data_histo.valmingaucheP1 < data_histo.u16ValminAmbBall) data_histo.u16ValminAmbBall = data_histo.valmingaucheP1 - 10;
		}
		else
		{
			if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1 && sConfig_IHM.sOption_PAC.sZone.zone.bZone2)
			{
				data_histo.valmaxgaucheP1 = (data_histo.u16TempBallon_Z1[i]>data_histo.u16Temp_Z2[i]) ? data_histo.u16TempBallon_Z1[i]:data_histo.u16Temp_Z2[i];
				if (data_histo.valmaxgaucheP1 > data_histo.u16ValmaxAmbBall) data_histo.u16ValmaxAmbBall = data_histo.valmaxgaucheP1 + 10;
				data_histo.valmingaucheP1 = (data_histo.u16TempBallon_Z1[i]<data_histo.u16Temp_Z2[i]) ? data_histo.u16TempBallon_Z1[i]:data_histo.u16Temp_Z2[i];
				if (data_histo.valmingaucheP1 < data_histo.u16ValminAmbBall) data_histo.u16ValminAmbBall = data_histo.valmingaucheP1 - 10;
			}
			else if (sConfig_IHM.sOption_PAC.sZone.zone.bZone1)
			{
				data_histo.valmaxgaucheP1 = data_histo.u16TempBallon_Z1[i];
				if (data_histo.valmaxgaucheP1 > data_histo.u16ValmaxAmbBall) data_histo.u16ValmaxAmbBall = data_histo.valmaxgaucheP1 + 10;
				data_histo.valmingaucheP1 = data_histo.u16TempBallon_Z1[i];
				if (data_histo.valmingaucheP1 < data_histo.u16ValminAmbBall) data_histo.u16ValminAmbBall = data_histo.valmingaucheP1 - 10;
			}
			else
			{
				data_histo.valmaxgaucheP1 = data_histo.u16Temp_Z2[i];
				if (data_histo.valmaxgaucheP1 > data_histo.u16ValmaxAmbBall) data_histo.u16ValmaxAmbBall = data_histo.valmaxgaucheP1 + 10;
				data_histo.valmingaucheP1 = data_histo.u16Temp_Z2[i];
				if (data_histo.valmingaucheP1 < data_histo.u16ValminAmbBall) data_histo.u16ValminAmbBall = data_histo.valmingaucheP1 - 10;
			}
		}

		//Page 2
		data_histo.valmaxgaucheP2 = (data_histo.u16TempDepart[i]>data_histo.u16TempRetour[i]) ? data_histo.u16TempDepart[i]:data_histo.u16TempRetour[i];
		if (data_histo.valmaxgaucheP2 > data_histo.u16ValmaxTeau) data_histo.u16ValmaxTeau = data_histo.valmaxgaucheP2 + 10;
		data_histo.valmingaucheP2 = (data_histo.u16TempDepart[i]<data_histo.u16TempRetour[i]) ? data_histo.u16TempDepart[i]:data_histo.u16TempRetour[i];
		if (data_histo.valmingaucheP2 < data_histo.u16ValminTeau) data_histo.u16ValminTeau = data_histo.valmingaucheP2 - 10;

		//Page 1 & 2
		data_histo.valmaxdroiteP1P2 = data_histo.i16TempExt[i];
		if (data_histo.valmaxdroiteP1P2 > data_histo.i16ValmaxText) data_histo.i16ValmaxText = data_histo.valmaxdroiteP1P2 + 10;
		data_histo.valmindroiteP1P2 = data_histo.i16TempExt[i];
		if (data_histo.valmindroiteP1P2 < data_histo.i16ValminText) data_histo.i16ValminText = data_histo.valmindroiteP1P2 - 10;

	}
	//Statut PAC
	switch(sStatut_PAC.S_Mode)
	{
		case S_ARRET:
			data_histo.etat_pac[data_histo.u16PointeurTableau] = COLOR_NONE;
			break;
		case S_ATTENTE:
			data_histo.etat_pac[data_histo.u16PointeurTableau] = COLOR_BLANC;
			break;

		case S_CHAUD:
		case S_CHAUD_FROID:
		case S_HORS_GEL:
		case S_EXT_CHAUD:
			data_histo.etat_pac[data_histo.u16PointeurTableau] = COLOR_ORANGE;
			break;

		case S_FROID:
		case S_EXT_FROID:
			data_histo.etat_pac[data_histo.u16PointeurTableau] = COLOR_BLEU;
			break;
		case S_ECS :
			data_histo.etat_pac[data_histo.u16PointeurTableau] = COLOR_ROSE;
			break;
		case S_PISCINE:
			data_histo.etat_pac[data_histo.u16PointeurTableau] = COLOR_VERT;
		break;
		default:
			break;
	}

	//Statut appoint PAC
	if (sStatut_PAC.sOutTor.Pw_Relec != 0) data_histo.etat_app_chaud[data_histo.u16PointeurTableau] = COLOR_ROUGE;
	else data_histo.etat_app_chaud[data_histo.u16PointeurTableau] = COLOR_NONE;

	//Statut appoint ECS
	if (sStatut_ECS.bOutTorAppoint_ECS != 0) data_histo.etat_app_ecs[data_histo.u16PointeurTableau] = COLOR_ROSE;
	else data_histo.etat_app_ecs[data_histo.u16PointeurTableau] = COLOR_NONE;


	data_histo.u16PointeurTableau++;
	if (data_histo.u16PointeurTableau >= 360)
	{
		data_histo.u16PointeurTableau = 0;
		data_histo.bTableauPlein = true;
	}
}

void Model::c_user_param()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
//	txData[u8Pointeur_buffer_tx].data[0] = CONTROL_WRITE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_PARAM;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_PAC) + sizeof(S_PARAM_UTILISATEUR);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_PAC, sizeof(S_MODE_PAC));
  u16Pointeur += sizeof(S_MODE_PAC);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_Utilisateur, sizeof(S_PARAM_UTILISATEUR));
  u16Pointeur += sizeof(S_PARAM_UTILISATEUR);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_vacances()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_VACANCES;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_ZX)*NB_ZONE + sizeof(S_MODE_ECS) + sizeof(S_MODE_PISCINE) + sizeof(S_MODE_REG_EXT) + sizeof(S_PARAM_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_Zx[0], sizeof(S_MODE_ZX) * NB_ZONE);
  u16Pointeur += sizeof(S_MODE_ZX) * NB_ZONE;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_ECS, sizeof(S_MODE_ECS));
  u16Pointeur += sizeof(S_MODE_ECS);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_Piscine, sizeof(S_MODE_PISCINE));
  u16Pointeur += sizeof(S_MODE_PISCINE);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_RegulExt, sizeof(S_MODE_REG_EXT));
  u16Pointeur += sizeof(S_MODE_REG_EXT);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_PAC, sizeof(S_PARAM_PAC));
  u16Pointeur += sizeof(S_PARAM_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_ecs()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
//	txData[u8Pointeur_buffer_tx].data[0] = CONTROL_WRITE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_ECS;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_ECS);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_ECS, sizeof(S_MODE_ECS));
  u16Pointeur += sizeof(S_MODE_ECS);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_zx(uint8_t u8Zone)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_Z1 + u8Zone;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_ZX);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_Zx[u8Zone], sizeof(S_MODE_ZX));
  u16Pointeur += sizeof(S_MODE_ZX);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_zx_all()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_ZX;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_PAC)+ sizeof(S_MODE_ZX) * NB_ZONE  + sizeof(S_MODE_REG_EXT) + sizeof(S_MODE_ECS) + sizeof(S_MODE_PISCINE);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_PAC, sizeof(S_MODE_PAC));
  u16Pointeur += sizeof(S_MODE_PAC);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_Zx[0], sizeof(S_MODE_ZX) * NB_ZONE);
  u16Pointeur += sizeof(S_MODE_ZX) * NB_ZONE;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_RegulExt, sizeof(S_MODE_REG_EXT));
u16Pointeur += sizeof(S_MODE_REG_EXT);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_ECS, sizeof(S_MODE_ECS));
  u16Pointeur += sizeof(S_MODE_ECS);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_Piscine, sizeof(S_MODE_PISCINE));
  u16Pointeur += sizeof(S_MODE_PISCINE);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_reg_ext()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_REG_EXT;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_REG_EXT);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_RegulExt, sizeof(S_MODE_REG_EXT));
  u16Pointeur += sizeof(S_MODE_REG_EXT);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_piscine()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_PISCINE;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODE_PISCINE);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sMode_Piscine, sizeof(S_MODE_PISCINE));
  u16Pointeur += sizeof(S_MODE_PISCINE);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_user_date()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USER_DATE;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_DATE);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sDate_modif, sizeof(S_DATE));
  u16Pointeur += sizeof(S_DATE);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_raz()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_RAZ_DATE;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_cumul_prod()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_CUMUL_PROD + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_cumul_conso()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_CUMUL_CONS + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_histo_12m_conso()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_CONS_12M + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_histo_24j_conso()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_CONS_24J + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_histo_24h_conso()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_CONS_24H + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_histo_12m_prod()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_PROD_12M + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_histo_24j_prod()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_PROD_24J + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_ener_histo_24h_prod()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_ENER_PROD_24H + CONTROL_READ;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_recup_config(uint8_t u8RecupConfig)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

//	if(u8RecupConfig == 0 || (u8RecupConfig == 3 && sConfig_IHM.sModele_PAC.u8ModelePAC != INVERTERRA))
//	{
//		txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
//	}
//	else txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
//
//	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
//	txData[u8Pointeur_buffer_tx].data[2] = RECUP_CONFIG;
//	//	txData[u8Pointeur_buffer_tx].data[0] = CONTROL_WRITE;
//
//	if(u8RecupConfig == 2)//|| u8RecupConfig == 5)
//	{
//		txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_TRAME2;
//	}
//	else if(u8RecupConfig == 3 && sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA)
//	{
//		txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_CONFIG_PHOENIX;
//	}
//	else txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_GENERAL;

	//Ajout
	switch(u8RecupConfig)
	{
		case 0:
			txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
			txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_GENERAL;
			break;
		case 1:
			txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
			txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_GENERAL;
			break;
		case 2:
			txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
			txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_TRAME2;
			break;
		case 3:
			if (sConfig_IHM.sModele_PAC.u8ModelePAC != INVERTERRA)
			{
				txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
				txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_GENERAL;
			}
			else
			{
				txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
				txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_CONFIG_PHOENIX;
			}
			break;
	}
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = RECUP_CONFIG;
	//Fin ajout

	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
    u16Pointeur = 6;
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

//
//void Model::c_recup_config(uint8_t u8RecupConfig)
//{
//	uint16_t u16Pointeur = 0, u16CRC = 0;
//
//	if(u8RecupConfig == 0)
//	{
//		txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
//	}
//	else txData[0].data[0] = N_ADD_REG;
//	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
//	txData[u8Pointeur_buffer_tx].data[2] = RECUP_CONFIG;
//	//	txData[u8Pointeur_buffer_tx].data[0] = CONTROL_WRITE;
//
//	if(u8RecupConfig == 2)
//	{
//		txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_TRAME2;
//	}
//	else if(u8RecupConfig == 3)
//	{
//		txData[u8Pointeur_buffer_tx].data[3] = SC_RECUP_CONFIG_PHOENIX;
//	}
//	else txData[0].data[3] = SC_RECUP_GENERAL;
//
//	txData[u8Pointeur_buffer_tx].data[4] = 0;
//	txData[u8Pointeur_buffer_tx].data[5] = 0;
//    u16Pointeur = 6;
//	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
//	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
//	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;
//
//	txData[u8Pointeur_buffer_tx].size = u16Pointeur;
//
//	if(++u8Pointeur_buffer_tx > 9)
//	{
//		u8Pointeur_buffer_tx = 0;
//	}
//}

void Model::c_prog_ecs(bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_ECS;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_ECS); //txData[0].data[4] = 168;//sizeof(au8Prog_ECS);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_ECS, sizeof(au8Prog_ECS));
    u16Pointeur += sizeof(au8Prog_ECS);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_option(bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_OPTIONS;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
 else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_Options);//txData[0].data[4] = sizeof(au8Prog_Options);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_Options, sizeof(au8Prog_Options));
    u16Pointeur += sizeof(au8Prog_Options);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_piscine(bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_PISCINE;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_Piscine);//txData[0].data[4] = sizeof(au8Prog_Piscine);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_Piscine, sizeof(au8Prog_Piscine));
    u16Pointeur += sizeof(au8Prog_Piscine);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_silence(bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_MODE_SILENCE;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_ModeSilence);//txData[0].data[4] = sizeof(au8Prog_ModeSilence);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_ModeSilence, sizeof(au8Prog_ModeSilence));
    u16Pointeur += sizeof(au8Prog_ModeSilence);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_CHAUD_Z1 + u8Zone;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_Chaud_Zx[u8Zone]);//txData[0].data[4] = sizeof(au8Prog_Chaud_Zx[u8Zone]);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_Chaud_Zx[u8Zone], sizeof(au8Prog_Chaud_Zx[u8Zone]));
    u16Pointeur += sizeof(au8Prog_Chaud_Zx[u8Zone]);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_FROID_Z1 + u8Zone;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_Froid_Zx[u8Zone]);//txData[0].data[4] = sizeof(au8Prog_Froid_Zx[u8Zone]);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_Froid_Zx[u8Zone], sizeof(au8Prog_Froid_Zx[u8Zone]));
    u16Pointeur += sizeof(au8Prog_Froid_Zx[u8Zone]);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_reg_ext_chaud(bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_EXT_CHAUD;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_Regul_Ext_Chaud);//txData[0].data[4] = sizeof(au8Prog_Regul_Ext_Chaud);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_Regul_Ext_Chaud, sizeof(au8Prog_Regul_Ext_Chaud));
    u16Pointeur += sizeof(au8Prog_Regul_Ext_Chaud);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_prog_reg_ext_froid(bool bEnvoi)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USER_PROG;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PROG_EXT_FROID;
  if(bEnvoi == false)
  {
		txData[u8Pointeur_buffer_tx].data[3] += CONTROL_READ;
		txData[u8Pointeur_buffer_tx].data[4] = 0;
  }
  else txData[u8Pointeur_buffer_tx].data[4] = sizeof(au8Prog_Regul_Ext_Froid);//txData[0].data[4] = sizeof(au8Prog_Regul_Ext_Froid);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;
  if(bEnvoi == true)
  {
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &au8Prog_Regul_Ext_Froid, sizeof(au8Prog_Regul_Ext_Froid));
    u16Pointeur += sizeof(au8Prog_Regul_Ext_Froid);
  }
	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_raz_config()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_RAZ_CONFIG;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_date_install()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_DATE_INSTALL;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_CONFIG_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sInstall_PAC.sDateMiseEnService, sizeof(sConfig_IHM.sInstall_PAC.sDateMiseEnService));
  u16Pointeur += sizeof(sConfig_IHM.sInstall_PAC.sDateMiseEnService);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_config_pac()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_CONFIG_PAC;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_CONFIG_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sConfig_PAC, sizeof(S_CONFIG_PAC));
  u16Pointeur += sizeof(S_CONFIG_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_install_pac()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_INSTALL_PAC;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_INSTALL_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sInstall_PAC, sizeof(S_INSTALL_PAC));
  u16Pointeur += sizeof(S_INSTALL_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_piscine()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PARAM_PISCINE;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_PISCINE);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_Piscine, sizeof(S_PARAM_PISCINE));
  u16Pointeur += sizeof(S_PARAM_PISCINE);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_ecs()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PARAM_ECS;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_ECS);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_ECS, sizeof(S_PARAM_ECS));
  u16Pointeur += sizeof(S_PARAM_ECS);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_param()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_PARAM;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_OPTION_PAC) + sizeof(S_PARAM_PAC) + sizeof(S_PARAM_FRIGO);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sOption_PAC, sizeof(S_OPTION_PAC));
  u16Pointeur += sizeof(S_OPTION_PAC);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_PAC, sizeof(S_PARAM_PAC));
  u16Pointeur += sizeof(S_PARAM_PAC);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_Frigo, sizeof(S_PARAM_FRIGO));
  u16Pointeur += sizeof(S_PARAM_FRIGO);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_modbus()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_MODBUS;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_ETHER_MODBUS_III);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParamModbus, sizeof(S_PARAM_ETHER_MODBUS_III));
  u16Pointeur += sizeof(S_PARAM_ETHER_MODBUS_III);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_raz_histo_err()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_RAZ_HISTO_ERR;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_reg_ext()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PARAM_REG_EXT;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_REG_EXT);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_RegulExt, sizeof(S_PARAM_REG_EXT));
	u16Pointeur += sizeof(S_PARAM_REG_EXT);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_zx(uint8_t u8Zone)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PARAM_Z1 + u8Zone;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_ZX);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_Zx[u8Zone], sizeof(S_PARAM_ZX));
	u16Pointeur += sizeof(S_PARAM_ZX);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_param_zx()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL;
	txData[u8Pointeur_buffer_tx].data[3] = SC_PARAM_ZX;
	txData[u8Pointeur_buffer_tx].data[4] = (((sizeof(S_PARAM_ZX))*10) + sizeof(S_PARAM_ECS) + sizeof(S_PARAM_PISCINE) + sizeof(S_PARAM_REG_EXT))&0xFF;
	txData[u8Pointeur_buffer_tx].data[5] = ((((sizeof(S_PARAM_ZX))*10) + sizeof(S_PARAM_ECS) + sizeof(S_PARAM_PISCINE) + sizeof(S_PARAM_REG_EXT)) >> 8) & 0xFF;
	u16Pointeur = 6;

	for (int i = 0; i < 10 ; i++)
	{
		memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_Zx[i], sizeof(S_PARAM_ZX));
		u16Pointeur += sizeof(S_PARAM_ZX);
	}

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_RegulExt, sizeof(S_PARAM_REG_EXT));
	u16Pointeur += sizeof(S_PARAM_REG_EXT);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_ECS, sizeof(S_PARAM_ECS));
	u16Pointeur += sizeof(S_PARAM_ECS);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_Piscine, sizeof(S_PARAM_PISCINE));
	u16Pointeur += sizeof(S_PARAM_PISCINE);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_th_association(uint8_t u8NumZone)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL_THERMOSTAT;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_TH_ASSO_Z1 + u8NumZone;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_install_th_dissociation(uint8_t u8NumZone)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_INSTALL_THERMOSTAT;
	txData[u8Pointeur_buffer_tx].data[3] = SC_INSTALL_TH_DISSO_Z1 + u8NumZone;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_usine_param()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USINE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USINE_PARAM;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODELE_PAC) + sizeof(S_CONFIG_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sModele_PAC, sizeof(S_MODELE_PAC));
  u16Pointeur += sizeof(S_MODELE_PAC);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sConfig_PAC, sizeof(S_CONFIG_PAC));
  u16Pointeur += sizeof(S_CONFIG_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_usine_offset()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USINE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USINE_OFFSET;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_CONFIG_OFFSET);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_Offset, sizeof(S_CONFIG_OFFSET));
  u16Pointeur += sizeof(S_CONFIG_OFFSET);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_usine_password()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USINE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USINE_PASSWORD;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_INSTALL_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sInstall_PAC, sizeof(S_INSTALL_PAC));
  u16Pointeur += sizeof(S_INSTALL_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_usine_phoenix(int u8Esclave)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_FRIGO + u8Esclave;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USINE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USINE_GENERAL;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_MODELE_FRIGO);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sConfigFrigo[u8Esclave].sModele_FRIGO, sizeof(S_MODELE_FRIGO));
  u16Pointeur += sizeof(S_MODELE_FRIGO);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_usine_raz_energie()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USINE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USINE_RAZ_ENERGIE;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_usine_raz_config()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_USINE;
	txData[u8Pointeur_buffer_tx].data[3] = SC_USINE_RAZ_CONFIG;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_histo_err()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_HISTO_ERR;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_param()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_PARAM;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(u16NumAction) + sizeof(u32ValAction);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &u16NumAction, sizeof(u16NumAction));
  u16Pointeur += sizeof(u16NumAction);
	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &u32ValAction, sizeof(u32ValAction));
  u16Pointeur += sizeof(u32ValAction);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_shunt_tempo()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_SHUNT_TEMPO;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_SAV);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sConfig_IHM.sParam_SAV, sizeof(S_PARAM_SAV));
  u16Pointeur += sizeof(S_PARAM_SAV);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_raz_tps_fonct(uint8_t u8Esclave)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_FRIGO + u8Esclave;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_RAZ_TPS_FONCT;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_raz_soft_flash()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_RAZ_SOFT_FLASH;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_raz_log()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_RAZ_LOG;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_mode_commande()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_FRIGO;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_HISTO_ERR; //Normal
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(u16CodeCommande);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &u16CodeCommande, sizeof(u16CodeCommande));
  u16Pointeur += sizeof(u16CodeCommande);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_test_pac()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_TEST_PAC;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(S_PARAM_TEST_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &sParam_Test_PAC, sizeof(S_PARAM_TEST_PAC));
	u16Pointeur += sizeof(S_PARAM_TEST_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_test_cps_start()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_TEST_CPS_START;
	txData[u8Pointeur_buffer_tx].data[4] = 0;//1;//sizeof(S_PARAM_TEST_PAC);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

//	txData[u8Pointeur_buffer_tx].data[u16Pointeur]= 0;//sizeof(S_PARAM_TEST_PAC));
//	u16Pointeur += 1;//sizeof(S_PARAM_TEST_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_test_cps_stop()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_TEST_CPS_STOP;
	txData[u8Pointeur_buffer_tx].data[4] = 0;//1;//sizeof
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

//	txData[u8Pointeur_buffer_tx].data[u16Pointeur] = 0;
//	u16Pointeur += 1;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}


void Model::c_sav_test_cps(uint16_t u16CodeTestCps)
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_TEST_CPS;
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(u16CodeTestCps);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &u16CodeTestCps, sizeof(u16CodeTestCps));
	u16Pointeur += sizeof(u16CodeTestCps);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_par21()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_FRIGO;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = SC_SAV_PAR21; //Normal
	txData[u8Pointeur_buffer_tx].data[4] = sizeof(u16CodeCommande);
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	memcpy(&txData[u8Pointeur_buffer_tx].data[u16Pointeur], &u16CodeCommande, sizeof(u16CodeCommande));
  u16Pointeur += sizeof(u16CodeCommande);

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_mode_pump_down_recup_ue()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = S_TYPE_PUMP_DOWN_RECUP_UE;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_mode_pump_down_recup_ui()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = S_TYPE_PUMP_DOWN_RECUP_UI;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

void Model::c_sav_mode_pump_down_stop()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_REG;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = C_SAV;
	txData[u8Pointeur_buffer_tx].data[3] = S_TYPE_PUMP_DOWN_STOP;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}




void Model::c_restart()
{
  uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[u8Pointeur_buffer_tx].data[0] = N_ADD_ETHER;
	txData[u8Pointeur_buffer_tx].data[1] = N_ADD_IHM;
	txData[u8Pointeur_buffer_tx].data[2] = RESTART;
	txData[u8Pointeur_buffer_tx].data[3] = 0;
	txData[u8Pointeur_buffer_tx].data[4] = 0;
	txData[u8Pointeur_buffer_tx].data[5] = 0;
  u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[u8Pointeur_buffer_tx].data[0], u16Pointeur);
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = u16CRC & 0xff;
	txData[u8Pointeur_buffer_tx].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[u8Pointeur_buffer_tx].size = u16Pointeur;

	if(++u8Pointeur_buffer_tx > 9)
	{
		u8Pointeur_buffer_tx = 0;
	}
}

uint16_t Model::computeCRC(uint8_t *data, uint16_t size)
{
  uint16_t u16Crc = 0xffff;

  for (int i = 0; i < size; i++)
  {
    u16Crc ^= (data[i]) & 0xFF;

    for (int j = 0; j < 8; j++)
    {
      if(u16Crc % 2)
      {
        u16Crc >>= 1;
        u16Crc ^= 0xA001;
      }
      else
        u16Crc >>= 1;
    }
  }
  return u16Crc;
}
