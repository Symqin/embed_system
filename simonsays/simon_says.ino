
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int button1 = 18;
const int button2 = 19;

const int MAX_LEVEL = 50;
int sequence[MAX_LEVEL];
int level = 1;

int readButton() {
  if (digitalRead(button1) == LOW) {
    delay(30);
    if (digitalRead(button1) == LOW) {
      while (digitalRead(button1) == LOW) {
        delay(10);
      }
      return 0;
    }
  }

  if (digitalRead(button2) == LOW) {
    delay(30);
    if (digitalRead(button2) == LOW) {
      while (digitalRead(button2) == LOW) {
        delay(10);
      }
      return 1;
    }
  }

  return -1;
}

void showReady() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SIMON SAYS");
  lcd.setCursor(0, 1);
  lcd.print("Tekan tombol");
}

void showSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingat urutan!");
  delay(700);

  for (int i = 0; i < level; i++) {
    lcd.setCursor(0, 1);
    lcd.print("Tombol: ");
    lcd.print(sequence[i] + 1);
    lcd.print("       ");
    delay(800);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Giliran kamu!");
  lcd.setCursor(0, 1);
  lcd.print("Level: ");
  lcd.print(level);
}

bool checkPlayer() {
  for (int i = 0; i < level; i++) {
    int pressed = -1;

    while (pressed == -1) {
      pressed = readButton();
      delay(5);
    }

    lcd.setCursor(0, 1);
    lcd.print("Tombol: ");
    lcd.print(pressed + 1);
    lcd.print("        ");

    if (pressed != sequence[i]) {
      return false;
    }
  }

  return true;
}

void gameOver() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAME OVER!");
  lcd.setCursor(0, 1);
  lcd.print("Level: ");
  lcd.print(level);

  delay(2000);

  level = 1;
  showReady();
}

void setup() {
  Wire.begin(21, 22);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  randomSeed(micros());
  showReady();
}

void loop() {
  if (readButton() != -1) {
    level = 1;

    while (level <= MAX_LEVEL) {
      for (int i = 0; i < level; i++) {
        sequence[i] = random(2);
      }

      showSequence();

      if (!checkPlayer()) {
        gameOver();
        return;
      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Benar!");
      lcd.setCursor(0, 1);
      lcd.print("Level: ");
      lcd.print(level);

      delay(1000);
      level++;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("KAMU MENANG!");
    delay(2000);

    level = 1;
    showReady();
  }
}
