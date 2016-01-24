#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"
#include "EEPROM.h"
#include "LiquidCrystal.h"

// Hardware setup - FPS connected to:
//    digital pin 4(arduino rx, fps tx)
//    digital pin 5(arduino tx - 560ohm resistor - fps tx - 1000ohm resistor - ground)
//    this voltage divider brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps(8, 9);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 int inPin1 = 0;
 int inPin2 = 1;
 int inPin3 = 6;
 int inPin4 = 7;
 int inPin5 = 13;
 
 int enroll = 0;
 int enrolled = 0;
 int set_day = 0;
 int set_month = 0;
 int last_address;
 int attendance;
 int erase_memory;
 int k;
 int load;

void setup()
{
  Serial.begin(9600);
  delay(100);
  fps.Open();
  fps.SetLED(true);
  lcd.begin(16, 2);
}


void loop()
{  
  enroll = digitalRead(inPin4);
  set_day = digitalRead(inPin1); 
  set_month = digitalRead(inPin2);
  load = digitalRead(inPin5);
  
  if (enroll == HIGH)
  Enroll();

  if (set_day == HIGH)
  set_date ();

  if (set_month == HIGH)
  set_date (); 

  if (load == HIGH)
  loaddata ();
  
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id <200)
    {
      lcd.clear();
      lcd.print("Verified ID:");
      lcd.print(id);      
      last_address = EEPROM.read(252); 
      k = last_address+2+id;
      attendance = EEPROM.read(k);
      if (attendance != 1)
      EEPROM.write(k,1);   
      delay(500);  
    }
    else
    {
      lcd.clear();
      lcd.print("Finger not found");
    }
  }
  else
  {
    lcd.clear();
    lcd.print("Press finger");
  }
  
  delay(1000);
}


void Enroll()
{  
  // Enroll test
 
  // find open enroll id
  
  int enrollid = 0;
  bool okid;
  okid = !(fps.CheckEnrolled(enrollid));
  while (okid == false)
  {
    enrollid++;
    okid = !(fps.CheckEnrolled(enrollid));
  }
  fps.EnrollStart(enrollid);

  // enroll
  lcd.clear();
  lcd.print("Enroll #");
  lcd.print(enrollid);
  
  while(fps.IsPressFinger() == false)   
  {
    delay(100);
    enroll = digitalRead(inPin4);
    if(enroll==LOW)
    {
    return;
    }
  }

  bool bret = fps.CaptureFinger(true);
  int iret = 0;
  if (bret != false)
  {
    lcd.clear();
    lcd.print("Remove finger");
    fps.Enroll1(); 
    while(fps.IsPressFinger() == true) delay(100);
    lcd.clear();
    lcd.println("Press same finger");
    while(fps.IsPressFinger() == false) delay(100);
    bret = fps.CaptureFinger(true);
    if (bret != false)
    {
      lcd.clear();
      lcd.print("Remove finger");
      fps.Enroll2();
      while(fps.IsPressFinger() == true) delay(100);
      lcd.clear();
      lcd.print("Press same finger");
      while(fps.IsPressFinger() == false) delay(100);
      bret = fps.CaptureFinger(true);
      if (bret != false)
      {
        lcd.clear();
        lcd.print("Remove finger");
        iret = fps.Enroll3();
        if (iret == 0)
        {
          lcd.clear();
          lcd.print("Enrolling Successfull");
          enrolled = EEPROM.read(255);
          enrolled++;
          EEPROM.write(255,enrolled);
        }
        else
        {
          lcd.clear();
          lcd.print("Enrolling Failed with error code:");
          lcd.print(iret);
        }
      }
      else 
      {
      lcd.clear();
      lcd.print("Failed to capture third finger");
      }
    }
    else
    {
    lcd.clear();
    lcd.print("Failed to capture second finger");
    }
  }
  else 
  {
  lcd.clear();
  lcd.print("Failed to capture first finger");
  }
  delay(500);
}

void set_date()
{

 int last_day;
 int last_month;
 int set;
 int day;
 int month;
 int address;
 int i;

 day = EEPROM.read(253);
 month = EEPROM.read(254);

 delay(500);
 
 set_day = digitalRead(inPin1); 
 set_month = digitalRead(inPin2);
 set = digitalRead(inPin3);

  
lcd.clear();
lcd.print(day);
lcd.print("/");
lcd.println(month);
 

 while(set_day == HIGH)
{
  
 if (day <= 30)
 {
  day++;
 }
 else
 {
 day = 1;
 }
 
  lcd.clear();
  lcd.print(day);
  lcd.print("/");
  lcd.print(month);
  delay(1000);
  set_day = digitalRead(inPin1); 
  }
  

 while(set_month == HIGH)
{
 if (month <= 11)
 {
  month++;
 }
 else
 {
 month = 1;
 }
 
 lcd.clear();
 lcd.print(day);
 lcd.print("/");
 lcd.print(month);
 delay(1000);
 set_month = digitalRead(inPin2);
  }

if (set == HIGH)
{
last_day = EEPROM.read(253);
last_month = EEPROM.read(254);

if (last_day != day)
{
//EEPROM.write(253,day);
}

if (last_month != month)
{
//EEPROM.write(254,month);
}

last_address = EEPROM.read(252);
enrolled = EEPROM.read(255);
address = last_address + enrolled + 2;
k = address+1;
//EEPROM.write(address,day);
//EEPROM.write(address+1,month);
for(i=k+1;i<=k+enrolled;i++)
{
// EEPROM.write(i,0);
 }

lcd.clear();
lcd.print("Date set to");
lcd.print(day);
lcd.print("/");
lcd.print(month);
}

 }

void loaddata()
{
  int i;
  int data;
  
  delay(5000);
  
  load = digitalRead(inPin5);
  if (load == HIGH)
  {
    lcd.clear();
    lcd.print("Sending data");

    for(i=0; i<=255; i++)
    {
      data = EEPROM.read(i);
      Serial.println(data);
      delay(100);
      }
    }


    erase_memory = digitalRead(inPin3);

    if (erase_memory == HIGH)
    {
      lcd.clear();
      lcd.print("Erase memory?");
      delay(5000);
      erase_memory = digitalRead(inPin3);
    
    if (erase_memory == HIGH)
    {
      lcd.clear();
      lcd.print("Erasing memory");
      for(i=0; i<=255; i++)
    {
      data = EEPROM.read(i);
      if (data != 255)
      {
        EEPROM.write(i, 255);
        }
      }
    }
  }
}
