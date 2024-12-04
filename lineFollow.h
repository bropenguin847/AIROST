int irleft = 17;
int irright = 16;
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