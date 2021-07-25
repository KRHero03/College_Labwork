/*lex code to accept a  valid email */ 
%{
#include<stdio.h>
%}

%%

[0-9.a-z]{2,}@[a-z]{4,}(\.[a-z]{2,})+ {printf("Valid Email Address!\n");}
.+ {printf("Invalid Email Address!\n");}
"\n" {return 0;}
%%

int yywrap(){}
int main() {
  yylex();
}