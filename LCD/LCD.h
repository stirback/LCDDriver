#ifndef LCD_H
#define LCD_H

#define D0 0b00000001
#define D1 0b00000010
#define D2 0b00000100
#define D3 0b00001000
#define D4 0b00010000
#define D5 0b00100000
#define D6 0b01000000
#define D7 0b10000000

#include "stm32f407xx.h"

void LCDPrintCharPin(GPIO_TypeDef *GPIO, uint32_t pin, char passedchar, uint8_t port);
void LCDPrintChar(char chartoprint);

#endif
