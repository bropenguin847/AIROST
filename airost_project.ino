#include "website.h"
#include "carMovement.h"
#include "esp32OTA.h"
#include "lineFollow.h"

int BUILTIN_LED = 2;

int manual = 4;
int manual_status;
int grip_button = 5;
int grip;

void setup() {
  Serial.begin(115200);
  Serial.println("Ok start working");
  // startOTA();   // OTA will begin

  // Setting up pins
  pinMode(BUILTIN_LED, OUTPUT);
  setupMotor();
  setupIR();
  servosetup();
  servoonline();

  pinMode(manual, INPUT);
  pinMode(grip_button, INPUT);

  ledcAttachChannel(motorleftEn, freq, resolution, pwmChannel);
  ledcAttachChannel(motorrightEn, freq, resolution, pwmChannel);
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
}

void loop() {
  // ArduinoOTA.handle();
  digitalWrite(BUILTIN_LED, LOW);
  manual_status = digitalRead(manual);
  while(manual_status){
    servoonline();
    digitalWrite(BUILTIN_LED, HIGH);
    manual_status = digitalRead(manual);
  }

  reading();
  if (leftside == 1 && rightside == 1){
    stopcar();
  }
  if (leftside == 0 && rightside == 1){
    goright();
    delay(1500);
  }
  if (leftside == 1 && rightside == 0){
    goleft();
    delay(1500);
  }
  if (leftside == 0 && rightside == 0){
    forward();
  }
}