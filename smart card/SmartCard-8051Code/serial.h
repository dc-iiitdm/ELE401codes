/**VARIABLES DECLARATION**/
bit flag;
bit r_flag = 0;
int i=0;
char idata buff[50],ch;

/**INTERRUPT SERVICE ROUTINE**/							 
void serial_intr(void) interrupt 4
{
	if(TI == 1)
	{
		TI = 0;
		flag = 1;
	} 
	else if(RI==1)
	{
		ch=SBUF;
		if((ch!='\r') && (ch!='\n'))
			buff[i++]=ch;
		else
			buff[i++]='\0';    
		if(ch=='\n')
		{
	 		r_flag=1;   
			i=0;
		}
		RI=0;

	}

}

/**TRANSMISSION FUNCTION**/
void print(char *str)
{
	while(*str)
	{
		flag = 0;
		SBUF = *str++;
		while(flag == 0);
	}
}
