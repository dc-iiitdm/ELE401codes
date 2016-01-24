
// This code can be used to solve a truth table and give the output using quinMcCluskey algorithm.
// initialize power

#include <stdio.h>

// Converts a given integer into a binary string and stores it in the array Grouping table;
void binaryConvert(int);

void arrayCopy(int);

void quinMcCluskey1(void);
void quinMcCluskey2(void);

void pairer(int,int);
int power(int,int);

int variables,outputs,numberOfMinterms = 0;

int minterm[16]; // Maximum possible input literals are 2^4 i.e. 16, so there can be atmax 16 minterms.
int groupingTable[81][23];
int binaryString1[4];
int mintermsArray[17][19];

char output[4];

int loopIterator1 = 0;
int loopIterator2 = 0;
int loopIterator3 = 0;

// All declarations

int continueOrHalt,maxMinTerm,groupingTableIndex,mintermIterator,mintermsArrayIterator,mintermsArrayIndex,presentOnlyOnce,implicantIndex,numberOfMintermsLeft,maxImplicant,maxNumberOfMintermsPossible,numberOfColumns,baseCopy;

/* Logic Behind number of rows and columns of grouping table. As we have 4 variables at max, there are 5 groups possible. Group with 0 -, 1 - and so on upto 4 -. In each group the maximum number of elements possible are 16+32+24+8+1 = 81.
Columns, first 16 columns to identify which minterms are present in it. Then 4 columns to determine the input string and last 3 columns to determine whether the string is paired once, whether the string has paired with anything once and number of 1's in the group.*/

int main()
{
  printf("Enter the number of input literals\n");
  scanf("%d",&variables);

  if((variables>=2)&&(variables<=4))
    {
      //valid variables and outputs, continue
      output[0] = 'a'; output[1] = 'b';output[2] = 'c';output[3] = 'd';
      continueOrHalt = -1;
      maxMinTerm = power(2,variables);
      // initialize minterm array
			// Initialize binary String 1 array
			
      loopIterator1 = 0;
			for(loopIterator1 = 0;loopIterator1<16;loopIterator1++)
				{
					minterm[loopIterator1] = 100;
					if(loopIterator1<4)
						{
							binaryString1[loopIterator1] = 100;
						}
				}
      
      //Initialize groupingTable array
			loopIterator1 = 0;
			
      for(loopIterator1 = 0;loopIterator1<81;loopIterator1++)
				{
					for(loopIterator2 = 0;loopIterator2<23;loopIterator2++)
						{
							groupingTable[loopIterator1][loopIterator2] = 100;
						}
				}
      
      // Get inputs for the minterms.

      printf("Enter the minterms and dont care terms, follow these instructions\n1) Enter minterm in +ve.\n2) Dont Cares in -ve.\n3) And any number greater than 15 to stop.\n\n");
      while(continueOrHalt<=15)
				{
					scanf("%d",&continueOrHalt);
					
					if(continueOrHalt>15)
						{
							break;
						}
					else if((continueOrHalt<maxMinTerm)&&(-1*continueOrHalt<maxMinTerm))
						{
							if((continueOrHalt>=0)&&(minterm[continueOrHalt] == 100))
								{
									minterm[continueOrHalt] = continueOrHalt;
									binaryConvert(continueOrHalt);
									numberOfMinterms++;
								}
							else if((continueOrHalt<0)&&(minterm[-1*continueOrHalt] == 100))
								{
									minterm[-1*continueOrHalt] = continueOrHalt;
									binaryConvert(-1*continueOrHalt);
								}
						}
					else
						{
							printf("Invalid Minterm or dont care\n");
						}
				}

      // Quin McCluskey first step, start pairing all the terms to get essential min terms.
      // printf("The grouping table is\n";
      
      quinMcCluskey1();

      // Quin McCluskey pairing step.
	
      quinMcCluskey2();
     
    }
  else
    {
      printf("Invalid, variables must be more than 1 and less than 5.\n");
    }
  return 0;
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

	loopIterator1 = 0;	
  for(loopIterator1 = 4-variables;loopIterator1<binaryString1Index;loopIterator1++)
    {
      // printf("Hi for loop i is "<<loopIterator1<<"\n";
      binaryString1[loopIterator1] = 0;
    }

  groupingTableIndex = -1;
  
  if(numberOf1s == 0)
    {
      groupingTableIndex = 0;
    }
  else if(numberOf1s == 1)
    {
      for(loopIterator1 = 1;loopIterator1<=4;loopIterator1++)
	{
	  if(groupingTable[loopIterator1][22] == 100)
	    {
	      groupingTableIndex = loopIterator1;
	      break;
	    }
	}
    }
   else if(numberOf1s == 2)
    {
      for(loopIterator1 = 5;loopIterator1<=10;loopIterator1++)
				{
					if(groupingTable[loopIterator1][22] == 100)
						{
							groupingTableIndex = loopIterator1;
							break;
						}
				}
    }
   else if(numberOf1s == 3)
    {
      for(loopIterator1 = 11;loopIterator1<=14;loopIterator1++)
				{
					if(groupingTable[loopIterator1][22] == 100)
						{
							groupingTableIndex = loopIterator1;
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
	loopIterator1 = 0;
  for(loopIterator1 = 0;loopIterator1<4;loopIterator1++)
    {
      groupingTable[index][loopIterator1+16] = binaryString1[loopIterator1];
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
      for(loopIterator1 = groupingTableRowIndex;loopIterator1<81;loopIterator1++)
				{
					if((groupingTable[loopIterator1][22]!=100)&&(groupingTable[loopIterator1][21]==100))
						{
							//printf("hi inside loop\n");
							groupingTableRowIndex = loopIterator1;
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
					for(loopIterator1 = groupingTableRowIndex+1;loopIterator1<81;loopIterator1++)
						{
							if(groupingTable[loopIterator1][22]-groupingTable[groupingTableRowIndex][22]==1)
								{
									//printf("hi next group exists\n";
									nextGroupExists = 1;
									groupingTableNextIndex = loopIterator1;
									groupingTableNextIndexCopy = loopIterator1;
									break;
								}
							else if((groupingTable[loopIterator1][22]!=100)&&((groupingTable[loopIterator1][22]-groupingTable[groupingTableRowIndex][22]>1)||(groupingTable[loopIterator1][22]-groupingTable[groupingTableRowIndex][22]<0)))
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
  for(loopIterator1 = 0;loopIterator1<4;loopIterator1++)
    {
      changeArray[loopIterator1] = 100;
    }
  
  // printf("The first string is ");
  for(loopIterator1 = 16;loopIterator1<20;loopIterator1++)
    {
      //printf("%d ",groupingTable[groupIndex1][loopIterator1]); 
    }
  //printf("\nThe second string is ");
  
   for(loopIterator1 = 16;loopIterator1<20;loopIterator1++)
    {
      // printf("%d ",groupingTable[groupIndex2][loopIterator1]);
    }
   //printf("\n");
  for(loopIterator1 = 0;loopIterator1<4;loopIterator1++)
    {
      if((groupingTable[groupIndex1][loopIterator1+16] != groupingTable[groupIndex2][loopIterator1+16]))
				{
					if(bitsChanged==0)
						{
							bitsChanged++;
							changeArray[loopIterator1] = -1;
						}
					else
						{
							bitsChanged++;
							break;
						}
				}
  
      if(changeArray[loopIterator1]!=-1)
			{
				changeArray[loopIterator1] = groupingTable[groupIndex1][loopIterator1+16];
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

      for(loopIterator1 = indexToStore;loopIterator1<81;loopIterator1++)
				{
					int arrayEqual = 1;
					if(groupingTable[loopIterator1][22]!=100)
						{
							// If its not an empty slot, compare both the paired string and string in that location.
							for(loopIterator2 = 0;loopIterator2<4;loopIterator2++)
								{
									if(groupingTable[loopIterator1][loopIterator2+16]!=changeArray[loopIterator2])
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
							
							for(loopIterator3 = 0;loopIterator3<16;loopIterator3++)
								{
									if((groupingTable[groupIndex1][loopIterator3] == 1)||(groupingTable[groupIndex2][loopIterator3] == 1))
										{
											groupingTable[loopIterator1][loopIterator3] = 1;
										}
								}

							// Update number of 1s in new string.
						
							groupingTable[loopIterator1][22] = groupingTable[groupIndex1][22];

							// printf("Stored at index %d ",loopIterator1); 
							//printf(The value stored is ");
							for(loopIterator2 = 16;loopIterator2<20;loopIterator2++)
								{
									groupingTable[loopIterator1][loopIterator2] = changeArray[loopIterator2-16];
									//printf("%d ",groupingTable[loopIterator1][loopIterator2]);
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
  for(loopIterator1 = 0;loopIterator1<17;loopIterator1++)
    {
      for(loopIterator2 = 0;loopIterator2<numberOfColumns;loopIterator2++)
				{
					if(loopIterator2!=numberOfColumns-1)
						{
							mintermsArray[loopIterator1][loopIterator2] = 100;
						}
					else
						{
							mintermsArray[loopIterator1][loopIterator2] = 0;
						}
				}
    }

  maxNumberOfMintermsPossible = power(2,variables);
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
  for(loopIterator1 = 0;loopIterator1<81;loopIterator1++)
    {
      if((groupingTable[loopIterator1][20] == 100)&&(groupingTable[loopIterator1][22] != 100))
				{
					/*printf("%d \n",loopIterator1);
					for(loopIterator2 = 0;loopIterator2<20;loopIterator2++)
						{
							printf("%d \n",groupingTable[loopIterator1][loopIterator2]);
						}
					printf("\n");
					*/

					mintermsArray[mintermsArrayIndex][numberOfColumns-3] = loopIterator1;
					for(loopIterator2 = 0;loopIterator2<numberOfColumns-3;loopIterator2++)
						{
							//printf(groupingTable[loopIterator1][mintermsArray[0][loopIterator2]]<<" ";
							if(groupingTable[loopIterator1][mintermsArray[0][loopIterator2]] == 1)
								{
									//printf("%d ",groupingTable[loopIterator1][mintermsArray[0][loopIterator2]]);
									mintermsArray[mintermsArrayIndex][loopIterator2] = 1;
									//printf("the minterm array index is %d ",mintermsArray[mintermsArrayIndex][numberOfColumns-1]);
									mintermsArray[mintermsArrayIndex][numberOfColumns-1]++;
								}
						}
					//printf("\n");
					mintermsArrayIndex++;
				}
    }
  
  /* for(loopIterator1 = 0;loopIterator1<mintermsArrayIndex;loopIterator1++)
    {
      for(int loopIterator2 = 0;loopIterator2<numberOfColumns;loopIterator2++)
			{
				printf("%d ",mintermsArray[loopIterator1][loopIterator2]);
			}
      printf("\n");
    }
  */
  // Code for output
  
  presentOnlyOnce = 0;
  implicantIndex = 100;
  numberOfMintermsLeft = numberOfMinterms;

  // pick up the essential prime implicants.
  for(loopIterator1 = 0;loopIterator1<numberOfColumns-3;loopIterator1++)
    {
      presentOnlyOnce = 0;
      for(loopIterator2 = 1;loopIterator2<mintermsArrayIndex;loopIterator2++)
				{
					if((mintermsArray[loopIterator2][loopIterator1]==1)&&(mintermsArray[0][loopIterator1]!=100))
						{
							presentOnlyOnce++;
							implicantIndex = loopIterator2;
						}

					if(presentOnlyOnce>1)
						{
							implicantIndex = 100;
							break;
						}
					
				}

      if(implicantIndex != 100)
				{
					//printf("%d %d \n",implicantIndex,mintermsArray[0][loopIterator1]);
					
					mintermsArray[implicantIndex][numberOfColumns-2] = 1;
					
					for(loopIterator2 = 0;loopIterator2<numberOfColumns-3;loopIterator2++)
						{
							if(mintermsArray[implicantIndex][loopIterator2] == 1)
								{
									numberOfMintermsLeft--;
									mintermsArray[0][loopIterator2] = 100;
									for(loopIterator3 = 1;loopIterator3<mintermsArrayIndex;loopIterator3++)
										{
											if(mintermsArray[loopIterator3][loopIterator2] == 1)
												{
													mintermsArray[loopIterator3][loopIterator2] = 100;
													mintermsArray[loopIterator3][numberOfColumns-1]--;
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
      for(loopIterator1 = 1;loopIterator1<mintermsArrayIndex;loopIterator1++)
				{
					if(mintermsArray[loopIterator1][numberOfColumns-1]>maxImplicant)
						{
							implicantIndex = loopIterator1;
							maxImplicant = mintermsArray[implicantIndex][numberOfColumns-1];
						}
				}

      mintermsArray[implicantIndex][numberOfColumns-2] = 1;
			
      for(loopIterator2 = 0;loopIterator2<numberOfColumns-3;loopIterator2++)
	    {
	      if(mintermsArray[implicantIndex][loopIterator2] == 1)
					{
						numberOfMintermsLeft--;
						mintermsArray[0][loopIterator2] = 100;
						for(loopIterator3 = 1;loopIterator3<mintermsArrayIndex;loopIterator3++)
							{
								if(mintermsArray[loopIterator3][loopIterator2] == 1)
								{
									mintermsArray[loopIterator3][loopIterator2] = 100;
									mintermsArray[loopIterator3][numberOfColumns-1]--;
								}
							}
					}
	    }
    }
  
  // Print the output
  for(loopIterator1 = 1;loopIterator1<mintermsArrayIndex;loopIterator1++)
    {
      if(mintermsArray[loopIterator1][numberOfColumns-2] == 1)
				{
					for(loopIterator2 = 0;loopIterator2<variables;loopIterator2++)
						{
							
							if(groupingTable[mintermsArray[loopIterator1][numberOfColumns-3]][loopIterator2+16+4-variables] == 1)
								{
									printf("%c",output[loopIterator2]);
								}
							else if(groupingTable[mintermsArray[loopIterator1][numberOfColumns-3]][loopIterator2+16+4-variables] == 0)
								{
									printf("~%c",output[loopIterator2]);
								}
							
						}

					printf(" + ");
				}
    }
  
		printf("\n");
}

int power(int base,int exponent)
{
	baseCopy = 1;
	for(loopIterator1 = 1;loopIterator1<=exponent;loopIterator1++)
		{
				baseCopy = base*baseCopy;
		}
		
	return baseCopy;
}