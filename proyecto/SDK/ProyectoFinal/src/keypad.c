#include "keypad.h"
#include "xparameters.h"

Xuint32 KEYPAD_getKey(){
	Xuint32 key = KEYPAD_mReadReg(XPAR_KEYPAD_0_BASEADDR, 0);
	key = key >> 28;
	return key;
}
