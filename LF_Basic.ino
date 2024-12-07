#include <BluetoothSerial.h>
BluetoothSerial Bluetooth;
#include "carMovement.h"

int motorspeed = 140;
int gripper_status = 0;
int gripper, forwardd, reversee, goleftt, gorightt;
char position;
char command;
bool manualMode = false;
unsigned long lastCommandTime = 0; // Timestamp of the last Bluetooth command
const unsigned long manualTimeout = 1000; // Timeout for manual mode (5 seconds)

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
    // manualMode = true; // Switch to manual mode
    // lastCommandTime = millis(); // Record the time of the last command
  }
  // if (manualMode && (millis() - lastCommandTime > manualTimeout)) {
  //   manualMode = false; // Switch back to autonomous mode
  // }

  if(command == 'A'){
    //forward
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 1) && (digitalRead(center) == 0) && (digitalRead(right1) == 1) && (digitalRead(right2) == 1)) {
      motorspeed = 130;//slower speed
      forward();
    }
    //goright
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 1) && (digitalRead(right1) == 0) && (digitalRead(right2) == 1)){
      goright();
    }
    //sharp right
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 1) && (digitalRead(center) == 0) && (digitalRead(right1) == 0) && (digitalRead(right2) == 0)) {
      goright();
      delay(900);
    }

    //goleft
    if ((digitalRead(left2) == 1) && (digitalRead(left1) == 0)&& (digitalRead(right1) == 1) && (digitalRead(right2) == 1)){
      goleft();
    }
    //sharp left
    if ((digitalRead(left2) == 0) && (digitalRead(left1) == 0) && (digitalRead(center) == 0) && (digitalRead(right1) == 1) && (digitalRead(right2) == 1)) {  //sharp left turn
      goleft();
      delay(900);
    }
    if ((digitalRead(left2) == 0) && (digitalRead(left1) == 0) && (digitalRead(center) == 0) && (digitalRead(right1) == 0) && (digitalRead(right2) == 0)) {
      stopcar();
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
  motorspeed = 160;
  analogWrite(motorleftEn, motorspeed);
  analogWrite(motorrightEn, motorspeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void lineright(){
  analogWrite(motorleftEn, motorspeed);
  analogWrite(motorrightEn, motorspeed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void goleft() {  //turnLeft
  position = 'l';
  motorspeed = 160;
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