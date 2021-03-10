int joy_x = 0;
int joy_y = 1;
int val1,val0;
double r,degree_joy,x,y;

int a,b;
byte value = B00000000;
float degree_rotary = 0.00;



void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val0 = analogRead(joy_x);
  val1 = analogRead(joy_y);   //ジョイコンから読み取り

    a=digitalRead(5);
    b=digitalRead(3);
    Serial.print(a);
    Serial.print(" , ");
    Serial.print(b);
    Serial.println("");

  val0=val0-528;
  val1=val1-520;

  x=(double)val0;
  y=(double)val1;

  r=sqrt(pow(x,2)+pow(y,2));
  degree_joy=180*atan2(y,x)/PI;

  Serial.print(r);
  Serial.print(" , ");
  Serial.println(degree_joy);

if(-50<degree_joy&degree_joy<50){
  if(r<490){
    Serial.println("XXX");
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    
    a=digitalRead(5);
    b=digitalRead(3);

    
  /*Serial.print(a);
    Serial.print(" , ");
    Serial.print(b);
    Serial.print("  ");*/
  }else{
   /* Serial.print("s,");
    Serial.print(val0, DEC);
    Serial.print(',');
    Serial.print(val1, DEC);
    Serial.print(',');
    Serial.print(n,DEC);
    Serial.println(',');*/
    
  value = (value<<2)+(digitalRead(5)<<1)+digitalRead(3);
  value = value & B00001111;
   if(value==B00000001||value==B00000111||value==B00001110||value==B00001000){
    degree_rotary = degree_rotary+3.75;
    }else if(value==B00000010||value==B00001011||value==B00001101||value==B00000100)
    {
    degree_rotary = degree_rotary-3.75;
    }
  
  if(degree_rotary>180){
    degree_rotary = degree_rotary-360;
  }else if(degree_rotary<=-180){
    degree_rotary = degree_rotary+360;
  }
  
  Serial.print("degree: ");
  Serial.println(degree_rotary);   //feedback
 
  if(degree_rotary-5>degree_joy){
    digitalWrite(6,HIGH);
    digitalWrite(4,LOW);    
   
    a=digitalRead(5);
    b=digitalRead(3);
    
    
   /* Serial.pridegree_joyt("HL 時計回り :");
    Serial.print(a);
    Serial.print(" , ");
    Serial.print(b);
    Serial.print("   ");*/

      }else if(degree_rotary+5<degree_joy){
    digitalWrite(4,HIGH);
    digitalWrite(6,LOW);
    
    a=digitalRead(5);
    b=digitalRead(3);

    
   /*Serial.print("LH　反時計回り :");
     Serial.print(a);
     Serial.print(" , ");
     Serial.print(b);
     Serial.print("  ");*/

      }else{
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    
    a=digitalRead(5);
    b=digitalRead(3);

    
   /*Serial.print(a);
    Serial.print(" , ");
    Serial.print(b);
    Serial.print("  ");*/
        }
  }
}else{
   digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    
    a=digitalRead(5);
    b=digitalRead(3);

    
   /*Serial.print(a);
    Serial.print(" , ");
    Serial.print(b);
    Serial.print("  ");*/
  }
}
