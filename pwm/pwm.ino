/*
 * Writes an analog value (PWM wave) to a pin. 
 * Can be used to light a LED at varying brightnesses or drive a 
 * motor at various speeds. After a call to analogWrite(), the pin 
 * will generate a steady square wave of the specified duty cycle 
 * until the next call to analogWrite() (or a call to digitalRead() 
 * or digitalWrite() on the same pin). 
 * 
 * The frequency of the PWM signal on most pins is approximately 490 Hz.
 * On the Uno and similar boards, pins 5 and 6 have a frequency of 
 * approximately 980 Hz. Pins 3 and 11 on the Leonardo also run at 980 Hz.
 */

/* 
 *  On most Arduino boards (those with the ATmega168 or ATmega328), 
 *  this function works on pins 3, 5, 6, 9, 10, and 11. 
 *  On the Arduino Mega, it works on pins 2 - 13 and 44 - 46. 
 *  Older Arduino boards with an ATmega8 only support analogWrite() 
 *  on pins 9, 10, and 11.
 */
const int ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

/*
 * Cycle through 5 values with a 2 seconds delay inbetween, 
 * where 255 is full on and 0 is off.
 */
void loop() {
  analogWrite(ledPin,255);
  delay(2000);
  analogWrite(ledPin,128);
  delay(2000);
  analogWrite(ledPin,64);
  delay(2000);
  analogWrite(ledPin,32);
  delay(2000);
  analogWrite(ledPin,0);
  delay(2000);
}
