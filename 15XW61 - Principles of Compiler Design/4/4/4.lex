%{ // Declaration
// Identify the hexadecimal number. Consider upper or lower case for the digits above 9.
#include<iostream>
#include<string>
std::string str;
%}

hexadecimal [0][x|X][0-9A-Fa-f]+

%%
{hexadecimal} {
	str = yytext;
	std::cout<<yytext<<": is an hexadecimal\n";
}
. ;
%%

inti main(){
	yyout
	yylex();
}
int yywrap(){
	return 1;
}
