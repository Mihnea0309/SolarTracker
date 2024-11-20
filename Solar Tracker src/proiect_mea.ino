#include <Servo.h>

Servo base;
Servo top;

int reztr;
int rezdr;
int rezdl;
int reztl;
int min=200;
int xtr;
int xtl;
int xdr;
int xdl;


void setup() {
  base.attach(2);
  top.attach(3);
  Serial.begin(9600);
  top.write(0);
  base.write(0);
  reztl = analogRead(A2);
  rezdl = analogRead(A3); 
  reztr = analogRead(A4);
  rezdr = analogRead(A5); 

  reztr = map(reztr, 0, 1023, 0, 180);
  rezdr = map(rezdr, 0, 1023, 0, 180);
  rezdl = map(rezdl, 0, 1023, 0, 180);
  reztl = map(reztl, 0, 1023, 0, 180);
  if(reztr<min)
  {
    min = reztr;
  }
  if(reztl<min)
  {
    min = reztl;
  }
  if(rezdl<min)
  {
    min = rezdl;

  }
  if(rezdr<min)
  {
    min = rezdr;
  }
  xtr = reztr - min;
  xtl = reztl - min;
  xdl = rezdl - min;
  xdr = rezdr - min;


}

void loop() {
  reztl = analogRead(A2);
  rezdl = analogRead(A3); 
  reztr = analogRead(A4);
  rezdr = analogRead(A5); 

  reztr = map(reztr, 0, 1023, 0, 180);
  rezdr = map(rezdr, 0, 1023, 0, 180);
  rezdl = map(rezdl, 0, 1023, 0, 180);
  reztl = map(reztl, 0, 1023, 0, 180);

  reztr = reztr - xtr;
  reztl = reztl - xtl ;
  rezdl = rezdl - xdl;
  rezdr = rezdr - xdr;

  int avgT = (reztr + reztl)/2;
  int avgB = (rezdl + rezdr)/2;
  int avgL = (reztl + rezdl)/2;
  int avgR = (reztr + rezdr)/2;

  Serial.print("tr: ");
  Serial.println(reztr);
  Serial.print("tl: ");
  Serial.println(reztl);
  Serial.print("dr: ");
  Serial.println(rezdr);
  Serial.print("dl: ");
  Serial.println(rezdl);

  if (avgT != avgB) {
    UpDown(avgT, avgB);
  }
  if (avgL != avgR) {
    LeftRight(avgL, avgR);
  }

  delay(100);
}

void UpDown(int avgT, int avgB){
  int pos1= top.read();
  Serial.print("pos1 initial: \n");
  Serial.println(pos1);    
  if(avgT > avgB){
     pos1 = --pos1;
     Serial.print("Coboara \n");
    }
  	 else
     {
      pos1 = ++pos1;
      Serial.print("Urca \n");
     }
  pos1 = constrain(pos1, 0, 170);
  top.write(pos1);
  Serial.print("pos1 final: \n");
  Serial.println(pos1);

}

void LeftRight(int avgL, int avgR){
  int pos2= base.read();
  if(avgL > avgR)
   { 
    pos2 = --pos2;
    Serial.print("dreapta \n");
   }
  	else
    {
     pos2 = ++pos2;
     Serial.print("stanga \n");
    }
  pos2 = constrain(pos2, 0, 180);
  base.write(pos2);
}