// Sistem Deteksi Gerakan dan Jarak Berdasarkan Bilangan Prima dan Ganjil-Genap ESP32.
const int pir = 2;
const int button = 7;

const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int buzzer = 6;

const int trig = 12;
const int echo = 13;

int bilangan = 0;
int bacaanTerakhir = HIGH;

unsigned long waktuDebounce = 0;
const unsigned long debounceDelay = 50;

unsigned long durasi;
float jarak;

bool prima(int n) {
  if (n < 2) return false;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

void semuaMati() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT_PULLUP);
  pinMode(pir, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);

  semuaMati();
  digitalWrite(buzzer, LOW);
}

void loop() {
  // Button menambah bilangan satu kali setiap tekanan
  int bacaan = digitalRead(button);

  if (bacaanTerakhir == HIGH && bacaan == LOW &&
      millis() - waktuDebounce > debounceDelay) {
    bilangan++;
    waktuDebounce = millis();

    Serial.print("Bilangan: ");
    Serial.println(bilangan);
  }

  bacaanTerakhir = bacaan;

  // Mode prima: kedua sensor tidak digunakan
  if (prima(bilangan)) {
    semuaMati();
    digitalWrite(buzzer, HIGH);
    digitalWrite(trig, LOW);

    Serial.println("Bilangan prima: buzzer aktif");
    delay(100);
    return;
  }

  digitalWrite(buzzer, LOW);

  // Bilangan ganjil: mode PIR
  if (bilangan % 2 != 0) {
    digitalWrite(trig, LOW);
    semuaMati();

    if (digitalRead(pir) == HIGH) {
      digitalWrite(led1, HIGH);
      Serial.println("Gerakan terdeteksi");
    } else {
      Serial.println("Tidak ada gerakan");
    }
  }

  // Bilangan genap: mode ultrasonik
  else {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    durasi = pulseIn(echo, HIGH, 30000);
    semuaMati();

    if (durasi > 0) {
      jarak = durasi / 58.0;

      Serial.print("Jarak: ");
      Serial.print(jarak);
      Serial.println(" cm");

      // Kriteria jarak dari soal 1
      if (jarak >= 15 && jarak <= 20) {
        digitalWrite(led1, HIGH);
      } else if (jarak > 20 && jarak <= 30) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
      } else if (jarak > 30 && jarak <= 50) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
      }
    } else {
      Serial.println("Jarak tidak terbaca");
    }
  }

  delay(100);
}
