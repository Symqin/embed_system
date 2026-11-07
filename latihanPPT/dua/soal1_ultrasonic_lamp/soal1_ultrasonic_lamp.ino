/*
soal1
Buatlah wiring dan kode yang mengahasilkan kriteria berikut.

Sebuah sensor ultrasonic akan bekerja. 
Ketika mendeteksi benda yang berjarak kurang dari 50 cm, 
maka lampu berwarna merah akan menyala.
*/

#define trig 13
#define echo 14

#define lamp 16
long dur;
float dis;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(lamp, OUTPUT);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  dur = pulseIn(echo, HIGH, 30000);
  dis = dur / 58;

  if (dis < 50) {
    digitalWrite(lamp, HIGH);
  } else {
    digitalWrite(lamp, LOW);
  }
}
