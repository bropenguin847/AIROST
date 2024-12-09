#include <BluetoothSerial.h>
BluetoothSerial Bluetooth;
#include <WiFi.h>
#include <ESPmDNS.h>
#include <NetworkUdp.h>
#include <ArduinoOTA.h>
#include "carMovement.h"

// const char* ssid     = "xxx;
// const char* password = "xxx";
char ssid[] = "xxx";
char password[] = "xxx";

int motorspeed = 140;
int gripper_status = 0;
int gripper, forwardd, reversee, goleftt, gorightt;
char position;
char command;

/////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  Bluetooth.begin("ESP32_LF_Car");

  pinMode(motorleftEn, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(motorrightEn, OUTPUT);
  setupCar();
}

void loop() {
  if (Bluetooth.available()){
    command = Bluetooth.read();
    handleBluetoothCommand(command);
    Serial.println(command);
  }

  if(command == 'A'){
    //forward
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 1) && (digitalRead(center) == 0) && (digitalRead(right1) == 1) && (digitalRead(right2) == 1)) {
      motorspeed = 120;//slower speed
      forward();
    }
    //goright
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 1) && (digitalRead(right1) == 0) && (digitalRead(right2) == 1)){
      lineright();
    }
    //sharp right
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 1) && (digitalRead(center)==0) && (digitalRead(right1) == 0) && (digitalRead(right2) == 0)) {
      lineright();
      delay(475);
    }

    //goleft
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 0)&& (digitalRead(right1) == 1) && (digitalRead(right2) == 1)){
      lineleft();
    }
    //sharp left
    if ((digitalRead(left2) == 0) && (digitalRead(left1) == 0) && (digitalRead(center)==0) && (digitalRead(right1) == 1) && (digitalRead(right2) == 1)) {  //sharp left turn
      lineleft();
      delay(475);
    }
    if ((digitalRead(left1) == 0) && (digitalRead(center)==0) && (digitalRead(right1) == 0)){
      reverse();
      delay(50);
      stopcar();
      delay(200);
    }
  }

}

void handleBluetoothCommand(char command) {
  switch (command) {
    case 'F': 
      forward(); 
      break;
    case 'B': 
      reverse(); 
      break;
    case 'L': 
      goleft(); 
      break;
    case 'R': 
      goright(); 
      break;
    case 'C':
      lineright();
      break;
    case 'S'://TX
      lineleft();
      break;
    default:
      stopcar();
      break;
  }
}

void forward() {  //forword
  analogWrite(motorleftEn, motorspeed);
  analogWrite(motorrightEn, motorspeed);
  digitalWrite(in1, HIGH);   //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, HIGH);   //Left Motor backword Pin
  digitalWrite(in4, LOW);  //Left Motor forword Pin
}
void reverse() {  //forword
  analogWrite(motorleftEn, motorspeed);
  analogWrite(motorrightEn, motorspeed);
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void goright() {  //turnRight
  motorspeed = 200;
  analogWrite(motorleftEn, motorspeed);
  analogWrite(motorrightEn, motorspeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void lineright(){
  analogWrite(motorleftEn, 200);
  analogWrite(motorrightEn, 110);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void lineleft(){
  analogWrite(motorleftEn, 110);
  analogWrite(motorrightEn, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void goleft() {  //turnLeft
  position = 'l';
  motorspeed = 200;
  analogWrite(motorleftEn, motorspeed);
  analogWrite(motorrightEn, motorspeed);
  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH);   //Right Motor backword Pin
  digitalWrite(in3, HIGH);   //Left Motor backword Pin
  digitalWrite(in4, LOW);
}

void stopcar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// void startOTA(){
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   while (WiFi.waitForConnectResult() != WL_CONNECTED) {
//     Serial.println("Connection Failed! Rebooting...");
//     delay(5000);
//     ESP.restart();
//   }
//   ArduinoOTA.setPassword("random");
//   ArduinoOTA
//     .onStart([]() {
//     String type;
//     if (ArduinoOTA.getCommand() == U_FLASH) {
//       type = "sketch";
//     } else {  // U_SPIFFS
//       type = "filesystem";
//     }

//     // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
//     Serial.println("Start updating " + type);
//     })
//     .onEnd([]() {
//       Serial.println("\nEnd");
//     })
//     .onProgress([](unsigned int progress, unsigned int total) {
//       Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
//     })
//     .onError([](ota_error_t error) {
//       Serial.printf("Error[%u]: ", error);
//       if (error == OTA_AUTH_ERROR) {
//         Serial.println("Auth Failed");
//       } else if (error == OTA_BEGIN_ERROR) {
//         Serial.println("Begin Failed");
//       } else if (error == OTA_CONNECT_ERROR) {
//         Serial.println("Connect Failed");
//       } else if (error == OTA_RECEIVE_ERROR) {
//         Serial.println("Receive Failed");
//       } else if (error == OTA_END_ERROR) {
//         Serial.println("End Failed");
//       }
//     });
//   ArduinoOTA.begin();
//   Serial.println("Ready");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
// }
