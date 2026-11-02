
#include <Keypad.h>

// Jumlah baris dan kolom
const byte ROWS = 4;
const byte COLS = 4;

// Susunan tombol keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Konfigurasi pin ESP32
// Row
byte rowPins[ROWS] = {14, 12, 13, 15};

// Column
byte colPins[COLS] = {27, 26, 25, 33};

// Inisialisasi keypad
Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

void setup() {
  Serial.begin(115200);

  keypad.setDebounceTime(50);
  keypad.setHoldTime(500);

  Serial.println("====================");
  Serial.println("    NUMPAD 4x4");
  Serial.println("====================");
  Serial.println("Numpad Ready!");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Tombol ditekan: ");
    Serial.println(key);
  }
}
