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

#ifndef _ARKTEOS_MACROS_H_
#define _ARKTEOS_MACROS_H_

/*****************************************************************************/
//  MACROS
/*****************************************************************************/
#define Min(x, y)                   ((x) < (y) ? (x) : (y))
#define Max(x, y)                   ((x) > (y) ? (x) : (y))

#define MIN(x, y)                   ((x) < (y) ? (x) : (y))
#define MAX(x, y)                   ((x) > (y) ? (x) : (y))

#define mBornage(x, min, max)       {if(x < min) x = min; else if(x > max) x = max;}
#define mBornageMin(x, min)         {if(x < min) x = min;}
#define mBornageMax(x, max)         {if(x > max) x = max;}
#define mChoix(x,y,z)               (x ? y : z)

#define FILL_ZERO(x)                memset(&x, 0, sizeof(x))
#define COPY(dest,source)           memcpy(&dest, &source, sizeof(dest))

#define mSwap_u16(x)                x = (x << 8 & 0xff00) | (x >> 8 & 0x00ff)
#define mSwap_u32(x)                x = (u32) (x >> 24 & 0x00ff) | (x >> 8 & 0x0000ff00) | (x << 8 & 0x00ff0000) | (x << 24 & 0xff000000)

#define mModele_PAC_Geotwin()       (sModele_PAC.u8ModelePAC == GEOTWIN_IV)
#define mModele_PAC_Zuran_Baguio()  (sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV || sModele_PAC.u8ModelePAC == TIMAX_III)
#define mModele_PAC_Ajpac()         (sModele_PAC.u8ModelePAC == AJPAC_III)
#define mModele_PAC_PHOENIX()       (sModele_PAC.u8ModelePAC == PHOENIX)
#define mModele_PAC_ARKTEA()        (sModele_PAC.u8ModelePAC == ARKTEA)
#define mModele_PAC_GEOINVERTER()   (sModele_PAC.u8ModelePAC == GEOINVERTER)
#define mModele_PAC_Cairox()        (sModele_PAC.u8ModelePAC == CAIROX)
#define mModele_PAC_Baguio_PP()     (sModele_PAC.u8ModelePAC == BAGUIO_ZURAN_IV && sModele_PAC.u3SousTypePAC == SOUS_TYPE_BAGUIO_PP)

#define mModeleMonobloc()           (sModele_PAC.u8ModelePAC == TIMAX_III)
#endif

// End of file
