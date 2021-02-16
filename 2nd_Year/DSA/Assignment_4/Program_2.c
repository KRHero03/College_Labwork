#include <stdio.h>
#define MAX 255

void push(long* stack,int* top,long x){
	if((*top)!=MAX-1){
		(*top)++;
		stack[*top]=x;
	}else{
		
	}
}
long pop(long* stack,int* top){
	if(*top!=-1){
		long y=stack[*top];
		(*top)--;
		return y;
	}else{
		return 0;
	}
}

long peep(long* stack,int* top){
	if((*top)!=-1)
		return (long)(stack[*top]);
	else
		return 0;
}

long pow(long x,long y){
	long ans=1;
	long i=0;
	for(i=0;i<y;i++)
		ans*=x;
	return ans;
}

int main(){
	long* stack=(long*) malloc(MAX*sizeof(long));
	printf("Please enter a postfix Expression:- ");
	int pass=1,top=-1,opCount=0,varCount=0;
	char x;
	while((x=getchar())!='\n'){
		long topElement=peep(stack,&top);
		if(x>=48 && x<=57){
			long y=x-48;
			push(stack,&top,y);
			varCount++;
		}else if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%' || x=='^'){		
			opCount++;
			long op1=pop(stack,&top);
			long op2=pop(stack,&top);
			if(op1==NULL || op2==NULL){
				pass=0;
				break;
			}else{
				long ans=0;
				if(x=='+')
					ans=op2+op1;
				else if(x=='-')
					ans=op2-op1;
				else if(x=='*')
					ans=op2*op1;
				else if(x=='/')
					ans=op2/op1;
				else if(x=='%')
					ans=op2-op1;
				else if(x=='^')
					ans=pow(op2,op1);
					
				push(stack,&top,ans);
			}
			
		}else{
			pass=0;
			break;
		}
	}
	if(pass==0||(opCount!=varCount-1)){
		printf("Invalid Postfix Expression! \n");
	}else{
		
		long ans=pop(stack,&top);
		printf("Evaluated Expression:- %ld \n",ans);
	}
	
}
