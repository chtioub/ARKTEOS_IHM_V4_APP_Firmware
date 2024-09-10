/*
 * arkteos_var_protocole.h
 *
 *  Created on: Jul 29, 2024
 *      Author: info
 */

#ifndef INC_ARKTEOS_VAR_PROTOCOLE_H_
#define INC_ARKTEOS_VAR_PROTOCOLE_H_

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
#include "stdbool.h"
#include "stdint.h"
/*****************************************************************************/
//  STRUCTURE DES TRAMES
/*****************************************************************************/
//    u8    u8    u8       u2+u6          u16       xx          u16
//   Dest  Emet  Comm  Control/S_Com   Nb_Octets   Data   CRC_Modus 0xA001
/*****************************************************************************/
#define TAILLE_BUFFER_UART      512

typedef enum
{
   COM_REC = 0,
   COM_EMET,
   COM_COMMANDE,
   COM_CNTRL,
   COM_LONG_LSB,
   COM_LONG_MSB,
   COM_DATA,
   COM_CRC1,
   COM_CRC2
} E_COM;

typedef struct S_RECEP_COM
{
    uint8_t         eEtatCom;                   // Machine d'état de la communication
    uint8_t         u8RecepteurCom;             // N° de récepteur
    uint8_t         u8EmetteurCom;              // n° de l'émetteur
    uint8_t         u8Commande;                 // Mot de commande

    uint8_t         u8Controle;                 // Controle d'information
    uint8_t         u8SousType;                 // sous type de commande
    uint16_t        u16LongData;                // Longueur des datas

    uint8_t         au8Data[TAILLE_BUFFER_UART];// données

    uint16_t        u16Crc;                     // Checksum complément à 2
    uint16_t        u16TimeOut;                 // TimeOut de la communication

    uint16_t        u16PtrData;                 // Pointeur sur les données
    uint16_t        u16CptOctet;                // Compte les octets bon pour vérifier si erreur

    uint16_t        u16TimeOutReponse;          // Time out pour la réponse
    uint16_t        u16TimeOutRepeat;           // Time out pour la répétition

    uint8_t         u8CaractEmis_n;             // Caractère Emis
    uint8_t         u8CaractEmis_n_1;           // Caractère Emis
    bool            bTrameOK;                   // Trame correct CRC OK
    bool            bTrameRxComplete;           // Trame Complete arrivée

    bool            bTrameTxEncours;            // Trame en cours de création ou d'envoi
    bool            bRepeatTrame;               // Demande de répétition de trame
    bool            bEnvoiEnCours;              // La Trame est en Cours d'envoi
    bool            bErrorCom;                  // Erreur de communication
} SCOM;

typedef enum
{
   MODBUS_REC = 0,
   MODBUS_COMMANDE = 1,
   MODBUS_ERROR = 2,
   MODBUS_REGISTER_MSB = 3,
   MODBUS_REGISTER_LSB = 4,
   MODBUS_QUANTITY_MSB = 5,
   MODBUS_QUANTITY_LSB = 6,
   MODBUS_COUNT_BYTE = 7,
   MODBUS_DATA = 8,
   MODBUS_CRC1 = 9,
   MODBUS_CRC2 = 10,
   MODBUS_FIN = 11,
   MODBUS_ATTENTE_FIN_TRAME = 12
} E_COM_MODBUS;

typedef struct S_RECEP_COM_MODBUS
{
    E_COM_MODBUS eEtatCom;                    // Machine d'état de la communication
    uint8_t          u8RecepteurCom;               // N° de récepteur
    uint8_t          u8EmetteurCom;                // n° de l'émetteur
    uint8_t          u8Commande;                   // Mot de commande
    uint8_t          u8Controle;                   // Controle d'information
    uint8_t          u8SousType;                   // sous type de commande
    uint16_t     u16LongData;                  // Longueur des datas
    uint8_t          au8Data[512];                 // données
    uint16_t     u16Crc;                       // Checksum complément à 2
    uint16_t         u16TimeOut;                   // TimeOut de la communication
    uint16_t         u16PtrData;                   // Pointeur sur les données
    bool        bTrameOK;                     // Trame correct
    bool        bTrameRxComplete;             // Trame fini
    uint8_t          u8CaractEmis_n;               // Caractère Emis
    uint8_t          u8CaractEmis_n_1;             // Caractère Emis
    bool        bErrorCom;                    // Erreur de communication
    uint16_t         u16CptOctet;                  // Compte les octets bon pour vérifier si erreur
    uint16_t         u16TimeOutReponse;            // Time out pour la réponse
    uint16_t         u16TimeOutRepeat;             // Time out pour la répétition
    bool        bRepeatTrame;                 // Demande de répétition de trame
    bool        bEnvoiEnCours;
    bool        bTrameTxEncours;
    uint16_t     u16NumRegistre;               // U16 NumRegistre pour ModBus
    uint16_t     u16QtyRegistre;               // U16 QtyRegistre pour Function WRITE MULTIPLE ModBus
    uint8_t          u8NbData;                     // U8  Nombre de Datas pour Function WRITE MULTIPLE ModBus
    uint8_t          u8LongEntete;                 // Longueur de l'entete en fonction de la fonction et defaut
    bool        bModbusMaitre;                // bModbusMaitre  si Faux alors Esclave si Vrai alors Maitre
    bool        bBadModbusFunction;           // Fonction Modbus inconnue
} SCOM_MODBUS;

/*****************************************************************************/
//  LISTE DES ADRESSES
/*****************************************************************************/
// Adresse des cartes
#define N_ADD_IHM               0x01
#define N_ADD_ETHER             0x02
#define N_ADD_REG               0x04
#define N_ADD_FAN               0x08
#define N_ADD_FRIGO             0x10
#define N_ADD_FRIGO_START       0x10
#define N_ADD_FRIGO_END         0x17
#define N_ADD_POWER             0x20
#define N_ADD_RF                0x40        // Antenne RF
#define N_ADD_RF_B              0x41        // Antenne RF B
#define N_ADD_REG_RF            0x80        // Liaison REG Vers RF
// Adresses de la cascade
#define N_ADD_CASCADE_START     0x20        // Adresse de base des machines en cascade (0x20 -> Maitre ; 0x21 à 0x27 esclaves)
#define N_ADD_CASCADE_MAITRE    0x20
#define N_ADD_CASCADE_ESCLAVE_1 0x21
#define N_ADD_CASCADE_ESCLAVE_2 0x22
#define N_ADD_CASCADE_ESCLAVE_3 0x23
#define N_ADD_CASCADE_ESCLAVE_4 0x24
#define N_ADD_CASCADE_ESCLAVE_5 0x25
#define N_ADD_CASCADE_ESCLAVE_6 0x26
#define N_ADD_CASCADE_ESCLAVE_7 0x27
#define N_ADD_CASCADE_END       0x27
// Adresse des options
#define N_ADD_OPTION_START      0x40        // Adresse de Base des cartes Options
#define N_ADD_OPTION_ECS_START  0x40        // Adresse de Base des cartes ECS
#define N_ADD_OPTION_ECS_END    0x43
#define N_ADD_OPTION_MZ_START   0x44        // Adresse de Base des cartes Multi Zone
#define N_ADD_OPTION_MZ_END     0x49
#define N_ADD_OPTION_END        0x4F
#define N_ADD_OPTION_REG_TIC    0x83        // Liaison TIC tele Information Compteur REG
#define N_ADD_OPTION_WIFI       0x84        // Lisaison vers le module WIFI

/*****************************************************************************/
//  RETOUR DES CONTROLES DE TRAMES
/*****************************************************************************/
#define CONTROL_WRITE                   0x00
#define CONTROL_NACK                    0x40
#define CONTROL_READ                    0x80
#define CONTROL_ACK                     0xC0

/*****************************************************************************/
//  LISTE DES COMMANDES
/*****************************************************************************/
typedef enum
{
    OLD_RECUP_CONFIG=0,                 // commande émise par les IHM afin de récupérer la configuration de la PAC

    RECUP_SOFT,                         // commande émise par Ether afin gérer les BootLoaders, les mises à jour et les démarrages de cartes
    UPLOAD,
    INSTALL_SOFT,
    START,
    RESTART,
    RECUP_CONFIG,                       // commande émise par les IHM afin de récupérer la configuration de la PAC

    CYC_ETHER_REG_FRIGO =0x0a,
    CYC_ETHER_REG_REGUL =0x0b,
    CYC_ETHER           =0x0c,

    C_USER              =0x10,          // les commandes à la demande de l'Utilisateur USER
    C_USER_PROG,                        // les commandes à la demande de l'Utilisateur USER pour la PROGRAMMATION
    C_USER_ENERGIE,                     // les commandes à la demande de l'Utilisateur USER pour les ENERGIES
    C_INSTALL,                          // les commandes de l'installateur / paramétrage
    C_INSTALL_THERMOSTAT,               // les commandes de l'installateur / paramétrage liées au thermostat Sonde RF / Modbus ?
    C_USINE,                            // les commandes USINE configuration PAC
    C_SAV,                              // les commandes pour Le SAV configuration PAC
    C_WEB,                              // les commandes spécifiques demandées par des appli type IHM
    C_MODBUS,                           // Commandes pour faire passer des commandes Modbus dans une Trame EHER REG
    C_MODULE_WIFI,                      // Commandes pour faire passer des commandes sur le WIFI (exemple nom ? clé ? , ..)
    C_TESTS_FONCTIONNELS= 0x1F,

    C_WIFI              = 0xE0,
    C_IHM_TABLETTE      = 0xE1,
    C_DEBUG             = 0xFE,
} E_COMMANDE_COMMUNE;

typedef enum
{
   CYC_REG_FAN = 0x40,
   CYC_REG_FRIGO = 0x41,
} E_COMMANDE_REG_FRIGO;

typedef enum
{
   C_REG_RF = 0x10,
   C_REG_xx,
} E_COMMANDE_REG_RF;

typedef enum
{
   C_REG_ESCLAVE_CONFIG,
   C_REG_ESCLAVE_CYCLIQUE,
} E_COMMANDE_REG_ESCLAVE;

typedef enum
{
   C_REG_OPTION_CYCLIQUE,
   C_REG_OPTION_xx,
} E_COMMANDE_REG_OPTION;

typedef enum
{
   C_REG_TIC_CYCLIQUE,
   C_REG_TIC_xx,
} E_COMMANDE_REG_TIC;

/*****************************************************************************/
//  LISTE DES SOUS-COMMANDES
/*****************************************************************************/
typedef enum
{
    SC_CYC_T1,              // Utilise dans la cas des trames Regul sont longues (environ 340 octets)  dans la Sous_Cyclique T1 il y a tout sauf les Statuts Zones de 3 à 10
    SC_CYC_T2,              // S'il y a plus de 2 Zones alors on envoie alternativement T1 puis T2 sinon que T1 ( T2 c'est les Zones 3 à 10 soit 160 octets)
} E_SC_CYC_ETHER_REG_REGUL;

typedef enum
{
    SC_RECUP_GENERAL = 0,
    SC_RECUP_TRAME2,
    SC_RECUP_CONFIG_PHOENIX,
} E_SC_RECUP;

typedef enum
{
    SC_UPLOAD_GENERAL = 0,
    SC_UPLOAD_START,
    SC_UPLOAD_END,
    SC_UPLOAD_ERROR,
} E_SC_UPLOAD;

typedef enum
{
    SC_PARAM_Z1,
    SC_PARAM_Z2,
    SC_PARAM_Z3,
    SC_PARAM_Z4,
    SC_PARAM_Z5,
    SC_PARAM_Z6,
    SC_PARAM_Z7,
    SC_PARAM_Z8,
    SC_PARAM_Z9,
    SC_PARAM_Z10,
    SC_PARAM_REG_EXT,
    SC_PARAM_ECS,
    SC_PARAM_PISCINE,
    SC_PARAM_ZX,        // regroupe tous les Param précédent

    SC_INSTALL_PARAM,
    SC_INSTALL_DATE_INSTALL,
    SC_INSTALL_RAZ_HISTO_ERR,
    SC_INSTALL_RAZ_CONFIG,
    SC_INSTALL_CONFIG_PAC,
    SC_INSTALL_INSTALL_PAC,
    SC_INSTALL_ETHER_PORT,  // a Destination de Ether pour paramètrage
    SC_INSTALL_ETHER_SEVEUR,// "
    SC_INSTALL_MODBUS,      // "
    SC_INSTALL_WIFI,        // "
} E_SC_INSTALL;

typedef enum
{
    SC_USER_Z1,
    SC_USER_Z2,
    SC_USER_Z3,
    SC_USER_Z4,
    SC_USER_Z5,
    SC_USER_Z6,
    SC_USER_Z7,
    SC_USER_Z8,
    SC_USER_REG_EXT,
    SC_USER_ECS,
    SC_USER_PISCINE,
    SC_USER_PARAM,
    SC_USER_CONTACT,
    SC_USER_INFO,
    SC_USER_VACANCES,
    SC_USER_DATE,
    SC_USER_ZX,     // Toutes les sMode
} E_SC_USER;

typedef enum
{
    SC_PROG_CHAUD_Z1,
    SC_PROG_CHAUD_Z2,
    SC_PROG_CHAUD_Z3,
    SC_PROG_CHAUD_Z4,
    SC_PROG_CHAUD_Z5,
    SC_PROG_CHAUD_Z6,
    SC_PROG_CHAUD_Z7,
    SC_PROG_CHAUD_Z8,
    SC_PROG_FROID_Z1,
    SC_PROG_FROID_Z2,
    SC_PROG_FROID_Z3,
    SC_PROG_FROID_Z4,
    SC_PROG_FROID_Z5,
    SC_PROG_FROID_Z6,
    SC_PROG_FROID_Z7,
    SC_PROG_FROID_Z8,
    SC_PROG_EXT_CHAUD,
    SC_PROG_EXT_FROID,
    SC_PROG_ECS,
    SC_PROG_PISCINE,
    SC_PROG_OPTIONS,
    SC_PROG_MODE_SILENCE,
} E_SC_USER_PROG;

typedef enum
{
    SC_ENER_CONS_12M,
    SC_ENER_CONS_24H,
    SC_ENER_CONS_24J,
    SC_ENER_CUMUL_CONS,
    SC_ENER_CUMUL_PROD,
    SC_ENER_PROD_12M,
    SC_ENER_PROD_24H,
    SC_ENER_PROD_24J,
    SC_ENER_RAZ_DATE,
} E_SC_USER_ENERGIE;

typedef enum
{
    SC_INSTALL_TH_ASSO_Z1,
    SC_INSTALL_TH_ASSO_Z2,
    SC_INSTALL_TH_ASSO_Z3,
    SC_INSTALL_TH_ASSO_Z4,
    SC_INSTALL_TH_ASSO_Z5,
    SC_INSTALL_TH_ASSO_Z6,
    SC_INSTALL_TH_ASSO_Z7,
    SC_INSTALL_TH_ASSO_Z8,
    SC_INSTALL_TH_ASSO_Z9,
    SC_INSTALL_TH_ASSO_Z10,
    SC_INSTALL_TH_DISSO_Z1,
    SC_INSTALL_TH_DISSO_Z2,
    SC_INSTALL_TH_DISSO_Z3,
    SC_INSTALL_TH_DISSO_Z4,
    SC_INSTALL_TH_DISSO_Z5,
    SC_INSTALL_TH_DISSO_Z6,
    SC_INSTALL_TH_DISSO_Z7,
    SC_INSTALL_TH_DISSO_Z8,
} E_SC_INSTALL_THERMOSTAT;

typedef enum
{
    SC_SAV_HISTO_ERR,
    SC_SAV_HISTO_FONCT,
    SC_SAV_PARAM,
    SC_SAV_PASSWORD,
    SC_SAV_SHUNT_TEMPO,
    SC_SAV_TEST_CPS,
    SC_SAV_TEST_CPS_START,
    SC_SAV_TEST_CPS_STOP,
    SC_SAV_TEST_PAC,
    SC_SAV_TEST_PAC_STOP,
    SC_SAV_VISU_SYSTEME,
    SC_SAV_FONCT_TR,
    SC_SAV_PAR21,
    SC_SAV_ACTION_CPS,
    SC_SAV_ENREG_REGUL,   // Les 4 octets du READ sont : octet 1 et 2 = {ENREG_START,ENREG_NEXT,CLEAR_ENREG,SET_ENREG} ; octet 3 et 4 nbOctet Request
    SC_SAV_ETHER,
    SC_SAV_RAZ_LOG,
    SC_SAV_RAZ_SOFT_FLASH,
    SC_SAV_RAZ_TPS_FONCT,
    S_TYPE_PUMP_DOWN_RECUP_UI,
    S_TYPE_PUMP_DOWN_RECUP_UE,
    S_TYPE_PUMP_DOWN_STOP,
} E_SC_SAV;

typedef enum
{
    SC_USINE_GENERAL,       // NU
    SC_USINE_PARAM,
    SC_USINE_PARAM2,
    SC_USINE_INSTALL_PAC,
    SC_USINE_PASSWORD,
    SC_USINE_RAZ_CONFIG,
    SC_USINE_RAZ_ENERGIE,
    SC_USINE_RAZ_INSTALL,
    SC_USINE_ELEC_PW_FRIGO, // NU
} E_SC_USINE;

typedef enum
{
    SC_WEB_GENERAL,
    SC_WEB_HISTO_ERR,
    SC_WEB_HISTO_FONCT,
    SC_WEB_FONCT_TR,
} E_SC_WEB;

typedef enum
{
    SC_MODBUS_xx,
} E_SC_MODBUS;

typedef enum
{
    SC_TF_START = 0,
    SC_TF_TESTS_OK = 1,
    SC_TF_TESTS_KO = 2,
} E_SC_TESTS_FONCTIONNELS;

typedef enum
{
    SC_STRUCT_INIT,
    SC_CYC_ETHER_WIFI,
    SC_DATE_TIME,
} E_SC_MODULE_WIFI;

typedef enum
{
    SC_IHM_ON_OFF,
} E_SC_IHM_TABLETTE;

typedef enum
{
    SC_DEBUG_00,
    SC_DEBUG_01,
    SC_DEBUG_02,
    SC_DEBUG_03,
    SC_DEBUG_04,
    SC_DEBUG_05,
    SC_DEBUG_06,
    SC_DEBUG_07,
    SC_DEBUG_08,
    SC_DEBUG_09,
    SC_DEBUG_10,
    SC_DEBUG_HISTO_ERR,
    SC_DEBUG_HISTO_FONCT,
    SC_DEBUG_FONCT_TR,
} E_SC_DEBUG;

typedef enum
{
    SC_ENREG_START,
    SC_ENREG_NEXT,
    SC_CLEAR_ENREG,
    SC_SET_ENREG
} E_SC_SAV_ENREG_REGUL;

typedef enum
{
    SC_SAV_PARAM_DEROG,
    SC_SAV_PARAM_FREQ_HISTO
} E_SC_SAV_PARAM;

/*****************************************************************************/
// COMMANDES MODBUS
/*****************************************************************************/
#define MODBUS_READ_HOLDING_REGISTER    0x03
#define MODBUS_READ_INPUT_REGISTER      0x04
#define MODBUS_WRITE                    0x06
#define MODBUS_WRITE_MULTIPLE           0x10

/*****************************************************************************/
// EXCEPTIONS MODBUS
/*****************************************************************************/
#define MODBUS_EXCEPTION                0x80
#define MODBUS_NO_EXCEPTION             0x00
#define MODBUS_EXCEPTION_FUNCTION       0x01
#define MODBUS_EXCEPTION_REGISTER       0x02
#define MODBUS_EXCEPTION_NB_REGISTER    0x03
#define MODBUS_EXCEPTION_READ           0x04
#define MODBUS_EXCEPTION_BAD_VALUE      0x05
#define MODBUS_EXCEPTION_NACK           0x07

/*****************************************************************************/
//  TABLE DE CALCUL DU CRC
/*****************************************************************************/
#define TABLE_CALCUL_CRC {\
    0x0000, 0xc0c1, 0xc181, 0x0140, 0xc301, 0x03c0, 0x0280, 0xc241,\
    0xc601, 0x06c0, 0x0780, 0xc741, 0x0500, 0xc5c1, 0xc481, 0x0440,\
    0xcc01, 0x0cc0, 0x0d80, 0xcd41, 0x0f00, 0xcfc1, 0xce81, 0x0e40,\
    0x0a00, 0xcac1, 0xcb81, 0x0b40, 0xc901, 0x09c0, 0x0880, 0xc841,\
    0xd801, 0x18c0, 0x1980, 0xd941, 0x1b00, 0xdbc1, 0xda81, 0x1a40,\
    0x1e00, 0xdec1, 0xdf81, 0x1f40, 0xdd01, 0x1dc0, 0x1c80, 0xdc41,\
    0x1400, 0xd4c1, 0xd581, 0x1540, 0xd701, 0x17c0, 0x1680, 0xd641,\
    0xd201, 0x12c0, 0x1380, 0xd341, 0x1100, 0xd1c1, 0xd081, 0x1040,\
    0xf001, 0x30c0, 0x3180, 0xf141, 0x3300, 0xf3c1, 0xf281, 0x3240,\
    0x3600, 0xf6c1, 0xf781, 0x3740, 0xf501, 0x35c0, 0x3480, 0xf441,\
    0x3c00, 0xfcc1, 0xfd81, 0x3d40, 0xff01, 0x3fc0, 0x3e80, 0xfe41,\
    0xfa01, 0x3ac0, 0x3b80, 0xfb41, 0x3900, 0xf9c1, 0xf881, 0x3840,\
    0x2800, 0xe8c1, 0xe981, 0x2940, 0xeb01, 0x2bc0, 0x2a80, 0xea41,\
    0xee01, 0x2ec0, 0x2f80, 0xef41, 0x2d00, 0xedc1, 0xec81, 0x2c40,\
    0xe401, 0x24c0, 0x2580, 0xe541, 0x2700, 0xe7c1, 0xe681, 0x2640,\
    0x2200, 0xe2c1, 0xe381, 0x2340, 0xe101, 0x21c0, 0x2080, 0xe041,\
    0xa001, 0x60c0, 0x6180, 0xa141, 0x6300, 0xa3c1, 0xa281, 0x6240,\
    0x6600, 0xa6c1, 0xa781, 0x6740, 0xa501, 0x65c0, 0x6480, 0xa441,\
    0x6c00, 0xacc1, 0xad81, 0x6d40, 0xaf01, 0x6fc0, 0x6e80, 0xae41,\
    0xaa01, 0x6ac0, 0x6b80, 0xab41, 0x6900, 0xa9c1, 0xa881, 0x6840,\
    0x7800, 0xb8c1, 0xb981, 0x7940, 0xbb01, 0x7bc0, 0x7a80, 0xba41,\
    0xbe01, 0x7ec0, 0x7f80, 0xbf41, 0x7d00, 0xbdc1, 0xbc81, 0x7c40,\
    0xb401, 0x74c0, 0x7580, 0xb541, 0x7700, 0xb7c1, 0xb681, 0x7640,\
    0x7200, 0xb2c1, 0xb381, 0x7340, 0xb101, 0x71c0, 0x7080, 0xb041,\
    0x5000, 0x90c1, 0x9181, 0x5140, 0x9301, 0x53c0, 0x5280, 0x9241,\
    0x9601, 0x56c0, 0x5780, 0x9741, 0x5500, 0x95c1, 0x9481, 0x5440,\
    0x9c01, 0x5cc0, 0x5d80, 0x9d41, 0x5f00, 0x9fc1, 0x9e81, 0x5e40,\
    0x5a00, 0x9ac1, 0x9b81, 0x5b40, 0x9901, 0x59c0, 0x5880, 0x9841,\
    0x8801, 0x48c0, 0x4980, 0x8941, 0x4b00, 0x8bc1, 0x8a81, 0x4a40,\
    0x4e00, 0x8ec1, 0x8f81, 0x4f40, 0x8d01, 0x4dc0, 0x4c80, 0x8c41,\
    0x4400, 0x84c1, 0x8581, 0x4540, 0x8701, 0x47c0, 0x4680, 0x8641,\
    0x8201, 0x42c0, 0x4380, 0x8341, 0x4100, 0x81c1, 0x8081, 0x4040\
}
// Exemple de declaration à mettre dans votre gestion des uarts
// u16 wCRCTable[256] = TABLE_CALCUL_CRC; pour déclarer la table en mémoire
// ou en constante const u16 wCRCTable[256] = TABLE_CALCUL_CRC;  pour déclarer la table en Flash
// Exemple de calcul CRC pour un Car ; u16Crc doit être initialisé à 0xFFFF;

//u16 CrcCar (uint8_t u8Car, u16 u16Crc)
//{
//    u16Crc = (u16Crc >> 8) ^ wCRCTable[((u16Crc) ^ ((u16) u8Car & 0xff)) & 0xff];
//    return u16Crc;
//}
//u16 CrcTrame (uint8_t* Trame, u16 nbChar) Non Testé
//{
//    u16 index , u16Crc = 0xFFFF;
//
//    for ( index = 0 ; index < nbChar ; index++)
//        u16Crc = (u16Crc >> 8) ^ wCRCTable[((u16Crc) ^ ((u16) *Trame++ & 0xff)) & 0xff];
//    return u16Crc;
//}


#endif /* INC_ARKTEOS_VAR_PROTOCOLE_H_ */
