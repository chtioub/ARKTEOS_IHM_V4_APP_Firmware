/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.23.2. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
#include "i2c.h"

uint8_t gTouched = 0;
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>

void STM32TouchController::init()
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_INT_GPIO_Port, LCD_INT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LCD_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_INT_GPIO_Port, &GPIO_InitStruct);

  HAL_Delay(1);     // T2 > 100us
  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
  HAL_Delay(6);     // T3 > 5ms

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LCD_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LCD_INT_GPIO_Port, &GPIO_InitStruct);
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
  uint8_t touches = 0;
  uint8_t buf[6];
  const uint16_t STATUS_REG = 0x814E;
  const uint16_t TOUCH_POS_REG = 0x8150;
  uint8_t ZERO = 0;

  HAL_I2C_Mem_Read(&hi2c4, 0xBA, STATUS_REG, 2, buf, 1, HAL_MAX_DELAY);
  touches = (0x0F & buf[0]);

  HAL_I2C_Mem_Write(&hi2c4, 0xBA, STATUS_REG, 2, &ZERO, 1, HAL_MAX_DELAY);

  if(touches > 0)
  {
    HAL_I2C_Mem_Read(&hi2c4, 0xBA, TOUCH_POS_REG, 2, buf, 4, HAL_MAX_DELAY);
    x = buf[0] + (buf[1] << 8);
    y = buf[2] + (buf[3] << 8);

    gTouched = 1;

    return true;
  }

  return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
