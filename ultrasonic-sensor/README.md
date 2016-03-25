# Use Ultrasonic Sensor with Arduino
The ultrasonic sensor emits an ultrasound at 40KHz and if it bounces off something that is in its path the signal will travel back to the module. Since we can measure the travel time and we know the speed of sound (in air) we can calculate the distance.

## HC-SR04
The HC-SR04 Ultrasonic Module has 4 pins, Ground, VCC, Trig and Echo. The Ground and the VCC pins of the module needs to be connected to the Ground and the 5 volts pins on the Arduino Board respectively and the trig and echo pins to any Digital I/O pin on the Arduino Board.

To generate the ultrasound we need to set the Trig on a High for 10 µs. That will send out an 8 cycle sonic burst which will travel at the speed sound and it will be received in the Echo pin. The Echo pin will output the time in microseconds the sound wave traveled.

## Example
The speed of sound is 340 m/s or 0.034 cm/microseconds, it the object is 10 cm away from the sensor the sound have to travel about 294us. Because it will travel to the object and back again the output will be double that (588us). So we need to divide the output from the echo pin by 2.

Calculate the distance
```
t = Time
d = Distance in cm
v = Speed (velocity) of air in cm/us

d = t * v / 2

10cm = 588us * 0,034 / 2
```

## Breadboard Setup
![Breadboard setup](HC-SR04_bb.png)

## Measuring
Here we can see the 10us trigger pulse in yellow and the response back from the echo pin in blue.

![8 cm from object](8cm.png)

The echo pin pulse is almost 500us (every division is 100us long, 5 division = 500us).

```
d = t * v / 2
8,5 cm = 500us * 0,034 / 2
```

The object was 8,5 cm from the sensor.