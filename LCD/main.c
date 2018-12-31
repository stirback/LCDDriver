#include "LCD.h"

int main(void)
{
	//INITILIZE START;
	// Enable the GPIO Clock for GPIO
	RCC->AHB1ENR |= (1 << 2);
	RCC->AHB1ENR |= (1 << 0);
	// Set any Control Registers for GPIO pins
	// Moder
	GPIOA->MODER |= 0b01010101;
	GPIOC->MODER |= 0b0101010101010101;
	// OTyper
	GPIOA->OTYPER = 0;
	GPIOC->OTYPER = 0;
	// OSpeedr
	GPIOA->OSPEEDR = 0b10101010;
	GPIOC->OSPEEDR = 0b1010101010101010;
	// PUPDr
	GPIOA->PUPDR = 0;
	GPIOC->PUPDR = 0b1010101010101010;
	//INITILIZE END
	
	// Turn on the LEDs (BSRR)
	//GPIOD->BSRR = (1 << 10); //test LED
	LCDInit(BITMODE8);
	//Writing Letter A (01000001);
	LCDPrintChar('O');
	LCDPrintChar('L');
	LCDPrintChar('E');
	LCDPrintChar('G');
	LCDSecondLine();
	LCDPrintString("STRBAC");
	
while(1)
{
	
}
}

