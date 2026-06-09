# Adaptive Intelligent Transportation System - Sample ESP32 Logic

#include <ESP32Servo.h>

Servo divider;

int irSensor = 32;
int servoPin = 4;

void setup() {

pinMode(irSensor, INPUT);

divider.attach(servoPin);
divider.write(0);

Serial.begin(9600);
}

void loop() {

int vehicleDetected = digitalRead(irSensor);

if(vehicleDetected == LOW) {

```
Serial.println("Emergency vehicle detected");

divider.write(90);

delay(3000);

divider.write(0);
```

}
}
