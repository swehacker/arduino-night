#include <Wire.h>
#include <SparkFunTSL2561.h>

SFE_TSL2561 light;
boolean gain;     // Gain setting, 0 = X1, 1 = X16;
unsigned int ms;  // Integration ("shutter") time in milliseconds

/*
 Lux sensor
 4-in-1 Sensor Strinity Cobber v0.1
 VCC to arduino 5V
 GND to arduino GNG
 SDA to arduino SDA
 SCL to arduino SCL
*/
void setup() {

    Serial.begin(9600);
    light.begin();

    gain = 0;
    unsigned char time = 2;

    Serial.println("Set timing...");
    light.setTiming(gain,time,ms);

  // To start taking measurements, power up the sensor:
  
  Serial.println("Powerup...");
  light.setPowerUp();

}

void loop() {
  
   delay(ms);
   unsigned int data0, data1;
  
  if (light.getData(data0,data1))
  {
    double lux;    // Resulting lux value
    boolean good;  // True if neither sensor is saturated

    good = light.getLux(gain,ms,data0,data1,lux);
  
    Serial.print(" lux: ");
    Serial.print(lux);
    if (good) Serial.println(" (good)"); else Serial.println(" (BAD)");
  }
}
