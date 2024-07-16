/*****************************************************************************
* Filename:          C:\Users\CJRipa\Desktop\SE-main\proyecto/drivers/leds_v1_00_a/src/leds.c
* Version:           1.00.a
* Description:       leds Driver Source File
* Date:              Fri Jan 26 20:18:42 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "leds.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/
/*
 * Slv 0 -> rojo
 * Slv 1 -> verde
 * Slv 2 -> azul
 */

void LED_enciendeRojo(){
	LEDS_mWriteSlaveReg0(XPAR_LEDS_0_BASEADDR, 0, 255);
}
void LED_apagaRojo(){
	LEDS_mWriteSlaveReg0(XPAR_LEDS_0_BASEADDR, 0, 0);
}
void LED_oscilaRojo(){
	LED_enciendeRojo();
	LED_apagaRojo();
}

void LED_enciendeVerde(){
	LEDS_mWriteSlaveReg1(XPAR_LEDS_0_BASEADDR, 0, 255);
}
void LED_apagaVerde(){
	LEDS_mWriteSlaveReg1(XPAR_LEDS_0_BASEADDR, 0, 0);
}
void LED_oscilaVerde(){
	LED_enciendeVerde();
	LED_apagaVerde();
}

void LED_enciendeAzul(){
	LEDS_mWriteSlaveReg2(XPAR_LEDS_0_BASEADDR, 0, 255);
}
void LED_apagaAzul(){
	LEDS_mWriteSlaveReg2(XPAR_LEDS_0_BASEADDR, 0, 0);
}
void LED_oscilaAzul(){
	LED_enciendeAzul();
	LED_apagaAzul();
}

void LED_doParty(){
	unsigned int i = 0;
	while(i<5){
		LED_oscilaAzul();
		LED_oscilaRojo();
		LED_oscilaVerde();
		i++;
	}
}
