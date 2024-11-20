int motorleft1 = 27;
int motorleft2 = 26;
int motorleftEn = 14;

int motorright1 = 25;
int motorright2 = 33;
int motorrightEn = 32;

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