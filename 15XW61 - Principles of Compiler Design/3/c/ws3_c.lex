%{
#include <stdio.h>
#include <string.h>
int c;
%}

arithmeticOperations [+\-\*/%]
digts [0-9]

%%

{arithmeticOperations} {
	printf("\nAn operator is encountered !!\n");
	
}

([0-9]+) {
	c = atoi(yytext);
	printf("\n%d\n",c);
}

%%

int yywrap(void){}

int main(){
	yylex();
	return 0;
}

