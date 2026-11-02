
const int pir = 2;
const int ledMerah = 8;
const int ledHijau = 7;
const int buzzer = 6;

int statusPIR;

void setup() {
  Serial.begin(9600);

  pinMode(pir, INPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  statusPIR = digitalRead(pir);

  if (statusPIR == HIGH) {
    // Gerakan terdeteksi
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);
    digitalWrite(buzzer, HIGH);

    Serial.println("Gerakan terdeteksi!");
  } else {
    // Tidak ada gerakan
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, HIGH);
    digitalWrite(buzzer, LOW);

    Serial.println("Tidak ada gerakan");
  }

  delay(200);
}
