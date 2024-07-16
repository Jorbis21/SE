/*****************************************************************************
* Filename:          C:\SE\motorola/drivers/lcd_v1_00_a/src/lcd.c
* Version:           1.00.a
* Description:       lcd Driver Source File
* Date:              Wed Jun 26 11:42:56 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "lcd.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/
void escribeAbriendo(){
	LCD_enviarCMD(CLEAR_DISPLAY_CMD);
	LCD_enviarCMD(RETURN_HOME_CMD);
	LCD_enviarCMD(WRITE_CMD);

	LCD_enviarCMD(WRITE_CMD + 'A');
	LCD_enviarCMD(WRITE_CMD + 'b');
	LCD_enviarCMD(WRITE_CMD + 'r');
	LCD_enviarCMD(WRITE_CMD + 'i');
	LCD_enviarCMD(WRITE_CMD + 'e');
	LCD_enviarCMD(WRITE_CMD + 'n');
	LCD_enviarCMD(WRITE_CMD + 'd');
	LCD_enviarCMD(WRITE_CMD + 'o');

	LCD_enviarCMD(SECOND_ROW);
}

void escribeCerrando(){
	LCD_enviarCMD(CLEAR_DISPLAY_CMD);
	LCD_enviarCMD(RETURN_HOME_CMD);
	LCD_enviarCMD(WRITE_CMD);

	LCD_enviarCMD(WRITE_CMD + 'C');
	LCD_enviarCMD(WRITE_CMD + 'e');
	LCD_enviarCMD(WRITE_CMD + 'r');
	LCD_enviarCMD(WRITE_CMD + 'r');
	LCD_enviarCMD(WRITE_CMD + 'a');
	LCD_enviarCMD(WRITE_CMD + 'n');
	LCD_enviarCMD(WRITE_CMD + 'd');
	LCD_enviarCMD(WRITE_CMD + 'o');

	LCD_enviarCMD(SECOND_ROW);
}
void lcdDEMO(){
	xil_printf("---Test para el LCD---\n\r");
	LCD_inicializa();
	LCD_enviarCMD(WRITE_CMD + 'H');
	LCD_enviarCMD(WRITE_CMD + 'O');
	LCD_enviarCMD(WRITE_CMD + 'L');
	LCD_enviarCMD(WRITE_CMD + 'A');
	LCD_enviarCMD(SECOND_ROW); // cambio fila
	LCD_enviarCMD(WRITE_CMD + ':');
	LCD_enviarCMD(WRITE_CMD + ')');
}
void LCD_inicializa(){
	LCD_mResetWriteFIFO(XPAR_LCD_0_BASEADDR);

	LCD_enviarCMD(CLEAR_DISPLAY_CMD);

	LCD_enviarCMD(RETURN_HOME_CMD); // moverse al comienzo de la pantalla LCD

	LCD_enviarCMD(WRITE_CMD); // primera escritura
}
void LCD_enviarCMD(Xuint32 cmd){
	// Comprobamos que la FIFO no est� llena
	while(LCD_mWriteFIFOFull(XPAR_LCD_0_BASEADDR));

	// Escribimos el comando en la FIFO
	LCD_mWriteToFIFO(XPAR_LCD_0_BASEADDR, 0, cmd);
}
void escribeLinea(char line){

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
}
void escribeParada(){
	LCD_enviarCMD(CLEAR_DISPLAY_CMD);
	LCD_enviarCMD(RETURN_HOME_CMD);
	LCD_enviarCMD(WRITE_CMD);

	LCD_enviarCMD(WRITE_CMD + 'P');
	LCD_enviarCMD(WRITE_CMD + 'a');
	LCD_enviarCMD(WRITE_CMD + 'r');
	LCD_enviarCMD(WRITE_CMD + 'a');
	LCD_enviarCMD(WRITE_CMD + 'd');
	LCD_enviarCMD(WRITE_CMD + 'a');
	LCD_enviarCMD(SECOND_ROW);
}

