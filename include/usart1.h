/**
  ******************************************************************************
  * @file    umart_lite_plus_teste/include/usart1.h
  * @author  Kleber Lima da Silva (kleber.ufu@hotmail.com)
  * @version V1.0.1
  * @date    20-Abril-2015
  * @brief   Cabe�alho para o m�dulo usart1.c
  ******************************************************************************
  */

/* Define para previnir a inclus�o recursiva ---------------------------------*/
#ifndef __USART1_H
#define __USART1_H


/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "stm32f4xx.h"

/* Constantes ----------------------------------------------------------------*/
#define BAUD_RATE	115200
#define USART_TIMEOUT	100

/* Prot�tipos das Fun��es --------------------------------------------------- */
void usart1Config(void);
int _write(int file, char *ptr, int len);
int _read (int file, char *ptr, int len);

/* Vari�veis ---------------------------------------------------------------- */
extern UART_HandleTypeDef huart1;


#endif /* __USART1_H */
