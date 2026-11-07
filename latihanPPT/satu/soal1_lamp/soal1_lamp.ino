/*

soal 1
Buatlah buzzer lalu lintas dengan aturan berikut:

a. Terdiri dari 3 warna lampu yang berbeda
b. Lampu pertama akan menyala selama 5 detik
c. Lampu kedua akan menyala selama 2 detik
d. Lampu ketiga akan menyala selama 3 detik

*/

#define lamp1 12
#define lamp2 13
#define lamp3 14

void setup() {
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);
}

void loop() {

  // lampu1 5detik
  digitalWrite(lamp1, HIGH);
  delay(5000);
  digitalWrite(lamp1, LOW);

  //lampu2 2detik
  digitalWrite(lamp2, HIGH);
  delay(2000);
  digitalWrite(lamp2, LOW);

  //lampu3 3detik
  digitalWrite(lamp3, HIGH);
  delay(3000);
  digitalWrite(lamp3, LOW);
}
