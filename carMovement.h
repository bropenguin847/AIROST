int motorleft1 = 27;
int motorleft2 = 26;
int motorleftEn = 14;

int motorright1 = 25;
int motorright2 = 33;
int motorrightEn = 32;

int freq = 30000;
int resolution = 8;
const int pwmChannel = 0;
int dutyCycle = 0;
int motorspeed;

void setupMotor(){
  pinMode(motorleft1, OUTPUT);
  pinMode(motorleft2, OUTPUT);
  pinMode(motorright1, OUTPUT);
  pinMode(motorright2, OUTPUT);
  ledcAttachChannel(motorleftEn, freq, resolution, pwmChannel);
  ledcAttachChannel(motorrightEn, freq, resolution, pwmChannel);

}

void forward(){
  motorspeed = 255; //kickstart motor
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
  delay(100);
  digitalWrite(motorleft1, HIGH);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, HIGH);
  digitalWrite(motorright2, LOW);
  motorspeed = 205;
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
}

void reverse(){
  motorspeed = 255; //kickstart motor
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
  delay(100);
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, HIGH); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, HIGH);
  motorspeed = 205;
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
}

void goleft(){
  motorspeed = 255;
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, HIGH); 
  digitalWrite(motorright1, HIGH);
  digitalWrite(motorright2, LOW);
}

void goright(){
  motorspeed = 255;
  ledcWrite(motorrightEn, motorspeed);
  ledcWrite(motorleftEn, motorspeed);
  digitalWrite(motorleft1, HIGH);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, HIGH);
}

void stopcar(){
  digitalWrite(motorleft1, LOW);
  digitalWrite(motorleft2, LOW); 
  digitalWrite(motorright1, LOW);
  digitalWrite(motorright2, LOW);
}