#include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

int PIN_U1_EN = 7;
int PIN_U1_STEP = 6;
int PIN_U1_DIR = 5;
int PIN_U2_EN = 4;
int PIN_U2_STEP = 3;
int PIN_U2_DIR = 2;
int PERIOD = 150;
int PIN_SW_L = 10;
int PIN_SW_R = 9;

void setup() {
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  pinMode(13, OUTPUT);
  pinMode(PIN_U2_EN, OUTPUT);
  pinMode(PIN_U2_STEP, OUTPUT);
  pinMode(PIN_U2_DIR, OUTPUT);
  pinMode(PIN_SW_L, INPUT_PULLUP);
  pinMode(PIN_SW_R, INPUT_PULLUP);

  digitalWrite(13, LOW);
  digitalWrite(PIN_U2_STEP, LOW);
  digitalWrite(PIN_U2_DIR, HIGH); // HIGH is unroll, LOW is roll
  digitalWrite(PIN_U2_EN, LOW);
  Serial.begin(9600);
}

void loop() {
  int sensorVal_L = digitalRead(PIN_SW_L);
  int sensorVal_R = digitalRead(PIN_SW_R);
  if (sensorVal_L == LOW) {
    digitalWrite(PIN_U2_DIR, LOW);
    digitalWrite(PIN_U2_EN, LOW);
  }
  else if (sensorVal_R == LOW) {
    digitalWrite(PIN_U2_DIR, HIGH);
    digitalWrite(PIN_U2_EN, LOW);
  }
  else {
    digitalWrite(PIN_U2_EN, HIGH);
  }
  if (sensorVal_L == LOW || sensorVal_R == LOW) {
    digitalWrite(13, HIGH);
    digitalWrite(PIN_U2_STEP, HIGH);
    delayMicroseconds(PERIOD);
    digitalWrite(13, LOW);
    digitalWrite(PIN_U2_STEP, LOW);
    delayMicroseconds(PERIOD);  

  }
}

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }