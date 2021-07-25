%{ 
#include <stdio.h> 
#include <string.h> 
#define MAX_OPERATORS 100
#define MAX_OPERANDS 100
#define MAX_CHARACTERS 250
    int operators_count = 0, operands_count = 0, valid = 1, top = -1, l = 0, j = 0; 
    char operands[MAX_OPERANDS][10], operators[MAX_OPERANDS][10], stack[MAX_CHARACTERS];
%} 
%%
"(" { 
    top++; 
    stack[top] = '('; 
} 
"{" {
    top++; 
    stack[top] = '{'; 
} 
"[" { 
    top++; 
    stack[top] = '['; 
} 
")" { 
    if (stack[top] != '(') { 
        valid = 0;     
    } 
    else if(operands_count>0 && (operands_count-operators_count)!=1){
        valid=0;
    }
    else{
        top--;
        operands_count=1;
        operators_count=0;
    } 
} 
"}" { 
    if (stack[top] != '{') { 
        valid = 0;     
    } 
    else if(operands_count>0 && (operands_count-operators_count)!=1){
        valid=0;
    }
    else{
        top--;
        operands_count=1;
        operators_count=0;
    } 
} 
"]" { 
    if (stack[top] != '[') { 
        valid = 0; 
    } 
    else if(operands_count>0 && (operands_count-operators_count)!=1){
        valid=0;
    }
    else{
        top--;
        operands_count=1;
        operators_count=0;
    } 
          
} 
"+"|"-"|"*"|"/" { 
    operators_count++; 
    strcpy(operators[l], yytext); 
    l++; 
} 
[0-9]+|[a-zA-Z][a-zA-Z0-9_]* { 
    operands_count++; 
    strcpy(operands[j], yytext); 
    j++; 
} 
"\n" {return 0;}
%% 
  
  
int yywrap() 
{ 
    return 1; 
} 
int main() 
{ 
    int k; 
    yylex(); 
  
    if (valid == 1 && top == -1) { 
        printf("\nGiven Expression is valid!\n"); 
        printf("Available Operators:\n");
        for(int i = 0;i<l;i++){
            printf("%s\n",operators[i]);
        } 
        printf("Available Operands:\n");
        for(int i = 0;i<j;i++){
            printf("%s\n",operands[i]);
        }
    } 
    else
        printf("\nGiven Expression is invalid!\n"); 
  
    return 0;
} 