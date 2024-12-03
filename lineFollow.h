int irleft = 18;
int irright = 19;
int leftside, rightside;

void setupIR(){
  pinMode(irleft, INPUT);
  pinMode(irright, INPUT);
}

void reading(){
  leftside = digitalRead(irleft);
  rightside = digitalRead(irright);
  Serial.print(leftside);
  Serial.println(rightside);
  delay(100);
}