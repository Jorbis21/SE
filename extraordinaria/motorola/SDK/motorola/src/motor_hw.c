/*****************************************************************************
* Filename:          C:\SE\motorola/drivers/motor_hw_v1_00_a/src/motor_hw.c
* Version:           1.00.a
* Description:       motor_hw Driver Source File
* Date:              Tue Jun 25 23:35:05 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "motor_hw.h"

/************************** Function Definitions ***************************/

void motorHorario(){
	int i;
	abriendoPuertas();
	for(i = 0; i <= 5000000; i++){
		MOTOR_HW_mWriteReg(XPAR_MOTOR_HW_0_BASEADDR, 0, 0x9E000000);//9E 9F 8F
	}
	esperaGiro();
}

void motorAntihorario(){
	int i;
	cerrandoPuertas();
	for(i = 0; i <= 5000000; i++){
		MOTOR_HW_mWriteReg(XPAR_MOTOR_HW_0_BASEADDR, 0, 0x1E000000);//1F 0F
	}
	esperaGiro();
}

void esperaGiro(){
	Xuint32 Data;
	Data = MOTOR_HW_mReadReg(XPAR_MOTOR_HW_0_BASEADDR , 0);
	while (!( Data & 0x40000000 )) {
		Data = MOTOR_HW_mReadReg ( XPAR_MOTOR_HW_0_BASEADDR, 0);
	}
}