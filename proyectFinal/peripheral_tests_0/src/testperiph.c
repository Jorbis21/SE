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

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include "keypad.h"
#include "banner.h"
#include "ledsrgb.h"
#include "bannerMsg.h"
#include "altavoz.h"
#include "motor_hw.h"

# define BASE_ADDRESS_KEYPAD 0xC9600000
# define BASE_ADDRESS_BANNER 0xC5800000
# define BASE_ADDRESS_LEDS 0xCB200000
# define BASE_ADDRESS_MOTOR 0xC0A00000
#define RED 0
#define GREEN 1
#define BLUE 2

int bool1, bool2 = 0;
int fin =0;
int mode=0;
int largaCorta=0;

char tecladoachar(Xuint32 tecla){
	if (tecla == -1073741824) return 'c';
	else if(tecla == 268435456) return '1';
	else if (tecla == 536870912) return '2';
	else if (tecla == -536870912)  return 'e';
	else if (tecla == -268435456) return 'f';
	else return '0';
}
int seleccion(char carac){
	if (carac == '1') return 1;
	else if(carac == '2') return 2;
	else if (carac == 'c') return 4;
	else if (carac == 'e')  return 5;
	else if (carac == 'f') return 6;
	else return 0;
}


void selecMode(){
	print("Pulse en el keypad el modo que desea\n\r");
	bool2=0;
	bool1=0;
    Xuint32 vale;
   char elec;


	while(bool1 != 1 && !fin){
    	vale = KEYPAD_mReadReg(BASE_ADDRESS_KEYPAD,0); //leo la tecla

    	elec=tecladoachar(vale);
 	   KEYPAD_mWriteReg(BASE_ADDRESS_KEYPAD, 0,0);
 	   mode=seleccion(elec);
 	  if(mode== 6){
 	  	   		fin=1;
 	  	   		bool1=1;
 	  	   	}
		if(mode == 1 || mode == 2){
			if(mode==1){
				print("Modo elegido -> lavadora \n\r");
				print("Pulse en el keypad duracion corta(tecla(4)) o larga(tecla(5))\n\r");
				while(bool2!=1){
					//largaCorta=getNumber();
					vale = KEYPAD_mReadReg(BASE_ADDRESS_KEYPAD,0); //leo la tecla
					elec=tecladoachar(vale);
				   KEYPAD_mWriteReg(BASE_ADDRESS_KEYPAD, 0,0);
				   largaCorta=seleccion(elec);

					if(largaCorta == 4 || largaCorta == 5){
						if(largaCorta==4){
							print("Duracion elegida -> corto \n\r");
						}else{
							print("Duracion elegida -> largo \n\r");
						}
						bool2=1;
					}else{
						print("Duracion no valida introduzca una valida \n\r");
					}
				}

			}else{
				print("Modo elegido -> secadora \n\r");
				print("Pulse en el keypad duracion corta(tecla(4)) o larga(tecla(5))\n\r");
				while(bool2!=1){
					//largaCorta=getNumber();
					vale = KEYPAD_mReadReg(BASE_ADDRESS_KEYPAD,0); //leo la tecla
					elec=tecladoachar(vale);
				   KEYPAD_mWriteReg(BASE_ADDRESS_KEYPAD, 0,0);
				   largaCorta=seleccion(elec);
					if(largaCorta == 4 || largaCorta == 5){
						if(largaCorta==4){
							print("Duracion elegida -> corto \n\r");
						}else{
							print("Duracion elegida -> largo \n\r");
						}
						bool2=1;
					}else{
						print("Duracion no valida introduzca una valida \n\r");
					}
				}
			}
			bool1=1;
		}else{
			print("Modo no valido introduzca uno valido \n\r");
		}
	}
}
void melodiaInicioLavado(){
ALTAVOZ_suena(DO, OCTAVA);
my_delay(300); print("DO\n\r");
ALTAVOZ_suena(MI, OCTAVA);
my_delay(300); print("MI\n\r");
ALTAVOZ_suena(SOL, OCTAVA);
my_delay(300); print("SOL\n\r");
ALTAVOZ_calla();
}

void melodiaFinLavado(){
ALTAVOZ_suena(MI, OCTAVA);
my_delay(300); print("MI\n\r");
ALTAVOZ_suena(SOL, OCTAVA);
my_delay(300); print("SOL\n\r");
ALTAVOZ_suena(DO, OCTAVA);
my_delay(300); print("DO\n\r");
ALTAVOZ_calla();
}

void melodiaInicioSecado(){
ALTAVOZ_suena(LA, (OCTAVA+1));
my_delay(300); print("LA\n\r");
ALTAVOZ_suena(DO, OCTAVA);
my_delay(300); print("DO\n\r");
ALTAVOZ_suena(MI, OCTAVA);
my_delay(300); print("MI\n\r");
ALTAVOZ_calla();
}

void melodiaFinSecado(){
ALTAVOZ_suena(DO, OCTAVA);
my_delay(300); print("DO\n\r");
ALTAVOZ_suena(MI, OCTAVA);
my_delay(300); print("MI\n\r");
ALTAVOZ_suena(LA, (OCTAVA+1));
my_delay(300); print("LA\n\r");
ALTAVOZ_calla();
}

int main()
{
	Xil_ICacheEnable();
  	Xil_DCacheEnable();
while(!fin){


    int exit = 0;
    banner_inicializa();
    ////
    //Xuint32 val;
    //val=0;
   // Xuint32 TeclaOld;
    //while(1){
    	//val = KEYPAD_mReadReg(BASE_ADDRESS_KEYPAD,0); //leo la tecla

    	  //xil_printf(" Pulse una tecla cualquiera \n\r");
    	   //val = KEYPAD_mReadReg(BASE_ADDRESS_KEYPAD, 0);
    	   //xil_printf("   Se ha leido %d del registro 0 del teclado \n\r", val);
    	   //KEYPAD_mWriteReg(BASE_ADDRESS_KEYPAD, 0,0);
    	   //TeclaOld=val;
    //}

   //////
    //gris modo standby
    LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0, 50);//ROJO
    LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 50);//VERDE
    LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 50);//AZUL
    selecMode();
    print("Mira el banner\n\r");
    Xuint32 data;
    Xuint32 stop;
    Xuint32 estado;

    int i;
    if(mode==1){
    	melodiaInicioLavado();
    	msg(lavando);
    	LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0,255);//ROJO
		LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 255);//VERDE
		LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 0);//AZUL
    	if(largaCorta==4){
    		data = 0xBC000000;
			for(i = 1; i <= 1000; i++){
				MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );
				estado = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 4);
				// printing data from hyperterminal
		    	xil_printf(" %d  \n\r", estado);

			}
			//data = 0x40000000;
			//MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );

		    stop = MOTOR_HW_mReadReg (BASE_ADDRESS_MOTOR , 0);
		    while (!( stop & 0x40000000 )) {//while (!( stop & 0x40000000 ))
				   stop = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 0);
		    }
			print("FIN LAVADO\n\r");
		    LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0, 0);//ROJO
			LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 255);//VERDE
			LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 0);//AZUL
			melodiaFinLavado();
    	}else{
    		melodiaInicioLavado();
    		data = 0xBC000000;
			for(i = 1; i <= 3000; i++){
				MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );
				estado = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 4);
				// printing data from hyperterminal
				xil_printf(" %d  \n\r", estado);

			}
			//data = 0x40000000;
			//MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );

			stop = MOTOR_HW_mReadReg (BASE_ADDRESS_MOTOR , 0);
			while (!( stop & 0x40000000 )) {//while (!( stop & 0x40000000 ))
				   stop = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 0);
			}
			print("FIN LAVADO\n\r");
			LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0, 0);//ROJO
			LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 255);//VERDE
			LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 0);//AZUL
			melodiaFinLavado();
    	}
    }else if(mode==2){
    	LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0,255);//ROJO
		LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 255);//VERDE
		LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 0);//AZUL
    	melodiaInicioSecado();
    	msg(secando);

    	if(largaCorta==4){
    		data = 0x3C000000;
    		for(i = 1; i <= 1000; i++){
    			MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );
    			estado = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 4);
				// printing data from hyperterminal
				xil_printf(" %d  \n\r", estado);
			}
    		//data = 0x40000000;
    		//MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );

    		stop = MOTOR_HW_mReadReg (BASE_ADDRESS_MOTOR , 0);
    		while (( stop & 0x40000000 )) {//while (!( stop & 0x40000000 ))
			   stop = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 0);
    		}
    		 stop = MOTOR_HW_mReadReg (BASE_ADDRESS_MOTOR , 0);
			while (!( stop & 0x40000000 )) {//while (!( stop & 0x40000000 ))
				   stop = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 0);
			}
			print("FIN LAVADO\n\r");
			LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0, 255);//ROJO
			LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 0);//VERDE
			LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 255);//AZUL
			melodiaFinSecado();
		}else{
			data = 0x3C000000;
			for(i = 1; i <= 1000; i++){
				MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );
				estado = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 4);
				// printing data from hyperterminal
				xil_printf(" %d  \n\r", estado);
			}
			//data = 0x40000000;
			//MOTOR_HW_mWriteReg ( BASE_ADDRESS_MOTOR , 0, data );

			stop = MOTOR_HW_mReadReg (BASE_ADDRESS_MOTOR , 0);
			while (( stop & 0x40000000 )) {//while (!( stop & 0x40000000 ))
			   stop = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 0);
			}
			 stop = MOTOR_HW_mReadReg (BASE_ADDRESS_MOTOR , 0);
			while (!( stop & 0x40000000 )) {//while (!( stop & 0x40000000 ))
				   stop = MOTOR_HW_mReadReg ( BASE_ADDRESS_MOTOR , 0);
			}
			print("FIN LAVADO\n\r");
			LEDSRGB_mWriteSlaveReg0(BASE_ADDRESS_LEDS, 0, 255);//ROJO
			LEDSRGB_mWriteSlaveReg1(BASE_ADDRESS_LEDS, 0, 0);//VERDE
			LEDSRGB_mWriteSlaveReg2(BASE_ADDRESS_LEDS, 0, 255);//AZUL
			melodiaFinSecado();
		}

    }
 Xil_DCacheDisable();
 Xil_ICacheDisable();
}
print("FIN USO LAVADORA\n\r");

 return 0;

}


