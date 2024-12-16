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
#include <texts/TextKeysAndLanguages.hpp>

#define VEILLE_1_TIME           60              // Temps avant mise en veille 1 en secondes
#define VEILLE_2_TIME           300             // Temps avant mise en veille 1 en secondes
#define PWM_VEILLE_1            5u




#define VEILLE_1_COUNT          (VEILLE_1_TIME*60)
#define VEILLE_2_COUNT          (VEILLE_2_TIME*60)

typedef enum
{
	OUI_NON_RAZ_CONF_USINE = 2,
	OUI_NON_RAZ_CODE_INST = 3,
	OUI_NON_RAZ_CODE_MAIN = 4,
	OUI_NON_RAZ_HISTO_ERREUR = 5,
	OUI_NON_SHUNT_TEMPO = 6,
	OUI_NON_MODE_SECOURS = 7,
	OUI_NON_MODE_DATE = 9,
	OUI_NON_CUMUL = 10,
	OUI_NON_RAZ_CONF_INSTALL = 11,
	OUI_NON_RESTART = 12,
	OUI_NON_RAZ_SOFT_FLASH = 13,
	OUI_NON_RAZ_LOG_ETHER = 14,
	OUI_NON_RESTART_IHM = 15,
	OUI_NON_MODE_SECOURS_ECS = 16,
	OUI_NON_MODE_SECOURS_PRESSION = 17,
	OUI_NON_MARCHE_GENERAL = 18,
	OUI_NON_ARRET_GENERAL = 19,
	OUI_NON_CHAUFFE_DALLE = 20,
	OUI_NON_FREECOOLING = 21,
	OUI_NON_SIMULTANE_PISCINE = 22,
	OUI_NON_RESTART_USINE = 23,
	OUI_NON_DEROG_PRESSION_BP = 24,
	OUI_NON_RAZ_TPS_FONCT = 25,
	OUI_NON_RAZ_ENERGIES = 26,
	OUI_NON_RESIST_TERM = 27,
	OUI_NON_RESIST_TERM_SONDE = 28,
} E_OUI_NON;

typedef enum
{
	CODE_ACCES_INSTALL = 1,
	CODE_ACCES_USINE = 2,
	CODE_ACCES_MAINT = 3,
	MODIF_CODE_INSTALL = 4,
	MODIF_CODE_MAINT = 5,
	NUM_SERIE = 6,
} E_CODE;

typedef enum
{
	HYST_TINT = 1,
	HYST_TEAU = 2,
	HYST_ECS = 3,
	HYST_EXT = 4,
	HYST_PISC = 5,
	HYST_PRIM = 6,
} E_HYST;

typedef enum
{
	PRO_CHAUD = 1,
	PRO_FROID = 2,
	PRO_EXT_CHAUD = 3,
	PRO_EXT_FROID = 4,
	PRO_PISCINE = 5,
	PRO_ECS = 6,
	PRO_PISCINE_CONFORT = 7,
	PRO_OPTION = 8,
	PRO_SILENCE = 9,
} E_PROG;

typedef struct
{
	uint8_t u8TypeRegul;
	uint8_t u8NumZone;
	S_ZONE sZones;
	S_PARAM_ZX sParamZx;
} S_CONFIG_HYDRAU_TEMP;

typedef struct
{
	bool bPiscine;
	S_PARAM_PISCINE sParam_Piscine;
} S_CONFIG_PISCINE_TEMP;

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
	bool statut_rf_update;
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

typedef struct
{
  uint16_t size;
  uint8_t data[TAILLE_BUFFER_UART - sizeof(header_t)];
}txData_t;

typedef struct
{
  // octet 1
  unsigned char bModePAC :1;//Marche / arret general
  unsigned char u7Spare :7;
  // octet 2
  unsigned char u8Spare;
  // octet 3 et 4
  short i16TempECS;
}cosebe_rx_t;

typedef struct
{
  uint16_t u16Data;
}cosebe_tx_t;

extern cosebe_test_t cosebe_test;
extern arkteos_update_t arkteos_update;
extern rxData_t rxData;
extern uint8_t rxBuffer[TAILLE_BUFFER_UART];
extern uint8_t dataUpdated;
extern uint8_t eOuiNon, eCode;
extern uint8_t eHysteresis;
extern uint8_t eProg;
extern S_DATE sDate, sDate_modif;
extern S_STATUT_PAC sStatut_PAC;
extern S_STATUT_PRIMAIRE sStatut_Primaire;
extern S_STATUT_ZX sStatut_Zx[20];
extern S_STATUT_ECS sStatut_ECS;
extern S_STATUT_PISCINE sStatut_Piscine;
extern S_STATUT_REG_EXT sStatut_RegulExt;
extern S_STATUT_TPS_FONCT sStatut_TpsFonct;
extern S_STATUT_REGUL_ESCLAVE sStatut_RegulEsclave;
extern S_STATUT_DEBUG sStatut_DebugTrame1[8];
extern S_STATUT_RF sStatut_RF[8];
extern S_STATUT_DEBUG sStatut_DebugTrame2[8];
extern S_CYC_ETHER_III sCycEther;
extern S_ENERGIE sEnergie;
extern uint16_t u16ErreurEncours;
extern uint16_t u16ListeErreurEncours[25];
extern S_CONFIG_IHM sConfig_IHM;
extern S_CYCL_REG_FRI sCyclRegFrigo[NB_UE_MAX];
extern S_DEMANDE_FRIGO sDemandeFrigo;
extern cosebe_rx_t cosebe_rx;
extern txData_t txData[10];
extern uint8_t sendData;
extern uint8_t au8Prog_Chaud_Zx[NB_ZONE][7][24];
extern uint8_t au8Prog_Froid_Zx[NB_ZONE][7][24];
extern uint8_t au8Prog_Regul_Ext_Chaud[7][24];
extern uint8_t au8Prog_Regul_Ext_Froid[7][24];
extern uint8_t au8Prog_ECS[7][24];
extern uint8_t au8Prog_Piscine[7][24];
extern uint8_t au8Prog_Options[7][24];
extern uint8_t au8Prog_ModeSilence[7][24];
extern uint8_t u8Prog[7][24], u8JourProg;
extern uint8_t u8ZoneSelect;
extern uint8_t u8PositionX, u8PositionY;
extern bool bConsoProd, bPageUsine, bMaintenanceDepuisUsine, bInstallationDepuisUsine, bRegroupementZoneTemp;
extern S_HISTO_ERR sHisto_Erreur;
extern uint16_t u16NumAction;
extern uint32_t u32ValAction, eAnciennePage, u32Erreurs[1000];
extern S_CONFIG_HYDRAU_TEMP sConfig_Hydrau_temp;
extern S_CONFIG_PISCINE_TEMP sConfig_Piscine_temp;
extern S_PARAM_ECS sParam_ECS_temp;
extern uint32_t u32LastCyclique;
extern uint8_t u8Pointeur_buffer_tx, u8Pointeur_envoi;
extern S_PARAM_ZX sParamZxMZtemp[10];

void setBackLightPWM(uint8_t pwm);
uint8_t decodeRxData(rxData_t *rxData);
uint8_t computeTxData(txData_t *txData, txData_t *cosebe_tx);
bool verifErreurs(void);
int ConvertPressionToTemperature(E_TYPE_GAZ typegaz, int PressionHP, int valpression);




#ifdef __cplusplus
}
#endif

#endif /* INC_IHM_V4_H_ */
