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
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    char data;
    data=Serial.read();
    Serial.write(data);
    if(data=='G')moveForward();
    if(data=='R')moveBackward();
    if(data=='E')moveRight();
    if(data=='Q')moveLeft();
   
    if(data=='S')Stop();
    if(data=='A')moveForwardL60();
    if(data=='D')moveForwardL30();
    if(data=='J')moveForwardR30();
    if(data=='K')moveForwardR60();

    
    
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
  analogWrite(Mleften,125);
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
