GPIO used in testing for I2C
--------------------------------------

UNO/NANO I2C

1. A4 SDA
2. A5 SCLK

ESP8266 HARDWARE I2C

3. D1 GPIO5 20 SCK
4. D2 GPIO4 19 SDA

ESP32 HARDWARE I2C

5. D22 GPIO22 SCK
6. D21 GPIO21 SDA

STM32 STM32F103C8T6  "blue pill" I2C

|  Pin Name | Pin | Arduino Pin | PCB Label   | Func | I2C Channel |
|  -- | -- | -- | --   |  --  | -- |
| PB6 | 42 | 22 | B6 | SCK | I2C1 |
| PB7 | 43 | 23 | B7 | SDA | I2C1 |
| PB10 | 21 | 26 | B10 | SCK | I2C2 |
| PB11 | 22 | 27 | B11 | SDA | I2C2 |


