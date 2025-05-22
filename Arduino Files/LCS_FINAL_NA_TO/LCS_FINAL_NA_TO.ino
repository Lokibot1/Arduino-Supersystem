#define LED1 6
#define LED2 7
#define BUTTON1 8
#define BUTTON2 9
#define BUTTON3 10
#define BUTTON4 11
bool ledGroup1On = false;
bool ledGroup2On = false;
String data;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
}

void toggleGroup1() {
  digitalWrite(LED1, ledGroup1On ? LOW : HIGH);
  ledGroup1On = !ledGroup1On;
}

void toggleGroup2() {
  digitalWrite(LED2, ledGroup2On ? LOW : HIGH);
  ledGroup2On = !ledGroup2On;
}

void turnOffAllLeds() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  ledGroup1On = false;
  ledGroup2On = false;
}



void loop() {
  if (Serial.available()) {
    data = Serial.readString();
    if (data == "MAIN_ON") {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
    } else if (data == "MAIN_OFF") {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
    } else if (data == "F1_ON") {
      digitalWrite(LED1, HIGH);
    } else if (data == "F1_OFF") {
      digitalWrite(LED1, LOW);
    } else if (data == "F2_ON") {
      digitalWrite(LED2, HIGH);
    } else if (data == "F2_OFF") {
      digitalWrite(LED2, LOW);
    }
  }
  if (digitalRead(BUTTON1) == LOW) {
    delay(10);
    toggleGroup1();
    while (digitalRead(BUTTON1) == LOW) {}
  }
  if (digitalRead(BUTTON2) == LOW) {
    delay(10);
    toggleGroup2();
    while (digitalRead(BUTTON2) == LOW) {}
  }
  if (digitalRead(BUTTON3) == LOW) {
    delay(10);
    if (!(ledGroup1On && ledGroup2On)) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      ledGroup1On = true;
      ledGroup2On = true;
    }
    while (digitalRead(BUTTON3) == LOW) {}
  }
  if (digitalRead(BUTTON4) == LOW) {
    delay(10);
    turnOffAllLeds();
    while (digitalRead(BUTTON4) == LOW) {}
  }
  
}
