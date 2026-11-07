/*
soal 4
uatlah rangkaian dengan aturan sebagai berikut:
a. Terdapat 3 LED, 1 push button, dan 1 buzzer.
b. Pada kondisi awal, Lampu 1 menyala sedangkan Lampu 2 dan Lampu 3 dalam keadaan mati.
c. Ketika push button ditekan, Lampu 1 akan berkedip sebanyak 5 kali dengan interval 1 detik.
d. Tampilkan pada Serial Monitor jumlah kedipan Lampu 1 setiap kali lampu menyala.
e. Setelah Lampu 1 selesai berkedip, Lampu 1 akan mati dan Lampu 2 menyala.
f. Bersamaan dengan Lampu 2 menyala, buzzer akan berbunyi sebanyak 3 kali.
g. Setelah buzzer selesai berbunyi, Lampu 2 akan mati dan Lampu 3 akan berkedip sebanyak 10 kali dengan interval 500 ms.
h. Setelah seluruh proses selesai, Lampu 3 akan mati dan sistem kembali ke kondisi awal. 

*/
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
