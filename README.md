# project_IOT

Kumpulan program ESP32 untuk praktikum **Sistem Benam / IoT** menggunakan Arduino IDE.

---

## 📁 Struktur Proyek

```
project_IOT/
├── basic/
│   ├── button/          # Tombol + lampu
│   ├── buzzer/          # Buzzer
│   ├── dht/             # Sensor suhu & kelembapan DHT11
│   ├── ir/              # Sensor IR
│   ├── keypad/          # Keypad 4x4
│   ├── lamp/            # Lampu LED
│   ├── lcd/             # LCD I2C 16x2
│   ├── pir/             # Sensor gerak PIR
│   │   └── pirsimple/
│   ├── potensiometer/
│   ├── servo/
│   └── ultasonic/       # HC-SR04 pengukur jarak
├── dht_lcd/             # Monitoring DHT ke LCD
├── simonsays/           # Game Simon Says
├── ultasonik_lamp_buzzer/  # Ultrasonic + lampu + buzzer
└── prima_pir_ultrasonic/   # Gabungan prima, PIR & ultrasonic
```

---

## 🛠️ Proyek

- **`basic/`** — contoh-contoh dasar pengoperasian sensor & aktuator satu per satu.
- **`dht_lcd/`** — monitoring suhu/kelembapan DHT ke LCD I2C dengan beberapa mode.
- **`simonsays/`** — game memori Simon Says menggunakan tombol dan LCD.
- **`ultasonik_lamp_buzzer/`** — pengukuran jarak mengontrol lampu dan buzzer.
- **`prima_pir_ultrasonic/`** — gabungan deteksi bilangan prima, gerakan (PIR), dan jarak (ultrasonik).

*(Deskripsi lengkap tiap proyek akan dilengkapi secara bertahap.)*

---

## 🚀 Cara Menjalankan

1. Instal **Arduino IDE** + board support **ESP32**.
2. Instal library yang diperlukan (DHT, LiquidCrystal_I2C, Keypad, ESP32Servo).
3. Buka file `.ino`, pilih board **ESP32 Dev Module**, lalu upload.
4. Sesuaikan koneksi pin sesuai keterangan di dalam kode.