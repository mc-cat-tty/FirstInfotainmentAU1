/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>

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
#define STEERING_RIGHT_RED_BUTTON_Pin GPIO_PIN_13
#define STEERING_RIGHT_RED_BUTTON_GPIO_Port GPIOG
#define MCU_ACTIVE_Pin GPIO_PIN_12
#define MCU_ACTIVE_GPIO_Port GPIOG
#define SDC_CTRL_Pin GPIO_PIN_10
#define SDC_CTRL_GPIO_Port GPIOG
#define LAP_COUNTER_TRIGGER_Pin GPIO_PIN_13
#define LAP_COUNTER_TRIGGER_GPIO_Port GPIOC
#define FRAME_RATE_Pin GPIO_PIN_1
#define FRAME_RATE_GPIO_Port GPIOA
#define STEERING_LEFT_RED_BUTTON_Pin GPIO_PIN_4
#define STEERING_LEFT_RED_BUTTON_GPIO_Port GPIOA
#define DASHBOARD_NEUTRAL_LED_Pin GPIO_PIN_4
#define DASHBOARD_NEUTRAL_LED_GPIO_Port GPIOC
#define VSYNC_FREQ_Pin GPIO_PIN_2
#define VSYNC_FREQ_GPIO_Port GPIOA
#define RENDER_TIME_Pin GPIO_PIN_6
#define RENDER_TIME_GPIO_Port GPIOA
#define STEERING_GREEN_BUTTON_Pin GPIO_PIN_5
#define STEERING_GREEN_BUTTON_GPIO_Port GPIOC
#define MCP2515_CS_Pin GPIO_PIN_6
#define MCP2515_CS_GPIO_Port GPIOH
#define STEERING_RIGHT_PADDLE_BUTTON_Pin GPIO_PIN_7
#define STEERING_RIGHT_PADDLE_BUTTON_GPIO_Port GPIOA
#define STEERING_LEFT_PADDLE_BUTTON_Pin GPIO_PIN_1
#define STEERING_LEFT_PADDLE_BUTTON_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
