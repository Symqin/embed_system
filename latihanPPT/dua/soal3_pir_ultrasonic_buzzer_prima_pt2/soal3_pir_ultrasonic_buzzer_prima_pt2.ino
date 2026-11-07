/*
soal3

Buatlah rangkaian menggunakan button dan sensor pir serta ultrasonik. 
Ketika ganjil pir menyala dan bisa digunakan untuk mendeteksi gerakan dan lampu 1 menyala, 
ketika genap ultrasonik dapat digunakan untuk mengukur jarak dengan kriteria pada soal 1.
Ketika bilangan adalah prima  kedua sensor tidak dapat digunakan dan buzzer berbunyi
*/

#define button 19
#define buzzer 18
#define pir 13
#define trig 14
#define echo 17
#define lamp 15

long dur;
float dis;

int angka = 0;

bool prime(int n) {
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void setup() {
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(lamp, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  int baca = digitalRead(button);

  if (baca == LOW) {
    angka++;

    Serial.println(angka);
  }

  if (prime(angka)) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(lamp, LOW);

      Serial.println("bilangan prima");
    
    }

    else if (angka % 2 != 0) {

      int gerakan = digitalRead(pir);
      digitalWrite(buzzer, LOW);

       if (gerakan == HIGH) {
        digitalWrite(lamp, HIGH);
        Serial.println("Gerakan Terdeteksi!");
      } else {
        digitalWrite(lamp, LOW);
        Serial.println("Tidak Ada Gerakan");
      }
    }

    else if (angka % 2 == 0) {
      digitalWrite(buzzer, LOW);
      digitalWrite(lamp, LOW);

      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);

      dur = pulseIn(echo, HIGH, 30000);
      dis = dur /58;

      Serial.print(dis);
      Serial.println(" cm");
    }


  delay(500); // bisa ganti pakai 
  /*
  while (digitalRead(button) == LOW) {
    // menunggu di lepas
  }S
  */

}
