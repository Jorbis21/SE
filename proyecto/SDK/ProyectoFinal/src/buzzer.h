#ifndef BUZZER_H_
#define BUZZER_H_

#include "xparameters.h"
#include "stdio.h"
#include "xutil.h"

#include "xgpio.h"

void buzzer_init(XGpio* Gpio_zumbador, Xuint32 zumbador);
void buzzer_suena(XGpio* Gpio_zumbador);
void buzzer_calla(XGpio *Gpio_zumbador);
void retardo();
void buzzer_oscila();

#endif
