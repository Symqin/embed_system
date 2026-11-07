#include <ESP32Servo.h>
#define servoA 13
#define button 14
#define lamp 12

int sudut = 0;
Servo myServo;

void setup() {
  myServo.attach(servoA);
  pinMode(lamp, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);

  myServo.write(0);
}

void loop() {
  
  int tombol = digitalRead(button);

  if(tombol ==  LOW) {

   

    if (sudut == 0) {
      for (int i = 0; i<=180; i+=5) {
        myServo.write(i);
        Serial.print(i);
        Serial.println("  derajat");
        delay(100);
      }

      sudut = 180;
      digitalWrite(lamp, HIGH);

      

    } else if (sudut == 180) {
      myServo.write(0);
      digitalWrite(lamp, LOW);
      sudut = 0;
    } 

    delay(500);

    // bisa pakai ini untuk pengganti delay(500)
    // Tunggu tombol dilepas
    //  while (digitalRead(button) == LOW) {
    //  delay(10)
    //} 
  }
}


