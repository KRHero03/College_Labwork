#include <stdio.h>
char* leftShift(char* x,long n)
{
	char* y= (char* )calloc(8,sizeof(char));
	
	long i=0;
	for(i=0;i<8;i++)
	{
		*(y+i)='0';
	}
	for(i=0;i<=3;i++)
	{
		*(y+4-n+i)=*(x+i);
	}
	return y;
}

void addBinary(char* ans,char* y)
{
	long carry=0;
	long i=0;
	for(i=7;i>=0;i--)
	{
		long p=0,q=0;
		p=*(ans+i)-'0';
		q=*(y+i)-'0';
		
		switch(p+q+carry)
		{
			case 0:
				*(ans+i)='0';
				carry=0;
				break;
			case 1:
				*(ans+i)='1';
				carry=0;
				break;
			case 2:
				*(ans+i)='0';
				carry=1;
				break;
			case 3:
				*(ans+i)='1';
				carry='1';
				break;

		}
	
	}
}
int main(int argc,char** argv)
{
	char* num1=(char* )calloc(4,sizeof(char));
	char* num2=(char* )calloc(4,sizeof(char));
	num1=argv[1];
	num2=argv[2];
	char* ans=(char* )calloc(8,sizeof(char));
	long i=0;
	for(i=0;i<8;i++)
	{
		*(ans+i)='0';
	}
	for(i=3;i>=0;i--)
	{
		if(num2[i]=='1')
		{
			char* y=leftShift(num1,3-i);
			addBinary(ans,y);
		}		
  
	}
	printf("Multiplication of unsigned Number: %s \n",ans);
}
