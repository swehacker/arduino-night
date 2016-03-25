const int pwmPin = 1;
int uSeconds = 1000;

void setup() {
  pinMode(pwmPin,OUTPUT);
}

void loop() {
  for (; uSeconds <= 1950; uSeconds+=20) {
    sweep();
  }

  for (; uSeconds >= 1050; uSeconds-= 20) {
    sweep();
  }
}

void sweep() {
  digitalWrite(pwmPin, HIGH);
  delayMicroseconds(uSeconds);
  digitalWrite(pwmPin, LOW);
  delayMicroseconds(17383-uSeconds);
}

