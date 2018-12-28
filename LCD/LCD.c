#include "LCD.h"

void LCDSetPin(GPIO_TypeDef *GPIO, uint32_t pin, char passedchar, uint8_t port){
	
	if((passedchar & port) != 0){
		GPIO->BSRR = (1 << pin);
	}
	else{
		GPIO->BSRR = (1 << (pin+16));
	}
}

void LCDPrintCharPins(char chartoprint){
	LCDSetPin(GPIODATA, GPIODATAPIND0, chartoprint, D0);
	LCDSetPin(GPIODATA, GPIODATAPIND1, chartoprint, D1);
	LCDSetPin(GPIODATA, GPIODATAPIND2, chartoprint, D2);
	LCDSetPin(GPIODATA, GPIODATAPIND3, chartoprint, D3);
	LCDSetPin(GPIODATA, GPIODATAPIND4, chartoprint, D4);
	LCDSetPin(GPIODATA, GPIODATAPIND5, chartoprint, D5);
	LCDSetPin(GPIODATA, GPIODATAPIND6, chartoprint, D6);
	LCDSetPin(GPIODATA, GPIODATAPIND7, chartoprint, D7);
	Delay(80000);
	GPIOCOMMAND->BSRR = (1 << (ENABLEPIN+16)); //Reset Enable (0)
};

void Delay(int time){
	volatile int i;
	for(i = 0; i < time; i++);
}

void LCDReadMode(){
	GPIOCOMMAND->BSRR = (1 << RWPIN); //Set R/W to read (1)
}

void LCDWriteMode(){
	GPIOCOMMAND->BSRR = (1 << (RWPIN+16)); //Set R/W to write (0)
}

void LCDDataMode(){
	GPIOCOMMAND->BSRR = (1 << RSPIN); //Set Register Select to Data Mode (1)
}

void LCDCommandMode(){
	GPIOCOMMAND->BSRR = (1 << (RSPIN+16)); //Set Register Select to Command Mode (0)
}

void LCDEnable(){
	Delay(40000);
	GPIOCOMMAND->BSRR = (1 << ENABLEPIN); //Set Enable (1)
}

void LCDPrintChar(char c){
	LCDDataMode();
	LCDWriteMode();
	LCDEnable();
	LCDPrintCharPins(c);
}

void LCDSendCommand(char command){
	LCDCommandMode();
	LCDWriteMode();
	LCDEnable();
	LCDPrintCharPins(command);
}

void LCDInit(){
	LCDSendCommand(0b00111000); //Function Set
	LCDSendCommand(0b00001110); //Turn on display
	LCDSendCommand(0b00000110); //Increment and shift cursor
}
