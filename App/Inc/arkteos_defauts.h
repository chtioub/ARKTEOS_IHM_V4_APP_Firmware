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

#ifndef _ARKTEOS_DEFAUTS_H_
#define _ARKTEOS_DEFAUTS_H_

/*****************************************************************************/
//  DEFINES
/*****************************************************************************/
#define NB_MAX_DEFAUTS          1000    // Numéro max de défaut
#define MAX_DEFAUTS_CARTE       5       // Nombre de défauts max par carte
// Masque et attributs
#define MASK_DEFAUT             0x03FF  // Masque des défauts
#define DEFAUT_NV_IHM           0x8000  // Non visible depuis l'IHM
#define DEFAUT_NV_TH            0x4000  // Non visible depuis le Thermostat
#define DEFAUT_BLOQUANT         0x0800  // Entraine l'arrêt de la demande et fait passer la regulation en mode secours si l'option "En Cas Defaut PAC" est activé
#define DEFAUT_NV_HISTORIQUE    0x0400  // Non visible depuis l'historique du menu maintenance
#define T_DEF_ALERTE            0x0000  // Valeur par defaut ou ne rien mettre ; affichage en Jaune sur l'IHM
#define T_DEF_DEFAUT            0x1000  // affichage en Rouge sur l'IHM
#define T_DEF_SPARE1            0x2000  // NU ; Niveau de defaut 2

/*****************************************************************************/
//  DEFAUTS
/*****************************************************************************/
typedef enum
{
    // ERREURS
	// Erreurs soft ETHER (0 -> 29)
    // Erreurs de BOOT
    ERR_BOOT_ETHER              =  10 | T_DEF_DEFAUT,
	ERR_BOOT_REG                =  11 | T_DEF_DEFAUT,
	ERR_BOOT_FAN				=  12 | T_DEF_DEFAUT,
	ERR_BOOT_PW					=  13 | T_DEF_DEFAUT,
	ERR_BOOT_FRIGO				=  14 | T_DEF_DEFAUT,
	ERR_BOOT_IHM				=  15 | T_DEF_DEFAUT,
	ERR_BOOT_RF					=  16 | T_DEF_DEFAUT,
    ERR_BOOT_DHW				=  17 | T_DEF_DEFAUT,
    ERR_BOOT_MZ					=  18 | T_DEF_DEFAUT,
	// Erreurs soft REG (30 -> 134)
    INFO_FONCT_CHAUDIERE        =  30 | DEFAUT_NV_IHM,
    // Erreurs débits
    ERR_DEBIT_PRIMAIRE          =  40 | T_DEF_DEFAUT,
    ERR_DEBIT_Z1                =  41 | T_DEF_DEFAUT,
    ERR_DEBIT_Z2                =  42 | T_DEF_DEFAUT,
    ERR_DEBIT_Z3                =  43 | T_DEF_DEFAUT,
    ERR_DEBIT_Z4                =  44 | T_DEF_DEFAUT,
    ERR_DEBIT_Z5                =  45 | T_DEF_DEFAUT,
    ERR_DEBIT_Z6                =  46 | T_DEF_DEFAUT,
    ERR_DEBIT_Z7                =  47 | T_DEF_DEFAUT,
    ERR_DEBIT_Z8                =  48 | T_DEF_DEFAUT,
    ERR_DEBIT_GROUPE_A          =  49 | T_DEF_DEFAUT,
    ERR_DEBIT_GROUPE_B          =  50 | T_DEF_DEFAUT,
    // Erreurs Températures intérieures
    ERR_TINT_Z1                 =  51 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z2                 =  52 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z3                 =  53 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z4                 =  54 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z5                 =  55 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z6                 =  56 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z7                 =  57 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TINT_Z8                 =  58 | T_DEF_DEFAUT | DEFAUT_NV_TH, 
    // Erreurs sondes d'eau départ
    ERR_TEAU_Z1_DEPART          =  61 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z2_DEPART          =  62 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z3_DEPART          =  63 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z4_DEPART          =  64 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z5_DEPART          =  65 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z6_DEPART          =  66 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z7_DEPART          =  67 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z8_DEPART          =  68 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_GROUPE_A_DEPART    =  69 | T_DEF_DEFAUT | DEFAUT_NV_TH,    
    ERR_TEAU_GROUPE_B_DEPART    =  70 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    // Erreurs sondes d'eau retour
    ERR_TEAU_Z1_RETOUR          =  71 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z2_RETOUR          =  72 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z3_RETOUR          =  73 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z4_RETOUR          =  74 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z5_RETOUR          =  75 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z6_RETOUR          =  76 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z7_RETOUR          =  77 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_Z8_RETOUR          =  78 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_GROUPE_A_RETOUR    =  79 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_GROUPE_B_RETOUR    =  80 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    // Erreurs sondes primaires
    ERR_TEAU_PRIM_DEPART        = 104 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TEAU_PRIM_RETOUR        = 105 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TEAU_BALLON_TAMPON_FROID = 107 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    // Erreurs sondes options
    ERR_TEAU_PISCINE            = 110 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_ECS_MILIEU         = 111 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_ECS_BAS            = 112 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    // Erreurs
    ERR_SYSTEM                  = 114 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,     // Erreur system (longueur de trame incohérente, etc ....)
    ERR_PRESSION_EAU_CHAUFFAGE  = 115 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_IN_COMPTAGE_PW          = 116 | DEFAUT_NV_TH,
    ERR_EEPROM                  = 117 | T_DEF_DEFAUT,
    ERR_FLASH                   = 118 | T_DEF_DEFAUT,
    ERR_RTC                     = 119 | T_DEF_DEFAUT,
    ERR_RS485_FRIGO             = 120 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_RS485_FAN               = 121 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_RS485_RF                = 122 | T_DEF_DEFAUT,
    ERR_TEAU_BALLON_TAMPON      = 123 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_DEPART_ATTEINT_ECS = 124 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_ASSOCIATION_MULTIPLE_RF = 125 | T_DEF_DEFAUT | DEFAUT_NV_TH,    // pour toutes les sondes RF
    ERR_RS485_MODBUS            = 127 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_ESCLAVE_REPONSE         = 128 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_MAUVAISE_CONFIG_CASCADE = 129 | T_DEF_DEFAUT,
    ERR_ESCLAVE_RECEPTION       = 130 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_OPTION_ECS_RECEPTION    = 131 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_OPTION_MZ1_RECEPTION    = 132 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_OPTION_MZ2_RECEPTION    = 133 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_OPTION_MZ3_RECEPTION    = 134 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_CONFIGURATION_PAC       = 135 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    // ALERTES
    ALERTE_TEAU_PRIM_DEPART     = 604 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_PRIM_RETOUR     = 605 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    // Alertes sondes options
    ALERTE_TEAU_PISCINE         = 610 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_ECS_MILIEU      = 611 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_ECS_BAS         = 612 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    // Alertes
    ALERTE_PRESSION_EAU_CHAUFFAGE= 615 | DEFAUT_NV_TH,
    ALERTE_IN_COMPTAGE_PW       = 616 | DEFAUT_NV_TH,
    ALERTE_DEFAUT_APPOINT       = 617,
    ALERTE_MAJ_HEURE            = 618 | DEFAUT_NV_TH,
    // Alertes sondes inversées
    ALERTE_SONDES_ECS_ENVERS    = 619 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z1_ENVERS     = 620 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z2_ENVERS     = 621 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z3_ENVERS     = 622 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z4_ENVERS     = 623 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z5_ENVERS     = 624 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z6_ENVERS     = 625 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z7_ENVERS     = 626 | DEFAUT_NV_TH,
    ALERTE_SONDES_Z8_ENVERS     = 627 | DEFAUT_NV_TH,
    ALERTE_SONDES_GROUPE_A      = 628 | DEFAUT_NV_TH,
    ALERTE_SONDES_GROUPE_B      = 629 | DEFAUT_NV_TH,
    // Alertes
    ALERTE_TEAU_BALLON_TAMPON   = 631 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_APPOINT_ECS          = 632 | DEFAUT_NV_TH,
    ALERTE_ANTIGEL              = 633 | DEFAUT_NV_TH,
    ALERTE_HYST_GEO             = 634 | DEFAUT_NV_TH,
    ALERTE_CONFIG_REGULATION    = 635 | DEFAUT_NV_TH,
    ALERTE_CONF_CHAUFFAGE_ECS   = 637 | DEFAUT_NV_TH,
    ALERTE_CONF_CHAUFFAGE_PISCINE=638 | DEFAUT_NV_TH,
    ALERTE_CHOIX_VOIE_CARTE     = 639 | DEFAUT_NV_TH, 
    // Alertes débits
    ALERTE_DEBIT_PRIMAIRE       = 640,
    ALERTE_DEBIT_Z1             = 641,
    ALERTE_DEBIT_Z2             = 642,
    ALERTE_DEBIT_Z3             = 643,
    ALERTE_DEBIT_Z4             = 644,
    ALERTE_DEBIT_Z5             = 645,
    ALERTE_DEBIT_Z6             = 646,
    ALERTE_DEBIT_Z7             = 647,
    ALERTE_DEBIT_Z8             = 648,
    ALERTE_DEBIT_GROUPE_A       = 649,
    ALERTE_DEBIT_GROUPE_B       = 650,
    // Alertes températures intérieures
    ALERTE_TINT_Z1              = 651 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z2              = 652 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z3              = 653 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z4              = 654 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z5              = 655 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z6              = 656 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z7              = 657 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TINT_Z8              = 658 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    // Alertes sondes d'eau départ
    ALERTE_TEAU_Z1_DEPART       = 661 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z2_DEPART       = 662 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z3_DEPART       = 663 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z4_DEPART       = 664 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z5_DEPART       = 665 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z6_DEPART       = 666 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z7_DEPART       = 667 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z8_DEPART       = 668 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_GROUPE_A_DEPART = 669 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_GROUPE_B_DEPART = 670 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    // Alertes sondes d'eau retour
    ALERTE_TEAU_Z1_RETOUR       = 671 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z2_RETOUR       = 672 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z3_RETOUR       = 673 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z4_RETOUR       = 674 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z5_RETOUR       = 675 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z6_RETOUR       = 676 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z7_RETOUR       = 677 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_Z8_RETOUR       = 678 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_GROUPE_A_RETOUR = 679 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEAU_GROUPE_B_RETOUR = 680 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    // Alertes piles faibles sondes RF
    ALERTE_PILE_RF1             = 681 | DEFAUT_NV_TH,
    ALERTE_PILE_RF2             = 682 | DEFAUT_NV_TH,
    ALERTE_PILE_RF3             = 683 | DEFAUT_NV_TH,
    ALERTE_PILE_RF4             = 684 | DEFAUT_NV_TH,
    ALERTE_PILE_RF5             = 685 | DEFAUT_NV_TH,
    ALERTE_PILE_RF6             = 686 | DEFAUT_NV_TH,
    ALERTE_PILE_RF7             = 687 | DEFAUT_NV_TH,
    ALERTE_PILE_RF8             = 688 | DEFAUT_NV_TH,
    // Alerte de puissance de réception des sondes RF
    ALERTE_RECEP_RF1            = 691 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF2            = 692 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF3            = 693 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF4            = 694 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF5            = 695 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF6            = 696 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF7            = 697 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_RECEP_RF8            = 698 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
} E_DEFAUT;

typedef enum
{
    // Erreurs
    ERR_TEXT                    = 200,
    ERR_TEMP_TEV_IN             = 201,
    ERR_TEMP_TEV_OUT            = 202 | DEFAUT_NV_TH | DEFAUT_NV_IHM,
    ERR_PRESSOSTAT_HP410        = 250,
    ERR_PRESSOSTAT_HP134        = 251,
    ERR_TEMP_TDS410             = 252,
    ERR_TEMP_TSC410_A           = 253 | DEFAUT_NV_TH | DEFAUT_NV_IHM,
    ERR_TEMP_TDS134             = 254,
    ERR_TEMP_TSC410_B           = 255 | DEFAUT_NV_TH | DEFAUT_NV_IHM,
    ERR_TEMP_TEV134             = 256,
    ERR_DEBIT                   = 257,
    ERR_TEMP_SPARE              = 258,
    ERR_IN_PRESSION_BP410       = 259,
    ERR_IN_PRESSION_BP134       = 260,
    ERR_IN_PRESSION_HP410       = 261,
    ERR_IN_PRESSION_HP134       = 262,
    ERR_IN_PRESSION_HPINT       = 263,
    ERR_ARRET_URGENT_410        = 264 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_ARRET_URGENT_134        = 265,
    ERR_CIRCUIT410_DEFAUT       = 266 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_CIRCUIT134_DEFAUT       = 267,
    ERR_RECURRENTES             = 268 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_DEMARRAGE               = 269,
    ERR_CIRCUIT410_BP           = 270,
    ERR_CIRCUIT410_HP           = 271,
    ERR_CYCLE_DEFROST           = 272 | DEFAUT_NV_TH | DEFAUT_NV_IHM,
    ERR_RS485_PW                = 273 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TEMP_EAU_INF_5          = 274,
    ERR_TEMP_EAU_SUP_85         = 275,
    ERR_DEMAR_134               = 276,
    ERR_RUCKING_2W              = 277,
    ERR_RUCKING_6W              = 278,
	// Alertes
    ALERTE_TEXT                 = 700 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TEV_IN          = 701 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TEV_OUT         = 702 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TDS410          = 750 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TSC410_A        = 751 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TDS134          = 752 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TSC410_B        = 753 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TEV134          = 754 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_T_IGBT          = 755 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_SPARE           = 756 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_IN_PRESSION_BP410    = 757 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_IN_PRESSION_BP134    = 758 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_IN_PRESSION_HP410    = 759 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_IN_PRESSION_HP134    = 760 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_IN_PRESSION_HPINT    = 761 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_PRESSOSTAT_HP410     = 762 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_PRESSOSTAT_HP134     = 763 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_MAINTENANCE          = 764 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_DEF_MODE_HM          = 765 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_CHARGE_R410          = 766 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_CHARGE_R134          = 767 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ERR_IPM_SURINTENSITE        = 857 | DEFAUT_NV_TH | DEFAUT_NV_IHM,                           // PW : IPM surintensité
    ERR_PILOT_COMP              = 858,                                                          // PW : Erreur pilotage compresseur
    ERR_COMP_SURINTENSITE       = 859,                                                          // PW : Surintensité compresseur
    ERR_INPUT_PHASE_LACK        = 860,                                                          // PW : Manque un Phase
    ERR_IPM_ECHANTILLONAGE      = 861,                                                          // PW : IPM erreur échantillonnage
    ERR_RADIATEUR_CHAUD         = 862,                                                          // PW : Radiateur PW trop Chaud
    ERR_DC_BUS_SURTENSION       = 863,                                                          // PW : DC bus surtension
    ERR_DC_BUS_SOUSTENSION      = 864,                                                          // PW : DC bus sous tension
    ERR_AC_INPUT_SOUSTENSION    = 865,                                                          // PW : AC input sous tension
    ERR_PFC_SURINTENSITE        = 866,                                                          // PW : PFC  surintensité
    ERR_TEMP_RADIATEUR          = 867,                                                          // PW : Erreur Sonde température radiateur
    ERR_COM_RS485               = 868,                                                          // PW : PW RS485 communication en erreur
    ERR_COM_MAITRE_ESCLAVE      = 869,                                                          // PW : Communication master avec esclave erreur
    ALERTE_COMP_SURINTENSITE    = 870 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,                   // PW : Alerte surintensité compresseur
    ALERTE_TEMP_RADIATEUR_ELEVEE = 871 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,                  // PW : Alerte Radiateur PW température élevée
    ALERTE_PFC_SURINTENSITE     = 872 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,                   // PW : Alerte PFC surintensité
    ALERTE_WEAK_MAGNETIC        = 873 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,    // PW : Alerte weak magnetic
} E_DEFAUT_AJPAC;

typedef enum
{
    // ERREURS
    ERR_TEMP_S1                 = 300 | T_DEF_DEFAUT,
    ERR_TEMP_TH2_LIQUIDE        = 301 | T_DEF_DEFAUT,
    ERR_MITSU_L3                = 340 | T_DEF_DEFAUT, // L3 Cireculation water overheat protection
    ERR_MITSU_L4                = 341 | T_DEF_DEFAUT, // L4 DHW tank water temperature overheat protection
    ERR_MITSU_L5                = 342 | T_DEF_DEFAUT, // L5 Thermistor (return warter temp.) (THW2)
    ERR_MITSU_L6                = 343 | T_DEF_DEFAUT, // L6 Circulation water freeze protection
    ERR_MITSU_L8                = 344 | T_DEF_DEFAUT, // L8 Heating operation error
    ERR_MITSU_L9                = 345 | T_DEF_DEFAUT, // L9 Low primary circuit flow rate detected by flow switch
    ERR_MITSU_LA                = 346 | T_DEF_DEFAUT, // LA Pressure sensor failure
    ERR_MITSU_LB                = 347 | T_DEF_DEFAUT, // LB High pressure protection
    ERR_MITSU_LF                = 348 | T_DEF_DEFAUT, // LF Flow sensor failure
    ERR_MITSU_PL                = 350 | T_DEF_DEFAUT, // PL Outdoor refrigerant system abnormally
    ERR_MITSU_FC                = 351 | T_DEF_DEFAUT, // FC Outdoor control system
    ERR_MITSU_EE                = 352 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // EE Combination error with indoor units
    ERR_MITSU_U9_01             = 354 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 Sur tension
    ERR_MITSU_U9_02             = 355 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 Sous tension
    ERR_MITSU_U9_04             = 356 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 Phase L1 ouverte
    ERR_MITSU_U9_08             = 357 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 Synchronisation des signaux de puissance
    ERR_MITSU_U9_10             = 358 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 PFC erreur
    ERR_MITSU_U9_20             = 359 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 PFC/IGBT erreur
    ERR_MITSU_U9                = 360 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U9 Anomalie de Tension d'alimentation",
    ERR_MITSU_UD                = 361 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // UD Protection liée a une surchauffe (TH3)",
    ERR_MITSU_A0_A8             = 362 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // A0 a A8 Erreur de communication sur M-NET",
    ERR_MITSU_E0                = 363 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E0 Erreur Communication avec Télécommmande",
    ERR_MITSU_E1_E2             = 364 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E1-E2 Anomalie de la Telecommande",
    ERR_MITSU_E3                = 365 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E3 Err. Communication Télécommande Transmission",
    ERR_MITSU_E4                = 366 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E4 Err. Signal Télécommande (avec UI)",
    ERR_MITSU_E5                = 367 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E5 Err. Communication Telecommande (avec UI)",
    ERR_MITSU_E6                = 368 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E6 Erreur COM. Reception UI/UE (detect. UI)",
    ERR_MITSU_E7                = 369 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E7 Erreur COM. Transmit. UI/UE (detect. UI)",
    ERR_MITSU_E8                = 370 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E8 Erreur COM. Reception UI/UE (detect. UE)",
    ERR_MITSU_E9                = 371 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // E9 Erreur COM. Transmit. UI/UE (detect. UE)",
    ERR_MITSU_EA                = 372 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // EA Cablage des modules en inadéquation avec\nla qté unité intérieure",
    ERR_MITSU_EB                = 373 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // EB Erreur sur cablage des modules internes et\nexternes ",
    ERR_MITSU_EC                = 374 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // EC Delai de demarrage écoulé",
    ERR_MITSU_ED                = 375 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // ED Erreur de communication entre cartes\npilotage et Power (unité externe)",
    ERR_MITSU_EF                = 376 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // EF Code Erreur indéfini",
    ERR_MITSU_F3                = 377 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // F3 Pressostat BP Ouvert (63L)",
    ERR_MITSU_F5                = 378 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // F5 Pressostat HP Ouvert (63H)",
    ERR_MITSU_F9                = 379 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // F9 Pressostat BP Ouvert (63L) ou\nHP Ouvert (63H)",
    ERR_MITSU_FB                = 380, // FB Carte Controller PAC module intérieur\nen defaut",
    ERR_MITSU_P1                = 381, // P1 Anomalie sur thermostat interieur (TH1)",
    ERR_MITSU_P2                = 382, // P2 Anomalie sur capteur de temperature\nliquide (TH2)",
    ERR_MITSU_P4                = 383, // P4 Anomalie du capteur d'évacuation (DS)\nou Contact (FS) ",
    ERR_MITSU_P5                = 384, // P5 Protection débordement de l'evacuation\ninterieure",
    ERR_MITSU_P6                = 385, // P6 Protection contre le gel (mode froid) ou\nsurchauffe (mode chaud)",
    ERR_MITSU_P8                = 386, // P8 Anomalie T° Tuyau R410A",
    ERR_MITSU_P9                = 387 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // P9 Anomalie de la sonde de T° du condenseur\nevaporateur",
    ERR_MITSU_U1                = 388 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U1 Pression excessive (klixon HP 63H activé)",
    ERR_MITSU_U2                = 389 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U2 Défaut du Thermostat de corps et\nde la T° de refoulement (TH4)",
    ERR_MITSU_U3                = 390 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U3 Defaut sonde T° unité exterieure\n(TH4)  ou (TH32)",
    ERR_MITSU_U4                = 391 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U4 Defaut sonde T° unité exterieure\n(TH3, TH6, TH7 ou TH8)",
    ERR_MITSU_U5                = 392 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U5 T° anormale radiateur de commande\nmoteur (UE)",
    ERR_MITSU_U6                = 393 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U6 Anomalie sur module de PW commande Moteur",
    ERR_MITSU_U7                = 394 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U7 Surchauffe liée à une T°  BP trop basse",
    ERR_MITSU_U8                = 395 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // U8 Problème sur Ventilateur Unité Extérieure",
    ERR_MITSU_UE                = 396 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // UE Problème Capteur de Pression HP (63HS)",
    ERR_MITSU_UF                = 397 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // UF Coupure Compresseur suite à surintenté\n(demarrage bloqué)",
    ERR_MITSU_UH                = 398 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // UH Anomalie sur Intensité (carte élec. ) ",
    ERR_MITSU_UL                = 399 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // UL Pression BP trop basse",
    ERR_MITSU_UP                = 400 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // UP Compresseur en surintenté",
    ERR_MITSU_TOR               = 401 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // Erreur Module Externe (signal TOR)",
    ERR_MITSU_XX                = 402 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // Défaut Module Externe (N° d'erreur non défini)",
    ERR_MITSU_COM               = 403 | T_DEF_DEFAUT | DEFAUT_BLOQUANT, // Défaut Erreur Communication avec PAC",
    ERR_MITSU_TRAME_INCONNUE    = 404 | T_DEF_DEFAUT | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE, // Défaut reccurent de communication avec PAC",
    ERR_TIMEOUT_EMISSION        = 405 | T_DEF_DEFAUT, // Défaut reccurent pas d'émisson vers Mitsu depuis 5 mn",
    ERR_MITSU_PE                = 406, // PE Anomalie sur capteur de temperature\nliquide PAC Monobloc (TH32) ",
    ERR_TIMEOUT_COM_RC          = 407 | T_DEF_DEFAUT, // Pas de communication RC depuis 200s
	// ALERTES
    ALERTE_TEMP_S1              = 800 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_TH2_LIQUIDE     = 801 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_LIMITE_COURANT       = 802 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_REFOULEMENT     = 803 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_CONSENSATION    = 804 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_ANTIGEL         = 805 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALERTE_TEMP_RADIATEUR       = 806 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
} E_DEFAUT_MITSU;

typedef enum
{
    // ERREURS
    ERR_TEAU_DEPART_CHAUFFAGE   = 500 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_RETOUR_CHAUFFAGE   = 501 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEAU_DEPART_CAPTEUR     = 502 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TEAU_RETOUR_CAPTEUR     = 503 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TEAU_ENTREE_PUITS       = 504 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TEAU_SORTIE_PUITS       = 505 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TEMP_HP1                = 506 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEMP_HP2                = 507 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEMP_BP1                = 508 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEMP_BP2                = 509 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TEMP_TSC                = 510 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_EEPROM_FRIGO            = 511 | T_DEF_DEFAUT ,
    ERR_PRESSION_HP             = 512 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_PRESSION_BP             = 513 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_SIGNAL_CIRC_CHAUFFAGE   = 514 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ERR_SIGNAL_CIRC_CAPTEUR     = 515 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ERR_PRESSION_CAPTEUR        = 516 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_DEBIT_CHAUFFAGE         = 517 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_DEBIT_CAPTEUR           = 518 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TEAU_DEPART_CHAUFFAGE   = 519 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TEAU_RETOUR_CHAUFFAGE   = 520 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TEAU_DEPART_CAPTEUR     = 521 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_TEAU_RETOUR_CAPTEUR     = 522 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_TEAU_SORTIE_PUITS       = 523 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,   //IDEM Err 572
    DEF_TEAU_ENTREE_PUITS       = 524 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,   //IDEM Err 573
    DEF_TEMP_HP1                = 525 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TEMP_HP2                = 526 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TEMP_BP1                = 527 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TEMP_BP2                = 528 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TEMP_TSC                = 529 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    /*Alertes suite à dépassement de valeurs sans entrainer arret PAC, fonctionnement éventuellement en dégradé*/
    ALR_TEAU_DEPART_CHAUFFAGE   = 530 | DEFAUT_NV_TH,
    ALR_TEAU_RETOUR_CHAUFFAGE   = 531 | DEFAUT_NV_TH,
    ALR_TEAU_DEPART_CAPTEUR     = 532 | DEFAUT_NV_TH,
    ALR_TEAU_RETOUR_CAPTEUR     = 533 | DEFAUT_NV_TH,
    ALR_TEAU_SORTIE_PUITS       = 534 | DEFAUT_NV_TH,   //IDEM Err 532
    ALR_TEAU_ENTREE_PUITS       = 535 | DEFAUT_NV_TH,   //IDEM Err 533
    ALR_TEMP_HP1                = 536 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_TEMP_HP2                = 537 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_TEMP_BP1                = 538 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_TEMP_BP2                = 539 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_TEMP_TSC                = 540 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ERR_IN_COMPTAGE_PW_GEO      = 541 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_PRESSION_HP             = 542 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_PRESSION_BP             = 543 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_SIGNAL_CIRC_CHAUFFAGE   = 544 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_SIGNAL_CIRC_CAPTEUR     = 545 | DEFAUT_NV_TH | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_PRESSION_CAPTEUR        = 546 | DEFAUT_NV_TH,
    ALR_DEBIT_CHAUFFAGE         = 547 | DEFAUT_NV_TH,
    ALR_DEBIT_CAPTEUR           = 548 | DEFAUT_NV_TH,
    ALR_DEBIT_PUITS             = 549 | DEFAUT_NV_TH,
    ALR_CONFIG_MAITRE           = 550 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE1         = 551 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE2         = 552 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE3         = 553 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE4         = 554 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE5         = 555 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE6         = 556 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_DEFAUT_ESCLAVE7         = 557 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ALR_CONFIG_ESCLAVE          = 558 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_DEMARRAGE_C1            = 559 | T_DEF_DEFAUT | DEFAUT_NV_TH, //Pas de démarrage sute à démarreur progressif HS
    DEF_DEMARRAGE_C2            = 560 | T_DEF_DEFAUT | DEFAUT_NV_TH, //Pas de démarrage sute à démarreur progressif HS
    DEF_CHARGE_FRIGO            = 561 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    /*Defauts suite à dépassement de valeurs entrainant arret PAC*/
    DEF_TEMP_EXT                = 562 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_PRESSION_HP             = 563 | T_DEF_DEFAUT ,
    DEF_PRESSION_BP             = 564 | T_DEF_DEFAUT ,
    DEF_SECU_HP                 = 565 | T_DEF_DEFAUT ,
    DEF_SIGNAL_CIRC_CHAUFFAGE   = 566 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_SIGNAL_CIRC_CAPTEUR     = 567 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_PRESSION_CAPTEUR        = 568 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_DEBIT_CHAUFFAGE         = 569 | T_DEF_DEFAUT,
    DEF_DEBIT_CAPTEUR           = 570 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_DEBIT_PUITS             = 571 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_CONFIG_PAC              = 572 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_REGUL_FRIGO             = 573 | T_DEF_ALERTE | DEFAUT_NV_TH | DEFAUT_NV_HISTORIQUE | DEFAUT_NV_IHM,   // PMA V015 Passage en Alerte Non visible IHM et Thermostat
    DEF_DEMARRAGE_C1_RECCURENT  = 574 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_DEMARRAGE_C2_RECCURENT  = 575 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_DEMARRAGE_NO_DELTA_P    = 576 | T_DEF_DEFAUT | DEFAUT_NV_TH,
} E_DEFAUT_GEOTWIN;

typedef enum
{
    // ERREURS / DEFAUTS
	// Extérieurs
    ERR_GEOINV_TEMP_EXT               			= 200,
    DEF_GEOINV_TEMP_EXT             			= 201,
    ERR_GEOINV_HYGRO_EXT               			= 202,	// Perte de comm avec le capteur
    DEF_GEOINV_HYGRO_EXT             			= 203,	// Valeur remontée par le capteur incohérente
	// Chauffage
	ERR_GEOINV_TEAU_DEPART_CHAUFFAGE  			= 210 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	DEF_GEOINV_TEAU_DEPART_CHAUFFAGE  			= 211 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_GEOINV_TEAU_RETOUR_CHAUFFAGE  			= 212 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_TEAU_RETOUR_CHAUFFAGE 			= 213 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_GEOINV_PRESSION_EAU_CHAUFFAGE    		= 214 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_GEOINV_PRESSION_EAU_CHAUFFAGE			= 215 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	ERR_GEOINV_DEBIT_CHAUFFAGE         			= 216 | T_DEF_DEFAUT,
	DEF_GEOINV_DEBIT_CHAUFFAGE         			= 217 | T_DEF_DEFAUT,
	// Appoint
	DEF_GEOINV_FUSIBLE_APP_1					= 230 | T_DEF_DEFAUT,
	DEF_GEOINV_FUSIBLE_APP_2					= 231 | T_DEF_DEFAUT,
	DEF_GEOINV_FUSIBLE_APP_3					= 232 | T_DEF_DEFAUT,
	DEF_GEOINV_APPOINT							= 233 | T_DEF_DEFAUT,	// DEF_GEOINV_FUSIBLE_APP_1 & DEF_GEOINV_FUSIBLE_APP_2 & DEF_GEOINV_FUSIBLE_APP_3
	// Config de la carte
    DEF_GEOINV_CONFIG          					= 240 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_GEOINV_NO_SERIAL               			= 241 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	// Capteur
    ERR_GEOINV_TEAU_DEPART_CAPTEUR    			= 250 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_GEOINV_TEAU_DEPART_CAPTEUR    			= 251 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_GEOINV_TEAU_RETOUR_CAPTEUR    			= 252 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_GEOINV_TEAU_RETOUR_CAPTEUR    			= 253 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_GEOINV_TEAU_ENTREE_PUITS      			= 254 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_GEOINV_TEAU_ENTREE_PUITS      			= 255 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_GEOINV_TEAU_SORTIE_PUITS      			= 256 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_GEOINV_TEAU_SORTIE_PUITS      			= 257 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_GEOINV_PRESSION_EAU_CAPTEUR    			= 258 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_GEOINV_PRESSION_EAU_CAPTEUR    			= 259 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_GEOINV_DEBIT_CAPTEUR           			= 260 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_GEOINV_DEBIT_CAPTEUR           			= 261 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_GEOINV_DEBIT_PUITS           			= 262 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	// Frigo circuit 1
    ERR_GEOINV_TEMP_HP1               			= 300 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_TEMP_HP1                			= 301 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_GEOINV_TEMP_BP1                			= 302 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_TEMP_BP1                			= 303 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_GEOINV_PRESSION_HP1            			= 304 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_PRESSION_HP1            			= 305 | T_DEF_DEFAUT,
    ERR_GEOINV_PRESSION_BP1            			= 306 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_PRESSION_BP1            			= 307 | T_DEF_DEFAUT,
    DEF_GEOINV_DEMARRAGE_C1            			= 308 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_DEMARRAGE_C1_RECCURENT  			= 309 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_PRESSOSTAT_HP1        			= 310,
    DEF_GEOINV_KLIXON_COMPRESSEUR_1    			= 311 | T_DEF_DEFAUT | DEFAUT_NV_TH,
//    ERR_GEOINV_ARRET_URGENT_CIRCUIT_1 			= 312 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
//    ERR_GEOINV_DEFAUT_CIRCUIT_1       			= 313 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
//    DEF_GEOINV_CHARGE_FRIGO_CIRCUIT_1           = 314 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	// Frigo autres
    ERR_GEOINV_TEMP_LIQUIDE            			= 380 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_TEMP_LIQUIDE           			= 381 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_GEOINV_TEMP_SPARE            			= 382 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_GEOINV_TEMP_SPARE           			= 383 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	ERR_GEOINV_RECURRENTES             			= 384 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,

	// Driver
	ERR_GEOINV_COMM_DRIVER            			= 400 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_GEOINV_DRIVER_COMPATIBILITY				= 401 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	DEF_GEOINV_GENERAL_DRIVER_RUKING   			= 402 | T_DEF_DEFAUT,
    DEF_GEOINV_CAPTEUR_COURANT_U       			= 403 | T_DEF_DEFAUT,
    DEF_GEOINV_CAPTEUR_COURANT_V       			= 404 | T_DEF_DEFAUT,
    DEF_GEOINV_CAPTEUR_COURANT_W       			= 405 | T_DEF_DEFAUT,
    DEF_GEOINV_CAPTEUR_COURANT_PFC     			= 406 | T_DEF_DEFAUT,
    DEF_GEOINV_CAPTEUR_TEMP_IPM        			= 407 | T_DEF_DEFAUT,
    DEF_GEOINV_CAPTEUR_TEMP_PFC        			= 408 | T_DEF_DEFAUT,
    DEF_GEOINV_SONDE_DLT               			= 409 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_HARWARE_PFC    		= 410 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_SOFTWARE_PFC   		= 411 | T_DEF_DEFAUT,
    DEF_GEOINV_SURTENSION_PFC              		= 412 | T_DEF_DEFAUT,
    DEF_GEOINV_CONVERTISSEUR_ANALOG_DIGITAL 	= 413 | T_DEF_DEFAUT,
    DEF_GEOINV_ADRESSAGE_INTERNE       			= 414 | T_DEF_DEFAUT,
    DEF_GEOINV_COMMUNICATION_PERDUE    			= 415 | T_DEF_DEFAUT,
    DEF_GEOINV_EEPROM                  			= 416 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_AC         			= 417 | T_DEF_DEFAUT,
    DEF_GEOINV_SURTENSION_AC           			= 418 | T_DEF_DEFAUT,
    DEF_GEOINV_SOUSTENSION_AC          			= 419 | T_DEF_DEFAUT,
    DEF_GEOINV_SURTENSION_DC           			= 420 | T_DEF_DEFAUT,
    DEF_GEOINV_SOUSTENSION_DC          			= 421 | T_DEF_DEFAUT,
    DEF_GEOINV_ENTREE_SECU_HP_RUKING   			= 422 | T_DEF_DEFAUT,
    DEF_GEOINV_MANQUE_PHASE_AC         			= 423 | T_DEF_DEFAUT,
    DEF_GEOINV_SURCHAUFFE_IPM          			= 424 | T_DEF_DEFAUT,
    DEF_GEOINV_SURCHAUFFE_IGBT         			= 425 | T_DEF_DEFAUT,
    DEF_GEOINV_CODE_COMPRESSEUR        			= 426 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_HARDWARE_COMP   	= 427 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_COMPRESSEUR_U       = 428 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_COMPRESSEUR_V       = 429 | T_DEF_DEFAUT,
    DEF_GEOINV_SURINTENSITE_COMPRESSEUR_W       = 430 | T_DEF_DEFAUT,
    DEF_GEOINV_MANQUE_PHASE_DC         			= 431 | T_DEF_DEFAUT,
    DEF_GEOINV_PERTE_ROTOR            			= 432 | T_DEF_DEFAUT,
    DEF_GEOINV_DEMARRAGE_COMP_INVERTER 			= 433 | T_DEF_DEFAUT,
    DEF_GEOINV_SURCHARGE_COMPRESSEUR   			= 434 | T_DEF_DEFAUT,
    DEF_GEOINV_TEMPERATURE_DLT         			= 435 | T_DEF_DEFAUT,
    DEF_GEOINV_IPM_DESAT_PROTECTION    			= 436 | T_DEF_DEFAUT,
    DEF_GEOINV_PERTE_ROTOR_2           			= 437 | T_DEF_DEFAUT,
    DEF_GEOINV_PERTE_ROTOR_3           			= 438 | T_DEF_DEFAUT,  
    // ALERTES
	// Extérieure
    ALR_GEOINV_TEMP_EXT             			= 700 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_GEOINV_HYGRO_EXT          				= 701 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
	// Chauffage
	ALR_GEOINV_TEMP_EAU_DEPART_CHAUFF  			= 705 | DEFAUT_NV_TH,
    ALR_GEOINV_TEMP_EAU_RETOUR_CHAUFF  			= 706 | DEFAUT_NV_TH,
    ALR_GEOINV_PRESS_EAU_CHAUFF  				= 707,
	ALR_GEOINV_DEBIT_CHAUFF         			= 708,
	// Config de la carte
	ALR_GEOINV_COMPTAGE_PW      				= 715 | DEFAUT_NV_TH,
	// Capteur
    ALR_GEOINV_TEAU_DEPART_CAPTEUR    			= 720 | DEFAUT_NV_TH,
    ALR_GEOINV_TEAU_RETOUR_CAPTEUR    			= 721 | DEFAUT_NV_TH,
    ALR_GEOINV_TEMP_EAU_ENT_PUITS      			= 722 | DEFAUT_NV_TH,
    ALR_GEOINV_TEMP_EAU_SOR_PUITS      			= 723 | DEFAUT_NV_TH,
    ALR_GEOINV_PRESSION_EAU_CAPTEUR             = 724,
    ALR_GEOINV_DEBIT_CAPTEUR           			= 725,
	// Frigo circuit 1
    ALR_GEOINV_TEMP_HP1               			= 740 | DEFAUT_NV_TH,
    ALR_GEOINV_TEMP_BP1                			= 741 | DEFAUT_NV_TH,
    ALR_GEOINV_PRESSION_HP1            			= 742 | DEFAUT_NV_TH,
    ALR_GEOINV_PRESSION_BP1            			= 743 | DEFAUT_NV_TH,
    ALR_GEOINV_CHARGE_FRIGO_CIRCUIT_1           = 744 | DEFAUT_NV_TH,
} E_DEFAUT_GEOINV;

typedef enum
{
    // ERREURS / DEFAUTS
	// Extérieurs
    ERR_ARKTEA_TEMP_EXT               			= 200,
    DEF_ARKTEA_TEMP_EXT             			= 201,
    ERR_ARKTEA_HYGRO_EXT               			= 202,	// Perte de comm avec le capteur
    DEF_ARKTEA_HYGRO_EXT             			= 203,	// Valeur remontée par le capteur incohérente
	// Chauffage
	ERR_ARKTEA_TEMP_EAU_DEPART_CHAUFF  			= 210 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	DEF_ARKTEA_TEMP_EAU_DEPART_CHAUFF  			= 211 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_ARKTEA_TEMP_EAU_RETOUR_CHAUFF  			= 212 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_ARKTEA_TEMP_EAU_RETOUR_CHAUFF  			= 213 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_ARKTEA_PRESS_EAU_CHAUFF  				= 214 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_PRESS_EAU_CHAUFF  				= 215 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	ERR_ARKTEA_DEBIT_CHAUFF         			= 216 | T_DEF_DEFAUT,
	DEF_ARKTEA_DEBIT_CHAUFF         			= 217 | T_DEF_DEFAUT,
	// Appoint
	DEF_ARKTEA_FUSIBLE_APP_1					= 230 | T_DEF_DEFAUT,
	DEF_ARKTEA_FUSIBLE_APP_2					= 231 | T_DEF_DEFAUT,
	DEF_ARKTEA_FUSIBLE_APP_3					= 232 | T_DEF_DEFAUT,
	DEF_ARKTEA_APPOINT							= 233 | T_DEF_DEFAUT,	// DEF_ARKTEA_FUSIBLE_APP_1 & DEF_ARKTEA_FUSIBLE_APP_2 & DEF_ARKTEA_FUSIBLE_APP_3
	// Config de la carte
    DEF_ARKTEA_CONFIG          					= 240 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_NO_SERIAL               			= 241 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_ARKTEA_COMM_ARDUINO                     = 242 | T_DEF_DEFAUT,
	// Capteur
    ERR_ARKTEA_TEMP_EAU_DEP_CAPTEUR    			= 250 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_ARKTEA_TEMP_EAU_DEP_CAPTEUR    			= 251 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_ARKTEA_TEMP_EAU_RET_CAPTEUR    			= 252 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_ARKTEA_TEMP_EAU_RET_CAPTEUR    			= 253 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_ARKTEA_PRESS_CAPTEUR        			= 258 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_PRESS_CAPTEUR        			= 259 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_ARKTEA_DEBIT_CAPTEUR           			= 260 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_DEBIT_CAPTEUR           			= 261 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	// Frigo circuit 1
    ERR_ARKTEA_PRESSION_HELIUM            		= 304 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_ARKTEA_PRESSION_HELIUM            		= 305 | T_DEF_DEFAUT,
    DEF_ARKTEA_DEMARRAGE_C1            			= 308 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_ARKTEA_DEMARRAGE_C1_RECCURENT  			= 309 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_ARKTEA_PRESSOSTAT_HP1        			= 310,
    DEF_ARKTEA_KLIXON_COMPRESSEUR_1    			= 311 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_ARKTEA_ARRET_URGENT_CIRCUIT_1 			= 312 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_ARKTEA_DEFAUT_CIRCUIT_1       			= 313 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_CHARGE_FRIGO_CIRCUIT_1           = 314 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	// Frigo autres
	ERR_ARKTEA_RECURRENTES             			= 384 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_REGUL_FRIGO             			= 387 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_NV_IHM,
	// Driver
	ERR_ARKTEA_COMM_DRIVER            			= 400 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_DRIVER_COMPATIBILITY				= 401 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	DEF_ARKTEA_MODULE_PUISSANCE   				= 402 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_INTERNE_ADC   					= 403 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_MESURE_RMS   					= 404 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_ARKTEA_TENSION_BUS_DC       			= 405 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MOTEUR_1     		= 406 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MOTEUR_2     		= 407 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MOTEUR_3     		= 408 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MOTEUR_4     		= 409 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURTENSION_MOTEUR_1    			= 410 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURTENSION_MOTEUR_2    			= 411 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURTENSION_MOTEUR_3    			= 412 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURTENSION_MOTEUR_4    			= 413 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MODULE_PUISSANCE_1  = 414 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MODULE_PUISSANCE_2  = 415 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MODULE_PUISSANCE_3  = 416 | T_DEF_DEFAUT,
    DEF_ARKTEA_SURINTENSITE_MODULE_PUISSANCE_4  = 417 | T_DEF_DEFAUT,
    // ALERTES
	// Extérieure
    ALR_ARKTEA_TEMP_EXT             			= 700 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_ARKTEA_HYGRO_EXT          				= 701 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
	// Chauffage
	ALR_ARKTEA_TEMP_EAU_DEPART_CHAUFF  			= 705 | DEFAUT_NV_TH,
    ALR_ARKTEA_TEMP_EAU_RETOUR_CHAUFF  			= 706 | DEFAUT_NV_TH,
    ALR_ARKTEA_PRESS_EAU_CHAUFF  				= 707,
	ALR_ARKTEA_DEBIT_CHAUFF         			= 708,
	// Config de la carte
	ALR_ARKTEA_COMPTAGE_PW      				= 715 | DEFAUT_NV_TH,
	// Capteur
    ALR_ARKTEA_TEMP_EAU_DEP_CAPTEUR    			= 720 | DEFAUT_NV_TH,
    ALR_ARKTEA_TEMP_EAU_RET_CAPTEUR    			= 721 | DEFAUT_NV_TH,
    ALR_ARKTEA_PRESS_CAPTEUR        			= 724,
    ALR_ARKTEA_DEBIT_CAPTEUR           			= 725,
	// Frigo circuit 1
    ALR_ARKTEA_PRESSION_HELIUM            		= 742 | DEFAUT_NV_TH,
    ALR_ARKTEA_CHARGE_FRIGO_CIRCUIT_1           = 744 | DEFAUT_NV_TH,
} E_DEFAUT_ARKTEA;

typedef enum
{
    // ERREURS / DEFAUTS
	// Extérieurs
    ERR_TYPE_TEMP_EXT               			= 200,
    DEF_TYPE_TEMP_EXT             				= 201,
    ERR_TYPE_HYGRO_EXT               			= 202,	// Perte de comm avec le capteur
    DEF_TYPE_HYGRO_EXT             				= 203,	// Valeur remontée par le capteur incohérente
	// Chauffage
	ERR_TYPE_TEMP_EAU_DEPART_CHAUFF  			= 210 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	DEF_TYPE_TEMP_EAU_DEPART_CHAUFF  			= 211 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_TEMP_EAU_RETOUR_CHAUFF  			= 212 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_EAU_RETOUR_CHAUFF  			= 213 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_PRESS_EAU_CHAUFF  					= 214 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_PRESS_EAU_CHAUFF  					= 215 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	ERR_TYPE_DEBIT_CHAUFF         				= 216 | T_DEF_DEFAUT,
	DEF_TYPE_DEBIT_CHAUFF         				= 217 | T_DEF_DEFAUT,
	// Appoint
	DEF_TYPE_FUSIBLE_APP_1						= 230 | T_DEF_DEFAUT,
	DEF_TYPE_FUSIBLE_APP_2						= 231 | T_DEF_DEFAUT,
	DEF_TYPE_FUSIBLE_APP_3						= 232 | T_DEF_DEFAUT,
	DEF_TYPE_APPOINT							= 233 | T_DEF_DEFAUT,	// DEF_TYPE_FUSIBLE_APP_1 & DEF_TYPE_FUSIBLE_APP_2 & DEF_TYPE_FUSIBLE_APP_3
	// Config de la carte
    DEF_TYPE_CONFIG          					= 240 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_NO_SERIAL               			= 241 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TYPE_COMM_SPARE                         = 242 | T_DEF_DEFAUT,
	// Capteur
    ERR_TYPE_TEMP_EAU_DEP_CAPTEUR    			= 250 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_TYPE_TEMP_EAU_DEP_CAPTEUR    			= 251 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TYPE_TEMP_EAU_RET_CAPTEUR    			= 252 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_TYPE_TEMP_EAU_RET_CAPTEUR    			= 253 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TYPE_TEMP_EAU_ENT_PUITS      			= 254 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_TYPE_TEMP_EAU_ENT_PUITS      			= 255 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TYPE_TEMP_EAU_SOR_PUITS      			= 256 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    DEF_TYPE_TEMP_EAU_SOR_PUITS      			= 257 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_BLOQUANT,
    ERR_TYPE_PRESS_CAPTEUR        				= 258 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_PRESS_CAPTEUR        				= 259 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TYPE_DEBIT_CAPTEUR           			= 260 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_DEBIT_CAPTEUR           			= 261 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	// Evaporateur
    ERR_TYPE_TEMP_EVAP_IN          				= 280 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_TEMP_EVAP_IN           			= 281 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TYPE_TEMP_EVAP_OUT          			= 282 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_TEMP_EVAP_OUT           			= 283 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	// Frigo circuit 1
    ERR_TYPE_TEMP_HP1               			= 300 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_HP1                			= 301 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_TEMP_BP1                			= 302 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_BP1                			= 303 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_PRESSION_HP1            			= 304 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_PRESSION_HP1            			= 305 | T_DEF_DEFAUT,
    ERR_TYPE_PRESSION_BP1            			= 306 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_PRESSION_BP1            			= 307 | T_DEF_DEFAUT,
    DEF_TYPE_DEMARRAGE_C1            			= 308 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_DEMARRAGE_C1_RECCURENT  			= 309 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_PRESSOSTAT_HP1        				= 310 | T_DEF_DEFAUT,
    DEF_TYPE_KLIXON_COMPRESSEUR_1    			= 311 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_ARRET_URGENT_CIRCUIT_1 			= 312 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TYPE_DEFAUT_CIRCUIT_1       			= 313 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_CHARGE_FRIGO_CIRCUIT_1           	= 314 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	// Frigo circuit 2
    ERR_TYPE_TEMP_HP2                			= 340 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_HP2                			= 341 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_TEMP_BP2                			= 342 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_BP2                			= 343 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_PRESSION_HP2            			= 344 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_PRESSION_HP2            			= 345 | T_DEF_DEFAUT,
    ERR_TYPE_PRESSION_BP2            			= 346 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_PRESSION_BP2            			= 347 | T_DEF_DEFAUT,
    DEF_TYPE_DEMARRAGE_C2            			= 348 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_DEMARRAGE_C2_RECCURENT  			= 349 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_PRESSOSTAT_HP2        				= 350 | T_DEF_DEFAUT,
    DEF_TYPE_KLIXON_COMPRESSEUR_2    			= 351 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_ARRET_URGENT_CIRCUIT_2 			= 352 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TYPE_DEFAUT_CIRCUIT_2       			= 353 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_CHARGE_FRIGO_CIRCUIT_2           	= 354 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	// Frigo autres
    ERR_TYPE_TEMP_LIQUIDE            			= 380 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_LIQUIDE           			= 381 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    ERR_TYPE_TEMP_SPARE            				= 382 | T_DEF_DEFAUT | DEFAUT_NV_TH,
    DEF_TYPE_TEMP_SPARE           				= 383 | T_DEF_DEFAUT | DEFAUT_NV_TH,
	ERR_TYPE_RECURRENTES             			= 384 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    ERR_TYPE_CYCLE_DEFROST           			= 385 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_NV_IHM,
    DEF_TYPE_REGUL_FRIGO             			= 386 | T_DEF_DEFAUT | DEFAUT_NV_TH | DEFAUT_NV_IHM,
	// Driver
	ERR_TYPE_COMM_DRIVER            			= 400 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
    DEF_TYPE_DRIVER_COMPATIBILITY				= 401 | T_DEF_DEFAUT | DEFAUT_BLOQUANT,
	DEF_TYPE_DRIVER_1   						= 402 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_2   						= 403 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_3   						= 404 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_4       					= 405 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_5     						= 406 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_6        					= 407 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_7        					= 408 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_8               			= 409 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_9    						= 410 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_10   						= 411 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_11              			= 412 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_12 							= 413 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_13       					= 414 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_14    						= 415 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_15                  		= 416 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_16         					= 417 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_17           				= 418 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_18          				= 419 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_19           				= 420 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_20          				= 421 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_21   						= 422 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_22         					= 423 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_23          				= 424 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_24         					= 425 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_25        					= 426 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_26   						= 427 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_27         					= 428 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_28         					= 429 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_29         					= 430 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_30         					= 431 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_31            				= 432 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_32 							= 433 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_33   						= 434 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_34         					= 435 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_35    						= 436 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_36           				= 437 | T_DEF_DEFAUT,
    DEF_TYPE_DRIVER_37           				= 438 | T_DEF_DEFAUT,  
    // ALERTES
	// Extérieure
    ALR_TYPE_TEMP_EXT             				= 700 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
    ALR_TYPE_HYGRO_EXT          				= 701 | DEFAUT_NV_IHM | DEFAUT_NV_HISTORIQUE,
	// Chauffage
	ALR_TYPE_TEMP_EAU_DEPART_CHAUFF  			= 705 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_EAU_RETOUR_CHAUFF  			= 706 | DEFAUT_NV_TH,
    ALR_TYPE_PRESS_EAU_CHAUFF  					= 707,
	ALR_TYPE_DEBIT_CHAUFF         				= 708,
	// Config de la carte
	ALR_TYPE_COMPTAGE_PW      					= 715 | DEFAUT_NV_TH,
	// Capteur
    ALR_TYPE_TEMP_EAU_DEP_CAPTEUR    			= 720 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_EAU_RET_CAPTEUR    			= 721 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_EAU_ENT_PUITS      			= 722 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_EAU_SOR_PUITS      			= 723 | DEFAUT_NV_TH,
    ALR_TYPE_PRESS_CAPTEUR        				= 724,
    ALR_TYPE_DEBIT_CAPTEUR           			= 725,
	// Evaporateur
    ALR_TYPE_TEMP_EVAP_IN          				= 730,
    ALR_TYPE_TEMP_EVAP_OUT          			= 731,
	// Frigo circuit 1
    ALR_TYPE_TEMP_HP1               			= 740 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_BP1                			= 741 | DEFAUT_NV_TH,
    ALR_TYPE_PRESSION_HP1            			= 742 | DEFAUT_NV_TH,
    ALR_TYPE_PRESSION_BP1            			= 743 | DEFAUT_NV_TH,
    ALR_TYPE_CHARGE_FRIGO_CIRCUIT_1           	= 744 | DEFAUT_NV_TH,
	// Frigo circuit 2
    ALR_TYPE_TEMP_HP2                			= 760 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_BP2                			= 761 | DEFAUT_NV_TH,
    ALR_TYPE_PRESSION_HP2            			= 762 | DEFAUT_NV_TH,
    ALR_TYPE_PRESSION_BP2            			= 763 | DEFAUT_NV_TH,
    ALR_TYPE_CHARGE_FRIGO_CIRCUIT_2           	= 764 | DEFAUT_NV_TH,
	// Frigo autres
    ALR_TYPE_TEMP_LIQUIDE            			= 780 | DEFAUT_NV_TH,
    ALR_TYPE_TEMP_SPARE            				= 781 | DEFAUT_NV_TH,
} E_DEFAUT_TYPE;

#endif

// End of file
