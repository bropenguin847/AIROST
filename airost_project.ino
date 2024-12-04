#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6bndVJqDX"
#define BLYNK_TEMPLATE_NAME "AIROST CAR"
#define BLYNK_AUTH_TOKEN "lFAkj-b33onExqWy-P0nn_FbI3tfv6xQ"

#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>

// #include "website.h"
#include "carMovement.h"
#include "esp32OTA.h"
#include "lineFollow.h"

// const char* ssid     = "LAPTOP-UPM4QH47 6598";
// const char* password = "Halo Halo Bonjour";
char ssid[] = "LIM_ILLEGEAR 9590";
char password[] = "7623H879";

int BUILTIN_LED = 2;
int manual = 4;
int manual_status;

Servo myservo;    // Attach at pin 18
int servopin = 13;
int servopos = 35;
int gripper, forwardd, reversee, goleftt, gorightt;
int gripper_status = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Ok start working");
  // startOTA();   // OTA will begin

  // Setting up pins
  pinMode(BUILTIN_LED, OUTPUT);
  setupMotor();
  setupIR();
  myservo.attach(servopin);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  pinMode(manual, INPUT);

  ledcAttachChannel(motorleftEn, freq, resolution, pwmChannel);
  ledcAttachChannel(motorrightEn, freq, resolution, pwmChannel);
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);

  myservo.write(servopos);
}

void loop() {
  // ArduinoOTA.handle();
  digitalWrite(BUILTIN_LED, LOW);
  manual_status = digitalRead(manual);
  
  while(manual_status){
    Blynk.run();
    digitalWrite(BUILTIN_LED, HIGH);
    Serial.println("now in manual mode");
    Serial.println(gripper);
    Serial.println(forwardd);
    Serial.println(reversee);
    Serial.println(goleftt);
    Serial.println(gorightt);

    if (gripper == 1 && gripper_status == 0){
      for (servopos = 40; servopos <= 110; servopos += 1) {
        myservo.write(servopos);
        delay(50);
        gripper_status = 1;
      }
    }
    if (gripper == 0 && gripper_status == 1){
      for (servopos = 110; servopos >= 40; servopos -= 1) {
        myservo.write(servopos);
        delay(50);
        gripper_status = 0;
      }
    }

    if (forwardd  == 1){
      forward();
    }
    else if (reversee  == 1){
      reverse();
    }
    else if (gorightt == 1){
      goright();
    }
    else if (goleftt == 1){
      goleft();
    }
    else{
      stopcar();
    }
    delay(50);
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

BLYNK_WRITE(V0)
{
  gripper = param.asInt();  //read value from this pin
}

BLYNK_WRITE(V1)
{
  forwardd = param.asInt();  //read value from this pin
}

BLYNK_WRITE(V2)
{
  reversee = param.asInt();  //read value from this pin
}

BLYNK_WRITE(V3)
{
  goleftt = param.asInt();  //read value from this pin
}

BLYNK_WRITE(V4)
{
  gorightt = param.asInt();  //read value from this pin
}