#include <stdio.h>
#define MAX 255
void push(char* stack,int* top,char x){
	if((*top)!=MAX-1){
		(*top)++;
		stack[*top]=x;
	}else{
		return;
	}
}
char pop(char* stack,int* top){
	if(*top!=-1){
		char y=stack[*top];
		(*top)--;
		return y;
	}else{
		return '\0';
	}
}

char peep(char* stack,int* top){
	if(*top!=-1)
		return stack[*top];
	else
		return 0;
}
int main(){
	char* stack=(char* ) malloc(MAX*sizeof(char));
	char* ans=(char* ) malloc(MAX*sizeof(char));
	int top=-1,i=0,pass=1;
	char x;
	printf("Please enter an Infix expression where variables are in lower Case:- \n");	
	while((x=getchar())!='\n'){		
			
		if(x=='('){
			push(stack,&top,x);
					
		}else if(x==')'){
			char y=peep(stack,&top);
			while(top!=-1){
				y=pop(stack,&top);
				if(y=='(')
					break;
				ans[i]=y;
				i++;
			}
			if(y!='('){
				pass=0;
				break;
			}
		}else if((x>=97 && x<=122)||(x>=48 && x<=57)){
			ans[i]=x;
			i++;
		}else if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%' || x=='^'){
			long j=0,k=0;
			if(x=='+'){
				j=0;
			}else if(x=='-'){
				j=0;
			}else if(x=='*'){
				j=1;
			}else if(x=='/'){
				j=1;
			}else if(x=='^'){
				j=2;
			}else if(x=='%'){
				j=1;
			}
			if(top!=-1){
				char y=pop(stack,&top);
				if(y=='+' || y=='-' || y=='*' || y=='/' || y=='%' || y=='^'){
					if(y=='+'){
						k=0;
					}else if(y=='-'){
						k=0;
					}else if(y=='*'){
						k=1;
					}else if(y=='/'){
						k=1;
					}else if(y=='^'){
						k=2;
					}else if(y=='%'){
						k=1;
					}
					if(j>k){
						push(stack,&top,y);
						push(stack,&top,x);		
					}else{
						ans[i]=y;
						i++;
						push(stack,&top,x);
					}
				}else if(y=='\0'){
					pass=0;
					break;
				}else{
					push(stack,&top,y);
					push(stack,&top,x);
				}
			}else{
				push(stack,&top,x);
			}
		}else{
			pass=0;
			break;
		}
	}
	
	while(top!=-1 && pass!=0){
		char y=pop(stack,&top);
		if(y=='('){
			pass=0;
			break;
		}else{
			ans[i]=y;
			i++;
		}
	}
	if(pass==1)
		printf("Postfix Notation (Reverse Polish Notation) :- %s \n",ans);
	else
		printf("Invalid Infix Expression! \n");

}
