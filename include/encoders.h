/**
  ******************************************************************************
  * @file    umart_lite_plus_teste/include/encoders.h
  * @author  Kleber Lima da Silva (kleber.ufu@hotmail.com)
  * @version V1.0.1
  * @date    20-Abril-2015
  * @brief   Cabeçalho para o módulo encoders.c
  ******************************************************************************
  */

/* Define para previnir a inclusão recursiva ---------------------------------*/
#ifndef __ENCODERS_H
#define __ENCODERS_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Constantes ----------------------------------------------------------------*/
#define BUZZER_PORT	GPIOB
#define BUZZER_PIN	GPIO_PIN_4

/* Macros --------------------------------------------------------------------*/
#define BUZZER_CLK	__GPIOB_CLK_ENABLE()
#define BEEP_ON		HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET)
#define BEEP_OFF	HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET)

/* Protótipos das Funções --------------------------------------------------- */
void encodersConfig(void);
int32_t getEncoderEsquerda(void);
void resetEncoderEsquerda(void);
int32_t getEncoderDireita(void);
void resetEncoderDireita(void);


#endif /* __ENCODERS_H */
