#include "stm32f407xx.h"
#include "LCD.h"

void LCDPrintCharPin(GPIO_TypeDef *GPIO, uint32_t pin, char passedchar, uint8_t port){
	
	if((passedchar & port) != 0){
		GPIO->BSRR = (1 << pin);
	}
	else{
		GPIO->BSRR = (1 << (pin+16));
	}
}

void LCDPrintChar(char chartoprint){
	LCDPrintCharPin(GPIOA, 0, chartoprint, D0);
	LCDPrintCharPin(GPIOA, 1, chartoprint, D1);
	LCDPrintCharPin(GPIOA, 2, chartoprint, D2);
	LCDPrintCharPin(GPIOA, 3, chartoprint, D3);
	LCDPrintCharPin(GPIOA, 4, chartoprint, D4);
	LCDPrintCharPin(GPIOA, 5, chartoprint, D5);
	LCDPrintCharPin(GPIOA, 6, chartoprint, D6);
	LCDPrintCharPin(GPIOA, 7, chartoprint, D7);
};
