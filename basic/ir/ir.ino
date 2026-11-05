// ============================================================
// SUGGESTION:
// Logika di bawah mengasumsikan modul IR obstacle AKTIF-LOW
// (ada objek = output LOW), contoh modul HW-201/FC-51.
// -> Jika modulmu AKTIF-HIGH, balik kondisinya (statusIR == HIGH).
// ============================================================
#define ir 4

void setup() {
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  int statusIR = digitalRead(ir);


  if (statusIR == LOW) {
    Serial.println("ada objek");
  } else {
    Serial.println("tidak ada objek");
  }
  
  delay(200);  
}
