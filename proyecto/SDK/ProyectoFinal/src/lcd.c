/***************************** Include Files *******************************/

#include "lcd.h"
#include "xparameters.h"

/************************** Function Definitions ***************************/


void LCD_enviarCMD(Xuint32 cmd){
	while(LCD_mWriteFIFOFull(XPAR_LCD_0_BASEADDR));
	LCD_mWriteToFIFO(XPAR_LCD_0_BASEADDR, 0, cmd);
}

void LCD_EnviarMensaje(char* mensaje){
	int i=0;
	while(mensaje[i] != '\0'){
		LCD_enviarCMD(WRITE_CMD + mensaje[i]);
		if(i == 15){
			LCD_enviarCMD(SECOND_ROW);
		}
		i++;
	}
}
void LCD_init(){
	LCD_mResetWriteFIFO(XPAR_LCD_0_BASEADDR);

	LCD_enviarCMD(CLEAR_DISPLAY_CMD);

	LCD_enviarCMD(RETURN_HOME_CMD); // moverse al comienzo de la pantalla LCD

	LCD_enviarCMD(WRITE_CMD); // primera escritura
}
