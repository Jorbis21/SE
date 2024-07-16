//Pr2 por Pablo Garc�a Fern�ndez y Javier Orbis Ram�rez. Laboratorio 8 Puesto 7
#include <stdio.h>
#include "xgpio.h"
#include "gpio_header.h"
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "xuartlite_l.h"
#include <xstatus.h>

#define XPAR_RS232_UART_1_BASEADDR 0x84000000

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
        print("This is not a valid number");
    }
}

void funcionA(){
	XGpio leds;
	XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&leds, 1, 0x0);
	XGpio_DiscreteWrite(&leds, 1, getNumber());
}

char opcion;
int op1=0, op2=0, sol=0;
int fin;
XGpio leds;
void funcionB(){
fin=0;
XGpio leds;
while(fin==0){
xil_printf("MENU\n");
xil_printf("Opciones:\n");
xil_printf("a -  introducir el primer operando\n");
xil_printf("b -  introducir el segundo operando\n");
xil_printf("c -  hacer la resta y visualizarla\n");
xil_printf("s -  salir\n");

opcion = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
   XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,opcion);
   //RECIBO EL CARACTER DE FIN DE LA LETRA
   XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

   xil_printf("\n");

   if(opcion == 'a'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);
    op1 = getNumber();
    XGpio_DiscreteWrite(&leds, 1, op1);
    xil_printf("Operando1: %d\n", op1);
   }
   else if(opcion == 'b'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);
    op2 = getNumber();
    XGpio_DiscreteWrite(&leds, 1, op2);
    xil_printf("Operando2: %d\n", op2);
   }
   else if(opcion == 'c'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);
    sol = op1 - op2;
    XGpio_DiscreteWrite(&leds, 1, sol);
    xil_printf("SOLUCI�N: %d\n", sol);
   }
   else if(opcion == 's'){
      fin = 1;
   }
   else {
    xil_printf("ERROR: opcion no valida\n");
   }
   xil_printf("\n");
}
}

//se usan las variables definidas arriba de la funcionB
//adem�s tambi�n defino
XGpio switches;
u32 datoSw;
void funcionC(){
fin=0;
while(fin==0){
xil_printf("MENU\n");
xil_printf("Opciones:\n");
xil_printf("a -  introducir el primer operando\n");
xil_printf("b -  introducir el segundo operando\n");
xil_printf("c -  hacer la resta y visualizarla\n");
xil_printf("d -  visualizar input switches\n");
xil_printf("s -  salir\n");

opcion = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
   XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,opcion);
   //RECIBO EL CARACTER DE FIN DE LA LETRA
   XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

   xil_printf("\n");

   if(opcion == 'a'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);
    op1 = getNumber();
    XGpio_DiscreteWrite(&leds, 1, op1);
    xil_printf("Operando1: %d\n", op1);
   }
   else if(opcion == 'b'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);
    op2 = getNumber();
    XGpio_DiscreteWrite(&leds, 1, op2);
    xil_printf("Operando2: %d\n", op2);
   }
   else if(opcion == 'c'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);
    sol = op1 - op2;
    XGpio_DiscreteWrite(&leds, 1, sol);
    xil_printf("SOLUCI�N: %d\n", sol);
   }
   else if(opcion == 'd'){
    XGpio_Initialize(&leds, XPAR_XPS_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0x0);//output
    XGpio_Initialize(&switches, XPAR_XPS_GPIO_1_DEVICE_ID);
    XGpio_SetDataDirection(&switches, 1, 0xffffffff);//input

    datoSw = XGpio_DiscreteRead(&switches, 1);
    XGpio_DiscreteWrite(&leds, 1, datoSw);
    xil_printf("Switches: %d\n", datoSw);
   }
   else if(opcion == 's'){
      fin = 1;
   }
   else {
    xil_printf("ERROR: opcion no valida\n");
   }
   xil_printf("\n");
}
}

int main(){//append LF
xil_printf("Pr2 - by Pablo Garc�a Fern�ndez y Javier Orbis Ram�rez\n");

//funcionA();
//funcionB();
funcionC();

    print("-- Exiting main() --\r\n");
    return 0;


}