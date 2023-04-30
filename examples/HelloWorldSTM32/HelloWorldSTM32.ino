 /*!
	@file     HelloWorldSTM32.ino
	@author   Gavin Lyons
	@brief 
		 Hello World for HD44780_LCD_PCF8574 arduino library  for STM32 "blue pill"
	@note Allows testing of both I2C ports 1 and 2 on the STM32 "blue pill" board
*/

// Section: Included library
#include "HD44780_LCD_PCF8574.h"

// Section: Defines
#define DISPLAY_DELAY_INIT 50 // mS
#define STM_I2C1_PORT 1 //  STM32 I2C port 1 = I2C1 
#define STM_I2C2_PORT 2 //  STM32 I2C port 2 = I2C2 

// Section: Globals
TwoWire Wire2(STM_I2C1_PORT);  // use I2C1 Port 1
HD44780LCD myLCD(2, 16, 0x27, &Wire2); 

// Section: Setup

void setup() {
  delay(DISPLAY_DELAY_INIT);
  myLCD.PCF8574_LCDInit(myLCD.LCDCursorTypeOn);
  myLCD.PCF8574_LCDClearScreen();
  myLCD.PCF8574_LCDBackLightSet(true);
  myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 0);
}

// Section: Main Loop

void loop() {
  char testString[] = "Hello World";
  myLCD.PCF8574_LCDSendString(testString);
  myLCD.PCF8574_LCDSendChar('!');  // Display a single character
  while (true) {};
}

// EOF
