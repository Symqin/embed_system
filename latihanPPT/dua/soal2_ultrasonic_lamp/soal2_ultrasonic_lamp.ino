/*
soal2
Buatlah wiring dan kode yang mengahasilkan kriteria berikut.

Sebuah sensor ultrasonic akan bekerja. Ketika mendeteksi objek yang berjarak kurang dari 20 cm,
maka lampu berwarna merah akan menyala. 
Ketika objek terdeteksi di jarak 1 meter dan/ lebih, maka lampu hijau akan menyala.
*/

#define hijau 13
#define merah 14

#define trig 15
#define echo 16

long dur;
float dis;

void setup() {
  pinMode(hijau, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH, 30000);
  dis = dur /58;

  Serial.print(dis);
  Serial.println("  cm");

  if (dis >= 100) {
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, LOW);
  } else if (dis < 20 ){
    digitalWrite(merah, HIGH);
    digitalWrite(hijau, LOW);
  } else {
    digitalWrite(merah, LOW);
    digitalWrite(hijau, LOW);
  }

  delay(100);
}
