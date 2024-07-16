#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xbram.h"
#include "bram_header.h"
//Perif�ricos usados en el proyecto
#include "keypad.h"
#include "lcd.h"
#include "leds.h"
#include "altavoz.h"
#include "motor_hw.h"

#define CERRADAS 0
#define SOLICITADA 1
#define ABIERTAS 2

void ordenadorCentralBus();
void escribeLineaLCD(char line);
unsigned int gestionPuertas(char key, unsigned int state);

int main() {
	   Xil_ICacheEnable();

	   Xil_DCacheEnable();

	   ordenadorCentralBus();

	   Xil_DCacheDisable();

	   Xil_ICacheDisable();

	   return 0;
}

void ordenadorCentralBus(){
    Xuint32 pressedKey, keypadValue;
    char key, lastKey = 'G', ultimaLinea;

    unsigned int estadoPuertas, newState, entrar = 0;

    LCD_inicializa();
    LED_init();

    estadoPuertas = CERRADAS;
    LED_ponColor(ROJO_R, ROJO_G, ROJO_B);

    while(1){
        pressedKey = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR, 0);
        keypadValue = transformKey(pressedKey);
        key = keyToChar(keypadValue);

        if(key != lastKey){
        	escribeLineaLCD(key);
            if(key == 'F' || key == 'E' || key == 'D'){//apertura/cierre de puertas o solicitar parada
            	if(entrar == 0){
            		ultimaLinea = lastKey;
            		entrar = 1;
            	}
                newState = gestionPuertas(key, estadoPuertas);
                estadoPuertas = newState;
                if(key == 'E'){
                	escribeLineaLCD(ultimaLinea);
                	entrar = 0;
                }
            }

        lastKey = key;
        }
    }
}
void escribeLineaLCD(char line){
	char* arrival;

	switch(line){
		case '0':
			arrival = "Marte-BCN";
			escribeLinea(line);
			break;
		case '1':
			arrival = "Pio-Cuzco";
			escribeLinea(line);
			break;
		case '2':
			arrival = "BCN-Cuenca";
			escribeLinea(line);
			break;
		case '3':
			arrival = "Sol-Cibeles";
			escribeLinea(line);
			break;
		case '4':
			arrival = "CiU-Sol";
			escribeLinea(line);
			break;
		case '5':
			arrival = "Sol-BCN";
			escribeLinea(line);
			break;
		case '6':
			arrival = "Gran Via-CiU";
			escribeLinea(line);
			break;
		case '7':
			arrival = "Madrid-Cielo";
			escribeLinea(line);
			break;
		case '8':
			arrival = "Murcia-CiU";
			escribeLinea(line);
			break;
		case '9':
			arrival = "Kansas-Mucho";
			escribeLinea(line);
			break;
		case 'A':
			arrival = "Kenia-Cuzco";
			escribeLinea(line);
			break;
		case 'B':
			arrival = "CiU-Mi Casa";
			escribeLinea(line);
			break;
		case 'C':
			arrival = "Kenia-BCN";
			escribeLinea(line);
			break;
		case 'D':
			escribeParada();
			arrival = "Solicitada";
			break;
		case 'E':
			escribeCerrando();
			arrival = "Puertas";
			break;
		case 'F':
			escribeAbriendo();
			arrival = "Puertas";
			break;
		default: break;
	}

	arrival += '\0';


	int i = 0;
	char letra;
	while(arrival[i]!='\0'){
		letra = arrival[i];
		LCD_enviarCMD(WRITE_CMD + letra);
		i++;
	}
}



unsigned int gestionPuertas(char key, unsigned int state){
    unsigned int newState;

    switch(state){
		case CERRADAS:
			if(key == 'D'){
				LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
				newState = SOLICITADA;
				parada();//como es la primera vez que se solicita la parada suena el zumbador
			}
			else if (key == 'F'){
				LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
				newState = ABIERTAS;
				motorAntihorario();
			}
			else{
				LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
				newState = state;
			}
		break;
		case SOLICITADA:
			if (key == 'F'){
				LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
				newState = ABIERTAS;
				motorAntihorario();
			}
			else{
				LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
				newState = state;
			}
		break;
		case ABIERTAS:
			if (key == 'E'){
				LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
				newState = CERRADAS;
				motorHorario();
			}
			else{
				LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
				newState = state;
			}
		break;
		default:
		break;
    }


    return newState;
}
