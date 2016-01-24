int i;
int j;
int currentvalue[30];
int val;


  int tag1=12345;
   String s;
 String s1;
int a;

void setup()
{
  
  Serial1.begin(19200);
  Serial.begin(19200);
  

  Serial.println("Config SIM900...");
  delay(2000);
  Serial.println("Done!...");
  Serial1.flush();
  Serial.flush();

  // attach or detach from GPRS service 
 Serial1.println("AT+CGATT?");
  delay(100);
  toSerial();


  // bearer settings
  Serial1.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  toSerial();

  // bearer settings
 Serial1.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
  delay(2000);
  toSerial();

  // bearer settings
  Serial1.println("AT+SAPBR=1,1");
  delay(2000);
  toSerial();
  
  i=5;
j=1;

}

void readinput()
{
  Serial.println("readinput"); 
  if(val==1)
  {
  i=30;
  while(i>0)
  {
    currentvalue[i-1]=analogRead(PE_4);
    delay(2);      // 6 points in half waveform for 50 Hz sine wave
   
    
     Serial.println(currentvalue[i-1]);
    Serial.println(" , ");
    s1 += currentvalue[i-1] ;
    s1 +="$";
    i=i-1;
  }
  }
  else
   {
  i=10;
  while(i>0)
  {
    currentvalue[i-1]=analogRead(PE_5);
    delay(2);      // 6 points in half waveform for 50 Hz sine wave
   
    
     Serial.println(currentvalue[i-1]);
    Serial.println(" , ");
    s1 += currentvalue[i-1] ;
    s1 +="$";
    i=i-1;
  }
  }
  
 
}


void loop()
{

  
if(val==1)
val=0;              //read temp
else
val=1;          //read current
    
    readinput();
    
    //  Serial.println("dosomethingreached345"); 
   // initialize http service
   Serial1.println("AT+HTTPINIT");
   delay(2000); 
   toSerial();

   // set http param value
//gprsSerial.println("AT+HTTPPARA=\"URL\",\"http://adarshshrivastava.tk/embed/pass.php?tag=1018&data=443.644\"");


Serial.println(s1);
s = "AT+HTTPPARA=\"URL\",\"http://adarshshrivastava.tk/embed/pass.php?tag=";
   s += 12345;
   if (val==1)
   s +=0;        //current
  else
    s +=1;
   s += "&data=";
   s += s1;
   s += "\"";
    Serial1.println(s);
   s1="";
    
    
   delay(2000);
  toSerial();
    toSerial();
    

   // set http action type 0 = GET, 1 = POST, 2 = HEAD
   Serial1.println("AT+HTTPACTION=0");
   delay(6000);
   toSerial();

   // read server response
   Serial1.println("AT+HTTPREAD"); 
   delay(1000);
   toSerial();

   Serial1.println("");
   Serial1.println("AT+HTTPTERM");
   toSerial();
   delay(300);

   Serial1.println("");
   delay(10000);


}

void toSerial()
{
  while(Serial1.available()!=0)
  {
    Serial.write(Serial1.read());
  }
}
