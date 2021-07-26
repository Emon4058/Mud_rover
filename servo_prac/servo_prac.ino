#include<Servo.h>
Servo servo1;
int pos1=0;
void setup() {
  servo1.attach(9);
}

void loop() {
  
  for(pos1=0;pos1<120;pos1++){
    servo1.write(pos1);
    delay(90);
    }
    for(pos1=120;pos1>0;pos1--){
    servo1.write(pos1);
    delay(90);
    }
  /*if(c==1){
    one.write(a);
    two.write(b);
    c++;
    }

    if(Serial.available()>0)
    {
      char d;
      d=Serial.read();
      Serial.println(d);
      if(d=='G')
      {
        a++;
        one.write(a);
      }
      if(d=='R')
      {
        a--;
        one.write(a);
      }
      if(d=='E')
      {
        b++;
        two.write(b);
      }
      if(d=='Q')
      {
        b--;
        two.write(b);
      }
    }*/
    
} 
