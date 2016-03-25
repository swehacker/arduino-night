const int pwmPin = 1;
int uSeconds = 1000;

void setup() {
  pinMode(pwmPin,OUTPUT);
}

void loop() {
  // Loop between 1050-1950 so that we dont accidentaly go too far.
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
  // Currently the largest most accurate delay is 16383us (which is close enough)
  delayMicroseconds(17383-uSeconds);
}

