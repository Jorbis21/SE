/***************************** Include Files *******************************/

#include "motor.h"

/************************** Function Definitions ***************************/

void motorGiro(){//Tercer bit?
	MOTOR_mWriteSlaveReg0(MOTOR_HW_BASEaddress, 0, 0x88000000);
	MOTOR_mWriteSlaveReg0(MOTOR_HW_BASEaddress, 0, 0xC8000000);
	MOTOR_mWriteSlaveReg0(MOTOR_HW_BASEaddress, 0, 0x08000000);
	MOTOR_mWriteSlaveReg0(MOTOR_HW_BASEaddress, 0, 0x48000000);
}
