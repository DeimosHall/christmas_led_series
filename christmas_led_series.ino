#include "BluetoothSerial.h"

#define INPUT_1 25
#define INPUT_2 26
#define LED_1 33
#define LED_2 32
#define LED_3 18
#define LED_4 19

BluetoothSerial SerialBT;
const String DEVICE_NAME = "ESP32 board";
byte dataRX;

int flag = 0;
int serie = 0;

void setup() {
  pinMode(INPUT_1, INPUT);
  pinMode(INPUT_2, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  Serial.begin(115200);
  SerialBT.begin(DEVICE_NAME);
  
  Serial.begin(115200);
}

void loop() {
  serialEvent();
  
  Serial.println("Mode: " + String(getMode()) + ", Serie: " + String(serie));
  if (getMode() != 0) {
    serie = getMode();
  }

  if (dataRX == '0') {
    serie = 0;
  } else if (dataRX == '1') {
    serie = 1;
  } else if (dataRX == '2') {
    serie = 2;
  } else if (dataRX == '3') {
    serie = 3;
  }
  
  if (serie == 1) {
    mode1();
  } else if (serie == 2) {
    mode2();
  } else if (serie == 3) {
    mode3();
  }
}

void serialEvent() {
  delay(20);

  if (SerialBT.available()) {
    dataRX = SerialBT.read();
    Serial.write(dataRX);
  }
}

int getMode() {
  if (digitalRead(INPUT_1) == 0 && digitalRead(INPUT_2) == 0) {
    return 0;
  } else if (digitalRead(INPUT_1) == 0 && digitalRead(INPUT_2) == 1) {
    return 1;
  } else if (digitalRead(INPUT_1) == 1 && digitalRead(INPUT_2) == 0) {
    return 2;
  } else if (digitalRead(INPUT_1) == 1 && digitalRead(INPUT_2) == 1) {
    return 3;
  }
}

void mode1() {
  delay(100);
  
  if (flag == 0) {
    flag = 1;
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, HIGH);
  } else if (flag == 1) {
    flag = 2;
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  } else if (flag == 2) {
    flag = 3;
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  } else {
    flag = 0;
    
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
}

void mode2() {
  delay(100);
  
  if (flag == 0) {
    flag = 1;
    
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  } else if (flag == 1) {
    flag = 2;
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  } else if (flag == 2) {
    flag = 3;
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  } else {
    flag = 0;
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, HIGH);
  }
}

void mode3() {
  delay(1000);
  
  if (flag == 0) {
    flag = 1;

    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  } else {
    flag = 0;

    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
}
