/*****************************************************************************
* Filename:          C:\SE\motorola/drivers/altavoz_v1_00_a/src/altavoz.c
* Version:           1.00.a
* Description:       altavoz Driver Source File
* Date:              Wed Jun 26 12:26:38 2024 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "altavoz.h"

/************************** Function Definitions ***************************/

void my_delay ( int delay ){
	int i, j;
	for (i =0; i<delay; i=i+1)
		for (j =0; j <500; j=j +1){}
}

void ALTAVOZ_calla(){
	ALTAVOZ_mWriteSlaveReg0(XPAR_ALTAVOZ_0_BASEADDR, 0, SILENCIO);
}

void ALTAVOZ_suena ( Xuint32 nota , Xuint32 octava ) {
	ALTAVOZ_mWriteSlaveReg0(XPAR_ALTAVOZ_0_BASEADDR , 0, nota << octava );
}
void parada(){
	ALTAVOZ_suena (RE , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (LA , OCTAVA );
	my_delay (300);
	ALTAVOZ_calla();
	my_delay (300);
}
void abriendoPuertas(){
	ALTAVOZ_suena (DO , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (MI , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (LA , OCTAVA );
	my_delay (300);
	ALTAVOZ_calla();
	my_delay (300);
}
void cerrandoPuertas(){
	ALTAVOZ_suena (LA , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (MI , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (DO , OCTAVA );
	my_delay (300);
	ALTAVOZ_calla();
	my_delay (300);
}
void altavozdemo(){
	ALTAVOZ_suena (DO , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (RE , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (MI , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (FA , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena(SOL, OCTAVA);
	my_delay (300);
	ALTAVOZ_suena (LA , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena (SI , OCTAVA );
	my_delay (300);
	ALTAVOZ_suena(DO, (OCTAVA -1));
	my_delay (300);
	ALTAVOZ_calla();
	my_delay (300);
}
