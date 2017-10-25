#define LED 13
#define KEY 2
#define Buzzer 3
int KEY_NUM=0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(KEY, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);
}

void loop() {
  ScanKey();
  if (KEY_NUM == 1) {
    digitalWrite(LED, !digitalRead(LED));
  }
}

void ScanKey() {
  KEY_NUM = 0;
  if (digitalRead(KEY) == LOW) {
    delay(20);
    if (digitalRead(KEY) == LOW) {
      BuzzerDi();
      KEY_NUM = 1;
      while(digitalRead(KEY) == LOW);
    }
  }
}

void BuzzerDi() {
  digitalWrite(Buzzer, HIGH);
  delay(100);
  digitalWrite(Buzzer, LOW);
}
