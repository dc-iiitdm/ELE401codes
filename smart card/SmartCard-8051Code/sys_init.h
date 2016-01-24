void sys_init()
{
		buzzer = 0;
		green = 0;
		
		TMOD = 0x21;	//USART REGISTERS INITIALIZATION
		SCON = 0x50;
		PCON = 0X80;	//DOUBLE THE BAUD RATE
		TH1 = 0xFD;		//9600 BAUD RATE
		TR1 = 1;
		IE = 0x92;
	
		init_lcd();	//LCD INITIALIZATION FUNCTION CALLING
		display_lcd("***UNIQUE ID CARD***");//DISPLAY STRING ON LCD
		cmd_lcd(0xC0);	//2ND LINE DISPLAY
		display_lcd("****** DESIGN ******");//DISPLAY STRING ON LCD
		cmd_lcd(0x94);	//3rd LINE DISPLAY
		display_lcd("****** USING *******");//DISPLAY STRING ON LCD
		cmd_lcd(0xD4);	//4th LINE DISPLAY
		display_lcd("* SMART TECHNOLOGY *");//DISPLAY STRING ON LCD
		delay_ms(2000);	//2000 MILLISECONDS DELAY FUNCTION CALLING
		cmd_lcd(0x01);	//CLEAR SCREEN
}
