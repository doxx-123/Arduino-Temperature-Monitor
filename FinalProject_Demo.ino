#include <LiquidCrystal_I2C.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int redLED = 3; // Red LED cathode on pin 3 → LOW = ON
const int buzzer = 5; // Buzzer (+) on pin 5
const int tempPin = A0; // TMP36 output

float temperatureF = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tempPin, INPUT);

  // Start with everything OFF
  digitalWrite(redLED, LOW); // OFF (reverse wired)
  digitalWrite(buzzer, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  delay(1500);
}

void loop() {

  // --- Read TMP36 sensor ---
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;
  temperatureF = temperatureC * 9.0 / 5.0 + 32.0;

  // --- LCD Display ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureF, 1);
  lcd.print(" F");

  // --- NEW Temperature Range: 70–75°F ---
  if (temperatureF < 80 || temperatureF > 85) {

    // OUT OF RANGE → ALERT
    lcd.setCursor(0, 1);
    lcd.print("ALERT! OUT RANGE");

    digitalWrite(redLED, HIGH); // Red LED ON (reverse wired)
    tone(buzzer, 100); // Buzzer ON (1 kHz tone)
    delay(1000);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
    delay(300);
    

  } else {

    // IN RANGE → Normal
    digitalWrite(redLED, LOW); 
    noTone(buzzer);
    delay(300);
    lcd.setCursor(0, 1);
    lcd.print("Status: NORMAL");

    digitalWrite(redLED, LOW); // Red LED OFF
    noTone(buzzer); // Buzzer OFF
  }

  delay(300);
}
