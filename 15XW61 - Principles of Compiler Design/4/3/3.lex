%{
#include<stdio.h>
#include<stdlib.h>
int charcount=0,linecount=0;
%}

%%
. charcount++;
\n {linecount++; charcount++;}
%%

int yywrap() { return 1;}
int main(int n,char ** r)
{
 FILE *file;
 file = fopen(r[1], "r");
 yyin=file;

yylex();
printf("There were %d characters in %d lines\n",charcount,linecount);
return 0;
}

