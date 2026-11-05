# project_IOT

Kumpulan program ESP32 untuk praktikum **Sistem Benam / IoT**. Proyek ini berisi contoh-contoh dasar penggunaan sensor dan aktuator, serta beberapa proyek gabungan yang lebih kompleks.

Kode ditulis menggunakan **Arduino IDE** dan ditujukan untuk board **ESP32** (DevKit). Semua program di sisi MCU (tidak ada server/web).

---

## 📁 Struktur Proyek

```
project_IOT/
├── basic/                     # Contoh-contoh dasar per komponen
│   ├── button/                # Membaca tombol & menyalakan lampu
│   ├── buzzer/                # Buzzer nyala-mati
│   ├── dht/                   # Sensor suhu & kelembapan DHT11
│   ├── ir/                    # Sensor IR (deteksi objek)
│   ├── keypad/                # Keypad 4x4
│   ├── lamp/                  # Lampu LED blink
│   ├── lcd/                   # LCD I2C 16x2
│   ├── pir/                   # Sensor gerak PIR + lampu/buzzer
│   │   └── pirsimple/         # PIR versi sederhana
│   ├── potensiometer/         # Membaca nilai analog potensiometer
│   ├── servo/                 # Menggerakkan servo
│   └── ultasonic/             # Pengukur jarak HC-SR04
├── dht_lcd/                   # Monitoring DHT ke LCD (3 mode)
├── simonsays/                 # Game Simon Says (2 tombol + LCD)
├── ultasonik_lamp_buzzer/     # Ultrasonic kontrol 3 lampu + buzzer
└── prima_pir_ultrasonic/      # Gabungan bilangan prima, PIR & ultrasonic
```

---

## 🔌 Contoh Dasar (`basic/`)

| Folder | Fungsi | Pin yang Digunakan |
|--------|--------|--------------------|
| `button` | Tombol menyalakan/mematikan lampu | button = 13, lamp = 23 |
| `buzzer` | Buzzer bunyi 1 dtk, diam 1 dtk | buzzer = 25 |
| `dht` | Membaca suhu (°C / °F) & kelembapan dari DHT11 via Serial | DHT_PIN = 21 |
| `ir` | Mendeteksi ada/tidak ada objek | ir = 4 |
| `keypad` | Membaca tombol keypad 4x4 dan menampilkan di Serial | rows {14,12,13,15}, cols {27,26,25,33} |
| `lamp` | Lampu LED blink (nyala 1 dtk, mati 1 dtk) | lamp = 12 |
| `lcd` | Menampilkan teks di LCD I2C 16x2 | I2C (SDA 21, SCL 22), addr 0x27 |
| `pir` | Gerakan terdeteksi → LED merah + buzzer; aman → LED hijau | pir=4, ledMerah=13, ledHijau=12, buzzer=14 |
| `pir/pirsimple` | Deteksi gerakan PIR, output ke Serial | PIR_PIN = 4 |
| `potensiometer` | Membaca nilai analog potensiometer | pot = 4 |
| `servo` | Servo bergerak 0° → 90° → 180° | servoPIN = 15 |
| `ultasonic` | Mengukur jarak dengan HC-SR04 (cm) | trig = 13, echo = 12 |

---

## 🛠️ Proyek Gabungan

### 1. `dht_lcd/` — Monitoring Suhu & Kelembapan ke LCD
- Membaca **DHT11/DHT22** dan menampilkan hasil ke **LCD I2C 16x2**.
- Tombol untuk berpindah **mode**: kelembapan (%), suhu Celsius, dan suhu Fahrenheit.
- Pin: DHT = 13, button = 14, LCD I2C (SDA 21, SCL 22).
- Data juga dikirim ke Serial Monitor (baud 115200).

### 2. `simonsays/` — Game Simon Says
- Game memori: sistem menampilkan urutan angka acak (Tombol 1 / Tombol 2) di **LCD**, pemain harus mengulang urutannya.
- Setiap level benar, urutan bertambah panjang (maks. level 50). Salah → *Game Over*.
- Pin: button1 = 18, button2 = 19, LCD I2C (SDA 21, SCL 22).

### 3. `ultasonik_lamp_buzzer/` — Ultrasonic Mengontrol Lampu & Buzzer
- Jarak diukur dengan **HC-SR04**, lalu mengontrol **3 lampu + buzzer**:
  - `jarak ≥ 80 cm` → lampu 1 nyala
  - `20 cm ≤ jarak < 80 cm` → lampu 2 nyala
  - `jarak < 20 cm` → lampu 3 + **buzzer** menyala
- Pin: trig=26, echo=19, lamp1=12, lamp2=13, lamp3=27, buzz=4.

### 4. `prima_pir_ultrasonic/` — Deteksi Bilangan Prima, Gerakan & Jarak
Sistem gabungan tombol, PIR, dan ultrasonik berbasis **bilangan**:
- Tombol menambah nilai `bilangan` (1 kali per tekan).
- **Bilangan prima** → buzzer aktif (sensor nonaktif).
- **Bilangan ganjil** → mode **PIR**: gerakan terdeteksi menyalakan LED1.
- **Bilangan genap** → mode **ultrasonik**:
  - jarak 15–20 cm → LED1
  - jarak >20–30 cm → LED1 + LED2
  - jarak >30–50 cm → LED1 + LED2 + LED3
- Pin: pir=2, button=7, led1=3, led2=4, led3=5, buzzer=6, trig=12, echo=13.

---

## 📚 Library yang Dibutuhkan

Instal melalui Library Manager di Arduino IDE:

| Library | Kegunaan |
|---------|----------|
| **DHT sensor library** (Adafruit) | Sensor DHT11/DHT22 |
| **LiquidCrystal_I2C** (Frank de Brabander) | LCD I2C 16x2 |
| **Keypad** (Mark Stanley & Alexander Brevig) | Keypad 4x4 |
| **ESP32Servo** | Kendali servo pada ESP32 |
| **Wire** (bawaan) | Komunikasi I2C |

---

## 🚀 Cara Menjalankan

1. Instal **Arduino IDE** dan **ESP32 board support** (Board Manager → `esp32 by Espressif Systems`).
2. Instal semua library yang dibutuhkan (lihat tabel di atas).
3. Buka file `.ino` yang diinginkan, pilih board **`ESP32 Dev Module`**.
4. Pilih port yang benar, lalu **Upload**.
5. Sesuaikan koneksi pin mengikuti keterangan masing-masing program.
6. Untuk program yang mencetak ke Serial, buka **Serial Monitor** dengan baud rate sesuai kode (9600 / 115200).

---

## ✍️ Catatan

- Program ditulis dengan komentar berbahasa Indonesia.
- Koneksi I2C pada ESP32 secara umum: **SDA = GPIO 21**, **SCL = GPIO 22**.
- Beberapa pin pada `basic/` mungkin perlu disesuaikan dengan konfigurasi board masing-masing.