
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
5. Tested on size 16x02 only but may work on other sizes (20x4 , 16X4 etc).

* Author: Gavin Lyons

Installation
------------------------------

The library is included in the official Arduino library manger and the optimum way to install it is using the library manager which can be opened by the manage libraries option in Arduino IDE.

See link below for instruction for this and for the other methods too.

[Installing Additional Arduino Libraries guide](https://www.arduino.cc/en/Guide/Libraries)

Output
---------------------

Output  of custom character test in test file.

![ pic ](https://github.com/gavinlyonsrepo/HD44780_LCD_RPI/blob/main/extras/image/custom_output.jpg)

Tested
------------------------

Tested on following MCUs.
The example files are setup for an UNO/NANO for the pin connections used 
by for other MCU testing see extras/doc folder GPIO_MCU_used.txt file.

1. Arduino  UNO & NANO v3
2. ESP8266 
3. ESP32 
4. STM32 "blue pill"

Ports
------------------------

Raspberry Pi C++ : [URL link](https://github.com/gavinlyonsrepo/HD44780_LCD_RPI)

PIC XC32 :  [URL link](https://github.com/gavinlyonsrepo/pic_32_projects)
