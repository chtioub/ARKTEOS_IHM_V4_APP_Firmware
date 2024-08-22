/*
 * IHM_V4.h
 *
 *  Created on: Jul 29, 2024
 *      Author: info
 */

#ifndef INC_IHM_V4_H_
#define INC_IHM_V4_H_

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef SIMULATOR
#include "main.h"
#endif /* SIMULATOR */

#include "arkteos_var_protocole.h"
#include "arkteos_var_commune.h"
#include "arkteos_defauts.h"

typedef enum
{
	OUI_NON_ANTIL = 1,
	OUI_NON_RAZ_CONF = 2,
	OUI_NON_RAZ_INST = 3,
	OUI_NON_RAZ_MAIN = 4,
	OUI_NON_RAZ_PARAM = 5,
	OUI_NON_SHUNT_TEMPO = 6,
	OUI_NON_MODE_SECOURS = 7,
	OUI_NON_MODE_SILENCE = 8,
	OUI_NON_MODE_DATE = 9,
	OUI_NON_CUMUL = 10,
	OUI_NON_RAZ_CONF_INSTALL = 11,
	OUI_NON_RESTART = 12,
	OUI_NON_RAZ_SOFT_FLASH = 13,
	OUI_NON_RAZ_LOG_ETHER = 14,
	OUI_NON_RESTART_IHM = 15,
	OUI_NON_MODE_SECOURS_ECS = 16,
	OUI_NON_MODE_SECOURS_PRESSION = 17,
	OUI_NON_MARCHE_GENERAL= 18,
	OUI_NON_ARRET_GENERAL= 19,
} E_OUI_NON;

typedef struct
{
  // octet 1
  unsigned char bModePAC :1; //Marche / arret general
  unsigned char u7Spare :7;
  // octet 2
  unsigned char u8Spare;
  // octet 3 et 4
  short i16TempECS;
} cosebe_test_t;

typedef struct
{
	bool date_update;
	bool erreur_update;
	bool demande_frigo_update;
	bool statut_pac_update;
	bool statut_primaire_update;
	bool statut_zx_update[20];
	bool statut_ecs_update;
	bool statut_piscine_update;
	bool statut_regul_ext_update;
	bool statut_tps_fonct_update;
	bool statut_regul_esclave_update;
	bool statut_debug_update;
	bool statut_ether_update;
	bool config_update;
	bool cycl_frigo_update;
} arkteos_update_t;

typedef struct
{
  uint16_t size;
  uint8_t data[TAILLE_BUFFER_UART];
} rxData_t;

typedef struct
{
  uint8_t dest;
  uint8_t emet;
  uint8_t comm;
  uint8_t s_comm :6;
  uint8_t control :2;
  uint16_t taille;
} header_t;

extern cosebe_test_t cosebe_test;
extern arkteos_update_t arkteos_update;
extern rxData_t rxData;
extern uint8_t rxBuffer[TAILLE_BUFFER_UART];
extern uint8_t dataUpdated;
extern uint8_t eOuiNon;
extern S_DATE sDate;
extern S_STATUT_PAC sStatut_PAC;
extern S_STATUT_PRIMAIRE sStatut_Primaire;
extern S_STATUT_ZX sStatut_Zx[20];
extern S_STATUT_ECS sStatut_ECS;
extern S_STATUT_PISCINE sStatut_Piscine;
extern S_STATUT_REG_EXT sStatut_RegulExt;
extern S_STATUT_TPS_FONCT sStatut_TpsFonct;
extern S_STATUT_REGUL_ESCLAVE sStatut_RegulEsclave;
extern S_STATUT_DEBUG sStatut_DebugTrame1[8];
extern S_STATUT_DEBUG sStatut_DebugTrame2[8];
extern S_CYC_ETHER_III sCycEther;
extern uint16_t u16ErreurEncours;
extern uint16_t u16ListeErreurEncours[25];
extern S_CONFIG_IHM sConfig_IHM;
extern S_CYCL_REG_FRI sCyclRegFrigo[NB_UE_MAX];
extern S_DEMANDE_FRIGO sDemandeFrigo;

uint8_t decodeRxData(rxData_t *rxData);
bool verifErreurs(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_IHM_V4_H_ */
