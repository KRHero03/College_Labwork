#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
	float a=atof(argv[1]);
	printf("%f \n",a);
	printf("%10.3f \n",a);
	printf("%1.1f \n",a);
	printf("%-1.3f \n",a);
	printf("%-4.3f \n",a);
	printf("%-4.10f \n",a);
	printf("%1.10f \n",a);
}
