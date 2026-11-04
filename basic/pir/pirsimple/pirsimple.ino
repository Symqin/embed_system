#define PIR_PIN 4
void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(115200);
}
void loop() {
  int gerakan = digitalRead(PIR_PIN);
  
  if (gerakan == HIGH) {
    Serial.println("Gerakan terdeteksi");
  } else {
    Serial.println("Tidak ada gerakan");
  }
  
  delay(300);
}