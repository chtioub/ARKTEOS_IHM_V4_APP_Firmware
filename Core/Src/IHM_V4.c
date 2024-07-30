/*
 * IHM_V4.c
 *
 *  Created on: Jul 29, 2024
 *      Author: info
 */

#include "main.h"
#include "IHM_V4.h"

uint8_t rxBuffer[TAILLE_BUFFER_UART];
rxData_t rxData;
cosebe_test_t cosebe_test;
uint8_t dataUpdated = 0;

uint8_t decodeRxData(rxData_t *rxData)
{
  uint8_t result = 0;
  header_t *pHeader;
  cosebe_test_t *pCosebe_test;

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
            pCosebe_test = (cosebe_test_t*)(rxData->data + sizeof(header_t));
            if((pCosebe_test->bModePAC) != cosebe_test.bModePAC)
            {
              cosebe_test.bModePAC = pCosebe_test->bModePAC;
              result++;
            }
            if((pCosebe_test->u7Spare) != cosebe_test.u7Spare)
            {
              cosebe_test.u7Spare = pCosebe_test->u7Spare;
              result++;
            }
            if((pCosebe_test->u8Spare) != cosebe_test.u8Spare)
            {
              cosebe_test.u8Spare = pCosebe_test->u8Spare;
              result++;
            }
            if((pCosebe_test->u8Spare) != cosebe_test.u8Spare)
            {
              cosebe_test.u8Spare = pCosebe_test->u8Spare;
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
