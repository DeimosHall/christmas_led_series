// Program behavior
//  in1 in2 led
//   0   0   1
//   0   1   2
//   1   0   3
//   1   1   4

#define INPUT_1 25
#define INPUT_2 26
#define LED_1 33
#define LED_2 32
#define LED_3 18
#define LED_4 19

int flag = 0;
int serie = 0;

void setup() {
  pinMode(INPUT_1, INPUT);
  pinMode(INPUT_2, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Mode: " + String(getMode()));
  
  if (getMode() == 1) {
    mode1();
  } else if (getMode() == 2) {
    mode2();
  } else if (getMode() == 3) {
    mode3();
  }
}

int getMode() {
  if (digitalRead(INPUT_1) == 0 && digitalRead(INPUT_2) == 0) {
    return 1;
  } else if (digitalRead(INPUT_1) == 0 && digitalRead(INPUT_2) == 1) {
    return 2; 
  } else if (digitalRead(INPUT_1) == 1 && digitalRead(INPUT_2) == 0) {
    return 3;
  } else if (digitalRead(INPUT_1) == 1 && digitalRead(INPUT_2) == 1) {
    return 4;
  }
}

void mode1() {
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

void mode2() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
}

void mode3() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, LOW);
}

void turnOnLed4() {
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, HIGH);
}
