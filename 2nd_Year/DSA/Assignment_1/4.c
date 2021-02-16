#include <stdio.h>

int main(){
	long n;
	printf("Please enter the number of elements in Array:-");
	scanf("%ld",&n);
	long a[n+10000];
	long i=0;
	printf("Please enter the elements in Array:-");
	for(i=0;i<n;i++){
	    scanf("%ld",&a[i]);
	}
	printf("Current Array:- \n");
	for(i=0;i<n;i++){
		printf("%ld ",a[i]);
	}
	printf("\n");
	printf("Please enter the position in the array which element needs to be deleted(0 is the start Index):- ");
	long p=0;
	scanf("%ld",&p);
	if(p>n-1 || p<0){
		printf("Invalid Array Position!\n");
	}else{
		for(i=p;i<n-1;i++){
			a[i]=a[i+1];
		}
		n--;
		printf("Current Array:- \n");
		for(i=0;i<n;i++){
			printf("%ld ",a[i]);
		}
		printf("\n");
	}
	
         

}
