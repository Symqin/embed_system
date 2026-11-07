/*
soal1 pt2
Buatlah wiring dan kode yang mengahasilkan kriteria berikut.

Sensor ultrasonic akan mendeteksi jarak dari 50cm - 15 cm dengan masing-masing sebagai berikut:
15-20 cm lampu 1 menyala
21-30 cm lampu 1 & 2 menyala
31-50 cm lampu 1, 2 & 3 menyala
*/

#define trig 8
#define echo 7
#define lamp1 13
#define lamp2 14 
#define lamp3 15

long dur;
float dis;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);
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
  dis = dur / 58.0;

  Serial.print(dis);
  Serial.println("  cm");

  if (dis <= 20 && dis >= 15) {
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    digitalWrite(lamp3, LOW);
  } else if( dis > 20 && dis <=30 ) {
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, HIGH);
    digitalWrite(lamp3, LOW);
  } else if (dis > 30 && dis <= 50) { 
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, HIGH);
    digitalWrite(lamp3, HIGH);
  } else {
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, LOW);
    digitalWrite(lamp3, LOW);
  }

  delay(500);
}
