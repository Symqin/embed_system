/*
soal3
Buatlah wiring dan kode yang mengahasilkan kriteria berikut.

Sebuah sensor PIR akan bekerja. Ketika mendeteksi objek, 
maka lampu berwarna merah akan menyala dan diiringi buzzer yang berbunyi. 
Ketika objek tidak terdeteksi, maka lampu berwarna hijau akan menyala.
*/

#define pir 8
#define hijau 15
#define merah 18
#define buzz 19
int status;

void setup() {
  pinMode(pir, INPUT);
  pinMode(hijau, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  status = digitalRead(pir);

  if (status == HIGH) {
    digitalWrite(buzz, HIGH);
    digitalWrite(merah, HIGH);
    digitalWrite(hijau, LOW);
    Serial.println("ada objek");
  } else {
    digitalWrite(buzz,LOW);
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, LOW);
    Serial.println("tidak ada objek");
  }
  delay(500);
}
