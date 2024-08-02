/*
 * IHM_V4.c
 *
 *  Created on: Jul 29, 2024
 *      Author: info
 */

#ifndef SIMULATOR
#include "main.h"
#endif /* SIMULATOR */
#include "IHM_V4.h"

uint8_t rxBuffer[TAILLE_BUFFER_UART];
rxData_t rxData;
cosebe_rx_t cosebe_rx;
uint8_t dataUpdated = 0;
cosebe_tx_t cosebe_tx;
uint8_t sendData = 0;

static uint16_t computeCRC(uint8_t *data, uint16_t size);

uint8_t decodeRxData(rxData_t *rxData, cosebe_rx_t *cosebe_rx)
{
  uint8_t result = 0;
  header_t *pHeader;
  cosebe_rx_t *pCosebe_rx;
// TODO: Verifier CRC
  if(rxData->size != 0)
  {
    pHeader = (header_t*) rxData->data;
    if(pHeader->dest == N_ADD_IHM)
    {
      if(pHeader->comm == C_USER)
      {
        if(pHeader->control == CONTROL_WRITE)
        {
          if(pHeader->s_comm == SC_USER_Z1)
          {
            pCosebe_rx = (cosebe_rx_t*)(rxData->data + sizeof(header_t));
            if((pCosebe_rx->bModePAC) != cosebe_rx->bModePAC)
            {
              cosebe_rx->bModePAC = pCosebe_rx->bModePAC;
              result++;
            }
            if((pCosebe_rx->u7Spare) != cosebe_rx->u7Spare)
            {
              cosebe_rx->u7Spare = pCosebe_rx->u7Spare;
              result++;
            }
            if((pCosebe_rx->u8Spare) != cosebe_rx->u8Spare)
            {
              cosebe_rx->u8Spare = pCosebe_rx->u8Spare;
              result++;
            }
            if((pCosebe_rx->u8Spare) != cosebe_rx->u8Spare)
            {
              cosebe_rx->u8Spare = pCosebe_rx->u8Spare;
              result++;
            }
          }
        }
      }
    }
  }
  rxData->size = 0;

  return result;
}

uint8_t computeTxData(txData_t *txData, const cosebe_tx_t *cosebe_tx)
{
  uint8_t result = 0;

  txData->header.dest = N_ADD_ETHER;
  txData->header.emet = N_ADD_IHM;
  txData->header.comm = C_IHM_TABLETTE;
  txData->header.control = CONTROL_WRITE;
  txData->header.s_comm = SC_IHM_ON_OFF;
  txData->header.taille = 2;
  txData->data[0] = (uint8_t)(cosebe_tx->u16Data >> 8);
  txData->data[1] = (uint8_t)(cosebe_tx->u16Data);
  txData->crc = (uint16_t*)(txData->data + txData->header.taille);
  *txData->crc = computeCRC((uint8_t*)txData, sizeof(header_t) + txData->header.taille);
  txData->size = sizeof(header_t) + txData->header.taille + sizeof(uint16_t);

  return result;
}

static uint16_t computeCRC(uint8_t *data, uint16_t size)
{
  uint16_t crc = 0x1234;
  return crc;
}
