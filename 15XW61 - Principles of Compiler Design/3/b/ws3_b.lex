%{
#include <stdio.h>
int wordCount = 0;
%}

words ([^ \t\n]+)

%%

{words} {wordCount++;}
"\n" {printf("The word count : %d\n",wordCount);wordCount = 0;return 0;}

%%

int yywrap(void){}

int main(){
	yylex();
	return 0;
}
