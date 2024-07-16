/*****************************************************************************
* Filename:          C:\SE\motorola/drivers/leds_v1_00_a/src/leds.c
* Version:           1.00.a
* Description:       leds Driver Source File
* Date:              Wed Jun 26 12:14:39 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "leds.h"
#include "xparameters.h"
#include "unistd.h"

/************************** Function Definitions ***************************/

/*
 * Slv 0 -> rojo
 * Slv 1 -> verde
 * Slv 2 -> azul
 */

void LED_init(){
	LEDS_mWriteSlaveReg0(XPAR_LEDS_0_BASEADDR, 0, 255);
	LEDS_mWriteSlaveReg1(XPAR_LEDS_0_BASEADDR, 0, 255);
	LEDS_mWriteSlaveReg2(XPAR_LEDS_0_BASEADDR, 0, 255);
}

void LED_ponColor(int R, int G, int B){
	LEDS_mWriteSlaveReg0(XPAR_LEDS_0_BASEADDR, 0, R);
	LEDS_mWriteSlaveReg1(XPAR_LEDS_0_BASEADDR, 0, G);
	LEDS_mWriteSlaveReg2(XPAR_LEDS_0_BASEADDR, 0, B);
}

void ledsDEMO(){
	LED_init();
	while(1){
		LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
		/*
		LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
		LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
		LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
		LED_ponColor(BLANCO_R, BLANCO_G, BLANCO_B);
		LED_ponColor(NEGRO_R, NEGRO_G, NEGRO_B);
		*/
	}
}
