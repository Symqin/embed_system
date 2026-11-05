#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ============================================================
// KONFIGURASI LCD
// ============================================================
// Alamat I2C: kebanyakan modul = 0x27. Jika layar tidak menampilkan
// apa-apa, coba alamat 0x3F (jalankan I2C scanner untuk memastikan).
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  Serial.begin(9600);

  lcd.init();          // inisialisasi LCD
  lcd.backlight();     // nyalakan backlight
  lcd.clear();
}

void loop() {
  // ============================================================
  // VARIASI 1: Teks statis (dasar)
  // ============================================================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SISTEM BENAM");
  lcd.setCursor(0, 1);
  lcd.print("UTS ESP32");
  delay(4000);

  // ============================================================
  // VARIASI 2: Tulisan bergerak / scrolling ke kiri
  // (persis pola sederhana: print sekali -> scrollDisplayLeft)
  // ============================================================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO UTS");
  for (int i = 0; i < 16; i++) {   // geser sampai konten habis keluar
    lcd.scrollDisplayLeft();
    delay(300);
  }
  lcd.clear();

  // ============================================================
  // VARIASI 3: Teks berkedip (blink)
  // Cara terbaik: noDisplay()/display() — HANYA menyembunyikan &
  // memunculkan tampilan, isi LCD tetap utuh (beda dgn clear()).
  //   lcd.clear()     -> hapus isi LCD
  //   lcd.noDisplay() -> sembunyikan tampilan sementara
  //   lcd.display()   -> tampilkan kembali isi LCD
  // ============================================================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BLINK BLINK");
  for (int i = 0; i < 3; i++) {
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
  }
  lcd.clear();

  // ============================================================
  // VARIASI 4: Counter (menghitung angka 0 s/d 10)
  // Pola variabel penghitung:
  //   int counter = 0;        buat variabel penghitung
  //   counter++;              tambah 1
  //   if (counter > 10)       cek apakah sudah lebih dari 10
  //   counter = 0;            reset ke nol
  // ============================================================
  int counter = 0;
  lcd.setCursor(0, 0);
  lcd.print("COUNTER:");
  for (int i = 0; i < 11; i++) {       // tampilkan 0 s/d 10, lalu reset
    lcd.setCursor(0, 1);
    lcd.print("Counter: ");
    lcd.print(counter);
    delay(1000);

    counter++;                         // tambah ke angka berikutnya
    if (counter > 10) {
      counter = 0;                     // sudah lewat 10 -> kembali ke 0
    }
    lcd.clear();
  }
  lcd.clear();

  // ============================================================
  // VARIASI 5: Karakter kustom (icon) — animasi sederhana
  //   1) mendefinisikan bentuk piksel (5x8)
  //   2) menampilkannya sebagai karakter
  // ============================================================
  byte hati[8] = {
    B00000,
    B01010,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000,
    B00000
  };
  lcd.createChar(0, hati);

  lcd.setCursor(0, 0);
  lcd.print("KUSTOM CHAR:");
  lcd.setCursor(12, 0);
  lcd.write(byte(0));            // tampilkan icon hati di kanan baris atas
  lcd.setCursor(0, 1);
  lcd.print("by Sistem Benam");
  delay(4000);

  lcd.clear();
}