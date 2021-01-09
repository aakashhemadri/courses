%{
#include<stdio.h>
int count=0,c1=0;
%}

digit [0-9]
letter [A-Za-z]

%%
{letter}({letter}|{digit})* { count++;  printf("\n%s is identifier",yytext);}
{digit}+                    { c1++; printf("\n%s is number",yytext); }

%%

int main(void) {
yylex();
printf("\nNumber of identifiers = %d\n Number of integer constants: %d", count,c1);
return 0;
}

int yywrap() {  return 1; }

