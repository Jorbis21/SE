//idea nocturna entre sábanas: tras leer del keypad hacer los condicionales con 0xV siendo V el valor
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
#include "lcd.h"
#include "leds.h"
#include "motor.h"
#include "buzzer.h"

static unsigned int SEED = 1;
unsigned int userMoney = 100;
void init();
int rand();
Xuint32 apuesta();
void apuestaNoValida(unsigned int *bill);
void putValueOnLCD(unsigned int *bill, Xuint32 tecla);
void init();

int main() {
    Xuint32 bill, tecla;
    char mensaje[4];
    char *msg;
    unsigned int i, ganar = 1, fin = 0;

    init();

    LCD_EnviarMensaje("Bienvenido, tienes ");
    msg = userMoney + '0';
    LCD_EnviarMensaje(msg);
    LCD_EnviarMensaje("$");
    //for(i = 0; i < 0x00070000; i++);

    while(!fin){
    	LCD_init();
        bill = apuesta();

        msg = '.';
        //generamos array
        for(i = 0; i < 4; i++){
        	msg+='|';
            switch(rand()%4){
            case 0:
                mensaje[i] = '+';
                break;
            case 1:
                mensaje[i] = '-';
                break;
            case 2:
                mensaje[i] = 'x';
                break;
            case 3:
                mensaje[i] = 'o';
                break;
            }
            msg+=mensaje[i];
            msg+='|';
        }
        msg+= '.';

    	LCD_init();
        LCD_EnviarMensaje(mensaje);

        i = 1;
        while(i < 3 && ganar){
            if(mensaje[1] != mensaje[i]){
                ganar = 0;
            }
        }

        LCD_enviarCMD(SECOND_ROW);
        if(ganar){
            LCD_EnviarMensaje("HAS GANADO");
            motorGiro();
            buzzer_oscila();
            LED_doParty();
            userMoney += bill;
        }
        else{
            LCD_EnviarMensaje("HAS PERDIDO");
            userMoney -= bill;
        }

        LCD_init();
        LCD_EnviarMensaje("Tienes ");
        msg = userMoney + '0';
        LCD_EnviarMensaje(msg);
        LCD_EnviarMensaje("$");
        //for(i = 0; i < 0x00070000; i++);

        LCD_init();
        LCD_EnviarMensaje("A Abandonar C Continuar");

        if(userMoney==0){
        	fin = 1;
            LCD_init();
            LCD_EnviarMensaje("Te quedaste sin dinero");
        } else {
            do{
            	tecla = KEYPAD_getKey();
            }while(tecla != 'A'|| tecla != 'C');

            if(tecla == 'A'){
            	fin = 1;
            }
        }
    }
    return 0;
}

int rand(void){
    SEED = SEED * 1103515245 + 12345;
    return (unsigned int)(SEED/65536) % 32768;
}

Xuint32 apuesta(){
	Xuint32 tecla;
	unsigned int aceptada = 0, bill = 0;

	LCD_EnviarMensaje("Inserte apuesta");
	LCD_enviarCMD(SECOND_ROW);
	while(!aceptada){
		tecla = KEYPAD_getKey();
		switch(tecla){
			case 'A'://'a'
				if(bill > 0 && bill <= userMoney){
					aceptada = 1;
				}
				else{
					apuestaNoValida(&bill);
				}
				break;
			case 'C'://'c'
				apuestaNoValida(&bill);
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				putValueOnLCD(&bill, tecla);
				break;
			default:
				break;
		}

	}
	return bill;
}

void apuestaNoValida(unsigned int *bill){
	LCD_init();
	bill = 0;
	LCD_EnviarMensaje("Inserte apuesta");
	LCD_enviarCMD(SECOND_ROW);
}

void putValueOnLCD(unsigned int *bill, Xuint32 tecla){
	char* msg;
	*bill = tecla + *bill *10;

	LCD_init();
	LCD_EnviarMensaje("Inserte apuesta");
	LCD_enviarCMD(SECOND_ROW);
    msg = *bill + '0';
    LCD_EnviarMensaje(msg);
}

void init(){
    LCD_init();
    LED_apagaAzul();
    LED_apagaRojo();
    LED_apagaVerde();
}