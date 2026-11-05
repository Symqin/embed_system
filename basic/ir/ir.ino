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
