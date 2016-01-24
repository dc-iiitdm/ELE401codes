/**LCD CONNECTION**/
#define LCD P0


/**LCD FUNCTIONS DECLARATION**/
void init_lcd(void);
void cmd_lcd(unsigned char);
void data_lcd(unsigned char);
void display_lcd(unsigned char *);
void integer_lcd(unsigned int);



/**LCD INITIALIZATION FUNCTION**/		
void init_lcd(void)
{
	cmd_lcd(0x02);//RETURN HOME
	cmd_lcd(0x28);//4BIT MODE
	cmd_lcd(0x0C);//DISPLAY ON CURSOR OFF
	cmd_lcd(0x06);//SHIFT CURSOR TO RIGHT
	cmd_lcd(0x01);//CLEAR SCREEN
}

/**LCD COMMAND FUNCTION**/
void cmd_lcd(unsigned char var)
{
	LCD = ((var & 0xF0) | 0x08);//RS=0,EN=1
	LCD = 0;
	LCD = ((var << 4) | 0x08);//RS=0,EN=1
	LCD = 0;
	delay_ms(1);
}

/**LCD DATA FUNCTION**/
void data_lcd(unsigned char var)
{
	LCD = ((var & 0xF0) | 0x0a);//RS=1,EN=1
	LCD = 0;
	LCD = ((var << 4) | 0x0a);//RS=1,EN=1
	LCD = 0;
	delay_ms(1);
}

/**LCD STRING FUNCTION**/
void display_lcd(char *str)
{
	while(*str)
	data_lcd(*str++);
}

/**LCD INTEGER FUNCTION**/
void integer_lcd(unsigned int n)
{
	unsigned char c[6];
	unsigned int i=0;
	if(n<0)
	{
		data_lcd('-');
		n=-n;
	}
	if(n==0)
		data_lcd('0');
	while(n>0)
	{
		c[i++]=(n%10)+48;
		n/=10;
	}
	while(i-->=1)
	data_lcd(c[i]);
}


