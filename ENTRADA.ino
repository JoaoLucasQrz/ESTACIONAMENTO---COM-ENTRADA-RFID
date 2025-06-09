#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 8
MFRC522 mfrc522(SS_PIN, RST_PIN);

Servo servo1;
Servo servo2;
int servoPin1 = 3;
int servoPin2 = 5;

// LCD I2C (ajuste o endereço se necessário)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// UIDs dos 4 cartões autorizados (substitua pelos seus)
byte authorizedUIDs[4][4] = {
  {0xEA, 0xFA, 0xB8, 0x89},  // Cartão 1
  {0x76, 0xF7, 0xAF, 0x89},  // Cartão 2
  {0xD3, 0xB9, 0xA2, 0xF5},  // Cartão 3
  {0x53, 0x42, 0x27, 0xF6}   // Cartão 4
};

bool lidos[4] = {false, false, false, false};       // Cartões novos já lidos
bool repetidos[4] = {false, false, false, false};   // Cartões repetidos pelo menos 1 vez

int vagas = 4;  // Total de vagas iniciais

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(0);
  servo2.write(0);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Aproxime o Cartao");
  lcd.setCursor(0, 1);
  lcd.print("Vagas: ");
  lcd.print(vagas);
  
  Serial.println("Aproxime os cartões RFID.");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) return;

  int index = getAuthorizedIndex(mfrc522.uid.uidByte, mfrc522.uid.size);

  if (index >= 0) {
    if (!lidos[index]) {
      // Cartão novo → Servo 1 e diminui vaga
      lidos[index] = true;
      vagas--;
      if (vagas < 0) vagas = 0; // Evita valor negativo
      
      String msg = "Cartao " + String(index + 1) + " novo";
      Serial.println(msg + " -> Servo 1");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(msg);
      lcd.setCursor(0, 1);
      lcd.print("Vagas: ");
      lcd.print(vagas);

      movimentarServo(servo1);
    } else {
      // Cartão repetido → Servo 2 e aumenta vaga
      if (!repetidos[index]) {
        repetidos[index] = true;
        vagas++;
        if (vagas > 4) vagas = 4; // Limite máximo de vagas
      }

      String msg = "Cartao " + String(index + 1) + " repetido";
      Serial.println(msg + " -> Servo 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(msg);
      lcd.setCursor(0, 1);
      lcd.print("Vagas: ");
      lcd.print(vagas);

      movimentarServo(servo2);

      if (todosRepetidos()) {
        Serial.println("Todos os cartoes repetidos, reiniciando ciclo...");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ciclo reiniciado");
        resetarCiclo();
        vagas = 4;  // Reseta vagas
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Aproxime o Cartao");
        lcd.setCursor(0, 1);
        lcd.print("Vagas: ");
        lcd.print(vagas);
      }
    }
  } else {
    Serial.println("Cartao nao autorizado");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cartao nao");
    lcd.setCursor(0, 1);
    lcd.print("autorizado");
  }

  mfrc522.PICC_HaltA();
}

int getAuthorizedIndex(byte *uid, byte length) {
  if (length != 4) return -1;
  for (int i = 0; i < 4; i++) {
    bool match = true;
    for (int j = 0; j < 4; j++) {
      if (uid[j] != authorizedUIDs[i][j]) {
        match = false;
        break;
      }
    }
    if (match) return i;
  }
  return -1;
}

bool todosRepetidos() {
  for (int i = 0; i < 4; i++) {
    if (!repetidos[i]) return false;
  }
  return true;
}

void movimentarServo(Servo &servo) {
  for (int pos = 0; pos <= 90; pos++) {
    servo.write(pos);
    delay(10);
  }
  delay(300);
  for (int pos = 90; pos >= 0; pos--) {
    servo.write(pos);
    delay(10);
  }
}

void resetarCiclo() {
  for (int i = 0; i < 4; i++) {
    lidos[i] = false;
    repetidos[i] = false;
  }
  Serial.println("Ciclo reiniciado.");
}
