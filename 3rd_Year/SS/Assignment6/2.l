%{
#include<stdio.h>
int flag=0,single=0,multi=0;
%}
  
%%
"/*" { comment(); multi++;}
"//".* { single++;}
%%
  
int yywrap(){}
 
void comment()
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
} 
int main(){
  
  
FILE *fp;
char filename[50];
printf("Enter the filename: ");
scanf("%s",filename);
fp = fopen(filename,"r");
yyin = fp;
yyout = fopen("out.c","w");
  
yylex();
     
printf("No. of Single Line Comments=%d\n", single); 
printf("No. of Multi Line Comments=%d\n", multi);
  
return 0;
}