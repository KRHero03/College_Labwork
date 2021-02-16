#include <stdio.h>
void twosComp(char* x)
{
	
	long i=3;
	for(i=3;i>=0;i--)
	{
		if(x[i]=='1')
		{			
			long j=i-1;
			for(j=i-1;j>=0;j--)
			{
				if(x[j]=='0')
					x[j]='1';
				else
					x[j]='0';				
			}
			return;
		}
	}
}

int main(int argc,char** argv)
{
	char* num1=(char* )calloc(4,sizeof(char));
	char* num2=(char* )calloc(4,sizeof(char));
	num1=argv[1];
	num2=argv[2];
	
	

	long carry=0,i=3;
	
	char* ans=(char* )calloc(4,sizeof(char));
	printf("Num1: %s \nNum2: %s\n",num1,num2);
	for(i=3;i>=0;i--)
	{
		long p=0,q=0;
		p=num1[i]-'0';
		q=num2[i]-'0';
		
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
	if(carry==0)
		twosComp(ans);
	printf("Addition:- ");
	for(i=0;i<4;i++){
		printf("%c",ans[i]);
	}
	printf("\n");
	carry=0;
	twosComp(num2);
	for(i=3;i>=0;i--)
	{
		long p=0,q=0;
		p=num1[i]-'0';
		q=num2[i]-'0';
		
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
	printf("Subtraction:- ");
	for(i=0;i<4;i++){
		printf("%c",ans[i]);
	}

}
