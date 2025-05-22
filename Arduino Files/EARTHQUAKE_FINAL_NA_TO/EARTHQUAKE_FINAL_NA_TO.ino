int buzzerPin = 7;
#define buttonPin1 2
#define buttonPin2 3
#define ledPin1 8
#define ledPin2 9
bool lState1 = LOW;
bool lState2 = LOW;
bool buzzerState1 = LOW;
NEW SKETCH

bool buzzerState2 = LOW;
String data;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

 
}

void loop() {
  gui();
  handleEarthquakeAlarm();
}
void gui() {
  if (Serial.available()) {
    data = Serial.readString();
    if (data == "DRILL_ON") {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      tone(buzzerPin, 500);
    } else if (data == "DRILL_OFF") {
      digitalWrite(ledPin2, LOW);
      noTone(buzzerPin);
    } else if (data == "DISASTER_ON") {
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin1, HIGH);
      tone(buzzerPin, 200);
    } else if (data == "DISASTER_OFF") {
      digitalWrite(ledPin1, LOW);
      noTone(buzzerPin);
    }
  }
}

void handleEarthquakeAlarm() {
  //EATHQUAKE ALARM SYSTEM
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == LOW) {
    lState1 = !lState1;
    buzzerState1 = !buzzerState1;
    digitalWrite(ledPin1, lState1);
    digitalWrite(ledPin2, LOW);
    lState2 = LOW;
    buzzerState2 = LOW;
    tone(buzzerPin, buzzerState1 ? 500 : 0);
    delay(200);
  }
  if (buttonState2 == LOW) {
    lState2 = !lState2;
    buzzerState2 = !buzzerState2;
    digitalWrite(ledPin2, lState2);
    digitalWrite(ledPin1, LOW);
    lState1 = LOW;
    buzzerState1 = LOW;
    tone(buzzerPin, buzzerState2 ? 200 : 0);
    delay(200);
  }
}
