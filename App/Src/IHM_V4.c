/*
 * IHM_V4.c
 *
 *  Created on: Jul 29, 2024
 *      Author: info
 */

#ifndef SIMULATOR
#include "main.h"
#endif /* SIMULATOR */
#include "IHM_V4.h"
#include <string.h>

uint8_t rxBuffer[TAILLE_BUFFER_UART];
rxData_t rxData;
cosebe_test_t cosebe_test;
arkteos_update_t arkteos_update;
uint8_t dataUpdated = 0;
uint8_t eOuiNon = 0;
S_DATE sDate;
S_DEMANDE_FRIGO sDemandeFrigo;
S_STATUT_PAC sStatut_PAC;
S_STATUT_PRIMAIRE sStatut_Primaire;
S_STATUT_ZX sStatut_Zx[20];
S_STATUT_ECS sStatut_ECS;
S_STATUT_PISCINE sStatut_Piscine;
S_STATUT_REG_EXT sStatut_RegulExt;
S_STATUT_TPS_FONCT sStatut_TpsFonct;
S_STATUT_REGUL_ESCLAVE sStatut_RegulEsclave;
S_STATUT_DEBUG sStatut_DebugTrame1[8];
S_STATUT_DEBUG sStatut_DebugTrame2[8];
S_CYC_ETHER_III sCycEther;
uint16_t u16ErreurEncours;
uint16_t u16ListeErreurEncours[25];
S_CONFIG_IHM sConfig_IHM;
S_CYCL_REG_FRI sCyclRegFrigo[NB_UE_MAX];

uint8_t decodeRxData(rxData_t *rxData)
{
	uint16_t ptrRxBuffer = 6;
	uint8_t result = 0;
	header_t *pHeader;
	cosebe_test_t *pCosebe_test;

	if(rxData->size != 0)
	{
		pHeader = (header_t*) rxData->data;
		switch(pHeader->comm)
		{
			case RECUP_SOFT:
				break;
			case UPLOAD:
				break;
			case INSTALL_SOFT:
				break;
			case START:
				break;
			case RESTART:
				break;
			case RECUP_CONFIG:
				if(pHeader->dest == N_ADD_IHM)
				{
					switch(pHeader->emet)
					{
						case N_ADD_ETHER:
							break;
						case N_ADD_REG:
							switch(pHeader->s_comm)
							{
								case SC_RECUP_GENERAL:
									if(pHeader->taille == (sizeof(S_MODE_ZX) * NB_ZONE + sizeof(S_MODE_ECS) + sizeof(S_MODE_PISCINE) + sizeof(S_MODE_REG_EXT) + sizeof(S_MODE_PAC) + sizeof(S_PARAM_UTILISATEUR) + sizeof(S_MODELE_PAC) + sizeof(S_OPTION_PAC) + sizeof(S_CONFIG_PAC) + sizeof(S_INSTALL_PAC) + sizeof(S_PARAM_PAC) + sizeof(S_PARAM_ECS) + sizeof(S_PARAM_PISCINE) + sizeof(S_PARAM_REG_EXT) + sizeof(S_PARAM_FRIGO)))
									{
										memcpy(&sConfig_IHM.sMode_Zx[0], &rxData->data[ptrRxBuffer], sizeof(S_MODE_ZX) * NB_ZONE);
										ptrRxBuffer += sizeof(S_MODE_ZX) * NB_ZONE;
										memcpy(&sConfig_IHM.sMode_ECS, &rxData->data[ptrRxBuffer], sizeof(S_MODE_ECS));
										ptrRxBuffer += sizeof(S_MODE_ECS);
										memcpy(&sConfig_IHM.sMode_Piscine, &rxData->data[ptrRxBuffer], sizeof(S_MODE_PISCINE));
										ptrRxBuffer += sizeof(S_MODE_PISCINE);
										memcpy(&sConfig_IHM.sMode_RegulExt, &rxData->data[ptrRxBuffer], sizeof(S_MODE_REG_EXT));
										ptrRxBuffer += sizeof(S_MODE_REG_EXT);
										memcpy(&sConfig_IHM.sMode_PAC, &rxData->data[ptrRxBuffer], sizeof(S_MODE_PAC));
										ptrRxBuffer += sizeof(S_MODE_PAC);
										memcpy(&sConfig_IHM.sParam_Utilisateur, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_UTILISATEUR));
										ptrRxBuffer += sizeof(S_PARAM_UTILISATEUR);
										memcpy(&sConfig_IHM.sModele_PAC, &rxData->data[ptrRxBuffer], sizeof(S_MODELE_PAC));
										ptrRxBuffer += sizeof(S_MODELE_PAC);
										memcpy(&sConfig_IHM.sOption_PAC, &rxData->data[ptrRxBuffer], sizeof(S_OPTION_PAC));
										ptrRxBuffer += sizeof(S_OPTION_PAC);
										memcpy(&sConfig_IHM.sConfig_PAC, &rxData->data[ptrRxBuffer], sizeof(S_CONFIG_PAC));
										ptrRxBuffer += sizeof(S_CONFIG_PAC);
										memcpy(&sConfig_IHM.sInstall_PAC, &rxData->data[ptrRxBuffer], sizeof(S_INSTALL_PAC));
										ptrRxBuffer += sizeof(S_INSTALL_PAC);
										memcpy(&sConfig_IHM.sParam_PAC, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_PAC));
										ptrRxBuffer += sizeof(S_PARAM_PAC);
										memcpy(&sConfig_IHM.sParam_ECS, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ECS));
										ptrRxBuffer += sizeof(S_PARAM_ECS);
										memcpy(&sConfig_IHM.sParam_Piscine, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_PISCINE));
										ptrRxBuffer += sizeof(S_PARAM_PISCINE);
										memcpy(&sConfig_IHM.sParam_RegulExt, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_REG_EXT));
										ptrRxBuffer += sizeof(S_PARAM_REG_EXT);
										memcpy(&sConfig_IHM.sParam_Frigo, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_FRIGO));
										ptrRxBuffer += sizeof(S_PARAM_FRIGO);
									}
									break;
								case SC_RECUP_TRAME2:
									if(pHeader->taille == (sizeof(S_PARAM_ZX) * NB_VOIE))
									{
										memcpy(&sConfig_IHM.sParam_Zx[0], &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ZX) * NB_VOIE);
										ptrRxBuffer += 320;
									}
									break;
								case SC_RECUP_CONFIG_PHOENIX:
									if(pHeader->taille == (sizeof(S_CONFIG_FRIGO) * NB_UE_MAX))
									{
										memcpy(&sConfig_IHM.sConfigFrigo[0], &rxData->data[ptrRxBuffer], sizeof(S_CONFIG_FRIGO) * NB_UE_MAX);
										ptrRxBuffer += sizeof(S_CONFIG_FRIGO) * NB_UE_MAX;
									}
									break;
							}
							break;
					}
				}
				arkteos_update.config_update = true;
				break;
			case CYC_ETHER_REG_FRIGO:
				if(pHeader->taille == sizeof(S_CYCL_REG_FRI))
				{
					memcpy(&sCyclRegFrigo[0], &rxData->data[ptrRxBuffer], sizeof(S_CYCL_REG_FRI));
					arkteos_update.cycl_frigo_update = true;
				}
				break;
			case CYC_ETHER_REG_REGUL:
				switch(pHeader->s_comm)
				{
					case SC_CYC_T1:
						if(pHeader->taille == LG_TRAME_CYCLIQUE_REGUL_T1)
						{
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_PAC, sizeof(S_STATUT_PAC)))
							{
								memcpy(&sStatut_PAC, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_PAC));
								arkteos_update.statut_pac_update = true;
								// Verification si MAJ de l'affichage nécessaire
								if(verifErreurs())
								{
									arkteos_update.erreur_update = true;
								}
							}
							ptrRxBuffer += sizeof(S_STATUT_PAC);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Primaire, sizeof(S_STATUT_PRIMAIRE)))
							{
								memcpy(&sStatut_Primaire, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_PRIMAIRE));
								arkteos_update.statut_primaire_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_PRIMAIRE);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[0], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[0], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[0] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[1], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[1], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[1] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_ECS, sizeof(S_STATUT_ECS)))
							{
								memcpy(&sStatut_ECS, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ECS));
								arkteos_update.statut_ecs_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ECS);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Piscine, sizeof(S_STATUT_PISCINE)))
							{
								memcpy(&sStatut_Piscine, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_PISCINE));
								arkteos_update.statut_piscine_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_PISCINE);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_RegulExt, sizeof(S_STATUT_REG_EXT)))
							{
								memcpy(&sStatut_RegulExt, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_REG_EXT));
								arkteos_update.statut_regul_ext_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_REG_EXT);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_TpsFonct, sizeof(S_STATUT_TPS_FONCT)))
							{
								memcpy(&sStatut_TpsFonct, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_TPS_FONCT));
								arkteos_update.statut_tps_fonct_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_TPS_FONCT);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_RegulEsclave, sizeof(S_STATUT_REGUL_ESCLAVE)))
							{
								memcpy(&sStatut_RegulEsclave, &rxData->data[ptrRxBuffer], sizeof(S_STATUT_REGUL_ESCLAVE));
								arkteos_update.statut_regul_esclave_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_REGUL_ESCLAVE);
							if(memcmp(&rxData->data[ptrRxBuffer], &sDate, sizeof(S_DATE)))
							{
								memcpy(&sDate, &rxData->data[ptrRxBuffer], sizeof(S_DATE));
								arkteos_update.date_update = true;
							}
							ptrRxBuffer += sizeof(S_DATE);
							if(memcmp(&rxData->data[ptrRxBuffer], &sDemandeFrigo, sizeof(S_DEMANDE_FRIGO)))
							{
								memcpy(&sDemandeFrigo, &rxData->data[ptrRxBuffer], sizeof(S_DEMANDE_FRIGO));
								arkteos_update.demande_frigo_update = true;
							}
							ptrRxBuffer += sizeof(S_DEMANDE_FRIGO);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_DebugTrame1[0], sizeof(S_STATUT_DEBUG) * 8))
							{
								memcpy(&sStatut_DebugTrame1[0], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_DEBUG) * 8);
								arkteos_update.statut_debug_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_DEBUG) * 8;
							result++;
						}
						break;
					case SC_CYC_T2:
						if(pHeader->taille == LG_TRAME_CYCLIQUE_REGUL_T2)
						{
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[2], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[2], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[2] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[3], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[3], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[3] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[4], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[4], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[4] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[5], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[5], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[5] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[6], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[6], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[6] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[7], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[7], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[7] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[8], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[8], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[8] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_Zx[9], sizeof(S_STATUT_ZX)))
							{
								memcpy(&sStatut_Zx[9], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_ZX));
								arkteos_update.statut_zx_update[9] = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_ZX);
							// u32Temp = sStatut_PAC.u3TypeData
							ptrRxBuffer += 4;
							if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_DebugTrame2[0], sizeof(S_STATUT_DEBUG) * 8))
							{
								memcpy(&sStatut_DebugTrame2[0], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_DEBUG) * 8);
								arkteos_update.statut_debug_update = true;
							}
							ptrRxBuffer += sizeof(S_STATUT_DEBUG) * 8;
						}
						break;
				}
				break;
			case CYC_ETHER:
				if(memcmp(&rxData->data[ptrRxBuffer], &sCycEther, sizeof(S_CYC_ETHER_III)))
				{
					memcpy(&sCycEther, &rxData->data[ptrRxBuffer], sizeof(S_CYC_ETHER_III));
					arkteos_update.statut_ether_update = true;
					// Verification si MAJ de l'affichage nécessaire
					if(verifErreurs())
					{
						arkteos_update.erreur_update = true;
					}
				}
				ptrRxBuffer += sizeof(S_CYC_ETHER_III);
				break;
			case C_USER:
				if(pHeader->dest == N_ADD_IHM)
				{
				  if(pHeader->comm == C_USER)
				  {
					if(pHeader->control == CONTROL_WRITE)
					{
					  if(pHeader->s_comm == SC_USER_Z1)
					  {
						pCosebe_test = (cosebe_test_t*)(rxData->data + sizeof(header_t));
						if((pCosebe_test->bModePAC) != cosebe_test.bModePAC)
						{
						  cosebe_test.bModePAC = pCosebe_test->bModePAC;
						  result++;
						}
						if((pCosebe_test->u7Spare) != cosebe_test.u7Spare)
						{
						  cosebe_test.u7Spare = pCosebe_test->u7Spare;
						  result++;
						}
						if((pCosebe_test->u8Spare) != cosebe_test.u8Spare)
						{
						  cosebe_test.u8Spare = pCosebe_test->u8Spare;
						  result++;
						}
						if((pCosebe_test->u8Spare) != cosebe_test.u8Spare)
						{
						  cosebe_test.u8Spare = pCosebe_test->u8Spare;
						  result++;
						}
					  }
					}
				  }
				}
				break;
			case C_USER_PROG:
				break;
			case C_USER_ENERGIE:
				break;
			case C_INSTALL:
				break;
			case C_INSTALL_THERMOSTAT:
				break;
			case C_USINE:
				break;
			case C_SAV:
				break;
			case C_WEB:
				break;
		}
	}
	rxData->size = 0;

	return result;
}

bool verifErreurs(void)
{
	uint8_t u8PointeurListeDefaut = 0;
	uint16_t u16ListeErreur[25], u16AlerteEnCours, u16ErreurEncours_old = u16ErreurEncours;

	// Init
	u16ErreurEncours = 0;
	// Erreur REG
	for(int i = 0; i < 5; i++)
	{
		if(sStatut_PAC.au16ListeErreurEnCoursREG[i] && ((sStatut_PAC.au16ListeErreurEnCoursREG[i] & DEFAUT_NV_IHM) == 0))
		{
			if(sStatut_PAC.au16ListeErreurEnCoursREG[i] & T_DEF_DEFAUT)
			{
				if(u16ErreurEncours == 0)
				{
					u16ErreurEncours = sStatut_PAC.au16ListeErreurEnCoursREG[i];
				}
			}
			else if(u16AlerteEnCours == 0)
			{
				u16AlerteEnCours = sStatut_PAC.au16ListeErreurEnCoursREG[i];
			}
			u16ListeErreur[u8PointeurListeDefaut++] = sStatut_PAC.au16ListeErreurEnCoursREG[i];
		}
	}
	// Erreur Frigo
	for(int i = 0; i < 5; i++)
	{
		if(sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i] && ((sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i] & DEFAUT_NV_IHM) == 0))
		{
			if(sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i] & T_DEF_DEFAUT)
			{
				if(u16ErreurEncours == 0)
				{
					u16ErreurEncours = sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i];
				}
			}
			else if(u16AlerteEnCours == 0)
			{
				u16AlerteEnCours = sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i];
			}
			u16ListeErreur[u8PointeurListeDefaut++] = sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i];
		}
	}
	// Erreur FAN
	if(sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
	{
		for(int i = 0; i < 5; i++)
		{
			if(sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i] && ((sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i] & DEFAUT_NV_IHM) == 0))
			{
				if(sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i] & T_DEF_DEFAUT)
				{
					if(u16ErreurEncours == 0)
					{
						u16ErreurEncours = sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i];
					}
				}
				else if(u16AlerteEnCours == 0)
				{
					u16AlerteEnCours = sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i];
				}
				u16ListeErreur[u8PointeurListeDefaut++] = sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i];
			}
		}
	}
	// Erreur Ether
	for(int i = 0; i < 5; i++)
	{
		if(sCycEther.au16ListeErreurEnCoursETHER[i] && ((sCycEther.au16ListeErreurEnCoursETHER[i] & DEFAUT_NV_IHM) == 0))
		{
			if(sCycEther.au16ListeErreurEnCoursETHER[i] & T_DEF_DEFAUT)
			{
				if(u16ErreurEncours == 0)
				{
					u16ErreurEncours = sCycEther.au16ListeErreurEnCoursETHER[i];
				}
			}
			else if(u16AlerteEnCours == 0)
			{
				u16AlerteEnCours = sCycEther.au16ListeErreurEnCoursETHER[i];
			}
			u16ListeErreur[u8PointeurListeDefaut++] = sCycEther.au16ListeErreurEnCoursETHER[i];
		}
	}
	// MAJ des variables communes
	if(u16ErreurEncours == 0)
	{
		u16ErreurEncours = u16AlerteEnCours;
	}
	memcpy(u16ListeErreurEncours, u16ListeErreur, sizeof(u16ListeErreur));
	// MAJ de l'affichage ou non
	if(u16ErreurEncours_old != u16ErreurEncours)
	{
		return true;
	}
	return false;
}
