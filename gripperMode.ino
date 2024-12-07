#define BLYNK_TEMPLATE_ID "TMPL6bndVJqDX"
#define BLYNK_TEMPLATE_NAME "AIROST CAR"
#define BLYNK_AUTH_TOKEN "lFAkj-b33onExqWy-P0nn_FbI3tfv6xQ"
#include <ESP32Servo.h>
#include <BlynkSimpleEsp32.h>

// const char* ssid     = "LAPTOP-UPM4QH47 6598";
// const char* password = "Halo Halo Bonjour";
char ssid[] = "LIM_ILLEGEAR 9590";
char password[] = "7623H879";

int manual = 26;
int servopin = 33;//13
int gripper_status = 0;
int servopos = 40;
Servo myservo;
int gripper;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  myservo.attach(servopin);
  myservo.write(servopos);
  pinMode(manual, INPUT);
}

void loop() {
  while(digitalRead(manual) == 1){
    Blynk.run();
    myservo.write(gripper);
    Serial.println(gripper);
  }
}

BLYNK_WRITE(V0){
  gripper = param.asInt();  //read value from this pin
}