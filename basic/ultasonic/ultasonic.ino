// ============================================================
// SUGGESTION:
// echo memakai GPIO12 (MTDI) — strapping pin. Aman selama echo LOW
// saat boot, tapi lebih baik pindah ke pin bebas, misal GPIO16.
// -> Contoh: #define echo 16
// ============================================================
#define trig 13
#define echo 12
float dur = 0;
float dis = 0;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(115200);
}

void loop() {

  // kirim gelombang ultasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  

  //terima durasi dan jarak
  dur = pulseIn(echo, HIGH, 30000);
  dis = dur/58;

  Serial.print("Distance: ");
  Serial.print(dis);
  Serial.println(" Cm");
  delay(500);
}
