#include <Arduino.h>
#include <sstream>
#include <iomanip>
void setup() {
 Serial.begin(115200);
}
void loop() {
 int iVal;

 iVal = analogRead(A0);
 long mVal = map(iVal,0,1024,0,5000);
 float dVal = (float)mVal /(float)100;
 String judgement = "";
 if (dVal<10){
  judgement = "Cold!";
 }else if(dVal >= 10 && dVal<15){
  judgement = "Cool";
 }else if(dVal >= 15 && dVal<25){
  judgement = "Perfect";
 }else if(dVal >= 25 && dVal<30){
  judgement = "Warm";
 }else if(dVal >= 30 && dVal<35){
  judgement = "Hot";
 }else{
  judgement = "Too Hot!";
 }

 Serial.println("Digitized output of "+ (String)iVal+"is equivalent to a temperature input of " + (String)dVal + " deg. C, which is "+judgement);

 delay(2000);
}