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

typedef struct
{
  uint8_t dest;
  uint8_t emet;
  uint8_t comm;
  uint8_t control :2;
  uint8_t s_comm :6;
  uint16_t taille;
}header_t;

typedef struct
{
  uint16_t size;
  header_t header;
  uint8_t data[TAILLE_BUFFER_UART - sizeof(header_t)];
  uint16_t *crc;
}txData_t;

typedef struct
{
  uint16_t size;
  uint8_t data[TAILLE_BUFFER_UART];
}rxData_t;

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

extern uint8_t rxBuffer[TAILLE_BUFFER_UART];
extern rxData_t rxData;
extern cosebe_rx_t cosebe_rx;
extern uint8_t dataUpdated;

extern cosebe_tx_t cosebe_tx;
extern uint8_t sendData;

uint8_t decodeRxData(rxData_t *rxData, cosebe_rx_t *cosebe_rx);
uint8_t computeTxData(txData_t *txData, const cosebe_tx_t *cosebe_tx);


#ifdef __cplusplus
}
#endif

#endif /* INC_IHM_V4_H_ */
