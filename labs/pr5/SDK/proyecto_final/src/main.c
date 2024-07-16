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

void practica5();
void escribeLineaLCD(char line);

int main() {
	   Xil_ICacheEnable();

	   Xil_DCacheEnable();

	   practica5();

	   Xil_DCacheDisable();

	   Xil_ICacheDisable();

	   return 0;
}

void practica5(){
	//EN ESTA PRACTICA VAMOS A USAR EL LCD, EL KEYPAD Y EL LED RGB
	//EL RESULTADO SER�A SIMULAR EN EL LCD LOS CARTELES QUE UTILIZAN LOS AUTBOUSES PARA INDICAR QUE LINEA SON
	//PARA ELLO EL USUARIO PODR� CAMBIAR EL VALOR EN EL LCD PULSANDO UNA DE LAS TECLAS DEL KEYPAD, DONDE CADA UNO DE ESOS VALORES CORRESPONDE A UNA LINEAS (L�NEAS 0-9 Y A-F)
	//SE MOSTRAR� ENTONCES LA L�NEA Y DE DONDE A DONDE VA
	//EL LED SE USAR� PARA REPRESENTAR EL COLOR DEL AUTOBUS:
	//	- SI ES UNA LINEA QUE VA DE UN PUNTO A OTRO PUNTO DE MADRID ES PONDR� AZUL
	//	- SI ES UNA LINEA QUE INVOLUCRA A MADRID Y OTRO SITIO EL LED ES VERDE
	//	- SI ES UNA LINEA QUE INVOLUCRA DOS SITIOS QUE NO SON DE MADRID ES ROJO
	Xuint32 pressedKey, keypadValue;
	char lastLine = 'g', line;

	LCD_inicializa();
	LED_init();

	while(1){
		pressedKey = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR, 0);
		keypadValue = transformKey(pressedKey);
		line = keyToChar(keypadValue);

		if(line != lastLine){//si se indica la misma linea, cambiamos la direccion
			escribeLineaLCD(line);
			lastLine = line;
		}
	}
}
void escribeLineaLCD(char line){
	char* arrival;

	switch(line){
		case '0'://verde
			arrival = "CiU-BCN";
			LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
			break;
		case '1'://azul
			arrival = "Pio-Cuzco";
			LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
			break;
		case '2'://rojo
			arrival = "BCN-Cuenca";
			LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
			break;
		case '3'://azul
			arrival = "Sol-Cibeles";
			LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
			break;
		case '4'://azul
			arrival = "CiU-Sol";
			LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
			break;
		case '5'://verde
			arrival = "Sol-BCN";
			LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
			break;
		case '6'://azul
			arrival = "Gran Via-CiU";
			LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
			break;
		case '7'://verde
			arrival = "Madrid-Cielo";
			LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
			break;
		case '8'://verde
			arrival = "Murcia-CiU";
			LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
			break;
		case '9'://rojo
			arrival = "Kansas-Mucho";
			LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
			break;
		case 'A'://verde
			arrival = "Kenia-Cuzco";
			LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
			break;
		case 'B'://verde
			arrival = "Moncloa-BCN";
			LED_ponColor(VERDE_R, VERDE_G, VERDE_B);
			break;
		case 'C'://rojo
			arrival = "Kenia-BCN";
			LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
			break;
		case 'D'://rojo
			arrival = "Murcia-BCN";
			LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
			break;
		case 'E'://rojo
			arrival = "Marte-BCN";
			LED_ponColor(ROJO_R, ROJO_G, ROJO_B);
			break;
		case 'F'://azul
			arrival = "CiU-Mi Casa";
			LED_ponColor(AZUL_R, AZUL_G, AZUL_B);
			break;
		default: break;
	}

	arrival += '\0';

	LCD_enviarCMD(CLEAR_DISPLAY_CMD);
	LCD_enviarCMD(RETURN_HOME_CMD);
	LCD_enviarCMD(WRITE_CMD);

	LCD_enviarCMD(WRITE_CMD + 'L');
	LCD_enviarCMD(WRITE_CMD + 'i');
	LCD_enviarCMD(WRITE_CMD + 'n');
	LCD_enviarCMD(WRITE_CMD + 'e');
	LCD_enviarCMD(WRITE_CMD + 'a');
	LCD_enviarCMD(WRITE_CMD + ' ');
	LCD_enviarCMD(WRITE_CMD + line);

	LCD_enviarCMD(SECOND_ROW);

	int i = 0;
	char letra;
	while(arrival[i]!='\0'){
		letra = arrival[i];
		LCD_enviarCMD(WRITE_CMD + letra);
		i++;
	}
}

