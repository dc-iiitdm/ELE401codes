
/**KEYPAD FUNCTIONS DECLARATION**/
unsigned char key();
void password(void);  

/** VARIABLES DECLARATION **/
unsigned char j,pwd[15],passwd[]="12345",pass1[]="54321";
unsigned char colval,rowval;


/**KEYPAD PIN CONNECTIONS**/
sbit row0=P2^0;
sbit row1=P2^1;
sbit row2=P2^6;
sbit row3=P2^7;	
sbit col0=P2^5;
sbit col1=P2^4;
sbit col2=P2^3;
sbit col3=P2^2;


/** KEYPAD ARRAY **/
unsigned char keypad[4][4]={'1','2','3','4',
                            '5','6','7','8',
                            '9','0','*','#',
                            ' ','x','d','y' };



/**KEYPAD FUNCTION**/
unsigned char key(void)
{
		row0=row1=row2=row3=0;
		col0=col1=col2=col3=1;
	
		while((col0 && col1 && col2 && col3));

		while(1)
		{
			row0=0;
			row1=1;
			row2=1;
			row3=1;
			if(!(col0 && col1 && col2 && col3))
			{
				rowval=0;
				break;
			}
			row0=1;
			row1=0;
			row2=1;
			row3=1;
			if(!(col0 && col1 && col2 && col3))
			{
				rowval=1;
				break;
			}
			row0=1;
			row1=1;
			row2=0;
			row3=1;
			if(!(col0 && col1 && col2 && col3))
			{
				rowval=2;
				break;
			}
			row0=1;
			row1=1;
			row2=1;
			row3=0;
			if(!(col0 && col1 && col2 && col3 ))
			{
				rowval=3;
				break;
			}
		}

		if(col0==0)
			colval=0;
		else if(col1==0)
			colval=1;
		else if(col2==0)
			colval=2;
		else if(col3==0)
			colval=3;

		while(!(col0 && col1 && col2 && col3));
		delay_ms(50);
		return(keypad[rowval][colval]);
}

/** PASSWORD FUNCTION DEFINATION **/
void password(void)       //PASSWORD CHECKING
{
	char l;
	l=0;
	while(1)
	{
		j=key();

		if(j=='#')
			break;
		if(j=='*')
		{
			if(l!=0)
			{
				--l;
				cmd_lcd(0x10);	//SHIFT CURSOR TO LEFT
				data_lcd(' ');
				cmd_lcd(0x10);	//SHIFT CURSOR TO LEFT
			}
		}
		else
		{
			pwd[l++]=j;
			data_lcd('*');
		}
	}
	pwd[l]='\0';	
}


