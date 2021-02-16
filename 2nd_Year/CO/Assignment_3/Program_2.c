#include <stdio.h>

//Addition of two binary numbers of n bits and returning final carry bit
int add(char* a,char* b,long n){
	long i,carry=0;
	for(i=n-1;i>=0;i--){		
		long p,q;
		if(a[i]=='0')
			p=0;
		else
			p=1;		
		if(b[i]=='0')
			q=0;
		else
			q=1;
		switch(p+q+carry){
			case 0:
				a[i]='0';
				carry=0;
				break;
			case 1:
				a[i]='1';
				carry=0;
				break;
			case 2:
				a[i]='0';
				carry=1;
				break;
			case 3:
				a[i]='1';
				carry=1;
				break;
		}
	}
	return carry;
}

//LefShift function used to leftShift combined values of e,A and Q where A and Q are of n bits
void leftShift(int* e,char* a,char* q,int n){
	if(a[0]=='0'){
		*e=0;
	}else{
		*e=1;
	}
	long i;
	for(i=0;i<n-1;i++){
		a[i]=a[i+1];
	}
	a[i]=q[0];
	for(i=0;i<n-1;i++){
		q[i]=q[i+1];
	}
	q[i]='0';
}

char* twosComp(char* num2,int n){
	long i;	
	char* num2Comp=(char* )malloc(n*sizeof(char));
	for(i=n-1;i>=0;i--){
		num2Comp[i]=num2[i];
		if(num2[i]=='1'){
			long j=i-1;
			for(j=i-1;j>=0;j--){
				if(num2[j]=='0')
					num2Comp[j]='1';
				else
					num2Comp[j]='0';
					
			}
			break;
		}
	}
	return num2Comp;
}

int main(int argc, char** argv){
	int n=5;
	char* num1=(char* )malloc(2*n*sizeof(char));
	char* num2=(char* )malloc(n*sizeof(char));	
	char* q=(char* )malloc(n*sizeof(char));
	char* num2Comp=(char* )malloc(n*sizeof(char));
	char* r=(char* )malloc(n*sizeof(char));
	char* signedBitNum1=(char*) malloc(1*sizeof(char));
	char* signedBitNum2=(char*) malloc(1*sizeof(char));
	long i=0;
	int e=0;
	
	for(i=0;i<n;i++){
		q[i]='0';
		r[i]='0';
	}
	
	//Retrieving num1 and num2 from Command Line
	signedBitNum1=argv[1];
	num1=argv[2];
	signedBitNum2=argv[3];
	num2=argv[4];
	
	for(i=0;i<5;i++)
		r[i]=num1[i];
	for(i=0;i<5;i++)
		q[i]=num1[i+5];
	
	printf("Before Algorithm:- %d %s %s %s\n\n\n",e,r,q,num2);	
	//Setting num2Comp = 2'sComp(num2)
	num2Comp=twosComp(num2,n);
	
	//Booth's Algorithm for Division	
	printf("Addition 1:- %d %s %s \n\n\n",e,r,q);	
	e=add(r,num2Comp,n);
	if(e==1){
		e=add(r,num2Comp,n);
	}else{
		int sc=n;
		e=add(r,num2,n);	
		printf("Addition 2:- %d %s %s \n\n\n",e,r,q);		
		while(sc>0){
			printf("Iteration:- %d \n",n-sc);			
			printf("E,A,Q Before Iteration:- %d %s %s \n",e,r,q);				
			leftShift(&e,r,q,n);		
			printf("LeftShift:- %d %s %s \n",e,r,q);
			if(e==1){
				int tp=add(r,num2Comp,n);
				printf("Addition Conditional if e==1:- %d %s %s \n",e,r,q);
				q[n-1]='1';
			}else{
				e=add(r,num2Comp,n);				
				printf("Addition Conditional if e==0:- %d %s %s \n",e,r,q);
				if(e==1){
					q[n-1]='1';
				}else{
					e=add(r,num2,n);
					printf("Addition Conditional 2 if e==0:- %d %s %s \n",e,r,q);
				}
			}
			sc--;
			printf("E,A,Q After Iteration:- %d %s %s \n",e,r,q);
			printf("\n\n");	
		}		
		if(signedBitNum1[0]=='1'){
			r=twosComp(r,n);
		}
		if((signedBitNum1[0]=='1' && signedBitNum2[0]!='1')||(signedBitNum1[0]!='1' && signedBitNum2[0]=='1')){
			q=twosComp(q,n);
		}
		printf("Quotient:- %s \nRemainder:- %s \n",q,r);
		
	}
}
