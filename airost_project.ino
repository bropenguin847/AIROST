//to do:
// test out ir sensor
// assemble sensor on car chassis

#include <WiFi.h>
#include <ESP32Servo.h>
#include <ArduinoOTA.h>
#include "carMovement.h"
#include "esp32OTA.h"

int led = 2;
int irleft = 15;
int irright = 18;

Servo servo;
int servoPin = 13;

void setup() {
  Serial.begin(115200);
  Serial.println("Ok start working");
  startOTA();   // OTA will begin

  // Setting up pins
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
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
}

void loop() {
  ArduinoOTA.handle();

  // test out motor
  forward();
  delay(4000);
  reverse();
  delay(4000);
  stopcar();
  delay(4000);
}
