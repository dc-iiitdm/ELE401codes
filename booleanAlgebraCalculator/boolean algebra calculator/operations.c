////////////////////////////////////////////////////////////
// Binary Operations
#include <stdio.h>
char read;
char x;
char in;
char val;
int inputArray1[5];
int inputArray2[5];
int intermediateArray[5];

int outputArray[9];


int binaryToIntegerConvert(int);
void integerToBinaryConvert(void);
int power(int,int);

int loopIterator1,loopIterator2;

// All declarations
int choice,integerToReturn,integer1,integer2,baseCopy,output,quotient,remainder,outputArrayIndex;

void operations()
{
		LCD_Clear();
		LCD_Goto(1,1);
 		LCD_Send_String("1.ADD 2.MULTIPLY");
		LCD_Goto(2,1);
		LCD_Send_String("3.XS3 4.GRAYCODE");

  
		in = Keypad_Read();
		
		val = key_pressed(in);
		choice = val;
		LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_Character(choice);

  while((choice!=1)&&(choice!=2)&&(choice!=3)&&(choice!=4))
    {
			LCD_Clear();
			LCD_Goto(1,1);
     		LCD_Send_String("Invalid choice");
			LCD_Goto(2,1);
			LCD_Send_String("Enter Again");
      
			in = Keypad_Read();
			
			val = key_pressed(in);
			choice = val+48;
			LCD_Clear();
			LCD_Goto(1,1);
			LCD_Send_Character(choice);
    }

    if(choice==1 || choice == 2)
    {
    	LCD_Clear();
		LCD_Goto(1,1);
	  	LCD_Send_String("Enter input 1 in");
		LCD_Goto(2,1);
		LCD_Send_String("sign mag form");
		Delay();
		LCD_Clear();
	 	for(loopIterator1 = 4;loopIterator1>=0;loopIterator1--)
	    {
			read = Keypad_Read();
			x = key_pressed(read);
			LCD_Goto(1,5-loopIterator1);
			LCD_Send_Character(x+48);
			inputArray1[loopIterator1] = x;
	    }

		LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_String("Enter input 2 in");
		LCD_Goto(2,1);
		LCD_Send_String("sign mag form");
		Delay();
		LCD_Clear();
		for(loopIterator1 = 4;loopIterator1>=0;loopIterator1--)
		{
			read = Keypad_Read();
			x = key_pressed(read);
			LCD_Goto(1,5-loopIterator1);
			LCD_Send_Character(x+48);
			inputArray2[loopIterator1] = x;
		}

		integer1 = binaryToIntegerConvert(1);
 		integer2 = binaryToIntegerConvert(2);
    }
    else if(choice == 3)
    {
    	LCD_Clear();
		LCD_Goto(1,1);
	  	LCD_Send_String("Enter Input in");
		LCD_Goto(2,1);
		LCD_Send_String("sign mag form");
		Delay();
		LCD_Clear();
	 	for(loopIterator1 = 4;loopIterator1>=0;loopIterator1--)
	    {
			read = Keypad_Read();
			x = key_pressed(read);
			LCD_Goto(1,5-loopIterator1);
			LCD_Send_Character(x+48);
			inputArray1[loopIterator1] = x;
	    }

	    integer1 = binaryToIntegerConvert(1);
    }
    else if(choice == 4)
    {
    	LCD_Clear();
		LCD_Goto(1,1);
	  	LCD_Send_String("Enter Input in");
		LCD_Goto(2,1);
		LCD_Send_String("BinaryForm-5bits");
		Delay();
		LCD_Clear();
	 	for(loopIterator1 = 4;loopIterator1>=0;loopIterator1--)
	    {
			read = Keypad_Read();
			x = key_pressed(read);
			LCD_Goto(1,5-loopIterator1);
			LCD_Send_Character(x+48);
			inputArray1[loopIterator1] = x;
	    }

	    //integer1 = binaryToIntegerConvert(1);
    }

  
  
		/*LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_String("The integers are");
		Delay();
		LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_Integer(integer1);
		LCD_Goto(2,1);
		LCD_Send_Integer(integer2);
		Delay();*/

  if(choice == 1)
    {
      	output = integer1+integer2;
		integerToBinaryConvert();
		LCD_Clear();
		LCD_Send_String("The output is");
		Delay();
		LCD_Clear();
		LCD_Goto(1,1);

		for(loopIterator1 = 8;loopIterator1>=0;loopIterator1--)
		{
		LCD_Goto(1,9-loopIterator1);
		LCD_Send_Integer(outputArray[loopIterator1]);
		}
    }
  else if(choice == 2)
    {
		output = integer1*integer2;
		integerToBinaryConvert();
		LCD_Clear();
		LCD_Send_String("The output is");
		Delay();
		LCD_Clear();
		LCD_Goto(1,1);

		for(loopIterator1 = 8;loopIterator1>=0;loopIterator1--)
		{
		LCD_Goto(1,9-loopIterator1);
		LCD_Send_Integer(outputArray[loopIterator1]);
		}
    }
    else if(choice == 3)
    {
    	output = integer1+3;
    	integerToBinaryConvert();
		LCD_Clear();
		LCD_Send_String("The output is");
		Delay();
		LCD_Clear();
		LCD_Goto(1,1);

		for(loopIterator1 = 8;loopIterator1>=0;loopIterator1--)
		{
			LCD_Goto(1,9-loopIterator1);
			LCD_Send_Integer(outputArray[loopIterator1]);
		}
    }
    else if(choice == 4)
    {
    	LCD_Clear();
		LCD_Send_String("Processing");
    	outputArray[4] = inputArray1[4];
    	for(loopIterator1 = 3;loopIterator1>=0;loopIterator1--)
    	{
    		outputArray[loopIterator1] = inputArray1[loopIterator1+1] ^ inputArray1[loopIterator1];
    	}
    	LCD_Clear();
		LCD_Send_String("The output is");
		Delay();
		LCD_Clear();
		LCD_Goto(1,1);
		for(loopIterator1 = 5;loopIterator1>=0;loopIterator1--)
		{
			LCD_Goto(1,6-loopIterator1);
			LCD_Send_Integer(outputArray[loopIterator1]);
		}
    }
}

int binaryToIntegerConvert(int arrayToChoose)
{
  integerToReturn = 0;
  
  if(arrayToChoose == 1)
    {
      for(loopIterator1 = 0;loopIterator1<5;loopIterator1++)
	{
	  intermediateArray[loopIterator1] = inputArray1[loopIterator1];
	}
    }
  else
    {
       for(loopIterator1 = 0;loopIterator1<5;loopIterator1++)
	{
	  intermediateArray[loopIterator1] = inputArray2[loopIterator1];
	}
    }

  for(loopIterator1 = 0;loopIterator1<4;loopIterator1++)
    {
      if(intermediateArray[loopIterator1]!=0)
	{
	  integerToReturn = integerToReturn + power(2,loopIterator1);
	}
      
    }

  if(intermediateArray[4] == 1)
    {
      return -1*integerToReturn; 
    }
  else
    {
      return integerToReturn;
    }
}

int power(int base,int exponent)
{
  baseCopy = 1;
  for(loopIterator2 = 1;loopIterator2<=exponent;loopIterator2++)
    {
      baseCopy = base*baseCopy;
    }
		
  return baseCopy;
}

void integerToBinaryConvert()
{
  if(output<0)
    {
      outputArray[8] = 1;
      output = -1*output;
    }
  else
    {
      outputArray[8] = 0;
    }

  quotient = output;
  remainder = 0;
  outputArrayIndex = 0;

  while(quotient>0)
    {
      remainder = quotient%2;
      quotient = quotient/2;
      outputArray[outputArrayIndex] = remainder;
      outputArrayIndex++;
    }
  
  for(loopIterator1 = outputArrayIndex;loopIterator1<8;loopIterator1++)
    {
      outputArray[loopIterator1] = 0;
    }
}








/////////////////////////////////////////////////////////////