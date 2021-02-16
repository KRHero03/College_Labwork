#include <stdio.h>
#define MAX 255
typedef struct str str;

struct str{
	char exp[255];
};

void push(str* stack,int* top,str* x){
	if((*top)!=MAX-1){
		(*top)++;
		stack[*top]=*x;
	}else{
		
	}
}
str* pop(str* stack,int* top){
	if(*top!=-1){
		str* y=&(stack[*top]);
		(*top)--;
		return y;
	}else{
		return NULL;
	}
}

str* peep(str* stack,int* top){
	if((*top)!=-1)
		return &(stack[*top]);
	else
		return NULL;
}

int main(){
	str* stack=(str*) malloc(MAX*sizeof(str));
	printf("Please enter a postfix Expression:- ");
	int pass=1,top=-1,opCount=0,varCount=0;
	char x;
	while((x=getchar())!='\n'){
		str* topElement=(str*) malloc(sizeof(str));
		topElement=peep(stack,&top);
		if((x>=97 && x<=122)||(x>=48 && x<=57)){
			str* y=(str*) malloc(MAX*sizeof(str));
			y->exp[0]=x;
			push(stack,&top,y);
			varCount++;
		}else if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%' || x=='^'){		opCount++;
			str* op1=pop(stack,&top);
			str* op2=pop(stack,&top);
			if(op1==NULL || op2==NULL){
				pass=0;
				break;
			}else{
				str* newExp=(str*) malloc(sizeof(str));
				newExp->exp[0]='(';
				long i=0,j=1;
				while(op2->exp[i]!='\0'){
					newExp->exp[j]=op2->exp[i];
					i++;
					j++;
				}
				
				newExp->exp[j++]=')';
				newExp->exp[j++]=x;
				newExp->exp[j++]='(';
				i=0;
				while(op1->exp[i]!='\0'){
					newExp->exp[j]=op1->exp[i];
					i++;
					j++;
				}
				newExp->exp[j]=')';
				push(stack,&top,newExp);
			}
			
		}else{
			pass=0;
			break;
		}
	}
	if(pass==0||(opCount!=varCount-1)){
		printf("Invalid Postfix Expression! \n");
	}else{
		str* ans=(str*) malloc(sizeof(str));
		ans=pop(stack,&top);
		printf("Evaluated Expression:- %s \n",ans->exp);
	}
	
}
