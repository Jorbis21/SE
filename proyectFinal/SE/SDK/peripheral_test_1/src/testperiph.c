/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include <stdlib.h>


#include <stdio.h>

#include <xstatus.h>

#define XPAR_RS232_UART_1_BASEADDR 0x84000000
#define XPAR_LEDS_DEVICE_ID 0
#define XPAR_SWITCHES_DEVICE_ID 1



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
			byte = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
			uartBuffer[digitIndex] = byte;
			XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,byte);
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
		print("This is not a valid number.\n\r");
	}
}

u32 operando, operando2;
char key;
int resultado;
int fin = 0;

XGpio GpioLeds;
XGpio GpioSwitch;

int main()
{


	// escribe un mensaje en la pantalla del hyperterminal
	print("MENU: \n\r");
	print("a - Introducir el primer operando y visualizarlo en los leds y pantalla \n\r");
	print("b - Introducir segundo operando y visualizarlo en los leds y en la pantalla \n\r");
	print("c - Sumar y visualizar el resultado en los leds y en la pantalla \n\r");
	print("d - Visualizar en los leds y en la pantalla el dato le�do en los switches \n\r");

	// lee una letra de teclado
	XGpio_Initialize(&GpioLeds, 0);
	XGpio_SetDataDirection(&GpioLeds, 1, 0x0);
	XGpio_Initialize(&GpioSwitch, 1);
	XGpio_SetDataDirection(&GpioSwitch, 1, 0xFF);


    // lee un n�mero de teclado
		while(fin != 1){
			key = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

				// escribe una letra en la pantalla del hyperterminal

				XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,key);
					print("\r\n");
					if(key == 'a'){

						xil_printf("Introduce un numero\n\r");
						operando = getNumber();
						print("\r\n");


						XGpio_DiscreteWrite(&GpioLeds, 1, operando);
					}
					else if(key == 'b'){
						xil_printf("Introduce un numero\n\r");
						operando2 = getNumber();
						print("\r\n");

						XGpio_DiscreteWrite(&GpioLeds, 1, operando2);
					}
					else if(key == 'c'){
						resultado = operando + operando2;
						xil_printf("resultado = %d\n\r", resultado);


						XGpio_DiscreteWrite(&GpioLeds, 1, resultado);
					}
					else if(key == 'd'){

						//Leds
						print("1------\n\r");
						//switch

						print("2------\n\r");

						u32 DataRead = XGpio_DiscreteRead(&GpioSwitch, 1);

						print("3------\n\r");
						XGpio_DiscreteWrite(&GpioLeds, 1, DataRead);
						operando = getNumber();
						xil_printf("Switches: %d\n\r", operando);
						print("\n\r");
					}
					else if(key == 'e'){
						fin = 1;
					}
		}



   return 0;


}
