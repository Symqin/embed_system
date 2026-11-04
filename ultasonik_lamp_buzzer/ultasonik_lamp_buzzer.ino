#define trig 26
#define echo 19
#define lamp1 12
#define lamp2 13
#define lamp3 27
#define buzz 4

float dur = 0;
float dis = 0;

void setup() {
  pinMode(lamp1,OUTPUT);
  pinMode(lamp2,OUTPUT);
  pinMode(lamp3,OUTPUT);
  
  pinMode(buzz, OUTPUT);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(115200);
}

void loop() {

  // kirim gelombang ultasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(20);
  digitalWrite(trig, HIGH);

  //terima durasi dan jarak
  dur = pulseIn(echo, HIGH);
  dis = dur/58;

  Serial.print("Distance: ");
  Serial.print(dis);
  Serial.println(" Cm");

  if (dis >= 80) {
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    digitalWrite(lamp3, LOW);
    digitalWrite(buzz, LOW);

  } else if (dis >=20 ){
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    digitalWrite(lamp3, LOW);
    digitalWrite(buzz, LOW);
  } else {
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, LOW);
    digitalWrite(lamp3, HIGH);
    digitalWrite(buzz, HIGH);
  }
  delay(500);
}
