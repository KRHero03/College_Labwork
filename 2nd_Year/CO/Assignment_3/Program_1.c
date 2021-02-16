#include <stdio.h>

void add(char* a,char* b,long n){
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
}

char* rightShift(char* ac,char* q,char* temp,long n){
	*temp=q[n-1];
	long i;
	for(i=n-1;i>0;i--){
		q[i]=q[i-1];
	}
	q[0]=ac[n-1];
	for(i=n-1;i>0;i--){
		ac[i]=ac[i-1];
	}
}
int main(){
	long n;
	printf("Please enter the value of n for Booth's algorithm:- ");
	scanf("%ld",&n);
	char* br=(char*)malloc(n*sizeof(char));
	char* q=(char*)malloc(n*sizeof(char));
	char* ac=(char*)malloc(n*sizeof(char));
	char* twosCompBR=(char*)malloc(n*sizeof(char));
	int i=0;
	for(i=0;i<n;i++){
		br[i]='0';
		q[i]='0';
		ac[i]='0';
		twosCompBR[i]='0';
	}
	int sc=n;
	char temp='0';	
	printf("Please enter the multiplicand in binary:- ");
	scanf("%s",br);
	printf("Please enter the multiplier in binary:- ");
	scanf("%s",q);
	long pass=0;
	for(i=n-1;i>=0;i--){		
		twosCompBR[i]=br[i];
					
		if(br[i]=='1'){
			long j=i-1;
			for(j=i-1;j>=0;j--){
				if(br[j]=='0')
					twosCompBR[j]='1';
				else
					twosCompBR[j]='0';				
			}
			pass=1;
		}
		if(pass==1)
			break;
			
	}
	while(sc--){
		if(q[n-1]=='0' && temp=='1'){
			add(ac,br,n);

		}else if(q[n-1]=='1' && temp=='0'){
			add(ac,twosCompBR,n);
		}
		rightShift(ac,q,&temp,n);
	}
	printf("Answer:- %s%s\n",ac,q);

}
