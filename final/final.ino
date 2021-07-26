#include<Servo.h>
#define left1  3
#define left2  4
#define leften  10

#define right1  5
#define right2  6
#define righten  11

String state = ""; 

Servo center, left, right;
int a=90, c=90, l=90, r=90, ml=0, mr=0 , s=0;



void setup()
{
  center.attach(9);
  left.attach(13);
  right.attach(12);
  pinMode(left1,OUTPUT);
  pinMode(left2,OUTPUT);
  pinMode(leften,OUTPUT); 
  pinMode(right1,OUTPUT);
  pinMode(right2,OUTPUT);
  pinMode(righten,OUTPUT); 
  Serial.begin(9600);

}
void loop()
{
  if(Serial.available()>0)
  
  {
    char data;
    data=Serial.read();
    /*Serial.write(data);*/
    Serial.println(' ');
    if(data=='s') 
    {
      movestop();
      Serial.println('s');
    }
    a= state.toInt();
    if(a>=0 && a<=180)
    {
      ml=s*sqrt(2)*cos(a-45);
      mr=s*sqrt(2)*sin(a-45);
      Serial.print(ml);
      Serial.println(mr);
      if(ml<0)
      {
        ml=-ml;
        digitalWrite(left1, LOW);
        digitalWrite(left2, HIGH);
        analogWrite(leften, ml);
      }
      else
      {
        digitalWrite(left1, HIGH);
        digitalWrite(left2, LOW);
        analogWrite(leften, ml); 
      }
      if(mr<0)
      {
        mr=-mr;
        digitalWrite(right1, LOW);
        digitalWrite(right2, HIGH);
        analogWrite(righten, mr);
      }
      else
      {
        digitalWrite(right1, HIGH);
        digitalWrite(right2, LOW);
        analogWrite(righten, ml); 
      }
    }
    else if(a>-180 && a<0)
    {
      ml=-(s*sqrt(2)*cos(a+45));
      mr=s*sqrt(2)*sin(a+45);
      Serial.print(ml);
      Serial.println(mr);
     if(ml<0)
      {
        ml=-ml;
        digitalWrite(left1, LOW);
        digitalWrite(left2, HIGH);
        analogWrite(leften, ml);
      }
      else
      {
        digitalWrite(left1, HIGH);
        digitalWrite(left2, LOW);
        analogWrite(leften, ml); 
      }
      if(mr<0)
      {
        mr=-mr;
        digitalWrite(right1, LOW);
        digitalWrite(right2, HIGH);
        analogWrite(righten, mr);
      }
      else
      {
        digitalWrite(right1, HIGH);
        digitalWrite(right2, LOW);
        analogWrite(righten, ml); 
      } 
    }
    else if(a>=200 && a<=455)
    {
      s=a-200;
      Serial.println(s);
    }
    
    if(data=='l') moveleft();
    else if(data=='r') moveright();
    else if(data=='u') moveup();
    else if(data=='d') movedown(); 
      
  }
}
void movestop()
{
  digitalWrite(left1, LOW);
  digitalWrite(left2, LOW);
  digitalWrite(right1, LOW);
  digitalWrite(right2, LOW);
  center.write(c);
  left.write(l);
  right.write(r);
  delay(10);
}
void moveleft()
{
  r++;
  l--;
  left.write(l);
  right.write(r);
  delay(10);
}
void moveright()
{
  r--;
  l++;
  left.write(l);
  right.write(r);
  delay(10);
}
void moveup()
{
  c--;
  center.write(c);
}
void movedown()
{
  c++;
  center.write(c);
}
