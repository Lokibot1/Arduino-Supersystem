String data;

int smoke1 = A8;
int flame1 = 4;
#define led1 3
int buzzer1 = 2;

int smoke2 = A1;
int flame2 = 10;
#define led2 9
int buzzer2 = 8;
int datasense1 = 0 , datasense2 = 0;


void setup() {
  Serial.begin(9600);

  pinMode(smoke1, INPUT);
  pinMode(smoke2, INPUT);
  pinMode(flame1, INPUT);
  pinMode(flame2, INPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
    datasense1 = analogRead(smoke1);
    datasense2 = analogRead(smoke2);

    if (datasense1 > 230) {
        data += ", Q1 Detected Smoke Or Gas.";
        digitalWrite(led1, HIGH);
        digitalWrite(buzzer1, HIGH);
    } else if (datasense2 > 230) {
        data += ", Q2 Detected Smoke Or Gas.";
        digitalWrite(led2, HIGH);
        tone(buzzer2, 500, 500);
    } else if (digitalRead(flame1) == LOW) {
        data += ", Q1 Detected Flame.";
        digitalWrite(led1, HIGH);
        digitalWrite(buzzer1, HIGH);
    } else if (digitalRead(flame2) == LOW) {
        data += ", Q2 Detected Flame.";
        digitalWrite(led2, HIGH);
        tone(buzzer2, 500, 500);
    } else {
        digitalWrite(led1, LOW);
        digitalWrite(buzzer1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(buzzer2, LOW);
    }

    Serial.println(data);
    delay(100);
}
