int joy_x = 0;
int joy_y = 1;
int val0,val1;
double r;
double n;
double x,y;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val0 = analogRead(joy_x);
  val1 = analogRead(joy_y);

  val0=val0-528;
  val1=val1-520;

  x=(double)val0;
  y=(double)val1;

  r=sqrt(pow(x,2)+pow(y,2));
  if(r<490)
  Serial.println("XXX");
  else{
  n=180*atan2(y,x)/PI;
  
  Serial.print("s,");
  Serial.print(val0, DEC);
  Serial.print(',');
  Serial.print(val1, DEC);
  Serial.print(',');
  Serial.print(n,DEC);
  Serial.println(',');


  delay(50);
  } 
}
