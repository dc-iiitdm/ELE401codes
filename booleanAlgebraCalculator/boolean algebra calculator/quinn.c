// This code can be used to solve a truth table and give the out using quinMcCluskey algorithm.
// initialize powerQuinn

#include <stdio.h>

// Converts a given integer into a binary string and stores it in the array Grouping table;
void binaryConvert(int);

void arrayCopy(int);

void quinMcCluskey1(void);
void quinMcCluskey2(void);

void pairer(int,int);
int powerQuinn(int,int);

int variables,outs,numberOfMinterms = 0,numberOfDontCares = 0;

int minterm[16]; // Maximum possible input literals are 2^4 i.e. 16, so there can be atmax 16 minterms.
int groupingTable[81][23];
int binaryString1[4];
int mintermsArray[17][19];

char out[4];
char out1[200];

int li1 = 0;
int li2 = 0;
int li3 = 0;

int row,c,m;
char readq,valq;
char c1,c2,c3;

// All declarations

int continueOrHalt,maxMinTerm,groupingTableIndex,mintermIterator,mintermsArrayIterator,mintermsArrayIndex,presentOnlyOnce,implicantIndex,numberOfMintermsLeft,maxImplicant,maxNumberOfMintermsPossible,numberOfColumns,bCopy,out1Index;

/* Logic Behind number of rows and columns of grouping table. As we have 4 variables at max, there are 5 groups possible. Group with 0 -, 1 - and so on upto 4 -. In each group the maximum number of elements possible are 16+32+24+8+1 = 81.
Columns, first 16 columns to identify which minterms are present in it. Then 4 columns to determine the input string and last 3 columns to determine whether the string is paired once, whether the string has paired with anything once and number of 1's in the group.*/

void quinns()
{
  LCD_Clear();
	LCD_Goto(1,1);
 	LCD_Send_String("Enter number of");
	LCD_Goto(2,1);
	LCD_Send_String("input literals");
  
	readq = Keypad_Read();
	valq = key_pressed(readq);
	variables = valq;
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_String("No. of literals");
	LCD_Goto(2,1);
	LCD_Send_Character(variables+48);
	Delay();

  if((variables>=2)&&(variables<=4))
    {
      //valid variables and outs, continue
      out1Index = 0;
      out[0] = 'a'; out[1] = 'b';out[2] = 'c';out[3] = 'd';
      continueOrHalt = -1;
      maxMinTerm = powerQuinn(2,variables);
      // initialize minterm array
			// Initialize binary String 1 array
			
      li1 = 0;
		for(li1 = 0;li1<16;li1++)
			{
				minterm[li1] = 100;
				if(li1<4)
					{
						binaryString1[li1] = 100;
					}
			}

      //Initialize groupingTable array
			li1 = 0;
			
      for(li1 = 0;li1<81;li1++)
				{
					for(li2 = 0;li2<23;li2++)
						{
							groupingTable[li1][li2] = 100;
						}
				}
      
      // Get inputs for the minterms.

  LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_String("Enter minterms &");
	LCD_Goto(2,1);
	LCD_Send_String("dont care terms");
	Delay();
	LCD_Clear();
	LCD_Goto(1,1);
	LCD_Send_String("Add 100 to ");
	LCD_Goto(2,1);
	LCD_Send_String("minterms");
	Delay();
	LCD_Clear();
	LCD_Goto(1,1);	
	LCD_Send_String("Add 200 to ");
	LCD_Goto(2,1);
	LCD_Send_String("dont cares");
	Delay();
	LCD_Clear();			
	LCD_Goto(1,1);
	LCD_Send_String("Enter any number");
	LCD_Goto(2,1);
	LCD_Send_String(">= 300 to stop");
	Delay();
      while(continueOrHalt!=18)
				{
					LCD_Clear();
					LCD_Goto(1,1);
					//scanf("%d",&continueOrHalt);
					readq = Keypad_Read();
					c1 = key_pressed(readq);
					LCD_Send_Character(c1+48);
					
					readq = Keypad_Read();
					c2 = key_pressed(readq);
					LCD_Goto(1,2);
					LCD_Send_Character(c2+48);
						
					readq = Keypad_Read();
					c3 = key_pressed(readq);
					LCD_Goto(1,3);
					LCD_Send_Character(c3+48);
					
					Delay();
					
					if(c1==2)
					{
						continueOrHalt = -1*(10*c2+c3)-1;
					}
					else if(c1==1)
					{
						continueOrHalt = 10*c2+c3;
					}
					else if(c1 == 3)
					{
						continueOrHalt = 18; // Automatically stops.
					}
					else
					{
						continueOrHalt = 16; // Automatically displays error.	
					}
					
					
					if(continueOrHalt==18)
						{
							LCD_Clear();
							/*LCD_Send_String("Computing");
							Delay();
							break;*/
						}
					else if((continueOrHalt<maxMinTerm)&&(-1*continueOrHalt<=maxMinTerm))
						{
							if((continueOrHalt>=0)&&(minterm[continueOrHalt] == 100))
								{
									if(minterm[continueOrHalt] == 100)
										{
											minterm[continueOrHalt] = continueOrHalt;
											binaryConvert(continueOrHalt);
											numberOfMinterms++;
											/*LCD_Clear();
											LCD_Goto(1,1);
											LCD_Send_String("Minterms incremented");
											Delay();*/
										}
								}
							else if((continueOrHalt<0)&&(minterm[-1*continueOrHalt-1] == 100))
								{
									if(minterm[-1*continueOrHalt] == 100)
										{
											minterm[-1*continueOrHalt-1] = continueOrHalt;
											binaryConvert(-1*continueOrHalt-1);
											numberOfDontCares++;
											/*LCD_Clear();
											LCD_Goto(1,1);
											LCD_Send_String("Dontcares incremented");
											Delay();
											*/
										}							
								}
						}
					else
						{
							LCD_Clear();
							LCD_Goto(1,1);
							LCD_Send_String("Invalid. ReEnter");
							Delay();
						}
				}

      // Quin McCluskey first step, start pairing all the terms to get essential min terms.
      // printf("The grouping table is\n";
     
     if(numberOfMinterms == 0)
			{
					out1[out1Index] = '0';
					out1Index++;
					LCD_Clear();
					LCD_Goto(1,1);
					LCD_Send_Character('0');
			}
      else if(numberOfMinterms+numberOfDontCares == maxMinTerm)
			{
				out1[out1Index] = '1';
				out1Index++;
				LCD_Clear();
				LCD_Goto(1,1);
				LCD_Send_Character('1');
				
			}
      else
			{
	      quinMcCluskey1();

	      // Quin McCluskey pairing step.
	
	      quinMcCluskey2();
     	

      if(out1[out1Index-1]=='+')
				{
					 out1Index--;
				}
      
      LCD_Clear();
      LCD_Goto(1,1);
      row = 1;
      c = 1;
      m = 1;
      for(li1 = 0;li1<out1Index;li1++)
				{
					if(c>16)
					{
						row = 2;
						c = 0;
					}
					if(m>32)
					{
						Delay();
						row = 1;
						c = 1;
						m = 1;
					}
					
						LCD_Goto(row,c);
						LCD_Send_Character(out1[li1]);	
						c++;
						m=c;

				}
      //printf("\n");
    }
	}
  else
    {
     	LCD_Clear();
		LCD_Goto(1,1);
		LCD_Send_String("Invalid. ReEnter");
		Delay();
    }
  
}
	


void binaryConvert(int minTerm)
{
  int quotient = minTerm;
  int remainder = 0;
  int numberOf1s = 0;
  int binaryString1Index = 4;
  
  while(quotient>0)
    {
      remainder = quotient%2;
      quotient = quotient/2;
      if(remainder == 1)
				{
					numberOf1s++;
				}
      binaryString1[binaryString1Index-1] = remainder;
      binaryString1Index--;
    }

	li1 = 0;	
  for(li1 = 4-variables;li1<binaryString1Index;li1++)
    {
      // printf("Hi for loop i is "<<li1<<"\n";
      binaryString1[li1] = 0;
    }

  groupingTableIndex = -1;
  
  if(numberOf1s == 0)
    {
      groupingTableIndex = 0;
    }
  else if(numberOf1s == 1)
    {
      for(li1 = 1;li1<=4;li1++)
	{
	  if(groupingTable[li1][22] == 100)
	    {
	      groupingTableIndex = li1;
	      break;
	    }
	}
    }
   else if(numberOf1s == 2)
    {
      for(li1 = 5;li1<=10;li1++)
				{
					if(groupingTable[li1][22] == 100)
						{
							groupingTableIndex = li1;
							break;
						}
				}
    }
   else if(numberOf1s == 3)
    {
      for(li1 = 11;li1<=14;li1++)
				{
					if(groupingTable[li1][22] == 100)
						{
							groupingTableIndex = li1;
							break;
						}
				}
    }
   else if(numberOf1s == 4)
    {
      groupingTableIndex = 15;
    }

   groupingTable[groupingTableIndex][22] = numberOf1s;
   groupingTable[groupingTableIndex][minTerm] = 1;
   arrayCopy(groupingTableIndex);
}

void arrayCopy(int index)
{
	li1 = 0;
  for(li1 = 0;li1<4;li1++)
    {
      groupingTable[index][li1+16] = binaryString1[li1];
    }
}

void quinMcCluskey1()
{
  //printf("hi\n");
  int groupingTableRowIndex = 0;
  //int loopBreakedOrNot = 0;
  
  int groupingTableNextIndex = 0;
  int groupingTableNextIndexCopy = 0;
  int nextGroupExists = 0;
  
  while(groupingTableRowIndex<81)
    {
      // Finding the element of the first group to pair.
      // Finding Current Group Number.
      for(li1 = groupingTableRowIndex;li1<81;li1++)
				{
					if((groupingTable[li1][22]!=100)&&(groupingTable[li1][21]==100))
						{
							//printf("hi inside loop\n");
							groupingTableRowIndex = li1;
							//loopBreakedOrNot = 1;
							break;
						}
				}
      
      /*if(loopBreakedOrNot != 1)
				{
					//printf("hi\n");
					break;
				}
      */
			
      //printf(loopBreakedOrNot<<"\n";
      //loopBreakedOrNot = 0;
      //printf("Current groupingTable index %d \n",groupingTableRowIndex);
      
      // Find the starting index of the next group to pair with.
      // If difference between number of 1s of current element and element of next group is 1 means groupingTableNext Index is already calculated.
   
      if(groupingTable[groupingTableNextIndex][22]-groupingTable[groupingTableRowIndex][22]!=1)
				{
					//printf("hi in if\n");
					for(li1 = groupingTableRowIndex+1;li1<81;li1++)
						{
							if(groupingTable[li1][22]-groupingTable[groupingTableRowIndex][22]==1)
								{
									//printf("hi next group exists\n";
									nextGroupExists = 1;
									groupingTableNextIndex = li1;
									groupingTableNextIndexCopy = li1;
									break;
								}
							else if((groupingTable[li1][22]!=100)&&((groupingTable[li1][22]-groupingTable[groupingTableRowIndex][22]>1)||(groupingTable[li1][22]-groupingTable[groupingTableRowIndex][22]<0)))
								{
									//printf("hi no next group\n";
									nextGroupExists = 0;
									break;
								}
							else
								{
									nextGroupExists = 2;
								}
						}
				}    
      
      if(nextGroupExists == 1)
				{
					//printf("Next groupingTable index in if %d \n",groupingTableNextIndex);
					while(groupingTable[groupingTableNextIndexCopy][22]-groupingTable[groupingTableRowIndex][22]==1)
						{
							//printf("Next GroupingTable index in loop %d \n",groupingTableNextIndexCopy);
							// Check both strings and store them in appropriate location.
							// Change bit no 20 on both indices and 21 on current index;
							pairer(groupingTableRowIndex,groupingTableNextIndexCopy);
							
							groupingTable[groupingTableRowIndex][21] = 1;
							
							//printf("Next grouping table value is %d \n",groupingTableNextIndexCopy);
							groupingTableNextIndexCopy++;
							// nextGroupExists = 0;
						 
						}
					
					//printf("\n");
					groupingTableNextIndexCopy = groupingTableNextIndex;
				}
      else if(nextGroupExists == 0)
				{
					// As this means there is no second group, no pairing possible.Go to the next group.
					// printf("i value is %d \n",groupingTableRowIndex);
					int groupingTableRowIndexCopy = groupingTableRowIndex;
					while((groupingTableRowIndex<81)&&(groupingTable[groupingTableRowIndex][22]==groupingTable[groupingTableRowIndexCopy][22]))
						{
							groupingTableRowIndex++;
							//printf("in while %d \n",groupingTableRowIndex);
						}
					
				}
      else
				{
					break;
				}
	   
    }
}


void pairer(int groupIndex1,int groupIndex2)
{
  //printf("HI pairer\n");
  int bitsChanged = 0;
  int changeArray[4];
  int indexToStore = -1;
  // Initialize change array
  for(li1 = 0;li1<4;li1++)
    {
      changeArray[li1] = 100;
    }
  
  // printf("The first string is ");
  for(li1 = 16;li1<20;li1++)
    {
      //printf("%d ",groupingTable[groupIndex1][li1]); 
    }
  //printf("\nThe second string is ");
  
   for(li1 = 16;li1<20;li1++)
    {
      // printf("%d ",groupingTable[groupIndex2][li1]);
    }
   //printf("\n");
  for(li1 = 0;li1<4;li1++)
    {
      if((groupingTable[groupIndex1][li1+16] != groupingTable[groupIndex2][li1+16]))
				{
					if(bitsChanged==0)
						{
							bitsChanged++;
							changeArray[li1] = -1;
						}
					else
						{
							bitsChanged++;
							break;
						}
				}
  
      if(changeArray[li1]!=-1)
			{
				changeArray[li1] = groupingTable[groupIndex1][li1+16];
			}
    }

  if(bitsChanged == 1)
    {
      //printf("Pairing possible for indexes %d and %d \n",groupIndex1,groupIndex2);
       
      groupingTable[groupIndex1][20] = 1;
      groupingTable[groupIndex2][20] = 1;
	
      // This means that they are valid pair of terms to group.
      if((0<=groupIndex1)&&(groupIndex1<=15))
				{
					// 1st table.
					indexToStore = 16;
				}
      else if((16<=groupIndex1)&&(groupIndex1<=47))
				{
					//2nd table 
					indexToStore = 48;
				}
      else if((48<=groupIndex1)&&(groupIndex1<=71))
				{
					//3rd table
					indexToStore = 72;
				}
      else if((72<=groupIndex1)&&(groupIndex1<=79))
				{
					//4th table
					indexToStore = 80;
				}
      else if(groupIndex1==80)
				{
					//5th table
					// This case itself it not possible.
				}
      
      //printf("The index to store is %d \n",indexToStore);

      for(li1 = indexToStore;li1<81;li1++)
				{
					int arrayEqual = 1;
					if(groupingTable[li1][22]!=100)
						{
							// If its not an empty slot, compare both the paired string and string in that location.
							for(li2 = 0;li2<4;li2++)
								{
									if(groupingTable[li1][li2+16]!=changeArray[li2])
										{
											arrayEqual = 0;
											break;
										}
								}

							if(arrayEqual == 1)
								{
									// Paired string already exists.
									// printf("Paired string already exists\n");
									break;
								}

						}
					else
						{
							// Got a location to store, store the string.
							// First keep the term present in the string. For e.g. if the string is an pair from 0, 1 keep 0,1 in the new string as 1.
							
							for(li3 = 0;li3<16;li3++)
								{
									if((groupingTable[groupIndex1][li3] == 1)||(groupingTable[groupIndex2][li3] == 1))
										{
											groupingTable[li1][li3] = 1;
										}
								}

							// Update number of 1s in new string.
						
							groupingTable[li1][22] = groupingTable[groupIndex1][22];

							// printf("Stored at index %d ",li1); 
							//printf(The value stored is ");
							for(li2 = 16;li2<20;li2++)
								{
									groupingTable[li1][li2] = changeArray[li2-16];
									//printf("%d ",groupingTable[li1][li2]);
								}
							// printf("\n");
							
							break;
						}
				}
      
    }
  else
    {
      //printf("Pairing not possible for indexes %d and %d \n",groupIndex1,groupIndex2);
    }
}


void quinMcCluskey2()
{
  // Logic behind 17 = 16+1, in 4 variables scenario, in group having 1 dashes we get maximum elements i.e 32, so if 16 elements absent, 16 non paired elements will be there.
  // First row will be used to tell which minterm is present there.
  // Columns are numberOfMinterms(to check whether the minterm is present or not,1 for location of given string in grouping table,2 whether this picked in answer or not, 3 to store the number of minterms this term has.

  numberOfColumns = numberOfMinterms+3;
  //printf("%d \n",numberOfColumns);
  //int mintermsArray[17][numberOfColumns];

  // initialize minterms array.
  for(li1 = 0;li1<17;li1++)
    {
      for(li2 = 0;li2<numberOfColumns;li2++)
				{
					if(li2!=numberOfColumns-1)
						{
							mintermsArray[li1][li2] = 100;
						}
					else
						{
							mintermsArray[li1][li2] = 0;
						}
				}
    }

  maxNumberOfMintermsPossible = powerQuinn(2,variables);
  mintermIterator = 0;
  mintermsArrayIterator = 0;

  // Store the minterms in first row of minterm array.
  while(mintermIterator<(maxNumberOfMintermsPossible)&&(mintermsArrayIterator<numberOfColumns))
    {
      if((minterm[mintermIterator]>=0)&&(minterm[mintermIterator]!=100))
				{
					mintermsArray[0][mintermsArrayIterator] = mintermIterator;
					mintermsArrayIterator++;
				}
      mintermIterator++;
    }

  mintermsArrayIndex = 1;
  
  // Here store all the unpaired terms in the minterm array.
  for(li1 = 0;li1<81;li1++)
    {
      if((groupingTable[li1][20] == 100)&&(groupingTable[li1][22] != 100))
				{
					/*printf("%d \n",li1);
					for(li2 = 0;li2<20;li2++)
						{
							printf("%d \n",groupingTable[li1][li2]);
						}
					printf("\n");
					*/

					mintermsArray[mintermsArrayIndex][numberOfColumns-3] = li1;
					for(li2 = 0;li2<numberOfColumns-3;li2++)
						{
							//printf(groupingTable[li1][mintermsArray[0][li2]]<<" ";
							if(groupingTable[li1][mintermsArray[0][li2]] == 1)
								{
									//printf("%d ",groupingTable[li1][mintermsArray[0][li2]]);
									mintermsArray[mintermsArrayIndex][li2] = 1;
									//printf("the minterm array index is %d ",mintermsArray[mintermsArrayIndex][numberOfColumns-1]);
									mintermsArray[mintermsArrayIndex][numberOfColumns-1]++;
								}
						}
					//printf("\n");
					mintermsArrayIndex++;
				}
    }
  
  /* for(li1 = 0;li1<mintermsArrayIndex;li1++)
    {
      for(int li2 = 0;li2<numberOfColumns;li2++)
			{
				printf("%d ",mintermsArray[li1][li2]);
			}
      printf("\n");
    }
  */
  // Code for out
  
  presentOnlyOnce = 0;
  implicantIndex = 100;
  numberOfMintermsLeft = numberOfMinterms;

  // pick up the essential prime implicants.
  for(li1 = 0;li1<numberOfColumns-3;li1++)
    {
      presentOnlyOnce = 0;
      for(li2 = 1;li2<mintermsArrayIndex;li2++)
				{
					if((mintermsArray[li2][li1]==1)&&(mintermsArray[0][li1]!=100))
						{
							presentOnlyOnce++;
							implicantIndex = li2;
						}

					if(presentOnlyOnce>1)
						{
							implicantIndex = 100;
							break;
						}
					
				}

      if(implicantIndex != 100)
				{
					//printf("%d %d \n",implicantIndex,mintermsArray[0][li1]);
					
					mintermsArray[implicantIndex][numberOfColumns-2] = 1;
					
					for(li2 = 0;li2<numberOfColumns-3;li2++)
						{
							if(mintermsArray[implicantIndex][li2] == 1)
								{
									numberOfMintermsLeft--;
									mintermsArray[0][li2] = 100;
									for(li3 = 1;li3<mintermsArrayIndex;li3++)
										{
											if(mintermsArray[li3][li2] == 1)
												{
													mintermsArray[li3][li2] = 100;
													mintermsArray[li3][numberOfColumns-1]--;
												}
										}
								}
						}
					implicantIndex = 100;
				}
    }
  
  maxImplicant = -100;
  implicantIndex = -100;
  
  while(numberOfMintermsLeft>0)
    {
      // Implicant having maximum min terms.
      for(li1 = 1;li1<mintermsArrayIndex;li1++)
				{
					if(mintermsArray[li1][numberOfColumns-1]>maxImplicant)
						{
							implicantIndex = li1;
							maxImplicant = mintermsArray[implicantIndex][numberOfColumns-1];
						}
				}

      mintermsArray[implicantIndex][numberOfColumns-2] = 1;
			
      for(li2 = 0;li2<numberOfColumns-3;li2++)
	    {
	      if(mintermsArray[implicantIndex][li2] == 1)
					{
						numberOfMintermsLeft--;
						mintermsArray[0][li2] = 100;
						for(li3 = 1;li3<mintermsArrayIndex;li3++)
							{
								if(mintermsArray[li3][li2] == 1)
								{
									mintermsArray[li3][li2] = 100;
									mintermsArray[li3][numberOfColumns-1]--;
								}
							}
					}
	    }
    }
  
  // Print the out
  for(li1 = 1;li1<mintermsArrayIndex;li1++)
    {
      if(mintermsArray[li1][numberOfColumns-2] == 1)
				{
					for(li2 = 0;li2<variables;li2++)
						{
							
							if(groupingTable[mintermsArray[li1][numberOfColumns-3]][li2+16+4-variables] == 1)
								{
									out1[out1Index] = out[li2];
									out1Index++;
									//printf("%c",out[li2]);
								}
							else if(groupingTable[mintermsArray[li1][numberOfColumns-3]][li2+16+4-variables] == 0)
								{

									out1[out1Index] = '!';
									out1Index++;
									out1[out1Index] = out[li2];
									out1Index++;
									//printf("~%c",out[li2]);
								}
							
						}

					out1[out1Index] = '+';
					out1Index++;
				}
    }
  
		//printf("\n");
}

int powerQuinn(int base,int exponent)
{
	bCopy = 1;
	for(li1 = 1;li1<=exponent;li1++)
		{
				bCopy = base*bCopy;
		}
		
	return bCopy;
}


