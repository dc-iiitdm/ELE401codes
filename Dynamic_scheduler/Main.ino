#include "Energia.h"
// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Platform not defined
#endif

#include <SPI.h>
#include "LCD_5110_SPI.h"

// Variables
/// P._. / PB_4 = SCK (2) = Serial Clock
/// P._. / PB_7 = MOSI (2) = Serial Data
#if defined(__MSP430G2553__)
LCD_5110_SPI myScreen;
#elif defined(__LM4F120H5QR__)
LCD_5110_SPI myScreen(PA_7,    // Chip Select
                      PB_2,    // Data/Command
                      PB_5,    // Reset
                      PA_6,    // Backlight
                      PUSH2);  // Push Button 2
#endif
boolean	backlight = false;
uint8_t k = 0;


char mime[]="i am ankith";
char inchar;
char msgstart[3]="#a";
char copyNUM[14];     //If anyone calls number will be stored in this.
String serveNUM;      //This is the number we have to send sms and ask him to come and use washing machine.
char extNUM[14] = "+919941319144";      //Person who is going to use it.This will be checked in keypad code.
int i=0;
int lookout=0;       //This is 1 when someone is using it.
int match=0;
const int buttonPin = PUSH2;  //This button is pressed when someone finishes the usage.
const int ledPin =  GREEN_LED; 
char validtxtmsg[] = "you are added to line in position ";
char txtMsg[]="Can wash clothes.COME IN 10 MIN";
char message[]="sry,OVERBOOKED,Kindly try after some time";
int usingm = 0;

//replies from webserver.
String reply1 = "junkjunkjunk";
String reply2 = "junkjunkjunk";
String reply3 = "junkjunkjunk";

//global varibales for keypad
String tempurl;
byte h=0,v=0;    //variables used in for loops
const unsigned long period=50;  //little period used to prevent error
unsigned long kdelay=0;        // variable used in non-blocking delay 
const byte rows=4;             //number of rows of keypad
const byte columns=4;            //number of columnss of keypad
const byte Output[rows]={PD_0, PD_1, PD_2, PD_3}; //array of pins used as output for rows of keypad
const byte Input[columns]={PA_2, PA_3, PA_4, PA_5}; //array of pins used as input for columnss of keypad
char comp[13];
int getVar=0;

//functions for keypad

byte keypad() // function used to detect which button is used 
{
 static bool no_press_flag=0;  //static flag used to ensure no button is pressed 
  for(byte x=0;x<columns;x++)   // for loop used to read all inputs of keypad to ensure no button is pressed 
  {
     if (digitalRead(Input[x])==HIGH);   //read evry input if high continue else break;
     else
     break;
     if(x==(columns-1))   //if no button is pressed 
     {
      no_press_flag=1;
      h=0;
      v=0;
     }
  }
  if(no_press_flag==1) //if no button is pressed 
  {
    for(byte r=0;r<rows;r++) //for loop used to make all output as low
    digitalWrite(Output[r],LOW);
    for(h=0;h<columns;h++)  // for loop to check if one of inputs is low
    {
      if(digitalRead(Input[h])==HIGH) //if specific input is remain high (no press on it) continue
      continue;
      else    //if one of inputs is low
      {
          for (v=0;v<rows;v++)   //for loop used to specify the number of row
          {
          digitalWrite(Output[v],HIGH);   //make specified output as HIGH
          if(digitalRead(Input[h])==HIGH)  //if the input that selected from first sor loop is change to high
          {
            no_press_flag=0;                //reset the no press flag;
            for(byte w=0;w<rows;w++) // make all outputs as low
            digitalWrite(Output[w],LOW);
            return v*4+h;  //return number of button 
          }
          }
      }
    }
  }
 return 50;
}
void display(String data,int i4)
{
     myScreen.begin();
     myScreen.setBacklight(backlight);
     myScreen.text(3,3,data);
}

void setupforkeypad() 
{
  for(byte i1=0;i1<rows;i1++)  //for loop used to make pin mode of outputs as output
  {
  pinMode(Output[i1],OUTPUT);
  }
  for(byte s=0;s<columns;s++)  //for loop used to makk pin mode of inputs as inputpullup
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
}

void keypadin()
{
  int correct;
  int temp4 = 2;
  while(getVar<13)
  {
  if(millis()-kdelay>period) //used to make non-blocking delay
  {
    String st;
    kdelay=millis();  //capture time from millis function
switch (keypad())  //switch used to specify which button
   {
            case 0:
            Serial.println(1);
            comp[getVar]='1';
            st = "1";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;  
            case 1:
            Serial.println(2);
             comp[getVar]='2';
              st = "2";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 2:
            Serial.println(0);
             comp[getVar]='0';
              st = "0";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 3:
            Serial.println("+");
             comp[getVar]='+';
              st = "+";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 4:
            Serial.println(4);
             comp[getVar]='4';
              st = "4";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 5:
            Serial.println(9);
             comp[getVar]='9';
              st = "9";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 6:
            Serial.println(8);
             comp[getVar]='8';
              st = "8";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 7:
            Serial.println("7");
             comp[getVar]='7';
              st = "7";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 8:
            Serial.println('w');
             comp[getVar]='q';
              st = "q";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 9:
            Serial.println(6);
             comp[getVar]='6';
              st = "6";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 10:
            Serial.println(5);
             comp[getVar]='5';
              st = "5";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 11:
            Serial.println("4");
             comp[getVar]='4';
              st = "4";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 12:
            Serial.println("+");
             comp[getVar]='+';
              st = "+";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 13:
            Serial.println(3);
             comp[getVar]='3';
              st = "3";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 14:
            Serial.println("2");
             comp[getVar]='2';
              st = "2";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            case 15:
            Serial.println("1");
             comp[getVar]='1';
             st = "1";
            display(st,temp4);
            getVar=getVar+1;temp4++;
       break;
            default:
            ;
}

}
  }
  Serial.println("came here after keypad input.");
  Serial.println(getVar);
if(getVar==13)
{
  correct = 0;
  Serial.println(comp);
  int mn=0;
  while(mn<14)
  {
    if(comp[mn]==extNUM[mn])
    {
     correct=correct+1; 
    }
    mn=mn+1;
  }
  if(correct==14)
  {
    match=1;
  }
  else
  {
   match=2; 
  }
  Serial.println(correct);
  getVar=0;
}
}

void ShowSerialData()
{
  while(Serial1.available()!=0)
    Serial.write(char (Serial1.read()));
}

// The below code is regarding HTTPRequest to web server


void gsmInit(){
  Serial1.println("AT+CSQ"); // Signal quality check

  delay(100);
 
  ShowSerialData();// this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.
  
  Serial1.println("AT+CGATT?"); //Attach or Detach from GPRS Support
  delay(100);
 
  ShowSerialData();
  Serial1.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);
 
  ShowSerialData();
 
  Serial1.println("AT+SAPBR=3,1,\"APN\",\"aircelgprs.po\"");//setting the APN, Access point name string
  delay(4000);
 
  ShowSerialData();
 
  Serial1.println("AT+SAPBR=1,1");//setting the SAPBR
  delay(2000);
 
  ShowSerialData();
}
String HTTPRequest(String link)
{
  
  Serial1.println("AT+HTTPINIT"); //init the HTTP request
 
  delay(4000); 
  ShowSerialData();
 
  Serial1.println("AT+HTTPPARA=\"URL\","+link);// setting the httppara, the second parameter is the website you want to access
  delay(1000);
 
  ShowSerialData();
 
  Serial1.println("AT+HTTPACTION=0");//submit the request 
  delay(25000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
  //while(!Serial1.available());
 
  ShowSerialData();
 
  Serial1.println("AT+HTTPREAD");// read the data from the website you access
  delay(300);
  String content = "";
  // String RedState = content.substring();
  while(Serial1.available()!=0)
  {  
    //Serial.write(Serial1.read());
    content = content + String(char (Serial1.read()));
  }
  Serial.println("first time content(28):");
  Serial.println(content.substring(28));
  Serial.println("first time content:");
  Serial.println(content);
  Serial.println("second time content(28):");
  Serial.println(content.substring(28));        //added to test the content value.
  ShowSerialData();
  return content.substring(28);
}


void Msg_Receiver_Init(){
  Serial1.print("AT+CLIP=1\r");
  ShowSerialData();
  delay(1000);  
  Serial1.print("AT+CNMI=2,2,0,0,0\r");
  ShowSerialData();
  delay(100);
  Serial.println("Ready...");
}

void Screen()
{ myScreen.begin();
    
    myScreen.setBacklight(backlight);
    myScreen.text(1, 2, mime);
    
    delay(1000);
}
  
void getSMS()
{
 
  Msg_Receiver_Init();
  if(Serial1.available() >0)
 {  
   Serial.println("came into first if:");
   
   inchar=Serial1.read();
   int j2 = 0;
    while(inchar != '#')
    {
      inchar=Serial1.read();
    }
   if (inchar==msgstart[0])
   {
     Serial.println("came into second if:");
     delay(100);
     inchar=Serial1.read();
      if (inchar==msgstart[1])
      {
     
     while(i<14)
     {
     inchar=Serial1.read();
    
      copyNUM[i]=inchar;
     
        i=i+1;
      delay(100);
     }
    }
   }

}
}

void sendSMS(String num,String msg)
{
   Serial.println("came into sendSMS");
   Serial1.print("AT+CMGF=1\r");
   delay(100);
   ShowSerialData();
   Serial1.print("AT + CMGS = \"");
   Serial1.print(num);
   Serial1.println("\"");
   delay(100);
   ShowSerialData();
   Serial1.println(msg);
   delay(100);
   
   Serial1.println((char)26);
   delay(100); 
   
   Serial1.println();
   delay(5000);
}

void setup()
{
  
  pinMode(PB_3,OUTPUT);
  digitalWrite(PB_3,HIGH);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.setBitOrder(MSBFIRST);
  setupforkeypad();
  Serial.begin(19200);
  Serial1.begin(19200);
  delay(5000);
  gsmInit();
  
}


void loop()
{
  /*
  if(usingm == 0)
  {
    tempurl = "http://embeddedcoe.esy.es/persontobeserved.php";
    reply1 = HTTPRequest(tempurl);
    Serial.println(reply1.substring(1,6));
    Serial.println("finished");
    if(reply1.substring(1,6) == "valid")
    {
      Serial.println("came here");
      reply1.substring(6).toCharArray(extNUM,14);
      sendSMS(extNUM,"you can come and use the washing machine.");
      lookout = 1;
      usingm =1;
    }
  }
  */

  getSMS();
  if(i==14)
{
  Serial.println("This is the number");
  Serial.println(copyNUM);
  tempurl = "http://embeddedcoe.esy.es/getstateofnumber.php?phone=";
  String temp2(copyNUM);
  reply2 = HTTPRequest(tempurl + temp2.substring(1));
  String ms = validtxtmsg+reply2.substring(5,6)+".You will get a message when your turn comes.";
  sendSMS("+917299102503",ms);
}
 /*
 if(reply2.substring(0,6) == "valid")
  {
    String ms = validtxtmsg+reply2.substring(5,6)+".You will get a message when your turn comes.";
    sendSMS(reply2.substring(6,19),ms);
    Serial.println("this is the number:");
    Serial.println(copyNUM);
  }
else if(reply2.substring(0,6) != "junkj")
  {
  sendSMS(copyNUM,"line is full try after some time.");
  }
  i=0;
}
*/

//Serial.println("waiting");
//delay(10000);
//if (buttonPin==HIGH)
//{
  /*
  Serial.println("call next one");
  digitalWrite(ledPin, LOW);
  usingm = 0;
  myScreen.clear();
  tempurl = "http://embeddedcoe.esy.es/finish.php";
  reply3 = HTTPRequest(tempurl);
  digitalWrite(ledPin, LOW);
  Serial.println(reply3.substring(0,6));
  sendSMS("+917299102503","Your turn has come.you can come and use wm");
  /*if(reply3.substring(0,6) == "valid")
  {
     reply3.substring(6).toCharArray(extNUM,14);
     sendSMS(extNUM,"You can come and use the washing machine.");
     lookout=1;
     usingm = 1;
  }
 */
//}

/*
lookout=1;
if(lookout==1)
{   
    //delay(10000);
    Serial.println("cam e here");
    display("Enter your pin:",1);
    keypadin();
    delay(1000);
    if(match==1)
    {
     myScreen.begin();
     myScreen.setBacklight(backlight);
     myScreen.text(1, 2,"Press sw2 when your use is over");
     digitalWrite(ledPin, HIGH);// GREEN LED ON INDICATES WM IN USE
     delay(1000);
     lookout=0;
     match=0;
    }
    else if(match==2)
    {
     myScreen.begin();
     myScreen.setBacklight(backlight);
     myScreen.text(1, 2,"Kindly enter the correct Phone number");
     delay(9000);
     myScreen.clear();
     match=0;
    }
  }
  */
}





