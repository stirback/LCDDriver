#ifndef LCD_H
#define LCD_H

#include "stm32f407xx.h"

void LCDPrintChar(GPIO_TypeDef *GPIO, uint32_t  pin, uint8_t chartoprint);

#endif
