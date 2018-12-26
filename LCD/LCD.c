#include "stm32f407xx.h"
#include "LCD.h"

void LCDPrintChar(GPIO_TypeDef *GPIO, uint32_t pin, uint8_t chartoprint){
	
	if(chartoprint & 0b00000001){
		GPIO->BSRR = (1 << pin);
	}
}
