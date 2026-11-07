/*

soal3
Buatlah rangkaian dengan aturan sebagai berikut:

a. Terdapat 2 LED
b. Lampu 1 hanya berkedip selama 10 Kali setiap 1 detik dan lampu akan mati
c. Tampilkan ke serial monitor bahwa Lampu 1 telah berkedip berapa kali
d. Setelah lampu 1 menyala sebanyak 10 kali, maka Lampu 1 mati dan Lampu 2 akan menyala terus-menerus

*/

#define lamp1 12
#define lamp2 13

void setup() {
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  for (int i = 1; i<=10; i++) {
    digitalWrite(lamp1, HIGH);
    Serial.println(i);
    delay(500);
    digitalWrite(lamp1, LOW);
    delay(500);
  }

  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, HIGH);

  while(true) {
    // dipakai untuk memberhentikan perulangan jadi (menahan program agar tidak mengulang) 
  }
}
