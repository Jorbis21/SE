#include <stdio.h>
#include "xbram.h"
#include "bram_header.h"
#include "my_plb_peripheral.h"
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"

int getNumber (){
	Xuint8 byte;
	Xuint8 uartBuffer[16];
	Xboolean validNumber;
	int digitIndex;
	int digit, number, sign;
	int c;

	while(1){
		byte = 0x00;
		digit = 0;
		digitIndex = 0;
		number = 0;
		validNumber = XTRUE;

		//get bytes from uart until RETURN is entered

		while(byte != 0x0d && byte != 0x0A){
			byte = XUartLite_RecvByte(XPAR_XPS_UARTLITE_0_BASEADDR);
			uartBuffer[digitIndex] = byte;
			XUartLite_SendByte(XPAR_XPS_UARTLITE_0_BASEADDR,byte);
			digitIndex++;
		}

		//calculate number from string of digits

		for(c = 0; c < (digitIndex - 1); c++){
			if(c == 0){
				//check if first byte is a "-"
				if(uartBuffer[c] == 0x2D){
					sign = -1;
					digit = 0;
				}
				//check if first byte is a digit
				else if((uartBuffer[c] >> 4) == 0x03){
					sign = 1;
					digit = (uartBuffer[c] & 0x0F);
				}
				else
					validNumber = XFALSE;
			}
			else{
				//check byte is a digit
				if((uartBuffer[c] >> 4) == 0x03){
					digit = (uartBuffer[c] & 0x0F);
				}
				else
					validNumber = XFALSE;
			}
			number = (number * 10) + digit;
		}
		number *= sign;
		if(validNumber == XTRUE){
			return number;
		}
		print("This is not a valid number");
	}
}

int main() 
{

	Xuint32 num, baseaddr;
	baseaddr = XPAR_MY_PLB_PERIPHERAL_0_BASEADDR;

	print("-- Práctica 3 - by Pablo García Fernández y Javier Orbis Ramírez --\n\r");

	//r0
	print("Introduzca 0 para suma y 1 para restar (valor para r0): \n\r");
	num = getNumber();
	MY_PLB_PERIPHERAL_mWriteSlaveReg0(baseaddr, 0, num);
	num = MY_PLB_PERIPHERAL_mReadSlaveReg0(baseaddr, 0);
	xil_printf("%d -> r0\n\r", num);
	if(num & 1) xil_printf("VAMOS A RESTAR\n\r", num);
	else xil_printf("VAMOS A SUMAR\n\r", num);

	//r1
	print("Introduzca valor del primer operando (valor para r1): \n\r");
	num = getNumber();
	MY_PLB_PERIPHERAL_mWriteSlaveReg1(baseaddr, 0, num);
	num = MY_PLB_PERIPHERAL_mReadSlaveReg1(baseaddr, 0);
	xil_printf("%d -> r1\n\r", num);

	//r2
	print("Introduzca valor del segundo operando (valor para r2): \n\r");
	num = getNumber();
	MY_PLB_PERIPHERAL_mWriteSlaveReg2(baseaddr, 0, num);
	num = MY_PLB_PERIPHERAL_mReadSlaveReg2(baseaddr, 0);
	xil_printf("%d -> r2\n\r", num);

	//r3
	num = MY_PLB_PERIPHERAL_mReadSlaveReg0(baseaddr, 0);
	if(num & 1) print("reg1 - reg2 = ");
	else print("reg1 + reg2 = ");

	num = MY_PLB_PERIPHERAL_mReadSlaveReg3(baseaddr, 0);
	xil_printf("%d\n\r", num);

	print("--------------------\r\n");

	return 0;
}

