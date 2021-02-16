#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
int main()
{
	printf("Size of short int : %lu \nSize of int : %lu \nSize of long : %lu \nSize of float : %lu \nSize of double: %lu \nSize of Char: %lu \n",sizeof(short int),sizeof(int),sizeof(long),sizeof(float),sizeof(double),sizeof(char));

	printf("Range for Short Integer: %ld to %ld \n",SHRT_MIN,SHRT_MAX);
	printf("Range for Integer: %d to %d \n",INT_MIN,INT_MAX);
	printf("Range for Long: %ld to %ld \n",LONG_MIN,LONG_MAX);
	printf("Range for Char: %d to %d \n",CHAR_MIN,CHAR_MAX);
	printf("Range for Float: %lf to %lf \n",FLT_MIN,FLT_MAX);
	printf("Range for Double: %lf to %lf \n",DBL_MIN,DBL_MAX);
	long x;
	printf("Please enter a number: ");
	scanf("%ld",&x);
	if(x>=CHAR_MIN && x<=CHAR_MAX)
		printf("%ld is in the Character Range. \n",x);
	else if(x>=SHRT_MIN && x<=SHRT_MAX)
		printf("%ld is in the Short Integer Range. \n",x);
	else if(x>=INT_MIN && x<=INT_MAX)
		printf("%ld is in the Integer Range. \n",x);
	else if(x>=LONG_MIN&& x<=LONG_MAX)
		printf("%ld is in the Long Integer Range. \n",x);
	else if(x>=LONG_MAX && x<=ULONG_MAX)
		printf("%ld is in the Unsigned Long Integer Range. \n",x);
	else
		printf("%ld is beyond the range of Unsigned Long Integer. \n",x);
}
