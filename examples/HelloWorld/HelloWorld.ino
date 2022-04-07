/*
 * File: HelloWorld.ino
 * Author: Gavin Lyons.
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/HD44780_LCD_PCF8574
 */

// Section: Included library 
#include "HD44780_LCD_PCF8574.h"

// Section: Globals
// myLCD(rows , cols , PCF8574 I2C address)
HD44780LCD myLCD( 2, 16, 0x27); // instantiate a LCD object

// Section: Setup

void setup() 
{
  delay(50);
  myLCD.PCF8574_LCDInit(LCDCursorTypeOn);
  myLCD.PCF8574_LCDClearScreen();
  myLCD.PCF8574_LCDBackLightSet(true);
  myLCD.PCF8574_LCDGOTO(LCDLineNumberOne, 0);
}

// Section: Main Loop

void loop() 
{  
  char testString[] = "Hello World";
  myLCD.PCF8574_LCDSendString(testString);
  myLCD.PCF8574_LCDSendChar('!'); // Display a single character
  while(true){};
  
} 

// EOF
