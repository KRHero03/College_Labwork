%{
#include <stdio.h>
#include <math.h>
#include <string.h>
void check(char*);
int num = 0;
%}
  
%%
[0-1] {check(yytext);}
"\n" {printf("%d\n",num);num = 0;return 0;}
%% 
int yywrap(){};
int main()
{
    yylex();
  
    return 0;
}
void check(char* a)
{
    int len = strlen(a), i;
    for (i = 0; i < len; i++)
        num = num * 2 + (a[i] - '0');
  
}