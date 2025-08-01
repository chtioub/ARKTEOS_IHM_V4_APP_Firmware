/*
 * IHM_V4.c
 *
 *  Created on: Jul 29, 2024
 *      Author: info
 */

#ifndef SIMULATOR
#include "main.h"
#include "tim.h"
#endif /* SIMULATOR */
#include "IHM_V4.h"
#include <string.h>
#include <math.h>

uint8_t rxBuffer[TAILLE_BUFFER_UART];
rxData_t rxData;

cosebe_rx_t cosebe_rx;
cosebe_test_t cosebe_test;
arkteos_update_t arkteos_update;
uint8_t dataUpdated = 0;
txData_t txData[10];
uint8_t eOuiNon = 0, eCode = 0, eTypeClavierAlpha = 0;
uint8_t eHysteresis = 0;
uint8_t ePageHystExt = 0;
uint8_t eProg;
uint8_t u8AppointPageZone;
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
uint16_t u16ErreurEncours_old = 0;
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
bool bConsoProd, bPageUsine, bMaintenanceDepuisUsine, bInstallationDepuisUsine, bRegroupementZoneTemp;
bool bPageAccueil;
S_HISTO_ERR sHisto_Erreur;
uint16_t u16NumAction = 0;
uint32_t u32ValAction = 0, eAnciennePage;
S_CONFIG_HYDRAU_TEMP sConfig_Hydrau_temp;
S_CONFIG_PISCINE_TEMP sConfig_Piscine_temp;
S_PARAM_ECS sParam_ECS_temp;
uint32_t u32LastCyclique;
uint8_t u8Pointeur_buffer_tx, u8Pointeur_envoi;
S_PARAM_ZX sParamZxMZtemp[10];
uint16_t u16CodeCommande;
S_STATUT_LINKY sStatutLinky;
uint8_t oui_veille = 1;
uint8_t u8Nb_PAC;
uint8_t u3CarteGroupeA, u3CarteGroupeB, u3NumVoieGroupeA, u3NumVoieGroupeB;
uint8_t eTypeSimultaneChaudFroid, bLimitationPW_Froid, bLimitationPW_ECS;
uint8_t bUserAdaptationLoiDeau;
uint16_t TempNonChauffage;
bool bBouclageECSTemp2;
unsigned char u2TypeEchangeurECSTemp2;
S_PARAM_TEST_PAC sParam_Test_PAC;
S_CONFIG_OFFSET sConfig_Offset;
bool bAutorisationNoCode = false;
uint32_t TimerNoNeededCode;
uint32_t u32LastTick;


void setBackLightPWM(uint8_t pwm)
{
#ifndef SIMULATOR
  if(pwm == 0)
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
  else
  {
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, pwm * 10);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  }
#endif
}


uint8_t decodeRxData(rxData_t *rxData)
{
  uint16_t ptrRxBuffer = 6;
  uint8_t result = 0;
  header_t *pHeader;

  if(rxData->size != 0)
  {
    pHeader = (header_t*) rxData->data;
    switch (pHeader->comm)
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
#ifndef SIMULATOR
					u32LastCyclique = HAL_GetTick();
#endif

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
#ifndef SIMULATOR
							u32LastCyclique = HAL_GetTick();
#endif
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
								//memcpy(&sDate, &rxData->data[ptrRxBuffer], sizeof(S_DATE));
								if(memcmp(&rxData->data[ptrRxBuffer], &sDate.Year, sizeof(sDate.Year)))
								{
									arkteos_update.date_update = true;
								}
								else if(memcmp(&rxData->data[ptrRxBuffer + 1], &sDate.Month, sizeof(sDate.Month)))
								{
									arkteos_update.date_update = true;
								}
								else if(memcmp(&rxData->data[ptrRxBuffer + 2], &sDate.Date, sizeof(sDate.Date)))
								{
									arkteos_update.date_update = true;
								}
								else if(memcmp(&rxData->data[ptrRxBuffer + 3], &sDate.Hours, sizeof(sDate.Hours)))
								{
									arkteos_update.date_update = true;
								}
								else if(memcmp(&rxData->data[ptrRxBuffer + 4], &sDate.Minutes, sizeof(sDate.Minutes)))
								{
									arkteos_update.date_update = true;
								}
								memcpy(&sDate, &rxData->data[ptrRxBuffer], sizeof(S_DATE));
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
								if(memcmp(&rxData->data[ptrRxBuffer], &sStatut_RF[0], (sizeof(S_STATUT_RF) *8)))
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
#ifndef SIMULATOR
							u32LastCyclique = HAL_GetTick();
#endif
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
#ifndef SIMULATOR
					u32LastCyclique = HAL_GetTick();
#endif
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
          switch (pHeader->s_comm)
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
        switch (pHeader->s_comm)
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
        switch (pHeader->s_comm)
        {
          case SC_SAV_HISTO_ERR:
            if(pHeader->taille == sizeof(sHisto_Erreur))
            {
              memcpy(&sHisto_Erreur, &rxData->data[ptrRxBuffer], sizeof(S_HISTO_ERR));
            }
            break;
          default:
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



int ConvertPressionToTemperature(E_TYPE_GAZ typegaz, int PressionHP, int valpression)
{
  int retour, i;
  double dPressionPow[10];

  dPressionPow[0] = (double)valpression;

  for (i = 1; i < 8; i++)
  {
	  dPressionPow[i] = dPressionPow[0] * dPressionPow[i - 1];
  }

  switch (typegaz)
  {
    case GAZ_R407:
    	if (PressionHP)
    	{
			if (valpression < 100)
			{
			retour = (int)(-440.890 +
					20.0314 * dPressionPow[0] -
					0.577171 * dPressionPow[1] +
					0.0157434 * dPressionPow[2] -
					0.000289235 * dPressionPow[3] +
					3.21508E-6 * dPressionPow[4] -
					1.93876E-8 * dPressionPow[5] +
					4.84923E-11 * dPressionPow[6]);
			}
			else
			{
			retour = (int)(-315.126 +
					8.83384 * dPressionPow[0] -
					0.0548563 * dPressionPow[1] +
					0.000280008 * dPressionPow[2] -
					9.57202E-7 * dPressionPow[3] +
					2.04109E-9 * dPressionPow[4] -
					2.44626E-12 * dPressionPow[5] +
					1.25703E-15 * dPressionPow[6]);
			}
		}
    	else
    	{
			if (valpression < 50)
			retour = (int)(-368.083 +
					20.4559 * dPressionPow[0] -
					0.732898 * dPressionPow[1] +
					0.030192 * dPressionPow[2] -
					0.000945452 * dPressionPow[3] +
					1.90519E-5 * dPressionPow[4] -
					2.14951E-7 * dPressionPow[5] +
					1.023417E-9 * dPressionPow[6]);
			else
			retour = (int)(-284.147 +
					10.6022 * dPressionPow[0] -
					0.0915881 * dPressionPow[1] +
					0.000657693 * dPressionPow[2] -
					3.18556E-6 * dPressionPow[3] +
					9.64081E-9 * dPressionPow[4] -
					1.63942E-11 * dPressionPow[5] +
					1.19249E-14 * dPressionPow[6]);
    	}
    	break;

    case GAZ_R410:
		if (valpression < 50)
		{
		retour = (int)(-525.2 +
				19.82 * dPressionPow[0] -
				0.7059 * dPressionPow[1] +
				0.0289 * dPressionPow[2] -
				0.0008989 * dPressionPow[3] +
				1.801E-5 * dPressionPow[4] -
				2.023E-7 * dPressionPow[5] +
				9.600E-10 * dPressionPow[6]);
		}
		else
		{
		retour = (int)(-433.6 +
				9.663 * dPressionPow[0] -
				0.0734 * dPressionPow[1] +
				0.0004492 * dPressionPow[2] -
				1.809E-6 * dPressionPow[3] +
				4.462E-9 * dPressionPow[4] -
				6.091E-12 * dPressionPow[5] +
				3.513E-15 * dPressionPow[6]);
		}
		break;

    case GAZ_R134:
		if (valpression < 50)
		{
		retour = (int)(-264.2 +
				21.71 * dPressionPow[0] -
				0.7734 * dPressionPow[1] +
				0.03172 * dPressionPow[2] -
				0.0009877 * dPressionPow[3] +
				1.980E-5 * dPressionPow[4] -
				2.225E-7 * dPressionPow[5] +
				1.056E-9 * dPressionPow[6]);
		}
		else
		{
		retour = (int)(-153.8 +
				10.12 * dPressionPow[0] -
				0.07154 * dPressionPow[1] +
				0.0004112 * dPressionPow[2] -
				1.564E-6 * dPressionPow[3] +
				3.657E-9 * dPressionPow[4] -
				4.744E-12 * dPressionPow[5] +
				2.603E-15 * dPressionPow[6]);
		}
		break;

    case GAZ_R454C: //!!!!Formules pour pressions absolues
    	if (PressionHP)
		{
			retour = (int)(((-135.6138 * exp(-(dPressionPow[0] / 10) / 34.01293)) +
					(-41.3338 * exp(-(dPressionPow[0] / 10) / 3.43721)) +
					121.8346) * 10);
		}
    	else
    	{
			retour = (int)(((-117.1731 * exp(-(dPressionPow[0] / 10) / 24.17337)) +
						(-39.11009 * exp(-(dPressionPow[0] / 10) / 2.637)) +
						104.1427) *	10);
    	}
		break;

		default:
		  retour = 0;
		  break;
  	  }

  	  if (retour > 32766)
  	  {
  		  retour = 32766;
  	  }

  	  return retour;
}



int16_t ConvertTemperatureToPression(E_TYPE_GAZ typegaz, int16_t temperature)
{
	int16_t retour, i;
	double dPressionPow[8];

	dPressionPow[0] = (double)temperature;

	for (i = 1; i < 8; i++)
	{
		dPressionPow[i] = dPressionPow[0] * dPressionPow[i - 1];
	}

	switch (typegaz)
	{
		case GAZ_R410:
			if (temperature < -87)
			{
				retour = (int16_t)(69.84 +
				0.2512 * dPressionPow[0] +
				0.0003007 * dPressionPow[1] +
				1.592E-7 * dPressionPow[2] +
				2.815E-11 * dPressionPow[3] -
				2.036E-15 * dPressionPow[4]);
			}
			else
			{
				retour = (int16_t)(69.84 +
				0.2512 * dPressionPow[0] +
				0.0003006 * dPressionPow[1] +
				1.66E-7 * dPressionPow[2] +
				1.677E-11 * dPressionPow[3] +
				2.867E-14 * dPressionPow[4]);
			}
			break;

		case GAZ_R32:
		default:
			retour = (int16_t)((7.13142 +
			0.26037 * dPressionPow[0] +
			0.00317 * dPressionPow[1] +
			0.0000178202 * dPressionPow[2] +
			0.000000000959761 * dPressionPow[3] -
			0.00000000128567 * dPressionPow[4] +
			0.0000000000743881 * dPressionPow[5] -
			0.00000000000113789 * dPressionPow[6] +
			6.15107E-15 * dPressionPow[7]) * 10);
			break;
	  }

  	  return (retour);
}


bool verifErreurs(void)
{
//  uint8_t u8PointeurListeDefaut = 0;
////  uint16_t u16ListeErreur[25], u16AlerteEnCours, u16ErreurEncours_old = u16ErreurEncours;
//  uint16_t u16ListeErreur[25], u16AlerteEnCours;
//  bool bErreursNouvelles = false;
//
//
//  // Init
//  memset(u16ListeErreur, 0, sizeof(u16ListeErreur));
//  u16ErreurEncours = 0;
//  u16AlerteEnCours = 0;
//  // Erreur REG
//  for (int i = 0; i < 5; i++)
//  {
//    if(sStatut_PAC.au16ListeErreurEnCoursREG[i] && ((sStatut_PAC.au16ListeErreurEnCoursREG[i] & DEFAUT_NV_IHM) == 0))
//    {
//      if(sStatut_PAC.au16ListeErreurEnCoursREG[i] & T_DEF_DEFAUT)
//      {
//        if(u16ErreurEncours == 0)
//        {
//          u16ErreurEncours = sStatut_PAC.au16ListeErreurEnCoursREG[i];
//        }
//      }
//      else if(u16AlerteEnCours == 0)
//      {
//        u16AlerteEnCours = sStatut_PAC.au16ListeErreurEnCoursREG[i];
//      }
//      u16ListeErreur[u8PointeurListeDefaut++] = sStatut_PAC.au16ListeErreurEnCoursREG[i];
//    }
//  }
//  // Erreur Frigo
//  for (int i = 0; i < 5; i++)
//  {
//    if(sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i] && ((sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i] & DEFAUT_NV_IHM) == 0))
//    {
//      if(sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i] & T_DEF_DEFAUT)
//      {
//        if(u16ErreurEncours == 0)
//        {
//          u16ErreurEncours = sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i];
//        }
//      }
//      else if(u16AlerteEnCours == 0)
//      {
//        u16AlerteEnCours = sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i];
//      }
//      u16ListeErreur[u8PointeurListeDefaut++] = sCyclRegFrigo[0].commun.au16ListeErreurEnCoursFRIGO[i];
//    }
//  }
//  // Erreur FAN
//  if(sConfig_IHM.sModele_PAC.u8ModelePAC == AJPAC_III)
//  {
//    for (int i = 0; i < 5; i++)
//    {
//      if(sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i]
//          && ((sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i] & DEFAUT_NV_IHM) == 0))
//      {
//        if(sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i] & T_DEF_DEFAUT)
//        {
//          if(u16ErreurEncours == 0)
//          {
//            u16ErreurEncours = sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i];
//          }
//        }
//        else if(u16AlerteEnCours == 0)
//        {
//          u16AlerteEnCours = sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i];
//        }
//        u16ListeErreur[u8PointeurListeDefaut++] = sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i];
//      }
//    }
//  }
//  // Erreur Ether
//  for (int i = 0; i < 5; i++)
//  {
//    if(sCycEther.au16ListeErreurEnCoursETHER[i] && ((sCycEther.au16ListeErreurEnCoursETHER[i] & DEFAUT_NV_IHM) == 0))
//    {
//      if(sCycEther.au16ListeErreurEnCoursETHER[i] & T_DEF_DEFAUT)
//      {
//        if(u16ErreurEncours == 0)
//        {
//          u16ErreurEncours = sCycEther.au16ListeErreurEnCoursETHER[i];
//        }
//      }
//      else if(u16AlerteEnCours == 0)
//      {
//        u16AlerteEnCours = sCycEther.au16ListeErreurEnCoursETHER[i];
//      }
//      u16ListeErreur[u8PointeurListeDefaut++] = sCycEther.au16ListeErreurEnCoursETHER[i];
//    }
//  }
//  // MAJ des variables communes
//  if(u16ErreurEncours == 0)
//  {
//    u16ErreurEncours = u16AlerteEnCours;
//  }
//  //memcpy(u16ListeErreurEncours, u16ListeErreur, sizeof(u16ListeErreur));
//  // MAJ de l'affichage ou non
////  if(u16ErreurEncours_old != u16ErreurEncours)
////  {
////	u16ErreurEncours_old = u16ErreurEncours;
////    return true;
////  }
////  else
////  {
////	  return false;
////  }
////  if (u16ListeErreurEncours != u16ListeErreur)*
//  for (int i=0; i < 25 || bErreursNouvelles; i++)
//  {
////	  if (u16ListeErreurEncours[i] != u16ListeErreur[i])
////	  {
////		  memcpy(u16ListeErreurEncours, u16ListeErreur, sizeof(u16ListeErreur));
////		  return true;
////
////	  }
////	  else //if (i == 24)
////	  {
////		  return false;
////	  }
//	  if (u16ListeErreurEncours[i] != u16ListeErreur[i])
//	  {
//		  memcpy(u16ListeErreurEncours, u16ListeErreur, sizeof(u16ListeErreur));
//		  bErreursNouvelles = true;
//		  break;
//	  }
//
//  }
//  if (bErreursNouvelles) return true;
//  else return false;
////  else
////   {
////
////   }

  //**************************************** CPA
	uint8_t u8PointeurListeDefaut = 0;
	uint16_t u16ListeErreur[25], u16AlerteEnCours;//, u16ErreurEncours_old = u16ErreurEncours;

	// Init
	memset(u16ListeErreur, 0, sizeof(u16ListeErreur));
	u16ErreurEncours = 0;
	u16AlerteEnCours = 0;
	// Erreur REG
	for (int i = 0; i < 5; i++)
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
	for (int i = 0; i < 5; i++)
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
		for (int i = 0; i < 5; i++)
		{
			if(sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i]
			&& ((sCyclRegFrigo[0].pac.ajpac.sRetourFan.au16ListeErreurEnCoursFAN[i] & DEFAUT_NV_IHM) == 0))
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
	for (int i = 0; i < 5; i++)
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

	// MAJ de l'affichage ou non
	if(memcmp(u16ListeErreurEncours, u16ListeErreur, sizeof(u16ListeErreur)) == 0)
	{
		return false;
	}
	else
	{
		memcpy(u16ListeErreurEncours, u16ListeErreur, sizeof(u16ListeErreur));
		return true;
	}

}

uint32_t u32Erreurs[1000] = {
    0,								// 0
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    T_TEXT_ERR_10_GAUCHE_DEFAUT,	// 10
    T_TEXT_ERR_11_GAUCHE_DEFAUT, T_TEXT_ERR_12_GAUCHE_DEFAUT, T_TEXT_ERR_13_GAUCHE_DEFAUT, T_TEXT_ERR_14_GAUCHE_DEFAUT, T_TEXT_ERR_15_GAUCHE_DEFAUT,
    T_TEXT_ERR_16_GAUCHE_DEFAUT, T_TEXT_ERR_17_GAUCHE_DEFAUT, T_TEXT_ERR_18_GAUCHE_DEFAUT, 0,
    0,								// 20
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    T_TEXT_ERR_30_GAUCHE_DEFAUT,	// 30
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    T_TEXT_ERR_40_GAUCHE_DEFAUT,	// 40
    T_TEXT_ERR_41_GAUCHE_DEFAUT, T_TEXT_ERR_42_GAUCHE_DEFAUT, T_TEXT_ERR_43_GAUCHE_DEFAUT, T_TEXT_ERR_44_GAUCHE_DEFAUT, T_TEXT_ERR_45_GAUCHE_DEFAUT,
    T_TEXT_ERR_46_GAUCHE_DEFAUT, T_TEXT_ERR_47_GAUCHE_DEFAUT, T_TEXT_ERR_48_GAUCHE_DEFAUT, T_TEXT_ERR_49_GAUCHE_DEFAUT,
    T_TEXT_ERR_50_GAUCHE_DEFAUT,	// 50
    T_TEXT_ERR_51_GAUCHE_DEFAUT, T_TEXT_ERR_52_GAUCHE_DEFAUT, T_TEXT_ERR_53_GAUCHE_DEFAUT, T_TEXT_ERR_54_GAUCHE_DEFAUT, T_TEXT_ERR_55_GAUCHE_DEFAUT,
    T_TEXT_ERR_56_GAUCHE_DEFAUT, T_TEXT_ERR_57_GAUCHE_DEFAUT, T_TEXT_ERR_58_GAUCHE_DEFAUT, 0,
    0,								// 60
    T_TEXT_ERR_61_GAUCHE_DEFAUT, T_TEXT_ERR_62_GAUCHE_DEFAUT, T_TEXT_ERR_63_GAUCHE_DEFAUT, T_TEXT_ERR_64_GAUCHE_DEFAUT, T_TEXT_ERR_65_GAUCHE_DEFAUT,
    T_TEXT_ERR_66_GAUCHE_DEFAUT, T_TEXT_ERR_67_GAUCHE_DEFAUT, T_TEXT_ERR_68_GAUCHE_DEFAUT, T_TEXT_ERR_69_GAUCHE_DEFAUT,
    T_TEXT_ERR_70_GAUCHE_DEFAUT,	// 70
    T_TEXT_ERR_71_GAUCHE_DEFAUT, T_TEXT_ERR_72_GAUCHE_DEFAUT, T_TEXT_ERR_73_GAUCHE_DEFAUT, T_TEXT_ERR_74_GAUCHE_DEFAUT, T_TEXT_ERR_75_GAUCHE_DEFAUT,
    T_TEXT_ERR_76_GAUCHE_DEFAUT, T_TEXT_ERR_77_GAUCHE_DEFAUT, T_TEXT_ERR_78_GAUCHE_DEFAUT, T_TEXT_ERR_79_GAUCHE_DEFAUT,
    T_TEXT_ERR_80_GAUCHE_DEFAUT,	// 80
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,								// 90
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,								// 100
    0, 0, 0, T_TEXT_ERR_104_GAUCHE_DEFAUT, T_TEXT_ERR_105_GAUCHE_DEFAUT, 0, T_TEXT_ERR_107_GAUCHE_DEFAUT, 0, 0,
    T_TEXT_ERR_110_GAUCHE_DEFAUT,	// 110
    T_TEXT_ERR_111_GAUCHE_DEFAUT, T_TEXT_ERR_112_GAUCHE_DEFAUT, 0, T_TEXT_ERR_114_GAUCHE_DEFAUT, T_TEXT_ERR_115_GAUCHE_DEFAUT, T_TEXT_ERR_116_GAUCHE_DEFAUT,
    T_TEXT_ERR_117_GAUCHE_DEFAUT, T_TEXT_ERR_118_GAUCHE_DEFAUT, T_TEXT_ERR_119_GAUCHE_DEFAUT,
    T_TEXT_ERR_120_GAUCHE_DEFAUT,	// 120
    T_TEXT_ERR_121_GAUCHE_DEFAUT, T_TEXT_ERR_122_GAUCHE_DEFAUT, T_TEXT_ERR_123_GAUCHE_DEFAUT, T_TEXT_ERR_124_GAUCHE_DEFAUT, T_TEXT_ERR_125_GAUCHE_DEFAUT, 0,
    T_TEXT_ERR_127_GAUCHE_DEFAUT, T_TEXT_ERR_128_GAUCHE_DEFAUT, 0, T_TEXT_ERR_130_GAUCHE_DEFAUT,	// 130
    T_TEXT_ERR_131_GAUCHE_DEFAUT, T_TEXT_ERR_132_GAUCHE_DEFAUT, T_TEXT_ERR_133_GAUCHE_DEFAUT, T_TEXT_ERR_134_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0,							// 140
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 150
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 160
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 170
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 180
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 190
    0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_200_GAUCHE_DEFAUT,	// 200
    T_TEXT_ERR_201_GAUCHE_DEFAUT, T_TEXT_ERR_202_GAUCHE_DEFAUT,0,0,0,0,0,0,0,0,//210
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 220
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 230
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 240
	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_250_GAUCHE_DEFAUT,// 250
	T_TEXT_ERR_251_GAUCHE_DEFAUT,T_TEXT_ERR_252_GAUCHE_DEFAUT,T_TEXT_ERR_253_GAUCHE_DEFAUT, T_TEXT_ERR_254_GAUCHE_DEFAUT, T_TEXT_ERR_255_GAUCHE_DEFAUT,
	T_TEXT_ERR_256_GAUCHE_DEFAUT,T_TEXT_ERR_257_GAUCHE_DEFAUT,T_TEXT_ERR_258_GAUCHE_DEFAUT,T_TEXT_ERR_259_GAUCHE_DEFAUT,T_TEXT_ERR_260_GAUCHE_DEFAUT,//260
	T_TEXT_ERR_261_GAUCHE_DEFAUT,T_TEXT_ERR_262_GAUCHE_DEFAUT,T_TEXT_ERR_263_GAUCHE_DEFAUT,T_TEXT_ERR_264_GAUCHE_DEFAUT,T_TEXT_ERR_265_GAUCHE_DEFAUT,
	T_TEXT_ERR_266_GAUCHE_DEFAUT,T_TEXT_ERR_267_GAUCHE_DEFAUT,T_TEXT_ERR_268_GAUCHE_DEFAUT,T_TEXT_ERR_269_GAUCHE_DEFAUT,T_TEXT_ERR_270_GAUCHE_DEFAUT,//270
	T_TEXT_ERR_271_GAUCHE_DEFAUT,T_TEXT_ERR_272_GAUCHE_DEFAUT,T_TEXT_ERR_273_GAUCHE_DEFAUT,T_TEXT_ERR_274_GAUCHE_DEFAUT,T_TEXT_ERR_275_GAUCHE_DEFAUT,
	T_TEXT_ERR_276_GAUCHE_DEFAUT,T_TEXT_ERR_277_GAUCHE_DEFAUT,T_TEXT_ERR_278_GAUCHE_DEFAUT, 0, 0, //280
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 290
	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_300_GAUCHE_DEFAUT,	// 300
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 310
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 320
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 330
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 340
	T_TEXT_ERR_341_GAUCHE_DEFAUT, T_TEXT_ERR_342_GAUCHE_DEFAUT, T_TEXT_ERR_343_GAUCHE_DEFAUT, T_TEXT_ERR_344_GAUCHE_DEFAUT, T_TEXT_ERR_345_GAUCHE_DEFAUT,
	T_TEXT_ERR_346_GAUCHE_DEFAUT, T_TEXT_ERR_347_GAUCHE_DEFAUT, T_TEXT_ERR_348_GAUCHE_DEFAUT, 0, T_TEXT_ERR_350_GAUCHE_DEFAUT,	// 350
	T_TEXT_ERR_351_GAUCHE_DEFAUT, T_TEXT_ERR_352_GAUCHE_DEFAUT, T_TEXT_ERR_353_GAUCHE_DEFAUT, T_TEXT_ERR_354_GAUCHE_DEFAUT, T_TEXT_ERR_355_GAUCHE_DEFAUT,
	T_TEXT_ERR_356_GAUCHE_DEFAUT, T_TEXT_ERR_357_GAUCHE_DEFAUT, T_TEXT_ERR_358_GAUCHE_DEFAUT, T_TEXT_ERR_359_GAUCHE_DEFAUT, T_TEXT_ERR_360_GAUCHE_DEFAUT,// 360
	T_TEXT_ERR_361_GAUCHE_DEFAUT, T_TEXT_ERR_362_GAUCHE_DEFAUT, T_TEXT_ERR_363_GAUCHE_DEFAUT, T_TEXT_ERR_364_GAUCHE_DEFAUT, T_TEXT_ERR_365_GAUCHE_DEFAUT,
	T_TEXT_ERR_366_GAUCHE_DEFAUT, T_TEXT_ERR_367_GAUCHE_DEFAUT, T_TEXT_ERR_368_GAUCHE_DEFAUT, T_TEXT_ERR_369_GAUCHE_DEFAUT, T_TEXT_ERR_370_GAUCHE_DEFAUT,// 370
	T_TEXT_ERR_371_GAUCHE_DEFAUT, T_TEXT_ERR_372_GAUCHE_DEFAUT, T_TEXT_ERR_373_GAUCHE_DEFAUT, T_TEXT_ERR_374_GAUCHE_DEFAUT, T_TEXT_ERR_375_GAUCHE_DEFAUT,
	T_TEXT_ERR_376_GAUCHE_DEFAUT, T_TEXT_ERR_377_GAUCHE_DEFAUT, T_TEXT_ERR_378_GAUCHE_DEFAUT, T_TEXT_ERR_379_GAUCHE_DEFAUT, T_TEXT_ERR_380_GAUCHE_DEFAUT,// 380
	T_TEXT_ERR_381_GAUCHE_DEFAUT, T_TEXT_ERR_382_GAUCHE_DEFAUT, T_TEXT_ERR_383_GAUCHE_DEFAUT, T_TEXT_ERR_384_GAUCHE_DEFAUT, T_TEXT_ERR_385_GAUCHE_DEFAUT,
	T_TEXT_ERR_386_GAUCHE_DEFAUT, T_TEXT_ERR_387_GAUCHE_DEFAUT, T_TEXT_ERR_388_GAUCHE_DEFAUT, T_TEXT_ERR_389_GAUCHE_DEFAUT, T_TEXT_ERR_390_GAUCHE_DEFAUT,// 390
	T_TEXT_ERR_391_GAUCHE_DEFAUT, T_TEXT_ERR_392_GAUCHE_DEFAUT, T_TEXT_ERR_393_GAUCHE_DEFAUT, T_TEXT_ERR_394_GAUCHE_DEFAUT, T_TEXT_ERR_395_GAUCHE_DEFAUT,
	T_TEXT_ERR_396_GAUCHE_DEFAUT, T_TEXT_ERR_397_GAUCHE_DEFAUT, T_TEXT_ERR_398_GAUCHE_DEFAUT, T_TEXT_ERR_399_GAUCHE_DEFAUT, T_TEXT_ERR_400_GAUCHE_DEFAUT,// 400
	T_TEXT_ERR_401_GAUCHE_DEFAUT, T_TEXT_ERR_402_GAUCHE_DEFAUT, T_TEXT_ERR_403_GAUCHE_DEFAUT, T_TEXT_ERR_404_GAUCHE_DEFAUT, T_TEXT_ERR_405_GAUCHE_DEFAUT,
	T_TEXT_ERR_406_GAUCHE_DEFAUT, 0, 0, 0, 0,				    // 410
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 420
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 430
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 440
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 450
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 460
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 470
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 480
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 490
	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_500_GAUCHE_DEFAUT,	// 500
	T_TEXT_ERR_501_GAUCHE_DEFAUT, T_TEXT_ERR_502_GAUCHE_DEFAUT, T_TEXT_ERR_503_GAUCHE_DEFAUT, T_TEXT_ERR_504_GAUCHE_DEFAUT, T_TEXT_ERR_505_GAUCHE_DEFAUT,
	T_TEXT_ERR_506_GAUCHE_DEFAUT, T_TEXT_ERR_507_GAUCHE_DEFAUT, T_TEXT_ERR_508_GAUCHE_DEFAUT, T_TEXT_ERR_509_GAUCHE_DEFAUT, T_TEXT_ERR_510_GAUCHE_DEFAUT,// 510
	T_TEXT_ERR_511_GAUCHE_DEFAUT, T_TEXT_ERR_512_GAUCHE_DEFAUT, T_TEXT_ERR_513_GAUCHE_DEFAUT, T_TEXT_ERR_514_GAUCHE_DEFAUT, T_TEXT_ERR_515_GAUCHE_DEFAUT,
	T_TEXT_ERR_516_GAUCHE_DEFAUT, T_TEXT_ERR_517_GAUCHE_DEFAUT, T_TEXT_ERR_518_GAUCHE_DEFAUT, T_TEXT_ERR_519_GAUCHE_DEFAUT, T_TEXT_ERR_520_GAUCHE_DEFAUT,// 520
	T_TEXT_ERR_521_GAUCHE_DEFAUT, T_TEXT_ERR_522_GAUCHE_DEFAUT, T_TEXT_ERR_523_GAUCHE_DEFAUT, T_TEXT_ERR_524_GAUCHE_DEFAUT, T_TEXT_ERR_525_GAUCHE_DEFAUT,
	T_TEXT_ERR_526_GAUCHE_DEFAUT, T_TEXT_ERR_527_GAUCHE_DEFAUT, T_TEXT_ERR_528_GAUCHE_DEFAUT, T_TEXT_ERR_529_GAUCHE_DEFAUT, T_TEXT_ERR_530_GAUCHE_DEFAUT,// 530
	T_TEXT_ERR_531_GAUCHE_DEFAUT, T_TEXT_ERR_532_GAUCHE_DEFAUT, T_TEXT_ERR_533_GAUCHE_DEFAUT, T_TEXT_ERR_534_GAUCHE_DEFAUT, T_TEXT_ERR_535_GAUCHE_DEFAUT,
	T_TEXT_ERR_536_GAUCHE_DEFAUT, T_TEXT_ERR_537_GAUCHE_DEFAUT, T_TEXT_ERR_538_GAUCHE_DEFAUT, T_TEXT_ERR_539_GAUCHE_DEFAUT, T_TEXT_ERR_540_GAUCHE_DEFAUT,// 540
	T_TEXT_ERR_541_GAUCHE_DEFAUT, T_TEXT_ERR_542_GAUCHE_DEFAUT, T_TEXT_ERR_543_GAUCHE_DEFAUT, T_TEXT_ERR_544_GAUCHE_DEFAUT, T_TEXT_ERR_545_GAUCHE_DEFAUT,
	T_TEXT_ERR_546_GAUCHE_DEFAUT, T_TEXT_ERR_547_GAUCHE_DEFAUT, T_TEXT_ERR_548_GAUCHE_DEFAUT, T_TEXT_ERR_549_GAUCHE_DEFAUT, T_TEXT_ERR_550_GAUCHE_DEFAUT,// 550
	T_TEXT_ERR_551_GAUCHE_DEFAUT, T_TEXT_ERR_552_GAUCHE_DEFAUT, T_TEXT_ERR_553_GAUCHE_DEFAUT, T_TEXT_ERR_554_GAUCHE_DEFAUT, T_TEXT_ERR_555_GAUCHE_DEFAUT,
	T_TEXT_ERR_556_GAUCHE_DEFAUT, T_TEXT_ERR_557_GAUCHE_DEFAUT, T_TEXT_ERR_558_GAUCHE_DEFAUT, T_TEXT_ERR_559_GAUCHE_DEFAUT, T_TEXT_ERR_560_GAUCHE_DEFAUT,// 560
	T_TEXT_ERR_561_GAUCHE_DEFAUT, T_TEXT_ERR_562_GAUCHE_DEFAUT, T_TEXT_ERR_563_GAUCHE_DEFAUT, T_TEXT_ERR_564_GAUCHE_DEFAUT, T_TEXT_ERR_565_GAUCHE_DEFAUT,
	T_TEXT_ERR_566_GAUCHE_DEFAUT, T_TEXT_ERR_567_GAUCHE_DEFAUT, T_TEXT_ERR_568_GAUCHE_DEFAUT, T_TEXT_ERR_569_GAUCHE_DEFAUT, T_TEXT_ERR_570_GAUCHE_DEFAUT,// 570
	T_TEXT_ERR_571_GAUCHE_DEFAUT, T_TEXT_ERR_572_GAUCHE_DEFAUT, T_TEXT_ERR_573_GAUCHE_DEFAUT, T_TEXT_ERR_574_GAUCHE_DEFAUT, T_TEXT_ERR_575_GAUCHE_DEFAUT,
	T_TEXT_ERR_576_GAUCHE_DEFAUT, T_TEXT_ERR_577_GAUCHE_DEFAUT, 0, 0, 0, // 580
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 590
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 600
	0, 0, 0, T_TEXT_ERR_604_GAUCHE_DEFAUT, T_TEXT_ERR_605_GAUCHE_DEFAUT, 0, 0, 0, 0, T_TEXT_ERR_610_GAUCHE_DEFAUT,// 610
	T_TEXT_ERR_611_GAUCHE_DEFAUT, T_TEXT_ERR_612_GAUCHE_DEFAUT, 0, 0, T_TEXT_ERR_615_GAUCHE_DEFAUT, T_TEXT_ERR_616_GAUCHE_DEFAUT, T_TEXT_ERR_617_GAUCHE_DEFAUT,
	T_TEXT_ERR_618_GAUCHE_DEFAUT, T_TEXT_ERR_619_GAUCHE_DEFAUT, T_TEXT_ERR_620_GAUCHE_DEFAUT,// 620
	T_TEXT_ERR_621_GAUCHE_DEFAUT, T_TEXT_ERR_622_GAUCHE_DEFAUT, T_TEXT_ERR_623_GAUCHE_DEFAUT, T_TEXT_ERR_624_GAUCHE_DEFAUT, T_TEXT_ERR_625_GAUCHE_DEFAUT,
	T_TEXT_ERR_626_GAUCHE_DEFAUT, T_TEXT_ERR_627_GAUCHE_DEFAUT, T_TEXT_ERR_628_GAUCHE_DEFAUT, T_TEXT_ERR_629_GAUCHE_DEFAUT, 0,							 // 630
	T_TEXT_ERR_631_GAUCHE_DEFAUT, T_TEXT_ERR_632_GAUCHE_DEFAUT, T_TEXT_ERR_633_GAUCHE_DEFAUT, T_TEXT_ERR_634_GAUCHE_DEFAUT, T_TEXT_ERR_635_GAUCHE_DEFAUT,
	0, T_TEXT_ERR_637_GAUCHE_DEFAUT, T_TEXT_ERR_638_GAUCHE_DEFAUT, T_TEXT_ERR_639_GAUCHE_DEFAUT, T_TEXT_ERR_640_GAUCHE_DEFAUT,// 640
	T_TEXT_ERR_641_GAUCHE_DEFAUT, T_TEXT_ERR_642_GAUCHE_DEFAUT, T_TEXT_ERR_643_GAUCHE_DEFAUT, T_TEXT_ERR_644_GAUCHE_DEFAUT, T_TEXT_ERR_645_GAUCHE_DEFAUT,
	T_TEXT_ERR_646_GAUCHE_DEFAUT, T_TEXT_ERR_647_GAUCHE_DEFAUT, T_TEXT_ERR_648_GAUCHE_DEFAUT, T_TEXT_ERR_649_GAUCHE_DEFAUT, T_TEXT_ERR_650_GAUCHE_DEFAUT,// 650
	T_TEXT_ERR_651_GAUCHE_DEFAUT, T_TEXT_ERR_652_GAUCHE_DEFAUT, T_TEXT_ERR_653_GAUCHE_DEFAUT, T_TEXT_ERR_654_GAUCHE_DEFAUT, T_TEXT_ERR_655_GAUCHE_DEFAUT,
	T_TEXT_ERR_656_GAUCHE_DEFAUT, T_TEXT_ERR_657_GAUCHE_DEFAUT, T_TEXT_ERR_658_GAUCHE_DEFAUT, 0, 0,						    // 660
	T_TEXT_ERR_661_GAUCHE_DEFAUT, T_TEXT_ERR_662_GAUCHE_DEFAUT, T_TEXT_ERR_663_GAUCHE_DEFAUT, T_TEXT_ERR_664_GAUCHE_DEFAUT, T_TEXT_ERR_665_GAUCHE_DEFAUT,
	T_TEXT_ERR_666_GAUCHE_DEFAUT, T_TEXT_ERR_667_GAUCHE_DEFAUT, T_TEXT_ERR_668_GAUCHE_DEFAUT, T_TEXT_ERR_669_GAUCHE_DEFAUT, T_TEXT_ERR_670_GAUCHE_DEFAUT,// 670
	T_TEXT_ERR_671_GAUCHE_DEFAUT, T_TEXT_ERR_672_GAUCHE_DEFAUT, T_TEXT_ERR_673_GAUCHE_DEFAUT, T_TEXT_ERR_674_GAUCHE_DEFAUT, T_TEXT_ERR_675_GAUCHE_DEFAUT,
	T_TEXT_ERR_676_GAUCHE_DEFAUT, T_TEXT_ERR_677_GAUCHE_DEFAUT, T_TEXT_ERR_678_GAUCHE_DEFAUT, T_TEXT_ERR_679_GAUCHE_DEFAUT, T_TEXT_ERR_680_GAUCHE_DEFAUT,// 680
	T_TEXT_ERR_681_GAUCHE_DEFAUT, T_TEXT_ERR_682_GAUCHE_DEFAUT, T_TEXT_ERR_683_GAUCHE_DEFAUT, T_TEXT_ERR_684_GAUCHE_DEFAUT, T_TEXT_ERR_685_GAUCHE_DEFAUT,
	T_TEXT_ERR_686_GAUCHE_DEFAUT, T_TEXT_ERR_687_GAUCHE_DEFAUT, T_TEXT_ERR_688_GAUCHE_DEFAUT, 0, 0,							// 690
	T_TEXT_ERR_691_GAUCHE_DEFAUT, T_TEXT_ERR_692_GAUCHE_DEFAUT, T_TEXT_ERR_693_GAUCHE_DEFAUT, T_TEXT_ERR_694_GAUCHE_DEFAUT, T_TEXT_ERR_695_GAUCHE_DEFAUT,
	T_TEXT_ERR_696_GAUCHE_DEFAUT, T_TEXT_ERR_697_GAUCHE_DEFAUT, T_TEXT_ERR_698_GAUCHE_DEFAUT, 0, T_TEXT_ERR_700_GAUCHE_DEFAUT,	// 700
	T_TEXT_ERR_701_GAUCHE_DEFAUT, T_TEXT_ERR_702_GAUCHE_DEFAUT,0,0,0,0,0,0,0,0,	// 710
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 720
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 730
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 740
	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_750_GAUCHE_DEFAUT,// 750
	0, T_TEXT_ERR_752_GAUCHE_DEFAUT, T_TEXT_ERR_753_GAUCHE_DEFAUT,T_TEXT_ERR_754_GAUCHE_DEFAUT,T_TEXT_ERR_755_GAUCHE_DEFAUT, T_TEXT_ERR_756_GAUCHE_DEFAUT,
	T_TEXT_ERR_757_GAUCHE_DEFAUT, T_TEXT_ERR_758_GAUCHE_DEFAUT, T_TEXT_ERR_759_GAUCHE_DEFAUT,T_TEXT_ERR_760_GAUCHE_DEFAUT,// 760
	T_TEXT_ERR_761_GAUCHE_DEFAUT,T_TEXT_ERR_762_GAUCHE_DEFAUT,T_TEXT_ERR_763_GAUCHE_DEFAUT,T_TEXT_ERR_764_GAUCHE_DEFAUT,T_TEXT_ERR_765_GAUCHE_DEFAUT,
	T_TEXT_ERR_766_GAUCHE_DEFAUT,T_TEXT_ERR_767_GAUCHE_DEFAUT,0,0,0,	// 770
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 780
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 790
	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_800_GAUCHE_DEFAUT,	// 800
	0, T_TEXT_ERR_802_GAUCHE_DEFAUT,T_TEXT_ERR_803_GAUCHE_DEFAUT,T_TEXT_ERR_804_GAUCHE_DEFAUT,T_TEXT_ERR_805_GAUCHE_DEFAUT,T_TEXT_ERR_806_GAUCHE_DEFAUT,0,0,0,0,	// 810
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 820
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 830
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 840
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 850
	0, 0, 0, 0, 0, 0, T_TEXT_ERR_857_GAUCHE_DEFAUT,T_TEXT_ERR_858_GAUCHE_DEFAUT,T_TEXT_ERR_859_GAUCHE_DEFAUT,T_TEXT_ERR_860_GAUCHE_DEFAUT, // 860
	T_TEXT_ERR_861_GAUCHE_DEFAUT,T_TEXT_ERR_862_GAUCHE_DEFAUT,T_TEXT_ERR_863_GAUCHE_DEFAUT,T_TEXT_ERR_864_GAUCHE_DEFAUT,T_TEXT_ERR_865_GAUCHE_DEFAUT,
	T_TEXT_ERR_866_GAUCHE_DEFAUT,T_TEXT_ERR_867_GAUCHE_DEFAUT,T_TEXT_ERR_868_GAUCHE_DEFAUT,T_TEXT_ERR_869_GAUCHE_DEFAUT,T_TEXT_ERR_870_GAUCHE_DEFAUT,  // 870
	T_TEXT_ERR_871_GAUCHE_DEFAUT,T_TEXT_ERR_872_GAUCHE_DEFAUT,T_TEXT_ERR_873_GAUCHE_DEFAUT,0,0,0,0,0,0,0, //880
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 890
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 900
};

//Défaut INVERTERRA
uint32_t u32ErreursINV[1000] = {
	    0,								// 0
	    0, 0, 0, 0, 0, 0, 0, 0, 0,
	    T_TEXT_ERR_10_GAUCHE_DEFAUT,	// 10
	    T_TEXT_ERR_11_GAUCHE_DEFAUT, T_TEXT_ERR_12_GAUCHE_DEFAUT, T_TEXT_ERR_13_GAUCHE_DEFAUT, T_TEXT_ERR_14_GAUCHE_DEFAUT, T_TEXT_ERR_15_GAUCHE_DEFAUT,
	    T_TEXT_ERR_16_GAUCHE_DEFAUT, T_TEXT_ERR_17_GAUCHE_DEFAUT, T_TEXT_ERR_18_GAUCHE_DEFAUT, 0,
	    0,								// 20
	    0, 0, 0, 0, 0, 0, 0, 0, 0,
	    T_TEXT_ERR_30_GAUCHE_DEFAUT,	// 30
	    0, 0, 0, 0, 0, 0, 0, 0, 0,
	    T_TEXT_ERR_40_GAUCHE_DEFAUT,	// 40
	    T_TEXT_ERR_41_GAUCHE_DEFAUT, T_TEXT_ERR_42_GAUCHE_DEFAUT, T_TEXT_ERR_43_GAUCHE_DEFAUT, T_TEXT_ERR_44_GAUCHE_DEFAUT, T_TEXT_ERR_45_GAUCHE_DEFAUT,
	    T_TEXT_ERR_46_GAUCHE_DEFAUT, T_TEXT_ERR_47_GAUCHE_DEFAUT, T_TEXT_ERR_48_GAUCHE_DEFAUT, T_TEXT_ERR_49_GAUCHE_DEFAUT,
	    T_TEXT_ERR_50_GAUCHE_DEFAUT,	// 50
	    T_TEXT_ERR_51_GAUCHE_DEFAUT, T_TEXT_ERR_52_GAUCHE_DEFAUT, T_TEXT_ERR_53_GAUCHE_DEFAUT, T_TEXT_ERR_54_GAUCHE_DEFAUT, T_TEXT_ERR_55_GAUCHE_DEFAUT,
	    T_TEXT_ERR_56_GAUCHE_DEFAUT, T_TEXT_ERR_57_GAUCHE_DEFAUT, T_TEXT_ERR_58_GAUCHE_DEFAUT, 0,
	    0,								// 60
	    T_TEXT_ERR_61_GAUCHE_DEFAUT, T_TEXT_ERR_62_GAUCHE_DEFAUT, T_TEXT_ERR_63_GAUCHE_DEFAUT, T_TEXT_ERR_64_GAUCHE_DEFAUT, T_TEXT_ERR_65_GAUCHE_DEFAUT,
	    T_TEXT_ERR_66_GAUCHE_DEFAUT, T_TEXT_ERR_67_GAUCHE_DEFAUT, T_TEXT_ERR_68_GAUCHE_DEFAUT, T_TEXT_ERR_69_GAUCHE_DEFAUT,
	    T_TEXT_ERR_70_GAUCHE_DEFAUT,	// 70
	    T_TEXT_ERR_71_GAUCHE_DEFAUT, T_TEXT_ERR_72_GAUCHE_DEFAUT, T_TEXT_ERR_73_GAUCHE_DEFAUT, T_TEXT_ERR_74_GAUCHE_DEFAUT, T_TEXT_ERR_75_GAUCHE_DEFAUT,
	    T_TEXT_ERR_76_GAUCHE_DEFAUT, T_TEXT_ERR_77_GAUCHE_DEFAUT, T_TEXT_ERR_78_GAUCHE_DEFAUT, T_TEXT_ERR_79_GAUCHE_DEFAUT,
	    T_TEXT_ERR_80_GAUCHE_DEFAUT,	// 80
	    0, 0, 0, 0, 0, 0, 0, 0, 0,
	    0,								// 90
	    0, 0, 0, 0, 0, 0, 0, 0, 0,
	    0,								// 100
	    0, 0, 0, T_TEXT_ERR_104_GAUCHE_DEFAUT, T_TEXT_ERR_105_GAUCHE_DEFAUT, 0, T_TEXT_ERR_107_GAUCHE_DEFAUT, 0, 0,
	    T_TEXT_ERR_110_GAUCHE_DEFAUT,	// 110
	    T_TEXT_ERR_111_GAUCHE_DEFAUT, T_TEXT_ERR_112_GAUCHE_DEFAUT, 0, T_TEXT_ERR_114_GAUCHE_DEFAUT, T_TEXT_ERR_115_GAUCHE_DEFAUT, T_TEXT_ERR_116_GAUCHE_DEFAUT,
	    T_TEXT_ERR_117_GAUCHE_DEFAUT, T_TEXT_ERR_118_GAUCHE_DEFAUT, T_TEXT_ERR_119_GAUCHE_DEFAUT,
	    T_TEXT_ERR_120_GAUCHE_DEFAUT,	// 120
	    T_TEXT_ERR_121_GAUCHE_DEFAUT, T_TEXT_ERR_122_GAUCHE_DEFAUT, T_TEXT_ERR_123_GAUCHE_DEFAUT, T_TEXT_ERR_124_GAUCHE_DEFAUT, T_TEXT_ERR_125_GAUCHE_DEFAUT, 0,
	    T_TEXT_ERR_127_GAUCHE_DEFAUT, T_TEXT_ERR_128_GAUCHE_DEFAUT, 0, T_TEXT_ERR_130_GAUCHE_DEFAUT,	// 130
	    T_TEXT_ERR_131_GAUCHE_DEFAUT, T_TEXT_ERR_132_GAUCHE_DEFAUT, T_TEXT_ERR_133_GAUCHE_DEFAUT, T_TEXT_ERR_134_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0,							// 140
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 150
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 160
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 170
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 180
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 190
	    0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_200_INV_GAUCHE_DEFAUT,//200
		T_TEXT_ERR_201_INV_GAUCHE_DEFAUT,T_TEXT_ERR_202_INV_GAUCHE_DEFAUT,T_TEXT_ERR_203_INV_GAUCHE_DEFAUT,0,0,0,0,0,0,T_TEXT_ERR_210_INV_GAUCHE_DEFAUT,  //210
		T_TEXT_ERR_211_INV_GAUCHE_DEFAUT,T_TEXT_ERR_212_INV_GAUCHE_DEFAUT,T_TEXT_ERR_213_INV_GAUCHE_DEFAUT,T_TEXT_ERR_214_INV_GAUCHE_DEFAUT,T_TEXT_ERR_215_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_216_INV_GAUCHE_DEFAUT,T_TEXT_ERR_217_INV_GAUCHE_DEFAUT,0,0,0,  //220
		0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_230_INV_GAUCHE_DEFAUT, // 230
		T_TEXT_ERR_231_INV_GAUCHE_DEFAUT, T_TEXT_ERR_232_INV_GAUCHE_DEFAUT,T_TEXT_ERR_233_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_240_INV_GAUCHE_DEFAUT,	// 240
		T_TEXT_ERR_241_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_250_INV_GAUCHE_DEFAUT,  //250
		T_TEXT_ERR_251_INV_GAUCHE_DEFAUT, T_TEXT_ERR_252_INV_GAUCHE_DEFAUT,T_TEXT_ERR_253_INV_GAUCHE_DEFAUT, T_TEXT_ERR_254_INV_GAUCHE_DEFAUT, T_TEXT_ERR_255_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_256_INV_GAUCHE_DEFAUT, T_TEXT_ERR_257_INV_GAUCHE_DEFAUT, T_TEXT_ERR_258_INV_GAUCHE_DEFAUT, T_TEXT_ERR_259_INV_GAUCHE_DEFAUT, T_TEXT_ERR_260_INV_GAUCHE_DEFAUT,	// 260
		T_TEXT_ERR_261_INV_GAUCHE_DEFAUT, T_TEXT_ERR_262_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, 0, 0,//270
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 280
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 290
		0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_300_INV_GAUCHE_DEFAUT, //300
		T_TEXT_ERR_301_INV_GAUCHE_DEFAUT,T_TEXT_ERR_302_INV_GAUCHE_DEFAUT,T_TEXT_ERR_303_INV_GAUCHE_DEFAUT,T_TEXT_ERR_304_INV_GAUCHE_DEFAUT,T_TEXT_ERR_305_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_306_INV_GAUCHE_DEFAUT,T_TEXT_ERR_307_INV_GAUCHE_DEFAUT,T_TEXT_ERR_308_INV_GAUCHE_DEFAUT,T_TEXT_ERR_309_INV_GAUCHE_DEFAUT,T_TEXT_ERR_310_INV_GAUCHE_DEFAUT,  //310
		T_TEXT_ERR_311_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, 0, 0, 0,	// 320
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 33
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 340
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 350
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 360
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 370
		0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_380_INV_GAUCHE_DEFAUT, // 380
		T_TEXT_ERR_381_INV_GAUCHE_DEFAUT,T_TEXT_ERR_382_INV_GAUCHE_DEFAUT,T_TEXT_ERR_383_INV_GAUCHE_DEFAUT,T_TEXT_ERR_384_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0,  //390
		0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_400_INV_GAUCHE_DEFAUT, // 400
		T_TEXT_ERR_401_INV_GAUCHE_DEFAUT,T_TEXT_ERR_402_INV_GAUCHE_DEFAUT,T_TEXT_ERR_403_INV_GAUCHE_DEFAUT,T_TEXT_ERR_404_INV_GAUCHE_DEFAUT,T_TEXT_ERR_405_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_406_INV_GAUCHE_DEFAUT,T_TEXT_ERR_407_INV_GAUCHE_DEFAUT,T_TEXT_ERR_408_INV_GAUCHE_DEFAUT,T_TEXT_ERR_409_INV_GAUCHE_DEFAUT,T_TEXT_ERR_410_INV_GAUCHE_DEFAUT,  //410
		T_TEXT_ERR_411_INV_GAUCHE_DEFAUT,T_TEXT_ERR_412_INV_GAUCHE_DEFAUT,T_TEXT_ERR_413_INV_GAUCHE_DEFAUT,T_TEXT_ERR_414_INV_GAUCHE_DEFAUT,T_TEXT_ERR_415_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_416_INV_GAUCHE_DEFAUT,T_TEXT_ERR_417_INV_GAUCHE_DEFAUT,T_TEXT_ERR_418_INV_GAUCHE_DEFAUT,T_TEXT_ERR_419_INV_GAUCHE_DEFAUT,T_TEXT_ERR_420_INV_GAUCHE_DEFAUT,  //420
		T_TEXT_ERR_421_INV_GAUCHE_DEFAUT,T_TEXT_ERR_422_INV_GAUCHE_DEFAUT,T_TEXT_ERR_423_INV_GAUCHE_DEFAUT,T_TEXT_ERR_424_INV_GAUCHE_DEFAUT,T_TEXT_ERR_425_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_426_INV_GAUCHE_DEFAUT,T_TEXT_ERR_427_INV_GAUCHE_DEFAUT,T_TEXT_ERR_428_INV_GAUCHE_DEFAUT,T_TEXT_ERR_429_INV_GAUCHE_DEFAUT,T_TEXT_ERR_430_INV_GAUCHE_DEFAUT,  //430
		T_TEXT_ERR_431_INV_GAUCHE_DEFAUT,T_TEXT_ERR_432_INV_GAUCHE_DEFAUT,T_TEXT_ERR_433_INV_GAUCHE_DEFAUT,T_TEXT_ERR_434_INV_GAUCHE_DEFAUT,T_TEXT_ERR_435_INV_GAUCHE_DEFAUT,
		T_TEXT_ERR_436_INV_GAUCHE_DEFAUT,T_TEXT_ERR_437_INV_GAUCHE_DEFAUT,T_TEXT_ERR_438_INV_GAUCHE_DEFAUT, 0, 0,  //440
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 450
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 460
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 470
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 480
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 490
		0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_500_GAUCHE_DEFAUT,	// 500
		T_TEXT_ERR_501_GAUCHE_DEFAUT, T_TEXT_ERR_502_GAUCHE_DEFAUT, T_TEXT_ERR_503_GAUCHE_DEFAUT, T_TEXT_ERR_504_GAUCHE_DEFAUT, T_TEXT_ERR_505_GAUCHE_DEFAUT,
		T_TEXT_ERR_506_GAUCHE_DEFAUT, T_TEXT_ERR_507_GAUCHE_DEFAUT, T_TEXT_ERR_508_GAUCHE_DEFAUT, T_TEXT_ERR_509_GAUCHE_DEFAUT, T_TEXT_ERR_510_GAUCHE_DEFAUT,// 510
		T_TEXT_ERR_511_GAUCHE_DEFAUT, T_TEXT_ERR_512_GAUCHE_DEFAUT, T_TEXT_ERR_513_GAUCHE_DEFAUT, T_TEXT_ERR_514_GAUCHE_DEFAUT, T_TEXT_ERR_515_GAUCHE_DEFAUT,
		T_TEXT_ERR_516_GAUCHE_DEFAUT, T_TEXT_ERR_517_GAUCHE_DEFAUT, T_TEXT_ERR_518_GAUCHE_DEFAUT, T_TEXT_ERR_519_GAUCHE_DEFAUT, T_TEXT_ERR_520_GAUCHE_DEFAUT,// 520
		T_TEXT_ERR_521_GAUCHE_DEFAUT, T_TEXT_ERR_522_GAUCHE_DEFAUT, T_TEXT_ERR_523_GAUCHE_DEFAUT, T_TEXT_ERR_524_GAUCHE_DEFAUT, T_TEXT_ERR_525_GAUCHE_DEFAUT,
		T_TEXT_ERR_526_GAUCHE_DEFAUT, T_TEXT_ERR_527_GAUCHE_DEFAUT, T_TEXT_ERR_528_GAUCHE_DEFAUT, T_TEXT_ERR_529_GAUCHE_DEFAUT, T_TEXT_ERR_530_GAUCHE_DEFAUT,// 530
		T_TEXT_ERR_531_GAUCHE_DEFAUT, T_TEXT_ERR_532_GAUCHE_DEFAUT, T_TEXT_ERR_533_GAUCHE_DEFAUT, T_TEXT_ERR_534_GAUCHE_DEFAUT, T_TEXT_ERR_535_GAUCHE_DEFAUT,
		T_TEXT_ERR_536_GAUCHE_DEFAUT, T_TEXT_ERR_537_GAUCHE_DEFAUT, T_TEXT_ERR_538_GAUCHE_DEFAUT, T_TEXT_ERR_539_GAUCHE_DEFAUT, T_TEXT_ERR_540_GAUCHE_DEFAUT,// 540
		T_TEXT_ERR_541_GAUCHE_DEFAUT, T_TEXT_ERR_542_GAUCHE_DEFAUT, T_TEXT_ERR_543_GAUCHE_DEFAUT, T_TEXT_ERR_544_GAUCHE_DEFAUT, T_TEXT_ERR_545_GAUCHE_DEFAUT,
		T_TEXT_ERR_546_GAUCHE_DEFAUT, T_TEXT_ERR_547_GAUCHE_DEFAUT, T_TEXT_ERR_548_GAUCHE_DEFAUT, T_TEXT_ERR_549_GAUCHE_DEFAUT, T_TEXT_ERR_550_GAUCHE_DEFAUT,// 550
		T_TEXT_ERR_551_GAUCHE_DEFAUT, T_TEXT_ERR_552_GAUCHE_DEFAUT, T_TEXT_ERR_553_GAUCHE_DEFAUT, T_TEXT_ERR_554_GAUCHE_DEFAUT, T_TEXT_ERR_555_GAUCHE_DEFAUT,
		T_TEXT_ERR_556_GAUCHE_DEFAUT, T_TEXT_ERR_557_GAUCHE_DEFAUT, T_TEXT_ERR_558_GAUCHE_DEFAUT, T_TEXT_ERR_559_GAUCHE_DEFAUT, T_TEXT_ERR_560_GAUCHE_DEFAUT,// 560
		T_TEXT_ERR_561_GAUCHE_DEFAUT, T_TEXT_ERR_562_GAUCHE_DEFAUT, T_TEXT_ERR_563_GAUCHE_DEFAUT, T_TEXT_ERR_564_GAUCHE_DEFAUT, T_TEXT_ERR_565_GAUCHE_DEFAUT,
		T_TEXT_ERR_566_GAUCHE_DEFAUT, T_TEXT_ERR_567_GAUCHE_DEFAUT, T_TEXT_ERR_568_GAUCHE_DEFAUT, T_TEXT_ERR_569_GAUCHE_DEFAUT, T_TEXT_ERR_570_GAUCHE_DEFAUT,// 570
		T_TEXT_ERR_571_GAUCHE_DEFAUT, T_TEXT_ERR_572_GAUCHE_DEFAUT, T_TEXT_ERR_573_GAUCHE_DEFAUT, T_TEXT_ERR_574_GAUCHE_DEFAUT, T_TEXT_ERR_575_GAUCHE_DEFAUT,
		T_TEXT_ERR_576_GAUCHE_DEFAUT, T_TEXT_ERR_577_GAUCHE_DEFAUT, 0, 0, 0, // 580
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 590
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,							    // 600
		0, 0, 0, T_TEXT_ERR_604_GAUCHE_DEFAUT, T_TEXT_ERR_605_GAUCHE_DEFAUT, 0, 0, 0, 0, T_TEXT_ERR_610_GAUCHE_DEFAUT,// 610
		T_TEXT_ERR_611_GAUCHE_DEFAUT, T_TEXT_ERR_612_GAUCHE_DEFAUT, 0, 0, T_TEXT_ERR_615_GAUCHE_DEFAUT, T_TEXT_ERR_616_GAUCHE_DEFAUT, T_TEXT_ERR_617_GAUCHE_DEFAUT,
		T_TEXT_ERR_618_GAUCHE_DEFAUT, T_TEXT_ERR_619_GAUCHE_DEFAUT, T_TEXT_ERR_620_GAUCHE_DEFAUT,// 620
		T_TEXT_ERR_621_GAUCHE_DEFAUT, T_TEXT_ERR_622_GAUCHE_DEFAUT, T_TEXT_ERR_623_GAUCHE_DEFAUT, T_TEXT_ERR_624_GAUCHE_DEFAUT, T_TEXT_ERR_625_GAUCHE_DEFAUT,
		T_TEXT_ERR_626_GAUCHE_DEFAUT, T_TEXT_ERR_627_GAUCHE_DEFAUT, T_TEXT_ERR_628_GAUCHE_DEFAUT, T_TEXT_ERR_629_GAUCHE_DEFAUT, 0,							 // 630
		T_TEXT_ERR_631_GAUCHE_DEFAUT, T_TEXT_ERR_632_GAUCHE_DEFAUT, T_TEXT_ERR_633_GAUCHE_DEFAUT, T_TEXT_ERR_634_GAUCHE_DEFAUT, T_TEXT_ERR_635_GAUCHE_DEFAUT,
		0, T_TEXT_ERR_637_GAUCHE_DEFAUT, T_TEXT_ERR_638_GAUCHE_DEFAUT, T_TEXT_ERR_639_GAUCHE_DEFAUT, T_TEXT_ERR_640_GAUCHE_DEFAUT,// 640
		T_TEXT_ERR_641_GAUCHE_DEFAUT, T_TEXT_ERR_642_GAUCHE_DEFAUT, T_TEXT_ERR_643_GAUCHE_DEFAUT, T_TEXT_ERR_644_GAUCHE_DEFAUT, T_TEXT_ERR_645_GAUCHE_DEFAUT,
		T_TEXT_ERR_646_GAUCHE_DEFAUT, T_TEXT_ERR_647_GAUCHE_DEFAUT, T_TEXT_ERR_648_GAUCHE_DEFAUT, T_TEXT_ERR_649_GAUCHE_DEFAUT, T_TEXT_ERR_650_GAUCHE_DEFAUT,// 650
		T_TEXT_ERR_651_GAUCHE_DEFAUT, T_TEXT_ERR_652_GAUCHE_DEFAUT, T_TEXT_ERR_653_GAUCHE_DEFAUT, T_TEXT_ERR_654_GAUCHE_DEFAUT, T_TEXT_ERR_655_GAUCHE_DEFAUT,
		T_TEXT_ERR_656_GAUCHE_DEFAUT, T_TEXT_ERR_657_GAUCHE_DEFAUT, T_TEXT_ERR_658_GAUCHE_DEFAUT, 0, 0,						    // 660
		T_TEXT_ERR_661_GAUCHE_DEFAUT, T_TEXT_ERR_662_GAUCHE_DEFAUT, T_TEXT_ERR_663_GAUCHE_DEFAUT, T_TEXT_ERR_664_GAUCHE_DEFAUT, T_TEXT_ERR_665_GAUCHE_DEFAUT,
		T_TEXT_ERR_666_GAUCHE_DEFAUT, T_TEXT_ERR_667_GAUCHE_DEFAUT, T_TEXT_ERR_668_GAUCHE_DEFAUT, T_TEXT_ERR_669_GAUCHE_DEFAUT, T_TEXT_ERR_670_GAUCHE_DEFAUT,// 670
		T_TEXT_ERR_671_GAUCHE_DEFAUT, T_TEXT_ERR_672_GAUCHE_DEFAUT, T_TEXT_ERR_673_GAUCHE_DEFAUT, T_TEXT_ERR_674_GAUCHE_DEFAUT, T_TEXT_ERR_675_GAUCHE_DEFAUT,
		T_TEXT_ERR_676_GAUCHE_DEFAUT, T_TEXT_ERR_677_GAUCHE_DEFAUT, T_TEXT_ERR_678_GAUCHE_DEFAUT, T_TEXT_ERR_679_GAUCHE_DEFAUT, T_TEXT_ERR_680_GAUCHE_DEFAUT,// 680
		T_TEXT_ERR_681_GAUCHE_DEFAUT, T_TEXT_ERR_682_GAUCHE_DEFAUT, T_TEXT_ERR_683_GAUCHE_DEFAUT, T_TEXT_ERR_684_GAUCHE_DEFAUT, T_TEXT_ERR_685_GAUCHE_DEFAUT,
		T_TEXT_ERR_686_GAUCHE_DEFAUT, T_TEXT_ERR_687_GAUCHE_DEFAUT, T_TEXT_ERR_688_GAUCHE_DEFAUT, 0, 0,							// 690
		T_TEXT_ERR_691_GAUCHE_DEFAUT, T_TEXT_ERR_692_GAUCHE_DEFAUT, T_TEXT_ERR_693_GAUCHE_DEFAUT, T_TEXT_ERR_694_GAUCHE_DEFAUT, T_TEXT_ERR_695_GAUCHE_DEFAUT,
		T_TEXT_ERR_696_GAUCHE_DEFAUT, T_TEXT_ERR_697_GAUCHE_DEFAUT, T_TEXT_ERR_698_GAUCHE_DEFAUT, 0, T_TEXT_ERR_700_INV_GAUCHE_DEFAUT,	// 700
		T_TEXT_ERR_701_INV_GAUCHE_DEFAUT,0,0,0,T_TEXT_ERR_705_INV_GAUCHE_DEFAUT,T_TEXT_ERR_706_INV_GAUCHE_DEFAUT,T_TEXT_ERR_707_INV_GAUCHE_DEFAUT,T_TEXT_ERR_708_INV_GAUCHE_DEFAUT, 0, 0, //710
		0, 0, 0, 0, T_TEXT_ERR_715_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, T_TEXT_ERR_720_INV_GAUCHE_DEFAUT, // 720
		T_TEXT_ERR_721_INV_GAUCHE_DEFAUT, T_TEXT_ERR_722_INV_GAUCHE_DEFAUT,T_TEXT_ERR_723_INV_GAUCHE_DEFAUT, T_TEXT_ERR_724_INV_GAUCHE_DEFAUT, T_TEXT_ERR_725_INV_GAUCHE_DEFAUT,
		0, 0, 0, 0, 0,  //730
		0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_740_INV_GAUCHE_DEFAUT, //740
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 750

};



////Défaut INVERTERRA 200 à 440
//uint32_t u32ErreursINV1[240] = {
//	T_TEXT_ERR_200_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_201_INV_GAUCHE_DEFAUT,T_TEXT_ERR_202_INV_GAUCHE_DEFAUT,T_TEXT_ERR_203_INV_GAUCHE_DEFAUT,0,0,0,0,0,0,T_TEXT_ERR_210_INV_GAUCHE_DEFAUT,  //210
//	T_TEXT_ERR_211_INV_GAUCHE_DEFAUT,T_TEXT_ERR_212_INV_GAUCHE_DEFAUT,T_TEXT_ERR_213_INV_GAUCHE_DEFAUT,T_TEXT_ERR_214_INV_GAUCHE_DEFAUT,T_TEXT_ERR_215_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_216_INV_GAUCHE_DEFAUT,T_TEXT_ERR_217_INV_GAUCHE_DEFAUT,0,0,0,  //220
//	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_230_INV_GAUCHE_DEFAUT, // 230
//	T_TEXT_ERR_231_INV_GAUCHE_DEFAUT, T_TEXT_ERR_232_INV_GAUCHE_DEFAUT,T_TEXT_ERR_233_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_240_INV_GAUCHE_DEFAUT,	// 240
//	T_TEXT_ERR_241_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_250_INV_GAUCHE_DEFAUT,  //250
//	T_TEXT_ERR_251_INV_GAUCHE_DEFAUT, T_TEXT_ERR_252_INV_GAUCHE_DEFAUT,T_TEXT_ERR_253_INV_GAUCHE_DEFAUT, T_TEXT_ERR_254_INV_GAUCHE_DEFAUT, T_TEXT_ERR_255_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_256_INV_GAUCHE_DEFAUT, T_TEXT_ERR_257_INV_GAUCHE_DEFAUT, T_TEXT_ERR_258_INV_GAUCHE_DEFAUT, T_TEXT_ERR_259_INV_GAUCHE_DEFAUT, T_TEXT_ERR_260_INV_GAUCHE_DEFAUT,	// 260
//	T_TEXT_ERR_261_INV_GAUCHE_DEFAUT, T_TEXT_ERR_262_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, 0, 0,//270
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 280
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 290
//	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_300_INV_GAUCHE_DEFAUT, //300
//	T_TEXT_ERR_301_INV_GAUCHE_DEFAUT,T_TEXT_ERR_302_INV_GAUCHE_DEFAUT,T_TEXT_ERR_303_INV_GAUCHE_DEFAUT,T_TEXT_ERR_304_INV_GAUCHE_DEFAUT,T_TEXT_ERR_305_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_306_INV_GAUCHE_DEFAUT,T_TEXT_ERR_307_INV_GAUCHE_DEFAUT,T_TEXT_ERR_308_INV_GAUCHE_DEFAUT,T_TEXT_ERR_309_INV_GAUCHE_DEFAUT,T_TEXT_ERR_310_INV_GAUCHE_DEFAUT,  //310
//	T_TEXT_ERR_311_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0, 0, 0, 0,	// 320
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 33
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 340
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 350
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 360
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 370
//	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_380_INV_GAUCHE_DEFAUT, // 380
//	T_TEXT_ERR_381_INV_GAUCHE_DEFAUT,T_TEXT_ERR_382_INV_GAUCHE_DEFAUT,T_TEXT_ERR_383_INV_GAUCHE_DEFAUT,T_TEXT_ERR_384_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, 0, 0,  //390
//	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_400_INV_GAUCHE_DEFAUT, // 400
//	T_TEXT_ERR_401_INV_GAUCHE_DEFAUT,T_TEXT_ERR_402_INV_GAUCHE_DEFAUT,T_TEXT_ERR_403_INV_GAUCHE_DEFAUT,T_TEXT_ERR_404_INV_GAUCHE_DEFAUT,T_TEXT_ERR_405_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_406_INV_GAUCHE_DEFAUT,T_TEXT_ERR_407_INV_GAUCHE_DEFAUT,T_TEXT_ERR_408_INV_GAUCHE_DEFAUT,T_TEXT_ERR_409_INV_GAUCHE_DEFAUT,T_TEXT_ERR_410_INV_GAUCHE_DEFAUT,  //410
//	T_TEXT_ERR_411_INV_GAUCHE_DEFAUT,T_TEXT_ERR_412_INV_GAUCHE_DEFAUT,T_TEXT_ERR_413_INV_GAUCHE_DEFAUT,T_TEXT_ERR_414_INV_GAUCHE_DEFAUT,T_TEXT_ERR_415_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_416_INV_GAUCHE_DEFAUT,T_TEXT_ERR_417_INV_GAUCHE_DEFAUT,T_TEXT_ERR_418_INV_GAUCHE_DEFAUT,T_TEXT_ERR_419_INV_GAUCHE_DEFAUT,T_TEXT_ERR_420_INV_GAUCHE_DEFAUT,  //420
//	T_TEXT_ERR_421_INV_GAUCHE_DEFAUT,T_TEXT_ERR_422_INV_GAUCHE_DEFAUT,T_TEXT_ERR_423_INV_GAUCHE_DEFAUT,T_TEXT_ERR_424_INV_GAUCHE_DEFAUT,T_TEXT_ERR_425_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_426_INV_GAUCHE_DEFAUT,T_TEXT_ERR_427_INV_GAUCHE_DEFAUT,T_TEXT_ERR_428_INV_GAUCHE_DEFAUT,T_TEXT_ERR_429_INV_GAUCHE_DEFAUT,T_TEXT_ERR_430_INV_GAUCHE_DEFAUT,  //430
//	T_TEXT_ERR_431_INV_GAUCHE_DEFAUT,T_TEXT_ERR_432_INV_GAUCHE_DEFAUT,T_TEXT_ERR_433_INV_GAUCHE_DEFAUT,T_TEXT_ERR_434_INV_GAUCHE_DEFAUT,T_TEXT_ERR_435_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_436_INV_GAUCHE_DEFAUT,T_TEXT_ERR_437_INV_GAUCHE_DEFAUT,T_TEXT_ERR_438_INV_GAUCHE_DEFAUT, 0  //439
//};
//
////Défaut INVERTERRA 700 à 800
//uint32_t u32ErreursINV2[100] = {
//	T_TEXT_ERR_700_INV_GAUCHE_DEFAUT,
//	T_TEXT_ERR_701_INV_GAUCHE_DEFAUT,0,0,0,T_TEXT_ERR_705_INV_GAUCHE_DEFAUT,T_TEXT_ERR_706_INV_GAUCHE_DEFAUT,T_TEXT_ERR_707_INV_GAUCHE_DEFAUT,T_TEXT_ERR_708_INV_GAUCHE_DEFAUT, 0, 0, //710
//	0, 0, 0, 0, T_TEXT_ERR_715_INV_GAUCHE_DEFAUT, 0, 0, 0, 0, T_TEXT_ERR_720_INV_GAUCHE_DEFAUT, // 720
//	T_TEXT_ERR_721_INV_GAUCHE_DEFAUT, T_TEXT_ERR_722_INV_GAUCHE_DEFAUT,T_TEXT_ERR_723_INV_GAUCHE_DEFAUT, T_TEXT_ERR_724_INV_GAUCHE_DEFAUT, T_TEXT_ERR_725_INV_GAUCHE_DEFAUT,
//	0, 0, 0, 0, 0,  //730
//	0, 0, 0, 0, 0, 0, 0, 0, 0, T_TEXT_ERR_740_INV_GAUCHE_DEFAUT, //740
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 750
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 770
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 780
//	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,								// 790
//	0, 0, 0, 0, 0, 0, 0, 0, 0								    // 799
//
//
//};
