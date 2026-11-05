// ============================================================
// SUGGESTION:
// GPIO12 (MTDI) adalah strapping pin ESP32. Dilarang keras / hindari
// memakainya sebagai OUTPUT yang bisa HIGH saat boot (bisa gagal boot).
// -> Ganti ke pin output bebas, misal GPIO18 / 19 / 23.
//    Contoh: #define lamp 18
// ============================================================
#define lamp 12

void setup() {
  pinMode(lamp, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(lamp, HIGH);
  delay(1000);
  digitalWrite(lamp, LOW);
  delay(1000);
}

