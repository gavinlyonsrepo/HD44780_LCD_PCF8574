/*
 * File: HelloWorld.ino
 * Author: Gavin Lyons.
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/HD44780_LCD_PCF8574
 */

// Section: Included library
#include "HD44780_LCD_PCF8574.h"

// Section: Defines
#define DISPLAY_DELAY_INIT 50 // mS
// **** NOTE ::  Comment in If using STM32 bluepill ****
//#define STM32_BLUE_PILL_SETUP


// Section: Globals
#ifdef STM32_BLUE_PILL_SETUP // *** STM32 Blue Pill *** 
// Set-up Choice I2C interface 1 or 2 :: pick one and one only 
TwoWire Wire2(1,I2C_FAST_MODE); // Use STM32 I2C1 
//TwoWire Wire2(2,I2C_FAST_MODE); // Use STM32 I2C2 
HD44780LCD myLCD(2, 16, 0x27, &Wire2); // LCD object.rows ,cols ,PCF8574 I2C addr, Interface)
#else
// myLCD(rows , cols , PCF8574 I2C address)
HD44780LCD myLCD( 2, 16, 0x27); // instantiate an object
#endif

// Section: Setup

void setup() {
  delay(DISPLAY_DELAY_INIT);
  myLCD.PCF8574_LCDInit(LCDCursorTypeOn);
  myLCD.PCF8574_LCDClearScreen();
  myLCD.PCF8574_LCDBackLightSet(true);
  myLCD.PCF8574_LCDGOTO(LCDLineNumberOne, 0);
}

// Section: Main Loop

void loop() {
  char testString[] = "Hello World";
  myLCD.PCF8574_LCDSendString(testString);
  myLCD.PCF8574_LCDSendChar('!');  // Display a single character
  while (true) {};
}

// EOF
