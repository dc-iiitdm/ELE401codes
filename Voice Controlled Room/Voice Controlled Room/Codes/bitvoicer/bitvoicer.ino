/*
   A.V.S.SAI BHARGAV KUMAR(EDM12B007)
   D. NAVEEN BABU(EDM12B009)
   S. BALASUBRAMANYAM(COE12B026)
*/
#include "BitVoicer11.h"
BitVoicerSerial bvSerial = BitVoicerSerial();

// Store the data type received by getData();

byte dataType = 4;
// create an array for all of the outputpins 
int OutPutPins[] ={2,3,4,5,6,7,8,9,10,11,12,13};// assign the output pins 
int pinCount = 6;


void setup() {
  // put your setup code here, to run once:
  // start serial communication at 9600
  Serial.begin(9600);
  // loop to set all the pins as outputs
 for(int activePin = 6 ; activePin < 13; activePin ++){
    pinMode(OutPutPins[activePin],OUTPUT);
 }
  for(int activePin = 6 ; activePin < pinCount; activePin ++){
    pinMode(OutPutPins[activePin],INPUT);
 }
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
}
// this function runs every time serial data is aviable .
// in the serial buffer after the loop.
void serialEvent()
{
   // Reads the serial bugger and stores the received data type.
   dataType = bvSerial.getData();
   Serial.println("data is received");
   
   // check if the data type is the same as the one in coming from bitvoicer
   if (dataType == BV_INT)
   {
     // the way that this is set up will avoid a bunch of if/else statements for the majaority of the outputs.
     // assign an INT to hold a pin number
     int pinNumber = bvSerial.intData;
     // Write to the pinNumber based on the current state of the output and reverse it.
     digitalWrite(pinNumber, !digitalRead(pinNumber));
     delay(50);  
   }  
   
   // if data type is string do something a little bit different.
   
   if(dataType == BV_STR)
   {
     if (bvSerial.strData == "onfan")
     {
        digitalWrite(2, HIGH);
        
     }
     else if (bvSerial.strData == "offfan")
     {
         digitalWrite(2, LOW);
     }
     else if (bvSerial.strData == "onlight")
     {
         digitalWrite(3, HIGH);
         
     }
     else if (bvSerial.strData == "offlight")
     {
        digitalWrite(3, LOW);
        
     }
     else if (bvSerial.strData == "opendoor")
     {
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(3000);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
     }  
     else if (bvSerial.strData == "closedoor")
     {
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(3000);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        
     }     

     else if (bvSerial.strData == "opencurtian")
     {
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        delay(3000);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
     }
     else if (bvSerial.strData == "closecurtian")
     {
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(3000);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        
     }

 }  
  
}
