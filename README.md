[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/paypalme/whitelight976)


![ lcd ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCDPCF.jpg)

Table of contents
---------------------------

  * [Overview](#overview)
  * [Installation](#installation)
  * [Output](#output)
  * [Tested](#tested)
  * [Ports](#ports)
  
Overview
--------------------
* Name : HD44780_LCD_PCF8574
* Description :

0. Library to support the HD44780 LCD , (I2C PCF8574 "backpack" interface) 
   for the Arduino Eco system
1. C++ library.
2. Backlight, scroll, cursor and entry-mode control.
3. Custom character support + print class for numerical data.
4. Hardware I2C 
5. Tested on size 16x02 + 20x04 (but may work on other sizes  eg 16X4 but not tested).
6. Can support both I2C ports on the STM32 see tested section.

* Author: Gavin Lyons

Installation
------------------------------

The library is included in the official Arduino library manger and the optimum way to install it is using the library manager which can be opened by the manage libraries option in Arduino IDE.

See link below for instruction for this and for the other methods too.

[Installing Additional Arduino Libraries guide](https://www.arduino.cc/en/Guide/Libraries)

Output
---------------------

Output  of custom character test in testrun example  file on 16x02 display.

![ pic ](https://github.com/gavinlyonsrepo/HD44780_LCD_RPI/blob/main/extras/image/custom_output.jpg)

20x04 display. 

![ pic2 ](https://github.com/gavinlyonsrepo/HD44780_LCD_PCF8574/blob/main/extras/image/2004.jpg)

Tested
------------------------

Tested on following MCUs.
The example files are setup for an UNO/NANO for the pin connections used 
by for other MCU testing see extras/doc folder GPIO_MCU_used.MD file.

1. Arduino  UNO & NANO v3
2. ESP8266 
3. ESP32 
4. STM32 "blue pill", Can support both I2C ports , In example files comment in #define STM32_BLUE_PILL_SETUP
and pick which port you want. Added in Version 1.2.0.

Ports
------------------------

Raspberry Pi C++ : [URL link](https://github.com/gavinlyonsrepo/HD44780_LCD_RPI)

PIC XC32 :  [URL link](https://github.com/gavinlyonsrepo/pic_32_projects)
