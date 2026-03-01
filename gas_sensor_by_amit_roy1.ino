#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

int valor_limits = 650;       // Gas risk threshold
const int buzzer = 6;

// MCP23008 I2C LCD at address 0x20 -> use "0" here
Adafruit_LiquidCrystal lcd(0);

void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);       // Green LED
  pinMode(7, OUTPUT);       // Red LED
  pinMode(buzzer, OUTPUT);  // Buzzer

  // Initialize I2C LCD
  lcd.begin(16, 2);         // 16 columns, 2 rows
  lcd.setBacklight(1);      // Turn on backlight

  lcd.setCursor(0, 0);
  lcd.print(" Gas Monitor ");
  lcd.setCursor(0, 1);
  lcd.print(" Initializing ");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(A0);   // Read MQ-4 sensor value

  Serial.println(sensorValue);

  // First line: show gas value
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(sensorValue);
  lcd.print("    "); // clear leftover digits if number shrinks

  if (sensorValue > valor_limits) {
    // DANGER zone
    digitalWrite(8, LOW);    // Green OFF
    digitalWrite(7, HIGH);   // Red ON
    tone(buzzer, 1200);

    lcd.setCursor(0, 1);
    lcd.print("STATUS: DANGER ");
  } else {
    // SAFE zone
    digitalWrite(8, HIGH);   // Green ON
    digitalWrite(7, LOW);    // Red OFF
    noTone(buzzer);

    lcd.setCursor(0, 1);
    lcd.print("STATUS: SAFE   ");
  }

  delay(500);
}
