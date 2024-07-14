/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_2
#define LED_GPIO_Port GPIOE
#define LTDC_B0_Pin GPIO_PIN_4
#define LTDC_B0_GPIO_Port GPIOE
#define LTDC_G0_Pin GPIO_PIN_5
#define LTDC_G0_GPIO_Port GPIOE
#define LTDC_G1_Pin GPIO_PIN_6
#define LTDC_G1_GPIO_Port GPIOE
#define LTDC_R5_Pin GPIO_PIN_0
#define LTDC_R5_GPIO_Port GPIOC
#define CTN_Pin GPIO_PIN_1
#define CTN_GPIO_Port GPIOC
#define LTDC_R1_Pin GPIO_PIN_2
#define LTDC_R1_GPIO_Port GPIOA
#define LTDC_B5_Pin GPIO_PIN_3
#define LTDC_B5_GPIO_Port GPIOA
#define LTDC_R4_Pin GPIO_PIN_5
#define LTDC_R4_GPIO_Port GPIOA
#define LTDC_G2_Pin GPIO_PIN_6
#define LTDC_G2_GPIO_Port GPIOA
#define LTDC_R7_Pin GPIO_PIN_4
#define LTDC_R7_GPIO_Port GPIOC
#define LTDC_R3_Pin GPIO_PIN_0
#define LTDC_R3_GPIO_Port GPIOB
#define LTDC_R6_Pin GPIO_PIN_1
#define LTDC_R6_GPIO_Port GPIOB
#define LCD_DISP_Pin GPIO_PIN_2
#define LCD_DISP_GPIO_Port GPIOB
#define LTDC_G4_Pin GPIO_PIN_10
#define LTDC_G4_GPIO_Port GPIOB
#define LTDC_G5_Pin GPIO_PIN_11
#define LTDC_G5_GPIO_Port GPIOB
#define LTDC_G6_Pin GPIO_PIN_7
#define LTDC_G6_GPIO_Port GPIOC
#define LTDC_G3_Pin GPIO_PIN_9
#define LTDC_G3_GPIO_Port GPIOC
#define LTDC_B6_Pin GPIO_PIN_15
#define LTDC_B6_GPIO_Port GPIOA
#define LTDC_R2_Pin GPIO_PIN_10
#define LTDC_R2_GPIO_Port GPIOC
#define LTDC_B4_Pin GPIO_PIN_11
#define LTDC_B4_GPIO_Port GPIOC
#define LTDC_B7_Pin GPIO_PIN_2
#define LTDC_B7_GPIO_Port GPIOD
#define LTDC_G7_Pin GPIO_PIN_3
#define LTDC_G7_GPIO_Port GPIOD
#define LCD_INT_Pin GPIO_PIN_7
#define LCD_INT_GPIO_Port GPIOD
#define LCD_RST_Pin GPIO_PIN_9
#define LCD_RST_GPIO_Port GPIOG
#define LTDC_B2_Pin GPIO_PIN_10
#define LTDC_B2_GPIO_Port GPIOG
#define LTDC_B3_Pin GPIO_PIN_11
#define LTDC_B3_GPIO_Port GPIOG
#define LTDC_B1_Pin GPIO_PIN_12
#define LTDC_B1_GPIO_Port GPIOG
#define LTDC_R0_Pin GPIO_PIN_13
#define LTDC_R0_GPIO_Port GPIOG
#define LCD_BL_PWM_Pin GPIO_PIN_4
#define LCD_BL_PWM_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
