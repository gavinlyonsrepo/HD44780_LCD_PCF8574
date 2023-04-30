/*!
	@file    TestRun16X02.ino
	@author   Gavin Lyons
	@brief 
		 This file contains the "main" function for  project, a set of test sequence
 		 to test the HD44780_LCD_PCF8574 arduino  library. 16X02 display.
	@note 
		-# Test 1 :: Hello world
		-# Test 2 :: Move the cursor test
		-# Test 3 :: Scroll the display test
		-# Test 4 :: Test GOTO method
		-# Test 5 :: Test clear a line method
		-# Test 6 :: Cursor type (4 off) and screen reset test, Cursor mode is changed with a reset.
		-# Test 7 :: Text entry mode (4 off) if screen is reset the entry mode will be reset to default
		-# Test 8 :: Print numerical data using print() method
		-# Test 9 :: Custom character's from the CGRAM test
		-# Test 10 :: Backlight test.
*/

// Section: Included library 
#include "HD44780_LCD_PCF8574.h"

// Section: Defines
#define DISPLAY_DELAY_1 1000
#define DISPLAY_DELAY_2 2000
#define DISPLAY_DELAY 5000

// Section: Globals
HD44780LCD myLCD( 2, 16, 0x27, &Wire); // instantiate an object 

// Section: Function Prototypes

void helloWorld(void);
void cursorMoveTest(void);
void scrollTest(void);
void gotoTest(void);
void clearLineTest(void); 
void cursorTest(void);
void entryModeTest(void);
void writeNumTest(void);
void customChar(void);
void backLightTest(void);
void endTest(void);

// Section: Setup

void setup() {
  delay(50);
  myLCD.PCF8574_LCDInit(myLCD.LCDCursorTypeOn);
  myLCD.PCF8574_LCDClearScreen();
  myLCD.PCF8574_LCDBackLightSet(true);

}

// Section: Main Loop

void loop() {
  
  helloWorld(); 
  cursorMoveTest(); 
  scrollTest();
  gotoTest();
  clearLineTest();
  cursorTest();
  entryModeTest(); 
  writeNumTest(); 
  customChar();  
  backLightTest();
  
} // End of Main

// Section :  Functions

void helloWorld(void) {
	char teststr1[] = "Hello";
	char teststr2[] = "World";
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 0);
	myLCD.PCF8574_LCDSendString(teststr1);
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo , 0);
	myLCD.PCF8574_LCDSendString(teststr2); // Display a string
	myLCD.PCF8574_LCDSendChar('!'); // Display a single character
	delay(DISPLAY_DELAY_1);
}

void cursorMoveTest(void) {
	myLCD.PCF8574_LCDMoveCursor(myLCD.LCDMoveRight, 2);
	delay(DISPLAY_DELAY);
	myLCD.PCF8574_LCDMoveCursor(myLCD.LCDMoveLeft, 2);
}

void scrollTest(void) {
	for (uint8_t i = 0; i < 5; i++) {
		myLCD.PCF8574_LCDScroll(myLCD.LCDMoveRight, 1);
		delay(DISPLAY_DELAY_2);
	}
	myLCD.PCF8574_LCDScroll(myLCD.LCDMoveLeft, 5);
	delay(DISPLAY_DELAY_2);
}

void gotoTest(void) {
	char teststr3[] = "Line 2";
	myLCD.PCF8574_LCDClearScreen();
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 10);
	myLCD.PCF8574_LCDSendChar('A');
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo , 2);
	myLCD.PCF8574_LCDSendString(teststr3);
	delay(DISPLAY_DELAY);
}

void clearLineTest(void)
{
	myLCD.PCF8574_LCDClearLine(myLCD.LCDLineNumberTwo );
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearLine(myLCD.LCDLineNumberOne);
	delay(DISPLAY_DELAY_2);
}

void cursorTest(void) {
	char teststr1[] = "Cursor no 4";
	char teststr2[] = "Cursor no 1";
	char teststr3[] = "Cursor no 2";
	char teststr4[] = "Cursor no 3";
	
	myLCD.PCF8574_LCDResetScreen(myLCD.LCDCursorTypeOnBlink); //type 4 cursor
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo, 0);
	myLCD.PCF8574_LCDSendString(teststr1);
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearLine(myLCD.LCDLineNumberTwo);

	myLCD.PCF8574_LCDResetScreen(myLCD.LCDCursorTypeOff); //type 1 cursor
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo, 0);
	myLCD.PCF8574_LCDSendString(teststr2);
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearLine(myLCD.LCDLineNumberTwo);

	myLCD.PCF8574_LCDResetScreen(myLCD.LCDCursorTypeBlink); //type 2 cursor
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo, 0);
	myLCD.PCF8574_LCDSendString(teststr3);
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearLine(myLCD.LCDLineNumberTwo);

	myLCD.PCF8574_LCDResetScreen(myLCD.LCDCursorTypeOn); // Back to initial state , type 3
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo, 0);
	myLCD.PCF8574_LCDSendString(teststr4);
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearLine(myLCD.LCDLineNumberTwo);
}

void writeNumTest()
{
	int numPos = 193;
	int numNeg = -8582;
	double myPI = 3.1456;
	
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 0);
	myLCD.print(numPos);
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo , 0);
	myLCD.print(numNeg);
	myLCD.PCF8574_LCDMoveCursor(myLCD.LCDMoveRight, 2);
	myLCD.print(myPI,3);  
	
	delay(DISPLAY_DELAY);
	myLCD.PCF8574_LCDClearScreen();
	
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 0); // 11
	myLCD.print(11);
	myLCD.PCF8574_LCDMoveCursor(myLCD.LCDMoveRight, 2);  // 13
	myLCD.print(11,OCT);
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo , 0); // B
	myLCD.print(11, HEX);
	myLCD.PCF8574_LCDMoveCursor(myLCD.LCDMoveRight, 2); // 1011
	myLCD.print(11,BIN);
	
	delay(DISPLAY_DELAY);
}

void customChar(void) {
	uint8_t index = 0; //  Character generator RAM location ,0-7 ,64 bytes
  // custom characters data to test custom character function
  uint8_t symbolData[8][8] = {
      {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00}, // bell
      {0x02, 0x03, 0x02, 0x0E, 0x1E, 0x0C, 0x00, 0x00},  // Note
      {0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00, 0x00},  // clock
      {0x00, 0x0C, 0x1D, 0x0F, 0x0F, 0x06, 0x00, 0x00},  // duck
      {0x00, 0x01, 0x03, 0x16, 0x1C, 0x08, 0x00, 0x00},  // check
      {0x00, 0x1B, 0x0E, 0x04, 0x0E, 0x1B, 0x00, 0x00},  // cross
      {0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00},  // heart
      {0x01, 0x01, 0x05, 0x09, 0x1F, 0x08, 0x04, 0x00}   // return arrow
    };

	myLCD.PCF8574_LCDClearScreen();

	// Load the CGRAM with the data , custom characters
	// location argument must be 0 to 7  , load the data into LCD memory
  for (uint8_t index  = 0; index  < 8; index++) {
      myLCD.PCF8574_LCDCreateCustomChar(index , symbolData[index]);
    }
  myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 0);

	// Print out custom characters from 
	// CGRAM locations 0-7 , location argument must be 0 to 7 
	for (index = 0; index < 8; index ++) {
		myLCD.PCF8574_LCDPrintCustomChar(index);
		myLCD.PCF8574_LCDMoveCursor(myLCD.LCDMoveRight, 1);
	}

	delay(DISPLAY_DELAY);
	myLCD.PCF8574_LCDClearScreen();
}

void backLightTest(void)
{
  char teststr4[] = "Back Light :: ";

	myLCD.PCF8574_LCDBackLightSet(false); 	// Needs another command/data before it changes Light
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo , 1);
	myLCD.PCF8574_LCDSendString(teststr4);
  myLCD.print(myLCD.PCF8574_LCDBackLightGet()); // read the backlight variable  status
	delay(DISPLAY_DELAY);

	myLCD.PCF8574_LCDBackLightSet(true); 	// Needs another command/data before it changes Light
	myLCD.PCF8574_LCDClearScreen();
}

void entryModeTest(void) {

	char teststr8[] = "1234";
	
	myLCD.PCF8574_LCDChangeEntryMode(myLCD.LCDEntryModeOne);
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberOne, 8);
	myLCD.PCF8574_LCDSendString(teststr8); // <-C4321
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearScreenCmd();

	myLCD.PCF8574_LCDChangeEntryMode(myLCD.LCDEntryModeTwo);
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo, 8);
	myLCD.PCF8574_LCDSendString(teststr8); // C4321->
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearScreenCmd();

	myLCD.PCF8574_LCDChangeEntryMode(myLCD.LCDEntryModeFour);
	myLCD.PCF8574_LCDGOTO(myLCD.LCDLineNumberTwo, 8);
	myLCD.PCF8574_LCDSendString(teststr8); // <-1234C
	delay(DISPLAY_DELAY_2);
	myLCD.PCF8574_LCDClearScreenCmd();

	myLCD.PCF8574_LCDChangeEntryMode(myLCD.LCDEntryModeThree); // Set back to default entry mode
	myLCD.PCF8574_LCDClearScreenCmd();
	delay(DISPLAY_DELAY_1);
}

// *** EOF ***
