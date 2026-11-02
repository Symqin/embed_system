#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Konfigurasi DHT22
#define DHTPIN 13
#define DHTTYPE DHT11

// Konfigurasi Button
#define BUTTON_PIN 14

// Inisialisasi sensor dan LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Mode pengukuran
int mode = 0;
int lastButtonState = HIGH;

void setup() {
    Serial.begin(115200);

    dht.begin();

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Wire.begin(21, 22);
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("DHT22 Monitoring");

    lcd.setCursor(0, 1);
    lcd.print("Press Button");
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);

    // Mendeteksi tombol ditekan
    if (lastButtonState == HIGH && buttonState == LOW) {
        mode++;

        if (mode > 2) {
            mode = 0;
        }

        lcd.clear();
        delay(50);
    }

    lastButtonState = buttonState;

    // Mode 0: Kelembapan
    if (mode == 0) {
        float h = dht.readHumidity();

        if (isnan(h)) {
            lcd.setCursor(0, 0);
            lcd.print("Sensor Error");
        } else {
            lcd.setCursor(0, 0);
            lcd.print("Humidity:");

            lcd.setCursor(0, 1);
            lcd.print(h, 1);
            lcd.print(" %       ");

            Serial.print("Humidity: ");
            Serial.print(h);
            Serial.println(" %");
        }
    }

    // Mode 1: Celsius
    else if (mode == 1) {
        float t = dht.readTemperature();

        if (isnan(t)) {
            lcd.setCursor(0, 0);
            lcd.print("Sensor Error");
        } else {
            lcd.setCursor(0, 0);
            lcd.print("Temperature:");

            lcd.setCursor(0, 1);
            lcd.print(t, 1);
            lcd.print(" C       ");

            Serial.print("Temperature: ");
            Serial.print(t);
            Serial.println(" C");
        }
    }

    // Mode 2: Fahrenheit
    else if (mode == 2) {
        float f = dht.readTemperature(true);

        if (isnan(f)) {
            lcd.setCursor(0, 0);
            lcd.print("Sensor Error");
        } else {
            lcd.setCursor(0, 0);
            lcd.print("Temperature:");

            lcd.setCursor(0, 1);
            lcd.print(f, 1);
            lcd.print(" F       ");

            Serial.print("Temperature: ");
            Serial.print(f);
            Serial.println(" F");
        }
    }

    delay(500);
}