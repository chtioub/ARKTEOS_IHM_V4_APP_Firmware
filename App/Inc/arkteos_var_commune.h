/*****************************************************************************/
//  File : ArkCOMMUN - ARKTEOS
/*****************************************************************************/
//
// Date 01/10/2018
// Copyright 2015 ARKTEOS
// All Rights Reserved
//
// This program contains proprietary information which is a trade
// secret of ARKTEOS and/or its affiliates and also is protected as
// an unpublished work under applicable Copyright laws. Recipient is
// to retain this program in confidence and is not permitted to use or
// make copies thereof other than as permitted in a written agreement
// with ARKTEOS, unless otherwise expressly allowed by applicable laws
//    
/*****************************************************************************/

#ifndef _ARKTEOS_VAR_COMMUNE
#define _ARKTEOS_VAR_COMMUNE

#include "arkteos_custom.h"
#include <stdint.h>

/*****************************************************************************/
//  DEFINES
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="DEFINES COMMUNS">
// Pas de Changement de ces variables simplement (nombre de zone ou esclave ou compresseur)
// car cela modifie la taille de trame, le systeme de sauvegarde de config / recup config etc ...
#define NB_ZONE             8                       // Nombre de Zone g�r�es par Thermostat
#define NB_GROUPE_EAU       2                       // 2 Zones pour la gestion des groupes d'eau
#define NB_VOIE             (NB_ZONE+NB_GROUPE_EAU) // Nombre de voies
#define NB_ESCLAVE          7                       // Nombre d'esclave max (+1 pour la ma�tre)
#define NB_COMPRESSEUR_MAX  2                       // Nombre maximum de compresseurs
#define NB_PAC              (LAST_MODEL - AJPAC_III)// Nombre de mod�le de PACs
#define NB_UE_MAX			8
// Nombre de cartes options maximum
#define NB_CARTES_ECS       1
#define NB_CARTES_MZ        3
// Nombre Maximum de cartes (par rapport aux adresses disponibles)
#define MAX_CARD_DHW        (N_ADD_OPTION_ECS_END - N_ADD_OPTION_ECS_START)
#define MAX_CARD_MZ         (N_ADD_OPTION_MZ_END - N_ADD_OPTION_MZ_START)
// </editor-fold>

/*****************************************************************************/
//  DEFINITION DES LONGUEURS DE TRAMES
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="DEFINE des LONGUEURS DE TRAME POUR CONTROLE   ">
// Pour controle de longueur de trame cela permet d'eviter des changements involontaires
#define LG_TRAME_CYCLIQUE_REGUL_T1  212
#define LG_TRAME_CYCLIQUE_REGUL_T2  196
#define LG_TRAME_CYCLIQUE_FRIGO     0x94
#define LG_TRAME_CYCLIQUE_FAN       0x1C
#define LG_STRUCTURE_DATA_EEPROM    0x136C
#define LG_S_ENERGIE                0x72c
#define LG_S_HISTO_ERR              0x1f8 
#define LG_S_ENREG_REGUL            0x1684
// </editor-fold>

/*****************************************************************************/
//  DEFINITION DES COULEURS
/*****************************************************************************/
#define BLANC			0xFFFFFF
#define ROUGE_CHAUD		0xD81F2A
#define BLEU_FROID		0x00628C
#define ORANGE_HORS_GEL 0xE27E00

/*****************************************************************************/
//  DEFINITION DES ENUMS
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="TYPE DEF ENUM COMMUN  ">
// Liste des PAC Arkteos Regulation V3
// Attention !!! il y a les tables des Thermomax et ThermomaxECS et Table des Pincement ECS a renseigner pour chaque nouvelle PAC 
// l'Introduction d'une PAC n�cessite la modification de Soft Serveur et des application IHM / Appli Distance / outils de conversion CSV ... 
typedef enum 
{
    AJPAC_III 			= 0x10,
    BAGUIO_ZURAN_IV		= 0x11,
    TIMAX_III			= 0x12,
    GEOTWIN_IV			= 0x13,
    CAIROX				= 0x14,
    PHOENIX             = 0x15,
    ARKTEA              = 0x16,
    GEOINVERTER         = 0x17,
    LAST_MODEL			= 0x18,
} E_MODEL_PAC;

#define INVERTERRA GEOINVERTER

typedef enum 
{
    SOUS_TYPE_UNDEFINED,
    SOUS_TYPE_BAGUIO,
    SOUS_TYPE_ZURAN,
    SOUS_TYPE_BAGUIO_PP,
    SOUS_TYPE_BAGUIO_PUZ,
    SOUS_TYPE_ZURAN_PUZ,
    LAST_SOUS_TYPE
} E_SOUS_TYPE_PAC;

// Parametre de configuration des differents modes
typedef enum { ARRET=0, MARCHE_CHAUD, AUTO_CHAUD, MARCHE_FROID, AUTO_FROID, HORS_GEL } E_FONCT_ZX;
typedef enum { NO_EXCEPTION=0, VACANCES, SABLIER, DALLE } E_FONCT_EXCEPTION;
typedef enum { ECS_OFF=0, ECS_ON, ECS_OFF_LEGIO, ECS_ON_LEGIO } E_MODE_AUTO_ECS;
typedef enum { CH_NU=0, CH_REDUIT, CH_CONFORT, CH_CONFORT_PLUS } E_MODE_AUTO_CHAUD;
typedef enum { FR_OFF=0, FR_REDUIT, FR_CONFORT } E_MODE_AUTO_FROID;
typedef enum { PIS_OFF=0, PIS_ON, PIS_CONFORT, PIS_CONFORT_PLUS } E_MODE_AUTO_PISCINE;
typedef enum { RF_OFF=0 , RF_HORS_GEL, RF_CH_VACANCES, RF_CH_SABLIER, RF_CH_NORMAL, RF_CH_AUTO_REDUIT, RF_CH_AUTO_CONFORT, RF_CH_CONFORT_PLUS, RF_FR_SABLIER, RF_FR_NORMAL, RF_FR_AUTO_REDUIT, RF_FR_AUTO_CONFORT  } E_MODE_RF;
typedef enum {MB_HEATMISER_CHANGE_OVER=0, MB_HEATMISER_SCHEDULE, MB_HEATMISER_HOLD, MB_HEATMISER_ADVANCED, MB_HEATMISER_AWAY, MB_HEATMISER_FROST_MODE} E_MODE_MODBUS_HEATMISER;
typedef enum { ZONE1=0, ZONE2, ZONE3, ZONE4, ZONE5, ZONE6, ZONE7, ZONE8, ZONE_GROUPE_A, ZONE_GROUPE_B} E_ZONE;
typedef enum { AUTONOME, GROUPE_A, GROUPE_B } E_RATTACHEMENT;

typedef enum { PROG_REDUC_PW_R0=0, PROG_REDUC_PW_R3, PROG_REDUC_PW_R5, PROG_REDUC_PW_R7 }             E_MODE_PROG_REDUC_PW;
typedef enum { PROG_SILENCIEUX_NO=0, PROG_SILENCIEUX_YES, PROG_SILENCIEUX_YES1, PROG_SILENCIEUX_YES2 }E_MODE_PROG_SILENCIEUX;

typedef enum { MODE_INX_NONE = 0, MODE_IN1=1, MODE_IN2=2,         MODE_IN14=14, MODE_INX_AUTO=15 }  E_MODE_CONTACT_INX;

// Les Type de Thermostat
typedef enum {TH_RF, TH_MODBUS, TH_CONTACT, TH_CASSETTE}                E_TYPE_THERMOSTAT;
typedef enum {AIRCALO, NB_TYPE_FAN}                                     E_TYPE_FAN;

typedef enum { NO_COMPTAGE_PW=0, PULSE_800, PULSE_1000}     E_CoeffComptagePW;
typedef enum { NO_APPOINT=0, ELEC, RELEVE_CHAUDIERE, APPOINT_CHAUDIERE} E_APPOINT_CHAUFFAGE;
typedef enum { ELEC_ECS=0, ELEC_PAC}                                    E_TYPE_APPOINT_ECS;
typedef enum { NO_COMPTAGE_EAU=0, PULSE_1L, PULSE_250ML }               E_CoeffComptageEau;

// Les PW Elec sur les brins
typedef enum {P0=0,P33,P66,P100} E_PW_RELEC ; /*( P0, P33, P66, P100)*/

// Les Types de test PAC
typedef enum {T_CHAUD, T_FROID, T_PISCINE, T_ECS} E_MODE_TEST_PAC;

// Parameters de configuration de la PAC
typedef enum {PRIORITE_PISCINE=0, PRIORITE_CHAUD, PRIORITE_EGAL} E_PRIORITE_PISC ;
typedef enum { GC_AUTO, GC_V40, GC_V50, GC_V60, GC_V70, GC_V80, GC_V90, GC_V100, 
               GC_Delta_T_5, GC_Delta_T_7, GC_Delta_T_10, GC_Delta_T_15 }   E_GESTION_CIRCULATEUR ;
typedef enum {HUBA_DN_10, HUBA_DN_15, HUBA_DN_20, HUBA_DN_25, HUBA_DN_32, SIKA_DN_32, SIKA_DN_40, SIKA_VTR1050} E_TYPE_DEBITMETRE;
typedef enum { TYPE_GRUNDFOS=0, TYPE_WILO, TYPE_RELAIS}                     E_TYPE_CIRCULATEUR ;
typedef enum { ECS_PLAQUE=0, ECS_BAIN_MARIE, ECS_SERPENTIN}                 E_TYPE_ECHANGEUR_ECS ;
typedef enum { ECHANGEUR_8KW=0, ECHANGEUR_12KW, ECHANGEUR_16KW, ECHANGEUR_20KW } E_PW_ECHANGEUR_ECS ;
typedef enum { MIN_VANNE_ECS_70_NO_LIMITE=0, MIN_VANNE_ECS_30_LIMITATION, MIN_VANNE_ECS_40_LIMITATION, MIN_VANNE_ECS_50_LIMITATION, MIN_VANNE_ECS_60_LIMITATION, MIN_VANNE_ECS_70_LIMITATION, MIN_VANNE_ECS_80_LIMITATION,  MIN_VANNE_ECS_90_LIMITATION} E_MIN_VANNE_ECS ;
typedef enum { MIN_VANNE_PISCINE_50_NO_LIMITE=0, MIN_VANNE_PISCINE_50_LIMITATION, MIN_VANNE_PISCINE_60_LIMITATION, MIN_VANNE_PISCINE_70_LIMITATION} E_MIN_VANNE_PISCINE ;
typedef enum { NB_COMPRESSEUR_1 = 0, NB_COMPRESSEUR_2 , NB_COMPRESSEUR_3 , NB_COMPRESSEUR_4 } E_NB_COMPRESSEUR ;
typedef enum { COMPRESSEUR_1 = 0, COMPRESSEUR_2, COMPRESSEUR_3, COMPRESSEUR_4 } E_COMPRESSEUR ;

typedef enum {E_TYPE_GESTION_V3V_MODE_2, E_TYPE_GESTION_V3V_MODE_1 }        E_TYPE_GESTION_V3V; // 2 Valeurs Max  Mode B pour AJPAC par def

// Liste des test composants pour le test 
typedef enum {TEST_NONE, TEST_CIRCULATEUR, TEST_APPOINT, TEST_VANNE_MELANGE, TEST_RELAIS_AJREG, TEST_AUTRES,
              TEST_VENTIL, TEST_DETENDEUR_FAN, TEST_RELAIS_FAN, TEST_RESERVE_1, TEST_RESERVE_2, 
              TEST_DETENDEUR_FRIGO, TEST_RELAIS_FRIGO, TEST_AJ_FRIGO, TEST_RESERVE_3, TEST_RESERVE_4 } E_TEST_COMPOSANT;

// Configuration de l'installation hydraulique
typedef enum { REGUL_DIRECTE = 0, REGUL_BCP_INTERNE, REGUL_BAL_TAMPON_2_ZONES, REGUL_BAL_TAMPON_MULTI_ZONE, REGUL_EXTERNE, REGUL_ESCLAVE } E_REGUL;
typedef enum {PLANCHER = 0, VENTILO, RADIATEUR, GAINABLE, SOUS_STATION} E_TYPE_ZONE;
typedef enum { CMD_0_10V = 0, CMD_PWM }                   E_COMMANDE_EMETTEUR;
typedef enum { MAITRE = 0,  ESCLAVE }                     E_MAITRE_ESCLAVE;

// Types utilises pour l'envoi des demandes a la carte Frigo
typedef enum { F_ARRET = 0, F_CHAUD, F_FROID, F_PISCINE, F_ECS, F_ARRET_URGENT, F_PUMP_DOWN, F_TEST_CPS, F_CIRCUL, F_CHAUD_FROID, F_ECS_FROID, F_PISCINE_FROID} E_DEMANDE_FRIGO;
typedef enum { REGUL_OFF=0, REGUL_ON }                  E_DEMANDE_REGUL;    // REG_III va permettre de g�rer le simultan�e on separe les demandes Chaud/Froid/ECS/Piscine
typedef enum { MODE_REGUL_NORMAL, MODE_REGUL_TEST }     E_TYPE_MODE;        // REG_III va permettre de choisir la demande Frigo
typedef enum { DEGIVRAGE_NORMAL = 0, DEGIVRAGE_LONG }   E_TYPE_DEGIVRAGE;
typedef enum { LIAISON_NORMAL   = 0, LIAISON_LONGUE }   E_TYPE_LIAISON;
typedef enum { R0 = 0, R1, R2, R3, R4, R5, R6, R7 }     E_REDUC_PW ;    // Def R0 Reduction PW de 0% � 50% pas de 10%

// Configuration utilisateur
//typedef enum { FR, EN, PT, NE } E_LANGUE;   // Jusqu'a 8 langues

// Date
typedef enum { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, DAYS_MAX } E_DAYS; 

// Status de la PAC pour affichage IHM
typedef enum {S_ARRET=0, S_ATTENTE, S_CHAUD, S_FROID, S_HORS_GEL, S_EXT_CHAUD, S_EXT_FROID, S_CHAUD_FROID, S_ECS = 8, S_PISCINE = 16} E_STATUT_PAC;
typedef enum {S_NO_TF = 0, S_TF_CPS, S_TF_PAC} E_STATUT_TEST;
typedef enum {S_AUCUNE=0, S_VACANCES, S_SABLIER, S_DALLE, S_LEGIONEL} E_STATUT_EXCEPTION;

typedef enum { RF_MODE_RIEN,  RF_MODE_REDUIT, RF_MODE_NORMAL, RF_MODE_CONFORT, RF_MODE_VACANCES, RF_MODE_SABLIER } E_MODE_SONDE;
typedef enum { RF_MODE_ARRET, RF_MODE_CHAUD,  RF_MODE_FROID,  RF_MODE_HORS_GEL } E_MODE_PROD ;

// Special Geotwin
typedef enum { E_TYPE_CAPTAGE_CAPTEUR = 0, E_TYPE_CAPTAGE_NAPPE_DIRECTE , E_TYPE_CAPTAGE_NAPPE_BARRAGE } E_TYPE_CAPTAGE_GEO;
typedef enum { REGUL_GEO_HYSTERESIS = 0, REGUL_GEO_AUTO } E_TYPE_REGULATION_GEO;

// special FAN des Ventilo_Cassette
typedef enum {REGUL_VENTILATEUR_GAINABLE_VOLUME_PIECES} E_TYPE_REGUL_VENTILATEUR_GAINABLE;
typedef enum {REGUL_FAN_VITESSE_NORMAL, REGUL_FAN_VITESSE_FORT, REGUL_FAN_VITESSE_FAIBLE , REGUL_FAN_VITESSE_XXX} E_TYPE_REGUL_FAN_VITESSE;
typedef enum {GAZ_NONE=0, GAZ_R410, GAZ_R134, GAZ_R407, GAZ_R32, GAZ_HELIUM, GAZ_R513, GAZ_R454C} E_TYPE_GAZ;

// Soft Ethernet
typedef enum {STATE_ARKTEOS_SERVER = 0, STATE_WIP_ADDRESS, STATE_TIME_ZONE, STATE_HP_SERVER, STATE_WAIT_NETWORK} E_SERVER_STATE;
typedef enum {TYPE_NONE = 0, TYPE_RECUP_SOFT, TYPE_INSTALL_SOFT, TYPE_UPLOAD, TYPE_RESTART, TYPE_START, TYPE_RESTART_IN_BOOT, TYPE_ENVOI_CONFIGURATION, TYPE_ENVOI_ENERGIES, TYPE_CONFIGURATION, TYPE_ENERGIES, TYPE_HISTORIQUE, TYPE_HISTORIQUE_ERREURS} E_TYPE_REQUEST;
typedef enum {USB_NOT_DEFINED = 0, USB_HOST, USB_DEVICE} E_TYPE_USB;

// 
typedef enum { CARTE_MZ1, CARTE_MZ2, CARTE_MZ3, CARTE_REG, CARTE_ECS, NB_CARTES } E_TYPE_CARTE_MZ;
typedef enum { BOARD_REG, BOARD_MZ1, BOARD_MZ2, BOARD_MZ3, BOARD_ECS } E_NUM_BOARD;
typedef enum { VOIE_1, VOIE_2, VOIE_3, VOIE_4, VOIE_5, NB_VOIE_CARTE_MZ } E_NUM_VOIE_OF_BOARD;

// AJPAC III
typedef enum { EGC_INIT, EGC_C2ON, EGC_ATTENTE_CARTER_ON, EGC_CARTER_ON, EGC_CARTER_OFF} E_ETAPE_GESTION_CARTER; 

// GEOTWIN
typedef enum {SOUS_TYPE_GEOTWIN, SOUS_TYPE_SAGITAIR} E_SOUS_TYPE_GEOTWIN;

// PHOENIX
typedef enum{PHOENIX_HT} E_SOUS_TYPE_PHOENIX;

// GEOINVERTER
typedef enum{GEOINV_STD, GEOINV_BI_COMP, GEOINV_BI_ETAGE, GEOINV_SAGITAIR, GEOINV_DEFROST} E_SOUS_TYPE_GEOINV;

// Configurations autres
typedef enum {SIMULTANE_CHAUD_FROID_NONE, SIMULTANE_CHAUD_FROID_CONFIGURATION_1, SIMULTANE_CHAUD_FROID_CONFIGURATION_2, SIMULTANE_CHAUD_FROID_CONFIGURATION_3} E_TYPE_SIMULTANE_CHAUD_FROID;
// SIMULTANE_CHAUD_FROID_CONFIGURATION_1 : Freecooling (Froid par Freecolling � classique � ou par le c�t� capteur de la PAC en fonction que la PAC est par ailleurs en demande de production de Chaud vers une source chaude ou pas)
// SIMULTANE_CHAUD_FROID_CONFIGURATION_2 : Froid actif (Pr�sence de 2 ballons Chaud et Froid, d�charge de la PAC du ballon satisfait vers le capteur)

// Type AJPAC
typedef enum { MONO_10KW, MONO_16KW, TRI_16KW, TRI_20KW, MONO_6KW, MONO_8KW, TRI_24KW } E_LISTE_PW;

// </editor-fold>

/*****************************************************************************/
//  DEFINITION DES ENTREES /SORTIES DES CARTES
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="STRUCTURES ENTREE / SORTIES DES CARTES">

// <editor-fold defaultstate="collapsed" desc="Description Carte Ether   ">
/* Liste des entrees TOR */
typedef struct
{
	uint8_t bInTorSpare0:1;            // Entr�e x
	uint8_t bInTorSpare1:1;            // Entr�e x
	uint8_t bInTorSpare2:1;            // Entr�e x
	uint8_t bInTorSpare3:1;            // Entr�e x
	uint8_t bInTorSpare4:1;            // Entr�e x
	uint8_t bInTorSpare5:1;            // Entr�e x
	uint8_t bInTorSpare6:1;            // Entr�e x
	uint8_t bInTorSpare7:1;            // Entr�e x

	uint8_t bInTorSpare8:1;            // Entr�e x
	uint8_t bInTorSpare9:1;            // Entr�e x
	unsigned char :6;             // Entr�e x
} S_IN_TOR_ETHER;

typedef struct
{
	unsigned char LED_StatutDefaut:1;
	unsigned char LED_StatutVerte:1;
	unsigned char LED_EtherSpeed:1;
	unsigned char LED_UsbVerte:1;
	unsigned char LED_UsbRouge:1;
	unsigned char Wifi_EnablePWR:1;
	uint8_t    u2Spare : 2;

	uint8_t    u8Spare;
} S_OUT_TOR_ETHER;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Reg   ">

// Liste des entrees TOR
typedef struct
{
	// Avec Gestion des rebonds
	uint8_t  bDefautAppoint  : 1;    // Cette Entr�e n'est pas param�trable la laisser en position Bit 0
	uint8_t  bInTOR_1        : 1;    // La fonction 1 tombe le bit 1 de la structure ce qui facilite la gestion des affectations
	uint8_t  bInTOR_2        : 1;
	uint8_t  bInTOR_3        : 1;
	uint8_t  bInTOR_4        : 1;
	uint8_t  bInTOR_5        : 1;
	uint8_t  bInTOR_6        : 1;
	uint8_t  bInTOR_7        : 1;

	uint8_t  bInSpare1       : 1;
	uint8_t  bInSpare2       : 1;
	uint8_t  bInSpare3       : 1;
	uint8_t  bInSpare4       : 1;
	uint8_t  bInSpare5       : 1;
	uint8_t  bInSpare6       : 1;
	uint8_t  bInSpare7       : 1;
	uint8_t  bInSpare8       : 1;

	uint8_t  Comptage_Energie: 1;        // Entr�e comptage Energie ; Cette entr�e est �galement attach� au comptage
	uint8_t  bInTF_1         : 1;
	uint8_t  bInTF_2         : 1;
	uint8_t  bInTF_3         : 1;

	uint8_t u8Spare;
} S_IN_TOR_REG;     // 4 Octets

typedef struct
{
	uint8_t  u1Spare         :1;
	uint8_t  Out_1           :1;     // La fonction 1 tombe le bit 1 de la structure ce qui facilite la gestion des affectations
	uint8_t  Out_2           :1;
	uint8_t  Out_3           :1;
	uint8_t  Out_4           :1;
	uint8_t  Out_5           :1;
	uint8_t  ReleveChaudiere :1;
	uint8_t  u1Spare2        :1;

	uint8_t  Pw_Relec        :2;     // E_PW_RELEC def P0
	uint8_t  LED_Defaut      :1;
	uint8_t  u5Spare         :5;
} S_OUT_TOR_REG;

typedef struct
{
	uint16_t  u16DebitPrimaire;
	uint16_t  u16DebitZ1;

	uint16_t  u16DebitZ2;

	uint8_t u8RetourPWM_Primaire;
	uint8_t u8RetourPWM_Z1;

	uint8_t u8RetourPWM_Z2;
	uint8_t u8Spare;
	uint16_t  u16Spare;
} S_IN_PWM_REG;


typedef struct
{
	int16_t i16TempDepartPrimaire;
	int16_t i16TempRetourPrimaire;
	int16_t i16TempDepartZ1;
	int16_t i16TempRetourZ1;
	int16_t i16TempDepartZ2;
	int16_t i16TempRetourZ2;
	uint16_t  u16Pression;
	int16_t i16BallonTampon;
} S_IN_ANA_REG;


/* Liste des sorties ANA */
typedef struct
{
	uint8_t Cons_Circul_Z1 ;    /* Def 0 ( de 0 � 200 )*/
	uint8_t Cons_Circul_Z2 ;    /* Def 0 ( de 0 � 200 )*/
	uint8_t Cons_V3V_Z2 ;       /* Def 0 ( de 0 � 200 )*/
	uint8_t Cons_Circul_Primaire ;
} S_OUT_ANA_REG;

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Option ECS   ">
typedef struct
{
	unsigned char   bSolaire:1;               // Entr�e Solaire (autorisation Production ECS)
	unsigned char   In2:1;                    // Entr�e 2
	unsigned char   In3:1;                    // Entr�e 3
	unsigned char   In4:1;                    // Entr�e 4
	unsigned char : 4;
	uint8_t      u8Spare;
	uint16_t      u16CompteurEau;           // Compteur Eau en impulsion / litre
} S_IN_TOR_ECS;

typedef struct
{
	uint8_t      appointECS:1;           // Relais appoint ECS
	uint8_t      V3V_ECS:1;              // vanne 3 voies ECS
	uint8_t      CirculateurECS:1;       // circulateur ECS
	uint8_t      Spare1:1;               // Spare 1 0-24V
	uint8_t      Spare2:1;               // Spare 2 0-24V
	unsigned char : 3;
} S_OUT_TOR_ECS;

typedef struct
{
	int16_t      i16TempECSMilieu;       // Temp�rature Ballon ECS Milieu (relance)
	int16_t      i16TempECSBas;          // Temp�rature Ballon ECS Bas
	int16_t      i16TempDepart;          // Temp�rature Depart voie 1
	int16_t      i16TempRetour;          // Temp�rature Retour voie 1
} S_IN_ANA_ECS;

typedef struct
{
	uint8_t      u8ConsigneCirculateur;  // Consigne circulateur 0-100%
	uint8_t      u8ConsigneVanneMelange; // Consigne 0-10V (vannes m�lange)
	uint16_t      u16Spare;               // Sortie Ana Spare
} S_OUT_ANA_ECS;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Option Multizone   ">
typedef struct
{
	unsigned char   bVoie1:1;               // Entr�e 1 (Zone 1 IN Contact)
	unsigned char   bVoie2:1;               // Entr�e 2 (Zone 2 IN Contact)
	unsigned char   bVoie3:1;               // Entr�e 3 (Zone 3 IN Contact)
	unsigned char   bVoie4:1;               // Entr�e 4 (Zone 4 IN Contact)
	unsigned char   bVoie5:1;               // Entr�e 5 (IN 5 Contact)
	unsigned char   bPiscine:1;
	unsigned char   bInSpare:1;
	unsigned char   u1Spare:1;

	uint8_t      u8Spare;

	uint16_t      u16Compteur;            // Compteur
	uint16_t      u16debit;               // Debitmetre

	uint8_t      u8RetourPWM[NB_VOIE_CARTE_MZ];   // 0-100% (retour circulateur)
	uint8_t      u8Spare1;
} S_IN_TOR_MULTI_ZONE;

typedef struct
{
	uint8_t      bRelais1:1;             // Relais 1 / Circulateur 1
	uint8_t      bRelais2:1;             // Relais 2 / Circulateur 2
	uint8_t      bRelais3:1;             // Relais 3 / Circulateur 3
	uint8_t      bRelais4:1;             // Relais 4 / Circulateur 4
	uint8_t      bRelais5:1;             // Relais 5 / Circulateur 5
	uint8_t      bV3V_Piscine:1;         // Relais V3V Piscine
	uint8_t      : 2;
	uint8_t      u8Spare;
} S_OUT_TOR_MULTI_ZONE;

typedef struct
{
	int16_t      i16TempDepart[NB_VOIE_CARTE_MZ]; // Temp�rature d�part Zone x
	int16_t      i16TempRetour[NB_VOIE_CARTE_MZ]; // Temp�rature retour Zone x
	int16_t      i16TempPiscine;         // Temp�rature piscine
	int16_t      i16TempSpare1;          // Temp�rature Spare
	int16_t      i16TempSpare2;          // Temp�rature Spare
	int16_t      i16TempSpare3;          // Temp�rature Spare
} S_IN_ANA_MULTI_ZONE;

typedef struct
{
	uint8_t      Consigne     : 7;       // Consigne des voies (circulateur/registre en 0-10V ou PWM) 0-100%
	uint8_t      bTypeConsigne: 1;       // Type de sortie ANA (0-10V ou PWM)
} S_OUT_CONSIGNE;

typedef struct
{
	S_OUT_CONSIGNE      ConsigneVoie[NB_VOIE_CARTE_MZ];  // Consigne des voies (circulateur/registre en 0-10V ou PWM) 0-100% ( on pourrait le mettre sur le bit 8 de chaque consigne)
	S_OUT_CONSIGNE      ConsigneFan;            // Consigne FAN   (Fan de la Cassette en 0-10V ou PWM) 0-100%
	uint16_t      u16Spare;                           // Sortie Spare
} S_OUT_ANA_MULTI_ZONE;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo AJPAC   ">
typedef struct //12 bytes
{
    int16_t  i16Temp_Frigo_TSH410;
    int16_t  i16Temp_Frigo_TSC410_A;
    int16_t  i16Temp_Frigo_TSH134;
    int16_t  i16Temp_Frigo_TSC410_B;
    int16_t  i16Temp_Frigo_TEV134;
    int16_t  i16Temp_Frigo_TIGBT;  // Utilise pour le resultat de la demande de Mode PAR21
} S_IN_TEMP_FRIGO_AJPAC;

typedef struct //10 bytes
{
    int16_t  i16In_Pression_BP410;
    int16_t  i16In_Pression_BP134;
    int16_t  i16In_Pression_HP410;
    int16_t  i16In_Pression_HP134;
    int16_t  i16In_Pression_HPINT;
} S_IN_PRESS_FRIGO_AJPAC;

typedef struct //2 bytes
{
	unsigned char Pressostat_HP410:1;
	unsigned char Pressostat_HP134:1;
	unsigned char J20:1;
	unsigned char u5Spare:5;
	uint8_t Spare;
} S_IN_TOR_FRIGO_AJPAC;

typedef struct //2 bytes
{
	unsigned char V4V_R410:1 ;            /*Def OFF */
	unsigned char Electrovanne_HP410:1;   /*Def OFF */
	unsigned char Ventilateur_PW:1;       /*Def ON */
	unsigned char Compresseur2 : 1;          /*Def OFF */
	unsigned char LED_Defaut:1;           /*Def OFF */
	unsigned char LED_Verte:1;            /*Def OFF */
	unsigned char : 2;

	uint8_t Spare;
} S_OUT_TOR_FRIGO_AJPAC;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Fan AJPAC   ">
typedef struct
{
	unsigned char Evap_EV1:1;
	unsigned char Evap_EV2:1;
	unsigned char Evap_EV3:1;
	unsigned char Evap_EV4:1;
	unsigned char Evap_EV5:1;
	unsigned char nu : 3 ; // Vitesse_Ventilateur:3;  // E_VITESSE_VENTILATEUR_EVAP
	unsigned char LED_Defaut:1;
	unsigned char  : 1;   // Ex Type detendeur
	unsigned char Spare  : 6 ;
} S_OUT_TOR_FAN_AJPAC;

typedef struct //2 bytes
{
	uint8_t Ventilateur1 ; /*def 0% , de 0 � 100% */
	uint8_t Ventilateur2 ; /*def 0% , de 0 � 100% */
} S_CONSIGNE_FAN_AJPAC;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo GEOTWIN    ">
// Partie Physique de la Carte
typedef struct //20 bytes
{
    int16_t  i16Temp_BP1;
    int16_t  i16Temp_BP2;
    int16_t  i16Temp_ALL_PRI;
    int16_t  i16Temp_RET_PRI;
    int16_t  i16Temp_ALL_CAP;
    int16_t  i16Temp_RET_CAP;
    int16_t  i16Temp_EXT;
    int16_t  i16Temp_HP1;
    int16_t  i16Temp_HP2;
    int16_t  i16Temp_COND;
} S_TEMP_GEO;

typedef struct //8 bytes
{
    int16_t  i16Pression_GazHP;
    int16_t  i16Pression_GazIntermediaire;
    int16_t  i16Pression_GazBP;
    int16_t  i16Pression_EauCaptage;
} S_IN_PRESS_GEO;

typedef struct //8 bytes
{
    uint16_t  u16Vitesse_Circul_PRI;
    uint16_t  u16Vitesse_Circul_CAP;
    uint16_t  u16Debit_PRI;
    uint16_t  u16Debit_CAP;
} S_IN_ANA_GEO;

typedef struct //2 bytes
{
	unsigned char           Puits :1;             // Puits
	unsigned char           HP :1;                // HP
	unsigned char           DemarreurC1 :1;       // Etat Demarreur C1
	unsigned char           DemarreurC2 :1;       // Etat Demarreur C2
	unsigned char   Spare2 : 4 ;
	uint8_t              Spare;
}S_IN_TOR_GEO ;

typedef union //2 bytes
{
    uint16_t  u16Val ;
    struct
    {
        unsigned char SW1_SW2 ;  // ces valeurs + SW3 sont remises dans S_IN_TOR_FRIGO
        unsigned char SW3_1 : 1;
        unsigned char dummy : 7;
    }sw;
    struct
    {
        unsigned char Num_PAC : 3;
        unsigned char Model_PAC : 5;

        unsigned char bmaitre : 1;
        unsigned char dummy : 7;
    }pac;

    struct
    {
        unsigned char  SW1_1 : 1;
        unsigned char  SW1_2 : 1;
        unsigned char  SW1_3 : 1;
        unsigned char  SW1_4 : 1;
        unsigned char  SW2_1 : 1;
        unsigned char  SW2_2 : 1;
        unsigned char  SW2_3 : 1;
        unsigned char  SW2_4 : 1;

        unsigned char  SW3_1 : 1;
        unsigned char dummy : 7;
    }swbit;
} S_IN_SW_GEO ;

typedef struct //2 bytes
{
	unsigned char REL_CirculateurPrimaire :1;
	unsigned char REL_CirculateurCaptage :1;
	unsigned char REL_V4V :1;                     //ON = rafraichissement
	unsigned char REL_PompeDePuit :1;
	unsigned char REL_Compresseur1 :1;
	unsigned char REL_Compresseur2 :1;
	unsigned char REL_Spare1 :1;
	unsigned char REL_Spare2 :1;   // => 8bits !!! Logique invers�e Relais NF


	unsigned char LED_Defaut :1;
	unsigned char LED_Verte :1;
	unsigned char Spare:6;
} S_OUT_TOR_GEO;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo Zuran Baguio   ">
typedef struct //2 bytes
{
	unsigned char Pac_On_Off    :1;
	unsigned char Pac_PW1       :1;
	unsigned char Pac_PW2       :1;
	unsigned char Pac_PW3       :1;
	unsigned char LED_Defaut    :1;
	unsigned char LED_Verte     :1;
	unsigned char Simu_Chaud_Froid:1;
	unsigned char Chaud_Froid   :1;

	unsigned char Circulateur   :1;
	unsigned char Zuran_IO8     :1;
	unsigned char Silencieux    :1;
	unsigned char Spare :5;
} S_OUT_TOR_FRIGO_ZUBA;


typedef struct //2 bytes
{
	unsigned char I1 :1;      // I1
	unsigned char I4 :1;      // I4
	unsigned char I_SSM :1;   // I_SSM
	unsigned char Spare2 :5;

	uint8_t Spare;
}S_IN_TOR_FRIGO_ZUBA;

typedef struct //2 bytes
{
	int16_t i16Temp_Th2_Liquide;
	int16_t i16Temp_S1;
	int16_t i16PressionBasse;
	int16_t i16PressionHaute;
}S_IN_ANA_FRIGO_ZUBA;

 // </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo PHOENIX / GEO INVERTER">
typedef struct
{
	// Debits
	uint16_t  u16DebitPrimaire;
	uint16_t  u16DebitCapteur;
	uint16_t  u16RetourVitessePrimaire;
	union
	{
		uint16_t  u16RetourVitesseVentilateur;
		uint16_t  u16RetourVitesseCapteur;
	};
	// Hygrom�trie
	int16_t  i16Hygrometrie;
	// Pressions
	int16_t  i16Press_BP1;
	int16_t  i16Press_BP2;
	int16_t  i16Press_HP1;
	int16_t  i16Press_HP2;
	int16_t  i16Press_EauCapteur;
	int16_t  i16Press_EauChauffage;
	int16_t  i16Press_Spare;
	// Temp�ratures
	int16_t  i16Temp_DepartPrimaire;
	int16_t  i16Temp_RetourPrimaire;
	int16_t  i16Temp_DepartCapteur;
	int16_t  i16Temp_RetourCapteur;
	int16_t  i16Temp_BP1;
	int16_t  i16Temp_BP2;
	int16_t  i16Temp_HP1;
	int16_t  i16Temp_HP2;
	int16_t  i16Temp_Exterieur;
	int16_t  i16Temp_Liquide;
	int16_t  i16Temp_Spare;
	int16_t  i16Temp_CaptSpare;
	int16_t  i16Temp_PrimSpare;
} S_IN_ANA_FRIGO; // 50 octets

typedef struct
{
	uint8_t InDebitPuit :1;
	uint8_t InKlixonCompresseur :1;
	uint8_t InPressostatHP1 :1;
	uint8_t InPressostatHP2 :1;
	uint8_t InDefautDemarreur1 :1;
	uint8_t InDefautDemarreur2 :1;
	uint8_t InSW1 :1;
	uint8_t InSW2 :1;

	uint8_t InSW3 :1;
	uint8_t InSW4 :1;
	uint8_t InDefautAppoint1 :1;
	uint8_t InDefautAppoint2 :1;
	uint8_t InDefautAppoint3 :1;
	uint8_t InEnergie :1;
	uint8_t u2Spare :2;

	uint16_t  u16CompteurEnergies;    // Energies consomm�e instantan�e
} S_IN_TOR_FRIGO;

typedef struct
{
	uint8_t u8ConsigneCirculateurPrimaire;
	union
	{
		uint8_t u8ConsigneCirculateurCapteur;
		uint8_t u8ConsigneVentilateur;
	};
	uint16_t  u16PositionDetendeur1;
	uint16_t  u16PositionDetendeur2;
	uint16_t  u16PositionDetendeur3;
	uint16_t  u16PositionDetendeur4;
} S_OUT_ANA_FRIGO;

typedef struct
{
	uint8_t V4V :1;
	uint8_t ResistanceVase :1;
	uint8_t ElectrovanneFroid :1;
	uint8_t ResistanceCarter :1;
	uint8_t Compresseur1 :1;
	uint8_t Compresseur2 :1;
	uint8_t Spare1 :1;   // V3V_ChauffageFC
	uint8_t Spare2 :1;   // V3V_CapteurFC

	uint8_t ContactPuit :1;
	uint8_t Appoint1 :1;
	uint8_t Appoint2_3 :1;
	uint8_t Ventilateur :1;
	uint8_t u4Spare:4;
} S_OUT_TOR_FRIGO;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo ARKTEA">
typedef struct
{
	// Debits
	uint16_t  u16DebitPrimaire;
	uint16_t  u16DebitCapteur;
	uint16_t  u16RetourVitessePrimaire;
	uint16_t  u16RetourVitesseVentilateur;
	// Hygrom�trie
	int16_t  i16Hygrometrie;
	// Pressions
	int16_t  i16Press_EauCapteur;
	int16_t  i16Press_EauPrimaire;
	int16_t  i16Press_Helium;
	// Temp�ratures
	int16_t  i16Temp_DepartPrimaire;
	int16_t  i16Temp_RetourPrimaire;
	int16_t  i16Temp_DepartCapteur;
	int16_t  i16Temp_RetourCapteur;
	int16_t  i16Temp_Spare1;
	int16_t  i16Temp_Spare2;
	int16_t  i16Temp_Exterieur;
	int16_t  i16Temp_Liquide;
	int16_t  i16Temp_Spare;
	int16_t  i16Temp_CaptSpare;
	int16_t  i16Temp_PrimSpare;
} S_IN_ANA_ARKTEA; // 38 octets

typedef struct
{
	int16_t  i16Temp_TC1;
	int16_t  i16Temp_TC2;
	int16_t  i16Temp_TC3;
	int16_t  i16Temp_TC4;
	int16_t  i16Temp_TC5;
	int16_t  i16Temp_TC6;
	int16_t  i16Temp_TC7;
	int16_t  i16Temp_TC8;
	int16_t  i16Temp_TC9;
	int16_t  i16Temp_TC10;
	int16_t  i16Temp_TC11;
	int16_t  i16Temp_TC12;
	int16_t  i16Debit_1;
	int16_t  i16Debit_2;
	int16_t  i16Debit_3;
	int16_t  i16Debit_4;
} S_IN_DEBUG_ARKTEA; // 32 octets

typedef struct
{
	uint8_t InDebitPuit :1;
	uint8_t InKlixonCompresseur :1;
	uint8_t InPressostatHP1 :1;
	uint8_t InPressostatHP2 :1;
	uint8_t InDefautDemarreur1 :1;
	uint8_t InDefautDemarreur2 :1;
	uint8_t InSW1 :1;
	uint8_t InSW2 :1;

	uint8_t InSW3 :1;
	uint8_t InSW4 :1;
	uint8_t InDefautAppoint1 :1;
	uint8_t InDefautAppoint2 :1;
	uint8_t InDefautAppoint3 :1;
	uint8_t InEnergie :1;
	uint8_t u2Spare :2;

	uint16_t  u16CompteurEnergies;    // Energies consomm�e instantan�e
} S_IN_TOR_ARKTEA;

typedef struct
{
	uint8_t u8ConsigneCirculateurPrimaire;
	uint8_t u8ConsigneCirculateurCapteur;
	uint8_t u8ConsigneVentilateur;
	uint8_t u8ConsigneSpare;
} S_OUT_ANA_ARKTEA;

typedef struct
{
	uint8_t V4V :1;
	uint8_t ResistanceVase :1;
	uint8_t ElectrovanneFroid :1;
	uint8_t ResistanceCarter :1;
	uint8_t Compresseur1 :1;
	uint8_t Compresseur2 :1;
	uint8_t Spare1 :1;
	uint8_t Spare2 :1;

	uint8_t ContactPuit :1;
	uint8_t Appoint1 :1;
	uint8_t Appoint2_3 :1;
	uint8_t Ventilateur :1;
	uint8_t u4Spare:4;
} S_OUT_TOR_ARKTEA;
// </editor-fold>

// </editor-fold>

/*****************************************************************************/
//  DEFINITION DES STRUCTURES DE COMMUNICATION
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="STRUCTURES de FONCTIONNEMENT pour SAV et DATE (la Date est Stock�e en Flash)   ">
typedef struct
{
	unsigned char   bShuntTempo : 1;
	// unsigned char   bDerogationPression : 1; // ce fait a l'aide d'une commande et le retour est dans le Statut_PAC
	unsigned char   NumPacStructe : 3;
	unsigned char   u4Spare : 4;
	uint8_t              u8Spare;
	uint16_t              u16Spare;
} S_PARAM_SAV;                      // 4 Octets ==> Cette variable n'est pas stock�e en E2P

typedef struct
{
	unsigned char ModeTest:3;   // E_MODE_TEST_PAC  def T_CHAUD
	unsigned char bTestPAC:1;   // Demande mode test
	unsigned char :4;           // Reserve
	uint8_t  Pw;                     // En prevision pour autres machines
	int16_t Teau;                   // Consigne de temperature mode test
	uint16_t  u16Spare1;              // Spare1
	uint16_t  u16Spare2;              // Spare2
} S_PARAM_TEST_PAC;                 //8 Octets ==> Cette variable n'est pas stock�e en E2P

// Date Stock�e en Flash pour v�rification de perte de date (la date de mise en service est en E2P)
typedef struct
{
	uint8_t Year;    // 0 � 99 = 2000 � 2099
	uint8_t Month;   // 1 � 12
	uint8_t Date;    // 1 � 31
	uint8_t Hours;   // 0 � 23
	uint8_t Minutes; // 0 � 59
	uint8_t Seconds; // 0 � 59
	uint8_t WeekDay; // 0 � 6 ; format E_DAYS
	uint8_t Semaine:7;   // Numero de semaine, inutilise
	uint8_t Heure_Ete:1;
} S_DATE;
#define S_DATE_COURTE sizeof(S_DATE)-2
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DE CONFIGURATION et OPTION DE LA REGULATION (Stock�es en E2P)   ">
typedef struct
{
	uint8_t                  u8ModelePAC;            // Voir E_MODEL_PAC
	uint8_t                  u8PwPac;                // En KW
	uint8_t                  u8ThermoMaxPac;         // �C

	uint8_t                  u3SousTypePAC : 3;      // si besoin ex (Zuran / Baguio / Baguio Mono Bloc)
	uint8_t                  nbCompresseur : 2;      // E_NB_COMPRESSEUR
	uint8_t                  bReversible : 1;        // NON / OUI
	uint8_t                  bSupply : 1;            // MONO / TRI
	uint8_t                  bDemarreurProgressif:1; // NON / OUI

	uint8_t                  Gaz_C1 : 4;             // None / R410 / R134 / R407 / R32 / R290 / R513 / R1234
	uint8_t                  Gaz_C2 : 4;

	uint8_t  u8Spare;
	uint16_t  u16Spare;
} S_MODELE_PAC;                                     // 8 Octets

// Structure pour l'option des Zones NB les zones sont assoic�es au physique des cartes options
typedef struct
{
	unsigned char bZone1:1;
	unsigned char bZone2:1;
	unsigned char bZone3:1;
	unsigned char bZone4:1;
	unsigned char bZone5:1;
	unsigned char bZone6:1;
	unsigned char bZone7:1;
	unsigned char bZone8:1;
}S_ZONE;                            // 1 octet


typedef struct
{
	S_ZONE          sZone;                  // Definition des 8 Zones  Def Zone 1

	unsigned char   Piscine:1;              // def FAUX
	unsigned char   ECS:1;                  // def FAUX
	unsigned char   CoeffComptagePW:2;      // E_CoeffComptagePW    Def NO_COMPTAGE
	unsigned char   TypeAppoint:2;          // E_APPOINT_CHAUFFAGE  Def NO_APPOINT
	unsigned char   CoeffCompteurEau : 2;   // E_CoeffComptageEau   Def NO_COMPTAGE_EAU Comptage Eau Sanitaire

	uint16_t              u16PW_Brin;             // Faire avancer de 100 Watts � la fois de 1KW � 4 KW

	unsigned char   u2NbBrinAppoint:2;      // Defaut : 3 brins
	unsigned char   u2ModeleThermostatRF:2; // Watts /
	unsigned char   u2ModeleThermostatRS485:2;//
	unsigned char   u2Spare:2;              //

	uint8_t              u8Spare;                //

	uint16_t              u16Spare;               //
} S_OPTION_PAC;                                 // 8 Octets

typedef struct
{
    uint8_t                  auc8Serial_Number_PAC[12];
    uint8_t                  auc8PW_Installateur[4];
    uint8_t                  auc8PW_Maintenance[4];
    uint8_t                  CodeLogoClient[15];         // Code pour faire afficher le logo client client
    uint8_t                  u5VerificationAnnuelle:5;
    uint8_t                  u3Spare:3;

    //uint8_t                  Spare;
    S_DATE              sDateMiseEnService;         // Date de mise en service
    uint32_t                 u32Spare;
} S_INSTALL_PAC;                                    // 48 Octets

typedef union
{
    uint64_t u64val;                                         // 8 Octets Max
    struct
    {
        int8_t i8Hysteresis_Primaire_Plus;                  // Hyst�r�sis sur T� eau des Arret et D�marrage de Compresseur
        int8_t i8Hysteresis_Primaire_Moins;
        uint8_t u8ConsignePompePuitsMax;
        uint8_t u8ConsignePompePuitsMin;

        unsigned char eTypeRegulation :3;               // different type de Captage ou gestion de Captage
        unsigned char bFreecooling:1;                   // Option free cooling
        unsigned char bElectrovanneNappe:1;             // Pr�sence Electrovanne Nappe
        unsigned char eTypeSimultaneChaudFroid :3;      // E_TYPE_SIMULTANE_CHAUD_FROID

        unsigned char eTypeDeCaptage :3;                // E_TYPE_CAPTAGE_GEO
        unsigned char bGestionCirculateurCaptageForce:1;// Mode Auto ou Forcee
        unsigned char eGestionCirculateurCaptage:4;     // E_GESTION_CIRCULATEUR

        unsigned char eTypeCirculateurCaptage :2;       // E_TYPE_CIRCULATEUR
        unsigned char bLimitationPW_Froid :1;           //
        unsigned char bLimitationPW_ECS :1;             //
        unsigned char u4Spare :4;                       // Spare

        unsigned char u4DebitmetreCaptage :4;           // E_TYPE_DEBITMETRE
        unsigned char u4DebitmetreChauffage :4;         // E_TYPE_DEBITMETRE
    } ConfigGeo;
    struct
    {
        int8_t i8Hysteresis_Primaire_Plus;
        int8_t i8Hysteresis_Primaire_Moins;

        unsigned char bFreecooling:1;                   // Option free cooling
        unsigned char eTypeSimultaneChaudFroid :3;      // E_TYPE_SIMULTANE_CHAUD_FROID
        unsigned char eTypeDeCaptage :3;                // E_TYPE_CAPTAGE_GEO
        unsigned char bUseCarterHeater :1;

        uint8_t u8ConsignePompePuitsMax;
        uint8_t u8ConsignePompePuitsMin;
    } ConfigGeoInverter;
    struct
    {
        int8_t i8Hysteresis_Primaire_Plus;
        int8_t i8Hysteresis_Primaire_Moins;
    } ConfigArktea;
    struct
    {
        int8_t i8Hysteresis_Primaire_Plus;
        int8_t i8Hysteresis_Primaire_Moins;
    } ConfigPhoenix;
    struct
    {
        uint8_t  futurConfigCairox;
    } ConfigCairox;
    struct
    {
        int8_t i8Hysteresis_Primaire_Plus;
        int8_t i8Hysteresis_Primaire_Moins;

        uint8_t u2TypeRegul_MITSU :2;
        uint8_t u6Spare :6;
    } ConfigZuranBaguio;
    struct
    {
        uint8_t futurConfigAjpac;
    } ConfigAjpac;
} S_CONFIG_PAC;                // 8 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURE MODE de FONCTIONNEMENT DE LA REGULATION (Stock�es en E2P)   ">

// Mode de fonctionnement en cours
typedef struct
{
	uint8_t         bEtatPAC:1;               // Arret / Marche
	uint8_t         bSecours:1;               // Mode secours
	uint8_t         bAppointUser:1;           // Utilisation appoint utilisateur
	uint8_t         bModeSilencieux:1;        // Utilisateur validation de la PROG mode Silencieux
	uint8_t         bUserFreeHeating:1;       // Validation User Freeheating
	uint8_t         bUserFreecooling:1;       // Validation User Freecooling
	uint8_t         bUserAdaptationLoiDeau:1; // Validation de l'adaptation loi d'eau via entr�e contact (auto conso)
	uint8_t         bUserAdaptationConsigne:1;// Validation de l'adaptation de consigne entr�e contact   (auto conso)

	uint8_t            u8Spare;
	uint16_t            u16Spare;
} S_MODE_PAC;                                   // 4 Octets

typedef struct
{
    unsigned char Mode:4;                       // E_FONCT_ZX Def ARRET
    unsigned char Exception:3;                  // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char u1Spare : 1;
    uint8_t            u8Spare;                      // Unused

    int16_t            i16Consigne_Tint_Reduit;      // Consigne reduit (chaud ou froid)
    int16_t            i16Consigne_Tint_Normal;      // Consigne normal (chaud ou froid)
    int16_t            i16Consigne_Tint_Confort;     // Consigne confort (chaud ou froid)

    int16_t            i16Consigne_Tint_Horsgel;     // Consigne temperature hors gel
    uint16_t            u16Time_Sablier;              // Temps de la d�rogation

    int16_t            i16Consigne_Tint_Sablier;     // Consigne pendant la d�rogation
    int16_t            i16Consigne_Tint_Vacances;    // Consigne temperature vacances
}S_MODE_ZX;                                     // 16 Octets

typedef struct
{
    unsigned char Mode :4;                      // E_FONCT_ECS Def ARRET
    unsigned char Exception :3;                 // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char bUserLegionnel :1;

    unsigned char bUserAppointECS : 1;          // Pas d'utilisation de l'appoint
    unsigned char bUserECSSecours : 1;          // 0 = NORMAL ; 1 = FORCE
    unsigned char bUserECSVacancesOFF : 1;      // 0 = ECS pendant Vacances            ; 1 = Arret de l'ECS pendant les vacances
    unsigned char bUserLegionnelVacancesOFF :1; // 0 = Anti Legionnel pendant Vacances ; 1 = Arret des cycles Anti Legionnel pendant les vacances
    unsigned char u4VerificationAnodeECS: 4;    // V�rification de l'�tat de l'anode pour l'ECS

    uint8_t            u8Time_Bouclage_ECS;          // Dur�e du bouclage ECS (marche forc�e)
    uint8_t            u8Spare;                      //

    int16_t            i16Consigne_ECS_Normal;       // Consigne normal (chaud ou froid)
    int16_t            i16Consigne_ECS_Confort;      // Consigne confort (chaud ou froid)

    int16_t            i16Consigne_ECS_Relance;      // Consigne temperature hors gel
    uint16_t            u16Time_ECS_Sablier;          // Temps de la d�rogation

    int16_t            i16Consigne_ECS_Sablier;      // Consigne pendant la d�rogation
    int16_t            i16Consigne_ECS_Vacances;     // Consigne temperature vacances
} S_MODE_ECS;                                   // 16 Octets

typedef struct
{
    unsigned char Mode :4;                      // E_FONCT_PISCINE Def ARRET
    unsigned char Exception :3;                 // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char u1Spare : 1;
    uint8_t            u8Spare;                      // Unused

    int16_t            i16Consigne_Piscine_Reduit;   // Consigne reduit (chaud ou froid)

    int16_t            i16Consigne_Piscine_Normal;   // Consigne normal (chaud ou froid)
    int16_t            i16Consigne_Piscine_Confort;  // Consigne confort (chaud ou froid)

    int16_t            i16Consigne_Piscine_Horgel;   // Consigne temperature hors gel
    uint16_t            u16Time_Piscine_Sablier;      // Temps de la d�rogation

    int16_t            i16Consigne_Piscine_Sablier;  // Consigne pendant la d�rogation
    int16_t            i16Consigne_Piscine_Vacances; // Consigne temperature vacances
} S_MODE_PISCINE;                               // 16 Octets

typedef struct
{
    unsigned char Mode :4;                      // E_FONCT_PISCINE Def ARRET
    unsigned char Exception :3;                 // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char u1Spare : 1;
    uint8_t            u8Spare;                      // Unused

    int16_t            i16Consigne_Eau_Reduit;       // Consigne reduit (chaud ou froid)

    int16_t            i16Consigne_Eau_Normal;       // Consigne normal (chaud ou froid)
    int16_t            i16Consigne_Eau_Confort;      // Consigne confort (chaud ou froid)

    int16_t            i16Consigne_Eau_Froid;        // Consigne temperature en mode Froid
    uint16_t            u16Time_RegExt_Sablier;       // Temps de la d�rogation

    int16_t            i16Consigne_Eau_Sablier;      // Consigne pendant la d�rogation
    int16_t            i16Consigne_Eau_Vacances;     // Consigne temperature vacances
} S_MODE_REG_EXT;                               // 16 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DE PARAMETRAGE DE LA REGULATION (Stock�es en E2P)   ">

typedef struct
{
    uint16_t          bModeSecoursDefautPAC:1;        // Def OFF
    uint16_t          bChaudFroidSimultane:1;         // Def FAUX
    uint16_t          bConsoEnergyBallonSurZ2:1;      // Si le Ballon Tampon est > � max plancher alors conso sur Z2 si demande Z1
    uint16_t          bConsoPendantECS_PIS:1;         // Regulation Chauffage Pendant l'ECS ou Piscine
    uint16_t          bGestionCascade:1;              // def FAUX ; si VRAI alors on gere une Cascade de PAC (ie on est la Maitre)
    uint16_t          TypeRegul:3;                    // E_REGUL  def REGUL_DIRECTE
    uint16_t          bCirculateurPrimaireForce:1;    // En previon Mode Auto ou Forcee
    uint16_t          eGestionCirculateurPrimaire:4;  // E_GESTION_CIRCULATEUR
    uint16_t          TypeCirculateur:2;              // E_TYPE_CIRCULATEUR
    uint16_t          bGestionHeureEte:1;             //
//2
    uint16_t          TempNonChauffage:4;             // 0 = OFF sinon 15+valeur en�C soit de 16 � 30�C
    uint16_t          bGestionProductionParallele:1;  // Permet dans le cas d'esclave de faire de l'ECS ou Piscine sur V3V sur la maitre et du CHAUD ou FROID sur les esclaves
    uint16_t          numEsclave:3;                   // Num esclave si Regul Esclave
    uint16_t          bFonction1:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction2:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction3:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction4:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction5:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction6:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction7:1;                   // Activation de fonction (sans entr�e contact)
    uint16_t          bFonction8:1;                   // Activation de fonction (sans entr�e contact)
//4
    uint8_t          u8Consigne_Sablier_Dalle[10];   // Consigne de chauffage dalle en �C en 4 etapes
//14
    uint8_t          u8Time_Vacances;                // Duree des vacances en Jour
    int8_t          i8Text_Ref_Appoint;             // De -20�C � 40�C
    uint8_t          u8CTime_Vacances_Jour;          // Temps restant vacances en Jour (Mis dans les Params afin de faire la sauvegarde)
    uint8_t          u8CTime_Sablier_Dalle_Jour;     // Temps restant Chauffe Dalle en Jour (Mis dans les Params afin de faire la sauvegarde ; dernier jour perdu)
//18
    int8_t          i8HysteresisTextPlus;           //
    int8_t          i8HysteresisEauMoins;           //
    int8_t          i8HysteresisEauPlus;            //
//22
    uint16_t          InxAdaptationLoiDeau    :4;     // def 0 = False ; 1 � 14 = num�ro du contact ; 15 = AUTO ; Pour AutoConso dans l'id�al possibilit� de mettre le m�me contact que la consigne
    uint16_t          InxAdaptationConsigne   :4;     // def 0 = False ; 1 � 14 = num�ro du contact ; 15 = AUTO ; Pour AutoConso
    uint16_t          InxEJP                  :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxCascade              :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxFreeHeating          :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxDelestage :4;                // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxAbaissementConsigne  :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxTH1                  :4;     // def 0 = False ; 1 � 15 = num�ro du contact
//26
    uint16_t          InxTH2      :4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxMarcheArret:4;               // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxChaudFroid:4;                // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxMarcheArretGeneral :4;       // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxFonction4:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxFonction5:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxFonction6:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    uint16_t          InxFonction7:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
//30
    uint16_t          OutxCarter  :3;                 // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxRelevePAC:3;                // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxModeChaudFroid:3;           // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxInfoDefautPAC:3;            // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxChaudFroidVoie1:3;          // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxChaudFroidVoie2:3;          // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxInfoMarcheArret:3;          // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxFonction8:3;                // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxFonction9:4;                // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    uint16_t          OutxFonction10:4;               // def 0 = False ; 1 � 15 = num�ro du Tor en Sortie
//34
    uint8_t          bThermostatContactModeFroid:1;  // def 1; 0 si pas de mode froid; sinon 1
    uint8_t          bConfigCascade120R:1;
    uint8_t          bConfigThermostats120R:1;
    uint8_t          bThermostatModbusExterne:1;
    uint8_t          bSansSondeBallonTampon:1;
    uint8_t          u3Spare:3;

    uint8_t          u8Spare;
//36
} S_PARAM_PAC;                  // 36 octets


typedef struct
{
    union
    {
        struct  // Cas des Zones 1 � 8
        {
            unsigned char   TypeThermostat          :2;     // E_TYPE_THERMOSTAT
            unsigned char   NumSonde                :3;     // 0 � 7
            unsigned char   AdresseSonde            :3;     // Adresse de base de la sonde (pour diff�rentier les mod�les)

            unsigned char   bVerouillageConsigne    :1;     // Verouillage de la consigne VRAI / FAUX
            unsigned char   bArretZoneDefautSonde   :1;     // Arret de la zone en cas de d�faut sonde
            unsigned char   u6Spare1                :6;
        } zone;
        struct  // Cas des groupes d'eau (Zones 9 et 10)
        {
            unsigned char   TypeGestionFan          :2;     // E_TYPE_REGUL_VENTILATEUR_GAINABLE
            unsigned char   bFanForce               :1;     // Default : false
            unsigned char   TypeFan                 :2;     // E_TYPE_FAN
            unsigned char   u2Spare                 :2;     //
            unsigned char   bGroupeActif            :1;     // Default : false

            unsigned char   u7VitesseMaxVentilateur :7;     // Vitesse maximum de ventilation (pour �viter les probl�matiques de bruit) (de 0 � 100)
            unsigned char   bSpare                  :1;     //
        } GroupeEau;
    } __attribute__((__packed__))  type_zone;				// 2

    union
    {
        struct  // Cas de zones autre que registre
        {
            unsigned char   GestionCirculateur      :4;     // E_GESTION_CIRCULATEUR
            unsigned char   bCirculateurForce       :1;     // Default : false
            unsigned char   bTypeCirculateur        :2;     // E_TYPE_CIRCULATEUR
            unsigned char   bCommandeEmetteur       :1;     // E_COMMANDE_EMETTEUR

            unsigned char   u8Spare2;                       //

            unsigned char   u8Spare3;                       //
        } plan_rad_vent;
        struct  // Cas des registres
        {
            unsigned char   u4GestionRegistre       :4;     // E_GESTION_REGISTRE (0 � 100 au pas de 10)
            unsigned char   bRegistreForce          :1;     // Default : false
            unsigned char   bCommandeRegistre       :1;     // E_COMMANDE_EMETTEUR
            unsigned char   u2Spare                 :2;

            int8_t              i8PertesDeCharges;              // Pertes de charges par les gaines (-90% � +90%)

            unsigned char   CorrectionDebitAir      :7;     // Correction du d�bit d'air (valeur max de ventilation pour la zone)
            unsigned char   bActivationCorrection   :1;     // Activation de la correction du d�bit d'air
        } gainable;
    } __attribute__((__packed__)) type_emetteur;			// 3

    unsigned short          NumVoieMZ               :3;     // E_NUM_VOIE_OF_BOARD
    unsigned short          NumCarteMZ              :3;     // E_TYPE_CARTE
    unsigned short          TypeEmmetteur           :3;     // E_TYPE_ZONE
    unsigned short          u7VolumePiece           :7;     // Volume de la pi�ce � 5m3 pr�s (jusqu'� 200m3) ; cas r�gul directe 2 zones pourcentage de chaque zone

    unsigned char           bModeChaud              :1;     // Default : true
    unsigned char           bModeFroid              :1;     // Default : false
    unsigned char           u2RattachementGroupe    :2;     // E_RATTACHEMENT
    unsigned char           u4ConsigneTeauFroid     :4;     // Temp�rature de d�part d'eau pour fonction rafraichissement (7�C � 22�C)
    // Hysteresis
    int8_t                      i8HysteresisMoins;
    int8_t                      i8HysteresisPlus;

    uint8_t                      u8LoiDeau[6];       // Loi d'eau
    uint8_t                      u8NomZone[10];      // Nom de la zone max : 10 caract�res
    // Spare
    uint8_t                      u8Spare[6];
} __attribute__((__packed__)) S_PARAM_ZX;       // 32 Octets

// Parametres de l'ECS
typedef struct
{
	unsigned char Heure_Legionel:5;             // Def 1H
	unsigned char Jour_Legionel:3;              // Def Lundi
	uint8_t            Time_ECS_Thermo;              // Def 90 min
	uint8_t            Time_Bascul_V3V_ECS;          // Def 120 sec

	unsigned char bAntiLegionnel:1;             // Def FAUX
	unsigned char bModeGestionHysteresis:1;     // Def Faux = Entr�e ON ; True = Entr�e OFF
	unsigned char u2TypeEchangeur:2;            // Enum E_TYPE_ECHANGEUR PLAQUE / BAIN MARIE / SERPENTION
	unsigned char bTypeAppointECS:1;            // Par Defaut il y a Appoint avec Resistance sur Ballon ECS : ELEC_ECS ou ELEC_PAC
	unsigned char bSolaire:1;                   // Def FAUX si Vrai prend entr�e bSolaire en compte pour Activer l'ECS
	unsigned char bLogiqueSolaire : 1;          // si VRAI alors la logique bSolaire est invers�e (Contact bSolaire FAUX autorise la Production ECS)
	unsigned char bCouplageEJP  : 1;            // FAUX si EJP alors ECS fonctionne toujours sinon ECS est Coupl� avec EJP

	unsigned char u2PW_Echangeur    :2;         // Enum E_PW_ECHANGEUR  8KW  12KW  16KW  20KW
	unsigned char u6PW_Brin         :6;         // Unit� 100 Watts de 1KW � 4 KW

	unsigned char u4DeltaLoiDeauSimultanee :4;  // (de 0 � 15 T�C )Si Production Simultan�e ECS et Chauffage alors R�duction des loi d'eau pour favoriser l'ECS
	unsigned char bGestionSimultanee       :1;  // Autorise la production ECS et �galement les Zones avec un decalage de loi d'eau
	unsigned char u3MiniOuvertureVanne     :3;  // 0 = pas de limite chauffage ouverture 70% ; 1 = 30%; ... ; 7=90% Mini Ouverture Vanne m�langeuse ECS ou PW mini si simultan�e (le compl�ment � 100% reste pour les zones ou Piscine )
												// La vanne est obligatoirement celle de la carte ECS

	int8_t            i8HysteresisECSMoins;         //
	int8_t            i8HysteresisECSPlus;          //

	unsigned char bAppointECS   :1;             //
	unsigned char bBouclageECS  :1;             //
	unsigned char u2TpsFinSimu  :2;             // 0 = 1h; 1 = 2h; 2 = 3h; 3 = pas de fin
	unsigned char u4Spare       :4;             //

	uint8_t 	  u8Spare[3];
} S_PARAM_ECS;                                      // 12 Octets


typedef struct
{
	unsigned char Time_Bascul_V3V_PISCINE;

	unsigned char Type_Gestion_V3V  :1;         // E_TYPE_GESTION_V3V
	unsigned char bConfort          :1;         // False = Normal ; True = trois niveaux de confort
	unsigned char PrioritePiscine   :2;         // E_PRIORITE_PISC Def PISCINE , ajout du simultan�e
	unsigned char NumCarteMZ        :2;         // 0 ==> sortie 5 de la carte N� 1 ;  1 ==> sortie 5 de la carte N�2;   2 ==> sortie 5 de la carte N�3
	unsigned char bAutorisationPiscineEJP:1;    // Autorisation de la pisicne en EJP
	unsigned char bAutorisationPiscineReleve:1; // Autorisation de la piscine en releve chaudiere

	int16_t            i16ConsigneDepartEauPiscine;  //

	int8_t            i8HysteresisEauMoins;         //
	int8_t            i8HysteresisEauPlus;          //

	unsigned char u4DeltaLoiDeauSimultanee :4;  // (de 0 � 15 T�C )Si Production Simultan�e ECS et Chauffage alors R�duction des loi d'eau pour favoriser l'ECS
	unsigned char bGestionSimultanee       :1;  // Autorise la production ECS et �galement les Zones avec un decalage de loi d'eau
	unsigned char u3MiniOuvertureVanne     :3;  // 0 = pas de limite chauffage ouverture 70% ; 1 = 30%; ... ; 7=90% Mini Ouverture Vanne m�langeuse ECS ou PW mini si simultan�e (le compl�ment � 100% reste pour les zones ou Piscine )
												// La vanne est obligatoirement celle de la carte ECS
	unsigned char u8Spare;
} S_PARAM_PISCINE;                                 // 8 Octets


typedef struct
{
    unsigned char   bModeFroid : 1;                 // Def Faux
    unsigned char   bModeChaud : 1;                 // Def Faux
    unsigned char   u6Spare : 6;                    // Def Faux

    uint8_t              u4ConsigneEauFroid : 4;         // Temp�rature de d�part d'eau pour fonction rafraichissement en �C
    uint8_t              u4Spare : 4;

    uint8_t              u8LoiDeau[6];                   //
} S_PARAM_REG_EXT;                                  // 8 Octets

// Parametres de la carte Frigo
typedef struct
{
	unsigned char Type_Degivrage  :1;           // E_TYPE_DEGIVRAGE def Normal / Rapide
	unsigned char Type_Liaison    :1;           // E_TYPE_LIAISON   def Normal / Longue
	unsigned char Reduc_PW        :3;           // E_REDUC_PW  def 0 � R7
	unsigned char bModeBoostDemarrage: 1;       // Permet de partir sur un palier plus �lev� au demarrage
	unsigned char u2NiveauSilence :2;           // Choix du niveau de r�duction de bruit (0 = 80%; 1 = 70%; 2 = 30%; 3 = 50%)

	uint8_t            u8Spare;
	uint16_t            u16Spare;
} S_PARAM_FRIGO;                                    // 4 Octets

typedef struct
{
	unsigned char Langue :3;                // E_LANGUE
	unsigned char u5Spare:5;
	uint8_t u7Luminosite :7;
	uint8_t bSpare :1;
	uint8_t u8PositionX;
	uint8_t u8PositionY;
} S_PARAM_UTILISATEUR;                          // 4 Octets

// Liste des contacts
typedef struct
{
    uint8_t  Ste_Inst[15];            // Societe de l'installateur
    uint8_t  Nom_Inst[15];            // Nom de l'installateur
    uint8_t  Tel_Inst[15];            // Num telephone installateur
    uint8_t  Port_Inst[15];           // Num portable installateur
    uint8_t  Email_Inst[30];          // Email installateur
    uint16_t  u16Spare;
} S_PARAM_CONTACT;               // 92 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DES DEMANDES VERS FRIGO   ">

typedef union
{
    uint64_t u64val;                       // 8 Octets Max
    struct
    {
        uint8_t  bCompresseurAdemarrer :1;       // Compresseur avec le moins de temps de fonctionnement; 0 = Compresseur 1; 1 = Compresseur 2
        uint8_t  bModeRafraichissement :1;       // Choix du mode de rafraichissement (freecooling ou froid)
        uint8_t  u6Spare :6;
        uint8_t  u8Spare;
        uint16_t  u16Spare1;
        int16_t  i16ConsigneTeauFroid;           // Consigne sur le ballon tampon froid captage
        int16_t  i16BallonTamponFroid;           // Ballon tampon froid sur le circuit captage (chaud / froid simultan�)
    } Geo;
    struct
    {
        int16_t  i16ConsigneTeauFroid;           // Consigne sur le ballon tampon froid captage
        int16_t  i16BallonTamponFroid;           // Ballon tampon froid sur le circuit captage (chaud / froid simultan�)
        uint8_t  bModeRafraichissement :1;       // Choix du mode de rafraichissement (freecooling ou froid)
        uint8_t  u7Spare :7;
        uint8_t  u8Spare;
        uint16_t  u16Spare1;
    } geoinverter;
    struct
    {
        int16_t  i16TeauEcsMilieu;
        int16_t  i16TeauEcsBas;
        int16_t  i16TeauPiscine;
        uint16_t  Spare;
    } Cairox;
    struct
    {
        int16_t  i16TeauEcsBas;
        uint16_t  u16Spare1;
        uint16_t  u16Spare2;
        uint16_t  u16Spare3;
    } ZuranBaguio;
    struct
    {
        uint8_t bPumpDown_V4V    :1;
        uint8_t u7Spare          :7;
    } Ajpac;
    struct
    {
        uint64_t FuturSupplementPhoenix;
    } phoenix;
    struct
    {
        uint64_t FuturSupplementArktea;
    } arktea;
}S_DEMANDE_SUPPLEMENT;          // 8 Octets

typedef struct
{
    unsigned char           Demande:4;          // E_DEMANDE_FRIGO
    unsigned char           bDerogationPression : 1;
    unsigned char           TypeRegul:3;        // Type de Regul de la PAC (Ballon ou BCP ou Directe...)

    unsigned char           bPacOn : 1;         // Si PAC OFF general ==> a faire sur GEO pour stopper le forcage des circulateurs
    unsigned char           Reduc_PW:3;         // E_REDUC_PW
    unsigned char           Appoint_Encours:1;  // Def FAUX, VRAI si utilisation appoint
    unsigned char           bShuntTempo:1;      // Pour faciliter les Tests
    unsigned char           bModeTestPAC : 1;   // si Vrai alors on est en mode Test PAC
    unsigned char           u1Spare : 1;

    unsigned char           ParamTestCps : 3;   // Reserve : Utilise pour les tests carte Frigo   Bit0: test detendeur  Bit1: test relais
    unsigned char           bCirculateurPrimaireForce:1;
    unsigned char           eGestionCirculateurPrimaire:4;

    unsigned char           u3ModeTest      :3; // Mode de AJPAC ???
    unsigned char           bModeSilencieux :1; // Issu de sParam_Frigo et de la Programmation du mode Silence
    unsigned char           u2TypeEchangeur :2; // Enum E_TYPE_ECHANGEUR_ECS
    unsigned char           u2PW_Echangeur  :2; // Enum E_PW_ECHANGEUR_ECS

    unsigned char           PalierTest ;        // utilise pour d�terminer le palier
    unsigned char           TestCode ;          // Mode 1 ou 2 ou 3

    unsigned char           bAppoint1:1;
    unsigned char           bAppoint2_3:1;
    unsigned char           bDerogPressionBP:1;
    unsigned char           bSimultaneECS : 1;
    unsigned char           bSimultanePiscine : 1;
    unsigned char           u3Spare:3;

    unsigned char           Spare ;             // 2        8 Octets
    S_DEMANDE_SUPPLEMENT    sSupplementPAC;     // 8        16 Octets

} S_DEMANDE_FRIGO;                              // 16 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURE DES STATUTS DE FONCTIONNEMENT DE LA REGULATION (non stock�es) ">

// Statut des In TOR en fonction du param�trage
typedef struct
{
	// Carte REG
	uint16_t          bAdaptationLoiDeau : 1;        // report du sInTor choisi
	uint16_t          bAdaptationConsigne: 1;        // report du sInTor choisi
	uint16_t          bTorEJP:1;                     // report du sInTor choisi
	uint16_t          bTorCascade:1;                 // report du sInTor choisi
	uint16_t          bTorFreeHeating:1;             // report du sInTor choisi
	uint16_t          bTorDelestage :1;              // report du sInTor choisi
	uint16_t          bTorAbaissementConsigne :1;    // report du sInTor choisi
	uint16_t          bTorTH1 :1;                    // report du sInTor choisi

	uint16_t          bTorTH2 :1;                    // report du sInTor choisi
	uint16_t          bTorMarcheArret:1;             // report du sInTor choisi
	uint16_t          bTorChaudFroid:1;              // report du sInTor choisi
	uint16_t          bTorMarcheArretGeneral:1;      // report du sInTor choisi
	uint16_t          bTorFonction4:1;               // report du sInTor choisi
	uint16_t          bTorFonction5:1;               // report du sInTor choisi
	uint16_t          bTorFonction6:1;               // report du sInTor choisi
	uint16_t          bTorFonction7:1;               // report du sInTor choisi

	uint16_t          u16Spare;
} S_FONCTION_IN_TOR;                                  // 4 Octets

// Demandes Out TOR
typedef struct
{
	// Carte REG
	uint16_t          bCarter:1;                // etat de la demande
	uint16_t          bRelevePAC:1;             // "
	uint16_t          bModeFroid:1;             // False = Chaud ; True = Froid
	uint16_t          bInfoDefautPAC:1;         // "
	uint16_t          bChaudFroidVoie1:1;       // "
	uint16_t          bChaudFroidVoie2:1;       // "
	uint16_t          bInfoMarcheArret:1;       // True = marche d'au moins un compresseur ; false = arr�t des compresseurs
	uint16_t          bFonction8:1;             // "
	uint16_t          bFonction9:1;             // "
	uint16_t          bFonction10:1;            // "
	uint16_t          u2PW_Elec :2;             // Puissance appoint electrique
	uint16_t          u4Spare :4;
} S_FONCTION_OUT_TOR;                          // 2 Octets

// Les Statuts de fonctionnement
typedef struct
{
	uint16_t              S_Mode:5;                   // E_STATUT_PAC ( REG_III ECS et PISCINE sont en bit 3 et bit 4 pour un retour de statut simultan�)
	uint16_t              Appoint:2;                  // E_APPOINT_CHAUFFAGE (REG_III passe de 3 � 2 bits)
	uint16_t              ModifConfig:1;              // Vrai si modification de la config
	uint16_t              ModifConfigSimple:1;        // Vrai si modification de la config de REG partie TYPE_GENERAL
	uint16_t              Mode_Secours:1;             // Def Faux ; Vrai servira � l'affichage
	uint16_t              Exception:3;                // E_STATUT_EXCEPTION
	uint16_t              Test :2;                    // E_STATUT_TEST
	uint16_t              bDerogationPression:1;      // Pression d'Eau

	uint16_t              u16CTime_Sablier_Dalle;     // Temps restant sablier dalle

	uint16_t              u16PWinstantaneeProduite;   // Unit� = 10 W

	uint16_t              u16PWinstantaneeConsommee;  // Unit� = 10 W
	uint16_t              u16TpsMiseSousTension;      // Unit� = 1 Heure; depuis la derniere mise sous tension

	uint8_t              u8CTime_Vacances;           // Temps restant vacances en Jour
	uint8_t              u3TypeData : 3;             // Pour faire passer des datas de Debug
	uint8_t              u3RetourAddressePAC: 3;     // 0 = Maitre
	uint8_t              bDerogationPressionBP: 1;
	uint8_t              u1Spare: 1;                 // Spare

	S_FONCTION_IN_TOR  sFonctInxTor;            // 4 Octets
	S_FONCTION_OUT_TOR sFonctOutxTor;           // 2 Octets

	uint16_t              au16ListeErreurEnCoursREG[5];// Liste des erreurs en cours

	S_IN_TOR_REG    sInTor;                     // 4 Octets
	S_OUT_TOR_REG   sOutTor;                    // 2 Octets
	uint8_t              u8RetourModelePAC;
	uint8_t              u8Spare;                    //
	uint32_t             u32Spare;                   //
} S_STATUT_PAC;                                     // 40 Octets

typedef struct
{
	int16_t           i16ConsigneTeauPrimaire;  // Consigne general d'eau primaire
	int16_t           i16TeauDepart;            // Temp�rature d�part d'eau
	int16_t           i16TeauRetour;            // Temp�rature retour d'eau
	int16_t           i16TeauBallonTampon;      // Temp�rature du Ballon
	uint16_t            u16DebitPrimaire;         // d�bit d'eau L/mn
    uint16_t            u16In_Pression_Eau;               // Pression d'eau primaire
    uint8_t            u8ConsigneCirculateur;            // Consigne Circulateur
    uint8_t            u8RetourCirculateur;              // Retour Info Circulateur
    uint16_t            u16Spare1;                        // Spare
}S_STATUT_PRIMAIRE;                                 // 16 Octets

typedef struct
{
    int16_t            i16Tint;                          // Temp�rature de la Zone
    int16_t            i16ConsigneTint;                  // Consigne de la zone
    int16_t            i16ConsigneTeau;                  // Temp�rature d�part d'eau
    int16_t            i16TeauDepart;                    // Temp�rature d�part d'eau
    int16_t            i16TeauRetour;                    // Temp�rature retour d'eau
    uint16_t            u16Debit;                         // d�bit d'eau L/mn
    uint16_t            u16CTime_Sablier;                 // Temps restant de la d�rogation
    uint8_t            u8ConsigneVanneMelange;           // Consigne vanne de m�lange
    uint8_t            u8ConsigneCirculateur;            // 0 = Arret si > � 0 alors consigne PWM ou Relais = ON

    uint8_t            u8RetourCirculateur;
    uint8_t            u4Mode_RF : 4;
    uint8_t            bTorThermostat:1;                 // est affect� suivant le numero d'entr�e contact voir (Param_Zx)
    uint8_t            bDemandeZoneGainable:1;           // Vrai si une demande de zone group�e
    uint8_t            u2Spare : 2;

    uint8_t            u8ConsigneFanCassette;            // Commande des ventilateurs des gainables (Groupe A et B)

    // si pas suffisant alors il faudra le mettre en oeuvre ici et egalement a minima les exceptions sur ECS piscine Regext ()
    // il s'agit d'un statut de la PAC struct�e et donc ne prendre que l'info pour sa PAC
    uint8_t            Mode :4;                          // E_FONCT_ZX
    uint8_t            Exception :3;                     // E_FONCT_EXCEPTION
    uint8_t            u1Spare :1;                       //
} S_STATUT_ZX;                                      // 20 Octets


typedef struct
{
    int16_t            i16TeauMilieu;                // Temp�rature ECS Milieu
    int16_t            i16TeauBas;                   // Temp�rature ECS Bas
    uint16_t            u16CTime_Sablier;             // Temps restant de la d�rogation
    int16_t            i16TempDepart;                // Temp�rature ECS Depart Voie 1
    int16_t            i16TempRetour;                // Temp�rature ECS Retour Voie 1
    uint8_t            u8ConsigneCirculateur;        // 0 = Arret ; > 0 alors ON ou PWM Voie 1
    uint8_t            u8ConsigneVanneMelange;       //

    uint16_t            bOutTorV3V_ECS        : 1;    // Sortie TOR
    uint16_t            bOutTorAppoint_ECS    : 1;    // Sortie TOR
    uint16_t            bOutTor_Circulateur   : 1;    // Sortie TOR
    uint16_t            bOutTor_Spare1        : 1;    // Sortie TOR
    uint16_t            bOutTor_Spare2        : 1;    // Sortie TOR
    uint16_t            bInTorECS_Solaire     : 1;    // Entr�e pour r�gulation
    uint16_t            bInTorECS_CompteurEau : 1;
    uint16_t            bInTorECS_Spare       : 1;
    uint16_t            bInTorECS_Spare1      : 1;
    uint16_t            Exception             : 3;    // E_FONCT_EXCEPTION reel de la Reel
    uint16_t            u4Spare               : 4;

    uint16_t            i16ConsigneECS;

} S_STATUT_ECS;                                 // 16 Octets


typedef struct
{
    int16_t            i16ConsignePiscine;           // Consigne Piscine
    int16_t            i16TeauPiscine;               // Temp�rature Piscine
    uint16_t            u16CTime_Sablier;             // Temps restant de la d�rogation
    uint8_t            u8ConsigneVanneMelange;       //
    uint8_t            bOutTorV3V_Piscine    : 1;    // Si simultan� -> circulateur; sinon -> V3V
    uint8_t            bInTor_Piscine        : 1;    //
    uint8_t            Exception             : 3;    // E_FONCT_EXCEPTION reel de la Reel
    uint8_t            bOutTorCirculateur    : 1;    // Mettra en fonctionnement le Relais 5 et le PWM 5 de la carte concern�e
    uint8_t            u2Spare               : 2;    //
} S_STATUT_PISCINE;                             // 8 Octets

typedef struct
{
    int16_t            i16ConsigneTeau;              // Consigne Temp�rature Eau
    uint16_t            u16CTime_Sablier;             // Temps de la d�rogation
    uint8_t            Mode      :4;                 // E_FONCT_xxx reel de la Regul
    uint8_t            Exception :3;                 // E_FONCT_EXCEPTION reel de la Reel
    uint8_t            u1Spare   :1;                 // E_FONCT_EXCEPTION reel de la Reel

    uint8_t            u8Spare;
    uint16_t            u16Spare;

} S_STATUT_REG_EXT;                             // 8 Octets

typedef struct
{
    uint32_t           u32TpsCompresseur1;           // Sec
    uint32_t           u32TpsCompresseur2;           // Sec
    uint32_t           u32NbCycleCompresseur1;       // Unit� 1
    uint32_t           u32NbCycleCompresseur2;       // Unit� 1
    uint32_t           u32TpsMisesousTensionTotal;   // Sec
} S_STATUT_TPS_FONCT;                           // 20 Octets  Sauvegarde en E2P

typedef union
{
    struct
    {
        uint8_t u8OperatingDemande:4;        // F_Arret/F_Chaud/F_Froid [F_Secours]
        uint8_t u8OperatingMode:4;           // ARRET MARCHE AUTO        // Pas utilis�
        uint8_t u8NbPacCascadeTotale:4;      // Nombre de PAC dans la cascade (Maitre Inclus)
        uint8_t u8NbPacCascadeDispo:4;       // Nombre de PAC Dispo
        uint8_t u8PacInterrogee:4;           // Il s'agit de la PAC interrog�e en DEMANDE et STATUT
        uint8_t u8PacStructee:4;             // PMA a faire permettra de recup�rer les donn�es de la PAC esclave et de les visualiser sur IHM mettre
        uint8_t u8OperatingPW;               // Correspond au nombre de PAC en demande (voir appoint Elec)
        int8_t i8OperatingDeltaDePAC;       // Nombre de PAC � activer ou d�activer
        uint8_t u8PacPresente;               // 1 bit par PAC (bit 0 = Maitre)
        uint8_t u8PacEnMarche;               // A faire Nombre de PAC En Marche ==> a faire 1 bits par PAC pour avoir un etat des PACs qui fonctionnent
        uint8_t u8Spare;                     // Spare
    } maitre;
    struct
    {
        S_MODELE_PAC maPAC;             // Attention ne doit faire 8 ( m�me taille STATUT_REGUL)
    } esclave;
} S_STATUT_REGUL_ESCLAVE;

// Les Statuts pour faire du Debug de fonctionnement
typedef struct
{
	uint32_t             u32Debug1;
	uint32_t             u32Debug2;
	uint32_t             u32Debug3;
	uint32_t             u32Debug4;
	uint32_t             u32Debug5;
	uint32_t             u32Debug6;
	uint32_t             u32Debug7;
	uint32_t             u32Debug8;
} S_STATUT_DEBUG;

// Les Statuts pour faire du Debug de fonctionnement
typedef struct
{
    S_STATUT_PAC            sStatut_PAC;            // 40
    S_STATUT_PRIMAIRE       sStatut_Primaire;       // 16
    S_STATUT_ZX             sStatut_Zx[2];          // 40
    S_STATUT_ECS            sStatut_ECS;            // 16
    S_STATUT_PISCINE        sStatut_Piscine;        //  8
    S_STATUT_REG_EXT        sStatut_RegulExt;       //  8
    S_STATUT_TPS_FONCT      sStatut_TpsFonct;       // 20
    S_STATUT_REGUL_ESCLAVE  sStatut_RegulEsclave;   //  8
    S_DATE                  sDate;                  //  8
    S_DEMANDE_FRIGO         sDemandeFrigo;          // 16
    S_STATUT_DEBUG          sStatut_Debug;          // 32
} S_CYCLIQUE_ETHER_REG_REGUL_T1;                    // 212 Octets


// Les Statuts pour faire du Debug de fonctionnement
typedef struct
{
    S_STATUT_ZX             sStatut_Zx[NB_ZONE];    // 160  8 Voies de 3 � 10
    uint8_t                      u8TypeDataDebug ;       //   1
    uint8_t                      u8Spare1 ;              //   1
    uint8_t                      u8Spare2 ;              //   1
    uint8_t                      u8Spare3 ;              //   1
    S_STATUT_DEBUG          sStatut_Debug;          //  32
} S_CYCLIQUE_ETHER_REG_REGUL_T2;                    // 196 Octets

typedef struct
{
	unsigned char Niveau_pile;
	char          Niveau_Reception;

	unsigned char Tamb_Zx_Modif:1;
	unsigned char Consigne_Zx_Modif:1;
	unsigned char Erreur_RF:1;          // info pour carte r�gulation
	unsigned char Valid_Zx:1;           // Zx Associ�es VRAI/FAUX
	unsigned char Init_Zx:1;            // Association ou dissociation  En cours  VRAI pendant l'INIT ; FAUX apr�s et  FAUX sur timeout 2 minutes
	unsigned char Transmis_Zx: 1 ;      // FAUX = Sonde non transmise -> valeurs contenues dans l'antenne non valides
	unsigned char bAssociationMultiple:1;
	unsigned char Spare2:1;

	unsigned char LastMinuteReceived;   // Cpt en minutes derni�re Reception RF de la Zone
} S_STATUT_RF;

typedef struct
{
	int16_t            Tamb_Zx;
	int16_t            Consigne_Zx;
	S_STATUT_RF   sStatutRF;
} S_RETOUR_RF;

typedef struct
{
  uint8_t    Frequence;
  unsigned char bCompresseur1On :1;
  unsigned char bCompresseur2On :1;
  uint8_t    Palier:6;
}  S_STATUT_COMPRESSEUR;

typedef struct
{
  unsigned char Mode_Sonde:3;      // E_MODE_SONDE  Def MODE_RIEN
  unsigned char Mode_Prod:3;       // E_MODE_PROD def MODE_ARRET
  unsigned char Erreur_Reg:1;      // d�faut carte de r�gulation
  unsigned char Erreur_Bus:1;      // d�faut de r�ception g�rer par Watts
  unsigned char Icone_Heat_Cool:1; // Affichage ic�ne Heat Cool Off / On
  unsigned char Icone_Auto:1;      // Affichage ic�ne Auto Off / On
  uint8_t Spare:6;
  int16_t  Consigne_Zx;                 // 1/10 de �C  199 = 19,9 �C
} S_DEMANDE_RF;

typedef struct
{
  int16_t  i16ConsigneEau;
  unsigned char bDefaut:1;
  unsigned char u7Spare:7;
  uint8_t Spare;
} S_SURVEILLANCE_BALLON;

//typedef struct //4 bytes
//{
//  uint32_t u32val;
//  struct
//  {
//    uint8_t bCirculateur_Off        :1;    // Circulateur Arrete sur demande.
//    uint8_t bDefautRotorBloque      :1;    // Rotor Bloque -> Arret du circulateur
//    uint8_t bDefautUnderVoltage     :1;    // Tension Alimentation Circulateur Trop Basse -> Arret du circulateur
//    uint8_t bRPMSensorFault         :1;    // Capteur de Rotation HS, vitesse circulateur � 14% du minimum
//    uint8_t bWarningUndervoltage    :1;    // Tension Alimentation Circulateur < 195V
//    uint8_t bCirculateurOK          :1;    // Pas de defaut circulateur
//    uint8_t bdummy1                 :1;    // non utilise
//    uint8_t bdummy2                 :1;    // non utilise
//
//    uint8_t u8Commande;                    // Commande PWM envoyee au circulateur (0-100%)
//    uint8_t u8Power;                       // Puissance renvoyee par le circulateur (0-100%)
//    uint8_t u8FeedBack;                    // PWM renvoye par le Circulateur (0-100%)
//  };
//
//}S_GRUNDFOS_STATUT_ZUBA;

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DES ENERGIES et HISTORIQUES DE LA REGULATION (Stock�es en Flash)  ">

// Energie produite stock�es en FLASH
typedef struct
{
    uint16_t  Chaud[24];
    uint16_t  Froid[24];
    uint16_t  ECS[24];
    uint16_t  Piscine[24];
    uint8_t  Pointeur;
    uint8_t  u8Dispo;
    uint16_t  u16Spare;
} S_ENERGIE_PROD;           // 196 Octets

// Energie consommee par cat�gorie stock�es en FLASH
typedef struct
{
    uint16_t  Chaud[24];
    uint16_t  Froid[24];
    uint16_t  ECS[24];
    uint16_t  Piscine[24];
    uint16_t  ElecChaud[24];
    uint16_t  ElecECS[24];
    uint16_t  EauECS[24];         // Litres
    uint8_t  Pointeur;
    uint8_t  u8Dispo;
    uint16_t  u16Spare;
} S_ENERGIE_CONSO;          // 340 Octets

// Cumul d'energie consomm�e stock�es en FLASH
typedef struct
{
    uint32_t Annee_Chaud;
    uint32_t Annee_Froid;
    uint32_t Annee_ECS;
    uint32_t Annee_Piscine;
    uint32_t Annee_ElecChaud;
    uint32_t Annee_ElecECS;
    uint32_t Annee_EauECS;
    S_DATE Annee_Date;
    uint32_t Partiel_Chaud;
    uint32_t Partiel_Froid;
    uint32_t Partiel_ECS;
    uint32_t Partiel_Piscine;
    uint32_t Partiel_ElecChaud;
    uint32_t Partiel_ElecECS;
    uint32_t Partiel_EauECS;
    S_DATE Partiel_Date_Reset;
    uint32_t Debut_Chaud;
    uint32_t Debut_Froid;
    uint32_t Debut_ECS;
    uint32_t Debut_Piscine;
    uint32_t Debut_ElecChaud;
    uint32_t Debut_ElecECS;
    uint32_t Debut_EauECS;
    S_DATE Debut_Date;
} S_ENERGIE_CUMUL;          // 108 Octets

// Cumul d'energie consomm�e stock�es en FLASH
typedef struct
{
	S_ENERGIE_PROD  Prod_24H;
	S_ENERGIE_PROD  Prod_24J;
	S_ENERGIE_PROD  Prod_12M;
	S_ENERGIE_CONSO Conso_24H;
	S_ENERGIE_CONSO Conso_24J;
	S_ENERGIE_CONSO Conso_12M;
	S_ENERGIE_CUMUL Cumul_Produite;
	S_ENERGIE_CUMUL Cumul_Consommee;
	S_DATE          Date;
	uint16_t              Spare;      // Alignement
	unsigned short  u16CRC;
} S_ENERGIE;                    // 1836 Octets

typedef struct
{
    uint16_t      Defaut[50];
    S_DATE  Date[50];
    uint8_t      Pointeur;
    uint8_t      u8Spare;
    uint16_t      u16Spare;
} S_HISTO_ERR;              // 504 Octets

// Historique de fonctionnement stock�es en FLASH
typedef struct
{
    uint8_t Data[512];
} S_LISTE_HISTO;            // (2 page de 256 octets) 512 Octets * 4096 enregistrements en Flash

// Historique de fonctionnement non stock�es permet � l'IHM de venir recup�rer l'histo de fonctionnement
typedef struct
{
    uint8_t      u8TintZx[8];            // en 1/10 �C de 5�C � 30�C pour �tre en u8
    int16_t      i16Text;                // en 1/10 �C
    int16_t      i16TeauDepartPrimaire;
    int16_t      i16TeauRetourPrimaire;
    uint16_t      ModePAC     :5;
    uint16_t      Exception   :3;
    uint16_t      bAppointECS :1;
    uint16_t      bAppointPAC :1;
    uint16_t                  :6;
} S_ENREG_STATUT;                   // 16 Octets

typedef struct
{
    S_ENREG_STATUT  sStatutRegul[360];          // Doit Contenir le Statut PAC et les 2 Appoints (PAC et ECS)
    uint16_t              u16IndexReadWrite;          //
    uint8_t              u8TimeRecord;               // en Sec
    uint8_t              bComplet : 1;               // VRAI si on a fait un remplissage complet (ie 360 valeurs)
    uint8_t              bRecupEncours : 1;          // pour �viter 2 recup simultan�es (il y a un Timeout sur la r�cup si plus de 30 sec)
    uint8_t              u6Spare : 6;                //

} S_ENREG_REGUL;                                // 5764 = 16 Octets * 360 + 4 enregistrements en memoire
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO ZURAN BAGUIO   ">

typedef struct                  // Struture des donn�es qui reviennent par la RC MITSU
{
    uint16_t  Statut;                 //  0	Cyclique TR_E5 // Etat de fonctionnement                        ;;	"Bit 0 � 3 voir �3  ; Bit 4 � 7 (0=Arret,1=Refroidissement,2=Chauffage,3=Degivrage)";;	-	;;	 ;;	BA/ZU
    int16_t  Intensite;              //  1	Intensit� de service du compresseur (non remont� sur REG2)      ;;	0 a 50			;;	A			;;				;;	BA/ZU
    int16_t  Temps_Compresseur;      //  2	Temps cumul� de fonctionnement du compresseur(base 10)          ;;	0 a 9999		;;	10 heures	;;				;;	BA/ZU
    int16_t  Nb_Cycle_Compresseur;   //  3	Nombre de cycles de mise en marche du compresseur (base 100)    ;;	0 a 9999		;;	100 cycles	;;				;;	BA/ZU
    int16_t  T_Refoulement;          //  4	Temp�rature de refoulement (TH4)                                ;;	3 a 217			;;	�C			;;				;;	BA/ZU
    int16_t  T_TH6;                  //  7	Unit� ext�rieure temp�rature de tuyau 2 phases(TH6)             ;;	-39 a 88		;;	�C			;;				;;	BA/ZU
    int16_t  T_Aspiration;           //  8	Unit� ext�rieure temp�rature de tuyau d'aspiration (TH32)       ;;	-39 a 88		;;	�C		;;				;;	ZU
    int16_t  Text;                   //  9	Cyclique TR_E5 // Unit� ext�rieure temp�rature de l'air ext�rieur(TH7)  ;;	-39 a 88		;;	�C		;;				;;	BA/ZU
    int16_t  Freq_Compresseur;       //  16	Cyclique TR_E5 // Compresseur fr�quence de service                      ;;	  0 a 255			;;	Hz			;;				;;	BA/ZU
    int16_t  Freq_Cible;             //  17	Compresseur fr�quence Cible     								;;	0 a 255			;;	Hz			;;				;;	BA/ZU
    int16_t  Vitesse_Ventilateur1;   //  19	Unit� ext�rieure vitesse ventilateur 1							;;	0 a 9999		;;	Rpm			;;				;;	BA/ZU
    int16_t  Vitesse_Ventilateur2;   //  20	Unit� ext�rieure vitesse ventilateur 2							;;	0 a 9999		;;	Rpm			;;	��0�� s?affiche si l?unit� ext�rieure est de type � un seul ventilateur			;;	BA/ZU
    int16_t  Intensite_Primaire;     //  25	Courant primaire												;;	0 a 50			;;	A			;;				;;	BA/ZU
    int16_t  Tension_DC;             //  26	Tension de bus DC												;;	180 a 370		;;	V			;;				;;	BA/ZU
    int16_t  Capacite;               //  70	Unit� ext�rieure affichage de r�glage de capacit�				;;	9=35 ; 10=50 ; 11=60 ; 14=71 ; 20=100 ; 25=125 ; 28=140 ; 40=200 ; 50=250			;;				;;				;;	BA/ZU
    int16_t  Type;                   //  71	Unit� ext�rieure information de r�glage							;;	"Bit 4 � 7 (0= Monophas� PAC CH/FR  ; 1=Monophas� FROID seulement ; 2= Triphas� PAC CH/FR  ; 3=Triphas� FROID seulement ;)Bit 0 � 3 (0=STANDARD ; 1= Pour humidit� �lev�e)"			;;				;;				;;	BA/ZU
    int16_t  T_TH3;
    int16_t  Autre;                  //  Autre (non remont� sur REG2)
    int16_t  T63HS;                  //  14  Pression de saturation (HP R410) -39 � 88�C
    int16_t  LEVA;                   //  22  Ouverture d�tenteur A de 0 - 500
    int16_t  LEVB;                   //  23  Ouverture d�tenteur B de 0 - 500
    int16_t  LEVC;                   //  24  Ouverture d�tenteur C de 0 - 500
    int16_t  T_HeatSink;             // 10 Temp�rature driver
    int16_t  T_Liquide2;             //  6	Unit� ext�rieure temp�rature Liquide MonoBloc                   ;;	3 a 217		;;	�C			;;				;;	MONOBLOC BA/ZU
}S_STATUT_MITSU;                // Total 48 bytes

typedef struct
{
    uint16_t      u16nombretrameInconnue;     //old sPalier_Fan
    int16_t      i16Resultat_Trame_Ihm_Sav;  //old 16Temp_Frigo_IGBT

    uint32_t     u32CodeErreurMitsu;

    uint8_t      u8CodeTrameInconnu;         //old sOut_Tor_Fan

    uint8_t      bTrameConnue :1;            //old 16Temp_Frigo_Spare
    uint8_t      bAcces_Com_SAV :1;          //old sOut_Tor_Frigo
    uint8_t      bTrame_SAV_IHM_Valide:1;
    uint8_t      u3SousTypePAC_Trouve : 3;   // On met le sous type de PAC trouve ( SOUS_TYPE_UNDEFINED, SOUS_TYPE_BAGUIO, SOUS_TYPE_ZURAN )
    uint8_t      u2TypeRegul_MITSU:2;

    uint16_t      u16Spare;
}S_INFO_TRAME_ZUBA;                     //12 bytes


typedef struct // 8 bytes
{
	uint16_t          i4Operating_Ability_Zuran   :4 ;
	uint16_t          u4IndexPente                :4 ;
	uint16_t          u4IndexDeltaTC              :4 ;
	uint16_t          bRegulNormal                :1 ;
	uint16_t          u3NbIterationTankInTank_ECS :3 ;
	uint8_t          u8SurchauffeRefoulement;
	uint8_t          u8SousRefroidissement;
	uint8_t          u8ConsigneEau_BaguioPP;
	uint8_t          u8Spare;
	uint16_t          u16Spare;
	//uint32_t         u32Spare;
}S_STATUT_FRIGO_ZUBA;                           // 8 bytes
 // </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO FAN AJPAC ">
typedef struct //2 bytes
{
	unsigned char PalierCompresseur1:5;     // def = 0  (0,..32)
	unsigned char         bCompresseur2     :1;     // Def OFF
	unsigned char :2;
	uint8_t Spare;
} S_DEMANDE_PW_AJPAC;

//typedef struct //2 bytes
//{
//   uint16_t  val;
//   struct
//   {
//      E_LISTE_PW        Pw : 4;           // E_LISTE_PW (MONO 10KW / MONO 16KW  / TRI 16KW /TRI 20KW)
//      unsigned char     Demarreur:1;
//      unsigned char     Compresseur2:1;
//      unsigned char     Spare2:2;
//      uint8_t                Spare;
//   };
//} S_TYPE_ELEC_PW_AJPAC;

typedef struct //4 bytes
{
    uint16_t  u16Position_Pulse_EEV410;
    uint16_t  u16Position_Pulse_EEV134;
}S_STATUT_EEV_AJPAC;


typedef struct // 8 bytes
{
    uint32_t u32Tps_Fonct_Compresseur_410;
    uint32_t u32Tps_Fonct_Compresseur_134;
}S_TPS_COMPRESSEUR_AJPAC;

typedef struct  //16 bytes
{
    uint8_t              u8Freq_Comp410;                 // 1    1

    unsigned char   u8_Comp134 :1;               // 1    2
    unsigned char   Palier_Comp410 :5;
    unsigned char   bDemarrageAutorise :1;
    unsigned char   bDegivrageEnCours :1;

    unsigned char   bArretUrgence :1;               // 1    3
    unsigned char   bCondition_Degivrage_1 :1;
    unsigned char   bCondition_Degivrage_2 :1;
    unsigned char   bCondition_Degivrage_3 :1;
    unsigned char   Spare1 :4;

    uint8_t              u8Fmin;                         // 1    4
    uint8_t              u8Fmax;                         // 1    5

    uint8_t              u8Modeval;                      // 1    6
    uint8_t              u8Mode_Comp;                    // 1    7
    uint8_t              u8Spare;                        // 1    8

    int16_t              i16Temp_HP410_Cible;            // 2    10
    int16_t              i16Temp_HP134_Cible;            // 2    12

    int16_t              i16Charge;                      // 2    14
    uint16_t              u16Spare;                       // 2    16
} S_STATUT_FRIGO_AJPAC;


/* * * * * * * * * * * * P O W E R * * * * * * * * * * * */
typedef struct //12 bytes
{
    uint16_t  u16U_Alim_AC;                           /* Tension AC issue de PW     */
    uint16_t  u16I_Alim_AC;                           /* Courant AC issu de PW      */
    uint16_t  u16U_Alim_DC;                           /* Tension DC issue de PW     */
    uint16_t  u16I_Alim_DC;                           /* Courant DC issu de PW      */
    uint16_t  u16U_Compresseur_1;                     /* Tension compresseur 1 (PW) */
    uint16_t  u16I_Compresseur_1;                     /* Courant compresseur 1 (PW) */
}  S_INFO_U_I_AJPAC;
//End AJPOWER

/* * * * * * * * * * * * F A N * * * * * * * * * * * */


typedef struct //2 bytes
{
	unsigned char TypeDetendeur : 1;
	unsigned char : 7 ;

	uint8_t u8Spare;
} S_CONFIG_FAN_AJPAC;

typedef struct // 28 bytes
{
    // Donnees FAN renvoyees vers REG                   // nb   Total
    S_OUT_TOR_FAN_AJPAC  sOutTorFAN;                    // 2    2   Retour Sorties TOR
    int16_t                   i16Text;                       // 2    4   Temperature externe
    int16_t                   i16Temp_TEV_IN;                // 2    6
    int16_t                   i16Temp_TEV_OUT;               // 2    8
    uint16_t                   u16In_Vitesse_Ventilateur_1;   // 2    10
    uint16_t                   u16In_Vitesse_Ventilateur_2;   // 2    12
    uint16_t                   u16Position_Pulse_EEV410BP;    // 2    14
    uint16_t                   au16ListeErreurEnCoursFAN[5];  // 10   24 Liste erreurs carte FAN
    uint32_t                  u32Spare;                      // 4    28
}S_RETOUR_FAN_AJPAC;

typedef struct      // 8 bytes
{
    // Donnees FRIGO renvoyees vers REG pour Demande � la FAN
    int16_t                      i16Consigne_Pulse_EEV410BP; // 2    2
    S_OUT_TOR_FAN_AJPAC     sOutTorFAN;                 // 2    4   Positionnement des Sorties TOR
    S_CONSIGNE_FAN_AJPAC    sConsigneVentilateur;       // 2    6   Consignes Vitesses des ventilateurs
    S_CONFIG_FAN_AJPAC      sConfigFan;                 // 2    8
}S_DEMANDE_FAN_AJPAC;


//End AJ-FAN
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO GEOTWIN   ">
typedef struct //4 bytes
{
	// CTN Erreurs
	unsigned char Erreur_Temp_BP1 : 1;
	unsigned char Erreur_Temp_BP2 : 1;
	unsigned char Erreur_Temp_ALL_PRI : 1;
	unsigned char Erreur_Temp_RET_PRI : 1;
	unsigned char Erreur_Temp_ALL_CAP : 1;
	unsigned char Erreur_Temp_RET_CAP : 1;
	unsigned char Erreur_Temp_T_EXT : 1;
	unsigned char Erreur_Temp_HP1 : 1;
	unsigned char Erreur_Temp_HP2 : 1;
	unsigned char Erreur_Temp_COND : 1;    // => 10 bits

	// CTN Alertes
	unsigned char Alerte_Temp_BP1 : 1;
	unsigned char Alerte_Temp_BP2 : 1;
	unsigned char Alerte_Temp_ALL_PRI : 1;
	unsigned char Alerte_Temp_RET_PRI : 1;
	unsigned char Alerte_Temp_ALL_CAP : 1;
	unsigned char Alerte_Temp_RET_CAP : 1;
	unsigned char Alerte_Temp_T_EXT : 1;
	unsigned char Alerte_Temp_HP1 : 1;
	unsigned char Alerte_Temp_HP2 : 1;
	unsigned char Alerte_Temp_COND : 1;    // => 10 bits

	// Pression Erreurs
	unsigned char Erreur_Pression_HP : 1;
	unsigned char Erreur_Pression_INT : 1;
	unsigned char Erreur_Pression_EAU : 1;
	unsigned char Erreur_Pression_BP : 1;  // => 4 bits

	// Pression Alertes
	unsigned char Alerte_Pression_HP : 1;
	unsigned char Alerte_Pression_INT : 1;
	unsigned char Alerte_Pression_EAU : 1;
	unsigned char Alerte_Pression_BP : 1;  // => 4 bits            TOTAL: 28bits

	unsigned char bCntDebitOverflow_PRI :1;
	unsigned char bCntDebitOverflow_CAP :1;
	unsigned char bExternalEEPROM_error :1;

	unsigned char dummy : 1;
} S_DEFAUT_GEO ;

typedef struct
{
    uint64_t u64Spare1;
    uint64_t u64Spare2;
    uint32_t au32CycleEnCoursCompresseur[NB_COMPRESSEUR_MAX];
    uint32_t au32CompteurCompresseurArret[NB_COMPRESSEUR_MAX];
} S_TPS_COMPRESSEUR_GEO;        //32 bytes

typedef struct //8 bytes
{
    int16_t  i16Temp_HP_Cible;
    uint16_t  u16Coef_Poly;
    uint16_t  u16Position_Pulse_EV;
    uint16_t  u16Position_Pulse_SP;
}S_STATUT_EEV_CIBLE_GEO;

typedef struct //8 bytes
{
    uint32_t u32PWInstCompresseur;       // puissance compresseur suivant table ert condition du Compresseur
    uint32_t u32PWInstCaptage;           // Puissance instantanee pris sur le captage en Watt
}S_INFO_CONSO_PAC_GEO;

typedef struct //2 bytes
{
	unsigned char bMachineOK :1;                 // Machine non op�rationnelle
	unsigned char bCycleRetourHuile :1;
	unsigned char bProblemeThermodynamique :1;   // PMA V019 sert � �courter le cycle ECS si plus possible
	unsigned char bCompresseur_1_OK :1;
	unsigned char bCompresseur_2_OK :1;
	unsigned char u3Spare :3;

	unsigned char u8Spare;
}S_STATUT_FRIGO_GEO;        // 2 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO CAIROX  ">
typedef struct
{
    int16_t  i16Tsonde1;         // Octet 3,4,5 ttt/1.6 en �C * 10 en 1/10�C
    //int16_t i16Text;            // Octet 32,33
    uint16_t  u16Defaut;          // Octet 34,35
    uint16_t  u16Palier;
    uint8_t  u8ModeCH_FR;        // Octet 28
    uint8_t  u8StatutCH_FR;      // Octet 37
    uint8_t  u8Defrost;          // Octet 31
    uint8_t  u8Spare;
    uint16_t  u16Spare;
}S_IMPROMAT_BRIEF_DATA;     //12 bytes


typedef struct
{
    int8_t              i8Operating_Ability_Zuran;
    int8_t              i8Palier_Test_Auto;

    unsigned char   bRegul_Normale :1;
    unsigned char   u7Spare : 7;

    int8_t              i8Table_Regul_Normale;   //TableDeltaPx

    int8_t              i8Table_Regul_Lente;     //TableDeltaTc
    uint8_t              u8Hyst_Test_Air;
    uint8_t              u8Hyst_Test_Eau;
    uint8_t              u8Type_Pac;

    uint8_t              u8Index_Pente;
    uint8_t              u8Index_Delta_Tc;
    uint16_t              u16Temps_Restant_MAL_Level;

    uint32_t             u32Spare;
}S_STATUT_FRIGO_CAIROX;                     //16 bytes

typedef struct
{
    unsigned char StatutPac : 1;    // Arret ou Marche
    unsigned char bDegivrage: 1;    // Vrai / Faux
    unsigned char bDefaut   : 1;    // Vrai / Faux
    unsigned char bInitUTI  : 1;    // OK   / False
    unsigned char u4Spare   : 4;    // Vrai / Faux
    uint8_t            u8Spare;
}S_STATUT_IMPROMAT_CAIROX;          //2 bytes
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO & RUKING PHOENIX / GEO INVERTER ">
typedef struct //16 bytes
{
    uint16_t  u16VersionDSP;              //_Add102;
    uint16_t  u16VersionTestDSP;          //_Add103;
    uint16_t  u16NA_Add104;
    uint16_t  u16NA_Add105;
    uint16_t  u16VersionHardware;          //_Add106;
    uint16_t  u16VersionEeprom;           //_Add107;

    bool bEepromVerifiedFlag : 1;   //_Add108
    unsigned char by7b_Spare : 7;
    uint8_t u8Spare;
    uint16_t  u16Spare;
}S_VERSION_INFORMATION_RUKING;

typedef struct //26 bytes
{
	bool bDSP_ChipReset : 1;            //_Add174Bit0;
	bool bDriveFault : 1;               //_Add174Bit1;
	bool bCompressorStartup : 1;        //_Add174Bit2;
	bool bCompressorRestartup : 1;      //_Add174Bit3;
	bool bCompressorRunning : 1;        //_Add174Bit4;
	bool bCompressorSpeedStable : 1;    //_Add174Bit5;
	bool bCompressorSpeedIncreasing : 1;//_Add174Bit6;
	bool bCompressorSpeedDecreasing : 1;//_Add174Bit7;

	bool bCompressorSpeedDroopProtection : 1;   //_Add174Bit8;
	bool bCompressorSpeedLimitProtection : 1;   //_Add174Bit9;
	bool bPFC_ON_OFF : 1;                       //_Add174Bit10;
	unsigned char Spare : 5;                    // i32NA_Add174Bit11_15;

	uint16_t  u16CompressorRunningSpeed;          //_Add175;
	uint16_t  u16CompressorPhaseCurrent;          //_Add176;
	uint16_t  u16AC_InputCurrent;                 //_Add177;
	uint16_t  u16AC_InputVoltage;                 //_Add178;
	uint16_t  u16DC_Voltage;                      //_Add179;
	uint16_t  u16IPM_Temperature;                 //_Add181;
	uint16_t  u16PFC_Temperature;                 //_Add182;
	uint16_t  u16CompressorU_PhaseCurrent;        //_Add184;
	uint16_t  u16CompressorV_PhaseCurrent;        //_Add185;
	uint16_t  u16CompressorW_PhaseCurrent;        //_Add186;
	uint16_t  u16DetectedSpeedByCurrentFrequency; //_Add187;
	uint16_t  u16DLT_Temperature;                 //_Add188;
}S_DRIVE_STATUS_INFORMATION;

typedef struct //12 bytes
{
    char Ruking_Model[12];
}S_RUKING_DRIVER_FRIGO;

typedef struct//22 bytes
{
	uint8_t      u8Fmin;                     // 1    1
	uint8_t      u8Fmax;                     // 1    2
	uint8_t      u8ConsignePompePuits;       // 1    3
	uint8_t      u8TypeRestriction;          // 1    4
	int16_t      i16Temp_HP_Cible[2];        // 4    8

	int16_t      i16MaxPressureHP_VS_RPM;    //2     10
	int16_t      i16MinCondensingTempVSEvap; //2     12
	int16_t      i16MaxCondensingTempVSEvap; //2     14

	uint8_t      u4Demande : 4;
	uint8_t      u3Reduction_PW : 3;
	uint8_t      bMachineOK : 1;

	uint8_t      bCycleRetourHuile :1;
	uint8_t      bProblemeThermodynamique : 1;
	uint8_t      bPreHeating : 1;
	uint8_t      bDegivrageEnCours : 1;
	uint8_t      u4Spare : 4;

	int16_t      i16ConsignePrimaire;
	uint16_t      u16Puissance_Produite;
	uint16_t      u16Puissance_Consommee;
}S_STATUT_FRIGO;

typedef struct   //32 bytes
{
	S_DRIVE_STATUS_INFORMATION      sDriveStatusInformation;// 26       26
	uint16_t  u16CompSpeedDemande;                //_Add300;          2       28
	uint16_t  u16CompStatorPreheatorCurrentDde;   //_Add303;          2       30

	bool bCompOnOff : 1;                //_Add299Bit0;
	bool bPFC_OnOff : 1;                //_Add299Bit1;
	bool bStatorHeatingOnOff : 1;       //_Add299Bit3;
	bool bClearFault : 1;               //_Add299Bit5;
	unsigned char Spare : 4;            //_Add299Bit6_7         1       31

	uint8_t u8Spare2;
}S_RETOUR_RUKING_RE;

typedef struct
{
	// Le sous-type + la puissance d�fini les propri�t� de la PAC nbcomp, GAZ, r�versibilit�, ...
	uint8_t u8NumeroSerie[12];               // A voir si m�me format que UI

	uint8_t u3SousType :3;                   // E_SOUS_TYPE_PHOENIX, E_SOUS_TYPE_GEOINV, ...
	uint8_t bReversible :1;
	uint8_t u4TypeGaz :4;                    // E_TYPE_GAZ

	uint8_t u7Puissance :7;                  // 0 -> 128KW
	uint8_t bSupply : 1;                     // MONO / TRI

	uint8_t u4DebitmetreCaptage :4;          // E_TYPE_DEBITMETRE
	uint8_t u4DebitmetreChauffage :4;        // E_TYPE_DEBITMETRE

	uint8_t eTypeCirculateurPrimaire :2;
	uint8_t eTypeVentiloCircCaptage :2;
	uint8_t bCirculateurPrimaireForce :1;
	uint8_t bCirculateurCaptageForce :1;
	uint8_t bFreecooling :1;
	uint8_t bSpare :1;

	uint8_t eTypeDeCaptage :2;               //E_TYPE_CAPTAGE_GEO;
	uint8_t u6Spare :6;

	uint8_t eGestionCirculateurPrimaire :4;
	uint8_t eGestionCirculateurCaptage :4;

	uint8_t u8Spare[12];

	uint16_t  u16CRC;
} S_MODELE_FRIGO;

typedef struct
{
	uint32_t u32TpsFonctC1;
	uint32_t u32TpsFonctC2;
	uint32_t u32NbCycleC1;
	uint32_t u32NbCycleC2;
} S_TPS_FONCTIONNEMENT_FRIGO;

typedef struct   //64 bytes
{
	S_MODELE_FRIGO sModele_FRIGO;                   //32
	S_RUKING_DRIVER_FRIGO sRukingModel_FRIGO;       //12
	S_TPS_FONCTIONNEMENT_FRIGO sTpsFonct_FRIGO;     //16
	uint8_t u8Spare[4];
} __attribute__((__packed__)) S_CONFIG_FRIGO;


typedef struct  //4 bytes
{
	uint16_t  u16Resultat_Trame_Ihm_Sav;
	uint16_t  u16RequestedRegister;
}S_INFO_TRAME_RUKING;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO ARKTEA">
typedef struct
{
	uint8_t      u4PuissanceDemandee : 4;
	uint8_t      u4Demande : 4;

	uint8_t      u3Reduction_PW : 3;
	uint8_t      u2StatutDriver : 2;
	uint8_t      u3Spare : 3;

	int16_t      i16ConsignePrimaire;
	uint16_t      u16Puissance_Produite;
	uint16_t      u16Puissance_Consommee;
}S_STATUT_FRIGO_ARKTEA;

typedef struct
{
	uint16_t      u16UrmsMoteur1;
	uint16_t      u16UdcMoteur1;
	uint8_t      u8IrmsMoteur1;
	uint8_t      u8IdcMoteur1;

	uint16_t      u16UrmsMoteur2;
	uint16_t      u16UdcMoteur2;
	uint8_t      u8IrmsMoteur2;
	uint8_t      u8IdcMoteur2;

	uint16_t      u16UrmsMoteur3;
	uint16_t      u16UdcMoteur3;
	uint8_t      u8IrmsMoteur3;
	uint8_t      u8IdcMoteur3;

	uint16_t      u16UrmsMoteur4;
	uint16_t      u16UdcMoteur4;
	uint8_t      u8IrmsMoteur4;
	uint8_t      u8IdcMoteur4;

	uint16_t      u16DephasageMoteur1;
	uint16_t      u16DephasageMoteur2;
	uint16_t      u16DephasageMoteur3;
	uint16_t      u16DephasageMoteur4;

	uint8_t      u8PasConsigneMoteur;
	uint8_t      u8ConsigneMoteur;

	uint8_t      u8Consigne;
	uint8_t      u8Spare;
} S_STATUT_DRIVER_EQUIUM;

typedef struct
{
	uint16_t  u16VersionHardware;
	uint16_t  u16VersionSoftware;
	uint8_t u4TopologieMoteur : 4;
	uint8_t u4ModeMoteur : 4;
	uint8_t u8FrequenceMoteur;
	uint16_t  u16RampeMonteeMoteur;
	uint16_t  u16RampeDescenteMoteur;
	uint8_t u8StepMoteur;
	uint8_t u8Spare;
} S_CONFIG_DRIVER_EQUIUM; // 12 octets
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES CYCLIQUE FRIGO VERS REG   ">
typedef union
{
//    uint8_t val[124];
    struct
    {                                                           //Byte    Cumul
        //Donn�es de FAN pour REG
        S_RETOUR_FAN_AJPAC          sRetourFan;                 //28        28
        // Donn�es de FRIGO vers REG
        S_IN_TEMP_FRIGO_AJPAC       sInTempFrigo;               //12        40
        S_IN_PRESS_FRIGO_AJPAC      sInPressFrigo;              //10        50
        S_IN_TOR_FRIGO_AJPAC        sInTorFrigo;                //2         52
        S_INFO_U_I_AJPAC            sInfo_U_I_AJP;              //12        64
        S_STATUT_EEV_AJPAC          sStatut_EEV_AJP;            //4         68
        S_STATUT_FRIGO_AJPAC        sStatut_Frigo_AJP;          //16        84
        S_DEMANDE_PW_AJPAC          sDemandePW;                 //2         86
        S_OUT_TOR_FRIGO_AJPAC       sOutTorFrigo;               //2         88
        S_DEMANDE_FAN_AJPAC         sDemandeFan;                //8         96
        S_TPS_COMPRESSEUR_AJPAC     sTpsCompresseur;            //8        104
    }ajpac;                                                     //Total    104 Octets
    struct
    {                                                           //Byte    Cumul
        S_TPS_COMPRESSEUR_GEO   Cpt;                            //32        32
        S_TEMP_GEO              Temp;                           //20        52
        S_IN_PRESS_GEO          InPress;                        //8         60
        S_IN_ANA_GEO            InAna;                          //8         68
        S_IN_TOR_GEO            InTor;                          //2         70
        S_IN_SW_GEO             InSW;                           //2         72
        S_OUT_TOR_GEO           OutTor;                         //2         74
        S_STATUT_FRIGO_GEO      sStatutFrigo;                   //2         76
        S_STATUT_EEV_CIBLE_GEO  StatutEEV;                      //8         84
        S_INFO_CONSO_PAC_GEO    InfoConsoPAc;                   //8         92

        uint8_t                      u8ConsigneCirculateurPrimaire;  //1         93
        uint8_t                      u8ConsigneCirculateurCaptage;   //1         94
        uint8_t                      u8ConsignePompePuits;           //1         95
        uint8_t                      u8Spare;                        //1         96
    }geotwin;                                                   //Total     96 Octets
    struct
    {                                                           //Byte    Cumul
        S_STATUT_MITSU              sStatutMitsu;               //48        48
        S_INFO_TRAME_ZUBA           sInfoTrame;                 //12        60
        S_IN_TOR_FRIGO_ZUBA         sInTorFrigo;                //2         62
        S_OUT_TOR_FRIGO_ZUBA        sOutTorFrigo;               //2         64
        S_STATUT_FRIGO_ZUBA         sStatutFrigo;               //8         72
        S_IN_ANA_FRIGO_ZUBA         sInAnaFrigo;                //8         80
    }zuba;                                                      //Total     80 Octets
    struct
    {                                                           //Byte    Cumul
        S_IMPROMAT_BRIEF_DATA       sImpromatBriefData;         //12        12
        S_STATUT_FRIGO_CAIROX       sStatutFrigo;               //16        28
        S_STATUT_IMPROMAT_CAIROX    sStatutImpromat;            //2         30
        S_IN_TOR_FRIGO_ZUBA         sInTorFrigo;                //2         32
        S_OUT_TOR_FRIGO_ZUBA        sOutTorFrigo;               //2         34
        uint16_t                          u16Spare;                   //2         36
        S_IN_ANA_FRIGO_ZUBA         sInAnaFrigo;                //8         44
    }cairox;                                                    //Total     44 Octets
    struct
    {                                                           //Byte    Cumul
        S_IN_ANA_FRIGO              sInAnaPhoenix;              //50        50
        S_IN_TOR_FRIGO              sInTorPhoenix;              //4         54
        S_OUT_ANA_FRIGO             sOutAnaPhoenix;             //10        64
        S_OUT_TOR_FRIGO             sOutTorPhoenix;             //2         66
        S_RETOUR_RUKING_RE          sRetourRukingRe;            //32        98
        S_STATUT_FRIGO              sStatutFrigoPhoenix;        //22       120
        S_INFO_TRAME_RUKING         sInfoTrameRuking;           //4        124
    }phoenix;                                                   //Total    124 Octets
    struct
    {                                                           //Byte    Cumul
        S_IN_ANA_FRIGO              sInAnaGeoinv;               //50        50
        S_IN_TOR_FRIGO              sInTorGeoinv;               //4         54
        S_OUT_ANA_FRIGO             sOutAnaGeoinv;              //10        64
        S_OUT_TOR_FRIGO             sOutTorGeoinv;              //2         66
        S_RETOUR_RUKING_RE          sRetourRukingRe;            //32        98
        S_STATUT_FRIGO              sStatutFrigoGeoinv;         //22       120
        S_INFO_TRAME_RUKING         sInfoTrameRuking;           //4        124
    }geoinverter;                                               //Total    124 Octets
    struct
    {                                                           //Byte    Cumul
        S_IN_ANA_ARKTEA             sInAnaArktea;               //38        38
        S_IN_TOR_ARKTEA             sInTorArktea;               //4         42
        S_OUT_ANA_ARKTEA            sOutAnaArktea;              //4         46
        S_OUT_TOR_ARKTEA            sOutTorArktea;              //2         48
        S_IN_DEBUG_ARKTEA           sInDebugArktea;             //32        80
        S_STATUT_FRIGO_ARKTEA       sStatutArktea;              //8         88
        S_STATUT_DRIVER_EQUIUM      sStatutDriverEquium;        //36       124
    }arktea;                                                    //Total    120 Octets
} __attribute__((__packed__)) S_CYCL_REG_FRI_PAC;

typedef struct //2 bytes
{                                                            //Byte    Cumul
	uint8_t                      bMaxPW : 1;
	uint8_t                      bFinThermoDynamique : 1;
	uint8_t                      bCycleDegivrage : 1;
	uint8_t                      bPumpDown:1;
	uint8_t                      u4Spare : 4;                        //1         1

	uint8_t                      u8Spare;
}S_CYC_FRI_COMMUN_STATUT;

typedef struct //2 bytes
{
	uint16_t bDemandeCirculateurPrimaire : 1;
	uint16_t u15Spare :15;
} S_DEMANDE_FRIGO_TO_REG; //Retour d'une demande venant des frigos vers la REG


typedef struct
{                                                               //Byte    Cumul
    uint16_t                      au16ListeErreurEnCoursFRIGO[5];     //10        10
    S_DEMANDE_FRIGO_TO_REG  sDemandeFrigoToReg;                 //2         12
    int16_t                      i16Text;                            //2         14
    uint16_t                      u16NbDegivrage;                     //2         16
    S_CYC_FRI_COMMUN_STATUT sStatut;                            //2         18
    uint16_t                      u16Spare;                           //2         20

    uint32_t                     u32Spare;                           //4         24
} __attribute__((__packed__))  S_CYC_FRI_COMMUN;            		//Total     24 Octets

typedef struct
{                                                               //Byte    Cumul
    S_CYC_FRI_COMMUN    commun;                                 //24        24
    S_CYCL_REG_FRI_PAC  pac;                                    //Force  a 124 Octets (max AJPAC 104 / GEO 96  / ZUBA 64  / CAIROX 36)
} __attribute__((__packed__)) S_CYCL_REG_FRI;                                                //Total    148 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES ETHER et CYCLIQUE ETHER   ">
#define TAILLE_SOFT 8
typedef struct //2 bytes
{
	uint8_t Soft_IHM[TAILLE_SOFT];
	uint8_t Soft_ETH[TAILLE_SOFT];
	uint8_t Soft_REG[TAILLE_SOFT];
	uint8_t Soft_FRI[TAILLE_SOFT];
	uint8_t Soft_FAN[TAILLE_SOFT];
	uint8_t Soft_ECS[TAILLE_SOFT];
	uint8_t Soft_MZ[TAILLE_SOFT];
	uint8_t Soft_RF[TAILLE_SOFT];
	uint8_t Soft_WIFI[TAILLE_SOFT];
	uint8_t MacAdress[6];
	uint16_t  u16Spare;
} S_PARAM_ETHER_SOFT_III;		// 80 Octets

typedef struct
{
	uint32_t IpFixe;               // Adresse IP fixe ou defaut

	uint16_t   Port_ihm;
	uint16_t   Port_http;

	uint8_t  bAcces_Distant  :1;     // autorisation a ce connecter au serveur
	uint8_t  bIpFixe         :1;		// si VRAI pas de DHCP on travaille alors avec IpFixe
	uint8_t  bEtherWifi      :1;     // si VRAI utilisation du Wifi pour ce connecter au r�seau local
	uint8_t  bWifiActivated  :1;     // Arret ou Marche du Module
	uint8_t  u4Spare         :4;

	uint8_t Spare[23];
} S_PARAM_ETHER_PORT_III;   // 32 Octets

typedef struct
{
	uint8_t WifiDirectName[32];		// nom du wifi Direct
	uint8_t WifiDirectPW[32];		// Password du wifi Direct

	uint8_t SSID_Name[32];           // nom du r�seau wifi local du client
	uint8_t CleWifi[64];             // Password cle wifi

	uint8_t  bWifiOn : 1;            // alimentation de l'alim module Wifi
	uint8_t  u7Spare : 7;

	uint8_t Timeout;                 // Timeout d'arr�t des �missions des ondes

	uint8_t u8Spare[30];
} S_PARAM_ETHER_WIFI_III;           // 192 Octets

typedef struct
{
	uint8_t adresse;                 // 1 � 63
	uint8_t speed;					// 4800 / 9600 / 19200 / 38400 ??

	uint8_t bGestionTimeOut  :1;		// gestion du timeout (pour stopper la regulation si plus de requete modbus)
	uint8_t u7TimeOut        :7;     // de 0 � 127 sec : defaut mettre 30 sec ( 2 fois au demarrage ?)

	uint8_t bConfigChange    :1;
	uint8_t bConfig120R      :1;     // Activation ou non de la r�sistance 120Ohm
	uint8_t u1NbStopBit      :1;
	uint8_t u2Parite         :2;
	uint8_t u3Spare          :3;

	uint8_t u8Spare[4];
} S_PARAM_ETHER_MODBUS_III;       // 8 Octets

typedef struct
{
	uint8_t ArkteosServeurName[64];
	uint8_t CheckIpServeurName[64];
	uint8_t TimeServeurName[64];
	uint8_t SpareServeurName[64];

	uint16_t  ArkteosServeurPort;
	uint16_t  CheckIpServeurPort;
	uint16_t  TimeServeurPort;
	uint16_t  SpareServeurPort;
} S_PARAM_SERVEUR_III;  	// 264 Octets

typedef struct
{
	uint32_t WIP;         // Format ASCII
	uint32_t IP;          // Format ASCII
	// 8
	uint16_t   au16ListeErreurEnCoursETHER[5];
	// 18
	uint8_t  bUPNP               :1;
	uint8_t  bAppletConnect      :1;
	uint8_t  bWifiNetworkConnect :1;
	uint8_t  bWifiDirectConnect  :1;
	uint8_t  bModbusConnect      :1;
	uint8_t  bModifConfig        :1;
	uint8_t  bModbusTimeout      :1;
	uint8_t  bIHMConnect         :1;

	uint8_t  u8Spare;
	// 20
	S_IN_TOR_ETHER  sInTorEther;    // 2 Octets
	S_OUT_TOR_ETHER sOutTorEther;   // 2 Octets
	// 24
	uint8_t u8Spare_Tab[40];
} S_CYC_ETHER_III;					// 64 Octets

typedef struct
{
        uint8_t  bModbusTimeout      :1;     // permet de dire � la REG d'arreter sa regulation car il y a une gestion du timeout MODBUS
        uint8_t  bIHMConnect         :1;     // signal � la REG la connexion de la tablette pour forcer une r�cup config
        uint8_t  u6Spare             :6;

        uint8_t u8Spare[7];
} S_CYC_ETHER_REG_III;					// 8 Octets

typedef struct
{
	uint8_t  u8Spare[8];
} S_CYC_ETHER_FRIGO_III;				// 8 Octets

typedef struct
{
	uint8_t  WIPAddress[4];
	uint8_t	IPAddress[4];
	int8_t	i8RSSI;

	uint8_t  u2CurrentMode 	:2;			// E_STATE_WIFI
	uint8_t  bSTAConnected 	:1;
	uint8_t  bAPConnected 	:1;
	uint8_t  u2RequestedMode :2;
	uint8_t  u2Spare			:2;

	uint8_t u8Spare;
	uint8_t u8Spare1;
} S_CYC_ETHER_WIFI;                     // 12 octets
// </editor-fold>


typedef struct
{
	S_PARAM_ETHER_SOFT_III sParamSoft;
	S_PARAM_ETHER_PORT_III sParamPort;
	S_PARAM_ETHER_WIFI_III sParamWifi;
	S_PARAM_ETHER_MODBUS_III sParamModbus;

	S_MODE_ZX sMode_Zx[20];
	S_MODE_ECS sMode_ECS;
	S_MODE_PISCINE sMode_Piscine;
	S_MODE_REG_EXT sMode_RegulExt;
	S_MODE_PAC sMode_PAC;
	S_PARAM_UTILISATEUR sParam_Utilisateur;
	S_MODELE_PAC sModele_PAC;
	S_OPTION_PAC sOption_PAC;
	S_CONFIG_PAC sConfig_PAC;
	S_INSTALL_PAC sInstall_PAC;
	S_PARAM_PAC sParam_PAC;
	S_PARAM_ECS sParam_ECS;
	S_PARAM_PISCINE sParam_Piscine;
	S_PARAM_REG_EXT sParam_RegulExt;
	S_PARAM_FRIGO sParam_Frigo;
	S_PARAM_SAV sParam_SAV;
	S_PARAM_ZX sParam_Zx[20];
	S_CONFIG_FRIGO sConfigFrigo[NB_UE_MAX];

	uint16_t u16RecupConfig;
	uint16_t u16NbCyclique;
} S_CONFIG_IHM;


#endif

// End of file
