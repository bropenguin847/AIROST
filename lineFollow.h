int irleft = 18;
int irright = 19;
int leftside, rightside;

void setupIR(){
  pinMode(irleft, INPUT);
  pinMode(irright, INPUT);
}

void reading(){
  leftside = analogRead(irleft);
  rightside = analogRead(irright);
  Serial.println(leftside);
  Serial.println(rightside);
}