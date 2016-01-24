#include "tm4c123gh6pm.h"

#define N_col 4
#define N_row 3

#include <stdio.h>
#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdlib.h>
#include "pins.h"

typedef unsigned char uint8;

void LCD_init(void);
void LCD_Send_Command(uint8 command);
void LCD_Goto(uint8 x, uint8 y);
void LCD_Send_Character(uint8 character);
void LCD_Send_String(char *str);
void Delay_ms(unsigned long time);
void LCD_Clear(void);
void LCD_Send_Integer(int number);
void LCD_Send_Float(float f);

#define LCD_DATA_PORT GPIO_PORTB_DATA_R

#define LCD_CONTROL_PORT GPIO_PORTF_DATA_R

#define LCD_RS_PIN PF1
#define LCD_RW_PIN PF2
#define LCD_E_PIN  PF3


void LCD_init(void)
{
 /* initialization for lcd data and command (ALL PINS OF PORT B)*/
 volatile unsigned long delay;
 SYSCTL_RCGC2_R |=SYSCTL_RCGC2_GPIOB; //ative clock for PORT B
 delay = SYSCTL_RCGC2_R;

 GPIO_PORTB_AMSEL_R = 0x00; //DISABLE ANLOG ON PORT B
 GPIO_PORTB_PCTL_R = 0x00000000; //
 GPIO_PORTB_DIR_R = 0xFF; // MAKE PORTB IS OUTPUT PORT
 GPIO_PORTB_AFSEL_R = 0x00; //DISABLE ALTERNATIVE FUNCTION
 GPIO_PORTB_DEN_R =0xFF;  // ENABLE DIGITAL I/O FOR PORT B
 
 /*initialization for lcd control ()*/
 SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
 delay = SYSCTL_RCGC2_R;
 GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
 GPIO_PORTF_CR_R = 0x0E;
 GPIO_PORTF_AMSEL_R = 0x00;
 GPIO_PORTF_PCTL_R = 0x00000000;
 GPIO_PORTF_DIR_R = 0x0E;
 GPIO_PORTF_AFSEL_R = 0x00;
 GPIO_PORTF_DEN_R = 0x0E;
 
 LCD_Send_Command(0x38);
 Delay_ms(100);
 LCD_Send_Command(0x0C);
 Delay_ms(100);
 LCD_Send_Command(0x01);
 Delay_ms(100);
 LCD_Send_Command(0x06);
}


void LCD_Send_Command(uint8 command)
{
 LCD_DATA_PORT = command;

 LCD_RS_PIN = 0x00;
 LCD_RW_PIN = 0x00;
 LCD_E_PIN = 0xFF;
 Delay_ms(100);
 LCD_E_PIN = 0x00;
}


void LCD_Goto(uint8 x, uint8 y)
{
 uint8 firstAddress[]={0x80,0xC0};
 LCD_Send_Command(firstAddress[x-1] + y-1);
 Delay_ms(100);
}


void LCD_Send_Character(uint8 character)
{
 LCD_DATA_PORT = character;
 
 LCD_RS_PIN = 0xFF;
 LCD_RW_PIN = 0x00;
 LCD_E_PIN = 0xFF;
 Delay_ms(100);
 LCD_E_PIN = 0x00;
}


void LCD_Send_String(char *str)
{
 while(*str)
 {
  LCD_Send_Character(*str++);
  
 }
}

void Delay_ms(unsigned long time)
{
 time = 145448;  // 0.1sec
  while(time){
  time--;
  }
}
void LCD_Clear()
{
 LCD_Send_Command(0x01);
}
void LCD_Send_Float(float f)
{
 unsigned int v,p;
 long int num;
 num=f*10000;
 p=num%10000;
 
 v=num/10000;
 
 LCD_Send_Integer(v);
 LCD_Send_Character('.');
 LCD_Send_Integer(p);

}


void LCD_Send_Integer(int number){// This function prints integer on LCD
 char buffer[10];
 Delay_ms(10);
 sprintf(buffer,"%d",number); // function sprintf converts integer to string
 LCD_Send_String(buffer);
}


unsigned char Keypad_Read(void);
void Keypad_Init(void);
char key_pressed(unsigned char value);

void NDelay_ms(unsigned long time)
{
 time = ((time/375)*1000000);
 while(time)
 {
  time--;
 }
}

unsigned char Keypad_Read(){

 unsigned char col_count =0,row_count=0;
 while(1)
 {
  for(col_count = 0;col_count < N_col;col_count++)
  {
 GPIO_PORTE_DATA_R = 1<<col_count;
   for(row_count = 0;row_count < N_row;row_count++)
   {
    if((GPIO_PORTA_DATA_R &(1<<(row_count+2))) != 0) 
    {
     NDelay_ms(400);
			/*LCD_Clear();
			LCD_Goto(1,1);
			LCD_Send_Character(row_count+48);
			LCD_Goto(2,1);
			LCD_Send_Character(col_count+48);*/
     return ((col_count*3)+row_count+1);     
    } 
   }
  }
 }
}
char key_pressed(unsigned char value)
{
 char key;
 switch(value)
 {
  case 1:key = 1;
  break;
  case 2:key = 2;
  break;
  case 3:key = 3;
  break;
  case 4:key = 4;
  break;
  case 5:key = 5;
  break;
  case 6:key = 6;
  break;
  case 7:key = 7;
  break;
  case 8:key = 8;
  break;
  case 9:key = 9;
  break;
  case 10:key = -6;
  break;
  case 11:key = 0;
  break;
  case 12:key = -13;
  break;
 }
 return key;
}
void PORTF_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;  //activate clock for portf
	delay = SYSCTL_RCGC2_R; //get the delay of the clock from the sysctl register
	GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock the gpio portf
	GPIO_PORTF_CR_R = 0x1F; //allow changes to portf (pf-4 to pf-0)
	GPIO_PORTF_AMSEL_R = 0x00; //disable analog for pf4-pf0
	GPIO_PORTF_PCTL_R = 0x00000000; //gpio on pf4-pf0
	GPIO_PORTF_DIR_R = 0x0E; //set the directions of pf-4 to pf -0 pf-4 and pf-0 input and others output
	GPIO_PORTF_AFSEL_R = 0x00; //disable alternate function of pf7-pf0
	GPIO_PORTF_PUR_R = 0x11; //pullup registers pf-0 and pf-4 as they are switches
	GPIO_PORTF_DEN_R = 0x1F; //digital i/o on pf-4 to pf-0
}
unsigned long led;

void Delay(void)
{
	volatile unsigned long time;
	time  = 145448; //0.1 second
	time  = time *20; //for 1 second
	while(time)
	{
		time--;
	}
}
void Keypad_Init(){
 
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) activate clock for Port E
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTE_DIR_R = 0xFF;          // 5) PE as output
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTE_PUR_R = 0x00;          // enable pull-up on PF0 and PF4
  GPIO_PORTE_DEN_R = 0xFF;          // 7) enable digital I/O on PF4-0


  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTA_DIR_R = 0x00;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) disable alt funct on PA7-0
  GPIO_PORTA_PDR_R = 0xFF;          // enable pull-up on PA4,5,6,7
  GPIO_PORTA_DEN_R = 0xFF;          // 7) enable digital I/O on PFA-0

} 

long unsigned int  led;
void PortE_Init(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) activate clock for Port E
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTE_DIR_R = 0xFF;          // 5) PE as output
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTE_PUR_R = 0x00;          // enable pull-up on PF0 and PF4
  GPIO_PORTE_DEN_R = 0xFF;          // 7) enable digital I/O on PF4-0
}

void PortA_Init(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTA_DIR_R = 0x00;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) disable alt funct on PA7-0
  GPIO_PORTA_PDR_R = 0xFF;          // enable pull-up on PA4,5,6,7
  GPIO_PORTA_DEN_R = 0xFF;          // 7) enable digital I/O on PFA-0
}


void PortF_Init(void){ volatile unsigned long delay;
SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;  // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0
}


char reads;
char xs;
int main()
{
	PortF_Init();
 PortA_Init();
 PortE_Init();
	LCD_init();
	Keypad_Init();
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_String("Boolean Algebra");
	LCD_Goto(2,1);
	LCD_Send_String("Calculator");
	Delay();
/*	while(1)
	{
		read =Keypad_Read();
		x = key_pressed(read);
		LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_Character(x+48);
		read =Keypad_Read();
		y = key_pressed(read);
		LCD_Goto(2,1);
		LCD_Send_Character(y+48);
		sum = x+y;
		LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_String("Sum");
		LCD_Goto(2,1);
		LCD_Send_Character(sum+48);
		
	}*/
	while(1)
	{
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_String("Operations");
	Delay();
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_String("1.Boolean Opns");
	LCD_Goto(2,1);
	LCD_Send_String("2.QuinnMcClusky");
	Delay();
	reads = Keypad_Read();
	xs = key_pressed(reads);
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_Character(xs+48);
	if(xs == 1)
	{
		operations();
		Delay();
		Delay();
		Delay();
		LCD_Clear();
	}
	else
	{
		quinns();
		Delay();
		Delay();
		Delay();
		Delay();
		Delay();
		Delay();
		LCD_Clear();
	}
}
	
}