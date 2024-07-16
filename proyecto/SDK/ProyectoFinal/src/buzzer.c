#include "buzzer.h"

void buzzer_init(XGpio* gpio, Xuint32 id) {
	Xuint32 status;
	status = XGpio_Initialize(gpio, id);

	if (status == XST_SUCCESS) XGpio_SetDataDirection(gpio, 1, 0x00);
}

void buzzer_suena(XGpio* gpio) {
	XGpio_DiscreteWrite(gpio, 1, (u8)0);
}

void buzzer_calla(XGpio *gpio) {
	XGpio_DiscreteWrite(gpio, 1, (u8)1);
}

void retardo(){
	unsigned int i;
	for(i = 0; i < 0x00070000; i++);
}

void buzzer_oscila() {
	XGpio gpio;
	Xuint32 id = XPAR_XPS_GPIO_0_DEVICE_ID;

	buzzer_init(&gpio, id);

	buzzer_suena(&gpio);
	//retardo();
	buzzer_calla(&gpio);
	//retardo();
	buzzer_suena(&gpio);
	//retardo();
	buzzer_calla(&gpio);
}
