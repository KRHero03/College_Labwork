#include <stdio.h>
#include "STRING.h"
int main()
{
	int t=1;
	printf("--------------------------------\n");
	printf("Assignment 2 - String Operations\n");
	printf("--------------------------------\n");
	
	char primary[255],secondary[255];
	long* ans=(long*) malloc(2*sizeof(long));
	printf("Please enter primary string:-");
	gets(primary);
	printf("Please enter secondary string:-");
	gets(secondary);
	printf("Please enter your task from the given menu:- \n");	
	printf("(1) Find the length of the string\n(2) Concatenation of two different strings\n(3) Retrieve the first index/position/occurrence of given symbol in the string\n(4) Retrieve the last occurrence of given symbol in the string\n(5) Concatenate the reversal of string at the end\n(6) Duplicate and concate the main string\n(7) Compare Strings\n(8) Compare Strings without case sensitivity\n(9) Reverse of the given string\n(10) Convert the string to upper case\n(11) Convert the string to lower case\n(12) Convert the string to Title Case\n(13) Replace the given substring in the main string from the given position\n(14) Retrieve the index of the substring in the main string\n(15) Check the given string is palindrome or not (using loop)\n(16) Display and count the vowels present in the string\n(17) Count the characters and words\n(18) Restart\n(19)Exit \n");
	
	while(t!=19)
	{	
		scanf("%d",&t);
		if(t==19)
			break;
		char x;		
		switch(t){
			case 1:
				printf("Length of Primary String:- %ld\n",length(primary));
			break;
			case 2:
				printf("Concatenation of Primary and Secondary Strings:- %s\n",concat(primary,secondary,255));
			break;
			case 3:				
				printf("Please enter character to be found in Primary String:- ");
				scanf(" %c",&x);
				printf("First occurence of %c in Primary String:- %ld\n",x,findPos(primary,x));
			break;
			case 4:				
				printf("Please enter character to be found in Primary String:- ");	
				scanf(" %c",&x);
				printf("Last occurence of %c in Primary String:- %ld\n",x,findPosRev(primary,x));
			break;			
			case 5:
				printf("Concatenation of Primary and Reversed Primary String:- %s\n",concatR(primary,255));
			break;			
			case 6:
				printf("Concatenation of Primary string with its duplicate:- %s\n",concatD(primary,255));
			break;					
			case 7:
				if(compare(primary,secondary))
					printf("Primary and Secondary strings are same.\n");
				else
					printf("Primary and Secondary strings are not same.\n");
			break;
								
			case 8:
				if(compareWC(primary,secondary))
					printf("Primary and Secondary strings are same ignoring cases.\n");
				else
					printf("Primary and Secondary strings are not same ignoring cases.\n");
			break;						
			case 9:
				printf("Reverse of Primary String:- %s\n",rev(primary));
			break;						
			case 10:
				printf("Primary string in Upper Case:- %s\n",toUpperCase(primary));
			break;						
			case 11:
				printf("Primary string in Lower Case:- %s\n",toLowerCase(primary));
			break;						
			case 12:
				printf("Primary string in Title Case:- %s\n",toTitleCase(primary));
			break;						
			case 13:
				
				printf("Please enter index in Primary String where Secondary String needs to be inserted:- ");
				int p=0;
				scanf("%d",&p);
				printf("Modified String(Will return Primary String if invalid):- %s\n",replace(primary,secondary,p));
			break;						
			case 14:
				printf("Position of Secondary String in Primary String:- %ld\n",getPosString(primary,secondary));
			break;
			case 15:
				if(isPalindrome(primary))
					printf("Primary String is a palindrome.\n");
				else
					printf("Primary String is not a palindrome.\n");
			break;									
			case 16:
				printf("No. of Vowels in Primary String:- %ld\n",countVowels(primary));
			break;
			case 17:
				ans=countLW(primary);				
				printf("No. of letters in Primary String: %ld\nNo. of words in Primary String: %ld\n",ans[0],ans[1]);
			break;
			case 18:
				main();
			break;
			
		}
		printf("End of Program. Refer above menu and select your task. Note that your task may have modified original string!\n");
	}
}
