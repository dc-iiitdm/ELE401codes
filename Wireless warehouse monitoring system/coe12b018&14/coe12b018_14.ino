// Authors: 
// Coe12b018 : Nitin Vivek Bharti
// Coe12b014 : Medha Vasishth
// Product : Wireless Warehouse monitoring system 
// Components : TM4C123ghpm, LM35, DHT11, LDR, Nokia 5110 LCD and HC-05 bluetooth module
#include "msp430.h"
#include "PCD8544.h"

#define LCD5110_SCLK_PIN BIT5
#define LCD5110_DN_PIN BIT7
#define LCD5110_SCE_PIN BIT2
#define LCD5110_DC_PIN BIT0
#define LCD5110_SELECT P2OUT &= ~LCD5110_SCE_PIN
#define LCD5110_DESELECT P2OUT |= LCD5110_SCE_PIN
#define LCD5110_SET_COMMAND P2OUT &= ~LCD5110_DC_PIN
#define LCD5110_SET_DATA P2OUT |= LCD5110_DC_PIN
#define LCD5110_COMMAND 0
#define LCD5110_DATA 1

#define RX_PIN	BIT1

void writeStringToLCD(const char *string);
void writeCharToLCD(char c);
void writeToLCD(char dataCommand, char data);
void clearLCD();
void setAddr(char xAddr, char yAddr);
void initLCD();

int sensorPin1 = A0;    // select the input pin for the LM35
int sensorPin1 = A1;    // select the input pin for the DHT11
int sensorPin1 = A2;    // select the input pin for the LDR
String data;
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int sensorValue3 = 0;  // variable to store the value coming from the sensor
int test=0;
void setup() {
    Serial.begin(9600
    WDTCTL = WDTPW + WDTHOLD; // disable WDT
	BCSCTL1 = CALBC1_1MHZ; // 1MHz clock
	DCOCTL = CALDCO_1MHZ;

	P2OUT |= LCD5110_SCE_PIN;
	P2DIR |= LCD5110_SCE_PIN;
	P2OUT |= LCD5110_DC_PIN;
	P2DIR |= LCD5110_DC_PIN;

	// setup UCA0
	P1SEL |= RX_PIN;
	P1SEL2 |= RX_PIN;

	UCA0CTL1 |= UCSSEL_2;
	UCA0BR0 = 0x68; // 9600@1MHz
	UCA0BR1 = 0x00;
	UCA0MCTL = UCBRS_1;
	UCA0CTL1 &= ~UCSWRST;
	IE2 |= UCA0RXIE;

	// setup UCB0
	P1SEL |= LCD5110_SCLK_PIN + LCD5110_DN_PIN;
	P1SEL2 |= LCD5110_SCLK_PIN + LCD5110_DN_PIN;

	UCB0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master
	UCB0CTL1 |= UCSSEL_2; // SMCLK
	UCB0BR0 |= 0x01; // 1:1
	UCB0BR1 = 0;
	UCB0CTL1 &= ~UCSWRST; // clear SW

	_delay_cycles(500000);
	initLCD();
	clearLCD();
}
void writeStringToLCD(const char *string) {
	while (*string) {
		writeCharToLCD(*string++);
	}
}

void writeCharToLCD(char c) {
	char i;
	for (i = 0; i < 5; i++) {
		writeToLCD(LCD5110_DATA, font[c - 0x20][i]);
	}
	writeToLCD(LCD5110_DATA, 0);
}

void writeToLCD(char dataCommand, char data) {
	LCD5110_SELECT;
	if (dataCommand) {
		LCD5110_SET_DATA;
	} else {
		LCD5110_SET_COMMAND;
	}
	UCB0TXBUF = data;
	while (!(IFG2 & UCB0TXIFG))
		;
	LCD5110_DESELECT;
}

void clearLCD() {
	setAddr(0, 0);
	int c = 0;
	while (c < PCD8544_MAXBYTES) {
		writeToLCD(LCD5110_DATA, 0);
		c++;
	}
	setAddr(0, 0);
}

void setAddr(char xAddr, char yAddr) {
	writeToLCD(LCD5110_COMMAND, PCD8544_SETXADDR | xAddr);
	writeToLCD(LCD5110_COMMAND, PCD8544_SETYADDR | yAddr);
}

void initLCD() {
	writeToLCD(LCD5110_COMMAND,
			PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION);
	writeToLCD(LCD5110_COMMAND, PCD8544_SETVOP | 0x3F);
	writeToLCD(LCD5110_COMMAND, PCD8544_SETTEMP | 0x02);
	writeToLCD(LCD5110_COMMAND, PCD8544_SETBIAS | 0x03);
	writeToLCD(LCD5110_COMMAND, PCD8544_FUNCTIONSET);
	writeToLCD(LCD5110_COMMAND, PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
}

void loop() {
  if(test==0)
  {
    // read the value from the sensor:
    sensorValue1 = analogRead(sensorPin1);
    sensorValue1=(sensorValue1*205)/1024-55;
    data="1$t$"+sesorValue1;
    Serial.print(data);
    data="Temp : "+sensorValue1;
    writeStringToLCD(data);
  }
  else if(test==1)
  {
    // read the value from the sensor:
    sensorValue2 = analogRead(sensorPin2);    
    sensorValue2 = (sensorValue2*100)/511;
    data="1$h$"+sesorValue2;
    Serial.print(data);
    data="Humid : "+sensorValue2;
    writeStringToLCD(data);    
  }
  else if(test==2)
  {
    // read the value from the sensor:
    sensorValue3 = analogRead(sensorPin3);
    sensorValue3=sensorValue3*100;
    data="1$l$"+sesorValue3;
    Serial.print(data);
    data="Light : "+sensorValue3;
    writeStringToLCD(data);
  }
  test=(test+1)%3;
  if(test==0)
  {
     delay(30*1000);//30 second delay for next value
  }
  else
  {
     delay(5*1000); // 5 second delay to use next sensor
  }
}
