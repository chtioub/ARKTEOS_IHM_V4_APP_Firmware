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

#include "main.h"
#include "arkteos_var_protocole.h"

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
  uint8_t size;
  uint8_t data[TAILLE_BUFFER_UART];
} rxData_t;

typedef struct
{
  uint8_t dest;
  uint8_t emet;
  uint8_t comm;
  uint8_t control :2;
  uint8_t s_comm :6;
  uint16_t taille;
} header_t;

extern cosebe_test_t cosebe_test;
extern rxData_t rxData;
extern uint8_t rxBuffer[TAILLE_BUFFER_UART];
extern uint8_t dataUpdated;

uint8_t decodeRxData(rxData_t *rxData);

#ifdef __cplusplus
}
#endif

#endif /* INC_IHM_V4_H_ */
