/*!
	@file     HD44780_LCD_PCF8574.h
	@author   Gavin Lyons
	@brief    HD44780-based character LCD 16x02 I2C(PCF8574) library header file for arduino eco system
	URL: https://github.com/gavinlyonsrepo/HD44780_LCD_PCF8574
*/


#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include "Wire.h"

#ifndef LCD_HD44780_H
#define LCD_HD44780_H

//#define LCD_SERIAL_DEBUG  // Comment in for serial debug I2C errors, set baud  rate externally.

/*!
	@brief Class for HD44780 LCD  
*/
class HD44780LCD : public Print{
public:

	// public enums
	
	/*! Backlight Control ,  Command Byte Code */
	enum LCDBackLight_e : uint8_t{
		LCDBackLightOnMask = 0x0F, /**< XXXX-1111 , Turn on Back light */
		LCDBackLightOffMask = 0x07 /**< XXXX-0111, Turn off Back light */
	}; 
	
	/*! Entry mode control  set command,  Command Byte Code */
	enum LCDEntryMode_e : uint8_t{
		LCDEntryModeOne = 0x04, /**< Display Shift :OFF Decrement Address Counter */
		LCDEntryModeTwo = 0x05, /**< Display Shift :ON  Decrement Address Counter */
		LCDEntryModeThree = 0x06, /**< Display Shift :OFF Increment Address Counter, default */
		LCDEntryModeFour = 0x07 /**<  Display Shift :ON Increment Address Counter */
	}; 

	/*! Cursor mode, Command Byte Code */
	enum LCDCursorType_e : uint8_t {
		LCDCursorTypeOff= 0x0C, /**< Make cursor invisible */
		LCDCursorTypeBlink = 0x0D, /**< Turn on blinking-block cursor */
		LCDCursorTypeOn = 0x0E,  /**< Turn on visible  underline cursor */
		LCDCursorTypeOnBlink  = 0x0F /**<Turn on blinking-block cursor + visible underline cursor */
	}; 
	
	/*! Direction mode for scroll and move */
	enum LCDDirectionType_e : uint8_t {
		LCDMoveRight= 1, /**< move or scroll right */
		LCDMoveLeft = 2   /**< move or scroll left */
	}; 

	/*! Line Row Number */
	enum LCDLineNumber_e : uint8_t{
		LCDLineNumberOne = 1,   /**< row 1 */
		LCDLineNumberTwo = 2,   /**< row 2 */
		LCDLineNumberThree = 3, /**< row 3 */
		LCDLineNumberFour = 4  /**<  row 4 */
	}; 
	
	
	// Constructor's
	HD44780LCD(uint8_t NumRow, uint8_t NumCol, uint8_t I2Caddress,TwoWire *twi );
	~HD44780LCD(){};
	
	// public methods
	void PCF8574_LCDInit (LCDCursorType_e);
	void PCF8574_LCDDisplayON(bool );
	void PCF8574_LCDResetScreen(LCDCursorType_e);
	
	void PCF8574_LCDBackLightSet(bool);
	bool PCF8574_LCDBackLightGet(void);
	
	void PCF8574_LCDSendString (char *str);
	void PCF8574_LCDSendChar (char data);
	void PCF8574_LCDCreateCustomChar(uint8_t location, uint8_t* charmap);
	void PCF8574_LCDPrintCustomChar(uint8_t location);

	void PCF8574_LCDMoveCursor(LCDDirectionType_e, uint8_t moveSize);
	void PCF8574_LCDScroll(LCDDirectionType_e, uint8_t ScrollSize);
	void PCF8574_LCDGOTO(LCDLineNumber_e  lineNo, uint8_t  col);
	void PCF8574_LCDClearLine (LCDLineNumber_e lineNo);
	void PCF8574_LCDClearScreen(void);
	void PCF8574_LCDClearScreenCmd(void);
	void PCF8574_LCDHome(void);
	void PCF8574_LCDChangeEntryMode(LCDEntryMode_e mode);

#if ARDUINO >= 100
		virtual size_t write(uint8_t);
#else
		virtual void   write(uint8_t);
#endif

private:

	// Private internal enums
	
	/*!  DDRAM address's used to set cursor position  Note Private */
	enum LCDAddress_e : uint8_t {
		LCDLineAddressOne =  0x80,  /**< Line 1 */
		LCDLineAddressTwo =  0xC0, /**< Line 2 */
		LCDLineAddress3Col20 = 0x94, /**< Line 3 20x04 line 3 */
		LCDLineAddress4Col20 = 0xD4, /**< Line 4 20x04 line 4 */
		LCDLineAddress3Col16  = 0x90, /**< Line 3 16x04  untested, no part */
		LCDLineAddress4Col16  = 0xD0 /**< Line 4 16x04 untested, no part */
	}; 

	/*!  Command Bytes General  Note Private */
	enum LCDCmdBytesGeneral_e : uint8_t {
		LCDModeFourBit = 0x28, /**< Function set (4-bit interface, 2 lines, 5*7 Pixels) */
		LCDHomePosition  = 0x02, /**< Home (move cursor to top/left character position) */
		LCDDisplayOn = 0x0C,  /**< Restore the display (with cursor hidden) */
		LCDDisplayOff = 0x08, /**< Blank the display (without clearing) */
		LCDClearScreen = 0x01 /**< clear screen */
	};

	
	enum  LCDBackLight_e _LCDBackLight= LCDBackLightOnMask;  /**< Enum to store backlight status*/
	
	// Private Data
	uint8_t _LCDSlaveAddresI2C = 0x27 ; /**< I2C  address for I2C module PCF8574 backpack on LCD*/
	uint8_t _NumRowsLCD = 2; /**< Number of rows on LCD */
	uint8_t _NumColsLCD = 16; /**< Number of Cols on LCD */
	TwoWire *wire;  /**< I2C wire interface */

	// private methods
	void PCF8574_LCDSendCmd (unsigned char cmd);
	void PCF8574_LCDSendData (unsigned char data);
	bool PCF8574_LCD_I2C_ON(void);
	
}; // end of HD44780LCD class

#endif // guard header ending
