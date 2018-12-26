#include "LCD.h"

void delay(void)
	{
		uint32_t i=0;
		for(i=0; i < 5000000;i++);
}

int main(void)
{
	//GPIO_INIT(GPIOA, 0);
// Enable the GPIO Clock for GPIO
	RCC->AHB1ENR |= (1 << 3);
	RCC->AHB1ENR |= (1 << 0);
// Set any Control Registers for GPIO pins
// Moder
	GPIOD->MODER |= (1 << 20);
	GPIOA->MODER |= 0b0101010101010101;
// OTyper
	GPIOD->OTYPER &= ~(1 << 10);
	GPIOA->OTYPER = 0;
// OSpeedr
	GPIOD->OSPEEDR &= ~( (1 << 21) | (1 << 20) );
	GPIOA->OSPEEDR = 0b1010101010101010;
// PUPDr
	GPIOD->PUPDR &= ~( (1 << 21) | (1 << 20) );
	GPIOA->PUPDR = 0;
	// Turn on the LEDs (BSRR)
	GPIOD->BSRR = (1 << 10); //test LED
	LCDPrintChar(GPIOA, 4, 'A');
	//GPIOA->BSRR = 0b1111111111; //8 LEDs simulation data input to LCD
while(1)
{

}
}

