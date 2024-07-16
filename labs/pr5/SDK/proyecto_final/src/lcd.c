/*****************************************************************************
* Filename:          U:\hlocal\git\SE\extraordinaria\proyecto/drivers/lcd_v1_00_a/src/lcd.c
* Version:           1.00.a
* Description:       lcd Driver Source File
* Date:              Fri Jun 07 16:01:54 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "lcd.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/

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
	// Comprobamos que la FIFO no esté llena
	while(LCD_mWriteFIFOFull(XPAR_LCD_0_BASEADDR));

	// Escribimos el comando en la FIFO
	LCD_mWriteToFIFO(XPAR_LCD_0_BASEADDR, 0, cmd);
}
