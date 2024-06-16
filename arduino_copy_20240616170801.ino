#include <SoftwareSerial.h>

// Motor A ve B için ENA ve ENB pinleri
int enA = 9;
int enB = 10;

// Motor A pinleri
int motorAPin1 = 2;
int motorAPin2 = 3;

// Motor B pinleri
int motorBPin1 = 4;
int motorBPin2 = 5;

// Bluetooth modülü için RX ve TX pinleri
int bluetoothTx = 11; // TX -> RX modülüne bağlanır
int bluetoothRx = 12; // RX -> TX modülüne bağlanır

// Bluetooth seri portu için bir değişken oluştur
SoftwareSerial myBluetooth(bluetoothTx, bluetoothRx);

void setup() {
  // Motor A ve B pinlerini çıkış olarak ayarla
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);

  // ENA ve ENB pinlerini çıkış olarak ayarla
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // Bluetooth seri portunu başlat
  myBluetooth.begin(9600);
}

void loop() {
  // Eğer Bluetooth üzerinden veri gelirse
  if (myBluetooth.available()) {
    char command = (char)myBluetooth.read();
    
    switch (command) {
      case 'F': // İleri
        digitalWrite(motorAPin1, HIGH);
        digitalWrite(motorAPin2, LOW);
        digitalWrite(motorBPin1, HIGH);
        digitalWrite(motorBPin2, LOW);
        analogWrite(enA, 200); // Motor A için hız
        analogWrite(enB, 200); // Motor B için hız
        break;
      case 'B': // Geri
        digitalWrite(motorAPin1, LOW);
        digitalWrite(motorAPin2, HIGH);
        digitalWrite(motorBPin1, LOW);
        digitalWrite(motorBPin2, HIGH);
        analogWrite(enA, 200); // Motor A için hız
        analogWrite(enB, 200); // Motor B için hız
        break;
      case 'S': // Dur
        digitalWrite(motorAPin1, LOW);
        digitalWrite(motorAPin2, LOW);
        digitalWrite(motorBPin1, LOW);
        digitalWrite(motorBPin2, LOW);
        break;
      // Diğer komutlar eklenebilir...
    }
  }
}
