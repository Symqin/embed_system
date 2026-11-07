/*
soal2
Buat sebuah variable bernama record. 
Buatlah rangkaian yang terdiri dari button, ultrasonic, led. Ultrasonic akan selalu mengukur jarak. Sementara ketika button ditekan, jarak yang terukur ultrasonic akan direkam ke Variabel record. 
Jika nilai record < 45, maka led akan menyala
Jika nilai record > 44, maka led mati 
*/

#define trig 13
#define echo 14
#define led 27
#define button 15

float record = 0;

long dur;
float dis;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
  int baca = digitalRead(button);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH, 30000);
  dis = dur /58;

  Serial.print(dis);
  Serial.println("  cm");

  if (baca == LOW) {
    record = dis;
  } 

  if (record < 45) {
    digitalWrite(led, HIGH);
  } else if (record > 44) {
    digitalWrite(led, LOW);
  }

  delay(500);

}
