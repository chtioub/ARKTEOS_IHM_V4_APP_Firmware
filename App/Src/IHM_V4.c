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

cosebe_rx_t cosebe_rx;
cosebe_test_t cosebe_test;
arkteos_update_t arkteos_update;
uint8_t dataUpdated = 0;
txData_t txData[10];
uint8_t eOuiNon = 0, eCode = 0;
uint8_t eHysteresis = 0;
uint8_t eProg;
S_DATE sDate, sDate_modif;
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
S_STATUT_RF sStatut_RF[8];
S_STATUT_DEBUG sStatut_DebugTrame2[8];
S_CYC_ETHER_III sCycEther;
S_ENERGIE sEnergie;
uint16_t u16ErreurEncours;
uint16_t u16ListeErreurEncours[25];
S_CONFIG_IHM sConfig_IHM;
S_CYCL_REG_FRI sCyclRegFrigo[NB_UE_MAX];
uint8_t au8Prog_Chaud_Zx[NB_ZONE][7][24];
uint8_t au8Prog_Froid_Zx[NB_ZONE][7][24];
uint8_t au8Prog_Regul_Ext_Chaud[7][24];
uint8_t au8Prog_Regul_Ext_Froid[7][24];
uint8_t au8Prog_ECS[7][24];
uint8_t au8Prog_Piscine[7][24];
uint8_t au8Prog_Options[7][24];
uint8_t au8Prog_ModeSilence[7][24];
uint8_t u8Prog[7][24], u8JourProg;
uint8_t u8ZoneSelect;
uint8_t u8PositionX, u8PositionY;
bool bConsoProd, bPageUsine, bMaintenanceDepuisUsine, bInstallationDepuisUsine;
S_HISTO_ERR sHisto_Erreur;
uint16_t u16NumAction;
uint32_t u32ValAction, eAnciennePage;
S_CONFIG_HYDRAU_TEMP sConfig_Hydrau_temp;
S_CONFIG_PISCINE_TEMP sConfig_Piscine_temp;
S_PARAM_ECS sParam_ECS_temp;
uint32_t u32LastCyclique;
uint8_t u8Pointeur_buffer_tx, u8Pointeur_envoi;

uint8_t decodeRxData(rxData_t *rxData)
{
	uint16_t ptrRxBuffer = 6;
	uint8_t result = 0;
	header_t *pHeader;

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
#ifndef SIMULATOR
				NVIC_SystemReset();
#endif
				break;
			case RECUP_CONFIG:
				if(pHeader->dest == N_ADD_IHM)
				{
					switch(pHeader->emet)
					{
						case N_ADD_ETHER:
							memcpy(&sConfig_IHM.sParamSoft, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ETHER_SOFT_III));
							ptrRxBuffer += sizeof(S_PARAM_ETHER_SOFT_III);
							memcpy(&sConfig_IHM.sParamPort, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ETHER_PORT_III));
							ptrRxBuffer += sizeof(S_PARAM_ETHER_PORT_III);
							memcpy(&sConfig_IHM.sParamWifi, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ETHER_WIFI_III));
							ptrRxBuffer += sizeof(S_PARAM_ETHER_WIFI_III);
							memcpy(&sConfig_IHM.sParamModbus, &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ETHER_MODBUS_III));
							ptrRxBuffer += sizeof(S_PARAM_ETHER_MODBUS_III);
							sConfig_IHM.u16RecupConfig = 1;
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
										sConfig_IHM.u16RecupConfig = 2;
									}
									break;
								case SC_RECUP_TRAME2:
									if(pHeader->taille == (sizeof(S_PARAM_ZX) * NB_VOIE))
									{
										memcpy(&sConfig_IHM.sParam_Zx[0], &rxData->data[ptrRxBuffer], sizeof(S_PARAM_ZX) * NB_VOIE);
										ptrRxBuffer += 320;
										sConfig_IHM.u16RecupConfig = 3;
									}
									break;
								case SC_RECUP_CONFIG_PHOENIX:
									if(pHeader->taille == (sizeof(S_CONFIG_FRIGO) * NB_UE_MAX))
									{
										for(int i = 0; i < NB_UE_MAX; i++)
										{
											memcpy(&sConfig_IHM.sConfigFrigo[i], &rxData->data[ptrRxBuffer], sizeof(S_CONFIG_FRIGO));
											ptrRxBuffer += sizeof(S_CONFIG_FRIGO);
										}
										sConfig_IHM.u16RecupConfig = 4;
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
					u32LastCyclique = HAL_GetTick();
					memcpy(&sCyclRegFrigo[0], &rxData->data[ptrRxBuffer], sizeof(S_CYCL_REG_FRI));
					arkteos_update.cycl_frigo_update = true;
					if(sConfig_IHM.u16NbCyclique < 6)
					{
						sConfig_IHM.u16NbCyclique++;
					}
				}
				break;
			case CYC_ETHER_REG_REGUL:
				switch(pHeader->s_comm)
				{
					case SC_CYC_T1:
						if(pHeader->taille == LG_TRAME_CYCLIQUE_REGUL_T1)
						{
							u32LastCyclique = HAL_GetTick();
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
							if(sStatut_PAC.u3TypeData == 0)
							{
								if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_RF[0], sizeof(S_STATUT_RF) * 8))
								{
									memcpy(&sStatut_RF[0], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_RF) * 8);
									arkteos_update.statut_rf_update = true;
								}
							}
							else
							{
								if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_DebugTrame1[0], sizeof(S_STATUT_DEBUG) * 8))
								{
									memcpy(&sStatut_DebugTrame1[0], &rxData->data[ptrRxBuffer], sizeof(S_STATUT_DEBUG) * 8);
									arkteos_update.statut_debug_update = true;
								}
							}
							ptrRxBuffer += sizeof(S_STATUT_DEBUG) * 8;
							result++;
							if(sConfig_IHM.u16NbCyclique < 6)
							{
								sConfig_IHM.u16NbCyclique++;
							}
						}
						break;
					case SC_CYC_T2:
						if(pHeader->taille == LG_TRAME_CYCLIQUE_REGUL_T2)
						{
							u32LastCyclique = HAL_GetTick();
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
							if(sConfig_IHM.u16NbCyclique < 6)
							{
								sConfig_IHM.u16NbCyclique++;
							}
						}
						break;
				}
				break;
			case CYC_ETHER:
				if(memcmp(&rxData->data[ptrRxBuffer], &sCycEther, sizeof(S_CYC_ETHER_III)))
				{
					u32LastCyclique = HAL_GetTick();
					memcpy(&sCycEther, &rxData->data[ptrRxBuffer], sizeof(S_CYC_ETHER_III));
					arkteos_update.statut_ether_update = true;
					// Verification si MAJ de l'affichage nécessaire
					if(verifErreurs())
					{
						arkteos_update.erreur_update = true;
					}
				}
				if(sConfig_IHM.u16NbCyclique < 6)
				{
					sConfig_IHM.u16NbCyclique++;
				}
				ptrRxBuffer += sizeof(S_CYC_ETHER_III);
				break;
			case C_USER:
//				if(pHeader->dest == N_ADD_IHM)
//				{
//				  if(pHeader->comm == C_USER)
//				  {
//					if(pHeader->control == CONTROL_WRITE)
//					{
//					  if(pHeader->s_comm == SC_USER_Z1)
//					  {
//						pCosebe_test = (cosebe_test_t*)(rxData->data + sizeof(header_t));
//						if((pCosebe_test->bModePAC) != cosebe_test.bModePAC)
//						{
//						  cosebe_test.bModePAC = pCosebe_test->bModePAC;
//						  result++;
//						}
//						if((pCosebe_test->u7Spare) != cosebe_test.u7Spare)
//						{
//						  cosebe_test.u7Spare = pCosebe_test->u7Spare;
//						  result++;
//						}
//						if((pCosebe_test->u8Spare) != cosebe_test.u8Spare)
//						{
//						  cosebe_test.u8Spare = pCosebe_test->u8Spare;
//						  result++;
//						}
//						if((pCosebe_test->u8Spare) != cosebe_test.u8Spare)
//						{
//						  cosebe_test.u8Spare = pCosebe_test->u8Spare;
//						  result++;
//						}
//					  }
//					}
//				  }
//				}
				break;
			case C_USER_PROG:
				if(pHeader->taille == sizeof(au8Prog_ECS))
				{
					switch(pHeader->s_comm)
					{
						case SC_PROG_CHAUD_Z1:
							memcpy(&au8Prog_Chaud_Zx[0], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z2:
							memcpy(&au8Prog_Chaud_Zx[1], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z3:
							memcpy(&au8Prog_Chaud_Zx[3], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z4:
							memcpy(&au8Prog_Chaud_Zx[3], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z5:
							memcpy(&au8Prog_Chaud_Zx[4], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z6:
							memcpy(&au8Prog_Chaud_Zx[5], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z7:
							memcpy(&au8Prog_Chaud_Zx[6], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_CHAUD_Z8:
							memcpy(&au8Prog_Chaud_Zx[7], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z1:
							memcpy(&au8Prog_Froid_Zx[0], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z2:
							memcpy(&au8Prog_Froid_Zx[1], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z3:
							memcpy(&au8Prog_Froid_Zx[2], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z4:
							memcpy(&au8Prog_Froid_Zx[3], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z5:
							memcpy(&au8Prog_Froid_Zx[4], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z6:
							memcpy(&au8Prog_Froid_Zx[5], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z7:
							memcpy(&au8Prog_Froid_Zx[6], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_FROID_Z8:
							memcpy(&au8Prog_Froid_Zx[7], &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_EXT_CHAUD:
							memcpy(&au8Prog_Regul_Ext_Chaud, &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_EXT_FROID:
							memcpy(&au8Prog_Regul_Ext_Froid, &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_ECS:
							memcpy(&au8Prog_ECS, &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_PISCINE:
							memcpy(&au8Prog_Piscine, &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_OPTIONS:
							memcpy(&au8Prog_Options, &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
						case SC_PROG_MODE_SILENCE:
							memcpy(&au8Prog_ModeSilence, &rxData->data[ptrRxBuffer], sizeof(au8Prog_ECS));
							break;
					}
				}
				break;
			case C_USER_ENERGIE:
				switch(pHeader->s_comm)
				{
					case SC_ENER_CONS_12M:
						if(pHeader->taille == sizeof(sEnergie.Conso_12M))
						{
							memcpy(&sEnergie.Conso_12M, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Conso_12M));
						}
						break;
					case SC_ENER_CONS_24H:
						if(pHeader->taille == sizeof(sEnergie.Conso_24H))
						{
							memcpy(&sEnergie.Conso_24H, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Conso_24H));
						}
						break;
					case SC_ENER_CONS_24J:
						if(pHeader->taille == sizeof(sEnergie.Conso_24J))
						{
							memcpy(&sEnergie.Conso_24J, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Conso_24J));
						}
						break;
					case SC_ENER_CUMUL_CONS:
						if(pHeader->taille == sizeof(sEnergie.Cumul_Consommee))
						{
							memcpy(&sEnergie.Cumul_Consommee, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Cumul_Consommee));
						}
						break;
					case SC_ENER_CUMUL_PROD:
						if(pHeader->taille == sizeof(sEnergie.Cumul_Produite))
						{
							memcpy(&sEnergie.Cumul_Produite, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Cumul_Produite));
						}
						break;
					case SC_ENER_PROD_12M:
						if(pHeader->taille == sizeof(sEnergie.Prod_12M))
						{
							memcpy(&sEnergie.Prod_12M, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Prod_12M));
						}
						break;
					case SC_ENER_PROD_24H:
						if(pHeader->taille == sizeof(sEnergie.Prod_24H))
						{
							memcpy(&sEnergie.Prod_24H, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Prod_24H));
						}
						break;
					case SC_ENER_PROD_24J:
						if(pHeader->taille == sizeof(sEnergie.Prod_24J))
						{
							memcpy(&sEnergie.Prod_24J, &rxData->data[ptrRxBuffer], sizeof(sEnergie.Prod_24J));
						}
						break;
				}
				break;
			case C_INSTALL:
				break;
			case C_INSTALL_THERMOSTAT:
				break;
			case C_USINE:
				break;
			case C_SAV:
				switch(pHeader->s_comm)
				{
					case SC_SAV_HISTO_ERR:
						if(pHeader->taille == sizeof(sHisto_Erreur))
						{
							memcpy(&sHisto_Erreur, &rxData->data[ptrRxBuffer], sizeof(S_HISTO_ERR));
						}
						break;
				}
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
	memset(u16ListeErreur, 0, sizeof(u16ListeErreur));
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

uint32_t u32Erreurs[1000] =
{
0,								// 0
0,
0,
0,
0,
0,
0,
0,
0,
0,
T_TEXT_ERR_10_GAUCHE_DEFAUT,	// 10
T_TEXT_ERR_11_GAUCHE_DEFAUT,
T_TEXT_ERR_12_GAUCHE_DEFAUT,
T_TEXT_ERR_13_GAUCHE_DEFAUT,
T_TEXT_ERR_14_GAUCHE_DEFAUT,
T_TEXT_ERR_15_GAUCHE_DEFAUT,
T_TEXT_ERR_16_GAUCHE_DEFAUT,
T_TEXT_ERR_17_GAUCHE_DEFAUT,
T_TEXT_ERR_18_GAUCHE_DEFAUT,
0,
0,								// 20
0,
0,
0,
0,
0,
0,
0,
0,
0,
T_TEXT_ERR_30_GAUCHE_DEFAUT,	// 30
0,
0,
0,
0,
0,
0,
0,
0,
0,
T_TEXT_ERR_40_GAUCHE_DEFAUT,	// 40
T_TEXT_ERR_41_GAUCHE_DEFAUT,
T_TEXT_ERR_42_GAUCHE_DEFAUT,
T_TEXT_ERR_43_GAUCHE_DEFAUT,
T_TEXT_ERR_44_GAUCHE_DEFAUT,
T_TEXT_ERR_45_GAUCHE_DEFAUT,
T_TEXT_ERR_46_GAUCHE_DEFAUT,
T_TEXT_ERR_47_GAUCHE_DEFAUT,
T_TEXT_ERR_48_GAUCHE_DEFAUT,
T_TEXT_ERR_49_GAUCHE_DEFAUT,
T_TEXT_ERR_50_GAUCHE_DEFAUT,	// 50
T_TEXT_ERR_51_GAUCHE_DEFAUT,
T_TEXT_ERR_52_GAUCHE_DEFAUT,
T_TEXT_ERR_53_GAUCHE_DEFAUT,
T_TEXT_ERR_54_GAUCHE_DEFAUT,
T_TEXT_ERR_55_GAUCHE_DEFAUT,
T_TEXT_ERR_56_GAUCHE_DEFAUT,
T_TEXT_ERR_57_GAUCHE_DEFAUT,
T_TEXT_ERR_58_GAUCHE_DEFAUT,
0,
0,								// 60
T_TEXT_ERR_61_GAUCHE_DEFAUT,
T_TEXT_ERR_62_GAUCHE_DEFAUT,
T_TEXT_ERR_63_GAUCHE_DEFAUT,
T_TEXT_ERR_64_GAUCHE_DEFAUT,
T_TEXT_ERR_65_GAUCHE_DEFAUT,
T_TEXT_ERR_66_GAUCHE_DEFAUT,
T_TEXT_ERR_67_GAUCHE_DEFAUT,
T_TEXT_ERR_68_GAUCHE_DEFAUT,
T_TEXT_ERR_69_GAUCHE_DEFAUT,
T_TEXT_ERR_70_GAUCHE_DEFAUT,	// 70
T_TEXT_ERR_71_GAUCHE_DEFAUT,
T_TEXT_ERR_72_GAUCHE_DEFAUT,
T_TEXT_ERR_73_GAUCHE_DEFAUT,
T_TEXT_ERR_74_GAUCHE_DEFAUT,
T_TEXT_ERR_75_GAUCHE_DEFAUT,
T_TEXT_ERR_76_GAUCHE_DEFAUT,
T_TEXT_ERR_77_GAUCHE_DEFAUT,
T_TEXT_ERR_78_GAUCHE_DEFAUT,
T_TEXT_ERR_79_GAUCHE_DEFAUT,
T_TEXT_ERR_80_GAUCHE_DEFAUT,	// 80
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 90
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 100
0,
0,
0,
T_TEXT_ERR_104_GAUCHE_DEFAUT,
T_TEXT_ERR_105_GAUCHE_DEFAUT,
0,
T_TEXT_ERR_107_GAUCHE_DEFAUT,
0,
0,
T_TEXT_ERR_110_GAUCHE_DEFAUT,	// 110
T_TEXT_ERR_111_GAUCHE_DEFAUT,
T_TEXT_ERR_112_GAUCHE_DEFAUT,
0,
T_TEXT_ERR_114_GAUCHE_DEFAUT,
T_TEXT_ERR_115_GAUCHE_DEFAUT,
T_TEXT_ERR_116_GAUCHE_DEFAUT,
T_TEXT_ERR_117_GAUCHE_DEFAUT,
T_TEXT_ERR_118_GAUCHE_DEFAUT,
T_TEXT_ERR_119_GAUCHE_DEFAUT,
T_TEXT_ERR_120_GAUCHE_DEFAUT,	// 120
T_TEXT_ERR_121_GAUCHE_DEFAUT,
T_TEXT_ERR_122_GAUCHE_DEFAUT,
T_TEXT_ERR_123_GAUCHE_DEFAUT,
T_TEXT_ERR_124_GAUCHE_DEFAUT,
T_TEXT_ERR_125_GAUCHE_DEFAUT,
0,
T_TEXT_ERR_127_GAUCHE_DEFAUT,
T_TEXT_ERR_128_GAUCHE_DEFAUT,
0,
T_TEXT_ERR_130_GAUCHE_DEFAUT,	// 130
T_TEXT_ERR_131_GAUCHE_DEFAUT,
T_TEXT_ERR_132_GAUCHE_DEFAUT,
T_TEXT_ERR_133_GAUCHE_DEFAUT,
T_TEXT_ERR_134_GAUCHE_DEFAUT,
0,
0,
0,
0,
0,
0,								// 140
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 150
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 160
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 170
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 180
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,								// 190
0,
0,
0,
0,
0,
0,
0,
0,
0,
T_TEXT_ERR_200_GAUCHE_DEFAUT,	// 200
T_TEXT_ERR_201_GAUCHE_DEFAUT,
T_TEXT_ERR_202_GAUCHE_DEFAUT,
};
