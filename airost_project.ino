//to do:
// test out motor
// test out ir sensor
// assemble sensor on car chassis

#include <WiFi.h>
const char* ssid = "sirKamalWIFI";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

const int led = 2;
int irleft = 15;
int irright = 17;

int motorleft1 = 27;
int motorleft2 = 26;
int motorleftEn;

int motorright1 = 33;
int motorright2 = 25;
int motorrightEn;

int motorspeed = 100;

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

void goleft(){
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, HIGH);
  digitalWrite(motorright2, LOW);
}

void goright(){
  digitalWrite(motorleft1, HIGH);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, LOW);
}

void stopcar(){
  ledcWrite(motorleftEn, 0);
  ledcWrite(motorrightEn, 0);

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

  // ledcAttach(motorleftEn, freq, resolution);
  // ledcAttach(motorrightEn, freq, resolution);
    
  // Initialize PWM with 0 duty cycle
  // car doesn't move
  // ledcWrite(motorleftEn, 0);
  // ledcWrite(motorrightEn, 0);

  // WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid, password);
  // Serial.print("Connecting to WiFi ..");
}

void loop() {
  forward();
  digitalWrite(led,LOW);
  Serial.println("Now going forward");
  delay(5000);

  reverse();
  Serial.println("Now going backwards");
  delay(5000);

  goleft();
  Serial.println("Now going left");
  delay(5000);

  goright();
  Serial.println("Now right");
  delay(5000);

  stopcar();
  Serial.println("Car will stop");
  digitalWrite(led,HIGH);
  delay(5000);

  // int readvalue = analogRead(irleft); // Set the GPIO as Input
  // Serial.println(readvalue);
  // delay(800);
}
