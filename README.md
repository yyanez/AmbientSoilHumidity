# AmbientSoilHumidity
Simple application to read the Ambient Humidity and Temperature from a DHT11 sensor and the Soil Humidity from a VMA303 Soil Humidity sensor. It sends all the information through the serial port



Needs the Adafruit_Sensor library and the DHT library

Sends a set of characters through the serial port like these:

__21.80°C, 49%, 0 SH__

Where SH means Soil Humidity. This value is the raw value of the voltage sent by the VMA303 sensor and acquired by the Arduino microcontroller.





