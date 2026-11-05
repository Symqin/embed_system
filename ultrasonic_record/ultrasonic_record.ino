#define trig 14
#define echo 27
#define button 19
#define led 13

float dis;
float dur;
float record;


void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop () {
  int tombol = digitalRead(button);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH, 30000);
  dis = dur/58;

  Serial.print("Distance: ");
  Serial.print(dis);
  Serial.println(" cm");



  if (tombol == LOW) {
    record = dis;

    Serial.print("Record Distance: ");
    Serial.print(record);
    Serial.println(" cm");

    if (record < 45) {
      digitalWrite(led, HIGH);
    }
    else if (record > 44) {
      digitalWrite(led, LOW);
    }
  }

  delay(300);
  

}