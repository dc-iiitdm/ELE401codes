#include<reg52.h>

sbit led = P1^0;

void delay(unsigned char i)
{
	unsigned int j;
	for(j=0;j<123;j++);
}

main()
{
	while(1)
	{
		led = 0;
		delay(500);
		led = 1;
		delay(500);
	}
}
