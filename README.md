# LCD DRIVER

Developed a driver for the LCD1602A for use with the STM32F407 microcontroller as a personal project using C and the datasheets for the LCD and the STM32F407 to provide an easy interface between them. The driver allows the microcontroller to send commands and data via GPIO pins to modify the LCD display.

![alt text](https://github.com/stirback/LCDDriver/blob/master/Pictures/Data1.jpg)
![alt text](https://github.com/stirback/LCDDriver/blob/master/Pictures/Data2.jpg)
### Prerequisites

Requires a STM32F407 microcontroller, use #include "LCD.h" to include the driver in your code.

### Commands available: 

- void LCDInit(uint32_t bittype);
- void LCDClear(void);
- void LCDSecondLine(void); 
- void LCDResetCursor(void);
- void LCDCursorRight(void);
- void LCDCursorLeft(void);
- void LCDDisplayRight(void);
- void LCDDisplayLeft(void);

### Data Commands available: 

- void LCDPrintChar(char chartoprint);
- void LCDPrintString(char* string);


### void LCDInit(uint32_t bittype);
- Used to initialize the LCD Library, requires and argument of BITMODE8 (which sets the bitmode to 8 bit) or BITMODE4 (which sets the bitmode to 4 bit). Also turns on the screeen and initilizes the cursor. Call this function before using the LCD library.
![alt text](https://github.com/stirback/LCDDriver/blob/master/Pictures/Pre-initilization.jpg)
![alt text](https://github.com/stirback/LCDDriver/blob/master/Pictures/ReadyforData.jpg)
```
LCDInit(BITMODE8); or LCDInit(BITMODE4);
```
### void LCDClear(void);
- Used to clear the display of the LCD. The cursor will reset back to original position as well.

```
LCDPrintChar('O'); //Display now displays the letter 'O'
LCDClear();
//This Display is now clear
```
### void LCDSecondLine(void); 
- Moves the cursor to the second line of the LCD. 

```
LCDPrintChar('O'); //Prints on first line
LCDSecondLine();
LCDPrintChar('L'); //Prints on second line
```
### void LCDResetCursor(void);
- Resets the cursor back to the original position on the LCD, will overwrite characters if already there

```
LCDPrintChar('O'); //Prints on first line 1st position
LCDPrintChar('L'); //Prints on first line 2nd position
LCDResetCursor();
LCDPrintChar('L'); //Prints on first line 1st position
```
### void LCDCursorRight(void);
- Moves the cursor one position over to the right
```
//Cursor is initially first line and 1st position
LCDCursorRight();
//Cursor is now at first line and 2nd position
```
### void LCDCursorLeft(void);
- Moves the cursor one position over to the Left
```
//Cursor is initially first line and 1st position
LCDPrintChar('O'); //Prints on first line 1st position
LCDPrintChar('L'); //Prints on first line 2nd position
LCDCursorLeft();
//Cursor is now at first line and 1st position
```
### void LCDDisplayRight(void);
- Shifts the display of the LCD to the right
```
LCDDisplayRight();
//All text on LCD is shifted to the right by one.
```
### void LCDDisplayLeft(void);
- Shifts the display of the LCD to the left
```
LCDDisplayLeft();
//All text on LCD is shifted to the left by one.
```

### void LCDPrintChar(char chartoprint);
- Prints a character to the LCD screen and increments the cursor by one
```
LCDPrintChar('O'); //Prints on first line 1st position
LCDPrintChar('L'); //Prints on first line 2nd position
```
### void LCDPrintString(char* string);
```
LCDPrintString("OLEG"); //Prints on first line 1st, 2nd, 3rd and 4th position. The cursor is now located at the 5th position.
```
