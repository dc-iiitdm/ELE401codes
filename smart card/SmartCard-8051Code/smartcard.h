
/** ATM FUNCTION DEFINATION **/
void atm_terminal()
{
	unsigned char cmd;
	cmd_lcd(0x01);	
	display_lcd("  WELCOME USERA");
	cmd_lcd(0xc0);
	display_lcd("ATM TERMINAL......");
	cmd_lcd(0xd4);
	display_lcd(" PLZ ENTER PIN NO.");
	cmd_lcd(0x94);
	password();
	cmd_lcd(0x01);
	cmd_lcd(0x80);
	display_lcd("Your request is ");
	cmd_lcd(0xC0);	
	display_lcd("Processing........");
	cmd_lcd(0x94);	
	display_lcd("Please wait");
	if(!strcmp(passwd,pwd)) 
	{
		cmd_lcd(0x01); 
		cmd_lcd(0x80);
		display_lcd("  HELLO WELCOME TO  ");
		cmd_lcd(0xC0);
		display_lcd("    ATM TERMINAL    ");
		cmd_lcd(0xd4);
		display_lcd("  FOLLOW THE MENU"); 
		delay_ms(200);
		for(n=0;n<5;n++)
		{
			green=1;
			delay_ms(100);
			green=0;
			delay_ms(100);
		}     
		
		while(1)
		{
		  	/** DISPLAY MENU **/
			cmd_lcd(0x01);
			cmd_lcd(0X80);
			display_lcd("*    WITHDRAW");
			cmd_lcd(0xc0);  
			display_lcd("d    DEPOSIT");
			cmd_lcd(0x94);
			display_lcd("#    BALANCE ENQUIRY");
			cmd_lcd(0xd4);
			display_lcd("Y   YES     x   EXIT");
			x=key(); //WAITING FOR KEY PRESSING
			if(x==0)
				break;
			if(x=='#')
			{
				cmd_lcd(0x01);
				display_lcd("UR ACCOUNT BALANCE:");
				cmd_lcd(0xc0);
				a=read_i2c(0xa0,0x02);	       
				b=read_i2c(0xa0,0x03);
				account=a;
				account=(account<<8)|b;
				display_lcd("RS.");
				integer_lcd(account);
				display_lcd("/-");
				account=0;	
				for(n=0;n<5;n++)
				{
					green=1;
					delay_ms(100);
					green=0;
					delay_ms(100);
				}     
				delay_ms(500);		
			}	//BALANCE LOOP END
			else if(x=='d')
			{       
	D:			temp=0;
				cmd_lcd(0x01);
				display_lcd("DEPOSIT MONEY");
				cmd_lcd(0xd4);
				display_lcd("IF YES PRESS  Y");
				cmd_lcd(0xc0);
				while(1)
				{
					x=key(); //WAITING FOR KEY PRESSING
					if(x=='*')
        			{
		                 cmd_lcd(0x10);
		                 data_lcd(' ');
		                 cmd_lcd(0x10);   
		                 cmd--;
		                 if(cmd<0xc0)
		                 {
		                    cmd=0xc0;
		                    cmd_lcd(cmd);
		                 }
		                 temp/=10;
		        	}	
					
					else if((x>='0')&&(x<='9'))
					{
						 cmd++;
						data_lcd(x);
						x=x-0x30;
						temp=temp*10+x;
					}
					else if(x=='y') 
						break;
					if(temp>50000)
		            {
		                cmd_lcd(0x80);
		                display_lcd("LIMIT CROSS    ");
		                delay_ms(1000);
		                goto D;
		            }			
				}
				a=read_i2c(0xa0,0x02);	       
				b=read_i2c(0xa0,0x03);	
				account=a;
				account=(account<<8)|b;
				
				cmd_lcd(0x01);
				cmd_lcd(0x80);
				display_lcd("Your request is ");
				cmd_lcd(0xc0);
				display_lcd("Processing........");
				cmd_lcd(0x94);
				display_lcd("Please wait");
				delay_ms(700);
				cmd_lcd(0X01);
				cmd_lcd(0X80);
				display_lcd("OLD BALANCE:");
				integer_lcd(account);
				delay_ms(100);			

				if(temp < (65535-account))
				{ 
					account=account+temp;

					cmd_lcd(0XC0);
					display_lcd("NEW BALANCE:");
					integer_lcd(account);			
					delay_ms(300);

					a=account>>8;
					b=account;
					write_i2c(0xa0,0x02,a);
					write_i2c(0xa0,0x03,b);
		     
					cmd_lcd(0x01);
					cmd_lcd(0x80);
					display_lcd("your deposit success");
					cmd_lcd(0xc0);
					display_lcd("UR ACCOUNT BALANCE:");
					cmd_lcd(0x94); 
					a=read_i2c(0xa0,0x02);	       
					b=read_i2c(0xa0,0x03);
					account=a;
					account=(account<<8)|b;
					display_lcd("RS.");
					integer_lcd(account);
					display_lcd("/-");
					account=0; 
					delay_ms(500);
				} 
				else
				{
					cmd_lcd(0x01);
					cmd_lcd(0x80);
					display_lcd("DEPOSIT NOT POSSIBLE");
					for(n=0;n<5;n++)
					{
						buzzer=1;
						delay_ms(100);
						buzzer=0;
						delay_ms(100);
					}
				}
			}	//DEPOSIT LOOP END
						
			else if(x=='*')
			{
				temp=0;
				cmd_lcd(0x01);	
				display_lcd("WITHDRAW MONEY");
				cmd_lcd(0xd4);
				display_lcd("IF YES PRESS  Y");
				L:	cmd_lcd(0xc0);
				while(1)
				{
					x=key();//WAITING FOR KEY PRESSING

					if(x=='*')
        			{
		                 cmd_lcd(0x10);
		                 data_lcd(' ');
		                 cmd_lcd(0x10);   
		                 cmd--;
		                 if(cmd<0xc0)
		                 {
		                    cmd=0xc0;
		                    cmd_lcd(cmd);
		                 }
		                 temp/=10;
		        	}
					else if((x>='0')&&(x<='9'))
					{
						data_lcd(x);
						x=x-0x30;
						temp=temp*10+x;
					}
					else if(x=='y') 
						break;
				}   
				if(temp==0)
				{  	
					cmd_lcd(0x94);   
					display_lcd("PLZ ENTER AMOUNT");
					goto L;
				}        
				if((temp%100)==0)  
				{
					a=read_i2c(0xa0,0x02);	       
					b=read_i2c(0xa0,0x03);
					account=a;
					account=(account<<8)|b;       
					if(temp<=account)
					{
						if((account-temp)>=500)
						{   	
						lable:	account=account-temp; 
							a=account>>8;
							b=account;
							write_i2c(0xa0,0x02,a);
							write_i2c(0xa0,0x03,b);
							cmd_lcd(0x01);
							display_lcd("Your request is ");
							cmd_lcd(0xc0);
							display_lcd("Processing........");
							cmd_lcd(0x94);
							display_lcd("Please wait");
							delay_ms(700);
							for(n=0;n<5;n++)
							{	
								green=1;
								delay_ms(100);
								green=0;
								delay_ms(100);
							}     
							cmd_lcd(0x01);
							display_lcd("PLEASE COLLECT CASH");
							delay_ms(200);
							
						}
						else
						{
							cmd_lcd(0x01);
							cmd_lcd(0x80);  
							display_lcd("MAINTAIN MIN BALANCE");
							cmd_lcd(0xc0);
							display_lcd("YOU WANT TO PROCEED?");
							cmd_lcd(0xd4);
							display_lcd("y   YES       x   NO");
							x=key();//WAITING FOR KEY PRESSING
							while(1)
							{
								if((x=='y')||(x=='x'))
									break;
							}
							if(x=='y')
								goto lable;
							else
								break; 
						}
					}
					else
					{ 
						cmd_lcd(0x01);
						cmd_lcd(0x80);
						display_lcd("Your request is ");
						cmd_lcd(0xc0);
						display_lcd("Processing........");
						cmd_lcd(0x94);
						display_lcd("Please wait");
						delay_ms(1000);
						cmd_lcd(0x01);
						cmd_lcd(0x80);
						display_lcd("   PLEASE CHECK");
						cmd_lcd(0xc0); 
						display_lcd("YOUR ACCOUNT BALANCE");
						for(n=0;n<5;n++)
						{
							buzzer=1;
							delay_ms(100);
							buzzer=0;
							delay_ms(100);
						}
						delay_ms(200);					    	
					}
				}
				else
				{       
					cmd_lcd(0x01);
					cmd_lcd(0x80);
					display_lcd("Your request is ");
					cmd_lcd(0xc0);
					display_lcd("Processing........");
					cmd_lcd(0x94);
					display_lcd("Please wait");
				  	delay_ms(700);     					
					cmd_lcd(0x01);
					cmd_lcd(0x80);
					display_lcd("    PLEASE ENTER  ");
					cmd_lcd(0xc0);
					display_lcd("  MULTIPLE OF 100 ");
					for(n=0;n<5;n++)
					{
						buzzer=1;
						delay_ms(100);
						buzzer=0;
						delay_ms(100);
					}
					delay_ms(500);
				}
			}	//withdraw loop end
			else if(x=='x')
			{       
				cmd_lcd(0x01);
				display_lcd("   THANK YOU FOR    ");
				cmd_lcd(0xc0);
				display_lcd("  USING ATM TERMINAL"); 
				delay_ms(500);	
				break;	
			}	//exit loop end						
		}
		}

		else
		{ 
			cmd_lcd(0x01);
		    display_lcd(" PASSWORD NOT MATCH");	
					       			
			for(n=0;n<5;n++)
			{
				buzzer=1;
				delay_ms(100);
				buzzer=0;
				delay_ms(100);
			}
		
		}
}//atm terminal loop end



/** PERSONAL DATA **/
void pancard_info()
{
	cmd_lcd(0x01);	
	display_lcd("  WELCOME USERA");
	cmd_lcd(0xc0);
	display_lcd("PAN CARD INFO.....");
	cmd_lcd(0xd4);
	display_lcd(" PLZ ENTER PASSWORD");
	cmd_lcd(0x94);
	password();
	cmd_lcd(0x01);
	cmd_lcd(0x80);
	display_lcd("Your request is ");
	cmd_lcd(0xC0);	
	display_lcd("Processing........");
	cmd_lcd(0x94);	
	display_lcd("Please wait");
	
	if(!strcmp(passwd,pwd)) 
	{			       		
		for(n=0;n<2;n++)
		{
			green=1;
			delay_ms(100);
			green=0;
			delay_ms(100);
		}     
		cmd_lcd(0x01);
		cmd_lcd(0x80);	       			
		display_lcd(" NAME  : USERA");	
		cmd_lcd(0xc0);
		display_lcd(" S/o   : FATHER");	
		cmd_lcd(0x94);
		display_lcd("D.O.B  : DD/MM/YYYY");
		cmd_lcd(0xd4);
		display_lcd("PAN NO : AB14K45L");
		delay_ms(2500);
	}
	else 
	{
		cmd_lcd(0x01);
		cmd_lcd(0x80);	  
		display_lcd(" PASSWORD NOT MATCH");	
				       			
		for(n=0;n<5;n++)
		{
			buzzer=1;
			delay_ms(100);
			buzzer=0;
			delay_ms(100);
		}
	}
}


/** VOTING FUNCTION DEFINATION **/	
void voting()
{
	a=read_i2c(0xa0,0x00);
	if(a==0)
	{
		cmd_lcd(0x01);	
		display_lcd("  WELCOME USERA");
		cmd_lcd(0xc0);
		display_lcd("    VOTING SYS.. ");
		cmd_lcd(0xd4);
		display_lcd(" PLZ ENTER PASSWORD");
		cmd_lcd(0x94);
		password();
		cmd_lcd(0x01);
		cmd_lcd(0x80);
		display_lcd("Your request is ");
		cmd_lcd(0xC0);	
		display_lcd("Processing........");
		cmd_lcd(0x94);	
		display_lcd("Please wait");
		if(!strcmp(passwd,pwd)) 
		{
			for(n=0;n<2;n++)
			{
				green=1;
				delay_ms(100);
				green=0;
				delay_ms(100);	
			} 
			cmd_lcd(0x01); 
			cmd_lcd(0x80);
			display_lcd("PARTY1.... ----->  1");
			cmd_lcd(0xc0);
			display_lcd("PARTY2.... ----->  2");
			cmd_lcd(0X94);
			display_lcd("PARTY3.... ----->  3");
			cmd_lcd(0xd4);
			display_lcd("PARTY4.... ----->  4");
			do
			{
				x=key();
			}while((x!='1')&&(x!='2')&&(x!='3')&&(x!='4')); 
			
			write_i2c(0xa0,0x00,0x01);

			if(x=='1')
			{
		   		cmd_lcd(0x01);
				cmd_lcd(0x80);
				display_lcd("VOTED FOR PARTY1");
			}
			else if(x=='2')
			{
				cmd_lcd(0x01);
				cmd_lcd(0x80);	
				display_lcd("VOTED FOR PARTY2");
			} 
			else if(x=='3')
			{
				cmd_lcd(0x01);
				cmd_lcd(0x80);
				display_lcd("VOTED FOR PARTY3");
			}
			else if(x=='4')
			{
				cmd_lcd(0x01);
				cmd_lcd(0x80);
				display_lcd("VOTED FOR PARTY4");
			} 
			delay_ms(700);
			cmd_lcd(0x01);
			cmd_lcd(0x80);
			display_lcd("THANKS FOR VOTING");
			delay_ms(700);
	}	
	else
	{
		cmd_lcd(0x01);
		display_lcd(" PASSWORD NOT MATCH");	
		for(n=0;n<2;n++)
		{
			buzzer=1;
			delay_ms(100);
			buzzer=0;
			delay_ms(100);
		}
	}
	}
	else
	{
		cmd_lcd(0x01);
		cmd_lcd(0x80);
		display_lcd("VOTE COMPLETED"); 
				   			
		for(n=0;n<2;n++)
		{
			buzzer=1;
			delay_ms(100);
			buzzer=0;
			delay_ms(100);
		}
	}
	
} 

/** RESET VOTING FUNCTION DEFINATION **/
void reset_voting()
{
	cmd_lcd(0x01);	
	display_lcd("**WELCOME  OFFICER**");
	delay_ms(700);
	cmd_lcd(0x01);
	display_lcd("VOTING SYSTEM ID:101");
	cmd_lcd(0xc0);
	display_lcd("RESET VOTING SYSTEM");
	cmd_lcd(0xd4);
	display_lcd(" PLZ ENTER PASSWORD");
	cmd_lcd(0x94);
	password();
	cmd_lcd(0x01);
	cmd_lcd(0x80);
	display_lcd("Your request is ");
	cmd_lcd(0xc0);
	display_lcd("Processing........");
	cmd_lcd(0x94);
	display_lcd("Please wait");		
				       		
			       		
	if(!strcmp(pass1,pwd)) 
	{ 
		
		for(n=0;n<3;n++)
		{
			green=1;
			delay_ms(100);
			green=0;
			delay_ms(100);
		} 
		       				
		write_i2c(0xa0,0x00,0x00); 
		
		       				
		cmd_lcd(0x01);
		cmd_lcd(0x80);	
		display_lcd("** VOTING SYSTEM ***");
		cmd_lcd(0xc0);	
		display_lcd("      RESETED     ");   
		delay_ms(1000);

	}
	else 
	{
		cmd_lcd(0x01);
		display_lcd(" PASSWORD NOT MATCH");	
				       			
		for(n=0;n<5;n++)
		{
			buzzer=1;
			delay_ms(100);
			buzzer=0;
			delay_ms(100);
		}
	}
}


