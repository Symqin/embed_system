#include <ESP32Servo.h>

#define servoPIN 15

Servo myServo;

void setup() {
 myServo.attach(servoPIN);
}

void loop() {
  myServo.write(0);
  delay(1000);

  myServo.write(90);
  delay(1000);

  myServo.write(180);
  delay(1000);
}
