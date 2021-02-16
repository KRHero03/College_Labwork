#include <stdio.h>
#include <stdlib.h>
#include "fact.h"
#include "Binary_To_Decimal.h"
#include "Decimal_To_Binary.h"

int main(int argc,char** argv[]){
	long num,i=0;
	num=atoi(argv[1]);
	printf("Please select the process to be done (1-Binary to Decimal 2-Decimal to Binary 3-Factorial):-");
	scanf("%ld",&i);
	if(num>=0){

	
		switch(i){
			case 1: printf("Binary to Decimal Conversion \n");
				long decimalAns=toDecimal(num);
				if(decimalAns==-1){
					printf("The given number is not in binary! \n");

				}else{
					printf("%ld in Decimal is %ld \n",num,decimalAns);
				}
				break;
			case 2:
				printf("Decimal to Binary Conversion \n");
				long binaryAns=toBinary(num);			
				printf("%ld in Binary is %ld \n",num,binaryAns);
				break;
			case 3:
				printf("Factorial of a Number \n");
				long p=fact(num);
				printf("Factorial of %ld is %ld \n",num,p);
				break;
			default:
				printf("Invalid Action!\n");

		}

	}else{
		printf("Invalid Argument! \n");

	}


}
