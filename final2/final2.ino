#include<Servo.h>
Servo s1,s2;
int pos1=90, pos2=90;

int Mleftin1=3;
int Mleftin2=4;
int Mrightin1=5;
int Mrightin2=6;

int Mleften=10;
int Mrighten=11;
//int i;
//unsigned long int ptime=0;
//unsigned long int interval=5000;



void setup()
{
  pinMode(Mleftin1,OUTPUT);
  pinMode(Mleftin2,OUTPUT);
  pinMode(Mleften,OUTPUT); 
  pinMode(Mrightin1,OUTPUT);
  pinMode(Mrightin2,OUTPUT);
  pinMode(Mrighten,OUTPUT);
  s1.attach(8);
  s1.write(90);
  s2.attach(9);
  s2.write(90); 
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    char data;
    data=Serial.read();
    Serial.write(data);
    if(data=='D')moveForward();
    if(data=='R')moveBackward();
    if(data=='Q')moveRight();
    if(data=='E')moveLeft();
    if(data=='B'){pos1++;
    servo1();}
    if(data=='K'){pos1--;
    servo1();}
    if(data=='A'){pos2++;
    servo2();}
    if(data=='M'){pos2--;
    servo2();}
   
    if(data=='S')Stop();
    if(data=='G')moveForwardL30();
    if(data=='J')moveForwardR30();
    if(data=='W')moveSlowForward();
    
    
  }
}
void Stop()
{
 analogWrite(Mleften,0);
 analogWrite(Mrighten,0);
}
void moveForward()
{
  digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,255);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,255);
  
}
void moveBackward()
{
   digitalWrite(Mleftin1,LOW);
  digitalWrite(Mleftin2,HIGH);
  analogWrite(Mleften,255);
  digitalWrite(Mrightin1,LOW);
  digitalWrite(Mrightin2,HIGH);
  analogWrite(Mrighten,255);
}
void moveRight()
{
  digitalWrite(Mleftin1,LOW);
  digitalWrite(Mleftin2,HIGH);
  analogWrite(Mleften,255);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,255);
}
void moveLeft()
{
  digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,255);
  digitalWrite(Mrightin1,LOW);
  digitalWrite(Mrightin2,HIGH);
  analogWrite(Mrighten,255);
}


void moveForwardR30()
{
  
 digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,215);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,255); 
}
void moveForwardR60()
{
  digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,180);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,255);
}
void moveForwardL30()
{
  digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,255);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,215);
}
void moveForwardL60()
{
  digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,255);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,180);
}
void moveSlowForward()
{
  digitalWrite(Mleftin1,HIGH);
  digitalWrite(Mleftin2,LOW);
  analogWrite(Mleften,150);
  digitalWrite(Mrightin1,HIGH);
  digitalWrite(Mrightin2,LOW);
  analogWrite(Mrighten,150);
}
void servo1(){
  s1.write(pos1);
  }
  void servo2(){
  s2.write(pos2);
  }
