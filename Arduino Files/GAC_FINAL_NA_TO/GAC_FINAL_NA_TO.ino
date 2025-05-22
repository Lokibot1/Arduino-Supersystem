#include <Servo.h>

const int pirPin = 2;      // PIR sensor pin
const int buttonPin = 3;   // Push button pin
const int servoPin = 9;    // Servo motor pin

String data;
Servo sl;

bool isslActive = false;  // Flag to track servo activation
bool isButtonPressed = false; // Flag to track button state
bool pirState = false;      // Variable to store PIR sensor state
bool lastPirState = false;  // Variable to store previous PIR sensor state
bool buttonState = false;   // Variable to store button state
bool lastButtonState = false; // Variable to store previous button state


void setup() {
  Serial.begin(9600);
  sl.attach(9);

  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(servoPin, OUTPUT);
  sl.attach(servoPin);
}




void loop() { // Read PIR sensor
  pirState = digitalRead(pirPin);

  // Read push button
  buttonState = digitalRead(buttonPin);

  // Check if button is pressed
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      isButtonPressed = true;
    }
  }
  lastButtonState = buttonState;

  // If the button is pressed, toggle servo activation
  if (isButtonPressed) {
    isslActive = !isslActive;
    isButtonPressed = false;
  }

  // If PIR sensor detects motion or the button is pressed, activate servo
  if (pirState == HIGH || isslActive) {
    sl.write(360); // Servo position when activated
  } else {
    sl.write(0); // Servo position when deactivated
  }
  delay(100); // Delay to avoid reading the button or PIR sensor too quickly

  if(Serial.available()){
    data = Serial.readString();
    if(data == "SERVO_OPEN"){
      sl.write(360);
      
      delay(3000);
      }
     else if(data == "SERVO_CLOSE"){
      sl.write(0);
       delay(3000);
      }
      
    }
  }
