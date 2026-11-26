Arduino Temperature Monitor
This project reads the room or surrounding temperature, shows it on a small screen, and sounds an alert with a light and buzzer if the temperature goes outside a set range.
What You Need
Arduino board (such as an Arduino Uno)
TMP36 temperature sensor
16x2 LCD screen with an I2C module (address 0x27)
Red LED
Buzzer
Jumper wires (and a breadboard)
How to Wire It Up
Temperature sensor middle/output pin  A0 (plus power and ground to your board)
Red LED  Pin 3
Buzzer (+)  Pin 5
LCD screen  Connect to the SDA and SCL pins on your Arduino
Tip: Double-check which way your LED and buzzer are facing when you plug them in so they work as expected.
Getting Started
Open the Arduino IDE on your computer.
Install the LiquidCrystal_I2C library from the Library Manager.
Wire up your parts using the list above.
Open the code file, pick your Arduino board and port, and click Upload.
What It Does
Startup: Turns on the screen and shows "Temp Monitor" for a moment while getting ready.
Live Reading: Checks the temperature sensor and shows the current temperature in Fahrenheit (°F) on the top line of the screen.
Normal Temperature (80°F to 85°F): Shows "Status: NORMAL" on the bottom line and keeps the light and buzzer off.
Too Cold or Too Hot (below 80°F or above 85°F): Shows "ALERT! OUT RANGE" on the bottom line and beeps/flashes the buzzer and red LED so you know something changed.
Note: A comment in the code mentions 70–75°F, while the active code currently watches for temperatures outside 80°F to 85°F. You can change those numbers in the code anytime if you want a different range
