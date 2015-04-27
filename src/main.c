/**
  ******************************************************************************
  * @file    umart_lite_plus_teste/src/main.c
  * @author  Kleber Lima da Silva (kleber.ufu@hotmail.com)
  * @version V1.0.1
  * @date    20-Abril-2015
  * @brief   Programa para teste do hardware do Robô uMaRT Lite Plus
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/**
  * @brief Programa Principal
  */
int main (void)
{
	uint32_t t0 = 0;
	int32_t lf = 0, l = 0, r = 0, rf = 0;

	// Configuração e inicialização dos periféricos ----------------------------
	buzzerConfig();
	ledsConfig();
	botaoConfig();
	motoresConfig();
	sensoresConfig();
	encodersConfig();
	usart1Config();
	usbConfig();


	// Inicio do programa ------------------------------------------------------
	// As mensagens enviadas por printf podem ser destinadas à USB ou à UART,
	// para isto altere a definição no arquivo main.h
	printf("Programa TESTE - uMaRT LITE+ V1.1!\r\n");

	allLEDs(HIGH);
	delay_ms(1000);
	allLEDs(LOW);
	beeps(3, 100, 50);

	resetEncoderEsquerda();
	resetEncoderDireita();


	// Loop principal ----------------------------------------------------------
	while (1)
	{
		// Manda para a serial mensagens de estados dos periféricos a cada 1s
		printf("Erro (linha): %d\r\n", getSensoresLinha());
		printf("\r\n");

		printf("Sensores de Paredes: %d\r\n", getSensoresParede(&lf, &l, &r, &rf));
		printf("%d | %d | %d | %d\r\n", lf, l, r, rf);
		printf("\r\n");

		printf("Gyro: %d\r\n", getGyro());
		printf("\r\n");

		printf("Bateria: %d mV\r\n", getTensao());
		printf("\r\n");

		printf("Encoders: %d | %d\r\n", getEncoderEsquerda(), getEncoderDireita());
		printf("\r\n");

		printf("\r\n");


		// Se o botão for pressionado: liga os motores por 1 segundo
		// .. ou aguarda 1 segundo sem fazer nada
		t0 = millis();
		while ((millis() - t0) < 1000)
		{
			if (getSW1() == HIGH)
			{
				beep(100);
				setMotores(300, 300);
				delay_ms(1000);
				setMotores(0, 0);
			}
		}

		// Pisca o LED2
		toggleLED(LED2);
	}
}


/**
  * @brief Esta função é chamada a cada 1ms por interrupção
  */
void systick (void)
{

}
