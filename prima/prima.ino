
#define button 19
#define trig 14
#define echo 27
#define led 13
#define pir 35
#define buzz 25

int bilangan = 0;
float jarak;
long durasi;

// Fungsi mengecek bilangan prima
bool prima(int n) {
  if (n < 2) {
    return false;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

// Fungsi mengukur jarak ultrasonic
float ukurJarak() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  durasi = pulseIn(echo, HIGH, 30000);

  if (durasi == 0) {
    return -1;
  }

  return durasi / 58;
}

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(buzz, OUTPUT);

  Serial.begin(9600);

  digitalWrite(led, LOW);
  digitalWrite(buzz, LOW);
}

void loop() {

  // Membaca tombol
  if (digitalRead(button) == LOW) {
    delay(50);

    if (digitalRead(button) == LOW) {
      bilangan++;

      Serial.print("Bilangan: ");
      Serial.println(bilangan);

      // Tunggu tombol dilepas
      while (digitalRead(button) == LOW) {
        delay(10);
      }
    }
  }

  // KONDISI 1: BILANGAN PRIMA
  if (prima(bilangan)) {

    digitalWrite(led, LOW);
    digitalWrite(buzz, HIGH);

    Serial.println("Bilangan prima");
    Serial.println("PIR dan Ultrasonic tidak aktif");

  }

  // KONDISI 2: BILANGAN GANJIL
  else if (bilangan % 2 != 0) {

    digitalWrite(buzz, LOW);

    Serial.println("Bilangan ganjil");
    Serial.println("Mode PIR");

    int gerakan = digitalRead(pir);

    if (gerakan == HIGH) {
      digitalWrite(led, HIGH);
      Serial.println("Gerakan terdeteksi");
    }
    else {
      digitalWrite(led, LOW);
      Serial.println("Tidak ada gerakan");
    }

  }

  // KONDISI 3: BILANGAN GENAP
  else {

    digitalWrite(buzz, LOW);
    digitalWrite(led, LOW);

    Serial.println("Bilangan genap");
    Serial.println("Mode Ultrasonic");

    jarak = ukurJarak();

    Serial.print("Jarak: ");
    Serial.print(jarak);
    Serial.println(" cm");

    // Kriteria contoh: jarak kurang dari 50 cm
    if (jarak >= 0 && jarak < 50) {
      digitalWrite(led, HIGH);
    }
    else {
      digitalWrite(led, LOW);
    }
  }

  delay(500);
}
