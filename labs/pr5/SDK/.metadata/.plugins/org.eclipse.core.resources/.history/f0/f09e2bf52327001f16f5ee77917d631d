	/*****************************************************************************
* Filename:          U:\hlocal\pablo\extraordinaria\proyecto/drivers/keypad_v1_00_a/src/keypad.c
* Version:           1.00.a
* Description:       keypad Driver Source File
* Date:              Fri Jun 07 12:18:11 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "keypad.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/

char keyToChar(Xuint32 key){
	char keyCHAR;

	switch(key){
		case 0:
			keyCHAR = '0';
			break;
		case 1:
			keyCHAR = '1';
			break;
		case 2:
			keyCHAR = '2';
			break;
		case 3:
			keyCHAR = '3';
			break;
		case 4:
			keyCHAR = '4';
			break;
		case 5:
			keyCHAR = '5';
			break;
		case 6:
			keyCHAR = '6';
			break;
		case 7:
			keyCHAR = '7';
			break;
		case 8:
			keyCHAR = '8';
			break;
		case 9:
			keyCHAR = '9';
			break;
		case 10:
			keyCHAR = 'A';
			break;
		case 11:
			keyCHAR = 'B';
			break;
		case 12:
			keyCHAR = 'C';
			break;
		case 13:
			keyCHAR = 'D';
			break;
		case 14:
			keyCHAR = 'E';
			break;
		case 15:
			keyCHAR = 'F';
			break;
		default: break;
	}

	return keyCHAR;
}
Xuint32 transformKey(Xuint32 pressed){
	return pressed >> 28;
}
void keypadDEMO(){
	Xuint32 Reg32Value, TeclaOld, value;

	print("---Test para el keypad---\n\r");
	xil_printf(" Pulse una tecla cualquiera \n\r");

	Reg32Value = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR, 0);
	value = transformKey(Reg32Value);

	xil_printf("   Se ha leido %c\n\r", keyToChar(value));
	TeclaOld = Reg32Value;

	while(1){
		Reg32Value = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR, 0);
		if(Reg32Value != TeclaOld){
			value = transformKey(Reg32Value);
			xil_printf("   Se ha leido %c\n\r", keyToChar(value));
			TeclaOld = Reg32Value;
			//KEYPAD_mWriteReg(XPAR_KEYPAD_0_BASEADDR, 0,0); /* Se escribe un 0 en el registro del teclado para borrar la última tecla leída */
		}
	}
}
