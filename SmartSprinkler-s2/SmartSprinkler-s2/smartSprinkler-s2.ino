***************************--------------------------------------*******************************
***************************__________Smart Sprinkler_____________*******************************
***************************--------------------------------------*******************************
***************************_______________s2_____________________*******************************
***************************--------------------------------------*******************************

By:

Kuldeep Gunta    COE12B012
Kapil Gupta      COE12B010
Avinash Devarla  EDM12B010


**************************--------------------------------------********************************



#include "SPI.h"             // included in energia libraries by default
#include "LCD_5110_SPI.h"    // should be included into energia library exteranlly

// Variables
/// P._. / PB_4 = SCK (2) = Serial Clock
/// P._. / PB_7 = MOSI (2) = Serial Data

#if defined(__MSP430G2553__)
LCD_5110_SPI myScreen;
#elif defined(__LM4F120H5QR__)
LCD_5110_SPI myScreen(PA_7,    // Chip Select
                      PA_2,    // Data/Command
                      PB_5,    // Reset
                      PA_6,    // Backlight
                      PUSH2);  // Push Button 2
#endif

#define OpenValve1 PC_7 								// Digital Output - HIGH:Open, LOW:Close
#define OpenValve2 PC_6 								// Digital Output - HIGH:Open, LOW:Close
#define OpenValve3 PC_5 								// Digital Output - HIGH:Open, LOW:Close

#define MoistureSensor1 PE_2   							// Analog Input - Ain1 
#define MoistureSensor2 PE_1   							// Analog Input - Ain2
#define MoistureSensor3 PE_0                    		// Analog Input - Ain3

#define ThresholdValue1 3500							// >(ThresholdValue): Dry, <(ThresholdValue): Wet Enough
#define ThresholdValue2 3500							// >(ThresholdValue): Dry, <(ThresholdValue): Wet Enough
#define ThresholdValue3 3500							// >(ThresholdValue): Dry, <(ThresholdValue): Wet Enough

#define ValveOpenTime 60000								// Time for which the valve is to be opened - Minutes*60*1000.
#define CheckMoistureTime 60000							// Time interval between consecutive soil moisture checks - Minutes*60*1000.

char RunMode='A';										// A: Completely Automatic - Valve turns on/off automatically.
														// S: Semi-Automatic - Valve turns-on when user triggers, but turns-off automatically after specific time.
														// M: Manual - Valve turns on/off only when the user triggers appropriately.
														// Defult mode is completely automatic: A.
String ToPhoneNumber="+919551957840";
String Message="";
String TimeStamp="";

void get_time_stamp()
{
        Serial.println("Time Stamp");
	//	Serial1.print("AT+CCLK?");      //SIM900 AT command to get time stamp
	// 	//Serial1.print(13,BYTE);
	// 	delay(100);
	// 	if (Serial1.available()>0)
	// 	{	
	// 		TimeStamp = "";
	//     	while (Serial1.available()>0)
	//     	{
	//     		TimeStamp += Serial2.read();
	//     	}
	//    }

  	TimeStamp = "HAI";
}

void send_sms()
{
   Serial.println("Send SMS");
   Serial.println(ToPhoneNumber);
   Serial.print("Message :");
   Serial.println(Message);
   Serial1.print("AT+CMGF=1\r");
   delay(100);
   Serial1.print("AT + CMGS = \"");
   Serial1.print(ToPhoneNumber);
   Serial1.println("\"");
   delay(100);
   Serial1.println(Message);
   delay(100);
   Serial1.println((char)26);
   delay(100); 
   Serial1.println();
   delay(5000);
}

void on_valve()
{
    Serial.println("Func ON Valve");
 	if(digitalRead(OpenValve1) == HIGH)
	{
		digitalWrite(OpenValve1, HIGH);
		Message += "Valve 1 :Already On\n";
	}
	else
	{
		digitalWrite(OpenValve1, HIGH);
		Message += "Valve 1 :On Now\n";
	}

	if(digitalRead(OpenValve2) == HIGH)
	{
		digitalWrite(OpenValve2, HIGH);
		Message += "Valve 2 :Already On\n";
	}
	else
	{
		digitalWrite(OpenValve2, HIGH);
		Message += "Valve 2 :On Now\n";
	}

	if(digitalRead(OpenValve3) == HIGH)
	{
		digitalWrite(OpenValve3, HIGH);
		Message += "Valve 3 :Already On\n";
	}
	else
	{
		digitalWrite(OpenValve3, HIGH);
		Message += "Valve 3 :On Now\n";
	}
}

void off_valve()
{
  
    Serial.println("Func OFF Valve");
 	if(digitalRead(OpenValve1) == LOW)
	{
		digitalWrite(OpenValve1, LOW);
		Message += "Valve 1 :Already Off\n";
	}
	else
	{
		digitalWrite(OpenValve1, LOW);
		Message += "Valve 1 :Off Now\n";
	}

	if(digitalRead(OpenValve2) == LOW)
	{
		digitalWrite(OpenValve2, HIGH);
		Message += "Valve 2 :Already Off\n";
	}
	else
	{
		digitalWrite(OpenValve2, LOW);
		Message += "Valve 2 :Off Now\n";
	}

	if(digitalRead(OpenValve3) == LOW)
	{
		digitalWrite(OpenValve3, LOW);
		Message += "Valve 3 :Already Off\n";
	}
	else
	{
		digitalWrite(OpenValve3, LOW);
		Message += "Valve 3 :Off Now\n";
	}	
}

void completely_automatic_mode()
{
        Serial.println("Auto Mode");
	int MoistureValue1 = analogRead(MoistureSensor1);
	int MoistureValue2 = analogRead(MoistureSensor2);
	int MoistureValue3 = analogRead(MoistureSensor3);
        Serial.print("MoistureValue1:");
        Serial.println(MoistureValue1);
        Serial.print("MoistureValue2:");
        Serial.println(MoistureValue2);
        Serial.print("MoistureValue3:");
        Serial.println(MoistureValue3);
    
	int StateChange = 0;								// 1: Let the Valve be open for ValveOpenTime;
        myScreen.clear();
        myScreen.text(0,0, "***--^^^^--***");
        myScreen.text(6,1, "S2");
        myScreen.text(0,2, "MODE:Automatic ");
        myScreen.text(0,3, "");
        myScreen.text(0,4, "");
        myScreen.text(0,5, "***--------***");

	if(MoistureValue1 > ThresholdValue1)
	{
		digitalWrite(OpenValve1, HIGH);
		StateChange = 1;
                myScreen.text(0,3, "V1:ON,");
	}
	else
        {
		digitalWrite(OpenValve1, LOW);
                myScreen.text(0,3, "V1:OFF,");
        }

	if(MoistureValue2 > ThresholdValue2)
	{
		digitalWrite(OpenValve1, HIGH);
		StateChange = 1;
                myScreen.text(7,3, "V2:ON"); 
	}
	else
        {
		digitalWrite(OpenValve2, LOW);
                myScreen.text(7,3, "V2:OFF"); 
        }

	if(MoistureValue3 > ThresholdValue3)
	{
		digitalWrite(OpenValve1, HIGH);
		StateChange = 1;
                myScreen.text(0,4, "V3:ON");
	}
	else
        {
		digitalWrite(OpenValve3, LOW);
                myScreen.text(0,4, "V3:OFF");
        }

	if(StateChange == 1)
		delay(ValveOpenTime);
	else
		delay(CheckMoistureTime);											
}

void receive_sms()
{
 	if(Serial1.available() >0)
  	{
    
        Serial.print("Authentication check :");
        char Auth1 = Serial1.read();
        delay(10);
        Serial.println(Auth1);
        if(Auth1=='#')
        {
          Serial.print("Authentication check # received :");
          char Auth2 = Serial1.read();
          delay(10);
          Serial.println(Auth2);
          if(Auth2=='S')
          {
            Serial.println("Authentication check S received :");
            char Auth3 = Serial1.read();
            delay(10);
            Serial.println(Auth3);
            if(Auth3=='2')
            {				
            	Serial.println("Authentication check 2 received :");
	            Serial.println("Authentication Success");
		        char Punctuation1 = Serial1.read();
		        delay(10);        
                        Serial.println(Auth3);
		        char Mode = Serial1.read();
                        delay(10); 
                        Serial.print("Mode check :");
                        Serial.println(Mode);
		    	if (Mode == 'M')
		    	{
		            Serial.println("MODE M");
		    		get_time_stamp();
		            Serial.println("MODE M 1");
					Message = TimeStamp;
					Message +="\n";
		    		if(RunMode !='M')
		    			Message += "Manual Mode Now\n";
		    		else 
		    			Message += "In Manual Mode\n";
		    		RunMode = 'M';
		      		delay(10);
		      		char Punctuation2 = Serial1.read();
		      		char OnOff1 = Serial1.read();
                                delay(10);
		      		char OnOff2 = Serial1.read();
                                delay(10);

		      		if ((OnOff1 == 'O')&&(OnOff2 == 'N'))
		      		{
		                Serial.println("MODE M ON Valve");
		        		on_valve();
		                Serial.println("MODE M ON Valve 1");
		        		send_sms();
		                Serial.println("MODE M ON Valve 2");

                                myScreen.clear();
                                myScreen.text(0,0, "***--^^^^--***");
                                myScreen.text(6,1, "S2");
                                myScreen.text(0,2, "MODE : Manual");
                                myScreen.text(0,3, "All Valves ON");
                                myScreen.text(0,4, "");
                                myScreen.text(0,5, "***--------***");
		 			}
		 			else if((OnOff1 == 'O')&&(OnOff2 == 'F'))
		 			{
		                Serial.println("MODE M OFF Valve");
		 				off_valve();
		                Serial.println("MODE M OFF Valve 1");
		 				send_sms();
		                Serial.println("MODE M OFF Valve 2");

                                myScreen.clear();
                                myScreen.text(0,0, "***--^^^^--***");
                                myScreen.text(6,1, "S2");
                                myScreen.text(0,2, "MODE : Manual");
                                myScreen.text(0,3, "All Valves OFF");
                                myScreen.text(0,4, "");
                                myScreen.text(0,5, "***--------***");
		 			}
		   		}
		   		else if(Mode == 'S')
		   		{
		            Serial.println("MODE S ON Valve");
		   			get_time_stamp();
		                        Serial.println("MODE S ON Valve 1");
					Message = TimeStamp;
					Message +="\n";
					if(RunMode !='S')
		    			Message += "Semi-Automatic Mode Now\n";
		    		else 
		    			Message += "In Semi-Automatic Mode\n";
		   			RunMode = 'S';
		                        Serial.println("MODE S ON Valve 2");
		   			on_valve();
		                        Serial.println("MODE S ON Valve 3");
		   			send_sms();
		                        Serial.println("MODE S ON Valve 4");
		   			delay(ValveOpenTime);
		                        Serial.println("MODE S ON Valve 5");
                                        
                                        myScreen.clear();
                                        myScreen.text(0,0, "***--^^^^--***");
                                        myScreen.text(6,1, "S2");
                                        myScreen.text(0,2, "MODE : ");
                                        myScreen.text(0,3, "Semi-Automatic");
                                        myScreen.text(0,4, "All Valves ON");
                                        myScreen.text(0,5, "***--------***");
                                        
		   			get_time_stamp();
		                        Serial.println("MODE S ON Valve 6");
					Message = TimeStamp;
					Message +="\n";
					Message += "In Semi-Automatic Mode\n";
		                        Serial.println("MODE S OFF Valve 1");
		   			off_valve();
		                        Serial.println("MODE S OFF Valve 2");
		   			send_sms();
		                        Serial.println("MODE S OFF Valve 3");

                                        myScreen.clear();
                                        myScreen.text(0,0, "***--^^^^--***");
                                        myScreen.text(6,1, "S2");
                                        myScreen.text(0,2, "MODE : ");
                                        myScreen.text(0,3, "Semi-Automatic");
                                        myScreen.text(0,4, "All Valves OFF");
                                        myScreen.text(0,5, "***--------***");
		   		}
		   		else if(Mode == 'A')
		   		{ 
		            Serial.println("MODE A ON Valve");
		   			get_time_stamp();
		            Serial.println("MODE A ON Valve 1");
					Message = TimeStamp;
					Message +="\n";
					if(RunMode !='A')
		    			Message += "Fully Automatic Mode Now\n";
		    		else 
		    			Message += "Fully Automatic Mode Already\n";
		   			RunMode = 'A';
		            Serial.println("MODE A ON Valve 2");
		   			completely_automatic_mode();
		            Serial.println("MODE A ON Valve  3");
		   			send_sms();
		            Serial.println("MODE A ON Valve 4");
		   		}
		   		else
		   		{ 
		            Serial.println("INVALID");
		            Serial.println(Mode);
		   			Message = "Invalid Command\nPlease send valid command";
		   		}
	        }
          }
        }
	   	else
	   	{
	   		Serial.println("Authentication Failed");
	   	}
   	}
}

void setup()
{
/* ----- Set Baud rate for serial communication ----- */

 Serial.begin(19200);									// Serial port for display while debugging via computer.
 Serial1.begin(19200);	


 Serial.println("Setup Start"); 
  
/* ----- Initialize Nokia5110 display ----- */
  #if defined(__MSP430G2553__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
  #elif defined(__LM4F120H5QR__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV128); // for LM4F120H5QR DIV2 = 4 MHz !
  #endif
    
    myScreen.begin();
    myScreen.text(0,0, "***--^^^^--***");
    myScreen.text(6,1, "S2");
    myScreen.text(5,2, "Your");
    myScreen.text(4,3, "Smart");
    myScreen.text(3,4, "Solution");
    myScreen.text(0,5, "***--------***"); 
 Serial.println("LCD Setup Done"); 								// UART1 for communication with GSM module via Rx:PB_1 and Tx:PB_2.

 pinMode(OpenValve1, OUTPUT);							// Set up the digital pin to control valve 1.
 pinMode(OpenValve2, OUTPUT);							// Set up the digital pin to control valve 2.
 pinMode(OpenValve3, OUTPUT);							// Set up the digital pin to control valve 3.


 /* ----- Wake up the GSM shield ----- */

 delay(20000);  										// Give time for the module to log on to network.
 Serial1.print("AT+CLIP=1\r");  						// Turn on caller ID notification.
 delay(1000);  
 Serial1.print("AT+CNMI=2,2,0,0,0\r");					// ??
 delay(100);
 Serial.println("GSM Module ready...");
 
}
void loop()
{
 	receive_sms();
        Serial.println("Loop");
        if(RunMode =='A')
          completely_automatic_mode();
        delay(1000);
}
