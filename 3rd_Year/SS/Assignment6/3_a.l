%{
#include<stdio.h>
int flag=0,single=0,multi=0;
%}
  
%%
[1-9][0-9]{9} {printf("Valid Mobile Number!\n");}
  
.+ {printf("Invalid Mobile Number!\n");}
"\n" {return 0;}
%%
  
int yywrap(){}
 
int main(){
  
    
yylex();
  
return 0;
}