/**HEADER FILES**/
#include<reg52.h>
#include<string.h>
#include<intrins.h>

/** LED & BUZZER CONNECTIONS **/
sbit buzzer = P3^6;
sbit green = P3^7;

/**VARIABLES DECLARATION**/
unsigned char s_pass1[]="USERA",s_pass2[]="RESET";

/**VARIABLES DECLARATION**/
unsigned char a,b,x,mask;
bit busy,noack;
unsigned int temp,account;
char n;

/**USER DEFINED HEADER FILES**/
#include"delay.h"
#include"lcd.h"
#include"serial.h"
#include"keypad.h"
#include"i2c.h"
#include"sys_init.h"
#include"smartcard.h"


/**MAIN FUNCTION**/
void main()
{
		/** LOCAL VARIABLES DECLARATION **/
		unsigned char x;
		sys_init();
		while(1)
		{
			cmd_lcd(0X01);			
			cmd_lcd(0X80);
			display_lcd("Waiting For Card....");
			i=0;
			r_flag=0;
			while(!r_flag);
					
			if(!(strcmp(buff,"Enter password:")))
			{
				cmd_lcd(0x80);
				display_lcd("card is inserted");
				cmd_lcd(0xc0);
				display_lcd("Processing......");
				delay_ms(500); 
				print("AAA\n");//SENDING PASSWORD
				r_flag=0;		
				while(!r_flag);//WAITING FOR REPLY
				cmd_lcd(0xc0);
				i=0;	r_flag=0;
				display_lcd(buff);
			
				while(!r_flag);//WAITING FOR REPLY
				cmd_lcd(0x94);
				display_lcd(buff);
				print("READ 32 5\n");	//READ DATA FROM SMARTCARD
				r_flag=0;
				while(!r_flag);//WAITING FOR REPLY
		
				cmd_lcd(0x01);
				display_lcd(buff);
				delay_ms(500);

				if(!(strcmp(buff,s_pass1)))
				{
					cmd_lcd(0x80);
					display_lcd("* UR CARD IS VALID *");
					for(n=0;n<5;n++)
					{	
						green=1;
						delay_ms(100);
						green=0;
						delay_ms(100);
					}
					cmd_lcd(0x94);
					display_lcd("Pls remove Card.....");
					r_flag=0;i=0;buff[0]='\0';
					while(!r_flag);//WAITING FOR REPLY
					cmd_lcd(0xc0);
					display_lcd(buff);
					delay_ms(700);
		m:			cmd_lcd(0x01);		
					cmd_lcd(0x80);
					display_lcd("1:    PAN CARD INFO.");		
					cmd_lcd(0xC0);
					display_lcd("2:    ATM TERMINAL  ");		
					cmd_lcd(0x94);		
					display_lcd("3:    VOTING SYSTEM ");
					cmd_lcd(0xd4);		
					display_lcd("4:      EXIT        ");   
					do
					{
					
						x=key();	//WAITINF FOR KEY PRESSING
					
					}while((x!='1')&&(x!='2')&&(x!='3')&&(x!='4'));
				
					if(x=='1')			
						pancard_info();	//PERSONAL INFROMATION
					else if(x=='2')
						atm_terminal();
					else if(x=='3')
					    voting();   //VOTING CARD SYSTEM   
					else if(x=='4')
					    continue;
					goto m;
				}
				else if(!(strcmp(buff,s_pass2)))
				{
					cmd_lcd(0x80);
					display_lcd("* UR CARD IS VALID *");
					for(n=0;n<5;n++)
					{	
						green=1;
						delay_ms(100);
						green=0;
						delay_ms(100);
					}
					cmd_lcd(0x94);
					display_lcd("Pls remove Card.....");
					r_flag=0;i=0;buff[0]='\0';
					while(!r_flag);//WAITING FOR REPLY
					cmd_lcd(0xc0);
					display_lcd(buff);
					delay_ms(700);
					reset_voting();
				}
				else
				{
					cmd_lcd(0x80);
					display_lcd("*UR CARD IS INVALID*");
					for(n=0;n<5;n++)
					{
						buzzer=1;
						delay_ms(100);
						buzzer=0;
						delay_ms(100);
					}
					cmd_lcd(0x94);
					display_lcd("Pls remove Card.");
					r_flag=0;
					while(!r_flag);//WAITING FOR REPLY
					cmd_lcd(0xc0);
					display_lcd(buff);
					delay_ms(700);
				}	
			}
			else
			{
			
		    	cmd_lcd(0x01); 
		      	cmd_lcd(0x80);
		    	display_lcd("PLEASE INSERT CARD");
			    cmd_lcd(0xC0);
			    display_lcd("      PROPERLY      "); 
	    		delay_ms(1000);                    
			    cmd_lcd(0x01);
		    	cmd_lcd(0x94);
	    		display_lcd("Pls Remove Card.....");  
    			r_flag=0; 
	   	
	   			while(!r_flag); 
		        cmd_lcd(0xd4);
	   			display_lcd(buff);  
		        delay_ms(500);
	   		}

		
			
	}	//main while loop end
	
}	//main loop end
 