# Sistem Benam — Proyek IoT ESP32 (Uts)

Kumpulan sketsa Arduino (`.ino`) dasar untuk berbagai modul sensor & aktuator ESP32.
Setiap folder berisi **satu program utuh** (pola folder Arduino IDE: nama file = nama folder),
memakai pin masing-masing agar mudah dicoba satu per satu.

---

## Daftar Modul & Pin

| Folder | Modul | Pin | Baud Serial |
|---|---|---|---|
| `button/` | Tombol + Lampu | tombol 13 (INPUT_PULLUP), lampu 23 | 9600 |
| `buzzer/` | Buzzer | 25 | – |
| `dht/` | DHT11 (suhu & kelembaban) | 21 | 9600 |
| `ir/` | Sensor IR obstacle | 4 | 9600 |
| `keypad/` | Keypad 4x4 | row: 14,12,13,15 · col: 27,26,25,33 | 115200 |
| `lamp/` | Lampu/LED blink | 12 | 115200 |
| `lcd/` | LCD I2C 16x2 (0x27) | SDA/SCL default (21/22) | 9600 |
| `pir/` | PIR + LED merah/hijau + buzzer | 4, 13, 12, 14 | 9600 |
| `pir/pirsimple/` | PIR sederhana (serial aja) | 4 | 115200 |
| `potensiometer/` | Potensiometer (ADC) | 4 | 9600 |
| `servo/` | Servo (ESP32Servo) | 15 | – |
| `ultasonic/` | Ultrasonik HC-SR04 | trig 13, echo 12 | 115200 |

---

## Penjelasan Singkat per File

### button/button.ino
Tombol memakai **INPUT_PULLUP** (tidak butuh resistor eksternal). Saat tombol ditekan,
input menjadi `LOW` → lampu menyala, teks `button_ditekan` dikirim ke Serial.

### buzzer/buzzer.ino
Buzzer bunyi 1 detik, mati 1 detik, berulang. Contoh paling dasar `digitalWrite`.

### dht/dht.ino
Membaca suhu (Celcius & Fahrenheit) dan kelembapan DHT11, dengan penanganan
nilai gagal (`isnan`). `delay(2000)` sesuai rekomendasi interval pembacaan DHT11 (min. 1 dtk).

### ir/ir.ino
Sensor IR obstacle mendeteksi **ada/tidaknya objek**. Asumsi: modul AKTIF-LOW
(ada objek = `LOW`). Jika modul berbeda, balik kondisinya.

### keypad/keypad.ino
Keypad 4x4 dengan library Keypad. Susunan tombol, pin per baris/kolom, serta
`setDebounceTime(50)` dan `setHoldTime(500)` sudah dikonfigurasi.

### lamp/lamp.ino
Lampu blink 1 detik menyala, 1 detik mati. Versi paling sederhana.

### lcd/lcd.ino
LCD I2C 16x2 menampilkan beberapa **variasi tampilan** yang berjalan bergantian:
1. Teks statis
2. **Tulisan bergerak (scrolling)** ke kiri — pakai metode bawaan `scrollDisplayLeft()`
3. Teks berkedip (blink) — pakai `noDisplay()`/`display()` agar isi LCD tidak hilang
4. Counter menghitung 0–10 — pola variabel `counter++` + reset `if (counter > 10)`
5. Karakter kustom (icon) memakai `createChar()`

### pir/pir.ino
PIR mendeteksi gerakan → LED merah + buzzer aktif; jika tenang → LED hijau.
Dengan pesan Serial untuk tiap kondisi.

### pir/pirsimple/pirsimple.ino
Versi paling sederhana PIR: hanya membaca status lalu mencetak ke Serial.

### potensiometer/potensiometer.ino
Membaca nilai analog (0–4095) potensiometer lalu mengirim ke Serial.

### servo/servo.ino
Servo bergerak bertahap 0° → 90° → 180° memakai library ESP32Servo.

### ultasonic/ultasonic.ino
Mengirim pulsa trig, mengukur durasi pantulan echo, lalu menghitung jarak
dalam cm dengan rumus `dur / 58`.

---

## ⚠️ Isu-Isu Penting & Rekomendasi

### 1. Potensiometer di GPIO4 → HARUS pindah jika pakai WiFi 🔴
- GPIO4 termasuk grup **ADC2**. Pada ESP32, saat **WiFi aktif** (SSID/HTTP/MQTT),
  semua pin ADC2 **tidak bisa `analogRead`** → hasilnya selalu 0.
- **Solusi:** pindahkan potensiometer ke pin ADC1, misal **32, 33, 34, 35, atau 39**.
  Contoh: `#define pot 34`.

### 2. Hindari GPIO12 (MTDI) untuk OUTPUT ⚠️
- GPIO12 adalah **strapping pin**. Jika ada rangkaian yang menahannya **HIGH saat boot**,
  ESP32 bisa masuk mode salah / gagal boot.
- Terdapat di: `lamp.ino` (pin 12), `pir.ino` (ledHijau 12), `ultasonic.ino` (echo 12),
  `keypad.ino` (rowPins berisi 12).
- **Solusi:** ganti ke pin output bebas seperti GPIO16/17/18/19/23.

### 3. Tombol belum ada debounce ⚠️
- Tanpa debounce, pembacaan tombol bisa "bouncing" (naik-turun cepat) sehingga
  hasilnya tidak stabil.
- **Solusi:** gunakan `millis()` + `lastDebounceTime`, atau library Bounce2.

### 4. Logika IR tergantung tipe modul
- Kode mengasumsikan modul IR **aktif-LOW** (HW-201/FC-51). Pastikan sesuai
  modul yang dipakai; jika aktif-HIGH, balik `if (statusIR == HIGH)`.

### 5. LCD tidak tampil?
- Alamat I2C default di kode `0x27`. Kebanyakan modul memakai itu, tapi ada yang `0x3F`.
- Jalankan **I2C scanner** untuk memastikan alamat sebenarnya.

### 6. PIR butuh waktu kalibrasi
- Setelah dinyalakan, PIR perlu **±10–30 detik** kalibrasi dan akan memicu
  beberapa kali di awal — wajar, tunggu sebentar sebelum menguji.

### 7. Catatan lain (bukan error)
- Baud rate Serial antar-sketsa tidak sama (9600 / 115200). Tidak masalah
  selama saat monitoring memakai baud yang sesuai dengan sketsanya.
- Meski pin dipakai berulang antar-folder, itu **aman** karena tiap sketsa
  dicoba terpisah. Jika ingin digabung jadi satu program, perlu mapping ulang.

---

## Tips Menjalankan
1. Buka folder proyek (mis. `basic/button/button.ino`) di **Arduino IDE**.
2. Pilih board **ESP32 Dev Module** (Tools → Board).
3. Install library yang dibutuhkan tiap modul:
   - `DHT sensor library` (dht)
   - `Keypad` (keypad)
   - `LiquidCrystal I2C` (lcd)
   - `ESP32Servo` (servo)
4. Upload & buka **Serial Monitor** sesuai baud tabel di atas.