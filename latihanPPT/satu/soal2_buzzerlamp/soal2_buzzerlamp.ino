/*
soal 2
Buatlah rangkaian dengan aturan sebagai berikut:

a. Terdapat 2 Buzzer dan 2 LED
b. Lampu 1 dan Lampu 2 menyala bergantian setiap 3,5 detik
c. Setiap Lampu 1 menyala, maka Buzzer 1 akan berbunyi 
d. Setiap Lampu 2 menyala, maka Buzzer 2 akan berbunyi
*/

#define buzz1 12
#define buzz2 13

#define lamp1 15
#define lamp2 16 

void setup() {
  pinMode(buzz1, OUTPUT);
  pinMode(buzz2, OUTPUT);

  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);

}

void loop() {

  digitalWrite(lamp1, HIGH);
  digitalWrite(buzz1,HIGH);
  delay(3500);
  digitalWrite(lamp1, LOW);
  digitalWrite(buzz1,LOW);

  digitalWrite(lamp2, HIGH);
  digitalWrite(buzz2,HIGH);
  delay(3500);
  digitalWrite(lamp2, LOW);
  digitalWrite(buzz2,LOW);
}
