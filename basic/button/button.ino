#define button 13
#define lamp 23

void setup() {
  pinMode(button,INPUT_PULLUP);
  pinMode(lamp, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tombol = digitalRead(button);

  if (tombol == LOW) {
    digitalWrite(lamp, HIGH);
    Serial.println("button_ditekan");
  } else {
    digitalWrite(lamp, LOW);
  }

  delay(200);
}
