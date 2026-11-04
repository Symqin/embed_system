#define lamp 12;

void setup() {
  pinMode(lamp, OUTPUT);
  serial.begin(115200)
}

void loop() {
  digitalWrite(lamp, HIGH);
  delay(1000);
  digitalWrite(lamp, LOW);
  delay(1000);
}

