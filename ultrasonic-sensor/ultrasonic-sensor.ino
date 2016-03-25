/*
 * HC-SR04 Ping distance sensor
 * VCC to arduino 5v 
 * GND to arduino GND
 * Echo to Arduino pin 11 
 * Trig to Arduino pin 12
 */

#define trigPin 11
#define echoPin 12
#define maximumDistance 200
#define minimumDistance 0

float duration, distance;

void setup() {
  // Set serial port to use 9600 bauds
  Serial.begin (9600);
  // Set the digital pin for trigger as output
  pinMode(trigPin, OUTPUT);
  // Set the digital pin for echo to input
  pinMode(echoPin, INPUT);
}

void loop() {
  // To setup the HC-SR04 for use, set the trigger pin low for 2us 
  // and then high for 10us and wait for a pulse.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  // Waiting for trigger pin to go high and returns the length 
  // of the puls in us
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm based on the speed of sound.
  distance = duration * 0.034 / 2;

  if (distance >= maximumDistance || distance <= minimumDistance) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Wait 100ms to next reading
  delay(100);
}
