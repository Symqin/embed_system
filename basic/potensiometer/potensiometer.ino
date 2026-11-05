// ============================================================
// PERHATIAN / SUGGESTION (KRUSIAL):
// GPIO4 termasuk ADC2. Jika WiFi aktif (SSID/HTTP/MQTT) di sketch,
// semua pin ADC2 TIDAK BISA analogRead -> hasilnya selalu 0.
// -> Pindahkan potensiometer ke pin ADC1: 32, 33, 34, 35, atau 39.
//    Contoh: #define pot 34
// ============================================================
#define pot 4

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potv = analogRead(pot);

  Serial.println(potv);
  delay(500);
}
