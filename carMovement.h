int motorleft1 = 27;
int motorleft2 = 26;
int motorleftEn = 14;

int motorright1 = 25;
int motorright2 = 33;
int motorrightEn = 32;

int motorspeed = 255;
// If motor speed too fast, then IR sensor might have trouble doing line following
// worth a discussion on motor speed. If speed too slow, the motor wont
// start up. So far i found that speed 205 is okay

// Setting PWM properties
const int freq = 30000;
const int resolution = 8;
const int pwmChannel = 0;
int dutyCycle = 0;

void setupMotor(){
  pinMode(motorleft1, OUTPUT);
  pinMode(motorleft2, OUTPUT);
  pinMode(motorright1, OUTPUT);
  pinMode(motorright2, OUTPUT);
}

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
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, LOW);
}