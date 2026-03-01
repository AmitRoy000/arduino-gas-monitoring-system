# arduino-gas-monitoring-system
Arduino-based gas leak detection system using an MQ-4 sensor and 16x2 I2C LCD. Continuously monitors gas levels and displays real-time readings. Activates a red LED and buzzer when the threshold is exceeded, and a green LED when safe. Simple, low-cost safety prototype suitable for home and industrial monitoring applications.

Arduino Gas Monitoring System

An Arduino-based gas leak detection system using an MQ-4 gas sensor and a 16x2 I2C LCD display. The system continuously monitors gas concentration levels and provides real-time visual and audible alerts when the gas value exceeds a predefined safety threshold.

Overview:

This project is designed as a simple, low-cost safety prototype for detecting gas leaks. It uses an analog gas sensor connected to an Arduino Uno to measure gas levels and trigger alerts when unsafe conditions are detected.

Features:

Real-time gas level monitoring
Live value display on 16x2 I2C LCD
Green LED indication for safe condition
Red LED indication for danger condition
Buzzer alarm when threshold is exceeded
Adjustable sensitivity threshold in code
Serial Monitor output for debugging

Components Used:

Arduino Uno R3
MQ-4 Gas Sensor
16x2 LCD (I2C, MCP23008 – Address 0x20)
Green LED
Red LED
Buzzer
Resistors
Breadboard and jumper wires
Working Principle
The MQ-4 gas sensor reads gas concentration and sends an analog signal to the Arduino (A0).
The Arduino compares the sensor reading with a predefined threshold value.
If the reading exceeds the threshold:
Red LED turns ON
Buzzer activates
LCD displays "STATUS: DANGER"
If the reading is below the threshold:
Green LED turns ON
Buzzer turns OFF
LCD displays "STATUS: SAFE"
Pin Configuration
A0 → MQ-4 analog output
D7 → Red LED
D8 → Green LED
D6 → Buzzer
SDA/SCL → I2C LCD

Configuration:

You can adjust the gas detection sensitivity by modifying this line in the code:
int valor_limits = 650;

Increase the value for lower sensitivity.
Decrease the value for higher sensitivity.

Applications:

Home gas leak detection
Kitchen safety systems
Industrial monitoring prototypes
Embedded systems learning project

Future Improvements:

WiFi-based alerts using ESP8266 or ESP32
SMS alerts using GSM module
Cloud data logging
Mobile app integration

Author

Amit Roy
