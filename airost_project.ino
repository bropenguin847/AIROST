// #include <Servo.h>
#include <WiFi.h>
#include <ESP32Servo.h>
// #include <ArduinoOTA.h>
#include <WebServer.h>
#include "carMovement.h"
#include "esp32OTA.h"
#include "lineFollow.h"

int led = 2;

int manual = 4;
int manual_status;
int grip_button = 5;
int grip;

Servo servo;    // Attach at pin 13

void setup() {
  Serial.begin(115200);
  Serial.println("Ok start working");
  // startOTA();   // OTA will begin

  // Setting up pins
  pinMode(led, OUTPUT);
  setupMotor();
  setupIR();
  pinMode(manual, INPUT);
  pinMode(grip_button, INPUT);

  servo.attach(13);
  ledcAttachChannel(motorleftEn, freq, resolution, pwmChannel);
  ledcAttachChannel(motorrightEn, freq, resolution, pwmChannel);
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
}

void loop() {
  // ArduinoOTA.handle();
  manual_status = digitalRead(manual);
  while(manual_status == 1){
    // Perform manual control over here
    grip = digitalRead(grip_button);
    if (grip == 1){   // When button is pushed, gripper will close and grab item
      servo.write(90);
    }
    else{             // Else, gripper will open
      servo.write(0);
    }
    manual_status = digitalRead(manual);
  }

  reading();
  if (leftside == 1 && rightside == 1){
    stopcar();
  }
  if (leftside == 0 && rightside == 1){
    goright();
  }
  if (leftside == 1 && rightside == 0){
    goleft(); 
  }
  if (leftside == 0 && rightside == 0){
    forward();
  }
}