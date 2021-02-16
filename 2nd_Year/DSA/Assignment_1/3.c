#include <stdio.h>

int main(){
	long n;
	printf("Please enter the number of elements in Array:-");
	scanf("%ld",&n);
	long a[n+10000];
	long i=0;
	long p=0,num=0;
	printf("Please enter the elements in Array:-");
	for(i=0;i<n;i++){
	    scanf("%ld",&a[i]);
	}
	printf("Current Array:- \n");
	for(i=0;i<n;i++){
		printf("%ld ",a[i]);
	}
	printf("\n");
	printf("Please enter the position at which you want to insert another number (O is the start Index):- ");	
	scanf("%ld",&p);
	if(p>n || p<0){
		printf("Invalid Array Position!\n");
	}else{
		printf("Please enter the number to be inserted:-");
		scanf("%ld",&num);
		for(i=n-1;i>=p;i--){
			a[i+1]=a[i];
		}
		a[p]=num;
		n++;
		printf("Current Array:- \n");
		for(i=0;i<n;i++){
			printf("%ld ",a[i]);
		}
		printf("\n");
	}
	
         

}
