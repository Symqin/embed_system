#include <DHT.h>

#define DHT_PIN 21
#define DHT_TYPE 11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity(); 
  float temperatureC = dht.readTemperature();// celcius
  float temperatureF = dht.readTemperature(true); // fahreheit

  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF) ){
    Serial.println("gagal membaca dht");
    delay(2000);
    return;
  }

  Serial.print("Kelembapan: ");  
  Serial.print(humidity);  
  Serial.println(" %");  
  
  Serial.print("Suhu: ");  
  Serial.print(temperatureC);  
  Serial.println(" C");

  Serial.print("Suhu: ");  
  Serial.print(temperatureF);  
  Serial.println(" F");

  delay(2000);
}
