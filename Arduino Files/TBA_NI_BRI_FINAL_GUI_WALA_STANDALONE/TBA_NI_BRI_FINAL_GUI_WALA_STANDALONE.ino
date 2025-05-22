#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buzzerPin = 9;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming string
    String incomingString = Serial.readString();
    Serial.print("Received string: ");
    Serial.println(incomingString);
  
    if (incomingString.indexOf("ALARM") >= 0) {
      // Display "Alarm is activated" on the LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Alarm is: ");
      lcd.setCursor(0, 1);
      lcd.print("Activated");

      Serial.println("Alarm is activated");
      
      // Activate the buzzer
      digitalWrite(9, HIGH);
      delay(5000); // Buzzer on for 5 seconds
      digitalWrite(9, LOW);
      
      // Clear the LCD after the alarm
      delay(1000);
      lcd.clear();
    }
  }
}
