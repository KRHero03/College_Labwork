#include <stdio.h>

int main(int argc,char** argv)
{
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	printf("Addition: %ld \n",(long)a+(long)b);
	printf("Subtraction: %ld \n",(long)a-(long)b);
	printf("Multiplication: %ld \n",(long)a*(long)b);
	if(b==0)
		printf("Division and Modulus is not Possible! \n");
	else
	{
		printf("Division: %lf \n",(float)a/(float)b);
		printf("Modulus: %ld \n",(long)a%(long)b);
	
	}

}
