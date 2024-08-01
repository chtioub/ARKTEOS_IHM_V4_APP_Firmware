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
typedef enum {HUBA_DN_10, HUBA_DN_15, HUBA_DN_20, HUBA_DN_25, HUBA_DN_32, SIKA_DN_32, SIKA_DN_40} E_TYPE_DEBITMETRE;
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
typedef enum { FR, EN, PT, NE } E_LANGUE;   // Jusqu'a 8 langues

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
typedef enum{GEOINV_STD, GEOINV_BI_COMP, GEOINV_BI_ETAGE, GEOINV_SAGITAIR,} E_SOUS_TYPE_GEOINV;

// Configurations autres
typedef enum {SIMULTANE_CHAUD_FROID_NONE, SIMULTANE_CHAUD_FROID_CONFIGURATION_1, SIMULTANE_CHAUD_FROID_CONFIGURATION_2, SIMULTANE_CHAUD_FROID_CONFIGURATION_3} E_TYPE_SIMULTANE_CHAUD_FROID;
// SIMULTANE_CHAUD_FROID_CONFIGURATION_1 : Freecooling (Froid par Freecolling � classique � ou par le c�t� capteur de la PAC en fonction que la PAC est par ailleurs en demande de production de Chaud vers une source chaude ou pas)
// SIMULTANE_CHAUD_FROID_CONFIGURATION_2 : Froid actif (Pr�sence de 2 ballons Chaud et Froid, d�charge de la PAC du ballon satisfait vers le capteur)

// </editor-fold>

/*****************************************************************************/
//  DEFINITION DES ENTREES /SORTIES DES CARTES
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="STRUCTURES ENTREE / SORTIES DES CARTES">

// <editor-fold defaultstate="collapsed" desc="Description Carte Ether   ">
/* Liste des entrees TOR */
typedef union
{
    u16 val;
    struct
    {
        u8 bInTorSpare0:1;            // Entr�e x
        u8 bInTorSpare1:1;            // Entr�e x
        u8 bInTorSpare2:1;            // Entr�e x
        u8 bInTorSpare3:1;            // Entr�e x
        u8 bInTorSpare4:1;            // Entr�e x
        u8 bInTorSpare5:1;            // Entr�e x
        u8 bInTorSpare6:1;            // Entr�e x
        u8 bInTorSpare7:1;            // Entr�e x
        
        u8 bInTorSpare8:1;            // Entr�e x
        u8 bInTorSpare9:1;            // Entr�e x
        unsigned char :6;             // Entr�e x
    };
} S_IN_TOR_ETHER;

typedef union
{
    u16 val;
    struct
    {
        offon LED_StatutDefaut:1;
        offon LED_StatutVerte:1;
        offon LED_EtherSpeed:1;
        offon LED_UsbVerte:1;
        offon LED_UsbRouge:1;
        offon Wifi_EnablePWR:1;
        u8    u2Spare : 2;
        
        u8    u8Spare;
    };
} S_OUT_TOR_ETHER;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Reg   ">

// Liste des entrees TOR
typedef union
{
    u32 val;
    struct
    {
        // Avec Gestion des rebonds
        u8  bDefautAppoint  : 1;    // Cette Entr�e n'est pas param�trable la laisser en position Bit 0
        u8  bInTOR_1        : 1;    // La fonction 1 tombe le bit 1 de la structure ce qui facilite la gestion des affectations 
        u8  bInTOR_2        : 1;
        u8  bInTOR_3        : 1;
        u8  bInTOR_4        : 1;
        u8  bInTOR_5        : 1;
        u8  bInTOR_6        : 1;
        u8  bInTOR_7        : 1;

        u8  bInSpare1       : 1;
        u8  bInSpare2       : 1;
        u8  bInSpare3       : 1;
        u8  bInSpare4       : 1;
        u8  bInSpare5       : 1;
        u8  bInSpare6       : 1;
        u8  bInSpare7       : 1;
        u8  bInSpare8       : 1;

        u8  Comptage_Energie: 1;        // Entr�e comptage Energie ; Cette entr�e est �galement attach� au comptage
        u8  bInTF_1         : 1;
        u8  bInTF_2         : 1;
        u8  bInTF_3         : 1;
        u8  u4Spare         : 4;
        
        u8 u8Spare;
    };
} S_IN_TOR_REG;     // 4 Octets

typedef union
{
    u16 val;
    struct
    {
        u8  u1Spare         :1;
        u8  Out_1           :1;     // La fonction 1 tombe le bit 1 de la structure ce qui facilite la gestion des affectations
        u8  Out_2           :1;
        u8  Out_3           :1;
        u8  Out_4           :1;
        u8  Out_5           :1;
        u8  ReleveChaudiere :1;
        u8  u1Spare2        :1;
        
        u8  Pw_Relec        :2;     // E_PW_RELEC def P0
        u8  LED_Defaut      :1;
        u8  u5Spare         :5;
    };
} S_OUT_TOR_REG;

typedef union
{
    u8 val[16];
    struct
    {
        u16 u16DebitPrimaire;
        u16 u16DebitZ1;

        u16 u16DebitZ2;
        
        u8 u8RetourPWM_Primaire;
        u8 u8RetourPWM_Z1;
        
        u8 u8RetourPWM_Z2;
        u8 u8Spare;
        u16 u16Spare;
    };
} S_IN_PWM_REG;


typedef union
{
    i16 val[8];
    struct
    {
        i16 i16TempDepartPrimaire;
        i16 i16TempRetourPrimaire;
        i16 i16TempDepartZ1;
        i16 i16TempRetourZ1;
        i16 i16TempDepartZ2;
        i16 i16TempRetourZ2;
        u16 u16Pression;
        i16 i16BallonTampon;
    };
} S_IN_ANA_REG;
        

/* Liste des sorties ANA */
typedef union
{
    u32 val;
    struct
    {
        u8 Cons_Circul_Z1 ;    /* Def 0 ( de 0 � 200 )*/
        u8 Cons_Circul_Z2 ;    /* Def 0 ( de 0 � 200 )*/
        u8 Cons_V3V_Z2 ;       /* Def 0 ( de 0 � 200 )*/
        u8 Cons_Circul_Primaire ;
    };
} S_OUT_ANA_REG;

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Option ECS   ">
typedef union
{
    u32 val;
    struct
    {
        offon   bSolaire:1;               // Entr�e Solaire (autorisation Production ECS)
        offon   In2:1;                    // Entr�e 2
        offon   In3:1;                    // Entr�e 3
        offon   In4:1;                    // Entr�e 4
        offon : 4;
        u8      u8Spare;
        u16     u16CompteurEau;           // Compteur Eau en impulsion / litre 
    };
} S_IN_TOR_ECS;

typedef union
{
    u16 val;
    struct
    {
        u8      appointECS:1;           // Relais appoint ECS
        u8      V3V_ECS:1;              // vanne 3 voies ECS
        u8      CirculateurECS:1;       // circulateur ECS
        u8      Spare1:1;               // Spare 1 0-24V
        u8      Spare2:1;               // Spare 2 0-24V
        unsigned char : 3;
    };
} S_OUT_TOR_ECS;

typedef union
{
    u64 val;
    struct
    {
        i16     i16TempECSMilieu;       // Temp�rature Ballon ECS Milieu (relance)
        i16     i16TempECSBas;          // Temp�rature Ballon ECS Bas
        i16     i16TempDepart;          // Temp�rature Depart voie 1
        i16     i16TempRetour;          // Temp�rature Retour voie 1
    };
} S_IN_ANA_ECS;

typedef union
{
    u32 val;
    struct
    {
        u8      u8ConsigneCirculateur;  // Consigne circulateur 0-100%
        u8      u8ConsigneVanneMelange; // Consigne 0-10V (vannes m�lange)
        u16     u16Spare;               // Sortie Ana Spare
    };
} S_OUT_ANA_ECS;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Option Multizone   ">
typedef union
{
    u8 val[12];
    struct
    {
        union
        {
			u8 Voie;
			struct {
                offon   bVoie1:1;               // Entr�e 1 (Zone 1 IN Contact)
                offon   bVoie2:1;               // Entr�e 2 (Zone 2 IN Contact)
                offon   bVoie3:1;               // Entr�e 3 (Zone 3 IN Contact)
                offon   bVoie4:1;               // Entr�e 4 (Zone 4 IN Contact)
                offon   bVoie5:1;               // Entr�e 5 (IN 5 Contact)
                offon   bPiscine:1;
				offon   bInSpare:1;
				offon   u1Spare:1;
			};
        };

        u8      u8Spare;

        u16     u16Compteur;            // Compteur
        u16     u16debit;               // Debitmetre

        u8      u8RetourPWM[NB_VOIE_CARTE_MZ];   // 0-100% (retour circulateur)
        u8      u8Spare1;
    }; 
} S_IN_TOR_MULTI_ZONE;

typedef union
{
    u16 val;
    struct
    {
        u8      bRelais1:1;             // Relais 1 / Circulateur 1
        u8      bRelais2:1;             // Relais 2 / Circulateur 2
        u8      bRelais3:1;             // Relais 3 / Circulateur 3
        u8      bRelais4:1;             // Relais 4 / Circulateur 4
        u8      bRelais5:1;             // Relais 5 / Circulateur 5
        u8      bV3V_Piscine:1;         // Relais V3V Piscine
        u8      : 2;
        u8      u8Spare;
    };
} S_OUT_TOR_MULTI_ZONE;

typedef union
{
    i16 val[14];
    struct
    {
        i16     i16TempDepart[NB_VOIE_CARTE_MZ]; // Temp�rature d�part Zone x
        i16     i16TempRetour[NB_VOIE_CARTE_MZ]; // Temp�rature retour Zone x
        i16     i16TempPiscine;         // Temp�rature piscine
        i16     i16TempSpare1;          // Temp�rature Spare
        i16     i16TempSpare2;          // Temp�rature Spare
        i16     i16TempSpare3;          // Temp�rature Spare
    };
} S_IN_ANA_MULTI_ZONE;

typedef union
{
    u8 val;
    struct
    {
        u8      Consigne     : 7;       // Consigne des voies (circulateur/registre en 0-10V ou PWM) 0-100%
        u8      bTypeConsigne: 1;       // Type de sortie ANA (0-10V ou PWM)
    };
} S_OUT_CONSIGNE;

typedef union
{
    u64 val;
    struct
    {
        S_OUT_CONSIGNE      ConsigneVoie[NB_VOIE_CARTE_MZ];  // Consigne des voies (circulateur/registre en 0-10V ou PWM) 0-100% ( on pourrait le mettre sur le bit 8 de chaque consigne)
        S_OUT_CONSIGNE      ConsigneFan;            // Consigne FAN   (Fan de la Cassette en 0-10V ou PWM) 0-100%
        u16     u16Spare;                           // Sortie Spare
    };
} S_OUT_ANA_MULTI_ZONE;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo AJPAC   ">
typedef struct //12 bytes
{
    i16 i16Temp_Frigo_TSH410;
    i16 i16Temp_Frigo_TSC410_A;
    i16 i16Temp_Frigo_TSH134;
    i16 i16Temp_Frigo_TSC410_B;
    i16 i16Temp_Frigo_TEV134;
    i16 i16Temp_Frigo_TIGBT;  // Utilise pour le resultat de la demande de Mode PAR21
} S_IN_TEMP_FRIGO_AJPAC;

typedef struct //10 bytes
{
    i16 i16In_Pression_BP410;
    i16 i16In_Pression_BP134;
    i16 i16In_Pression_HP410;
    i16 i16In_Pression_HP134;
    i16 i16In_Pression_HPINT;
} S_IN_PRESS_FRIGO_AJPAC;

typedef union //2 bytes
{
    u16 val;
    struct
    {
        unsigned char Pressostat_HP410:1; 
        unsigned char Pressostat_HP134:1;
        unsigned char J20:1;
        unsigned char u5Spare:5;
        u8 Spare;
    };
} S_IN_TOR_FRIGO_AJPAC;

typedef union //2 bytes
{
    u16 val;
    struct
    {
        offon V4V_R410:1 ;            /*Def OFF */
        offon Electrovanne_HP410:1;   /*Def OFF */
        offon Ventilateur_PW:1;       /*Def ON */
        offon Compresseur2 : 1;          /*Def OFF */
        offon LED_Defaut:1;           /*Def OFF */
        offon LED_Verte:1;            /*Def OFF */
        unsigned char : 2;

        u8 Spare;
    };
} S_OUT_TOR_FRIGO_AJPAC;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Fan AJPAC   ">
typedef union
{
    u16 val;
    struct
    {
		offon Evap_EV1:1; 
		offon Evap_EV2:1;
		offon Evap_EV3:1;
		offon Evap_EV4:1;
		offon Evap_EV5:1; 
		unsigned char nu : 3 ; // Vitesse_Ventilateur:3;  // E_VITESSE_VENTILATEUR_EVAP
		offon LED_Defaut:1;
		unsigned char  : 1;   // Ex Type detendeur
		unsigned char Spare  : 6 ;
    };
} S_OUT_TOR_FAN_AJPAC;

typedef union //2 bytes
{
    u16 val;
    struct
    {
        u8 Ventilateur1 ; /*def 0% , de 0 � 100% */ 
        u8 Ventilateur2 ; /*def 0% , de 0 � 100% */
    };
} S_CONSIGNE_FAN_AJPAC;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo GEOTWIN    ">
// Partie Physique de la Carte
typedef struct //20 bytes
{
    i16 i16Temp_BP1;
    i16 i16Temp_BP2;
    i16 i16Temp_ALL_PRI;
    i16 i16Temp_RET_PRI;
    i16 i16Temp_ALL_CAP;
    i16 i16Temp_RET_CAP;
    i16 i16Temp_EXT;
    i16 i16Temp_HP1;
    i16 i16Temp_HP2;
    i16 i16Temp_COND;
} S_TEMP_GEO;

typedef struct //8 bytes
{
    i16 i16Pression_GazHP;
    i16 i16Pression_GazIntermediaire;
    i16 i16Pression_GazBP;
    i16 i16Pression_EauCaptage;
} S_IN_PRESS_GEO;

typedef struct //8 bytes
{
    u16 u16Vitesse_Circul_PRI;
    u16 u16Vitesse_Circul_CAP;
    u16 u16Debit_PRI;            
    u16 u16Debit_CAP;             
} S_IN_ANA_GEO;

typedef union //2 bytes
{
    u16 val;
    struct
    {
        offon           Puits :1;             // Puits
        offon           HP :1;                // HP
        offon           DemarreurC1 :1;       // Etat Demarreur C1
        offon           DemarreurC2 :1;       // Etat Demarreur C2
        unsigned char   Spare2 : 4 ;
        u8              Spare;
    };
}S_IN_TOR_GEO ;

typedef union //2 bytes
{
    u16 u16Val ;
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

typedef union //2 bytes
{
    u16 val;
    struct
    {
        offon REL_CirculateurPrimaire :1;
        offon REL_CirculateurCaptage :1;
        offon REL_V4V :1;                     //ON = rafraichissement
        offon REL_PompeDePuit :1;
        offon REL_Compresseur1 :1;
        offon REL_Compresseur2 :1;
        offon REL_Spare1 :1;
        offon REL_Spare2 :1;   // => 8bits !!! Logique invers�e Relais NF
        
        
        offon LED_Defaut :1;
        offon LED_Verte :1;
        unsigned char Spare:6;
    };
} S_OUT_TOR_GEO;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo Zuran Baguio   ">
typedef union //2 bytes
{
    u16 val;
    struct
    {
        offon Pac_On_Off    :1;
        offon Pac_PW1       :1;
        offon Pac_PW2       :1;
        offon Pac_PW3       :1;
        offon LED_Defaut    :1;
        offon LED_Verte     :1;
        offon Simu_Chaud_Froid:1;
        offon Chaud_Froid   :1;

        offon Circulateur   :1;
        offon Zuran_IO8     :1;
        offon Silencieux    :1;
        unsigned char Spare :5;
    };
} S_OUT_TOR_FRIGO_ZUBA;


typedef union //2 bytes
{
    u16 val;
    struct
    {
        offon I1 :1;      // I1
        offon I4 :1;      // I4
        offon I_SSM :1;   // I_SSM
        unsigned char Spare2 :5;
        
        u8 Spare;
    };
}S_IN_TOR_FRIGO_ZUBA;

typedef union //2 bytes
{
    u64 val;
    struct
    {
		i16 i16Temp_Th2_Liquide;
		i16 i16Temp_S1;
		i16 i16PressionBasse;
		i16 i16PressionHaute;
    };
}S_IN_ANA_FRIGO_ZUBA;

 // </editor-fold> 

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo PHOENIX / GEO INVERTER">
typedef union
{
    u16 val[25];
    struct
    {
        // Debits
        u16 u16DebitPrimaire;            
        u16 u16DebitCapteur;
        u16 u16RetourVitessePrimaire;
        union
        {
            u16 u16RetourVitesseVentilateur;
            u16 u16RetourVitesseCapteur;
        };
        // Hygrom�trie
        i16 i16Hygrometrie;
        // Pressions
        i16 i16Press_BP1;
        i16 i16Press_BP2;
        i16 i16Press_HP1;
        i16 i16Press_HP2;
        i16 i16Press_EauCapteur;
        i16 i16Press_EauChauffage;
        i16 i16Press_Spare;
        // Temp�ratures
        i16 i16Temp_DepartPrimaire;
        i16 i16Temp_RetourPrimaire;
        i16 i16Temp_DepartCapteur;
        i16 i16Temp_RetourCapteur;
        i16 i16Temp_BP1;
        i16 i16Temp_BP2;
        i16 i16Temp_HP1;
        i16 i16Temp_HP2;
        i16 i16Temp_Exterieur;
        i16 i16Temp_Liquide;
        i16 i16Temp_Spare;
        i16 i16Temp_CaptSpare;
        i16 i16Temp_PrimSpare;
    };
} S_IN_ANA_FRIGO; // 50 octets

typedef union
{
    u8 u8Val[4];
    struct
    {
        u8 InDebitPuit :1;
        u8 InKlixonCompresseur :1;
        u8 InPressostatHP1 :1;
        u8 InPressostatHP2 :1;
        u8 InDefautDemarreur1 :1;
        u8 InDefautDemarreur2 :1;
        u8 InSW1 :1;
        u8 InSW2 :1;
        
        u8 InSW3 :1;
        u8 InSW4 :1;
        u8 InDefautAppoint1 :1;
        u8 InDefautAppoint2 :1;
        u8 InDefautAppoint3 :1;
        u8 InEnergie :1;
        u8 u2Spare :2;

        u16 u16CompteurEnergies;    // Energies consomm�e instantan�e
    };
} S_IN_TOR_FRIGO;

typedef union
{
    u8 val[10];
    struct
    {
        u8 u8ConsigneCirculateurPrimaire;
        union
        {
            u8 u8ConsigneCirculateurCapteur;
            u8 u8ConsigneVentilateur;
        };
        u16 u16PositionDetendeur1;
        u16 u16PositionDetendeur2;
        u16 u16PositionDetendeur3;
        u16 u16PositionDetendeur4;
    };
} S_OUT_ANA_FRIGO;

typedef union
{
    u8 u8Val[2];
    struct
    {
        u8 V4V :1;
        u8 ResistanceVase :1;
        u8 ElectrovanneFroid :1;
        u8 ResistanceCarter :1;
        u8 Compresseur1 :1;
        u8 Compresseur2 :1;
        u8 Spare1 :1;   // V3V_ChauffageFC
        u8 Spare2 :1;   // V3V_CapteurFC
        
        u8 ContactPuit :1;
        u8 Appoint1 :1;
        u8 Appoint2_3 :1;
        u8 Ventilateur :1;
        u8 u4Spare:4;
    };
} S_OUT_TOR_FRIGO;
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Description Carte Frigo ARKTEA">
typedef union
{
    u16 val[19];
    struct
    {
        // Debits
        u16 u16DebitPrimaire;            
        u16 u16DebitCapteur;
        u16 u16RetourVitessePrimaire;
        u16 u16RetourVitesseVentilateur;
        // Hygrom�trie
        i16 i16Hygrometrie;
        // Pressions
        i16 i16Press_EauCapteur;
        i16 i16Press_EauPrimaire;
        i16 i16Press_Helium;
        // Temp�ratures
        i16 i16Temp_DepartPrimaire;
        i16 i16Temp_RetourPrimaire;
        i16 i16Temp_DepartCapteur;
        i16 i16Temp_RetourCapteur;
        i16 i16Temp_Spare1;
        i16 i16Temp_Spare2;
        i16 i16Temp_Exterieur;
        i16 i16Temp_Liquide;
        i16 i16Temp_Spare;
        i16 i16Temp_CaptSpare;
        i16 i16Temp_PrimSpare;
    };
} S_IN_ANA_ARKTEA; // 38 octets

typedef union
{
    u8 val[32];
    struct
    {
        i16 i16Temp_TC1;
        i16 i16Temp_TC2;
        i16 i16Temp_TC3;
        i16 i16Temp_TC4;
        i16 i16Temp_TC5;
        i16 i16Temp_TC6;
        i16 i16Temp_TC7;
        i16 i16Temp_TC8;
        i16 i16Temp_TC9;
        i16 i16Temp_TC10;
        i16 i16Temp_TC11;
        i16 i16Temp_TC12;
        i16 i16Debit_1;
        i16 i16Debit_2;
        i16 i16Debit_3;
        i16 i16Debit_4;
    };
} S_IN_DEBUG_ARKTEA; // 32 octets

typedef union
{
    u8 u8Val[4];
    struct
    {
        u8 InDebitPuit :1;
        u8 InKlixonCompresseur :1;
        u8 InPressostatHP1 :1;
        u8 InPressostatHP2 :1;
        u8 InDefautDemarreur1 :1;
        u8 InDefautDemarreur2 :1;
        u8 InSW1 :1;
        u8 InSW2 :1;
        
        u8 InSW3 :1;
        u8 InSW4 :1;
        u8 InDefautAppoint1 :1;
        u8 InDefautAppoint2 :1;
        u8 InDefautAppoint3 :1;
        u8 InEnergie :1;
        u8 u2Spare :2;

        u16 u16CompteurEnergies;    // Energies consomm�e instantan�e
    };
} S_IN_TOR_ARKTEA;

typedef union
{
    u8 val[4];
    struct
    {
        u8 u8ConsigneCirculateurPrimaire;
        u8 u8ConsigneCirculateurCapteur;
        u8 u8ConsigneVentilateur;
        u8 u8ConsigneSpare;
    };
} S_OUT_ANA_ARKTEA;

typedef union
{
    u8 u8Val[2];
    struct
    {
        u8 V4V :1;
        u8 ResistanceVase :1;
        u8 ElectrovanneFroid :1;
        u8 ResistanceCarter :1;
        u8 Compresseur1 :1;
        u8 Compresseur2 :1;
        u8 Spare1 :1;
        u8 Spare2 :1;

        u8 ContactPuit :1;
        u8 Appoint1 :1;
        u8 Appoint2_3 :1;
        u8 Ventilateur :1;
        u8 u4Spare:4;
    };
} S_OUT_TOR_ARKTEA;
// </editor-fold>

// </editor-fold>

/*****************************************************************************/
//  DEFINITION DES STRUCTURES DE COMMUNICATION
/*****************************************************************************/
// <editor-fold defaultstate="collapsed" desc="STRUCTURES de FONCTIONNEMENT pour SAV et DATE (la Date est Stock�e en Flash)   ">
typedef union
{
    u32 val;
    struct
    {
        unsigned char   bShuntTempo : 1;
        // unsigned char   bDerogationPression : 1; // ce fait a l'aide d'une commande et le retour est dans le Statut_PAC
        unsigned char   NumPacStructe : 3;
        unsigned char   u4Spare : 4;
        u8              u8Spare;
        u16             u16Spare;
    };
} S_PARAM_SAV;                      // 4 Octets ==> Cette variable n'est pas stock�e en E2P

typedef union
{
    u64 val;
    struct
    {
        unsigned char ModeTest:3;   // E_MODE_TEST_PAC  def T_CHAUD
        unsigned char bTestPAC:1;   // Demande mode test
        unsigned char :4;           // Reserve
        u8  Pw;                     // En prevision pour autres machines
        i16 Teau;                   // Consigne de temperature mode test
        u16 u16Spare1;              // Spare1
        u16 u16Spare2;              // Spare2
    };
} S_PARAM_TEST_PAC;                 //8 Octets ==> Cette variable n'est pas stock�e en E2P

// Date Stock�e en Flash pour v�rification de perte de date (la date de mise en service est en E2P)
typedef union
{
    u64 val;
    struct
    {         
        u8 Year;    // 0 � 99 = 2000 � 2099
        u8 Month;   // 1 � 12
        u8 Date;    // 1 � 31
        u8 Hours;   // 0 � 23
        u8 Minutes; // 0 � 59
        u8 Seconds; // 0 � 59
        u8 WeekDay; // 0 � 6 ; format E_DAYS
        unsigned char Semaine:7;   // Numero de semaine, inutilise
        unsigned char Heure_Ete:1; // Vrai en heure d'ete
    };
} S_DATE;
#define S_DATE_COURTE sizeof(S_DATE)-2
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DE CONFIGURATION et OPTION DE LA REGULATION (Stock�es en E2P)   ">
typedef union
{
    u64 val;
    struct
    {
        u8                  u8ModelePAC;            // Voir E_MODEL_PAC
        u8                  u8PwPac;                // En KW
        u8                  u8ThermoMaxPac;         // �C

        u8                  u3SousTypePAC : 3;      // si besoin ex (Zuran / Baguio / Baguio Mono Bloc)
        u8                  nbCompresseur : 2;      // E_NB_COMPRESSEUR 
        u8                  bReversible : 1;        // NON / OUI
        u8                  bSupply : 1;            // MONO / TRI
        u8                  bDemarreurProgressif:1; // NON / OUI

        u8                  Gaz_C1 : 4;             // None / R410 / R134 / R407 / R32 / R290 / R513 / R1234
        u8                  Gaz_C2 : 4;

        u8  u8Spare;
        u16 u16Spare;
    };
} S_MODELE_PAC;                                     // 8 Octets

// Structure pour l'option des Zones NB les zones sont assoic�es au physique des cartes options
typedef union
{ 
    u8 u8Zone;
    struct
    {
        unsigned char bZone1:1;
        unsigned char bZone2:1;
        unsigned char bZone3:1;
        unsigned char bZone4:1;
        unsigned char bZone5:1;
        unsigned char bZone6:1;
        unsigned char bZone7:1;
        unsigned char bZone8:1;
    };
}S_ZONE;                            // 1 octet


typedef union
{
    u64 val;
    struct
    {
        S_ZONE          sZone;                  // Definition des 8 Zones  Def Zone 1

        unsigned char   Piscine:1;              // def FAUX
        unsigned char   ECS:1;                  // def FAUX
        unsigned char   CoeffComptagePW:2;      // E_CoeffComptagePW    Def NO_COMPTAGE
        unsigned char   TypeAppoint:2;          // E_APPOINT_CHAUFFAGE  Def NO_APPOINT
        unsigned char   CoeffCompteurEau : 2;   // E_CoeffComptageEau   Def NO_COMPTAGE_EAU Comptage Eau Sanitaire

        u16             u16PW_Brin;             // Faire avancer de 100 Watts � la fois de 1KW � 4 KW
        
        unsigned char   u2NbBrinAppoint:2;      // Defaut : 3 brins
        unsigned char   u2ModeleThermostatRF:2; // Watts / 
        unsigned char   u2ModeleThermostatRS485:2;// 
        unsigned char   u2Spare:2;              //
        
        u8              u8Spare;                //

        u16             u16Spare;               //
    };
} S_OPTION_PAC;                                 // 8 Octets

typedef struct
{
    u8                  auc8Serial_Number_PAC[12];
    u8                  auc8PW_Installateur[4];
    u8                  auc8PW_Maintenance[4];
    u8                  CodeLogoClient[15];         // Code pour faire afficher le logo client client
    u8                  u5VerificationAnnuelle:5;
    u8                  u3Spare:3;

    //u8                  Spare;
    S_DATE              sDateMiseEnService;         // Date de mise en service
    u32                 u32Spare;
} S_INSTALL_PAC;                                    // 48 Octets

typedef union
{
    u64 u64val;                                         // 8 Octets Max
    struct
    {
        i8 i8Hysteresis_Primaire_Plus;                  // Hyst�r�sis sur T� eau des Arret et D�marrage de Compresseur
        i8 i8Hysteresis_Primaire_Moins;
        u8 u8ConsignePompePuitsMax;
        u8 u8ConsignePompePuitsMin;

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
        i8 i8Hysteresis_Primaire_Plus;
        i8 i8Hysteresis_Primaire_Moins;
        
        unsigned char bFreecooling:1;                   // Option free cooling
        unsigned char eTypeSimultaneChaudFroid :3;      // E_TYPE_SIMULTANE_CHAUD_FROID
        unsigned char eTypeDeCaptage :3;                // E_TYPE_CAPTAGE_GEO
        unsigned char bUseCarterHeater :1;
        
        u8 u8ConsignePompePuitsMax;
        u8 u8ConsignePompePuitsMin;
    } ConfigGeoInverter;
    struct
    {
        i8 i8Hysteresis_Primaire_Plus;
        i8 i8Hysteresis_Primaire_Moins;
    } ConfigArktea;
    struct
    {
        i8 i8Hysteresis_Primaire_Plus;
        i8 i8Hysteresis_Primaire_Moins;
    } ConfigPhoenix;
    struct
    {
        u8  futurConfigCairox;
    } ConfigCairox;
    struct
    {
        i8 i8Hysteresis_Primaire_Plus;
        i8 i8Hysteresis_Primaire_Moins;
        
        u8 u2TypeRegul_MITSU :2;
        u8 u6Spare :6;
    } ConfigZuranBaguio;
    struct
    {
        u8 futurConfigAjpac;
    } ConfigAjpac;
} S_CONFIG_PAC;                // 8 Octets 

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURE MODE de FONCTIONNEMENT DE LA REGULATION (Stock�es en E2P)   ">

// Mode de fonctionnement en cours
typedef union
{
    u32 val;
    struct
    {
        offon         bEtatPAC:1;               // Arret / Marche
        offon         bSecours:1;               // Mode secours
        offon         bAppointUser:1;           // Utilisation appoint utilisateur
        offon         bModeSilencieux:1;        // Utilisateur validation de la PROG mode Silencieux
        offon         bUserFreeHeating:1;       // Validation User Freeheating
        offon         bUserFreecooling:1;       // Validation User Freecooling
        offon         bUserAdaptationLoiDeau:1; // Validation de l'adaptation loi d'eau via entr�e contact (auto conso)
        offon         bUserAdaptationConsigne:1;// Validation de l'adaptation de consigne entr�e contact   (auto conso)
        
        u8            u8Spare;
        u16           u16Spare;
    };
} S_MODE_PAC;                                   // 4 Octets

typedef struct
{
    unsigned char Mode:4;                       // E_FONCT_ZX Def ARRET
    unsigned char Exception:3;                  // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char u1Spare : 1;
    u8            u8Spare;                      // Unused

    i16           i16Consigne_Tint_Reduit;      // Consigne reduit (chaud ou froid)
    i16           i16Consigne_Tint_Normal;      // Consigne normal (chaud ou froid)
    i16           i16Consigne_Tint_Confort;     // Consigne confort (chaud ou froid)

    i16           i16Consigne_Tint_Horsgel;     // Consigne temperature hors gel
    u16           u16Time_Sablier;              // Temps de la d�rogation

    i16           i16Consigne_Tint_Sablier;     // Consigne pendant la d�rogation
    i16           i16Consigne_Tint_Vacances;    // Consigne temperature vacances
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

    u8            u8Time_Bouclage_ECS;          // Dur�e du bouclage ECS (marche forc�e)
    u8            u8Spare;                      // 

    i16           i16Consigne_ECS_Normal;       // Consigne normal (chaud ou froid)
    i16           i16Consigne_ECS_Confort;      // Consigne confort (chaud ou froid)

    i16           i16Consigne_ECS_Relance;      // Consigne temperature hors gel
    u16           u16Time_ECS_Sablier;          // Temps de la d�rogation

    i16           i16Consigne_ECS_Sablier;      // Consigne pendant la d�rogation
    i16           i16Consigne_ECS_Vacances;     // Consigne temperature vacances
} S_MODE_ECS;                                   // 16 Octets

typedef struct
{
    unsigned char Mode :4;                      // E_FONCT_PISCINE Def ARRET
    unsigned char Exception :3;                 // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char u1Spare : 1;
    u8            u8Spare;                      // Unused

    i16           i16Consigne_Piscine_Reduit;   // Consigne reduit (chaud ou froid)

    i16           i16Consigne_Piscine_Normal;   // Consigne normal (chaud ou froid)
    i16           i16Consigne_Piscine_Confort;  // Consigne confort (chaud ou froid)

    i16           i16Consigne_Piscine_Horgel;   // Consigne temperature hors gel
    u16           u16Time_Piscine_Sablier;      // Temps de la d�rogation

    i16           i16Consigne_Piscine_Sablier;  // Consigne pendant la d�rogation
    i16           i16Consigne_Piscine_Vacances; // Consigne temperature vacances
} S_MODE_PISCINE;                               // 16 Octets

typedef struct
{
    unsigned char Mode :4;                      // E_FONCT_PISCINE Def ARRET
    unsigned char Exception :3;                 // E_FONCT_EXCEPTION  Def NO_EXCEPTION
    unsigned char u1Spare : 1;
    u8            u8Spare;                      // Unused

    i16           i16Consigne_Eau_Reduit;       // Consigne reduit (chaud ou froid)

    i16           i16Consigne_Eau_Normal;       // Consigne normal (chaud ou froid)
    i16           i16Consigne_Eau_Confort;      // Consigne confort (chaud ou froid)

    i16           i16Consigne_Eau_Froid;        // Consigne temperature en mode Froid
    u16           u16Time_RegExt_Sablier;       // Temps de la d�rogation

    i16           i16Consigne_Eau_Sablier;      // Consigne pendant la d�rogation
    i16           i16Consigne_Eau_Vacances;     // Consigne temperature vacances
} S_MODE_REG_EXT;                               // 16 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DE PARAMETRAGE DE LA REGULATION (Stock�es en E2P)   ">

typedef struct
{
    u16         bModeSecoursDefautPAC:1;        // Def OFF
    u16         bChaudFroidSimultane:1;         // Def FAUX
    u16         bConsoEnergyBallonSurZ2:1;      // Si le Ballon Tampon est > � max plancher alors conso sur Z2 si demande Z1
    u16         bConsoPendantECS_PIS:1;         // Regulation Chauffage Pendant l'ECS ou Piscine
    u16         bGestionCascade:1;              // def FAUX ; si VRAI alors on gere une Cascade de PAC (ie on est la Maitre)
    u16         TypeRegul:3;                    // E_REGUL  def REGUL_DIRECTE
    u16         bCirculateurPrimaireForce:1;    // En previon Mode Auto ou Forcee
    u16         eGestionCirculateurPrimaire:4;  // E_GESTION_CIRCULATEUR
    u16         TypeCirculateur:2;              // E_TYPE_CIRCULATEUR
    u16         bGestionHeureEte:1;             //
//2
    u16         TempNonChauffage:4;             // 0 = OFF sinon 15+valeur en�C soit de 16 � 30�C
    u16         bGestionProductionParallele:1;  // Permet dans le cas d'esclave de faire de l'ECS ou Piscine sur V3V sur la maitre et du CHAUD ou FROID sur les esclaves
    u16         numEsclave:3;                   // Num esclave si Regul Esclave
    u16         bFonction1:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction2:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction3:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction4:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction5:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction6:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction7:1;                   // Activation de fonction (sans entr�e contact)
    u16         bFonction8:1;                   // Activation de fonction (sans entr�e contact)
//4
    u8          u8Consigne_Sablier_Dalle[10];   // Consigne de chauffage dalle en �C en 4 etapes
//14
    u8          u8Time_Vacances;                // Duree des vacances en Jour
    i8          i8Text_Ref_Appoint;             // De -20�C � 40�C
    u8          u8CTime_Vacances_Jour;          // Temps restant vacances en Jour (Mis dans les Params afin de faire la sauvegarde)
    u8          u8CTime_Sablier_Dalle_Jour;     // Temps restant Chauffe Dalle en Jour (Mis dans les Params afin de faire la sauvegarde ; dernier jour perdu)
//18
    i8          i8HysteresisTextMoins;          //
    i8          i8HysteresisTextPlus;           //
    i8          i8HysteresisEauMoins;           //
    i8          i8HysteresisEauPlus;            //
//22
    u16         InxAdaptationLoiDeau    :4;     // def 0 = False ; 1 � 14 = num�ro du contact ; 15 = AUTO ; Pour AutoConso dans l'id�al possibilit� de mettre le m�me contact que la consigne
    u16         InxAdaptationConsigne   :4;     // def 0 = False ; 1 � 14 = num�ro du contact ; 15 = AUTO ; Pour AutoConso
    u16         InxEJP                  :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxCascade              :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxFreeHeating          :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxDelestage :4;                // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxAbaissementConsigne  :4;     // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxTH1                  :4;     // def 0 = False ; 1 � 15 = num�ro du contact
//26
    u16         InxTH2      :4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxMarcheArret:4;               // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxChaudFroid:4;                // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxMarcheArretGeneral :4;       // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxFonction4:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxFonction5:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxFonction6:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
    u16         InxFonction7:4;                 // def 0 = False ; 1 � 15 = num�ro du contact
//30 
    u16         OutxCarter  :3;                 // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxRelevePAC:3;                // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxModeChaudFroid:3;           // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxInfoDefautPAC:3;            // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxChaudFroidVoie1:3;          // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxChaudFroidVoie2:3;          // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxInfoMarcheArret:3;          // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxFonction8:3;                // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxFonction9:4;                // def 0 = False ; 1 � 7  = num�ro du Tor en Sortie
    u16         OutxFonction10:4;               // def 0 = False ; 1 � 15 = num�ro du Tor en Sortie
//34    
    u8          bThermostatContactModeFroid:1;  // def 1; 0 si pas de mode froid; sinon 1
    u8          bConfigCascade120R:1;
    u8          bConfigThermostats120R:1;
    u8          bThermostatModbusExterne:1;
    u8          bSansSondeBallonTampon:1;
    u8          u3Spare:3;
    
    u8          u8Spare;
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
        };
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
    };

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
        };
        struct  // Cas des registres
        {
            unsigned char   u4GestionRegistre       :4;     // E_GESTION_REGISTRE (0 � 100 au pas de 10)
            unsigned char   bRegistreForce          :1;     // Default : false
            unsigned char   bCommandeRegistre       :1;     // E_COMMANDE_EMETTEUR
            unsigned char   u2Spare                 :2;
            
            i8              i8PertesDeCharges;              // Pertes de charges par les gaines (-90% � +90%)
            
            unsigned char   CorrectionDebitAir      :7;     // Correction du d�bit d'air (valeur max de ventilation pour la zone)
            unsigned char   bActivationCorrection   :1;     // Activation de la correction du d�bit d'air
        } Registre;
    };
    
    unsigned short          NumVoieMZ               :3;     // E_NUM_VOIE_OF_BOARD
    unsigned short          NumCarteMZ              :3;     // E_TYPE_CARTE
    unsigned short          TypeEmmetteur           :3;     // E_TYPE_ZONE
    unsigned short          u7VolumePiece           :7;     // Volume de la pi�ce � 5m3 pr�s (jusqu'� 200m3) ; cas r�gul directe 2 zones pourcentage de chaque zone
    
    unsigned char           bModeChaud              :1;     // Default : true
    unsigned char           bModeFroid              :1;     // Default : false
    unsigned char           u2RattachementGroupe    :2;     // E_RATTACHEMENT
    unsigned char           u4ConsigneTeauFroid     :4;     // Temp�rature de d�part d'eau pour fonction rafraichissement (7�C � 22�C)
    // Hysteresis
    i8                      i8HysteresisMoins;
    i8                      i8HysteresisPlus;
    
    u8                      u8LoiDeau[6];       // Loi d'eau
    u8                      u8NomZone[10];      // Nom de la zone max : 10 caract�res
    // Spare
    u8                      u8Spare[6];                 
} S_PARAM_ZX;       // 32 Octets

// Parametres de l'ECS
typedef union
{
    u8 val[12];
    struct
    {
        unsigned char Heure_Legionel:5;             // Def 1H
        unsigned char Jour_Legionel:3;              // Def Lundi
        u8            Time_ECS_Thermo;              // Def 90 min
        u8            Time_Bascul_V3V_ECS;          // Def 120 sec

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

        i8            i8HysteresisECSMoins;         //
        i8            i8HysteresisECSPlus;          //
        
        unsigned char bAppointECS   :1;             //
        unsigned char bBouclageECS  :1;             //
        unsigned char u2TpsFinSimu  :2;             // 0 = 1h; 1 = 2h; 2 = 3h; 3 = pas de fin
        unsigned char u4Spare       :4;             //
    };
} S_PARAM_ECS;                                      // 12 Octets


typedef union
{
    u64 val;
    struct
    {
        unsigned char Time_Bascul_V3V_PISCINE;
        
        unsigned char Type_Gestion_V3V  :1;         // E_TYPE_GESTION_V3V
        unsigned char bConfort          :1;         // False = Normal ; True = trois niveaux de confort
        unsigned char PrioritePiscine   :2;         // E_PRIORITE_PISC Def PISCINE , ajout du simultan�e
        unsigned char NumCarteMZ        :2;         // 0 ==> sortie 5 de la carte N� 1 ;  1 ==> sortie 5 de la carte N�2;   2 ==> sortie 5 de la carte N�3
        unsigned char bAutorisationPiscineEJP:1;    // Autorisation de la pisicne en EJP
        unsigned char bAutorisationPiscineReleve:1; // Autorisation de la piscine en releve chaudiere
        
        i16           i16ConsigneDepartEauPiscine;  // 

        i8            i8HysteresisEauMoins;         //
        i8            i8HysteresisEauPlus;          //

        unsigned char u4DeltaLoiDeauSimultanee :4;  // (de 0 � 15 T�C )Si Production Simultan�e ECS et Chauffage alors R�duction des loi d'eau pour favoriser l'ECS  
        unsigned char bGestionSimultanee       :1;  // Autorise la production ECS et �galement les Zones avec un decalage de loi d'eau 
        unsigned char u3MiniOuvertureVanne     :3;  // 0 = pas de limite chauffage ouverture 70% ; 1 = 30%; ... ; 7=90% Mini Ouverture Vanne m�langeuse ECS ou PW mini si simultan�e (le compl�ment � 100% reste pour les zones ou Piscine )
                                                    // La vanne est obligatoirement celle de la carte ECS
        unsigned char u8Spare;
    };
} S_PARAM_PISCINE;                                 // 8 Octets


typedef struct
{
    unsigned char   bModeFroid : 1;                 // Def Faux
    unsigned char   bModeChaud : 1;                 // Def Faux
    unsigned char   u6Spare : 6;                    // Def Faux

    u8              u4ConsigneEauFroid : 4;         // Temp�rature de d�part d'eau pour fonction rafraichissement en �C
    u8              u4Spare : 4;
    
    u8              u8LoiDeau[6];                   //
} S_PARAM_REG_EXT;                                  // 8 Octets

// Parametres de la carte Frigo
typedef union
{
    u32 val;
    struct
    {
        unsigned char Type_Degivrage  :1;           // E_TYPE_DEGIVRAGE def Normal / Rapide
        unsigned char Type_Liaison    :1;           // E_TYPE_LIAISON   def Normal / Longue
        unsigned char Reduc_PW        :3;           // E_REDUC_PW  def 0 � R7
        unsigned char bModeBoostDemarrage: 1;       // Permet de partir sur un palier plus �lev� au demarrage
        unsigned char u2NiveauSilence :2;           // Choix du niveau de r�duction de bruit (0 = 80%; 1 = 70%; 2 = 30%; 3 = 50%)

        u8            u8Spare;
        u16           u16Spare;
    } ;
} S_PARAM_FRIGO;                                    // 4 Octets

typedef union
{
    u32 val;
    struct
    {
        unsigned char Langue :3;                // E_LANGUE
        unsigned char u5Spare:5;
        u8            u8Spare;
        u16           u16Spare;
    };
} S_PARAM_UTILISATEUR;                          // 4 Octets

// Liste des contacts
typedef struct
{
    u8  Ste_Inst[15];            // Societe de l'installateur
    u8  Nom_Inst[15];            // Nom de l'installateur
    u8  Tel_Inst[15];            // Num telephone installateur
    u8  Port_Inst[15];           // Num portable installateur
    u8  Email_Inst[30];          // Email installateur
    u16 u16Spare;
} S_PARAM_CONTACT;               // 92 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DES DEMANDES VERS FRIGO   ">

typedef union
{
    u64 u64val;                       // 8 Octets Max
    struct
    {
        u8  bCompresseurAdemarrer :1;       // Compresseur avec le moins de temps de fonctionnement; 0 = Compresseur 1; 1 = Compresseur 2
        u8  bModeRafraichissement :1;       // Choix du mode de rafraichissement (freecooling ou froid)
        u8  u6Spare :6;
        u8  u8Spare;
        u16 u16Spare1;
        i16 i16ConsigneTeauFroid;           // Consigne sur le ballon tampon froid captage
        i16 i16BallonTamponFroid;           // Ballon tampon froid sur le circuit captage (chaud / froid simultan�)
    } Geo;
    struct
    {
        i16 i16ConsigneTeauFroid;           // Consigne sur le ballon tampon froid captage
        i16 i16BallonTamponFroid;           // Ballon tampon froid sur le circuit captage (chaud / froid simultan�)
        u8  bModeRafraichissement :1;       // Choix du mode de rafraichissement (freecooling ou froid)
        u8  u7Spare :7;
        u8  u8Spare;
        u16 u16Spare1;
    } geoinverter;
    struct
    {
        i16 i16TeauEcsMilieu;
        i16 i16TeauEcsBas;
        i16 i16TeauPiscine;
        u16 Spare;
    } Cairox;
    struct
    {
        i16 i16TeauEcsBas;
        u16 u16Spare1;
        u16 u16Spare2;
        u16 u16Spare3;
    } ZuranBaguio;
    struct
    {
        u8 bPumpDown_V4V    :1;
        u8 u7Spare          :7;
    } Ajpac;
    struct
    {
        u64 FuturSupplementPhoenix;
    } phoenix;
    struct
    {
        u64 FuturSupplementArktea;
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
typedef union
{
    u32 val;
    struct
    {
        // Carte REG
        u16         bAdaptationLoiDeau : 1;        // report du sInTor choisi
        u16         bAdaptationConsigne: 1;        // report du sInTor choisi
        u16         bTorEJP:1;                     // report du sInTor choisi
        u16         bTorCascade:1;                 // report du sInTor choisi
        u16         bTorFreeHeating:1;             // report du sInTor choisi
        u16         bTorDelestage :1;              // report du sInTor choisi
        u16         bTorAbaissementConsigne :1;    // report du sInTor choisi
        u16         bTorTH1 :1;                    // report du sInTor choisi

        u16         bTorTH2 :1;                    // report du sInTor choisi
        u16         bTorMarcheArret:1;             // report du sInTor choisi
        u16         bTorChaudFroid:1;              // report du sInTor choisi
        u16         bTorMarcheArretGeneral:1;      // report du sInTor choisi
        u16         bTorFonction4:1;               // report du sInTor choisi
        u16         bTorFonction5:1;               // report du sInTor choisi
        u16         bTorFonction6:1;               // report du sInTor choisi
        u16         bTorFonction7:1;               // report du sInTor choisi
        
        u16         u16Spare;
    };
} S_FONCTION_IN_TOR;                                  // 4 Octets

// Demandes Out TOR
typedef union
{
    u16 val;
    struct
    {
        // Carte REG
        u16         bCarter:1;                // etat de la demande
        u16         bRelevePAC:1;             // " 
        u16         bModeFroid:1;             // False = Chaud ; True = Froid
        u16         bInfoDefautPAC:1;         // "
        u16         bChaudFroidVoie1:1;       // "
        u16         bChaudFroidVoie2:1;       // "
        u16         bInfoMarcheArret:1;       // True = marche d'au moins un compresseur ; false = arr�t des compresseurs
        u16         bFonction8:1;             // "
        u16         bFonction9:1;             // "
        u16         bFonction10:1;            // "
        u16         u2PW_Elec :2;             // Puissance appoint electrique
        u16         u4Spare :4;
    };
} S_FONCTION_OUT_TOR;                          // 2 Octets

// Les Statuts de fonctionnement
typedef union
{
    u8 val;
    struct
    {
        u16             S_Mode:5;                   // E_STATUT_PAC ( REG_III ECS et PISCINE sont en bit 3 et bit 4 pour un retour de statut simultan�)
        u16             Appoint:2;                  // E_APPOINT_CHAUFFAGE (REG_III passe de 3 � 2 bits)
        u16             ModifConfig:1;              // Vrai si modification de la config
        u16             ModifConfigSimple:1;        // Vrai si modification de la config de REG partie TYPE_GENERAL
        u16             Mode_Secours:1;             // Def Faux ; Vrai servira � l'affichage
        u16             Exception:3;                // E_STATUT_EXCEPTION
        u16             Test :2;                    // E_STATUT_TEST
        u16             bDerogationPression:1;      // Pression d'Eau

        u16             u16CTime_Sablier_Dalle;     // Temps restant sablier dalle
        
        u16             u16PWinstantaneeProduite;   // Unit� = 10 W

        u16             u16PWinstantaneeConsommee;  // Unit� = 10 W
        u16             u16TpsMiseSousTension;      // Unit� = 1 Heure; depuis la derniere mise sous tension

        u8              u8CTime_Vacances;           // Temps restant vacances en Jour
        u8              u3TypeData : 3;             // Pour faire passer des datas de Debug
        u8              u3RetourAddressePAC: 3;     // 0 = Maitre
        u8              bDerogationPressionBP: 1;
        u8              u1Spare: 1;                 // Spare

        S_FONCTION_IN_TOR  sFonctInxTor;            // 4 Octets
        S_FONCTION_OUT_TOR sFonctOutxTor;           // 2 Octets
        
        u16             au16ListeErreurEnCoursREG[5];// Liste des erreurs en cours
        
        S_IN_TOR_REG    sInTor;                     // 4 Octets
        S_OUT_TOR_REG   sOutTor;                    // 2 Octets
        u8              u8RetourModelePAC;
        u8              u8Spare;                    //
        u32             u32Spare;                   //
    };
} S_STATUT_PAC;                                     // 40 Octets

typedef struct
{
    // partie principale primaire utilis� aussi dans la demande frigo
    union
    {
        u16 ValCommune[5];
        struct 
        {
            i16           i16ConsigneTeauPrimaire;  // Consigne general d'eau primaire
            i16           i16TeauDepart;            // Temp�rature d�part d'eau
            i16           i16TeauRetour;            // Temp�rature retour d'eau
            i16           i16TeauBallonTampon;      // Temp�rature du Ballon
            u16           u16DebitPrimaire;         // d�bit d'eau L/mn
        };
    };
    // Complement de donn�es primaire
    u16           u16In_Pression_Eau;               // Pression d'eau primaire
    u8            u8ConsigneCirculateur;            // Consigne Circulateur
    u8            u8RetourCirculateur;              // Retour Info Circulateur
    u16           u16Spare1;                        // Spare
}S_STATUT_PRIMAIRE;                                 // 16 Octets

typedef struct
{
    i16           i16Tint;                          // Temp�rature de la Zone
    i16           i16ConsigneTint;                  // Consigne de la zone
    i16           i16ConsigneTeau;                  // Temp�rature d�part d'eau
    i16           i16TeauDepart;                    // Temp�rature d�part d'eau
    i16           i16TeauRetour;                    // Temp�rature retour d'eau
    u16           u16Debit;                         // d�bit d'eau L/mn
    u16           u16CTime_Sablier;                 // Temps restant de la d�rogation
    u8            u8ConsigneVanneMelange;           // Consigne vanne de m�lange
    u8            u8ConsigneCirculateur;            // 0 = Arret si > � 0 alors consigne PWM ou Relais = ON

    u8            u8RetourCirculateur;
    u8            u4Mode_RF : 4;
    u8            bTorThermostat:1;                 // est affect� suivant le numero d'entr�e contact voir (Param_Zx)
    u8            bDemandeZoneGainable:1;           // Vrai si une demande de zone group�e 
    u8            u2Spare : 2;
    
    u8            u8ConsigneFanCassette;            // Commande des ventilateurs des gainables (Groupe A et B)
    
    // si pas suffisant alors il faudra le mettre en oeuvre ici et egalement a minima les exceptions sur ECS piscine Regext ()
    // il s'agit d'un statut de la PAC struct�e et donc ne prendre que l'info pour sa PAC
    u8            Mode :4;                          // E_FONCT_ZX
    u8            Exception :3;                     // E_FONCT_EXCEPTION
    u8            u1Spare :1;                       // 
} S_STATUT_ZX;                                      // 20 Octets


typedef struct
{
    i16           i16TeauMilieu;                // Temp�rature ECS Milieu
    i16           i16TeauBas;                   // Temp�rature ECS Bas
    u16           u16CTime_Sablier;             // Temps restant de la d�rogation
    i16           i16TempDepart;                // Temp�rature ECS Depart Voie 1
    i16           i16TempRetour;                // Temp�rature ECS Retour Voie 1
    u8            u8ConsigneCirculateur;        // 0 = Arret ; > 0 alors ON ou PWM Voie 1        
    u8            u8ConsigneVanneMelange;       //
    
    u16           bOutTorV3V_ECS        : 1;    // Sortie TOR
    u16           bOutTorAppoint_ECS    : 1;    // Sortie TOR
    u16           bOutTor_Circulateur   : 1;    // Sortie TOR
    u16           bOutTor_Spare1        : 1;    // Sortie TOR
    u16           bOutTor_Spare2        : 1;    // Sortie TOR
    u16           bInTorECS_Solaire     : 1;    // Entr�e pour r�gulation
    u16           bInTorECS_CompteurEau : 1;
    u16           bInTorECS_Spare       : 1;
    u16           bInTorECS_Spare1      : 1;
    u16           Exception             : 3;    // E_FONCT_EXCEPTION reel de la Reel
    u16           u4Spare               : 4;
    
    u16           i16ConsigneECS;
    
} S_STATUT_ECS;                                 // 16 Octets


typedef struct
{
    i16           i16ConsignePiscine;           // Consigne Piscine
    i16           i16TeauPiscine;               // Temp�rature Piscine
    u16           u16CTime_Sablier;             // Temps restant de la d�rogation
    u8            u8ConsigneVanneMelange;       // 
    u8            bOutTorV3V_Piscine    : 1;    // Si simultan� -> circulateur; sinon -> V3V
    u8            bInTor_Piscine        : 1;    // 
    u8            Exception             : 3;    // E_FONCT_EXCEPTION reel de la Reel
    u8            bOutTorCirculateur    : 1;    // Mettra en fonctionnement le Relais 5 et le PWM 5 de la carte concern�e 
    u8            u2Spare               : 2;    // 
} S_STATUT_PISCINE;                             // 8 Octets

typedef struct
{
    i16           i16ConsigneTeau;              // Consigne Temp�rature Eau
    u16           u16CTime_Sablier;             // Temps de la d�rogation
    u8            Mode      :4;                 // E_FONCT_xxx reel de la Regul
    u8            Exception :3;                 // E_FONCT_EXCEPTION reel de la Reel
    u8            u1Spare   :1;                 // E_FONCT_EXCEPTION reel de la Reel

    u8            u8Spare;
    u16           u16Spare;
    
} S_STATUT_REG_EXT;                             // 8 Octets

typedef struct
{
    u32           u32TpsCompresseur1;           // Sec
    u32           u32TpsCompresseur2;           // Sec
    u32           u32NbCycleCompresseur1;       // Unit� 1
    u32           u32NbCycleCompresseur2;       // Unit� 1
    u32           u32TpsMisesousTensionTotal;   // Sec
} S_STATUT_TPS_FONCT;                           // 20 Octets  Sauvegarde en E2P

typedef union
{
    u64 val;
    struct
    {
        u8 u8OperatingDemande:4;        // F_Arret/F_Chaud/F_Froid [F_Secours]
        u8 u8OperatingMode:4;           // ARRET MARCHE AUTO        // Pas utilis�
        u8 u8NbPacCascadeTotale:4;      // Nombre de PAC dans la cascade (Maitre Inclus)
        u8 u8NbPacCascadeDispo:4;       // Nombre de PAC Dispo
        u8 u8PacInterrogee:4;           // Il s'agit de la PAC interrog�e en DEMANDE et STATUT
        u8 u8PacStructee:4;             // PMA a faire permettra de recup�rer les donn�es de la PAC esclave et de les visualiser sur IHM mettre
        u8 u8OperatingPW;               // Correspond au nombre de PAC en demande (voir appoint Elec)
        i8 i8OperatingDeltaDePAC;       // Nombre de PAC � activer ou d�activer
        u8 u8PacPresente;               // 1 bit par PAC (bit 0 = Maitre)
        u8 u8PacEnMarche;               // A faire Nombre de PAC En Marche ==> a faire 1 bits par PAC pour avoir un etat des PACs qui fonctionnent
        u8 u8Spare;                     // Spare
    } maitre;
    struct
    {
        S_MODELE_PAC maPAC;             // Attention ne doit faire 8 ( m�me taille STATUT_REGUL)
    } esclave;
} S_STATUT_REGUL_ESCLAVE;

// Les Statuts pour faire du Debug de fonctionnement
typedef union
{
    u8 val[32];         // 32 Octets MAX
    struct
    {
        u32             u32Debug1;
        u32             u32Debug2;
        u32             u32Debug3;
        u32             u32Debug4;
        u32             u32Debug5;
        u32             u32Debug6;
        u32             u32Debug7;
        u32             u32Debug8;
    };
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
    u8                      u8TypeDataDebug ;       //   1
    u8                      u8Spare1 ;              //   1
    u8                      u8Spare2 ;              //   1
    u8                      u8Spare3 ;              //   1
    S_STATUT_DEBUG          sStatut_Debug;          //  32
} S_CYCLIQUE_ETHER_REG_REGUL_T2;                    // 196 Octets  

typedef union 
{ 
	u32 val;
	struct 
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
	};
} S_STATUT_RF;

typedef union 
{ 
    u64 u64val;
    struct 
    { 
        i16           Tamb_Zx; 
        i16           Consigne_Zx;
        S_STATUT_RF   sStatutRF;
    };
} S_RETOUR_RF;

typedef union
{
   u16 val;
   struct
   {
      u8    Frequence;
      offon bCompresseur1On :1;
      offon bCompresseur2On :1;
      u8    Palier:6;
   };
}  S_STATUT_COMPRESSEUR;

typedef union 
{ 
   u32 val; 
   struct 
   { 
      unsigned char Mode_Sonde:3;      // E_MODE_SONDE  Def MODE_RIEN
      unsigned char Mode_Prod:3;       // E_MODE_PROD def MODE_ARRET
      unsigned char Erreur_Reg:1;      // d�faut carte de r�gulation
      unsigned char Erreur_Bus:1;      // d�faut de r�ception g�rer par Watts
      unsigned char Icone_Heat_Cool:1; // Affichage ic�ne Heat Cool Off / On
      unsigned char Icone_Auto:1;      // Affichage ic�ne Auto Off / On
      u8 Spare:6;
      i16 Consigne_Zx;                 // 1/10 de �C  199 = 19,9 �C
  } str;
} S_DEMANDE_RF;

typedef union 
{ 
   u32 val;
   struct 
   { 
      i16 i16ConsigneEau; 
      unsigned char bDefaut:1;
      unsigned char u7Spare:7;
      u8 Spare;
   };
} S_SURVEILLANCE_BALLON;

//typedef union //4 bytes
//{
//  u32 u32val;
//  struct
//  {
//    u8 bCirculateur_Off        :1;    // Circulateur Arrete sur demande.
//    u8 bDefautRotorBloque      :1;    // Rotor Bloque -> Arret du circulateur
//    u8 bDefautUnderVoltage     :1;    // Tension Alimentation Circulateur Trop Basse -> Arret du circulateur
//    u8 bRPMSensorFault         :1;    // Capteur de Rotation HS, vitesse circulateur � 14% du minimum
//    u8 bWarningUndervoltage    :1;    // Tension Alimentation Circulateur < 195V
//    u8 bCirculateurOK          :1;    // Pas de defaut circulateur
//    u8 bdummy1                 :1;    // non utilise
//    u8 bdummy2                 :1;    // non utilise
//
//    u8 u8Commande;                    // Commande PWM envoyee au circulateur (0-100%)
//    u8 u8Power;                       // Puissance renvoyee par le circulateur (0-100%)
//    u8 u8FeedBack;                    // PWM renvoye par le Circulateur (0-100%)
//  };
//
//}S_GRUNDFOS_STATUT_ZUBA;

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES DES ENERGIES et HISTORIQUES DE LA REGULATION (Stock�es en Flash)  ">

// Energie produite stock�es en FLASH
typedef struct
{
    u16 Chaud[24];
    u16 Froid[24];
    u16 ECS[24];
    u16 Piscine[24];
    u8  Pointeur;
    u8  u8Dispo;
    u16 u16Spare;
} S_ENERGIE_PROD;           // 196 Octets

// Energie consommee par cat�gorie stock�es en FLASH
typedef struct
{
    u16 Chaud[24];
    u16 Froid[24];
    u16 ECS[24];
    u16 Piscine[24];
    u16 ElecChaud[24];
    u16 ElecECS[24];
    u16 EauECS[24];         // Litres
    u8  Pointeur;
    u8  u8Dispo;
    u16 u16Spare;
} S_ENERGIE_CONSO;          // 340 Octets

// Cumul d'energie consomm�e stock�es en FLASH
typedef struct
{
    u32 Annee_Chaud;
    u32 Annee_Froid;
    u32 Annee_ECS;
    u32 Annee_Piscine;
    u32 Annee_ElecChaud;
    u32 Annee_ElecECS;
    u32 Annee_EauECS;
    S_DATE Annee_Date;
    u32 Partiel_Chaud;
    u32 Partiel_Froid;
    u32 Partiel_ECS;
    u32 Partiel_Piscine;
    u32 Partiel_ElecChaud;
    u32 Partiel_ElecECS;
    u32 Partiel_EauECS;
    S_DATE Partiel_Date_Reset;
    u32 Debut_Chaud;
    u32 Debut_Froid;
    u32 Debut_ECS;
    u32 Debut_Piscine;
    u32 Debut_ElecChaud;
    u32 Debut_ElecECS;
    u32 Debut_EauECS;
    S_DATE Debut_Date;
} S_ENERGIE_CUMUL;          // 108 Octets

// Cumul d'energie consomm�e stock�es en FLASH
typedef union
{
    u8 val[1836];
    struct
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
        u16             Spare;      // Alignement
        unsigned short  CRC;
    };
} S_ENERGIE;                    // 1836 Octets

typedef struct
{
    u16     Defaut[50];
    S_DATE  Date[50];
    u8      Pointeur;
    u8      u8Spare;
    u16     u16Spare;
} S_HISTO_ERR;              // 504 Octets          

// Historique de fonctionnement stock�es en FLASH
typedef struct
{
    u8 Data[512];
} S_LISTE_HISTO;            // (2 page de 256 octets) 512 Octets * 4096 enregistrements en Flash

// Historique de fonctionnement non stock�es permet � l'IHM de venir recup�rer l'histo de fonctionnement
typedef struct
{
    u8      u8TintZx[8];            // en 1/10 �C de 5�C � 30�C pour �tre en u8
    i16     i16Text;                // en 1/10 �C
    i16     i16TeauDepartPrimaire;
    i16     i16TeauRetourPrimaire;
    u16     ModePAC     :5;
    u16     Exception   :3;
    u16     bAppointECS :1;
    u16     bAppointPAC :1;
    u16                 :6;
} S_ENREG_STATUT;                   // 16 Octets

typedef struct
{
    S_ENREG_STATUT  sStatutRegul[360];          // Doit Contenir le Statut PAC et les 2 Appoints (PAC et ECS)
    u16             u16IndexReadWrite;          // 
    u8              u8TimeRecord;               // en Sec
    u8              bComplet : 1;               // VRAI si on a fait un remplissage complet (ie 360 valeurs)
    u8              bRecupEncours : 1;          // pour �viter 2 recup simultan�es (il y a un Timeout sur la r�cup si plus de 30 sec)
    u8              u6Spare : 6;                //
    
} S_ENREG_REGUL;                                // 5764 = 16 Octets * 360 + 4 enregistrements en memoire
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO ZURAN BAGUIO   ">

typedef struct                  // Struture des donn�es qui reviennent par la RC MITSU
{
    u16 Statut;                 //  0	Cyclique TR_E5 // Etat de fonctionnement                        ;;	"Bit 0 � 3 voir �3  ; Bit 4 � 7 (0=Arret,1=Refroidissement,2=Chauffage,3=Degivrage)";;	-	;;	 ;;	BA/ZU
    i16 Intensite;              //  1	Intensit� de service du compresseur (non remont� sur REG2)      ;;	0 a 50			;;	A			;;				;;	BA/ZU
    i16 Temps_Compresseur;      //  2	Temps cumul� de fonctionnement du compresseur(base 10)          ;;	0 a 9999		;;	10 heures	;;				;;	BA/ZU
    i16 Nb_Cycle_Compresseur;   //  3	Nombre de cycles de mise en marche du compresseur (base 100)    ;;	0 a 9999		;;	100 cycles	;;				;;	BA/ZU
    i16 T_Refoulement;          //  4	Temp�rature de refoulement (TH4)                                ;;	3 a 217			;;	�C			;;				;;	BA/ZU
    i16 T_TH6;                  //  7	Unit� ext�rieure temp�rature de tuyau 2 phases(TH6)             ;;	-39 a 88		;;	�C			;;				;;	BA/ZU
    i16 T_Aspiration;           //  8	Unit� ext�rieure temp�rature de tuyau d'aspiration (TH32)       ;;	-39 a 88		;;	�C		;;				;;	ZU
    i16 Text;                   //  9	Cyclique TR_E5 // Unit� ext�rieure temp�rature de l'air ext�rieur(TH7)  ;;	-39 a 88		;;	�C		;;				;;	BA/ZU
    i16 Freq_Compresseur;       //  16	Cyclique TR_E5 // Compresseur fr�quence de service                      ;;	  0 a 255			;;	Hz			;;				;;	BA/ZU
    i16 Freq_Cible;             //  17	Compresseur fr�quence Cible     								;;	0 a 255			;;	Hz			;;				;;	BA/ZU
    i16 Vitesse_Ventilateur1;   //  19	Unit� ext�rieure vitesse ventilateur 1							;;	0 a 9999		;;	Rpm			;;				;;	BA/ZU
    i16 Vitesse_Ventilateur2;   //  20	Unit� ext�rieure vitesse ventilateur 2							;;	0 a 9999		;;	Rpm			;;	��0�� s?affiche si l?unit� ext�rieure est de type � un seul ventilateur			;;	BA/ZU
    i16 Intensite_Primaire;     //  25	Courant primaire												;;	0 a 50			;;	A			;;				;;	BA/ZU
    i16 Tension_DC;             //  26	Tension de bus DC												;;	180 a 370		;;	V			;;				;;	BA/ZU
    i16 Capacite;               //  70	Unit� ext�rieure affichage de r�glage de capacit�				;;	9=35 ; 10=50 ; 11=60 ; 14=71 ; 20=100 ; 25=125 ; 28=140 ; 40=200 ; 50=250			;;				;;				;;	BA/ZU
    i16 Type;                   //  71	Unit� ext�rieure information de r�glage							;;	"Bit 4 � 7 (0= Monophas� PAC CH/FR  ; 1=Monophas� FROID seulement ; 2= Triphas� PAC CH/FR  ; 3=Triphas� FROID seulement ;)Bit 0 � 3 (0=STANDARD ; 1= Pour humidit� �lev�e)"			;;				;;				;;	BA/ZU
    i16 T_TH3;
    i16 Autre;                  //  Autre (non remont� sur REG2)
    i16 T63HS;                  //  14  Pression de saturation (HP R410) -39 � 88�C
    i16 LEVA;                   //  22  Ouverture d�tenteur A de 0 - 500
    i16 LEVB;                   //  23  Ouverture d�tenteur B de 0 - 500
    i16 LEVC;                   //  24  Ouverture d�tenteur C de 0 - 500
    i16 T_HeatSink;             // 10 Temp�rature driver
    i16 T_Liquide2;             //  6	Unit� ext�rieure temp�rature Liquide MonoBloc                   ;;	3 a 217		;;	�C			;;				;;	MONOBLOC BA/ZU 
}S_STATUT_MITSU;                // Total 48 bytes

typedef struct
{
    u16     u16nombretrameInconnue;     //old sPalier_Fan
    i16     i16Resultat_Trame_Ihm_Sav;  //old 16Temp_Frigo_IGBT

    u32     u32CodeErreurMitsu;             

    u8      u8CodeTrameInconnu;         //old sOut_Tor_Fan
    
    u8      bTrameConnue :1;            //old 16Temp_Frigo_Spare
    u8      bAcces_Com_SAV :1;          //old sOut_Tor_Frigo
    u8      bTrame_SAV_IHM_Valide:1;
    u8      u3SousTypePAC_Trouve : 3;   // On met le sous type de PAC trouve ( SOUS_TYPE_UNDEFINED, SOUS_TYPE_BAGUIO, SOUS_TYPE_ZURAN )
    u8      u2TypeRegul_MITSU:2;

    u16     u16Spare;
}S_INFO_TRAME_ZUBA;                     //12 bytes


typedef union // 8 bytes
{
    u64 val;
    struct
    {
        u16         i4Operating_Ability_Zuran   :4 ;
        u16         u4IndexPente                :4 ;
        u16         u4IndexDeltaTC              :4 ;
        u16         bRegulNormal                :1 ;
        u16         u3NbIterationTankInTank_ECS :3 ;
        u8          u8SurchauffeRefoulement;
        u8          u8SousRefroidissement;
        u8          u8ConsigneEau_BaguioPP;
        u8          u8Spare;
        u16         u16Spare;
        //u32         u32Spare;
    };
}S_STATUT_FRIGO_ZUBA;                           // 8 bytes
 // </editor-fold> 

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO FAN AJPAC ">
typedef union //2 bytes
{
    u16 val;
    struct
    {
        unsigned char PalierCompresseur1:5;     // def = 0  (0,..32)
        offon         bCompresseur2     :1;     // Def OFF
        unsigned char :2;
        u8 Spare;
    };
} S_DEMANDE_PW_AJPAC;

//typedef union //2 bytes
//{
//   u16 val;
//   struct
//   {
//      E_LISTE_PW        Pw : 4;           // E_LISTE_PW (MONO 10KW / MONO 16KW  / TRI 16KW /TRI 20KW)
//      unsigned char     Demarreur:1;
//      unsigned char     Compresseur2:1;
//      unsigned char     Spare2:2;
//      u8                Spare;
//   };
//} S_TYPE_ELEC_PW_AJPAC;

typedef struct //4 bytes
{
    u16 u16Position_Pulse_EEV410;
    u16 u16Position_Pulse_EEV134;
}S_STATUT_EEV_AJPAC;


typedef struct // 8 bytes
{
    u32 u32Tps_Fonct_Compresseur_410;
    u32 u32Tps_Fonct_Compresseur_134;
}S_TPS_COMPRESSEUR_AJPAC;

typedef struct  //16 bytes
{
    u8              u8Freq_Comp410;                 // 1    1

    offon           Offon_Comp134 :1;               // 1    2
    unsigned char   Palier_Comp410 :5;
    unsigned char   bDemarrageAutorise :1;
    unsigned char   bDegivrageEnCours :1;
    
    unsigned char   bArretUrgence :1;               // 1    3
    unsigned char   bCondition_Degivrage_1 :1;
    unsigned char   bCondition_Degivrage_2 :1; 
    unsigned char   bCondition_Degivrage_3 :1;
    unsigned char   Spare1 :4;

    u8              u8Fmin;                         // 1    4
    u8              u8Fmax;                         // 1    5

    u8              u8Modeval;                      // 1    6
    u8              u8Mode_Comp;                    // 1    7
    u8              u8Spare;                        // 1    8

    i16             i16Temp_HP410_Cible;            // 2    10
    i16             i16Temp_HP134_Cible;            // 2    12
    
    i16             i16Charge;                      // 2    14
    u16             u16Spare;                       // 2    16
} S_STATUT_FRIGO_AJPAC;


/* * * * * * * * * * * * P O W E R * * * * * * * * * * * */
typedef struct //12 bytes
{
    u16 u16U_Alim_AC;                           /* Tension AC issue de PW     */
    u16 u16I_Alim_AC;                           /* Courant AC issu de PW      */
    u16 u16U_Alim_DC;                           /* Tension DC issue de PW     */
    u16 u16I_Alim_DC;                           /* Courant DC issu de PW      */
    u16 u16U_Compresseur_1;                     /* Tension compresseur 1 (PW) */
    u16 u16I_Compresseur_1;                     /* Courant compresseur 1 (PW) */
}  S_INFO_U_I_AJPAC;
//End AJPOWER

/* * * * * * * * * * * * F A N * * * * * * * * * * * */


typedef union //2 bytes
{
    u16 val;
    struct
    {
        offon TypeDetendeur : 1;
        unsigned char : 7 ;
    };
} S_CONFIG_FAN_AJPAC;

typedef struct // 28 bytes
{
    // Donnees FAN renvoyees vers REG                   // nb   Total
    S_OUT_TOR_FAN_AJPAC  sOutTorFAN;                    // 2    2   Retour Sorties TOR
    i16                  i16Text;                       // 2    4   Temperature externe
    i16                  i16Temp_TEV_IN;                // 2    6
    i16                  i16Temp_TEV_OUT;               // 2    8
    u16                  u16In_Vitesse_Ventilateur_1;   // 2    10
    u16                  u16In_Vitesse_Ventilateur_2;   // 2    12
    u16                  u16Position_Pulse_EEV410BP;    // 2    14
    u16                  au16ListeErreurEnCoursFAN[5];  // 10   24 Liste erreurs carte FAN
    u32                  u32Spare;                      // 4    28
}S_RETOUR_FAN_AJPAC;

typedef struct      // 8 bytes
{
    // Donnees FRIGO renvoyees vers REG pour Demande � la FAN
    i16                     i16Consigne_Pulse_EEV410BP; // 2    2
    S_OUT_TOR_FAN_AJPAC     sOutTorFAN;                 // 2    4   Positionnement des Sorties TOR
    S_CONSIGNE_FAN_AJPAC    sConsigneVentilateur;       // 2    6   Consignes Vitesses des ventilateurs
    S_CONFIG_FAN_AJPAC      sConfigFan;                 // 2    8   
}S_DEMANDE_FAN_AJPAC;


//End AJ-FAN
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO GEOTWIN   ">
typedef union //4 bytes
{
    u32 u32Val ;
    struct 
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
    };
} S_DEFAUT_GEO ;

typedef struct
{
    u64 u64Spare1;
    u64 u64Spare2;
    u32 au32CycleEnCoursCompresseur[NB_COMPRESSEUR_MAX];
    u32 au32CompteurCompresseurArret[NB_COMPRESSEUR_MAX];
} S_TPS_COMPRESSEUR_GEO;        //32 bytes

typedef struct //8 bytes
{
    i16 i16Temp_HP_Cible;
    u16 u16Coef_Poly;
    u16 u16Position_Pulse_EV;
    u16 u16Position_Pulse_SP;
}S_STATUT_EEV_CIBLE_GEO;

typedef struct //8 bytes
{
    u32 u32PWInstCompresseur;       // puissance compresseur suivant table ert condition du Compresseur
    u32 u32PWInstCaptage;           // Puissance instantanee pris sur le captage en Watt
}S_INFO_CONSO_PAC_GEO;

typedef union //2 bytes
{
    u16 val;
    struct
    {
        unsigned char bMachineOK :1;                 // Machine non op�rationnelle
        unsigned char bCycleRetourHuile :1;
        unsigned char bProblemeThermodynamique :1;   // PMA V019 sert � �courter le cycle ECS si plus possible
        unsigned char bCompresseur_1_OK :1;
        unsigned char bCompresseur_2_OK :1;
        unsigned char u3Spare :3;
        
        unsigned char u8Spare;

    };
}S_STATUT_FRIGO_GEO;        // 2 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO CAIROX  ">
typedef struct
{
    i16 i16Tsonde1;         // Octet 3,4,5 ttt/1.6 en �C * 10 en 1/10�C
    //i16 i16Text;            // Octet 32,33
    u16 u16Defaut;          // Octet 34,35
    u16 u16Palier;
    u8  u8ModeCH_FR;        // Octet 28
    u8  u8StatutCH_FR;      // Octet 37
    u8  u8Defrost;          // Octet 31
    u8  u8Spare;
    u16 u16Spare;
}S_IMPROMAT_BRIEF_DATA;     //12 bytes


typedef struct
{
    i8              i8Operating_Ability_Zuran;
    i8              i8Palier_Test_Auto;

    unsigned char   bRegul_Normale :1;
    unsigned char   u7Spare : 7;

    i8              i8Table_Regul_Normale;   //TableDeltaPx

    i8              i8Table_Regul_Lente;     //TableDeltaTc
    u8              u8Hyst_Test_Air;
    u8              u8Hyst_Test_Eau;
    u8              u8Type_Pac;

    u8              u8Index_Pente;
    u8              u8Index_Delta_Tc;
    u16             u16Temps_Restant_MAL_Level;

    u32             u32Spare;
}S_STATUT_FRIGO_CAIROX;                     //16 bytes

typedef struct
{
    unsigned char StatutPac : 1;    // Arret ou Marche
    unsigned char bDegivrage: 1;    // Vrai / Faux 
    unsigned char bDefaut   : 1;    // Vrai / Faux 
    unsigned char bInitUTI  : 1;    // OK   / False 
    unsigned char u4Spare   : 4;    // Vrai / Faux
    u8            u8Spare;
}S_STATUT_IMPROMAT_CAIROX;          //2 bytes
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO & RUKING PHOENIX / GEO INVERTER ">
typedef struct //16 bytes
{
    u16 u16VersionDSP;              //_Add102;
    u16 u16VersionTestDSP;          //_Add103;
    u16 u16NA_Add104;
    u16 u16NA_Add105;
    u16 u16VersionHardware;          //_Add106;
    u16 u16VersionEeprom;           //_Add107;
    
    BOOL bEepromVerifiedFlag : 1;   //_Add108
    unsigned char by7b_Spare : 7;
    u8 u8Spare;
    u16 u16Spare;
}S_VERSION_INFORMATION_RUKING;

typedef union //26 bytes
{
    u8 u8val[26];
    struct 
    {
        BOOL bDSP_ChipReset : 1;            //_Add174Bit0;
        BOOL bDriveFault : 1;               //_Add174Bit1;
        BOOL bCompressorStartup : 1;        //_Add174Bit2;
        BOOL bCompressorRestartup : 1;      //_Add174Bit3;
        BOOL bCompressorRunning : 1;        //_Add174Bit4;
        BOOL bCompressorSpeedStable : 1;    //_Add174Bit5;
        BOOL bCompressorSpeedIncreasing : 1;//_Add174Bit6;
        BOOL bCompressorSpeedDecreasing : 1;//_Add174Bit7;

        BOOL bCompressorSpeedDroopProtection : 1;   //_Add174Bit8;
        BOOL bCompressorSpeedLimitProtection : 1;   //_Add174Bit9;
        BOOL bPFC_ON_OFF : 1;                       //_Add174Bit10;
        unsigned char Spare : 5;                    // i32NA_Add174Bit11_15;

        u16 u16CompressorRunningSpeed;          //_Add175;
        u16 u16CompressorPhaseCurrent;          //_Add176;
        u16 u16AC_InputCurrent;                 //_Add177;
        u16 u16AC_InputVoltage;                 //_Add178;
        u16 u16DC_Voltage;                      //_Add179;
        u16 u16IPM_Temperature;                 //_Add181;
        u16 u16PFC_Temperature;                 //_Add182;
        u16 u16CompressorU_PhaseCurrent;        //_Add184;
        u16 u16CompressorV_PhaseCurrent;        //_Add185;
        u16 u16CompressorW_PhaseCurrent;        //_Add186;
        u16 u16DetectedSpeedByCurrentFrequency; //_Add187;
        u16 u16DLT_Temperature;                 //_Add188;
    };
}S_DRIVE_STATUS_INFORMATION;

typedef struct //12 bytes
{
    char Ruking_Model[12];
}S_RUKING_DRIVER_FRIGO;

typedef union//22 bytes
{
    u8 val[22];
    struct  
    {
        u8      u8Fmin;                     // 1    1
        u8      u8Fmax;                     // 1    2
        u8      u8ConsignePompePuits;       // 1    3
        u8      u8TypeRestriction;          // 1    4
        i16     i16Temp_HP_Cible[2];        // 4    8
        
        i16     i16MaxPressureHP_VS_RPM;    //2     10
        i16     i16MinCondensingTempVSEvap; //2     12
        i16     i16MaxCondensingTempVSEvap; //2     14
        
        u8      u4Demande : 4;
        u8      u3Reduction_PW : 3;
        u8      bMachineOK : 1;
        
        u8      bCycleRetourHuile :1;
        u8      bProblemeThermodynamique : 1;
        u8      bPreHeating : 1;
        u8      u5Spare : 5;

        i16     i16ConsignePrimaire;
        u16     u16Puissance_Produite;
        u16     u16Puissance_Consommee;
    };
}S_STATUT_FRIGO;

typedef union   //32 bytes
{
    u8 val[32];
    struct  
    {
        S_DRIVE_STATUS_INFORMATION      sDriveStatusInformation;// 26       26
        u16 u16CompSpeedDemande;                //_Add300;          2       28
        u16 u16CompStatorPreheatorCurrentDde;   //_Add303;          2       30

        BOOL bCompOnOff : 1;                //_Add299Bit0;
        BOOL bPFC_OnOff : 1;                //_Add299Bit1;
        BOOL bStatorHeatingOnOff : 1;       //_Add299Bit3;
        BOOL bClearFault : 1;               //_Add299Bit5;
        unsigned char Spare : 4;            //_Add299Bit6_7         1       31
        
        u8 u8Spare2;                                            //  1       32         
    };
}S_RETOUR_RUKING_RE;

typedef union
{
    u8 u8Val[32];
    struct
    {
        // Le sous-type + la puissance d�fini les propri�t� de la PAC nbcomp, GAZ, r�versibilit�, ...
        u8 u8NumeroSerie[12];               // A voir si m�me format que UI
        
        u8 u3SousType :3;                   // E_SOUS_TYPE_PHOENIX, E_SOUS_TYPE_GEOINV, ...
        u8 bReversible :1;
        u8 u4TypeGaz :4;                    // E_TYPE_GAZ
        
        u8 u7Puissance :7;                  // 0 -> 128KW
        u8 bSupply : 1;                     // MONO / TRI
        
        u8 u4DebitmetreCaptage :4;          // E_TYPE_DEBITMETRE
        u8 u4DebitmetreChauffage :4;        // E_TYPE_DEBITMETRE
        
        u8 eTypeCirculateurPrimaire :2;
        u8 eTypeVentiloCircCaptage :2;
        u8 bCirculateurPrimaireForce :1;
        u8 bCirculateurCaptageForce :1;
        u8 bFreecooling :1;
        u8 bSpare :1;
        
        u8 eTypeDeCaptage :2;               //E_TYPE_CAPTAGE_GEO;
        u8 u6Spare :6;
        
        u8 eGestionCirculateurPrimaire :4;
        u8 eGestionCirculateurCaptage :4;
        
        u8 u8Spare[12];
        
        u16 u16CRC;
    };
} S_MODELE_FRIGO;

typedef union
{
    u8 u8Val[16];
    struct
    {
        u32 u32TpsFonctC1;
        u32 u32TpsFonctC2;
        u32 u32NbCycleC1;
        u32 u32NbCycleC2;
    };
} S_TPS_FONCTIONNEMENT_FRIGO;

typedef union   //64 bytes
{
    u8 val[64];
    struct
    {
        S_MODELE_FRIGO sModele_FRIGO;                   //32
        S_RUKING_DRIVER_FRIGO sRukingModel_FRIGO;       //12
        S_TPS_FONCTIONNEMENT_FRIGO sTpsFonct_FRIGO;     //16
    };
} S_CONFIG_FRIGO;


typedef union  //4 bytes
{
    u8 val[4];
    struct
    {
        u16 u16Resultat_Trame_Ihm_Sav; 
        u16 u16RequestedRegister;
    };
}S_INFO_TRAME_RUKING;                    
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES FRIGO ARKTEA">
typedef union
{
    u8 val[8];
    struct  
    {
        u8      u4PuissanceDemandee : 4;
        u8      u4Demande : 4;
        
        u8      u3Reduction_PW : 3;
        u8      u2StatutDriver : 2;
        u8      u3Spare : 3;
        
        i16     i16ConsignePrimaire;
        u16     u16Puissance_Produite;
        u16     u16Puissance_Consommee;
    };
}S_STATUT_FRIGO_ARKTEA;

typedef union
{
    u8 val[36];
    struct  
    {
        u16     u16UrmsMoteur1;
        u16     u16UdcMoteur1;
        u8      u8IrmsMoteur1;
        u8      u8IdcMoteur1;
        
        u16     u16UrmsMoteur2;
        u16     u16UdcMoteur2;
        u8      u8IrmsMoteur2;
        u8      u8IdcMoteur2;
        
        u16     u16UrmsMoteur3;
        u16     u16UdcMoteur3;
        u8      u8IrmsMoteur3;
        u8      u8IdcMoteur3;
        
        u16     u16UrmsMoteur4;
        u16     u16UdcMoteur4;
        u8      u8IrmsMoteur4;
        u8      u8IdcMoteur4;
        
        u16     u16DephasageMoteur1;
        u16     u16DephasageMoteur2;
        u16     u16DephasageMoteur3;
        u16     u16DephasageMoteur4;
        
        u8      u8PasConsigneMoteur;
        u8      u8ConsigneMoteur;
        
        u8      u8Consigne;
        u8      u8Spare;
    };
} S_STATUT_DRIVER_EQUIUM;

typedef union
{
    u8 val[12];
    struct
    {
        u16 u16VersionHardware;
        u16 u16VersionSoftware;
        u8 u4TopologieMoteur : 4;
        u8 u4ModeMoteur : 4;
        u8 u8FrequenceMoteur;
        u16 u16RampeMonteeMoteur;
        u16 u16RampeDescenteMoteur;
        u8 u8StepMoteur;
        u8 u8Spare;
    };
} S_CONFIG_DRIVER_EQUIUM; // 12 octets
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES CYCLIQUE FRIGO VERS REG   ">
typedef union
{
    u8 val[124]; 
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

        u8                      u8ConsigneCirculateurPrimaire;  //1         93
        u8                      u8ConsigneCirculateurCaptage;   //1         94
        u8                      u8ConsignePompePuits;           //1         95
        u8                      u8Spare;                        //1         96
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
        u16                         u16Spare;                   //2         36
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
}S_CYCL_REG_FRI_PAC;

typedef union //2 bytes
{
    u16 val;
    struct
    {                                                               //Byte    Cumul 
        u8                      bMaxPW : 1;
        u8                      bFinThermoDynamique : 1;
        u8                      bCycleDegivrage : 1;
        u8                      bPumpDown:1;
        u8                      u4Spare : 4;                        //1         1

        u8                      u8Spare;                            //1         2
    };
}S_CYC_FRI_COMMUN_STATUT; 

typedef union //2 bytes
{
    u16 val;
    struct
    {
        unsigned char bDemandeCirculateurPrimaire : 1;
    };
} S_DEMANDE_FRIGO_TO_REG; //Retour d'une demande venant des frigos vers la REG


typedef struct
{                                                               //Byte    Cumul 
    u16                     au16ListeErreurEnCoursFRIGO[5];     //10        10
    S_DEMANDE_FRIGO_TO_REG  sDemandeFrigoToReg;                 //2         12
    i16                     i16Text;                            //2         14
    u16                     u16NbDegivrage;                     //2         16
    S_CYC_FRI_COMMUN_STATUT sStatut;                            //2         18
    u16                     u16Spare;                           //2         20
    
    u32                     u32Spare;                           //4         24
}S_CYC_FRI_COMMUN;                                              //Total     24 Octets

typedef struct
{                                                               //Byte    Cumul 
    S_CYC_FRI_COMMUN    commun;                                 //24        24
    S_CYCL_REG_FRI_PAC  pac;                                    //Force  a 124 Octets (max AJPAC 104 / GEO 96  / ZUBA 64  / CAIROX 36)
}S_CYCL_REG_FRI;                                                //Total    148 Octets

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="STRUCTURES ETHER et CYCLIQUE ETHER   ">
#define TAILLE_SOFT 8
typedef union //2 bytes
{
    u8 val[80];
    struct
    {               
        u8 Soft_IHM[TAILLE_SOFT];
        u8 Soft_ETH[TAILLE_SOFT];
        u8 Soft_REG[TAILLE_SOFT];
        u8 Soft_FRI[TAILLE_SOFT];
        u8 Soft_FAN[TAILLE_SOFT];
        u8 Soft_ECS[TAILLE_SOFT];
        u8 Soft_MZ[TAILLE_SOFT];
        u8 Soft_RF[TAILLE_SOFT];
        u8 Soft_WIFI[TAILLE_SOFT];
        u8 MacAdress[6];
        u16 u16Spare;
    };
} S_PARAM_ETHER_SOFT_III;		// 80 Octets

typedef union
{
    u8 val[32];
    struct
    { 
        u32_val IpFixe;               // Adresse IP fixe ou defaut

        u16  Port_ihm;
        u16  Port_http;

        u8  bAcces_Distant  :1;     // autorisation a ce connecter au serveur
        u8  bIpFixe         :1;		// si VRAI pas de DHCP on travaille alors avec IpFixe
        u8  bEtherWifi      :1;     // si VRAI utilisation du Wifi pour ce connecter au r�seau local
        u8  bWifiActivated  :1;     // Arret ou Marche du Module
        u8  u4Spare         :4;

        //u8 Spare[xx];  (32-d�ja pris)
    };
} S_PARAM_ETHER_PORT_III;   // 32 Octets	

typedef union
{
    u8 val[192];
    struct
    { 
        u8 WifiDirectName[32];		// nom du wifi Direct
        u8 WifiDirectPW[32];		// Password du wifi Direct

        u8 SSID_Name[32];           // nom du r�seau wifi local du client 
        u8 CleWifi[64];             // Password cle wifi

        u8  bWifiOn : 1;            // alimentation de l'alim module Wifi
        u8  u7Spare : 7;
        
        u8 Timeout;                 // Timeout d'arr�t des �missions des ondes
        
        //u8 Spare[xx];  (192-d�ja pris)
    };
} S_PARAM_ETHER_WIFI_III;           // 192 Octets

typedef union
{
    u8 val[8];
    struct
    { 
        u8 adresse;                 // 1 � 63
        u8 speed;					// 4800 / 9600 / 19200 / 38400 ??

        u8 bGestionTimeOut  :1;		// gestion du timeout (pour stopper la regulation si plus de requete modbus)
        u8 u7TimeOut        :7;     // de 0 � 127 sec : defaut mettre 30 sec ( 2 fois au demarrage ?)
        
        u8 bConfigChange    :1;
        u8 bConfig120R      :1;     // Activation ou non de la r�sistance 120Ohm
        u8 u1NbStopBit      :1;
        u8 u2Parite         :2;
        u8 u3Spare          :3;
    };
} S_PARAM_ETHER_MODBUS_III;       // 8 Octets

typedef union
{
    u8 val[264];
    struct
    { 
        u8 ArkteosServeurName[64];
        u8 CheckIpServeurName[64];
        u8 TimeServeurName[64];
        u8 SpareServeurName[64];

        u16 ArkteosServeurPort;
        u16 CheckIpServeurPort;
        u16 TimeServeurPort;
        u16 SpareServeurPort;
    };
} S_PARAM_SERVEUR_III;  	// 264 Octets
    
typedef union
{
    u8 val[64];
    struct
    { 
        u32_val WIP;         // Format ASCII
        u32_val IP;          // Format ASCII

        u16  au16ListeErreurEnCoursETHER[5];

        u8  bUPNP               :1;
        u8  bAppletConnect      :1;
        u8  bWifiNetworkConnect :1;
        u8  bWifiDirectConnect  :1;
        u8  bModbusConnect      :1;
        u8  bModifConfig        :1;
        u8  bModbusTimeout      :1;
        u8  bIHMConnect         :1;

        u8  u8Spare;
        
        S_IN_TOR_ETHER  sInTorEther;    // 2 Octets
        S_OUT_TOR_ETHER sOutTorEther;   // 2 Octets

        // u8 tabSpare[] le reste (64-deja pris)
    };	
} S_CYC_ETHER_III;					// 64 Octets

typedef union
{
    u64 val;
    struct
    { 
        u8  bModbusTimeout      :1;     // permet de dire � la REG d'arreter sa regulation car il y a une gestion du timeout MODBUS
        u8  bIHMConnect         :1;     // signal � la REG la connexion de la tablette pour forcer une r�cup config
        u8  u6Spare             :6;
        
        // u8 u8Spare[7];
    };	
} S_CYC_ETHER_REG_III;					// 8 Octets

typedef union
{
    u64 val;
    struct
    { 
        u8  u8Spare;
    };	
} S_CYC_ETHER_FRIGO_III;				// 8 Octets 

typedef union
{
    u8 val[12];
    struct
    {
        u8  WIPAddress[4];
		u8	IPAddress[4];
		i8	i8RSSI;

		u8  u2CurrentMode 	:2;			// E_STATE_WIFI
		u8  bSTAConnected 	:1;
		u8  bAPConnected 	:1;
		u8  u2RequestedMode :2;
		u8  u2Spare			:2;

		u8 u8Spare;
		u8 u8Spare1;
    };
} S_CYC_ETHER_WIFI;                     // 12 octets
// </editor-fold>

#endif

// End of file
