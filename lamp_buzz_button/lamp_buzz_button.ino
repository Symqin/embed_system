
#define lamp1 12
#define lamp2 13
#define lamp3 14

#define button 19
#define buzz 15

void setup() {
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);

  pinMode(button, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);

  Serial.begin(9600);

  // Kondisi awal
  digitalWrite(lamp1, HIGH);
  digitalWrite(lamp2, LOW);
  digitalWrite(lamp3, LOW);
  digitalWrite(buzz, LOW);
}

void loop() {
  int baca = digitalRead(button);

  if (baca == LOW) {

      // Tahap 1: Lampu 1 berkedip 5 kali
      for (int i = 1; i <= 5; i++) {
        digitalWrite(lamp1, HIGH);

        Serial.print("Kedipan lampu 1: ");
        Serial.println(i);

        delay(1000);

        digitalWrite(lamp1, LOW);
        delay(1000);
      }

      // Tahap 2: Lampu 2 menyala
      digitalWrite(lamp2, HIGH);

      // Buzzer berbunyi 3 kali
      for (int i = 1; i <= 3; i++) {
        digitalWrite(buzz, HIGH);
        delay(1000);

        digitalWrite(buzz, LOW);
        delay(1000);
      }

      digitalWrite(lamp2, LOW);

      // Tahap 3: Lampu 3 berkedip 10 kali
      for (int i = 1; i <= 10; i++) {
        digitalWrite(lamp3, HIGH);
        delay(500);

        digitalWrite(lamp3, LOW);
        delay(500);
      }

      // Tahap 4: Kembali ke kondisi awal
      digitalWrite(lamp1, HIGH);
      digitalWrite(lamp2, LOW);
      digitalWrite(lamp3, LOW);
      digitalWrite(buzz, LOW);

      // Tunggu tombol dilepas
      while (digitalRead(button) == LOW) {
        delay(10);
      }
  }
}
