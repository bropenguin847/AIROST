//to do:
// test out ir sensor
// assemble sensor on car chassis

#include <WiFi.h>
#include <ESP32Servo.h>
#include "BluetoothSerial.h"
// #include "carMovement.h"
const char* ssid = "sirKamalWIFI";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// for reference
int motorleft1 = 27;
int motorleft2 = 26;
int motorleftEn = 14;
int leftspeed = 150; /////////////////////////////////////////////////////

int motorright1 = 25;
int motorright2 = 33;
int motorrightEn = 32;
int rightspeed = 170; /////////////////////////////////////////////////////
// int motorspeed;

int led = 2;
int irleft = 15;
int irright = 18;

Servo servo;
int servoPin = 13;

int potpin = 4; // use potentiometer to determine the speed of car, the hardcode the speed into the code
int potvalue = 0;

// Setting PWM properties
const int freq = 30000;
const int resolution = 8;
const int pwmChannel = 0;
int dutyCycle = 0;

void forward(){
  digitalWrite(motorleft1, HIGH);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, HIGH);
  digitalWrite(motorright2, LOW);
}
void reverse(){
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, HIGH); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, HIGH);
}

void stopcar(){
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, LOW);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Ok start working");
  pinMode(led, OUTPUT);
  pinMode(motorleft1, OUTPUT);
  pinMode(motorleft2, OUTPUT);
  pinMode(motorright1, OUTPUT);
  pinMode(motorright2, OUTPUT);
  pinMode(irleft, INPUT);
  pinMode(irright, INPUT);
  servo.attach(servoPin);
  ledcAttachChannel(motorleftEn, freq, resolution, pwmChannel);
  ledcAttachChannel(motorrightEn, freq, resolution, pwmChannel);
  // ledcWrite(motorleftEn, 255);  // to kickstart the motor, if speed too low, then it wont run
  // ledcWrite(motorrightEn, 255);
  // forward();
  // delay(100);
  // ledcWrite(motorleftEn, 250);  // to kickstart the motor, if speed too low, then it wont run
  // ledcWrite(motorrightEn, 250);
  // forward();
  // digitalWrite(led, HIGH);  //indicate car stopping, can setup
  // delay(4000);
  // digitalWrite(led, LOW);

}

void loop() {
  // potvalue = analogRead(potpin);
  // motorspeed = map(potvalue, 0, 4095, 0, 255);
  digitalWrite(led, LOW);
  ledcWrite(motorrightEn, 205);
  ledcWrite(motorleftEn, 205);
  reverse();
  // delay(6000);

  // stopcar();
  // digitalWrite(led, HIGH);
  // delay(7000);
}
