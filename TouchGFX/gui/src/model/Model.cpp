#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "IHM_V4.h"
#include <string.h>

Model::Model() : modelListener(0)
{
#ifdef SIMULATOR
	// Options PAC
	sConfig_IHM.sOption_PAC.sZone.bZone1 = 1;
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
	sStatut_Piscine.i16TeauPiscine = 321;
	sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Confort = 350;
	sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Normal = 300;
	sConfig_IHM.sMode_Piscine.i16Consigne_Piscine_Reduit = 290;
	// Config Piscine
	sStatut_Zx[0].i16Tint = 196;
	strcpy((char *)&sConfig_IHM.sParam_Zx[0].u8NomZone[0], "Zone 1");
	sConfig_IHM.sMode_Zx[0].Mode = MARCHE_CHAUD;
	sConfig_IHM.sMode_Zx[0].i16Consigne_Tint_Reduit = 160;
	sConfig_IHM.sMode_Zx[0].i16Consigne_Tint_Normal = 186;
	sConfig_IHM.sMode_Zx[0].i16Consigne_Tint_Confort = 200;
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
#endif
}

void Model::tick()
{
	if(dataUpdated != 0)
	{
		modelListener->changeModePac(cosebe_test.bModePAC);
		dataUpdated = 0;
	}
	if(arkteos_update.date_update)
	{
		modelListener->changeDate(&sDate);
		arkteos_update.date_update = false;
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
	if(arkteos_update.statut_pac_update)
	{
		modelListener->changeStatutPAC(&sStatut_PAC);
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
		modelListener->changeDemandeFrigo(&sDemandeFrigo);
		arkteos_update.demande_frigo_update = false;
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

void Model::c_user_param()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
//	txData[0].data[0] = CONTROL_WRITE;
	txData[0].data[3] = SC_USER_PARAM;
	txData[0].data[4] = sizeof(S_MODE_PAC) + sizeof(S_PARAM_UTILISATEUR);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_PAC, sizeof(S_MODE_PAC));
	u16Pointeur += sizeof(S_MODE_PAC);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sParam_Utilisateur, sizeof(S_PARAM_UTILISATEUR));
	u16Pointeur += sizeof(S_PARAM_UTILISATEUR);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_vacances()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
	txData[0].data[3] = SC_USER_VACANCES;
	txData[0].data[4] = sizeof(S_MODE_ZX)*NB_ZONE + sizeof(S_MODE_ECS) + sizeof(S_MODE_PISCINE) + sizeof(S_MODE_REG_EXT) + sizeof(S_PARAM_PAC);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_Zx[0], sizeof(S_MODE_ZX) * NB_ZONE);
	u16Pointeur += sizeof(S_MODE_ZX) * NB_ZONE;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_ECS, sizeof(S_MODE_ECS));
	u16Pointeur += sizeof(S_MODE_ECS);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_Piscine, sizeof(S_MODE_PISCINE));
	u16Pointeur += sizeof(S_MODE_PISCINE);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_RegulExt, sizeof(S_MODE_REG_EXT));
	u16Pointeur += sizeof(S_MODE_REG_EXT);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sParam_PAC, sizeof(S_PARAM_PAC));
	u16Pointeur += sizeof(S_PARAM_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_ecs()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
//	txData[0].data[0] = CONTROL_WRITE;
	txData[0].data[3] = SC_USER_ECS;
	txData[0].data[4] = sizeof(S_MODE_ECS);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_ECS, sizeof(S_MODE_ECS));
	u16Pointeur += sizeof(S_MODE_ECS);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_zx(uint8_t u8Zone)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
	txData[0].data[3] = SC_USER_Z1 + u8Zone;
	txData[0].data[4] = sizeof(S_MODE_ZX);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_Zx[u8Zone], sizeof(S_MODE_ZX));
	u16Pointeur += sizeof(S_MODE_ZX);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_zx_all()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
	txData[0].data[3] = SC_USER_ZX;
	txData[0].data[4] = sizeof(S_MODE_ZX) * NB_ZONE;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_Zx[0], sizeof(S_MODE_ZX) * NB_ZONE);
	u16Pointeur += sizeof(S_MODE_ZX) * NB_ZONE;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_reg_ext()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
	txData[0].data[3] = SC_USER_REG_EXT;
	txData[0].data[4] = sizeof(S_MODE_REG_EXT);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_RegulExt, sizeof(S_MODE_REG_EXT));
	u16Pointeur += sizeof(S_MODE_REG_EXT);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_piscine()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
	txData[0].data[3] = SC_USER_PISCINE;
	txData[0].data[4] = sizeof(S_MODE_PISCINE);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sMode_Piscine, sizeof(S_MODE_PISCINE));
	u16Pointeur += sizeof(S_MODE_PISCINE);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_user_date()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER;
	txData[0].data[3] = SC_USER_DATE;
	txData[0].data[4] = sizeof(S_DATE);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	memcpy(&txData[0].data[u16Pointeur], &sDate_modif, sizeof(S_DATE));
	u16Pointeur += sizeof(S_DATE);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_raz()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_RAZ_DATE;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_cumul_prod()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_CUMUL_PROD + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_cumul_conso()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_CUMUL_CONS + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_histo_12m_conso()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_CONS_12M + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_histo_24j_conso()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_CONS_24J + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_histo_24h_conso()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_CONS_24H + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_histo_12m_prod()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_PROD_12M + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_histo_24j_prod()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_PROD_24J + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_ener_histo_24h_prod()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_ENERGIE;
	txData[0].data[3] = SC_ENER_PROD_24H + CONTROL_READ;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_recup_config(uint8_t u8RecupConfig)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	if(u8RecupConfig == 0)
	{
		txData[0].data[0] = N_ADD_ETHER;
	}
	else txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = RECUP_CONFIG;
//	txData[0].data[0] = CONTROL_WRITE;
	if(u8RecupConfig == 2)
	{
		txData[0].data[3] = SC_RECUP_TRAME2;
	}
	else
	if(u8RecupConfig == 3)
	{
		txData[0].data[3] = SC_RECUP_CONFIG_PHOENIX;
	}
	else txData[0].data[3] = SC_RECUP_GENERAL;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_ecs(bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_ECS;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_ECS);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_ECS, sizeof(au8Prog_ECS));
		u16Pointeur += sizeof(au8Prog_ECS);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_option(bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_OPTIONS;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_Options);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_Options, sizeof(au8Prog_Options));
		u16Pointeur += sizeof(au8Prog_Options);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_piscine(bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_PISCINE;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_Piscine);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_Piscine, sizeof(au8Prog_Piscine));
		u16Pointeur += sizeof(au8Prog_Piscine);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_CHAUD_Z1 + u8Zone;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_Chaud_Zx[u8Zone]);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_Chaud_Zx[u8Zone], sizeof(au8Prog_Chaud_Zx[u8Zone]));
		u16Pointeur += sizeof(au8Prog_Chaud_Zx[u8Zone]);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_FROID_Z1 + u8Zone;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_Froid_Zx[u8Zone]);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_Froid_Zx[u8Zone], sizeof(au8Prog_Froid_Zx[u8Zone]));
		u16Pointeur += sizeof(au8Prog_Froid_Zx[u8Zone]);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_reg_ext_chaud(bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_EXT_CHAUD;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_Regul_Ext_Chaud);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_Regul_Ext_Chaud, sizeof(au8Prog_Regul_Ext_Chaud));
		u16Pointeur += sizeof(au8Prog_Regul_Ext_Chaud);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_prog_reg_ext_froid(bool bEnvoi)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USER_PROG;
	txData[0].data[3] = SC_PROG_EXT_FROID;
	if(bEnvoi == false)
	{
		txData[0].data[3] += CONTROL_READ;
		txData[0].data[4] = 0;
	}
	else txData[0].data[4] = sizeof(au8Prog_Regul_Ext_Froid);
	txData[0].data[5] = 0;
	u16Pointeur = 6;
	if(bEnvoi == true)
	{
		memcpy(&txData[0].data[u16Pointeur], &au8Prog_Regul_Ext_Froid, sizeof(au8Prog_Regul_Ext_Froid));
		u16Pointeur += sizeof(au8Prog_Regul_Ext_Froid);
	}
	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_install_raz_config()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_INSTALL;
	txData[0].data[3] = SC_INSTALL_RAZ_CONFIG;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_install_config_pac()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_INSTALL;
	txData[0].data[3] = SC_INSTALL_CONFIG_PAC;
	txData[0].data[4] = sizeof(S_CONFIG_PAC);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sConfig_PAC, sizeof(S_CONFIG_PAC));
	u16Pointeur += sizeof(S_CONFIG_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_install_piscine()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_INSTALL;
	txData[0].data[3] = SC_PARAM_PISCINE;
	txData[0].data[4] = sizeof(S_PARAM_PISCINE);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sParam_Piscine, sizeof(S_PARAM_PISCINE));
	u16Pointeur += sizeof(S_PARAM_PISCINE);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_install_param()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_INSTALL;
	txData[0].data[3] = SC_INSTALL_PARAM;
	txData[0].data[4] = sizeof(S_OPTION_PAC) + sizeof(S_PARAM_PAC) + sizeof(S_PARAM_FRIGO);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sOption_PAC, sizeof(S_OPTION_PAC));
	u16Pointeur += sizeof(S_OPTION_PAC);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sParam_PAC, sizeof(S_PARAM_PAC));
	u16Pointeur += sizeof(S_PARAM_PAC);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sParam_Frigo, sizeof(S_PARAM_FRIGO));
	u16Pointeur += sizeof(S_PARAM_FRIGO);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_install_raz_histo_err()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_INSTALL;
	txData[0].data[3] = SC_INSTALL_RAZ_HISTO_ERR;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_usine_param()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USINE;
	txData[0].data[3] = SC_USINE_PARAM;
	txData[0].data[4] = sizeof(S_MODELE_PAC) + sizeof(S_CONFIG_PAC);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sModele_PAC, sizeof(S_MODELE_PAC));
	u16Pointeur += sizeof(S_MODELE_PAC);
	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sConfig_PAC, sizeof(S_CONFIG_PAC));
	u16Pointeur += sizeof(S_CONFIG_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_usine_password()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USINE;
	txData[0].data[3] = SC_USINE_PASSWORD;
	txData[0].data[4] = sizeof(S_INSTALL_PAC);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sInstall_PAC, sizeof(S_INSTALL_PAC));
	u16Pointeur += sizeof(S_INSTALL_PAC);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_usine_phoenix(int u8Esclave)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_FRIGO + u8Esclave;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USINE;
	txData[0].data[3] = SC_USINE_GENERAL;
	txData[0].data[4] = sizeof(S_MODELE_FRIGO);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sConfigFrigo[u8Esclave].sModele_FRIGO, sizeof(S_MODELE_FRIGO));
	u16Pointeur += sizeof(S_MODELE_FRIGO);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_usine_raz_energie()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USINE;
	txData[0].data[3] = SC_USINE_RAZ_ENERGIE;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_usine_raz_config()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_USINE;
	txData[0].data[3] = SC_USINE_RAZ_CONFIG;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_sav_histo_err()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_SAV;
	txData[0].data[3] = SC_SAV_HISTO_ERR;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_sav_param()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_SAV;
	txData[0].data[3] = SC_SAV_PARAM;
	txData[0].data[4] = sizeof(u16NumAction) + sizeof(u32ValAction);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &u16NumAction, sizeof(u16NumAction));
	u16Pointeur += sizeof(u16NumAction);
	memcpy(&txData[0].data[u16Pointeur], &u32ValAction, sizeof(u32ValAction));
	u16Pointeur += sizeof(u32ValAction);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_sav_shunt_tempo()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_REG;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_SAV;
	txData[0].data[3] = SC_SAV_SHUNT_TEMPO;
	txData[0].data[4] = sizeof(S_PARAM_SAV);
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	memcpy(&txData[0].data[u16Pointeur], &sConfig_IHM.sParam_SAV, sizeof(S_PARAM_SAV));
	u16Pointeur += sizeof(S_PARAM_SAV);

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_sav_raz_tps_fonct(uint8_t u8Esclave)
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_FRIGO + u8Esclave;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_SAV;
	txData[0].data[3] = SC_SAV_RAZ_TPS_FONCT;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_sav_raz_soft_flash()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_ETHER;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_SAV;
	txData[0].data[3] = SC_SAV_RAZ_SOFT_FLASH;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_sav_raz_log()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_ETHER;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = C_SAV;
	txData[0].data[3] = SC_SAV_RAZ_LOG;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

void Model::c_restart()
{
	uint16_t u16Pointeur = 0, u16CRC = 0;

	txData[0].data[0] = N_ADD_ETHER;
	txData[0].data[1] = N_ADD_IHM;
	txData[0].data[2] = RESTART;
	txData[0].data[3] = 0;
	txData[0].data[4] = 0;
	txData[0].data[5] = 0;
	u16Pointeur = 6;

	u16CRC = computeCRC((uint8_t*)&txData[0].data[0], u16Pointeur);
	txData[0].data[u16Pointeur++] = u16CRC & 0xff;
	txData[0].data[u16Pointeur++] = (u16CRC >> 8) & 0xff;

	txData[0].size = u16Pointeur;
}

uint16_t Model::computeCRC(uint8_t *data, uint16_t size)
{
	uint16_t u16Crc = 0xffff;

	for(int i = 0; i < size; i++)
	{
		u16Crc ^= (data[i]) & 0xFF;

		for(int j = 0; j < 8; j++)
		{
			if(u16Crc % 2)
			{
				u16Crc >>=1;
				u16Crc ^= 0xA001;
			}
			else u16Crc >>=1;
		}
	}
  	return u16Crc;
}
